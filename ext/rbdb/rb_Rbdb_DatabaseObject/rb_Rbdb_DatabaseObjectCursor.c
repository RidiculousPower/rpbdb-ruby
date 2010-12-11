/*
 *		Rbdb::DatabaseController::Database::CursorController::ObjectCursor
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseCursor.h"
#include "rb_Rbdb_DatabaseCursor_internal.h"

#include "rb_Rbdb_DatabaseObjectCursor.h"
#include "rb_Rbdb_DatabaseObjectCursor_internal.h"

#include "rb_Rbdb_DatabaseObject_internal.h"

#include <rbdb/Rbdb_Record.h>

#include <rbdb/Rbdb_DatabaseCursor.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_DatabaseCursorController;
extern	VALUE	rb_Rbdb_DatabaseCursor;
extern	VALUE	rb_Rbdb_DatabaseObjectCursor;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
 Module Definition (Ruby Init)
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_Rbdb_DatabaseObjectCursor()	{

	rb_Rbdb_DatabaseObjectCursor		=	rb_define_class_under(	rb_Rbdb_DatabaseCursor, 
																														"ObjectCursor",				
																														rb_Rbdb_DatabaseCursor );
	
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"delete",																rb_Rbdb_DatabaseObjectCursor_delete,															-1 	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"overwrite_current",										rb_Rbdb_DatabaseObjectCursor_writeAsCurrent,											1 	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"write_as_duplicate_after_current",			rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateAfterCurrent,				1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"write_after_current",									"write_as_duplicate_after_current"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"write_as_duplicate_before_current",		rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateBeforeCurrent,				1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"write_before_current",									"write_as_duplicate_before_current"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"write_before_any_duplicates",					rb_Rbdb_DatabaseObjectCursor_writeBeforeAnyDuplicates,						2 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"write_before_duplicates",							"write_before_any_duplicates"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"write_after_any_duplicates",						rb_Rbdb_DatabaseObjectCursor_writeAfterAnyDuplicates,							2 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"write_after_duplicates",								"write_after_any_duplicates"	);
	
	//	Default behavior for write is to insert data after existing duplicates for key
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"write",																"write_after_any_duplicates"	);

	//	FIX - shouldn't there be a corresponding function for the database?
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"write_only_if_not_in_database",				rb_Rbdb_DatabaseObjectCursor_writeOnlyIfNotInDatabase,						1 	);

	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"key_exists?",													rb_Rbdb_DatabaseObjectCursor_keyExists,														1 	);

	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve",															rb_Rbdb_DatabaseObjectCursor_retrieve,														-1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"move_cursor_to",												"retrieve"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"move_to",															"retrieve"	);
	
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_current",											rb_Rbdb_DatabaseObjectCursor_current,															0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"current",															"retrieve_current"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_current_key",									rb_Rbdb_DatabaseObjectCursor_currentKey,													0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"current_key",													"retrieve_current_key"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_first",												rb_Rbdb_DatabaseObjectCursor_retrieveFirst,												0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"first",																"retrieve_first"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_first_key",										rb_Rbdb_DatabaseObjectCursor_retrieveFirstKey,										0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"first_key",														"retrieve_first_key"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_last",												rb_Rbdb_DatabaseObjectCursor_retrieveLast,												0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"last",																	"retrieve_last"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_last_key",										rb_Rbdb_DatabaseObjectCursor_retrieveLastKey,											0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"last_key",															"retrieve_last_key"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_next",												rb_Rbdb_DatabaseObjectCursor_retrieveNext,												0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"next",																	"retrieve_next"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_next_key",										rb_Rbdb_DatabaseObjectCursor_retrieveNextKey,											0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"next_key",															"retrieve_next_key"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_previous",										rb_Rbdb_DatabaseObjectCursor_retrievePrevious,										0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"previous",															"retrieve_previous"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_prev",												"retrieve_previous"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"prev",																	"retrieve_previous"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_previous_key",								rb_Rbdb_DatabaseObjectCursor_retrievePreviousKey,									0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"previous_key",													"retrieve_previous_key"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_prev_key",										"retrieve_previous_key"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"prev_key",															"retrieve_previous_key"	);
	                                                                                					
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_next_duplicate",							rb_Rbdb_DatabaseObjectCursor_retrieveNextDuplicate,								0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"next_duplicate",												"retrieve_next_duplicate"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_previous_duplicate",					rb_Rbdb_DatabaseObjectCursor_retrievePreviousDuplicate,						0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"previous_duplicate",										"retrieve_previous_duplicate"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_prev_duplicate",							"retrieve_previous_duplicate"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"prev_duplicate",												"retrieve_previous_duplicate"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_next_non_duplicate",					rb_Rbdb_DatabaseObjectCursor_retrieveNextNonDuplicate,						0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"next_non_duplicate",										"retrieve_next_non_duplicate"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_previous_non_duplicate",			rb_Rbdb_DatabaseObjectCursor_retrievePreviousNonDuplicate,				0 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"previous_non_duplicate",								"retrieve_previous_non_duplicate"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"retrieve_prev_non_duplicate",					"retrieve_previous_non_duplicate"	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"prev_non_duplicate",										"retrieve_previous_non_duplicate"	);
		
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"iterate",															rb_Rbdb_DatabaseObjectCursor_iterate,															-1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"each",																	"iterate"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"iterate_all",													rb_Rbdb_DatabaseObjectCursor_iterateAll,													-1 	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"iterate_duplicates",										rb_Rbdb_DatabaseObjectCursor_iterateDuplicates,										-1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"each_duplicate",												"iterate_duplicates"	);
	rb_define_method(	rb_Rbdb_DatabaseObjectCursor, 	"iterate_keys",													rb_Rbdb_DatabaseObjectCursor_iterateKeys,													-1 	);
	rb_define_alias(	rb_Rbdb_DatabaseObjectCursor, 	"each_key",															"iterate_keys"	);
	
}

/*******************************************************************************************************************************************************************************************
															Writing Data
*******************************************************************************************************************************************************************************************/

