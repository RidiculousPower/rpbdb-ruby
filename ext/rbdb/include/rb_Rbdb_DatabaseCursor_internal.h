#ifndef RB_RBDB_DATABASE_CURSOR_INTERNAL
	#define RB_RBDB_DATABASE_CURSOR_INTERNAL


Rbdb_Record* rb_Rbdb_DatabaseCursor_internal_retrieveRecord(	int				argc,
																															VALUE*		args,
																															VALUE			rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( VALUE   arg1,
                                                                        VALUE   arg2,
                                                                        VALUE   arg3,
                                                                        VALUE   arg4,
                                                                        int*    c_index );
	
#endif