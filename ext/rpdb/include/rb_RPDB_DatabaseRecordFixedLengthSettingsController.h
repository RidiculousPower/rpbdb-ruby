#ifndef RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseRecordFixedLengthSettingsController();

VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_new(	int			argc,
																																VALUE*	args,
																																VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabase(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_recordLength( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setRecordLength(	VALUE	rb_database_record_fixed_length_settings_controller,
																		VALUE	rb_record_length );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_paddingByte( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	VALUE	rb_database_record_fixed_length_settings_controller, 
																		VALUE	rb_record_padding_byte );

#endif
