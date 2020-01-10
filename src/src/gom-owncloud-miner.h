/*
 * GNOME Online Miners - crawls through your online content
 * Copyright (c) 2013 Red Hat, Inc.
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

#ifndef __GOM_OWNCLOUD_MINER_H__
#define __GOM_OWNCLOUD_MINER_H__

#include <gio/gio.h>
#include "gom-miner.h"

G_BEGIN_DECLS

#define GOM_TYPE_OWNCLOUD_MINER gom_owncloud_miner_get_type()

#define GOM_OWNCLOUD_MINER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
   GOM_TYPE_OWNCLOUD_MINER, GomOwncloudMiner))

#define GOM_OWNCLOUD_MINER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
   GOM_TYPE_OWNCLOUD_MINER, GomOwncloudMinerClass))

#define GOM_IS_OWNCLOUD_MINER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
   GOM_TYPE_OWNCLOUD_MINER))

#define GOM_IS_OWNCLOUD_MINER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
   GOM_TYPE_OWNCLOUD_MINER))

#define GOM_OWNCLOUD_MINER_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
   GOM_TYPE_OWNCLOUD_MINER, GomOwncloudMinerClass))

typedef struct _GomOwncloudMiner GomOwncloudMiner;
typedef struct _GomOwncloudMinerClass GomOwncloudMinerClass;
typedef struct _GomOwncloudMinerPrivate GomOwncloudMinerPrivate;

struct _GomOwncloudMiner {
  GomMiner parent;

  GomOwncloudMinerPrivate *priv;
};

struct _GomOwncloudMinerClass {
  GomMinerClass parent_class;
};

GType gom_owncloud_miner_get_type(void);

G_END_DECLS

#endif /* __GOM_OWNCLOUD_MINER_H__ */
