#ifndef RB_RPDB_MUTEX_CONTROLLER
	#define RB_RPDB_MUTEX_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE	rb_RPDB_MutexController_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE	rb_RPDB_MutexController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE	rb_RPDB_MutexController_settingsController(	VALUE	rb_mutex_controller );
	VALUE	rb_RPDB_MutexController_parentEnvironment(	VALUE	rb_mutex_controller );
	VALUE	rb_RPDB_MutexController_closeAllMutexes( VALUE	rb_mutex_controller );

#endif
