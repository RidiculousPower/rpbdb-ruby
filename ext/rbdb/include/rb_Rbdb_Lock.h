#ifndef RB_Rbdb_LOCK
	#define RB_Rbdb_LOCK

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_Rbdb_Lock_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_Rbdb_Lock_settingsController(	VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_parentEnvironment(	VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_lock(	VALUE	rb_lock, 
								VALUE	record );
	VALUE rb_Rbdb_Lock_unlock( VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_isReadLock( VALUE	rb_lock );
		VALUE rb_Rbdb_Lock_setToReadLock( VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_isWriteLock( VALUE	rb_lock );
		VALUE rb_Rbdb_Lock_setToWriteLock( VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_isIntentToWriteLock( VALUE	rb_lock );
		VALUE rb_Rbdb_Lock_setToIntentToWriteLock( VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_isIntentToReadLock( VALUE	rb_lock );
		VALUE rb_Rbdb_Lock_setToIntentToReadLock( VALUE	rb_lock );
	VALUE rb_Rbdb_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock );
		VALUE rb_Rbdb_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock );

#endif
