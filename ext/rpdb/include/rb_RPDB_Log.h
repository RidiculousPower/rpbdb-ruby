#ifndef RB_RPDB_LOG
	#define RB_RPDB_LOG
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_Log_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPDB_Log_init(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_RPDB_Log_settingsController(	VALUE	rb_log );
	VALUE rb_RPDB_Log_parentEnvironment(	VALUE	rb_log );
	VALUE rb_RPDB_Log_logRecord( VALUE	rb_log );
	VALUE rb_RPDB_Log_logSequenceNumber( VALUE	rb_log );
	VALUE rb_RPDB_Log_filename( VALUE	rb_log );

#endif
