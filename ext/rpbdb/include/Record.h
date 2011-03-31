#ifndef RB_RPBDB_RECORD
	#define RB_RPBDB_RECORD

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_Record();

VALUE rb_RPbdb_Record_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_RPbdb_Record_initialize(	int				argc __attribute__ ((unused)),
														VALUE*		args __attribute__ ((unused)),
														VALUE			rb_self );
	VALUE rb_RPbdb_Record_settingsController(	VALUE	rb_record );
VALUE rb_RPbdb_Record_parentEnvironment(	VALUE	rb_record );
VALUE rb_RPbdb_Record_parentDatabaseController(	VALUE	rb_record );
VALUE rb_RPbdb_Record_parentDatabase(	VALUE	rb_record );
	VALUE rb_RPbdb_Record_primaryKey( VALUE	rb_record );
	VALUE rb_RPbdb_Record_retrievalKey( VALUE	rb_record );
	VALUE rb_RPbdb_Record_setExistsInDatabase(	VALUE	rb_record,
												VALUE	rb_data_status	);
	VALUE rb_RPbdb_Record_existsInDatabase( VALUE	rb_record );
	VALUE rb_RPbdb_Record_setRequiresUpdateToDatabase(	VALUE	rb_record,
														VALUE	rb_data_status	);
	VALUE rb_RPbdb_Record_requiresUpdateToDatabase( VALUE	rb_record );

#endif
