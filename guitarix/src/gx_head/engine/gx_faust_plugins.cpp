/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden
 * Copyright (C) 2011 Pete Shorthose, Andreas Degert
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 * --------------------------------------------------------------------------
 */

#include <glibmm/i18n.h>
#include <cstdlib>
#include <cmath>
#include "gx_faust_plugins.h"
#include "gx_faust_support.h"

namespace gx_engine {

namespace gx_amps {
#include "../../faust-generated/gxamp.cc"
#include "../../faust-generated/gxamp2.cc"
#include "../../faust-generated/gxamp3.cc"
#include "../../faust-generated/gxamp4.cc"
#include "../../faust-generated/gxamp5.cc"
#include "../../faust-generated/gxamp6.cc"
#include "../../faust-generated/gxamp7.cc"
#include "../../faust-generated/gxamp8.cc"
#include "../../faust-generated/gxamp9.cc"
#include "../../faust-generated/gxamp10.cc"
#include "../../faust-generated/gxamp11.cc"
#include "../../faust-generated/gxamp12.cc"
#include "../../faust-generated/gxamp13.cc"
#include "../../faust-generated/gxamp14.cc"
#include "../../faust-generated/gxamp15.cc"
#include "../../faust-generated/gxamp16.cc"
#include "../../faust-generated/gxamp17.cc"
#include "../../faust-generated/gxamp18.cc"
#include "../../faust-generated/gxnoamp.cc"
#include "../../faust-generated/gx_ampmodul.cc"
}

namespace gx_tonestacks {
#include "../../faust-generated/tonestack_default.cc"
#include "../../faust-generated/tonestack_bassman.cc"
#include "../../faust-generated/tonestack_twin.cc"
#include "../../faust-generated/tonestack_princeton.cc"
#include "../../faust-generated/tonestack_jcm800.cc"
#include "../../faust-generated/tonestack_jcm2000.cc"
#include "../../faust-generated/tonestack_mlead.cc"
#include "../../faust-generated/tonestack_m2199.cc"
#include "../../faust-generated/tonestack_ac30.cc"
#include "../../faust-generated/tonestack_mesa.cc"
#include "../../faust-generated/tonestack_soldano.cc"
#include "../../faust-generated/tonestack_jtm45.cc"
#include "../../faust-generated/tonestack_ac15.cc"
#include "../../faust-generated/tonestack_peavey.cc"
#include "../../faust-generated/tonestack_ibanez.cc"
#include "../../faust-generated/tonestack_roland.cc"
#include "../../faust-generated/tonestack_ampeg.cc"
#include "../../faust-generated/tonestack_ampeg_rev.cc"
#include "../../faust-generated/tonestack_sovtek.cc"
#include "../../faust-generated/tonestack_bogner.cc"
#include "../../faust-generated/tonestack_groove.cc"
#include "../../faust-generated/tonestack_crunch.cc"
#include "../../faust-generated/tonestack_fender_blues.cc"
#include "../../faust-generated/tonestack_fender_default.cc"
#include "../../faust-generated/tonestack_fender_deville.cc"
#include "../../faust-generated/tonestack_gibsen.cc"
#include "../../faust-generated/tonestack_engl.cc"
}

namespace gx_effects {
#include "../../faust-generated/bassbooster.cc"
#include "../../faust-generated/highbooster.cc"
#include "../../faust-generated/gxfeedreverb.cc"
#include "../../faust-generated/gxfeed.cc"
#include "../../faust-generated/gx_feedback.cc"
#include "../../faust-generated/gx_outputlevel.cc"
#include "../../faust-generated/gx_ampout.cc"
#include "../../faust-generated/overdrive.cc"
#include "../../faust-generated/compressor.cc"
#include "../../faust-generated/expander.cc"
#include "../../faust-generated/crybaby.cc"
#include "../../faust-generated/autowah.cc"
#include "../../faust-generated/echo.cc"
#include "../../faust-generated/delay.cc"
#include "../../faust-generated/stereodelay.cc"
#include "../../faust-generated/stereoecho.cc"
#include "../../faust-generated/noise_shaper.cc"
#include "../../faust-generated/gx_distortion.cc"
#include "../../faust-generated/bitdowner.cc"
#include "../../faust-generated/thick_distortion.cc"
#include "../../faust-generated/freeverb.cc"
#include "../../faust-generated/impulseresponse.cc"
#include "../../faust-generated/chorus.cc"
#include "../../faust-generated/moog.cc"
#include "../../faust-generated/biquad.cc"
#include "../../faust-generated/flanger.cc"
#include "../../faust-generated/selecteq.cc"
#include "../../faust-generated/phaser.cc"
#include "../../faust-generated/low_high_pass.cc"
#include "../../faust-generated/softclip.cc"
#include "../../faust-generated/tonecontroll.cc"
#include "../../faust-generated/tremolo.cc"
#include "../../faust-generated/phaser_mono.cc"
#include "../../faust-generated/chorus_mono.cc"
#include "../../faust-generated/flanger_mono.cc"
#include "../../faust-generated/stereoverb.cc"
#include "../../faust-generated/peak_eq.cc"
#include "../../faust-generated/digital_delay.cc"
#include "../../faust-generated/digital_delay_st.cc"
#include "../../faust-generated/dattorros_progenitor.cc"
#include "../../faust-generated/ring_modulator.cc"
#include "../../faust-generated/ring_modulator_st.cc"
#include "../../faust-generated/panoram_enhancer.cc"
#include "../../faust-generated/graphiceq.cc"
#include "../../faust-generated/bass_enhancer.cc"
#include "../../faust-generated/gain.cc"
#include "../../faust-generated/duck_delay.cc"
#include "../../faust-generated/duck_delay_st.cc"
#include "../../faust-generated/duck_delay_dbl.cc"
#include "../../faust-generated/baxandall.cc"
#include "../../faust-generated/distortion2.cc"
#include "../../faust-generated/fuzzface.cc"
#include "../../faust-generated/trbuff.cc"
#include "../../faust-generated/colwah.cc"
#include "../../faust-generated/dallaswah.cc"
#include "../../faust-generated/foxwah.cc"
#include "../../faust-generated/maestrowah.cc"
#include "../../faust-generated/voxwah.cc"
#include "../../faust-generated/selwah.cc"
#include "../../faust-generated/jenwah.cc"
#include "../../faust-generated/colbwah.cc"
#include "../../faust-generated/rolwah.cc"
#include "../../faust-generated/jenbasswah.cc"

}

#include "../../faust-generated/balance.cc"

}
