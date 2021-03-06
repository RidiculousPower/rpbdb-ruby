/*
 *		RPbdb::RPbdb_SettingsController::RPbdb_ConcurrentDataStoreSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "SettingsController.h"
#include "TransactionSettingsController.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Transaction.h>

#include <rpbdb/TransactionSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_TransactionSettingsController;
extern	VALUE	rb_RPbdb_Transaction;

void Init_rb_RPbdb_TransactionSettingsController()	{

	rb_RPbdb_TransactionSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																																		"Transaction",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_TransactionSettingsController, 	"new",																rb_RPbdb_TransactionSettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"initialize",													rb_RPbdb_TransactionSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"parent_environment",									rb_RPbdb_TransactionSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_TransactionSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController,				"parent_settings_controller",					rb_RPbdb_TransactionSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"on?",														rb_RPbdb_TransactionSettingsController_on,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"off?",														rb_RPbdb_TransactionSettingsController_off,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_on",														rb_RPbdb_TransactionSettingsController_turnOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_off",														rb_RPbdb_TransactionSettingsController_turnOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"prohibit_sync_on_write?",														rb_RPbdb_TransactionSettingsController_prohibitSyncOnWrite,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_prohibit_sync_on_write_on",														rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_prohibit_sync_on_write_off",														rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"prohibit_sync_on_commit_transaction?",														rb_RPbdb_TransactionSettingsController_prohibitSyncOnCommit,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_prohibit_sync_on_commit_transaction_on",														rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_prohibit_sync_on_commit_transaction_off",														rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"timeout_in_microseconds_returns_deny_not_deadlock?",														rb_RPbdb_TransactionSettingsController_timeoutInMicrosecondsReturnsDenyNotDeadlock,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_timeout_in_microseconds_returns_deny_not_deadlock_on",														rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_timeout_in_microseconds_returns_deny_not_deadlock_off",														rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"concurrent_data_store_locking?",														rb_RPbdb_TransactionSettingsController_concurrentDataStoreLocking,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_concurrent_data_store_locking_on",														rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_concurrent_data_store_locking_off",														rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"snapshot_isolation?",														rb_RPbdb_TransactionSettingsController_snapshotIsolation,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_snapshot_isolation_on",														rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_snapshot_isolation_off",														rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"degree_one_isolation?",														rb_RPbdb_TransactionSettingsController_degreeOneIsolation,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_degree_one_isolation_on",														rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_degree_one_isolation_off",														rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"degree_two_isolation?",														rb_RPbdb_TransactionSettingsController_degreeTwoIsolation,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_degree_two_isolation_on",														rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_degree_two_isolation_off",														rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"enclose_all_activity_in_transaction?",														rb_RPbdb_TransactionSettingsController_encloseAllActivityInTransaction,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_enclose_all_activity_in_transaction_on",														rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_enclose_all_activity_in_transaction_off",														rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"environmental_snapshot_isolation?",														rb_RPbdb_TransactionSettingsController_environmentalSnapshotIsolation,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_environmental_snapshot_isolation_on",														rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_environmental_snapshot_isolation_off",														rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"sync_on_commit?",														rb_RPbdb_TransactionSettingsController_syncOnCommit,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_sync_on_commit_on",														rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_sync_on_commit_off",														rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"wait_for_locks?",														rb_RPbdb_TransactionSettingsController_waitForLocks,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_wait_for_locks_on",														rb_RPbdb_TransactionSettingsController_turnWaitForLocksOn,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"turn_wait_for_locks_off",														rb_RPbdb_TransactionSettingsController_turnWaitForLocksOff,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"maximum_number_of_transactions_to_recover",														rb_RPbdb_TransactionSettingsController_maximumNumberOfTransactionsToRecover,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"set_maximum_number_of_transactions_to_recover",														rb_RPbdb_TransactionSettingsController_setMaximumNumberOfTransactionsToRecover,													1 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"timeout_in_microseconds",														rb_RPbdb_TransactionSettingsController_timeoutInMicroseconds,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"set_timeout_in_microseconds",														rb_RPbdb_TransactionSettingsController_setTimeoutInMicroseconds,													1 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"max_open",														rb_RPbdb_TransactionSettingsController_maxOpen,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"set_max_open",														rb_RPbdb_TransactionSettingsController_setMaxOpen,													1 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"recovery_timestamp",														rb_RPbdb_TransactionSettingsController_recoveryTimestamp,													0 	);
	rb_define_method(			rb_RPbdb_TransactionSettingsController, 				"set_recovery_timestamp",														rb_RPbdb_TransactionSettingsController_setRecoveryTimestamp,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_TransactionSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}

	RPbdb_SettingsController*	c_parent_settings_controller;
	C_RPBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );
	
	VALUE	rb_transaction_settings_controller	= RUBY_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( RPbdb_TransactionSettingsController_new( c_parent_settings_controller ) );

	rb_iv_set(	rb_transaction_settings_controller,
							RPBDB_RB_TRANSACTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_transaction_settings_controller,
										 1, 
										 argv );
	
	return rb_transaction_settings_controller;		
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_TransactionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_TransactionSettingsController_parentEnvironment(	VALUE	rb_transaction_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_TransactionSettingsController_parentSettingsController( rb_transaction_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_TransactionSettingsController_parentSettingsController(	VALUE	rb_transaction_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_transaction_settings_controller,
																										RPBDB_RB_TRANSACTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/********
*  on?  *
********/

