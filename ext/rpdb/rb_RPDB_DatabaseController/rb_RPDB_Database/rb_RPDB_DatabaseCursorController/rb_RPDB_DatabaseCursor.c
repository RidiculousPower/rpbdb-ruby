/*
 *		RPDB::DatabaseController::Database::CursorController::Cursor
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseCursor.h>

#include <rpdb/RPDB_Record.h>

#include "rb_RPDB_DatabaseCursor.h"
#include "rb_RPDB_DatabaseCursor_internal.h"
#include "rb_RPDB_Database_internal.h"

#include <rpdb/RPDB_DatabaseCursor.h>
#include <rpdb/RPDB_DatabaseCursorController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseReadWriteSettingsController.h>

#define RPDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED "Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursor;
extern	VALUE	rb_RPDB_DatabaseCursorController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;

void Init_RPDB_DatabaseCursor()	{

	rb_RPDB_DatabaseCursor		=	rb_define_class_under(	rb_RPDB_DatabaseCursorController, 
																											"Cursor",				
																											rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursor, 	"new",																	rb_RPDB_DatabaseCursor_new,															1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"initialize",														rb_RPDB_DatabaseCursor_init,														1 	);

	rb_define_method(						rb_RPDB_DatabaseCursor, 	"settings_controller",									rb_RPDB_DatabaseCursor_settingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"is_set_to",														"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"parent_environment",										rb_RPDB_DatabaseCursor_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"parent_environment",										"parent_environment"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"parent_database",											rb_RPDB_DatabaseCursor_parentDatabase,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"database",															"parent_database"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"parent_databae_cursor_controller",			rb_RPDB_DatabaseCursor_parentDatabaseCursorController,	0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"parent_cursor_controller",							"parent_databae_cursor_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"cursor_controller",										"parent_databae_cursor_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"open",																	rb_RPDB_DatabaseCursor_open,														0 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"is_open?",															rb_RPDB_DatabaseCursor_isOpen,													0 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"close",																rb_RPDB_DatabaseCursor_close,														0 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve",															rb_RPDB_DatabaseCursor_retrieve,												-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"move_cursor_to",												"retrieve"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"move_cursor",													"retrieve"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"duplicate",														rb_RPDB_DatabaseCursor_duplicateCursor,									0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"delete",																rb_RPDB_DatabaseCursor_delete,													-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"overwrite_current",										rb_RPDB_DatabaseCursor_writeAsCurrent,									1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_as_duplicate_after_current",			rb_RPDB_DatabaseCursor_writeAsDuplicateAfterCurrent,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_after_current",									"write_as_duplicate_after_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_as_duplicate_before_current",		rb_RPDB_DatabaseCursor_writeAsDuplicateBeforeCurrent,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_before_current",									"write_as_duplicate_before_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_before_any_duplicates",					rb_RPDB_DatabaseCursor_writeBeforeAnyDuplicates,				2 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_before_duplicates",							"write_before_any_duplicates"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_after_any_duplicates",						rb_RPDB_DatabaseCursor_writeAfterAnyDuplicates,					2 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_after_duplicates",								"write_after_any_duplicates"	);

	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write",																"write_after_any_duplicates"	);

	//	FIX - shouldn't there be a corresponding function for the database?
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_only_if_not_in_database",				rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase,						1 	);
                    					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"key_exists?",													rb_RPDB_DatabaseCursor_keyExists,														1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"exists?",															"key_exists?"	);
                    					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_current",											rb_RPDB_DatabaseCursor_current,															0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"current",															"retrieve_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_current_key",									rb_RPDB_DatabaseCursor_currentKey,													0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"current_key",													"retrieve_current_key"	);                            				
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_first",												rb_RPDB_DatabaseCursor_retrieveFirst,												0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"first",																"retrieve_first"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_first_key",										rb_RPDB_DatabaseCursor_retrieveFirstKey,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"first_key",														"retrieve_first_key"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_last",												rb_RPDB_DatabaseCursor_retrieveLast,												0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"last",																	"retrieve_last"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_last_key",										rb_RPDB_DatabaseCursor_retrieveLastKey,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"last_key",															"retrieve_last_key"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_next",												rb_RPDB_DatabaseCursor_retrieveNext,												0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"next",																	"retrieve_next"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_next_key",										rb_RPDB_DatabaseCursor_retrieveNextKey,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"next_key",															"retrieve_next_key"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_previous",										rb_RPDB_DatabaseCursor_retrievePrevious,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"previous",															"retrieve_previous"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_prev",												"retrieve_previous"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"prev",																	"retrieve_previous"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_previous_key",								rb_RPDB_DatabaseCursor_retrievePreviousKey,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"previous_key",													"retrieve_previous_key"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_prev_key",										"retrieve_previous_key"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"prev_key",															"retrieve_previous_key"	);
	                  					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_next_duplicate",							rb_RPDB_DatabaseCursor_retrieveNextDuplicate,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"next_duplicate",												"retrieve_next_duplicate"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_previous_duplicate",					rb_RPDB_DatabaseCursor_retrievePreviousDuplicate,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"previous_duplicate",										"retrieve_previous_duplicate"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_prev_duplicate",							"retrieve_previous_duplicate"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"prev_duplicate",												"retrieve_previous_duplicate"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_next_non_duplicate",					rb_RPDB_DatabaseCursor_retrieveNextNonDuplicate,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"next_non_duplicate",										"retrieve_next_non_duplicate"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_previous_non_duplicate",			rb_RPDB_DatabaseCursor_retrievePreviousNonDuplicate,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"previous_non_duplicate",								"retrieve_previous_non_duplicate"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_prev_non_duplicate",					"retrieve_previous_non_duplicate"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"prev_non_duplicate",										"retrieve_previous_non_duplicate"	);
                    					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"count_duplicates_for_current",					rb_RPDB_DatabaseCursor_countDuplicatesForCurrentKey,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"count_duplicates",											"count_duplicates_for_current"	);
	                  					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate",															rb_RPDB_DatabaseCursor_iterate,															-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each",																	"iterate"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate_duplicates",										rb_RPDB_DatabaseCursor_iterateDuplicates,										-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each_duplicate",												"iterate_duplicates"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate_keys",													rb_RPDB_DatabaseCursor_iterateKeys,													-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each_key",															"iterate_keys"	);
                    					                                                          				
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"to_array",															rb_RPDB_DatabaseCursor_toArray,															0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursor_new( VALUE	klass __attribute__((unused)),
																	VALUE	rb_parent_database_cursor_controller )	{
	
	RPDB_DatabaseCursorController*		c_parent_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_parent_database_cursor_controller, c_parent_database_cursor_controller );
	
	VALUE	rb_database_cursor		=	RUBY_RPDB_DATABASE_CURSOR(	RPDB_DatabaseCursor_new( c_parent_database_cursor_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_cursor_controller;
	
	rb_obj_call_init(	rb_database_cursor,
						1, 
						argv );
	
	return rb_database_cursor;
}

/************
*  new  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursor_init( VALUE	rb_database_cursor,
																		VALUE	rb_parent_database_cursor_controller __attribute__((unused)) )	{

	return rb_database_cursor;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseCursor_settingsController(	VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( RPDB_DatabaseCursor_settingsController( c_database_cursor ) );
}

/***************************************
*  parentEnvironment  *
***************************************/
VALUE rb_RPDB_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursor_parentEnvironment( c_database_cursor ) );
}

