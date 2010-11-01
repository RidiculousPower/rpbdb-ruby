#ifndef RB_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MemoryPoolSettingsController();
VALUE rb_RPDB_MemoryPoolSettingsController_new(	int			argc,
																								VALUE*	args,
																								VALUE		rb_klass_self );
	VALUE rb_RPDB_MemoryPoolSettingsController_init(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
	VALUE rb_RPDB_MemoryPoolSettingsController_parentEnvironment(	VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_on( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_off( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnOn( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnOff( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_memoryMapping( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOn( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOff( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_doNotWriteToTemporaryBackingFile( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOn( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOff( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_removeFileWithLastReference( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOn( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOff( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_pagesizeFactorMismatchShouldFail( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOn( VALUE	rb_memory_pool_settings_controller );
		VALUE rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOff( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_fileSettingsController( VALUE	rb_memory_pool_settings_controller );
	VALUE rb_RPDB_MemoryPoolSettingsController_readWriteSettingsController( VALUE	rb_memory_pool_settings_controller );

#endif