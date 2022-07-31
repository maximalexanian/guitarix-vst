// generated from file '../src/LV2/faust/flanger_mono.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace flanger_mono {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT	*fHslider0_;
	int iVec0[2];
	int IOTA;
	double fVec1[4096];
	double fConst0;
	double fConst1;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT	*fHslider1_;
	double fRec1[2];
	double fRec2[2];
	double fRec0[2];

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
	id = "flanger_mono";
	name = N_("Flanger Mono");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) iVec0[l0] = 0;
	for (int l1 = 0; (l1 < 4096); l1 = (l1 + 1)) fVec1[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec1[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec2[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec0[l4] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (6.2831853071795862 / fConst0);
	fVslider0 = FAUSTFLOAT(100.0);
	fHslider0 = FAUSTFLOAT(0.0);
	fHslider1 = FAUSTFLOAT(0.20000000000000001);
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
#define fHslider0 (*fHslider0_)
#define fHslider1 (*fHslider1_)
	double fSlow0 = double(fVslider0);
	double fSlow1 = (1.0 - (0.01 * fSlow0));
	double fSlow2 = (0.01 * (std::pow(10.0, (0.050000000000000003 * double(fHslider0))) * fSlow0));
	double fSlow3 = (fConst1 * double(fHslider1));
	double fSlow4 = std::sin(fSlow3);
	double fSlow5 = std::cos(fSlow3);
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = double(input0[i]);
		double fTemp1 = (fSlow2 * fTemp0);
		iVec0[0] = 1;
		double fTemp2 = ((0.5 * fRec0[1]) - fTemp1);
		fVec1[(IOTA & 4095)] = fTemp2;
		fRec1[0] = ((fSlow4 * fRec2[1]) + (fSlow5 * fRec1[1]));
		fRec2[0] = ((double((1 - iVec0[1])) + (fSlow5 * fRec2[1])) - (fSlow4 * fRec1[1]));
		double fTemp3 = (fConst0 * ((0.0050000000000000001 * (fRec1[0] + 1.0)) + 0.001));
		int iTemp4 = int(fTemp3);
		double fTemp5 = std::floor(fTemp3);
		fRec0[0] = ((fVec1[((IOTA - std::min<int>(2049, std::max<int>(0, iTemp4))) & 4095)] * (fTemp5 + (1.0 - fTemp3))) + ((fTemp3 - fTemp5) * fVec1[((IOTA - std::min<int>(2049, std::max<int>(0, (iTemp4 + 1)))) & 4095)]));
		output0[i] = FAUSTFLOAT(((fSlow1 * fTemp0) + (0.5 * (fTemp1 - fRec0[0]))));
		iVec0[1] = iVec0[0];
		IOTA = (IOTA + 1);
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
#undef fVslider0
#undef fHslider0
#undef fHslider1
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case FREQ: 
		fHslider1_ = (float*)data; // , 0.20000000000000001, 0.0, 5.0, 0.01 
		break;
	case LEVEL: 
		fHslider0_ = (float*)data; // , 0.0, -60.0, 10.0, 0.10000000000000001 
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
   FREQ, 
   LEVEL, 
   WET_DRY, 
} PortIndex;
*/

} // end namespace flanger_mono
