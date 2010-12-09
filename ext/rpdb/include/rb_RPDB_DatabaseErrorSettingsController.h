#ifndef RB_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseErrorSettingsController();

VALUE rb_Rbdb_DatabaseErrorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_Rbdb_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller );
VALUE rb_Rbdb_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller );
VALUE rb_Rbdb_DatabaseErrorSettingsController_parentSettingsController(	VALUE	rb_database_error_settings_controller );
VALUE rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_error_settings_controller );
	VALUE rb_Rbdb_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller );
	VALUE rb_Rbdb_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
																													VALUE	rb_error_file );
	VALUE rb_Rbdb_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller );
	VALUE rb_Rbdb_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																														VALUE		rb_error_prefix );

#endif
