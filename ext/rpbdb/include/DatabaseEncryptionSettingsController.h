#ifndef RB_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseEncryptionSettingsController();

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller );
	VALUE rb_RPbdb_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller );
		VALUE rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																				VALUE	rb_encryption_password );
		VALUE rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																				VALUE	rb_encryption_password );

#endif
