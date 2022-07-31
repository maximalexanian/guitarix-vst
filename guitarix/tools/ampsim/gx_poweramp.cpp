#include <zita-resampler/resampler.h>
#include <glibmm/i18n.h>
#include "intpp.h"
#include "data.h"
#include "gx_plugin.h"
#include <stdio.h>

/****************************************************************
 ** Resampler
 */
#include <cassert>
#include <cmath>

class FixedRateResampler {
private:
    Resampler r_up, r_down;
    int inputRate, outputRate;
    int last_in_count;
public:
    int setup(int _inputRate, int _outputRate);
    int up(int count, float *input, float *output);
    void down(float *input, float *output);
    int max_out_count(int in_count) {
	return static_cast<int>(ceil((in_count*static_cast<double>(outputRate))/inputRate)); }
};

int FixedRateResampler::setup(int _inputRate, int _outputRate)
{
    const int qual = 16; // resulting in a total delay of 2*qual (0.7ms @44100)
    inputRate = _inputRate;
    outputRate = _outputRate;
    if (inputRate == outputRate) {
	return 0;
    }
    // upsampler
    int ret = r_up.setup(inputRate, outputRate, 1, qual);
    if (ret) {
	return ret;
    }
    // k == filtlen() == 2 * qual
    // pre-fill with k-1 zeros
    r_up.inp_count = r_up.filtlen() - 1;
    r_up.out_count = 1;
    r_up.inp_data = r_up.out_data = 0;
    r_up.process();
    // downsampler
    ret = r_down.setup(outputRate, inputRate, 1, qual);
    if (ret) {
	return ret;
    }
    // k == filtlen() == 2 * qual * fact
    // pre-fill with k-2 zeros
    r_down.inp_count = r_down.filtlen() - 2;
    r_down.out_count = 1;
    r_down.inp_data = r_down.out_data = 0;
    r_down.process();
    return 0;
}

int FixedRateResampler::up(int count, float *input, float *output)
{
    if (inputRate == outputRate) {
	memcpy(output, input, count*sizeof(float));
	r_down.out_count = count;
	return count;
    }
    r_up.inp_count = count;
    r_down.out_count = count+1; // +1 == trick to drain input
    r_up.inp_data = input;
    int m = max_out_count(count);
    r_up.out_count = m;
    r_up.out_data = output;
    r_up.process();
    assert(r_up.inp_count == 0);
    assert(r_up.out_count <= 1);
    r_down.inp_count = m - r_up.out_count;
    return r_down.inp_count;
}

void FixedRateResampler::down(float *input, float *output)
{
    if (inputRate == outputRate) {
	memcpy(output, input, r_down.out_count*sizeof(float));
	return;
    }
    r_down.inp_data = input;
    r_down.out_data = output;
    r_down.process();
    assert(r_down.inp_count == 0);
    assert(r_down.out_count == 1);
}

