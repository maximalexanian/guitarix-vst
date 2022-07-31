// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_RACKTUNER_P_H
#define _GXWMM_RACKTUNER_P_H


#include <gxwmm/private/tuner_p.h>

#include <glibmm/class.h>

namespace Gxw
{

class RackTuner_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RackTuner CppObjectType;
  typedef GxRackTuner BaseObjectType;
  typedef GxRackTunerClass BaseClassType;
  typedef Gxw::Tuner_Class CppClassParent;
  typedef GxTunerClass BaseClassParent;

  friend class RackTuner;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void frequency_poll_callback(GxRackTuner* self);
  static void poll_status_changed_callback(GxRackTuner* self, gboolean p0);

  //Callbacks (virtual functions):
};


} // namespace Gxw


#endif /* _GXWMM_RACKTUNER_P_H */
