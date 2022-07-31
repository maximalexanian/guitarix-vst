// generated from file '../src/LV2/faust/stereoecho.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace stereoecho {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	int iVec0[2];
	float fConst0;
	float fConst1;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	float fRec1[2];
	float fRec2[2];
	int iRec3[2];
	int iRec4[2];
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT	*fCheckbox0_;
	float fConst2;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT	*fHslider0_;
	float fRec5[2];
	float fRec6[2];
	int IOTA;
	float *fRec0;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	float fRec8[2];
	float fRec9[2];
	int iRec10[2];
	int iRec11[2];
	float *fRec7;

	bool mem_allocated;
	void mem_alloc();
	void mem_free();
	void connect(uint32_t port,void* data);
	void clear_state_f();
	int activate(bool start);
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1);

	static void clear_state_f_static(PluginLV2*);
	static int activate_static(bool start, PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2(),
	  fRec0(0),
	  fRec7(0),
	  mem_allocated(false) {
	version = PLUGINLV2_VERSION;
	id = "stereoecho";
	name = N_("Stereo Echo");
	mono_audio = 0;
	stereo_audio = compute_static;
	set_samplerate = init_static;
	activate_plugin = activate_static;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) iVec0[l0] = 0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec1[l1] = 0.0f;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec2[l2] = 0.0f;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) iRec3[l3] = 0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) iRec4[l4] = 0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec5[l5] = 0.0f;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec6[l6] = 0.0f;
	for (int l7 = 0; (l7 < 262144); l7 = (l7 + 1)) fRec0[l7] = 0.0f;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec8[l8] = 0.0f;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec9[l9] = 0.0f;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) iRec10[l10] = 0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) iRec11[l11] = 0;
	for (int l12 = 0; (l12 < 262144); l12 = (l12 + 1)) fRec7[l12] = 0.0f;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
	fConst1 = (0.00100000005f * fConst0);
	fConst2 = (6.28318548f / fConst0);
	fVslider0 = FAUSTFLOAT(0.0f);
	fVslider1 = FAUSTFLOAT(1.0f);
	fCheckbox0 = FAUSTFLOAT(0.0f);
	fHslider0 = FAUSTFLOAT(0.20000000000000001f);
	fVslider2 = FAUSTFLOAT(0.0f);
	fVslider3 = FAUSTFLOAT(1.0f);
			IOTA = 0;
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void Dsp::mem_alloc()
{
	if (!fRec0) fRec0 = new float[262144];
	if (!fRec7) fRec7 = new float[262144];
	mem_allocated = true;
}

void Dsp::mem_free()
{
	mem_allocated = false;
	if (fRec0) { delete fRec0; fRec0 = 0; }
	if (fRec7) { delete fRec7; fRec7 = 0; }
}

int Dsp::activate(bool start)
{
	if (start) {
		if (!mem_allocated) {
			mem_alloc();
			clear_state_f();
		}
	} else if (mem_allocated) {
		mem_free();
	}
	return 0;
}

