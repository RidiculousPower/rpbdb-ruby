/*
 *		RPDB::JoinController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseJoinController.h"

#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseJoinController.h>
#include <rpdb/RPDB_DatabaseJoinCursor.h>

#include <rpdb/RPDB_DatabaseJoinSettingsController.h>
#include <rpdb/RPDB_DatabaseCursor.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_DatabaseJoinController;
VALUE	extern	rb_RPDB_DatabaseJoinCursor;
VALUE	extern	rb_RPDB_DatabaseJoinSettingsController;
VALUE	extern	rb_RPDB_DatabaseCursor;
VALUE	extern	rb_RPDB_Database;

void Init_RPDB_DatabaseJoinController()	{

	rb_RPDB_DatabaseJoinController		=	rb_define_class_under(	rb_RPDB_Database,				
																															"JoinController",				
																															rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseJoinController, 	"new",													rb_RPDB_DatabaseJoinController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"initialize",										rb_RPDB_DatabaseJoinController_init,										-1 	);
		
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"settings_controller",					rb_RPDB_DatabaseJoinController_settingsController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"settings",											"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"set",													"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"set_to",												"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"is_set_to",										"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"parent_environment",						rb_RPDB_DatabaseJoinController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"environment",									"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"parent_database",							rb_RPDB_DatabaseJoinController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"database",											"parent_database"	);
	                  					
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"join",													rb_RPDB_DatabaseJoinController_join,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"cursor",												"join"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"close_all_cursors",						rb_RPDB_DatabaseJoinController_closeAllCursors,					-1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_database_join_controller_class __attribute__((unused)) )	{

	VALUE	rb_parent_database	=	Qnil;

	/*------------------------------------------------------*/

	VALUE	rb_parent_database_or_environment				=	Qnil;
	VALUE	rb_parent_database_name_in_environment	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_parent_database_or_environment,
								& rb_parent_database_name_in_environment );

	if ( rb_parent_database_name_in_environment == Qnil )	{
		rb_parent_database = rb_parent_database_or_environment;
	}
	else {
		VALUE	rb_parent_environment		=	rb_parent_database_or_environment;
		VALUE	rb_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_RPDB_Database_new( 1,
																								& rb_database_controller,
																								rb_RPDB_Database );
	}

	/*------------------------------------------------------*/
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	VALUE	rb_join_controller	=	RUBY_RPDB_DATABASE_JOIN_CONTROLLER( RPDB_DatabaseJoinController_new( c_parent_database ) );

	rb_iv_set(	rb_join_controller,
							RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE,
							rb_parent_database );

	rb_obj_call_init(	rb_join_controller,
										1, 
										& rb_parent_database );
	
	return rb_join_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinController_init(	int			argc __attribute__ ((unused)),
																						VALUE*	args __attribute__ ((unused)),
																						VALUE		rb_join_controller )	{

	return rb_join_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseJoinController_settingsController(	VALUE	rb_database_join_controller )	{

	VALUE	rb_database_join_settings_controller	=	Qnil;
	
	if ( ( rb_database_join_settings_controller = rb_iv_get(	rb_database_join_controller,
																														RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_DatabaseJoinController*		c_database_join_controller;
		C_RPDB_DATABASE_JOIN_CONTROLLER( rb_database_join_controller, c_database_join_controller );
	
		RPDB_DatabaseJoinSettingsController*	c_database_join_settings_controller	=	RPDB_DatabaseJoinController_settingsController( c_database_join_controller );

		rb_database_join_settings_controller	=	RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller );

		rb_iv_set(	rb_database_join_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER,
								rb_database_join_settings_controller );
	}

	return rb_database_join_settings_controller;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller )	{

	VALUE	rb_parent_database	=	rb_RPDB_DatabaseJoinController_parentDatabase( rb_join_controller );
	
	VALUE	rb_parent_environment	=	rb_RPDB_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPDB_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller )	{
	
	VALUE	rb_parent_database	=		rb_iv_get(	rb_join_controller,
																						RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE );
	return rb_parent_database;
}

/****************
*  join         *
*  join_cursor  *
*  cursor       *
****************/

//	args:
//		:index => value, ...
//		positioned cursor, ...
VALUE rb_RPDB_DatabaseJoinController_join(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller )	{
	
	//	parse args and sort out cursors and hash descriptors
	
	//	retrieve positioned cursors for hash descriptors
	
	//	call join_cursor_list on set of cursors, 
	//	which now include cursors corresponding to passed hash descriptors
	
	
}

/*********************
*  join_cursor_list  *
*  join_cursors      *
*********************/

//	The curslist parameter contains a NULL terminated array of cursors. Each database_cursor must have been initialized to refer to the key 
//	on which the underlying database should be joined. Typically, this initialization is done by a DBcursor->get call with the 
//	DB_SET flag specified. Once the cursors have been passed as part of a curslist, they should not be accessed or modified until 
//	the newly created join database_cursor has been closed, or else inconsistent results may be returned.
//
//	the best join performance normally results from sorting the cursors from the one that refers to the least number of data items 
//	to the one that refers to the most. By default, DB->join does this sort on behalf of its caller.
//
//	For the returned join database_cursor to be used in a transaction-protected manner, the cursors listed in curslist must have been created within the context of the same transaction.
//
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
//	Assumes that all cursors in list have the same primary database (the first will be used)
//
//	Join cursors have the same name as the Database database_cursor that was used to initalize them
VALUE rb_RPDB_DatabaseJoinController_joinCursorList(	int			argc,
																											VALUE*	args,
																											VALUE		rb_join_controller )	{

	VALUE	rb_cursor_list	=	Qnil;

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
	
	VALUE	rb_this_cursor		=	Qnil;
	RPDB_DatabaseCursor**	c_cursor_list	=	calloc( RARRAY_LEN( rb_cursor_list ) + 1, sizeof( RPDB_DatabaseCursor* ) );
	int		which_cursor_index	=	0;
	for( which_cursor_index = 0 ; which_cursor_index < RARRAY_LEN( rb_cursor_list ) ; which_cursor_index++ )	{

		rb_this_cursor	=	RARRAY_PTR( rb_cursor_list )[ which_cursor_index ];
		
		//	Get c pointer to RPDB_DatabaseCursor
		C_RPDB_DATABASE_CURSOR( rb_this_cursor, c_cursor_list[ which_cursor_index ] );
	}
	
	//	cap off list with a NULL pointer
	c_cursor_list[ which_cursor_index++ ]	=	NULL;
		
	RPDB_DatabaseJoinCursor*	c_join_cursor	=	RPDB_DatabaseJoinController_join(	c_join_controller,
																																							c_cursor_list );
							
	return RUBY_RPDB_DATABASE_JOIN_CURSOR( c_join_cursor );
	
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_RPDB_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );

	RPDB_DatabaseJoinController_closeAllCursors( c_join_controller );

	return rb_join_controller;
}
