#ifndef RB_RPDB_LOG_CURSOR_CONTROLLER
	#define RB_RPDB_LOG_CURSOR_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_RPDB_LogCursorController_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_RPDB_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller );
	VALUE rb_RPDB_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller );
VALUE rb_RPDB_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller );

#endif
