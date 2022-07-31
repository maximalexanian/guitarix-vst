// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GXWMM_LEVELSLIDER_H
#define _GXWMM_LEVELSLIDER_H


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

#include <gxwmm/vslider.h>
#include <gtkmm/adjustment.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GxLevelSlider GxLevelSlider;
typedef struct _GxLevelSliderClass GxLevelSliderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gxw
{ class LevelSlider_Class; } // namespace Gxw
namespace Gxw {


class LevelSlider: public Gxw::VSlider {
	public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef LevelSlider CppObjectType;
  typedef LevelSlider_Class CppClassType;
  typedef GxLevelSlider BaseObjectType;
  typedef GxLevelSliderClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~LevelSlider();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class LevelSlider_Class;
  static CppClassType levelslider_class_;

  // noncopyable
  LevelSlider(const LevelSlider&);
  LevelSlider& operator=(const LevelSlider&);

protected:
  explicit LevelSlider(const Glib::ConstructParams& construct_params);
  explicit LevelSlider(GxLevelSlider* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GxLevelSlider*       gobj()       { return reinterpret_cast<GxLevelSlider*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GxLevelSlider* gobj() const { return reinterpret_cast<GxLevelSlider*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

	public:
	explicit LevelSlider(Gtk::Adjustment& adjustment);
	LevelSlider();


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
   * @relates Gxw::LevelSlider
   */
  Gxw::LevelSlider* wrap(GxLevelSlider* object, bool take_copy = false);
} //namespace Glib


#endif /* _GXWMM_LEVELSLIDER_H */

