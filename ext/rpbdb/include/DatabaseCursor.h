#ifndef RB_RPBDB_DATABASE_CURSOR
	#define RB_RPBDB_DATABASE_CURSOR

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCursor();

VALUE rb_RPbdb_DatabaseCursor_new( int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseCursor_initialize(	int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_settingsController(	VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_open( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_isOpen( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_close( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_overwriteCurrent(	VALUE	rb_database_cursor, 
													VALUE	rb_data );
	VALUE rb_RPbdb_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																VALUE	rb_data );
	VALUE rb_RPbdb_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																	VALUE	rb_data );
	VALUE rb_RPbdb_DatabaseCursor_writeBeforeAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_writeAfterAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_writeOnlyIfNotInDatabase(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );

	VALUE rb_RPbdb_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
																VALUE		key );
VALUE rb_RPbdb_DatabaseCursor_current(	VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrieve(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveKey(	int	argc,
										  VALUE*	args,
										  VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrievePrimaryKey(	int     argc,
                                                  VALUE*	args,
                                                  VALUE   rb_database_cursor );
											
VALUE rb_RPbdb_DatabaseCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																									VALUE	rb_key );
VALUE rb_RPbdb_DatabaseCursor_retrieveDuplicateMatchingPartialData(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_database_cursor );

											
	VALUE rb_RPbdb_DatabaseCursor_currentKey(	VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_currentPrimaryKey(	VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveFirstPrimaryKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveLastPrimaryKey( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrieveNext( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveNextKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrieveNextPrimaryKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_retrievePreviousPrimaryKey( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor );

VALUE rb_RPbdb_DatabaseCursor_iterate( VALUE	rb_database_cursor	);
VALUE rb_RPbdb_DatabaseCursor_iterateDuplicates( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_iterateKeys( VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_iteratePrimaryKeys( VALUE		rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_slice( int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor	);
VALUE rb_RPbdb_DatabaseCursor_sliceKeys(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_sliceDuplicates(	int			argc,
																							VALUE*	args,
																							VALUE		rb_database_cursor );
	
	VALUE rb_RPbdb_DatabaseCursor_toArray( VALUE rb_database_cursor );
	VALUE rb_RPbdb_DatabaseCursor_delete(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_RPbdb_DatabaseCursor_startingWithFirst( VALUE	rb_database_cursor );

#endif