/*
 *		RPDB::LockController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_LockController.h"
#include "rb_RPDB_Lock.h"

#include "rb_RPDB_Record.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_LockController.h>
#include <rpdb/RPDB_LockSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_Lock;
extern	VALUE	rb_RPDB_LockController;
extern	VALUE	rb_RPDB_LockSettingsController;

void Init_RPDB_LockController()	{

	rb_RPDB_LockController	=	rb_define_class_under(	rb_RPDB_Environment, 
																										"LockController",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LockController, 	"new",																													rb_RPDB_LockController_new,																							-1 	);
	rb_define_method(						rb_RPDB_LockController, 	"initialize",																										rb_RPDB_LockController_init,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_LockController, 	"settings_controller",																					rb_RPDB_LockController_settingsController,															0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_LockController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_LockController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_LockController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_LockController, 	"parent_environment",																						rb_RPDB_LockController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPDB_LockController, 	"locker_id",																										rb_RPDB_LockController_lockerID,																				0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"id",																														"locker_id"	);
	rb_define_method(						rb_RPDB_LockController, 	"create_lock",																									rb_RPDB_LockController_createLock,																			0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"lock",																													"create_lock"	);
	rb_define_method(						rb_RPDB_LockController, 	"queue_lock",																										rb_RPDB_LockController_queueLock,																				0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"queue",																												"queue_lock"	);
	rb_define_method(						rb_RPDB_LockController, 	"remove_lock_from_queue",																				rb_RPDB_LockController_removeLockFromQueue,															0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"remove_from_queue",																						"remove_lock_from_queue"	);
	rb_define_method(						rb_RPDB_LockController, 	"obtain_queued_locks",																					rb_RPDB_LockController_obtainQueuedLocks,																0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"obtain_queued",																								"obtain_queued_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"release_queued_locks",																					rb_RPDB_LockController_releaseQueuedLocks,															0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"release_queued",																								"release_queued_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"obtain_locks",																									rb_RPDB_LockController_obtainLocks,																			0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"obtain",																												"obtain_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"obtain_locks_and_override_timeout",														rb_RPDB_LockController_obtainLocksAndOverrideTimeout,										0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"obtain_and_override_timeout",																	"obtain_locks_and_override_timeout"	);
	rb_define_alias(						rb_RPDB_LockController, 	"override_timeout_and_obtain",																	"obtain_locks_and_override_timeout"	);
	rb_define_method(						rb_RPDB_LockController, 	"release_locks",																								rb_RPDB_LockController_releaseLocks,																		0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"release",																											"release_locks"	);

	//	what's the difference between releasing and closing locks?

	rb_define_method(						rb_RPDB_LockController, 	"release_all_locks",																						rb_RPDB_LockController_releaseAllLocks,																	0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"release_all",																									"release_all_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"release_all_locks_on_object",																	rb_RPDB_LockController_releaseAllLocksOnObject,													0 	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_default_locks",																					rb_RPDB_LockController_clearDefaultLocks,																0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_default",																								"clear_default_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_expired_locks",																					rb_RPDB_LockController_clearExpiredLocks,																0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_expired",																								"clear_expired_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_for_locker_with_most_locks",								rb_RPDB_LockController_clearLockRequestForLockerWithMostLocks,					0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_most_locks",																	"clear_lock_request_for_locker_with_most_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_request_for_locker_with_most_write_locks",								rb_RPDB_LockController_clearLockRequestForLockerWithMostWriteLocks,			0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_most_write_locks",														"clear_request_for_locker_with_most_write_locks"	);

	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_for_locker_with_least_locks",								rb_RPDB_LockController_clearLockRequestForLockerWithLeastLocks,					0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_least",																			"clear_lock_request_for_locker_with_least_locks"	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_least",																									"clear_lock_request_for_locker_with_least_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_for_locker_with_least_write_locks",					rb_RPDB_LockController_clearLockRequestForLockerWithLeastWriteLocks,		0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_least_write",																"clear_lock_request_for_locker_with_least_write_locks"	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_least_write",																						"clear_lock_request_for_locker_with_least_write_locks"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_for_locker_with_oldest_lock",								rb_RPDB_LockController_clearLockRequestForLockerWithOldestLock,					0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_oldest",																			"clear_lock_request_for_locker_with_oldest_lock"	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_oldest",																									"clear_lock_request_for_locker_with_oldest_lock"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_for_locker_with_youngest_lock",							rb_RPDB_LockController_clearLockRequestForLockerWithYoungestLock,				0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_for_youngest",																		"clear_lock_request_for_locker_with_youngest_lock"	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_youngest",																								"clear_lock_request_for_locker_with_youngest_lock"	);
	rb_define_method(						rb_RPDB_LockController, 	"clear_lock_request_from_random_locker",												rb_RPDB_LockController_clearLockRequestForRandomLocker,									0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_request_from_random",																		"clear_lock_request_from_random_locker"	);
	rb_define_alias(						rb_RPDB_LockController, 	"clear_random",																									"clear_lock_request_from_random_locker"	);
	rb_define_method(						rb_RPDB_LockController, 	"close_all_locks",																							rb_RPDB_LockController_closeAllLocks,																		0 	);
	rb_define_alias(						rb_RPDB_LockController, 	"close_all",																										"close_all_locks"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_LockController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);
	
	RPDB_Environment*		c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_lock_controller	=	RUBY_RPDB_LOCK_CONTROLLER( RPDB_LockController_new( c_parent_environment ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_environment;
	
	rb_obj_call_init(	rb_lock_controller,
					 1, 
					 argv );
	
	return rb_lock_controller;	
}

/*********
*  init  *
*********/
	
