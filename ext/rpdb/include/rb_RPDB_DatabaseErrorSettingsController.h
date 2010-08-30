#ifndef RB_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseErrorSettingsController();

VALUE rb_RPDB_DatabaseErrorSettingsController_new(	VALUE	klass,
												   VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseErrorSettingsController_init(	VALUE	rb_database_error_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller );
	VALUE rb_RPDB_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller );
	VALUE rb_RPDB_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller );
	VALUE rb_RPDB_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
															VALUE	rb_error_file );
	VALUE rb_RPDB_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller );
	VALUE rb_RPDB_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																VALUE		rb_error_prefix );

#endif
