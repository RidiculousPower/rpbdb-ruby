#ifndef RB_RPDB_TRANSACTION_CONTROLLER
	#define RB_RPDB_TRANSACTION_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_TransactionController();
VALUE rb_RPDB_TransactionController_new(	VALUE	klass,
										 VALUE	rb_parent_environment );
VALUE rb_RPDB_TransactionController_init(	VALUE	rb_transaction_controller,
	VALUE	rb_parent_environment );
	VALUE rb_RPDB_TransactionController_settingsController(	VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_parentEnvironment(	VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_beginTransaction( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_beginConcurrentDataStoreGroup( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_currentTransaction( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_rollbackTransaction( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_commitTransaction( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_commitCheckpoint( VALUE	rb_transaction_controller );
	VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenData(	VALUE	rb_transaction_controller,
																				 VALUE	rb_minimum_written_data_for_checkpoint_in_k );
	VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientTimeElapsed(	VALUE	rb_transaction_controller,
																				 VALUE	rb_minimum_time_for_checkpoint_in_minutes );
	VALUE rb_RPDB_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	VALUE	rb_transaction_controller,
																							  VALUE	rb_minimum_written_data_for_checkpoint_in_k,
																							  VALUE	rb_minimum_time_for_checkpoint_in_minutes );
	
#endif