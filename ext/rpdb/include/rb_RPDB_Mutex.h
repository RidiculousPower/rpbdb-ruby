#ifndef RB_RPDB_MUTEX
	#define RB_RPDB_MUTEX

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_Mutex_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_RPDB_Mutex_init(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPDB_Mutex_settingsController(	VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_parentEnvironment(	VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_open( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_close( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_lock( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_unlock( VALUE	rb_mutex );

#endif
