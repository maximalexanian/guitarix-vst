declare id "metal"; // in amp tube ba.selector
declare name "GxMetal_head";

import("stdfaust.lib"); 
import("guitarix.lib");

/****************************************************************
 ** Tube Preamp Emulation stage 1 - 2 
 */

tubeax(preamp,gain1) =  hgroup("stage1", stage1)  :
                        hgroup("stage2", stage2) : tone :
                        hgroup("stage3", stage3)
                        with {
    stage1 = tubestage(TB_12AX7_68k,86.0,2700.0,1.581656) : *(preamp):
        fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,132.0,1500.0,1.204285); 
    stage2 = fi.lowpass(1,6531.0) : tubestage(TB_12AX7_250k,194.0,820.0,0.840703)  ; 
    tone = component("bigmuff.dsp").bigmuff ;
    stage3 =  *(gain1) : _<:(tubestageP(TB_6L6CG_68k,450.0,40.0,5000, 256.0,490.0,20.063657),
        tubestageP(TB_6L6CG_250k,450.0,40.0,5000, 256.0,490.0,20.063657)):> *(gain1) :fi.lowpass(1,6531.0) ;
};
 //tubestageP(tb,vplus,divider,Rp,fck,Rk,Vk0)
 //tubestage(tb,fck,Rk,Vk0)

process = component("gxdistortion.dsp").distdrive1(drive) :
          tubeax(preamp,gain1) : div_drive with {
    drive = ampctrl.drive;
    div_drive = *((drive*-12):ba.db2linear : smoothi(0.999));
    preamp = ampctrl.preamp;
    gain1 = ampctrl.gain1;
};
