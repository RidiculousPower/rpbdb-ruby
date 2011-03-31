#ifndef RB_RPBDB_LOG_CURSOR_CONTROLLER
	#define RB_RPBDB_LOG_CURSOR_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_RPbdb_LogCursorController_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_RPbdb_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller );
VALUE rb_RPbdb_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller );
VALUE rb_RPbdb_LogCursorController_parentLogController(	VALUE	rb_log_cursor_controller );
VALUE rb_RPbdb_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller );

#endif
