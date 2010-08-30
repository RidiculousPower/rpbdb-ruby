#ifndef RB_RPDB_TRANSACTION
	#define RB_RPDB_TRANSACTION

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Transaction();
VALUE rb_RPDB_Transaction_new(	VALUE	klass,
							   VALUE	rb_parent_transaction_controller );
VALUE rb_RPDB_Transaction_init(	VALUE	rb_transaction,
	VALUE	rb_parent_transaction_controller );
	VALUE rb_RPDB_Transaction_settingsController(	VALUE	rb_transaction );
	VALUE rb_RPDB_Transaction_parentEnvironment(	VALUE	rb_transaction );
	VALUE rb_RPDB_Transaction_name( VALUE	rb_transaction );
	VALUE rb_RPDB_Transaction_setName(	VALUE	rb_transaction,
	 												VALUE	rb_transaction_name );
VALUE rb_RPDB_Transaction_begin( VALUE	rb_transaction );
VALUE rb_RPDB_Transaction_commit( VALUE	rb_transaction );
	VALUE rb_RPDB_Transaction_prepare(	VALUE	rb_transaction,
													//	global_transaction_id is a DB_XIDDATASIZE (currently 128) length array of 8 bit ints
													//	The array is used to identify distributed transactions, which may be relayed 
													//	through multiple centralizing environment nodes to distributed environments.
	 												VALUE	rb_global_transaction_id	);
	VALUE rb_RPDB_Transaction_rollback( VALUE	rb_transaction );
	VALUE rb_RPDB_Transaction_discardRecoveredResources( VALUE	rb_transaction );

#endif