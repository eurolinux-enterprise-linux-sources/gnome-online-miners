/*
 * GNOME Online Miners - crawls through your online content
 * Copyright (c) 2014 Pranav Kant
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
 * Author: Pranav Kant <pranav913@gmail.com>
 *
 */

#ifndef GOM_DLNA_SERVERS_MANAGER_H
#define GOM_DLNA_SERVERS_MANAGER_H

#include <glib-object.h>
#include "gom-dlna-server.h"

G_BEGIN_DECLS

#define GOM_TYPE_DLNA_SERVERS_MANAGER (gom_dlna_servers_manager_get_type ())

#define GOM_DLNA_SERVERS_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   GOM_TYPE_DLNA_SERVERS_MANAGER, GomDlnaServersManager))

#define GOM_DLNA_SERVERS_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   GOM_TYPE_DLNA_SERVERS_MANAGER, GomDlnaServersManagerClass))

#define GOM_IS_DLNA_SERVERS_MANAGER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   GOM_TYPE_DLNA_SERVERS_MANAGER))

#define GOM_IS_DLNA_SERVERS_MANAGER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   GOM_TYPE_DLNA_SERVERS_MANAGER))

#define GOM_DLNA_SERVERS_MANAGER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   GOM_TYPE_DLNA_SERVERS_MANAGER, GomDlnaServersManagerClass))

typedef struct _GomDlnaServersManager        GomDlnaServersManager;
typedef struct _GomDlnaServersManagerClass   GomDlnaServersManagerClass;
typedef struct _GomDlnaServersManagerPrivate GomDlnaServersManagerPrivate;

struct _GomDlnaServersManager
{
  GObject parent_instance;
  GomDlnaServersManagerPrivate *priv;
};

struct _GomDlnaServersManagerClass
{
  GObjectClass parent_class;
};

GType                    gom_dlna_servers_manager_get_type           (void) G_GNUC_CONST;

GomDlnaServersManager   *gom_dlna_servers_manager_dup_singleton      (void);

GomDlnaServer           *gom_dlna_servers_manager_get_server         (GomDlnaServersManager *self,
                                                                      const gchar *udn);

G_END_DECLS

#endif /* GOM_DLNA_SERVERS_MANAGER_H */
