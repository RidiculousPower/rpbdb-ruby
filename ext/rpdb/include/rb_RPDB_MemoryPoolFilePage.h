#ifndef RB_RPDB_MEMORY_POOL_FILE_PAGE
	#define RB_RPDB_MEMORY_POOL_FILE_PAGE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFilePage_new( int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_RPDB_MemoryPoolFilePage_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_RPDB_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page );
	VALUE rb_RPDB_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page );
	VALUE rb_RPDB_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page );

#endif
