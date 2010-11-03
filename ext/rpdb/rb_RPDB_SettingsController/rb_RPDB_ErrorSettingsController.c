/*
 *		RPDB::ErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_ErrorSettingsController.h"
#include "rb_RPDB.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_ErrorSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Objects
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_ErrorSettingsController;

void Init_RPDB_ErrorSettingsController()	{


	rb_RPDB_ErrorSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																															"Error",	
																															rb_cObject );

	rb_define_singleton_method(	rb_RPDB_ErrorSettingsController, 	"new",																rb_RPDB_ErrorSettingsController_new,														-1 	);
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"initialize",													rb_RPDB_ErrorSettingsController_init,														-1 	);
                        			                                        
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"parent_environment",									rb_RPDB_ErrorSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_ErrorSettingsController, 	"environment",												"parent_environment"	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"shm_key",														rb_RPDB_ErrorSettingsController_file,													0 	);
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"shm_key",														rb_RPDB_ErrorSettingsController_setFile,													0 	);
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"shm_key",														rb_RPDB_ErrorSettingsController_prefix,													0 	);
	rb_define_method(						rb_RPDB_ErrorSettingsController, 	"shm_key",														rb_RPDB_ErrorSettingsController_setPrefix,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_ErrorSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_error_settings_controller	= RUBY_RPDB_ERROR_SETTINGS_CONTROLLER( RPDB_ErrorSettingsController_new( c_parent_settings_controller ) );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	
	rb_obj_call_init(	rb_error_settings_controller,
										 1, 
										 argv );
	
	return rb_error_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_ErrorSettingsController_init(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_ErrorSettingsController_parentEnvironment(	VALUE	rb_error_settings_controller )	{

	RPDB_ErrorSettingsController*	c_error_settings_controller;
	C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_ErrorSettingsController_parentEnvironment( c_error_settings_controller ) );
}

/************
*  file  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
VALUE rb_RPDB_ErrorSettingsController_file( VALUE	rb_error_settings_controller )	{

	RPDB_ErrorSettingsController*	c_error_settings_controller;
	C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

								//	FIX - FILE

	RPDB_ErrorSettingsController_file( c_error_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

	/****************
	*  setFile  *
	****************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errfile.html
	VALUE rb_RPDB_ErrorSettingsController_setFile(	VALUE	rb_error_settings_controller, 
																									VALUE	rb_file __attribute__ ((unused )) )	{

		RPDB_ErrorSettingsController*	c_error_settings_controller;
		C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );
			//	FIX- file
			
		FILE*	c_file;

		RPDB_ErrorSettingsController_setFile(	c_error_settings_controller,
																					c_file );

		return rb_error_settings_controller;
	}

/************
*  prefix  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
VALUE rb_RPDB_ErrorSettingsController_prefix( VALUE	rb_error_settings_controller )	{

	RPDB_ErrorSettingsController*	c_error_settings_controller;
	C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

	return rb_str_new2( RPDB_ErrorSettingsController_prefix( c_error_settings_controller ) );
}

	/****************
	*  setPrefix  *
	****************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errpfx.html
	VALUE rb_RPDB_ErrorSettingsController_setPrefix(	VALUE	rb_error_settings_controller,
														VALUE	rb_error_prefix )	{

		RPDB_ErrorSettingsController*	c_error_settings_controller;
		C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller );

		RPDB_ErrorSettingsController_setPrefix(	c_error_settings_controller,
													StringValuePtr( rb_error_prefix ) );

		return rb_error_settings_controller;
	}

/****************************
*  setErrorCallbackMethod  *
****************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errcall.html
VALUE rb_RPDB_ErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_error_settings_controller,
 															void (*error_callback_method)(	VALUE			environment,
																							const VALUE		error_prefix,
																							const VALUE		error_message ) )	{
	

}
*/
/************************
*  errorCallbackMethod  *
************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_errcall.html
void (*error_callback_method)(	VALUE			environment,
								const VALUE		error_prefix,
								const VALUE		error_message ) RPDB_ErrorSettingsController_errorCallbackMethod( VALUE	rb_error_settings_controller )	{
	
}
*/
