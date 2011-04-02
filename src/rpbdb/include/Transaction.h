#ifndef RB_RPBDB_TRANSACTION
	#define RB_RPBDB_TRANSACTION

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_Transaction();
VALUE rb_RPbdb_Transaction_new(	int			argc,
																VALUE*	args,
																VALUE		rb_klass_self );
VALUE rb_RPbdb_Transaction_initialize(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self );
	VALUE rb_RPbdb_Transaction_settingsController(	VALUE	rb_transaction );
VALUE rb_RPbdb_Transaction_parentEnvironment(	VALUE	rb_transaction );
VALUE rb_RPbdb_Transaction_parentTransactionController(	VALUE	rb_transaction );
	VALUE rb_RPbdb_Transaction_name( VALUE	rb_transaction );
	VALUE rb_RPbdb_Transaction_setName(	VALUE	rb_transaction,
	 												VALUE	rb_transaction_name );
VALUE rb_RPbdb_Transaction_begin( VALUE	rb_transaction );
VALUE rb_RPbdb_Transaction_commit( VALUE	rb_transaction );
	VALUE rb_RPbdb_Transaction_prepare(	VALUE	rb_transaction,
													//	global_transaction_id is a DB_XIDDATASIZE (currently 128) length array of 8 bit ints
													//	The array is used to identify distributed transactions, which may be relayed 
													//	through multiple centralizing environment nodes to distributed environments.
	 												VALUE	rb_global_transaction_id	);
	VALUE rb_RPbdb_Transaction_rollback( VALUE	rb_transaction );
	VALUE rb_RPbdb_Transaction_discardRecoveredResources( VALUE	rb_transaction );

#endif