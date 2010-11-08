#ifndef RB_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorCacheSettingsController();

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCacheSettingsController_prioritySettingsController( VALUE rb_database_cursor_cache_settings_controller );

#endif
