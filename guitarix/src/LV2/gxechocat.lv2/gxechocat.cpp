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

#include "lv2/lv2plug.in/ns/ext/atom/atom.h"
#include "lv2/lv2plug.in/ns/ext/atom/util.h"
#include "lv2/lv2plug.in/ns/ext/time/time.h"
#include "lv2/lv2plug.in/ns/ext/urid/urid.h"
#include "lv2/lv2plug.in/ns/lv2core/lv2.h"
////////////////////////////// LOCAL INCLUDES //////////////////////////

#include "gx_common.h"      // faust support and denormal protection (SSE)
#include "gxechocat.h"        // define struct PortIndex
#include "gx_pluginlv2.h"   // define struct PluginLV2

namespace gx_echocat {
#include "gxechocat.cc"    // dsp class generated by faust -> dsp2cc
#ifndef __SSE__
#include "noiser.cc"
#endif
////////////////////////////// PLUG-IN CLASS ///////////////////////////

class Gxechocat
{
private:
  // internal stuff
  float*                       output;
  float*                       input;
     
        
  PluginLV2*                   echocat;
#ifndef __SSE__
  PluginLV2*                   wn;
#endif
public:

  inline void run_dsp_mono(uint32_t n_samples);
  inline void connect_mono(uint32_t port,void* data);
  inline void init_dsp_mono(uint32_t rate);
  inline void connect_all_mono_ports(uint32_t port, void* data);
  inline void activate_f();
  inline void clean_up();
  inline void deactivate_f();
  Gxechocat();
  ~Gxechocat();
};

// constructor
Gxechocat::Gxechocat() :
  output(NULL),
  input(NULL),
  echocat(gxechocat::plugin()) {};

// destructor
Gxechocat::~Gxechocat()
{
  // just to be sure the plug have given free the allocated mem
  // it didn't hurd if the mem is already given free by clean_up()
  if (echocat->activate_plugin !=0)
    echocat->activate_plugin(false, echocat);
  // delete DSP class
  echocat->delete_instance(echocat);
};

////////////////////////////// PLUG-IN CLASS  FUNCTIONS ////////////////

void Gxechocat::init_dsp_mono(uint32_t rate)
{
  AVOIDDENORMALS(); // init th`ee SSE denormal protection
#ifndef __SSE__
  wn = noiser::plugin();
  wn->set_samplerate(rate, wn);
#endif
  echocat->set_samplerate(rate, echocat); // init the DSP class
}

// connect the Ports used by the plug-in class
void Gxechocat::connect_mono(uint32_t port,void* data)
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

void Gxechocat::activate_f()
{
  // allocate the internal DSP mem
  if (echocat->activate_plugin !=0)
    echocat->activate_plugin(true, echocat);
}

void Gxechocat::clean_up()
{
#ifndef __SSE__
  wn->delete_instance(wn);;
#endif
  // delete the internal DSP mem
  if (echocat->activate_plugin !=0)
    echocat->activate_plugin(false, echocat);
}

void Gxechocat::deactivate_f()
{  
  // delete the internal DSP mem
  if (echocat->activate_plugin !=0)
    echocat->activate_plugin(false, echocat);
}

void Gxechocat::run_dsp_mono(uint32_t n_samples)
{
#ifndef __SSE__
  wn->mono_audio(static_cast<int>(n_samples), input, input, wn);;
#endif
  echocat->mono_audio(static_cast<int>(n_samples), input,
                        output, echocat);
}

void Gxechocat::connect_all_mono_ports(uint32_t port, void* data)
{
  // connect the Ports used by the plug-in class
  connect_mono(port,data); 
  // connect the Ports used by the DSP class
  echocat->connect_ports(port,  data, echocat);
}

///////////////////////////// LV2 defines //////////////////////////////

static LV2_Handle
instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  // init the plug-in class

  Gxechocat *self = new Gxechocat();
  if (!self)
    {
      return NULL;
    }
  self->init_dsp_mono((uint32_t)rate);

  return (LV2_Handle)self;
}

static void
connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
  // connect all ports
  static_cast<Gxechocat*>(instance)->connect_all_mono_ports(port, data);
}

static void
activate(LV2_Handle instance)
{
  // allocate needed mem
  static_cast<Gxechocat*>(instance)->activate_f();
}

static void
run(LV2_Handle instance, uint32_t n_samples)
{
  // run dsp
  static_cast<Gxechocat*>(instance)->run_dsp_mono(n_samples);
}

static void
deactivate(LV2_Handle instance)
{
  // free allocated mem
  static_cast<Gxechocat*>(instance)->deactivate_f();
}

static void
cleanup(LV2_Handle instance)
{
  // well, clean up after us
  Gxechocat* self = static_cast<Gxechocat*>(instance);
  self->clean_up();
  delete self;
}

///////////////////////////// LV2 DESCRIPTOR ///////////////////////////

static const LV2_Descriptor descriptor =
{
  GXPLUGIN_URI "#echocat",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  NULL
};

} // end namespace gx_echocat

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &gx_echocat::descriptor;
    default:
      return NULL;
    }
}

///////////////////////////// FIN //////////////////////////////////////
