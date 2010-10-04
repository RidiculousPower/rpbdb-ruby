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


#include "rb_RPDB_DatabaseCursor.h"
#include "rb_RPDB_DatabaseCursor_internal.h"
#include "rb_RPDB_DatabaseCursorController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database_internal.h"

#include "rb_RPDB_DatabaseObject_internal.h"

#include <rpdb/RPDB_DatabaseCursor.h>
#include <rpdb/RPDB_DatabaseCursorController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseCursor.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>

#define RPDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED "Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursor;
extern	VALUE	rb_RPDB_DatabaseCursorController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseController;

void Init_RPDB_DatabaseCursor()	{

	rb_RPDB_DatabaseCursor		=	rb_define_class_under(	rb_RPDB_DatabaseCursorController, 
																											"Cursor",				
																											rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursor, 	"new",																	rb_RPDB_DatabaseCursor_new,															-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"initialize",														rb_RPDB_DatabaseCursor_init,														-1 	);

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
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"parent_database_cursor_controller",		rb_RPDB_DatabaseCursor_parentDatabaseCursorController,	0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"parent_cursor_controller",							"parent_database_cursor_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"cursor_controller",										"parent_database_cursor_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"open",																	rb_RPDB_DatabaseCursor_open,														0 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"is_open?",															rb_RPDB_DatabaseCursor_isOpen,													0 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"close",																rb_RPDB_DatabaseCursor_close,														0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"duplicate",														rb_RPDB_DatabaseCursor_duplicateCursor,									0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"delete",																rb_RPDB_DatabaseCursor_delete,													-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"overwrite_current",										rb_RPDB_DatabaseCursor_overwriteCurrent,									1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_as_duplicate_after_current",			rb_RPDB_DatabaseCursor_writeAsDuplicateAfterCurrent,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_after_current",									"write_as_duplicate_after_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_as_duplicate_before_current",		rb_RPDB_DatabaseCursor_writeAsDuplicateBeforeCurrent,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_before_current",									"write_as_duplicate_before_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_before_any_duplicates",					rb_RPDB_DatabaseCursor_writeBeforeAnyDuplicates,				-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_before_duplicates",							"write_before_any_duplicates"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_after_any_duplicates",						rb_RPDB_DatabaseCursor_writeAfterAnyDuplicates,					-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write_after_duplicates",								"write_after_any_duplicates"	);

	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"write",																"write_after_any_duplicates"	);

	//	FIX - shouldn't there be a corresponding function for the database?
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"write_only_if_not_in_database",				rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase,						-1 	);
                    					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"key_exists?",													rb_RPDB_DatabaseCursor_keyExists,														1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"exists?",															"key_exists?"	);

	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve",															rb_RPDB_DatabaseCursor_retrieve,														-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"move_cursor_to",												"retrieve"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"move_cursor",													"retrieve"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"move_to",															"retrieve"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_key",													rb_RPDB_DatabaseCursor_retrieveKey,													-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"key",																	"retrieve_key"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_partial_key",									rb_RPDB_DatabaseCursor_retrievePartialKey,									1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"partial_key",													"retrieve_partial_key"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_partial",											"retrieve_partial_key"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_duplicate_matching_partial_data",			rb_RPDB_DatabaseCursor_retrieveDuplicateMatchingPartialData,									-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_duplicate_for_partial_data",					"retrieve_duplicate_matching_partial_data"	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"retrieve_partial_data",												"retrieve_duplicate_matching_partial_data"	);

	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_current",											rb_RPDB_DatabaseCursor_current,															0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"current",															"retrieve_current"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_current_key",									rb_RPDB_DatabaseCursor_currentKey,													0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"current_key",													"retrieve_current_key"	);                            				
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"retrieve_first",												rb_RPDB_DatabaseCursor_retrieveFirst,												0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"first",																"retrieve_first"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"starting_with_first",									rb_RPDB_DatabaseCursor_startingWithFirst,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"from_first",														"starting_with_first"	);
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
                    					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"count_duplicates_for_current_key",			rb_RPDB_DatabaseCursor_countDuplicatesForCurrentKey,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"count_duplicates",											"count_duplicates_for_current_key"	);
	                  					                                                              		
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate",															rb_RPDB_DatabaseCursor_iterate,															0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each",																	"iterate"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate_duplicates",										rb_RPDB_DatabaseCursor_iterateDuplicates,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each_duplicate",												"iterate_duplicates"	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"iterate_keys",													rb_RPDB_DatabaseCursor_iterateKeys,													0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursor, 	"each_key",															"iterate_keys"	);

	rb_define_method(						rb_RPDB_DatabaseCursor, 	"slice",																rb_RPDB_DatabaseCursor_slice,																-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"slice_keys",														rb_RPDB_DatabaseCursor_sliceKeys,														-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursor, 	"slice_duplicates",											rb_RPDB_DatabaseCursor_sliceDuplicates,											-1 	);
                    					                                                          				
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_DatabaseCursor_new( int			argc,
																	VALUE*	args,
																	VALUE		rb_database_cursor_class __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_cursor_controller	=	Qnil;
	
	/*------------------------------------------------------*/

	VALUE	rb_database_cursor_controller_or_database_or_database_controller_or_environment	=	Qnil;
	VALUE	rb_database_name	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_database_cursor_controller_or_database_or_database_controller_or_environment,
								& rb_database_name );
	
	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_database							=	Qnil;
	VALUE	rb_parent_database_controller		=	Qnil;

	//	figure out what our first arg is
	VALUE	rb_first_arg_klass	=	rb_obj_class( rb_database_cursor_controller_or_database_or_database_controller_or_environment );
	VALUE	rb_ancestors	=	rb_mod_ancestors( rb_first_arg_klass );
	if ( rb_ary_includes(	rb_ancestors,
												rb_RPDB_DatabaseCursorController ) == Qtrue )	{
		
		rb_parent_cursor_controller	=	rb_database_cursor_controller_or_database_or_database_controller_or_environment;
	}
	else if ( rb_ary_includes(	rb_ancestors,
															rb_RPDB_Database ) == Qtrue )	{
		
		rb_parent_database					=	rb_database_cursor_controller_or_database_or_database_controller_or_environment;
		rb_parent_cursor_controller	=	rb_RPDB_Database_cursorController( rb_parent_database );
	}
	else if ( rb_ary_includes(	rb_ancestors,
															rb_RPDB_DatabaseController ) == Qtrue )	{
		
		rb_parent_database_controller	=	rb_database_cursor_controller_or_database_or_database_controller_or_environment;
		rb_parent_database						=	rb_RPDB_DatabaseController_newDatabase(	rb_parent_database_controller,
																																						rb_database_name );
		rb_parent_cursor_controller		=	rb_RPDB_Database_cursorController( rb_parent_database );
	}
	else if ( rb_ary_includes(	rb_ancestors,
															rb_RPDB_Environment ) == Qtrue )	{
		
		rb_parent_environment					=	rb_database_cursor_controller_or_database_or_database_controller_or_environment;
		rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		rb_parent_database						=	rb_RPDB_DatabaseController_newDatabase(	rb_parent_database_controller,
																																						rb_database_name );
		rb_parent_cursor_controller		=	rb_RPDB_Database_cursorController( rb_parent_database );
	}
	else if ( TYPE( rb_database_cursor_controller_or_database_or_database_controller_or_environment ) == T_STRING )	{

		VALUE	rb_parent_environment_directory	=	rb_database_cursor_controller_or_database_or_database_controller_or_environment;
		
		rb_parent_environment	=	rb_RPDB_Environment_new(	1,
																											& rb_parent_environment_directory,
																											rb_RPDB_Environment );
		rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_RPDB_DatabaseController_newDatabase( rb_parent_environment,
																																	rb_database_name );
		rb_parent_cursor_controller	=	rb_RPDB_Database_cursorController( rb_parent_database );
	}
	
	/*------------------------------------------------------*/
	
	
	RPDB_DatabaseCursorController*		c_parent_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_parent_cursor_controller, c_parent_cursor_controller );

	RPDB_DatabaseCursor*	c_database_cursor		=	RPDB_DatabaseCursorController_cursor( c_parent_cursor_controller );
	VALUE									rb_database_cursor	=	RUBY_RPDB_DATABASE_CURSOR( c_database_cursor );

	rb_iv_set(	rb_database_cursor,
							RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER,
							rb_parent_cursor_controller );
																					
	VALUE	argv[ 1 ];	
	argv[ 0 ]	=	rb_parent_cursor_controller;
	rb_obj_call_init(	rb_database_cursor,
										1, 
										argv );
	
	return rb_database_cursor;
}

