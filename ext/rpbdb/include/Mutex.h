#ifndef RB_RPBDB_MUTEX
	#define RB_RPBDB_MUTEX

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_Mutex_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_RPbdb_Mutex_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPbdb_Mutex_settingsController(	VALUE	rb_mutex );
VALUE rb_RPbdb_Mutex_parentEnvironment(	VALUE	rb_mutex );
VALUE rb_RPbdb_Mutex_parentMutexController(	VALUE	rb_mutex );
	VALUE rb_RPbdb_Mutex_open( VALUE	rb_mutex );
	VALUE rb_RPbdb_Mutex_close( VALUE	rb_mutex );
	VALUE rb_RPbdb_Mutex_lock( VALUE	rb_mutex );
	VALUE rb_RPbdb_Mutex_unlock( VALUE	rb_mutex );

#endif
