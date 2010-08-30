#ifndef RB_RPDB_KEY
	#define RB_RPDB_KEY

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Key();

VALUE rb_RPDB_Key_new(	VALUE	klass,
					   VALUE	rb_parent_record );
VALUE rb_RPDB_Key_init(	VALUE	rb_key,
	VALUE	rb_parent_record );
	VALUE rb_RPDB_Key_settingsController(	VALUE	rb_key );
	VALUE rb_RPDB_Key_parentEnvironment(	VALUE	rb_key );

#endif
