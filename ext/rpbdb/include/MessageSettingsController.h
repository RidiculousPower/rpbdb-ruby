#ifndef RB_RPBDB_MESSAGE_SETTINGS_CONTROLLER
	#define RB_RPBDB_MESSAGE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_MessageSettingsController();

VALUE rb_RPbdb_MessageSettingsController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_RPbdb_MessageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self );
VALUE rb_RPbdb_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller );
VALUE rb_RPbdb_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller );
	VALUE rb_RPbdb_MessageSettingsController_file( VALUE	rb_message_settings_controller );
	VALUE rb_RPbdb_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
														VALUE	rb_message_file );

#endif