#ifndef RB_RPBDB_MUTEX_CONTROLLER
	#define RB_RPBDB_MUTEX_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE	rb_RPbdb_MutexController_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE	rb_RPbdb_MutexController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE	rb_RPbdb_MutexController_settingsController(	VALUE	rb_mutex_controller );
	VALUE	rb_RPbdb_MutexController_parentEnvironment(	VALUE	rb_mutex_controller );
	VALUE	rb_RPbdb_MutexController_closeAllMutexes( VALUE	rb_mutex_controller );

#endif
