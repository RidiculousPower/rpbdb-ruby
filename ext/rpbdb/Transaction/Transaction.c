/*
 *		RPbdb::TransactionController::Transaction
 *
 *
 */

#include "Transaction.h"
#include "TransactionController.h"
#include "Environment.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Transaction.h>
#include <rpbdb/TransactionSettingsController.h>

#include <rargs.h>

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_TransactionController;
extern	VALUE	rb_RPbdb_Transaction;
extern	VALUE	rb_RPbdb_TransactionSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_RPbdb_Transaction()	{
	
	
	rb_RPbdb_Transaction	=	rb_define_class_under(	rb_RPbdb_TransactionController, 
																								"Transaction",	
																								rb_cObject );
	
	rb_define_singleton_method(	rb_RPbdb_Transaction, 	"new",										rb_RPbdb_Transaction_new,										-1 	);
	rb_define_method(						rb_RPbdb_Transaction,	"initialize",							rb_RPbdb_Transaction_initialize,										-1 	);
	                  					
	rb_define_method(						rb_RPbdb_Transaction, 	"settings_controller",			rb_RPbdb_Transaction_settingsController,			0 	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"settings_controller",		"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"settings",								"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"set",										"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"set_to",									"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"is_set_to",							"settings_controller"	);
	rb_define_method(						rb_RPbdb_Transaction, 	"parent_environment",			rb_RPbdb_Transaction_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"parent_environment",			"parent_environment"	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"environment",						"parent_environment"	);
	                  					
	rb_define_method(						rb_RPbdb_Transaction, 	"begin",									rb_RPbdb_Transaction_begin,									0 	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"start",									"begin"	);
	rb_define_method(						rb_RPbdb_Transaction, 	"commit",									rb_RPbdb_Transaction_commit,									0 	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"end",										"commit"	);
	rb_define_method(						rb_RPbdb_Transaction, 	"rollback",								rb_RPbdb_Transaction_rollback,								0 	);
	rb_define_alias(						rb_RPbdb_Transaction, 	"abort",									"rollback"	);
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Transaction_new(	int			argc,
																VALUE*	args,
																VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_transaction_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_transaction_controller, rb_RPbdb_TransactionController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent transaction controller> ]"
		)
	);

	RPbdb_TransactionController*	c_parent_transaction_controller;
	C_RPBDB_TRANSACTION_CONTROLLER( rb_parent_transaction_controller, c_parent_transaction_controller );
	
	VALUE	rb_transaction	=	RUBY_RPBDB_TRANSACTION( RPbdb_Transaction_new( c_parent_transaction_controller ) );
	
	rb_iv_set(	rb_transaction,
							RPBDB_RB_TRANSACTION_VARIABLE_PARENT_TRANSACTION_CONTROLLER,
							rb_parent_transaction_controller );
	
	VALUE	argv[]	=	{ rb_parent_transaction_controller };
	rb_obj_call_init(	rb_transaction,
					 1, 
					 argv );
	
	return rb_transaction;	
}

/*************
*  initialize  *
*************/

VALUE rb_RPbdb_Transaction_initialize(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_Transaction_settingsController(	VALUE	rb_transaction )	{

	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );

	return RUBY_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( RPbdb_Transaction_settingsController( c_transaction ) );

}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_Transaction_parentEnvironment(	VALUE	rb_transaction )	{

	VALUE	rb_parent_transaction_controller	=	rb_RPbdb_Transaction_parentTransactionController( rb_transaction );
	VALUE	rb_parent_environment							=	rb_RPbdb_TransactionController_parentEnvironment( rb_parent_transaction_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_transaction_controller  *
***************************************/
VALUE rb_RPbdb_Transaction_parentTransactionController(	VALUE	rb_transaction )	{

	VALUE	rb_parent_transaction_controller	=	rb_iv_get(	rb_transaction,
																												RPBDB_RB_TRANSACTION_VARIABLE_PARENT_TRANSACTION_CONTROLLER );
	
	return rb_parent_transaction_controller;
}

/*******************************************************************************************************************************************************************************************
																		Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  transactionName  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_set_name.html
VALUE rb_RPbdb_Transaction_name( VALUE	rb_transaction )	{

	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );

	return rb_str_new2( RPbdb_Transaction_name( c_transaction ) );
}

/*************************
*  setTransactionName  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_set_name.html
VALUE rb_RPbdb_Transaction_setName(	VALUE	rb_transaction,
 												VALUE	rb_transaction_name )	{

	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );

	RPbdb_Transaction_setName(	c_transaction,
											StringValuePtr( rb_transaction_name ) );
	
	return rb_transaction;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************************
*  begin  *
*************************/

VALUE rb_RPbdb_Transaction_begin( VALUE	rb_transaction )	{
	
	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPbdb_Transaction_begin( c_transaction );
	
	return rb_transaction;
}

/*************************
*  commit  *
*************************/

VALUE rb_RPbdb_Transaction_commit( VALUE	rb_transaction )	{
	
	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPbdb_Transaction_commit( c_transaction );
	
	return rb_transaction;
}

/*************************
*  prepareTransaction  *
*************************/
/*
//	Child transactions should never be explicitly prepared. Their fate will be resolved aVALUE with their parent's during global recovery.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_prepare.html
VALUE rb_RPbdb_Transaction_prepare(	VALUE	rb_transaction,
												//	global_transaction_id is a DB_XIDDATASIZE (currently 128) length array of 8 bit ints
												//	The array is used to identify distributed transactions, which may be relayed 
												//	through multiple centralizing environment nodes to distributed environments.
 												VALUE	rb_global_transaction_id	)	{
	
	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );
	
	RPbdb_Transaction_prepare(	c_transaction,
								FIX2INT( rb_global_transaction_id ) );

	return rb_transaction;
}
*/
/*****************************
*  rollbackTransaction  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_abort.html
VALUE rb_RPbdb_Transaction_rollback( VALUE	rb_transaction )	{

	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );

	RPbdb_Transaction_rollback( c_transaction );

	return rb_transaction;
}

/*************************************
*  discardRecoveredResources  *
*************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/txn_discard.html
VALUE rb_RPbdb_Transaction_discardRecoveredResources( VALUE	rb_transaction )	{

	RPbdb_Transaction*	c_transaction;
	C_RPBDB_TRANSACTION( rb_transaction, c_transaction );

	RPbdb_Transaction_discardRecoveredResources( c_transaction );
	
	return rb_transaction;
}

