declare id "mbc";
declare name "Multi Band Compressor";
declare shortname "MB Compressor";
declare category "Guitar Effects";
declare description "Multi Band Compressor contributed by kokoko3k";

import("stdfaust.lib");
import("reducemaps.lib");

vmeter1(x)		= attach(x, envelop(x) : vbargraph("v1[tooltip:no]", -70, +5));
vmeter2(x)		= attach(x, envelop(x) : vbargraph("v2[tooltip:no]", -70, +5));
vmeter3(x)		= attach(x, envelop(x) : vbargraph("v3[tooltip:no]", -70, +5));
vmeter4(x)		= attach(x, envelop(x) : vbargraph("v4[tooltip:no]", -70, +5));
vmeter5(x)		= attach(x, envelop(x) : vbargraph("v5[tooltip:no]", -70, +5));
vmeter6(x)		= attach(x, envelop(x) : vbargraph("v6[tooltip:no]", -70, +5));
vmeter7(x)		= attach(x, envelop(x) : vbargraph("v7[tooltip:no]", -70, +5));
vmeter8(x)		= attach(x, envelop(x) : vbargraph("v8[tooltip:no]", -70, +5));
vmeter9(x)		= attach(x, envelop(x) : vbargraph("v9[tooltip:no]", -70, +5));
vmeter10(x)		= attach(x, envelop(x) : vbargraph("v10[tooltip:no]", -70, +5));

envelop         = abs : max ~ (1.0/ma.SR) : mean(4096) ; // : max(ba.db2linear(-70)) : ba.linear2db;

//Mono 
process =   geq : ( gcomp5s , gcomp4s , gcomp3s, gcomp2s, gcomp1s) :>_ with { 
gcomp1s = vmeter6:ba.bypass1(bswitch1,co.compressor_mono(ratio1,-push1,attack1,release1)):*(Makeup1) : vmeter1;
gcomp2s = vmeter7:ba.bypass1(bswitch2,co.compressor_mono(ratio2,-push2,attack2,release2)):*(Makeup2) : vmeter2;
gcomp3s = vmeter8:ba.bypass1(bswitch3,co.compressor_mono(ratio3,-push3,attack3,release3)):*(Makeup3) : vmeter3;
gcomp4s = vmeter9:ba.bypass1(bswitch4,co.compressor_mono(ratio4,-push4,attack4,release4)):*(Makeup4) : vmeter4;
gcomp5s = vmeter10:ba.bypass1(bswitch5,co.compressor_mono(ratio5,-push5,attack5,release5)):*(Makeup5) : vmeter5;
};

sel1         = hslider("Mode1[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]",1,1,3,1);
sel2         = hslider("Mode2[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]",1,1,3,1);
sel3         = hslider("Mode3[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]",1,1,3,1);
sel4         = hslider("Mode4[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]",1,1,3,1);
sel5         = hslider("Mode5[enum:Compress|Bypass|Mute][tooltip: Compress or Mute the selected band, or Bypass The Compressor]",1,1,3,1);

not(x) 	= abs(x-1);
mute1		= not(max(0,sel1-2));
mute2		= not(max(0,sel2-2));
mute3		= not(max(0,sel3-2));
mute4		= not(max(0,sel4-2));
mute5		= not(max(0,sel5-2));

bypass(switch, block) = _ <: select2(switch, _, block);

bswitch1	= max(0,sel1-1);
bswitch2	= max(0,sel2-1);
bswitch3	= max(0,sel3-1);
bswitch4	= max(0,sel4-1);
bswitch5	= max(0,sel5-1);

hifr1			=hslider("crossover_b1_b2 [log][name:Crossover B1-B2 (hz)][tooltip: Crossover fi.bandpass frequency]" ,80 , 20, 20000, 1.08);
hifr2			=hslider("crossover_b2_b3 [log][name:Crossover B2-B3 (hz)][tooltip: Crossover fi.bandpass frequency]",210,20,20000,1.08);
hifr3			=hslider("crossover_b3_b4 [log][name:Crossover B3-B4 (hz)][tooltip: Crossover fi.bandpass frequency]",1700,20,20000,1.08);
hifr4			=hslider("crossover_b4_b5 [log][name:Crossover B4-B5 (hz)][tooltip: Crossover fi.bandpass frequency]",5000,20,20000,1.08);

geq = fi.filterbank(3, (hifr1,hifr2,hifr3,hifr4));

