// generated from file '../src/faust/drumseq.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace drumseq {


Dsp::Dsp() {
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) fVec0[l0] = 0.0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) iVec1[l1] = 0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec2[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) iRec0[l3] = 0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec1[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec7[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec8[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec9[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec5[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec6[l9] = 0.0;
	for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) fRec4[l10] = 0.0;
	for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) fRec3[l11] = 0.0;
	for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) fRec12[l12] = 0.0;
	for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) iRec10[l13] = 0;
	for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) fRec11[l14] = 0.0;
	for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) fRec15[l15] = 0.0;
	for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) iRec18[l16] = 0;
	for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) fVec2[l17] = 0.0;
	for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) fRec17[l18] = 0.0;
	for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) fRec16[l19] = 0.0;
	for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) fVec3[l20] = 0.0;
	for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) fRec14[l21] = 0.0;
	for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) fRec13[l22] = 0.0;
	for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) fRec19[l23] = 0.0;
	for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) fVec4[l24] = 0.0;
	for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) fRec22[l25] = 0.0;
	for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) iRec20[l26] = 0;
	for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) fRec21[l27] = 0.0;
	for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) fRec25[l28] = 0.0;
	for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) fRec27[l29] = 0.0;
	for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) fRec28[l30] = 0.0;
	for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) fRec23[l31] = 0.0;
	for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) fRec24[l32] = 0.0;
	for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) fRec29[l33] = 0.0;
	for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) fRec30[l34] = 0.0;
	for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) fRec31[l35] = 0.0;
	for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) fRec32[l36] = 0.0;
	for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) iRec33[l37] = 0;
	for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) fRec34[l38] = 0.0;
	for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) fRec35[l39] = 0.0;
	for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) fVec5[l40] = 0.0;
	for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) fRec38[l41] = 0.0;
	for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) iRec36[l42] = 0;
	for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) fRec37[l43] = 0.0;
	for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) fRec42[l44] = 0.0;
	for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) fRec43[l45] = 0.0;
	for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) fVec6[l46] = 0.0;
	for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) fRec44[l47] = 0.0;
	for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) fVec7[l48] = 0.0;
	for (int l49 = 0; (l49 < 64); l49 = (l49 + 1)) fVec8[l49] = 0.0;
	for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) fRec40[l50] = 0.0;
	for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) fRec41[l51] = 0.0;
	for (int l52 = 0; (l52 < 2); l52 = (l52 + 1)) fRec47[l52] = 0.0;
	for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) fRec48[l53] = 0.0;
	for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) fRec45[l54] = 0.0;
	for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) fRec46[l55] = 0.0;
	for (int l56 = 0; (l56 < 2); l56 = (l56 + 1)) fRec51[l56] = 0.0;
	for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) fRec52[l57] = 0.0;
	for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) fRec49[l58] = 0.0;
	for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) fRec50[l59] = 0.0;
	for (int l60 = 0; (l60 < 2); l60 = (l60 + 1)) fRec55[l60] = 0.0;
	for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) fRec56[l61] = 0.0;
	for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) fRec53[l62] = 0.0;
	for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) fRec54[l63] = 0.0;
	for (int l64 = 0; (l64 < 2); l64 = (l64 + 1)) fVec9[l64] = 0.0;
	for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) fRec57[l65] = 0.0;
	for (int l66 = 0; (l66 < 3); l66 = (l66 + 1)) fRec39[l66] = 0.0;
	for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) iRec58[l67] = 0;
	for (int l68 = 0; (l68 < 2); l68 = (l68 + 1)) fRec59[l68] = 0.0;
	for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) fRec62[l69] = 0.0;
	for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) fRec61[l70] = 0.0;
	for (int l71 = 0; (l71 < 3); l71 = (l71 + 1)) fRec60[l71] = 0.0;
	for (int l72 = 0; (l72 < 2); l72 = (l72 + 1)) fRec63[l72] = 0.0;
	for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) fVec10[l73] = 0.0;
	for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) fRec66[l74] = 0.0;
	for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) iRec64[l75] = 0;
	for (int l76 = 0; (l76 < 2); l76 = (l76 + 1)) fRec65[l76] = 0.0;
	for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) fRec67[l77] = 0.0;
	for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) fRec68[l78] = 0.0;
	for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) iRec69[l79] = 0;
	for (int l80 = 0; (l80 < 2); l80 = (l80 + 1)) fRec70[l80] = 0.0;
	for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) fRec71[l81] = 0.0;
	for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) fRec72[l82] = 0.0;
	for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) iRec73[l83] = 0;
	for (int l84 = 0; (l84 < 2); l84 = (l84 + 1)) fRec74[l84] = 0.0;
	for (int l85 = 0; (l85 < 2); l85 = (l85 + 1)) fRec76[l85] = 0.0;
	for (int l86 = 0; (l86 < 3); l86 = (l86 + 1)) fRec75[l86] = 0.0;
	for (int l87 = 0; (l87 < 2); l87 = (l87 + 1)) iRec77[l87] = 0;
	for (int l88 = 0; (l88 < 2); l88 = (l88 + 1)) fRec78[l88] = 0.0;
	for (int l89 = 0; (l89 < 2); l89 = (l89 + 1)) fRec80[l89] = 0.0;
	for (int l90 = 0; (l90 < 3); l90 = (l90 + 1)) fRec79[l90] = 0.0;
	for (int l91 = 0; (l91 < 2); l91 = (l91 + 1)) fRec81[l91] = 0.0;
	for (int l92 = 0; (l92 < 2); l92 = (l92 + 1)) fRec82[l92] = 0.0;
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = std::tan((3141.5926535897929 / fConst0));
	fConst2 = (1.0 / fConst1);
	fConst3 = (1.0 / (((fConst2 + 1.0000000000000004) / fConst1) + 1.0));
	fConst4 = (1.0 / double(int((0.0050000000000000001 * fConst0))));
	fConst5 = (200.0 / fConst0);
	fConst6 = (1.0 - (1.0 / std::pow(1000.0, (2.5 / fConst0))));
	fConst7 = (1.0 / (fConst2 + 1.0));
	fConst8 = (1.0 - fConst2);
	fConst9 = (6.2831853071795862 / fConst0);
	fConst10 = (31.415926535897931 / fConst0);
	fConst11 = std::sin(fConst10);
	fConst12 = std::cos(fConst10);
	fConst13 = (1.0 / double(int((0.02 * fConst0))));
	fConst14 = (((fConst2 + -1.0000000000000004) / fConst1) + 1.0);
	fConst15 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst1))));
	fConst16 = (1.0 / double(int((0.01 * fConst0))));
	fConst17 = (100.0 / fConst0);
	fConst18 = (1.0 / fConst0);
	fConst19 = (1.0 - (1.0 / std::pow(1000.0, fConst18)));
	fConst20 = (3.1415926535897931 / fConst0);
	fConst21 = (1.0 / double(int((0.029999999999999999 * fConst0))));
	fConst22 = std::tan((1570.7963267948965 / fConst0));
	fConst23 = (1.0 / fConst22);
	fConst24 = (1.0 / (((fConst23 + 1.0000000000000004) / fConst22) + 1.0));
	fConst25 = mydsp_faustpower2_f(fConst22);
	fConst26 = (1.0 / fConst25);
	fConst27 = (fConst23 + 1.0);
	fConst28 = (1.0 / (fConst27 * fConst22));
	fConst29 = (0.0 - fConst28);
	fConst30 = ((1.0 - fConst23) / fConst27);
	fConst31 = (((fConst23 + -1.0000000000000004) / fConst22) + 1.0);
	fConst32 = (2.0 * (1.0 - fConst26));
	fConst33 = (0.0 - (2.0 / fConst25));
	fConst34 = (5.3407075111026483 / fConst0);
	fConst35 = (5.026548245743669 / fConst0);
	fConst36 = (1.0 - (1.0 / std::pow(1000.0, fConst17)));
	fConst37 = (1.0 - (1.0 / std::pow(1000.0, (10.0 / fConst0))));
	fConst38 = (0.037259615384615384 * fConst0);
	fConst39 = (1498.2980347889782 / fConst0);
	fConst40 = std::sin(fConst39);
	fConst41 = std::cos(fConst39);
	fConst42 = std::max<double>(0.0, std::min<double>(2047.0, (0.00031250000000000001 * fConst0)));
	fConst43 = std::floor(fConst42);
	fConst44 = (fConst43 + (1.0 - fConst42));
	iConst45 = int(fConst42);
	fConst46 = (fConst42 - fConst43);
	iConst47 = (iConst45 + 1);
	fConst48 = (0.0081250000000000003 * fConst0);
	fConst49 = (326.72563597333851 / fConst0);
	fConst50 = std::sin(fConst49);
	fConst51 = std::cos(fConst49);
	fConst52 = (0.00050551470588235299 * fConst0);
	fConst53 = (20.327952464404543 / fConst0);
	fConst54 = std::sin(fConst53);
	fConst55 = std::cos(fConst53);
	fConst56 = (0.00011370625 * fConst0);
	fConst57 = (4.5723996117407291 / fConst0);
	fConst58 = std::sin(fConst57);
	fConst59 = std::cos(fConst57);
	fConst60 = (2.0 / fConst0);
	fConst61 = (1.0 / double(int((0.10000000000000001 * fConst0))));
	fConst62 = (1.0 / double(int((0.00050000000000000001 * fConst0))));
	fConst63 = (2000.0 / fConst0);
	fConst64 = (1.0 - std::pow(1.0, (1000.0 / fConst0)));
	fConst65 = (1.0 - (1.0 / std::pow(1000.0, (18.181818181818183 / fConst0))));
	fConst66 = (2073.4511513692632 / fConst0);
	fConst67 = std::sin(fConst66);
	fConst68 = std::cos(fConst66);
	fConst69 = (1.0 - (1.0 / std::pow(1000.0, (13.333333333333334 / fConst0))));
	fConst70 = (1162.3892818282234 / fConst0);
	fConst71 = std::sin(fConst70);
	fConst72 = std::cos(fConst70);
	fConst73 = std::tan((22116.812281272145 / fConst0));
	fConst74 = (1.0 / fConst73);
	fConst75 = (1.0 / (((fConst74 + 1.0000000000000004) / fConst73) + 1.0));
	fConst76 = (1.0 - (1.0 / std::pow(1000.0, (5.0 / fConst0))));
	fConst77 = (1.0 / (fConst74 + 1.0));
	fConst78 = (1.0 - fConst74);
	fConst79 = (((fConst74 + -1.0000000000000004) / fConst73) + 1.0);
	fConst80 = (2.0 * (1.0 - (1.0 / mydsp_faustpower2_f(fConst73))));
	fConst81 = std::tan((1643.0529578274618 / fConst0));
	fConst82 = (1.0 / fConst81);
	fConst83 = (1.0 / (((fConst82 + 1.0000000000000004) / fConst81) + 1.0));
	fConst84 = (1.0 - (1.0 / std::pow(1000.0, (5.4644808743169397 / fConst0))));
	fConst85 = mydsp_faustpower2_f(fConst81);
	fConst86 = (1.0 / fConst85);
	fConst87 = (fConst82 + 1.0);
	fConst88 = (1.0 / (fConst87 * fConst81));
	fConst89 = (0.0 - fConst88);
	fConst90 = ((1.0 - fConst82) / fConst87);
	fConst91 = (((fConst82 + -1.0000000000000004) / fConst81) + 1.0);
	fConst92 = (2.0 * (1.0 - fConst86));
	fConst93 = (0.0 - (2.0 / fConst85));
	fCheckbox0 = FAUSTFLOAT(0.0);
	fCheckbox1 = FAUSTFLOAT(0.0);
	fVslider0 = FAUSTFLOAT(-20.0);
	fCheckbox2 = FAUSTFLOAT(0.0);
	fVslider1 = FAUSTFLOAT(90.0);
	fVslider2 = FAUSTFLOAT(-20.0);
	fCheckbox3 = FAUSTFLOAT(0.0);
	fVslider3 = FAUSTFLOAT(-20.0);
	fCheckbox4 = FAUSTFLOAT(0.0);
	fVslider4 = FAUSTFLOAT(-20.0);
	fVslider5 = FAUSTFLOAT(-20.0);
			IOTA = 0;
	clear_state_f();
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fCheckbox0 (*fCheckbox0_)
#define fCheckbox1 (*fCheckbox1_)
#define fCheckbox2 (*fCheckbox2_)
#define fVslider1 (*fVslider1_)
#define fVslider2 (*fVslider2_)
#define fCheckbox3 (*fCheckbox3_)
#define fCheckbox4 (*fCheckbox4_)
	int iSlow0 = int(double(fCheckbox0));
	double fSlow1 = double(fCheckbox1);
	double fSlow2 = (0.0010000000000000009 * double(fVslider0));
	double fSlow3 = double(fCheckbox2);
	double fSlow4 = double(fVslider1);
	double fSlow5 = std::max<double>(9.9999999999999995e-08, std::fabs((0.90000000000000002 * fSlow4)));
	double fSlow6 = (fConst18 * fSlow5);
	double fSlow7 = (1.0 - (fConst0 / fSlow5));
	double fSlow8 = (0.65384615384615374 * fSlow4);
	double fSlow9 = (fConst34 * fSlow4);
	double fSlow10 = std::sin(fSlow9);
	double fSlow11 = std::cos(fSlow9);
	double fSlow12 = (fConst35 * fSlow4);
	double fSlow13 = std::sin(fSlow12);
	double fSlow14 = std::cos(fSlow12);
	double fSlow15 = (fConst9 * fSlow4);
	double fSlow16 = std::sin(fSlow15);
	double fSlow17 = std::cos(fSlow15);
	double fSlow18 = (0.0010000000000000009 * double(fVslider2));
	double fSlow19 = double(fCheckbox3);
	double fSlow20 = (0.0010000000000000009 * double(fVslider3));
	double fSlow21 = double(fCheckbox4);
	double fSlow22 = (0.0010000000000000009 * double(fVslider4));
	double fSlow23 = (0.0010000000000000009 * double(fVslider5));
	for (int i = 0; (i < count); i = (i + 1)) {
		fVec0[0] = fSlow1;
		iVec1[0] = 1;
		double fTemp0 = double((fSlow1 > fVec0[1]));
		fRec2[0] = ((fTemp0 + fRec2[1]) - (fConst4 * double((fRec2[1] > 0.0))));
		int iTemp1 = (fRec2[0] > 0.0);
		int iTemp2 = (iTemp1 > 0);
		iRec0[0] = (iTemp2 & (iRec0[1] | (fRec1[1] >= 1.0)));
		int iTemp3 = ((iTemp1 <= 0) & (fRec1[1] > 0.0));
		fRec1[0] = (((fConst5 * double((((iRec0[1] == 0) & iTemp2) & (fRec1[1] < 1.0)))) + (fRec1[1] * (1.0 - (fConst6 * double(iTemp3))))) * double(((iTemp3 == 0) | (fRec1[1] >= 9.9999999999999995e-07))));
		fRec7[0] = ((fConst11 * fRec8[1]) + (fConst12 * fRec7[1]));
		double fTemp4 = double((1 - iVec1[1]));
		fRec8[0] = ((fTemp4 + (fConst12 * fRec8[1])) - (fConst11 * fRec7[1]));
		fRec9[0] = ((fRec9[1] + fTemp0) - (fConst13 * double((fRec9[1] > 0.0))));
		double fTemp5 = (fConst9 * ((19.23076923076923 * fRec7[0]) + (50.0 * (fRec9[0] + 1.0))));
		double fTemp6 = std::sin(fTemp5);
		double fTemp7 = std::cos(fTemp5);
		fRec5[0] = ((fRec6[1] * fTemp6) + (fRec5[1] * fTemp7));
		fRec6[0] = ((fTemp4 + (fRec6[1] * fTemp7)) - (fTemp6 * fRec5[1]));
		fRec4[0] = (0.0 - (fConst7 * ((fConst8 * fRec4[1]) - (fRec5[0] + fRec5[1]))));
		fRec3[0] = (fRec4[0] - (fConst3 * ((fConst14 * fRec3[2]) + (fConst15 * fRec3[1]))));
		fRec12[0] = ((fTemp0 + fRec12[1]) - (fConst16 * double((fRec12[1] > 0.0))));
		int iTemp8 = (fRec12[0] > 0.0);
		int iTemp9 = (iTemp8 > 0);
		iRec10[0] = (iTemp9 & (iRec10[1] | (fRec11[1] >= 1.0)));
		int iTemp10 = ((iTemp8 <= 0) & (fRec11[1] > 0.0));
		fRec11[0] = (((fConst17 * double((((iRec10[1] == 0) & iTemp9) & (fRec11[1] < 1.0)))) + (fRec11[1] * (1.0 - (fConst19 * double(iTemp10))))) * double(((iTemp10 == 0) | (fRec11[1] >= 9.9999999999999995e-07))));
		fRec15[0] = ((fTemp0 + fRec15[1]) - (fConst21 * double((fRec15[1] > 0.0))));
		double fTemp11 = std::tan((fConst20 * ((5500.0 * fRec15[0]) + 500.0)));
		double fTemp12 = (1.0 / fTemp11);
		iRec18[0] = ((1103515245 * iRec18[1]) + 12345);
		double fTemp13 = double(iRec18[0]);
		fVec2[0] = fTemp13;
		fRec17[0] = ((1.3969838625737391e-11 * ((fConst28 * fTemp13) + (fConst29 * fVec2[1]))) - (fConst30 * fRec17[1]));
		fRec16[0] = (fRec17[0] - (fConst24 * ((fConst31 * fRec16[2]) + (fConst32 * fRec16[1]))));
		double fTemp14 = (((fConst26 * fRec16[0]) + (fConst33 * fRec16[1])) + (fConst26 * fRec16[2]));
		fVec3[0] = fTemp14;
		fRec14[0] = (0.0 - (((fRec14[1] * (1.0 - fTemp12)) - (fConst24 * (fTemp14 + fVec3[1]))) / (fTemp12 + 1.0)));
		double fTemp15 = (((fTemp12 + 1.0000000000000004) / fTemp11) + 1.0);
		fRec13[0] = (fRec14[0] - (((fRec13[2] * (((fTemp12 + -1.0000000000000004) / fTemp11) + 1.0)) + (2.0 * (fRec13[1] * (1.0 - (1.0 / mydsp_faustpower2_f(fTemp11)))))) / fTemp15));
		fRec19[0] = (fSlow2 + (0.999 * fRec19[1]));
		fVec4[0] = fSlow3;
		fRec22[0] = ((fRec22[1] + double((fSlow3 > fVec4[1]))) - (fConst4 * double((fRec22[1] > 0.0))));
		int iTemp16 = (fRec22[0] > 0.0);
		int iTemp17 = (iTemp16 > 0);
		iRec20[0] = (iTemp17 & (iRec20[1] | (fRec21[1] >= 1.0)));
		int iTemp18 = (iTemp16 <= 0);
		int iTemp19 = (iTemp18 & (fRec21[1] > 0.0));
		fRec21[0] = (((fConst5 * double((((iRec20[1] == 0) & iTemp17) & (fRec21[1] < 1.0)))) + (fRec21[1] * (1.0 - (fConst6 * double(iTemp19))))) * double(((iTemp19 == 0) | (fRec21[1] >= 9.9999999999999995e-07))));
		double fTemp20 = (fSlow6 + (fRec25[1] + -1.0));
		int iTemp21 = (fTemp20 < 0.0);
		double fTemp22 = (fSlow6 + fRec25[1]);
		fRec25[0] = (iTemp21?fTemp22:fTemp20);
		double fRec26 = (iTemp21?fTemp22:(fSlow6 + (fRec25[1] + (fSlow7 * fTemp20))));
		fRec27[0] = ((fSlow10 * fRec28[1]) + (fSlow11 * fRec27[1]));
		fRec28[0] = ((fTemp4 + (fSlow11 * fRec28[1])) - (fSlow10 * fRec27[1]));
		double fTemp23 = (fConst9 * (((2.0 * fRec26) + (fSlow8 * fRec27[0])) + -1.0));
		double fTemp24 = std::sin(fTemp23);
		double fTemp25 = std::cos(fTemp23);
		fRec23[0] = ((fRec24[1] * fTemp24) + (fRec23[1] * fTemp25));
		fRec24[0] = ((fTemp4 + (fRec24[1] * fTemp25)) - (fTemp24 * fRec23[1]));
		fRec29[0] = ((fSlow13 * fRec30[1]) + (fSlow14 * fRec29[1]));
		fRec30[0] = ((fTemp4 + (fSlow14 * fRec30[1])) - (fSlow13 * fRec29[1]));
		fRec31[0] = ((fSlow16 * fRec32[1]) + (fSlow17 * fRec31[1]));
		fRec32[0] = ((fTemp4 + (fSlow17 * fRec32[1])) - (fSlow16 * fRec31[1]));
		iRec33[0] = (iTemp17 & (iRec33[1] | (fRec34[1] >= 1.0)));
		int iTemp26 = (iTemp18 & (fRec34[1] > 0.0));
		fRec34[0] = (((fConst5 * double((((iRec33[1] == 0) & iTemp17) & (fRec34[1] < 1.0)))) + (fRec34[1] * (1.0 - (fConst36 * double(iTemp26))))) * double(((iTemp26 == 0) | (fRec34[1] >= 9.9999999999999995e-07))));
		fRec35[0] = (fSlow18 + (0.999 * fRec35[1]));
		fVec5[0] = fSlow19;
		double fTemp27 = double((fSlow19 > fVec5[1]));
		fRec38[0] = ((fTemp27 + fRec38[1]) - (fConst4 * double((fRec38[1] > 0.0))));
		int iTemp28 = (fRec38[0] > 0.0);
		int iTemp29 = (iTemp28 > 0);
		iRec36[0] = (iTemp29 & (iRec36[1] | (fRec37[1] >= 1.0)));
		int iTemp30 = (iTemp28 <= 0);
		int iTemp31 = (iTemp30 & (fRec37[1] > 0.0));
		fRec37[0] = (((fConst5 * double((((iRec36[1] == 0) & iTemp29) & (fRec37[1] < 1.0)))) + (fRec37[1] * (1.0 - (fConst37 * double(iTemp31))))) * double(((iTemp31 == 0) | (fRec37[1] >= 9.9999999999999995e-07))));
		fRec42[0] = ((fConst40 * fRec43[1]) + (fConst41 * fRec42[1]));
		fRec43[0] = ((fTemp4 + (fConst41 * fRec43[1])) - (fConst40 * fRec42[1]));
		fVec6[0] = 1600.0;
		double fTemp32 = (fRec44[1] + (fConst18 * fVec6[1]));
		fRec44[0] = (fTemp32 - std::floor(fTemp32));
		double fTemp33 = mydsp_faustpower2_f(((2.0 * fRec44[0]) + -1.0));
		fVec7[0] = fTemp33;
		double fTemp34 = (double(iVec1[1]) * (fTemp33 - fVec7[1]));
		fVec8[(IOTA & 63)] = fTemp34;
		double fTemp35 = ((fTemp34 - (fConst44 * fVec8[((IOTA - iConst45) & 63)])) - (fConst46 * fVec8[((IOTA - iConst47) & 63)]));
		double fTemp36 = (fConst9 * ((fConst38 * (fRec42[0] * fTemp35)) + 2144.0));
		double fTemp37 = std::sin(fTemp36);
		double fTemp38 = std::cos(fTemp36);
		fRec40[0] = ((fRec41[1] * fTemp37) + (fRec40[1] * fTemp38));
		fRec41[0] = ((fTemp4 + (fRec41[1] * fTemp38)) - (fTemp37 * fRec40[1]));
		fRec47[0] = ((fConst50 * fRec48[1]) + (fConst51 * fRec47[1]));
		fRec48[0] = ((fTemp4 + (fConst51 * fRec48[1])) - (fConst50 * fRec47[1]));
		double fTemp39 = (fConst9 * ((fConst48 * (fRec47[0] * fTemp35)) + 3847.9999999999995));
		double fTemp40 = std::sin(fTemp39);
		double fTemp41 = std::cos(fTemp39);
		fRec45[0] = ((fRec46[1] * fTemp40) + (fRec45[1] * fTemp41));
		fRec46[0] = ((fTemp4 + (fRec46[1] * fTemp41)) - (fTemp40 * fRec45[1]));
		fRec51[0] = ((fConst54 * fRec52[1]) + (fConst55 * fRec51[1]));
		fRec52[0] = ((fTemp4 + (fConst55 * fRec52[1])) - (fConst54 * fRec51[1]));
		double fTemp42 = (fConst9 * ((fConst52 * (fRec51[0] * fTemp35)) + 4944.0));
		double fTemp43 = std::sin(fTemp42);
		double fTemp44 = std::cos(fTemp42);
		fRec49[0] = ((fRec50[1] * fTemp43) + (fRec49[1] * fTemp44));
		fRec50[0] = ((fTemp4 + (fRec50[1] * fTemp44)) - (fTemp43 * fRec49[1]));
		fRec55[0] = ((fConst58 * fRec56[1]) + (fConst59 * fRec55[1]));
		fRec56[0] = ((fTemp4 + (fConst59 * fRec56[1])) - (fConst58 * fRec55[1]));
		double fTemp45 = (fConst9 * ((fConst56 * (fRec55[0] * fTemp35)) + 2094.4000000000001));
		double fTemp46 = std::sin(fTemp45);
		double fTemp47 = std::cos(fTemp45);
		fRec53[0] = ((fRec54[1] * fTemp46) + (fRec53[1] * fTemp47));
		fRec54[0] = ((fTemp4 + (fRec54[1] * fTemp47)) - (fTemp46 * fRec53[1]));
		double fTemp48 = (((fRec40[0] + fRec45[0]) + fRec49[0]) + fRec53[0]);
		fVec9[0] = fTemp48;
		fRec57[0] = ((fRec57[1] + fTemp27) - (fConst61 * double((fRec57[1] > 0.0))));
		double fTemp49 = ((6000.0 * fRec57[0]) + 9000.0);
		double fTemp50 = (0.0 - (3.1415926535897931 * fTemp49));
		fRec39[0] = (fTemp48 - (((fRec39[1] * (0.0 - (fConst60 * fTemp50))) * std::cos((fConst9 * fTemp49))) + (mydsp_faustpower2_f((fConst18 * fTemp50)) * fRec39[2])));
		iRec58[0] = (iTemp29 & (iRec58[1] | (fRec59[1] >= 1.0)));
		int iTemp51 = (iTemp30 & (fRec59[1] > 0.0));
		fRec59[0] = (((fConst5 * double((((iRec58[1] == 0) & iTemp29) & (fRec59[1] < 1.0)))) + (fRec59[1] * (1.0 - (fConst36 * double(iTemp51))))) * double(((iTemp51 == 0) | (fRec59[1] >= 9.9999999999999995e-07))));
		fRec62[0] = ((fTemp27 + fRec62[1]) - (fConst16 * double((fRec62[1] > 0.0))));
		double fTemp52 = std::tan((fConst20 * (12000.0 - (3000.0 * fRec62[0]))));
		double fTemp53 = (1.0 / fTemp52);
		double fTemp54 = (fTemp53 + 1.0);
		fRec61[0] = ((fVec9[1] * (0.0 - (1.0 / (fTemp52 * fTemp54)))) - (((fRec61[1] * (1.0 - fTemp53)) - (fTemp48 / fTemp52)) / fTemp54));
		double fTemp55 = mydsp_faustpower2_f(fTemp52);
		double fTemp56 = (((fTemp53 + 1.0000000000000004) / fTemp52) + 1.0);
		fRec60[0] = (fRec61[0] - (((fRec60[2] * (((fTemp53 + -1.0000000000000004) / fTemp52) + 1.0)) + (2.0 * (fRec60[1] * (1.0 - (1.0 / fTemp55))))) / fTemp56));
		fRec63[0] = (fSlow20 + (0.999 * fRec63[1]));
		fVec10[0] = fSlow21;
		fRec66[0] = ((fRec66[1] + double((fSlow21 > fVec10[1]))) - (fConst62 * double((fRec66[1] > 0.0))));
		int iTemp57 = (fRec66[0] > 0.0);
		int iTemp58 = (iTemp57 > 0);
		iRec64[0] = (iTemp58 & (iRec64[1] | (fRec65[1] >= 1.0)));
		int iTemp59 = (iTemp57 <= 0);
		int iTemp60 = (iTemp59 & (fRec65[1] > 0.0));
		fRec65[0] = (((fConst63 * double((((iRec64[1] == 0) & iTemp58) & (fRec65[1] < 1.0)))) + (fRec65[1] * ((1.0 - (fConst64 * double((iRec64[1] & (fRec65[1] > 1.0))))) - (fConst65 * double(iTemp60))))) * double(((iTemp60 == 0) | (fRec65[1] >= 9.9999999999999995e-07))));
		fRec67[0] = ((fConst67 * fRec68[1]) + (fConst68 * fRec67[1]));
		fRec68[0] = ((fTemp4 + (fConst68 * fRec68[1])) - (fConst67 * fRec67[1]));
		iRec69[0] = (iTemp58 & (iRec69[1] | (fRec70[1] >= 1.0)));
		int iTemp61 = (iTemp59 & (fRec70[1] > 0.0));
		fRec70[0] = (((fConst63 * double((((iRec69[1] == 0) & iTemp58) & (fRec70[1] < 1.0)))) + (fRec70[1] * ((1.0 - (fConst64 * double((iRec69[1] & (fRec70[1] > 1.0))))) - (fConst69 * double(iTemp61))))) * double(((iTemp61 == 0) | (fRec70[1] >= 9.9999999999999995e-07))));
		fRec71[0] = ((fConst71 * fRec72[1]) + (fConst72 * fRec71[1]));
		fRec72[0] = ((fTemp4 + (fConst72 * fRec72[1])) - (fConst71 * fRec71[1]));
		iRec73[0] = (iTemp58 & (iRec73[1] | (fRec74[1] >= 1.0)));
		int iTemp62 = (iTemp59 & (fRec74[1] > 0.0));
		fRec74[0] = (((fConst63 * double((((iRec73[1] == 0) & iTemp58) & (fRec74[1] < 1.0)))) + (fRec74[1] * ((1.0 - (fConst64 * double((iRec73[1] & (fRec74[1] > 1.0))))) - (fConst76 * double(iTemp62))))) * double(((iTemp62 == 0) | (fRec74[1] >= 9.9999999999999995e-07))));
		fRec76[0] = (fConst77 * ((4.6566128752457969e-10 * (fTemp13 + fVec2[1])) - (fConst78 * fRec76[1])));
		fRec75[0] = (fRec76[0] - (fConst75 * ((fConst79 * fRec75[2]) + (fConst80 * fRec75[1]))));
		iRec77[0] = (iTemp58 & (iRec77[1] | (fRec78[1] >= 1.0)));
		int iTemp63 = (iTemp59 & (fRec78[1] > 0.0));
		fRec78[0] = (((fConst63 * double((((iRec77[1] == 0) & iTemp58) & (fRec78[1] < 1.0)))) + (fRec78[1] * ((1.0 - (fConst64 * double((iRec77[1] & (fRec78[1] > 1.0))))) - (fConst84 * double(iTemp63))))) * double(((iTemp63 == 0) | (fRec78[1] >= 9.9999999999999995e-07))));
		fRec80[0] = ((4.6566128752457969e-10 * ((fConst88 * fTemp13) + (fConst89 * fVec2[1]))) - (fConst90 * fRec80[1]));
		fRec79[0] = (fRec80[0] - (fConst83 * ((fConst91 * fRec79[2]) + (fConst92 * fRec79[1]))));
		fRec81[0] = (fSlow22 + (0.999 * fRec81[1]));
		fRec82[0] = (fSlow23 + (0.999 * fRec82[1]));
		double fTemp64 = (((2.0 * ((((fConst3 * (fRec1[0] * (fRec3[2] + (fRec3[0] + (2.0 * fRec3[1]))))) + ((fRec11[0] * (fRec13[2] + (fRec13[0] + (2.0 * fRec13[1])))) / fTemp15)) * std::pow(10.0, (0.050000000000000003 * fRec19[0]))) + (((0.25 * (fRec21[0] * ((5.0 * fRec23[0]) + (0.5 * (fRec29[0] + fRec31[0]))))) + (3.0 * fRec34[0])) * std::pow(10.0, (0.050000000000000003 * fRec35[0]))))) + ((((fRec37[0] * (fRec39[0] - fRec39[2])) + ((std::sqrt(fRec59[0]) * (((fRec60[1] * (0.0 - (2.0 / fTemp55))) + (fRec60[0] / fTemp55)) + (fRec60[2] / fTemp55))) / fTemp56)) * std::pow(10.0, (0.050000000000000003 * fRec63[0]))) + ((((fRec65[0] * (fRec67[0] + 0.25)) + (fRec70[0] * (fRec71[0] + 0.25))) + (0.20000000000000001 * ((fConst75 * (fRec74[0] * (fRec75[2] + (fRec75[0] + (2.0 * fRec75[1]))))) + (fConst83 * (fRec78[0] * (((fConst86 * fRec79[0]) + (fConst93 * fRec79[1])) + (fConst86 * fRec79[2]))))))) * std::pow(10.0, (0.050000000000000003 * fRec81[0]))))) * std::pow(10.0, (0.050000000000000003 * fRec82[0])));
		output0[i] = FAUSTFLOAT((iSlow0?fTemp64:(fTemp64 + double(input0[i]))));
		fVec0[1] = fVec0[0];
		iVec1[1] = iVec1[0];
		fRec2[1] = fRec2[0];
		iRec0[1] = iRec0[0];
		fRec1[1] = fRec1[0];
		fRec7[1] = fRec7[0];
		fRec8[1] = fRec8[0];
		fRec9[1] = fRec9[0];
		fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		fRec4[1] = fRec4[0];
		fRec3[2] = fRec3[1];
		fRec3[1] = fRec3[0];
		fRec12[1] = fRec12[0];
		iRec10[1] = iRec10[0];
		fRec11[1] = fRec11[0];
		fRec15[1] = fRec15[0];
		iRec18[1] = iRec18[0];
		fVec2[1] = fVec2[0];
		fRec17[1] = fRec17[0];
		fRec16[2] = fRec16[1];
		fRec16[1] = fRec16[0];
		fVec3[1] = fVec3[0];
		fRec14[1] = fRec14[0];
		fRec13[2] = fRec13[1];
		fRec13[1] = fRec13[0];
		fRec19[1] = fRec19[0];
		fVec4[1] = fVec4[0];
		fRec22[1] = fRec22[0];
		iRec20[1] = iRec20[0];
		fRec21[1] = fRec21[0];
		fRec25[1] = fRec25[0];
		fRec27[1] = fRec27[0];
		fRec28[1] = fRec28[0];
		fRec23[1] = fRec23[0];
		fRec24[1] = fRec24[0];
		fRec29[1] = fRec29[0];
		fRec30[1] = fRec30[0];
		fRec31[1] = fRec31[0];
		fRec32[1] = fRec32[0];
		iRec33[1] = iRec33[0];
		fRec34[1] = fRec34[0];
		fRec35[1] = fRec35[0];
		fVec5[1] = fVec5[0];
		fRec38[1] = fRec38[0];
		iRec36[1] = iRec36[0];
		fRec37[1] = fRec37[0];
		fRec42[1] = fRec42[0];
		fRec43[1] = fRec43[0];
		fVec6[1] = fVec6[0];
		fRec44[1] = fRec44[0];
		fVec7[1] = fVec7[0];
		IOTA = (IOTA + 1);
		fRec40[1] = fRec40[0];
		fRec41[1] = fRec41[0];
		fRec47[1] = fRec47[0];
		fRec48[1] = fRec48[0];
		fRec45[1] = fRec45[0];
		fRec46[1] = fRec46[0];
		fRec51[1] = fRec51[0];
		fRec52[1] = fRec52[0];
		fRec49[1] = fRec49[0];
		fRec50[1] = fRec50[0];
		fRec55[1] = fRec55[0];
		fRec56[1] = fRec56[0];
		fRec53[1] = fRec53[0];
		fRec54[1] = fRec54[0];
		fVec9[1] = fVec9[0];
		fRec57[1] = fRec57[0];
		fRec39[2] = fRec39[1];
		fRec39[1] = fRec39[0];
		iRec58[1] = iRec58[0];
		fRec59[1] = fRec59[0];
		fRec62[1] = fRec62[0];
		fRec61[1] = fRec61[0];
		fRec60[2] = fRec60[1];
		fRec60[1] = fRec60[0];
		fRec63[1] = fRec63[0];
		fVec10[1] = fVec10[0];
		fRec66[1] = fRec66[0];
		iRec64[1] = iRec64[0];
		fRec65[1] = fRec65[0];
		fRec67[1] = fRec67[0];
		fRec68[1] = fRec68[0];
		iRec69[1] = iRec69[0];
		fRec70[1] = fRec70[0];
		fRec71[1] = fRec71[0];
		fRec72[1] = fRec72[0];
		iRec73[1] = iRec73[0];
		fRec74[1] = fRec74[0];
		fRec76[1] = fRec76[0];
		fRec75[2] = fRec75[1];
		fRec75[1] = fRec75[0];
		iRec77[1] = iRec77[0];
		fRec78[1] = fRec78[0];
		fRec80[1] = fRec80[0];
		fRec79[2] = fRec79[1];
		fRec79[1] = fRec79[0];
		fRec81[1] = fRec81[0];
		fRec82[1] = fRec82[0];
	}
