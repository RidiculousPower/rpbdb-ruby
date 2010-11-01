#ifndef RB_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFilePageController_new(	int			argc,
																								VALUE*	args,
																								VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolFilePageController_init(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self );
	VALUE rb_RPDB_MemoryPoolFilePageController_settingsController(	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPDB_MemoryPoolFilePageController_parentEnvironment(	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPDB_MemoryPoolFilePageController_retrievePageFromCache(	VALUE	rb_memory_pool_file_page_controller,
																		VALUE	rb_page_number_address	);

#endif
