#ifndef RB_RBDB_DATABASE_CURSOR
	#define RB_RBDB_DATABASE_CURSOR

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseCursor();

VALUE rb_Rbdb_DatabaseCursor_new( int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCursor_initialize(	int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_settingsController(	VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_open( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_isOpen( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_close( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_overwriteCurrent(	VALUE	rb_database_cursor, 
													VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																	VALUE	rb_data );
	VALUE rb_Rbdb_DatabaseCursor_writeBeforeAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_writeAfterAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_writeOnlyIfNotInDatabase(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor );

	VALUE rb_Rbdb_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
																VALUE		key );
VALUE rb_Rbdb_DatabaseCursor_current(	VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrieve(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveKey(	int	argc,
										  VALUE*	args,
										  VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrievePrimaryKey(	int     argc,
                                                  VALUE*	args,
                                                  VALUE   rb_database_cursor );
											
VALUE rb_Rbdb_DatabaseCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																									VALUE	rb_key );
VALUE rb_Rbdb_DatabaseCursor_retrieveDuplicateMatchingPartialData(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_database_cursor );

											
	VALUE rb_Rbdb_DatabaseCursor_currentKey(	VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_currentPrimaryKey(	VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveFirstPrimaryKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveLastPrimaryKey( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrieveNext( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveNextKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrieveNextPrimaryKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_retrievePreviousPrimaryKey( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor );

VALUE rb_Rbdb_DatabaseCursor_iterate( VALUE	rb_database_cursor	);
VALUE rb_Rbdb_DatabaseCursor_iterateDuplicates( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_iterateKeys( VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_iteratePrimaryKeys( VALUE		rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_slice( int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor	);
VALUE rb_Rbdb_DatabaseCursor_sliceKeys(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_sliceDuplicates(	int			argc,
																							VALUE*	args,
																							VALUE		rb_database_cursor );
	
	VALUE rb_Rbdb_DatabaseCursor_toArray( VALUE rb_database_cursor );
	VALUE rb_Rbdb_DatabaseCursor_delete(	int	argc,
	 										VALUE*	args,
											VALUE	rb_database_cursor );
VALUE rb_Rbdb_DatabaseCursor_startingWithFirst( VALUE	rb_database_cursor );

#endif