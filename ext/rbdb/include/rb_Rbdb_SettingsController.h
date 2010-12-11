#ifndef RB_RBDB_SETTINGS_CONTROLLER
	#define RB_RBDB_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>


void Init_rb_Rbdb_SettingsController();

VALUE rb_Rbdb_SettingsController_new(	int				argc,
																			VALUE*		args,
																			VALUE			rb_klass_self );
VALUE rb_Rbdb_SettingsController_initialize(	int				argc,
																				VALUE*		args,
																				VALUE			rb_settings_controller_self );

	VALUE rb_Rbdb_SettingsController_parentEnvironment(	VALUE	rb_settings_controller );

	VALUE rb_Rbdb_SettingsController_SHMkey( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_setSHMkey(	VALUE	rb_settings_controller, 
													VALUE	shm_key );
	VALUE rb_Rbdb_SettingsController_debugSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_fileSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_threadSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_errorSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_messageSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_memoryPoolSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_transactionSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_lockSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_logSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_joinSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_replicationSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_databaseSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_mutexSettingsController( VALUE	rb_settings_controller );
	VALUE rb_Rbdb_SettingsController_directorySettingsController( VALUE	rb_settings_controller );
VALUE rb_Rbdb_SettingsController_replicationSettingsController( VALUE	rb_settings_controller );

#endif