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

#include "Environment.h"
#include "RPbdb.h"

#include "SettingsController.h"
#include "LockSettingsController.h"
#include "LockDeadlockDetectorSettingsController.h"
#include "LockDeadlockDetectorVerbositySettingsController.h"

#include <rpbdb/LockDeadlockDetectorVerbositySettingsController.h>
#include <rpbdb/LockDeadlockDetectorSettingsController.h>
#include <rpbdb/LockSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rpbdb/Environment.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb; 
extern	VALUE	rb_RPbdb_Environment; 
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_LockSettingsController;
extern	VALUE	rb_RPbdb_LockDeadlockDetectorSettingsController;
extern	VALUE	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController;

void Init_rb_RPbdb_LockDeadlockDetectorVerbositySettingsController()	{

	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController		=	rb_define_class_under(	rb_RPbdb_LockDeadlockDetectorSettingsController, 
																																											"Verbosity",	
																																											rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 	"new",																									rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"initialize",																						rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_initialize,														-1 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController,				"parent_settings_controller",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController,				"parent_lock_settings_controller",											rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController,								0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController,				"parent_lock_deadlock_detector_settings_controller",		rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"parent_environment",																		rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"environment",																					"parent_environment"	);


	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"display_additional_information_during_deadlock_detection?",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection,													0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"turn_display_additional_information_during_deadlock_detection_on",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn,													0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"turn_display_additional_information_during_deadlock_detection_off",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff,													0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"display_wait_table_during_deadlock_detection?",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection,													0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"turn_display_wait_table_during_deadlock_detection_on",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn,													0 	);
	rb_define_method(			rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, 				"turn_display_wait_table_during_deadlock_detection_off",														rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_new(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_lock_settings_controller										=	Qnil;
	VALUE	rb_parent_lock_deadlock_detector_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_lock_settings_controller, rb_RPbdb_LockSettingsController ),
																						R_MatchAncestorInstance( rb_parent_lock_deadlock_detector_settings_controller, rb_RPbdb_LockDeadlockDetectorSettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent lock settings controller> ]",
			"[ <parent lock deadlock detector settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_lock_settings_controller == Qnil
			&&	rb_parent_lock_deadlock_detector_settings_controller == Qnil )	{
		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_lock_settings_controller = rb_RPbdb_SettingsController_lockSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_lock_settings_controller != Qnil )	{
		rb_parent_lock_deadlock_detector_settings_controller	=	rb_RPbdb_LockSettingsController_deadlockDetectorSettingsController( rb_parent_lock_settings_controller );
	}

	RPbdb_LockDeadlockDetectorSettingsController*	c_parent_lock_deadlock_detector_settings_controller;
	C_RPBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_parent_lock_deadlock_detector_settings_controller, c_parent_lock_deadlock_detector_settings_controller );
	
	RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_verbosity_settings_controller	=	RPbdb_LockDeadlockDetectorSettingsController_verbositySettingsController( c_parent_lock_deadlock_detector_settings_controller );

	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller	= RUBY_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( c_lock_deadlock_verbosity_settings_controller );

	rb_iv_set(	rb_lock_deadlock_detector_verbosity_settings_controller,
							RPBDB_RB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER,
							rb_parent_lock_deadlock_detector_settings_controller );

	VALUE	argv[]	=	{ rb_parent_lock_deadlock_detector_settings_controller };
	rb_obj_call_init(	rb_lock_deadlock_detector_verbosity_settings_controller,
										 1, 
										 argv );
	
	return rb_lock_deadlock_detector_verbosity_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentSettingsController( rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	VALUE	rb_parent_lock_settings_controller		=	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController( rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller					=	rb_RPbdb_LockSettingsController_parentSettingsController( rb_parent_lock_settings_controller );
	
	return rb_parent_settings_controller;	
}

/************************************
*  parent_lock_settings_controller  *
************************************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	VALUE	rb_parent_lock_deadlock_detector_settings_controller		=	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController( rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE	rb_parent_lock_settings_controller											=	rb_RPbdb_LockDeadlockDetectorSettingsController_parentLockSettingsController( rb_parent_lock_deadlock_detector_settings_controller );
	
	return rb_parent_lock_settings_controller;	
}

/******************************************************
*  parent_lock_deadlock_detector_settings_controller  *
******************************************************/

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	VALUE	rb_parent_lock_deadlock_detector_settings_controller	=	rb_iv_get(	rb_lock_deadlock_detector_verbosity_settings_controller,
																																						RPBDB_RB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER );

	return rb_parent_lock_deadlock_detector_settings_controller;
}

/**************************************************************
*  display_additional_information_during_deadlock_detection?  *
**************************************************************/

//	DB_VERB_DEADLOCK        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
	C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

	return ( RPbdb_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( c_lock_deadlock_detector_verbosity_settings_controller )	?	Qtrue
																																													:	Qfalse );
}

	/*********************************************************************
	*  turn_display_additional_information_during_deadlock_detection_on  *
	*********************************************************************/

	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

	/**********************************************************************
	*  turn_display_additional_information_during_deadlock_detection_off  *
	**********************************************************************/

	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

/**************************************************
*  display_wait_table_during_deadlock_detection?  *
**************************************************/

//	DB_VERB_WAITSFOR			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
	C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

	return ( RPbdb_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( c_lock_deadlock_detector_verbosity_settings_controller )	?	Qtrue
																																										:	Qfalse );
}

	/*********************************************************
	*  turn_display_wait_table_during_deadlock_detection_on  *
	*********************************************************/

	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

	/**********************************************************
	*  turn_display_wait_table_during_deadlock_detection_off  *
	**********************************************************/

	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{
	
		RPbdb_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );
	
		RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}
