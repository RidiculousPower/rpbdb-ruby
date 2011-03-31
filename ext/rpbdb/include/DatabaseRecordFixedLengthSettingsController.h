#ifndef RB_RPBDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseRecordFixedLengthSettingsController();

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_new(	int			argc,
																																VALUE*	args,
																																VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabase(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_recordLength( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setRecordLength(	VALUE	rb_database_record_fixed_length_settings_controller,
																		VALUE	rb_record_length );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_paddingByte( VALUE	rb_database_record_fixed_length_settings_controller );
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	VALUE	rb_database_record_fixed_length_settings_controller, 
																		VALUE	rb_record_padding_byte );

#endif
