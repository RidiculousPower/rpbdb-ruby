#ifndef RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseRecordFixedLengthSettingsController();

VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_new(	VALUE	klass,
														 VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_init(	VALUE	rb_database_record_fixed_length_settings_controller,
	VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabase(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_recordLength( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setRecordLength(	VALUE	rb_database_record_fixed_length_settings_controller,
																		VALUE	rb_record_length );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_paddingByte( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	VALUE	rb_database_record_fixed_length_settings_controller, 
																		VALUE	rb_record_padding_byte );

#endif
