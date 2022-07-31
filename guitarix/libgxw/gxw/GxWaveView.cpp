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

// ***** GxWaveView.cpp *****
/******************************************************************************
part of guitarix, show a wave with Gtk
******************************************************************************/

#include "GxWaveView.h"
#include "GxGradient.h"
#include <math.h>

#define P_(s) (s)   // FIXME -> gettext

enum {
	PROP_TEXT_TOP_LEFT = 1,
	PROP_TEXT_TOP_RIGHT,
	PROP_TEXT_BOTTOM_LEFT,
	PROP_TEXT_BOTTOM_RIGHT,
	PROP_TEXT_POS_LEFT,
	PROP_TEXT_POS_RIGHT
};

static void gx_wave_view_destroy(GtkObject*);
static gboolean gx_wave_view_expose(GtkWidget *widget, GdkEventExpose *event);
static void gx_wave_view_size_request(GtkWidget *widget, GtkRequisition *requisition);
static void gx_wave_view_set_property(
	GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec);
static void gx_wave_view_get_property(
	GObject *object, guint prop_id, GValue *value, GParamSpec *pspec);

G_DEFINE_TYPE(GxWaveView, gx_wave_view, GTK_TYPE_DRAWING_AREA);

static const int liveview_x = 300;
static const int liveview_y = 110;
static const int background_width = 282;
static const int background_height = 82;

inline double cairo_clr(guint16 clr)
{
	return clr / 65535.0;
}

// set cairo color related to the used skin
static void set_box_color(GtkWidget *wi, cairo_pattern_t *pat)
{
	GxGradient *grad;
	gtk_widget_style_get(wi, "box-gradient", &grad, NULL);
	if (!grad) {
		GdkColor *p1 = &wi->style->bg[GTK_STATE_NORMAL];
		cairo_pattern_add_color_stop_rgba(
			pat, 0, cairo_clr(p1->red), cairo_clr(p1->green),
			cairo_clr(p1->blue), 0.8);
		GdkColor *p2 = &wi->style->fg[GTK_STATE_NORMAL];
		cairo_pattern_add_color_stop_rgba(
			pat, 1, (cairo_clr(p1->red)+cairo_clr(p2->red))/2,
			(cairo_clr(p1->green)+cairo_clr(p2->green))/2,
			(cairo_clr(p1->blue)+cairo_clr(p2->blue))/2, 0.8);
		return;
	}
	GSList *p;
	for (p = grad->colors; p; p = g_slist_next(p)) {
		GxGradientElement *el = (GxGradientElement*)p->data;
		cairo_pattern_add_color_stop_rgba(pat, el->offset, el->red, el->green, el->blue, el->alpha);
	}
	gx_gradient_free(grad);
}

