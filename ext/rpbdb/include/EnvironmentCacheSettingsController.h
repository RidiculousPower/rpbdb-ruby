#ifndef RB_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER
	#define RB_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_EnvironmentCacheSettingsController();

VALUE rb_RPbdb_EnvironmentCacheSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_RPbdb_EnvironmentCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_RPbdb_EnvironmentCacheSettingsController_parentEnvironment(	VALUE	rb_environment_cache_settings_controller );
VALUE rb_RPbdb_EnvironmentCacheSettingsController_parentSettingsController(	VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_buffering( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOn( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOff( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInKBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInMBytes( VALUE	rb_environment_cache_settings_controller );
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInGBytes( VALUE	rb_environment_cache_settings_controller );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_in_bytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_kbytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_mbytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_environment_cache_settings_controller, 
																				VALUE	rb_max_size_gbytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																								VALUE	rb_max_size_gbytes, 
																								VALUE	rb_additional_max_size_mbytes, 
																								VALUE	rb_additional_max_size_kbytes, 
																								VALUE	rb_additional_max_size_bytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																							VALUE	rb_max_size_mbytes, 
																							VALUE	rb_additional_max_size_kbytes, 
																							VALUE	rb_additional_max_size_bytes );
		VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																			  		VALUE	rb_max_size_kbytes, 
																			  		VALUE	rb_additional_max_size_bytes );
void Init_rb_RPbdb_EnvironmentCacheSettingsController();

#endif