/***************************************
*  parentDatabase  *
***************************************/
VALUE rb_RPDB_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

 	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursor_parentDatabase( c_database_cursor ) );
}

/***************************************
*  parentDatabaseCursorController  *
***************************************/
VALUE rb_RPDB_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

 	return RUBY_RPDB_DATABASE_CURSOR_CONTROLLER( RPDB_DatabaseCursor_parentDatabaseCursorController( c_database_cursor ) );
}

/************
*  open  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursor_open( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_DatabaseCursor_open( c_database_cursor );

	return rb_database_cursor;
}

/************
*  isOpen  *
************/

VALUE rb_RPDB_DatabaseCursor_isOpen( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return RPDB_DatabaseCursor_isOpen( c_database_cursor )	?	Qtrue
															:	Qfalse;
}
	
/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_close.html
VALUE rb_RPDB_DatabaseCursor_close( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_DatabaseCursor_close( c_database_cursor );

	return rb_database_cursor;
}

/*************************
*  duplicateCursor  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPDB_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

 	return RUBY_RPDB_DATABASE_CURSOR( RPDB_DatabaseCursor_duplicateCursor( c_database_cursor ) );
}

/*******************************************************************************************************************************************************************************************
																	Writing Data
*******************************************************************************************************************************************************************************************/

