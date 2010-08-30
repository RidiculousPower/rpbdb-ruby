#ifndef RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseFixedRecordSettingsController();

VALUE rb_RPDB_DatabaseFixedRecordSettingsController_new(	VALUE	klass,
														 VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_init(	VALUE	rb_database_fixed_record_settings_controller,
	VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_parentEnvironment(	VALUE	rb_database_fixed_record_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_parentDatabase(	VALUE	rb_database_fixed_record_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_recordLength( VALUE	rb_database_fixed_record_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_setRecordLength(	VALUE	rb_database_fixed_record_settings_controller,
																		VALUE	rb_record_length );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_paddingByte( VALUE	rb_database_fixed_record_settings_controller );
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_setPaddingByte(	VALUE	rb_database_fixed_record_settings_controller, 
																		VALUE	rb_record_padding_byte );

#endif
