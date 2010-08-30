/*
 *		RPDB::TransactionController::Transaction
 *
 *
 */

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Transaction.h>
#include "rb_RPDB_Transaction.h"
#include <rpdb/RPDB_TransactionSettingsController.h>
#include "rb_RPDB_Environment.h"

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_TransactionController;
extern	VALUE	rb_RPDB_Transaction;
extern	VALUE	rb_RPDB_TransactionSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Transaction()	{
	
	
	rb_RPDB_Transaction	=	rb_define_class_under(	rb_RPDB_TransactionController, 
																								"Transaction",	
																								rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_Transaction, 	"new",										rb_RPDB_Transaction_new,										1 	);
	rb_define_method(						rb_RPDB_Transaction,	"initialize",							rb_RPDB_Transaction_init,										1 	);
	                  					
	rb_define_method(						rb_RPDB_Transaction, 	"settings_controller",			rb_RPDB_Transaction_settingsController,			0 	);
	rb_define_alias(						rb_RPDB_Transaction, 	"settings_controller",		"settings_controller"	);
	rb_define_alias(						rb_RPDB_Transaction, 	"settings",								"settings_controller"	);
	rb_define_alias(						rb_RPDB_Transaction, 	"set",										"settings_controller"	);
	rb_define_alias(						rb_RPDB_Transaction, 	"set_to",									"settings_controller"	);
	rb_define_alias(						rb_RPDB_Transaction, 	"is_set_to",							"settings_controller"	);
	rb_define_method(						rb_RPDB_Transaction, 	"parent_environment",			rb_RPDB_Transaction_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_Transaction, 	"parent_environment",			"parent_environment"	);
	rb_define_alias(						rb_RPDB_Transaction, 	"environment",						"parent_environment"	);
	                  					
	rb_define_method(						rb_RPDB_Transaction, 	"begin",									rb_RPDB_Transaction_begin,									0 	);
	rb_define_alias(						rb_RPDB_Transaction, 	"start",									"begin"	);
	rb_define_method(						rb_RPDB_Transaction, 	"commit",									rb_RPDB_Transaction_commit,									0 	);
	rb_define_alias(						rb_RPDB_Transaction, 	"end",										"commit"	);
	rb_define_method(						rb_RPDB_Transaction, 	"rollback",								rb_RPDB_Transaction_rollback,								0 	);
	rb_define_alias(						rb_RPDB_Transaction, 	"abort",									"rollback"	);
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Transaction_new(	VALUE	klass __attribute__ ((unused )),
																VALUE	rb_parent_transaction_controller )	{
	
	RPDB_TransactionController*	c_parent_transaction_controller;
	C_RPDB_TRANSACTION_CONTROLLER( rb_parent_transaction_controller, c_parent_transaction_controller );
	
	VALUE	rb_transaction	=	RUBY_RPDB_TRANSACTION( RPDB_Transaction_new( c_parent_transaction_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_transaction_controller;
	
	rb_obj_call_init(	rb_transaction,
					 1, 
					 argv );
	
	return rb_transaction;	
}

/*************
*  init  *
*************/

VALUE rb_RPDB_Transaction_init(	VALUE	rb_transaction,
																VALUE	rb_parent_transaction_controller __attribute__ ((unused )) )	{

	return rb_transaction;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Transaction_settingsController(	VALUE	rb_transaction )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	return RUBY_RPDB_TRANSACTION_SETTINGS_CONTROLLER( RPDB_Transaction_settingsController( c_transaction ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_Transaction_parentEnvironment(	VALUE	rb_transaction )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Transaction_parentEnvironment( c_transaction ) );

}

/*******************************************************************************************************************************************************************************************
																		Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  transactionName  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_set_name.html
VALUE rb_RPDB_Transaction_name( VALUE	rb_transaction )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	return rb_str_new2( RPDB_Transaction_name( c_transaction ) );
}

/*************************
*  setTransactionName  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_set_name.html
VALUE rb_RPDB_Transaction_setName(	VALUE	rb_transaction,
 												VALUE	rb_transaction_name )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	RPDB_Transaction_setName(	c_transaction,
											StringValuePtr( rb_transaction_name ) );
	
	return rb_transaction;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************************
*  begin  *
*************************/

VALUE rb_RPDB_Transaction_begin( VALUE	rb_transaction )	{
	
	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPDB_Transaction_begin( c_transaction );
	
	return rb_transaction;
}

/*************************
*  commit  *
*************************/

VALUE rb_RPDB_Transaction_commit( VALUE	rb_transaction )	{
	
	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPDB_Transaction_commit( c_transaction );
	
	return rb_transaction;
}

/*************************
*  prepareTransaction  *
*************************/
/*
//	Child transactions should never be explicitly prepared. Their fate will be resolved aVALUE with their parent's during global recovery.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_prepare.html
VALUE rb_RPDB_Transaction_prepare(	VALUE	rb_transaction,
												//	global_transaction_id is a DB_XIDDATASIZE (currently 128) length array of 8 bit ints
												//	The array is used to identify distributed transactions, which may be relayed 
												//	through multiple centralizing environment nodes to distributed environments.
 												VALUE	rb_global_transaction_id	)	{
	
	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPDB_Transaction_prepare(	c_transaction,
								FIX2INT( rb_global_transaction_id ) );

	return rb_transaction;
}
*/
/*****************************
*  rollbackTransaction  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_abort.html
VALUE rb_RPDB_Transaction_rollback( VALUE	rb_transaction )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	RPDB_Transaction_rollback( c_transaction );

	return rb_transaction;
}

/*************************************
*  discardRecoveredResources  *
*************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_discard.html
VALUE rb_RPDB_Transaction_discardRecoveredResources( VALUE	rb_transaction )	{

	RPDB_Transaction*	c_transaction;
	C_RPDB_TRANSACTION( rb_transaction, c_transaction );

	RPDB_Transaction_discardRecoveredResources( c_transaction );
	
	return rb_transaction;
}

