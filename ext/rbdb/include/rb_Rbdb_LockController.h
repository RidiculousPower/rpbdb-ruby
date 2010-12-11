#ifndef RB_RBDB_LOCK_CONTROLLER
	#define RB_RBDB_LOCK_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_LockController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_Rbdb_LockController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE rb_Rbdb_LockController_settingsController(	VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_parentEnvironment(	VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_lockerID( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_createLock( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_queueLock(	VALUE	rb_lock_controller,
												VALUE	rb_lock_for_queue );
	VALUE rb_Rbdb_LockController_removeLockFromQueue(	VALUE	rb_lock_controller,
														VALUE	rb_queued_lock );
	VALUE rb_Rbdb_LockController_obtainQueuedLocks(	VALUE	rb_lock_controller	);
	VALUE rb_Rbdb_LockController_releaseQueuedLocks(	VALUE	rb_lock_controller	);
	VALUE rb_Rbdb_LockController_releaseAllLocks(	VALUE	rb_lock_controller	);
	VALUE rb_Rbdb_LockController_releaseAllLocksOnObject(	VALUE	rb_lock_controller,
															VALUE	rb_record	);
	VALUE rb_Rbdb_LockController_clearDefaultLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearExpiredLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithMostLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithMostWriteLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithLeastLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithLeastWriteLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithOldestLock( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForLockerWithYoungestLock( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_clearLockRequestForRandomLocker( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_closeAllLocks( VALUE	rb_lock_controller );
	VALUE rb_Rbdb_LockController_obtainLocks(	VALUE	rb_lock_controller,
												VALUE	rb_locks_to_obtain	);
	VALUE rb_Rbdb_LockController_obtainLocksAndOverrideTimeout(	VALUE	rb_lock_controller,
																	VALUE	rb_locks_to_obtain,
																	VALUE	rb_timeout	);
	VALUE rb_Rbdb_LockController_releaseLocks(	VALUE	rb_lock_controller,
												VALUE	rb_locks_to_release	);

#endif