/********************************************
*  writeRawKeyDataPairAsCurrentRecord  *
********************************************/

//	DB_CURRENT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeAsCurrent(	VALUE	rb_database_cursor, 
													VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_overwriteCurrentDataWithRecord(	c_database_cursor,
													c_record	);
	
	return rb_database_cursor;
}

/****************************************
*  writeAfterCurrentRecord  *
****************************************/

//	DB_AFTER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
															VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_writeRecordAsDuplicateDataAfterCurrent(	c_database_cursor,
																	c_record	);
	
	return rb_database_cursor;
}

/************************************************
*  writeRawKeyDataPairBeforeCurrentRecord  *
************************************************/

//	DB_BEFORE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
															VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_writeRecordAsDuplicateBeforeCurrent(	c_database_cursor,
																c_record );
	
	return rb_database_cursor;
}

/*********************************
*  writeAsFirstRecord  *
*********************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting before duplicates. 
//	DB_KEYFIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeBeforeAnyDuplicates(	VALUE	rb_database_cursor, 
													   VALUE	rb_key,
													   VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																																		c_record->key->wrapped_bdb_dbt,
																																		TRUE );
		
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_writeRecordBeforeAnyDuplicates(	c_database_cursor,
																											c_record );
	
	return rb_database_cursor;
}

/********************************
*  writeDataAsLastRecord  *
********************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting after duplicates. 
//	DB_KEYLAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeAfterAnyDuplicates(	VALUE	rb_database_cursor, 
													  VALUE	rb_key,
													  VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																																		c_record->key->wrapped_bdb_dbt,
																																		TRUE );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_writeRecordAfterAnyDuplicates(		c_database_cursor,
															c_record );
	
	return rb_database_cursor;
}

/**************************************
*  writeOnlyIfNonExisting  *
**************************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_Rbdb_DatabaseObjectCursor_writeOnlyIfNotInDatabase(	VALUE	rb_database_cursor, 
													   VALUE	rb_key,
													   VALUE	rb_data )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																																		c_record->key->wrapped_bdb_dbt,
																																		TRUE );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_data,
																																		c_record->data->wrapped_bdb_dbt,
																																		FALSE );
	
	Rbdb_DatabaseCursor_writeRecordOnlyIfNotInDatabase(	c_database_cursor,
																											c_record );
	
	return rb_database_cursor;
}

/*******************************************************************************************************************************************************************************************
 Retrieval
*******************************************************************************************************************************************************************************************/

