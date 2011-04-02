/*
 *		RPbdb::DatabaseController::Database::CursorController::Cursor
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/


#include "DatabaseCursor.h"
#include "DatabaseCursor_internal.h"
#include "DatabaseCursorSettingsController.h"
#include "DatabaseCursorController.h"
#include "Database.h"
#include "DatabaseController.h"
#include "Database_internal.h"

#include "DatabaseObject_internal.h"

#include <rpbdb/DatabaseCursor.h>
#include <rpbdb/DatabaseCursorController.h>
#include <rpbdb/DatabaseCursorSettingsController.h>

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>
#include <rpbdb/DatabaseCursor.h>

#include <rpbdb/Record.h>

#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseRecordReadWriteSettingsController.h>

#include <rargs.h>

#define RPBDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED "Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseCursor;
extern	VALUE	rb_RPbdb_DatabaseCursorController;
extern	VALUE	rb_RPbdb_DatabaseCursorSettingsController;
extern	VALUE	rb_RPbdb_DatabaseController;

void Init_rb_RPbdb_DatabaseCursor()	{

	rb_RPbdb_DatabaseCursor		=	rb_define_class_under(	rb_RPbdb_Database, 
																											"Cursor",				
																											rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseCursor, 	"new",																	rb_RPbdb_DatabaseCursor_new,															-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"initialize",														rb_RPbdb_DatabaseCursor_initialize,														-1 	);

	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"settings_controller",									rb_RPbdb_DatabaseCursor_settingsController,							0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"is_set_to",														"settings_controller"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"parent_environment",										rb_RPbdb_DatabaseCursor_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"parent_environment",										"parent_environment"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"parent_database",											rb_RPbdb_DatabaseCursor_parentDatabase,									0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"database",															"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"parent_database_cursor_controller",		rb_RPbdb_DatabaseCursor_parentDatabaseCursorController,	0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"parent_cursor_controller",							"parent_database_cursor_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"cursor_controller",										"parent_database_cursor_controller"	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"open",																	rb_RPbdb_DatabaseCursor_open,														0 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"is_open?",															rb_RPbdb_DatabaseCursor_isOpen,													0 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"close",																rb_RPbdb_DatabaseCursor_close,														0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"duplicate",														rb_RPbdb_DatabaseCursor_duplicateCursor,									0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"delete",																rb_RPbdb_DatabaseCursor_delete,													-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"overwrite_current",										rb_RPbdb_DatabaseCursor_overwriteCurrent,									1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"write_as_duplicate_after_current",			rb_RPbdb_DatabaseCursor_writeAsDuplicateAfterCurrent,		1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"write_after_current",									"write_as_duplicate_after_current"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"write_as_duplicate_before_current",		rb_RPbdb_DatabaseCursor_writeAsDuplicateBeforeCurrent,		1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"write_before_current",									"write_as_duplicate_before_current"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"write_before_any_duplicates",					rb_RPbdb_DatabaseCursor_writeBeforeAnyDuplicates,				-1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"write_before_duplicates",							"write_before_any_duplicates"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"write_after_any_duplicates",						rb_RPbdb_DatabaseCursor_writeAfterAnyDuplicates,					-1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"write_after_duplicates",								"write_after_any_duplicates"	);

	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"write",																"write_after_any_duplicates"	);

	//	FIX - shouldn't there be a corresponding function for the database?
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"write_only_if_not_in_database",				rb_RPbdb_DatabaseCursor_writeOnlyIfNotInDatabase,						-1 	);
                    					                                                              		
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"has_key?",                             rb_RPbdb_DatabaseCursor_keyExists,														1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"key_exists?",													"has_key?"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"exists?",															"has_key?"	);

	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve",															rb_RPbdb_DatabaseCursor_retrieve,														-1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"move_cursor_to",												"retrieve"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"move_cursor",													"retrieve"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"move_to",															"retrieve"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_key",													rb_RPbdb_DatabaseCursor_retrieveKey,													-1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"key",																	"retrieve_key"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_partial_key",									rb_RPbdb_DatabaseCursor_retrievePartialKey,									1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"partial_key",													"retrieve_partial_key"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_partial",											"retrieve_partial_key"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_duplicate_matching_partial_data",			rb_RPbdb_DatabaseCursor_retrieveDuplicateMatchingPartialData,									-1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_duplicate_for_partial_data",					"retrieve_duplicate_matching_partial_data"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_partial_data",												"retrieve_duplicate_matching_partial_data"	);

	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_current",											rb_RPbdb_DatabaseCursor_current,															0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"current",															"retrieve_current"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_current_key",									rb_RPbdb_DatabaseCursor_currentKey,													0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"current_key",													"retrieve_current_key"	);                            				
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_first",												rb_RPbdb_DatabaseCursor_retrieveFirst,												0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"first",																"retrieve_first"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"starting_with_first",									rb_RPbdb_DatabaseCursor_startingWithFirst,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"from_first",														"starting_with_first"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_first_key",										rb_RPbdb_DatabaseCursor_retrieveFirstKey,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"first_key",														"retrieve_first_key"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_last",												rb_RPbdb_DatabaseCursor_retrieveLast,												0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"last",																	"retrieve_last"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_last_key",										rb_RPbdb_DatabaseCursor_retrieveLastKey,											0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"last_key",															"retrieve_last_key"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_next",												rb_RPbdb_DatabaseCursor_retrieveNext,												0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"next",																	"retrieve_next"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_next_key",										rb_RPbdb_DatabaseCursor_retrieveNextKey,											0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"next_key",															"retrieve_next_key"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_previous",										rb_RPbdb_DatabaseCursor_retrievePrevious,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"previous",															"retrieve_previous"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_prev",												"retrieve_previous"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"prev",																	"retrieve_previous"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_previous_key",								rb_RPbdb_DatabaseCursor_retrievePreviousKey,									0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"previous_key",													"retrieve_previous_key"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_prev_key",										"retrieve_previous_key"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"prev_key",															"retrieve_previous_key"	);
	                  					                                                              		
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_next_duplicate",							rb_RPbdb_DatabaseCursor_retrieveNextDuplicate,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"next_duplicate",												"retrieve_next_duplicate"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_previous_duplicate",					rb_RPbdb_DatabaseCursor_retrievePreviousDuplicate,						0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"previous_duplicate",										"retrieve_previous_duplicate"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_prev_duplicate",							"retrieve_previous_duplicate"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"prev_duplicate",												"retrieve_previous_duplicate"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_next_non_duplicate",					rb_RPbdb_DatabaseCursor_retrieveNextNonDuplicate,						0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"next_non_duplicate",										"retrieve_next_non_duplicate"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"retrieve_previous_non_duplicate",			rb_RPbdb_DatabaseCursor_retrievePreviousNonDuplicate,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"previous_non_duplicate",								"retrieve_previous_non_duplicate"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"retrieve_prev_non_duplicate",					"retrieve_previous_non_duplicate"	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"prev_non_duplicate",										"retrieve_previous_non_duplicate"	);
                    					                                                              		
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"count_duplicates_for_current_key",			rb_RPbdb_DatabaseCursor_countDuplicatesForCurrentKey,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"count_duplicates",											"count_duplicates_for_current_key"	);
	                  					                                                              		
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"iterate",															rb_RPbdb_DatabaseCursor_iterate,															0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"each",																	"iterate"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"iterate_duplicates",										rb_RPbdb_DatabaseCursor_iterateDuplicates,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"each_duplicate",												"iterate_duplicates"	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"iterate_keys",													rb_RPbdb_DatabaseCursor_iterateKeys,													0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursor, 	"each_key",															"iterate_keys"	);

	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"slice",																rb_RPbdb_DatabaseCursor_slice,																-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"slice_keys",														rb_RPbdb_DatabaseCursor_sliceKeys,														-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursor, 	"slice_duplicates",											rb_RPbdb_DatabaseCursor_sliceDuplicates,											-1 	);
                    					                                                          				
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseCursor_new( int			argc,
																	VALUE*	args,
																	VALUE		rb_database_cursor_class __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database            =	Qnil;
	VALUE	rb_parent_cursor_controller   =	Qnil;

	R_DefineAndParse( argc, args, rb_database_cursor_class,
		R_DescribeParameterSet(
			R_ParameterSet(
				R_Parameter(	R_MatchAncestorInstance(					rb_parent_database,                 rb_RPbdb_Database ),
                      R_MatchAncestorInstance(					rb_parent_cursor_controller,        rb_RPbdb_DatabaseCursorController )
				)
			),
			1,
			"<database>",
			"<database cursor controller>"
		)
	);
	
	if ( rb_parent_database != Qnil )	{
		rb_parent_cursor_controller	=	rb_RPbdb_Database_cursorController(	rb_parent_database );
	}
	
	RPbdb_DatabaseCursorController*		c_parent_cursor_controller;
	C_RPBDB_DATABASE_CURSOR_CONTROLLER( rb_parent_cursor_controller, c_parent_cursor_controller );

	RPbdb_DatabaseCursor*	c_database_cursor		=	RPbdb_DatabaseCursorController_cursor( c_parent_cursor_controller );
	VALUE									rb_database_cursor	=	RUBY_RPBDB_DATABASE_CURSOR( c_database_cursor );

	//	store reference to parent
	rb_iv_set(	rb_database_cursor,
							RPBDB_RB_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER,
							rb_parent_cursor_controller );

	VALUE	argv[]	=	{ rb_parent_cursor_controller };
	rb_obj_call_init(	rb_database_cursor,
										1, 
										argv );
	
	return rb_database_cursor;
}

/***************
*  initialize  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPbdb_DatabaseCursor_initialize(	int			argc __attribute__ ((unused)),
																		VALUE*	args __attribute__ ((unused)),
																		VALUE		rb_database_cursor )	{

	return rb_database_cursor;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPbdb_DatabaseCursor_settingsController(	VALUE	rb_database_cursor )	{

	VALUE	rb_local_database_cursor_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_cursor_settings_controller = rb_iv_get(	rb_database_cursor,
																																		RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_local_database_cursor_settings_controller	=	rb_RPbdb_DatabaseCursorSettingsController_new(	1,
																																																	& rb_database_cursor,
																																																	rb_RPbdb_DatabaseCursorSettingsController );

		rb_iv_set(	rb_database_cursor,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER,
								rb_local_database_cursor_settings_controller );
	}

	return rb_local_database_cursor_settings_controller;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPbdb_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_database		=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	VALUE	rb_parent_environment	=	rb_RPbdb_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPbdb_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_cursor_controller	=	rb_RPbdb_DatabaseCursor_parentDatabaseCursorController( rb_database_cursor );
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursorController_parentDatabase( rb_parent_cursor_controller );
	
	return rb_parent_database;
}

/**************************************
*  parent_database_cursor_controller  *
**************************************/
VALUE rb_RPbdb_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_cursor_controller		=	rb_iv_get(	rb_database_cursor,
																										RPBDB_RB_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER );
	return rb_parent_cursor_controller;
}

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPbdb_DatabaseCursor_open( VALUE	rb_database_cursor )	{
	
	RPbdb_DatabaseCursor*		c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_DatabaseCursor_open( c_database_cursor );

	return rb_database_cursor;
}

