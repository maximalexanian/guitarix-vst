// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_CONTROLPARAMETER_H
#define _GXWMM_CONTROLPARAMETER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
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
 */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GxControlParameterIface GxControlParameterIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GxControlParameter GxControlParameter;
typedef struct _GxControlParameterClass GxControlParameterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gxw
{ class ControlParameter_Class; } // namespace Gxw
namespace Gxw
{


class ControlParameter: public Glib::Interface
{
	
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef ControlParameter CppObjectType;
  typedef ControlParameter_Class CppClassType;
  typedef GxControlParameter BaseObjectType;
  typedef GxControlParameterIface BaseClassType;

private:
  friend class ControlParameter_Class;
  static CppClassType controlparameter_class_;

  // noncopyable
  ControlParameter(const ControlParameter&);
  ControlParameter& operator=(const ControlParameter&);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ControlParameter();
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit ControlParameter(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit ControlParameter(GxControlParameter* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~ControlParameter();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GxControlParameter*       gobj()       { return reinterpret_cast<GxControlParameter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GxControlParameter* gobj() const { return reinterpret_cast<GxControlParameter*>(gobject_); }

private:

	public:
	
  void cp_configure(Glib::ustring group, Glib::ustring name, double lower, double upper, double step);
	
  void cp_set_value(double value);
	
  double cp_get_value();
	
  int cp_get_int_value();
	
  Glib::ustring cp_get_var();
	
  void cp_set_var(Glib::ustring p1);
	#ifdef GLIBMM_PROPERTIES_ENABLED
/** The id of the linked variable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::ustring > property_var_id() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The id of the linked variable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_var_id() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gxw


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gxw::ControlParameter
   */
  Glib::RefPtr<Gxw::ControlParameter> wrap(GxControlParameter* object, bool take_copy = false);

} // namespace Glib


#endif /* _GXWMM_CONTROLPARAMETER_H */
