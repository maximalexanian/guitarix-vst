// generated from file '../src/LV2/faust/jenwah.dsp' by dsp2cc:
// Code generated with Faust 2.15.11 (https://faust.grame.fr)


namespace jenwah {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
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
	id = "jenwah";
	name = N_("Jen Wah");
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

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = std::min<double>(192000.0, std::max<double>(1.0, double(fSamplingFreq)));
	fConst1 = (716.97484916389521 / fConst0);
	fConst2 = (fConst1 + 1.0);
	fConst3 = (1.0 / fConst2);
	fConst4 = (1.0 - fConst1);
	fConst5 = (0.01 / fConst2);
	fConst6 = (4.7421424498700302e-20 * fConst0);
	fConst7 = mydsp_faustpower2_f(fConst0);
	fConst8 = (((-6.5139595429217896e-17 - fConst6) * fConst7) + 2.1963298716217899e-11);
	fConst9 = (0.10471975511965977 / fConst0);
	fConst10 = std::exp((0.0 - (100.0 / fConst0)));
	fConst11 = (1.0 - fConst10);
	fConst12 = std::exp((0.0 - (10.0 / fConst0)));
	fConst13 = (1.0 - fConst12);
	fConst14 = (1.5428804132500399e-18 * fConst0);
	fConst15 = (((-5.5541523995112896e-17 - fConst14) * fConst7) + 5.5072493453199502e-12);
	fConst16 = (2.7986847676334699e-19 * fConst0);
	fConst17 = ((fConst16 + 2.7878855623725798e-17) * fConst7);
	fConst18 = ((7.1132136748050499e-20 * fConst7) + -1.15849678023402e-12);
	fConst19 = ((2.3143206198750598e-18 * fConst7) + -2.10989891977295e-13);
	fConst20 = (2.4231897119407802e-13 - (4.1980271514502001e-19 * fConst7));
	fConst21 = (((6.5139595429217896e-17 - fConst6) * fConst7) + -2.1963298716217899e-11);
	fConst22 = (((5.5541523995112896e-17 - fConst14) * fConst7) + -5.5072493453199502e-12);
	fConst23 = ((fConst16 + -2.7878855623725798e-17) * fConst7);
	fConst24 = (1.18553561246751e-20 * fConst0);
	fConst25 = (((((fConst24 + -3.2569797714608997e-17) * fConst0) + 5.79248390117011e-13) * fConst0) + -1.0981649358109e-11);
	fConst26 = (3.85720103312511e-19 * fConst0);
	fConst27 = (((((fConst26 + -2.7770761997556497e-17) * fConst0) + 1.0549494598864799e-13) * fConst0) + -2.7536246726599699e-12);
	fConst28 = (6.9967119190836604e-20 * fConst0);
	fConst29 = ((((1.3939427811862899e-17 - fConst28) * fConst0) + -1.2115948559703901e-13) * fConst0);
	fConst30 = (((((fConst24 + 3.2569797714608997e-17) * fConst0) + 5.79248390117011e-13) * fConst0) + 1.0981649358109e-11);
	fConst31 = (((((fConst26 + 2.7770761997556497e-17) * fConst0) + 1.0549494598864799e-13) * fConst0) + 2.7536246726599699e-12);
	fConst32 = ((((-1.3939427811862899e-17 - fConst28) * fConst0) + -1.2115948559703901e-13) * fConst0);
	fConst33 = (7.4475393708179402e-21 * fConst0);
	fConst34 = (((((-2.4589456637934499e-16 - fConst33) * fConst0) + -3.5346957314301301e-13) * fConst0) + -2.09356017382726e-14);
	fConst35 = (4.2496888018541799e-21 * fConst0);
	fConst36 = (((((-6.7472209089641597e-17 - fConst35) * fConst0) + -9.3305629523714399e-14) * fConst0) + -1.7091597982174e-12);
	fConst37 = (4.2631391894984302e-21 * fConst0);
	fConst38 = ((((fConst37 + 6.7438235280675997e-17) * fConst0) + 9.2116647648399394e-14) * fConst0);
	fConst39 = (2.9790157483271701e-20 * fConst0);
	fConst40 = (((fConst39 + 4.9178913275868998e-16) * fConst7) + -4.18712034765452e-14);
	fConst41 = (1.6998755207416701e-20 * fConst0);
	fConst42 = (((fConst41 + 1.34944418179283e-16) * fConst7) + -3.41831959643481e-12);
	fConst43 = (1.70525567579937e-20 * fConst0);
	fConst44 = ((-1.3487647056135199e-16 - fConst43) * fConst7);
	fConst45 = (7.0693914628602602e-13 - (4.4685236224907599e-20 * fConst7));
	fConst46 = (1.86611259047429e-13 - (2.54981328111251e-20 * fConst7));
	fConst47 = ((2.5578835136990601e-20 * fConst7) + -1.8423329529679899e-13);
	fConst48 = (((fConst39 + -4.9178913275868998e-16) * fConst7) + 4.18712034765452e-14);
	fConst49 = (((fConst41 + -1.34944418179283e-16) * fConst7) + 3.41831959643481e-12);
	fConst50 = ((1.3487647056135199e-16 - fConst43) * fConst7);
	fConst51 = (((((2.4589456637934499e-16 - fConst33) * fConst0) + -3.5346957314301301e-13) * fConst0) + 2.09356017382726e-14);
	fConst52 = (((((6.7472209089641597e-17 - fConst35) * fConst0) + -9.3305629523714399e-14) * fConst0) + 1.7091597982174e-12);
	fConst53 = ((((fConst37 + -6.7438235280675997e-17) * fConst0) + 9.2116647648399394e-14) * fConst0);
	fVslider0 = FAUSTFLOAT(100.0);
	fVslider1 = FAUSTFLOAT(0.0);
	fVslider2 = FAUSTFLOAT(24.0);
	fVslider3 = FAUSTFLOAT(0.0);
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
	double fSlow1 = (0.01 * fSlow0);
	double fSlow2 = (1.0 - fSlow1);
	double fSlow3 = (fConst5 * fSlow0);
	int iSlow4 = int(double(fVslider1));
	int iSlow5 = (iSlow4 == 0);
	int iSlow6 = (iSlow4 == 1);
	double fSlow7 = (fConst9 * double(fVslider2));
	double fSlow8 = (0.0070000000000000062 * (1.0 - double(fVslider3)));
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
		fRec5[0] = ((0.99299999999999999 * fRec5[1]) + (0.0070000000000000062 * std::max<double>(0.10000000000000001, std::min<double>(0.98999999999999999, fRec6[0]))));
		fRec8[0] = (fSlow8 + (0.99299999999999999 * fRec8[1]));
		double fTemp2 = (iSlow5?fRec8[0]:(iSlow6?fRec5[0]:(1.0 - std::max<double>(0.01, std::min<double>(0.97999999999999998, (0.5 * (fRec2[0] + 1.0)))))));
		double fTemp3 = ((fConst0 * (fConst30 + (fTemp2 * (fConst31 + (fConst32 * fTemp2))))) + 6.25823789240903e-13);
		fRec0[0] = (fRec1[0] - (((((fRec0[1] * ((fConst0 * (fConst8 + (fTemp2 * (fConst15 + (fConst17 * fTemp2))))) + 2.50329515696361e-12)) + (fRec0[2] * ((fConst7 * (fConst18 + (fTemp2 * (fConst19 + (fConst20 * fTemp2))))) + 3.7549427354454204e-12))) + (fRec0[3] * ((fConst0 * (fConst21 + (fTemp2 * (fConst22 + (fConst23 * fTemp2))))) + 2.50329515696361e-12))) + (fRec0[4] * ((fConst0 * (fConst25 + (fTemp2 * (fConst27 + (fConst29 * fTemp2))))) + 6.25823789240903e-13))) / fTemp3));
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

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case WAH: 
		fVslider3_ = (float*)data; // , 0.0, 0.0, 1.0, 0.01 
		break;
	case FREQ: 
		fVslider2_ = (float*)data; // , 24.0, 24.0, 360.0, 1.0 
		break;
	// static const value_pair fVslider1_values[] = {{"manual"},{"auto"},{"alien"},{0}};
	case MODE: 
		fVslider1_ = (float*)data; // , 0.0, 0.0, 2.0, 1.0 
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
   WAH, 
   FREQ, 
   MODE, 
   WET_DRY, 
} PortIndex;
*/

} // end namespace jenwah
