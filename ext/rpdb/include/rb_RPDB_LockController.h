#ifndef RB_RPDB_LOCK_CONTROLLER
	#define RB_RPDB_LOCK_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_LockController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self );
VALUE rb_RPDB_LockController_init(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self );
	VALUE rb_RPDB_LockController_settingsController(	VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_parentEnvironment(	VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_lockerID( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_createLock( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_queueLock(	VALUE	rb_lock_controller,
												VALUE	rb_lock_for_queue );
	VALUE rb_RPDB_LockController_removeLockFromQueue(	VALUE	rb_lock_controller,
														VALUE	rb_queued_lock );
	VALUE rb_RPDB_LockController_obtainQueuedLocks(	VALUE	rb_lock_controller	);
	VALUE rb_RPDB_LockController_releaseQueuedLocks(	VALUE	rb_lock_controller	);
	VALUE rb_RPDB_LockController_releaseAllLocks(	VALUE	rb_lock_controller	);
	VALUE rb_RPDB_LockController_releaseAllLocksOnObject(	VALUE	rb_lock_controller,
															VALUE	rb_record	);
	VALUE rb_RPDB_LockController_clearDefaultLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearExpiredLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithMostLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithMostWriteLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithLeastLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithLeastWriteLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithOldestLock( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForLockerWithYoungestLock( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_clearLockRequestForRandomLocker( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_closeAllLocks( VALUE	rb_lock_controller );
	VALUE rb_RPDB_LockController_obtainLocks(	VALUE	rb_lock_controller,
												VALUE	rb_locks_to_obtain	);
	VALUE rb_RPDB_LockController_obtainLocksAndOverrideTimeout(	VALUE	rb_lock_controller,
																	VALUE	rb_locks_to_obtain,
																	VALUE	rb_timeout	);
	VALUE rb_RPDB_LockController_releaseLocks(	VALUE	rb_lock_controller,
												VALUE	rb_locks_to_release	);

#endif
