/*
 *		Rbdb::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_ReplicationSettingsController.h"
#include "rb_Rbdb_ReplicationElectionSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_ReplicationSettingsController.h>
#include <rbdb/Rbdb_ReplicationElectionSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_ReplicationSettingsController;
extern	VALUE	rb_Rbdb_ReplicationElectionSettingsController;

void Init_rb_Rbdb_ReplicationElectionSettingsController()	{

	rb_Rbdb_ReplicationElectionSettingsController		=	rb_define_class_under(	rb_Rbdb_ReplicationSettingsController, 
																																						"Election",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_ReplicationElectionSettingsController, 	"new",																rb_Rbdb_ReplicationElectionSettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"initialize",													rb_Rbdb_ReplicationElectionSettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"parent_environment",									rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_ReplicationElectionSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController,				"parent_settings_controller",					rb_Rbdb_ReplicationElectionSettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController,				"parent_replication_settings_controller",					rb_Rbdb_ReplicationElectionSettingsController_parentReplicationSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"number_of_sites_required_for_election",														rb_Rbdb_ReplicationElectionSettingsController_numberOfSitesRequiredForElection,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"set_number_of_sites_required_for_election",														rb_Rbdb_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"number_of_votes_required_for_election",														rb_Rbdb_ReplicationElectionSettingsController_numberOfVotesRequiredForElection,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"set_number_of_votes_required_for_election",														rb_Rbdb_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_all_clients?",														rb_Rbdb_ReplicationElectionSettingsController_waitForAllClients,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_all_clients_on",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_all_clients_off",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_all_electable_peers?",														rb_Rbdb_ReplicationElectionSettingsController_waitForAllElectablePeers,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_all_electable_peers_on",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_all_electable_peers_off",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_none?",														rb_Rbdb_ReplicationElectionSettingsController_neverWait,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_none_on",														rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_none_off",														rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_at_least_one_client?",														rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneClient,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_at_least_one_client_on",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_at_least_one_client_off",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_at_least_one_electable_peer?",														rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_at_least_one_electable_peer_on",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_at_least_one_electable_peer_off",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"wait_for_minimum_electable_peers_for_durable_election?",														rb_Rbdb_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_minimum_electable_peers_for_durable_election_on",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationElectionSettingsController, 				"turn_wait_for_minimum_electable_peers_for_durable_election_off",														rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE	rb_Rbdb_ReplicationElectionSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_settings_controller								=	Qnil;
	VALUE	rb_parent_replication_settings_controller		=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_replication_settings_controller, rb_Rbdb_ReplicationSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <no argument> ]",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent replication settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_replication_settings_controller	=	rb_Rbdb_SettingsController_replicationSettingsController( rb_parent_settings_controller );
	}

	Rbdb_ReplicationSettingsController*	c_parent_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_parent_replication_settings_controller, c_parent_replication_settings_controller );

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller	=	Rbdb_ReplicationSettingsController_electionSettingsController( c_parent_replication_settings_controller );

	VALUE	rb_replication_election_settings_controller	= RUBY_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( c_replication_election_settings_controller );

	rb_iv_set(	rb_replication_election_settings_controller,
							RBDB_RB_REPLICATION_ELECTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER,
							rb_parent_replication_settings_controller );

	VALUE	argv[]	=	{ rb_parent_replication_settings_controller };
	rb_obj_call_init(	rb_replication_election_settings_controller,
										 1, 
										 argv );
	
	return rb_replication_election_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE	rb_Rbdb_ReplicationElectionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment(	VALUE	rb_replication_election_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_ReplicationElectionSettingsController_parentSettingsController( rb_replication_election_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_ReplicationElectionSettingsController_parentSettingsController(	VALUE	rb_replication_election_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller		=	rb_Rbdb_ReplicationElectionSettingsController_parentReplicationSettingsController( rb_replication_election_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_Rbdb_ReplicationSettingsController_parentSettingsController( rb_parent_replication_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_replication_settings_controller  *
*******************************************/

VALUE rb_Rbdb_ReplicationElectionSettingsController_parentReplicationSettingsController(	VALUE	rb_replication_election_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller	=	rb_iv_get(	rb_replication_election_settings_controller,
																																RBDB_RB_REPLICATION_ELECTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER );

	return rb_parent_replication_settings_controller;
}