//	DB_INIT_TXN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Returns DB_INIT_TXN or FALSE
VALUE rb_RPbdb_TransactionSettingsController_on( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_on( c_transaction_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/*********
*  off?  *
*********/

//	DB_INIT_TXN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Doesn't seem like off should return the flag, so TRUE/FALSE
VALUE rb_RPbdb_TransactionSettingsController_off( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_off( c_transaction_settings_controller )	?	Qtrue
																							:	Qfalse );
}

	/************
	*  turn_on  *
	************/

	//	DB_INIT_TXN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPbdb_TransactionSettingsController_turnOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/*************
	*  turn_off  *
	*************/

	//	DB_INIT_TXN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	//	Returns DB_INIT_TXN or FALSE
	VALUE rb_RPbdb_TransactionSettingsController_turnOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/****************************
*  prohibit_sync_on_write?  *
****************************/

//	DB_TXN_WRITE_NOSYNC     http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_TransactionSettingsController_prohibitSyncOnWrite( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_prohibitSyncOnWrite( c_transaction_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/***********************************
	*  turn_prohibit_sync_on_write_on  *
	***********************************/

	//	DB_TXN_WRITE_NOSYNC     http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}
	
	/************************************
	*  turn_prohibit_sync_on_write_off  *
	************************************/

	//	DB_TXN_WRITE_NOSYNC     http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}
	
/*****************************************
*  prohibit_sync_on_commit_transaction?  *
*****************************************/

//	DB_TXN_NOSYNC           http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_TransactionSettingsController_prohibitSyncOnCommit( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_prohibitSyncOnCommit( c_transaction_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/************************************************
	*  turn_prohibit_sync_on_commit_transaction_on  *
	************************************************/

	//	DB_TXN_NOSYNC           http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/*************************************************
	*  turn_prohibit_sync_on_commit_transaction_off  *
	*************************************************/

	//	DB_TXN_NOSYNC           http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/*******************************************************
*  timeout_in_microseconds_returns_deny_not_deadlock?  *
*******************************************************/

//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_TransactionSettingsController_timeoutInMicrosecondsReturnsDenyNotDeadlock( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_timeoutInMicrosecondsReturnsDenyNotDeadlock( c_transaction_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/**************************************************************
	*  turn_timeout_in_microseconds_returns_deny_not_deadlock_on  *
	**************************************************************/

	//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/***************************************************************
	*  turn_timeout_in_microseconds_returns_deny_not_deadlock_off  *
	***************************************************************/

	//	DB_TIME_NOTGRANTED      http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/***********************************
*  concurrent_data_store_locking?  *
***********************************/

//	DB_INIT_CDB - 			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	only other flag allowed concurrently is DB_INIT_MPOOL; multiple reader single write mode
VALUE rb_RPbdb_TransactionSettingsController_concurrentDataStoreLocking( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_concurrentDataStoreLocking( c_transaction_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/******************************************
	*  turn_concurrent_data_store_locking_on  *
	******************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/*******************************************
	*  turn_concurrent_data_store_locking_off  *
	*******************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/************************
*  snapshot_isolation?  *
************************/

//	DB_TXN_SNAPSHOT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
//	DB_TXN_SNAPSHOT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPbdb_TransactionSettingsController_snapshotIsolation( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_snapshotIsolation( c_transaction_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/*******************************
	*  turn_snapshot_isolation_on  *
	*******************************/

	//	DB_TXN_SNAPSHOT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	//	DB_TXN_SNAPSHOT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
	VALUE rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnSnapshotIsolationOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/********************************
	*  turn_snapshot_isolation_off  *
	********************************/

	//	DB_TXN_SNAPSHOT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	//	DB_TXN_SNAPSHOT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
	VALUE rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnSnapshotIsolationOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/**************************
*  degree_one_isolation?  *
**************************/

//	DB_READ_UNCOMMITTED		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
//	This should also make sure that the ThreadSettingsController flag was on with the DB Open
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/transapp/read.html
VALUE rb_RPbdb_TransactionSettingsController_degreeOneIsolation( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_degreeOneIsolation( c_transaction_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*********************************
	*  turn_degree_one_isolation_on  *
	*********************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnDegreeOneIsolationOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/**********************************
	*  turn_degree_one_isolation_off  *
	**********************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnDegreeOneIsolationOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/**************************
*  degree_two_isolation?  *
**************************/

//	DB_READ_COMMITTED		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/transapp/read.html
VALUE rb_RPbdb_TransactionSettingsController_degreeTwoIsolation( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_degreeTwoIsolation( c_transaction_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*********************************
	*  turn_degree_two_isolation_on  *
	*********************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/**********************************
	*  turn_degree_two_isolation_off  *
	**********************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/*****************************************
*  enclose_all_activity_in_transaction?  *
*****************************************/

//	DB_AUTO_COMMIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_TransactionSettingsController_encloseAllActivityInTransaction( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_encloseAllActivityInTransaction( c_transaction_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/************************************************
	*  turn_enclose_all_activity_in_transaction_on  *
	************************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/*************************************************
	*  turn_enclose_all_activity_in_transaction_off  *
	*************************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/**************************************
*  environmental_snapshot_isolation?  *
**************************************/

//	DB_MULTIVERSION         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_TransactionSettingsController_environmentalSnapshotIsolation( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_environmentalSnapshotIsolation( c_transaction_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*********************************************
	*  turn_environmental_snapshot_isolation_on  *
	*********************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/**********************************************
	*  turn_environmental_snapshot_isolation_off  *
	**********************************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/*******************
*  sync_on_commit  *
*******************/

//	DB_TXN_SYNC         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_begin.html
VALUE rb_RPbdb_TransactionSettingsController_syncOnCommit( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_syncOnCommit( c_transaction_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/***************************
	*  turn_sync_on_commit_on  *
	***************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnSyncOnCommitOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/****************************
	*  turn_sync_on_commit_off  *
	****************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnSyncOnCommitOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/*******************
*  wait_for_locks  *
*******************/

//	DB_TXN_WAIT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_begin.html
VALUE rb_RPbdb_TransactionSettingsController_waitForLocks( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return ( RPbdb_TransactionSettingsController_waitForLocks( c_transaction_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/***************************
	*  turn_wait_for_locks_on  *
	***************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnWaitForLocksOn( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnWaitForLocksOn( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

	/****************************
	*  turn_wait_for_locks_off  *
	****************************/

	VALUE rb_RPbdb_TransactionSettingsController_turnWaitForLocksOff( VALUE	rb_transaction_settings_controller )	{

		RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
		C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

		RPbdb_TransactionSettingsController_turnWaitForLocksOff( c_transaction_settings_controller );

		return rb_transaction_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/**********************************************
*  maximum_number_of_transactions_to_recover  *
**********************************************/

VALUE rb_RPbdb_TransactionSettingsController_maximumNumberOfTransactionsToRecover( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return INT2FIX( RPbdb_TransactionSettingsController_maximumNumberOfTransactionsToRecover( c_transaction_settings_controller ) );
}

/**************************************************
*  set_maximum_number_of_transactions_to_recover  *
**************************************************/

VALUE rb_RPbdb_TransactionSettingsController_setMaximumNumberOfTransactionsToRecover(	VALUE	rb_transaction_settings_controller,
																																											VALUE	rb_maximum_number_of_transactions_to_recover )	{

	VALUE	rb_parent_environment	=	rb_RPbdb_TransactionSettingsController_parentEnvironment( rb_transaction_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Maximum number of transactions can only be specified before environment is opened." );	
	}
	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	RPbdb_TransactionSettingsController_setMaximumNumberOfTransactionsToRecover(	c_transaction_settings_controller,
																																							FIX2INT( rb_maximum_number_of_transactions_to_recover ) );

	return rb_transaction_settings_controller;
}

/************
*  timeout  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_timeout.html
VALUE rb_RPbdb_TransactionSettingsController_timeoutInMicroseconds( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	return INT2FIX( RPbdb_TransactionSettingsController_timeoutInMicroseconds( c_transaction_settings_controller ) );
}

/****************
*  set_timeout  *
****************/

//	DB_SET_TXN_TIMEOUT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_timeout.html
VALUE rb_RPbdb_TransactionSettingsController_setTimeoutInMicroseconds(	VALUE	rb_transaction_settings_controller, 
																		VALUE	rb_timeout_in_microseconds )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	RPbdb_TransactionSettingsController_setTimeoutInMicroseconds(	c_transaction_settings_controller,
	 																FIX2INT( rb_timeout_in_microseconds ) );

	return rb_transaction_settings_controller;
}

/*************
*  max_open  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tx_max.html
VALUE rb_RPbdb_TransactionSettingsController_maxOpen( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	int		c_max_open	=	RPbdb_TransactionSettingsController_maxOpen( c_transaction_settings_controller );

	VALUE	rb_max_open	=	INT2FIX( c_max_open );

	return rb_max_open;
}

/*****************
*  set_max_open  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tx_max.html
VALUE rb_RPbdb_TransactionSettingsController_setMaxOpen(	VALUE	rb_transaction_settings_controller, 
																												VALUE	rb_max_open )	{

	VALUE	rb_parent_environment	=	rb_RPbdb_TransactionSettingsController_parentEnvironment( rb_transaction_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Maximum number of open transactions can only be specified before environment is opened." );	
	}
	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	RPbdb_TransactionSettingsController_setMaxOpen(	c_transaction_settings_controller,
																									FIX2INT( rb_max_open ) );

	return rb_transaction_settings_controller;
}

/***********************
*  recovery_timestamp  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tx_timestamp.html
VALUE rb_RPbdb_TransactionSettingsController_recoveryTimestamp( VALUE	rb_transaction_settings_controller )	{

	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	time_t	c_recovery_timestamp	=	RPbdb_TransactionSettingsController_recoveryTimestamp( c_transaction_settings_controller );
	
	VALUE		rb_recovery_timestamp	=	INT2FIX( c_recovery_timestamp );

	return rb_recovery_timestamp;
}

/***************************
*  set_recovery_timestamp  *
***************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tx_timestamp.html
VALUE rb_RPbdb_TransactionSettingsController_setRecoveryTimestamp(	VALUE	rb_transaction_settings_controller, 
																																	VALUE	rb_recovery_timestamp )	{

	VALUE	rb_parent_environment	=	rb_RPbdb_TransactionSettingsController_parentEnvironment( rb_transaction_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Recovery timestamp can only be specified before environment is opened." );	
	}
	RPbdb_TransactionSettingsController*	c_transaction_settings_controller;
	C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller );

	time_t		c_recovery_timestamp	=	FIX2INT( rb_recovery_timestamp );

	RPbdb_TransactionSettingsController_setRecoveryTimestamp(	c_transaction_settings_controller,
																														c_recovery_timestamp );

	return rb_transaction_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/

/*************************************
*  set_rollbackward_callback_method  *
*************************************/
/*
VALUE rb_RPbdb_TransactionSettingsController_setRollbackwardCallbackMethod(	VALUE	rb_transaction_settings_controller,
																		VALUE(*rollbackward_callback_method)(	VALUE				environment->wrapped_bdb_environment,
																												VALUE		transaction_log_record ) )	{
	RPbdb_TransactionSettingsController_setRollbackwardCallbackMethod();
																													

}
*/
/*********************************
*  rollbackward_callback_method  *
*********************************/
/*
VALUE(*rollbackward_callback_method)(	VALUE				environment->wrapped_bdb_environment,
										VALUE		transaction_log_record ) RPbdb_TransactionSettingsController_rollbackwardCallbackMethod( VALUE	rb_transaction_settings_controller )	{


}
*/
/************************************
*  set_rollforward_callback_method  *
************************************/
/*
VALUE rb_RPbdb_TransactionSettingsController_setRollforwardCallbackMethod(	VALUE	rb_transaction_settings_controller,
																		VALUE(*rollforward_callback_method)(	VALUE				environment->wrapped_bdb_environment,
																											VALUE		transaction_log_record ) )	{
	RPbdb_TransactionSettingsController_setRollforwardCallbackMethod();
																													

}
*/
/********************************
*  rollforward_callback_method  *
********************************/
/*
VALUE(*rollforward_callback_method)(	VALUE				environment->wrapped_bdb_environment,
									VALUE		transaction_log_record ) RPbdb_TransactionSettingsController_rollforwardCallbackMethod( VALUE	rb_transaction_settings_controller )	{


}
*/
/******************************
*  set_abort_callback_method  *
******************************/
/*
VALUE rb_RPbdb_TransactionSettingsController_setAbortCallbackMethod(	VALUE	rb_transaction_settings_controller,
																	VALUE(*abort_callback_method)(	VALUE						environment->wrapped_bdb_environment,
																									VALUE				transaction_log_record ) )	{
	RPbdb_TransactionSettingsController_setAbortCallbackMethod();
																													

}
*/
/**************************
*  abort_callback_method  *
**************************/
/*
VALUE(*abort_callback_method)(	VALUE				environment->wrapped_bdb_environment,
								VALUE		transaction_log_record ) RPbdb_TransactionSettingsController_abortCallbackMethod( VALUE	rb_transaction_settings_controller )	{


}
*/
/******************************
*  set_apply_callback_method  *
******************************/
/*
VALUE rb_RPbdb_TransactionSettingsController_setApplyCallbackMethod(	VALUE	rb_transaction_settings_controller,
																	VALUE(*apply_callback_method)(	VALUE				environment->wrapped_bdb_environment,
																									VALUE		transaction_log_record ) )	{
	RPbdb_TransactionSettingsController_setApplyCallbackMethod();
																													

}
*/
/**************************
*  apply_callback_method  *
**************************/
/*
VALUE(*apply_callback_method)(	VALUE				environment->wrapped_bdb_environment,
								VALUE		transaction_log_record ) RPbdb_TransactionSettingsController_applyCallbackMethod( VALUE	rb_transaction_settings_controller )	{


}
*/
/******************************
*  set_print_callback_method  *
******************************/
/*
VALUE rb_RPbdb_TransactionSettingsController_setPrintCallbackMethod(	VALUE	rb_transaction_settings_controller,
																	VALUE(*print_callback_method)(	VALUE				environment->wrapped_bdb_environment,
																									VALUE		transaction_log_record ) )	{
	RPbdb_TransactionSettingsController_setPrintCallbackMethod();
					

}
*/
/**************************
*  print_callback_method  *
**************************/
/*
VALUE(*print_callback_method)(	VALUE				environment->wrapped_bdb_environment,
								VALUE		transaction_log_record ) RPbdb_TransactionSettingsController_printCallbackMethod( VALUE	rb_transaction_settings_controller )	{


}
*/