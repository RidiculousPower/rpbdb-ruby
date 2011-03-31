#ifndef RB_RPBDB_SETTINGS_CONTROLLER
	#define RB_RPBDB_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>


void Init_rb_RPbdb_SettingsController();

VALUE rb_RPbdb_SettingsController_new(	int				argc,
																			VALUE*		args,
																			VALUE			rb_klass_self );
VALUE rb_RPbdb_SettingsController_initialize(	int				argc,
																				VALUE*		args,
																				VALUE			rb_settings_controller_self );

	VALUE rb_RPbdb_SettingsController_parentEnvironment(	VALUE	rb_settings_controller );

	VALUE rb_RPbdb_SettingsController_SHMkey( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_setSHMkey(	VALUE	rb_settings_controller, 
													VALUE	shm_key );
	VALUE rb_RPbdb_SettingsController_debugSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_fileSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_threadSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_errorSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_messageSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_memoryPoolSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_transactionSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_lockSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_joinSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_replicationSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_databaseSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_mutexSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPbdb_SettingsController_directorySettingsController( VALUE	rb_settings_controller );
VALUE rb_RPbdb_SettingsController_replicationSettingsController( VALUE	rb_settings_controller );

#endif