/*****************************
*  recordExistsForKey  *
*****************************/

VALUE rb_Rbdb_DatabaseObjectCursor_keyExists(	VALUE	rb_database_cursor, 
												VALUE	rb_key )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																																		c_record->key->wrapped_bdb_dbt,
																																		TRUE );

	return ( Rbdb_DatabaseCursor_keyExists(	c_database_cursor,
												c_record->key )	?	Qtrue
																		:	Qfalse );
}

/*************************
*  retrieve  *
*************************/

VALUE rb_Rbdb_DatabaseObjectCursor_retrieve(	int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	rb_Rbdb_DatabaseObjectCursor_internal_retrieveRecord(	rb_database_cursor,
																							argc,
																							args );
	
	VALUE	rb_object	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
	
	if ( c_record != NULL )	{
		Rbdb_Record_free( & c_record );
	}
	
	return rb_object;
}

/*****************************************
*  retrievePartialRawKey  *
*****************************************/

VALUE rb_Rbdb_DatabaseObjectCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																												VALUE	rb_key __attribute__((unused)) )	{
 
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
 
//	Rbdb_DatabaseCursor_retrievePartialKey( c_database_cursor );

	return Qnil;
}

/****************************************
*  retrievePartialObject  *
****************************************/

//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePartialData(	VALUE	rb_database_cursor,
																												VALUE	rb_data __attribute__((unused)) )	{
 
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
 
//	Rbdb_DatabaseCursor_retrievePartialData( c_database_cursor );
 
	return Qnil;
}

/**************************************
*  retrievePartialData  *
**************************************/

//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePartialKeyDataPair(	VALUE	rb_database_cursor,
																																VALUE	partial_key __attribute__((unused)),
																																VALUE	partial_data __attribute__((unused)) )	{
 
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
 
//	Rbdb_DatabaseCursor_retrievePartialKeyDataPair( c_database_cursor );

	return Qnil;
}
 

/*******************************************************************************************************************************************************************************************
														Relative to Current Key
*******************************************************************************************************************************************************************************************/


/*************************
*  current  *
*************************/

VALUE rb_Rbdb_DatabaseObjectCursor_current(	VALUE	rb_database_cursor )	{

	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveCurrent(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/*************************
*  currentKey  *
*************************/

VALUE rb_Rbdb_DatabaseObjectCursor_currentKey(	VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveCurrent(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
}

/****************
*  first  *
****************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveFirst( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/****************
*  firstKey  *
****************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveFirstKey( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
}

/**************
*  last  *
**************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveLast( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/**************
*  lastKey  *
**************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveLastKey( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
}

/**************
*  next  *
**************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNext( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveNext(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}		

/**************
*  nextKey  *
**************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextKey( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveNext(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
}		

/******************
*  previous  *
******************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePrevious( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/******************
*  previousKey  *
******************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousKey( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
}

/************************
*  nextDuplicate  *
************************/

//	DB_NEXT_DUP			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextDuplicate( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveNextDuplicate(	c_database_cursor );

	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/****************************
*  previousDuplicate  *
****************************/

//	DB_PREV_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrievePreviousDuplicate(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/*************************
*  nextNonDuplicate  *
*************************/

//	DB_NEXT_NODUP		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrieveNextNonDuplicate(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/******************************
*  previousNonDuplicate  *
******************************/

//	DB_PREV_NODUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseObjectCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_DatabaseCursor_retrievePreviousNonDuplicate(	c_database_cursor );
	
	return rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
}

/****************************
*  iterateInSegments  *
****************************/
/*
VALUE rb_Rbdb_DatabaseObjectCursor_iterateInSegments(	VALUE rb_database_cursor,
														VALUE rb_items_per_segment )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	//	Get our next record for the iteration
	Rbdb_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = Rbdb_DatabaseCursor_iterate( c_database_cursor, FALSE ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		rb_yield( rb_record_data );
	}
	//	If we got here we return nothing
	return Qnil;
}
*/
/****************************
*  iterate  *
****************************/

VALUE rb_Rbdb_DatabaseObjectCursor_iterate( int	argc,
											VALUE*	args,
											VALUE	rb_database_cursor )	{
	
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}

/*
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? 0 : FIX2INT( rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_Rbdb_DatabaseObjectCursor_iterateInSegments(	rb_database_cursor,
																rb_items_per_segment );
	}	
*/
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	//	Get our next record for the iteration
	Rbdb_Record*	c_record	=	NULL;
	
	while ( ( c_record = Rbdb_DatabaseCursor_iterate( c_database_cursor, c_record ) ) )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		//	If we don't have a block, we return an enumerator
		R_ReturnEnumeratorIfNoBlock(	0,
																	NULL,
																	rb_database_cursor );
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );
	}
	//	If we got here we return nothing
	return Qnil;
}

