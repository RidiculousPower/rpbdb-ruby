#ifndef RB_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseTypeHashSettingsController();

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self);
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentSettingsController(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_hash_settings_controller );
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																	VALUE	rb_number_of_elements );
	VALUE rb_RPbdb_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																			VALUE	rb_density );

#endif
