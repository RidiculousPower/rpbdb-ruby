/*
 *		Rbdb::ErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_ErrorSettingsController.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_ErrorSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Objects
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_ErrorSettingsController;

void Init_rb_Rbdb_ErrorSettingsController()	{


	rb_Rbdb_ErrorSettingsController		=	rb_define_class_under(	rb_Rbdb_SettingsController, 
																															"Error",	
																															rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_ErrorSettingsController, 	"new",																rb_Rbdb_ErrorSettingsController_new,														-1 	);
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"initialize",													rb_Rbdb_ErrorSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"parent_environment",									rb_Rbdb_ErrorSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_ErrorSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"parent_settings_controller",					rb_Rbdb_ErrorSettingsController_parentSettingsController,								0 	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"file",														rb_Rbdb_ErrorSettingsController_file,													0 	);
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"set_file",														rb_Rbdb_ErrorSettingsController_setFile,													1 	);
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"prefix",														rb_Rbdb_ErrorSettingsController_prefix,													0 	);
	rb_define_method(						rb_Rbdb_ErrorSettingsController, 	"set_prefix",														rb_Rbdb_ErrorSettingsController_setPrefix,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_ErrorSettingsController_new(	int			argc,
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
	C_RBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	Rbdb_ErrorSettingsController*	c_error_settings_controller	=	Rbdb_SettingsController_errorSettingsController( c_parent_settings_controller );

	VALUE	rb_error_settings_controller	= RUBY_RBDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller );

	rb_iv_set(	rb_error_settings_controller,
							RBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_ErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_ErrorSettingsController_parentSettingsController( rb_error_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_ErrorSettingsController_parentSettingsController(	VALUE	rb_error_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_error_settings_controller,
																										RBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
VALUE rb_Rbdb_ErrorSettingsController_file( VALUE	rb_error_settings_controller )	{

	Rbdb_ErrorSettingsController*	c_error_settings_controller;
	C_RBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

								//	FIX - FILE

	Rbdb_ErrorSettingsController_file( c_error_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

	/*************
	*  set_file  *
	*************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
	VALUE rb_Rbdb_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
																									VALUE	rb_file __attribute__ ((unused )) )	{

		Rbdb_ErrorSettingsController*	c_error_settings_controller;
		C_RBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );
			//	FIX- file
			
		FILE*	c_file;

		Rbdb_ErrorSettingsController_setFile(	c_error_settings_controller,
																					c_file );

		return rb_error_settings_controller;
	}

/***********
*  prefix  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
VALUE rb_Rbdb_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller )	{

	Rbdb_ErrorSettingsController*	c_error_settings_controller;
	C_RBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

	return rb_str_new2( Rbdb_ErrorSettingsController_prefix( c_error_settings_controller ) );
}

	/***************
	*  set_prefix  *
	***************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
	VALUE rb_Rbdb_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
														VALUE	rb_error_prefix )	{

		Rbdb_ErrorSettingsController*	c_error_settings_controller;
		C_RBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

		Rbdb_ErrorSettingsController_setPrefix(	c_error_settings_controller,
													StringValuePtr( rb_error_prefix ) );

		return rb_error_settings_controller;
	}

/******************************
*  set_error_callback_method  *
******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errcall.html
VALUE rb_Rbdb_ErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_error_settings_controller,
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
								const VALUE		error_message ) Rbdb_ErrorSettingsController_errorCallbackMethod( VALUE	rb_error_settings_controller )	{
	
}
*/

/******************************
*  set_panic_callback_method  *
******************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setPanicCallbackMethod(	VALUE	rb_message_settings_controller,
 																void *(panic_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setPanicCallbackMethod();
	

}
*/
/**************************
*  panic_callback_method  *
**************************/
/*
void *(panic_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_panicCallbackMethod(	VALUE	rb_message_settings_controller )	{
	

}
*/
