#ifndef RB_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseTypeHashSettingsController();

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self);
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentSettingsController(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																	VALUE	rb_number_of_elements );
	VALUE rb_Rbdb_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																			VALUE	rb_density );

#endif
