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


#include "widget.h"

#include <iostream>


/*    @get controller by port
 *  this function is used by make_selector() make_controller_box()
 *  set_value() and on_value_changed()
 *  so controller widgets needs only here asined to a port, 
 *  and all functions which need acess to the controller widget pointer 
 *  can receive them by port number
 */

Gtk::Widget* Widget::get_controller_by_port(uint32_t port_index)
{
  switch ((PortIndex)port_index )
  {
    case WAH:
      return &m_bigknob[0];
    case FREQ:
      return &m_bigknob[1];
    case MODE:
      return &m_selector[0];
    case MODEL:
      return &m_selector[1];
    case WET_DRY:
      return &m_bigknob[2];

    default:
      return NULL;
  } 
}

Widget::Widget(Glib::ustring plugname):
plug_name(plugname),
logo(plugname)
{
  Glib::ustring enumMODEL[] = {"Colorsound Wah","Dallas Wah","Foxx Wah","Jen Wah","Maestro Wah","Selmer Wah","Vox Wah V847"};
  static const size_t enumMODEL_size = sizeof(enumMODEL) / sizeof(enumMODEL[0]);
  make_selector_box(&m_vboxs[0],"MODEL", enumMODEL, enumMODEL_size, 0,1.0, MODEL);

  Glib::ustring enumMODE[] = {"manual","auto","alien"};
  static const size_t enumMODE_size = sizeof(enumMODE) / sizeof(enumMODE[0]);
  make_selector_box(&m_vboxs[1],"MODE", enumMODE, enumMODE_size, 0,1.0, MODE);

  // create controllers for port name
  make_controller_box(&m_vboxc[0], "WAH", 0.0, 1.0, 0.01, WAH);
  make_controller_box(&m_vboxc[1], "ALIEN FREQ", 24.0, 3.6e+02, 1.0, FREQ);
  make_controller_box(&m_vboxc[2], "WET_DRY", 0.0, 1e+02, 1.0, WET_DRY);

  // set propertys for the main paintbox holding the skin
  m_paintbox.set_border_width(10);
  m_paintbox.set_spacing(6);
  m_paintbox.set_homogeneous(false);
  m_paintbox.set_name(plug_name);
  m_paintbox.property_paint_func() = "rack_unit_expose";
  add(m_paintbox);
  // box for the controllers
  m_hbox_.set_spacing(25);
  m_hbox_.set_border_width(24);
  m_hbox_.set_homogeneous(false);
  // set a vertical box in the paintbox
  m_vbox.set_border_width(14);
  m_vbox1.set_border_width(14);
  m_paintbox.pack_start(m_vbox_);

  // modify logo layout
  Pango::FontDescription font_desc = logo.get_style()->get_font();
  font_desc.set_size(int(14*Pango::SCALE));
  font_desc.set_weight(Pango::WEIGHT_BOLD);
  logo.modify_font(font_desc);

  // and controller box on top
  //m_hbox1_.set_border_width(24);
  m_hbox1_.set_spacing(64);
  logo.set_name("amplabel");
  m_vbox_.pack_start(m_hbox1_, Gtk::PACK_SHRINK);
  m_hbox1_.pack_start(m_vbox1_, Gtk::PACK_EXPAND_PADDING);
  m_hbox1_.pack_end(m_vbox2_, Gtk::PACK_SHRINK);
  m_hbox1_.pack_end(logo, Gtk::PACK_SHRINK);
  m_vbox_.pack_start(m_hbox_, Gtk::PACK_SHRINK);
  m_vbox_.set_homogeneous(false);
   // put boxed controllers into controller box
  m_hbox_.pack_start(m_vbox1, Gtk::PACK_EXPAND_PADDING);
  for (int i = 0; i<2;i++) {
    m_vboxs_.pack_start(m_vboxs[i]);
  }
  m_vboxs_.set_spacing(5);
  m_hbox_.pack_start(m_vboxs_, Gtk::PACK_EXPAND_PADDING);
  for (int i = 0; i<3;i++) {
    m_hbox_.pack_start(m_vboxc[i]);
  }
  m_hbox_.pack_start(m_vbox, Gtk::PACK_EXPAND_PADDING);

  // connect expose handler as resize handler
  m_paintbox.signal_expose_event().connect(
    sigc::mem_fun(this, &Widget::_expose_event), true);

  set_app_paintable(true);
  show_all();
}

Widget::~Widget()
{

}

// set borderwith for paintbox when widget resize
// to hold controllers in place
bool Widget::_expose_event(GdkEventExpose *event)
{
  int x, y, width, height, depth;
  m_paintbox.get_window()->get_geometry(x, y, width, height, depth);
  //double_t height = m_paintbox.get_window()->get_height();
  m_paintbox.set_border_width(height/10);
  return false;
}

