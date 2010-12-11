#ifndef RB_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER
	#define RB_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_ReplicationElectionSettingsController();

VALUE	rb_Rbdb_ReplicationElectionSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE	rb_Rbdb_ReplicationElectionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment(	VALUE	rb_replication_election_settings_controller );
VALUE rb_Rbdb_ReplicationElectionSettingsController_parentSettingsController(	VALUE	rb_replication_election_settings_controller );
VALUE rb_Rbdb_ReplicationElectionSettingsController_parentReplicationSettingsController(	VALUE	rb_replication_election_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	VALUE	replication_elections_settings_controller,
		 																							VALUE	rb_number_of_sites_required_for_election	);
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	VALUE	replication_elections_settings_controller,
		 																							VALUE	rb_number_of_votes_required_for_election	);
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAllClients( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOff( VALUE replication_elections_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAllElectablePeers( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( VALUE replication_elections_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_neverWait( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOff( VALUE replication_elections_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneClient( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( VALUE replication_elections_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( VALUE replication_elections_settings_controller );
	VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( VALUE replication_elections_settings_controller );
		VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( VALUE replication_elections_settings_controller );

#endif
