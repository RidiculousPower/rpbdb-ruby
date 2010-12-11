#ifndef RB_RBDB_MEMORY_POOL_CONTROLLER
	#define RB_RBDB_MEMORY_POOL_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_MemoryPoolController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_Rbdb_MemoryPoolController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_Rbdb_MemoryPoolController_settingsController(	VALUE	rb_memory_pool_controller );
	VALUE rb_Rbdb_MemoryPoolController_parentEnvironment(	VALUE	rb_memory_pool_controller );
	VALUE rb_Rbdb_MemoryPoolController_trickleClean(	VALUE	rb_memory_pool_controller, 
														VALUE	rb_percent_of_pages_to_clean );
	VALUE rb_Rbdb_MemoryPoolController_flush(	VALUE	rb_memory_pool_controller, 
												VALUE	rb_write_all_records_before_lsn );
	VALUE rb_Rbdb_MemoryPoolController_fileController( VALUE	rb_memory_pool_controller );


#endif
