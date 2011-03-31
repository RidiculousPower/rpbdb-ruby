/*
 *		RPbdb::LogController::LogCursorController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "LogCursorController.h"
#include "LogController.h"

#include <rpbdb/Database.h>

#include <rpbdb/Environment.h>

#include <rpbdb/LogCursorController.h>
#include <rpbdb/LogCursor.h>

#include <rpbdb/LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPbdb_Environment;
VALUE	extern	rb_RPbdb_LogController;

VALUE	extern	rb_RPbdb_LogCursorController;
VALUE	extern	rb_RPbdb_LogCursor;
VALUE	extern	rb_RPbdb_LogSettingsController;

void Init_rb_RPbdb_LogCursorController()	{

	rb_RPbdb_LogCursorController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																												"LogCursorController",			
																												rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_LogCursorController, 	"new",																													rb_RPbdb_LogCursorController_new,																							-1 	);
	rb_define_method(						rb_RPbdb_LogCursorController, 	"initialize",																										rb_RPbdb_LogCursorController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_LogCursorController, 	"settings_controller",																					rb_RPbdb_LogCursorController_settingsController,															0 	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_LogCursorController, 	"parent_environment",																						rb_RPbdb_LogCursorController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"environment",																									"parent_environment"	);

//	rb_define_method(						rb_RPbdb_LogCursorController, 	"cursor",																												rb_RPbdb_LogCursorController_cursor,																				0 	);
	rb_define_method(						rb_RPbdb_LogCursorController, 	"close_all_cursors",																						rb_RPbdb_LogCursorController_closeAllCursors,																				0 	);
	rb_define_alias(						rb_RPbdb_LogCursorController, 	"close_all",																										"close_all_cursors"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  self.new  *
************/

VALUE rb_RPbdb_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_RPbdb_LogController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]"
		)
	);
	
	RPbdb_LogController*	c_parent_log_controller;
	C_RPBDB_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log_cursor_controller	=	RUBY_RPBDB_LOG_CURSOR_CONTROLLER( RPbdb_LogCursorController_new( c_parent_log_controller ) );	

	//	store reference to parent
	rb_iv_set(	rb_log_cursor_controller,
							RPBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER,
							rb_parent_log_controller );

	VALUE	argv[]	=	{ rb_parent_log_controller };
	rb_obj_call_init(	rb_log_cursor_controller,
					 1, 
					 argv );
	
	return rb_log_cursor_controller;	
}

/************
*  self.new  *
************/

VALUE rb_RPbdb_LogCursorController_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{

	return rb_self;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_cursor_controller,
																												RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_LogCursorController*		c_log_cursor_controller;
		C_RPBDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller );
	
		RPbdb_LogSettingsController*	c_local_log_settings_controller	=	RPbdb_LogCursorController_settingsController( c_log_cursor_controller );

		rb_local_log_settings_controller	=	RUBY_RPBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_cursor_controller,
								RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller )	{

	VALUE	rb_parent_log_controller	=	rb_RPbdb_LogCursorController_parentLogController( rb_log_cursor_controller );
	VALUE	rb_parent_environment			=	rb_RPbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/

VALUE rb_RPbdb_LogCursorController_parentLogController(	VALUE	rb_log_cursor_controller )	{
	
	VALUE	rb_parent_log_controller	=	rb_iv_get(	rb_log_cursor_controller,
																								RPBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER );
	
	return rb_parent_log_controller;
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_RPbdb_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller )	{

	RPbdb_LogCursorController*		c_log_cursor_controller;
	C_RPBDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	RPbdb_LogCursorController_closeAllCursors( c_log_cursor_controller );

	return rb_log_cursor_controller;
}
