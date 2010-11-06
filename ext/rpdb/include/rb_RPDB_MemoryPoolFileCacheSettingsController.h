#ifndef RB_RPDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

	void Init_RPDB_MemoryPoolFileCacheSettingsController();

	VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self );
	VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );
VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller );

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_prioritySettingsController( VALUE	rb_memory_pool_file_cache_settings_controller );

#endif