#ifndef RB_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MemoryPoolReadWriteSettingsController();

VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_parentEnvironment(	VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_parentSettingsController(	VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxOpenFiles( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	VALUE	rb_memory_pool_record_read_write_settings_controller, 
																				VALUE	rb_max_open_files );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxSequentialWrites( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	VALUE	rb_memory_pool_record_read_write_settings_controller,
																						VALUE	rb_max_sequential_writes );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	VALUE	rb_memory_pool_record_read_write_settings_controller, 
																							VALUE	rb_time_to_sleep_before_next_write );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxMappedDatabaseSize( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxMappedDatabaseSize(	VALUE	rb_memory_pool_record_read_write_settings_controller, 
																					VALUE	rb_max_mapped_db_size );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( VALUE	rb_memory_pool_record_read_write_settings_controller );
		VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( VALUE	rb_memory_pool_record_read_write_settings_controller );

VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_doNotWriteToTemporaryBackingFile( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_useSystemMemoryForStorage( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_applicationHasExclusiveAccess( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_applicationAllocatesMemory( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_memory_pool_read_write_settings_controller );
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_databaseFreesMemory( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_memory_pool_read_write_settings_controller );
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_memory_pool_read_write_settings_controller );


#endif