#ifndef RB_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorCacheSettingsController();

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_new(	VALUE	klass,
														 VALUE	rb_parent_database_cursor_settings_controller );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_init(	VALUE	rb_database_cursor_cache_settings_controller,
	VALUE	rb_parent_database_cursor_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCacheSettingsController_priorityController( VALUE rb_database_cursor_cache_settings_controller );

#endif
