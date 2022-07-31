// generated from file '../src/LV2/faust/tonecontroll.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace tonecontroll {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT	*fCheckbox0_;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec0[2];
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fVec0[2];
	double fConst8;
	double fConst9;
	double fRec3[2];
	double fConst10;
	double fConst11;
	double fRec2[3];
	double fConst12;
	double fConst13;
	double fConst14;
	double fConst15;
	double fConst16;
	double fConst17;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fRec1[3];
	double fConst22;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec4[2];
	double fConst23;
	double fRec8[2];
	double fRec7[3];
	double fVec1[2];
	double fConst24;
	double fConst25;
	double fRec6[2];
	double fConst26;
	double fRec5[3];
	double fConst27;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec9[2];
	double fConst28;
	double fRec11[2];
	double fRec10[3];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fConst29;
	double fConst30;
	double fRec12[2];
	double fVec2[2];
	double fRec15[2];
	double fRec14[3];
	double fRec13[3];
	double fRec19[2];
	double fRec18[3];
	double fVec3[2];
	double fRec17[2];
	double fRec16[3];
	double fRec21[2];
	double fRec20[3];
	double fRec22[2];

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
	id = "tonemodul";
	name = N_("3 Band EQ");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec0[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec3[l2] = 0.0;
	for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) fRec2[l3] = 0.0;
	for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) fRec1[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec4[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec8[l6] = 0.0;
	for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) fRec7[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fVec1[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec6[l9] = 0.0;
	for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) fRec5[l10] = 0.0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec9[l11] = 0.0;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fRec11[l12] = 0.0;
	for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) fRec10[l13] = 0.0;
	for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) fRec12[l14] = 0.0;
	for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) fVec2[l15] = 0.0;
	for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) fRec15[l16] = 0.0;
	for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) fRec14[l17] = 0.0;
	for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) fRec13[l18] = 0.0;
	for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) fRec19[l19] = 0.0;
	for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) fRec18[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fVec3[l21] = 0.0;
	for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) fRec17[l22] = 0.0;
	for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) fRec16[l23] = 0.0;
	for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) fRec21[l24] = 0.0;
	for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) fRec20[l25] = 0.0;
	for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) fRec22[l26] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = std::tan((7539.8223686155034 / fConst0));
	fConst2 = (1.0 / fConst1);
	fConst3 = (1.0 / (((fConst2 + 1.0000000000000004) / fConst1) + 1.0));
	fConst4 = mydsp_faustpower2_f(fConst1);
	fConst5 = (1.0 / fConst4);
	fConst6 = (fConst2 + 1.0);
	fConst7 = (0.0 - (1.0 / (fConst6 * fConst1)));
	fConst8 = (1.0 / fConst6);
	fConst9 = (1.0 - fConst2);
	fConst10 = (((fConst2 + -1.0000000000000004) / fConst1) + 1.0);
	fConst11 = (2.0 * (1.0 - fConst5));
	fConst12 = (0.0 - (2.0 / fConst4));
	fConst13 = std::tan((1884.9555921538758 / fConst0));
	fConst14 = (1.0 / fConst13);
	fConst15 = (fConst14 + 1.0);
	fConst16 = (1.0 / ((fConst15 / fConst13) + 1.0));
	fConst17 = (1.0 - fConst14);
	fConst18 = (1.0 - (fConst17 / fConst13));
	fConst19 = mydsp_faustpower2_f(fConst13);
	fConst20 = (1.0 / fConst19);
	fConst21 = (2.0 * (1.0 - fConst20));
	fConst22 = (1.0 / (((fConst14 + 1.0000000000000004) / fConst13) + 1.0));
	fConst23 = (1.0 / (fConst13 * fConst15));
	fConst24 = (0.0 - fConst23);
	fConst25 = (fConst17 / fConst15);
	fConst26 = (((fConst14 + -1.0000000000000004) / fConst13) + 1.0);
	fConst27 = (0.0 - (2.0 / fConst19));
	fConst28 = (1.0 / fConst15);
	fConst29 = std::exp((0.0 - (200.0 / fConst0)));
	fConst30 = std::exp((0.0 - (0.20000000000000001 / fConst0)));
	fCheckbox0 = FAUSTFLOAT(0.0);
	fVslider0 = FAUSTFLOAT(0.0);
	fVslider1 = FAUSTFLOAT(0.0);
	fVslider2 = FAUSTFLOAT(0.0);
	fVslider3 = FAUSTFLOAT(-2.0);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *input1, FAUSTFLOAT *output0, FAUSTFLOAT *output1)
{
#define fCheckbox0 (*fCheckbox0_)
#define fVslider0 (*fVslider0_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fVslider3 (*fVslider3_)
	int iSlow0 = int(double(fCheckbox0));
	double fSlow1 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider0))));
	double fSlow2 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider1))));
	double fSlow3 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider2))));
	double fSlow4 = double(fVslider3);
	double fSlow5 = (5.0 * fSlow4);
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec0[0] = (fSlow1 + (0.999 * fRec0[1]));
		double fTemp0 = double(input0[i]);
		fVec0[0] = fTemp0;
		fRec3[0] = ((fConst7 * fVec0[1]) - (fConst8 * ((fConst9 * fRec3[1]) - (fConst2 * fTemp0))));
		fRec2[0] = (fRec3[0] - (fConst3 * ((fConst10 * fRec2[2]) + (fConst11 * fRec2[1]))));
		double fTemp1 = (fConst21 * fRec1[1]);
		fRec1[0] = ((fConst3 * (((fConst5 * fRec2[0]) + (fConst12 * fRec2[1])) + (fConst5 * fRec2[2]))) - (fConst16 * ((fConst18 * fRec1[2]) + fTemp1)));
		fRec4[0] = (fSlow2 + (0.999 * fRec4[1]));
		fRec8[0] = (0.0 - (fConst8 * ((fConst9 * fRec8[1]) - (fVec0[1] + fTemp0))));
		fRec7[0] = (fRec8[0] - (fConst3 * ((fConst10 * fRec7[2]) + (fConst11 * fRec7[1]))));
		double fTemp2 = (fRec7[2] + (fRec7[0] + (2.0 * fRec7[1])));
		fVec1[0] = fTemp2;
		fRec6[0] = ((fConst3 * ((fConst23 * fTemp2) + (fConst24 * fVec1[1]))) - (fConst25 * fRec6[1]));
		fRec5[0] = (fRec6[0] - (fConst22 * ((fConst26 * fRec5[2]) + (fConst21 * fRec5[1]))));
		fRec9[0] = (fSlow3 + (0.999 * fRec9[1]));
		fRec11[0] = (0.0 - (fConst28 * ((fConst17 * fRec11[1]) - (fConst3 * (fTemp2 + fVec1[1])))));
		fRec10[0] = (fRec11[0] - (fConst22 * ((fConst26 * fRec10[2]) + (fConst21 * fRec10[1]))));
		double fTemp3 = ((fRec0[0] * (fRec1[2] + (fConst16 * (fTemp1 + (fConst18 * fRec1[0]))))) + (fConst22 * ((fRec4[0] * (((fConst20 * fRec5[0]) + (fConst27 * fRec5[1])) + (fConst20 * fRec5[2]))) + (fRec9[0] * (fRec10[2] + (fRec10[0] + (2.0 * fRec10[1])))))));
		double fTemp4 = std::max<double>(1.0, std::fabs(fTemp3));
		double fTemp5 = ((fConst29 * double((fRec12[1] < fTemp4))) + (fConst30 * double((fRec12[1] >= fTemp4))));
		fRec12[0] = ((fRec12[1] * fTemp5) + (fTemp4 * (1.0 - fTemp5)));
		double fTemp6 = std::max<double>(0.0, (fSlow5 + (20.0 * std::log10(fRec12[0]))));
		double fTemp7 = (2.0 * std::min<double>(1.0, std::max<double>(0.0, (0.095229025807065992 * fTemp6))));
		output0[i] = FAUSTFLOAT((iSlow0?(fTemp3 * std::pow(10.0, (0.050000000000000003 * (fSlow4 + ((fTemp6 * (0.0 - fTemp7)) / (fTemp7 + 1.0)))))):fTemp3));
		double fTemp8 = double(input1[i]);
		fVec2[0] = fTemp8;
		fRec15[0] = ((fConst7 * fVec2[1]) - (fConst8 * ((fConst9 * fRec15[1]) - (fConst2 * fTemp8))));
		fRec14[0] = (fRec15[0] - (fConst3 * ((fConst10 * fRec14[2]) + (fConst11 * fRec14[1]))));
		double fTemp9 = (fConst21 * fRec13[1]);
		fRec13[0] = ((fConst3 * (((fConst5 * fRec14[0]) + (fConst12 * fRec14[1])) + (fConst5 * fRec14[2]))) - (fConst16 * ((fConst18 * fRec13[2]) + fTemp9)));
		fRec19[0] = (0.0 - (fConst8 * ((fConst9 * fRec19[1]) - (fVec2[1] + fTemp8))));
		fRec18[0] = (fRec19[0] - (fConst3 * ((fConst10 * fRec18[2]) + (fConst11 * fRec18[1]))));
		double fTemp10 = (fRec18[2] + (fRec18[0] + (2.0 * fRec18[1])));
		fVec3[0] = fTemp10;
		fRec17[0] = ((fConst3 * ((fConst23 * fTemp10) + (fConst24 * fVec3[1]))) - (fConst25 * fRec17[1]));
		fRec16[0] = (fRec17[0] - (fConst22 * ((fConst26 * fRec16[2]) + (fConst21 * fRec16[1]))));
		fRec21[0] = (0.0 - (fConst28 * ((fConst17 * fRec21[1]) - (fConst3 * (fTemp10 + fVec3[1])))));
		fRec20[0] = (fRec21[0] - (fConst22 * ((fConst26 * fRec20[2]) + (fConst21 * fRec20[1]))));
		double fTemp11 = ((fRec0[0] * (fRec13[2] + (fConst16 * (fTemp9 + (fConst18 * fRec13[0]))))) + (fConst22 * ((fRec4[0] * (((fConst20 * fRec16[0]) + (fConst27 * fRec16[1])) + (fConst20 * fRec16[2]))) + (fRec9[0] * (fRec20[2] + (fRec20[0] + (2.0 * fRec20[1])))))));
		double fTemp12 = std::max<double>(1.0, std::fabs(fTemp11));
		double fTemp13 = ((fConst29 * double((fRec22[1] < fTemp12))) + (fConst30 * double((fRec22[1] >= fTemp12))));
		fRec22[0] = ((fRec22[1] * fTemp13) + (fTemp12 * (1.0 - fTemp13)));
		double fTemp14 = std::max<double>(0.0, (fSlow5 + (20.0 * std::log10(fRec22[0]))));
		double fTemp15 = (2.0 * std::min<double>(1.0, std::max<double>(0.0, (0.095229025807065992 * fTemp14))));
		output1[i] = FAUSTFLOAT((iSlow0?(fTemp11 * std::pow(10.0, (0.050000000000000003 * (fSlow4 + ((fTemp14 * (0.0 - fTemp15)) / (fTemp15 + 1.0)))))):fTemp11));
		fRec0[1] = fRec0[0];
		fVec0[1] = fVec0[0];
		fRec3[1] = fRec3[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fRec1[2] = fRec1[1];
		fRec1[1] = fRec1[0];
		fRec4[1] = fRec4[0];
		fRec8[1] = fRec8[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fVec1[1] = fVec1[0];
		fRec6[1] = fRec6[0];
		fRec5[2] = fRec5[1];
		fRec5[1] = fRec5[0];
		fRec9[1] = fRec9[0];
		fRec11[1] = fRec11[0];
		fRec10[2] = fRec10[1];
		fRec10[1] = fRec10[0];
		fRec12[1] = fRec12[0];
		fVec2[1] = fVec2[0];
		fRec15[1] = fRec15[0];
		fRec14[2] = fRec14[1];
		fRec14[1] = fRec14[0];
		fRec13[2] = fRec13[1];
		fRec13[1] = fRec13[0];
		fRec19[1] = fRec19[0];
		fRec18[2] = fRec18[1];
		fRec18[1] = fRec18[0];
		fVec3[1] = fVec3[0];
		fRec17[1] = fRec17[0];
		fRec16[2] = fRec16[1];
		fRec16[1] = fRec16[0];
		fRec21[1] = fRec21[0];
		fRec20[2] = fRec20[1];
		fRec20[1] = fRec20[0];
		fRec22[1] = fRec22[0];
	}
#undef fCheckbox0
#undef fVslider0
#undef fVslider1
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
	case BASS: 
		fVslider2_ = (float*)data; // , 0.0, -5.0, 5.0, 0.01 
		break;
	case MIDDLE: 
		fVslider1_ = (float*)data; // , 0.0, -5.0, 5.0, 0.01 
		break;
	case ON: 
		fCheckbox0_ = (float*)data; // , 0.0, 0.0, 1.0, 1.0 
		break;
	case TREBLE: 
		fVslider0_ = (float*)data; // , 0.0, -5.0, 5.0, 0.01 
		break;
	case SHARPER: 
		fVslider3_ = (float*)data; // , -2.0, -2.5, 5.0, 0.10000000000000001 
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
   ON, 
   TREBLE, 
   SHARPER, 
} PortIndex;
*/

} // end namespace tonecontroll
