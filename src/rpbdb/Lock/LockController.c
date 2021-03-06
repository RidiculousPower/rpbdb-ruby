/*
 *		RPbdb::LockController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "LockController.h"
#include "Lock.h"

#include "Record.h"

#include <rpbdb/Environment.h>

#include <rpbdb/LockController.h>
#include <rpbdb/LockSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_Lock;
extern	VALUE	rb_RPbdb_LockController;
extern	VALUE	rb_RPbdb_LockSettingsController;

void Init_rb_RPbdb_LockController()	{

	rb_RPbdb_LockController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																										"LockController",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_LockController, 	"new",																													rb_RPbdb_LockController_new,																							-1 	);
	rb_define_method(						rb_RPbdb_LockController, 	"initialize",																										rb_RPbdb_LockController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_LockController, 	"settings_controller",																					rb_RPbdb_LockController_settingsController,															0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_LockController, 	"parent_environment",																						rb_RPbdb_LockController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_LockController, 	"locker_id",																										rb_RPbdb_LockController_lockerID,																				0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"id",																														"locker_id"	);
	rb_define_method(						rb_RPbdb_LockController, 	"create_lock",																									rb_RPbdb_LockController_createLock,																			0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"lock",																													"create_lock"	);
	rb_define_method(						rb_RPbdb_LockController, 	"queue_lock",																										rb_RPbdb_LockController_queueLock,																				0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"queue",																												"queue_lock"	);
	rb_define_method(						rb_RPbdb_LockController, 	"remove_lock_from_queue",																				rb_RPbdb_LockController_removeLockFromQueue,															0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"remove_from_queue",																						"remove_lock_from_queue"	);
	rb_define_method(						rb_RPbdb_LockController, 	"obtain_queued_locks",																					rb_RPbdb_LockController_obtainQueuedLocks,																0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"obtain_queued",																								"obtain_queued_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"release_queued_locks",																					rb_RPbdb_LockController_releaseQueuedLocks,															0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"release_queued",																								"release_queued_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"obtain_locks",																									rb_RPbdb_LockController_obtainLocks,																			0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"obtain",																												"obtain_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"obtain_locks_and_override_timeout",														rb_RPbdb_LockController_obtainLocksAndOverrideTimeout,										0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"obtain_and_override_timeout",																	"obtain_locks_and_override_timeout"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"override_timeout_and_obtain",																	"obtain_locks_and_override_timeout"	);
	rb_define_method(						rb_RPbdb_LockController, 	"release_locks",																								rb_RPbdb_LockController_releaseLocks,																		0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"release",																											"release_locks"	);

	//	what's the difference between releasing and closing locks?

	rb_define_method(						rb_RPbdb_LockController, 	"release_all_locks",																						rb_RPbdb_LockController_releaseAllLocks,																	0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"release_all",																									"release_all_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"release_all_locks_on_object",																	rb_RPbdb_LockController_releaseAllLocksOnObject,													0 	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_default_locks",																					rb_RPbdb_LockController_clearDefaultLocks,																0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_default",																								"clear_default_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_expired_locks",																					rb_RPbdb_LockController_clearExpiredLocks,																0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_expired",																								"clear_expired_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_for_locker_with_most_locks",								rb_RPbdb_LockController_clearLockRequestForLockerWithMostLocks,					0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_most_locks",																	"clear_lock_request_for_locker_with_most_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_request_for_locker_with_most_write_locks",								rb_RPbdb_LockController_clearLockRequestForLockerWithMostWriteLocks,			0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_most_write_locks",														"clear_request_for_locker_with_most_write_locks"	);

	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_for_locker_with_least_locks",								rb_RPbdb_LockController_clearLockRequestForLockerWithLeastLocks,					0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_least",																			"clear_lock_request_for_locker_with_least_locks"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_least",																									"clear_lock_request_for_locker_with_least_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_for_locker_with_least_write_locks",					rb_RPbdb_LockController_clearLockRequestForLockerWithLeastWriteLocks,		0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_least_write",																"clear_lock_request_for_locker_with_least_write_locks"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_least_write",																						"clear_lock_request_for_locker_with_least_write_locks"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_for_locker_with_oldest_lock",								rb_RPbdb_LockController_clearLockRequestForLockerWithOldestLock,					0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_oldest",																			"clear_lock_request_for_locker_with_oldest_lock"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_oldest",																									"clear_lock_request_for_locker_with_oldest_lock"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_for_locker_with_youngest_lock",							rb_RPbdb_LockController_clearLockRequestForLockerWithYoungestLock,				0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_for_youngest",																		"clear_lock_request_for_locker_with_youngest_lock"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_youngest",																								"clear_lock_request_for_locker_with_youngest_lock"	);
	rb_define_method(						rb_RPbdb_LockController, 	"clear_lock_request_from_random_locker",												rb_RPbdb_LockController_clearLockRequestForRandomLocker,									0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_request_from_random",																		"clear_lock_request_from_random_locker"	);
	rb_define_alias(						rb_RPbdb_LockController, 	"clear_random",																									"clear_lock_request_from_random_locker"	);
	rb_define_method(						rb_RPbdb_LockController, 	"close_all_locks",																							rb_RPbdb_LockController_closeAllLocks,																		0 	);
	rb_define_alias(						rb_RPbdb_LockController, 	"close_all",																										"close_all_locks"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LockController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);
	
	RPbdb_Environment*		c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_lock_controller	=	RUBY_RPBDB_LOCK_CONTROLLER( RPbdb_LockController_new( c_parent_environment ) );
	
	//	store reference to parent
	rb_iv_set(	rb_lock_controller,
							RPBDB_RB_LOCK_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );
	
	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_lock_controller,
										 1, 
										 argv );
	
	return rb_lock_controller;	
}

/*********
*  initialize  *
*********/
	
