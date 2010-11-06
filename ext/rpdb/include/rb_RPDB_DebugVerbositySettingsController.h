#ifndef RB_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DebugVerbositySettingsController();

VALUE rb_RPDB_DebugVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPDB_DebugVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPDB_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_RPDB_DebugVerbositySettingsController_parentSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_RPDB_DebugVerbositySettingsController_parentDebugSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
	VALUE rb_RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller );

#endif
