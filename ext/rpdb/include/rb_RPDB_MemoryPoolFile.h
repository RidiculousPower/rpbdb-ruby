#ifndef RB_RPDB_MEMORY_POOL_FILE
	#define RB_RPDB_MEMORY_POOL_FILE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFile_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolFile_init(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE rb_RPDB_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_sync( VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_close( VALUE	rb_memory_pool_file );

#endif