/*************
*  is_open?  *
*************/

VALUE rb_RPbdb_DatabaseCursor_isOpen( VALUE	rb_database_cursor )	{

	RPbdb_DatabaseCursor*		c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return RPbdb_DatabaseCursor_isOpen( c_database_cursor )	?	Qtrue
																													:	Qfalse;
}
	
/**********
*  close  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_close.html
VALUE rb_RPbdb_DatabaseCursor_close( VALUE	rb_database_cursor )	{

	RPbdb_DatabaseCursor*		c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_DatabaseCursor_close( c_database_cursor );

	return rb_database_cursor;
}

/*********************
*  duplicate_cursor  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPbdb_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor )	{

	RPbdb_DatabaseCursor*		c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_DatabaseCursor*		c_duplicate_cursor	=	RPbdb_DatabaseCursor_duplicateCursor( c_database_cursor );

	VALUE	rb_duplicate_cursor	=	RUBY_RPBDB_DATABASE_CURSOR( c_duplicate_cursor );

 	return rb_duplicate_cursor;
}

/*******************************************************************************************************************************************************************************************
																	Writing Data
*******************************************************************************************************************************************************************************************/

/**********************
*  overwrite_current  *
**********************/

//	DB_CURRENT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_overwriteCurrent(	VALUE	rb_database_cursor, 
                                                VALUE	rb_data )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Database*	c_parent_database	=	c_database_cursor->parent_database_cursor_controller->parent_database;

	RPbdb_Record*    c_record	=	RPbdb_Record_new( c_parent_database );

	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );

	RPbdb_DatabaseCursor_overwriteCurrentDataWithRecord(	c_database_cursor,
																											c_record	);
	
	return rb_database_cursor;
}

