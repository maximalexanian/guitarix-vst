declare name   "Treble boost";
declare category "Tone Control";

import("stdfaust.lib");

level = vslider("Level", 0, 0.5, 20, 0.5) ;
hfboost(level,fx,x) = x + (ba.db2linear(level)-1)*fi.highpass(1,fx,x);

process = hfboost(level, 1500);
