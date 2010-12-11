#ifndef RB_RBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER
	#define RB_RBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_LockDeadlockDetectorSettingsController();

VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_settings_controller );
VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_settings_controller );
VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_isDefault( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToDefault( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectExpired( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithMostWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithFewestWriteLocks( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithOldestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectLockerWithYoungestLock( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_rejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_setToRejectRandom( VALUE	rb_lock_deadlock_detector_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorSettingsController_verbositySettingsController( VALUE	rb_lock_deadlock_detector_settings_controller );

#endif
