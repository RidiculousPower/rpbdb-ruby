#ifndef RB_RPDB_LOG_SEQUENCE_NUMBER
	#define RB_RPDB_LOG_SEQUENCE_NUMBER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LogSequenceNumber_new(	VALUE	klass,
									 VALUE	rb_parent_log );
VALUE rb_RPDB_LogSequenceNumber_init(	VALUE	rb_log_sequence_number,
	VALUE	rb_parent_log );
	VALUE rb_RPDB_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number );
	VALUE rb_RPDB_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number );
	VALUE rb_RPDB_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
	 											VALUE	rb_log_sequence_number_two);

#endif
