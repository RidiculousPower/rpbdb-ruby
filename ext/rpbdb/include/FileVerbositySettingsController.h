#ifndef RB_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_FileVerbositySettingsController();

VALUE rb_RPbdb_FileVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_FileVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPbdb_FileVerbositySettingsController_parentEnvironment(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPbdb_FileVerbositySettingsController_parentSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPbdb_FileVerbositySettingsController_parentFileSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );

#endif
