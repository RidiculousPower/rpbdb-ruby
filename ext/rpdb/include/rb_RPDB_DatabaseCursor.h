#ifndef RB_RPDB_DATABASE_CURSOR
	#define RB_RPDB_DATABASE_CURSOR

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursor();

VALUE rb_RPDB_DatabaseCursor_new( VALUE	klass,
								  VALUE	rb_parent_database_cursor_controller );
VALUE rb_RPDB_DatabaseCursor_init( VALUE	rb_database_cursor,
	VALUE	rb_parent_database_cursor_controller );
	VALUE rb_RPDB_DatabaseCursor_settingsController(	VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_open( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_isOpen( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_close( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_writeAsCurrent(	VALUE	rb_database_cursor, 
													VALUE	rb_data );
	VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																VALUE	rb_data );
	VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																	VALUE	rb_data );
	VALUE rb_RPDB_DatabaseCursor_writeBeforeAnyDuplicates(	VALUE	rb_database_cursor, 
															VALUE	rb_key,
															VALUE	rb_data );
	VALUE rb_RPDB_DatabaseCursor_writeAfterAnyDuplicates(	VALUE	rb_database_cursor, 
															VALUE	rb_key,
															VALUE	rb_data );
	VALUE rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase(	VALUE	rb_database_cursor, 
																	VALUE	rb_key,
																	VALUE	rb_data );

	VALUE rb_RPDB_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
																VALUE		key );
VALUE rb_RPDB_DatabaseCursor_current(	VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrieve(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveKey(	int	argc,
										  VALUE*	args,
										  VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_currentKey(	VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrieveNext( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrieveNextKey( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_iterateInSegments( VALUE	rb_database_cursor,
								   VALUE	rb_items_per_segment	);
VALUE rb_RPDB_DatabaseCursor_iterate( int	argc,
									  VALUE*	args,
									  VALUE	rb_database_cursor	);
VALUE rb_RPDB_DatabaseCursor_iterateAllInSegments(	VALUE rb_database_cursor,
									  VALUE	rb_items_per_segment	);
VALUE rb_RPDB_DatabaseCursor_iterateAll( int	argc,
										 VALUE*	args,
										 VALUE	rb_database_cursor	);
VALUE rb_RPDB_DatabaseCursor_iterateDuplicatesInSegments(	VALUE	rb_database_cursor,
											 VALUE	rb_items_per_segment );
VALUE rb_RPDB_DatabaseCursor_iterateDuplicates( int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_iterateKeysInSegments( VALUE rb_database_cursor,
									   VALUE rb_items_per_segment );
VALUE rb_RPDB_DatabaseCursor_iterateKeys( int	argc,
										  VALUE*	args,
										  VALUE	rb_database_cursor );
	
	VALUE rb_RPDB_DatabaseCursor_toArray( VALUE rb_database_cursor );
	VALUE rb_RPDB_DatabaseCursor_delete(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_RPDB_DatabaseCursor_internal_insideIterateKeysBlock();

#endif