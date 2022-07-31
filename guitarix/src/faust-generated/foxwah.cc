// generated from file '../src/faust/foxwah.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace foxwah {

class Dsp: public PluginDef {
private:
	int fSamplingFreq;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT	*fVslider0_;
	double fConst0;
	double fConst1;
	double fConst2;
	double fConst3;
	double fConst4;
	int iVec0[2];
	double fConst5;
	double fVec1[2];
	double fRec1[2];
	double fConst6;
	double fConst7;
	double fConst8;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT	*fVslider1_;
	double fConst9;
	FAUSTFLOAT fVslider2;
	FAUSTFLOAT	*fVslider2_;
	double fRec4[2];
	double fRec3[2];
	double fRec2[2];
	double fConst10;
	double fConst11;
	double fConst12;
	double fConst13;
	double fRec7[2];
	double fRec6[2];
	double fRec5[2];
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT	*fVslider3_;
	double fRec8[2];
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
	double fConst24;
	double fConst25;
	double fConst26;
	double fConst27;
	double fConst28;
	double fConst29;
	double fConst30;
	double fConst31;
	double fConst32;
	double fRec0[5];
	double fConst33;
	double fConst34;
	double fConst35;
	double fConst36;
	double fConst37;
	double fConst38;
	double fConst39;
	double fConst40;
	double fConst41;
	double fConst42;
	double fConst43;
	double fConst44;
	double fConst45;
	double fConst46;
	double fConst47;
	double fConst48;
	double fConst49;
	double fConst50;
	double fConst51;
	double fConst52;
	double fConst53;

	void clear_state_f();
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);
	int register_par(const ParamReg& reg);

	static void clear_state_f_static(PluginDef*);
	static void init_static(unsigned int samplingFreq, PluginDef*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef*);
	static int register_params_static(const ParamReg& reg);
	static void del_instance(PluginDef *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginDef() {
	version = PLUGINDEF_VERSION;
	flags = 0;
	id = "foxwah";
	name = N_("Foxx Wah");
	groups = 0;
	description = N_("Foxx Wah"); // description (tooltip)
	category = N_("Guitar Effects");       // category
	shortname = N_("Foxx Wah");     // shortname
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	register_params = register_params_static;
	load_ui = 0;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) iVec0[l0] = 0;
	for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) fVec1[l1] = 0.0;
	for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) fRec1[l2] = 0.0;
	for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) fRec4[l3] = 0.0;
	for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) fRec3[l4] = 0.0;
	for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) fRec2[l5] = 0.0;
	for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) fRec7[l6] = 0.0;
	for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) fRec6[l7] = 0.0;
	for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) fRec5[l8] = 0.0;
	for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) fRec8[l9] = 0.0;
	for (int l10 = 0; (l10 < 5); l10 = (l10 + 1)) fRec0[l10] = 0.0;
}