/********************************************
*  writeRawKeyDataPairAsCurrentRecord  *
********************************************/

//	DB_CURRENT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAsCurrent(	VALUE	rb_database_cursor, 
												VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );

	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->data->wrapped_bdb_dbt );

	RPDB_DatabaseCursor_writeRecordAsCurrentData(	c_database_cursor,
													c_record	);
	
	return rb_database_cursor;
}

/****************************************
*  writeAfterCurrentRecord  *
****************************************/

//	DB_AFTER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
															VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->data->wrapped_bdb_dbt );
	
	RPDB_DatabaseCursor_writeRecordAsDuplicateDataAfterCurrent(	c_database_cursor,
																	c_record	);

	return rb_database_cursor;
}

/************************************************
*  writeRawKeyDataPairBeforeCurrentRecord  *
************************************************/

//	DB_BEFORE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->data->wrapped_bdb_dbt );
	
	RPDB_DatabaseCursor_writeRecordAsDuplicateBeforeCurrent(	c_database_cursor,
	 															c_record	);

	return rb_database_cursor;
}

/*********************************
*  writeAsFirstRecord  *
*********************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting before duplicates. 
//	DB_KEYFIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeBeforeAnyDuplicates(	VALUE	rb_database_cursor, 
														VALUE	rb_key __attribute__((unused)),
														VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );

	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->key->wrapped_bdb_dbt );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->data->wrapped_bdb_dbt );
	
	RPDB_DatabaseCursor_writeRecordBeforeAnyDuplicates(	c_database_cursor,
															c_record	);

	return rb_database_cursor;
}

/********************************
*  writeDataAsLastRecord  *
********************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting after duplicates. 
//	DB_KEYLAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAfterAnyDuplicates(	VALUE	rb_database_cursor, 
														VALUE	rb_key __attribute__((unused)),
														VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
												   c_record->key->wrapped_bdb_dbt );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
												   c_record->data->wrapped_bdb_dbt );
	
	RPDB_DatabaseCursor_writeRecordAfterAnyDuplicates(		c_database_cursor,
															c_record	);

	return rb_database_cursor;
}

/**************************************
*  writeOnlyIfNonExisting  *
**************************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase(	VALUE	rb_database_cursor, 
																VALUE	rb_key,
																VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_key,
												   c_record->key->wrapped_bdb_dbt );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
												   c_record->data->wrapped_bdb_dbt );
	
	RPDB_DatabaseCursor_writeRecordOnlyIfNotInDatabase(	c_database_cursor,
															c_record	);
																	
	return rb_database_cursor;
}

/*******************************************************************************************************************************************************************************************
																	Retrieval
*******************************************************************************************************************************************************************************************/

/*****************************
*  recordExistsForKey  *
*****************************/

VALUE rb_RPDB_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
											VALUE	rb_key )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	rb_RPDB_Database_internal_serializeRubyObject(	rb_key,
													c_record->key->wrapped_bdb_dbt );
		
	return ( RPDB_DatabaseCursor_keyExists(	c_database_cursor,
	 											c_record->key	)	?	Qtrue
																			:	Qfalse );
}

/*************************
*  retrieveRecord  *
*************************/

VALUE rb_RPDB_DatabaseCursor_retrieve(	int	argc,
 										VALUE*	args,
										VALUE	rb_database_cursor )	{

	RPDB_Record*	c_record	=	rb_RPDB_DatabaseCursor_internal_retrieveRecord(	rb_database_cursor,
																						argc,
																						args );

	return rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
						RPDB_Record_dataSize( c_record ) );
}

/*************************
*  retrieveKey  *
*************************/

