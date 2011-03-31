/*
 *		RPbdb::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MessageSettingsController.h"
#include "SettingsController.h"

#include "Environment.h"

#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/SettingsController.h>
#include <rpbdb/MessageSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_MessageSettingsController;

void Init_rb_RPbdb_MessageSettingsController()	{

	rb_RPbdb_MessageSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																																		"Message",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MessageSettingsController, 	"new",																rb_RPbdb_MessageSettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_MessageSettingsController, 				"initialize",													rb_RPbdb_MessageSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_MessageSettingsController, 				"parent_environment",									rb_RPbdb_MessageSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_MessageSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_MessageSettingsController,				"parent_settings_controller",					rb_RPbdb_MessageSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_MessageSettingsController, 				"file",														rb_RPbdb_MessageSettingsController_file,													0 	);
	rb_define_method(			rb_RPbdb_MessageSettingsController, 				"set_file",														rb_RPbdb_MessageSettingsController_setFile,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MessageSettingsController_new(	int			argc,
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

	VALUE	rb_message_settings_controller	= RUBY_RPBDB_MESSAGE_SETTINGS_CONTROLLER( RPbdb_SettingsController_messageSettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_message_settings_controller,
							RPBDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
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

VALUE rb_RPbdb_MessageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_MessageSettingsController_parentSettingsController( rb_message_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_message_settings_controller,
																										RPBDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgfile.html
VALUE rb_RPbdb_MessageSettingsController_file( VALUE	rb_message_settings_controller )	{

	RPbdb_MessageSettingsController*	c_message_settings_controller;
	C_RPBDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	//	FIX - FILE
	RPbdb_MessageSettingsController_file( c_message_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/*************
*  set_file  *
*************/

VALUE rb_RPbdb_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
																									VALUE	rb_message_file __attribute__ ((unused )) )	{

	RPbdb_MessageSettingsController*	c_message_settings_controller;
	C_RPBDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	FILE*	c_message_file;

	//	FIX - FILE
	RPbdb_MessageSettingsController_setFile(	c_message_settings_controller,
																					c_message_file );

	return rb_message_settings_controller;
}

/*************************
*  set_message_callback  *
*************************/
/*
VALUE rb_RPbdb_MessageSettingsController_setMessageCallbackMethod(	VALUE	rb_message_settings_controller, 
																void (*message_callback_method)(	VALUE			environment, 
																									const VALUE		message ) )	{
	RPbdb_MessageSettingsController_setMessageCallbackMethod();
	
	
}
*/
/*********************
*  message_callback  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgcall.html
void (*message_callback_method)(	VALUE			environment, 
									const VALUE		message ) RPbdb_MessageSettingsController_messageCallbackMethod( VALUE	rb_message_settings_controller )	{

}
*/
