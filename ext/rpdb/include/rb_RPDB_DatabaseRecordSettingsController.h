#ifndef RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseRecordSettingsController();

VALUE rb_RPDB_DatabaseRecordSettingsController_new(	VALUE	klass,
													VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseRecordSettingsController_init(	VALUE	rb_database_record_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_record_settings_controller );

#endif