VALUE rb_RPDB_DatabaseCursor_retrieveKey(	int	argc,
											VALUE*	args,
											VALUE	rb_database_cursor )	{
	
	RPDB_Record*	c_record	=	rb_RPDB_DatabaseCursor_internal_retrieveRecord(	rb_database_cursor,
																						argc,
																						args );
	
	return rb_str_new(	(char*) RPDB_Record_rawKey( c_record ),
					  RPDB_Record_keySize( c_record ) );
}

/*****************************************
*  retrievePartialRawKey  *
*****************************************/

VALUE rb_RPDB_DatabaseCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																									VALUE	rb_key __attribute__((unused)) )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

//	RPDB_DatabaseCursor_retrievePartialKey( c_database_cursor );

	return Qnil;
}

/****************************************
*  retrievePartialObject  *
****************************************/

//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPDB_DatabaseCursor_retrievePartialData(	VALUE	rb_database_cursor,
																									VALUE	rb_data __attribute__((unused)) )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
//	RPDB_DatabaseCursor_retrievePartialData( c_database_cursor );

	return Qnil;
}

/**************************************
*  retrievePartialData  *
**************************************/

//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_RPDB_DatabaseCursor_retrievePartialKeyDataPair(	VALUE	rb_database_cursor,
																													VALUE	partial_key __attribute__((unused)),
																													VALUE	partial_data __attribute__((unused)) )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

//	RPDB_DatabaseCursor_retrievePartialKeyDataPair( c_database_cursor );

	return Qnil;
}

/*******************************************************************************************************************************************************************************************
																Relative to Current Key
*******************************************************************************************************************************************************************************************/

/*************************
*  current  *
*************************/

VALUE rb_RPDB_DatabaseCursor_current(	VALUE	rb_database_cursor )	{
	return rb_RPDB_DatabaseCursor_retrieve(	0,
												NULL,
												rb_database_cursor );
}

/*************************
*  currentKey  *
*************************/

VALUE rb_RPDB_DatabaseCursor_currentKey(	VALUE	rb_database_cursor )	{
	return rb_RPDB_DatabaseCursor_retrieveKey(	0,
												NULL,
												rb_database_cursor );
}

/****************
*  first  *
****************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/****************
*  firstKey  *
****************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
											   RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/**************
*  last  *
**************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/**************
*  lastKey  *
**************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
											   RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/**************
*  next  *
**************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNext( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_DatabaseCursor_retrieveNext(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
												RPDB_Record_dataSize( c_record ) );
	
	VALUE	return_value	=	( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
	
	return return_value;
}		

/**************
*  nextKey  *
**************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNextKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	RPDB_DatabaseCursor_retrieveNext(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( c_record ),
											   RPDB_Record_keySize( c_record ) );
	
	VALUE	return_value	=	( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
	
	return return_value;
}		

/******************
*  previous  *
******************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/******************
*  previousKey  *
******************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
											   RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/*********************************
*  countDuplicatesForCurrentKey  *
*********************************/

//	Count data items for current key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_count.html
VALUE rb_RPDB_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return	INT2FIX( RPDB_DatabaseCursor_countDuplicatesForCurrentKey(	c_database_cursor ) );
}

/************************
*  nextDuplicate  *
************************/

//	DB_NEXT_DUP			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveNextDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/****************************
*  previousDuplicate  *
****************************/

//	DB_PREV_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePreviousDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/*************************
*  nextNonDuplicate  *
*************************/

//	DB_NEXT_NODUP		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveNextNonDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/******************************
*  previousNonDuplicate  *
******************************/

//	DB_PREV_NODUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePreviousNonDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/****************************
*  list  *
****************************/
/*(
VALUE rb_RPDB_DatabaseCursor_iterateInSegments( VALUE	rb_database_cursor,
									VALUE	rb_items_per_segment	)	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	//	Get our next record for the iteration
	RPDB_Record*	c_record	=	NULL;
	
	//	run the block on data rb_items_per_segment times
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while (		++c_item_record_number <= c_items_per_segment
		   &&	( c_record = RPDB_DatabaseCursor_iterate( c_database_cursor, FALSE ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
												RPDB_Record_dataSize( c_record ) );
		
		rb_yield( rb_record_data );
	}
	//	If we got here we return nothing
	return Qnil;
}
	*/
