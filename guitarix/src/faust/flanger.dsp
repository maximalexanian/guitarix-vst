declare id 		"flanger";
declare name            "Flanger";
declare category        "Modulation";
declare license 	"BSD";

import("stdfaust.lib");
import("guitarix.lib");

flangerstereogx = *(level),*(level) : flangerstereoN(dmax,curdel1,curdel2,depth,fb,invert) // change to pf.flanger_stereo for faust >= 0.9.27
with {
  lfol = os.oscrs; // sine for left channel
  lfor = os.oscrc; // cosine for right channel
  dmax = 2048;
  dflange = 0.001 * ma.SR * hslider("flange delay[name:Delay][unit:ms]", 10, 0, 20, 0.01);
  odflange = 0.001 * ma.SR * hslider("flange delay offset[name:Offset][unit:ms]", 1, 0, 20, 0.01);
  //freq	 = hslider("LFO freq [unit:Hz]", 0.2, 0, 5, 0.01);
  freq     = hslider("lfobpm[name:BPM][unit:bpm][tooltip:LFO in Beats per Minute]",24,24,360,1)/60;
  depth	 = hslider("depth[name:Depth]", 1, 0, 1, 0.01);
  fb	 = hslider("feedback gain[name:Feedback]", 0, 0, 1, 0.01);
  invert   = checkbox("invert[enum:linear|invert][name:Invert]");
  level	 = hslider("level[name:Level][unit:dB]", 0, -60, 10, 0.1) : ba.db2linear;
  curdel1 = odflange+dflange*(1 + lfol(freq))/2; 
  curdel2 = odflange+dflange*(1 + lfor(freq))/2; 
};

process = flangerstereogx;
