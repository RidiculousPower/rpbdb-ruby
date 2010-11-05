#ifndef RB_RPDB_SECONDARY_KEYS
	#define RB_RPDB_SECONDARY_KEYS

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_SecondaryKeys_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPDB_SecondaryKeys_init(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self );
	VALUE rb_RPDB_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
	 												VALUE	rb_key );
	VALUE rb_RPDB_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
														VALUE	rb_index );
VALUE rb_RPDB_SecondaryKeys_parentEnvironment(	VALUE	rb_secondary_keys );
VALUE rb_RPDB_SecondaryKeys_parentDatabaseController(	VALUE	rb_secondary_keys );
VALUE rb_RPDB_SecondaryKeys_parentDatabase(	VALUE	rb_secondary_keys );
VALUE rb_RPDB_SecondaryKeys_parentRecord(	VALUE	rb_secondary_keys );

#endif