static void wave_view_background(GxWaveView *waveview,GtkWidget *widget ,
                                 int liveviewx, int liveviewy)
{
	
    cairo_t *crp; 
    GdkPixmap*  pix = gdk_pixmap_new(widget->window,background_width,background_height,-1);
	waveview->liveview_image = gdk_pixbuf_new(
		GDK_COLORSPACE_RGB,FALSE,8,background_width,background_height);
	g_assert(waveview->liveview_image != NULL);
	
    crp = gdk_cairo_create (pix);     
	
	cairo_pattern_t*pat =
		cairo_pattern_create_radial (-130.4, -270.4, 1.6, -1.4,  -4.4, 300.0);

	cairo_pattern_add_color_stop_rgba (pat, 0, 0.2, 0.2, 0.3, 1);
	cairo_pattern_add_color_stop_rgba (pat, 1, 0.05, 0.05, 0.05, 1);
	cairo_set_source_rgb(crp, 0.05, 0.05, 0.05);
	cairo_rectangle (crp, 0, 0, 282, 82);
	cairo_set_source (crp, pat);
	cairo_fill (crp);
	cairo_pattern_destroy (pat);

	/*
	cairo_set_line_width (cr, 10.0);
	cairo_set_source_rgba (cr, 0, 0, 0,0.4);
	cairo_rectangle (cr, liveviewx-5, liveviewy-5, 286, 60);
	cairo_stroke (cr);

	cairo_set_line_width (cr, 1.0);
	cairo_set_source_rgba (cr, 0.1, 0.1, 0.1,0.7);
	cairo_rectangle (cr, liveviewx-6, liveviewy-6, 288, 62);
	cairo_stroke (cr);

	cairo_set_line_width (cr, 1.0);
	cairo_set_source_rgba (cr, 0.5, 0.5, 0.5,0.1);
	cairo_rectangle (cr, liveviewx-12, liveviewy-12, 302, 74);
	cairo_rectangle (cr, liveviewx-2, liveviewy-2, 302, 54);
	cairo_stroke (cr);
	*/

	cairo_set_line_width (crp, 1);
	//cairo_set_source_rgba (crp,1.0, 0.85, 0.0, 0.4);
	//cairo_move_to (crp, 0, 40);
	//cairo_line_to (crp, 280, 40);
	//cairo_stroke (crp);
    
	//cairo_set_source_rgba (crp,0.46, 0.6, 0.31, 0.4);
	//cairo_rectangle (crp, 0, 0, 280.0, 80.0);
	//cairo_stroke (crp);

	float gitter = 0.5;
	for (int i=0; i<28; i++)
	{
		gitter += 10;
		cairo_move_to (crp, gitter-5, 0);
		cairo_line_to (crp, gitter-5, 80);
	}

	gitter = 0.5;
	for (int i=0; i<7; i++)
	{
		gitter += 10;
		cairo_move_to (crp, 0, gitter);
		cairo_line_to (crp, 280, gitter);
	}

	cairo_set_source_rgba (crp,1, 1, 1, 0.1);
	cairo_stroke (crp);
	
	
    cairo_destroy (crp); 

	gdk_pixbuf_get_from_drawable(
		waveview->liveview_image,
		GDK_DRAWABLE(pix), gdk_colormap_get_system(),
		0, 0,0,0,background_width,background_height);
	g_object_unref(pix);
}

static void draw_text(GtkWidget *widget, GdkEventExpose *event, gchar *str,
                      int xorg, int yorg, GtkCornerType corner)
{
	if (!str || !*str) {
		return;
	}
	PangoLayout *layout = gtk_widget_create_pango_layout(widget, NULL);
	pango_layout_set_markup(layout, str, -1);
	int width, height;
	pango_layout_get_pixel_size(layout, &width, &height);
	if (corner == GTK_CORNER_BOTTOM_LEFT || corner == GTK_CORNER_BOTTOM_RIGHT) {
		yorg += background_height - height - 3;
	} else {
		yorg += 1;
	}
	gtk_paint_layout(widget->style, widget->window, gtk_widget_get_state(widget),
		                 FALSE, NULL, widget, "label", xorg, yorg, layout);
	g_object_unref(layout);
}

