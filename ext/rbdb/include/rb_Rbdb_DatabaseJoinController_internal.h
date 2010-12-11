#ifndef RB_RBDB_DATABASE_JOIN_CONTROLLER_INTERNAL
	#define RB_RBDB_DATABASE_JOIN_CONTROLLER_INTERNAL

VALUE rb_DatabaseJoinController_internal_joinCursorForHashDescriptor( VALUE	rb_join_controller,
																																			VALUE	rb_primary_database,
																																			VALUE	rb_hash_descriptor );
VALUE rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	VALUE	rb_primary_database,
																																		VALUE	rb_hash_descriptor );
VALUE rb_Rbdb_DatabaseJoinController_internal_cursorForIndexAtKeyValue(	VALUE	rb_primary_database,
																													VALUE	rb_index_name,
																													VALUE	rb_key_value  );

#endif