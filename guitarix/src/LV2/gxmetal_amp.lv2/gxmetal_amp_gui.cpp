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


#include <string>
#include <iostream>

#include <gtkmm.h>
#include "gxmetal_amp.h"
#include "widget.h"


#include <lv2.h>
#include <lv2/lv2plug.in/ns/extensions/ui/ui.h>

using namespace std;

class Gxmetal_ampGUI
{
private:

  Glib::ustring plugskin;
  Glib::ustring addKnob;
  Glib::ustring plug_name;
  void set_knob(Glib::ustring knob);
  void set_skin();
  void set_plug_name(const char * plugin_uri);
  GtkWidget* make_gui();
  Widget* widget;

public:

  static LV2UI_Handle instantiate(const struct _LV2UI_Descriptor * descriptor,
                                  const char * plugin_uri,
                                  const char * bundle_path,
                                  LV2UI_Write_Function write_function,
                                  LV2UI_Controller controller,
                                  LV2UI_Widget * widget,
                                  const LV2_Feature * const * features);

  static void port_event(LV2UI_Handle ui, uint32_t port_index,
                        uint32_t buffer_size, uint32_t format,
                        const void *                   buffer);

  static LV2UI_Descriptor descriptors[];
  static void cleanup(LV2UI_Handle ui);

  Gxmetal_ampGUI () {};
  ~Gxmetal_ampGUI () {};
} ;

void Gxmetal_ampGUI::set_knob(Glib::ustring knob)
{
  addKnob =   " style 'gx_";
  addKnob +=  plug_name;
  addKnob +=   "_dark_skin_icons'\n"
               " { \n"
               "   stock['bigknob'] = {{'";
  addKnob +=  knob;
  addKnob +=  ".png'}}\n";
  addKnob +=  "   stock['smallknobr'] = {{'";
  addKnob +=  knob;
  addKnob +=  "-middle.png'}}\n";
  addKnob +=  "   stock['button_on'] = {{'"
              "chump-switch_on.png'}}\n"
              "   stock['button_off'] = {{'"
              "chump-switch_off.png'}}\n"
              " }\n"
              "widget '*.";
  addKnob +=  plug_name;
  addKnob +=  "' style 'gx_";
  addKnob +=  plug_name;
  addKnob +=  "_dark_skin_icons' \n"
              "class '*GxToggleImage' style'gx_"; 
  addKnob +=  plug_name;
  addKnob +=  "_dark_skin_icons' \n";
}

void Gxmetal_ampGUI::set_skin()
{
  Glib::ustring toparse = "pixmap_path  ";
  toparse +=     " '";
  toparse +=        GX_LV2_STYLE_DIR;
  toparse +=     "/'\n";
  toparse +=     "style \"gx_";
  toparse +=     plug_name;
  toparse +=     "_dark-paintbox\"\n"
                 " { \n"
                 "GxPaintBox::skin-gradient = {\n"
                 "{ 65536, 0, 0, 13107, 52428 }, \n"
                 "{ 52428, 0, 0, 0, 52428 },\n"
                 "{ 13107, 0, 0, 13107, 13107 }}\n"
                 "    GxPaintBox::icon-set =4\n"
                 "    stock['gxhead'] = {{'";
  toparse +=     plugskin;
  toparse +=     "'}}\n"
                 " }\n"
                 "\n"
                 "style 'gx_headmetal_amp_box' \n"
                 " { \n"
                 "    fg[NORMAL] = '#cbc8c8' \n"
                 "font_name = 'sans bold 9.5' \n"
                 " }\n";
  toparse +=     addKnob;

  toparse +=     " widget '*.amplabel' style:highest 'gx_headmetal_amp_box'\n"
                 "widget '*.";
  toparse +=     plug_name;
  toparse +=     "' style 'gx_";
  toparse +=     plug_name;
  toparse +=     "_dark-paintbox' ";
  toparse +=  "style 'gx_switch'\n"
              "{\n"
              "xthickness = 0\n"
              "ythickness = 0\n"
              "GtkButton::inner-border = {0, 0, 0, 0}\n"
              "GtkButton::default-border = {0, 0, 0, 0}\n"
              "GtkButton::focus-line-width = 0\n"
              "GtkButton::focus-padding = 0\n"
              "GtkButton::interior-focus = 0\n"
              "GtkButton::child-displacement-x = 0\n"
              "GtkButton::child-displacement-y = 0\n"
              " }\n"
              "widget '*.";
  toparse +=  plug_name;
  toparse +=  "' style:highest 'gx_switch'";

  gtk_rc_parse_string (toparse.c_str());
}

void Gxmetal_ampGUI::set_plug_name(const char * plugin_uri)
{
  addKnob = "";

  if (strcmp("http://guitarix.sourceforge.net/plugins/gxmetal_amp#metal_amp", plugin_uri) == 0)
    {
      plugskin = "metalamp.png";
      plug_name = "gxmetal_amp";
      set_knob("sn-knob");
    }
  else
    {
      plugskin = "preampmono.png";
      plug_name = "gxmetal_amp";
    }
}

GtkWidget* Gxmetal_ampGUI::make_gui()
{
  // init the gxwmm library
  Gxw::init();
  set_skin();
  GtkWidget* container = gtk_vbox_new(FALSE, 0);
  widget = new Widget(plug_name);
  GtkWidget* cWidget = GTK_WIDGET(widget->gobj());
  gtk_container_add(GTK_CONTAINER(container), cWidget );

  return container;
}


LV2UI_Handle Gxmetal_ampGUI::instantiate(const struct _LV2UI_Descriptor * descriptor,
                                const char * plugin_uri,
                                const char * bundle_path,
                                LV2UI_Write_Function write_function,
                                LV2UI_Controller controller,
                                LV2UI_Widget * widget,
                                const LV2_Feature * const * features)
{
  Gxmetal_ampGUI* self = new Gxmetal_ampGUI();
  if (self == NULL) return NULL;
  self->set_plug_name(plugin_uri);
  *widget = (LV2UI_Widget)self->make_gui();
  self->widget->controller = controller;
  self->widget->write_function = write_function;
  return (LV2UI_Handle)self;
}

void Gxmetal_ampGUI::cleanup(LV2UI_Handle ui)
{
  Gxmetal_ampGUI *pluginGui = static_cast<Gxmetal_ampGUI*>(ui);
  delete pluginGui->widget;
  delete pluginGui;
}

void Gxmetal_ampGUI::port_event(LV2UI_Handle ui,
                       uint32_t port_index,
                       uint32_t buffer_size,
                       uint32_t format,
                       const void * buffer)
{
  Gxmetal_ampGUI *self = static_cast<Gxmetal_ampGUI*>(ui);
  self->widget->set_value_static( port_index, buffer_size, format, buffer, self->widget);
  return;
}

LV2UI_Descriptor Gxmetal_ampGUI::descriptors[] =
{
  {
    GXPLUGIN_UI_URI,
    Gxmetal_ampGUI::instantiate,
    Gxmetal_ampGUI::cleanup,
    Gxmetal_ampGUI::port_event,
    NULL
  }
};

const LV2UI_Descriptor * lv2ui_descriptor(uint32_t index)
{
  //printf("lv2ui_descriptor(%u) called\n", (uint32_t)index);
  if (index >= sizeof(Gxmetal_ampGUI::descriptors) /
               sizeof(Gxmetal_ampGUI::descriptors[0]))
    {
      return NULL;
    }
  return Gxmetal_ampGUI::descriptors + index;
}

