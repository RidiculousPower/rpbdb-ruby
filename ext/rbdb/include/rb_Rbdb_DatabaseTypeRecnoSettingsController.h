#ifndef RB_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseTypeRecnoSettingsController();

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentEnvironment(	VALUE	rb_database_type_recno_settings_controller );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabase(	VALUE	rb_database_type_recno_settings_controller );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentSettingsController(	VALUE	rb_database_type_recno_settings_controller );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_recno_settings_controller );
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_recordRenumbering( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_snapshotIsolation( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( VALUE	rb_database_type_recno_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_sourceFile( VALUE	rb_database_type_recno_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_setSourceFile(	VALUE	rb_database_type_recno_settings_controller,
																		VALUE	rb_file_path );

#endif
