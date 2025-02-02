/*
 * GNOME-MAG Magnification service for GNOME
 *
 * Copyright 2006 Carlos Eduardo Rodrigues Diógenes
 * Copyright 2004 Sun Microsystems Inc. (damage-client.c)
 * Copyright 2001 Sun Microsystems Inc. (magnifier.c)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef GMAG_CURSOR_H_
#define GMAG_CURSOR_H_

#include "magnifier.h"

#include <X11/Xlib.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

gint       gmag_cursor_init (Magnifier *magnifier, Display *dpy_conn);
GdkPixbuf *gmag_cursor_get_source_pixbuf (Magnifier *magnifier);
void       gmag_cursor_events_handler (Magnifier *magnifier, XEvent *ev);

#endif /* GMAG_CURSOR_H_ */
