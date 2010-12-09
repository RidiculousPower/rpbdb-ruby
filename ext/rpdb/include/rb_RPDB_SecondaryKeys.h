#ifndef RB_Rbdb_SECONDARY_KEYS
	#define RB_Rbdb_SECONDARY_KEYS

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_SecondaryKeys_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_Rbdb_SecondaryKeys_initialize(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self );
	VALUE rb_Rbdb_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
	 												VALUE	rb_key );
	VALUE rb_Rbdb_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
														VALUE	rb_index );
VALUE rb_Rbdb_SecondaryKeys_parentEnvironment(	VALUE	rb_secondary_keys );
VALUE rb_Rbdb_SecondaryKeys_parentDatabaseController(	VALUE	rb_secondary_keys );
VALUE rb_Rbdb_SecondaryKeys_parentDatabase(	VALUE	rb_secondary_keys );
VALUE rb_Rbdb_SecondaryKeys_parentRecord(	VALUE	rb_secondary_keys );

#endif
