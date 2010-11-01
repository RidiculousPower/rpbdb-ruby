#ifndef RB_RPDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_ReplicationVerbositySettingsController();

VALUE rb_RPDB_ReplicationVerbositySettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPDB_ReplicationVerbositySettingsController_init(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_parentEnvironment(	VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayAllReplicationInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayElectionInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayElectionInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayElectionInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayReplicationMasterLeaseInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayMiscProcessingInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayMessageProcessingInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayClientSynchronizationInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayManagerConnectionFailureInformation( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOff( VALUE	rb_replication_verbosity_settings_controller );
	VALUE rb_RPDB_ReplicationVerbositySettingsController_displayManagerMiscProcessing( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOn( VALUE	rb_replication_verbosity_settings_controller );
		VALUE rb_RPDB_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOff( VALUE	rb_replication_verbosity_settings_controller );

#endif
