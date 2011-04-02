#ifndef RB_RPBDB_LOG_SEQUENCE_NUMBER
	#define RB_RPBDB_LOG_SEQUENCE_NUMBER
	
	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_LogSequenceNumber_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_RPbdb_LogSequenceNumber_initialize(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self );
	VALUE rb_RPbdb_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number );
VALUE rb_RPbdb_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number );
VALUE rb_RPbdb_LogSequenceNumber_parentLogController(	VALUE	rb_log_sequence_number );
VALUE rb_RPbdb_LogSequenceNumber_parentLogCursorController(	VALUE	rb_log_sequence_number );
VALUE rb_RPbdb_LogSequenceNumber_parentLogCursor(	VALUE	rb_log_sequence_number );
VALUE rb_RPbdb_LogSequenceNumber_parentLog(	VALUE	rb_log_sequence_number );
	VALUE rb_RPbdb_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
	 											VALUE	rb_log_sequence_number_two);

#endif
