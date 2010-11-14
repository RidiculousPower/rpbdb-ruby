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

#include "rb_RPDB_LockSettingsController.h"
#include "rb_RPDB_LockDeadlockDetectorSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_LockSettingsController.h>
#include <rpdb/RPDB_LockDeadlockDetectorSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_LockSettingsController;
extern	VALUE	rb_RPDB_LockDeadlockDetectorSettingsController;

void Init_RPDB_LockSettingsController()	{

	rb_RPDB_LockSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																	"Lock",	
																	rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LockSettingsController, 	"new",																rb_RPDB_LockSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"initialize",													rb_RPDB_LockSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPDB_LockSettingsController, 				"parent_environment",									rb_RPDB_LockSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_LockSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPDB_LockSettingsController,					"parent_settings_controller",					rb_RPDB_LockSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPDB_LockSettingsController, 				"on?",														rb_RPDB_LockSettingsController_on,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"off?",														rb_RPDB_LockSettingsController_off,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_on",														rb_RPDB_LockSettingsController_turnOn,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_off",														rb_RPDB_LockSettingsController_turnOff,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"prohibit_locking?",														rb_RPDB_LockSettingsController_prohibitLocking,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_prohibit_locking_on",														rb_RPDB_LockSettingsController_turnProhibitLockingOn,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_prohibit_locking_off",														rb_RPDB_LockSettingsController_turnProhibitLockingOff,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"timeout_returns_deny_not_deadlock?",														rb_RPDB_LockSettingsController_timeoutReturnsDenyNotDeadlock,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_timeout_returns_deny_not_deadlock_on",														rb_RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOn,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_timeout_returns_deny_not_deadlock_off",														rb_RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOff,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"no_waiting_for_conflicts?",														rb_RPDB_LockSettingsController_noWaitingForConflicts,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_no_waiting_for_conflicts_on",														rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOn,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_no_waiting_for_conflicts_off",														rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOff,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"lock_for_environment_not_database?",														rb_RPDB_LockSettingsController_lockForEnvironmentNotDatabase,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_lock_for_environment_not_database_on",														rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOn,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"turn_lock_for_environment_not_database_off",														rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOff,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"timeout",														rb_RPDB_LockSettingsController_timeout,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_timeout",														rb_RPDB_LockSettingsController_setTimeout,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"conflict_matrix",														rb_RPDB_LockSettingsController_conflictMatrix,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_conflict_matrix",														rb_RPDB_LockSettingsController_setConflictMatrix,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"max_lockers",														rb_RPDB_LockSettingsController_maxLockers,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_max_lockers",														rb_RPDB_LockSettingsController_setMaxLockers,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"max_locks",														rb_RPDB_LockSettingsController_maxLocks,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_max_locks",														rb_RPDB_LockSettingsController_setMaxLocks,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"max_objects",														rb_RPDB_LockSettingsController_maxObjects,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_max_objects",														rb_RPDB_LockSettingsController_setMaxObjects,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"number_of_partitions",														rb_RPDB_LockSettingsController_numberOfPartitions,													0 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"set_number_of_partitions",														rb_RPDB_LockSettingsController_setNumberOfPartitions,													1 	);
	rb_define_method(			rb_RPDB_LockSettingsController, 				"deadlock_detector_settings_controller",														rb_RPDB_LockSettingsController_deadlockDetectorSettingsController,													0 	);

}


/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPDB_LockSettingsController_new(	int			argc,
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

	VALUE	rb_lock_settings_controller	= RUBY_RPDB_LOCK_SETTINGS_CONTROLLER( RPDB_LockSettingsController_new( c_parent_settings_controller ) );

	rb_iv_set(	rb_lock_settings_controller,
							RPDB_RB_LOCK_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_lock_settings_controller,
										 1, 
										 argv );
	
	return rb_lock_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_LockSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_LockSettingsController_parentEnvironment(	VALUE	rb_lock_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_LockSettingsController_parentSettingsController( rb_lock_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_LockSettingsController_parentSettingsController(	VALUE	rb_lock_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_lock_settings_controller,
																										RPDB_RB_LOCK_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********
*  on?  *
********/

//	DB_INIT_LOCK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_LockSettingsController_on( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_on( c_lock_settings_controller )	?	Qtrue
																			:	Qfalse );
}

/*********
*  off?  *
*********/

//	DB_INIT_LOCK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_LockSettingsController_off( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_off( c_lock_settings_controller )	?	Qtrue
																			:	Qfalse );
}

	/************
	*  turn_on  *
	************/

	//	DB_INIT_LOCK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_LockSettingsController_turnOn( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnOn( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

	/*************
	*  turn_off  *
	*************/

	//	DB_INIT_LOCK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_LockSettingsController_turnOff( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnOff( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

