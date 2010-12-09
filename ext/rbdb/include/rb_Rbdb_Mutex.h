#ifndef RB_Rbdb_MUTEX
	#define RB_Rbdb_MUTEX

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_Mutex_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_Rbdb_Mutex_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_Rbdb_Mutex_settingsController(	VALUE	rb_mutex );
VALUE rb_Rbdb_Mutex_parentEnvironment(	VALUE	rb_mutex );
VALUE rb_Rbdb_Mutex_parentMutexController(	VALUE	rb_mutex );
	VALUE rb_Rbdb_Mutex_open( VALUE	rb_mutex );
	VALUE rb_Rbdb_Mutex_close( VALUE	rb_mutex );
	VALUE rb_Rbdb_Mutex_lock( VALUE	rb_mutex );
	VALUE rb_Rbdb_Mutex_unlock( VALUE	rb_mutex );

#endif
