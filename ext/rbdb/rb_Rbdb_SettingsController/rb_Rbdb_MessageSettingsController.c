/*
 *		Rbdb::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_MessageSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_Environment.h"

#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_MessageSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_MessageSettingsController;

void Init_Rbdb_MessageSettingsController()	{

	rb_Rbdb_MessageSettingsController		=	rb_define_class_under(	rb_Rbdb_SettingsController, 
																																		"Message",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MessageSettingsController, 	"new",																rb_Rbdb_MessageSettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_MessageSettingsController, 				"initialize",													rb_Rbdb_MessageSettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_MessageSettingsController, 				"parent_environment",									rb_Rbdb_MessageSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_MessageSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_MessageSettingsController,				"parent_settings_controller",					rb_Rbdb_MessageSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_MessageSettingsController, 				"file",														rb_Rbdb_MessageSettingsController_file,													0 	);
	rb_define_method(			rb_Rbdb_MessageSettingsController, 				"set_file",														rb_Rbdb_MessageSettingsController_setFile,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MessageSettingsController_new(	int			argc,
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

	VALUE	rb_message_settings_controller	= RUBY_RBDB_MESSAGE_SETTINGS_CONTROLLER( Rbdb_SettingsController_messageSettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_message_settings_controller,
							Rbdb_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_MessageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_MessageSettingsController_parentEnvironment(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_MessageSettingsController_parentSettingsController( rb_message_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_MessageSettingsController_parentSettingsController(	VALUE	rb_message_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_message_settings_controller,
																										Rbdb_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgfile.html
VALUE rb_Rbdb_MessageSettingsController_file( VALUE	rb_message_settings_controller )	{

	Rbdb_MessageSettingsController*	c_message_settings_controller;
	C_Rbdb_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	//	FIX - FILE
	Rbdb_MessageSettingsController_file( c_message_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/*************
*  set_file  *
*************/

VALUE rb_Rbdb_MessageSettingsController_setFile(	VALUE	rb_message_settings_controller, 
																									VALUE	rb_message_file __attribute__ ((unused )) )	{

	Rbdb_MessageSettingsController*	c_message_settings_controller;
	C_Rbdb_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller );

	FILE*	c_message_file;

	//	FIX - FILE
	Rbdb_MessageSettingsController_setFile(	c_message_settings_controller,
																					c_message_file );

	return rb_message_settings_controller;
}

/*************************
*  set_message_callback  *
*************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setMessageCallbackMethod(	VALUE	rb_message_settings_controller, 
																void (*message_callback_method)(	VALUE			environment, 
																									const VALUE		message ) )	{
	Rbdb_MessageSettingsController_setMessageCallbackMethod();
	
	
}
*/
/*********************
*  message_callback  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_msgcall.html
void (*message_callback_method)(	VALUE			environment, 
									const VALUE		message ) Rbdb_MessageSettingsController_messageCallbackMethod( VALUE	rb_message_settings_controller )	{

}
*/
