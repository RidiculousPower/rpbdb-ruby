#ifndef RB_RPBDB_DATABASE_OBJECT_DATABASE
	#define RB_RPBDB_DATABASE_OBJECT_DATABASE

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

	void Init_rb_RPbdb_DatabaseObjectDatabase();
	VALUE rb_RPbdb_DatabaseObjectDatabase_cursor( VALUE	rb_database );
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateInSegments(	VALUE	rb_database,
															VALUE	rb_items_per_segment	);
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterate(	int	argc,
													VALUE*	args,
													VALUE	rb_database	);
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateAllInSegments(	VALUE	rb_database,
																VALUE	rb_items_per_segment	);
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateAll(	int	argc,
														VALUE*	args,
														VALUE	rb_database	);
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateDuplicatesInSegments(	VALUE	rb_database,
																		VALUE	rb_items_per_segment );
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateDuplicates(	int	argc,
															VALUE*	args,
															VALUE	rb_database );
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateKeysInSegments(	VALUE rb_database,
																VALUE rb_items_per_segment );
	VALUE rb_RPbdb_DatabaseObjectDatabase_iterateKeys(	int	argc,
														VALUE*	args,
														VALUE	rb_database );
	
#endif
