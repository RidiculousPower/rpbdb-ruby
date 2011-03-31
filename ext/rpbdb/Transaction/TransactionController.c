/*
 *		RPbdb::TransactionController
 *
 *
 */

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>
#include <rpbdb/Transaction.h>

#include "TransactionController.h"
#include <rpbdb/TransactionController.h>
#include <rpbdb/TransactionSettingsController.h>

#include <rargs.h>

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;

extern	VALUE	rb_RPbdb_Transaction;
extern	VALUE	rb_RPbdb_TransactionController;
extern	VALUE	rb_RPbdb_TransactionSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_RPbdb_TransactionController()	{
	
	rb_RPbdb_TransactionController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																													"TransactionController",	
																													rb_cObject );
	
	rb_define_singleton_method(	rb_RPbdb_TransactionController, 	"new",																																rb_RPbdb_TransactionController_new,																											-1 	);
	rb_define_method(						rb_RPbdb_TransactionController,	"initialize",																													rb_RPbdb_TransactionController_initialize,																											-1 	);
	                                                                                                          												                                                                                        
	rb_define_method(						rb_RPbdb_TransactionController, 	"settings_controller",																								rb_RPbdb_TransactionController_settingsController,																				0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"settings",																														"settings_controller"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"set",																																"settings_controller"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"set_to",																															"settings_controller"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"is_set_to",																													"settings_controller"	);                                                                
	rb_define_method(						rb_RPbdb_TransactionController, 	"parent_environment",																									rb_RPbdb_TransactionController_parentEnvironment,																				0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"environment",																												"parent_environment"	);                                                                
	                  					                                                                              												                                                                                        
	rb_define_method(						rb_RPbdb_TransactionController, 	"begin_transaction",																									rb_RPbdb_TransactionController_beginTransaction,																					0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"begin",																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"open"	,																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"start_transaction",																									"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"start",																															"begin_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"start_transaction",																									"begin_transaction"	);                                                                  
	rb_define_method(						rb_RPbdb_TransactionController, 	"begin_concurrent_data_store_group",																	rb_RPbdb_TransactionController_beginConcurrentDataStoreGroup,														0 	);
	rb_define_method(						rb_RPbdb_TransactionController, 	"commit_transaction",																									rb_RPbdb_TransactionController_commitTransaction,																				0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"commit",																															"commit_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"close",																															"commit_transaction"	);                                                                  
	rb_define_alias(						rb_RPbdb_TransactionController, 	"close_transaction",																									"commit_transaction"	);                                                                  
	rb_define_method(						rb_RPbdb_TransactionController, 	"rollback_transaction",																								rb_RPbdb_TransactionController_rollbackTransaction,																			0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"rollback",																														"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"abort_transaction",																									"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"abort",																															"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"cancel_transaction",																									"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"cancel",																															"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"discard_transaction",																								"rollback_transaction"	);                                                                
	rb_define_alias(						rb_RPbdb_TransactionController, 	"discard",																														"rollback_transaction"	);                                                                
	rb_define_method(						rb_RPbdb_TransactionController, 	"commit_checkpoint",																									rb_RPbdb_TransactionController_commitCheckpoint,																					0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"checkpoint",																													"commit_checkpoint"	);                                                                  
	rb_define_method(						rb_RPbdb_TransactionController, 	"commit_checkpoint_if_sufficient_written_data",												rb_RPbdb_TransactionController_commitCheckpointIfSufficientWrittenData,									0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"checkpoint_if_sufficient_written_data",															"commit_checkpoint_if_sufficient_written_data"	);                                            
	rb_define_method(						rb_RPbdb_TransactionController, 	"commit_checkpoint_if_sufficient_time_elapsed",												rb_RPbdb_TransactionController_commitCheckpointIfSufficientTimeElapsed,									0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"checkpoint_if_sufficient_time_elapsed",															"commit_checkpoint_if_sufficient_time_elapsed"	);                                            
	rb_define_method(						rb_RPbdb_TransactionController, 	"commit_checkpoint_if_sufficient_written_data_or_time_elapsed",				rb_RPbdb_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed,			0 	);
	rb_define_alias(						rb_RPbdb_TransactionController, 	"checkpoint_if_sufficient_written_data_or_time_elapsed",							"commit_checkpoint_if_sufficient_written_data_or_time_elapsed"	);
}

/*************
*  self.new  *
*************/
	
VALUE rb_RPbdb_TransactionController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);

	RPbdb_Environment*	c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	VALUE	rb_transaction_controller	=	RUBY_RPBDB_TRANSACTION_CONTROLLER( RPbdb_TransactionController_new( c_parent_environment ) );

	rb_iv_set(	rb_transaction_controller,
							RPBDB_RB_TRANSACTION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_transaction_controller,
									 1, 
									 argv );
	
	return rb_transaction_controller;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_TransactionController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_TransactionController_settingsController(	VALUE	rb_transaction_controller )	{

	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( RPbdb_TransactionController_settingsController( c_transaction_controller ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPbdb_TransactionController_parentEnvironment(	VALUE	rb_transaction_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_transaction_controller,
																						RPBDB_RB_TRANSACTION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT);
	
	return rb_parent_environment;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************************
*  beginTransaction  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_id.html
VALUE rb_RPbdb_TransactionController_beginTransaction( VALUE	rb_transaction_controller )	{

	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPBDB_TRANSACTION( RPbdb_TransactionController_beginTransaction( c_transaction_controller ) );
}

/********************************
*  beginConcurrentDataStore  *
********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_cdsgroup_begin.html
VALUE rb_RPbdb_TransactionController_beginConcurrentDataStoreGroup( VALUE	rb_transaction_controller )	{

	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	RPbdb_TransactionController_beginConcurrentDataStoreGroup( c_transaction_controller );

	return rb_transaction_controller;
}

/*************************
*  currentTransaction  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_checkpoint.html
VALUE rb_RPbdb_TransactionController_currentTransaction( VALUE	rb_transaction_controller )	{

	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

	return RUBY_RPBDB_TRANSACTION( RPbdb_TransactionController_currentTransaction( c_transaction_controller ) );
}

/*************************
*  abortTransaction  *
*************************/

VALUE rb_RPbdb_TransactionController_rollbackTransaction( VALUE	rb_transaction_controller )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_rollbackTransaction( c_transaction_controller );
	return rb_transaction_controller;
}

/*************************
*  commitTransaction  *
*************************/

VALUE rb_RPbdb_TransactionController_commitTransaction( VALUE	rb_transaction_controller )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_commitTransaction( c_transaction_controller );
	return rb_transaction_controller;
}

/*****************************
*  recoverTransactions  *
*****************************/

//	The DB_ENV->txn_recover method should only be called after the environment has been recovered.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_recover.html
VALUE rb_RPbdb_TransactionController_recoverTransactions( VALUE	rb_transaction_controller )	{

	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );

								//	FIX - return array of transactions

	RPbdb_TransactionController_recoverTransactions( c_transaction_controller );
	
	return rb_transaction_controller;
}

