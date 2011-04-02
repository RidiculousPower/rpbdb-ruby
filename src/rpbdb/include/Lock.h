#ifndef RB_RPBDB_LOCK
	#define RB_RPBDB_LOCK

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPbdb_Lock_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPbdb_Lock_settingsController(	VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_parentEnvironment(	VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_lock(	VALUE	rb_lock, 
								VALUE	record );
	VALUE rb_RPbdb_Lock_unlock( VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_isReadLock( VALUE	rb_lock );
		VALUE rb_RPbdb_Lock_setToReadLock( VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_isWriteLock( VALUE	rb_lock );
		VALUE rb_RPbdb_Lock_setToWriteLock( VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_isIntentToWriteLock( VALUE	rb_lock );
		VALUE rb_RPbdb_Lock_setToIntentToWriteLock( VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_isIntentToReadLock( VALUE	rb_lock );
		VALUE rb_RPbdb_Lock_setToIntentToReadLock( VALUE	rb_lock );
	VALUE rb_RPbdb_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock );
		VALUE rb_RPbdb_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock );

#endif
