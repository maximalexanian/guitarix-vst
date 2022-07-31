// generated from file '../src/faust/gx_ampout_ladspa.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace gx_ampout_ladspa {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fVslider1;
	double fRec0[2];

	void clear_state_f();
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



static const char* parm_groups[] = {
	".amp", N_("?"),
	0
	};

Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "gx_ampout_ladspa";
	name = N_("gx_ampout_ladspa");
	groups = parm_groups;
	description = ""; // description (tooltip)
	category = "";       // category
	shortname = "";     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = 0;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec0[l0] = 0.0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fCheckbox0 = FAUSTFLOAT(0.0);
	fVslider0 = FAUSTFLOAT(0.0);
	fVslider1 = FAUSTFLOAT(0.0);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
	double fSlow0 = double(fVslider0);
	double fSlow1 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * (int(double(fCheckbox0))?(fSlow0 + double(fVslider1)):fSlow0))));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = ((0.999 * fRec0[1]) + fSlow1);
		output0[i] = FAUSTFLOAT((fRec0[0] * double(input0[i])));
		fRec0[1] = fRec0[0];
	}
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("amp.on_off",N_("use Level"),"B","",&fCheckbox0, 0.0, 0.0, 1.0, 1.0);
	reg.registerVar("amp.out_amp",N_("Level"),"S","",&fVslider1, 0.0, -20.0, 4.0, 0.10000000000000001);
	reg.registerVar("amp.out_ladspa",N_("Ladspa Level"),"S","",&fVslider0, 0.0, -20.0, 20.0, 0.10000000000000001);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace gx_ampout_ladspa
