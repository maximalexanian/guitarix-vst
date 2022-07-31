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

#ifndef __GX_CONTROL_PARAMETER_H__
#define __GX_CONTROL_PARAMETER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define GX_TYPE_CONTROL_PARAMETER                 (gx_control_parameter_get_type ())
#define GX_CONTROL_PARAMETER(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), GX_TYPE_CONTROL_PARAMETER, GxControlParameter))
#define GX_IS_CONTROL_PARAMETER(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GX_TYPE_CONTROL_PARAMETER))
#define GX_CONTROL_PARAMETER_GET_INTERFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), GX_TYPE_CONTROL_PARAMETER, GxControlParameterIface))


typedef struct _GxControlParameter GxControlParameter;
typedef struct _GxControlParameterIface GxControlParameterIface;

struct _GxControlParameterIface
{
	GTypeInterface parent_iface;

	void (*cp_configure)(GxControlParameter *self, gchar* group, gchar *name, gdouble lower, gdouble upper, gdouble step);
	void (*cp_set_value)(GxControlParameter *self, gdouble value);
	gdouble (*cp_get_value)(GxControlParameter *self);
};

GType gx_control_parameter_get_type(void);

void gx_control_parameter_cp_configure(GxControlParameter *self, gchar* group, gchar *name, gdouble lower, gdouble upper, gdouble step);
void gx_control_parameter_cp_set_value(GxControlParameter *self, gdouble value);
gdouble gx_control_parameter_cp_get_value(GxControlParameter *self);
gint gx_control_parameter_cp_get_int_value(GxControlParameter *self);
gchar *gx_control_parameter_cp_get_var(GxControlParameter *self);
void gx_control_parameter_cp_set_var(GxControlParameter *self, gchar *varname);

G_END_DECLS

#endif /* __GX_CONTROL_PARAMETER_H__ */
