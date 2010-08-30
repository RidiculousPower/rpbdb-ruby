#ifndef RB_RPDB_MUTEX
	#define RB_RPDB_MUTEX

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_Mutex_new(	VALUE	klass,
						 VALUE	rb_parent_mutex_controller );
VALUE rb_RPDB_Mutex_init(	VALUE	rb_mutex,
	VALUE	rb_parent_mutex_controller );
	VALUE rb_RPDB_Mutex_settingsController(	VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_parentEnvironment(	VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_open( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_close( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_lock( VALUE	rb_mutex );
	VALUE rb_RPDB_Mutex_unlock( VALUE	rb_mutex );

#endif
