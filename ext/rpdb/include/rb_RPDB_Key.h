#ifndef RB_RPDB_KEY
	#define RB_RPDB_KEY

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Key();

VALUE rb_RPDB_Key_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPDB_Key_init(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_RPDB_Key_settingsController(	VALUE	rb_key );
VALUE rb_RPDB_Key_parentEnvironment(	VALUE	rb_key );
VALUE rb_RPDB_Key_parentDatabaseController(	VALUE	rb_key );
VALUE rb_RPDB_Key_parentDatabase(	VALUE	rb_key );
VALUE rb_RPDB_Key_parentRecord(	VALUE	rb_key );

#endif
