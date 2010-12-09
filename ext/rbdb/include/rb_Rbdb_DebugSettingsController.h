#ifndef RB_Rbdb_DEBUG_SETTINGS_CONTROLLER
	#define RB_Rbdb_DEBUG_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DebugSettingsController();

VALUE rb_Rbdb_DebugSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_Rbdb_DebugSettingsController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
VALUE rb_Rbdb_DebugSettingsController_parentEnvironment(	VALUE	rb_debug_settings_controller );
VALUE rb_Rbdb_DebugSettingsController_parentSettingsController(	VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_openInLockdown( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnOpenInLockdownOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnOpenInLockdownOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_registerForRecovery( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRegisterForRecoveryOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnRegisterForRecoveryOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_prohibitPanic( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnProhibitPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnProhibitPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_panic( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_yieldCPUForStressTest( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnYieldCPUForStressTestOn( VALUE	rb_debug_settings_controller );
		VALUE rb_Rbdb_DebugSettingsController_turnYieldCPUForStressTestOff( VALUE	rb_debug_settings_controller );
	VALUE rb_Rbdb_DebugSettingsController_verbositySettingsController( VALUE	rb_debug_settings_controller );
VALUE rb_Rbdb_DebugSettingsController_parentDatabase(	VALUE	rb_debug_settings_controller );

#endif
