#ifndef RB_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseTypeRecnoSettingsController();

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_new(	VALUE	klass,
													   VALUE	rb_parent_database_type_settings_controller );
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_init(	VALUE	rb_database_type_recno_settings_controller,
	VALUE	rb_parent_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentEnvironment(	VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabase(	VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_sourceFile( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_setSourceFile(	VALUE	rb_database_type_recno_settings_controller,
																		VALUE	rb_file_path );

#endif
