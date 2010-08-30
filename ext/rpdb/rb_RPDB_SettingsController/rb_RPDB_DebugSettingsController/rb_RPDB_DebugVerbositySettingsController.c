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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_DebugVerbositySettingsController.h>
#include "rb_RPDB_DebugVerbositySettingsController.h"
#include "rb_RPDB_Environment.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_DebugSettingsController;
extern	VALUE	rb_RPDB_DebugVerbositySettingsController;

void Init_RPDB_DebugVerbositySettingsController()	{

	rb_RPDB_DebugVerbositySettingsController		=	rb_define_class_under(	rb_RPDB_DebugSettingsController, 
																																				"DebugVerbositySettingsController",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DebugVerbositySettingsController, 	"new",																												rb_RPDB_DebugVerbositySettingsController_new,																									1 	);
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"initialize",																									rb_RPDB_DebugVerbositySettingsController_init,																								1 	);
                    					
	rb_define_method(						rb_RPDB_DebugVerbositySettingsController, 	"parent_environment",																					rb_RPDB_DebugVerbositySettingsController_parentEnvironment,																		0 	);
	rb_define_alias(						rb_RPDB_DebugVerbositySettingsController, 	"environment",																								"parent_environment"	);
                    					
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
*  new  *
*************/

VALUE rb_RPDB_DebugVerbositySettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_debug_settings_controller )	{
	
	RPDB_DebugSettingsController*	c_parent_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_parent_debug_settings_controller, c_parent_debug_settings_controller );
	
	VALUE	rb_debug_verbosity_settings_controller	= RUBY_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( RPDB_DebugVerbositySettingsController_new( c_parent_debug_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_debug_settings_controller;
	
	rb_obj_call_init(	rb_debug_verbosity_settings_controller,
					 1, 
					 argv );
	
	return rb_debug_verbosity_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DebugVerbositySettingsController_init(	VALUE	rb_debug_verbosity_settings_controller,
																											VALUE	rb_parent_debug_settings_controller __attribute__ ((unused )) )	{

	return rb_debug_verbosity_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DebugVerbositySettingsController_parentEnvironment(	VALUE	rb_debug_verbosity_settings_controller )	{

	RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
	C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DebugVerbositySettingsController_parentEnvironment( c_debug_verbosity_settings_controller ) );
}

/*************************************************
*  displayAdditionalInformationDuringRecovery  *
*************************************************/

//	DB_VERB_RECOVERY        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( VALUE	rb_debug_verbosity_settings_controller )	{

	RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
	C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

	return ( RPDB_DebugVerbositySettingsController_displayAdditionalInformationDuringRecovery( c_debug_verbosity_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*********************************************************
	*  turnDisplayAdditionalInformationDuringRecoveryOn  *
	*********************************************************/

	VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( VALUE	rb_debug_verbosity_settings_controller )	{

		RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );
	
		RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOn( c_debug_verbosity_settings_controller );
		
		return rb_debug_verbosity_settings_controller;
	}

	/*********************************************************
	*  turnDisplayAdditionalInformationDuringRecoveryOff  *
	*********************************************************/

	VALUE rb_RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( VALUE	rb_debug_verbosity_settings_controller )	{

		RPDB_DebugVerbositySettingsController*	c_debug_verbosity_settings_controller;
		C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller );

		RPDB_DebugVerbositySettingsController_turnDisplayAdditionalInformationDuringRecoveryOff( c_debug_verbosity_settings_controller );

		return rb_debug_verbosity_settings_controller;
	}
