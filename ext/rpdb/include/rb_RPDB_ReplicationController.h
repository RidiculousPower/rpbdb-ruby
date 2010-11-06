#ifndef RB_RPDB_REPLICATION_CONTROLLER
	#define RB_RPDB_REPLICATION_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

VALUE rb_RPDB_ReplicationController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPDB_ReplicationController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self );
	VALUE rb_RPDB_ReplicationController_settingsController(	VALUE	rb_replication_controller );
	VALUE rb_RPDB_ReplicationController_parentEnvironment(	VALUE	rb_replication_controller );
	VALUE rb_RPDB_ReplicationController_initReplicationID(	VALUE	rb_replication_controller );
	VALUE rb_RPDB_ReplicationController_start(	VALUE	rb_replication_controller,
	 											VALUE	rb_number_of_threads_for_message_processing	);
	VALUE rb_RPDB_ReplicationController_processMessage(	VALUE	rb_replication_controller,
	 														VALUE	rb_control_record,
															VALUE	rb_replication_record	);
	VALUE rb_RPDB_ReplicationController_sync( VALUE	rb_replication_controller );
	VALUE rb_RPDB_ReplicationController_callElection( VALUE	rb_replication_controller );
	VALUE rb_RPDB_ReplicationController_addRemoteSite(	VALUE	rb_replication_controller,
	 													VALUE	remote_host,
														VALUE	remote_port	);
VALUE rb_RPDB_ReplicationController_siteList( VALUE	rb_replication_controller );

#endif