/*************************************
*  write_as_duplicate_after_current  *
*************************************/

//	DB_AFTER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																														VALUE	rb_data )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_DatabaseCursor_writeRecordAsDuplicateDataAfterCurrent(	c_database_cursor,
																															c_record	);

	return rb_database_cursor;
}

/**************************************
*  write_as_duplicate_before_current  *
**************************************/

//	DB_BEFORE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																														VALUE	rb_data )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_DatabaseCursor_writeRecordAsDuplicateBeforeCurrent(	c_database_cursor,
																														c_record	);

	return rb_database_cursor;
}

/********************************
*  write_before_any_duplicates  *
********************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting before duplicates. 
//	DB_KEYFIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_writeBeforeAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

  //  FIX - ensure open

	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;

	/*------------------------------------------------------*/

	VALUE	rb_key_or_key_data_hash	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_key_or_key_data_hash,
								& rb_data );

	//	if we have a hash we expect key => data
	if ( TYPE( rb_key_or_key_data_hash ) == T_HASH )	{
		VALUE	rb_key_data_array	=	Qnil;
		rb_key_data_array	=	rb_funcall( rb_key_or_key_data_hash,
																		rb_intern( "first" ),
																		0 );
		rb_key						=	rb_ary_shift( rb_key_data_array );
		rb_data						=	rb_ary_shift( rb_key_data_array );
	}
	//	otherwise we have key, data
	else {
		rb_key						=	rb_key_or_key_data_hash;
	}

	if ( rb_key == Qnil )	{
		rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );	
	}
	else if ( rb_data == Qnil )	{		
		rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );
	}

	/*------------------------------------------------------*/

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );

	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_DatabaseCursor_writeRecordBeforeAnyDuplicates(	c_database_cursor,
																											c_record	);

	return rb_database_cursor;
}