/******************************************
*  number_of_sites_required_for_election  *
******************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_Rbdb_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return INT2FIX( Rbdb_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( c_replication_election_settings_controller ) );
}

	/**********************************************
	*  set_number_of_sites_required_for_election  *
	**********************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	VALUE	rb_replication_election_settings_controller,
	 																							VALUE	rb_number_of_sites_required_for_election	)	{

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	c_replication_election_settings_controller,
																							FIX2INT( rb_number_of_sites_required_for_election ) );

		return rb_number_of_sites_required_for_election;
	}

/******************************************
*  number_of_votes_required_for_election  *
******************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_Rbdb_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return INT2FIX( Rbdb_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( c_replication_election_settings_controller ) );
}

	/**********************************************
	*  set_number_of_votes_required_for_election  *
	**********************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	VALUE	rb_replication_election_settings_controller,
	 																							VALUE	rb_number_of_votes_required_for_election	)	{

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	c_replication_election_settings_controller,
																							FIX2INT( rb_number_of_votes_required_for_election ) );

		return rb_replication_election_settings_controller;
	}

/*************************
*  wait_for_all_clients  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAllClients( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_waitForAllClients( c_replication_election_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/*********************************
	*  turn_wait_for_all_clients_on  *
	*********************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for all clients can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/**********************************
	*  turn_wait_for_all_clients_off  *
	**********************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for all clients can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAllClientsOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/**********************************
*  wait_for_all_electable_peers?  *
**********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL_PEERS
VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAllElectablePeers( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_waitForAllElectablePeers( c_replication_election_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*****************************************
	*  turn_wait_for_all_electable_peers_on  *
	*****************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for all electable peers can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/******************************************
	*  turn_wait_for_all_electable_peers_off  *
	******************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for all electable peers can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/******************
*  wait_for_none  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_NONE
VALUE	rb_Rbdb_ReplicationElectionSettingsController_neverWait( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_neverWait( c_replication_election_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/**************************
	*  turn_wait_for_none_on  *
	**************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for no peers can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnNeverWaitOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/***************************
	*  turn_wait_for_none_off  *
	***************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnNeverWaitOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for no peers can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnNeverWaitOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/**********************************
*  wait_for_at_least_one_client?  *
**********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ONE
VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneClient( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneClient( c_replication_election_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*****************************************
	*  turn_wait_for_at_least_one_client_on  *
	*****************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at least one client can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/******************************************
	*  turn_wait_for_at_least_one_client_off  *
	******************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at least one client can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/******************************************
*  wait_for_at_least_one_electable_peer?  *
******************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ONE_PEER
VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( c_replication_election_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*************************************************
	*  turn_wait_for_at_least_one_electable_peer_on  *
	*************************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at least one electable peer can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/**************************************************
	*  turn_wait_for_at_least_one_electable_peer_off  *
	**************************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at least one electable peer can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/***********************************************************
*  wait_for_minimum_electable_peers_for_durable_election?  *
***********************************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_QUORUM
VALUE	rb_Rbdb_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( VALUE	rb_replication_election_settings_controller )	{

	Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( Rbdb_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( c_replication_election_settings_controller )	?	Qtrue
																																						:	Qfalse );
}

	/******************************************************************
	*  turn_wait_for_minimum_electable_peers_for_durable_election_on  *
	******************************************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at minimum electable peers for durable election can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*******************************************************************
	*  turn_wait_for_minimum_electable_peers_for_durable_election_off  *
	*******************************************************************/

	VALUE	rb_Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( VALUE	rb_replication_election_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationElectionSettingsController_parentEnvironment( rb_replication_election_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Waiting for at minimum electable peers for durable election can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		Rbdb_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*******************************************************
*  set_site_is_now_replication_client_callback_method  *
*******************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setSiteIsNowReplicationClientCallbackMethod(	VALUE	rb_message_settings_controller,
 																					void *(site_is_now_replication_client_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setSiteIsNowReplicationClientCallbackMethod();


}
*/
/***************************************************
*  site_is_now_replication_client_callback_method  *
***************************************************/
/*
void *(site_is_now_replication_client_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_siteIsNowReplicationClientCallbackMethod(	VALUE	rb_message_settings_controller )	{
	

}
*/
/******************************************************
*  set_site_won_replication_election_callback_method  *
******************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setSiteWonReplicationElectionCallbackMethod(	VALUE	rb_message_settings_controller,
 																					void *(site_won_replication_election_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setSiteWonReplicationElectionCallbackMethod();
	
}
*/
/**************************************************
*  site_won_replication_election_callback_method  *
**************************************************/
/*
void *(site_won_replication_election_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_siteWonReplicationElectionCallbackMethod(	VALUE	rb_message_settings_controller )	{
	

}
*/
/****************************************************************
*  set_site_is_now_master_of_replication_group_callback_method  *
****************************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setSiteIsNowMasterOfReplicationGroupCallbackMethod(	VALUE	rb_message_settings_controller,
 																							void *(site_is_now_master_of_replication_group_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setSiteIsNowMasterOfReplicationGroupCallbackMethod();
	
}
*/
/************************************************************
*  site_is_now_master_of_replication_group_callback_method  *
************************************************************/
/*
void *(site_is_now_master_of_replication_group_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_siteIsNowMasterOfReplicationGroupCallbackMethod(	VALUE	rb_message_settings_controller )	{
	
}
*/
/*********************************************************
*  set_replication_group_has_new_master_callback_method  *
*********************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setReplicationGroupHasNewMasterCallbackMethod(	VALUE	rb_message_settings_controller,
 																					void *(replication_group_has_new_master_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setReplicationGroupHasNewMasterCallbackMethod();
	
}
*/
/*****************************************************
*  replication_group_has_new_master_callback_method  *
*****************************************************/
/*
void *(replication_group_has_new_master_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_replicationGroupHasNewMasterCallbackMethod(	VALUE	rb_message_settings_controller )	{
	
}
*/
/***********************************************************
*  set_replication_acknowledgement_failed_callback_method  *
***********************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setReplicationAcknowledgementFailedCallbackMethod(	VALUE	rb_message_settings_controller,
 																						void *(replication_acknowledgement_failed_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setReplicationAcknowledgementFailedCallbackMethod();
	

}
*/
/*******************************************************
*  replication_acknowledgement_failed_callback_method  *
*******************************************************/
/*
void *(replication_acknowledgement_failed_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_replicationAcknowledgementFailedCallbackMethod(	VALUE	rb_message_settings_controller )	{
	

}
*/
/******************************************************
*  set_replication_startup_completed_callback_method  *
******************************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setReplicationStartupCompletedCallbackMethod(	VALUE	rb_message_settings_controller,
 																					void *(replication_startup_completed_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setReplicationStartupCompletedCallbackMethod();
	
}
*/
/**************************************************
*  replication_startup_completed_callback_method  *
**************************************************/
/*
void *(replication_startup_completed_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_replicationStartupCompletedCallbackMethod(	VALUE	rb_message_settings_controller )	{
	
}
*/
