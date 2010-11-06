#ifndef RB_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseVerbositySettingsController();

VALUE rb_RPDB_DatabaseVerbositySettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentSettingsController(	VALUE	rb_database_verbosity_settings_controller );
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verbosity_settings_controller );
	VALUE rb_RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller );
		VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller );
		VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller );

#endif
