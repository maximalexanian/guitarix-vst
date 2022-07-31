// generated from file '../src/LV2/faust/tonestack_ampeg_stereo.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace tonestack_ampeg_stereo {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double fConst0;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fConst1;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fConst2;
	double fRec0[4];
	double fRec1[4];

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
	id = "Ampeg";
	name = N_("Ampeg");
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
	for (int l0 = 0; (l0 < 4); l0 = (l0 + 1)) fRec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 4); l1 = (l1 + 1)) fRec1[l1] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = (2.0 * std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq))));
	fConst1 = mydsp_faustpower2_f(fConst0);
	fConst2 = (3.0 * fConst0);
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
	double fSlow0 = double(fVslider0);
	double fSlow1 = std::exp((3.3999999999999999 * (double(fVslider1) + -1.0)));
	double fSlow2 = ((0.00055000000000000003 * fSlow0) + (0.022470000000000004 * fSlow1));
	double fSlow3 = (fConst0 * (fSlow2 + 0.0020872500000000001));
	double fSlow4 = (3.0896250000000005e-07 * fSlow0);
	double fSlow5 = ((((((1.2358500000000002e-05 * fSlow1) + -1.361249999999999e-08) - fSlow4) * fSlow0) + (1.8734760000000003e-05 * fSlow1)) + 6.3380900000000011e-07);
	double fSlow6 = ((1.6037340000000005e-09 * fSlow1) - (4.0093350000000015e-11 * fSlow0));
	double fSlow7 = (1.8198400000000004e-09 * fSlow1);
	double fSlow8 = ((((fSlow6 + -5.4026500000000002e-12) * fSlow0) + fSlow7) + 4.5496000000000015e-11);
	double fSlow9 = (fConst0 * fSlow8);
	double fSlow10 = (1.0 / (-1.0 - (fSlow3 + (fConst1 * (fSlow5 + fSlow9)))));
	double fSlow11 = double(fVslider2);
	double fSlow12 = (fConst0 * ((fSlow2 + (0.00011750000000000001 * fSlow11)) + 0.00056175000000000007));
	double fSlow13 = (((1.6544000000000003e-07 * fSlow11) + (((3.7358750000000009e-07 - fSlow4) * fSlow0) + (fSlow1 * ((1.2358500000000002e-05 * fSlow0) + 3.2467600000000001e-06)))) + 8.1169000000000004e-08);
	double fSlow14 = (((fSlow6 + 4.0093350000000015e-11) * fSlow0) + ((fSlow7 - (4.5496000000000015e-11 * (fSlow0 + -1.0))) * fSlow11));
	double fSlow15 = (fConst0 * fSlow14);
	double fSlow16 = (0.0 - (fSlow12 + (fConst1 * (fSlow13 + fSlow15))));
	double fSlow17 = (fConst2 * fSlow8);
	double fSlow18 = ((fConst1 * (fSlow5 + fSlow17)) + (-3.0 - fSlow3));
	double fSlow19 = ((fSlow3 + (fConst1 * (fSlow5 - fSlow17))) + -3.0);
	double fSlow20 = (fSlow3 + (-1.0 - (fConst1 * (fSlow5 - fSlow9))));
	double fSlow21 = (fConst2 * fSlow14);
	double fSlow22 = ((fConst1 * (fSlow13 + fSlow21)) - fSlow12);
	double fSlow23 = (fSlow12 + (fConst1 * (fSlow13 - fSlow21)));
	double fSlow24 = (fSlow12 - (fConst1 * (fSlow13 - fSlow15)));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (double(input0[i]) - (fSlow10 * (((fSlow18 * fRec0[1]) + (fSlow19 * fRec0[2])) + (fSlow20 * fRec0[3]))));
		output0[i] = FAUSTFLOAT((fSlow10 * ((((fSlow16 * fRec0[0]) + (fSlow22 * fRec0[1])) + (fSlow23 * fRec0[2])) + (fSlow24 * fRec0[3]))));
		fRec1[0] = (double(input1[i]) - (fSlow10 * (((fSlow18 * fRec1[1]) + (fSlow19 * fRec1[2])) + (fSlow20 * fRec1[3]))));
		output1[i] = FAUSTFLOAT((fSlow10 * ((((fSlow16 * fRec1[0]) + (fSlow22 * fRec1[1])) + (fSlow23 * fRec1[2])) + (fSlow24 * fRec1[3]))));
		for (int j0 = 3; (j0 > 0); j0 = (j0 - 1)) {
			fRec0[j0] = fRec0[(j0 - 1)];
		}
		for (int j1 = 3; (j1 > 0); j1 = (j1 - 1)) {
			fRec1[j1] = fRec1[(j1 - 1)];
		}
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
		fVslider1_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case MIDDLE: 
		fVslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case TREBLE: 
		fVslider2_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
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

} // end namespace tonestack_ampeg_stereo
