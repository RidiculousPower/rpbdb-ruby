/*
 *		RPDB::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_ReplicationElectionSettingsController.h"
#include "rb_RPDB_ReplicationSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ReplicationElectionSettingsController.h>
#include <rpdb/RPDB_ReplicationSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_ReplicationSettingsController;
extern	VALUE	rb_RPDB_ReplicationElectionSettingsController;

void Init_RPDB_ReplicationElectionSettingsController()	{

	rb_RPDB_ReplicationElectionSettingsController		=	rb_define_class_under(	rb_RPDB_ReplicationSettingsController, 
																																						"Election",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_ReplicationElectionSettingsController, 	"new",																rb_RPDB_ReplicationElectionSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"initialize",													rb_RPDB_ReplicationElectionSettingsController_init,														-1 	);

	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"parent_environment",									rb_RPDB_ReplicationElectionSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_ReplicationElectionSettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_numberOfSitesRequiredForElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_numberOfVotesRequiredForElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_waitForAllClients,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_waitForAllElectablePeers,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_neverWait,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneClient,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationElectionSettingsController, 				"shm_key",														rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE	rb_RPDB_ReplicationElectionSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_settings_controller								=	Qnil;
	VALUE	rb_parent_replication_settings_controller		=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_replication_settings_controller, rb_RPDB_ReplicationSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <no argument> ]",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent replication settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_replication_settings_controller	=	rb_RPDB_SettingsController_replicationSettingsController( rb_parent_settings_controller );
	}

	RPDB_ReplicationSettingsController*	c_parent_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_parent_replication_settings_controller, c_parent_replication_settings_controller );

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller	=	RPDB_ReplicationSettingsController_electionSettingsController( c_parent_replication_settings_controller );

	VALUE	rb_replication_election_settings_controller	= RUBY_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( c_replication_election_settings_controller );

	rb_iv_set(	rb_replication_election_settings_controller,
							RPDB_RB_REPLICATION_ELECTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_replication_settings_controller };
	rb_obj_call_init(	rb_replication_election_settings_controller,
										 1, 
										 argv );
	
	return rb_replication_election_settings_controller;		
}

/*************
*  new  *
*************/

VALUE	rb_RPDB_ReplicationElectionSettingsController_init(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/

VALUE rb_RPDB_ReplicationElectionSettingsController_parentEnvironment(	VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_ReplicationElectionSettingsController_parentEnvironment( c_replication_election_settings_controller ) );
}

/*****************************************
*  numberOfSitesRequiredForElection  *
*****************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_RPDB_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return INT2FIX( RPDB_ReplicationElectionSettingsController_numberOfSitesRequiredForElection( c_replication_election_settings_controller ) );
}

	/*********************************************
	*  setNumberOfSitesRequiredForElection  *
	*********************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	VALUE	rb_replication_election_settings_controller,
	 																							VALUE	rb_number_of_sites_required_for_election	)	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_setNumberOfSitesRequiredForElection(	c_replication_election_settings_controller,
																							FIX2INT( rb_number_of_sites_required_for_election ) );

		return rb_number_of_sites_required_for_election;
	}

/*****************************************
*  numberOfSitesRequiredForElection  *
*****************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_RPDB_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return INT2FIX( RPDB_ReplicationElectionSettingsController_numberOfVotesRequiredForElection( c_replication_election_settings_controller ) );
}

	/*********************************************
	*  setNumberOfSitesRequiredForElection  *
	*********************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	VALUE	rb_replication_election_settings_controller,
	 																							VALUE	rb_number_of_votes_required_for_election	)	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_setNumberOfVotesRequiredForElection(	c_replication_election_settings_controller,
																							FIX2INT( rb_number_of_votes_required_for_election ) );

		return rb_replication_election_settings_controller;
	}

/*************************
*  waitForAllClients  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL
VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAllClients( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_waitForAllClients( c_replication_election_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/*********************************
	*  turnWaitForAllClientsOn  *
	*********************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*********************************
	*  turnWaitForAllClientsOff  *
	*********************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAllClientsOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*********************************
*  waitForAllElectablePeers  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ALL_PEERS
VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAllElectablePeers( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_waitForAllElectablePeers( c_replication_election_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************************************
	*  turnWaitForAllElectablePeersOn  *
	*************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/****************************************
	*  turnWaitForAllElectablePeersOff  *
	***************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAllElectablePeersOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*********************
*  waitForNone  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_NONE
VALUE	rb_RPDB_ReplicationElectionSettingsController_neverWait( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_neverWait( c_replication_election_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*************************
	*  turnWaitForNoneOn  *
	*************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnNeverWaitOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*************************
	*  turnWaitForNoneOff  *
	*************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnNeverWaitOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnNeverWaitOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*********************************
*  waitForAtLeastOneClient  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ONE
VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneClient( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_waitForAtLeastOneClient( c_replication_election_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************************************
	*  turnWaitForAtLeastOneClientOn  *
	*************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*************************************
	*  turnWaitForAtLeastOneClientOff  *
	*************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneClientOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*************************************
*  waitForAtLeastOneElectablePeer  *
*************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_ONE_PEER
VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_waitForAtLeastOneElectablePeer( c_replication_election_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*********************************************
	*  turnWaitForAtLeastOneElectablePeerOn  *
	*********************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*********************************************
	*  turnWaitForAtLeastOneElectablePeerOff  *
	*********************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForAtLeastOneElectablePeerOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

/*****************************************************
*  waitForMinimumElectablePeersForDurableElection  *
*****************************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_ack_policy.html
//	DB_REPMGR_ACKS_QUORUM
VALUE	rb_RPDB_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( VALUE	rb_replication_election_settings_controller )	{

	RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
	C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

	return ( RPDB_ReplicationElectionSettingsController_waitForMinimumElectablePeersForDurableElection( c_replication_election_settings_controller )	?	Qtrue
																																						:	Qfalse );
}

	/*************************************************************
	*  turnWaitForMinimumElectablePeersForDurableElectionOn  *
	*************************************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOn( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}

	/*************************************************************
	*  turnWaitForMinimumElectablePeersForDurableElectionOff  *
	*************************************************************/

	VALUE	rb_RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( VALUE	rb_replication_election_settings_controller )	{

		RPDB_ReplicationElectionSettingsController*	c_replication_election_settings_controller;
		C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller );

		RPDB_ReplicationElectionSettingsController_turnWaitForMinimumElectablePeersForDurableElectionOff( c_replication_election_settings_controller );

		return rb_replication_election_settings_controller;
	}