/*********
*  init  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursor_init(	int			argc __attribute__ ((unused)),
																		VALUE*	args __attribute__ ((unused)),
																		VALUE		rb_database_cursor )	{

	return rb_database_cursor;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPDB_DatabaseCursor_settingsController(	VALUE	rb_database_cursor )	{

	VALUE	rb_local_database_cursor_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_cursor_settings_controller = rb_iv_get(	rb_database_cursor,
																																		RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
		RPDB_DatabaseCursorSettingsController*	c_local_database_cursor_settings_controller	=	RPDB_DatabaseCursor_settingsController( c_database_cursor );

		rb_local_database_cursor_settings_controller	=	RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_local_database_cursor_settings_controller );

		rb_iv_set(	rb_database_cursor,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER,
								rb_local_database_cursor_settings_controller );
	}

	return rb_local_database_cursor_settings_controller;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPDB_DatabaseCursor_parentEnvironment(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_database		=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
	VALUE	rb_parent_environment	=	rb_RPDB_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPDB_DatabaseCursor_parentDatabase(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_cursor_controller	=	rb_RPDB_DatabaseCursor_parentDatabaseCursorController( rb_database_cursor );
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursorController_parentDatabase( rb_parent_cursor_controller );
	
	return rb_parent_database;
}

/**************************************
*  parent_database_cursor_controller  *
**************************************/
VALUE rb_RPDB_DatabaseCursor_parentDatabaseCursorController(	VALUE	rb_database_cursor )	{

	VALUE	rb_parent_cursor_controller		=	rb_iv_get(	rb_database_cursor,
																										RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER );
	return rb_parent_cursor_controller;
}

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursor_open( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_DatabaseCursor_open( c_database_cursor );

	return rb_database_cursor;
}

