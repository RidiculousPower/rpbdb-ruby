#ifndef RB_RPDB_MEMORY_POOL_FILE
	#define RB_RPDB_MEMORY_POOL_FILE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFile_new(	VALUE	klass,
								  VALUE	rb_parent_memory_pool_file_controller );
VALUE rb_RPDB_MemoryPoolFile_init(	VALUE	rb_memory_pool_file,
	VALUE	rb_parent_memory_pool_file_controller );
	VALUE rb_RPDB_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_sync( VALUE	rb_memory_pool_file );
	VALUE rb_RPDB_MemoryPoolFile_close( VALUE	rb_memory_pool_file );

#endif
