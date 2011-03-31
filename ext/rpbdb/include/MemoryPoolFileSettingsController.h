#ifndef RB_RPBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER
	#define RB_RPBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_MemoryPoolFileSettingsController();

VALUE rb_RPbdb_MemoryPoolFileSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFileSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_RPbdb_MemoryPoolFileSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_settings_controller );
VALUE rb_RPbdb_MemoryPoolFileSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_settings_controller );
VALUE rb_RPbdb_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_createWithInitialNullBytesNumbering( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setCreateWithInitialNullBytesNumbering( VALUE	rb_memory_pool_file_settings_controller, 
																									VALUE	rb_initial_null_bytes );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_fileID( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setFileID(	VALUE	rb_memory_pool_file_settings_controller, 
																	VALUE	rb_file_id );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_fileType( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setFileType(	VALUE	rb_memory_pool_file_settings_controller, 
																		VALUE	rb_file_type );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_logSequenceNumberOffset( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setLogSequenceNumberOffset(	VALUE	rb_memory_pool_file_settings_controller, 
																					VALUE	rb_log_sequence_number_offset );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_maxFileSizeInBytes( VALUE	rb_memory_pool_file_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_maxFileSizeInKBytes( VALUE	rb_memory_pool_file_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_maxFileSizeInMBytes( VALUE	rb_memory_pool_file_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_maxFileSizeInGBytes( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setMaxFileSizeInBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																				VALUE	rb_max_file_size_in_bytes );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setMaxFileSizeInKBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																				VALUE	rb_size_in_kbytes );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setMaxFileSizeInMBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																				VALUE	rb_size_in_mbytes );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setMaxFileSizeInGBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																				VALUE	rb_size_in_gbytes );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_cookie( VALUE	rb_memory_pool_file_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFileSettingsController_setCookie(	VALUE	rb_memory_pool_file_settings_controller, 
																	VALUE	rb_cookie );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_cacheSettingsController( VALUE	rb_memory_pool_file_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFileSettingsController_pageSettingsController( VALUE	rb_memory_pool_file_settings_controller );

#endif
