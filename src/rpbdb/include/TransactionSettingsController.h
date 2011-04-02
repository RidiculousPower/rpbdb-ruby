#ifndef RB_RPBDB_TRANSACTION_SETTINGS_CONTROLLER
	#define RB_RPBDB_TRANSACTION_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_TransactionSettingsController();

VALUE rb_RPbdb_TransactionSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_RPbdb_TransactionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self );
VALUE rb_RPbdb_TransactionSettingsController_parentEnvironment(	VALUE	rb_transaction_settings_controller );
VALUE rb_RPbdb_TransactionSettingsController_parentSettingsController(	VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_on( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_off( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_prohibitSyncOnWrite( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnWriteTransactionOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_prohibitSyncOnCommit( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnProhibitSyncOnCommitOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_timeoutInMicrosecondsReturnsDenyNotDeadlock( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnTimeoutInMicrosecondsReturnsDenyNotDeadlockOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_concurrentDataStoreLocking( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnConcurrentDataStoreLockingOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_snapshotIsolation( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnSnapshotIsolationOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_degreeOneIsolation( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnDegreeOneIsolationOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_degreeTwoIsolation( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnDegreeTwoIsolationOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_encloseAllActivityInTransaction( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnEncloseAllActivityInTransactionOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_environmentalSnapshotIsolation( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnEnvironmentalSnapshotIsolationOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_syncOnCommit( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnSyncOnCommitOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_waitForLocks( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnWaitForLocksOn( VALUE	rb_transaction_settings_controller );
		VALUE rb_RPbdb_TransactionSettingsController_turnWaitForLocksOff( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_maximumNumberOfTransactionsToRecover( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_setMaximumNumberOfTransactionsToRecover(	VALUE	rb_transaction_settings_controller,
																							VALUE	rb_maximum_number_of_transactions_to_recover );
	VALUE rb_RPbdb_TransactionSettingsController_timeoutInMicroseconds( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_setTimeoutInMicroseconds(	VALUE	rb_transaction_settings_controller, 
																			VALUE	rb_timeout_in_microseconds );
	VALUE rb_RPbdb_TransactionSettingsController_maxOpen( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_setMaxOpen(	VALUE	rb_transaction_settings_controller, 
																VALUE	rb_max_open );
	VALUE rb_RPbdb_TransactionSettingsController_recoveryTimestamp( VALUE	rb_transaction_settings_controller );
	VALUE rb_RPbdb_TransactionSettingsController_setRecoveryTimestamp(	VALUE	rb_transaction_settings_controller, 
																		VALUE	rb_recovery_timestamp );

#endif