/*******************************
*  write_after_any_duplicates  *
*******************************/

//	If the key already exists in the database and no duplicate sort function has been specified, 
//	the inserted data item is added as the first of the data items for that key.
//	If duplicate sort function has been specified, it will be used rather than inserting after duplicates. 
//	DB_KEYLAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_writeAfterAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

  //  FIX - ensure open

	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;

	/*------------------------------------------------------*/

	VALUE	rb_key_or_key_data_hash	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_key_or_key_data_hash,
								& rb_data );

	//	if we have a hash we expect key => data
	if ( TYPE( rb_key_or_key_data_hash ) == T_HASH )	{
		VALUE	rb_key_data_array	=	Qnil;
		rb_key_data_array	=	rb_funcall( rb_key_or_key_data_hash,
																		rb_intern( "first" ),
																		0 );
		rb_key						=	rb_ary_shift( rb_key_data_array );
		rb_data						=	rb_ary_shift( rb_key_data_array );
	}
	//	otherwise we have key, data
	else {
		rb_key						=	rb_key_or_key_data_hash;
	}

	if ( rb_key == Qnil )	{
		rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );	
	}
	else if ( rb_data == Qnil )	{		
		rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );
	}

	/*------------------------------------------------------*/

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_DatabaseCursor_writeRecordAfterAnyDuplicates(		c_database_cursor,
																												c_record	);

	return rb_database_cursor;
}

/**********************************
*  write_only_if_not_in_database  *
**********************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPbdb_DatabaseCursor_writeOnlyIfNotInDatabase(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

  //  FIX - ensure open

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_data																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database_cursor,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 2 ),
			":index, [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 5 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	if ( RPbdb_DatabaseCursor_writeRecordOnlyIfNotInDatabase(	c_database_cursor,
																														c_record	) == FALSE )	{
		return Qfalse;
	}
																	
	return Qtrue;
}

/*******************************************************************************************************************************************************************************************
																	Retrieval
*******************************************************************************************************************************************************************************************/

/***************
*  key_exists  *
***************/

VALUE rb_RPbdb_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
																				VALUE	rb_key )	{

  //  FIX - ensure open

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );
  VALUE rb_has_key  = ( RPbdb_DatabaseCursor_keyExists(	c_database_cursor,
                                                        c_record->key	)	?	Qtrue
                                                                        :	Qfalse );
    
	return rb_has_key;
}

/*************
*  retrieve  *
*************/

VALUE rb_RPbdb_DatabaseCursor_retrieve(	int       argc,
																				VALUE*    args,
																				VALUE     rb_database_cursor )	{

  //  internal retrieve record will ensure open

	RPbdb_Record*	c_record	=	rb_RPbdb_DatabaseCursor_internal_retrieveRecord(	argc,
																																						args,
																																						rb_database_cursor );

  VALUE rb_data	=	Qnil;
  if ( c_record->result )	{

    VALUE rb_database = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

    rb_data = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->data,
                                                                  FALSE );
  }
  
  return rb_data;
}

/*****************
*  retrieve_key  *
*****************/

VALUE rb_RPbdb_DatabaseCursor_retrieveKey(	int     argc,
																					VALUE*	args,
																					VALUE   rb_database_cursor )	{

  //  internal retrieve record will ensure open

	RPbdb_Record*	c_record	=	rb_RPbdb_DatabaseCursor_internal_retrieveRecord(	argc,
																																						args,
																																						rb_database_cursor );

  VALUE rb_key	=	Qnil;
    if ( c_record->result )	{

    VALUE rb_database = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

    rb_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->key,
                                                                  TRUE );
  }
	
  return rb_key;
}

/*************************
*  retrieve_primary_key  *
*************************/

