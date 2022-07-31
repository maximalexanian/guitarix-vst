// generated from file '../src/LV2/faust/autowah.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace autowah {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	int IOTA;
	int iVec0[1024];
	int iRec2[2];
	double fRec1[2];
	double fConst0;
	double fConst1;
	double fConst2;
	double fRec3[2];
	double fRec4[2];
	double fRec0[3];

	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "auto";
	name = N_("auto");
	mono_audio = compute_static;
	stereo_audio = 0;
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
	for (int l0 = 0; (l0 < 1024); l0 = (l0 + 1)) iVec0[l0] = 0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) iRec2[l1] = 0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec1[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec3[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec4[l4] = 0.0;
	for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) fRec0[l5] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (1413.7166941154069 / fConst0);
	fConst2 = (2827.4333882308138 / fConst0);
	fVslider0 = FAUSTFLOAT(100.0);
	fVslider1 = FAUSTFLOAT(0.10000000000000001);
	fVslider2 = FAUSTFLOAT(0.0);
			IOTA = 0;
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
	double fSlow0 = double(fVslider0);
	double fSlow1 = (0.01 * (fSlow0 * double(fVslider1)));
	double fSlow2 = (2.384185791015625e-10 * double(fVslider2));
	double fSlow3 = (1.0 - (0.01 * fSlow0));
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = double(input0[i]);
		int iTemp1 = std::abs(int((4194304.0 * fTemp0)));
		iVec0[(IOTA & 1023)] = iTemp1;
		iRec2[0] = ((iRec2[1] + iTemp1) - iVec0[((IOTA - 1000) & 1023)]);
		double fTemp2 = std::min<double>(1.0, std::max<double>(0.0, (fSlow2 * double(iRec2[0]))));
		fRec1[0] = ((0.999 * fRec1[1]) + (0.0001000000000000001 * std::pow(4.0, fTemp2)));
		double fTemp3 = std::pow(2.0, (2.2999999999999998 * fTemp2));
		double fTemp4 = (1.0 - (fConst1 * (fTemp3 / std::pow(2.0, ((2.0 * (1.0 - fTemp2)) + 1.0)))));
		fRec3[0] = ((0.999 * fRec3[1]) - (0.0020000000000000018 * (fTemp4 * std::cos((fConst2 * fTemp3)))));
		fRec4[0] = ((0.999 * fRec4[1]) + (0.0010000000000000009 * mydsp_faustpower2_f(fTemp4)));
		fRec0[0] = ((fSlow1 * (fRec1[0] * fTemp0)) - ((fRec3[0] * fRec0[1]) + (fRec4[0] * fRec0[2])));
		output0[i] = FAUSTFLOAT(((fRec0[0] + (fSlow3 * fTemp0)) - fRec0[1]));
		IOTA = (IOTA + 1);
		iRec2[1] = iRec2[0];
		fRec1[1] = fRec1[0];
		fRec3[1] = fRec3[0];
		fRec4[1] = fRec4[0];
		fRec0[2] = fRec0[1];
		fRec0[1] = fRec0[0];
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case LEVEL: 
		fVslider1_ = (float*)data; // , 0.10000000000000001, 0.0, 1.0, 0.01 
		break;
	case WAH: 
		fVslider2_ = (float*)data; // , 0.0, 0.0, 1.0, 0.01 
		break;
	case WET_DRY: 
		fVslider0_ = (float*)data; // , 100.0, 0.0, 100.0, 1.0 
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
   LEVEL, 
   WAH, 
   WET_DRY, 
} PortIndex;
*/

} // end namespace autowah
