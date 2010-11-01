#ifndef RB_RPDB_LOG_SETTINGS_CONTROLLER
	#define RB_RPDB_LOG_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_LogSettingsController();

VALUE rb_RPDB_LogSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPDB_LogSettingsController_init(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_RPDB_LogSettingsController_parentEnvironment(	VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_on( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnOn( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_off( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_disableSystemBuffering( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnDisableSystemBufferingOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnDisableSystemBufferingOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_flushBeforeReturnFromWrite( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_autoremoveLogs( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnAutoremoveLogsOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnAutoremoveOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_logInMemory( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnLogInMemoryOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnLogInMemoryOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_zeroAtCreation( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnZeroAtCreationOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnZeroAtCreationOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_forceFlushAfterRecordWrite( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOn( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOff( VALUE	rb_log_settings_controller );
	VALUE rb_RPDB_LogSettingsController_bufferSize( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_setBufferSize(	VALUE	rb_log_settings_controller, 
															VALUE	rb_buffer_size );
	VALUE rb_RPDB_LogSettingsController_directory( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_setDirectory(	VALUE	rb_log_settings_controller, 
															VALUE	rb_directory );
	VALUE rb_RPDB_LogSettingsController_mode( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_setMode(	VALUE	rb_log_settings_controller, 
														VALUE	rb_mode );
	VALUE rb_RPDB_LogSettingsController_maxLogSize( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_setMaxLogSize(	VALUE	rb_log_settings_controller, 
															VALUE	rb_max_size );
	VALUE rb_RPDB_LogSettingsController_maxRegionSize( VALUE	rb_log_settings_controller );
		VALUE rb_RPDB_LogSettingsController_setMaxRegionSize(	VALUE	rb_log_settings_controller, 
																VALUE	rb_max_region_size );

#endif