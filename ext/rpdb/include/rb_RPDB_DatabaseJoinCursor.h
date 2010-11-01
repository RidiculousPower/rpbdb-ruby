#ifndef RB_RPDB_JOIN_CURSOR
	#define RB_RPDB_JOIN_CURSOR

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseJoinCursor();
VALUE rb_RPDB_DatabaseJoinCursor_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseJoinCursor_init(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_RPDB_DatabaseJoinCursor_settingsController(	VALUE	rb_join_cursor );
	VALUE rb_RPDB_DatabaseJoinCursor_parentEnvironment(	VALUE	rb_join_cursor );
	VALUE rb_RPDB_DatabaseJoinCursor_parentDatabase(	VALUE	rb_join_cursor );
VALUE rb_RPDB_DatabaseJoinCursor_parentDatabaseJoinController(	VALUE	rb_join_cursor );
	VALUE rb_RPDB_DatabaseJoinCursor_close( VALUE	rb_join_cursor );
	VALUE rb_RPDB_DatabaseJoinCursor_retrieveKey(	VALUE	rb_join_cursor,
	 										VALUE	rb_key	);
VALUE rb_RPDB_DatabaseJoinCursor_iterate(	int	argc,
											  VALUE*	args,
											  VALUE	rb_join_cursor );
	
#endif
