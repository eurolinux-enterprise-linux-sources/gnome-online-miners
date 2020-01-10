/*
 * GNOME Online Miners - crawls through your online content
 * Copyright (c) 2011 Red Hat, Inc.
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
 * Author: Cosimo Cecchi <cosimoc@redhat.com>
 *
 */

#ifndef INSIDE_MINER
#error "gom-miner-main.c is meant to be included, not compiled standalone"
#endif

#include <unistd.h>

#include <glib-unix.h>
#include <glib.h>

#include "gom-application.h"
#include "tracker-ioprio.h"
#include "tracker-sched.h"

static gboolean
signal_handler_cb (gpointer user_data)
{
  GApplication *app = user_data;

  g_application_quit (app);
  return FALSE;
}

int
main (int argc,
      char **argv)
{
  GApplication *app;
  gint exit_status;

  tracker_sched_idle ();
  tracker_ioprio_init ();

  errno = 0;
  if (nice (19) == -1 && errno != 0)
    {
      const gchar *str;

      str = g_strerror (errno);
      g_warning ("Couldn't set nice value to 19, %s", (str != NULL) ? str : "no error given");
    }

  app = gom_application_new (MINER_BUS_NAME, MINER_TYPE);
  if (g_getenv (MINER_NAME "_MINER_PERSIST") != NULL)
    g_application_hold (app);

  g_unix_signal_add_full (G_PRIORITY_DEFAULT,
			  SIGTERM,
			  signal_handler_cb,
			  app, NULL);
  g_unix_signal_add_full (G_PRIORITY_DEFAULT,
			  SIGINT,
			  signal_handler_cb,
			  app, NULL);

  exit_status = g_application_run (app, argc, argv);
  g_object_unref (app);

  return exit_status;
}