VALUE rb_RPbdb_LockController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{

	return rb_self;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPbdb_LockController_settingsController(	VALUE	rb_lock_controller )	{

	VALUE	rb_local_lock_settings_controller	=	Qnil;
	
	if ( ( rb_local_lock_settings_controller = rb_iv_get(	rb_lock_controller,
																												RPBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_LockController*		c_lock_controller;
		C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
	
		RPbdb_LockSettingsController*	c_local_lock_settings_controller	=	RPbdb_LockController_settingsController( c_lock_controller );

		rb_local_lock_settings_controller	=	RUBY_RPBDB_LOCK_SETTINGS_CONTROLLER( c_local_lock_settings_controller );

		rb_iv_set(	rb_lock_controller,
								RPBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER,
								rb_local_lock_settings_controller );
	}

	return rb_local_lock_settings_controller;
}

/****************
*  environment  *
****************/
VALUE rb_RPbdb_LockController_parentEnvironment(	VALUE	rb_lock_controller )	{

	VALUE	rb_parent_environment			=	rb_iv_get(	rb_lock_controller,
																								RPBDB_RB_LOCK_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/**************
*  locker_id  *
**************/

//	Our lock controller serves as a locker to gather a collection of locks - it needs a unique locker ID for identification
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_id.html
VALUE rb_RPbdb_LockController_lockerID( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	return INT2FIX( RPbdb_LockController_lockerID( c_lock_controller ) );
}

/****************
*  create_lock  *
****************/

VALUE rb_RPbdb_LockController_createLock( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_createLock( c_lock_controller );
	
	return rb_lock_controller;
}

/***************
*  queue_lock  *
***************/

VALUE rb_RPbdb_LockController_queueLock(	VALUE	rb_lock_controller,
											VALUE	rb_lock_for_queue )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_Lock*				c_lock_for_queue;
	C_RPBDB_LOCK( rb_lock_for_queue, c_lock_for_queue );
	
	RPbdb_LockController_queueLock(	c_lock_controller,
									c_lock_for_queue );

	return rb_lock_controller;
}

/***************************
*  remove_lock_from_queue  *
***************************/

VALUE rb_RPbdb_LockController_removeLockFromQueue(	VALUE	rb_lock_controller,
													VALUE	rb_queued_lock )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_Lock*				c_queued_lock;
	C_RPBDB_LOCK( rb_queued_lock, c_queued_lock );
	
	RPbdb_LockController_removeLockFromQueue(	c_lock_controller,
												c_queued_lock	);

	return rb_lock_controller;
}

/************************
*  obtain_queued_locks  *
************************/

VALUE rb_RPbdb_LockController_obtainQueuedLocks(	VALUE	rb_lock_controller	)	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_obtainQueuedLocks( c_lock_controller );

	return rb_lock_controller;
}

/*************************
*  release_queued_locks  *
*************************/

VALUE rb_RPbdb_LockController_releaseQueuedLocks(	VALUE	rb_lock_controller	)	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_releaseQueuedLocks( c_lock_controller );

	return rb_lock_controller;
}

/*****************
*  obtain_locks  *
*****************/

VALUE rb_RPbdb_LockController_obtainLocks(	VALUE	rb_lock_controller,
																					VALUE	rb_locks_to_obtain	)	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
	//	FIX - ruby array into C array of locks
	
	RPbdb_Lock**	c_locks_to_obtain	=	NULL;

	RPbdb_LockController_obtainLocks(	c_lock_controller,
										c_locks_to_obtain,
										RARRAY_LEN( rb_locks_to_obtain ) );
	
	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/**************************************
*  obtain_locks_and_override_timeout  *
**************************************/

VALUE rb_RPbdb_LockController_obtainLocksAndOverrideTimeout(	VALUE	rb_lock_controller,
																														VALUE	rb_locks_to_obtain,
																														VALUE	rb_timeout __attribute__ ((unused))	)	{

	//	FIX - array

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_Lock**	c_locks_to_obtain	=	NULL;
	uint32_t	c_timeout			=	0;

	RPbdb_LockController_obtainLocksAndOverrideTimeout(	c_lock_controller,
														c_locks_to_obtain,
														RARRAY_LEN( rb_locks_to_obtain ),
														c_timeout );

	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/******************
*  release_locks  *
******************/

VALUE rb_RPbdb_LockController_releaseLocks(	VALUE	rb_lock_controller,
											VALUE	rb_locks_to_release	)	{

	//	FIX - array

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_Lock**	c_locks_to_release	=	NULL;

	RPbdb_LockController_releaseLocks(	c_lock_controller,
										c_locks_to_release,
										RARRAY_LEN( rb_locks_to_release ) );

	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/**********************
*  release_all_locks  *
**********************/

VALUE rb_RPbdb_LockController_releaseAllLocks(	VALUE	rb_lock_controller	)	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_releaseAllLocks( c_lock_controller );

	return rb_lock_controller;
}

/********************************
*  release_all_locks_on_object  *
********************************/

VALUE rb_RPbdb_LockController_releaseAllLocksOnObject(	VALUE	rb_lock_controller,
														VALUE	rb_record	)	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_Record*			c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	RPbdb_LockController_releaseAllLocksOnObject(	c_lock_controller,
													c_record	);

	return rb_lock_controller;
}

/************************
*  clear_default_locks  *
************************/

//	If no default has been set, will randomly select for what types of locks to do deadlock detection
VALUE rb_RPbdb_LockController_clearDefaultLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_clearDefaultLocks( c_lock_controller );

	return rb_lock_controller;
}

