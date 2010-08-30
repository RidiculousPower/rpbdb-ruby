#ifndef RB_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DebugVerbositySettingsController();

VALUE rb_RPDB_DebugVerbositySettingsController_new(	VALUE	klass,
													VALUE	rb_parent_debug_settings_controller );
VALUE rb_RPDB_DebugVerbositySettingsController_init(	VALUE	rb_debug_verbosity_settings_controller,
	VALUE	rb_parent_debug_settings_controller );
	VALUE rb_RPDB_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller );
	VALUE rb_RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller );

#endif
