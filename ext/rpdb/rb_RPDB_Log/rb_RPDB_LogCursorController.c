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

#include <rargs.h>

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

//	rb_define_method(						rb_RPDB_LogCursorController, 	"cursor",																												rb_RPDB_LogCursorController_cursor,																				0 	);
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

VALUE rb_RPDB_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_RPDB_LogController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]"
		)
	);
	
	RPDB_LogController*	c_parent_log_controller;
	C_RPDB_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log_cursor_controller	=	RUBY_RPDB_LOG_CURSOR_CONTROLLER( RPDB_LogCursorController_new( c_parent_log_controller ) );	

	//	store reference to parent
	rb_iv_set(	rb_log_cursor_controller,
							RPDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER,
							rb_parent_log_controller );

	VALUE	argv[]	=	{ rb_parent_log_controller };
	rb_obj_call_init(	rb_log_cursor_controller,
					 1, 
					 argv );
	
	return rb_log_cursor_controller;	
}

/************
*  new  *
************/

VALUE rb_RPDB_LogCursorController_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{

	return rb_self;
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
*  parent_environment  *
***************************************/

VALUE rb_RPDB_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller )	{

	VALUE	rb_parent_log_controller	=	rb_RPDB_LogCursorController_parentLogController( rb_log_cursor_controller );
	VALUE	rb_parent_environment			=	rb_RPDB_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/

VALUE rb_RPDB_LogCursorController_parentLogController(	VALUE	rb_log_cursor_controller )	{
	
	VALUE	rb_parent_log_controller	=	rb_iv_get(	rb_log_cursor_controller,
																								RPDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER );
	
	return rb_parent_log_controller;
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
