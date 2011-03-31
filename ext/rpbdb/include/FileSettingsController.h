#ifndef RB_RPBDB_FILE_SETTINGS_CONTROLLER
	#define RB_RPBDB_FILE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_FileSettingsController();

VALUE rb_RPbdb_FileSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPbdb_FileSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self );
VALUE rb_RPbdb_FileSettingsController_parentEnvironment(	VALUE	rb_file_settings_controller );
VALUE rb_RPbdb_FileSettingsController_parentSettingsController(	VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_intermediateDirectoryMode( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_setIntermediateDirectoryMode(	VALUE			rb_file_settings_controller, 
																			VALUE		rb_mode );
	VALUE rb_RPbdb_FileSettingsController_tempDirectory( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_setTempDirectory(	VALUE		rb_file_settings_controller, 
																														const VALUE	rb_temp_directory );
	VALUE rb_RPbdb_FileSettingsController_permitEnvironmentBasedFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_createIfNecessary( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_isErrorIfDBExistsBeforeCreate( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_openReadOnly( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnOpenReadOnlyOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnOpenReadOnlyOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_forceRemoval( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnForceRemovalOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnForceRemovalOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_isXACompliant( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnIsXACompliantOn( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_turnIsXACompliantOff( VALUE	rb_file_settings_controller );
	VALUE rb_RPbdb_FileSettingsController_fileCreationMode( VALUE	rb_file_settings_controller );
		VALUE rb_RPbdb_FileSettingsController_setFileCreationMode(	VALUE	rb_file_settings_controller,
		 															VALUE	rb_mode	);
	VALUE rb_RPbdb_FileSettingsController_verbositySettingsController( VALUE	rb_file_settings_controller );

#endif
