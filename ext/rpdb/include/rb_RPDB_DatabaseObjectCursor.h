#ifndef RB_RPDB_DATABASE_OBJECT_CURSOR
	#define RB_RPDB_DATABASE_OBJECT_CURSOR

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

	void Init_RPDB_DatabaseObjectCursor();

	VALUE rb_RPDB_DatabaseObjectCursor_writeAsCurrent(	VALUE	rb_database_cursor, 
													   VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																	 VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																	  VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_writeBeforeAnyDuplicates(	VALUE	rb_database_cursor, 
																 VALUE	rb_key,
																 VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_writeAfterAnyDuplicates(	VALUE	rb_database_cursor, 
																VALUE	rb_key,
																VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_writeOnlyIfNotInDatabase(	VALUE	rb_database_cursor, 
																 VALUE	rb_key,
																 VALUE	rb_data );
	VALUE rb_RPDB_DatabaseObjectCursor_keyExists(	VALUE	rb_database_cursor, 
												  VALUE	rb_key );
	VALUE rb_RPDB_DatabaseObjectCursor_retrieve(	int	argc,
												 VALUE*	args,
												 VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_current(	VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_currentKey(	VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveFirst( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveFirstKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveLast( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveLastKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveNext( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveNextKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrievePrevious( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrievePreviousKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseObjectCursor_retrieveNextDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_iterateInSegments(	VALUE rb_database_cursor,
												VALUE rb_items_per_segment	);
VALUE rb_RPDB_DatabaseObjectCursor_iterate( int	argc,
											VALUE*	args,
											VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_iterateAllInSegments(	VALUE rb_database_cursor,
													VALUE rb_items_per_segment	);
VALUE rb_RPDB_DatabaseObjectCursor_iterateAll( int	argc,
											   VALUE*	args,
											   VALUE	rb_database_cursor	);
	VALUE rb_RPDB_DatabaseObjectCursor_iterateDuplicatesInSegments( VALUE rb_database_cursor,
														VALUE rb_items_per_segment );
VALUE rb_RPDB_DatabaseObjectCursor_iterateDuplicates( int	argc,
													  VALUE*	args,
													  VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseObjectCursor_iterateKeysInSegments(	VALUE rb_database_cursor,
													VALUE rb_items_per_segment );
VALUE rb_RPDB_DatabaseObjectCursor_iterateKeys( int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor );
		
	VALUE rb_RPDB_DatabaseObjectCursor_delete(	int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor );
	
#endif