VALUE rb_RPDB_LockController_init(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{

	return rb_self;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPDB_LockController_settingsController(	VALUE	rb_lock_controller )	{

	RPDB_LockController*		c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	return RUBY_RPDB_LOCK_SETTINGS_CONTROLLER( RPDB_LockController_settingsController( c_lock_controller ) );
}

/****************
*  environment  *
****************/
VALUE rb_RPDB_LockController_parentEnvironment(	VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_LockController_parentEnvironment( c_lock_controller ) );

}

/**************
*  locker_id  *
**************/

//	Our lock controller serves as a locker to gather a collection of locks - it needs a unique locker ID for identification
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_id.html
VALUE rb_RPDB_LockController_lockerID( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	return INT2FIX( RPDB_LockController_lockerID( c_lock_controller ) );
}

/****************
*  create_lock  *
****************/

VALUE rb_RPDB_LockController_createLock( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_createLock( c_lock_controller );
	
	return rb_lock_controller;
}

/***************
*  queue_lock  *
***************/

VALUE rb_RPDB_LockController_queueLock(	VALUE	rb_lock_controller,
											VALUE	rb_lock_for_queue )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_Lock*				c_lock_for_queue;
	C_RPDB_LOCK( rb_lock_for_queue, c_lock_for_queue );
	
	RPDB_LockController_queueLock(	c_lock_controller,
									c_lock_for_queue );

	return rb_lock_controller;
}

/***************************
*  remove_lock_from_queue  *
***************************/

VALUE rb_RPDB_LockController_removeLockFromQueue(	VALUE	rb_lock_controller,
													VALUE	rb_queued_lock )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_Lock*				c_queued_lock;
	C_RPDB_LOCK( rb_queued_lock, c_queued_lock );
	
	RPDB_LockController_removeLockFromQueue(	c_lock_controller,
												c_queued_lock	);

	return rb_lock_controller;
}

/************************
*  obtain_queued_locks  *
************************/

VALUE rb_RPDB_LockController_obtainQueuedLocks(	VALUE	rb_lock_controller	)	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_obtainQueuedLocks( c_lock_controller );

	return rb_lock_controller;
}

/*************************
*  release_queued_locks  *
*************************/

VALUE rb_RPDB_LockController_releaseQueuedLocks(	VALUE	rb_lock_controller	)	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_releaseQueuedLocks( c_lock_controller );

	return rb_lock_controller;
}

/*****************
*  obtain_locks  *
*****************/

VALUE rb_RPDB_LockController_obtainLocks(	VALUE	rb_lock_controller,
																					VALUE	rb_locks_to_obtain	)	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
	//	FIX - ruby array into C array of locks
	
	RPDB_Lock**	c_locks_to_obtain	=	NULL;

	RPDB_LockController_obtainLocks(	c_lock_controller,
										c_locks_to_obtain,
										RARRAY_LEN( rb_locks_to_obtain ) );
	
	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/**************************************
*  obtain_locks_and_override_timeout  *
**************************************/

