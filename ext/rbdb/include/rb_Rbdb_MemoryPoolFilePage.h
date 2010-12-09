#ifndef RB_Rbdb_MEMORY_POOL_FILE_PAGE
	#define RB_Rbdb_MEMORY_POOL_FILE_PAGE

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_MemoryPoolFilePage_new( int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_Rbdb_MemoryPoolFilePage_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_Rbdb_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page );
VALUE rb_Rbdb_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page );
VALUE rb_Rbdb_MemoryPoolFilePage_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page );
VALUE rb_Rbdb_MemoryPoolFilePage_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page );
VALUE rb_Rbdb_MemoryPoolFilePage_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page );
VALUE rb_Rbdb_MemoryPoolFilePage_parentMemoryPoolFilePageController(	VALUE	rb_memory_pool_file_page );
	VALUE rb_Rbdb_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page );

#endif
