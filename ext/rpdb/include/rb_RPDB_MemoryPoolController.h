#ifndef RB_RPDB_MEMORY_POOL_CONTROLLER
	#define RB_RPDB_MEMORY_POOL_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolController_init(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_RPDB_MemoryPoolController_settingsController(	VALUE	rb_memory_pool_controller );
	VALUE rb_RPDB_MemoryPoolController_parentEnvironment(	VALUE	rb_memory_pool_controller );
	VALUE rb_RPDB_MemoryPoolController_trickleClean(	VALUE	rb_memory_pool_controller, 
														VALUE	rb_percent_of_pages_to_clean );
	VALUE rb_RPDB_MemoryPoolController_flush(	VALUE	rb_memory_pool_controller, 
												VALUE	rb_write_all_records_before_lsn );
	VALUE rb_RPDB_MemoryPoolController_fileController( VALUE	rb_memory_pool_controller );


#endif
