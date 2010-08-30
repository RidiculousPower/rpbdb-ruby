#ifndef RB_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MemoryPoolReadWriteSettingsController();

VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_new(	VALUE	klass,
														 VALUE	rb_parent_memory_pool_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_init(	VALUE	rb_memory_pool_read_write_settings_controller,
	VALUE	rb_parent_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_parentEnvironment(	VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxOpenFiles( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	VALUE	rb_memory_pool_read_write_settings_controller, 
																				VALUE	rb_max_open_files );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxSequentialWrites( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	VALUE	rb_memory_pool_read_write_settings_controller,
																						VALUE	rb_max_sequential_writes );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	VALUE	rb_memory_pool_read_write_settings_controller, 
																							VALUE	rb_time_to_sleep_before_next_write );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxMappedDBSize( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxMappedDBSize(	VALUE	rb_memory_pool_read_write_settings_controller, 
																					VALUE	rb_max_mapped_db_size );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( VALUE	rb_memory_pool_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( VALUE	rb_memory_pool_read_write_settings_controller );

#endif