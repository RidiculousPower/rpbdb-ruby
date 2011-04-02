#ifndef RB_RPBDB_LOCK_SETTINGS_CONTROLLER
	#define RB_RPBDB_LOCK_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_LockSettingsController();

VALUE rb_RPbdb_LockSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPbdb_LockSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self );
VALUE rb_RPbdb_LockSettingsController_parentEnvironment(	VALUE	rb_lock_settings_controller );
VALUE rb_RPbdb_LockSettingsController_parentSettingsController(	VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_on( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_off( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_prohibitLocking( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnProhibitLockingOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnProhibitLockingOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_timeoutReturnsDenyNotDeadlock( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnTimeoutReturnsDenyNotDeadlockOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_noWaitingForConflicts( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnNoWaitingForConflictsOn( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_turnNoWaitingForConflictsOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_lockForEnvironmentNotDatabase( VALUE	rb_lock_settings_controller );
			VALUE rb_RPbdb_LockSettingsController_turnLockForEnvironmentNotDatabaseOn( VALUE	rb_lock_settings_controller );
			VALUE rb_RPbdb_LockSettingsController_turnLockForEnvironmentNotDatabaseOff( VALUE	rb_lock_settings_controller );
	VALUE rb_RPbdb_LockSettingsController_timeout( VALUE	rb_lock_settings_controller );
VALUE rb_RPbdb_LockSettingsController_setTimeout(	VALUE	rb_lock_settings_controller,
												 VALUE	timeout	);
	VALUE rb_RPbdb_LockSettingsController_conflictMatrix( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_setConflictMatrix( 	VALUE	rb_lock_settings_controller,
																	VALUE	rb_conflict_matrix );
	VALUE rb_RPbdb_LockSettingsController_maxLockers( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_setMaxLockers(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_lockers );
	VALUE rb_RPbdb_LockSettingsController_maxLocks( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_setMaxLocks(	VALUE	rb_lock_settings_controller, 
															VALUE	rb_max_locks );
	VALUE rb_RPbdb_LockSettingsController_maxObjects( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_setMaxObjects(	VALUE	rb_lock_settings_controller, 
																VALUE	rb_max_objects );
	VALUE rb_RPbdb_LockSettingsController_numberOfPartitions( VALUE	rb_lock_settings_controller );
		VALUE rb_RPbdb_LockSettingsController_setNumberOfPartitions(	VALUE	rb_lock_settings_controller, 
																		VALUE	rb_partitions );
	VALUE rb_RPbdb_LockSettingsController_deadlockDetectorSettingsController( VALUE	rb_lock_settings_controller );

#endif
