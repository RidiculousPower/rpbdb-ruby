#ifndef RB_RPDB_DATABASE_CURSOR_INTERNAL
	#define RB_RPDB_DATABASE_CURSOR_INTERNAL


RPDB_Record* rb_RPDB_DatabaseCursor_internal_retrieveRecord(	VALUE	rb_database_cursor,
															  int		argc,
															  VALUE*	args );
	
#endif