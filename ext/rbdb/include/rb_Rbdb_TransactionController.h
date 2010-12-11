#ifndef RB_RBDB_TRANSACTION_CONTROLLER
	#define RB_RBDB_TRANSACTION_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_TransactionController();
VALUE rb_Rbdb_TransactionController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_Rbdb_TransactionController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_Rbdb_TransactionController_settingsController(	VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_parentEnvironment(	VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_beginTransaction( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_beginConcurrentDataStoreGroup( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_currentTransaction( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_rollbackTransaction( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_commitTransaction( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_commitCheckpoint( VALUE	rb_transaction_controller );
	VALUE rb_Rbdb_TransactionController_commitCheckpointIfSufficientWrittenData(	VALUE	rb_transaction_controller,
																				 VALUE	rb_minimum_written_data_for_checkpoint_in_k );
	VALUE rb_Rbdb_TransactionController_commitCheckpointIfSufficientTimeElapsed(	VALUE	rb_transaction_controller,
																				 VALUE	rb_minimum_time_for_checkpoint_in_minutes );
	VALUE rb_Rbdb_TransactionController_commitCheckpointIfSufficientWrittenDataOrTimeElapsed(	VALUE	rb_transaction_controller,
																							  VALUE	rb_minimum_written_data_for_checkpoint_in_k,
																							  VALUE	rb_minimum_time_for_checkpoint_in_minutes );
	
#endif