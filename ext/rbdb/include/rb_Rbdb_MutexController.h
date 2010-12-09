#ifndef RB_Rbdb_MUTEX_CONTROLLER
	#define RB_Rbdb_MUTEX_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE	rb_Rbdb_MutexController_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE	rb_Rbdb_MutexController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE	rb_Rbdb_MutexController_settingsController(	VALUE	rb_mutex_controller );
	VALUE	rb_Rbdb_MutexController_parentEnvironment(	VALUE	rb_mutex_controller );
	VALUE	rb_Rbdb_MutexController_closeAllMutexes( VALUE	rb_mutex_controller );

#endif
