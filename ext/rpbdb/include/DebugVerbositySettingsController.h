#ifndef RB_RPBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DebugVerbositySettingsController();

VALUE rb_RPbdb_DebugVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_DebugVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPbdb_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_RPbdb_DebugVerbositySettingsController_parentSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_RPbdb_DebugVerbositySettingsController_parentDebugSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
	VALUE rb_RPbdb_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller );

#endif
