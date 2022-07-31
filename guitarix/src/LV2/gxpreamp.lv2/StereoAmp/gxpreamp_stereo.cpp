/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
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
#include	<stdio.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <glibmm.h>
#include <unistd.h>

#ifdef __SSE__
/* On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
   flags to avoid costly denormals */
#ifdef __SSE3__
#include <pmmintrin.h>
inline void AVOIDDENORMALS()
{
  _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
  _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
}
#else
#include <xmmintrin.h>
inline void AVOIDDENORMALS()
{
  _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON);
}
#endif //__SSE3__

#else
inline void AVOIDDENORMALS() {}
#endif //__SSE__

// faust support
#define FAUSTFLOAT float
#ifndef N_
#define N_(String) (String)
#endif
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
template <int32_t N> inline float faustpower(float x)
{
  return powf(x, N);
}
template <int32_t N> inline double faustpower(double x)
{
  return pow(x, N);
}
template <int32_t N> inline int32_t faustpower(int32_t x)
{
  return faustpower<N/2>(x) * faustpower<N-N/2>(x);
}
template <>      inline int32_t faustpower<0>(int32_t x)
{
  return 1;
}
template <>      inline int32_t faustpower<1>(int32_t x)
{
  return x;
}

/****************************************************************
 ** "atomic" value access
 */

inline void atomic_set(volatile int32_t* p, int32_t v)
{
  g_atomic_int_set(p, v);
}

inline int32_t atomic_get(volatile int32_t& p)
{
  return g_atomic_int_get(&p);
}

inline bool atomic_compare_and_exchange(volatile int32_t *p, int32_t oldv, int32_t newv)
{
  return g_atomic_int_compare_and_exchange(p, oldv, newv);
}

template <class T>
inline void atomic_set(T **p, T *v)
{
  g_atomic_pointer_set(p, v);
}

template <class T>
inline void atomic_set_0(T **p)
{
  g_atomic_pointer_set(p, 0);
}

template <class T>
inline T *atomic_get(T*& p)
{
  return static_cast<T*>(g_atomic_pointer_get(&p));
}

template <class T>
inline bool atomic_compare_and_exchange(T **p, T *oldv, T *newv)
{
  return g_atomic_pointer_compare_and_exchange(reinterpret_cast<void* volatile*>(p), oldv, newv);
}


#include "gxpreamp.h"
#include "gx_preamp.h"

// define run pointer typs
typedef void (GxPreAmpStereo::*run_amp_stereo)
(uint32_t count,float* input, float* input1, float* output, float* output1);


//////////////////////////// STEREO ////////////////////////////////////

class GxPluginStereo
{
private:
  // internal stuff
  float*                       output;
  float*                       input;
  float*                       output1;
  float*                       input1;

  GxPreAmpStereo                  amplifier;
  run_amp_stereo               _as_ptr;
  uint32_t                     bufsize;
  bool                         doit;
  volatile int32_t             schedule_wait;
 

public:
  // LV2 stuff
  LV2_URID_Map*                map;
  LV2_Worker_Schedule*         schedule;

  inline void run_dsp_stereo(uint32_t n_samples);
  void connect_stereo(uint32_t port,void* data);
  inline void init_dsp_stereo(uint32_t rate, uint32_t bufsize_);
  inline void do_work_stereo();
  inline void connect_all_stereo_ports(uint32_t port, void* data);

  GxPluginStereo() :
    output(NULL),
    input(NULL),
    output1(NULL),
    input1(NULL),
    amplifier(GxPreAmpStereo()),
    bufsize(0)
  {
    atomic_set(&schedule_wait,0);
  };

  ~GxPluginStereo()
  {
  };
};


#include "gx_preamp.cc"

// plugin stuff

void GxPluginStereo::do_work_stereo()
{
	// Work for the maxlevels here
  atomic_set(&schedule_wait,0);
}


void GxPluginStereo::init_dsp_stereo(uint32_t rate, uint32_t bufsize_)
{
  AVOIDDENORMALS();
  bufsize = bufsize_;
  _as_ptr = &GxPreAmpStereo::run;
  amplifier.init_static(rate, &amplifier);
}


void GxPluginStereo::connect_stereo(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {

    case AMP_OUTPUT:
      output = static_cast<float*>(data);
      break;
    case AMP_INPUT:
      input = static_cast<float*>(data);
      break;
    case AMP_OUTPUT1:
      output1 = static_cast<float*>(data);
      break;
    case AMP_INPUT1:
      input1 = static_cast<float*>(data);
      break;
    default:
      break;
    }
}