/*************
*  is_open?  *
*************/

VALUE rb_RPDB_DatabaseCursor_isOpen( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return RPDB_DatabaseCursor_isOpen( c_database_cursor )	?	Qtrue
																													:	Qfalse;
}
	
/**********
*  close  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_close.html
VALUE rb_RPDB_DatabaseCursor_close( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_DatabaseCursor_close( c_database_cursor );

	return rb_database_cursor;
}

/*********************
*  duplicate_cursor  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPDB_DatabaseCursor_duplicateCursor( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*		c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_DatabaseCursor*		c_duplicate_cursor	=	RPDB_DatabaseCursor_duplicateCursor( c_database_cursor );

	VALUE	rb_duplicate_cursor	=	RUBY_RPDB_DATABASE_CURSOR( c_duplicate_cursor );

 	return rb_duplicate_cursor;
}

/*******************************************************************************************************************************************************************************************
																	Writing Data
*******************************************************************************************************************************************************************************************/

/**********************
*  overwrite_current  *
**********************/

//	DB_CURRENT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_overwriteCurrent(	VALUE	rb_database_cursor, 
																							VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Database*	c_parent_database	=	c_database_cursor->parent_database_cursor_controller->parent_database;
	RPDB_Record*	c_record	=	RPDB_Record_new( c_parent_database );
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );

	RPDB_DatabaseCursor_overwriteCurrentDataWithRecord(	c_database_cursor,
																											c_record	);
	
	return rb_database_cursor;
}

/*************************************
*  write_as_duplicate_after_current  *
*************************************/

//	DB_AFTER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateAfterCurrent(	VALUE	rb_database_cursor, 
																														VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
	
	RPDB_DatabaseCursor_writeRecordAsDuplicateDataAfterCurrent(	c_database_cursor,
																															c_record	);

	return rb_database_cursor;
}

/**************************************
*  write_as_duplicate_before_current  *
**************************************/

