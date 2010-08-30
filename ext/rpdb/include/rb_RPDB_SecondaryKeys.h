#ifndef RB_RPDB_SECONDARY_KEYS
	#define RB_RPDB_SECONDARY_KEYS

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_SecondaryKeys_new(	VALUE	klass,
								 VALUE	rb_parent_record );
VALUE rb_RPDB_SecondaryKeys_init(	VALUE	rb_secondary_keys,
	VALUE	rb_parent_record );
	VALUE rb_RPDB_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
	 												VALUE	rb_key );
	VALUE rb_RPDB_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
														VALUE	rb_index );

#endif
