/*
 *		RPDB_settingsController:RPDB_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DebugVerbositySettingsController.h"

#include "rb_RPDB_DebugSettingsController.h"

#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_DebugVerbositySettingsController.h>
#include <rpdb/RPDB_DebugSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DebugSettingsController;
extern	VALUE	rb_RPDB_DebugVerbositySettingsController;

void Init_RPDB_DebugVerbositySettingsController()	{

	rb_RPDB_DebugVerbositySettingsController		=	rb_define_class_under(	rb_RPDB_DebugSettingsController, 
																																				"Verbosity",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DebugVerbositySettingsController, 	"new",																												rb_RPDB_DebugVerbositySettingsController_new,																									-1 	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"initialize",																									rb_RPDB_DebugVerbositySettingsController_initialize,																								-1 	);
                    					
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"parent_environment",																					rb_RPDB_DebugVerbositySettingsController_parentEnvironment,																		0 	);
	rb_define_alias(						rb_RPDB_DebugVerbositySettingsController, 	"environment",																								"parent_environment"	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"parent_settings_controller",																	rb_RPDB_DebugVerbositySettingsController_parentSettingsController,																		0 	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"parent_debug_settings_controller",														rb_RPDB_DebugVerbositySettingsController_parentDebugSettingsController,																		0 	);
                    					
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"display_additional_information_during_recovery?",						rb_RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery,					0 	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"turn_display_additional_information_during_recovery_on",			rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn,		0 	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"turn_display_additional_information_during_recovery_off",		rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff,		0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DebugVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_debug_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_debug_settings_controller, rb_RPDB_DebugSettingsController ) ) ),
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
		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_debug_settings_controller = rb_RPDB_SettingsController_debugSettingsController( rb_parent_settings_controller );
	}

	RPDB_DebugSettingsController*	c_parent_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_parent_debug_settings_controller, c_parent_debug_settings_controller );
	
	RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller	=	RPDB_DebugSettingsController_verbositySettingsController( c_parent_debug_settings_controller );
	
	VALUE	rb_debug_verbosity_settings_controller	= RUBY_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( c_debug_verbosity_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_debug_verbosity_settings_controller,
							RPDB_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER,
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

VALUE rb_RPDB_DebugVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_DebugVerbositySettingsController_parentSettingsController( rb_debug_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DebugVerbositySettingsController_parentSettingsController(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_debug_settings_controller		=	rb_RPDB_DebugVerbositySettingsController_parentDebugSettingsController( rb_debug_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller					=	rb_RPDB_DebugSettingsController_parentSettingsController( rb_parent_debug_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*************************************
*  parent_debug_settings_controller  *
*************************************/

VALUE rb_RPDB_DebugVerbositySettingsController_parentDebugSettingsController(	VALUE	rb_debug_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_debug_verbosity_settings_controller,
																										RPDB_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/***************************************************
*  display_additional_information_during_recovery  *
***************************************************/

//	DB_VERB_RECOVERY        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller )	{

	RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
	C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

	return ( RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( c_debug_verbosity_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/***********************************************************
	*  turn_display_additional_information_during_recovery_on  *
	***********************************************************/

	VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller )	{

		RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );
	
		RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( c_debug_verbosity_settings_controller );
		
		return rb_debug_verbosity_settings_controller;
	}

	/************************************************************
	*  turn_display_additional_information_during_recovery_off  *
	************************************************************/

	VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller )	{

		RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

		RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( c_debug_verbosity_settings_controller );

		return rb_debug_verbosity_settings_controller;
	}
