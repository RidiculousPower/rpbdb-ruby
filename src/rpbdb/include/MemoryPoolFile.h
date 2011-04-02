#ifndef RB_RPBDB_MEMORY_POOL_FILE
	#define RB_RPBDB_MEMORY_POOL_FILE

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_MemoryPoolFile_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFile_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE rb_RPbdb_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file );
VALUE rb_RPbdb_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file );
VALUE rb_RPbdb_MemoryPoolFile_parentMemoryPoolController(	VALUE	rb_memory_pool_file );
VALUE rb_RPbdb_MemoryPoolFile_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file );
	VALUE rb_RPbdb_MemoryPoolFile_sync( VALUE	rb_memory_pool_file );
	VALUE rb_RPbdb_MemoryPoolFile_close( VALUE	rb_memory_pool_file );

#endif
