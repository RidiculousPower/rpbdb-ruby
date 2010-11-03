/*
 *		RPDB::TransactionController
 *
 *
 */

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_Transaction.h>

#include "rb_RPDB_TransactionController.h"
#include <rpdb/RPDB_TransactionController.h>
#include <rpdb/RPDB_TransactionSettingsController.h>

#include <rargs.h>

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;

extern	VALUE	rb_RPDB_Transaction;
extern	VALUE	rb_RPDB_TransactionController;
extern	VALUE	rb_RPDB_TransactionSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_TransactionController()	{
	
	rb_RPDB_TransactionController	=	rb_define_class_under(	rb_RPDB_Environment, 
																													"TransactionController",	
																													rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_TransactionController, 	"new",																																rb_RPDB_TransactionController_new,																											-1 	);
	rb_define_method(						rb_RPDB_TransactionController,	"initialize",																													rb_RPDB_TransactionController_init,																											-1 	);
	                                                                                                          												                                                                                        
	rb_define_method(						rb_RPDB_TransactionController, 	"settings_controller",																								rb_RPDB_TransactionController_settingsController,																				0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"settings",																														"settings_controller"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"set",																																"settings_controller"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"set_to",																															"settings_controller"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"is_set_to",																													"settings_controller"	);                                                                
	rb_define_method(						rb_RPDB_TransactionController, 	"parent_environment",																									rb_RPDB_TransactionController_parentEnvironment,																				0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"environment",																												"parent_environment"	);                                                                
	                  					                                                                              												                                                                                        
	rb_define_method(						rb_RPDB_TransactionController, 	"begin_transaction",																									rb_RPDB_TransactionController_beginTransaction,																					0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"begin",																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"open"	,																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"start_transaction",																									"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"start",																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"start_transaction",																									"begin_transaction"	);                                                                  
	rb_define_method(						rb_RPDB_TransactionController, 	"begin_concurrent_data_store_group",																	rb_RPDB_TransactionController_beginConcurrentDataStoreGroup,														0 	);
	rb_define_method(						rb_RPDB_TransactionController, 	"commit_transaction",																									rb_RPDB_TransactionController_commitTransaction,																				0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"commit",																															"commit_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"close",																															"commit_transaction"	);                                                                  
	rb_define_alias(						rb_RPDB_TransactionController, 	"close_transaction",																									"commit_transaction"	);                                                                  
	rb_define_method(						rb_RPDB_TransactionController, 	"rollback_transaction",																								rb_RPDB_TransactionController_rollbackTransaction,																			0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"rollback",																														"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"abort_transaction",																									"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"abort",																															"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"cancel_transaction",																									"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"cancel",																															"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"discard_transaction",																								"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPDB_TransactionController, 	"discard",																														"rollback_transaction"	);                                                                
	rb_define_method(						rb_RPDB_TransactionController, 	"commit_checkpoint",																									rb_RPDB_TransactionController_commitCheckpoint,																					0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"checkpoint",																													"commit_checkpoint"	);                                                                  
	rb_define_method(						rb_RPDB_TransactionController, 	"commit_checkpoint_if_sufficient_written_data",												rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenData,									0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"checkpoint_if_sufficient_written_data",															"commit_checkpoint_if_sufficient_written_data"	);                                            
	rb_define_method(						rb_RPDB_TransactionController, 	"commit_checkpoint_if_sufficient_time_elapsed",												rb_RPDB_TransactionController_commitCheckpointIfSufficientTimeElapsed,									0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"checkpoint_if_sufficient_time_elapsed",															"commit_checkpoint_if_sufficient_time_elapsed"	);                                            
	rb_define_method(						rb_RPDB_TransactionController, 	"commit_checkpoint_if_sufficient_written_data_or_time_elapsed",				rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed,			0 	);
	rb_define_alias(						rb_RPDB_TransactionController, 	"checkpoint_if_sufficient_written_data_or_time_elapsed",							"commit_checkpoint_if_sufficient_written_data_or_time_elapsed"	);
}

/*************
*  new  *
*************/
	
VALUE rb_RPDB_TransactionController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);

	RPDB_Environment*	c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	VALUE	rb_transaction_controller	=	RUBY_RPDB_TRANSACTION_CONTROLLER( RPDB_TransactionController_new( c_parent_environment ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_environment;
	
	rb_obj_call_init(	rb_transaction_controller,
					 1, 
					 argv );
	
	return rb_transaction_controller;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_TransactionController_init(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_TransactionController_settingsController(	VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPDB_TRANSACTION_SETTINGS_CONTROLLER( RPDB_TransactionController_settingsController( c_transaction_controller ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_TransactionController_parentEnvironment(	VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_TransactionController_parentEnvironment( c_transaction_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************************
*  beginTransaction  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_id.html
VALUE rb_RPDB_TransactionController_beginTransaction( VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPDB_TRANSACTION( RPDB_TransactionController_beginTransaction( c_transaction_controller ) );
}

/********************************
*  beginConcurrentDataStore  *
********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_cdsgroup_begin.html
VALUE rb_RPDB_TransactionController_beginConcurrentDataStoreGroup( VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	RPDB_TransactionController_beginConcurrentDataStoreGroup( c_transaction_controller );

	return rb_transaction_controller;
}

/*************************
*  currentTransaction  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_checkpoint.html
VALUE rb_RPDB_TransactionController_currentTransaction( VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPDB_TRANSACTION( RPDB_TransactionController_currentTransaction( c_transaction_controller ) );
}

/*************************
*  abortTransaction  *
*************************/

VALUE rb_RPDB_TransactionController_rollbackTransaction( VALUE	rb_transaction_controller )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_rollbackTransaction( c_transaction_controller );
	return rb_transaction_controller;
}

/*************************
*  commitTransaction  *
*************************/

VALUE rb_RPDB_TransactionController_commitTransaction( VALUE	rb_transaction_controller )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_commitTransaction( c_transaction_controller );
	return rb_transaction_controller;
}

/*****************************
*  recoverTransactions  *
*****************************/

//	The DB_ENV->txn_recover method should only be called after the environment has been recovered.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_recover.html
VALUE rb_RPDB_TransactionController_recoverTransactions( VALUE	rb_transaction_controller )	{

	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

								//	FIX - return array of transactions

	RPDB_TransactionController_recoverTransactions( c_transaction_controller );
	
	return rb_transaction_controller;
}

/*************************
*  commitCheckpoint  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_checkpoint.html
VALUE rb_RPDB_TransactionController_commitCheckpoint( VALUE	rb_transaction_controller )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_commitCheckpoint( c_transaction_controller );
	
	return rb_transaction_controller;
}

/*************************************************
*  commitCheckpointIfSufficientWrittenData  *
*************************************************/

VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenData(	VALUE	rb_transaction_controller,
																				VALUE	rb_minimum_written_data_for_checkpoint_in_k )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_commitCheckpointIfSufficientWrittenData(	c_transaction_controller,
																			NUM2INT( rb_minimum_written_data_for_checkpoint_in_k ) );
	
	return rb_transaction_controller;
}

/*************************************************
*  commitCheckpointIfSufficientTimeElapsed  *
*************************************************/

VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientTimeElapsed(	VALUE	rb_transaction_controller,
																				VALUE	rb_minimum_time_for_checkpoint_in_minutes )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_commitCheckpointIfSufficientTimeElapsed(	c_transaction_controller,
																			FIX2INT( rb_minimum_time_for_checkpoint_in_minutes ) );
	
	return rb_transaction_controller;
}

/*************************************************************
*  commitCheckpointIfSufficientWrittenDataOrTimeElapsed  *
*************************************************************/

VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	VALUE	rb_transaction_controller,
																							VALUE	rb_minimum_written_data_for_checkpoint_in_k,
																							VALUE	rb_minimum_time_for_checkpoint_in_minutes )	{
	
	RPDB_TransactionController*	c_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPDB_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	c_transaction_controller,
																						NUM2INT( rb_minimum_written_data_for_checkpoint_in_k ),
																						FIX2INT( rb_minimum_time_for_checkpoint_in_minutes ) );
	
	return rb_transaction_controller;
}
