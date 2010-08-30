#ifndef RB_RPDB_LOG
	#define RB_RPDB_LOG
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_Log_new(	VALUE	klass,
					   VALUE	rb_parent_log_controller );
VALUE rb_RPDB_Log_init(	VALUE	rb_log,
	VALUE	rb_parent_log_controller );
	VALUE rb_RPDB_Log_settingsController(	VALUE	rb_log );
	VALUE rb_RPDB_Log_parentEnvironment(	VALUE	rb_log );
	VALUE rb_RPDB_Log_logRecord( VALUE	rb_log );
	VALUE rb_RPDB_Log_logSequenceNumber( VALUE	rb_log );
	VALUE rb_RPDB_Log_filename( VALUE	rb_log );

#endif
