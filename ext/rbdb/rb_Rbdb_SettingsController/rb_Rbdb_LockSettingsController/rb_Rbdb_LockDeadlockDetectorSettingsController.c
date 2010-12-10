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

#include "rb_Rbdb_LockDeadlockDetectorSettingsController.h"
#include "rb_Rbdb_LockDeadlockDetectorVerbositySettingsController.h"
#include "rb_Rbdb_LockSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_LockSettingsController.h>
#include <rbdb/Rbdb_LockDeadlockDetectorSettingsController.h>
#include <rbdb/Rbdb_LockDeadlockDetectorVerbositySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_LockSettingsController;
extern	VALUE	rb_Rbdb_LockDeadlockDetectorSettingsController;
extern	VALUE	rb_Rbdb_LockDeadlockDetectorVerbositySettingsController;

void Init_Rbdb_LockDeadlockDetectorSettingsController()	{

	rb_Rbdb_LockDeadlockDetectorSettingsController		=	rb_define_class_under(	rb_Rbdb_LockSettingsController, 
																																							"DeadlockDetector",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_LockDeadlockDetectorSettingsController, 	"new",																rb_Rbdb_LockDeadlockDetectorSettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"initialize",													rb_Rbdb_LockDeadlockDetectorSettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"parent_environment",									rb_Rbdb_LockDeadlockDetectorSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController,					"parent_settings_controller",					rb_Rbdb_LockDeadlockDetectorSettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController,					"parent_lock_settings_controller",		rb_Rbdb_LockDeadlockDetectorSettingsController_parentLockSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"is_default?",														rb_Rbdb_LockDeadlockDetectorSettingsController_isDefault,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_default",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToDefault,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_expired?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectExpired,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_expired",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectExpired,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_most_locks?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_most_locks",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_most_write_locks?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostWriteLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_most_write_locks",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostWriteLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_fewest_locks?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_fewest_locks",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_fewest_write_locks?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestWriteLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_fewest_write_locks",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestWriteLocks,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_oldest_lock?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithOldestLock,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_oldest_lock",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithOldestLock,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_locker_with_youngest_lock?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithYoungestLock,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_locker_with_youngest_lock",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithYoungestLock,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"reject_random_lock?",														rb_Rbdb_LockDeadlockDetectorSettingsController_rejectRandom,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"set_to_reject_random_lock",														rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectRandom,													0 	);
	rb_define_method(			rb_Rbdb_LockDeadlockDetectorSettingsController, 				"verbosity_settings_controller",														rb_Rbdb_LockDeadlockDetectorSettingsController_verbositySettingsController,													0 	);

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_lock_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_lock_settings_controller, rb_Rbdb_LockSettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent lock settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_lock_settings_controller == Qnil )	{
		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_lock_settings_controller = rb_Rbdb_SettingsController_lockSettingsController( rb_parent_settings_controller );
	}

	Rbdb_LockSettingsController*	c_parent_lock_settings_controller;
	C_Rbdb_LOCK_SETTINGS_CONTROLLER( rb_parent_lock_settings_controller, c_parent_lock_settings_controller );
	
	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_settings_controller	=	Rbdb_LockSettingsController_deadlockDetectorSettingsController( c_parent_lock_settings_controller );

	VALUE	rb_lock_deadlock_detector_settings_controller	= RUBY_RBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( c_lock_deadlock_settings_controller );

	rb_iv_set(	rb_lock_deadlock_detector_settings_controller,
							Rbdb_RB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_SETTINGS_CONTROLLER,
							rb_parent_lock_settings_controller );

	VALUE	argv[]	=	{ rb_parent_lock_settings_controller };
	rb_obj_call_init(	rb_lock_deadlock_detector_settings_controller,
										 1, 
										 argv );
	
	return rb_lock_deadlock_detector_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_LockDeadlockDetectorSettingsController_parentSettingsController( rb_lock_deadlock_detector_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_settings_controller )	{

	VALUE	rb_parent_lock_settings_controller		=	rb_Rbdb_LockDeadlockDetectorSettingsController_parentLockSettingsController( rb_lock_deadlock_detector_settings_controller );
	VALUE	rb_parent_settings_controller					=	rb_Rbdb_LockSettingsController_parentSettingsController( rb_parent_lock_settings_controller );
	
	return rb_parent_settings_controller;	
}

