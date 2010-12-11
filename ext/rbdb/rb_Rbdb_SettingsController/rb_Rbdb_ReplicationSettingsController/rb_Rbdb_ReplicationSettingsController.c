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
#include "rb_Rbdb_ReplicationTimeoutSettingsController.h"
#include "rb_Rbdb_ReplicationVerbositySettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_ReplicationSettingsController.h>
#include <rbdb/Rbdb_ReplicationElectionSettingsController.h>
#include <rbdb/Rbdb_ReplicationTimeoutSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_ReplicationSettingsController;
extern	VALUE	rb_Rbdb_ReplicationVerbositySettingsController;
extern	VALUE	rb_Rbdb_ReplicationElectionSettingsController;
extern	VALUE	rb_Rbdb_ReplicationTimeoutSettingsController;

void Init_rb_Rbdb_ReplicationSettingsController()	{

	rb_Rbdb_ReplicationSettingsController		=	rb_define_class_under(	rb_Rbdb_SettingsController, 
																																		"Replication",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_ReplicationSettingsController, 	"new",																rb_Rbdb_ReplicationSettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"initialize",													rb_Rbdb_ReplicationSettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"parent_environment",									rb_Rbdb_ReplicationSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_ReplicationSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController,				"parent_settings_controller",					rb_Rbdb_ReplicationSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"on?",														rb_Rbdb_ReplicationSettingsController_on,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_on",														rb_Rbdb_ReplicationSettingsController_turnOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"off?",														rb_Rbdb_ReplicationSettingsController_off,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_off",														rb_Rbdb_ReplicationSettingsController_turnOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"client_to_client_synchronization?",														rb_Rbdb_ReplicationSettingsController_clientToClientSynchronization,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_client_to_client_synchronization_on",														rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_client_to_client_synchronization_off",														rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"single_bulk_transfer?",														rb_Rbdb_ReplicationSettingsController_singleBulkTransfer,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_single_bulk_transfer_on",														rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_single_bulk_transfer_off",														rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"delay_new_sync_until_explicit_call?",														rb_Rbdb_ReplicationSettingsController_delayNewSyncUntilExplicitCall,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_delay_new_sync_until_explicit_call_on",														rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_delay_new_sync_until_explicit_call_off",														rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"use_master_leases?",														rb_Rbdb_ReplicationSettingsController_useMasterLeases,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_use_master_leases_on",														rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_use_master_leases_off",														rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"reinitialize_outdated_clients?",														rb_Rbdb_ReplicationSettingsController_reinitializeOutdatedClients,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_reinitialize_outdated_clients_on",														rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_reinitialize_outdated_clients_off",														rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"prohibit_wait?",														rb_Rbdb_ReplicationSettingsController_prohibitWait,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_prohibit_wait_on",														rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_prohibit_wait_off",														rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"require_strict_majority?",														rb_Rbdb_ReplicationSettingsController_requireStrictMajority,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_require_strict_majority_on",														rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOn,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"turn_require_strict_majority_off",														rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOff,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"is_master?",														rb_Rbdb_ReplicationSettingsController_isMaster,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_is_master",														rb_Rbdb_ReplicationSettingsController_setIsMaster,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"is_client?",														rb_Rbdb_ReplicationSettingsController_isClient,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_is_client",														rb_Rbdb_ReplicationSettingsController_setIsClient,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"start_as_client_or_rally_election?",														rb_Rbdb_ReplicationSettingsController_startAsClientOrRallyElection,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_start_as_client_or_rally_election",														rb_Rbdb_ReplicationSettingsController_setStartAsClientOrRallyElection,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"limit",														rb_Rbdb_ReplicationSettingsController_limit,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_limit",														rb_Rbdb_ReplicationSettingsController_setLimit,													2 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"host",														rb_Rbdb_ReplicationSettingsController_host,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_host",														rb_Rbdb_ReplicationSettingsController_setHost,													-1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"port",														rb_Rbdb_ReplicationSettingsController_port,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_port",														rb_Rbdb_ReplicationSettingsController_setPort,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"site_count",														rb_Rbdb_ReplicationSettingsController_siteCount,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_site_count",														rb_Rbdb_ReplicationSettingsController_setSiteCount,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"priority_order_number",														rb_Rbdb_ReplicationSettingsController_priorityOrderNumber,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_priority_order_number",														rb_Rbdb_ReplicationSettingsController_setPriorityOrderNumber,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"retransmission_threshold_minimum",														rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMinimum,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_retransmission_threshold_minimum",														rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMinimum,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"retransmission_threshold_maximum",														rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMaximum,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_retransmission_threshold_maximum",														rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMaximum,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"slowest_clock_value",														rb_Rbdb_ReplicationSettingsController_slowestClockValue,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_slowest_clock_value",														rb_Rbdb_ReplicationSettingsController_setSlowestClockValue,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"fastest_clock_skew_value",														rb_Rbdb_ReplicationSettingsController_fastestClockSkewValue,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"set_fastest_clock_skew_value",														rb_Rbdb_ReplicationSettingsController_setFastestClockSkewValue,													1 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"election_settings_controller",														rb_Rbdb_ReplicationSettingsController_electionSettingsController,													0 	);
	rb_define_method(			rb_Rbdb_ReplicationSettingsController, 				"timeout_settings_controller",														rb_Rbdb_ReplicationSettingsController_timeoutSettingsController,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

//	FIX - replication should be moved under database (probably?)

VALUE rb_Rbdb_ReplicationSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <no argument> ]",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );	
	}

	Rbdb_SettingsController*	c_parent_settings_controller;
	C_RBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller	=	Rbdb_SettingsController_replicationSettingsController( c_parent_settings_controller );

	VALUE	rb_replication_settings_controller	= RUBY_RBDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller );

	rb_iv_set(	rb_replication_settings_controller,
							RBDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_replication_settings_controller,
										 1, 
										 argv );
	
	return rb_replication_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_ReplicationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_ReplicationSettingsController_parentEnvironment(	VALUE	rb_replication_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_ReplicationSettingsController_parentSettingsController( rb_replication_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_ReplicationSettingsController_parentSettingsController(	VALUE	rb_replication_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_replication_settings_controller,
																										RBDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********
*  on?  *
********/

//	DB_INIT_REP             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_Rbdb_ReplicationSettingsController_on( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_on( c_replication_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/************
*  turn_on  *
************/

VALUE rb_Rbdb_ReplicationSettingsController_turnOn( VALUE	rb_replication_settings_controller )	{

	VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
	if (		rb_parent_environment != Qnil
			&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
		rb_raise( rb_eRuntimeError, "Replication can only be turned on before environment is opened." );	
	}

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	Rbdb_ReplicationSettingsController_turnOn( c_replication_settings_controller );

	return rb_replication_settings_controller;
}

/*********
*  off?  *
*********/

VALUE rb_Rbdb_ReplicationSettingsController_off( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_off( c_replication_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/*************
*  turn_off  *
*************/

VALUE rb_Rbdb_ReplicationSettingsController_turnOff( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	Rbdb_ReplicationSettingsController_turnOff( c_replication_settings_controller );

	return rb_replication_settings_controller;
}


/**************************************
*  client_to_client_synchronization?  *
**************************************/

//	Currently, the replication manager framework only supports a single client peer, and the last specified peer is used
VALUE rb_Rbdb_ReplicationSettingsController_clientToClientSynchronization( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_clientToClientSynchronization( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*********************************************
	*  turn_client_to_client_synchronization_on  *
	*********************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Client to client synchronization can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOn( c_replication_settings_controller );
		
		return rb_replication_settings_controller;
	}

	/*********************************************
	*  turn_client_to_client_synchronization_on  *
	*********************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Client to client synchronization can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnClientToClientSynchronizationOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/**************************
*  single_bulk_transfer?  *
**************************/

//	DB_REP_CONF_BULK				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_singleBulkTransfer( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_singleBulkTransfer( c_replication_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*********************************
	*  turn_single_bulk_transfer_on  *
	*********************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Single bulk transfer can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnSingleBulkTransferOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/**********************************
	*  turn_single_bulk_transfer_off  *
	**********************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnSingleBulkTransferOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Single bulk transfer can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnSingleBulkTransferOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/****************************************
*  delay_new_sync_until_explicit_call?  *
****************************************/

//	DB_REP_CONF_DELAYCLIENT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_delayNewSyncUntilExplicitCall( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_delayNewSyncUntilExplicitCall( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/***********************************************
	*  turn_delay_new_sync_until_explicit_call_on  *
	***********************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Delay new sync until explicit call can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/************************************************
	*  turn_delay_new_sync_until_explicit_call_off  *
	************************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Delay new sync until explicit call can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/***********************
*  use_master_leases?  *
***********************/

//	DB_REP_CONF_LEASE               http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_useMasterLeases( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_useMasterLeases( c_replication_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/******************************
	*  turn_use_master_leases_on  *
	******************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Master leases can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnUseMasterLeasesOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*******************************
	*  turn_use_master_leases_off  *
	*******************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnUseMasterLeasesOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Master leases can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnUseMasterLeasesOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/***********************************
*  reinitialize_outdated_clients?  *
***********************************/

//	DB_REP_CONF_NOAUTOINIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_reinitializeOutdatedClients( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_reinitializeOutdatedClients( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/******************************************
	*  turn_reinitialize_outdated_clients_on  *
	******************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Reinitializing outdated clients can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*******************************************
	*  turn_reinitialize_outdated_clients_off  *
	*******************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Reinitializing outdated clients can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*******************
*  prohibit_wait?  *
*******************/

//	DB_REP_CONF_NOWAIT              http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_prohibitWait( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_prohibitWait( c_replication_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/**************************
	*  turn_prohibit_wait_on  *
	**************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Prohibiting waiting can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnProhibitWaitOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/***************************
	*  turn_prohibit_wait_off  *
	***************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnProhibitWaitOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Prohibiting waiting can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnProhibitWaitOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*****************************
*  require_strict_majority?  *
*****************************/

//	DB_REPMGR_CONF_2SITE_STRICT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_Rbdb_ReplicationSettingsController_requireStrictMajority( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_requireStrictMajority( c_replication_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/************************************
	*  turn_require_strict_majority_on  *
	************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOn( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Requiring strict majority can only be turned on before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*************************************
	*  turn_require_strict_majority_off  *
	*************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOff( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Requiring strict majority can only be turned off before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_turnRequireStrictMajorityOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/***************
*  is_master?  *
***************/

//	DB_REP_MASTER			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_start.html
VALUE rb_Rbdb_ReplicationSettingsController_isMaster( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_isMaster( c_replication_settings_controller )	?	Qtrue
																																														:	Qfalse );
}

	/******************
	*  set_is_master  *
	******************/

	VALUE rb_Rbdb_ReplicationSettingsController_setIsMaster( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Site can only be set as master before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setIsMaster( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/***************
*  is_client?  *
***************/

//	DB_REP_CLIENT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
VALUE rb_Rbdb_ReplicationSettingsController_isClient( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_isClient( c_replication_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/******************
	*  set_is_client  *
	******************/

	VALUE rb_Rbdb_ReplicationSettingsController_setIsClient( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Site can only be set as client before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setIsClient( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/***************************************
*  start_as_client_or_rally_election?  *
***************************************/

VALUE rb_Rbdb_ReplicationSettingsController_startAsClientOrRallyElection( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( Rbdb_ReplicationSettingsController_startAsClientOrRallyElection( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/******************************************
	*  set_start_as_client_or_rally_election  *
	******************************************/

	//	DB_REP_ELECTION		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
	VALUE rb_Rbdb_ReplicationSettingsController_setStartAsClientOrRallyElection( VALUE	rb_replication_settings_controller )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Site can only be set to start as client or rally election before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setStartAsClientOrRallyElection( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/**********
*  limit  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_limit.html
VALUE rb_Rbdb_ReplicationSettingsController_limit( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	double	c_limit		=	Rbdb_ReplicationSettingsController_limit( c_replication_settings_controller );
	VALUE		rb_limit	=	LONG2NUM( c_limit );

	return rb_limit;
}

	/**************
	*  set_limit  *
	**************/

	//	FIX - modify to follow pattern of other numeric setters
	VALUE rb_Rbdb_ReplicationSettingsController_setLimit(	VALUE	rb_replication_settings_controller, 
																												VALUE	rb_limit_in_gbytes, 
																												VALUE	rb_limit_in_bytes )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Replication limit can only be set before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		uint64_t		c_limit_in_gbytes	=	NUM2LONG( rb_limit_in_gbytes );
		uint64_t		c_limit_in_bytes	=	NUM2LONG( rb_limit_in_bytes );

		Rbdb_ReplicationSettingsController_setLimit(	c_replication_settings_controller,
																									c_limit_in_gbytes,
																									c_limit_in_bytes );

		return rb_replication_settings_controller;
	}

/*********
*  host  *
*********/

VALUE rb_Rbdb_ReplicationSettingsController_host( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return rb_str_new2( Rbdb_ReplicationSettingsController_host( c_replication_settings_controller ) );
}

	/*************
	*  set_host  *
	*************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_local_site.html
	//	specifies the host identification string and port number for the local system.
	VALUE rb_Rbdb_ReplicationSettingsController_setHost(	int			argc,
																												VALUE*	args,
																												VALUE		rb_replication_settings_controller )	{

		VALUE	rb_host	=	Qnil;
		VALUE	rb_port	=	Qnil;
		R_DefineAndParse( argc, args, rb_replication_settings_controller,
			R_DescribeParameterSet(
				R_ParameterSet(
					R_Parameter(					R_MatchString( rb_host ) ),
					R_OptionalParameter(	R_MatchFixNum( rb_port ) )
				),
				1,
				"<host>",
				"<host>, [<port>]"
			)
		);

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		char*	c_host	=	StringValuePtr( rb_host );

		Rbdb_ReplicationSettingsController_setHost(	c_replication_settings_controller,
																								c_host );

		return rb_replication_settings_controller;
	}

/*********
*  port  *
*********/

VALUE rb_Rbdb_ReplicationSettingsController_port( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	int		c_port	=	Rbdb_ReplicationSettingsController_port( c_replication_settings_controller );
	VALUE	rb_port	=	INT2FIX( c_port );

	return rb_port;
}

	/*************
	*  set_port  *
	*************/

	VALUE rb_Rbdb_ReplicationSettingsController_setPort(	VALUE		rb_replication_settings_controller,
																												VALUE		rb_port )	{

		if ( TYPE( rb_port ) != T_FIXNUM )	{
			rb_raise( rb_eArgError, "Port must be specified as numeric." );
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		int		c_port	=	FIX2INT( rb_port );

		Rbdb_ReplicationSettingsController_setPort(	c_replication_settings_controller,
																								c_port );

		return rb_replication_settings_controller;
	}

/***************
*  site_count  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_nsites.html
VALUE rb_Rbdb_ReplicationSettingsController_siteCount( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_siteCount( c_replication_settings_controller ) );
}

	/*******************
	*  set_site_count  *
	*******************/

	VALUE rb_Rbdb_ReplicationSettingsController_setSiteCount(	VALUE	rb_replication_settings_controller, 
																VALUE	rb_site_count )	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Site count can only be set before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setSiteCount(	c_replication_settings_controller,
		 													FIX2INT( rb_site_count ) );

		return rb_replication_settings_controller;
	}

/**************************
*  priority_order_number  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_priority.html
VALUE rb_Rbdb_ReplicationSettingsController_priorityOrderNumber( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_priorityOrderNumber( c_replication_settings_controller ) );
}

	/******************************
	*  set_priority_order_number  *
	******************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_priority.html
	VALUE rb_Rbdb_ReplicationSettingsController_setPriorityOrderNumber(	VALUE	rb_replication_settings_controller,
																			VALUE	rb_priority_order_number)	{

		VALUE	rb_parent_environment	=	rb_Rbdb_ReplicationSettingsController_parentEnvironment( rb_replication_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_Rbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Priority order number can only be set before environment is opened." );	
		}

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setPriorityOrderNumber(	c_replication_settings_controller,
		 															FIX2INT( rb_priority_order_number ) );

		return rb_replication_settings_controller;
	}

/*************************************
*  retransmission_threshold_minimum  *
*************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_request.html
VALUE rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMinimum( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_retransmissionThresholdMinimum( c_replication_settings_controller ) );
}

	/*****************************************
	*  set_retransmission_threshold_minimum  *
	*****************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMinimum(	VALUE	rb_replication_settings_controller, 
																					VALUE	rb_retransmission_threshold_minimum )	{

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setRetransmissionThresholdMinimum(	c_replication_settings_controller,
		 																		FIX2INT( rb_retransmission_threshold_minimum ) );

		return rb_replication_settings_controller;
	}

/*************************************
*  retransmission_threshold_maximum  *
*************************************/

VALUE rb_Rbdb_ReplicationSettingsController_retransmissionThresholdMaximum( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_retransmissionThresholdMaximum( c_replication_settings_controller ) );
}

	/*****************************************
	*  set_retransmission_threshold_maximum  *
	*****************************************/

	VALUE rb_Rbdb_ReplicationSettingsController_setRetransmissionThresholdMaximum(	VALUE	rb_replication_settings_controller,
	 																				VALUE	rb_retransmission_threshold_maximum )	{

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setRetransmissionThresholdMaximum(	c_replication_settings_controller,
		 																		FIX2INT( rb_retransmission_threshold_maximum ) );

		return rb_replication_settings_controller;
	}

/************************
*  slowest_clock_value  *
************************/

VALUE rb_Rbdb_ReplicationSettingsController_slowestClockValue( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_slowestClockValue( c_replication_settings_controller ) );
}

	/****************************
	*  set_slowest_clock_value  *
	****************************/

	VALUE rb_Rbdb_ReplicationSettingsController_setSlowestClockValue(	VALUE	rb_replication_settings_controller, 
																		VALUE	rb_slowest_clock_value )	{

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		Rbdb_ReplicationSettingsController_setSlowestClockValue(	c_replication_settings_controller,
		 															FIX2INT( rb_slowest_clock_value ) );

		return rb_replication_settings_controller;
	}

/*****************************
*  fastest_clock_skew_value  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_clockskew.html
VALUE rb_Rbdb_ReplicationSettingsController_fastestClockSkewValue( VALUE	rb_replication_settings_controller )	{

	Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
	C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( Rbdb_ReplicationSettingsController_fastestClockSkewValue( c_replication_settings_controller ) );
}

	/*********************************
	*  set_fastest_clock_skew_value  *
	*********************************/

	VALUE rb_Rbdb_ReplicationSettingsController_setFastestClockSkewValue(	VALUE	rb_replication_settings_controller, 
																			VALUE	rb_fastest_clock_value )	{

		Rbdb_ReplicationSettingsController*	c_replication_settings_controller;
		C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );
		Rbdb_ReplicationSettingsController_setFastestClockSkewValue(	c_replication_settings_controller,
		 																FIX2INT( rb_fastest_clock_value ) );

		return rb_replication_settings_controller;
	}

/*********************************
*  election_settings_controller  *
*********************************/

VALUE rb_Rbdb_ReplicationSettingsController_electionSettingsController( VALUE	rb_replication_settings_controller )	{

	VALUE	rb_replication_election_settings_controller	=	Qnil;
	
	if ( ( rb_replication_election_settings_controller = rb_iv_get(	rb_replication_settings_controller,
																																	RBDB_RB_SETTINGS_VARIABLE_REPLICATION_ELECTION_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_replication_election_settings_controller	=	rb_Rbdb_ReplicationElectionSettingsController_new(	1,
																																																			& rb_replication_settings_controller,
																																																			rb_Rbdb_ReplicationElectionSettingsController );
		rb_iv_set(	rb_replication_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_REPLICATION_ELECTION_SETTINGS_CONTROLLER,
								rb_replication_election_settings_controller );
	}
	
	return rb_replication_election_settings_controller;
}

/********************************
*  timeout_settings_controller  *
********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_Rbdb_ReplicationSettingsController_timeoutSettingsController( VALUE	rb_replication_settings_controller )	{

	VALUE	rb_replication_timeout_settings_controller	=	Qnil;
	
	if ( ( rb_replication_timeout_settings_controller = rb_iv_get(	rb_replication_settings_controller,
																																	RBDB_RB_SETTINGS_VARIABLE_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_replication_timeout_settings_controller	=	rb_Rbdb_ReplicationTimeoutSettingsController_new(	1,
																																																		& rb_replication_settings_controller,
																																																		rb_Rbdb_ReplicationTimeoutSettingsController );
		rb_iv_set(	rb_replication_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER,
								rb_replication_timeout_settings_controller );
	}
	
	return rb_replication_timeout_settings_controller;
}

/********************************
*  verbosity_settings_controller  *
********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_verbosity.html
VALUE rb_Rbdb_ReplicationSettingsController_verbositySettingsController( VALUE	rb_replication_settings_controller )	{

	VALUE	rb_replication_verbosity_settings_controller	=	Qnil;
	
	if ( ( rb_replication_verbosity_settings_controller = rb_iv_get(	rb_replication_settings_controller,
																																	RBDB_RB_SETTINGS_VARIABLE_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_replication_verbosity_settings_controller	=	rb_Rbdb_ReplicationVerbositySettingsController_new(	1,
																																																				& rb_replication_settings_controller,
																																																				rb_Rbdb_ReplicationVerbositySettingsController );
		rb_iv_set(	rb_replication_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER,
								rb_replication_verbosity_settings_controller );
	}
	
	return rb_replication_verbosity_settings_controller;
}

/*
	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_transport.html
	VALUE rb_Rbdb_ReplicationSettingsController_transportCallbackFunction( VALUE	rb_replication_settings_controller )	{
	Rbdb_ReplicationSettingsController_transportCallbackFunction();
	
	}

	VALUE rb_Rbdb_ReplicationSettingsController_setTransportCallbackFunction( VALUE	rb_replication_settings_controller )	{
	Rbdb_ReplicationSettingsController_setTransportCallbackFunction();

	}
*/
