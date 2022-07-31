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

#include "GxVSlider.h"

#define P_(s) (s)   // FIXME -> gettext

static gboolean vslider_expose (GtkWidget *widget, GdkEventExpose *event);
static void gx_vslider_size_request (GtkWidget *widget, GtkRequisition *requisition);
static gboolean gx_vslider_button_release (GtkWidget *widget, GdkEventButton *event);
static gboolean gx_vslider_button_press (GtkWidget *widget, GdkEventButton *event);
static gboolean gx_vslider_pointer_motion (GtkWidget *widget, GdkEventMotion *event);
static gboolean gx_vslider_enter_in (GtkWidget *widget, GdkEventCrossing *event);
static gboolean gx_vslider_leave_out (GtkWidget *widget, GdkEventCrossing *event);
static void gx_vslider_set_pointer (GtkWidget *widget, GdkEventMotion *event);
static void gx_vslider_render_pixbuf (GtkWidget *widget);

G_DEFINE_TYPE(GxVSlider, gx_vslider, GX_TYPE_REGLER);

#define get_stock_id(widget) (GX_VSLIDER_CLASS(GTK_OBJECT_GET_CLASS(widget))->stock_id)

static void gx_vslider_class_init(GxVSliderClass *klass)
{
	GtkWidgetClass *widget_class = (GtkWidgetClass*)klass;

	widget_class->expose_event         = vslider_expose;
	widget_class->size_request         = gx_vslider_size_request;
	widget_class->button_press_event   = gx_vslider_button_press;
    widget_class->button_release_event = gx_vslider_button_release;
	widget_class->motion_notify_event  = gx_vslider_pointer_motion;
	widget_class->enter_notify_event   = gx_vslider_enter_in;
	widget_class->leave_notify_event   = gx_vslider_leave_out;
	klass->stock_id = "vslider";
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("slider-width",P_("size of slider"),
				 P_("Height of movable part of vslider"),
		                 0, 100, 20, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
}

static void gx_vslider_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
	g_assert(GX_IS_VSLIDER(widget));
    GxVSlider *slider   = GX_VSLIDER(widget);
    requisition->width  = slider->width;
    requisition->height = slider->height;
	_gx_regler_calc_size_request(GX_REGLER(widget), requisition);
}

static gboolean vslider_expose(GtkWidget *widget, GdkEventExpose *event)
{
    g_assert(GX_IS_VSLIDER(widget));
    GxVSlider *slider = GX_VSLIDER(widget);
    int x = widget->allocation.x;
    int y = widget->allocation.y;
    slider->image_rect.x = slider->image_rect.y = 0;
	GdkRectangle  value_rect;
    gdouble slstate = _gx_regler_get_step_pos(GX_REGLER(widget), slider->height - slider->slider_height);
	_gx_regler_get_positions(GX_REGLER(widget), &slider->image_rect, &value_rect);
    if (gtk_widget_has_focus(widget)) {
        gtk_paint_focus(widget->style, widget->window, GTK_STATE_NORMAL, NULL, widget, NULL,
                        x, y, slider->width, slider->height);
    }
	cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(widget));
    // background
    gdk_cairo_set_source_pixbuf (cr, slider->image, x, y);
    cairo_rectangle(cr, x, y, slider->width, slider->height);
	cairo_fill(cr);
    //slider
    int sy = gtk_widget_get_state(widget) ? slider->slider_height : 0;
    gdk_cairo_set_source_pixbuf (cr, slider->image, x, y - slider->height + ((slider->height - slider->slider_height) - slstate) - sy);
    cairo_rectangle(cr, x, y + ((slider->height - slider->slider_height) - slstate), slider->width, slider->slider_height);
    cairo_fill(cr);
	_gx_regler_display_value(GX_REGLER(widget), &value_rect);
	cairo_destroy(cr);
    return FALSE;
}

static gboolean gx_vslider_enter_in (GtkWidget *widget, GdkEventCrossing *event)
{
    if (gtk_widget_get_state(widget) == GTK_STATE_NORMAL)
        gtk_widget_set_state(widget, GTK_STATE_PRELIGHT);
    GX_VSLIDER(widget)->hover = 1;
    gx_vslider_set_pointer(widget, NULL);
	return TRUE;
}

static gboolean gx_vslider_leave_out (GtkWidget *widget, GdkEventCrossing *event)
{
    if (gtk_widget_get_state(widget) == GTK_STATE_PRELIGHT)
        gtk_widget_set_state(widget, GTK_STATE_NORMAL);
    GX_VSLIDER(widget)->hover = 0;
    gx_vslider_set_pointer(widget, NULL);
	return TRUE;
}

static inline void get_width_height(GtkWidget *widget, GdkRectangle *r)
{
	GdkPixbuf *pb = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
	r->width = gdk_pixbuf_get_width(pb);
	r->height = gdk_pixbuf_get_height(pb);
	g_object_unref(pb);
}

