#ifndef RB_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseEncryptionSettingsController();

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller );
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller );
	VALUE rb_Rbdb_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller );
		VALUE rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																				VALUE	rb_encryption_password );
		VALUE rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																				VALUE	rb_encryption_password );

#endif
