#ifndef RB_RPBDB_MEMORY_POOL_FILE_PAGE
	#define RB_RPBDB_MEMORY_POOL_FILE_PAGE

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_MemoryPoolFilePage_new( int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_RPbdb_MemoryPoolFilePage_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_RPbdb_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page );
VALUE rb_RPbdb_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page );
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page );
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page );
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page );
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFilePageController(	VALUE	rb_memory_pool_file_page );
	VALUE rb_RPbdb_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page );

#endif
