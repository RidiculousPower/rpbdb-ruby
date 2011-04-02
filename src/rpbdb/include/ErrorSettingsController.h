#ifndef RB_RPBDB_ERROR_SETTINGS_CONTROLLER
	#define RB_RPBDB_ERROR_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_ErrorSettingsController();

VALUE rb_RPbdb_ErrorSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPbdb_ErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self);
VALUE rb_RPbdb_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller );
VALUE rb_RPbdb_ErrorSettingsController_parentSettingsController(	VALUE	rb_error_settings_controller );
	VALUE rb_RPbdb_ErrorSettingsController_file( VALUE	rb_error_settings_controller );
		VALUE rb_RPbdb_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
														VALUE	rb_file );
	VALUE rb_RPbdb_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller );
		VALUE rb_RPbdb_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
															VALUE	rb_error_prefix );

#endif
