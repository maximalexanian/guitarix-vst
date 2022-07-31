// generated from file '../src/LV2/faust/gxamp13.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)

#include "valve.h"

namespace gxamp13 {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	double fConst5;
	double fConst6;
	double fConst7;
	double fVec0[2];
	double fRec9[2];
	double fRec8[3];
	double fConst8;
	double fConst9;
	double fConst10;
	double fVec1[2];
	double fRec10[2];
	double fRec7[2];
	double fConst11;
	double fConst12;
	double fRec6[2];
	double fVec2[2];
	double fRec20[2];
	double fRec19[3];
	double fConst13;
	double fConst14;
	double fConst15;
	double fVec3[2];
	double fRec21[2];
	double fRec18[2];
	double fRec17[2];
	double fRec26[2];
	int IOTA;
	double fVec4[32768];
	double fConst16;
	int iConst17;
	double fRec28[2];
	double fRec27[2];
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fRec29[2];
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fConst18;
	double fConst19;
	double fConst20;
	double fConst21;
	double fConst22;
	double fConst23;
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fConst33;
	double fConst34;
	double fConst35;
	double fRec37[3];
	double fVec5[2];
	double fRec36[2];
	double fRec35[2];
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fRec34[3];
	double fVec6[2];
	double fConst40;
	double fConst41;
	double fConst42;
	double fRec33[2];
	double fConst43;
	double fConst44;
	double fRec32[3];
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fRec31[3];
	double fConst55;
	double fRec41[2];
	double fRec40[3];
	double fConst56;
	double fConst57;
	double fConst58;
	double fRec39[3];
	double fRec38[3];
	double fConst59;
	double fConst60;
	double fConst61;
	double fRec45[2];
	double fRec44[3];
	double fVec7[2];
	double fConst62;
	double fConst63;
	double fRec43[2];
	double fConst64;
	double fRec42[3];
	double fConst65;
	double fConst66;
	double fRec47[2];
	double fRec46[3];
	double fVec8[2];
	double fRec30[2];
	double fVec9[2];
	double fRec25[2];
	double fRec24[3];
	double fConst67;
	double fConst68;
	double fConst69;
	double fVec10[2];
	double fRec48[2];
	double fRec23[2];
	double fRec22[2];
	double fRec16[2];
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec49[2];
	double fVec11[2];
	double fRec15[2];
	double fVec12[2];
	double fRec14[2];
	double fRec13[3];
	double fVec13[2];
	double fRec50[2];
	double fRec12[2];
	double fRec11[2];
	double fRec5[2];
	double fRec4[2];
	double fVec14[2];
	double fRec3[2];
	double fRec2[3];
	double fVec15[2];
	double fRec51[2];
	double fRec1[2];
	double fRec0[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec52[2];

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
	id = "6DJ8 feedback";
	name = N_("6DJ8 feedback");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fVec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fRec9[l1] = 0.0;
	for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) fRec8[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fVec1[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec10[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec7[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec6[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fVec2[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec20[l8] = 0.0;
	for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) fRec19[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fVec3[l10] = 0.0;
	for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) fRec21[l11] = 0.0;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fRec18[l12] = 0.0;
	for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) fRec17[l13] = 0.0;
	for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) fRec26[l14] = 0.0;
	for (int l15 = 0; (l15 < 32768); l15 = (l15 + 1)) fVec4[l15] = 0.0;
	for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) fRec28[l16] = 0.0;
	for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) fRec27[l17] = 0.0;
	for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) fRec29[l18] = 0.0;
	for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) fRec37[l19] = 0.0;
	for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) fVec5[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fRec36[l21] = 0.0;
	for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) fRec35[l22] = 0.0;
	for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) fRec34[l23] = 0.0;
	for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) fVec6[l24] = 0.0;
	for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) fRec33[l25] = 0.0;
	for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) fRec32[l26] = 0.0;
	for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) fRec31[l27] = 0.0;
	for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) fRec41[l28] = 0.0;
	for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) fRec40[l29] = 0.0;
	for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) fRec39[l30] = 0.0;
	for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) fRec38[l31] = 0.0;
	for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) fRec45[l32] = 0.0;
	for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) fRec44[l33] = 0.0;
	for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) fVec7[l34] = 0.0;
	for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) fRec43[l35] = 0.0;
	for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) fRec42[l36] = 0.0;
	for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) fRec47[l37] = 0.0;
	for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) fRec46[l38] = 0.0;
	for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) fVec8[l39] = 0.0;
	for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) fRec30[l40] = 0.0;
	for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) fVec9[l41] = 0.0;
	for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) fRec25[l42] = 0.0;
	for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) fRec24[l43] = 0.0;
	for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) fVec10[l44] = 0.0;
	for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) fRec48[l45] = 0.0;
	for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) fRec23[l46] = 0.0;
	for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) fRec22[l47] = 0.0;
	for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) fRec16[l48] = 0.0;
	for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) fRec49[l49] = 0.0;
	for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) fVec11[l50] = 0.0;
	for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) fRec15[l51] = 0.0;
	for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) fVec12[l52] = 0.0;
	for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) fRec14[l53] = 0.0;
	for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) fRec13[l54] = 0.0;
	for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) fVec13[l55] = 0.0;
	for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) fRec50[l56] = 0.0;
	for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) fRec12[l57] = 0.0;
	for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) fRec11[l58] = 0.0;
	for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) fRec5[l59] = 0.0;
	for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) fRec4[l60] = 0.0;
	for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) fVec14[l61] = 0.0;
	for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) fRec3[l62] = 0.0;
	for (int l63 = 0; (l63 < 3); l63 = (l63 + 1)) fRec2[l63] = 0.0;
	for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) fVec15[l64] = 0.0;
	for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) fRec51[l65] = 0.0;
	for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) fRec1[l66] = 0.0;
	for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) fRec0[l67] = 0.0;
	for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) fRec52[l68] = 0.0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = std::tan((97.389372261283583 / fConst0));
	fConst2 = (1.0 / fConst1);
	fConst3 = (fConst2 + 1.0);
	fConst4 = (1.0 / (fConst3 * fConst1));
	fConst5 = (1.0 / std::tan((20517.741620594938 / fConst0)));
	fConst6 = (1.0 / (fConst5 + 1.0));
	fConst7 = (1.0 - fConst5);
	fConst8 = (1.0 / std::tan((609.46897479641984 / fConst0)));
	fConst9 = (1.0 / (fConst8 + 1.0));
	fConst10 = (1.0 - fConst8);
	fConst11 = (0.0 - fConst4);
	fConst12 = ((1.0 - fConst2) / fConst3);
	fConst13 = (1.0 / std::tan((414.69023027385271 / fConst0)));
	fConst14 = (1.0 / (fConst13 + 1.0));
	fConst15 = (1.0 - fConst13);
	fConst16 = (0.009000000000000008 / fConst0);
	iConst17 = int(std::min<double>(65536.0, std::max<double>(0.0, (0.1111111111111111 * fConst0))));
	fConst18 = std::tan((3769.9111843077517 / fConst0));
	fConst19 = (1.0 / fConst18);
	fConst20 = (1.0 / (((fConst19 + 1.0000000000000004) / fConst18) + 1.0));
	fConst21 = mydsp_faustpower2_f(fConst18);
	fConst22 = (1.0 / fConst21);
	fConst23 = std::tan((10053.096491487338 / fConst0));
	fConst24 = (1.0 / fConst23);
	fConst25 = (1.0 / (((fConst24 + 1.0000000000000004) / fConst23) + 1.0));
	fConst26 = (fConst19 + 1.0);
	fConst27 = (1.0 / (fConst18 * fConst26));
	fConst28 = (fConst24 + 1.0);
	fConst29 = (1.0 / fConst28);
	fConst30 = (1.0 - fConst24);
	fConst31 = std::tan((47123.889803846898 / fConst0));
	fConst32 = (1.0 / fConst31);
	fConst33 = (1.0 / (((fConst32 + 1.4142135623730949) / fConst31) + 1.0));
	fConst34 = (((fConst32 + -1.4142135623730949) / fConst31) + 1.0);
	fConst35 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst31))));
	fConst36 = (((fConst24 + -1.0000000000000004) / fConst23) + 1.0);
	fConst37 = mydsp_faustpower2_f(fConst23);
	fConst38 = (1.0 / fConst37);
	fConst39 = (2.0 * (1.0 - fConst38));
	fConst40 = (0.0 - fConst27);
	fConst41 = (1.0 - fConst19);
	fConst42 = (fConst41 / fConst26);
	fConst43 = (((fConst19 + -1.0000000000000004) / fConst18) + 1.0);
	fConst44 = (2.0 * (1.0 - fConst22));
	fConst45 = (0.0 - (2.0 / fConst21));
	fConst46 = std::tan((942.47779607693792 / fConst0));
	fConst47 = (1.0 / fConst46);
	fConst48 = (fConst47 + 1.0);
	fConst49 = (1.0 / ((fConst48 / fConst46) + 1.0));
	fConst50 = (1.0 - fConst47);
	fConst51 = (1.0 - (fConst50 / fConst46));
	fConst52 = mydsp_faustpower2_f(fConst46);
	fConst53 = (1.0 / fConst52);
	fConst54 = (2.0 * (1.0 - fConst53));
	fConst55 = (0.0 - (1.0 / (fConst28 * fConst23)));
	fConst56 = (0.0 - (2.0 / fConst37));
	fConst57 = (1.0 / ((fConst26 / fConst18) + 1.0));
	fConst58 = (1.0 - (fConst41 / fConst18));
	fConst59 = (1.0 / (((fConst47 + 1.0000000000000004) / fConst46) + 1.0));
	fConst60 = (1.0 / (fConst46 * fConst48));
	fConst61 = (1.0 / fConst26);
	fConst62 = (0.0 - fConst60);
	fConst63 = (fConst50 / fConst48);
	fConst64 = (((fConst47 + -1.0000000000000004) / fConst46) + 1.0);
	fConst65 = (0.0 - (2.0 / fConst52));
	fConst66 = (1.0 / fConst48);
	fConst67 = (1.0 / std::tan((270.1769682087222 / fConst0)));
	fConst68 = (1.0 / (fConst67 + 1.0));
	fConst69 = (1.0 - fConst67);
	fVslider0 = FAUSTFLOAT(100.0);
	fVslider1 = FAUSTFLOAT(0.34999999999999998);
	fVslider2 = FAUSTFLOAT(-6.0);
	fVslider3 = FAUSTFLOAT(-6.0);
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
#define fVslider3 (*fVslider3_)
	double fSlow0 = (1.0000000000000009e-05 * double(fVslider0));
	double fSlow1 = double(fVslider1);
	double fSlow2 = (1.25 * fSlow1);
	double fSlow3 = (2.0 * (fSlow1 + -0.5));
	double fSlow4 = (0.024937655860349125 * (1.0 - std::max<double>(0.0, fSlow3)));
	double fSlow5 = std::pow(10.0, (2.0 * fSlow1));
	double fSlow6 = (1.0 - std::max<double>(0.0, (-1.0 * fSlow3)));
	double fSlow7 = std::pow(10.0, (1.2 * fSlow1));
	double fSlow8 = std::pow(10.0, (0.80000000000000004 * fSlow1));
	double fSlow9 = (fConst59 * fSlow5);
	double fSlow10 = (fConst59 * std::pow(10.0, (0.90000000000000002 * fSlow1)));
	double fSlow11 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider2))));
	double fSlow12 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider3))));
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = (fRec5[1] + 1.0000000000000001e-15);
		fVec0[0] = fTemp0;
		fRec9[0] = ((0.93028479253239138 * (fTemp0 + fVec0[1])) - (0.86056958506478287 * fRec9[1]));
		fRec8[0] = (fRec9[0] - ((1.8405051250752198 * fRec8[1]) + (0.86129424393186271 * fRec8[2])));
		double fTemp1 = ((0.0082000000000000007 * fRec7[1]) + 1.0000000000000001e-15);
		fVec1[0] = fTemp1;
		fRec10[0] = (0.0 - (fConst9 * ((fConst10 * fRec10[1]) - (fTemp1 + fVec1[1]))));
		fRec7[0] = (double(Ftube(int(TUBE_TABLE_6DJ8_250k), double((((0.92544984225177063 * (fRec8[0] + fRec8[2])) + (fRec10[0] + (1.8508996845035413 * fRec8[1]))) + -0.79704299999999995)))) + -32.799634146341475);
		fRec6[0] = ((0.050000000000000003 * ((fConst4 * fRec7[0]) + (fConst11 * fRec7[1]))) - (fConst12 * fRec6[1]));
		double fTemp2 = (fRec16[1] + 1.0000000000000001e-15);
		fVec2[0] = fTemp2;
		fRec20[0] = ((0.93028479253239138 * (fTemp2 + fVec2[1])) - (0.86056958506478287 * fRec20[1]));
		fRec19[0] = (fRec20[0] - ((1.8405051250752198 * fRec19[1]) + (0.86129424393186271 * fRec19[2])));
		double fTemp3 = ((0.014999999999999999 * fRec18[1]) + 1.0000000000000001e-15);
		fVec3[0] = fTemp3;
		fRec21[0] = (0.0 - (fConst14 * ((fConst15 * fRec21[1]) - (fTemp3 + fVec3[1]))));
		fRec18[0] = (double(Ftube(int(TUBE_TABLE_6DJ8_250k), double((((0.92544984225177063 * (fRec19[0] + fRec19[2])) + (fRec21[0] + (1.8508996845035413 * fRec19[1]))) + -1.271609)))) + -45.226066666666668);
		fRec17[0] = ((0.050000000000000003 * ((fConst4 * fRec18[0]) + (fConst11 * fRec18[1]))) - (fConst12 * fRec17[1]));
		double fTemp4 = double(input0[i]);
		double fTemp5 = std::fabs(fTemp4);
		fRec26[0] = ((0.99990000000000001 * fRec26[1]) + (9.9999999999988987e-05 * fTemp5));
		double fTemp6 = std::max<double>(fRec26[0], fTemp5);
		fVec4[(IOTA & 32767)] = fTemp6;
		fRec28[0] = ((fTemp6 + fRec28[1]) - fVec4[((IOTA - iConst17) & 32767)]);
		fRec27[0] = ((0.999 * fRec27[1]) + (fConst16 * fRec28[0]));
		double fTemp7 = std::max<double>(-1.0, std::min<double>(-0.01, (fTemp6 + (-1.0 - (1.02 * fRec27[0])))));
		double fTemp8 = (fTemp4 - fTemp7);
		double fTemp9 = (40.100000000000001 * fTemp8);
		double fTemp10 = std::max<double>(-600.0, fTemp9);
		double fTemp11 = (0.0 - (40.100000000000001 * fTemp7));
		double fTemp12 = std::max<double>(-600.0, fTemp11);
		double fTemp13 = (((std::fabs(fTemp9) > 0.0001)?((fTemp10 < -50.0)?(0.0 - (fTemp10 * std::exp(fTemp10))):(fTemp10 / (1.0 - std::exp((-1.0 * fTemp10))))):((fTemp8 * ((134.00083333333336 * fTemp8) + 20.050000000000001)) + 1.0)) - ((std::fabs(fTemp11) > 0.0001)?((fTemp12 < -50.0)?(0.0 - (fTemp12 * std::exp(fTemp12))):(fTemp12 / (1.0 - std::exp((-1.0 * fTemp12))))):((fTemp11 * ((0.083333333333333329 * fTemp11) + 0.5)) + 1.0)));
		fRec29[0] = (fSlow0 + (0.999 * fRec29[1]));
		double fTemp14 = (1.0 - fRec29[0]);
		double fTemp15 = (0.024937655860349125 * (fRec29[0] * fTemp13));
		double fTemp16 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow5 * std::max<double>(-0.69999999999999996, std::min<double>(0.69999999999999996, fTemp15)))));
		fRec37[0] = (fTemp15 - (fConst33 * ((fConst34 * fRec37[2]) + (fConst35 * fRec37[1]))));
		double fTemp17 = (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])));
		fVec5[0] = fTemp17;
		fRec36[0] = ((fConst33 * ((fConst4 * fTemp17) + (fConst11 * fVec5[1]))) - (fConst12 * fRec36[1]));
		fRec35[0] = (0.0 - (fConst29 * ((fConst30 * fRec35[1]) - (fRec36[0] + fRec36[1]))));
		fRec34[0] = (fRec35[0] - (fConst25 * ((fConst36 * fRec34[2]) + (fConst39 * fRec34[1]))));
		double fTemp18 = (fRec34[2] + (fRec34[0] + (2.0 * fRec34[1])));
		fVec6[0] = fTemp18;
		fRec33[0] = ((fConst25 * ((fConst27 * fTemp18) + (fConst40 * fVec6[1]))) - (fConst42 * fRec33[1]));
		fRec32[0] = (fRec33[0] - (fConst20 * ((fConst43 * fRec32[2]) + (fConst44 * fRec32[1]))));
		double fTemp19 = (fConst54 * fRec31[1]);
		fRec31[0] = ((fConst20 * (((fConst22 * fRec32[0]) + (fConst45 * fRec32[1])) + (fConst22 * fRec32[2]))) - (fConst49 * ((fConst51 * fRec31[2]) + fTemp19)));
		double fTemp20 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow7 * (fRec31[2] + (fConst49 * (fTemp19 + (fConst51 * fRec31[0])))))));
		fRec41[0] = ((fConst55 * fRec36[1]) - (fConst29 * ((fConst30 * fRec41[1]) - (fConst24 * fRec36[0]))));
		fRec40[0] = (fRec41[0] - (fConst25 * ((fConst36 * fRec40[2]) + (fConst39 * fRec40[1]))));
		double fTemp21 = (fConst44 * fRec39[1]);
		fRec39[0] = ((fConst25 * (((fConst38 * fRec40[0]) + (fConst56 * fRec40[1])) + (fConst38 * fRec40[2]))) - (fConst57 * ((fConst58 * fRec39[2]) + fTemp21)));
		double fTemp22 = (fConst54 * fRec38[1]);
		fRec38[0] = ((fRec39[2] + (fConst57 * (fTemp21 + (fConst58 * fRec39[0])))) - (fConst49 * ((fConst51 * fRec38[2]) + fTemp22)));
		double fTemp23 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow8 * (fRec38[2] + (fConst49 * (fTemp22 + (fConst51 * fRec38[0])))))));
		fRec45[0] = (0.0 - (fConst61 * ((fConst41 * fRec45[1]) - (fConst25 * (fTemp18 + fVec6[1])))));
		fRec44[0] = (fRec45[0] - (fConst20 * ((fConst43 * fRec44[2]) + (fConst44 * fRec44[1]))));
		double fTemp24 = (fRec44[2] + (fRec44[0] + (2.0 * fRec44[1])));
		fVec7[0] = fTemp24;
		fRec43[0] = ((fConst20 * ((fConst60 * fTemp24) + (fConst62 * fVec7[1]))) - (fConst63 * fRec43[1]));
		fRec42[0] = (fRec43[0] - (fConst59 * ((fConst64 * fRec42[2]) + (fConst54 * fRec42[1]))));
		double fTemp25 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow9 * (((fConst53 * fRec42[0]) + (fConst65 * fRec42[1])) + (fConst53 * fRec42[2])))));
		fRec47[0] = (0.0 - (fConst66 * ((fConst50 * fRec47[1]) - (fConst20 * (fTemp24 + fVec7[1])))));
		fRec46[0] = (fRec47[0] - (fConst59 * ((fConst64 * fRec46[2]) + (fConst54 * fRec46[1]))));
		double fTemp26 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow10 * (fRec46[2] + (fRec46[0] + (2.0 * fRec46[1]))))));
		double fTemp27 = (((1.333521432 * (fTemp20 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp20))))) + (1.584893192 * ((fTemp23 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp23)))) + (fTemp25 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp25))))))) + (1.2589412 * (fTemp26 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp26))))));
		fVec8[0] = fTemp27;
		fRec30[0] = (0.0 - (fConst6 * ((fConst7 * fRec30[1]) - (fTemp27 + fVec8[1]))));
		double fTemp28 = (((fTemp13 * ((fTemp14 * ((fSlow2 * ((0.099750623441396499 * (1.0 - std::fabs((0.024937655860349125 * (fTemp14 * fTemp13))))) + -0.024937655860349125)) + 0.024937655860349125)) + (fSlow4 * fRec29[0]))) + ((0.5 * (fTemp16 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp16))))) + (fSlow6 * fRec30[0]))) + 1.0000000000000001e-15);
		fVec9[0] = fTemp28;
		fRec25[0] = ((0.93028479253239138 * (fTemp28 + fVec9[1])) - (0.86056958506478287 * fRec25[1]));
		fRec24[0] = (fRec25[0] - ((1.8405051250752198 * fRec24[1]) + (0.86129424393186271 * fRec24[2])));
		double fTemp29 = ((0.027 * fRec23[1]) + 1.0000000000000001e-15);
		fVec10[0] = fTemp29;
		fRec48[0] = (0.0 - (fConst68 * ((fConst69 * fRec48[1]) - (fTemp29 + fVec10[1]))));
		fRec23[0] = (double(Ftube(int(TUBE_TABLE_6DJ8_68k), double((((0.92544984225177063 * (fRec24[0] + fRec24[2])) + (fRec48[0] + (1.8508996845035413 * fRec24[1]))) + -1.8639460000000001)))) + -60.964962962962957);
		fRec22[0] = ((0.050000000000000003 * ((fConst4 * fRec23[0]) + (fConst11 * fRec23[1]))) - (fConst12 * fRec22[1]));
		fRec16[0] = ((0.59999999999999998 * fRec17[0]) - fRec22[0]);
		fRec49[0] = (fSlow11 + (0.999 * fRec49[1]));
		double fTemp30 = (fRec16[0] * fRec49[0]);
		fVec11[0] = fTemp30;
		fRec15[0] = (0.0 - (fConst6 * ((fConst7 * fRec15[1]) - (fTemp30 + fVec11[1]))));
		double fTemp31 = (fRec15[0] + 1.0000000000000001e-15);
		fVec12[0] = fTemp31;
		fRec14[0] = ((0.93028479253239138 * (fTemp31 + fVec12[1])) - (0.86056958506478287 * fRec14[1]));
		fRec13[0] = (fRec14[0] - ((1.8405051250752198 * fRec13[1]) + (0.86129424393186271 * fRec13[2])));
		double fTemp32 = ((0.014999999999999999 * fRec12[1]) + 1.0000000000000001e-15);
		fVec13[0] = fTemp32;
		fRec50[0] = (0.0 - (fConst14 * ((fConst15 * fRec50[1]) - (fTemp32 + fVec13[1]))));
		fRec12[0] = (double(Ftube(int(TUBE_TABLE_6DJ8_250k), double((((0.92544984225177063 * (fRec13[0] + fRec13[2])) + (fRec50[0] + (1.8508996845035413 * fRec13[1]))) + -1.271609)))) + -45.226066666666668);
		fRec11[0] = ((0.050000000000000003 * ((fConst4 * fRec12[0]) + (fConst11 * fRec12[1]))) - (fConst12 * fRec11[1]));
		fRec5[0] = ((0.59999999999999998 * fRec6[0]) + fRec11[0]);
		fRec4[0] = (0.0 - (fConst6 * ((fConst7 * fRec4[1]) - (fRec5[0] + fRec5[1]))));
		double fTemp33 = (fRec4[0] + 1.0000000000000001e-15);
		fVec14[0] = fTemp33;
		fRec3[0] = ((0.93028479253239138 * (fTemp33 + fVec14[1])) - (0.86056958506478287 * fRec3[1]));
		fRec2[0] = (fRec3[0] - ((1.8405051250752198 * fRec2[1]) + (0.86129424393186271 * fRec2[2])));
		double fTemp34 = ((0.0082000000000000007 * fRec1[1]) + 1.0000000000000001e-15);
		fVec15[0] = fTemp34;
		fRec51[0] = (0.0 - (fConst9 * ((fConst10 * fRec51[1]) - (fTemp34 + fVec15[1]))));
		fRec1[0] = (double(Ftube(int(TUBE_TABLE_6DJ8_250k), double((((0.92544984225177063 * (fRec2[0] + fRec2[2])) + (fRec51[0] + (1.8508996845035413 * fRec2[1]))) + -0.79704299999999995)))) + -32.799634146341475);
		fRec0[0] = ((0.050000000000000003 * ((fConst4 * fRec1[0]) + (fConst11 * fRec1[1]))) - (fConst12 * fRec0[1]));
		fRec52[0] = (fSlow12 + (0.999 * fRec52[1]));
		output0[i] = FAUSTFLOAT((fRec0[0] * fRec52[0]));
		fVec0[1] = fVec0[0];
		fRec9[1] = fRec9[0];
		fRec8[2] = fRec8[1];
		fRec8[1] = fRec8[0];
		fVec1[1] = fVec1[0];
		fRec10[1] = fRec10[0];
		fRec7[1] = fRec7[0];
		fRec6[1] = fRec6[0];
		fVec2[1] = fVec2[0];
		fRec20[1] = fRec20[0];
		fRec19[2] = fRec19[1];
		fRec19[1] = fRec19[0];
		fVec3[1] = fVec3[0];
		fRec21[1] = fRec21[0];
		fRec18[1] = fRec18[0];
		fRec17[1] = fRec17[0];
		fRec26[1] = fRec26[0];
		IOTA = (IOTA + 1);
		fRec28[1] = fRec28[0];
		fRec27[1] = fRec27[0];
		fRec29[1] = fRec29[0];
		fRec37[2] = fRec37[1];
		fRec37[1] = fRec37[0];
		fVec5[1] = fVec5[0];
		fRec36[1] = fRec36[0];
		fRec35[1] = fRec35[0];
		fRec34[2] = fRec34[1];
		fRec34[1] = fRec34[0];
		fVec6[1] = fVec6[0];
		fRec33[1] = fRec33[0];
		fRec32[2] = fRec32[1];
		fRec32[1] = fRec32[0];
		fRec31[2] = fRec31[1];
		fRec31[1] = fRec31[0];
		fRec41[1] = fRec41[0];
		fRec40[2] = fRec40[1];
		fRec40[1] = fRec40[0];
		fRec39[2] = fRec39[1];
		fRec39[1] = fRec39[0];
		fRec38[2] = fRec38[1];
		fRec38[1] = fRec38[0];
		fRec45[1] = fRec45[0];
		fRec44[2] = fRec44[1];
		fRec44[1] = fRec44[0];
		fVec7[1] = fVec7[0];
		fRec43[1] = fRec43[0];
		fRec42[2] = fRec42[1];
		fRec42[1] = fRec42[0];
		fRec47[1] = fRec47[0];
		fRec46[2] = fRec46[1];
		fRec46[1] = fRec46[0];
		fVec8[1] = fVec8[0];
		fRec30[1] = fRec30[0];
		fVec9[1] = fVec9[0];
		fRec25[1] = fRec25[0];
		fRec24[2] = fRec24[1];
		fRec24[1] = fRec24[0];
		fVec10[1] = fVec10[0];
		fRec48[1] = fRec48[0];
		fRec23[1] = fRec23[0];
		fRec22[1] = fRec22[0];
		fRec16[1] = fRec16[0];
		fRec49[1] = fRec49[0];
		fVec11[1] = fVec11[0];
		fRec15[1] = fRec15[0];
		fVec12[1] = fVec12[0];
		fRec14[1] = fRec14[0];
		fRec13[2] = fRec13[1];
		fRec13[1] = fRec13[0];
		fVec13[1] = fVec13[0];
		fRec50[1] = fRec50[0];
		fRec12[1] = fRec12[0];
		fRec11[1] = fRec11[0];
		fRec5[1] = fRec5[0];
		fRec4[1] = fRec4[0];
		fVec14[1] = fVec14[0];
		fRec3[1] = fRec3[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fVec15[1] = fVec15[0];
		fRec51[1] = fRec51[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
		fRec52[1] = fRec52[0];
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
#undef fVslider3
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case DRIVE: 
		fVslider1_ = (float*)data; // , 0.34999999999999998, 0.0, 1.0, 0.01 
		break;
	case WET_DRY: 
		fVslider0_ = (float*)data; // , 100.0, 0.0, 100.0, 1.0 
		break;
	case PREGAIN: 
		fVslider2_ = (float*)data; // , -6.0, -20.0, 20.0, 0.10000000000000001 
		break;
	case GAIN1: 
		fVslider3_ = (float*)data; // , -6.0, -20.0, 20.0, 0.10000000000000001 
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
   DRIVE, 
   WET_DRY, 
   PREGAIN, 
   GAIN1, 
} PortIndex;
*/

} // end namespace gxamp13
