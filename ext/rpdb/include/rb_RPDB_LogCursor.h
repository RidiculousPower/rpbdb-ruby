#ifndef RB_RPDB_LOG_CURSOR
	#define RB_RPDB_LOG_CURSOR

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LogCursor_new(	VALUE	klass,
							 VALUE	rb_parent_log_cursor_controller );
VALUE rb_RPDB_LogCursor_init(	VALUE	rb_log_cursor,
	VALUE	rb_parent_log_cursor_controller );
	VALUE rb_RPDB_LogCursor_settingsController(	VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_parentEnvironment(	VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_open( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_close( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrieveCurrentLogRecord( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrieveFirstLogRecord( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrieveLastLogRecord( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrieveNextLogRecord( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrievePreviousLogRecord( VALUE	rb_log_cursor );
	VALUE rb_RPDB_LogCursor_retrieveLogRecord(	VALUE	rb_log_cursor,
												VALUE	rb_log_sequence_number );

#endif