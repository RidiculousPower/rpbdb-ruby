#ifndef RB_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseRecordSettingsController();

VALUE rb_RPbdb_DatabaseRecordSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseRecordSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPbdb_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPbdb_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPbdb_DatabaseRecordSettingsController_parentSettingsController(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_settings_controller );

VALUE rb_RPbdb_DatabaseRecordSettingsController_fixedLengthSettingsController(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPbdb_DatabaseRecordSettingsController_variableLengthSettingsController(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPbdb_DatabaseRecordSettingsController_readWriteSettingsController(	VALUE	rb_database_record_settings_controller );


#endif
