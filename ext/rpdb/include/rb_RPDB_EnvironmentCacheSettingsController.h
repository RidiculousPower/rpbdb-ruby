#ifndef RB_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER
	#define RB_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_EnvironmentCacheSettingsController();

VALUE rb_RPDB_EnvironmentCacheSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_RPDB_EnvironmentCacheSettingsController_init(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_parentEnvironment(	VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_buffering( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOn( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOff( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_in_bytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_kbytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_mbytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_gbytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																								VALUE	rb_max_size_gbytes, 
																								VALUE	rb_additional_max_size_mbytes, 
																								VALUE	rb_additional_max_size_kbytes, 
																								VALUE	rb_additional_max_size_bytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																							VALUE	rb_max_size_mbytes, 
																							VALUE	rb_additional_max_size_kbytes, 
																							VALUE	rb_additional_max_size_bytes );
		VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																			  		VALUE	rb_max_size_kbytes, 
																			  		VALUE	rb_additional_max_size_bytes );
void Init_RPDB_EnvironmentCacheSettingsController();

#endif
