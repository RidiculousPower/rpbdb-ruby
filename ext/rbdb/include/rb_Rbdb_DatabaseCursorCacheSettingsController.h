#ifndef RB_Rbdb_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseCursorCacheSettingsController();

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_prioritySettingsController( VALUE rb_database_cursor_cache_settings_controller );

#endif
