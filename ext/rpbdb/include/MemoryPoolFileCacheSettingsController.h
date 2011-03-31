#ifndef RB_RPBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER
	#define RB_RPBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

	void Init_rb_RPbdb_MemoryPoolFileCacheSettingsController();

	VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self );
	VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );

VALUE rb_RPbdb_MemoryPoolFileCacheSettingsController_prioritySettingsController( VALUE	rb_memory_pool_file_cache_settings_controller );

#endif