VALUE rb_RPbdb_DatabaseCursor_retrievePrimaryKey(	int     argc,
                                                  VALUE*	args,
                                                  VALUE   rb_database_cursor )	{

  //  internal retrieve record will ensure open

	RPbdb_Record*	c_record	=	rb_RPbdb_DatabaseCursor_internal_retrieveRecord(	argc,
																																						args,
																																						rb_database_cursor );

  VALUE rb_primary_key	=	Qnil;
  if ( c_record->result )	{

    VALUE rb_database = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

    rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                          c_record->primary_key,
                                                                          TRUE );
  }
	
  return rb_primary_key;
}

/*************************
*  retrieve_partial_key  *
*  partial_key           *
*  retrieve_partial      *
*************************/

VALUE rb_RPbdb_DatabaseCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																									VALUE	rb_partial_key )	{

  //  FIX - ensure open

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	RPbdb_Database*	c_parent_database;
	C_RPBDB_DATABASE( rb_parent_database, c_parent_database );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_parent_database );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_partial_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );

	RPbdb_DatabaseCursor_retrievePartialKeyInRecord(	c_database_cursor,
																									c_record );

  VALUE rb_key	=	Qnil;
  if ( c_record->result )	{

    VALUE rb_database = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

    rb_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->key,
                                                                  TRUE );
  }
	
  return rb_key;
}

/**************************
*  retrieve_partial_data  *
*  partial_data           *
**************************/

//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPbdb_DatabaseCursor_retrieveDuplicateMatchingPartialData(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_database_cursor )	{

  //  FIX - ensure open

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_data																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database_cursor,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 2 ),
			":index, [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 5 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	RPbdb_Database*	c_parent_database;
	C_RPBDB_DATABASE( rb_parent_database, c_parent_database );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_parent_database );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										TRUE );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );

	c_record	=	RPbdb_DatabaseCursor_retrieveDuplicateMatchingPartialDataInRecord( c_database_cursor,
																																								c_record );

  if ( c_record->result )	{

    VALUE rb_database = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

    rb_data = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->data,
                                                                  FALSE );
  }

  return rb_data;
}

/*******************************************************************************************************************************************************************************************
																Relative to Current Key
*******************************************************************************************************************************************************************************************/

/*********************
*  retrieve_current  *
*  current           *
*********************/

VALUE rb_RPbdb_DatabaseCursor_current(	VALUE	rb_database_cursor )	{

  //  retrieve ensures open

	return rb_RPbdb_DatabaseCursor_retrieve(	0,
																					NULL,
																					rb_database_cursor );
}

/*************************
*  retrieve_current_key  *
*  current_key           *
*************************/

VALUE rb_RPbdb_DatabaseCursor_currentKey(	VALUE	rb_database_cursor )	{

  //  retrieve key ensures open

	return rb_RPbdb_DatabaseCursor_retrieveKey(	0,
																							NULL,
																							rb_database_cursor );
}

/*********************************
*  retrieve_current_primary_key  *
*  current_primary_key           *
*********************************/

VALUE rb_RPbdb_DatabaseCursor_currentPrimaryKey(	VALUE	rb_database_cursor )	{

  //  retrieve primary key ensures open

	return rb_RPbdb_DatabaseCursor_retrievePrimaryKey(	0,
                                                    NULL,
                                                    rb_database_cursor );

}

/************************
*  starting_with_first  *
*  from_first           *
************************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_startingWithFirst( VALUE	rb_database_cursor )	{

  //  FIX - ensure open

	rb_RPbdb_DatabaseCursor_retrieveFirst( rb_database_cursor );

	return rb_database_cursor;
}

/*******************
*  retrieve_first  *
*  first           *
*******************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor )	{

  //  FIX - ensure open

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveFirst(	c_database_cursor );

  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/***********************
*  retrieve_first_key  *
*  first_key           *
***********************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor )	{

  //  retrieve first ensures open
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
  VALUE rb_key              = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_key;
}

/*******************************
*  retrieve_first_primary_key  *
*  first_key                   *
*******************************/

VALUE rb_RPbdb_DatabaseCursor_retrieveFirstPrimaryKey( VALUE	rb_database_cursor )	{

  //  retrieve first ensures open
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record    =	RPbdb_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
  VALUE rb_primary_key      = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_primary_key,
																										(RPbdb_DBT*) c_record->primary_key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_primary_key;

}

/******************
*  retrieve_last  *
*  last           *
******************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor )	{

  //  FIX - ensure open

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
  
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveLast(	c_database_cursor );

  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/**********************
*  retrieve_last_key  *
*  last_key           *
**********************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor )	{
	
  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveLast(	c_database_cursor );
	
  VALUE rb_key              = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_key;
}

/******************************
*  retrieve_last_primary_key  *
*  last_primary_key           *
******************************/

VALUE rb_RPbdb_DatabaseCursor_retrieveLastPrimaryKey( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record    =	RPbdb_DatabaseCursor_retrieveLast(	c_database_cursor );
	
  VALUE rb_primary_key      = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_primary_key,
																										(RPbdb_DBT*) c_record->primary_key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_primary_key;
}

