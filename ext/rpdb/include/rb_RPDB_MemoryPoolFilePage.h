#ifndef RB_RPDB_MEMORY_POOL_FILE_PAGE
	#define RB_RPDB_MEMORY_POOL_FILE_PAGE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_MemoryPoolFilePage_new( VALUE	klass,
									  VALUE	rb_memory_pool_file_page_controller );
VALUE rb_RPDB_MemoryPoolFilePage_init( VALUE	rb_memory_pool_file_page,
	VALUE	rb_memory_pool_file_page_controller );
	VALUE rb_RPDB_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page );
	VALUE rb_RPDB_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page );
	VALUE rb_RPDB_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page );

#endif
