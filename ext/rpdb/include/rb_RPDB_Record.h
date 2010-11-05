#ifndef RB_RPDB_RECORD
	#define RB_RPDB_RECORD

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Record();

VALUE rb_RPDB_Record_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_RPDB_Record_init(	int				argc __attribute__ ((unused)),
														VALUE*		args __attribute__ ((unused)),
														VALUE			rb_self );
	VALUE rb_RPDB_Record_settingsController(	VALUE	rb_record );
VALUE rb_RPDB_Record_parentEnvironment(	VALUE	rb_record );
VALUE rb_RPDB_Record_parentDatabaseController(	VALUE	rb_record );
VALUE rb_RPDB_Record_parentDatabase(	VALUE	rb_record );
	VALUE rb_RPDB_Record_primaryKey( VALUE	rb_record );
	VALUE rb_RPDB_Record_retrievalKey( VALUE	rb_record );
	VALUE rb_RPDB_Record_setExistsInDatabase(	VALUE	rb_record,
												VALUE	rb_data_status	);
	VALUE rb_RPDB_Record_existsInDatabase( VALUE	rb_record );
	VALUE rb_RPDB_Record_setRequiresUpdateToDatabase(	VALUE	rb_record,
														VALUE	rb_data_status	);
	VALUE rb_RPDB_Record_requiresUpdateToDatabase( VALUE	rb_record );

#endif
