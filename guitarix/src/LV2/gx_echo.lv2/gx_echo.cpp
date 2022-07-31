/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose, Steve Poskitt
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
#include "gx_echo.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2
#include "stereoecho.cc"    // dsp class generated by faust -> dsp2cc

////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gx_echo_stereo
{
private:
  // pointer to buffer
  float*      output;
  float*      input;
  float*      output1;
  float*      input1;
  // pointer to dsp class
  PluginLV2*  echo_st;
  // private functions
  inline void run_dsp_stereo(uint32_t n_samples);
  inline void connect_stereo(uint32_t port,void* data);
  inline void init_dsp_stereo(uint32_t rate);
  inline void connect_all_stereo_ports(uint32_t port, void* data);
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
  Gx_echo_stereo();
  ~Gx_echo_stereo();
};

// constructor
Gx_echo_stereo::Gx_echo_stereo() :
  output(NULL),
  input(NULL),
  output1(NULL),
  input1(NULL),
  echo_st(stereoecho::plugin()) {};

// destructor
Gx_echo_stereo::~Gx_echo_stereo()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (echo_st->activate_plugin !=0)
    echo_st->activate_plugin(false, echo_st);
  // delete DSP class
  echo_st->delete_instance(echo_st);
};

///////////////////////// PRIVATE CLASS  FUNCTIONS /////////////////////

void Gx_echo_stereo::init_dsp_stereo(uint32_t rate)
{
  AVOIDDENORMALS(); // init the SSE denormal protection
  echo_st->set_samplerate(rate, echo_st); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gx_echo_stereo::connect_stereo(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case EFFECTS_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case EFFECTS_OUTPUT1:
      output1 = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT:
      input = static_cast<float*>(data);
      break;
    case EFFECTS_INPUT1:
      input1 = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void Gx_echo_stereo::activate_f()
{
  // allocate the internal DSP mem
  if (echo_st->activate_plugin !=0)
    echo_st->activate_plugin(true, echo_st);
}

void Gx_echo_stereo::clean_up()
{
  // delete the internal DSP mem
  if (echo_st->activate_plugin !=0)
    echo_st->activate_plugin(false, echo_st);
}

void Gx_echo_stereo::deactivate_f()
{
  // delete the internal DSP mem
  if (echo_st->activate_plugin !=0)
    echo_st->activate_plugin(false, echo_st);
}

void Gx_echo_stereo::run_dsp_stereo(uint32_t n_samples)
{
  echo_st->stereo_audio(static_cast<int>(n_samples), input, input1,
                        output, output1, echo_st);
}

void Gx_echo_stereo::connect_all_stereo_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_stereo(port,data); 
  // connect the Ports used by the DSP class
  echo_st->connect_ports(port,  data, echo_st);
}

////////////////////// STATIC CLASS  FUNCTIONS  ////////////////////////

LV2_Handle 
Gx_echo_stereo::instantiate(const LV2_Descriptor* descriptor,
                            double rate, const char* bundle_path,
                            const LV2_Feature* const* features)
{
  // init the plug-in class
  Gx_echo_stereo *self = new Gx_echo_stereo();
  if (!self)
    {
      return NULL;
    }

  self->init_dsp_stereo((uint32_t)rate);

  return (LV2_Handle)self;
}

void Gx_echo_stereo::connect_port(LV2_Handle instance, 
                                   uint32_t port, void* data)
{
  // connect all ports
  static_cast<Gx_echo_stereo*>(instance)->connect_all_stereo_ports(port, data);
}

void Gx_echo_stereo::activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gx_echo_stereo*>(instance)->activate_f();
}

void Gx_echo_stereo::run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gx_echo_stereo*>(instance)->run_dsp_stereo(n_samples);
}

void Gx_echo_stereo::deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gx_echo_stereo*>(instance)->deactivate_f();
}

void Gx_echo_stereo::cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gx_echo_stereo* self = static_cast<Gx_echo_stereo*>(instance);
  self->clean_up();
  delete self;
}

const LV2_Descriptor Gx_echo_stereo::descriptor =
{
  GXPLUGIN_URI "#_echo_stereo",
  Gx_echo_stereo::instantiate,
  Gx_echo_stereo::connect_port,
  Gx_echo_stereo::activate,
  Gx_echo_stereo::run,
  Gx_echo_stereo::deactivate,
  Gx_echo_stereo::cleanup,
  NULL
};

////////////////////////// LV2 SYMBOL EXPORT ///////////////////////////

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &Gx_echo_stereo::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
