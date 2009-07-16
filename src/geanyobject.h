/*
 *      geanyobject.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2007-2009 Enrico Tröger <enrico(dot)troeger(at)uvena(dot)de>
 *      Copyright 2007-2009 Nick Treleaven <nick(dot)treleaven(at)btinternet(dot)com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 * $Id$
 */


#ifndef __GEANYOBJECT_H__
#define __GEANYOBJECT_H__

#include <glib-object.h>

G_BEGIN_DECLS

typedef enum
{
	GCB_DOCUMENT_NEW,
	GCB_DOCUMENT_OPEN,
	GCB_DOCUMENT_SAVE,
	GCB_DOCUMENT_ACTIVATE,
	GCB_DOCUMENT_CLOSE,
	GCB_PROJECT_OPEN,
	GCB_PROJECT_SAVE,
	GCB_PROJECT_CLOSE,
	GCB_UPDATE_EDITOR_MENU,
	GCB_EDITOR_NOTIFY,
	GCB_SAVE_SETTINGS,
	GCB_LOAD_SETTINGS,
	GCB_MAX
}
GeanyCallbackId;


#define GEANY_OBJECT_TYPE				(geany_object_get_type())
#define GEANY_OBJECT(obj)				(G_TYPE_CHECK_INSTANCE_CAST((obj),\
		GEANY_OBJECT_TYPE, GeanyObject))
#define GEANY_OBJECT_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST((klass),\
		GEANY_OBJECT_TYPE, GeanyObjectClass))
#define IS_GEANY_OBJECT(obj)				(G_TYPE_CHECK_INSTANCE_TYPE((obj),\
		GEANY_OBJECT_TYPE))
#define IS_GEANY_OBJECT_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE((klass),\
		GEANY_OBJECT_TYPE))

typedef struct _GeanyObject				GeanyObject;
typedef struct _GeanyObjectClass			GeanyObjectClass;

struct _GeanyObject
{
	GObject parent;
	/* add your public declarations here */
};

struct SCNotification;

struct _GeanyObjectClass
{
	GObjectClass parent_class;

	void (*document_new)(GeanyDocument *doc);
	void (*document_open)(GeanyDocument *doc);
	void (*document_save)(GeanyDocument *doc);
	void (*document_activate)(GeanyDocument *doc);
	void (*document_close)(GeanyDocument *doc);
	void (*project_open)(GKeyFile *keyfile);
	void (*project_save)(GKeyFile *keyfile);
	void (*project_close)(void);
	void (*update_editor_menu)(const gchar *word, gint click_pos, GeanyDocument *doc);
	gboolean (*editor_notify)(GeanyEditor *editor, gpointer scnt);
	void (*save_settings)(GKeyFile *keyfile);
	void (*load_settings)(GKeyFile *keyfile);
};

GType		geany_object_get_type	(void);
GObject*	geany_object_new		(void);

G_END_DECLS

#endif /* __GEANYOBJECT_H__ */
