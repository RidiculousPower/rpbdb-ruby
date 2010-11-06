#ifndef RB_RPDB_THREAD_SETTINGS_CONTROLLER
	#define RB_RPDB_THREAD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_ThreadSettingsController();

VALUE rb_RPDB_ThreadSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPDB_ThreadSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self );
VALUE rb_RPDB_ThreadSettingsController_parentEnvironment(	VALUE	rb_thread_settings_controller );
VALUE rb_RPDB_ThreadSettingsController_parentSettingsController(	VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_on( VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_off( VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_turnOn( VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_turnOff( VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_threadCount( VALUE	rb_thread_settings_controller );
	VALUE rb_RPDB_ThreadSettingsController_setThreadCount(	VALUE	rb_thread_settings_controller, 
															VALUE	rb_thread_count );

#endif