#undef fCheckbox0
#undef fCheckbox1
#undef fCheckbox2
#undef fVslider1
#undef fVslider2
#undef fCheckbox3
#undef fCheckbox4
}

int Dsp::register_par(const ParamReg& reg)
{
	fCheckbox0_ = reg.registerVar("seq.direct_out","","BA",N_("bypass the rack for direct output"),&fCheckbox0, 0.0, 0.0, 1.0, 1.0);
	reg.registerVar("seq.gain","","S",N_("Volume level in decibels"),&fVslider5, -20.0, -60.0, 40.0, 0.10000000000000001);
	reg.registerVar("seq.hat_closed.dsp.Gain","","S",N_("Volume level in decibels"),&fVslider3, -20.0, -60.0, 40.0, 0.10000000000000001);
	fCheckbox3_ = reg.registerNonMidiSharedVar("seq.hat_closed.dsp.gate",&fCheckbox3, false, true, 0.0, 0.0, 1.0, 1.0);
	fCheckbox1_ = reg.registerNonMidiSharedVar("seq.kick.dsp.gate",&fCheckbox1, false, true, 0.0, 0.0, 1.0, 1.0);
	reg.registerVar("seq.kick.dsp.Gain","","S",N_("Volume level in decibels"),&fVslider0, -20.0, -60.0, 40.0, 0.10000000000000001);
	reg.registerVar("seq.snare.dsp.Gain","","S",N_("Volume level in decibels"),&fVslider4, -20.0, -60.0, 40.0, 0.10000000000000001);
	fCheckbox4_ = reg.registerNonMidiSharedVar("seq.snare.dsp.gate",&fCheckbox4, false, true, 0.0, 0.0, 1.0, 1.0);
	fVslider2_ = reg.registerNonMidiSharedVar("seq.tom.dsp.Gainf",&fVslider2, false, true, -20.0, -60.0, 40.0, 0.10000000000000001);
	fVslider1_ = reg.registerNonMidiSharedVar("seq.tom.dsp.freq",&fVslider1, false, true, 90.0, 90.0, 150.0, 1.0);
	fCheckbox2_ = reg.registerNonMidiSharedVar("seq.tom.dsp.gate",&fCheckbox2, false, true, 0.0, 0.0, 1.0, 1.0);
	return 0;
}


} // end namespace drumseq