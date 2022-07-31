// generated from file '../src/faust/cabinet_impulse_former.dsp' by dsp2cc:
// Code generated with Faust 0.9.65 (http://faust.grame.fr)

#define FAUSTFLOAT float


class Impf {
private:
	int fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	int 	iConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fVec0[3];
	double 	fRec1[3];
	FAUSTFLOAT 	fslider1;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fRec0[3];
	FAUSTFLOAT 	fslider2;

public:
	void clear_state_f();
	void init(unsigned int samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, float bass, float treble, float level);
	Impf();
	~Impf();
};

Impf::Impf() {
}

Impf::~Impf() {
}

inline void Impf::clear_state_f()
{
	for (int i=0; i<3; i++) fVec0[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
}

inline void Impf::init(unsigned int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	iConst0 = min(192000, max(1, fSamplingFreq));
	fConst1 = (1884.9555921538758 / double(iConst0));
	fConst2 = (1.4142135623730951 * sin(fConst1));
	fConst3 = cos(fConst1);
	fConst4 = (15079.644737231007 / double(iConst0));
	fConst5 = (1.4142135623730951 * sin(fConst4));
	fConst6 = cos(fConst4);
	clear_state_f();
}

void always_inline Impf::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, float value1, float value2, float value3)
{
 fslider0 = value1;
 fslider1 = value2;
 fslider2 = value3;
	double 	fSlow0 = pow(10,(0.025 * double(fslider0)));
	double 	fSlow1 = (fConst2 * sqrt(fSlow0));
	double 	fSlow2 = (fConst3 * (fSlow0 - 1));
	double 	fSlow3 = (fSlow0 + fSlow2);
	double 	fSlow4 = ((1 + fSlow3) - fSlow1);
	double 	fSlow5 = (1 + fSlow0);
	double 	fSlow6 = (fConst3 * fSlow5);
	double 	fSlow7 = (0 - (2 * ((fSlow0 + fSlow6) - 1)));
	double 	fSlow8 = (fSlow5 - (fSlow2 + fSlow1));
	double 	fSlow9 = (2 * (0 - ((1 + fSlow6) - fSlow0)));
	double 	fSlow10 = ((1 + (fSlow0 + fSlow1)) - fSlow2);
	double 	fSlow11 = (1.0 / (1 + (fSlow1 + fSlow3)));
	double 	fSlow12 = pow(10,(0.025 * double(fslider1)));
	double 	fSlow13 = (fConst5 * sqrt(fSlow12));
	double 	fSlow14 = (fConst6 * (fSlow12 - 1));
	double 	fSlow15 = (fSlow12 + fSlow14);
	double 	fSlow16 = (fSlow12 * ((1 + fSlow15) - fSlow13));
	double 	fSlow17 = (1 + fSlow12);
	double 	fSlow18 = (fConst6 * fSlow17);
	double 	fSlow19 = ((0 - (2 * fSlow12)) * ((fSlow12 + fSlow18) - 1));
	double 	fSlow20 = (fSlow12 * (1 + (fSlow15 + fSlow13)));
	double 	fSlow21 = (2 * (0 - ((1 + fSlow18) - fSlow12)));
	double 	fSlow22 = (fSlow17 - (fSlow14 + fSlow13));
	double 	fSlow23 = (1.0 / ((1 + (fSlow12 + fSlow13)) - fSlow14));
	double 	fSlow24 = double(fslider2);
	double 	fSlow25 = (fSlow24 * pow(10,(0 - (0.1 * fSlow24))));
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fVec0[0] = fTemp0;
		fRec1[0] = (fSlow11 * ((fSlow0 * (((fSlow10 * fVec0[0]) + (fSlow9 * fVec0[1])) + (fSlow8 * fVec0[2]))) - ((fSlow7 * fRec1[1]) + (fSlow4 * fRec1[2]))));
		fRec0[0] = (fSlow23 * ((0 - ((fSlow22 * fRec0[2]) + (fSlow21 * fRec0[1]))) + (((fSlow20 * fRec1[0]) + (fSlow19 * fRec1[1])) + (fSlow16 * fRec1[2]))));
		output0[i] = (FAUSTFLOAT)(fSlow25 * fRec0[0]);
		// post processing
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fVec0[2] = fVec0[1]; fVec0[1] = fVec0[0];
	}
}

