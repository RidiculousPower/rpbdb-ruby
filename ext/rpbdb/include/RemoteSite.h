#ifndef RB_RPBDB_REMOTE_SITE
	#define RB_RPBDB_REMOTE_SITE

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

VALUE rb_RPbdb_RemoteSite_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
VALUE rb_RPbdb_RemoteSite_initialize(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self );
	VALUE rb_RPbdb_RemoteSite_settingsController(	VALUE	rb_remote_site );
VALUE rb_RPbdb_RemoteSite_parentEnvironment(	VALUE	rb_remote_site );
VALUE rb_RPbdb_RemoteSite_parentReplicationController(	VALUE	rb_remote_site );

#endif
