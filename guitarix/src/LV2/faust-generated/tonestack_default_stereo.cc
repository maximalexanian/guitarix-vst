// generated from file '../src/LV2/faust/tonestack_default_stereo.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace tonestack_default_stereo {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fVec0[3];
	double fRec3[3];
	double fRec2[3];
	double fRec1[3];
	double fRec0[3];
	double fVec1[3];
	double fRec7[3];
	double fRec6[3];
	double fRec5[3];
	double fRec4[3];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "default";
	name = N_("default");
	mono_audio = 0;
	stereo_audio = compute_static;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) fVec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) fRec3[l1] = 0.0;
	for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) fRec2[l2] = 0.0;
	for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) fRec1[l3] = 0.0;
	for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) fRec0[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fVec1[l5] = 0.0;
	for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) fRec7[l6] = 0.0;
	for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) fRec6[l7] = 0.0;
	for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) fRec5[l8] = 0.0;
	for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) fRec4[l9] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (15079.644737231007 / fConst0);
	fConst2 = (1.4142135623730951 * std::sin(fConst1));
	fConst3 = std::cos(fConst1);
	fConst4 = (3769.9111843077517 / fConst0);
	fConst5 = (1.4142135623730951 * std::sin(fConst4));
	fConst6 = std::cos(fConst4);
	fVslider0 = FAUSTFLOAT(0.5);
	fVslider1 = FAUSTFLOAT(0.5);
	fVslider2 = FAUSTFLOAT(0.5);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
	double fSlow0 = (double(fVslider1) + -0.5);
	double fSlow1 = (10.0 * fSlow0);
	double fSlow2 = std::pow(10.0, (0.025000000000000001 * ((20.0 * (double(fVslider0) + -0.5)) - fSlow1)));
	double fSlow3 = (fConst2 * std::sqrt(fSlow2));
	double fSlow4 = (fConst3 * (fSlow2 + -1.0));
	double fSlow5 = (1.0 / ((fSlow2 + fSlow3) + (1.0 - fSlow4)));
	double fSlow6 = (fSlow2 + (1.0 - (fSlow4 + fSlow3)));
	double fSlow7 = (fConst3 * (fSlow2 + 1.0));
	double fSlow8 = (2.0 * (fSlow2 + (-1.0 - fSlow7)));
	double fSlow9 = (fSlow2 + fSlow4);
	double fSlow10 = (fSlow2 * ((fSlow3 + fSlow9) + 1.0));
	double fSlow11 = std::pow(10.0, (0.25 * fSlow0));
	double fSlow12 = std::sqrt(fSlow11);
	double fSlow13 = (fConst5 * fSlow12);
	double fSlow14 = (fSlow11 + -1.0);
	double fSlow15 = (fConst6 * fSlow14);
	double fSlow16 = (1.0 / ((fSlow11 + fSlow13) + (1.0 - fSlow15)));
	double fSlow17 = (fSlow11 + (1.0 - (fSlow15 + fSlow13)));
	double fSlow18 = (fSlow11 + 1.0);
	double fSlow19 = (fConst6 * fSlow18);
	double fSlow20 = (2.0 * (fSlow11 + (-1.0 - fSlow19)));
	double fSlow21 = (fSlow15 + fSlow11);
	double fSlow22 = (((fSlow21 + fSlow13) + 1.0) * fSlow11);
	double fSlow23 = (fConst3 * fSlow14);
	double fSlow24 = (fSlow23 + fSlow11);
	double fSlow25 = (fConst2 * fSlow12);
	double fSlow26 = (1.0 / ((fSlow24 + fSlow25) + 1.0));
	double fSlow27 = (fConst3 * fSlow18);
	double fSlow28 = (0.0 - (2.0 * ((fSlow27 + fSlow11) + -1.0)));
	double fSlow29 = (fSlow24 + (1.0 - fSlow25));
	double fSlow30 = ((fSlow11 + fSlow25) + (1.0 - fSlow23));
	double fSlow31 = std::pow(10.0, (0.025000000000000001 * ((20.0 * (std::exp((3.3999999999999999 * (double(fVslider2) + -1.0))) + -0.5)) - fSlow1)));
	double fSlow32 = (fConst6 * (fSlow31 + -1.0));
	double fSlow33 = (fSlow31 + fSlow32);
	double fSlow34 = (fConst5 * std::sqrt(fSlow31));
	double fSlow35 = (1.0 / ((fSlow33 + fSlow34) + 1.0));
	double fSlow36 = (fConst6 * (fSlow31 + 1.0));
	double fSlow37 = (0.0 - (2.0 * ((fSlow31 + fSlow36) + -1.0)));
	double fSlow38 = (fSlow33 + (1.0 - fSlow34));
	double fSlow39 = ((fSlow31 + fSlow34) + (1.0 - fSlow32));
	double fSlow40 = (2.0 * (fSlow31 + (-1.0 - fSlow36)));
	double fSlow41 = (fSlow31 + (1.0 - (fSlow32 + fSlow34)));
	double fSlow42 = (2.0 * (fSlow11 + (-1.0 - fSlow27)));
	double fSlow43 = (fSlow11 + (1.0 - (fSlow23 + fSlow25)));
	double fSlow44 = ((0.0 - (2.0 * fSlow11)) * ((fSlow19 + fSlow11) + -1.0));
	double fSlow45 = ((fSlow21 + (1.0 - fSlow13)) * fSlow11);
	double fSlow46 = ((0.0 - (2.0 * fSlow2)) * ((fSlow2 + fSlow7) + -1.0));
	double fSlow47 = (fSlow2 * (fSlow9 + (1.0 - fSlow3)));
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = double(input0[i]);
		fVec0[0] = fTemp0;
		fRec3[0] = (0.0 - (fSlow35 * (((fSlow37 * fRec3[1]) + (fSlow38 * fRec3[2])) - (fSlow31 * (((fSlow39 * fTemp0) + (fSlow40 * fVec0[1])) + (fSlow41 * fVec0[2]))))));
		fRec2[0] = (0.0 - (fSlow26 * (((fSlow28 * fRec2[1]) + (fSlow29 * fRec2[2])) - (fSlow11 * (((fSlow30 * fRec3[0]) + (fSlow42 * fRec3[1])) + (fSlow43 * fRec3[2]))))));
		fRec1[0] = (fSlow16 * ((0.0 - ((fSlow17 * fRec1[2]) + (fSlow20 * fRec1[1]))) + (((fSlow22 * fRec2[0]) + (fSlow44 * fRec2[1])) + (fSlow45 * fRec2[2]))));
		fRec0[0] = (fSlow5 * ((0.0 - ((fSlow6 * fRec0[2]) + (fSlow8 * fRec0[1]))) + (((fSlow10 * fRec1[0]) + (fSlow46 * fRec1[1])) + (fSlow47 * fRec1[2]))));
		output0[i] = FAUSTFLOAT(fRec0[0]);
		double fTemp1 = double(input1[i]);
		fVec1[0] = fTemp1;
		fRec7[0] = (0.0 - (fSlow35 * (((fSlow37 * fRec7[1]) + (fSlow38 * fRec7[2])) - (fSlow31 * (((fSlow39 * fTemp1) + (fSlow40 * fVec1[1])) + (fSlow41 * fVec1[2]))))));
		fRec6[0] = (0.0 - (fSlow26 * (((fSlow28 * fRec6[1]) + (fSlow29 * fRec6[2])) - (fSlow11 * (((fSlow30 * fRec7[0]) + (fSlow42 * fRec7[1])) + (fSlow43 * fRec7[2]))))));
		fRec5[0] = (fSlow16 * ((0.0 - ((fSlow17 * fRec5[2]) + (fSlow20 * fRec5[1]))) + (((fSlow22 * fRec6[0]) + (fSlow44 * fRec6[1])) + (fSlow45 * fRec6[2]))));
		fRec4[0] = (fSlow5 * ((0.0 - ((fSlow6 * fRec4[2]) + (fSlow8 * fRec4[1]))) + (((fSlow10 * fRec5[0]) + (fSlow46 * fRec5[1])) + (fSlow47 * fRec5[2]))));
		output1[i] = FAUSTFLOAT(fRec4[0]);
		fVec0[2] = fVec0[1];
		fVec0[1] = fVec0[0];
		fRec3[2] = fRec3[1];
		fRec3[1] = fRec3[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fRec1[2] = fRec1[1];
		fRec1[1] = fRec1[0];
		fRec0[2] = fRec0[1];
		fRec0[1] = fRec0[0];
		fVec1[2] = fVec1[1];
		fVec1[1] = fVec1[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec5[2] = fRec5[1];
		fRec5[1] = fRec5[0];
		fRec4[2] = fRec4[1];
		fRec4[1] = fRec4[0];
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, input1, output0, output1);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case BASS: 
		fVslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MIDDLE: 
		fVslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fVslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   BASS, 
   MIDDLE, 
   TREBLE, 
} PortIndex;
*/

} // end namespace tonestack_default_stereo
