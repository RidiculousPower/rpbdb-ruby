#ifndef RB_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseVariableRecordSettingsController();

VALUE rb_RPDB_DatabaseVariableRecordSettingsController_new(	VALUE	klass,
															VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseVariableRecordSettingsController_init(	VALUE	rb_database_variable_record_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseVariableRecordSettingsController_parentEnvironment(	VALUE	rb_database_variable_record_settings_controller );
	VALUE rb_RPDB_DatabaseVariableRecordSettingsController_parentDatabase(	VALUE	rb_database_variable_record_settings_controller );
	VALUE rb_RPDB_DatabaseVariableRecordSettingsController_recordDelimeter( VALUE	rb_database_variable_record_settings_controller );
	VALUE rb_RPDB_DatabaseVariableRecordSettingsController_setRecordDelimeter(	VALUE	rb_database_variable_record_settings_controller, 
																				VALUE	rb_record_delimeter );

#endif