ratio1 		= hslider("[9] Ratio1 [tooltip: Compression ratio]",2,1,100,0.1);
attack1		= hslider("[A] Attack1 [tooltip: Time before the compressor starts to kick in]", 0.012, 0.001, 1, 0.001);
release1 	= hslider("[B] Release1 [tooltip: Time before the compressor releases the sound]", 1.25, 0.01, 10, 0.01);

ratio2 		= hslider("[9] Ratio2 [tooltip: Compression ratio]",2,1,100,0.1);
attack2		= hslider("[A] Attack2 [tooltip: Time before the compressor starts to kick in]", 0.012, 0.001, 1, 0.001);
release2 	= hslider("[B] Release2 [tooltip: Time before the compressor releases the sound]", 1.25, 0.01, 10, 0.01);

ratio3 		= hslider("[9] Ratio3 [tooltip: Compression ratio]",2,1,100,0.1);
attack3		= hslider("[A] Attack3 [tooltip: Time before the compressor starts to kick in]", 0.012, 0.001, 1, 0.001);
release3 	= hslider("[B] Release3 [tooltip: Time before the compressor releases the sound]", 1.25, 0.01, 10, 0.01);

ratio4 		= hslider("[9] Ratio4 [tooltip: Compression ratio]",2,1,100,0.1);
attack4		= hslider("[A] Attack4 [tooltip: Time before the compressor starts to kick in]", 0.012, 0.001, 1, 0.001);
release4 	= hslider("[B] Release4 [tooltip: Time before the compressor releases the sound]", 1.25, 0.01, 10, 0.01);

ratio5 		= hslider("[9] Ratio5 [tooltip: Compression ratio]",2,1,100,0.1);
attack5		= hslider("[A] Attack5 [tooltip: Time before the compressor starts to kick in]", 0.012, 0.001, 1, 0.001);
release5 	= hslider("[B] Release5 [tooltip: Time before the compressor releases the sound]", 1.25, 0.01, 10, 0.01);

push1 		= hslider("[5] Makeup1 [tooltip: Post amplification and threshold]"   , 13, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push
push2 		= hslider("[5] Makeup2 [tooltip: Post amplification and threshold]"   , 10, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push
push3 		= hslider("[5] Makeup3 [tooltip: Post amplification and threshold]"   , 4,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push
push4 		= hslider("[5] Makeup4 [tooltip: Post amplification and threshold]"   , 8,  -50, +50, 0.1) ; // threshold-=push ;  makeup+=push
push5 		= hslider("[5] Makeup5 [tooltip: Post amplification and threshold]"   , 11, -50, +50, 0.1) ; // threshold-=push ;  makeup+=push

safe1 	= hslider("[6] MakeupThreshold1 [tooltip: Threshold correction, an anticlip measure]" , 2, 0, +10, 0.1) ; // makeup-=safe
safe2 	= hslider("[6] MakeupThreshold2 [tooltip: Threshold correction, an anticlip measure]" , 2, 0, +10, 0.1) ; // makeup-=safe
safe3 	= hslider("[6] MakeupThreshold3 [tooltip: Threshold correction, an anticlip measure]" , 2, 0, +10, 0.1) ; // makeup-=safe
safe4 	= hslider("[6] MakeupThreshold4 [tooltip: Threshold correction, an anticlip measure]" , 2, 0, +10, 0.1) ; // makeup-=safe
safe5 	= hslider("[6] MakeupThreshold5 [tooltip: Threshold correction, an anticlip measure]" , 2, 0, +10, 0.1) ; // makeup-=safe

Makeup1	=  mute1* (not(bswitch1)*(push1-safe1)  : ba.db2linear : si.smooth(0.999));
Makeup2	=  mute2* (not(bswitch2)*(push2-safe2)  : ba.db2linear : si.smooth(0.999));
Makeup3	=  mute3* (not(bswitch3)*(push3-safe3)  : ba.db2linear : si.smooth(0.999));
Makeup4	=  mute4* (not(bswitch4)*(push4-safe4)  : ba.db2linear : si.smooth(0.999));
Makeup5	=  mute5* (not(bswitch5)*(push5-safe5)  : ba.db2linear : si.smooth(0.999));

//Low end headsets: 13,10,4,8,11 (split 80,210,1700,5000)
//Mid-high end headsets: 17,20.5,20,10.5,10 (split 44,180,800,5000)