/****************************
*  iterateAllInSegments  *
****************************/
/*
VALUE rb_Rbdb_DatabaseObjectCursor_iterateAllInSegments(	VALUE rb_database_cursor,
												VALUE rb_items_per_segment	)	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = Rbdb_DatabaseCursor_iterate( c_database_cursor, TRUE ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		rb_yield( rb_record_data );
	}
	
	//	If we got here we return nothing
	return Qnil;
}
*/
/****************************
*  iterateAll  *
****************************/

VALUE rb_Rbdb_DatabaseObjectCursor_iterateAll( int	argc,
											   VALUE*	args,
											   VALUE	rb_database_cursor	)	{
	
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}
	
/*
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? 0 : FIX2INT( rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_Rbdb_DatabaseObjectCursor_iterateAllInSegments(	rb_database_cursor,
																   rb_items_per_segment );
	}	
*/
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	while ( ( c_record = Rbdb_DatabaseCursor_iterate( c_database_cursor, c_record ) ) )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		//	If we don't have a block, we return an enumerator
		R_ReturnEnumeratorIfNoBlock(	0,
																	NULL,
																	rb_database_cursor );
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/****************************
*  iterateDuplicatesInSegments  *
****************************/
/*
//	iterates all records with one or more duplicates
VALUE rb_Rbdb_DatabaseObjectCursor_iterateDuplicatesInSegments( VALUE rb_database_cursor,
													VALUE rb_items_per_segment )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = Rbdb_DatabaseCursor_iterateDuplicates( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		rb_yield( rb_record_data );
	}
	
	//	If we got here we return nothing
	return Qnil;
}
*/
/****************************
*  iterateDuplicates  *
****************************/

//	iterates all records with one or more duplicates
VALUE rb_Rbdb_DatabaseObjectCursor_iterateDuplicates( int	argc,
													  VALUE*	args,
													  VALUE	rb_database_cursor )	{
	
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}
/*
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? 0 : FIX2INT( rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_Rbdb_DatabaseObjectCursor_iterateDuplicatesInSegments(	rb_database_cursor,
																			rb_items_per_segment );
	}	
*/
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	while ( ( c_record = Rbdb_DatabaseCursor_iterateDuplicates( c_database_cursor, c_record ) ) )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		//	If we don't have a block, we return an enumerator
		R_ReturnEnumeratorIfNoBlock(	0,
																	NULL,
																	rb_database_cursor );
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );		
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/****************************
*  iterateKeysInSegments  *
****************************/
/*
//	iterates all keys without iterating duplicate records
VALUE rb_Rbdb_DatabaseObjectCursor_iterateKeysInSegments( VALUE rb_database_cursor,
												VALUE rb_items_per_segment )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = Rbdb_DatabaseCursor_iterateKeys( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalData( c_record );
		
		rb_yield( rb_record_data );
	}
	
	//	If we got here we return nothing
	return Qnil;
}
*/
/****************************
*  iterateKeys  *
****************************/

