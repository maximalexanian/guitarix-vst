declare id   "feedback";
declare name "Feedback";
declare category "Tone Control";

import("stdfaust.lib");
import("guitarix.lib");

feedback = hslider("feedback", 0, -1, 1, 0.01);
fbackw = (- : ma.neg ) ~ (feedback * _'''');

wet = vslider("wet_dry",  100, 0, 100, 1) : /(100);
dry = 1 - wet;
  
process =  _<:*(dry),(*(wet): fbackw ):>_;
