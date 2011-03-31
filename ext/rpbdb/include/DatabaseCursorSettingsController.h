#ifndef RB_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCursorSettingsController();

VALUE rb_RPbdb_DatabaseCursorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseCursorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentEnvironment(	VALUE	rb_database_cursor_settings_controller );
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabase(	VALUE	rb_database_cursor_settings_controller );
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseCursor(	VALUE	rb_database_cursor_settings_controller );
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentSettingsController(	VALUE	rb_database_cursor_settings_controller );
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorSettingsController_duplicateRetainsLocation( VALUE	rb_cursor_settings_controller );
		VALUE rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( VALUE	rb_cursor_settings_controller );
		VALUE rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( VALUE	rb_cursor_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorSettingsController_cacheSettingsController( VALUE	rb_cursor_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorSettingsController_readWriteSettingsController( VALUE	rb_cursor_settings_controller );

#endif
