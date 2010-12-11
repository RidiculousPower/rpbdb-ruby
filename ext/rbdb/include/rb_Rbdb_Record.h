#ifndef RB_RBDB_RECORD
	#define RB_RBDB_RECORD

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_Record();

VALUE rb_Rbdb_Record_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self );
VALUE rb_Rbdb_Record_initialize(	int				argc __attribute__ ((unused)),
														VALUE*		args __attribute__ ((unused)),
														VALUE			rb_self );
	VALUE rb_Rbdb_Record_settingsController(	VALUE	rb_record );
VALUE rb_Rbdb_Record_parentEnvironment(	VALUE	rb_record );
VALUE rb_Rbdb_Record_parentDatabaseController(	VALUE	rb_record );
VALUE rb_Rbdb_Record_parentDatabase(	VALUE	rb_record );
	VALUE rb_Rbdb_Record_primaryKey( VALUE	rb_record );
	VALUE rb_Rbdb_Record_retrievalKey( VALUE	rb_record );
	VALUE rb_Rbdb_Record_setExistsInDatabase(	VALUE	rb_record,
												VALUE	rb_data_status	);
	VALUE rb_Rbdb_Record_existsInDatabase( VALUE	rb_record );
	VALUE rb_Rbdb_Record_setRequiresUpdateToDatabase(	VALUE	rb_record,
														VALUE	rb_data_status	);
	VALUE rb_Rbdb_Record_requiresUpdateToDatabase( VALUE	rb_record );

#endif