namespace gx_engine {

/****************************************************************
 ** Pre Amp
 */

class preCalc: public SplineCalc {
public:
    preCalc(splinedata *sd_, real *s0_): SplineCalc(sd_, s0_) {}
    void calc(real *in, real *out);
};

void preCalc::calc(real *in, real *out)
{
    temp[0] = in[0] - temp[1];
    real t[sd->m];
    for (int i = 0; i < sd->m; i++) {
	splinecoeffs *p = &sd->sc[i];
	check(sd, temp, (*p->eval)(p, temp, &t[i]));
    }
    for (int i = 0; i < sd->n_output; i++) {
	out[i] = t[i];
    }
    for (int i = 0; i < sd->n_state; i++) {
	temp[i+sd->n_input] += t[i+sd->n_output];
    }
}

class PreAmp {
private:
    preCalc pre;
    real Uin;
    static const real TransN;
    static const real Fdamp;

public:
    PreAmp();
    ~PreAmp();
    float operator()(float v);
};

static real ctc0[] = { 2.2423, 266.95 };

PreAmp::PreAmp()
    : pre(&AmpData::ct::sd, ctc0)
{
    pre.reset();
}

PreAmp::~PreAmp()
{
}

inline float PreAmp::operator()(float v)
{
    real Uout;
    pre.calc(&v, &Uout);
    return Uout;
}

static PreAmp PreAmp1;
static PreAmp PreAmp2;
static PreAmp PreAmp3;
static PreAmp PreAmp4;
static PreAmp PreAmp5;
static PreAmp PreAmp6;

#include "gx_faust_support.h"
#include "gxpreamp.cc"

/****************************************************************/

FixedRateResampler pre_smp;

void Pre_init(unsigned int samplingFreq, PluginDef*)
{
    pre_smp.setup(samplingFreq, AmpData::fs);
    gxpreamp::init(AmpData::fs);
}

void run_preamp(int count, float* input, float* output, PluginDef *plugin) {
    float buf[pre_smp.max_out_count(count)];
    int n = pre_smp.up(count, input, buf);
    gxpreamp::compute(n, buf, buf, plugin);
    pre_smp.down(buf, output);
}

int preamp_register(const ParamReg& reg)
{
    gxpreamp::register_params(reg);
    return 0;
}

int preamp_load_ui(const UiBuilder& b, int form) {
    if (!(form & UI_FORM_STACK)) {
	return -1;
    }
    b.openHorizontalhideBox("");
    {
        b.create_master_slider("gxpreamp.gain1", 0);
    }
    b.closeBox();
    b.openVerticalBox("");
    {
	b.openHorizontalBox("");
	{
	    b.create_small_rackknob("gxpreamp.gain1", 0);
	    b.create_small_rackknob("gxpreamp.gain2", 0);
	    b.create_small_rackknob("gxpreamp.gain3", 0);
	}
	b.closeBox();
    }
    b.closeBox();
    return 0;
}


/****************************************************************
 ** Power Amp
 */

class psCalc: public SplineCalc {
public:
    psCalc(splinedata *sd_, real *s0_): SplineCalc(sd_, s0_) {}
    void calc(real *in, real *out);
};

void psCalc::calc(real *in, real *out)
{
    real temp1[3];
    temp1[0] = in[0] - temp[1];
    temp1[1] = temp[2];
    temp1[2] = temp[3];
    real t[sd->m];
    for (int i = 0; i < sd->m; i++) {
	splinecoeffs *p = &sd->sc[i];
	check(sd, temp1, (*p->eval)(p, temp1, &t[i]));
    }
    for (int i = 0; i < sd->n_output; i++) {
	out[i] = t[i];
    }
    for (int i = 0; i < sd->n_state; i++) {
	temp[i+sd->n_input] += t[i+sd->n_output];
    }
}

class gCalc: public SplineCalc {
public:
    gCalc(splinedata *sd_, real *s0_): SplineCalc(sd_, s0_) {}
    void calc(real *in, real *out);
};

void gCalc::calc(real *in, real *out)
{
    for (int i = 0; i < sd->n_input; i++) {
	temp[i] = in[i];
    }
    temp[0] -= temp[1] - 311.045;
    real t[sd->m];
    for (int i = 0; i < sd->m; i++) {
	splinecoeffs *p = &sd->sc[i];
	check(sd, temp, (*p->eval)(p, temp, &t[i]));
    }
    out[0] = t[0];
    temp[1] += t[1] - 311.045;
}

class ptCalc: public SplineCalc {
public:
    ptCalc(splinedata *sd_, real *s0_): SplineCalc(sd_, s0_) {}
    void calc(real *in, real *out);
};

void ptCalc::calc(real *in, real *out)
{
    for (int i = 0; i < sd->n_input; i++) {
	temp[i] = in[i];
    }
    real t[sd->m];
    for (int i = 0; i < sd->m; i++) {
	splinecoeffs *p = &sd->sc[i];
	check(sd, temp, (*p->eval)(p, temp, &t[i]));
    }
    for (int i = 0; i < sd->n_output; i++) {
	out[i] = t[i];
    }
    for (int i = 0; i < sd->n_state; i++) {
	temp[i+sd->n_input] += t[i+sd->n_output];
    }
}

class Amp {
private:
    psCalc ps;
    gCalc g1;
    gCalc g2;
    ptCalc pt;
    void reset();
    static const real TransN;
    static const real Fdamp;

public:
    Amp();
    ~Amp();
    float operator()(float v);
};

static real ps0[] = { -29.77995343, 29.64688073, 0.13308519 };
static real g10[] = { 311.045 };
static real g20[] = { 302.032 };
static real pt0[] = { 427.582 };

Amp::Amp()
    : ps(&AmpData::ps_jcm800::sd, ps0),
      g1(&AmpData::ppg_jcm800::sd, g10),
      g2(&AmpData::ppg_jcm800::sd, g20),
      pt(&AmpData::ppp_jcm800::sd, pt0)
{
    reset();
}

Amp::~Amp()
{
}


const real Amp::TransN = 450.0;
const real Amp::Fdamp = 15.0;

void Amp::reset()
{
    ps.reset();
    g1.reset();
    g2.reset();
    pt.reset();
}

inline float Amp::operator()(float v)
{
    real s[2];
    ps.calc(&v, s);
    real up[2];
    g1.calc(&s[0], &up[0]);
    g2.calc(&s[1], &up[1]);
    real Uout;
    //up[1] += up[0]; // pt spline table expects signal + sum
    pt.calc(up, &Uout);
    return Uout;
}

static Amp PowAmp;

#include "gxpoweramp.cc"

/****************************************************************/

FixedRateResampler smp;

void PAinit(unsigned int samplingFreq, PluginDef*)
{
    smp.setup(samplingFreq, AmpData::fs);
    gxpoweramp::init(AmpData::fs);
}

void run_poweramp(int count, float* input, float* output, PluginDef *plugin) {
    float buf[smp.max_out_count(count)];
    int n = smp.up(count, input, buf);
    gxpoweramp::compute(n, buf, buf, plugin);
    smp.down(buf, output);
}

int poweramp_register(const ParamReg& reg)
{
    gxpoweramp::register_params(reg);
    return 0;
}

int poweramp_load_ui(const UiBuilder& b, int form) {
    if (!(form & UI_FORM_STACK)) {
	return -1;
    }
    b.openHorizontalhideBox("");
    {
        b.create_master_slider("gxpoweramp.Pregain", 0);
    }
    b.closeBox();
    b.openVerticalBox("");
    {
	b.openHorizontalBox("");
	{
	    b.create_small_rackknob("gxpoweramp.R4", "Presence");
	    b.create_small_rackknob("gxpoweramp.fbgain", "FeedBack");
	    b.create_small_rackknob("gxpoweramp.Pregain", "PreGain");
	    b.create_small_rackknob("gxpoweramp.postgain", "PostGain");
	}
	b.closeBox();
    }
    b.closeBox();
    return 0;
}

extern "C" __attribute__ ((visibility ("default"))) int
get_gx_plugin(unsigned int idx, PluginDef **pplugin)
{
    const int count = 2;
    if (!pplugin) {
	return count;
    }
    switch (idx) {
    case 0: {
	PluginDef *p = gxpreamp::plugin();
	p->mono_audio = run_preamp;
	p->set_samplerate = Pre_init;
	p->register_params = preamp_register;
	p->load_ui = preamp_load_ui;
	*pplugin = p;
	return count;
    }
    case 1: {
	PluginDef *p = gxpoweramp::plugin();
	p->mono_audio = run_poweramp;
	p->set_samplerate = PAinit;
	p->register_params = poweramp_register;
	p->load_ui = poweramp_load_ui;
	*pplugin = p;
	return count;
    }
    default:
	*pplugin = 0;
	return -1;
    }
}

} // namespace gx_engine
