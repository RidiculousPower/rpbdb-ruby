#ifndef RB_RBDB_FILE_SETTINGS_CONTROLLER
	#define RB_RBDB_FILE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_FileSettingsController();

VALUE rb_Rbdb_FileSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_Rbdb_FileSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self );
VALUE rb_Rbdb_FileSettingsController_parentEnvironment(	VALUE	rb_file_settings_controller );
VALUE rb_Rbdb_FileSettingsController_parentSettingsController(	VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_intermediateDirectoryMode( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_setIntermediateDirectoryMode(	VALUE			rb_file_settings_controller, 
																			VALUE		rb_mode );
	VALUE rb_Rbdb_FileSettingsController_tempDirectory( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_setTempDirectory(	VALUE		rb_file_settings_controller, 
																														const VALUE	rb_temp_directory );
	VALUE rb_Rbdb_FileSettingsController_permitEnvironmentBasedFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_createIfNecessary( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnCreateIfNecessaryOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnCreateIfNecessaryOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_isErrorIfDBExistsBeforeCreate( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_openReadOnly( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnOpenReadOnlyOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnOpenReadOnlyOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_forceRemoval( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnForceRemovalOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnForceRemovalOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_isXACompliant( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnIsXACompliantOn( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_turnIsXACompliantOff( VALUE	rb_file_settings_controller );
	VALUE rb_Rbdb_FileSettingsController_fileCreationMode( VALUE	rb_file_settings_controller );
		VALUE rb_Rbdb_FileSettingsController_setFileCreationMode(	VALUE	rb_file_settings_controller,
		 															VALUE	rb_mode	);
	VALUE rb_Rbdb_FileSettingsController_verbositySettingsController( VALUE	rb_file_settings_controller );

#endif
