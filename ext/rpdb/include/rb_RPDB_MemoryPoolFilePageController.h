#ifndef RB_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFilePageController_new(	VALUE	klass,
												VALUE	rb_parent_memory_pool_file );
VALUE rb_RPDB_MemoryPoolFilePageController_init(	VALUE	rb_memory_pool_file_page_controller,
	VALUE	rb_parent_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFilePageController_settingsController(	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPDB_MemoryPoolFilePageController_parentEnvironment(	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPDB_MemoryPoolFilePageController_retrievePageFromCache(	VALUE	rb_memory_pool_file_page_controller,
																		VALUE	rb_page_number_address	);

#endif
