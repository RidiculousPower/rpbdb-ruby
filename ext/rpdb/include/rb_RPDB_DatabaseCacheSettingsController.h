#ifndef RB_Rbdb_DATABASE_CACHE_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_CACHE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseCacheSettingsController();

VALUE rb_Rbdb_DatabaseCacheSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_Rbdb_DatabaseCacheSettingsController_parentEnvironment(	VALUE	rb_database_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCacheSettingsController_parentDatabase(	VALUE	rb_database_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCacheSettingsController_parentSettingsController(	VALUE	rb_database_cache_settings_controller );
VALUE rb_Rbdb_DatabaseCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cache_settings_controller );
	VALUE rb_Rbdb_DatabaseCacheSettingsController_maxSizeInBytes( VALUE	rb_database_cache_settings_controller );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_maxSizeInKBytes( VALUE	rb_database_cache_settings_controller );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_maxSizeInMBytes( VALUE	rb_database_cache_settings_controller );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_maxSizeInGBytes( VALUE	rb_database_cache_settings_controller );
	VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_database_cache_settings_controller, 
																		VALUE	rb_max_size_in_bytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_database_cache_settings_controller, 
																			VALUE	rb_max_size_kbytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_database_cache_settings_controller, 
																			VALUE	rb_max_size_mbytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_database_cache_settings_controller, 
																			VALUE	rb_max_size_gbytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																							VALUE	rb_max_size_gbytes, 
																							VALUE	rb_additional_max_size_mbytes, 
																							VALUE	rb_additional_max_size_kbytes, 
																							VALUE	rb_additional_max_size_in_bytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																						VALUE	rb_max_size_mbytes, 
																						VALUE	rb_additional_max_size_kbytes, 
																						VALUE	rb_additional_max_size_in_bytes );
		VALUE rb_Rbdb_DatabaseCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																				VALUE	rb_max_size_kbytes, 
																				VALUE	rb_additional_max_size_in_bytes );
	VALUE rb_Rbdb_DatabaseCacheSettingsController_numberCacheRegions( VALUE	rb_database_cache_settings_controller );
	VALUE rb_Rbdb_DatabaseCacheSettingsController_setNumberCacheRegions(	VALUE	rb_database_cache_settings_controller, 
																			VALUE	rb_number_cache_regions );
	VALUE rb_Rbdb_DatabaseCacheSettingsController_prioritySettingsController( VALUE	rb_database_cache_settings_controller );

#endif