/******************
*  retrieve_next  *
*  next           *
******************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveNext( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveNext(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}		

/**********************
*  retrieve_next_key  *
*  next_key           *
**********************/

//	DB_NEXT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveNextKey( VALUE	rb_database_cursor )	{

  //  retrieve next ensures open
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveNext(	c_database_cursor );
	
  VALUE rb_key              = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_key;
}		

/******************************
*  retrieve_next_primary_key  *
*  next_primary_key           *
******************************/

VALUE rb_RPbdb_DatabaseCursor_retrieveNextPrimaryKey( VALUE	rb_database_cursor )	{

  //  retrieve next ensures open
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveNext(	c_database_cursor );
	
  VALUE rb_primary_key      = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_primary_key,
																										(RPbdb_DBT*) c_record->primary_key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_primary_key;
}

/**********************
*  retrieve_previous  *
*  previous           *
**********************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/**************************
*  retrieve_previous_key  *
*  previous_key           *
**************************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor )	{
	
  //  retrieve previous ensures open
  
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
  VALUE rb_key              = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_key,
																										(RPbdb_DBT*) c_record->key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_key;
}

/**********************************
*  retrieve_previous_primary_key  *
*  previous_primary_key           *
**********************************/

VALUE rb_RPbdb_DatabaseCursor_retrievePreviousPrimaryKey( VALUE	rb_database_cursor )	{

  //  retrieve previous ensures open
  
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
  VALUE rb_primary_key      = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_primary_key,
																										(RPbdb_DBT*) c_record->primary_key,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_primary_key;
}

/*************************************
*  count_duplicates_for_current_key  *
*************************************/

//	Count data items for current key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_count.html
VALUE rb_RPbdb_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return	INT2FIX( RPbdb_DatabaseCursor_countDuplicatesForCurrentKey(	c_database_cursor ) );
}

/****************************
*  retrieve_next_duplicate  *
*  next_duplicate           *
****************************/

//	DB_NEXT_DUP			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveNextDuplicate(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/********************************
*  retrieve_previous_duplicate  *
*  previous_duplicate           *
********************************/

//	DB_PREV_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrievePreviousDuplicate(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/********************************
*  retrieve_next_non_duplicate  *
*  next_non_duplicate           *
********************************/

//	DB_NEXT_NODUP		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrieveNextNonDuplicate(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/************************************
*  retrieve_previous_non_duplicate  *
*  previous_non_duplicate           *
************************************/

//	DB_PREV_NODUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPbdb_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_DatabaseCursor_retrievePreviousNonDuplicate(	c_database_cursor );
	
  VALUE rb_data             = Qnil;
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																										rb_data,
																										(RPbdb_DBT*) c_record->data,
																										FALSE );
	
	RPbdb_Record_free( & c_record );
	
	return rb_data;
}

/*******************************************************************************************************************************************************************************************
                                                              Iteration
*******************************************************************************************************************************************************************************************/


/*********
*  each  *
*********/

