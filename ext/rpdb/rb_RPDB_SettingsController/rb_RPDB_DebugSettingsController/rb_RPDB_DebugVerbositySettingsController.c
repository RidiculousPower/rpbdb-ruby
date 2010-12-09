/*
 *		Rbdb_settingsController:Rbdb_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DebugVerbositySettingsController.h"

#include "rb_Rbdb_DebugSettingsController.h"

#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_DebugVerbositySettingsController.h>
#include <rbdb/Rbdb_DebugSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DebugSettingsController;
extern	VALUE	rb_Rbdb_DebugVerbositySettingsController;

void Init_Rbdb_DebugVerbositySettingsController()	{

	rb_Rbdb_DebugVerbositySettingsController		=	rb_define_class_under(	rb_Rbdb_DebugSettingsController, 
																																				"Verbosity",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DebugVerbositySettingsController, 	"new",																												rb_Rbdb_DebugVerbositySettingsController_new,																									-1 	);
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"initialize",																									rb_Rbdb_DebugVerbositySettingsController_initialize,																								-1 	);
                    					
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"parent_environment",																					rb_Rbdb_DebugVerbositySettingsController_parentEnvironment,																		0 	);
	rb_define_alias(						rb_Rbdb_DebugVerbositySettingsController, 	"environment",																								"parent_environment"	);
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"parent_settings_controller",																	rb_Rbdb_DebugVerbositySettingsController_parentSettingsController,																		0 	);
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"parent_debug_settings_controller",														rb_Rbdb_DebugVerbositySettingsController_parentDebugSettingsController,																		0 	);
                    					
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"display_additional_information_during_recovery?",						rb_Rbdb_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery,					0 	);
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"turn_display_additional_information_during_recovery_on",			rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn,		0 	);
	rb_define_method(						rb_Rbdb_DebugVerbositySettingsController, 	"turn_display_additional_information_during_recovery_off",		rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff,		0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DebugVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_debug_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_debug_settings_controller, rb_Rbdb_DebugSettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent debug settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_debug_settings_controller == Qnil )	{
		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_debug_settings_controller = rb_Rbdb_SettingsController_debugSettingsController( rb_parent_settings_controller );
	}

	Rbdb_DebugSettingsController*	c_parent_debug_settings_controller;
	C_Rbdb_DEBUG_SETTINGS_CONTROLLER( rb_parent_debug_settings_controller, c_parent_debug_settings_controller );
	
	Rbdb_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller	=	Rbdb_DebugSettingsController_verbositySettingsController( c_parent_debug_settings_controller );
	
	VALUE	rb_debug_verbosity_settings_controller	= RUBY_Rbdb_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( c_debug_verbosity_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_debug_verbosity_settings_controller,
							Rbdb_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER,
							rb_parent_debug_settings_controller );

	VALUE	argv[]	=	{ rb_parent_debug_settings_controller };
	rb_obj_call_init(	rb_debug_verbosity_settings_controller,
										 1, 
										 argv );
	
	return rb_debug_verbosity_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DebugVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DebugVerbositySettingsController_parentSettingsController( rb_debug_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DebugVerbositySettingsController_parentSettingsController(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_debug_settings_controller		=	rb_Rbdb_DebugVerbositySettingsController_parentDebugSettingsController( rb_debug_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller					=	rb_Rbdb_DebugSettingsController_parentSettingsController( rb_parent_debug_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*************************************
*  parent_debug_settings_controller  *
*************************************/

VALUE rb_Rbdb_DebugVerbositySettingsController_parentDebugSettingsController(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_debug_verbosity_settings_controller,
																										Rbdb_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/***************************************************
*  display_additional_information_during_recovery  *
***************************************************/

//	DB_VERB_RECOVERY        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_Rbdb_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller )	{

	Rbdb_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
	C_Rbdb_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

	return ( Rbdb_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( c_debug_verbosity_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/***********************************************************
	*  turn_display_additional_information_during_recovery_on  *
	***********************************************************/

	VALUE rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller )	{

		Rbdb_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_Rbdb_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );
	
		Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( c_debug_verbosity_settings_controller );
		
		return rb_debug_verbosity_settings_controller;
	}

	/************************************************************
	*  turn_display_additional_information_during_recovery_off  *
	************************************************************/

	VALUE rb_Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller )	{

		Rbdb_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_Rbdb_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

		Rbdb_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( c_debug_verbosity_settings_controller );

		return rb_debug_verbosity_settings_controller;
	}
