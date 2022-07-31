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
 * -------------------------------------------------------------------------
 *
 * Code shamelessly stolen from Ardour by Paul Davis, thanks man!
 * This is actually an adaptation of the C++ gtkmm2ext class in the
 * GTK C style.
 *
 * -------------------------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
#include "GxFastMeter.h"

#ifndef max
#define max(x,y) (((x)>(y)) ? (x) : (y))
#endif

#ifndef min
#define min(x,y) (((x)<(y)) ? (x) : (y))
#endif

#define P_(s) (s)   // FIXME -> gettext

enum {
	PROP_HOLD = 1,
	PROP_DIMEN,
    PROP_HORIZ,
    PROP_TYPE,
	PROP_VAR_ID
};

static const int min_size = 1;

static void gx_fast_meter_class_init(GxFastMeterClass*);
static void gx_fast_meter_init(GxFastMeter*);

static gboolean gx_fast_meter_expose_event(GtkWidget*, GdkEventExpose*);
static void gx_fast_meter_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void gx_fast_meter_size_request(GtkWidget*, GtkRequisition*);
static void gx_fast_meter_set_property(
	GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec);
static void gx_fast_meter_get_property(
	GObject *object, guint prop_id, GValue *value, GParamSpec *pspec);
static void queue_vertical_redraw(GxFastMeter*, GdkWindow*);
static void request_vertical_meter(GtkWidget *widget);
static void gx_fast_meter_style_set (GtkWidget *widget, GtkStyle  *previous_style);

G_DEFINE_TYPE(GxFastMeter, gx_fast_meter, GTK_TYPE_DRAWING_AREA);