VALUE rb_RPbdb_DatabaseCursor_iterate( VALUE		rb_database_cursor	)	{

  //  FIX - ensure open
  //  FIX - ensure there is a current
		
	//	If we don't have a block, we return an enumerator
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key            =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data           =  Qnil;
  VALUE rb_database       = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterate( c_database_cursor, c_record ) ) != NULL )	{

    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/********************
*  each_with_index  *
********************/

VALUE rb_RPbdb_DatabaseCursor_iterateWithIndex( VALUE		rb_database_cursor	)	{

  //  FIX - ensure open
  //  FIX - ensure there is a current
		
	//	If we don't have a block, we return an enumerator
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key   =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterate( c_database_cursor, c_record ) ) != NULL )	{

    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/**********************
*  each_duplicate  *
**********************/

//	iterates all records with one or more duplicates
VALUE rb_RPbdb_DatabaseCursor_iterateDuplicates(	VALUE		rb_database_cursor )	{
	
  //  FIX - ensure open
  //  FIX - ensure there is a current
  
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key  = Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data = Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateDuplicates( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/******************************
*  each_duplicate_with_index  *
******************************/

//	iterates all records with one or more duplicates
VALUE rb_RPbdb_DatabaseCursor_iterateDuplicatesWithIndex(	VALUE		rb_database_cursor )	{
	
  //  FIX - ensure open
  //  FIX - ensure there is a current
  
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key  = Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data = Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateDuplicates( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*************
*  each_key  *
*************/

//	iterates all keys without iterating duplicate records
VALUE rb_RPbdb_DatabaseCursor_iterateKeys(	VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key   =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      & c_index );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/************************
*  each_key_with_index  *
************************/

//	iterates all keys without iterating duplicate records
VALUE rb_RPbdb_DatabaseCursor_iterateKeysWithIndex(	VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key   =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*********************
*  each_primary_key  *
*********************/

VALUE rb_RPbdb_DatabaseCursor_iteratePrimaryKeys( VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key            = Qnil;
  VALUE rb_primary_key    = Qnil;
  VALUE rb_data           = Qnil;
  VALUE rb_database       = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_primary_key,
                                                                      rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/********************************
*  each_primary_key_with_index  *
********************************/

VALUE rb_RPbdb_DatabaseCursor_iteratePrimaryKeysWithIndex( VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_primary_key    = Qnil;
  VALUE rb_key           = Qnil;
  VALUE rb_data           = Qnil;
  VALUE rb_database       = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*******************************************************************************************************************************************************************************************
                                                                    Slices
*******************************************************************************************************************************************************************************************/

/**********
*  slice  *
**********/

VALUE rb_RPbdb_DatabaseCursor_slice( int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor	)	{

  //  FIX - ensure open
  //  FIX - ensure there is a current
		
	//	If we don't have a block, we return an enumerator
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );
	
	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );
	
	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key   =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_slice( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
    if ( c_record->result )	{

      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	//	If we got here we return nothing
	return Qnil;
}

/*********************
*  slice_duplicates  *
*********************/

//	iterates all records with one or more duplicates
VALUE rb_RPbdb_DatabaseCursor_sliceDuplicates(	int			argc,
																							VALUE*	args,
																							VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current
	
	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key  = Qnil;
  VALUE rb_data = Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_sliceDuplicates( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
      
    if ( c_record->result )	{

      rb_data = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                    c_record->data,
                                                                    FALSE );
      rb_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                    c_record->key,
                                                                    TRUE );
    }
		
		YIELD_BLOCK_FOR_DATA_INDEX( rb_key,
																rb_data,
																c_index );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/***************
*  slice_keys  *
***************/

//	iterates all keys without iterating duplicate records
VALUE rb_RPbdb_DatabaseCursor_sliceKeys(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key   =  Qnil;
  VALUE rb_primary_key    =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_sliceKeys( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
    if ( c_record->result )	{

      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      rb_primary_key,
                                                                      NULL );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/***********************
*  slice_primary_keys  *
***********************/

VALUE rb_RPbdb_DatabaseCursor_slicePrimaryKeys(	int			argc,
                                                VALUE*	args,
                                                VALUE		rb_database_cursor )	{

  //  FIX - ensure open
  //  FIX - ensure there is a current

	R_ReturnEnumeratorIfNoBlock(	0,
																NULL,
																rb_database_cursor );

	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPbdb_Record*	c_record	=	NULL;
  VALUE rb_key            = Qnil;
  VALUE rb_primary_key   =  Qnil;
  VALUE rb_data  =  Qnil;
  VALUE rb_database     = rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
	while ( ( c_record = RPbdb_DatabaseCursor_sliceKeys( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
    if ( c_record->result )	{

      rb_data         = rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->data,
                                                                            FALSE );
      rb_key          =	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->key,
                                                                            TRUE );
      rb_primary_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                            c_record->primary_key,
                                                                            TRUE );
    }
		
    rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( rb_primary_key,
                                                                      rb_key,
                                                                      rb_data,
                                                                      rb_database,
                                                                      & c_index );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/*******************************************************************************************************************************************************************************************
																	Deleting Data
*******************************************************************************************************************************************************************************************/

/***********
*  delete  *
***********/

//	Deletes key/pair to which database_cursor refers
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_del.html
VALUE rb_RPbdb_DatabaseCursor_delete(	int			argc,
																			VALUE*	args,
																			VALUE		rb_database_cursor )	{
  
  //  we don't need to ensure open here because it will happen in whichever function we call

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	no args: delete current
	if ( argc == 0 )	{
		RPbdb_DatabaseCursor_deleteCurrentRecord( c_database_cursor );
	}
	else	{
	
		VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );
		rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																											args[ 0 ],
																											(RPbdb_DBT*) c_record->key,
																											TRUE );
		
		//	1 arg - key, record, raw, or record number (if recno)
		if ( argc == 1 )	{
			RPbdb_DatabaseCursor_deleteRecord(	c_database_cursor,
																				c_record	);
			//	FIX - for recno
			//	record	=	RPbdb_DatabaseCursor_deleteRecordWithNumber();
		}
		
		//	2 args - match entire set
		if ( argc == 2 )	{
			
			rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																												args[ 1 ],
																												(RPbdb_DBT*) c_record->data,
																												FALSE );
			
			//	FIX - make sure deleteRecord supports exact pair deletion
			RPbdb_DatabaseCursor_deleteRecord(	c_database_cursor,
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

/*******************
*  retrieveRecord  *
*******************/

RPbdb_Record* rb_RPbdb_DatabaseCursor_internal_retrieveRecord(	int			argc,
																															VALUE*	args,
																															VALUE		rb_database_cursor )	{

  //  FIX - ensure open
	
	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;	
	R_DefineAndParse( argc, args, rb_database_cursor,
		R_DescribeParameterSet(
			R_ParameterSet(					R_Parameter(					R_MatchAny( rb_key ) ),
															R_OptionalParameter(	R_MatchAny( rb_data ) )
			),
			1,
			"<key>",
			"<key>, <value>"
		)
	)
	
	VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_database_cursor );

	RPbdb_DatabaseCursor*	c_database_cursor;
	C_RPBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	if (		rb_key == Qnil
			&&	rb_data == Qnil
      &&  ! argc )	{
		
		c_record	=	RPbdb_DatabaseCursor_retrieveCurrent(	c_database_cursor );
	}
	else	{
	
		rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																											rb_key,
																											(RPbdb_DBT*) c_record->key,
																											TRUE );

		if ( rb_data != Qnil )	{
			
			rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_parent_database,
																												rb_data,
																												(RPbdb_DBT*) c_record->data,
																												FALSE );
		}
		
		c_record = RPbdb_DatabaseCursor_retrieveRecord(	c_database_cursor,
																										c_record );
		
	}

	return c_record;	
}

/*************************************
*  yieldDataPrimaryKeyKeyAndOrIndex  *
*************************************/

VALUE rb_RPbdb_DatabaseCursor_internal_yieldDataPrimaryKeyKeyAndOrIndex( VALUE   arg1,
                                                                        VALUE   arg2,
                                                                        VALUE   arg3,
                                                                        VALUE   arg4,
                                                                        int*    c_index ) {

  //  get a reference to our provided block
  VALUE rb_block  = rb_block_proc();
    
  //  get block arity
	VALUE	rb_arity	=	rb_funcall(	rb_block,
																rb_intern( "arity" ),
																0 );

	int	c_arity	=	FIX2INT( rb_arity );

  //  if index:
  //
  //  1:  error - insufficient block arity
  //  2:  arg1,  index
  //  3:  arg1,  arg2,  index
  //  4:  arg1,  arg2,  arg3,  index
  //  -1: arg1,  arg2,  arg3,  index
  //  -2: arg1,  arg2,  arg3,  index
  //
  
  if ( c_index != NULL )  {
    switch ( c_arity )	{
      
      //	* 5 args gets arg1,  arg2,  arg3,  index
      //	-1 (*args) and -2 (arg, *args) are the same as 3
      case 5:			
      case -1:
      case -2:
        return rb_yield_values( 5,
                                arg1,
                                arg2,
                                arg3,
                                arg4,
                                c_index );
        break;

      case 4:
        return rb_yield_values( 4,
                                arg1,
                                arg2,
                                arg3,
                                c_index );
        break;

      //	* 3 args gets arg1,  arg2,  index
      case 3:
        return rb_yield_values( 3,
                                arg1,
                                arg2,
                                c_index );
        break;

      //	* 2 args gets arg[0], index
      case 2:
        return rb_yield_values( 2,
                                arg1,
                                c_index );
        break;

      default:
        rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_ITERATION );
        break;
    }

  }
  else  {

    //  without index:
    //
    //  if we have an index it goes last
    //  that means we have 1, 2, or 3 arguments then possibly an index
    //
    //  1:  arg1
    //  2:  arg1,  arg2
    //  3:  arg1,  arg2,  arg3
    //  4:  arg1,  arg2,  arg3,  index
    //  -1: arg1,  arg2,  arg3,  index
    //  -2: arg1,  arg2,  arg3,  index
    switch ( c_arity )	{
      
      //	* 4 args gets arg1,  arg2,  arg3,  index
      //	-1 (*args) and -2 (arg, *args) are the same as 4
      case 4:
      case -1:
      case -2:
        return rb_yield_values( 4,
                                arg1,
                                arg2,
                                arg3,
                                arg4 );
        break;

      //	* 3 args gets arg1,  arg2,  arg3
      case 3:
        return rb_yield_values( 3,
                                arg1,
                                arg2,
                                arg3 );
        break;

      //	* 2 args gets arg1,  arg2
      case 2:
        return rb_yield_values( 2,
                                arg1,
                                arg2 );
        break;

      //	* 1 arg gets arg1
      case 1:
        return rb_yield_values( 1,
                                arg1 );
        break;
      
      default:
        rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_ITERATION );
        break;
    }
  }

  rb_raise( rb_eRuntimeError, "Should never have gotten here." );

  return Qnil;
}
