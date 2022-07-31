/*
 * Copyright (C) 2014 Guitarix project MOD project
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
 */


////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gx_muff.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "gx_resampler.h"
#include "muff.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

namespace muff {

class Gx_muff_
{
private:
  // pointer to buffer
  float*      output;
  float*      input;
  // pointer to dsp class
  PluginLV2*  muff;
  // private functions
  inline void run_dsp_(uint32_t n_samples);
  inline void connect_(uint32_t port,void* data);
  inline void init_dsp_(uint32_t rate);
  inline void connect_all__ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();

public:
  // LV2 Descriptor
  static const LV2_Descriptor descriptor;
  // static wrapper to private functions
  static void deactivate(LV2_Handle instance);
  static void cleanup(LV2_Handle instance);
  static void run(LV2_Handle instance, uint32_t n_samples);
  static void activate(LV2_Handle instance);
  static void connect_port(LV2_Handle instance, uint32_t port, void* data);
  static LV2_Handle instantiate(const LV2_Descriptor* descriptor,
                                double rate, const char* bundle_path,
                                const LV2_Feature* const* features);
  Gx_muff_();
  ~Gx_muff_();
};

// constructor
Gx_muff_::Gx_muff_() :
  output(NULL),
  input(NULL),
  muff(muff::plugin()) {};

// destructor
Gx_muff_::~Gx_muff_()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (muff->activate_plugin !=0)
    muff->activate_plugin(false, muff);
  // delete DSP class
  muff->delete_instance(muff);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Gx_muff_::init_dsp_(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  muff->set_samplerate(rate, muff); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_muff_::connect_(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_muff_::activate_f()
{
  // allocate the internal DSP mem
  if (muff->activate_plugin !=0)
    muff->activate_plugin(true, muff);
}

void Gx_muff_::clean_up()
{
  // delete the internal DSP mem
  if (muff->activate_plugin !=0)
    muff->activate_plugin(false, muff);
}

void Gx_muff_::deactivate_f()
{
  // delete the internal DSP mem
  if (muff->activate_plugin !=0)
    muff->activate_plugin(false, muff);
}

void Gx_muff_::run_dsp_(uint32_t n_samples)
{
  muff->mono_audio(static_cast<int>(n_samples), input, output, muff);
}

void Gx_muff_::connect_all__ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_(port,data); 
  // connect the Ports used by the DSP class
  muff->connect_ports(port,  data, muff);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Gx_muff_::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_muff_ *self = new Gx_muff_();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_muff_::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<Gx_muff_*>(instance)->connect_all__ports(port, data);
}

void Gx_muff_::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_muff_*>(instance)->activate_f();
}

void Gx_muff_::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_muff_*>(instance)->run_dsp_(n_samples);
}

void Gx_muff_::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_muff_*>(instance)->deactivate_f();
}

void Gx_muff_::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_muff_* self = static_cast<Gx_muff_*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gx_muff_::descriptor =
{
  GXPLUGIN_URI "#_muff_",
  Gx_muff_::instantiate,
  Gx_muff_::connect_port,
  Gx_muff_::activate,
  Gx_muff_::run,
  Gx_muff_::deactivate,
  Gx_muff_::cleanup,
  NULL
};


} // end namespace muff

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &muff::Gx_muff_::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
