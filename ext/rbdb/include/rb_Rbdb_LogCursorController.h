#ifndef RB_Rbdb_LOG_CURSOR_CONTROLLER
	#define RB_Rbdb_LOG_CURSOR_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self );
VALUE rb_Rbdb_LogCursorController_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self );
	VALUE rb_Rbdb_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller );
VALUE rb_Rbdb_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller );
VALUE rb_Rbdb_LogCursorController_parentLogController(	VALUE	rb_log_cursor_controller );
VALUE rb_Rbdb_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller );

#endif
