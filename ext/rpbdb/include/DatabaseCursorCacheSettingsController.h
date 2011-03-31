#ifndef RB_RPBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCursorCacheSettingsController();

VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCacheSettingsController_prioritySettingsController( VALUE rb_database_cursor_cache_settings_controller );

#endif
