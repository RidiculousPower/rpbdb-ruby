#ifndef RB_Rbdb_REMOTE_SITE
	#define RB_Rbdb_REMOTE_SITE

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

VALUE rb_Rbdb_RemoteSite_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
VALUE rb_Rbdb_RemoteSite_initialize(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self );
	VALUE rb_Rbdb_RemoteSite_settingsController(	VALUE	rb_remote_site );
VALUE rb_Rbdb_RemoteSite_parentEnvironment(	VALUE	rb_remote_site );
VALUE rb_Rbdb_RemoteSite_parentReplicationController(	VALUE	rb_remote_site );

#endif
