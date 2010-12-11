#ifndef RB_RBDB_LOG_SEQUENCE_NUMBER
	#define RB_RBDB_LOG_SEQUENCE_NUMBER
	
	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_LogSequenceNumber_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_Rbdb_LogSequenceNumber_initialize(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self );
	VALUE rb_Rbdb_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number );
VALUE rb_Rbdb_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number );
VALUE rb_Rbdb_LogSequenceNumber_parentLogController(	VALUE	rb_log_sequence_number );
VALUE rb_Rbdb_LogSequenceNumber_parentLogCursorController(	VALUE	rb_log_sequence_number );
VALUE rb_Rbdb_LogSequenceNumber_parentLogCursor(	VALUE	rb_log_sequence_number );
VALUE rb_Rbdb_LogSequenceNumber_parentLog(	VALUE	rb_log_sequence_number );
	VALUE rb_Rbdb_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
	 											VALUE	rb_log_sequence_number_two);

#endif
