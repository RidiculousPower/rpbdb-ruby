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

#include <rpdb/RPDB_LockDeadlockDetectorVerbositySettingsController.h>

#include <rpdb/RPDB_Environment.h>

#include "rb_RPDB_Environment.h"

#include "rb_RPDB_LockDeadlockDetectorSettingsController.h"
#include "rb_RPDB_LockDeadlockDetectorVerbositySettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment; 
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_LockDeadlockDetectorSettingsController;
extern	VALUE	rb_RPDB_LockDeadlockDetectorVerbositySettingsController;

void Init_RPDB_LockDeadlockDetectorVerbositySettingsController()	{

	rb_RPDB_LockDeadlockDetectorVerbositySettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																							"LockDeadlockDetectorVerbosity",	
																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 	"new",																rb_RPDB_LockDeadlockDetectorVerbositySettingsController_init,														1 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"initialize",													rb_RPDB_LockDeadlockDetectorVerbositySettingsController_init,														1 	);

	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"parent_environment",									rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"environment",												"parent_environment"	);


	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection,													0 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn,													0 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff,													0 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection,													0 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn,													0 	);
	rb_define_method(			rb_RPDB_LockDeadlockDetectorVerbositySettingsController, 				"shm_key",														rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_new(	VALUE	klass __attribute__ ((unused )),
																																		VALUE	rb_parent_deadlock_detector_settings_controller )	{

	RPDB_LockDeadlockDetectorSettingsController*	c_parent_deadlock_detector_settings_controller;
	C_RPDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_parent_deadlock_detector_settings_controller, c_parent_deadlock_detector_settings_controller );

	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller	= RUBY_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( RPDB_LockDeadlockDetectorVerbositySettingsController_new( c_parent_deadlock_detector_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_deadlock_detector_settings_controller;
	
	rb_obj_call_init(	rb_lock_deadlock_detector_verbosity_settings_controller,
					 1, 
					 argv );
	
	return rb_lock_deadlock_detector_verbosity_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_init(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller,
																																		VALUE	rb_parent_deadlock_detector_settings_controller __attribute__ ((unused )) )	{
	
	return rb_lock_deadlock_detector_verbosity_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
	C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_LockDeadlockDetectorVerbositySettingsController_parentEnvironment( c_lock_deadlock_detector_verbosity_settings_controller ) );
}

/*************************************************************
*  displayAdditionalInformationDuringDeadlockDetection  *
*************************************************************/

//	DB_VERB_DEADLOCK        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
	C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

	return ( RPDB_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( c_lock_deadlock_detector_verbosity_settings_controller )	?	Qtrue
																																													:	Qfalse );
}

	/*****************************************************************
	*  turnDisplayAdditionalInformationDuringDeadlockDetectionOn  *
	*****************************************************************/

	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

	/*****************************************************************
	*  turnDisplayAdditionalInformationDuringDeadlockDetectionOff  *
	*****************************************************************/

	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

/*************************************************
*  displayWaitTableDuringDeadlockDetection  *
*************************************************/

//	DB_VERB_WAITSFOR			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

	RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
	C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

	return ( RPDB_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( c_lock_deadlock_detector_verbosity_settings_controller )	?	Qtrue
																																										:	Qfalse );
}

	/*****************************************************
	*  turnDisplayWaitTableDuringDeadlockDetectionOn  *
	*****************************************************/

	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{

		RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );

		RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}

	/*****************************************************
	*  turnDisplayWaitTableDuringDeadlockDetectionOff  *
	*****************************************************/

	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller )	{
	
		RPDB_LockDeadlockDetectorVerbositySettingsController*	c_lock_deadlock_detector_verbosity_settings_controller;
		C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller );
	
		RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( c_lock_deadlock_detector_verbosity_settings_controller );

		return rb_lock_deadlock_detector_verbosity_settings_controller;
	}
