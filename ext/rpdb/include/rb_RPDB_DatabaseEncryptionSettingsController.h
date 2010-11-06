#ifndef RB_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseEncryptionSettingsController();

VALUE rb_RPDB_DatabaseEncryptionSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller );
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller );
		VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																				VALUE	rb_encryption_password );
		VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																				VALUE	rb_encryption_password );

#endif
