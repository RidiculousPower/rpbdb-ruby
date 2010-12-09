#ifndef RB_Rbdb_KEY
	#define RB_Rbdb_KEY

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_Key();

VALUE rb_Rbdb_Key_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_Rbdb_Key_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self );
	VALUE rb_Rbdb_Key_settingsController(	VALUE	rb_key );
VALUE rb_Rbdb_Key_parentEnvironment(	VALUE	rb_key );
VALUE rb_Rbdb_Key_parentDatabaseController(	VALUE	rb_key );
VALUE rb_Rbdb_Key_parentDatabase(	VALUE	rb_key );
VALUE rb_Rbdb_Key_parentRecord(	VALUE	rb_key );

#endif