//	iterates all keys without iterating duplicate records
VALUE rb_Rbdb_DatabaseObjectCursor_iterateKeys( int	argc,
												VALUE*	args,
												VALUE	rb_database_cursor )	{
	
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}
/*	
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? 0 : FIX2INT( rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_Rbdb_DatabaseObjectCursor_iterateKeysInSegments(	rb_database_cursor,
																	rb_items_per_segment );
	}	
*/	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	NULL;
	
	while ( ( c_record = Rbdb_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) )	{
		
		VALUE	rb_key	=	rb_Rbdb_DatabaseObject_internal_extractRetrievalKey( c_record );
		
		VALUE	enumerator_args[2];
		enumerator_args[ 0 ]	=	rb_key;
		enumerator_args[ 1 ]	=	rb_database_cursor;
		
		//	If we don't have a block, we return an enumerator
		R_ReturnEnumeratorIfNoBlock(	2, 
																	enumerator_args,
																	rb_database_cursor );
		//	Otherwise we iterate the block
		rb_yield( rb_key );
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*******************************************************************************************************************************************************************************************
															Deleting Data
*******************************************************************************************************************************************************************************************/

/*****************************
*  deleteCurrentRecord  *
*****************************/

//	Deletes key/pair to which database_cursor refers
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_del.html
VALUE rb_Rbdb_DatabaseObjectCursor_delete(	int	argc,
									 VALUE*	args,
									 VALUE	rb_database_cursor )	{
	
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_OBJECT_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ 0 ],
																																		c_record->key->wrapped_bdb_dbt,
																																		TRUE );
	
	//	no args: delete current
	if ( argc == 0 )	{
		Rbdb_DatabaseCursor_deleteCurrentRecord( c_database_cursor );
	}
	
	//	1 arg - key, record, raw, or record number (if recno)
	if ( argc == 1 )	{
		Rbdb_DatabaseCursor_deleteRecord(	c_database_cursor,
											c_record );
		//	FIX - for recno
		//	record	=	Rbdb_DatabaseCursor_deleteRecordWithNumber();
	}
	
	//	2 args - match entire set
	if ( argc == 2 )	{
		
		rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ 1 ],
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
		
		Rbdb_DatabaseCursor_deleteRecord(	c_database_cursor,
											c_record );
	}
	
	return rb_database_cursor;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																Internal Retrieve Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

Rbdb_Record* rb_Rbdb_DatabaseObjectCursor_internal_retrieveRecord(	VALUE	rb_database_cursor,
																		int		argc,
																		VALUE*	args )	{
	Rbdb_DatabaseCursor*	c_database_cursor;
	C_RBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	0 args - current record
	if ( argc == 0 )	{
		
		c_record	=	Rbdb_DatabaseCursor_retrieveCurrent(	c_database_cursor );

	}
	else	{
		
		rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ 0 ],
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );
		
		//	1 arg - record, key, raw or record number (if recno)
		if ( argc == 1 )	{
			/*
			 FIX - figure out retrieveRecordWithNumber and how it should be structured (Btree with Recno so...?)
			 
			 if ( Rbdb_DatabaseTypeSettingsController_isRecno( Rbdb_DatabaseSettingsController_typeSettingsController( Rbdb_Database_settingsController( c_database_cursor->parent_database ) ) ) )	{
			 record	=	Rbdb_DatabaseObjectCursor_retrieveRecordWithNumber(	c_database_cursor );
			 }
			 */
		}
		
		//	2 args - key/data pair
		else if ( argc == 2 )	{
			
			rb_Rbdb_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ 1 ],
																																				c_record->data->wrapped_bdb_dbt,
																																				FALSE );
			
			//	FIX - make sure that retrieveRecord supports exact key/data retrieval
		}
		
		c_record	=	Rbdb_DatabaseCursor_retrieveRecord(	c_database_cursor,
																c_record );
		
	}
	return c_record;	
}