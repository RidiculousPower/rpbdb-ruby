#ifndef RB_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_MemoryPoolFileCachePrioritySettingsController();

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileCacheSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_currentPriority( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_low( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_default( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_high( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );

#endif