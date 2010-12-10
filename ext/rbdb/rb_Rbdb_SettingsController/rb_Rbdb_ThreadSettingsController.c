
/*
 *		Rbdb::SettingsController::ThreadSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_ThreadSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_ThreadSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;	
extern	VALUE	rb_Rbdb_Environment;	
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_ThreadSettingsController;
	
void Init_Rbdb_ThreadSettingsController()	{

	rb_Rbdb_ThreadSettingsController		=	rb_define_class_under(	rb_Rbdb_SettingsController, 
																																"Thread",	
																																rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_ThreadSettingsController, 	"new",																rb_Rbdb_ThreadSettingsController_new,										-1 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"initialize",													rb_Rbdb_ThreadSettingsController_initialize,										-1 	);

	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"parent_environment",									rb_Rbdb_ThreadSettingsController_parentEnvironment,				0 	);
	rb_define_alias(			rb_Rbdb_ThreadSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController,					"parent_settings_controller",					rb_Rbdb_ThreadSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"on?",														rb_Rbdb_ThreadSettingsController_on,													0 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"off?",														rb_Rbdb_ThreadSettingsController_off,													0 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"turn_on",														rb_Rbdb_ThreadSettingsController_turnOn,											0 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"turn_off",														rb_Rbdb_ThreadSettingsController_turnOff,											0 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"thread_count",														rb_Rbdb_ThreadSettingsController_threadCount,									0 	);
	rb_define_method(			rb_Rbdb_ThreadSettingsController, 				"set_thread_count",														rb_Rbdb_ThreadSettingsController_setThreadCount,							1 	);

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_ThreadSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );	
	}

	Rbdb_SettingsController*	c_parent_settings_controller;
	C_Rbdb_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );
	
	VALUE	rb_thread_settings_controller	= RUBY_RBDB_THREAD_SETTINGS_CONTROLLER( Rbdb_ThreadSettingsController_new( c_parent_settings_controller ) );
	
	rb_iv_set(	rb_thread_settings_controller,
							Rbdb_RB_THREAD_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_thread_settings_controller,
										 1, 
										 argv );
	
	return rb_thread_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_ThreadSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_ThreadSettingsController_parentEnvironment(	VALUE	rb_thread_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_ThreadSettingsController_parentSettingsController( rb_thread_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_ThreadSettingsController_parentSettingsController(	VALUE	rb_thread_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_thread_settings_controller,
																										Rbdb_RB_THREAD_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********
*  on?  *
********/

//	DB_THREAD		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_Rbdb_ThreadSettingsController_on( VALUE	rb_thread_settings_controller )	{

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return ( Rbdb_ThreadSettingsController_on( c_thread_settings_controller )	?	Qtrue
																				:	Qfalse );
}

/*********
*  off?  *
*********/

VALUE rb_Rbdb_ThreadSettingsController_off( VALUE	rb_thread_settings_controller )	{

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return ( Rbdb_ThreadSettingsController_off( c_thread_settings_controller )	?	Qtrue
																				:	Qfalse );
}

/************
*  turn_on  *
************/

VALUE rb_Rbdb_ThreadSettingsController_turnOn( VALUE	rb_thread_settings_controller )	{

	VALUE	rb_parent_environment	=	rb_Rbdb_ThreadSettingsController_parentEnvironment( rb_thread_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Threads can only be enabled before environment is opened." );	
	}

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	Rbdb_ThreadSettingsController_turnOn( c_thread_settings_controller );

	return rb_thread_settings_controller;
}

/*************
*  turn_off  *
*************/

VALUE rb_Rbdb_ThreadSettingsController_turnOff( VALUE	rb_thread_settings_controller )	{

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	Rbdb_ThreadSettingsController_turnOff( c_thread_settings_controller );

	return rb_thread_settings_controller;
}

/*****************
*  thread_count  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_count.html
VALUE rb_Rbdb_ThreadSettingsController_threadCount( VALUE	rb_thread_settings_controller )	{

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	int		c_thread_count	=	Rbdb_ThreadSettingsController_threadCount( c_thread_settings_controller );
	VALUE	rb_thread_count	=	INT2FIX( c_thread_count );

	return rb_thread_count;
}

/*********************
*  set_thread_count  *
*********************/

VALUE rb_Rbdb_ThreadSettingsController_setThreadCount(	VALUE	rb_thread_settings_controller, 
																												VALUE	rb_thread_count )	{

	VALUE	rb_parent_environment	=	rb_Rbdb_ThreadSettingsController_parentEnvironment( rb_thread_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Thread count can only be set before environment is opened." );	
	}

	Rbdb_ThreadSettingsController*	c_thread_settings_controller;
	C_Rbdb_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	Rbdb_ThreadSettingsController_setThreadCount(	c_thread_settings_controller,
																								FIX2INT( rb_thread_count ) );

	return rb_thread_settings_controller;
}

/*************************************************
*  set_unique_thread_identifier_callback_method  *
*************************************************/
/*
VALUE rb_Rbdb_ThreadSettingsController_setUniqueThreadIdentifierCallbackMethod(	VALUE	rb_thread_settings_controller,
 																				void (*unique_thread_identifier_callback_method)(	VALUE				environment,
																																	pid_t*				process_id,
																																	db_threadid_t*		thread_id	) )	{

}
*/
/*********************************************
*  unique_thread_identifier_callback_method  *
*********************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_id.html
void (*unique_thread_identifier_callback_method)(	VALUE				environment,
													pid_t*				process_id,
													db_threadid_t*		thread_id	) Rbdb_ThreadSettingsController_uniqueThreadIdentifierCallbackMethod( VALUE	rb_thread_settings_controller )	{

}
*/
/*************************************************************************
*  set_format_thread_and_process_identifier_for_display_callback_method  *
*************************************************************************/
/*
VALUE rb_Rbdb_ThreadSettingsController_setFormatThreadAndProcessIdentifierForDisplayCallbackMethod(	VALUE	rb_thread_settings_controller,
 																									void (*format_thread_and_process_identifier_for_display_callback_method)(	VALUE				environment,
																																												pid_t				process_id,
																																												db_threadid_t		thread_id,
																																												VALUE				string_buffer ) )	{

}
*/
/*********************************************************************
*  format_thread_and_process_identifier_for_display_callback_method  *
*********************************************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_id_string.html
void (*format_thread_and_process_identifier_for_display_callback_method)(	VALUE				environment,
																			pid_t				process_id,
																			db_threadid_t		thread_id,
																			VALUE				string_buffer ) Rbdb_ThreadSettingsController_formatThreadAndProcessIDForDisplayCallbackMethod(	VALUE	rb_thread_settings_controller	)	{


}
*/
/****************************************
*  set_is_thread_alive_callback_method  *
****************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_isalive.html
VALUE rb_Rbdb_ThreadSettingsController_setIsThreadAliveCallbackgBDB_ThreadSettingsController* 									thread_settings_controller,
 																	VALUE(*Rbdb_IsThreadAliveCallbackMethod)(	VALUE				environment,
																													pid_t				process_id,
																													db_threadid_t		thread_id,
																													VALUE			associated_with_single_process ) )	{
																														
}
*/
/************************************
*  is_thread_alive_callback_method  *
************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_isalive.html
VALUE(*Rbdb_IsThreadAliveCallbackMethod)(	VALUE				environment,
												pid_t				process_id,
												db_threadid_t		thread_id,
												VALUE			associated_with_single_process ) Rbdb_ThreadSettingsController_isThreadAliveCallbackMethod( VALUE	rb_thread_settings_controller )	{

}
*/