void GxPluginStereo::run_dsp_stereo(uint32_t n_samples)
{
  // run dsp
  (&amplifier->*_as_ptr)(n_samples, input, input1, output, output1);
  //amplifier.run_static(n_samples, input, input1, output, output1, &amplifier);
  // work ?
  if (!atomic_get(schedule_wait) )
    {
	// Do max values and set work
      atomic_set(&schedule_wait,1);
      schedule->schedule_work(schedule->handle, sizeof(bool), &doit);
    }
}

void GxPluginStereo::connect_all_stereo_ports(uint32_t port, void* data)
{
  connect_stereo(port,data);
  amplifier.connect_static(port,data, &amplifier);
 
}

///////////////////////////// LV2 defines //////////////////////////////

static LV2_Worker_Status
work(LV2_Handle                  instance,
     LV2_Worker_Respond_Function respond,
     LV2_Worker_Respond_Handle   handle,
     uint32_t                    size,
     const void*                 data)
{
  GxPluginStereo* self = (GxPluginStereo*)instance;
  self->do_work_stereo();
  return LV2_WORKER_SUCCESS;
}

static LV2_Worker_Status
work_response(LV2_Handle  instance,
              uint32_t    size,
              const void* data)
{
  //printf("worker respose.\n");
  return LV2_WORKER_SUCCESS;
}


static LV2_Handle
instantiate(const LV2_Descriptor*     descriptor,
            double                    rate,
            const char*               bundle_path,
            const LV2_Feature* const* features)
{
  GxPluginStereo *self = new GxPluginStereo();

  if (!self)
    {
      return NULL;
    }

  const LV2_Options_Option* options  = NULL;
  uint32_t bufsize = 0;
  fprintf(stderr," %s\n",descriptor->URI);

  for (int32_t i = 0; features[i]; ++i)
    {
      if (!strcmp(features[i]->URI, LV2_URID__map))
        {
          self->map = (LV2_URID_Map*)features[i]->data;
        }
      else if (!strcmp(features[i]->URI, LV2_WORKER__schedule))
        {
          self->schedule = (LV2_Worker_Schedule*)features[i]->data;
        }
      else if (!strcmp(features[i]->URI, LV2_OPTIONS__options))
        {
          options = (const LV2_Options_Option*)features[i]->data;
        }
    }
  if (!self->schedule)
    {
      fprintf(stderr, "Missing feature work:schedule.\n");
      delete self;
      return NULL;
    }
  if (!self->map)
    {
      fprintf(stderr, "Missing feature uri:map.\n");
    }
  else if (!options)
    {
      fprintf(stderr, "Missing feature options.\n");
    }
  else
    {
// IS this where I set up th LV2 Atom for vumeter maxlevels? 
     LV2_URID bufsz_max = self->map->map(self->map->handle, LV2_BUF_SIZE__maxBlockLength);
      LV2_URID atom_Int = self->map->map(self->map->handle, LV2_ATOM__Int);

      for (const LV2_Options_Option* o = options; o->key; ++o)
        {
          if (o->context == LV2_OPTIONS_INSTANCE &&
              o->key == bufsz_max &&
              o->type == atom_Int)
            {
              bufsize = *(const int32_t*)o->value;
            }
        }

      if (bufsize == 0)
        {
          fprintf(stderr, "No maximum buffer size given.\n");
        }
      printf("using block size: %d\n", bufsize);
    }
  self->init_dsp_stereo((uint32_t)rate, bufsize);

  return (LV2_Handle)self;
}

static void
connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
  GxPluginStereo* self = (GxPluginStereo*)instance;
  self->connect_all_stereo_ports(port, data);

}

static void
activate(LV2_Handle instance)
{

}

static void
run(LV2_Handle instance, uint32_t n_samples)
{
  GxPluginStereo* self = (GxPluginStereo*)instance;
  self->run_dsp_stereo(n_samples);
}

static void
deactivate(LV2_Handle instance)
{

}

static void
cleanup(LV2_Handle instance)
{
  GxPluginStereo* self = (GxPluginStereo*)instance;
  delete self;
}

//////////////////////////////////////////////////////////////////

const void*
extension_data(const char* uri)
{
  static const LV2_Worker_Interface worker = { work, work_response, NULL };
  if (!strcmp(uri, LV2_WORKER__interface))
    {
      return &worker;
    }
  return NULL;
}

static const LV2_Descriptor descriptor1 =
{
  GXPLUGIN_URI "#preampstereo",
  instantiate,
  connect_port,
  activate,
  run,
  deactivate,
  cleanup,
  extension_data
};

extern "C"
LV2_SYMBOL_EXPORT
const LV2_Descriptor*
lv2_descriptor(uint32_t index)
{
  switch (index)
    {
    case 0:
      return &descriptor1;
    default:
      return NULL;
    }
}
