#ifndef RB_RPDB_REPLICATION_SETTINGS_CONTROLLER
	#define RB_RPDB_REPLICATION_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_ReplicationSettingsController();

VALUE rb_RPDB_ReplicationSettingsController_new(	VALUE	klass,
												 VALUE	rb_parent_settings_controller );
VALUE rb_RPDB_ReplicationSettingsController_init(	VALUE	rb_replication_settings_controller,
	VALUE	rb_parent_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_parentEnvironment(	VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_on( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_turnOn( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_off( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_turnOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_clientToClientSynchronization( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_singleBulkTransfer( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_delayNewSyncUntilExplicitCall( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_useMasterLeases( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_reinitializeOutdatedClients( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_prohibitWait( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnProhibitWaitOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnProhibitWaitOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_requireStrictMajority( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOn( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOff( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_isMaster( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setIsMaster( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_isClient( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setIsClient( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_startAsClientOrRallyElection( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setStartAsClientOrRallyElection( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_limit( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setLimit(	VALUE	rb_replication_settings_controller, 
																VALUE	rb_limit_in_gbytes, 
																VALUE	rb_limit_in_bytes );
	VALUE rb_RPDB_ReplicationSettingsController_host( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setHost(	VALUE	rb_replication_settings_controller, 
																VALUE 	rb_host );
	VALUE rb_RPDB_ReplicationSettingsController_port( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setPort(	VALUE	rb_replication_settings_controller,
																VALUE	rb_host, 
																VALUE	rb_port );
	VALUE rb_RPDB_ReplicationSettingsController_siteCount( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setSiteCount(	VALUE	rb_replication_settings_controller, 
																	VALUE	rb_site_count );
	VALUE rb_RPDB_ReplicationSettingsController_priorityOrderNumber( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setPriorityOrderNumber(	VALUE	rb_replication_settings_controller,
																				VALUE	rb_priority_order_number);
	VALUE rb_RPDB_ReplicationSettingsController_retransmissionThresholdMinimum( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMinimum(	VALUE	rb_replication_settings_controller, 
																						VALUE	rb_retransmission_threshold_minimum );
	VALUE rb_RPDB_ReplicationSettingsController_retransmissionThresholdMaximum( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMaximum(	VALUE	rb_replication_settings_controller,
		 																				VALUE	rb_retransmission_threshold_maximum );
	VALUE rb_RPDB_ReplicationSettingsController_slowestClockValue( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setSlowestClockValue(	VALUE	rb_replication_settings_controller, 
																			VALUE	rb_slowest_clock_value );
	VALUE rb_RPDB_ReplicationSettingsController_fastestClockSkewValue( VALUE	rb_replication_settings_controller );
		VALUE rb_RPDB_ReplicationSettingsController_setFastestClockSkewValue(	VALUE	rb_replication_settings_controller, 
																				VALUE	rb_fastest_clock_value );
	VALUE rb_RPDB_ReplicationSettingsController_electionSettingsController( VALUE	rb_replication_settings_controller );
	VALUE rb_RPDB_ReplicationSettingsController_timeoutSettingsController( VALUE	rb_replication_settings_controller );

#endif
