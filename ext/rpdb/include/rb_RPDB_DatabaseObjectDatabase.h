#ifndef RB_RPDB_DATABASE_OBJECT_DATABASE
	#define RB_RPDB_DATABASE_OBJECT_DATABASE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

	void Init_RPDB_DatabaseObjectDatabase();
	VALUE rb_RPDB_DatabaseObjectDatabase_cursor( VALUE	rb_database );
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateInSegments(	VALUE	rb_database,
															VALUE	rb_items_per_segment	);
	VALUE rb_RPDB_DatabaseObjectDatabase_iterate(	int	argc,
													VALUE*	args,
													VALUE	rb_database	);
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateAllInSegments(	VALUE	rb_database,
																VALUE	rb_items_per_segment	);
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateAll(	int	argc,
														VALUE*	args,
														VALUE	rb_database	);
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateDuplicatesInSegments(	VALUE	rb_database,
																		VALUE	rb_items_per_segment );
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateDuplicates(	int	argc,
															VALUE*	args,
															VALUE	rb_database );
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateKeysInSegments(	VALUE rb_database,
																VALUE rb_items_per_segment );
	VALUE rb_RPDB_DatabaseObjectDatabase_iterateKeys(	int	argc,
														VALUE*	args,
														VALUE	rb_database );
	
#endif