// create selectors from gxwmm
void Widget::make_selector_box(Gtk::Box *box,
                               Glib::ustring labela,
                               Glib::ustring tables[],
                               size_t _size,
                               float min, float digits,
                               PortIndex port_name)
{
  Gxw::Selector *regler = static_cast<Gxw::Selector*>
                                    (get_controller_by_port(port_name));
  if (regler)
  {
    float max = static_cast<float>(_size+1);

    Gtk::TreeModelColumn<Glib::ustring> label;
    Gtk::TreeModelColumnRecord rec;
    rec.add(label);
    Glib::RefPtr<Gtk::ListStore> ls = Gtk::ListStore::create(rec);

    for (uint32_t i = 0 ; i< _size; ++i) {
      ls->append()->set_value(0, tables[i]);
    }
    regler->set_model(ls);
    regler->set_has_tooltip();
    regler->set_tooltip_text(labela);
    regler->cp_configure("SELECTOR", labela, min, max, digits);
    regler->set_show_value(false);
    regler->set_name(plug_name);
    regler->signal_value_changed().connect(sigc::bind(sigc::mem_fun(
           *this, &Widget::on_value_changed), port_name));
    box->pack_start(*regler,Gtk::PACK_SHRINK);
  }
}

// create stackboxes with controllers for port name
void Widget::make_controller_box(Gtk::Box *box,
                                 Glib::ustring label,
                                 float min, float max,
                                 float digits,
                                 PortIndex port_name)
{
  Gxw::Regler *regler = static_cast<Gxw::Regler*>(
                                    get_controller_by_port(port_name));
  if (regler)
  {
    Gtk::Label* pr = new Gtk::Label(label, 0);
    pr->set_name("amplabel");
    // use label images instead simple string labes
    //Glib::ustring  label_image = GX_LV2_STYLE_DIR;
    //label_image += "/";
    //label_image += label;
    //label_image += ".png";
    //Gtk::Image *pr = new Gtk::Image(label_image);

    Gtk::VBox* b1 = new Gtk::VBox();
    box->pack_start( *Gtk::manage(b1), Gtk::PACK_EXPAND_PADDING);
    box->pack_start( *Gtk::manage(pr),Gtk::PACK_SHRINK);
    regler->cp_configure("KNOB", label, min, max, digits);
    regler->set_show_value(true);
    regler->set_name(plug_name);
    box->pack_start(*regler,Gtk::PACK_SHRINK);
    Gtk::VBox* b2 = new Gtk::VBox();
    box->pack_start( *Gtk::manage(b2), Gtk::PACK_EXPAND_PADDING);
    regler->signal_value_changed().connect(sigc::bind(sigc::mem_fun(
           *this, &Widget::on_value_changed), port_name));
  }
}

// create stackboxes with switch controller for port name
void Widget::make_switch_box(Gtk::Box *box,
                             Glib::ustring label,
                             PortIndex port_name)
{
  Gxw::Switch *regler = static_cast<Gxw::Switch*>(
                                    get_controller_by_port(port_name));
  if (regler)
  {
    Gtk::Label* pr = new Gtk::Label(label, 0);
    pr->set_name("amplabel");
    // use label images instead simple string labes
    /*Glib::ustring  label_image = GX_LV2_STYLE_DIR;
    label_image += "/"+plug_name+"-";
    label_image += label;
    label_image += "-label.png";
     Gtk::Image *pr = new Gtk::Image(label_image);*/
 
    regler->cp_configure("switch", label, 0, 1, 1);
    regler->set_name(plug_name);
    regler->set_base_name( "button" );
    Gtk::VBox* b1 = new Gtk::VBox();
    box->pack_start( *Gtk::manage(b1), Gtk::PACK_EXPAND_PADDING);
    box->pack_start( *Gtk::manage(pr),Gtk::PACK_SHRINK); 
    box->pack_start(*regler,Gtk::PACK_SHRINK);
    Gtk::VBox* b2 = new Gtk::VBox();
    box->pack_start( *Gtk::manage(b2), Gtk::PACK_EXPAND_PADDING);
    regler->signal_toggled().connect(sigc::bind(sigc::mem_fun(
        *this, &Widget::on_value_changed), port_name));
  }
}

// receive controller value changes from host and set them to controller
void Widget::set_value(uint32_t port_index,
                       uint32_t format,
                       const void * buffer)
{
  if ( format == 0 )
  {
    Gxw::Regler *regler = static_cast<Gxw::Regler*>(
                                    get_controller_by_port(port_index));
    if (regler)
    {
      float value = *static_cast<const float*>(buffer);
      regler->cp_set_value(value);
    }
  }
}

// write (UI) controller value changes to the host->engine
void Widget::on_value_changed(uint32_t port_index)
{
  Gxw::Regler *regler = static_cast<Gxw::Regler*>(
                                    get_controller_by_port(port_index));
  if (regler)
  {
    float value = regler->cp_get_value();
    write_function(controller, port_index, sizeof(float), 0,
                                    static_cast<const void*>(&value));
  }
}

