#ifndef RB_RBDB_REPLICATION_SETTINGS_CONTROLLER
	#define RB_RBDB_REPLICATION_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_ReplicationSettingsController();

VALUE rb_Rbdb_ReplicationSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_Rbdb_ReplicationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self );
VALUE rb_Rbdb_ReplicationSettingsController_parentEnvironment(	VALUE	rb_replication_settings_controller );
VALUE rb_Rbdb_ReplicationSettingsController_parentSettingsController(	VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_on( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_turnOn( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_off( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_turnOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_clientToClientSynchronization( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_singleBulkTransfer( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_delayNewSyncUntilExplicitCall( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_useMasterLeases( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_reinitializeOutdatedClients( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_prohibitWait( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_requireStrictMajority( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOn( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOff( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_isMaster( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setIsMaster( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_isClient( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setIsClient( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_startAsClientOrRallyElection( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setStartAsClientOrRallyElection( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_limit( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setLimit(	VALUE	rb_replication_settings_controller, 
																VALUE	rb_limit_in_gbytes, 
																VALUE	rb_limit_in_bytes );
	VALUE rb_Rbdb_ReplicationSettingsController_host( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setHost(	int			argc,
																												VALUE*	args,
																												VALUE		rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_port( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setPort(	VALUE		rb_replication_settings_controller,
																												VALUE		rb_port );
	VALUE rb_Rbdb_ReplicationSettingsController_siteCount( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setSiteCount(	VALUE	rb_replication_settings_controller, 
																	VALUE	rb_site_count );
	VALUE rb_Rbdb_ReplicationSettingsController_priorityOrderNumber( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setPriorityOrderNumber(	VALUE	rb_replication_settings_controller,
																				VALUE	rb_priority_order_number);
	VALUE rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMinimum( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMinimum(	VALUE	rb_replication_settings_controller, 
																						VALUE	rb_retransmission_threshold_minimum );
	VALUE rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMaximum( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMaximum(	VALUE	rb_replication_settings_controller,
		 																				VALUE	rb_retransmission_threshold_maximum );
	VALUE rb_Rbdb_ReplicationSettingsController_slowestClockValue( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setSlowestClockValue(	VALUE	rb_replication_settings_controller, 
																			VALUE	rb_slowest_clock_value );
	VALUE rb_Rbdb_ReplicationSettingsController_fastestClockSkewValue( VALUE	rb_replication_settings_controller );
		VALUE rb_Rbdb_ReplicationSettingsController_setFastestClockSkewValue(	VALUE	rb_replication_settings_controller, 
																				VALUE	rb_fastest_clock_value );
	VALUE rb_Rbdb_ReplicationSettingsController_electionSettingsController( VALUE	rb_replication_settings_controller );
	VALUE rb_Rbdb_ReplicationSettingsController_timeoutSettingsController( VALUE	rb_replication_settings_controller );

#endif
