#ifndef RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseRecordSettingsController();

VALUE rb_RPDB_DatabaseRecordSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseRecordSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPDB_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPDB_DatabaseRecordSettingsController_parentSettingsController(	VALUE	rb_database_record_settings_controller );
VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_settings_controller );

#endif
