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

#include "GxPortDisplay.h"

#define P_(s) (s)   // FIXME -> gettext

#define get_stock_id(widget) (GX_PORT_DISPLAY_CLASS(GTK_OBJECT_GET_CLASS(widget))->parent_class.stock_id)

static gboolean gx_port_display_expose (GtkWidget *widget, GdkEventExpose *event);
static void gx_port_display_size_request (GtkWidget *widget, GtkRequisition *requisition);

G_DEFINE_TYPE(GxPortDisplay, gx_port_display, GX_TYPE_VSLIDER);

static void gx_port_display_class_init(GxPortDisplayClass *klass)
{
	GtkWidgetClass *widget_class = (GtkWidgetClass*) klass;

	widget_class->expose_event = gx_port_display_expose;
	widget_class->size_request = gx_port_display_size_request;
	widget_class->button_press_event = NULL;
	widget_class->motion_notify_event = NULL;
	widget_class->enter_notify_event = NULL;
	widget_class->leave_notify_event = NULL;
	klass->parent_class.stock_id = "portdisplay";
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("display-width",P_("size of display"),
				 P_("Height of movable part of display"),
		                 0, 80, 0, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
}

static void gx_port_display_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
	g_assert(GX_IS_PORT_DISPLAY(widget));
	gint display_width;
	gtk_widget_style_get(widget, "display-width", &display_width, NULL);
	GdkPixbuf *pb = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
	requisition->height = 2+gdk_pixbuf_get_height(pb);
	requisition->width = (gdk_pixbuf_get_width(pb) + display_width) / 2;
	_gx_regler_calc_size_request(GX_REGLER(widget), requisition);
	g_object_unref(pb);
}

static void port_display_expose(GdkEventExpose *ev,
	GtkWidget *widget, GdkRectangle *rect, gdouble sliderstate, GdkPixbuf *image)
{
	cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(widget));
    GxPortDisplay *port_display = GX_PORT_DISPLAY(widget);
    GdkRegion *region;
	region = gdk_region_rectangle (&widget->allocation);
	gdk_region_intersect (region, ev->region);
    gdk_cairo_region (cr, region);
    cairo_clip (cr);
	gdk_cairo_set_source_pixbuf(cr, image, rect->x - (rect->width-(gint)sliderstate), rect->y);
	cairo_rectangle(cr, rect->x, rect->y, rect->width, rect->height);
	cairo_fill(cr);
    if (port_display->cutoff_low + port_display->cutoff_high) {
      cairo_set_source_rgba (cr, 0.8, 0.1, 0.1, 0.4);
      cairo_set_line_width(cr, rect->height);
      gint low = rect->width * port_display->cutoff_low * 0.01;
      gint high = (rect->width* port_display->cutoff_high * 0.01)-5;
      gint lw = rect->height/2;
      cairo_move_to(cr,rect->x, rect->y+lw);
      cairo_line_to(cr,rect->x + low, rect->y+lw);
      cairo_stroke (cr);
      cairo_move_to(cr,rect->width - high, rect->y+lw);
      cairo_line_to(cr,rect->width+5, rect->y+lw);
      cairo_stroke (cr);
      cairo_set_source_rgba (cr, 1.0, 0.6, 0.0, 0.4);
      cairo_move_to(cr,rect->x+ low, rect->y+lw);
      cairo_line_to(cr,rect->width - high, rect->y+lw);
      cairo_stroke (cr);
      
    }
	cairo_destroy(cr);
    gdk_region_destroy (region);
}

static gboolean gx_port_display_expose(GtkWidget *widget, GdkEventExpose *event)
{
    if (GDK_IS_WINDOW (widget->window)) {
	  g_assert(GX_IS_PORT_DISPLAY(widget));
	  gint display_width;
	  GdkRectangle image_rect, value_rect;
	  GdkPixbuf *pb = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
	  gtk_widget_style_get(widget, "display-width", &display_width, NULL);
	  image_rect.height = gdk_pixbuf_get_height(pb);
	  image_rect.width = (gdk_pixbuf_get_width(pb) + display_width) / 2;
	  gdouble sliderstate = _gx_regler_get_step_pos(GX_REGLER(widget), image_rect.width-display_width);
	  _gx_regler_get_positions(GX_REGLER(widget), &image_rect, &value_rect);
	  port_display_expose(event, widget, &image_rect, sliderstate, pb);
	  _gx_regler_simple_display_value(GX_REGLER(widget), &value_rect);
	  g_object_unref(pb);
    }
	return FALSE;
}

static inline void get_width_height(GtkWidget *widget, GdkRectangle *r)
{
	GdkPixbuf *pb = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
	r->width = gdk_pixbuf_get_width(pb);
	r->height = gdk_pixbuf_get_height(pb);
	g_object_unref(pb);
}

static void gx_port_display_init(GxPortDisplay *port_display)
{
	gtk_widget_set_name (GTK_WIDGET(port_display),"rack_slider");
    port_display->cutoff_low = 0;
    port_display->cutoff_high = 0;
}

void gx_port_display_set_state(GxPortDisplay *port_display, gint cutoff_low, gint cutoff_high) {
    g_assert(GX_IS_PORT_DISPLAY(port_display));
    port_display->cutoff_low = cutoff_low;
    port_display->cutoff_high = cutoff_high;
}