//	DB_BEFORE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeAsDuplicateBeforeCurrent(	VALUE	rb_database_cursor, 
																														VALUE	rb_data )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
	
	RPDB_DatabaseCursor_writeRecordAsDuplicateBeforeCurrent(	c_database_cursor,
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
VALUE rb_RPDB_DatabaseCursor_writeBeforeAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

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
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );	
	}
	else if ( rb_data == Qnil )	{		
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );
	}

	/*------------------------------------------------------*/

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );

	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );
	
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
	
	RPDB_DatabaseCursor_writeRecordBeforeAnyDuplicates(	c_database_cursor,
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
VALUE rb_RPDB_DatabaseCursor_writeAfterAnyDuplicates(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

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
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );	
	}
	else if ( rb_data == Qnil )	{		
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );
	}

	/*------------------------------------------------------*/

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );
	
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
	
	RPDB_DatabaseCursor_writeRecordAfterAnyDuplicates(		c_database_cursor,
																												c_record	);

	return rb_database_cursor;
}

/**********************************
*  write_only_if_not_in_database  *
**********************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_put.html
VALUE rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase(	int			argc,
																												VALUE*	args,
																												VALUE		rb_database_cursor )	{

	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;
	PARSE_RUBY_ARGS_FOR_KEY_DATA_HASH_OR_ARRAY( argc, args, rb_database_cursor, rb_RPDB_DatabaseCursor_writeOnlyIfNotInDatabase, FALSE, rb_key, rb_data );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );
	
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );
	
	if ( RPDB_DatabaseCursor_writeRecordOnlyIfNotInDatabase(	c_database_cursor,
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

VALUE rb_RPDB_DatabaseCursor_keyExists(	VALUE	rb_database_cursor, 
																				VALUE	rb_key )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );
		
	return ( RPDB_DatabaseCursor_keyExists(	c_database_cursor,
																					c_record->key	)	?	Qtrue
																												:	Qfalse );
}

/*************
*  retrieve  *
*************/

VALUE rb_RPDB_DatabaseCursor_retrieve(	int	argc,
																				VALUE*	args,
																				VALUE	rb_database_cursor )	{

	RPDB_Record*	c_record	=	rb_RPDB_DatabaseCursor_internal_retrieveRecord(	argc,
																																						args,
																																						rb_database_cursor );

	RETURN_RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );
}

/*****************
*  retrieve_key  *
*****************/

VALUE rb_RPDB_DatabaseCursor_retrieveKey(	int	argc,
																					VALUE*	args,
																					VALUE	rb_database_cursor )	{
	
	RPDB_Record*	c_record	=	rb_RPDB_DatabaseCursor_internal_retrieveRecord(	argc,
																																						args,
																																						rb_database_cursor );
	
	RETURN_RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record );
}

/*************************
*  retrieve_partial_key  *
*  partial_key           *
*  retrieve_partial      *
*************************/

VALUE rb_RPDB_DatabaseCursor_retrievePartialKey(	VALUE	rb_database_cursor,
																									VALUE	rb_key )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );

	RPDB_Database*	c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_parent_database );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );

	RPDB_DatabaseCursor_retrievePartialKeyInRecord(	c_database_cursor,
																									c_record );

	RETURN_RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record );
}

/**************************
*  retrieve_partial_data  *
*  partial_data           *
**************************/

//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPDB_DatabaseCursor_retrieveDuplicateMatchingPartialData(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_database_cursor )	{

	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;
	PARSE_RUBY_ARGS_FOR_KEY_DATA_HASH_OR_ARRAY( argc, args, rb_database_cursor, rb_RPDB_DatabaseCursor_retrieveDuplicateMatchingPartialData, TRUE, rb_key, rb_data );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );

	RPDB_Database*	c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_parent_database );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_key,
																																			c_record->key->wrapped_bdb_dbt,
																																			TRUE );

	rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																			rb_data,
																																			c_record->data->wrapped_bdb_dbt,
																																			FALSE );

	c_record	=	RPDB_DatabaseCursor_retrieveDuplicateMatchingPartialDataInRecord( c_database_cursor,
																																								c_record );

	RETURN_RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );
}

/*******************************************************************************************************************************************************************************************
																Relative to Current Key
*******************************************************************************************************************************************************************************************/

/*********************
*  retrieve_current  *
*  current           *
*********************/

