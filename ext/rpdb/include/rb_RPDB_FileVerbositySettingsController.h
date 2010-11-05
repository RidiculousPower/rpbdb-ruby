#ifndef RB_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_FileVerbositySettingsController();

VALUE rb_RPDB_FileVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPDB_FileVerbositySettingsController_init(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPDB_FileVerbositySettingsController_parentEnvironment(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPDB_FileVerbositySettingsController_parentSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPDB_FileVerbositySettingsController_parentFileSettingsController(	VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );
VALUE rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( VALUE	rb_file_verbosity_settings_controller );
	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( VALUE	rb_file_verbosity_settings_controller );

#endif
