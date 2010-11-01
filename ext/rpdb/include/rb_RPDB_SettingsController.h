#ifndef RB_RPDB_SETTINGS_CONTROLLER
	#define RB_RPDB_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>


void Init_RPDB_SettingsController();

VALUE rb_RPDB_SettingsController_new(	int				argc,
																			VALUE*		args,
																			VALUE			rb_klass_self );
VALUE rb_RPDB_SettingsController_init(	int				argc,
																				VALUE*		args,
																				VALUE			rb_settings_controller_self );
	VALUE rb_RPDB_SettingsController_SHMkey( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_setSHMkey(	VALUE	rb_settings_controller, 
													VALUE	shm_key );
	VALUE rb_RPDB_SettingsController_debugSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_fileSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_threadSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_errorSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_messageSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_memoryPoolSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_transactionSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_lockSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_joinSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_replicationSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_databaseSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_mutexSettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_directorySettingsController( VALUE	rb_settings_controller );
	VALUE rb_RPDB_SettingsController_parentEnvironment(	VALUE	rb_settings_controller );

#endif