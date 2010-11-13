/*
 *		RPDB::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MessageSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"

#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_MessageSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MessageSettingsController;

void Init_RPDB_MessageSettingsController()	{

	rb_RPDB_MessageSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"Message",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MessageSettingsController, 	"new",																rb_RPDB_MessageSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_MessageSettingsController, 				"initialize",													rb_RPDB_MessageSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPDB_MessageSettingsController, 				"parent_environment",									rb_RPDB_MessageSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MessageSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPDB_MessageSettingsController,				"parent_settings_controller",					rb_RPDB_MessageSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPDB_MessageSettingsController, 				"file",														rb_RPDB_MessageSettingsController_file,													0 	);
	rb_define_method(			rb_RPDB_MessageSettingsController, 				"set_file",														rb_RPDB_MessageSettingsController_setFile,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_MessageSettingsController_new(	int			argc,
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

	VALUE	rb_message_settings_controller	= RUBY_RPDB_MESSAGE_SETTINGS_CONTROLLER( RPDB_SettingsController_messageSettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_message_settings_controller,
							RPDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_message_settings_controller,
										 1, 
										 argv );
	
	return rb_message_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_MessageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_MessageSettingsController_parentSettingsController( rb_message_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_message_settings_controller,
																										RPDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgfile.html
VALUE rb_RPDB_MessageSettingsController_file( VALUE	rb_message_settings_controller )	{

	RPDB_MessageSettingsController*	c_message_settings_controller;
	C_RPDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	//	FIX - FILE
	RPDB_MessageSettingsController_file( c_message_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/*************
*  set_file  *
*************/

VALUE rb_RPDB_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
																									VALUE	rb_message_file __attribute__ ((unused )) )	{

	RPDB_MessageSettingsController*	c_message_settings_controller;
	C_RPDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	FILE*	c_message_file;

	//	FIX - FILE
	RPDB_MessageSettingsController_setFile(	c_message_settings_controller,
																					c_message_file );

	return rb_message_settings_controller;
}

/*************************
*  set_message_callback  *
*************************/
/*
VALUE rb_RPDB_MessageSettingsController_setMessageCallbackMethod(	VALUE	rb_message_settings_controller, 
																void (*message_callback_method)(	VALUE			environment, 
																									const VALUE		message ) )	{
	RPDB_MessageSettingsController_setMessageCallbackMethod();
	
	
}
*/
/*********************
*  message_callback  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgcall.html
void (*message_callback_method)(	VALUE			environment, 
									const VALUE		message ) RPDB_MessageSettingsController_messageCallbackMethod( VALUE	rb_message_settings_controller )	{

}
*/
