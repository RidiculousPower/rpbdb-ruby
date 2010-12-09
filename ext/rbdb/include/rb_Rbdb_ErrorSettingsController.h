#ifndef RB_Rbdb_ERROR_SETTINGS_CONTROLLER
	#define RB_Rbdb_ERROR_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_ErrorSettingsController();

VALUE rb_Rbdb_ErrorSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_Rbdb_ErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self);
VALUE rb_Rbdb_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller );
VALUE rb_Rbdb_ErrorSettingsController_parentSettingsController(	VALUE	rb_error_settings_controller );
	VALUE rb_Rbdb_ErrorSettingsController_file( VALUE	rb_error_settings_controller );
		VALUE rb_Rbdb_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
														VALUE	rb_file );
	VALUE rb_Rbdb_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller );
		VALUE rb_Rbdb_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
															VALUE	rb_error_prefix );

#endif
