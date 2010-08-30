#ifndef RB_RPDB_FILE_SETTINGS_CONTROLLER
	#define RB_RPDB_FILE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_FileSettingsController();

VALUE rb_RPDB_FileSettingsController_new(	VALUE	klass,
										  VALUE	rb_parent_settings_controller );
VALUE rb_RPDB_FileSettingsController_init(	VALUE	rb_file_settings_controller,
	VALUE	rb_parent_settings_controller );
	VALUE rb_RPDB_FileSettingsController_parentEnvironment(	VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_intermediateDirectoryMode( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_setIntermediateDirectoryMode(	VALUE			rb_file_settings_controller, 
																			VALUE		rb_mode );
	VALUE rb_RPDB_FileSettingsController_tempDirectory( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_setTempDirectory(	VALUE		rb_file_settings_controller, 
																														const VALUE	rb_temp_directory );
	VALUE rb_RPDB_FileSettingsController_permitEnvironmentBasedFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_createIfNecessary( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnCreateIfNecessaryOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnCreateIfNecessaryOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_isErrorIfDBExistsBeforeCreate( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_openReadOnly( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnOpenReadOnlyOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnOpenReadOnlyOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_forceRemoval( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnForceRemovalOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnForceRemovalOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_isXACompliant( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnIsXACompliantOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_turnIsXACompliantOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPDB_FileSettingsController_fileCreationMode( VALUE	rb_file_settings_controller );
		VALUE rb_RPDB_FileSettingsController_setFileCreationMode(	VALUE	rb_file_settings_controller,
		 															VALUE	rb_mode	);
	VALUE rb_RPDB_FileSettingsController_verbositySettingsController( VALUE	rb_file_settings_controller );

#endif