static gboolean gx_wave_view_expose (GtkWidget *widget, GdkEventExpose *event)
{
	g_assert(GX_IS_WAVE_VIEW(widget));
	GxWaveView *waveview = GX_WAVE_VIEW(widget);

	int liveviewx = (int)((widget->allocation.width  - liveview_x) * 0.5) + 10;
	int liveviewy = (int)((widget->allocation.height - liveview_y) * 0.5) + 15;

	cairo_t*cr = gdk_cairo_create(GDK_DRAWABLE(widget->window));
	GdkRegion *region;
	region = gdk_region_rectangle (&widget->allocation);
	gdk_region_intersect (region, event->region);
	gdk_cairo_region (cr, region);
	cairo_clip (cr);
	gx_draw_inset(widget,liveviewx-2, liveviewy-1, 284,82, 0, 4);
    gx_draw_glass(widget,liveviewx, liveviewy-1, 280,82, 0);

	if (!waveview->liveview_image) {
		wave_view_background(waveview, widget, liveviewx, liveviewy);
	} else {
		gdk_cairo_set_source_pixbuf(cr, waveview->liveview_image, liveviewx-1, liveviewy-1);
		cairo_paint (cr);
	}

	cairo_set_source_rgb(cr, 1, 1, 1);
	draw_text(widget, event, waveview->text_top_left, liveviewx + (int)(background_width * waveview->text_pos_left / 100),
	          liveviewy, GTK_CORNER_TOP_LEFT);
	draw_text(widget, event, waveview->text_top_right, liveviewx + (int)(background_width * waveview->text_pos_right / 100),
	          liveviewy, GTK_CORNER_TOP_RIGHT);
	draw_text(widget, event, waveview->text_bottom_left, liveviewx + (int)(background_width * waveview->text_pos_left / 100),
	          liveviewy, GTK_CORNER_BOTTOM_LEFT);
	draw_text(widget, event, waveview->text_bottom_right, liveviewx + (int)(background_width * waveview->text_pos_right / 100),
	          liveviewy, GTK_CORNER_BOTTOM_RIGHT);

	cairo_move_to (cr, liveviewx+280, liveviewy+40);

	float wave_go = 0;
	float sc = 280.0/waveview->frame_size;
	float sc1 = liveviewx+280+sc;
	float sc2 = liveviewy+40;
	//----- draw the frame
	for (int i = 0; i < waveview->frame_size; i++)
	{
		float x_in = waveview->frame[i];
		cairo_line_to (cr, sc1 - sc*(i+1), sc2 - x_in*waveview->m_wave);
		//cairo_line_to (cr, sc1 - sc*(i+1), sc2 + x_in*waveview->m_wave);
		wave_go = fmax(wave_go, fabs(x_in));
	}

	//----- get the sample, for display the gain value

	float wave_db = log(fabs( wave_go))*6/log(2);
	double xl     = floor(exp(log(1.055)*2.1*wave_db)*waveview->m_loud);

	if (xl > 125.0) xl = 125.0;
	else if (xl < -125.0) xl = -125.0;

	cairo_set_line_width (cr, 1.0);
	cairo_line_to (cr, liveviewx, liveviewy+40);
	cairo_pattern_t* linpat =
		cairo_pattern_create_linear (liveviewx, liveviewy-15,liveviewx, liveviewy+40);
	cairo_pattern_set_extend(linpat, CAIRO_EXTEND_REFLECT);
    set_box_color(widget, linpat);

	//cairo_pattern_add_color_stop_rgba (linpat, 0.4, 1, 0.2, 0,0.8);
	//cairo_pattern_add_color_stop_rgba (linpat, 0.8, 0.2, 1, 0.2,0.8);
	cairo_set_source (cr, linpat);
	cairo_close_path (cr);

	cairo_fill_preserve (cr);
	cairo_stroke (cr);

	//----- draw the gain value
	static const double dashes[] = {5.0, 1.0 };
	cairo_set_dash (cr, dashes, 2, -0.25);
	cairo_move_to (cr, liveviewx+140-xl, liveviewy);
	cairo_line_to (cr, liveviewx+140+xl, liveviewy);
	cairo_move_to (cr, liveviewx+140-xl, liveviewy+80);
	cairo_line_to (cr, liveviewx+140+xl, liveviewy+80);
	//cairo_set_source_rgba (cr,  redline, greenline, 0.2,0.8);
	linpat =
		cairo_pattern_create_linear (liveviewx, liveviewy,liveviewx+140, liveviewy);

	cairo_pattern_set_extend(linpat, CAIRO_EXTEND_REFLECT);
    set_box_color(widget, linpat);
	//cairo_pattern_add_color_stop_rgba (linpat, 0.2, 1, 0.2, 0,0.8);
	//cairo_pattern_add_color_stop_rgba (linpat, 0.8, 0.2, 1, 0.2,0.8);
	cairo_set_source (cr, linpat);
	cairo_set_line_width (cr, 3.0);
	cairo_stroke (cr);
	cairo_pattern_destroy (linpat);
	cairo_destroy(cr);
	gdk_region_destroy (region);

	return FALSE;
}

