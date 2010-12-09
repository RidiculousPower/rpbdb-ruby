#ifndef RB_Rbdb_MEMORY_POOL_FILE
	#define RB_Rbdb_MEMORY_POOL_FILE

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_MemoryPoolFile_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_Rbdb_MemoryPoolFile_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE rb_Rbdb_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file );
VALUE rb_Rbdb_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file );
VALUE rb_Rbdb_MemoryPoolFile_parentMemoryPoolController(	VALUE	rb_memory_pool_file );
VALUE rb_Rbdb_MemoryPoolFile_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file );
	VALUE rb_Rbdb_MemoryPoolFile_sync( VALUE	rb_memory_pool_file );
	VALUE rb_Rbdb_MemoryPoolFile_close( VALUE	rb_memory_pool_file );

#endif