/************************************
*  parent_lock_settings_controller  *
************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_settings_controller )	{

	VALUE	rb_parent_lock_settings_controller	=	rb_iv_get(	rb_lock_deadlock_detector_settings_controller,
																													Rbdb_RB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_SETTINGS_CONTROLLER );

	return rb_parent_lock_settings_controller;
}

/****************
*  is_default?  *
****************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_isDefault( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_isDefault( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*******************
	*  set_to_default  *
	*******************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_detect.html
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToDefault( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToDefault( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/********************
*  reject_expired?  *
********************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectExpired( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/**************************
	*  set_to_reject_expired  *
	**************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectExpired( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/***********************************
*  reject_locker_with_most_locks?  *
***********************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostLocks( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/*****************************************
	*  set_to_reject_locker_with_most_locks  *
	*****************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostLocks( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/*****************************************
*  reject_locker_with_most_write_locks?  *
*****************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostWriteLocks( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/***********************************************
	*  set_to_reject_locker_with_most_write_locks  *
	***********************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );
	
		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostWriteLocks( c_lock_deadlock_detector_settings_controller );
	
		return rb_lock_deadlock_detector_settings_controller;
	}

/*************************************
*  reject_locker_with_fewest_locks?  *
*************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestLocks( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*******************************************
	*  set_to_reject_locker_with_fewest_locks  *
	*******************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestLocks( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/*******************************************
*  reject_locker_with_fewest_write_locks?  *
*******************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestWriteLocks( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/*************************************************
	*  set_to_reject_locker_with_fewest_write_locks  *
	*************************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestWriteLocks( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/************************************
*  reject_locker_with_oldest_lock?  *
************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithOldestLock( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/******************************************
	*  set_to_reject_locker_with_oldest_lock  *
	******************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithOldestLock( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/**************************************
*  reject_locker_with_youngest_lock?  *
**************************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithYoungestLock( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/********************************************
	*  set_to_reject_locker_with_youngest_lock  *
	********************************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithYoungestLock( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/************************
*  reject_random_lock?  *
************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
	C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

	return ( Rbdb_LockDeadlockDetectorSettingsController_rejectRandom( c_lock_deadlock_detector_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/******************************
	*  set_to_reject_random_lock  *
	******************************/

	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller )	{

		Rbdb_LockDeadlockDetectorSettingsController*	c_lock_deadlock_detector_settings_controller;
		C_Rbdb_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller );

		Rbdb_LockDeadlockDetectorSettingsController_setToRejectRandom( c_lock_deadlock_detector_settings_controller );

		return rb_lock_deadlock_detector_settings_controller;
	}

/**********************************
*  verbosity_settings_controller  *
**********************************/

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_verbositySettingsController( VALUE	rb_lock_deadlock_detector_settings_controller )	{

	VALUE	rb_deadlock_detector_verbosity_settings_controller	=	Qnil;
	
	if ( ( rb_deadlock_detector_verbosity_settings_controller = rb_iv_get(	rb_lock_deadlock_detector_settings_controller,
																																					Rbdb_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_deadlock_detector_verbosity_settings_controller	=	rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_new(	1,
																																																												& rb_lock_deadlock_detector_settings_controller,
																																																												rb_Rbdb_LockDeadlockDetectorVerbositySettingsController );
		rb_iv_set(	rb_lock_deadlock_detector_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER,
								rb_deadlock_detector_verbosity_settings_controller );
	}
	
	return rb_deadlock_detector_verbosity_settings_controller;
}
