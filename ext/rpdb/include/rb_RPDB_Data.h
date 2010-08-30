#ifndef RB_RPDB_DATA
	#define RB_RPDB_DATA
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Data();

VALUE rb_RPDB_Data_new(	VALUE	klass,
						VALUE	rb_parent_record );
VALUE rb_RPDB_Data_init(	VALUE	rb_data,
	VALUE	rb_parent_record );
	VALUE rb_RPDB_Data_settingsController(	VALUE	rb_data );
	VALUE rb_RPDB_Data_parentEnvironment(	VALUE	rb_data );

#endif
