#ifndef RB_RPDB_DATA
	#define RB_RPDB_DATA
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Data();

VALUE rb_RPDB_Data_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPDB_Data_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPDB_Data_settingsController(	VALUE	rb_data );
VALUE rb_RPDB_Data_parentEnvironment(	VALUE	rb_data );
VALUE rb_RPDB_Data_parentDatabaseController(	VALUE	rb_data );
VALUE rb_RPDB_Data_parentDatabase(	VALUE	rb_data );
VALUE rb_RPDB_Data_parentRecord(	VALUE	rb_data );

#endif
