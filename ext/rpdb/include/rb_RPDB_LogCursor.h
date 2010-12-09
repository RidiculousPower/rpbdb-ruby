#ifndef RB_Rbdb_LOG_CURSOR
	#define RB_Rbdb_LOG_CURSOR

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_LogCursor_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
VALUE rb_Rbdb_LogCursor_initialize(	int				argc __attribute__ ((unused)),
															VALUE*		args __attribute__ ((unused)),
															VALUE			rb_self );
	VALUE rb_Rbdb_LogCursor_settingsController(	VALUE	rb_log_cursor );
VALUE rb_Rbdb_LogCursor_parentEnvironment(	VALUE	rb_log_cursor );
VALUE rb_Rbdb_LogCursor_parentLogController(	VALUE	rb_log_cursor );
VALUE rb_Rbdb_LogCursor_parentLogCursorController(	VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_open( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_close( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrieveCurrentLogRecord( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrieveFirstLogRecord( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrieveLastLogRecord( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrieveNextLogRecord( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrievePreviousLogRecord( VALUE	rb_log_cursor );
	VALUE rb_Rbdb_LogCursor_retrieveLogRecord(	VALUE	rb_log_cursor,
												VALUE	rb_log_sequence_number );

#endif