#ifndef RB_RPDB_LOCK_SETTINGS_CONTROLLER
	#define RB_RPDB_LOCK_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_LockSettingsController();

VALUE rb_RPDB_LockSettingsController_new(	VALUE	klass,
										  VALUE	rb_parent_settings_controller );
VALUE rb_RPDB_LockSettingsController_init(	VALUE	rb_lock_settings_controller,
	VALUE	rb_parent_settings_controller );
	VALUE rb_RPDB_LockSettingsController_parentEnvironment(	VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_on( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_off( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_prohibitLocking( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnProhibitLockingOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnProhibitLockingOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_timeoutReturnsReturnDenyNotDeadlock( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnTimeoutReturnsReturnDenyNotDeadlockOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnTimeoutReturnsReturnDenyNotDeadlockOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_noWaitingForConflicts( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_turnNoWaitingForConflictsOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_lockForEnvironmentNotDatabase( VALUE	rb_lock_settings_controller );
			VALUE rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOn( VALUE	rb_lock_settings_controller );
			VALUE rb_RPDB_LockSettingsController_turnLockForEnvironmentNotDatabaseOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPDB_LockSettingsController_timeout( VALUE	rb_lock_settings_controller );
VALUE rb_RPDB_LockSettingsController_setTimeout(	VALUE	rb_lock_settings_controller,
												 VALUE	timeout	);
	VALUE rb_RPDB_LockSettingsController_conflictMatrix( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_setConflictMatrix( 	VALUE	rb_lock_settings_controller,
																	VALUE	rb_conflict_matrix );
	VALUE rb_RPDB_LockSettingsController_maxLockers( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_setMaxLockers(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_lockers );
	VALUE rb_RPDB_LockSettingsController_maxLocks( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_setMaxLocks(	VALUE	rb_lock_settings_controller, 
															VALUE	rb_max_locks );
	VALUE rb_RPDB_LockSettingsController_maxObjects( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_setMaxObjects(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_objects );
	VALUE rb_RPDB_LockSettingsController_numberOfPartitions( VALUE	rb_lock_settings_controller );
		VALUE rb_RPDB_LockSettingsController_setNumberOfPartitions(	VALUE	rb_lock_settings_controller, 
																		VALUE	rb_partitions );
	VALUE rb_RPDB_LockSettingsController_deadlockDetectorSettingsController( VALUE	rb_lock_settings_controller );

#endif