VALUE rb_RPDB_LockController_obtainLocksAndOverrideTimeout(	VALUE	rb_lock_controller,
																														VALUE	rb_locks_to_obtain,
																														VALUE	rb_timeout __attribute__ ((unused))	)	{

	//	FIX - array

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_Lock**	c_locks_to_obtain	=	NULL;
	uint32_t	c_timeout			=	0;

	RPDB_LockController_obtainLocksAndOverrideTimeout(	c_lock_controller,
														c_locks_to_obtain,
														RARRAY_LEN( rb_locks_to_obtain ),
														c_timeout );

	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/******************
*  release_locks  *
******************/

VALUE rb_RPDB_LockController_releaseLocks(	VALUE	rb_lock_controller,
											VALUE	rb_locks_to_release	)	{

	//	FIX - array

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_Lock**	c_locks_to_release	=	NULL;

	RPDB_LockController_releaseLocks(	c_lock_controller,
										c_locks_to_release,
										RARRAY_LEN( rb_locks_to_release ) );

	VALUE	rb_obtained_locks	=	Qnil;
	
	return rb_obtained_locks;
}

/**********************
*  release_all_locks  *
**********************/

VALUE rb_RPDB_LockController_releaseAllLocks(	VALUE	rb_lock_controller	)	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_releaseAllLocks( c_lock_controller );

	return rb_lock_controller;
}

/********************************
*  release_all_locks_on_object  *
********************************/

VALUE rb_RPDB_LockController_releaseAllLocksOnObject(	VALUE	rb_lock_controller,
														VALUE	rb_record	)	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_Record*			c_record;
	C_RPDB_RECORD( rb_record, c_record );

	RPDB_LockController_releaseAllLocksOnObject(	c_lock_controller,
													c_record	);

	return rb_lock_controller;
}

/************************
*  clear_default_locks  *
************************/

//	If no default has been set, will randomly select for what types of locks to do deadlock detection
VALUE rb_RPDB_LockController_clearDefaultLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_clearDefaultLocks( c_lock_controller );

	return rb_lock_controller;
}

/************************
*  clear_expired_locks  *
************************/

VALUE rb_RPDB_LockController_clearExpiredLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPDB_LockController_clearExpiredLocks( c_lock_controller );

	return rb_lock_controller;
}

/**************************************************
*  clear_lock_request_for_locker_with_most_locks  *
**************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithMostLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_clearLockRequestForLockerWithMostLocks( c_lock_controller );

	return rb_lock_controller;
}

/********************************************************
*  clear_lock_request_for_locker_with_most_write_locks  *
********************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithMostWriteLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_clearLockRequestForLockerWithMostWriteLocks( c_lock_controller );

	return rb_lock_controller;
}

/***************************************************
*  clear_lock_request_for_locker_with_least_locks  *
***************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithLeastLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_clearLockRequestForLockerWithLeastLocks( c_lock_controller );

	return rb_lock_controller;
}

/*********************************************************
*  clear_lock_request_for_locker_with_least_write_locks  *
*********************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithLeastWriteLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_clearLockRequestForLockerWithLeastWriteLocks( c_lock_controller );

	return rb_lock_controller;
}

/***************************************************
*  clear_lock_request_for_locker_with_oldest_lock  *
***************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithOldestLock( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPDB_LockController_clearLockRequestForLockerWithOldestLock( c_lock_controller );

	return rb_lock_controller;
}

/*****************************************************
*  clear_lock_request_for_locker_with_youngest_lock  *
*****************************************************/

VALUE rb_RPDB_LockController_clearLockRequestForLockerWithYoungestLock( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPDB_LockController_clearLockRequestForLockerWithYoungestLock( c_lock_controller );
	
	return rb_lock_controller;
}

/*****************************************
*  clear_lock_request_for_random_locker  *
*****************************************/

VALUE rb_RPDB_LockController_clearLockRequestForRandomLocker( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );
							
	RPDB_LockController_clearLockRequestForRandomLocker( c_lock_controller );
	
	return rb_lock_controller;
}

/*********************
*  close_all_locks  *
*********************/

VALUE rb_RPDB_LockController_closeAllLocks( VALUE	rb_lock_controller )	{

	RPDB_LockController*	c_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller );

	RPDB_LockController_closeAllLocks( c_lock_controller );

	return rb_lock_controller;
}
