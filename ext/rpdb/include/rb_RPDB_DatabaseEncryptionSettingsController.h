#ifndef RB_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseEncryptionSettingsController();

VALUE rb_RPDB_DatabaseEncryptionSettingsController_new(	VALUE	klass,
														VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseEncryptionSettingsController_init(	VALUE	rb_database_encryption_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller );
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller );
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller );
		VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																				VALUE	rb_encryption_password );
		VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																				VALUE	rb_encryption_password );

#endif
