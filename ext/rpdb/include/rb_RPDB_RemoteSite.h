#ifndef RB_RPDB_REMOTE_SITE
	#define RB_RPDB_REMOTE_SITE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_RemoteSite_new(	VALUE	klass,
							  VALUE	rb_parent_replication_controller );
VALUE rb_RPDB_RemoteSite_init(	VALUE	rb_remote_site,
	VALUE	rb_parent_replication_controller );
	VALUE rb_RPDB_RemoteSite_settingsController(	VALUE	rb_remote_site );
	VALUE rb_RPDB_RemoteSite_parentEnvironment(	VALUE	rb_remote_site );

#endif
