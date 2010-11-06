#ifndef MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER
	#define MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_MemoryPoolFilePageSettingsController();

VALUE rb_RPDB_MemoryPoolFilePageSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( VALUE	rb_memory_pool_file_page_settings_controller );
	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( VALUE	rb_memory_pool_file_page_settings_controller );
		VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( VALUE	rb_memory_pool_file_page_settings_controller );

#endif