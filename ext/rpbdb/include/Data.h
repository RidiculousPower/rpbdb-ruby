#ifndef RB_RPBDB_DATA
	#define RB_RPBDB_DATA
	
	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_Data();

VALUE rb_RPbdb_Data_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPbdb_Data_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPbdb_Data_settingsController(	VALUE	rb_data );
VALUE rb_RPbdb_Data_parentEnvironment(	VALUE	rb_data );
VALUE rb_RPbdb_Data_parentDatabaseController(	VALUE	rb_data );
VALUE rb_RPbdb_Data_parentDatabase(	VALUE	rb_data );
VALUE rb_RPbdb_Data_parentRecord(	VALUE	rb_data );

#endif
