#ifndef RB_RPDB_REMOTE_SITE
	#define RB_RPDB_REMOTE_SITE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_RemoteSite_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
VALUE rb_RPDB_RemoteSite_init(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self );
	VALUE rb_RPDB_RemoteSite_settingsController(	VALUE	rb_remote_site );
VALUE rb_RPDB_RemoteSite_parentEnvironment(	VALUE	rb_remote_site );
VALUE rb_RPDB_RemoteSite_parentReplicationController(	VALUE	rb_remote_site );

#endif
