#ifndef RB_RBDB_JOIN_CURSOR
	#define RB_RBDB_JOIN_CURSOR

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseJoinCursor();
VALUE rb_Rbdb_DatabaseJoinCursor_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseJoinCursor_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_Rbdb_DatabaseJoinCursor_settingsController(	VALUE	rb_join_cursor );
	VALUE rb_Rbdb_DatabaseJoinCursor_parentEnvironment(	VALUE	rb_join_cursor );
	VALUE rb_Rbdb_DatabaseJoinCursor_parentDatabase(	VALUE	rb_join_cursor );
VALUE rb_Rbdb_DatabaseJoinCursor_parentDatabaseJoinController(	VALUE	rb_join_cursor );
	VALUE rb_Rbdb_DatabaseJoinCursor_close( VALUE	rb_join_cursor );
	VALUE rb_Rbdb_DatabaseJoinCursor_retrieveKey(	VALUE	rb_join_cursor,
	 										VALUE	rb_key	);
VALUE rb_Rbdb_DatabaseJoinCursor_iterate(	int	argc,
											  VALUE*	args,
											  VALUE	rb_join_cursor );
VALUE rb_Rbdb_DatabaseJoinCursor_first(	VALUE	rb_join_cursor );
VALUE rb_Rbdb_DatabaseJoinCursor_firstKey(	VALUE	rb_join_cursor );
	
#endif
