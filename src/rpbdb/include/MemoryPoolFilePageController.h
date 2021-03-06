#ifndef RB_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER
	#define RB_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_MemoryPoolFilePageController_new(	int			argc,
																								VALUE*	args,
																								VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFilePageController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self );
	VALUE rb_RPbdb_MemoryPoolFilePageController_settingsController(	VALUE	rb_memory_pool_file_page_controller );
VALUE rb_RPbdb_MemoryPoolFilePageController_parentEnvironment(	VALUE	rb_memory_pool_file_page_controller );
VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page_controller );
VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page_controller );
VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPbdb_MemoryPoolFilePageController_retrievePageFromCache(	VALUE	rb_memory_pool_file_page_controller,
																		VALUE	rb_page_number_address	);

#endif
