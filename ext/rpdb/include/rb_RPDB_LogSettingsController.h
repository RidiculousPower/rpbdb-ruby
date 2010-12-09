#ifndef RB_Rbdb_LOG_SETTINGS_CONTROLLER
	#define RB_Rbdb_LOG_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_LogSettingsController();

VALUE rb_Rbdb_LogSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_Rbdb_LogSettingsController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
VALUE rb_Rbdb_LogSettingsController_parentEnvironment(	VALUE	rb_log_settings_controller );
VALUE rb_Rbdb_LogSettingsController_parentSettingsController(	VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_on( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnOn( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_off( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_disableSystemBuffering( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnDisableSystemBufferingOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnDisableSystemBufferingOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_flushBeforeReturnFromWrite( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnFlushBeforeReturnFromWriteOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnFlushBeforeReturnFromWriteOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_autoremoveLogs( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnAutoremoveLogsOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnAutoremoveOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_logInMemory( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnLogInMemoryOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnLogInMemoryOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_zeroAtCreation( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnZeroAtCreationOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnZeroAtCreationOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_forceFlushAfterRecordWrite( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnForceFlushAfterRecordWriteOn( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_turnForceFlushAfterRecordWriteOff( VALUE	rb_log_settings_controller );
	VALUE rb_Rbdb_LogSettingsController_bufferSize( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_setBufferSize(	VALUE	rb_log_settings_controller, 
															VALUE	rb_buffer_size );
	VALUE rb_Rbdb_LogSettingsController_directory( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_setDirectory(	VALUE	rb_log_settings_controller, 
															VALUE	rb_directory );
	VALUE rb_Rbdb_LogSettingsController_mode( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_setMode(	VALUE	rb_log_settings_controller, 
														VALUE	rb_mode );
	VALUE rb_Rbdb_LogSettingsController_maxLogSize( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_setMaxLogSize(	VALUE	rb_log_settings_controller, 
															VALUE	rb_max_size );
	VALUE rb_Rbdb_LogSettingsController_maxRegionSize( VALUE	rb_log_settings_controller );
		VALUE rb_Rbdb_LogSettingsController_setMaxRegionSize(	VALUE	rb_log_settings_controller, 
																VALUE	rb_max_region_size );

#endif