void Dsp::clear_state_f_static(PluginDef *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (717.01248503233671 / fConst0);
	fConst2 = (fConst1 + 1.0);
	fConst3 = (1.0 / fConst2);
	fConst4 = (1.0 - fConst1);
	fConst5 = (0.01 / fConst2);
	fConst6 = (1.2275879528436901e-18 * fConst0);
	fConst7 = mydsp_faustpower2_f(fConst0);
	fConst8 = (((-4.8055399796856898e-17 - fConst6) * fConst7) + 1.69880968875719e-11);
	fConst9 = (0.10471975511965977 / fConst0);
	fConst10 = std::exp((0.0 - (100.0 / fConst0)));
	fConst11 = (1.0 - fConst10);
	fConst12 = std::exp((0.0 - (10.0 / fConst0)));
	fConst13 = (1.0 - fConst12);
	fConst14 = (8.4734818644789999e-19 * fConst0);
	fConst15 = (((fConst14 + 3.01343158474042e-18) * fConst7) + -2.2480754421574902e-12);
	fConst16 = (2.1117579289813799e-19 * fConst0);
	fConst17 = ((fConst16 + 7.6916244557656196e-18) * fConst7);
	fConst18 = ((1.8413819292655401e-18 * fConst7) + -5.8687949031775201e-13);
	fConst19 = (-1.1685244043225301e-13 - (1.27102227967185e-18 * fConst7));
	fConst20 = (8.9023787509436504e-14 - (3.1676368934720701e-19 * fConst7));
	fConst21 = (((4.8055399796856898e-17 - fConst6) * fConst7) + -1.69880968875719e-11);
	fConst22 = (((fConst14 + -3.01343158474042e-18) * fConst7) + 2.2480754421574902e-12);
	fConst23 = ((fConst16 + -7.6916244557656196e-18) * fConst7);
	fConst24 = (3.06896988210923e-19 * fConst0);
	fConst25 = (((((fConst24 + -2.4027699898428501e-17) * fConst0) + 2.93439745158876e-13) * fConst0) + -8.4940484437859305e-12);
	fConst26 = (2.11837046611975e-19 * fConst0);
	fConst27 = (((((1.50671579237021e-18 - fConst26) * fConst0) + 5.8426220216126604e-14) * fConst0) + 1.12403772107874e-12);
	fConst28 = (5.27939482245346e-20 * fConst0);
	fConst29 = ((((3.8458122278828098e-18 - fConst28) * fConst0) + -4.4511893754718202e-14) * fConst0);
	fConst30 = (((((fConst24 + 2.4027699898428501e-17) * fConst0) + 2.93439745158876e-13) * fConst0) + 8.4940484437859305e-12);
	fConst31 = (((((-1.50671579237021e-18 - fConst26) * fConst0) + 5.8426220216126604e-14) * fConst0) + -1.12403772107874e-12);
	fConst32 = ((((-3.8458122278828098e-18 - fConst28) * fConst0) + -4.4511893754718202e-14) * fConst0);
	fConst33 = (7.0652649274790194e-21 * fConst0);
	fConst34 = (((((-2.3382087600362899e-16 - fConst33) * fConst0) + -3.2682564451510601e-13) * fConst0) + -3.2429214385964599e-12);
	fConst35 = (2.0374917851091199e-21 * fConst0);
	fConst36 = (((((-4.8544781840811302e-17 - fConst35) * fConst0) + -6.52701543961359e-14) * fConst0) + 1.41209804493283e-12);
	fConst37 = (1.8319982808400902e-21 * fConst0);
	fConst38 = ((((fConst37 + 4.3717757539413797e-17) * fConst0) + 5.9658637492238004e-14) * fConst0);
	fConst39 = (2.8261059709916102e-20 * fConst0);
	fConst40 = (((fConst39 + 4.6764175200725896e-16) * fConst7) + -6.4858428771929198e-12);
	fConst41 = (8.1499671404364798e-21 * fConst0);
	fConst42 = (((fConst41 + 9.7089563681622506e-17) * fConst7) + 2.8241960898656499e-12);
	fConst43 = (7.3279931233603697e-21 * fConst0);
	fConst44 = ((-8.7435515078827595e-17 - fConst43) * fConst7);
	fConst45 = (6.5365128903021101e-13 - (4.2391589564874099e-20 * fConst7));
	fConst46 = (1.30540308792272e-13 - (1.22249507106547e-20 * fConst7));
	fConst47 = ((1.09919896850405e-20 * fConst7) + -1.1931727498447601e-13);
	fConst48 = (((fConst39 + -4.6764175200725896e-16) * fConst7) + 6.4858428771929198e-12);
	fConst49 = (((fConst41 + -9.7089563681622506e-17) * fConst7) + -2.8241960898656499e-12);
	fConst50 = ((8.7435515078827595e-17 - fConst43) * fConst7);
	fConst51 = (((((2.3382087600362899e-16 - fConst33) * fConst0) + -3.2682564451510601e-13) * fConst0) + 3.2429214385964599e-12);
	fConst52 = (((((4.8544781840811302e-17 - fConst35) * fConst0) + -6.52701543961359e-14) * fConst0) + -1.41209804493283e-12);
	fConst53 = ((((fConst37 + -4.3717757539413797e-17) * fConst0) + 5.9658637492238004e-14) * fConst0);
	fVslider0 = FAUSTFLOAT(100.0);
	fVslider1 = FAUSTFLOAT(0.0);
	fVslider2 = FAUSTFLOAT(24.0);
	fVslider3 = FAUSTFLOAT(0.0);
	clear_state_f();
}

