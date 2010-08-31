#ifndef RB_RPDB_MUTEX_CONTROLLER
	#define RB_RPDB_MUTEX_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE	rb_RPDB_MutexController_new(	VALUE	klass,
									 VALUE	rb_parent_environment );
VALUE	rb_RPDB_MutexController_init(	VALUE	rb_mutex_controller,
	VALUE	rb_parent_environment );
	VALUE	rb_RPDB_MutexController_settingsController(	VALUE	rb_mutex_controller );
	VALUE	rb_RPDB_MutexController_parentEnvironment(	VALUE	rb_mutex_controller );
	VALUE	rb_RPDB_MutexController_closeAllMutexes( VALUE	rb_mutex_controller );

#endif
