#ifndef RB_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER
	#define RB_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_ReplicationElectionSettingsController();

VALUE	rb_RPDB_ReplicationElectionSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE	rb_RPDB_ReplicationElectionSettingsController_init(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
	VALUE rb_RPDB_ReplicationElectionSettingsController_parentEnvironment(	VALUE	rb_replication_election_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	VALUE	replication_elections_settings_controller,
		 																							VALUE	rb_number_of_sites_required_for_election	);
	VALUE	rb_RPDB_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	VALUE	replication_elections_settings_controller,
		 																							VALUE	rb_number_of_votes_required_for_election	);
	VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAllClients( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOff( VALUE replication_elections_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAllElectablePeers( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( VALUE replication_elections_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_neverWait( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOff( VALUE replication_elections_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneClient( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( VALUE replication_elections_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( VALUE replication_elections_settings_controller );
	VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( VALUE replication_elections_settings_controller );
		VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( VALUE replication_elections_settings_controller );

#endif
