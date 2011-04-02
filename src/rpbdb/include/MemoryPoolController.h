#ifndef RB_RPBDB_MEMORY_POOL_CONTROLLER
	#define RB_RPBDB_MEMORY_POOL_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_MemoryPoolController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_RPbdb_MemoryPoolController_settingsController(	VALUE	rb_memory_pool_controller );
	VALUE rb_RPbdb_MemoryPoolController_parentEnvironment(	VALUE	rb_memory_pool_controller );
	VALUE rb_RPbdb_MemoryPoolController_trickleClean(	VALUE	rb_memory_pool_controller, 
														VALUE	rb_percent_of_pages_to_clean );
	VALUE rb_RPbdb_MemoryPoolController_flush(	VALUE	rb_memory_pool_controller, 
												VALUE	rb_write_all_records_before_lsn );
	VALUE rb_RPbdb_MemoryPoolController_fileController( VALUE	rb_memory_pool_controller );


#endif