static gboolean slider_set_from_pointer(GtkWidget *widget, int state, gdouble x, gdouble y, gboolean drag, gint button, GdkEventButton *event)
{
    GxVSlider *slider = GX_VSLIDER(widget);
    GdkRectangle value_rect;
    slider->image_rect.x = slider->image_rect.y = 0;
    _gx_regler_get_positions(GX_REGLER(widget), &slider->image_rect, &value_rect);
	x += widget->allocation.x;
	y += widget->allocation.y;
	_gx_regler_get_positions(GX_REGLER(widget), &slider->image_rect, &value_rect);
	if (!drag) {
		if (_gx_regler_check_display_popup(GX_REGLER(widget), &slider->image_rect, &value_rect, event)) {
			return FALSE;
		}
	}
	gint off =  slider->image_rect.y + slider->slider_height/2;
	GtkAdjustment *adj = gtk_range_get_adjustment(GTK_RANGE(widget));
	static double last_y = 2e20;
	if (!drag) {
		last_y = y;
		if (event && event->type == GDK_2BUTTON_PRESS) {
			double value = adj->upper - ((y - off) / slider->height)* (adj->upper - adj->lower);
		    gtk_range_set_value(GTK_RANGE(widget), value);
		}
	} else {
		double value = ((last_y - y) / slider->height) * (adj->upper - adj->lower);
		if (state & (GDK_CONTROL_MASK|GDK_SHIFT_MASK)) {
			value *= 0.1;
		}
	    last_y = y;
	    gtk_range_set_value(GTK_RANGE(widget), adj->value + value);
	}
	return TRUE;
}

static gboolean gx_vslider_button_press (GtkWidget *widget, GdkEventButton *event)
{
	g_assert(GX_IS_VSLIDER(widget));
	if (event->button != 1 && event->button != 3) {
		return FALSE;
	}
	gtk_widget_grab_focus(widget);
	if (slider_set_from_pointer(widget, event->state, event->x, event->y, FALSE, event->button, event)) {
		gtk_grab_add(widget);
        gtk_widget_set_state(widget, GTK_STATE_ACTIVE);
        gx_vslider_set_pointer(widget, NULL);
	}
	return FALSE;
}

static gboolean gx_vslider_button_release (GtkWidget *widget, GdkEventButton *event)
{
	g_assert(GX_IS_VSLIDER(widget));
	if (event->button != 1 && event->button != 3) {
		return FALSE;
	}
    gtk_grab_remove(widget);
    gtk_widget_set_state(widget, GX_VSLIDER(widget)->hover ? GTK_STATE_PRELIGHT : GTK_STATE_NORMAL);
        return TRUE;
}

static gboolean gx_vslider_pointer_motion(GtkWidget *widget, GdkEventMotion *event)
{
    g_assert(GX_IS_VSLIDER(widget));
    gx_vslider_set_pointer(widget, event);
        if (!gtk_widget_has_grab(widget))
               return FALSE;
	gdk_event_request_motions (event);
	slider_set_from_pointer(widget, event->state, event->x, event->y, TRUE, 0, NULL);
	return FALSE;
}

static void gx_vslider_init(GxVSlider *vslider)
{
    GtkWidget *widget = GTK_WIDGET(vslider);
    vslider->hover        = 0;
    gx_vslider_render_pixbuf(widget);
    g_signal_connect ( GTK_OBJECT (widget), "style-set",
                     G_CALLBACK (gx_vslider_render_pixbuf), NULL);
}
static void gx_vslider_set_pointer (GtkWidget *widget, GdkEventMotion *event)
{
    GxVSlider *slider = GX_VSLIDER(widget);
    GdkCursor *cur = gdk_cursor_new(GDK_HAND2);
    gdouble slstate = _gx_regler_get_step_pos(GX_REGLER(widget), slider->height - slider->slider_height);
    slstate = ((slider->height - slider->slider_height) - slstate);
    if (gtk_widget_get_state(widget) == GTK_STATE_ACTIVE
    or (event and event->y > slstate and event->y < slstate + slider->slider_height))
        gdk_window_set_cursor(GDK_WINDOW(gtk_widget_get_window(widget)), cur);
    else
        gdk_window_set_cursor(GDK_WINDOW(gtk_widget_get_window(widget)), NULL);
}

static void gx_vslider_render_pixbuf (GtkWidget *widget)
{
    GxVSlider *vslider = GX_VSLIDER(widget);
    gtk_widget_style_get(widget, "slider-width", &vslider->slider_height, NULL);
    vslider->image        = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
    vslider->width        = gdk_pixbuf_get_width(vslider->image);
    vslider->height       = gdk_pixbuf_get_height(vslider->image) - vslider->slider_height * 2;
    GdkRectangle rect;
    rect.width  = vslider->width;
    rect.height = vslider->height;
    vslider->image_rect = rect;
}
