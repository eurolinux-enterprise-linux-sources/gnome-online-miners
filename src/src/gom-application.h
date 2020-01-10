/*
 * GNOME Online Miners - crawls through your online content
 * Copyright (C) 2014 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * Author: Debarshi Ray <debarshir@gnome.org>
 *
 */

#ifndef __GOM_APPLICATION_H__
#define __GOM_APPLICATION_H__

#include <gio/gio.h>

G_BEGIN_DECLS

#define GOM_TYPE_APPLICATION (gom_application_get_type ())

#define GOM_APPLICATION(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   GOM_TYPE_APPLICATION, GomApplication))

#define GOM_APPLICATION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   GOM_TYPE_APPLICATION, GomApplicationClass))

#define GOM_IS_APPLICATION(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   GOM_TYPE_APPLICATION))

#define GOM_IS_APPLICATION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   GOM_TYPE_APPLICATION))

#define GOM_APPLICATION_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   GOM_TYPE_APPLICATION, GomApplicationClass))

typedef struct _GomApplication      GomApplication;
typedef struct _GomApplicationClass GomApplicationClass;

GType gom_application_get_type (void);

GApplication * gom_application_new (const gchar *application_id, GType miner_type);

G_END_DECLS

#endif /* __GOM_APPLICATION_H__ */
