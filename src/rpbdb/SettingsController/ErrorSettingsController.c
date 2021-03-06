/*
 *		RPbdb::ErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "SettingsController.h"
#include "ErrorSettingsController.h"
#include "RPbdb.h"

#include "Environment.h"

#include <rpbdb/Environment.h>
#include <rpbdb/ErrorSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Objects
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_ErrorSettingsController;

void Init_rb_RPbdb_ErrorSettingsController()	{


	rb_RPbdb_ErrorSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																															"Error",	
																															rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_ErrorSettingsController, 	"new",																rb_RPbdb_ErrorSettingsController_new,														-1 	);
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"initialize",													rb_RPbdb_ErrorSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"parent_environment",									rb_RPbdb_ErrorSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_ErrorSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"parent_settings_controller",					rb_RPbdb_ErrorSettingsController_parentSettingsController,								0 	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"file",														rb_RPbdb_ErrorSettingsController_file,													0 	);
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"set_file",														rb_RPbdb_ErrorSettingsController_setFile,													1 	);
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"prefix",														rb_RPbdb_ErrorSettingsController_prefix,													0 	);
	rb_define_method(						rb_RPbdb_ErrorSettingsController, 	"set_prefix",														rb_RPbdb_ErrorSettingsController_setPrefix,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_ErrorSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}

	RPbdb_SettingsController*	c_parent_settings_controller;
	C_RPBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPbdb_ErrorSettingsController*	c_error_settings_controller	=	RPbdb_SettingsController_errorSettingsController( c_parent_settings_controller );

	VALUE	rb_error_settings_controller	= RUBY_RPBDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller );

	rb_iv_set(	rb_error_settings_controller,
							RPBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_error_settings_controller,
										 1, 
										 argv );
	
	return rb_error_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_ErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_ErrorSettingsController_parentSettingsController( rb_error_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_ErrorSettingsController_parentSettingsController(	VALUE	rb_error_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_error_settings_controller,
																										RPBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
VALUE rb_RPbdb_ErrorSettingsController_file( VALUE	rb_error_settings_controller )	{

	RPbdb_ErrorSettingsController*	c_error_settings_controller;
	C_RPBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

								//	FIX - FILE

	RPbdb_ErrorSettingsController_file( c_error_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

	/*************
	*  set_file  *
	*************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
	VALUE rb_RPbdb_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
																									VALUE	rb_file __attribute__ ((unused )) )	{

		RPbdb_ErrorSettingsController*	c_error_settings_controller;
		C_RPBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );
			//	FIX- file
			
		FILE*	c_file;

		RPbdb_ErrorSettingsController_setFile(	c_error_settings_controller,
																					c_file );

		return rb_error_settings_controller;
	}

/***********
*  prefix  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
VALUE rb_RPbdb_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller )	{

	RPbdb_ErrorSettingsController*	c_error_settings_controller;
	C_RPBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

	return rb_str_new2( RPbdb_ErrorSettingsController_prefix( c_error_settings_controller ) );
}

	/***************
	*  set_prefix  *
	***************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
	VALUE rb_RPbdb_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
														VALUE	rb_error_prefix )	{

		RPbdb_ErrorSettingsController*	c_error_settings_controller;
		C_RPBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

		RPbdb_ErrorSettingsController_setPrefix(	c_error_settings_controller,
													StringValuePtr( rb_error_prefix ) );

		return rb_error_settings_controller;
	}

/******************************
*  set_error_callback_method  *
******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errcall.html
VALUE rb_RPbdb_ErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_error_settings_controller,
 															void (*error_callback_method)(	VALUE			environment,
																							const VALUE		error_prefix,
																							const VALUE		error_message ) )	{
	

}
*/
/**************************
*  error_callback_method  *
**************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errcall.html
void (*error_callback_method)(	VALUE			environment,
								const VALUE		error_prefix,
								const VALUE		error_message ) RPbdb_ErrorSettingsController_errorCallbackMethod( VALUE	rb_error_settings_controller )	{
	
}
*/

/******************************
*  set_panic_callback_method  *
******************************/
/*
VALUE rb_RPbdb_MessageSettingsController_setPanicCallbackMethod(	VALUE	rb_message_settings_controller,
 																void *(panic_callback_method)( VALUE	environment ) )	{
	RPbdb_MessageSettingsController_setPanicCallbackMethod();
	

}
*/
/**************************
*  panic_callback_method  *
**************************/
/*
void *(panic_callback_method)( VALUE	environment ) RPbdb_MessageSettingsController_panicCallbackMethod(	VALUE	rb_message_settings_controller )	{
	

}
*/
