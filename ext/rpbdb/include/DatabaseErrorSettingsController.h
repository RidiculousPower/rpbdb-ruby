#ifndef RB_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseErrorSettingsController();

VALUE rb_RPbdb_DatabaseErrorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPbdb_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller );
VALUE rb_RPbdb_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller );
VALUE rb_RPbdb_DatabaseErrorSettingsController_parentSettingsController(	VALUE	rb_database_error_settings_controller );
VALUE rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_error_settings_controller );
	VALUE rb_RPbdb_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller );
	VALUE rb_RPbdb_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
																													VALUE	rb_error_file );
	VALUE rb_RPbdb_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller );
	VALUE rb_RPbdb_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																														VALUE		rb_error_prefix );

#endif
