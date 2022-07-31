// generated from file '../src/LV2/faust/gxamp5.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)

#include "valve.h"

namespace gxamp5 {

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
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fConst8;
	double fConst9;
	double fConst10;
	double fConst11;
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
	double fConst22;
	double fConst23;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fRec26[2];
	double fVec0[2];
	double fRec25[2];
	double fRec24[3];
	double fConst24;
	double fConst25;
	double fConst26;
	double fVec1[2];
	double fRec27[2];
	double fRec23[2];
	double fConst27;
	double fConst28;
	double fRec22[2];
	double fRec21[2];
	double fVec2[2];
	double fRec20[2];
	double fRec19[3];
	double fConst29;
	double fConst30;
	double fConst31;
	double fVec3[2];
	double fRec28[2];
	double fRec18[2];
	double fRec17[2];
	double fVec4[2];
	double fRec16[2];
	double fRec15[3];
	double fConst32;
	double fConst33;
	double fConst34;
	double fVec5[2];
	double fRec29[2];
	double fRec14[2];
	double fRec13[2];
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec30[2];
	double fConst35;
	double fConst36;
	double fRec12[3];
	double fVec6[2];
	double fRec11[2];
	double fRec10[2];
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fRec9[3];
	double fVec7[2];
	double fConst41;
	double fConst42;
	double fConst43;
	double fRec8[2];
	double fConst44;
	double fConst45;
	double fRec7[3];
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;
	double fConst54;
	double fConst55;
	double fRec6[3];
	double fConst56;
	double fRec34[2];
	double fRec33[3];
	double fConst57;
	double fConst58;
	double fConst59;
	double fRec32[3];
	double fRec31[3];
	double fConst60;
	double fConst61;
	double fConst62;
	double fRec38[2];
	double fRec37[3];
	double fVec8[2];
	double fConst63;
	double fConst64;
	double fRec36[2];
	double fConst65;
	double fRec35[3];
	double fConst66;
	double fConst67;
	double fRec40[2];
	double fRec39[3];
	double fVec9[2];
	double fRec5[2];
	double fVec10[2];
	double fRec4[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec41[2];
	double fVec11[2];
	double fRec3[2];
	double fRec2[3];
	double fVec12[2];
	double fRec42[2];
	double fRec1[2];
	double fRec0[2];
	double fVec13[2];
	double fRec45[2];
	double fRec44[2];
	double fRec43[2];

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
	id = "pre 12ax7/ master 6V6";
	name = N_("pre 12ax7/ master 6V6");
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
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fRec26[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec0[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec25[l2] = 0.0;
	for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) fRec24[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fVec1[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec27[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec23[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec22[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec21[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fVec2[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec20[l10] = 0.0;
	for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) fRec19[l11] = 0.0;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fVec3[l12] = 0.0;
	for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) fRec28[l13] = 0.0;
	for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) fRec18[l14] = 0.0;
	for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) fRec17[l15] = 0.0;
	for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) fVec4[l16] = 0.0;
	for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) fRec16[l17] = 0.0;
	for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) fRec15[l18] = 0.0;
	for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) fVec5[l19] = 0.0;
	for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) fRec29[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fRec14[l21] = 0.0;
	for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) fRec13[l22] = 0.0;
	for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) fRec30[l23] = 0.0;
	for (int l24 = 0; (l24 < 3); l24 = (l24 + 1)) fRec12[l24] = 0.0;
	for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) fVec6[l25] = 0.0;
	for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) fRec11[l26] = 0.0;
	for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) fRec10[l27] = 0.0;
	for (int l28 = 0; (l28 < 3); l28 = (l28 + 1)) fRec9[l28] = 0.0;
	for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) fVec7[l29] = 0.0;
	for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) fRec8[l30] = 0.0;
	for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) fRec7[l31] = 0.0;
	for (int l32 = 0; (l32 < 3); l32 = (l32 + 1)) fRec6[l32] = 0.0;
	for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) fRec34[l33] = 0.0;
	for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) fRec33[l34] = 0.0;
	for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) fRec32[l35] = 0.0;
	for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) fRec31[l36] = 0.0;
	for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) fRec38[l37] = 0.0;
	for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) fRec37[l38] = 0.0;
	for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) fVec8[l39] = 0.0;
	for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) fRec36[l40] = 0.0;
	for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) fRec35[l41] = 0.0;
	for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) fRec40[l42] = 0.0;
	for (int l43 = 0; (l43 < 3); l43 = (l43 + 1)) fRec39[l43] = 0.0;
	for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) fVec9[l44] = 0.0;
	for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) fRec5[l45] = 0.0;
	for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) fVec10[l46] = 0.0;
	for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) fRec4[l47] = 0.0;
	for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) fRec41[l48] = 0.0;
	for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) fVec11[l49] = 0.0;
	for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) fRec3[l50] = 0.0;
	for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) fRec2[l51] = 0.0;
	for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) fVec12[l52] = 0.0;
	for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) fRec42[l53] = 0.0;
	for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) fRec1[l54] = 0.0;
	for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) fRec0[l55] = 0.0;
	for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) fVec13[l56] = 0.0;
	for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) fRec45[l57] = 0.0;
	for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) fRec44[l58] = 0.0;
	for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) fRec43[l59] = 0.0;
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
	fConst8 = std::tan((3769.9111843077517 / fConst0));
	fConst9 = (1.0 / fConst8);
	fConst10 = (1.0 / (((fConst9 + 1.0000000000000004) / fConst8) + 1.0));
	fConst11 = mydsp_faustpower2_f(fConst8);
	fConst12 = (1.0 / fConst11);
	fConst13 = std::tan((10053.096491487338 / fConst0));
	fConst14 = (1.0 / fConst13);
	fConst15 = (1.0 / (((fConst14 + 1.0000000000000004) / fConst13) + 1.0));
	fConst16 = (fConst9 + 1.0);
	fConst17 = (1.0 / (fConst8 * fConst16));
	fConst18 = (fConst14 + 1.0);
	fConst19 = (1.0 / fConst18);
	fConst20 = (1.0 - fConst14);
	fConst21 = std::tan((47123.889803846898 / fConst0));
	fConst22 = (1.0 / fConst21);
	fConst23 = (1.0 / (((fConst22 + 1.4142135623730949) / fConst21) + 1.0));
	fConst24 = (1.0 / std::tan((270.1769682087222 / fConst0)));
	fConst25 = (1.0 / (fConst24 + 1.0));
	fConst26 = (1.0 - fConst24);
	fConst27 = (0.0 - fConst4);
	fConst28 = ((1.0 - fConst2) / fConst3);
	fConst29 = (1.0 / std::tan((414.69023027385271 / fConst0)));
	fConst30 = (1.0 / (fConst29 + 1.0));
	fConst31 = (1.0 - fConst29);
	fConst32 = (1.0 / std::tan((609.46897479641984 / fConst0)));
	fConst33 = (1.0 / (fConst32 + 1.0));
	fConst34 = (1.0 - fConst32);
	fConst35 = (((fConst22 + -1.4142135623730949) / fConst21) + 1.0);
	fConst36 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst21))));
	fConst37 = (((fConst14 + -1.0000000000000004) / fConst13) + 1.0);
	fConst38 = mydsp_faustpower2_f(fConst13);
	fConst39 = (1.0 / fConst38);
	fConst40 = (2.0 * (1.0 - fConst39));
	fConst41 = (0.0 - fConst17);
	fConst42 = (1.0 - fConst9);
	fConst43 = (fConst42 / fConst16);
	fConst44 = (((fConst9 + -1.0000000000000004) / fConst8) + 1.0);
	fConst45 = (2.0 * (1.0 - fConst12));
	fConst46 = (0.0 - (2.0 / fConst11));
	fConst47 = std::tan((942.47779607693792 / fConst0));
	fConst48 = (1.0 / fConst47);
	fConst49 = (fConst48 + 1.0);
	fConst50 = (1.0 / ((fConst49 / fConst47) + 1.0));
	fConst51 = (1.0 - fConst48);
	fConst52 = (1.0 - (fConst51 / fConst47));
	fConst53 = mydsp_faustpower2_f(fConst47);
	fConst54 = (1.0 / fConst53);
	fConst55 = (2.0 * (1.0 - fConst54));
	fConst56 = (0.0 - (1.0 / (fConst18 * fConst13)));
	fConst57 = (0.0 - (2.0 / fConst38));
	fConst58 = (1.0 / ((fConst16 / fConst8) + 1.0));
	fConst59 = (1.0 - (fConst42 / fConst8));
	fConst60 = (1.0 / (((fConst48 + 1.0000000000000004) / fConst47) + 1.0));
	fConst61 = (1.0 / (fConst47 * fConst49));
	fConst62 = (1.0 / fConst16);
	fConst63 = (0.0 - fConst61);
	fConst64 = (fConst51 / fConst49);
	fConst65 = (((fConst48 + -1.0000000000000004) / fConst47) + 1.0);
	fConst66 = (0.0 - (2.0 / fConst53));
	fConst67 = (1.0 / fConst49);
	fVslider0 = FAUSTFLOAT(0.34999999999999998);
	fVslider1 = FAUSTFLOAT(-6.0);
	fVslider2 = FAUSTFLOAT(100.0);
	fVslider3 = FAUSTFLOAT(-6.0);
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
	double fSlow0 = double(fVslider0);
	double fSlow1 = (2.0 * (fSlow0 + -0.5));
	double fSlow2 = (1.0 - std::max<double>(0.0, (-1.0 * fSlow1)));
	double fSlow3 = std::pow(10.0, (1.2 * fSlow0));
	double fSlow4 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider1))));
	double fSlow5 = (1.0000000000000009e-05 * double(fVslider2));
	double fSlow6 = std::pow(10.0, (0.80000000000000004 * fSlow0));
	double fSlow7 = (fConst60 * std::pow(10.0, (2.0 * fSlow0)));
	double fSlow8 = (fConst60 * std::pow(10.0, (0.90000000000000002 * fSlow0)));
	double fSlow9 = (1.25 * fSlow0);
	double fSlow10 = (1.0 - std::max<double>(0.0, fSlow1));
	double fSlow11 = (0.0010000000000000009 * std::pow(10.0, (0.050000000000000003 * double(fVslider3))));
	for (int i = 0; (i < count); i = (i + 1)) {
		fRec26[0] = (fSlow4 + (0.999 * fRec26[1]));
		double fTemp0 = ((fRec26[0] * double(input0[i])) + 1.0000000000000001e-15);
		fVec0[0] = fTemp0;
		fRec25[0] = ((0.93028479253239138 * (fTemp0 + fVec0[1])) - (0.86056958506478287 * fRec25[1]));
		fRec24[0] = (fRec25[0] - ((1.8405051250752198 * fRec24[1]) + (0.86129424393186271 * fRec24[2])));
		double fTemp1 = ((0.027 * fRec23[1]) + 1.0000000000000001e-15);
		fVec1[0] = fTemp1;
		fRec27[0] = (0.0 - (fConst25 * ((fConst26 * fRec27[1]) - (fTemp1 + fVec1[1]))));
		fRec23[0] = (double(Ftube(int(TUBE_TABLE_12AX7_68k), double((((0.92544984225177063 * (fRec24[0] + fRec24[2])) + (fRec27[0] + (1.8508996845035413 * fRec24[1]))) + -1.581656)))) + -191.42014814814814);
		fRec22[0] = ((0.025000000000000001 * ((fConst4 * fRec23[0]) + (fConst27 * fRec23[1]))) - (fConst28 * fRec22[1]));
		fRec21[0] = (0.0 - (fConst6 * ((fConst7 * fRec21[1]) - (fRec22[0] + fRec22[1]))));
		double fTemp2 = (fRec21[0] + 1.0000000000000001e-15);
		fVec2[0] = fTemp2;
		fRec20[0] = ((0.93028479253239138 * (fTemp2 + fVec2[1])) - (0.86056958506478287 * fRec20[1]));
		fRec19[0] = (fRec20[0] - ((1.8405051250752198 * fRec19[1]) + (0.86129424393186271 * fRec19[2])));
		double fTemp3 = ((0.014999999999999999 * fRec18[1]) + 1.0000000000000001e-15);
		fVec3[0] = fTemp3;
		fRec28[0] = (0.0 - (fConst30 * ((fConst31 * fRec28[1]) - (fTemp3 + fVec3[1]))));
		fRec18[0] = (double(Ftube(int(TUBE_TABLE_12AX7_250k), double((((0.92544984225177063 * (fRec19[0] + fRec19[2])) + (fRec28[0] + (1.8508996845035413 * fRec19[1]))) + -1.204285)))) + -169.71433333333334);
		fRec17[0] = ((0.025000000000000001 * ((fConst4 * fRec18[0]) + (fConst27 * fRec18[1]))) - (fConst28 * fRec17[1]));
		double fTemp4 = (fRec17[0] + 1.0000000000000001e-15);
		fVec4[0] = fTemp4;
		fRec16[0] = ((0.93028479253239138 * (fTemp4 + fVec4[1])) - (0.86056958506478287 * fRec16[1]));
		fRec15[0] = (fRec16[0] - ((1.8405051250752198 * fRec15[1]) + (0.86129424393186271 * fRec15[2])));
		double fTemp5 = ((0.0082000000000000007 * fRec14[1]) + 1.0000000000000001e-15);
		fVec5[0] = fTemp5;
		fRec29[0] = (0.0 - (fConst33 * ((fConst34 * fRec29[1]) - (fTemp5 + fVec5[1]))));
		fRec14[0] = (double(Ftube(int(TUBE_TABLE_12AX7_250k), double((((0.92544984225177063 * (fRec15[0] + fRec15[2])) + (fRec29[0] + (1.8508996845035413 * fRec15[1]))) + -0.84070299999999998)))) + -147.47524390243905);
		fRec13[0] = ((0.025000000000000001 * ((fConst4 * fRec14[0]) + (fConst27 * fRec14[1]))) - (fConst28 * fRec13[1]));
		fRec30[0] = (fSlow5 + (0.999 * fRec30[1]));
		double fTemp6 = (fRec13[0] * fRec30[0]);
		fRec12[0] = (fTemp6 + (1.0000000000000001e-15 - (fConst23 * ((fConst35 * fRec12[2]) + (fConst36 * fRec12[1])))));
		double fTemp7 = (fRec12[2] + (fRec12[0] + (2.0 * fRec12[1])));
		fVec6[0] = fTemp7;
		fRec11[0] = ((fConst23 * ((fConst4 * fTemp7) + (fConst27 * fVec6[1]))) - (fConst28 * fRec11[1]));
		fRec10[0] = (0.0 - (fConst19 * ((fConst20 * fRec10[1]) - (fRec11[0] + fRec11[1]))));
		fRec9[0] = (fRec10[0] - (fConst15 * ((fConst37 * fRec9[2]) + (fConst40 * fRec9[1]))));
		double fTemp8 = (fRec9[2] + (fRec9[0] + (2.0 * fRec9[1])));
		fVec7[0] = fTemp8;
		fRec8[0] = ((fConst15 * ((fConst17 * fTemp8) + (fConst41 * fVec7[1]))) - (fConst43 * fRec8[1]));
		fRec7[0] = (fRec8[0] - (fConst10 * ((fConst44 * fRec7[2]) + (fConst45 * fRec7[1]))));
		double fTemp9 = (fConst55 * fRec6[1]);
		fRec6[0] = ((fConst10 * (((fConst12 * fRec7[0]) + (fConst46 * fRec7[1])) + (fConst12 * fRec7[2]))) - (fConst50 * ((fConst52 * fRec6[2]) + fTemp9)));
		double fTemp10 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow3 * (fRec6[2] + (fConst50 * (fTemp9 + (fConst52 * fRec6[0])))))));
		fRec34[0] = ((fConst56 * fRec11[1]) - (fConst19 * ((fConst20 * fRec34[1]) - (fConst14 * fRec11[0]))));
		fRec33[0] = (fRec34[0] - (fConst15 * ((fConst37 * fRec33[2]) + (fConst40 * fRec33[1]))));
		double fTemp11 = (fConst45 * fRec32[1]);
		fRec32[0] = ((fConst15 * (((fConst39 * fRec33[0]) + (fConst57 * fRec33[1])) + (fConst39 * fRec33[2]))) - (fConst58 * ((fConst59 * fRec32[2]) + fTemp11)));
		double fTemp12 = (fConst55 * fRec31[1]);
		fRec31[0] = ((fRec32[2] + (fConst58 * (fTemp11 + (fConst59 * fRec32[0])))) - (fConst50 * ((fConst52 * fRec31[2]) + fTemp12)));
		double fTemp13 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow6 * (fRec31[2] + (fConst50 * (fTemp12 + (fConst52 * fRec31[0])))))));
		fRec38[0] = (0.0 - (fConst62 * ((fConst42 * fRec38[1]) - (fConst15 * (fTemp8 + fVec7[1])))));
		fRec37[0] = (fRec38[0] - (fConst10 * ((fConst44 * fRec37[2]) + (fConst45 * fRec37[1]))));
		double fTemp14 = (fRec37[2] + (fRec37[0] + (2.0 * fRec37[1])));
		fVec8[0] = fTemp14;
		fRec36[0] = ((fConst10 * ((fConst61 * fTemp14) + (fConst63 * fVec8[1]))) - (fConst64 * fRec36[1]));
		fRec35[0] = (fRec36[0] - (fConst60 * ((fConst65 * fRec35[2]) + (fConst55 * fRec35[1]))));
		double fTemp15 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow7 * (((fConst54 * fRec35[0]) + (fConst66 * fRec35[1])) + (fConst54 * fRec35[2])))));
		fRec40[0] = (0.0 - (fConst67 * ((fConst51 * fRec40[1]) - (fConst10 * (fTemp14 + fVec8[1])))));
		fRec39[0] = (fRec40[0] - (fConst60 * ((fConst65 * fRec39[2]) + (fConst55 * fRec39[1]))));
		double fTemp16 = std::max<double>(-1.0, std::min<double>(1.0, (fSlow8 * (fRec39[2] + (fRec39[0] + (2.0 * fRec39[1]))))));
		double fTemp17 = (((1.333521432 * (fTemp10 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp10))))) + (1.584893192 * ((fTemp13 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp13)))) + (fTemp15 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp15))))))) + (1.2589412 * (fTemp16 * (1.0 - (0.33333333333333331 * mydsp_faustpower2_f(fTemp16))))));
		fVec9[0] = fTemp17;
		fRec5[0] = (0.0 - (fConst6 * ((fConst7 * fRec5[1]) - (fTemp17 + fVec9[1]))));
		double fTemp18 = (fRec13[0] * (1.0 - fRec30[0]));
		double fTemp19 = (fTemp18 + 1.0000000000000001e-15);
		double fTemp20 = (((fSlow2 * fRec5[0]) + ((fTemp18 + (fSlow9 * ((4.0 * (fTemp19 * (1.0 - std::fabs(fTemp19)))) + (-1.0000000000000001e-15 - fTemp18)))) + (fSlow10 * (fTemp6 + 1.0000000000000001e-15)))) + 1.0000000000000001e-15);
		fVec10[0] = fTemp20;
		fRec4[0] = (0.0 - (fConst6 * ((fConst7 * fRec4[1]) - (fTemp20 + fVec10[1]))));
		fRec41[0] = (fSlow11 + (0.999 * fRec41[1]));
		double fTemp21 = ((fRec4[0] * fRec41[0]) + 1.0000000000000001e-15);
		fVec11[0] = fTemp21;
		fRec3[0] = ((0.93028479253239138 * (fTemp21 + fVec11[1])) - (0.86056958506478287 * fRec3[1]));
		fRec2[0] = (fRec3[0] - ((1.8405051250752198 * fRec2[1]) + (0.86129424393186271 * fRec2[2])));
		double fTemp22 = (0.92544984225177063 * (fRec2[0] + fRec2[2]));
		double fTemp23 = ((0.0082000000000000007 * fRec1[1]) + 1.0000000000000001e-15);
		fVec12[0] = fTemp23;
		fRec42[0] = (0.0 - (fConst6 * ((fConst7 * fRec42[1]) - (fTemp23 + fVec12[1]))));
		double fTemp24 = (1.8508996845035413 * fRec2[1]);
		fRec1[0] = (double(Ftube(int(TUBE_TABLE_6V6_250k), double(((fTemp22 + (fRec42[0] + fTemp24)) + -1.1304620000000001)))) + -112.13878048780487);
		fRec0[0] = ((0.025000000000000001 * ((fConst4 * fRec1[0]) + (fConst27 * fRec1[1]))) - (fConst28 * fRec0[1]));
		double fTemp25 = ((0.0082000000000000007 * fRec44[1]) + 1.0000000000000001e-15);
		fVec13[0] = fTemp25;
		fRec45[0] = (0.0 - (fConst6 * ((fConst7 * fRec45[1]) - (fTemp25 + fVec13[1]))));
		fRec44[0] = (double(Ftube(int(TUBE_TABLE_6V6_68k), double(((fTemp22 + (fRec45[0] + fTemp24)) + -1.1307400000000001)))) + -112.10487804878048);
		fRec43[0] = ((0.025000000000000001 * ((fConst4 * fRec44[0]) + (fConst27 * fRec44[1]))) - (fConst28 * fRec43[1]));
		output0[i] = FAUSTFLOAT((fRec0[0] + fRec43[0]));
		fRec26[1] = fRec26[0];
		fVec0[1] = fVec0[0];
		fRec25[1] = fRec25[0];
		fRec24[2] = fRec24[1];
		fRec24[1] = fRec24[0];
		fVec1[1] = fVec1[0];
		fRec27[1] = fRec27[0];
		fRec23[1] = fRec23[0];
		fRec22[1] = fRec22[0];
		fRec21[1] = fRec21[0];
		fVec2[1] = fVec2[0];
		fRec20[1] = fRec20[0];
		fRec19[2] = fRec19[1];
		fRec19[1] = fRec19[0];
		fVec3[1] = fVec3[0];
		fRec28[1] = fRec28[0];
		fRec18[1] = fRec18[0];
		fRec17[1] = fRec17[0];
		fVec4[1] = fVec4[0];
		fRec16[1] = fRec16[0];
		fRec15[2] = fRec15[1];
		fRec15[1] = fRec15[0];
		fVec5[1] = fVec5[0];
		fRec29[1] = fRec29[0];
		fRec14[1] = fRec14[0];
		fRec13[1] = fRec13[0];
		fRec30[1] = fRec30[0];
		fRec12[2] = fRec12[1];
		fRec12[1] = fRec12[0];
		fVec6[1] = fVec6[0];
		fRec11[1] = fRec11[0];
		fRec10[1] = fRec10[0];
		fRec9[2] = fRec9[1];
		fRec9[1] = fRec9[0];
		fVec7[1] = fVec7[0];
		fRec8[1] = fRec8[0];
		fRec7[2] = fRec7[1];
		fRec7[1] = fRec7[0];
		fRec6[2] = fRec6[1];
		fRec6[1] = fRec6[0];
		fRec34[1] = fRec34[0];
		fRec33[2] = fRec33[1];
		fRec33[1] = fRec33[0];
		fRec32[2] = fRec32[1];
		fRec32[1] = fRec32[0];
		fRec31[2] = fRec31[1];
		fRec31[1] = fRec31[0];
		fRec38[1] = fRec38[0];
		fRec37[2] = fRec37[1];
		fRec37[1] = fRec37[0];
		fVec8[1] = fVec8[0];
		fRec36[1] = fRec36[0];
		fRec35[2] = fRec35[1];
		fRec35[1] = fRec35[0];
		fRec40[1] = fRec40[0];
		fRec39[2] = fRec39[1];
		fRec39[1] = fRec39[0];
		fVec9[1] = fVec9[0];
		fRec5[1] = fRec5[0];
		fVec10[1] = fVec10[0];
		fRec4[1] = fRec4[0];
		fRec41[1] = fRec41[0];
		fVec11[1] = fVec11[0];
		fRec3[1] = fRec3[0];
		fRec2[2] = fRec2[1];
		fRec2[1] = fRec2[0];
		fVec12[1] = fVec12[0];
		fRec42[1] = fRec42[0];
		fRec1[1] = fRec1[0];
		fRec0[1] = fRec0[0];
		fVec13[1] = fVec13[0];
		fRec45[1] = fRec45[0];
		fRec44[1] = fRec44[0];
		fRec43[1] = fRec43[0];
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
		fVslider0_ = (float*)data; // , 0.34999999999999998, 0.0, 1.0, 0.01 
		break;
	case WET_DRY: 
		fVslider2_ = (float*)data; // , 100.0, 0.0, 100.0, 1.0 
		break;
	case PREGAIN: 
		fVslider1_ = (float*)data; // , -6.0, -20.0, 20.0, 0.10000000000000001 
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

} // end namespace gxamp5
