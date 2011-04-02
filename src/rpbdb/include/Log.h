#ifndef RB_RPBDB_LOG
	#define RB_RPBDB_LOG
	
	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_Log_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPbdb_Log_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_RPbdb_Log_settingsController(	VALUE	rb_log );
VALUE rb_RPbdb_Log_parentEnvironment(	VALUE	rb_log );
VALUE rb_RPbdb_Log_parentLogController(	VALUE	rb_log );
VALUE rb_RPbdb_Log_parentLogCursorController(	VALUE	rb_log );
VALUE rb_RPbdb_Log_parentLogCursor(	VALUE	rb_log );
	VALUE rb_RPbdb_Log_logRecord( VALUE	rb_log );
	VALUE rb_RPbdb_Log_logSequenceNumber( VALUE	rb_log );
	VALUE rb_RPbdb_Log_filename( VALUE	rb_log );

#endif
