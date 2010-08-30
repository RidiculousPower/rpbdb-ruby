/*
 *		RPDB::LogController::LogCursorController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_LogCursorController.h"
#include "rb_RPDB_LogController.h"

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_LogCursorController.h>
#include <rpdb/RPDB_LogCursor.h>

#include <rpdb/RPDB_LogSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_LogController;

VALUE	extern	rb_RPDB_LogCursorController;
VALUE	extern	rb_RPDB_LogCursor;
VALUE	extern	rb_RPDB_LogSettingsController;

void Init_RPDB_LogCursorController()	{

	rb_RPDB_LogCursorController	=	rb_define_class_under(	rb_RPDB_Environment, 
																												"LogCursorController",			
																												rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LogCursorController, 	"new",																													rb_RPDB_LogCursorController_new,																							-1 	);
	rb_define_method(						rb_RPDB_LogCursorController, 	"initialize",																										rb_RPDB_LogCursorController_init,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_LogCursorController, 	"settings_controller",																					rb_RPDB_LogCursorController_settingsController,															0 	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_LogCursorController, 	"parent_environment",																						rb_RPDB_LogCursorController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"environment",																									"parent_environment"	);

	//	FIX - rename cursorForName to cursorWithName
	rb_define_method(						rb_RPDB_LogCursorController, 	"cursor_with_name",																						rb_RPDB_LogCursorController_cursorForName,																				0 	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"cursors",																											"cursor_with_name"	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"cursor",																												"cursor_with_name"	);
	rb_define_method(						rb_RPDB_LogCursorController, 	"all_cursors",																									rb_RPDB_LogCursorController_allCursors,																			0 	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"all",																													"all"	);
	rb_define_method(						rb_RPDB_LogCursorController, 	"close_all_cursors",																						rb_RPDB_LogCursorController_closeAllCursors,																				0 	);
	rb_define_alias(						rb_RPDB_LogCursorController, 	"close_all",																										"close_all_cursors"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_LogCursorController_new(	VALUE	klass __attribute__ ((unused)),
																				VALUE	rb_parent_log_controller )	{
	
	RPDB_LogController*	c_parent_log_controller;
	C_RPDB_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log_cursor_controller	=	RUBY_RPDB_LOG_CURSOR_CONTROLLER( RPDB_LogCursorController_new( c_parent_log_controller ) );	

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_log_controller;
	
	rb_obj_call_init(	rb_log_cursor_controller,
					 1, 
					 argv );
	
	return rb_log_cursor_controller;	
}

/************
*  new  *
************/

VALUE rb_RPDB_LogCursorController_init(	VALUE	rb_log_cursor_controller,
																				VALUE	rb_parent_log_controller __attribute__ ((unused)) )	{

	return rb_log_cursor_controller;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller )	{

	RPDB_LogCursorController*	c_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	return RUBY_RPDB_LOG_SETTINGS_CONTROLLER( RPDB_LogCursorController_settingsController( c_log_cursor_controller ) );
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller )	{

	RPDB_LogCursorController*		c_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	return RUBY_RPDB_ENVIRONMENT( RPDB_LogCursorController_parentEnvironment( c_log_cursor_controller ) );
}

/*************************
*  cursorForName  *
*************************/

VALUE rb_RPDB_LogCursorController_cursorForName(	VALUE	rb_log_cursor_controller,
 																VALUE	rb_cursor_name )	{

	RPDB_LogCursorController*		c_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	return RUBY_RPDB_LOG_CURSOR( RPDB_LogCursorController_cursorForName(	c_log_cursor_controller,
																				StringValuePtr( rb_cursor_name )  ) );
}

/*****************
*  allCursors  *
*****************/

//	Return a list of database names that have been created and stored in this controller
VALUE rb_RPDB_LogCursorController_allCursors( VALUE	rb_log_cursor_controller )	{

	RPDB_LogCursorController*		c_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	//	FIX - return array

	RPDB_LogCursorController_allCursors( c_log_cursor_controller );
	
	return rb_log_cursor_controller;
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_RPDB_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller )	{

	RPDB_LogCursorController*		c_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	RPDB_LogCursorController_closeAllCursors( c_log_cursor_controller );

	return rb_log_cursor_controller;
}
