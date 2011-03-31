#ifndef RB_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseVerbositySettingsController();

VALUE rb_RPbdb_DatabaseVerbositySettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentSettingsController(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verbosity_settings_controller );
	VALUE rb_RPbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller );
		VALUE rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller );
		VALUE rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller );

#endif
