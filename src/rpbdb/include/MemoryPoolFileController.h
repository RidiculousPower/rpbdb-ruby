#ifndef RB_RPBDB_MEMORY_POOL_FILE_CONTROLLER
	#define RB_RPBDB_MEMORY_POOL_FILE_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_MemoryPoolFileController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFileController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self );
	VALUE rb_RPbdb_MemoryPoolFileController_settingsController(	VALUE	rb_memory_pool_file_controller );
VALUE rb_RPbdb_MemoryPoolFileController_parentEnvironment(	VALUE	rb_memory_pool_file_controller );
VALUE rb_RPbdb_MemoryPoolFileController_parentMemoryPoolController(	VALUE	rb_memory_pool_file_controller );
	VALUE rb_RPbdb_MemoryPoolFileController_createFile( VALUE	rb_memory_pool_file_controller );
	VALUE rb_RPbdb_MemoryPoolFileController_openFile(	VALUE	rb_memory_pool_file_controller,
	 													VALUE	rb_file_path,
														//	This should be broken down into functions that specify the type of mode, probably
														VALUE	rb_chmod_mode,
														//	How do we determine how large pagesize should be?
														VALUE	rb_pagesize_in_bytes );

#endif