/****************************
*  iterate  *
****************************/

VALUE rb_RPDB_DatabaseCursor_iterate( int	argc,
									  VALUE*	args,
									  VALUE	rb_database_cursor	)	{
	
	VALUE	rb_items_per_segment	=	Qnil;
	rb_scan_args(	argc,
					args,
					"01",
					& rb_items_per_segment );
	/*
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? 0 : FIX2INT( rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_RPDB_DatabaseCursor_iterateInSegments(	rb_database_cursor,
															rb_items_per_segment );
	}	
	*/
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	//	Get our next record for the iteration
	RPDB_Record*	c_record	=	NULL;
	
	while ( ( c_record = RPDB_DatabaseCursor_iterate( c_database_cursor ) ) != NULL )	{
	
		VALUE	rb_record_data	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
												RPDB_Record_dataSize( c_record ) );

		//	If we don't have a block, we return an enumerator
		RETURN_ENUMERATOR(	rb_database_cursor,
							1, 
							& rb_items_per_segment );
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );
	}
	//	If we got here we return nothing
	return Qnil;
}

/****************************
*  listDuplicates  *
****************************/
/*
//	iterates all records with one or more duplicates
VALUE rb_RPDB_DatabaseCursor_iterateDuplicatesInSegments(	VALUE	rb_database_cursor,
												VALUE	rb_items_per_segment )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = RPDB_DatabaseCursor_iterateDuplicates( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
											   RPDB_Record_dataSize( c_record ) );
		
		//	Otherwise we iterate the block
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
VALUE rb_RPDB_DatabaseCursor_iterateDuplicates(	int	argc,
													VALUE*	args,
													VALUE	rb_database_cursor )	{
	
	VALUE	rb_items_per_segment	=	Qnil;
	rb_scan_args(	argc,
					args,
					"01",
					& rb_items_per_segment );
	/*
	int	c_items_per_segment = FIX2INT( ( rb_items_per_segment == Qnil ? 0 : rb_items_per_segment ) );
	if ( c_items_per_segment > 0 )	{
		return rb_RPDB_DatabaseCursor_iterateInSegments(	rb_database_cursor,
															rb_items_per_segment );
	}	
	*/
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	RPDB_Record*	c_record	=	NULL;

	while ( ( c_record = RPDB_DatabaseCursor_iterateDuplicates( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
												RPDB_Record_dataSize( c_record ) );
		
		//	If we don't have a block, we return an enumerator
		RETURN_ENUMERATOR(	rb_database_cursor,
							1, 
							& rb_items_per_segment );
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*************
*  listKeys  *
*************/
/*
//	iterates all keys without iterating duplicate records
VALUE rb_RPDB_DatabaseCursor_iterateKeysInSegments( VALUE rb_database_cursor,
										VALUE rb_items_per_segment )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	NULL;
	
	int	c_item_record_number	=	0;
	int	c_items_per_segment		=	FIX2INT( rb_items_per_segment );
	while ( 	++c_item_record_number <= c_items_per_segment
		   &&	( c_record = RPDB_DatabaseCursor_iterateKeys( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_data	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
												RPDB_Record_dataSize( c_record ) );
		
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
VALUE rb_RPDB_DatabaseCursor_iterateKeys(	int	argc,
											VALUE*	args,
											VALUE	rb_database_cursor )	{

	VALUE	rb_items_per_segment	=	Qnil;
	rb_scan_args(	argc,
					args,
					"01",
					& rb_items_per_segment );
	/*
	int	c_items_per_segment = ( rb_items_per_segment == Qnil ? INT2FIX( 0 ) : rb_items_per_segment );
	if ( c_items_per_segment > 0 )	{
		return rb_RPDB_DatabaseCursor_iterateInSegments(	rb_database_cursor,
															rb_items_per_segment );
	}	
*/
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	NULL;

	while ( ( c_record = RPDB_DatabaseCursor_iterateKeys( c_database_cursor ) ) != NULL )	{
		
		VALUE	rb_record_key	=	rb_str_new(	(char*) RPDB_Record_rawKey( c_record ),
												RPDB_Record_keySize( c_record ) );
		
		//	If we don't have a block, we return an enumerator
		RETURN_ENUMERATOR(	rb_database_cursor,
												1, 
												& rb_items_per_segment );
		//	Otherwise we iterate the block
		rb_yield( rb_record_key );
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/****************************
*  toArray  *
****************************/

//	iterates all keys without iterating duplicate records
VALUE rb_RPDB_DatabaseCursor_toArray( VALUE rb_database_cursor )	{

	VALUE	rb_key_enum		=	Qnil;
	VALUE	rb_return_array	=	rb_ary_new();
	while ( ( rb_key_enum = rb_funcall(	rb_database_cursor,
										rb_intern( "each" ),
										0 ) ) )	{
		
		rb_ary_push(	rb_return_array,
						rb_funcall(	rb_key_enum,
									rb_intern( "next" ),
									0 ) );
	}
	
	if ( RARRAY_LEN( rb_return_array ) == 0 )	{
		return Qnil;
	}
	
	return rb_return_array;
}
	
/*******************************************************************************************************************************************************************************************
																	Deleting Data
*******************************************************************************************************************************************************************************************/

/*****************************
*  deleteCurrentRecord  *
*****************************/

//	Deletes key/pair to which database_cursor refers
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_del.html
VALUE rb_RPDB_DatabaseCursor_delete(	int	argc,
 										VALUE*	args,
										VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	no args: delete current
	if ( argc == 0 )	{
		RPDB_DatabaseCursor_deleteCurrentRecord( c_database_cursor );
	}
	else	{
	
		rb_RPDB_Database_internal_serializeRubyObject(	args[ 0 ],
														c_record->key->wrapped_bdb_dbt );
		
		//	1 arg - key, record, raw, or record number (if recno)
		if ( argc == 1 )	{
			RPDB_DatabaseCursor_deleteRecord(	c_database_cursor,
												c_record	);
			//	FIX - for recno
			//	record	=	RPDB_DatabaseCursor_deleteRecordWithNumber();
		}
		
		//	2 args - match entire set
		if ( argc == 2 )	{
			
			rb_RPDB_Database_internal_serializeRubyObject(	args[ 1 ],
															c_record->data->wrapped_bdb_dbt );
			
			//	FIX - make sure deleteRecord supports exact pair deletion
			RPDB_DatabaseCursor_deleteRecord(	c_database_cursor,
												c_record );
		}
	}
	
	return rb_database_cursor;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
															Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

RPDB_Record* rb_RPDB_DatabaseCursor_internal_retrieveRecord(	VALUE	rb_database_cursor,
																int		argc,
																VALUE*	args )	{
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	0 args - current record
	if ( argc == 0 )	{
		
		c_record	=	RPDB_DatabaseCursor_retrieveCurrent(	c_database_cursor );
	}
	else	{
		
		rb_RPDB_Database_internal_serializeRubyObject(	args[ 0 ],
													   c_record->key->wrapped_bdb_dbt );
		
		//	1 arg - record, key, raw or record number (if recno)
		if ( argc == 1 )	{
			/*
			 FIX - figure out retrieveRecordWithNumber and how it should be structured (Btree with Recno so...?)
			 
			 if ( RPDB_DatabaseTypeSettingsController_isRecno( RPDB_DatabaseSettingsController_typeSettingsController( RPDB_Database_settingsController( c_database_cursor->parent_database ) ) ) )	{
			 record	=	RPDB_DatabaseCursor_retrieveRecordWithNumber(	c_database_cursor );
			 }
			 */
		}
		
		//	2 args - key/data pair
		else if ( argc == 2 )	{
			
			rb_RPDB_Database_internal_serializeRubyObject(	args[ 1 ],
														   c_record->data->wrapped_bdb_dbt );
			
			//	FIX - make sure that retrieveRecord supports exact key/data retrieval
		}
		
		c_record	=	RPDB_DatabaseCursor_retrieveRecord(	c_database_cursor,
															c_record );
		
	}
	return c_record;	
}