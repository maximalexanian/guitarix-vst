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

#ifndef __GX_VSLIDER_H__
#define __GX_VSLIDER_H__


#include "GxRegler.h"

G_BEGIN_DECLS

#define GX_TYPE_VSLIDER          (gx_vslider_get_type())
#define GX_VSLIDER(obj)          (G_TYPE_CHECK_INSTANCE_CAST ((obj), GX_TYPE_VSLIDER, GxVSlider))
#define GX_VSLIDER_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST ((klass),  GX_TYPE_VSLIDER, GxVSliderClass))
#define GX_IS_VSLIDER(obj)       (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GX_TYPE_VSLIDER))
#define GX_IS_VSLIDER_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GX_TYPE_VSLIDER))
#define GX_VSLIDER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GX_TYPE_VSLIDER, GxVSliderClass))

typedef struct _GxVSlider GxVSlider;
typedef struct _GxVSliderClass GxVSliderClass;

struct _GxVSlider {
	GxRegler parent;
    GdkPixbuf *image;
    int slider_height;
    int width;
    int height;
    int hover;
    GdkRectangle image_rect;
};

struct _GxVSliderClass {
	GxReglerClass parent_class;
	const gchar *stock_id;
};

GType gx_vslider_get_type(void);

G_END_DECLS

#endif /* __GX_VSLIDER_H__ */
