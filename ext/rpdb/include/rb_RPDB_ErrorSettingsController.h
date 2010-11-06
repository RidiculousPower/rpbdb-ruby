#ifndef RB_RPDB_ERROR_SETTINGS_CONTROLLER
	#define RB_RPDB_ERROR_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_ErrorSettingsController();

VALUE rb_RPDB_ErrorSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPDB_ErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self);
VALUE rb_RPDB_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller );
VALUE rb_RPDB_ErrorSettingsController_parentSettingsController(	VALUE	rb_error_settings_controller );
	VALUE rb_RPDB_ErrorSettingsController_file( VALUE	rb_error_settings_controller );
		VALUE rb_RPDB_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
														VALUE	rb_file );
	VALUE rb_RPDB_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller );
		VALUE rb_RPDB_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
															VALUE	rb_error_prefix );

#endif
