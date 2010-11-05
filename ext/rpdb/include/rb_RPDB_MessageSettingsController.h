#ifndef RB_RPDB_MESSAGE_SETTINGS_CONTROLLER
	#define RB_RPDB_MESSAGE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MessageSettingsController();

VALUE rb_RPDB_MessageSettingsController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_RPDB_MessageSettingsController_init(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self );
VALUE rb_RPDB_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller );
VALUE rb_RPDB_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller );
	VALUE rb_RPDB_MessageSettingsController_file( VALUE	rb_message_settings_controller );
	VALUE rb_RPDB_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
														VALUE	rb_message_file );

#endif