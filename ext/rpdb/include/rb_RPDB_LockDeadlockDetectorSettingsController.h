#ifndef RB_RPDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER
	#define RB_RPDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_LockDeadlockDetectorSettingsController();

VALUE rb_RPDB_LockDeadlockDetectorSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPDB_LockDeadlockDetectorSettingsController_init(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_isDefault( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToDefault( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_rejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorSettingsController_setToRejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorSettingsController_verbositySettingsController( VALUE	rb_lock_deadlock_detector_settings_controller );

#endif