/**********************
*  prohibit_locking?  *
**********************/

//	DB_NOLOCKING			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_LockSettingsController_prohibitLocking( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_prohibitLocking( c_lock_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/*****************************
	*  turn_prohibit_locking_on  *
	*****************************/

	//	DB_NOLOCKING			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_LockSettingsController_turnProhibitLockingOn( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnProhibitLockingOn( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

	/******************************
	*  turn_prohibit_locking_off  *
	******************************/

	//	DB_NOLOCKING			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_LockSettingsController_turnProhibitLockingOff( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnProhibitLockingOff( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

/*********************************************
*  timeout_returns_return_deny_not_deadlock  *
*********************************************/

//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_LockSettingsController_timeoutReturnsDenyNotDeadlock( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_timeoutReturnsDenyNotDeadlock( c_lock_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*****************************************************
	*  turn_timeout_returns_return_deny_not_deadlock_on  *
	*****************************************************/

	//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOn( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOn( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

	/******************************************************
	*  turn_timeout_returns_return_deny_not_deadlock_off  *
	******************************************************/

	//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOff( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOff( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

/******************************
*  no_waiting_for_conflicts?  *
******************************/

//	DB_LOCK_NOWAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
VALUE rb_RPDB_LockSettingsController_noWaitingForConflicts( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_noWaitingForConflicts( c_lock_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/*************************************
	*  turn_no_waiting_for_conflicts_on  *
	*************************************/

	//	DB_LOCK_NOWAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
	VALUE rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOn( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnNoWaitingForConflictsOn( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

	/**************************************
	*  turn_no_waiting_for_conflicts_off  *
	**************************************/

	//	DB_LOCK_NOWAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
	VALUE rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOff( VALUE	rb_lock_settings_controller )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_turnNoWaitingForConflictsOff( c_lock_settings_controller );

		return rb_lock_settings_controller;
	}

/***************************************
*  lock_for_environment_not_database?  *
***************************************/

//	DB_CDB_ALLDB            http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_LockSettingsController_lockForEnvironmentNotDatabase( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return ( RPDB_LockSettingsController_lockForEnvironmentNotDatabase( c_lock_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/**********************************************
	*  turn_lock_for_environment_not_database_on  *
	**********************************************/

		VALUE rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOn( VALUE	rb_lock_settings_controller )	{

			RPDB_LockSettingsController*	c_lock_settings_controller;
			C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

			RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOn( c_lock_settings_controller );

			return rb_lock_settings_controller;
		}

	/***********************************************
	*  turn_lock_for_environment_not_database_off  *
	***********************************************/

		VALUE rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOff( VALUE	rb_lock_settings_controller )	{

			RPDB_LockSettingsController*	c_lock_settings_controller;
			C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

			RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOff( c_lock_settings_controller );

			return rb_lock_settings_controller;
		}

/************
*  timeout  *
************/

//	DB_SET_LOCK_TIMEOUT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_timeout.html
VALUE rb_RPDB_LockSettingsController_timeout( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return INT2FIX( RPDB_LockSettingsController_timeout( c_lock_settings_controller ) );
}

	/****************
	*  set_timeout  *
	****************/

	//	DB_SET_LOCK_TIMEOUT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_timeout.html
	VALUE rb_RPDB_LockSettingsController_setTimeout(	VALUE	rb_lock_settings_controller,
														VALUE	timeout	)	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_setTimeout(	c_lock_settings_controller,
													FIX2INT( timeout ) );

		return rb_lock_settings_controller;
	}

/********************
*  conflict_matrix  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_conflicts.html
VALUE rb_RPDB_LockSettingsController_conflictMatrix( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

								//	FIX - return array

	RPDB_LockSettingsController_conflictMatrix( c_lock_settings_controller );
	
	VALUE	rb_conflict_matrix	=	Qnil;
	
	return rb_conflict_matrix;
}

	/************************
	*  set_conflict_matrix  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_conflicts.html
	VALUE rb_RPDB_LockSettingsController_setConflictMatrix( 	VALUE	rb_lock_settings_controller,
																														VALUE	rb_conflict_matrix __attribute__ ((unused )) )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		//	FIX
		uint8_t*	c_conflict_matrix;

		RPDB_LockSettingsController_setConflictMatrix(	c_lock_settings_controller,
																										c_conflict_matrix );

		return rb_lock_settings_controller;
	}

/****************
*  max_lockers  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_lockers.html
VALUE rb_RPDB_LockSettingsController_maxLockers( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return INT2FIX( RPDB_LockSettingsController_maxLockers( c_lock_settings_controller ) );
}

	/********************
	*  set_max_lockers  *
	********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_lockers.html
	VALUE rb_RPDB_LockSettingsController_setMaxLockers(	VALUE	rb_lock_settings_controller, 
															VALUE	rb_max_lockers )	{
	
		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );
	
		RPDB_LockSettingsController_setMaxLockers(	c_lock_settings_controller,
													FIX2INT( rb_max_lockers ) );
	
		return rb_lock_settings_controller;
	}

/**************
*  max_locks  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_locks.html
VALUE rb_RPDB_LockSettingsController_maxLocks( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return INT2FIX( RPDB_LockSettingsController_maxLocks( c_lock_settings_controller ) );
}

	/******************
	*  set_max_locks  *
	******************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_locks.html
	VALUE rb_RPDB_LockSettingsController_setMaxLocks(	VALUE	rb_lock_settings_controller, 
														VALUE	rb_max_locks )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_setMaxLocks(	c_lock_settings_controller,
													FIX2INT( rb_max_locks ) );
	
		return rb_lock_settings_controller;
	}

/****************
*  max_objects  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_objects.html
VALUE rb_RPDB_LockSettingsController_maxObjects( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return INT2FIX( RPDB_LockSettingsController_maxObjects( c_lock_settings_controller ) );
}

	/********************
	*  set_max_objects  *
	********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_max_objects.html
	VALUE rb_RPDB_LockSettingsController_setMaxObjects(	VALUE	rb_lock_settings_controller, 
															VALUE	rb_max_objects )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_setMaxObjects(	c_lock_settings_controller,
													FIX2INT( rb_max_objects ) );

		return rb_lock_settings_controller;
	}

/*************************
*  number_of_partitions  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_partitions.html
VALUE rb_RPDB_LockSettingsController_numberOfPartitions( VALUE	rb_lock_settings_controller )	{

	RPDB_LockSettingsController*	c_lock_settings_controller;
	C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

	return INT2FIX( RPDB_LockSettingsController_numberOfPartitions( c_lock_settings_controller ) );
}

	/*****************************
	*  set_number_of_partitions  *
	*****************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lk_partitions.html
	VALUE rb_RPDB_LockSettingsController_setNumberOfPartitions(	VALUE	rb_lock_settings_controller, 
																	VALUE	rb_partitions )	{

		RPDB_LockSettingsController*	c_lock_settings_controller;
		C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller );

		RPDB_LockSettingsController_setNumberOfPartitions(	c_lock_settings_controller,
															FIX2INT( rb_partitions ) );

		return rb_lock_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*********************************
*  deadlock_detector_controller  *
*********************************/

VALUE rb_RPDB_LockSettingsController_deadlockDetectorSettingsController( VALUE	rb_lock_settings_controller )	{

	VALUE	rb_deadlock_detector_settings_controller	=	Qnil;
	
	if ( ( rb_deadlock_detector_settings_controller = rb_iv_get(	rb_lock_settings_controller,
																																RPDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_deadlock_detector_settings_controller	=	rb_RPDB_LockDeadlockDetectorSettingsController_new(	1,
																																																		& rb_lock_settings_controller,
																																																		rb_RPDB_LockDeadlockDetectorSettingsController );
		rb_iv_set(	rb_lock_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER,
								rb_deadlock_detector_settings_controller );
	}
	
	return rb_deadlock_detector_settings_controller;
}