static void gx_wave_view_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
	g_assert(GX_IS_WAVE_VIEW(widget));
	requisition->width = liveview_x;
	requisition->height = liveview_y;
}

static void gx_wave_view_class_init (GxWaveViewClass *klass)
{
	GtkObjectClass *object_class = GTK_OBJECT_CLASS(klass);
	GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);

	object_class->destroy = gx_wave_view_destroy;
	gobject_class->set_property = gx_wave_view_set_property;
	gobject_class->get_property = gx_wave_view_get_property;
	widget_class->expose_event = gx_wave_view_expose;
	widget_class->size_request = gx_wave_view_size_request;
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_TOP_LEFT,
	                                 g_param_spec_string ("text-top-left",
	                                                      P_("Text top left"),
	                                                      P_("Text to be displayed at the top left"),
	                                                      "",
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_TOP_RIGHT,
	                                 g_param_spec_string ("text-top-right",
	                                                      P_("Text top right"),
	                                                      P_("Text to be displayed at the top right"),
	                                                      "",
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_BOTTOM_LEFT,
	                                 g_param_spec_string ("text-bottom-left",
	                                                      P_("Text bottom left"),
	                                                      P_("Text to be displayed at the bottom left"),
	                                                      "",
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_BOTTOM_RIGHT,
	                                 g_param_spec_string ("text-bottom-right",
	                                                      P_("Text bottom right"),
	                                                      P_("Text to be displayed at the bottom right"),
	                                                      "",
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_POS_LEFT,
	                                 g_param_spec_double ("text-pos-left",
	                                                      P_("Left Position"),
	                                                      P_("Text to be displayed at the bottom right"),
	                                                      0, 100, 5,
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property (gobject_class,
	                                 PROP_TEXT_POS_RIGHT,
	                                 g_param_spec_double ("text-pos-right",
	                                                      P_("Right Position"),
	                                                      P_("Text to be displayed at the bottom right"),
	                                                      0, 100, 70,
	                                                      GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property_parser(
		GTK_WIDGET_CLASS(klass),
		g_param_spec_boxed("box-gradient",
		                   P_("Skin color"),
		                   P_("Color gradient defined as part of skin"),
		                   GX_TYPE_GRADIENT,
		                   GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)),
		gx_parse_gradient);
}

static void gx_wave_view_init(GxWaveView *waveview)
{
	GtkWidget *widget = GTK_WIDGET(waveview);
	waveview->frame = NULL;
	waveview->frame_size = 0;
	waveview->text_top_left = NULL;
	waveview->text_top_right = NULL;
	waveview->text_bottom_left = NULL;
	waveview->text_bottom_right = NULL;
	waveview->text_pos_left = 5;
	waveview->text_pos_right = 70;
	waveview->m_wave = 75;
	waveview->m_loud = 150;
	widget->requisition.width = liveview_x;
	widget->requisition.height = liveview_y;
}

static void gx_wave_view_destroy (GtkObject *obj)
{
	GxWaveView *waveview = GX_WAVE_VIEW(obj);
	if (waveview->liveview_image) {
		g_object_unref(waveview->liveview_image);
		waveview->liveview_image = 0;
	}
	GTK_OBJECT_CLASS(gx_wave_view_parent_class)->destroy(obj);
}

GtkWidget* gx_wave_view_new()
{
	GtkWidget* widget = GTK_WIDGET(g_object_new(GX_TYPE_WAVE_VIEW, NULL));
	return widget;
}

void gx_wave_view_set_frame(GxWaveView *waveview, const float *frame, int frame_size)
{
	g_assert(GX_IS_WAVE_VIEW(waveview));
	waveview->frame = frame;
	waveview->frame_size = frame_size;
	gtk_widget_queue_draw(GTK_WIDGET(waveview));
}

void gx_wave_view_set_multiplicator(GxWaveView *waveview, double m_wave, double m_loud)
{
	g_assert(GX_IS_WAVE_VIEW(waveview));
	waveview->m_wave = m_wave;
	waveview->m_loud = m_loud;
}

void gx_wave_view_set_text(GxWaveView *waveview, const gchar *text, GtkCornerType pos)
{
	char **f;
	const char *p;
	g_assert(GX_IS_WAVE_VIEW(waveview));
	switch (pos) {
	case GTK_CORNER_TOP_LEFT:
		f = &waveview->text_top_left;
		p = "text-top-left";
		break;
	case GTK_CORNER_TOP_RIGHT:
		f = &waveview->text_top_right;
		p = "text-top-right";
		break;
	case GTK_CORNER_BOTTOM_LEFT:
		f = &waveview->text_bottom_left;
		p = "text-bottom-left";
		break;
	case GTK_CORNER_BOTTOM_RIGHT:
		f = &waveview->text_bottom_right;
		p = "text-bottom-right";
		break;
	default:
		g_assert(FALSE);
		return;
	}
	g_free(*f);
	*f = g_strdup(text);
	gtk_widget_queue_draw(GTK_WIDGET(waveview));
	g_object_notify(G_OBJECT(waveview), p);
}

static void gx_wave_view_set_property(GObject *object, guint prop_id,
                                          const GValue *value, GParamSpec *pspec)
{
	GxWaveView *wv = GX_WAVE_VIEW(object);
	switch(prop_id) {
	case PROP_TEXT_TOP_LEFT:
		gx_wave_view_set_text(wv, g_value_get_string(value), GTK_CORNER_TOP_LEFT);
		break;
	case PROP_TEXT_TOP_RIGHT:
		gx_wave_view_set_text(wv, g_value_get_string(value), GTK_CORNER_TOP_RIGHT);
		break;
	case PROP_TEXT_BOTTOM_LEFT:
		gx_wave_view_set_text(wv, g_value_get_string(value), GTK_CORNER_BOTTOM_LEFT);
		break;
	case PROP_TEXT_BOTTOM_RIGHT:
		gx_wave_view_set_text(wv, g_value_get_string(value), GTK_CORNER_BOTTOM_RIGHT);
		break;
	case PROP_TEXT_POS_LEFT:
		wv->text_pos_left = g_value_get_double(value);
		g_object_notify(object, "text-pos-left");
		break;
	case PROP_TEXT_POS_RIGHT:
		wv->text_pos_right = g_value_get_double(value);
		g_object_notify(object, "text-pos-right");
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void gx_wave_view_get_property(GObject *object, guint prop_id,
                                      GValue *value, GParamSpec *pspec)
{
	GxWaveView *wv = GX_WAVE_VIEW(object);

	switch(prop_id) {
	case PROP_TEXT_TOP_LEFT:
		g_value_set_string (value, wv->text_top_left);
		break;
	case PROP_TEXT_TOP_RIGHT:
		g_value_set_string (value, wv->text_top_right);
		break;
	case PROP_TEXT_BOTTOM_LEFT:
		g_value_set_string (value, wv->text_bottom_left);
		break;
	case PROP_TEXT_BOTTOM_RIGHT:
		g_value_set_string (value, wv->text_bottom_right);
		break;
	case PROP_TEXT_POS_LEFT:
		g_value_set_double (value, wv->text_pos_left);
		break;
	case PROP_TEXT_POS_RIGHT:
		g_value_set_double (value, wv->text_pos_right);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}
