#ifndef RB_RBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DebugVerbositySettingsController();

VALUE rb_Rbdb_DebugVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_Rbdb_DebugVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_Rbdb_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_Rbdb_DebugVerbositySettingsController_parentSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
VALUE rb_Rbdb_DebugVerbositySettingsController_parentDebugSettingsController(	VALUE	rb_debug_verbosity_settings_controller );
	VALUE rb_Rbdb_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller );
		VALUE rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller );

#endif