VALUE rb_RPDB_DatabaseCursor_current(	VALUE	rb_database_cursor )	{
	return rb_RPDB_DatabaseCursor_retrieve(	0,
																					NULL,
																					rb_database_cursor );
}

/*************************
*  retrieve_current_key  *
*  current_key           *
*************************/

VALUE rb_RPDB_DatabaseCursor_currentKey(	VALUE	rb_database_cursor )	{
	return rb_RPDB_DatabaseCursor_retrieveKey(	0,
																							NULL,
																							rb_database_cursor );
}

/************************
*  starting_with_first  *
*  from_first           *
************************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_startingWithFirst( VALUE	rb_database_cursor )	{
	rb_RPDB_DatabaseCursor_retrieveFirst( rb_database_cursor );
	return rb_database_cursor;
}

/*******************
*  retrieve_first  *
*  first           *
*******************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveFirst( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
																				RPDB_Record_dataSize( record ) );
	
	RPDB_Record_free( & record );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/***********************
*  retrieve_first_key  *
*  first_key           *
***********************/

//	DB_FIRST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveFirstKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveFirst(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
																				RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/******************
*  retrieve_last  *
*  last           *
******************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveLast( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/**********************
*  retrieve_last_key  *
*  last_key           *
**********************/

//	DB_LAST				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveLastKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveLast(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
											   RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/******************
*  retrieve_next  *
*  next           *
******************/

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

/**********************
*  retrieve_next_key  *
*  next_key           *
**********************/

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

/**********************
*  retrieve_previous  *
*  previous           *
**********************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePrevious( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/**************************
*  retrieve_previous_key  *
*  previous_key           *
**************************/

//	DB_PREV				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousKey( VALUE	rb_database_cursor )	{
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePrevious(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawKey( record ),
											   RPDB_Record_keySize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/*************************************
*  count_duplicates_for_current_key  *
*************************************/

//	Count data items for current key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_count.html
VALUE rb_RPDB_DatabaseCursor_countDuplicatesForCurrentKey( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	return	INT2FIX( RPDB_DatabaseCursor_countDuplicatesForCurrentKey(	c_database_cursor ) );
}

/****************************
*  retrieve_next_duplicate  *
*  next_duplicate           *
****************************/

//	DB_NEXT_DUP			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNextDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveNextDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/********************************
*  retrieve_previous_duplicate  *
*  previous_duplicate           *
********************************/

//	DB_PREV_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePreviousDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/********************************
*  retrieve_next_non_duplicate  *
*  next_non_duplicate           *
********************************/

//	DB_NEXT_NODUP		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrieveNextNonDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrieveNextNonDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/************************************
*  retrieve_previous_non_duplicate  *
*  previous_non_duplicate           *
************************************/

//	DB_PREV_NODUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursor_retrievePreviousNonDuplicate( VALUE	rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	record	=	RPDB_DatabaseCursor_retrievePreviousNonDuplicate(	c_database_cursor );
	
	VALUE	rb_return_string	=	rb_str_new(	(char*) RPDB_Record_rawData( record ),
												RPDB_Record_dataSize( record ) );
	
	return ( FIX2INT( rb_str_length( rb_return_string ) ) ? rb_return_string : Qnil );
}

/************
*  each  *
************/

VALUE rb_RPDB_DatabaseCursor_iterate( VALUE		rb_database_cursor	)	{
		
	//	If we don't have a block, we return an enumerator
	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_iterate( c_database_cursor, c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_KEY_DATA_INDEX( rb_record_key,
																		rb_record_data,
																		c_index );

		c_index++;
	}
	//	If we got here we return nothing
	return Qnil;
}

/**********************
*  each_duplicate  *
**********************/

