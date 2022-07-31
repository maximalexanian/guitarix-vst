// generated from file '../src/LV2/faust/crybaby.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace crybaby {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	float fRec1[2];
	float fConst0;
	float fConst1;
	float fConst2;
	float fRec2[2];
	float fRec3[2];
	float fRec0[3];

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
	id = "manual";
	name = N_("manual");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec1[l0] = 0.0f;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec2[l1] = 0.0f;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec3[l2] = 0.0f;
	for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) fRec0[l3] = 0.0f;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
	fConst1 = (1413.71667f / fConst0);
	fConst2 = (2827.43335f / fConst0);
	fVslider0 = FAUSTFLOAT(100.0f);
	fVslider1 = FAUSTFLOAT(0.10000000000000001f);
	fVslider2 = FAUSTFLOAT(0.0f);
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
	float fSlow0 = float(fVslider0);
	float fSlow1 = (0.00999999978f * (fSlow0 * float(fVslider1)));
	float fSlow2 = float(fVslider2);
	float fSlow3 = (9.99999975e-05f * std::pow(4.0f, fSlow2));
	float fSlow4 = std::pow(2.0f, (2.29999995f * fSlow2));
	float fSlow5 = (1.0f - (fConst1 * (fSlow4 / std::pow(2.0f, ((2.0f * (1.0f - fSlow2)) + 1.0f)))));
	float fSlow6 = (0.00200000009f * (fSlow5 * std::cos((fConst2 * fSlow4))));
	float fSlow7 = (0.00100000005f * mydsp_faustpower2_f(fSlow5));
	float fSlow8 = (1.0f - (0.00999999978f * fSlow0));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec1[0] = (fSlow3 + (0.999000013f * fRec1[1]));
		float fTemp0 = float(input0[i]);
		fRec2[0] = ((0.999000013f * fRec2[1]) - fSlow6);
		fRec3[0] = (fSlow7 + (0.999000013f * fRec3[1]));
		fRec0[0] = ((fSlow1 * (fRec1[0] * fTemp0)) - (0.995999992f * ((fRec2[0] * fRec0[1]) + (fRec3[0] * fRec0[2]))));
		output0[i] = FAUSTFLOAT(((fRec0[0] + (fSlow8 * fTemp0)) - (0.995999992f * fRec0[1])));
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		fRec3[1] = fRec3[0];
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
		fVslider1_ = (float*)data; // , 0.100000001f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case WAH: 
		fVslider2_ = (float*)data; // , 0.0f, 0.0f, 1.0f, 0.00999999978f 
		break;
	case WET_DRY: 
		fVslider0_ = (float*)data; // , 100.0f, 0.0f, 100.0f, 1.0f 
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

} // end namespace crybaby
