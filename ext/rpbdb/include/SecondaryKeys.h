#ifndef RB_RPBDB_SECONDARY_KEYS
	#define RB_RPBDB_SECONDARY_KEYS

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_SecondaryKeys_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPbdb_SecondaryKeys_initialize(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self );
	VALUE rb_RPbdb_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
	 												VALUE	rb_key );
	VALUE rb_RPbdb_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
														VALUE	rb_index );
VALUE rb_RPbdb_SecondaryKeys_parentEnvironment(	VALUE	rb_secondary_keys );
VALUE rb_RPbdb_SecondaryKeys_parentDatabaseController(	VALUE	rb_secondary_keys );
VALUE rb_RPbdb_SecondaryKeys_parentDatabase(	VALUE	rb_secondary_keys );
VALUE rb_RPbdb_SecondaryKeys_parentRecord(	VALUE	rb_secondary_keys );

#endif
