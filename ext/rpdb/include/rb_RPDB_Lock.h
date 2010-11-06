#ifndef RB_RPDB_LOCK
	#define RB_RPDB_LOCK

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_RPDB_Lock_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_RPDB_Lock_settingsController(	VALUE	rb_lock );
	VALUE rb_RPDB_Lock_parentEnvironment(	VALUE	rb_lock );
	VALUE rb_RPDB_Lock_lock(	VALUE	rb_lock, 
								VALUE	record );
	VALUE rb_RPDB_Lock_unlock( VALUE	rb_lock );
	VALUE rb_RPDB_Lock_isReadLock( VALUE	rb_lock );
		VALUE rb_RPDB_Lock_setToReadLock( VALUE	rb_lock );
	VALUE rb_RPDB_Lock_isWriteLock( VALUE	rb_lock );
		VALUE rb_RPDB_Lock_setToWriteLock( VALUE	rb_lock );
	VALUE rb_RPDB_Lock_isIntentToWriteLock( VALUE	rb_lock );
		VALUE rb_RPDB_Lock_setToIntentToWriteLock( VALUE	rb_lock );
	VALUE rb_RPDB_Lock_isIntentToReadLock( VALUE	rb_lock );
		VALUE rb_RPDB_Lock_setToIntentToReadLock( VALUE	rb_lock );
	VALUE rb_RPDB_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock );
		VALUE rb_RPDB_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock );

#endif
