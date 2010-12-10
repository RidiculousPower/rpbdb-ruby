/*
 *		Rbdb::DatabaseController::Database::CursorController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_DatabaseCursor.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseCursorController.h>
#include "rb_Rbdb_DatabaseCursorController.h"

#include <rbdb/Rbdb_DatabaseCursor.h>
#include <rbdb/Rbdb_DatabaseCursorSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_Rbdb_Environment;
VALUE	extern	rb_Rbdb_Database;
VALUE	extern	rb_Rbdb_DatabaseCursor;
VALUE	extern	rb_Rbdb_DatabaseObjectCursor;
VALUE	extern	rb_Rbdb_DatabaseCursorController;
VALUE	extern	rb_Rbdb_DatabaseCursorSettingsController;

void Init_Rbdb_DatabaseCursorController()	{

	rb_Rbdb_DatabaseCursorController	=	rb_define_class_under(	rb_Rbdb_DatabaseCursor, 
																															"Controller",	
																															rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseCursorController, 	"new",													rb_Rbdb_DatabaseCursorController_new,												-1 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorController,		"initialize",										rb_Rbdb_DatabaseCursorController_initialize,											-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"settings_controller",					rb_Rbdb_DatabaseCursorController_settingsController,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"settings",											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"set",													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"set_to",												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"is_set_to",										"settings_controller"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"parent_environment",						rb_Rbdb_DatabaseCursorController_parentEnvironment,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"parent_environment",						"parent_environment"	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"environment",									"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"parent_database",							rb_Rbdb_DatabaseCursorController_parentDatabase,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"database",											"parent_database"	);

	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"cursor",												rb_Rbdb_DatabaseCursorController_cursor,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"object_cursor",								rb_Rbdb_DatabaseCursorController_objectCursor,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorController, 	"close_all_cursors",						rb_Rbdb_DatabaseCursorController_closeAllCursors,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorController, 	"close_all",										"close_all_cursors"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCursorController_new( int			argc,
																						VALUE*	args,
																						VALUE		rb_cursor_controller_klass __attribute__ ((unused)) )	{
	
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
		VALUE	rb_database_controller	=	rb_Rbdb_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_Rbdb_Database_new( 1,
																								& rb_database_controller,
																								rb_Rbdb_Database );
	}

	/*------------------------------------------------------*/
	
	Rbdb_Database*		c_parent_database;
	C_Rbdb_DATABASE( rb_parent_database, c_parent_database );
	
	Rbdb_DatabaseCursorController*	c_database_cursor_controller	=	Rbdb_Database_cursorController( c_parent_database );
	
	VALUE	rb_database_cursor_controller	=	RUBY_RBDB_DATABASE_CURSOR_CONTROLLER( c_database_cursor_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_cursor_controller,
							Rbdb_RB_ALL_VARIABLE_PARENT_DATABASE,
							rb_parent_database );

	VALUE	argv[]	=	{ rb_parent_database };
	
	rb_obj_call_init(	rb_database_cursor_controller,
										1, 
										argv );
	
	return rb_database_cursor_controller;	
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCursorController_initialize( 	int			argc __attribute__ ((unused)),
																							VALUE*	args __attribute__ ((unused)),
																							VALUE		rb_database_cursor_controller )	{

	return rb_database_cursor_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_DatabaseCursorController_settingsController(	VALUE	rb_database_cursor_controller )	{

	VALUE	rb_database_cursor_settings_controller	=	Qnil;
	
	if ( ( rb_database_cursor_settings_controller = rb_iv_get(	rb_database_cursor_controller,
																															Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
	Rbdb_DatabaseCursorController*		c_database_cursor_controller;
	C_Rbdb_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );
	
		Rbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller	=	Rbdb_DatabaseCursorController_settingsController( c_database_cursor_controller );

		rb_database_cursor_settings_controller	=	RUBY_RBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller );

		rb_iv_set(	rb_database_cursor_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER,
								rb_database_cursor_settings_controller );
	}

	return rb_database_cursor_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_Rbdb_DatabaseCursorController_parentEnvironment(	VALUE	rb_database_cursor_controller )	{
	
	VALUE	rb_parent_database		=	rb_Rbdb_DatabaseCursorController_parentDatabase( rb_database_cursor_controller );
	VALUE	rb_parent_environment	=	rb_Rbdb_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_Rbdb_DatabaseCursorController_parentDatabase(	VALUE	rb_database_cursor_controller )	{
	
	VALUE	rb_parent_database	=	rb_iv_get(	rb_database_cursor_controller,
																					Rbdb_RB_ALL_VARIABLE_PARENT_DATABASE );
	
	return rb_parent_database;
}

/*************
*  cursor  *
************/

VALUE rb_Rbdb_DatabaseCursorController_cursor(	VALUE	rb_database_cursor_controller )	{
	
	VALUE	rb_cursor	=	rb_Rbdb_DatabaseCursor_new(	1,
																								& rb_database_cursor_controller,
																								rb_Rbdb_DatabaseCursor );
	
	return rb_cursor;
}

/*********************
*  objectCursor  *
********************/

VALUE rb_Rbdb_DatabaseCursorController_objectCursor(	VALUE	rb_database_cursor_controller )	{
	
	Rbdb_DatabaseCursorController*		c_database_cursor_controller;
	C_Rbdb_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );
	
	Rbdb_DatabaseCursor*	c_cursor	=	Rbdb_DatabaseCursorController_cursor( c_database_cursor_controller );
	VALUE									rb_cursor	=	RUBY_RBDB_DATABASE_OBJECT_CURSOR( c_cursor );
	
	return rb_cursor;
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_Rbdb_DatabaseCursorController_closeAllCursors( VALUE	rb_database_cursor_controller )	{

	Rbdb_DatabaseCursorController*		c_database_cursor_controller;
	C_Rbdb_DATABASE_CURSOR_CONTROLLER( rb_database_cursor_controller, c_database_cursor_controller );

	Rbdb_DatabaseCursorController_closeAllCursors( c_database_cursor_controller );

	return 	rb_database_cursor_controller;
}
