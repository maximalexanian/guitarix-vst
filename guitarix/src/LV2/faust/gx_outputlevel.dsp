
import("stdfaust.lib");
import("guitarix.lib");

gain = vslider(".amp.out_master[name:Level]", 0, -50, 4, 0.1) : ba.db2linear : smoothi(0.999);
process = *(gain), *(gain);
