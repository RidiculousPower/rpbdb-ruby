#ifndef RB_RBDB_DATABASE_OBJECT_DATABASE
	#define RB_RBDB_DATABASE_OBJECT_DATABASE

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

	void Init_rb_Rbdb_DatabaseObjectDatabase();
	VALUE rb_Rbdb_DatabaseObjectDatabase_cursor( VALUE	rb_database );
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateInSegments(	VALUE	rb_database,
															VALUE	rb_items_per_segment	);
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterate(	int	argc,
													VALUE*	args,
													VALUE	rb_database	);
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateAllInSegments(	VALUE	rb_database,
																VALUE	rb_items_per_segment	);
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateAll(	int	argc,
														VALUE*	args,
														VALUE	rb_database	);
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateDuplicatesInSegments(	VALUE	rb_database,
																		VALUE	rb_items_per_segment );
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateDuplicates(	int	argc,
															VALUE*	args,
															VALUE	rb_database );
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateKeysInSegments(	VALUE rb_database,
																VALUE rb_items_per_segment );
	VALUE rb_Rbdb_DatabaseObjectDatabase_iterateKeys(	int	argc,
														VALUE*	args,
														VALUE	rb_database );
	
#endif
