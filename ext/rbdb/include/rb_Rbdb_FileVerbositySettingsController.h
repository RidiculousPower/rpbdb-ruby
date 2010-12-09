#ifndef RB_Rbdb_FILE_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_Rbdb_FILE_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_FileVerbositySettingsController();

VALUE rb_Rbdb_FileVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_Rbdb_FileVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_Rbdb_FileVerbositySettingsController_parentEnvironment(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_Rbdb_FileVerbositySettingsController_parentSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_Rbdb_FileVerbositySettingsController_parentFileSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_Rbdb_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_Rbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_Rbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );
VALUE rb_Rbdb_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_Rbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_Rbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );

#endif
