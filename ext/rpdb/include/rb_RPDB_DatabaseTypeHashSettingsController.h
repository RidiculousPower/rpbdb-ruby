#ifndef RB_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseTypeHashSettingsController();

VALUE rb_RPDB_DatabaseTypeHashSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseTypeHashSettingsController_init(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self);
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																	VALUE	rb_number_of_elements );
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller );
	VALUE rb_RPDB_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																			VALUE	rb_density );

#endif