//	iterates all records with one or more duplicates
VALUE rb_RPDB_DatabaseCursor_iterateDuplicates(	VALUE		rb_database_cursor )	{
	
	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_iterateDuplicates( c_database_cursor, c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_DATA_INDEX( rb_record_key,
																rb_record_data,
																c_index );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/****************
*  each_key  *
****************/

//	iterates all keys without iterating duplicate records
VALUE rb_RPDB_DatabaseCursor_iterateKeys(	VALUE		rb_database_cursor )	{

	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_iterateKeys( c_database_cursor, c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_KEY_DATA_INDEX( rb_record_key,
																		rb_record_data,
																		c_index );

		c_index++;
	}
	
	//	If we got here we return nothing
	return Qnil;
}

/**********
*  slice  *
**********/

VALUE rb_RPDB_DatabaseCursor_slice( int			argc,
																		VALUE*	args,
																		VALUE		rb_database_cursor	)	{
		
	//	If we don't have a block, we return an enumerator
	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );
	
	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );
	
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_slice( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_KEY_DATA_INDEX( rb_record_key,
																		rb_record_data,
																		c_index );

		c_index++;
	}
	//	If we got here we return nothing
	return Qnil;
}

/*********************
*  slice_duplicates  *
*********************/

//	iterates all records with one or more duplicates
VALUE rb_RPDB_DatabaseCursor_sliceDuplicates(	int			argc,
																							VALUE*	args,
																							VALUE		rb_database_cursor )	{
	
	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );

	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_sliceDuplicates( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_DATA_INDEX( rb_record_key,
																rb_record_data,
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
VALUE rb_RPDB_DatabaseCursor_sliceKeys(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database_cursor )	{

	RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_database_cursor,
																	0,
																	NULL );

	VALUE	rb_slice_length	=	Qnil;
	rb_scan_args(	argc,
								args,
								"10",
								& rb_slice_length );

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	int	c_index	=	0;
	RPDB_Record*	c_record	=	NULL;
	VALUE	rb_record_key		=	Qnil;
	VALUE	rb_record_data	=	Qnil;
	while ( ( c_record = RPDB_DatabaseCursor_sliceKeys( c_database_cursor, FIX2INT( rb_slice_length ), c_record ) ) != NULL )	{
		
		RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_record_key, rb_record_data, c_record );
		
		YIELD_BLOCK_FOR_KEY_DATA_INDEX( rb_record_key,
																		rb_record_data,
																		c_index );

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
VALUE rb_RPDB_DatabaseCursor_delete(	int			argc,
																			VALUE*	args,
																			VALUE		rb_database_cursor )	{

	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	no args: delete current
	if ( argc == 0 )	{
		RPDB_DatabaseCursor_deleteCurrentRecord( c_database_cursor );
	}
	else	{
	
		VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																				args[ 0 ],
																																				c_record->key->wrapped_bdb_dbt,
																																				TRUE );
		
		//	1 arg - key, record, raw, or record number (if recno)
		if ( argc == 1 )	{
			RPDB_DatabaseCursor_deleteRecord(	c_database_cursor,
																				c_record	);
			//	FIX - for recno
			//	record	=	RPDB_DatabaseCursor_deleteRecordWithNumber();
		}
		
		//	2 args - match entire set
		if ( argc == 2 )	{
			
			rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																					args[ 1 ],
																																					c_record->data->wrapped_bdb_dbt,
																																					FALSE );
			
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

/*******************
*  retrieveRecord  *
*******************/

RPDB_Record* rb_RPDB_DatabaseCursor_internal_retrieveRecord(	int			argc,
																															VALUE*	args,
																															VALUE		rb_database_cursor )	{
	RPDB_DatabaseCursor*	c_database_cursor;
	C_RPDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
	
	RPDB_Record*	c_record	=	RPDB_Record_new( c_database_cursor->parent_database_cursor_controller->parent_database );
	
	//	0 args - current record
	if ( argc == 0 )	{
		
		c_record	=	RPDB_DatabaseCursor_retrieveCurrent(	c_database_cursor );
	}
	else	{
		
		VALUE	rb_parent_database	=	rb_RPDB_DatabaseCursor_parentDatabase( rb_database_cursor );
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																				args[ 0 ],
																																				c_record->key->wrapped_bdb_dbt,
																																				TRUE );
		
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
			
			rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_parent_database,
																																								args[ 1 ],
																																								c_record->data->wrapped_bdb_dbt,
																																								FALSE );
			
			//	FIX - make sure that retrieveRecord supports exact key/data retrieval
		}
		
		c_record	=	RPDB_DatabaseCursor_retrieveRecord(	c_database_cursor,
																										c_record );
		
	}
	return c_record;	
}