#ifndef RB_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER
	#define RB_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_ReplicationTimeoutSettingsController();

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentEnvironment(	VALUE	rb_replication_timeout_settings_controller );
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentSettingsController(	VALUE	rb_replication_timeout_settings_controller );
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentReplicationSettingsController(	VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_timeout( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setTimeout(		VALUE	rb_replication_timeout_settings_controller, 
																		VALUE	rb_timeout );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	VALUE	rb_replication_timeout_settings_controller, 
																							VALUE	rb_wait_time_before_checkpoint_write );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	VALUE	rb_replication_timeout_settings_controller,
																							VALUE	rb_wait_time_before_retry_connection );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_electionTimeout( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setElectionTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																			VALUE	rb_election_timeout );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	VALUE	rb_replication_timeout_settings_controller, 
																						VALUE	rb_wait_time_before_retry_election );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																								VALUE	rb_full_election_participation_timeout );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	VALUE	rb_replication_timeout_settings_controller, 
																					VALUE	rb_heartbeat_monitor_pulse );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	VALUE	rb_replication_timeout_settings_controller, 
																					VALUE	rb_heartbeat_broadcast_pulse );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_leaseTimeout( VALUE	rb_replication_timeout_settings_controller );
	VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setLeaseTimeout(	VALUE	rb_replication_timeout_settings_controller,
																			VALUE	rb_lease_timeout );

#endif
