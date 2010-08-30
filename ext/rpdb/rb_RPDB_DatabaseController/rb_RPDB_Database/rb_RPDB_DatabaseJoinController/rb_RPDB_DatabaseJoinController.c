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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseJoinController.h>
#include <rpdb/RPDB_DatabaseJoinCursor.h>
#include "rb_RPDB_DatabaseJoinController.h"

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
	
	rb_define_singleton_method(	rb_RPDB_DatabaseJoinController, 	"new",													rb_RPDB_DatabaseJoinController_new,											1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"initialize",										rb_RPDB_DatabaseJoinController_init,										1 	);
		
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
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"cursor_for_name",						rb_RPDB_DatabaseJoinController_cursorForName,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"cursor",												"cursor_for_name"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"for_name",										"cursor_for_name"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"[]",														"cursor_for_name"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"close_cursor_for_name",			rb_RPDB_DatabaseJoinController_closeCursorForName,		-1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"all_cursors",									rb_RPDB_DatabaseJoinController_allCursors,							-1 	);
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

VALUE rb_RPDB_DatabaseJoinController_new(	VALUE	klass __attribute__((unused)),
																					VALUE	rb_parent_database __attribute__((unused)) )	{
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	VALUE	rb_join_controller	=	RUBY_RPDB_DATABASE_JOIN_CONTROLLER( RPDB_DatabaseJoinController_new( c_parent_database ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database;
	
	rb_obj_call_init(	rb_join_controller,
						1, 
						argv );
	
	return rb_join_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinController_init(	VALUE	rb_join_controller,
																						VALUE	rb_parent_environment __attribute__((unused)) )	{

	return rb_join_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseJoinController_settingsController(	VALUE	rb_join_controller )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );

	return RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( RPDB_DatabaseJoinController_settingsController( c_join_controller ) );
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseJoinController_parentEnvironment( c_join_controller ) );

}

/***************************************
*  database  *
***************************************/
VALUE rb_RPDB_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller )	{
	
	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
	
	return RUBY_RPDB_DATABASE( RPDB_DatabaseJoinController_parentDatabase( c_join_controller ) );
	
}

/************
*  join  *
************/

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
VALUE rb_RPDB_DatabaseJoinController_join(	VALUE	rb_join_controller,
																VALUE	rb_join_cursor_name,
																VALUE	rb_cursor_list )	{

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
	
	char*	c_join_cursor_name	=	StringValuePtr( rb_join_cursor_name );
	
	
	RPDB_DatabaseJoinCursor*	c_join_cursor	=	RPDB_DatabaseJoinController_join(	c_join_controller,
																						c_join_cursor_name,
																						c_cursor_list );
							
	return RUBY_RPDB_DATABASE_JOIN_CURSOR( c_join_cursor );
	
}

/*************************
*  cursorForName  *
*************************/

VALUE rb_RPDB_DatabaseJoinController_cursorForName(	VALUE	rb_join_controller,
 														VALUE	rb_join_cursor_name )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
							
	return RUBY_RPDB_DATABASE_CURSOR( RPDB_DatabaseJoinController_cursorForName(	c_join_controller,
																						StringValuePtr( rb_join_cursor_name ) ) );
}

/*****************************
*  closeCursorForName  *
*****************************/

VALUE rb_RPDB_DatabaseJoinController_closeCursorForName(	VALUE	rb_join_controller,
 																VALUE	rb_join_cursor_name )	{
	
	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
							
	RPDB_DatabaseJoinController_closeCursorForName(	c_join_controller,
												StringValuePtr( rb_join_cursor_name )	);

	return rb_join_controller;
}

/*****************
*  allCursors  *
*****************/

//	Return a list of database names that have been created and stored in this controller
VALUE rb_RPDB_DatabaseJoinController_allCursors( VALUE	rb_join_controller )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
							
	RPDB_DatabaseJoinController_allCursors( c_join_controller );

	return rb_join_controller;
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
