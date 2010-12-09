#ifndef RB_Rbdb_MESSAGE_SETTINGS_CONTROLLER
	#define RB_Rbdb_MESSAGE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_MessageSettingsController();

VALUE rb_Rbdb_MessageSettingsController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_Rbdb_MessageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self );
VALUE rb_Rbdb_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller );
VALUE rb_Rbdb_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller );
	VALUE rb_Rbdb_MessageSettingsController_file( VALUE	rb_message_settings_controller );
	VALUE rb_Rbdb_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
														VALUE	rb_message_file );

#endif