/************************
*  clear_expired_locks  *
************************/

VALUE rb_RPbdb_LockController_clearExpiredLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPbdb_LockController_clearExpiredLocks( c_lock_controller );

	return rb_lock_controller;
}

/**************************************************
*  clear_lock_request_for_locker_with_most_locks  *
**************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithMostLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_clearLockRequestForLockerWithMostLocks( c_lock_controller );

	return rb_lock_controller;
}

/********************************************************
*  clear_lock_request_for_locker_with_most_write_locks  *
********************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithMostWriteLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_clearLockRequestForLockerWithMostWriteLocks( c_lock_controller );

	return rb_lock_controller;
}

/***************************************************
*  clear_lock_request_for_locker_with_least_locks  *
***************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithLeastLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_clearLockRequestForLockerWithLeastLocks( c_lock_controller );

	return rb_lock_controller;
}

/*********************************************************
*  clear_lock_request_for_locker_with_least_write_locks  *
*********************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithLeastWriteLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_clearLockRequestForLockerWithLeastWriteLocks( c_lock_controller );

	return rb_lock_controller;
}

/***************************************************
*  clear_lock_request_for_locker_with_oldest_lock  *
***************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithOldestLock( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPbdb_LockController_clearLockRequestForLockerWithOldestLock( c_lock_controller );

	return rb_lock_controller;
}

/*****************************************************
*  clear_lock_request_for_locker_with_youngest_lock  *
*****************************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForLockerWithYoungestLock( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPbdb_LockController_clearLockRequestForLockerWithYoungestLock( c_lock_controller );
	
	return rb_lock_controller;
}

/*****************************************
*  clear_lock_request_for_random_locker  *
*****************************************/

VALUE rb_RPbdb_LockController_clearLockRequestForRandomLocker( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPbdb_LockController_clearLockRequestForRandomLocker( c_lock_controller );
	
	return rb_lock_controller;
}

/*********************
*  close_all_locks  *
*********************/

VALUE rb_RPbdb_LockController_closeAllLocks( VALUE	rb_lock_controller )	{

	RPbdb_LockController*	c_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPbdb_LockController_closeAllLocks( c_lock_controller );

	return rb_lock_controller;
}
