#ifndef RB_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorSettingsController();

VALUE rb_RPDB_DatabaseCursorSettingsController_new(	VALUE	klass,
													VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseCursorSettingsController_init(	VALUE	rb_database_cursor_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseCursorSettingsController_parentEnvironment(	VALUE database_cursor_settings_controller );
	VALUE rb_RPDB_DatabaseCursorSettingsController_parentDatabase(	VALUE database_cursor_settings_controller );
	VALUE rb_RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation( VALUE	rb_cursor_settings_controller );
		VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( VALUE	rb_cursor_settings_controller );
		VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( VALUE	rb_cursor_settings_controller );
	VALUE rb_RPDB_DatabaseCursorSettingsController_cacheSettingsController( VALUE	rb_cursor_settings_controller );
	VALUE rb_RPDB_DatabaseCursorSettingsController_readWriteSettingsController( VALUE	rb_cursor_settings_controller );

#endif
