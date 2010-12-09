#ifndef RB_Rbdb_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseRecordVariableLengthSettingsController();

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self);
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_variable_length_settings_controller );
	VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( VALUE	rb_database_record_variable_length_settings_controller );
	VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	VALUE	rb_database_record_variable_length_settings_controller, 
																																										VALUE	rb_delimeter_byte );

#endif