int Dsp::activate_static(bool start, PluginLV2 *p)
{
	return static_cast<Dsp*>(p)->activate(start);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fCheckbox0 (*fCheckbox0_)
#define fHslider0 (*fHslider0_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
	float fSlow0 = (0.00999999978f * float(fVslider0));
	int iSlow1 = (int((fConst1 * float(fVslider1))) + -1);
	float fSlow2 = float(fCheckbox0);
	float fSlow3 = (fConst2 * float(fHslider0));
	float fSlow4 = std::sin(fSlow3);
	float fSlow5 = std::cos(fSlow3);
	float fSlow6 = (0.00999999978f * float(fVslider2));
	int iSlow7 = (int((fConst1 * float(fVslider3))) + -1);
	for (int i = 0; (i < count); i = (i + 1)) {
		iVec0[0] = 1;
		float fTemp0 = ((fRec1[1] != 0.0f)?(((fRec2[1] > 0.0f) & (fRec2[1] < 1.0f))?fRec1[1]:0.0f):(((fRec2[1] == 0.0f) & (iSlow1 != iRec3[1]))?0.0009765625f:(((fRec2[1] == 1.0f) & (iSlow1 != iRec4[1]))?-0.0009765625f:0.0f)));
		fRec1[0] = fTemp0;
		fRec2[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec2[1] + fTemp0)));
		iRec3[0] = (((fRec2[1] >= 1.0f) & (iRec4[1] != iSlow1))?iSlow1:iRec3[1]);
		iRec4[0] = (((fRec2[1] <= 0.0f) & (iRec3[1] != iSlow1))?iSlow1:iRec4[1]);
		fRec5[0] = ((fSlow4 * fRec6[1]) + (fSlow5 * fRec5[1]));
		fRec6[0] = ((float((1 - iVec0[1])) + (fSlow5 * fRec6[1])) - (fSlow4 * fRec5[1]));
		fRec0[(IOTA & 262143)] = ((fSlow0 * ((((1.0f - fRec2[0]) * fRec0[((IOTA - (std::min<int>(131072, std::max<int>(0, iRec3[0])) + 1)) & 262143)]) + (fRec2[0] * fRec0[((IOTA - (std::min<int>(131072, std::max<int>(0, iRec4[0])) + 1)) & 262143)])) * (1.0f - (fSlow2 * fRec5[0])))) + float(input0[i]));
		output0[i] = FAUSTFLOAT(fRec0[((IOTA - 0) & 262143)]);
		float fTemp1 = ((fRec8[1] != 0.0f)?(((fRec9[1] > 0.0f) & (fRec9[1] < 1.0f))?fRec8[1]:0.0f):(((fRec9[1] == 0.0f) & (iSlow7 != iRec10[1]))?0.0009765625f:(((fRec9[1] == 1.0f) & (iSlow7 != iRec11[1]))?-0.0009765625f:0.0f)));
		fRec8[0] = fTemp1;
		fRec9[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec9[1] + fTemp1)));
		iRec10[0] = (((fRec9[1] >= 1.0f) & (iRec11[1] != iSlow7))?iSlow7:iRec10[1]);
		iRec11[0] = (((fRec9[1] <= 0.0f) & (iRec10[1] != iSlow7))?iSlow7:iRec11[1]);
		fRec7[(IOTA & 262143)] = ((fSlow6 * ((((1.0f - fRec9[0]) * fRec7[((IOTA - (std::min<int>(131072, std::max<int>(0, iRec10[0])) + 1)) & 262143)]) + (fRec9[0] * fRec7[((IOTA - (std::min<int>(131072, std::max<int>(0, iRec11[0])) + 1)) & 262143)])) * (1.0f - (fSlow2 * (0.0f - fRec5[0]))))) + float(input1[i]));
		output1[i] = FAUSTFLOAT(fRec7[((IOTA - 0) & 262143)]);
		iVec0[1] = iVec0[0];
		fRec1[1] = fRec1[0];
		fRec2[1] = fRec2[0];
		iRec3[1] = iRec3[0];
		iRec4[1] = iRec4[0];
		fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		IOTA = (IOTA + 1);
		fRec8[1] = fRec8[0];
		fRec9[1] = fRec9[0];
		iRec10[1] = iRec10[0];
		iRec11[1] = iRec11[0];
	}
#undef fVslider0
#undef fVslider1
#undef fCheckbox0
#undef fHslider0
#undef fVslider2
#undef fVslider3
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, input1, output0, output1);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case LFOFREQ: 
		fHslider0_ = (float*)data; // , 0.200000003f, 0.0f, 5.0f, 0.00999999978f 
		break;
	// static const value_pair fCheckbox0_values[] = {{"linear"},{"pingpong"},{0}};
	case INVERT: 
		fCheckbox0_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case PERCENT_L: 
		fVslider0_ = (float*)data; // , 0.0f, 0.0f, 100.0f, 0.100000001f 
		break;
	case PERCENT_R: 
		fVslider2_ = (float*)data; // , 0.0f, 0.0f, 100.0f, 0.100000001f 
		break;
	case TIME_L: 
		fVslider1_ = (float*)data; // , 1.0f, 1.0f, 2000.0f, 1.0f 
		break;
	case TIME_R: 
		fVslider3_ = (float*)data; // , 1.0f, 1.0f, 2000.0f, 1.0f 
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
   LFOFREQ, 
   INVERT, 
   PERCENT_L, 
   PERCENT_R, 
   TIME_L, 
   TIME_R, 
} PortIndex;
*/

} // end namespace stereoecho
