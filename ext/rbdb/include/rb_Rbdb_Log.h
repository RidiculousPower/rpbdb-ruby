#ifndef RB_Rbdb_LOG
	#define RB_Rbdb_LOG
	
	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_Log_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_Rbdb_Log_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_Rbdb_Log_settingsController(	VALUE	rb_log );
VALUE rb_Rbdb_Log_parentEnvironment(	VALUE	rb_log );
VALUE rb_Rbdb_Log_parentLogController(	VALUE	rb_log );
VALUE rb_Rbdb_Log_parentLogCursorController(	VALUE	rb_log );
VALUE rb_Rbdb_Log_parentLogCursor(	VALUE	rb_log );
	VALUE rb_Rbdb_Log_logRecord( VALUE	rb_log );
	VALUE rb_Rbdb_Log_logSequenceNumber( VALUE	rb_log );
	VALUE rb_Rbdb_Log_filename( VALUE	rb_log );

#endif