void Dsp::init_static(unsigned int samplingFreq, PluginDef *p)
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
	double fSlow1 = (0.01 * fSlow0);
	double fSlow2 = (1.0 - fSlow1);
	double fSlow3 = (fConst5 * fSlow0);
	int iSlow4 = int(double(fVslider1));
	int iSlow5 = (iSlow4 == 0);
	int iSlow6 = (iSlow4 == 1);
	double fSlow7 = (fConst9 * double(fVslider2));
	double fSlow8 = (4.748558434412966e-05 * (std::exp((5.0 * std::max<double>(0.01, double(fVslider3)))) + -1.0));
	for (int i = 0; (i < count); i = (i + 1)) {
		double fTemp0 = double(input0[i]);
		iVec0[0] = 1;
		fVec1[0] = (fSlow3 * fTemp0);
		fRec1[0] = ((fConst3 * ((fSlow1 * fTemp0) + (fConst4 * fRec1[1]))) - fVec1[1]);
		fRec4[0] = (fRec4[1] + (fSlow7 * (0.0 - fRec2[1])));
		fRec3[0] = ((fSlow7 * fRec4[0]) + (double((1 - iVec0[1])) + fRec3[1]));
		fRec2[0] = fRec3[0];
		double fTemp1 = std::fabs(fTemp0);
		fRec7[0] = std::max<double>(fTemp1, ((fConst12 * fRec7[1]) + (fConst13 * fTemp1)));
		fRec6[0] = ((fConst10 * fRec6[1]) + (fConst11 * fRec7[0]));
		fRec5[0] = ((0.99299999999999999 * fRec5[1]) + (0.0070000000000000062 * (1.0 - std::max<double>(0.02, std::min<double>(0.97999999999999998, fRec6[0])))));
		fRec8[0] = (fSlow8 + (0.99299999999999999 * fRec8[1]));
		double fTemp2 = (iSlow5?fRec8[0]:(iSlow6?fRec5[0]:(1.0 - std::max<double>(0.02, std::min<double>(0.97999999999999998, (0.5 * (fRec2[0] + 1.0)))))));
		double fTemp3 = ((fConst0 * (fConst30 + (fTemp2 * (fConst31 + (fConst32 * fTemp2))))) + 2.8384790936331901e-11);
		fRec0[0] = (fRec1[0] - (((((fRec0[1] * ((fConst0 * (fConst8 + (fTemp2 * (fConst15 + (fConst17 * fTemp2))))) + 1.1353916374532801e-10)) + (fRec0[2] * ((fConst7 * (fConst18 + (fTemp2 * (fConst19 + (fConst20 * fTemp2))))) + 1.70308745617991e-10))) + (fRec0[3] * ((fConst0 * (fConst21 + (fTemp2 * (fConst22 + (fConst23 * fTemp2))))) + 1.1353916374532801e-10))) + (fRec0[4] * ((fConst0 * (fConst25 + (fTemp2 * (fConst27 + (fConst29 * fTemp2))))) + 2.8384790936331901e-11))) / fTemp3));
		output0[i] = FAUSTFLOAT(((fSlow2 * fTemp0) + (fConst0 * ((((((fRec0[0] * (fConst34 + (fTemp2 * (fConst36 + (fConst38 * fTemp2))))) + (fRec0[1] * (fConst40 + (fTemp2 * (fConst42 + (fConst44 * fTemp2)))))) + (fConst0 * (fRec0[2] * (fConst45 + (fTemp2 * (fConst46 + (fConst47 * fTemp2))))))) + (fRec0[3] * (fConst48 + (fTemp2 * (fConst49 + (fConst50 * fTemp2)))))) + (fRec0[4] * (fConst51 + (fTemp2 * (fConst52 + (fConst53 * fTemp2)))))) / fTemp3))));
		iVec0[1] = iVec0[0];
		fVec1[1] = fVec1[0];
		fRec1[1] = fRec1[0];
		fRec4[1] = fRec4[0];
		fRec3[1] = fRec3[0];
		fRec2[1] = fRec2[0];
		fRec7[1] = fRec7[0];
		fRec6[1] = fRec6[0];
		fRec5[1] = fRec5[0];
		fRec8[1] = fRec8[0];
		for (int j0 = 4; (j0 > 0); j0 = (j0 - 1)) {
			fRec0[j0] = fRec0[(j0 - 1)];
		}
	}
#undef fVslider0
#undef fVslider1
#undef fVslider2
#undef fVslider3
}

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginDef *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}

int Dsp::register_par(const ParamReg& reg)
{
	fVslider3_ = reg.registerVar("wah.Wah","","SA","",&fVslider3, 0.0, 0.0, 1.0, 0.01);
	fVslider2_ = reg.registerVar("wah.freq",N_("Alien Freq"),"SA",N_("LFO in Beats per Minute"),&fVslider2, 24.0, 24.0, 360.0, 1.0);
	static const value_pair fVslider1_values[] = {{"manual"},{"auto"},{"alien"},{0}};
	fVslider1_ = reg.registerSharedEnumVar("wah.mode","","SA","",fVslider1_values,&fVslider1, 0.0, 0.0, 2.0, 1.0);
	fVslider0_ = reg.registerVar("wah.wet_dry",N_("dry/wet"),"SA","",&fVslider0, 100.0, 0.0, 100.0, 1.0);
	return 0;
}

int Dsp::register_params_static(const ParamReg& reg)
{
	return static_cast<Dsp*>(reg.plugin)->register_par(reg);
}

PluginDef *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginDef *p)
{
	delete static_cast<Dsp*>(p);
}

} // end namespace foxwah
