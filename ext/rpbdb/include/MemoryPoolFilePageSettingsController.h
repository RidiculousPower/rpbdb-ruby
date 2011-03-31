#ifndef MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER
	#define MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_MemoryPoolFilePageSettingsController();

VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( VALUE	rb_memory_pool_file_page_settings_controller );

#endif