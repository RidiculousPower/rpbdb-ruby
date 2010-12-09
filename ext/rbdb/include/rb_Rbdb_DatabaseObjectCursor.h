#ifndef RB_Rbdb_DATABASE_OBJECT_CURSOR
	#define RB_Rbdb_DATABASE_OBJECT_CURSOR

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

	void Init_Rbdb_DatabaseObjectCursor();

	VALUE rb_Rbdb_DatabaseObjectCursor_writeAsCurrent(	VALUE	rb_database_cursor, 
													   VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																	 VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																	  VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_writeBeforeAnyDuplicates(	VALUE	rb_database_cursor, 
																 VALUE	rb_key,
																 VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_writeAfterAnyDuplicates(	VALUE	rb_database_cursor, 
																VALUE	rb_key,
																VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_writeOnlyIfNotInDatabase(	VALUE	rb_database_cursor, 
																 VALUE	rb_key,
																 VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseObjectCursor_keyExists(	VALUE	rb_database_cursor, 
												  VALUE	rb_key );
	VALUE rb_Rbdb_DatabaseObjectCursor_retrieve(	int	argc,
												 VALUE*	args,
												 VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_current(	VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_currentKey(	VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveFirst( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveFirstKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveLast( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveLastKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNext( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePrevious( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_iterateInSegments(	VALUE rb_database_cursor,
												VALUE rb_items_per_segment	);
VALUE rb_Rbdb_DatabaseObjectCursor_iterate( int	argc,
											VALUE*	args,
											VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_iterateAllInSegments(	VALUE rb_database_cursor,
													VALUE rb_items_per_segment	);
VALUE rb_Rbdb_DatabaseObjectCursor_iterateAll( int	argc,
											   VALUE*	args,
											   VALUE	rb_database_cursor	);
	VALUE rb_Rbdb_DatabaseObjectCursor_iterateDuplicatesInSegments( VALUE rb_database_cursor,
														VALUE rb_items_per_segment );
VALUE rb_Rbdb_DatabaseObjectCursor_iterateDuplicates( int	argc,
													  VALUE*	args,
													  VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseObjectCursor_iterateKeysInSegments(	VALUE rb_database_cursor,
													VALUE rb_items_per_segment );
VALUE rb_Rbdb_DatabaseObjectCursor_iterateKeys( int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor );
		
	VALUE rb_Rbdb_DatabaseObjectCursor_delete(	int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor );
	
#endif
