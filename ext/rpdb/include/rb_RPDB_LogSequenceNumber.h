#ifndef RB_RPDB_LOG_SEQUENCE_NUMBER
	#define RB_RPDB_LOG_SEQUENCE_NUMBER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LogSequenceNumber_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_RPDB_LogSequenceNumber_init(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self );
	VALUE rb_RPDB_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number );
	VALUE rb_RPDB_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number );
	VALUE rb_RPDB_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
	 											VALUE	rb_log_sequence_number_two);

#endif
