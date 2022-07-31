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

#include "GxPlayHead.h"

#define P_(s) (s)   // FIXME -> gettext

static gboolean gx_play_head_expose (GtkWidget *widget, GdkEventExpose *event);
static void gx_play_head_size_request (GtkWidget *widget, GtkRequisition *requisition);
static void gx_play_head_render_pixbuf (GtkWidget *widget);

G_DEFINE_TYPE(GxPlayHead, gx_play_head, GX_TYPE_REGLER);

#define get_stock_id(widget) (GX_PLAYHEAD_CLASS(GTK_OBJECT_GET_CLASS(widget))->stock_id)

static void gx_play_head_class_init(GxPlayHeadClass *klass)
{
	GtkWidgetClass *widget_class = (GtkWidgetClass*) klass;

	widget_class->expose_event = gx_play_head_expose;
	widget_class->size_request = gx_play_head_size_request;
	widget_class->button_press_event   = NULL;
    widget_class->button_release_event = NULL;
	widget_class->motion_notify_event  = NULL;
	widget_class->enter_notify_event   = NULL;
	widget_class->leave_notify_event   = NULL;
	klass->stock_id = "playhead";
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("phead-width",P_("size of phead"),
		                   P_("Width of movable part of playhead"),
		                 0, 100, 20, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
}

static void gx_play_head_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
	g_assert(GX_IS_PLAYHEAD(widget));
    GxPlayHead *phead   = GX_PLAYHEAD(widget);
	requisition->width  = phead->width;
	requisition->height = phead->height;
	_gx_regler_calc_size_request(GX_REGLER(widget), requisition);
}

static gboolean gx_play_head_expose(GtkWidget *widget, GdkEventExpose *event)
{
	g_assert(GX_IS_PLAYHEAD(widget));
    GxPlayHead *phead = GX_PLAYHEAD(widget);
    int x = widget->allocation.x;
    int y = widget->allocation.y;
	int rect_width  = widget->allocation.width;
    phead->image_rect.x = phead->image_rect.y = 0;
	//GdkRectangle  value_rect;
    gdouble slstate = _gx_regler_get_step_pos(GX_REGLER(widget), rect_width - (phead->height*2));
	//_gx_regler_get_positions(GX_REGLER(widget), &phead->image_rect, &value_rect);
	cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(widget));
    // background
    phead->scaled_image = gdk_pixbuf_scale_simple(
			phead->image, rect_width+(phead->height*60), phead->height, GDK_INTERP_NEAREST);
	gdk_cairo_set_source_pixbuf (cr, phead->scaled_image, x, y);
	cairo_rectangle(cr, x, y, rect_width, phead->height);
	cairo_fill(cr);
    //phead
    //int sx = gtk_widget_get_state(widget) ? phead->phead_width : 0;
    gdk_cairo_set_source_pixbuf (cr, phead->image, x - ((phead->width+(phead->height)) - slstate), y);
    cairo_rectangle(cr, x + slstate, y, (phead->height*3), phead->height);
    cairo_fill(cr);
	//_gx_regler_display_value(GX_REGLER(widget), &value_rect);
	cairo_destroy (cr);
	g_object_unref(phead->scaled_image);
	return FALSE;
}

static void gx_play_head_init(GxPlayHead *playhead)
{
    GtkWidget *widget = GTK_WIDGET(playhead);
    gx_play_head_render_pixbuf(widget);
    g_signal_connect ( GTK_OBJECT (widget), "style-set",
                     G_CALLBACK (gx_play_head_render_pixbuf), NULL);
}

static void gx_play_head_render_pixbuf (GtkWidget *widget)
{
    GxPlayHead *playhead = GX_PLAYHEAD(widget);
    gtk_widget_style_get(widget, "phead-width", &playhead->phead_width, NULL);
    playhead->image        = gtk_widget_render_icon(widget, get_stock_id(widget), GtkIconSize(-1), NULL);
    playhead->height       = gdk_pixbuf_get_height(playhead->image);
    playhead->width        = gdk_pixbuf_get_width(playhead->image) - playhead->height*2;
    GdkRectangle rect;
    rect.width  = playhead->width;
    rect.height = playhead->height;
    playhead->image_rect = rect;
}
