/*
 *		RPDB::DatabaseController::Database::CursorController
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

#include <rpdb/RPDB_DatabaseCursorController.h>
#include "rb_RPDB_DatabaseCursorController.h"

#include <rpdb/RPDB_DatabaseCursor.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_Database;
VALUE	extern	rb_RPDB_DatabaseCursor;
VALUE	extern	rb_RPDB_DatabaseObjectCursor;
VALUE	extern	rb_RPDB_DatabaseCursorController;
VALUE	extern	rb_RPDB_DatabaseCursorSettingsController;

void Init_RPDB_DatabaseCursorController()	{

	rb_RPDB_DatabaseCursorController	=	rb_define_class_under(	rb_RPDB_Database, 
																															"CursorController",	
																															rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorController, 	"new",													rb_RPDB_DatabaseCursorController_new,												1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorController,		"initialize",										rb_RPDB_DatabaseCursorController_init,											1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"settings_controller",					rb_RPDB_DatabaseCursorController_settingsController,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"settings",											"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"set",													"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"set_to",												"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"is_set_to",										"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"parent_environment",						rb_RPDB_DatabaseCursorController_parentEnvironment,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"parent_environment",						"parent_environment"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"environment",									"parent_environment"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"cursor_for_name",						rb_RPDB_DatabaseCursorController_cursorForName,						-1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"cursor",												"cursor_for_name"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"for_name",										"cursor_for_name"	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"[]",														"cursor_for_name"	);
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"object_cursor_for_name",			rb_RPDB_DatabaseCursorController_objectCursorForName,			1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"object_cursor",								"object_cursor_for_name"	);
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"close_cursor_for_name",			rb_RPDB_DatabaseCursorController_closeCursorForName,			1 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"close_cursor",									"close_cursor_for_name"	);
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"close",												rb_RPDB_DatabaseCursorController_closeCursorForName,			1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorController, 	"close_all_cursors",						rb_RPDB_DatabaseCursorController_closeAllCursors,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorController, 	"close_all",										"close_all_cursors"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorController_new( 	VALUE	klass __attribute__((unused)),
																							VALUE	rb_parent_database __attribute__((unused)) )	{
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_database_cursor_controller	=	RUBY_RPDB_DATABASE_CURSOR_CONTROLLER( RPDB_DatabaseCursorController_new( c_parent_database ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database;
	
	rb_obj_call_init(	rb_database_cursor_controller,
						1, 
						argv );
	
	return rb_database_cursor_controller;	
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorController_init( 	VALUE	rb_database_cursor_controller,
																							VALUE	rb_parent_database __attribute__((unused)) )	{

	return rb_database_cursor_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseCursorController_settingsController(	VALUE	rb_database_cursor_controller )	{

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	return RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( RPDB_DatabaseCursorController_settingsController( c_database_cursor_controller ) );
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorController_parentEnvironment(	VALUE	rb_database_cursor_controller )	{

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorController_parentEnvironment( c_database_cursor_controller ) );
}

/*************
*  cursor  *
************/

VALUE rb_RPDB_DatabaseCursorController_cursor(	VALUE	rb_database_cursor_controller )	{
	
	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	return RUBY_RPDB_DATABASE_CURSOR( RPDB_DatabaseCursorController_cursor( c_database_cursor_controller ) );
}

/*********************
*  objectCursor  *
********************/

VALUE rb_RPDB_DatabaseCursorController_objectCursor(	VALUE	rb_database_cursor_controller )	{
	
	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );
	
	return RUBY_RPDB_DATABASE_OBJECT_CURSOR( RPDB_DatabaseCursorController_cursor( c_database_cursor_controller ) );
}

/*************************
*  cursorForName  *
*************************/

VALUE rb_RPDB_DatabaseCursorController_cursorForName(	int	argc,
															VALUE*	args,
															VALUE	rb_database_cursor_controller )	{

	VALUE	rb_cursor_name				=	Qnil;

	rb_scan_args(	argc, 
					args, 
					"01", 
					& rb_cursor_name );
	
	if ( rb_cursor_name == Qnil )	{
		return rb_RPDB_DatabaseCursorController_cursor( rb_database_cursor_controller );
	}

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	return RUBY_RPDB_DATABASE_CURSOR( RPDB_DatabaseCursorController_cursorForName(	c_database_cursor_controller,
																						StringValuePtr( rb_cursor_name ) ) );
}

/*************************
*  objectCursorForName  *
*************************/

VALUE rb_RPDB_DatabaseCursorController_objectCursorForName(	int	argc,
																VALUE*	args,
																VALUE	rb_database_cursor_controller )	{
	
	VALUE	rb_cursor_name				=	Qnil;
	
	rb_scan_args(	argc, 
					args, 
					"01", 
					& rb_cursor_name );
	
	if ( rb_cursor_name == Qnil )	{
		return rb_RPDB_DatabaseCursorController_objectCursor( rb_database_cursor_controller );
	}
	
	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );
	
	return RUBY_RPDB_DATABASE_OBJECT_CURSOR( RPDB_DatabaseCursorController_cursorForName(	c_database_cursor_controller,
																								StringValuePtr( rb_cursor_name ) ) );
}

/*****************************
*  closeCursorForName  *
*****************************/

VALUE rb_RPDB_DatabaseCursorController_closeCursorForName(	VALUE	rb_database_cursor_controller,
 																VALUE	cursor_name )	{

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	RPDB_DatabaseCursorController_closeCursorForName( 	c_database_cursor_controller,
									 						StringValuePtr( cursor_name ) );

	return 	rb_database_cursor_controller;
}

/*****************
*  allCursors  *
*****************/
/*
//	Return a list of database names that have been created and stored in this controller
VALUE rb_RPDB_DatabaseCursorController_allCursors( VALUE	rb_database_cursor_controller )	{

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	//	FIX - wrap in array
	RPDB_DatabaseCursorController_allCursors( c_database_cursor_controller )
}
*/
/*************************
*  closeAllCursors  *
*************************/

VALUE rb_RPDB_DatabaseCursorController_closeAllCursors( VALUE	rb_database_cursor_controller )	{

	RPDB_DatabaseCursorController*		c_database_cursor_controller;
	C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	RPDB_DatabaseCursorController_closeAllCursors( c_database_cursor_controller );

	return 	rb_database_cursor_controller;
}
