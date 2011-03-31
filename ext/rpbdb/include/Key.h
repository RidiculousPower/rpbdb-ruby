#ifndef RB_RPBDB_KEY
	#define RB_RPBDB_KEY

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_Key();

VALUE rb_RPbdb_Key_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPbdb_Key_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_RPbdb_Key_settingsController(	VALUE	rb_key );
VALUE rb_RPbdb_Key_parentEnvironment(	VALUE	rb_key );
VALUE rb_RPbdb_Key_parentDatabaseController(	VALUE	rb_key );
VALUE rb_RPbdb_Key_parentDatabase(	VALUE	rb_key );
VALUE rb_RPbdb_Key_parentRecord(	VALUE	rb_key );

#endif
