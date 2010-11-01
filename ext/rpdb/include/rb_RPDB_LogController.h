#ifndef RB_RPDB_LOG_CONTROLLER
	#define RB_RPDB_LOG_CONTROLLER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LogController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPDB_LogController_init(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self );
	VALUE rb_RPDB_LogController_settingsController(	VALUE	rb_log_controller );
	VALUE rb_RPDB_LogController_parentEnvironment(	VALUE	rb_log_controller );
	VALUE rb_RPDB_LogController_flushLogsToDisk(	VALUE	rb_log_controller,
	 												VALUE	rb_log_sequence_number );
	VALUE rb_RPDB_LogController_appendLogRecord(	VALUE	rb_log_controller,
	 												VALUE	rb_log_record );
	VALUE rb_RPDB_LogController_cursorController( VALUE	rb_log_controller );
VALUE rb_RPDB_LogController_appendStringToCurrentLog(	int			argc,
																											VALUE*	args,
																											VALUE	rb_log_controller );

#endif