/*************************
*  commitCheckpoint  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_checkpoint.html
VALUE rb_RPbdb_TransactionController_commitCheckpoint( VALUE	rb_transaction_controller )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_commitCheckpoint( c_transaction_controller );
	
	return rb_transaction_controller;
}

/*************************************************
*  commitCheckpointIfSufficientWrittenData  *
*************************************************/

VALUE rb_RPbdb_TransactionController_commitCheckpointIfSufficientWrittenData(	VALUE	rb_transaction_controller,
																				VALUE	rb_minimum_written_data_for_checkpoint_in_k )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_commitCheckpointIfSufficientWrittenData(	c_transaction_controller,
																			NUM2INT( rb_minimum_written_data_for_checkpoint_in_k ) );
	
	return rb_transaction_controller;
}

/*************************************************
*  commitCheckpointIfSufficientTimeElapsed  *
*************************************************/

VALUE rb_RPbdb_TransactionController_commitCheckpointIfSufficientTimeElapsed(	VALUE	rb_transaction_controller,
																				VALUE	rb_minimum_time_for_checkpoint_in_minutes )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_commitCheckpointIfSufficientTimeElapsed(	c_transaction_controller,
																			FIX2INT( rb_minimum_time_for_checkpoint_in_minutes ) );
	
	return rb_transaction_controller;
}

/*************************************************************
*  commitCheckpointIfSufficientWrittenDataOrTimeElapsed  *
*************************************************************/

VALUE rb_RPbdb_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	VALUE	rb_transaction_controller,
																							VALUE	rb_minimum_written_data_for_checkpoint_in_k,
																							VALUE	rb_minimum_time_for_checkpoint_in_minutes )	{
	
	RPbdb_TransactionController*	c_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller );
	
	RPbdb_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	c_transaction_controller,
																						NUM2INT( rb_minimum_written_data_for_checkpoint_in_k ),
																						FIX2INT( rb_minimum_time_for_checkpoint_in_minutes ) );
	
	return rb_transaction_controller;
}
