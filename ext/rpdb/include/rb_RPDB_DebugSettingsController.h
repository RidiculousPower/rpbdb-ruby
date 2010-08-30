#ifndef RB_RPDB_DEBUG_SETTINGS_CONTROLLER
	#define RB_RPDB_DEBUG_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DebugSettingsController();

VALUE rb_RPDB_DebugSettingsController_new(	VALUE	klass,
										   VALUE	rb_parent_settings_controller );
VALUE rb_RPDB_DebugSettingsController_init(	VALUE	rb_debug_settings_controller,
	VALUE	rb_parent_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_parentEnvironment(	VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_openInLockdown( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnOpenInLockdownOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnOpenInLockdownOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_registerForRecovery( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_prohibitPanic( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnProhibitPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnProhibitPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_panic( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_yieldCPUForStressTest( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPDB_DebugSettingsController_verbositySettingsController( VALUE	rb_debug_settings_controller );
VALUE rb_RPDB_DebugSettingsController_parentDatabase(	VALUE	rb_debug_settings_controller );

#endif
