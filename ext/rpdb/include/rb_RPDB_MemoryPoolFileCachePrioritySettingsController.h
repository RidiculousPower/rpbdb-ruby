#ifndef RB_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MemoryPoolFileCachePrioritySettingsController();

VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_new(	VALUE	klass,
																 VALUE	rb_parent_memory_pool_file_settings_controller );
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_init(	VALUE	rb_memory_pool_file_cache_priority_settings_controller,
	VALUE	rb_parent_memory_pool_file_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_currentPriority( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_low( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_default( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_high( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );
		VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller );

#endif