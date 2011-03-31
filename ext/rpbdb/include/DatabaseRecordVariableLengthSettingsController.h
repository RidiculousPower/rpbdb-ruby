#ifndef RB_RPBDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseRecordVariableLengthSettingsController();

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self);
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
	VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( VALUE	rb_database_record_variable_length_settings_controller );
	VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	VALUE	rb_database_record_variable_length_settings_controller, 
																																										VALUE	rb_delimeter_byte );

#endif