/* ----- fast meter class init ----- */
void gx_fast_meter_class_init(GxFastMeterClass* klass)
{
	GtkWidgetClass* widget_class = (GtkWidgetClass*)klass;
	GObjectClass *gobject_class = G_OBJECT_CLASS(klass);

	widget_class->size_request  = gx_fast_meter_size_request;
	widget_class->size_allocate = gx_fast_meter_size_allocate;
	widget_class->expose_event  = gx_fast_meter_expose_event;
	widget_class->style_set = gx_fast_meter_style_set;
	gobject_class->set_property = gx_fast_meter_set_property;
	gobject_class->get_property = gx_fast_meter_get_property;

	g_object_class_install_property (
		gobject_class, PROP_VAR_ID, g_param_spec_string(
			"var-id", P_("Variable"),
			P_("The id of the linked variable"),
			NULL, GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property(
		gobject_class, PROP_HOLD, g_param_spec_int(
			"hold", P_("Hold"),
			P_("Count of cycles for which the peak value is held on display"),
			0, 1000, 2, GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	g_object_class_install_property(
		gobject_class, PROP_DIMEN, g_param_spec_int(
			"dimen", P_("Dimension"),
			P_("Size of meter"),
			0, 100, 2, GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
    g_object_class_install_property(
		gobject_class, PROP_HORIZ, g_param_spec_boolean(
			"horiz", P_("Horizontal"),
			P_("Meter is drawn horizontally"),
			FALSE, GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
    g_object_class_install_property(
		gobject_class, PROP_TYPE, g_param_spec_int(
			"type", P_("Type"),
			P_("Type of meter: 0->stand-alone; 1->stereo left; 2->stereo right;"),
			0, 2, 0, GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_boxed("clr-bottom",P_("bottom color"),
		                   P_("indicator color gradient: value at the bottom"),
		                   GDK_TYPE_COLOR,
		                   GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_boxed("clr-middle",P_("middle color"),
		                   P_("indicator color gradient: value in the middle"),
		                   GDK_TYPE_COLOR,
		                   GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_boxed("clr-top",P_("top color"),
		                   P_("indicator color gradient: value near the top"),
		                   GDK_TYPE_COLOR,
		                   GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_boxed("over",P_("clip warn color"),
		                   P_("indicator color for values > 0 dbFS"),
		                   GDK_TYPE_COLOR,
		                   GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
	gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("dimen",P_("width of indicator"),
		                   P_("width of (vertical) indicator"),
		                 0, 100, 2, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("led-border",P_("LED Border"),
		                   P_("Border around LED"),
		                 0, 100, 1, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("led-width",P_("LED Width"),
		                   P_("Width of LED"),
		                 0, 100, 2, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("led-height",P_("LED Height"),
		                   P_("Height of LED"),
		                 0, 100, 2, GParamFlags(G_PARAM_READABLE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_int("border-radius",
            P_("Border Radius"),
            P_("The radius of the corners in pixels"),
            0, 100, 0,
            GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
    
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_float("bevel",
            P_("Bevel"),
            P_("The bevel effect"),
            -1.0, 1.0, 0.0,
            GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
    gtk_widget_class_install_style_property(
		widget_class,
		g_param_spec_float("mid-pos",
            P_("Mid-Position"),
            P_("Position of the middle color"),
            0, 1, 0.5,
            GParamFlags(G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS)));
}

/* ----- fast meter init ----- */
void gx_fast_meter_init(GxFastMeter* fm)
{
	fm->surface = 0;
    fm->overlay = 0;
	fm->top_of_meter = 0;
	fm->last_peak_rect.width = 0;
	fm->last_peak_rect.height = 0;
	fm->hold_cnt = 0;
	fm->hold_state = 0;
	fm->current_peak = 0;
	fm->current_level = 0;
    fm->old_peak_db =  -INFINITY;
	gtk_widget_set_events(GTK_WIDGET(fm),
	                      GDK_BUTTON_PRESS_MASK|GDK_BUTTON_RELEASE_MASK);
    gtk_widget_set_has_window(GTK_WIDGET(fm), FALSE);
    GdkScreen *screen = gdk_screen_get_default();
    GdkColormap *colormap = gdk_screen_get_rgba_colormap(screen);
    if (colormap && gdk_screen_is_composited (screen))
        gtk_widget_set_colormap(GTK_WIDGET(fm), colormap);

}

/* -------------- */
GtkWidget* gtk_fast_meter_new (int hold)
{
	GxFastMeter* fm;
	fm = GX_FAST_METER(g_object_new(GX_TYPE_FAST_METER, NULL));
	fm->hold_cnt = hold;
	return GTK_WIDGET (fm);
}


/* ------ hold count ----- */
void gx_fast_meter_set_hold_count(GxFastMeter* fm, int val)
{
	if (val < 1) val = 1;

	fm->hold_cnt     = val;
	fm->hold_state   = 0;
	fm->current_peak = 0;

	gtk_widget_queue_draw(GTK_WIDGET(fm));
}

static void gx_fast_meter_size_allocate (GtkWidget *widget, GtkAllocation *allocation)
{
	GTK_WIDGET_CLASS(gx_fast_meter_parent_class)->size_allocate(widget, allocation);
	request_vertical_meter(widget);
}

static void gx_fast_meter_set_var_id(GxFastMeter *fm, const gchar *str)
{
	g_free(fm->var_id);
	fm->var_id = g_strdup(str ? str : "");
	g_object_notify(G_OBJECT(fm), "var-id");
}

static void gx_fast_meter_set_property(GObject *object, guint prop_id,
                                           const GValue *value, GParamSpec *pspec)
{
	GxFastMeter *fm = GX_FAST_METER(object);
	switch(prop_id) {
	case PROP_HOLD:
		fm->hold_cnt = g_value_get_int(value);
		g_object_notify(object, "hold");
		fm->hold_state = 0;
		break;
	case PROP_DIMEN:
		fm->dimen = g_value_get_int(value);
		g_object_notify(object, "dimen");
		gtk_widget_queue_resize(GTK_WIDGET(object));
		break;
    case PROP_HORIZ:
		fm->horiz = g_value_get_boolean(value);
		g_object_notify(object, "horiz");
		gtk_widget_queue_resize(GTK_WIDGET(object));
		break;
    case PROP_TYPE:
		fm->type = g_value_get_int(value);
		g_object_notify(object, "type");
		gtk_widget_queue_resize(GTK_WIDGET(object));
		break;
	case PROP_VAR_ID:
		gx_fast_meter_set_var_id (fm, g_value_get_string (value));
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void gx_fast_meter_get_property(GObject *object, guint prop_id,
                                           GValue *value, GParamSpec *pspec)
{
	GxFastMeter *fm = GX_FAST_METER(object);

	switch(prop_id) {
	case PROP_HOLD:
		g_value_set_int(value, fm->hold_cnt);
		break;
	case PROP_DIMEN:
		g_value_set_int(value, fm->dimen);
		break;
    case PROP_HORIZ:
		g_value_set_boolean(value, fm->horiz);
		break;
    case PROP_TYPE:
		g_value_set_int(value, fm->type);
		break;
	case PROP_VAR_ID:
		g_value_set_string (value, fm->var_id);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void gx_fast_meter_style_set(GtkWidget *widget, GtkStyle  *previous_style)
{
	request_vertical_meter(widget);
}

/* ------- setting meter level ----------- */
void gx_fast_meter_set(GxFastMeter* fm, gdouble lvl)
{
	float old_level = fm->current_level;
	float old_peak  = fm->current_peak;

	lvl = max(0.0, min(1.0, lvl));
	fm->current_level = lvl;

	if (lvl >= fm->current_peak) {
	    fm->current_peak = lvl;
	    fm->hold_state   = fm->hold_cnt;
	}
	if (fm->hold_state > 0) {
	    --fm->hold_state;
	}
	if (fm->hold_state == 0) {
	    fm->current_peak = lvl;
	}
	if (fm->current_level == old_level &&
	    (fm->hold_state == 0 || fm->current_peak  == old_peak)) {
		return;
	}
	GdkWindow* window = gtk_widget_get_window(GTK_WIDGET(fm));
	if (window) {
		queue_vertical_redraw(fm, window);
	}
}



inline float power2db(float power) {
    return  20.*log10(power);
}

inline double log_meter (double db)
{
    // keep log_meter_inv in sync when changing anying!
    gfloat def = 0.0f; /* Meter deflection %age */

    if (db < -70.0f) {
        def = 0.0f;
    } else if (db < -60.0f) {
        def = (db + 70.0f) * 0.25f;
    } else if (db < -50.0f) {
        def = (db + 60.0f) * 0.5f + 2.5f;
    } else if (db < -40.0f) {
        def = (db + 50.0f) * 0.75f + 7.5f;
    } else if (db < -30.0f) {
        def = (db + 40.0f) * 1.5f + 15.0f;
    } else if (db < -20.0f) {
        def = (db + 30.0f) * 2.0f + 30.0f;
    } else if (db < 6.0f) {
        def = (db + 20.0f) * 2.5f + 50.0f;
    } else {
        def = 115.0f;
    }

    /* 115 is the deflection %age that would be
       when db=6.0. this is an arbitrary
       endpoint for our scaling.
    */

    return def/115.0f;
}

double meter_level_by_power(GxFastMeter* fm, float new_level) {

    static const float falloff = 27 * 60 * 0.0005;

    // calculate peak dB and translate into meter
    float peak_db = -INFINITY;
    if (new_level > 0) {
        peak_db = power2db(new_level);
    }
    // retrieve old meter value and consider falloff
    if (peak_db < fm->old_peak_db) {
        peak_db = max(peak_db, fm->old_peak_db - falloff);
    }
    fm->old_peak_db = peak_db;
    return (log_meter(peak_db));
}


/* ------- setting meter level ----------- */
void gx_fast_meter_set_by_power(GxFastMeter* fm, gdouble lvl)
{
	float old_level = fm->current_level;
	float old_peak  = fm->current_peak;

	lvl = max(0.0, min(1.0, meter_level_by_power(fm,lvl)));
	fm->current_level = lvl;

	if (lvl >= fm->current_peak) {
	    fm->current_peak = lvl;
	    fm->hold_state   = fm->hold_cnt;
	}
	if (fm->hold_state > 0) {
	    --fm->hold_state;
	}
	if (fm->hold_state == 0) {
	    fm->current_peak = lvl;
	}
	if (fm->current_level == old_level &&
	    (fm->hold_state == 0 || fm->current_peak  == old_peak)) {
		return;
	}
	GdkWindow* window = gtk_widget_get_window(GTK_WIDGET(fm));
	if (window) {
		queue_vertical_redraw(fm, window);
	}
}

/* ------- setting compressor meter level ----------- */
void gx_fast_meter_set_c_level(GxFastMeter* fm, gdouble lvl)
{
	float old_level = fm->current_level;
	float old_peak  = fm->current_peak;

	lvl = max(0.0, min(1.0, lvl*0.25));
	fm->current_level = lvl;

	if (lvl >= fm->current_peak) {
	    fm->current_peak = lvl;
	    fm->hold_state   = fm->hold_cnt;
	}
	if (fm->hold_state > 0) {
	    --fm->hold_state;
	}
	if (fm->hold_state == 0) {
	    fm->current_peak = lvl;
	}
	if (fm->current_level == old_level &&
	    (fm->hold_state == 0 || fm->current_peak  == old_peak)) {
		return;
	}
	GdkWindow* window = gtk_widget_get_window(GTK_WIDGET(fm));
	if (window) {
		queue_vertical_redraw(fm, window);
	}
}
/* ------------- clear fast meter object ------------ */
void gx_fast_meter_clear(GxFastMeter* fm)
{
	fm->current_level = 0;
	fm->current_peak  = 0;
	fm->hold_state    = 0;
	gtk_widget_queue_draw(GTK_WIDGET(fm));
}

/* ------------------------------ static functions ------------------------- */

static void gx_fast_meter_size_request (GtkWidget* wd, GtkRequisition* req)
{
    GxFastMeter * fm = GX_FAST_METER(wd);
    int lw, lh, lb, dim_, dim, tm, xs, ys;
    gtk_widget_style_get(wd, "led-width", &lw, "led-height", &lh, "led-border", &lb, "dimen", &dim_, NULL);
    dim = fm->dimen ? fm->dimen : dim_;
    if (fm->horiz) {
        xs = wd->style->xthickness;
        ys = wd->style->ythickness;
    } else {
        xs = wd->style->ythickness;
        ys = wd->style->xthickness;
    }
    if (!fm->horiz) {
        tm = !fm->type ? 2 * xs : int(1.5 * xs);
        req->width  = lb + dim * (lw + lb) + tm;
        req->height = lb + min_size * (lh + lb) + 2 * ys;
    } else {
        tm = !fm->type ? 2 * ys : int(1.5 * ys);
        req->width  = lb + min_size * (lh + lb) + 2 * xs;
        req->height = lb + dim * (lw + lb) + tm;
    }
    if (!fm->type) {
        req->width  = lb + dim * (lw + lb) + xs;
        req->height = lb + min_size * (lh + lb);
    }
    fm->request = req;
}

/* --------- vertical drawing queue ----------- */
void queue_vertical_redraw (GxFastMeter* fm, GdkWindow* win)
{
    if (!fm->surface)
		return;
	GtkWidget *widget = GTK_WIDGET(fm);
	GdkRectangle rect;
    GdkRectangle b = fm->bar;
	int lw, lh, lb;
    gtk_widget_style_get(GTK_WIDGET(fm), "led-width", &lw, "led-height", &lh, "led-border", &lb, NULL);
    
    int hrz    = fm->horiz;
    int tom    = fm->top_of_meter;
    
	gint new_top = (gint)floor((hrz ? b.width : b.height) * fm->current_level);
    new_top -= new_top % (lh + lb);
    if (new_top) {
        new_top += (lh + lb);
    }
	rect.x       = b.x + widget->allocation.x;
	rect.width   = hrz ? new_top : b.width;
	rect.height  = hrz ? b.width : new_top;
	rect.y       = hrz ? b.y : b.y + b.height - new_top;
    rect.y += widget->allocation.y;
    
	if (new_top >= tom) {
        if (hrz) {
            rect.x += tom;
            rect.width -= tom;
        } else {
            rect.height -= tom;
        }
	} else {
        if (hrz) {
            rect.x += new_top;
            rect.width = tom - new_top;
        } else {
            rect.y += new_top - tom;
            rect.height = tom;
        }
	}

	GdkRegion* region = 0;
	bool queue = false;

	if (rect.height + rect.width != 0) {
		/* ok, first region to draw ... */
		region = gdk_region_rectangle (&rect);
		queue = true;
	}

	/* redraw the last place where the last peak hold bar was;
	   the next expose will draw the new one whether its part of
	   expose region or not. */

	if (fm->last_peak_rect.width * fm->last_peak_rect.height != 0) {
		if (!queue) {
			region = gdk_region_new ();
			queue = true;
		}

		gdk_region_union_with_rect (region, &fm->last_peak_rect);
	}
	if (queue) {
		gdk_window_invalidate_region (win, region, TRUE);
	}
	if (region) {
		gdk_region_destroy(region);
		region = 0;
	}
}


/* ------- expose event -------- */
static gboolean gx_fast_meter_expose_event (GtkWidget* wd, GdkEventExpose* ev)
{
	GxFastMeter* fm = GX_FAST_METER(wd);
    GdkRectangle b = fm->bar;
	gint         top_of_meter;
    int lw, lh, lb, dim, dim_;
    gtk_widget_style_get(wd, "led-width", &lw, "led-height", &lh, "led-border", &lb, "dimen", &dim_, NULL);
    dim = fm->dimen ? fm->dimen : dim_;
    
	if (!fm->surface) {
		return FALSE;
	}
    int hrz    = fm->horiz;
	int height = cairo_image_surface_get_height(fm->surface);
	int width  = cairo_image_surface_get_width(fm->surface);
    int x = wd->allocation.x;
    int y = wd->allocation.y;
    
    top_of_meter  = (gint) floor (float(hrz ? b.width : b.height) * fm->current_level);
    top_of_meter -= top_of_meter % (lh + lb);
    if (top_of_meter)
        top_of_meter += (lh + lb);
    fm->top_of_meter = top_of_meter;
    
	cairo_t *cr = gdk_cairo_create(GTK_WIDGET(fm)->window);
    
    cairo_rectangle(cr, x, y, width, height);
    cairo_clip(cr);
    
    //cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    //cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 0.0);
    //cairo_paint(cr);
    
    cairo_set_source_surface(cr, fm->surface, x, y);
	cairo_rectangle(cr, x, y, width, height);
	cairo_fill(cr);
    
    cairo_set_source_surface(cr, fm->overlay, x, y);
    cairo_rectangle(cr,
        b.x + x,
        hrz ? b.y + y : b.y + b.height - top_of_meter + y,
        hrz ? top_of_meter : b.width,
        hrz ? b.height : top_of_meter );
	cairo_fill(cr);
    
	// draw peak bar

	if (fm->hold_state) {
        GdkRectangle *r = &fm->last_peak_rect;
        
        r->width  = hrz ? lb + lh - (lw + lb) : lb + dim * (lw + lb);
        r->height = hrz ? lb + dim * (lw + lb) : lb + lh;
        
        if (hrz) {
            int w = floor(b.width * fm->current_peak);
            r->x = b.x + w - w % (lb + lh);
            r->y = b.y;
        } else {
            int h = floor(b.height * fm->current_peak);
            r->x = b.x;
            r->y = b.y + b.height - h + h % (lb + lh);
        }

		cairo_set_source_surface(cr, fm->overlay, x, y);
		cairo_rectangle(cr, r->x, r->y, r->width, r->height);
		cairo_fill(cr);
	} else {
		fm->last_peak_rect.width  = 0;
		fm->last_peak_rect.height = 0;
	}
    cairo_destroy(cr);
	return FALSE;
}



#define grad_size 4

GdkColor default_gradient_color[grad_size] = {
	//   red     green   blue
	{ 0, 0x0000, 0xffff, 0x0000 }, // clr-bottom
	{ 0, 0xffff, 0xffff, 0x0000 }, // clr-middle
	{ 0, 0xffff, 0xaa00, 0x0000 }, // clr-top
	{ 0, 0xffff, 0x0000, 0x0000 }  // over
};

#define CVALUE(i,c,y,mx) (guint8)floor(((int)rgb[i]->c + (((int)rgb[i+1]->c - (int)rgb[i]->c) * (y)) / (float)(mx))/256)

/* ----- create pixbuf for vertical meter ------ */
static void request_vertical_meter(GtkWidget *widget)
{
	GxFastMeter* fm = GX_FAST_METER(widget);
	if (fm->surface) {
		cairo_surface_destroy(fm->surface);
        cairo_surface_destroy(fm->overlay);
	}
    int lw, lh, lb, dim_, dim, type, tm, rad;
    float bevel;
    gtk_widget_style_get(widget, "led-width", &lw, "led-height", &lh, "led-border", &lb, "dimen", &dim_, "border-radius", &rad, "bevel", &bevel, NULL);
    dim = fm->dimen ? fm->dimen : dim_;
    type = fm->type;
    bool hrz = fm->horiz;
    
    int xs, ys;
    
    if (hrz) {
        xs = widget->style->xthickness;
        ys = widget->style->ythickness;
    } else {
        xs = widget->style->ythickness;
        ys = widget->style->xthickness;
    }
    //printf("tw %d th %d tb %d dim %d type %d\n", lw, lh, lb, dim, type);
    
    int width, height;
    if (!hrz) {
        tm = !fm->type ? 2 * xs : int(1.5 * xs);
        width  = min(widget->allocation.width, lb + dim * (lw + lb) + tm);
        height = max(widget->allocation.height, lb + min_size * (lh + lb) + 2 * ys);
    } else {
        tm = !fm->type ? 2 * ys : int(1.5 * ys);
        width  = max(widget->allocation.width, lb + min_size * (lh + lb) + 2 * xs);
        height = min(widget->allocation.height, lb + dim * (lw + lb) + tm);
    }
    
    cairo_t *cr;
    fm->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    fm->overlay = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cr = cairo_create(fm->surface);
	if (!fm->surface) {
		return;
	}
    
    int w_ = width;
    int h_ = height;
    int x_ = 0;
    int y_ = 0;
    switch (type) {
        case 0:
        default:
            break;
        case 1:
            if (hrz)
                h_ *= 2;
            else
                w_ *= 2;
            break;
        case 2:
            if (hrz) {
                y_ = -h_;
                h_ *= 2;
            } else {
                x_ = -w_;
                w_ *= 2;
            }
            break;
    }
    //printf("width %d | height %d | w_ %d | h_ %d | x_ %d | y_ %d | rad %d | bevel %.2f\n", width, height, w_, h_, x_, y_, rad, bevel);
    
    // overall background
    float r, g, b;
    gx_get_color(widget, "bg", NULL, &r, &g, &b);
    //if (type) {
    gx_create_rectangle(cr, x_, y_, w_, h_, rad);
	cairo_set_source_rgb(cr, r, g, b);
	cairo_fill(cr);
    
    if (bevel)
        gx_bevel(cr, x_, y_, w_, h_, rad, bevel);
    //}
    // inner background
    w_ = hrz ? width - 2 * xs : lb + dim * (lw + lb);
    h_ = hrz ? lb + dim * (lw + lb) : height - 2 * ys;
    x_ = xs;
    y_ = ys;
    if (type == 2) {
        if (hrz)
            y_ -= int(0.5 * ys);
        else
            x_ -= int(0.5 * xs);
    }
    if (hrz) {
        w_ -= (w_ - lb) % (lh + lb);
    } else {
        h_ -= (h_ - lb) % (lh + lb);
    }
    gx_get_color(widget, "base", NULL, &r, &g, &b);
    gx_create_rectangle(cr, x_, y_, w_, h_, 0);
    cairo_set_source_rgb(cr, r, g, b);
    cairo_fill(cr);
    
    // gradient
    GdkColor *rgb[4];
    unsigned int i;
    float midpos;
    gtk_widget_style_get(widget, "clr-bottom", &rgb[0], "clr-middle", &rgb[1], "clr-top", &rgb[2], "over", &rgb[3], "mid-pos", &midpos, NULL);
	for (i = 0; i < sizeof(rgb)/sizeof(rgb[0]); i++) {
		if (!rgb[i]) {
			rgb[i] = gdk_color_copy(&default_gradient_color[i]);
		}
	}
    
    float bars = hrz ? w_ - 2*lb : h_ - 2*lb; // size of only the leds
    float lpos = (bars - lh) / bars;
    cairo_pattern_t *pat = cairo_pattern_create_linear(
        x_ + lb,
        y_ + h_ - lb,
        hrz ? x_ + w_ - lb : x_ + lb,
        hrz ? y_ + h_ - lb : y_ + lb);
    cairo_pattern_add_color_stop_rgb(pat, 0, rgb[0]->red / 65536., rgb[0]->green / 65536., rgb[0]->blue / 65536.);
    cairo_pattern_add_color_stop_rgb(pat, midpos, rgb[1]->red / 65536., rgb[1]->green / 65536., rgb[1]->blue / 65536.);
    cairo_pattern_add_color_stop_rgb(pat, lpos, rgb[2]->red / 65536., rgb[2]->green / 65536., rgb[2]->blue / 65536.);
    cairo_pattern_add_color_stop_rgb(pat, lpos + 0.0001, rgb[3]->red / 65536., rgb[3]->green / 65536., rgb[3]->blue / 65536.);
    
    cairo_rectangle(cr, x_ + lb, y_ + lb, w_ - 2*lb, h_ - 2*lb);
    cairo_set_source(cr, pat);
    cairo_fill(cr);
    
    fm->bar.x      = x_ + lb;
    fm->bar.y      = y_ + lb;
    fm->bar.width  = w_ - 2*lb;
    fm->bar.height = h_ - 2*lb;
    
    // led borders
    cairo_set_source_rgb(cr, r, g, b);
    int max = hrz ? w_ : h_;
    for (int j = 0; j < max; j += lh + lb) {
        cairo_rectangle(cr,
            x_ + (hrz ? j : 0),
            y_ + (hrz ? 0 : j),
            hrz ? lb : w_,
            hrz ? h_ : lb);
        cairo_fill(cr);
    }
    for (int j = 1; j < dim; j++) {
        cairo_rectangle(cr,
            x_ + (hrz ? 0 : j * (lb + lw)),
            y_ + (hrz ? j * (lb + lw) : 0),
            hrz ? w_ : lb,
            hrz ? lb : h_);
        cairo_fill(cr);
    }
    
    // inset
    if (hrz)
        _gx_draw_inset(cr, x_, y_, w_, h_, rad, 1);
    else
        _gx_draw_inset(cr, x_ + 1, y_ + 1, w_, h_, rad, 0.5);
    // overlay
    cairo_t *co;
    co = cairo_create(fm->overlay);
    cairo_set_source_surface(co, fm->surface, 0, 0);
    cairo_paint(co);
    
    cairo_rectangle(cr, x_, y_, w_, h_);
    cairo_set_source_rgba(cr, r, g, b, 0.8);
    cairo_fill(cr);
    
    cairo_destroy(cr);
    cairo_destroy(co);
    cairo_pattern_destroy(pat);
}

/* -------------- */
/* EOF */
