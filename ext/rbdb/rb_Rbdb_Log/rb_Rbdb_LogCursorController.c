/*
 *		Rbdb::LogController::LogCursorController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_LogCursorController.h"
#include "rb_Rbdb_LogController.h"

#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_LogCursorController.h>
#include <rbdb/Rbdb_LogCursor.h>

#include <rbdb/Rbdb_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_Rbdb_Environment;
VALUE	extern	rb_Rbdb_LogController;

VALUE	extern	rb_Rbdb_LogCursorController;
VALUE	extern	rb_Rbdb_LogCursor;
VALUE	extern	rb_Rbdb_LogSettingsController;

void Init_Rbdb_LogCursorController()	{

	rb_Rbdb_LogCursorController	=	rb_define_class_under(	rb_Rbdb_Environment, 
																												"LogCursorController",			
																												rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_LogCursorController, 	"new",																													rb_Rbdb_LogCursorController_new,																							-1 	);
	rb_define_method(						rb_Rbdb_LogCursorController, 	"initialize",																										rb_Rbdb_LogCursorController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_LogCursorController, 	"settings_controller",																					rb_Rbdb_LogCursorController_settingsController,															0 	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_Rbdb_LogCursorController, 	"parent_environment",																						rb_Rbdb_LogCursorController_parentEnvironment,																0 	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"environment",																									"parent_environment"	);

//	rb_define_method(						rb_Rbdb_LogCursorController, 	"cursor",																												rb_Rbdb_LogCursorController_cursor,																				0 	);
	rb_define_method(						rb_Rbdb_LogCursorController, 	"close_all_cursors",																						rb_Rbdb_LogCursorController_closeAllCursors,																				0 	);
	rb_define_alias(						rb_Rbdb_LogCursorController, 	"close_all",																										"close_all_cursors"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  self.new  *
************/

VALUE rb_Rbdb_LogCursorController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_Rbdb_LogController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]"
		)
	);
	
	Rbdb_LogController*	c_parent_log_controller;
	C_Rbdb_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log_cursor_controller	=	RUBY_RBDB_LOG_CURSOR_CONTROLLER( Rbdb_LogCursorController_new( c_parent_log_controller ) );	

	//	store reference to parent
	rb_iv_set(	rb_log_cursor_controller,
							Rbdb_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER,
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

VALUE rb_Rbdb_LogCursorController_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{

	return rb_self;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_LogCursorController_settingsController(	VALUE	rb_log_cursor_controller )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_cursor_controller,
																												Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_LogCursorController*		c_log_cursor_controller;
		C_Rbdb_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller );
	
		Rbdb_LogSettingsController*	c_local_log_settings_controller	=	Rbdb_LogCursorController_settingsController( c_log_cursor_controller );

		rb_local_log_settings_controller	=	RUBY_RBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_cursor_controller,
								Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_Rbdb_LogCursorController_parentEnvironment(	VALUE	rb_log_cursor_controller )	{

	VALUE	rb_parent_log_controller	=	rb_Rbdb_LogCursorController_parentLogController( rb_log_cursor_controller );
	VALUE	rb_parent_environment			=	rb_Rbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/

VALUE rb_Rbdb_LogCursorController_parentLogController(	VALUE	rb_log_cursor_controller )	{
	
	VALUE	rb_parent_log_controller	=	rb_iv_get(	rb_log_cursor_controller,
																								Rbdb_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER );
	
	return rb_parent_log_controller;
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_Rbdb_LogCursorController_closeAllCursors( VALUE	rb_log_cursor_controller )	{

	Rbdb_LogCursorController*		c_log_cursor_controller;
	C_Rbdb_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller  );

	Rbdb_LogCursorController_closeAllCursors( c_log_cursor_controller );

	return rb_log_cursor_controller;
}
