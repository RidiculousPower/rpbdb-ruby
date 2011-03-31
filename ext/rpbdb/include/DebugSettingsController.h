#ifndef RB_RPBDB_DEBUG_SETTINGS_CONTROLLER
	#define RB_RPBDB_DEBUG_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DebugSettingsController();

VALUE rb_RPbdb_DebugSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPbdb_DebugSettingsController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
VALUE rb_RPbdb_DebugSettingsController_parentEnvironment(	VALUE	rb_debug_settings_controller );
VALUE rb_RPbdb_DebugSettingsController_parentSettingsController(	VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_openInLockdown( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnOpenInLockdownOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnOpenInLockdownOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_registerForRecovery( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRegisterForRecoveryOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnRegisterForRecoveryOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_prohibitPanic( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnProhibitPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnProhibitPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_panic( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnPanicOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnPanicOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_yieldCPUForStressTest( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnYieldCPUForStressTestOn( VALUE	rb_debug_settings_controller );
		VALUE rb_RPbdb_DebugSettingsController_turnYieldCPUForStressTestOff( VALUE	rb_debug_settings_controller );
	VALUE rb_RPbdb_DebugSettingsController_verbositySettingsController( VALUE	rb_debug_settings_controller );
VALUE rb_RPbdb_DebugSettingsController_parentDatabase(	VALUE	rb_debug_settings_controller );

#endif
