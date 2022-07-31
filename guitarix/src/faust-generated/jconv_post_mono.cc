// generated from file '../src/faust/jconv_post_mono.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace jconv_post_mono {


Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec0[l0] = 0.0;
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fVslider0 = FAUSTFLOAT(100.0);
	fVslider1 = FAUSTFLOAT(0.0);
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0)
{
	double fSlow0 = (0.01 * double(fVslider0));
	double fSlow1 = (1.0 - fSlow0);
	double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider1))));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (fSlow2 + (0.999 * fRec0[1]));
		output0[i] = FAUSTFLOAT(((fSlow1 * double(input0[i])) + (fSlow0 * (fRec0[0] * double(input1[i])))));
		fRec0[1] = fRec0[0];
	}
}

int Dsp::register_par(const ParamReg& reg)
{
	reg.registerVar("jconv_mono.gain",N_("Gain"),"S",N_("gain trim for processed signal (unit: dB)"),&fVslider1, 0.0, -20.0, 20.0, 0.10000000000000001);
	reg.registerVar("jconv_mono.wet_dry",N_("wet/dry"),"S",N_("percentage of processed signal in output signal"),&fVslider0, 100.0, 0.0, 100.0, 1.0);
	return 0;
}


} // end namespace jconv_post_mono
