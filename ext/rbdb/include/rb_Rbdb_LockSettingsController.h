#ifndef RB_RBDB_LOCK_SETTINGS_CONTROLLER
	#define RB_RBDB_LOCK_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_LockSettingsController();

VALUE rb_Rbdb_LockSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_Rbdb_LockSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self );
VALUE rb_Rbdb_LockSettingsController_parentEnvironment(	VALUE	rb_lock_settings_controller );
VALUE rb_Rbdb_LockSettingsController_parentSettingsController(	VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_on( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_off( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnOn( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnOff( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_prohibitLocking( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnProhibitLockingOn( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnProhibitLockingOff( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_timeoutReturnsDenyNotDeadlock( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOn( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOff( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_noWaitingForConflicts( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnNoWaitingForConflictsOn( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_turnNoWaitingForConflictsOff( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_lockForEnvironmentNotDatabase( VALUE	rb_lock_settings_controller );
			VALUE rb_Rbdb_LockSettingsController_turnLockForEnvironmentNotDatabaseOn( VALUE	rb_lock_settings_controller );
			VALUE rb_Rbdb_LockSettingsController_turnLockForEnvironmentNotDatabaseOff( VALUE	rb_lock_settings_controller );
	VALUE rb_Rbdb_LockSettingsController_timeout( VALUE	rb_lock_settings_controller );
VALUE rb_Rbdb_LockSettingsController_setTimeout(	VALUE	rb_lock_settings_controller,
												 VALUE	timeout	);
	VALUE rb_Rbdb_LockSettingsController_conflictMatrix( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_setConflictMatrix( 	VALUE	rb_lock_settings_controller,
																	VALUE	rb_conflict_matrix );
	VALUE rb_Rbdb_LockSettingsController_maxLockers( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_setMaxLockers(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_lockers );
	VALUE rb_Rbdb_LockSettingsController_maxLocks( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_setMaxLocks(	VALUE	rb_lock_settings_controller, 
															VALUE	rb_max_locks );
	VALUE rb_Rbdb_LockSettingsController_maxObjects( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_setMaxObjects(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_objects );
	VALUE rb_Rbdb_LockSettingsController_numberOfPartitions( VALUE	rb_lock_settings_controller );
		VALUE rb_Rbdb_LockSettingsController_setNumberOfPartitions(	VALUE	rb_lock_settings_controller, 
																		VALUE	rb_partitions );
	VALUE rb_Rbdb_LockSettingsController_deadlockDetectorSettingsController( VALUE	rb_lock_settings_controller );

#endif
