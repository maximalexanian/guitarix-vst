// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_MINISLIDER_H
#define _GXWMM_MINISLIDER_H


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

#include <gxwmm/hslider.h>
#include <gtkmm/adjustment.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GxMiniSlider GxMiniSlider;
typedef struct _GxMiniSliderClass GxMiniSliderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gxw
{ class MiniSlider_Class; } // namespace Gxw
namespace Gxw {


class MiniSlider: public Gxw::HSlider {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MiniSlider CppObjectType;
  typedef MiniSlider_Class CppClassType;
  typedef GxMiniSlider BaseObjectType;
  typedef GxMiniSliderClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~MiniSlider();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class MiniSlider_Class;
  static CppClassType minislider_class_;

  // noncopyable
  MiniSlider(const MiniSlider&);
  MiniSlider& operator=(const MiniSlider&);

protected:
  explicit MiniSlider(const Glib::ConstructParams& construct_params);
  explicit MiniSlider(GxMiniSlider* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GxMiniSlider*       gobj()       { return reinterpret_cast<GxMiniSlider*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GxMiniSlider* gobj() const { return reinterpret_cast<GxMiniSlider*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	MiniSlider();
	explicit MiniSlider(Gtk::Adjustment& adjustment);


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
   * @relates Gxw::MiniSlider
   */
  Gxw::MiniSlider* wrap(GxMiniSlider* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_MINISLIDER_H */
