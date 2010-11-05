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

#include "rb_RPDB_ReplicationSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_ReplicationSettingsController.h>
#include <rpdb/RPDB_ReplicationElectionSettingsController.h>
#include <rpdb/RPDB_ReplicationTimeoutSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_ReplicationSettingsController;
extern	VALUE	rb_RPDB_ReplicationElectionSettingsController;
extern	VALUE	rb_RPDB_ReplicationTimeoutSettingsController;

void Init_RPDB_ReplicationSettingsController()	{

	rb_RPDB_ReplicationSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"Replication",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_ReplicationSettingsController, 	"new",																rb_RPDB_ReplicationSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"initialize",													rb_RPDB_ReplicationSettingsController_init,														-1 	);

	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"parent_environment",									rb_RPDB_ReplicationSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_ReplicationSettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_on,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_off,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_clientToClientSynchronization,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_singleBulkTransfer,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_delayNewSyncUntilExplicitCall,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_useMasterLeases,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_reinitializeOutdatedClients,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_prohibitWait,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnProhibitWaitOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnProhibitWaitOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_requireStrictMajority,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOn,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOff,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_isMaster,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setIsMaster,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_isClient,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setIsClient,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_startAsClientOrRallyElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setStartAsClientOrRallyElection,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_limit,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setLimit,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_host,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setHost,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_port,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setPort,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_siteCount,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setSiteCount,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_priorityOrderNumber,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setPriorityOrderNumber,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_retransmissionThresholdMinimum,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMinimum,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_retransmissionThresholdMaximum,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMaximum,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_slowestClockValue,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setSlowestClockValue,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_fastestClockSkewValue,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_setFastestClockSkewValue,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_electionSettingsController,													0 	);
	rb_define_method(			rb_RPDB_ReplicationSettingsController, 				"shm_key",														rb_RPDB_ReplicationSettingsController_timeoutSettingsController,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

//	FIX - replication should be moved under database (probably?)

VALUE rb_RPDB_ReplicationSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <no argument> ]",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPDB_ReplicationSettingsController*	c_replication_settings_controller	=	RPDB_SettingsController_replicationSettingsController( c_parent_settings_controller );

	VALUE	rb_replication_settings_controller	= RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller );

	rb_iv_set(	rb_replication_settings_controller,
							RPDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_replication_settings_controller,
										 1, 
										 argv );
	
	return rb_replication_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_ReplicationSettingsController_init(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_ReplicationSettingsController_parentEnvironment(	VALUE	rb_replication_settings_controller )	{

}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_ReplicationSettingsController_parentSettingsController(	VALUE	rb_replication_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_replication_settings_controller,
																										RPDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********
*  on  *
*********/

//	DB_INIT_REP             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_ReplicationSettingsController_on( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_on( c_replication_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/*************
*  turnOn  *
*************/

VALUE rb_RPDB_ReplicationSettingsController_turnOn( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	RPDB_ReplicationSettingsController_turnOn( c_replication_settings_controller );

	return rb_replication_settings_controller;
}

/*************
*  off  *
*************/

VALUE rb_RPDB_ReplicationSettingsController_off( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_off( c_replication_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/*****************
*  turnOff  *
*****************/

VALUE rb_RPDB_ReplicationSettingsController_turnOff( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	RPDB_ReplicationSettingsController_turnOff( c_replication_settings_controller );

	return rb_replication_settings_controller;
}


/*************
*  clientToClientSynchronization  *
*************/

//	Currently, the replication manager framework only supports a single client peer, and the last specified peer is used
VALUE rb_RPDB_ReplicationSettingsController_clientToClientSynchronization( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_clientToClientSynchronization( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*****************
	*  turnClientToClientSynchronizationOn  *
	*****************/

	VALUE rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOn( c_replication_settings_controller );
		
		return rb_replication_settings_controller;
	}

	/*****************
	*  turnClientToClientSynchronizationOff  *
	*****************/

	VALUE rb_RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnClientToClientSynchronizationOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*************************
*  singleBulkTransfer  *
*************************/

//	DB_REP_CONF_BULK				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_singleBulkTransfer( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_singleBulkTransfer( c_replication_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*********************************
	*  turnSingleBulkTransferOn  *
	*********************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnSingleBulkTransferOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*********************************
	*  turnSingleBulkTransferOff  *
	*********************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnSingleBulkTransferOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnSingleBulkTransferOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*************************************
*  delayNewSyncUntilExplicitCall  *
*************************************/

//	DB_REP_CONF_DELAYCLIENT         http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_delayNewSyncUntilExplicitCall( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_delayNewSyncUntilExplicitCall( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/*********************************************
	*  turnDelayNewSyncUntilExplicitCallOn  *
	*********************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*********************************************
	*  turnDelayNewSyncUntilExplicitCallOff  *
	*********************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnDelayNewSyncUntilExplicitCallOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*************************
*  useMasterLeases  *
*************************/

//	DB_REP_CONF_LEASE               http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_useMasterLeases( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_useMasterLeases( c_replication_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/*****************************
	*  turnUseMasterLeasesOn  *
	*****************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnUseMasterLeasesOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*****************************
	*  turnUseMasterLeasesOff  *
	*****************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnUseMasterLeasesOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnUseMasterLeasesOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*************************************
*  prohibitAutoInitForOldClients  *
*************************************/

//	DB_REP_CONF_NOAUTOINIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_reinitializeOutdatedClients( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_reinitializeOutdatedClients( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*********************************************
	*  turnProhibitAutoInitForOldClientsOn  *
	*********************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*********************************************
	*  turnProhibitAutoInitForOldClientsOff  *
	*********************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnReinitializeOutdatedClientsOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*********************
*  prohibitWait  *
*********************/

//	DB_REP_CONF_NOWAIT              http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_prohibitWait( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_prohibitWait( c_replication_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/*************************
	*  turnProhibitWaitOn  *
	*************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnProhibitWaitOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnProhibitWaitOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*****************************
	*  turnProhibitWaitOff  *
	*****************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnProhibitWaitOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnProhibitWaitOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*****************************
*  requireStrictMajority  *
*****************************/

//	DB_REPMGR_CONF_2SITE_STRICT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_config.html
VALUE rb_RPDB_ReplicationSettingsController_requireStrictMajority( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_requireStrictMajority( c_replication_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*************************************
	*  turnRequireStrictMajorityOn  *
	*************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOn( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnRequireStrictMajorityOn( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

	/*************************************
	*  turnRequireStrictMajorityOff  *
	*************************************/

	VALUE rb_RPDB_ReplicationSettingsController_turnRequireStrictMajorityOff( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_turnRequireStrictMajorityOff( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*****************
*  isMaster  *
*****************/

//	DB_REP_MASTER			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_start.html
VALUE rb_RPDB_ReplicationSettingsController_isMaster( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_isMaster( c_replication_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/*********************
	*  setIsMaster  *
	*********************/

	VALUE rb_RPDB_ReplicationSettingsController_setIsMaster( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setIsMaster( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*****************
*  isClient  *
*****************/

//	DB_REP_CLIENT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
VALUE rb_RPDB_ReplicationSettingsController_isClient( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_isClient( c_replication_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/*********************
	*  setIsClient  *
	*********************/

	VALUE rb_RPDB_ReplicationSettingsController_setIsClient( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setIsClient( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*****************
*  startAsClientOrRallyElection  *
*****************/

VALUE rb_RPDB_ReplicationSettingsController_startAsClientOrRallyElection( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return ( RPDB_ReplicationSettingsController_startAsClientOrRallyElection( c_replication_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*****************
	*  setStartAsClientOrRallyElection  *
	*****************/

	//	DB_REP_ELECTION		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
	VALUE rb_RPDB_ReplicationSettingsController_setStartAsClientOrRallyElection( VALUE	rb_replication_settings_controller )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setStartAsClientOrRallyElection( c_replication_settings_controller );

		return rb_replication_settings_controller;
	}

/*************
*  limit  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_limit.html
VALUE rb_RPDB_ReplicationSettingsController_limit( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_limit( c_replication_settings_controller ) );
}

	/*****************
	*  setLimit  *
	*****************/

	VALUE rb_RPDB_ReplicationSettingsController_setLimit(	VALUE	rb_replication_settings_controller, 
															VALUE	rb_limit_in_gbytes, 
															VALUE	rb_limit_in_bytes )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setLimit(	c_replication_settings_controller,
		 												FIX2INT( rb_limit_in_gbytes ),
														FIX2INT( rb_limit_in_bytes ) );

		return rb_replication_settings_controller;
	}

/*************
*  host  *
*************/

VALUE rb_RPDB_ReplicationSettingsController_host( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return rb_str_new2( RPDB_ReplicationSettingsController_host( c_replication_settings_controller ) );
}

	/*****************
	*  setHost  *
	*****************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_local_site.html
	//	specifies the host identification string and port number for the local system.
	VALUE rb_RPDB_ReplicationSettingsController_setHost(	VALUE	rb_replication_settings_controller, 
															VALUE 	rb_host )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setHost(	c_replication_settings_controller,
		 												StringValuePtr( rb_host ) );

		return rb_replication_settings_controller;
	}

/*************
*  port  *
*************/

VALUE rb_RPDB_ReplicationSettingsController_port( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_port( c_replication_settings_controller ) );
}

	/*****************
	*  setPort  *
	*****************/

	VALUE rb_RPDB_ReplicationSettingsController_setPort(	VALUE	rb_replication_settings_controller,
															VALUE	rb_host, 
															VALUE	rb_port )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setPort(	c_replication_settings_controller,
		 												StringValuePtr( rb_host ),
														FIX2INT( rb_port ) );

		return rb_replication_settings_controller;
	}

/*****************
*  siteCount  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_nsites.html
VALUE rb_RPDB_ReplicationSettingsController_siteCount( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_siteCount( c_replication_settings_controller ) );
}

	/*********************
	*  setSiteCount  *
	*********************/

	VALUE rb_RPDB_ReplicationSettingsController_setSiteCount(	VALUE	rb_replication_settings_controller, 
																VALUE	rb_site_count )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setSiteCount(	c_replication_settings_controller,
		 													FIX2INT( rb_site_count ) );

		return rb_replication_settings_controller;
	}

/*****************************
*  priorityOrderNumber  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_priority.html
VALUE rb_RPDB_ReplicationSettingsController_priorityOrderNumber( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_priorityOrderNumber( c_replication_settings_controller ) );
}

	/*****************************
	*  setPriorityOrderNumber  *
	*****************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_priority.html
	VALUE rb_RPDB_ReplicationSettingsController_setPriorityOrderNumber(	VALUE	rb_replication_settings_controller,
																			VALUE	rb_priority_order_number)	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setPriorityOrderNumber(	c_replication_settings_controller,
		 															FIX2INT( rb_priority_order_number ) );

		return rb_replication_settings_controller;
	}

/*************************************
*  retransmissionThresholdMinimum  *
*************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_request.html
VALUE rb_RPDB_ReplicationSettingsController_retransmissionThresholdMinimum( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_retransmissionThresholdMinimum( c_replication_settings_controller ) );
}

	/*****************************************
	*  setRetransmissionThresholdMinimum  *
	*****************************************/

	VALUE rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMinimum(	VALUE	rb_replication_settings_controller, 
																					VALUE	rb_retransmission_threshold_minimum )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setRetransmissionThresholdMinimum(	c_replication_settings_controller,
		 																		FIX2INT( rb_retransmission_threshold_minimum ) );

		return rb_replication_settings_controller;
	}

/*************************************
*  retransmissionThresholdMaximum  *
*************************************/

VALUE rb_RPDB_ReplicationSettingsController_retransmissionThresholdMaximum( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_retransmissionThresholdMaximum( c_replication_settings_controller ) );
}

	/*****************************************
	*  setRetransmissionThresholdMaximum  *
	*****************************************/

	VALUE rb_RPDB_ReplicationSettingsController_setRetransmissionThresholdMaximum(	VALUE	rb_replication_settings_controller,
	 																				VALUE	rb_retransmission_threshold_maximum )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setRetransmissionThresholdMaximum(	c_replication_settings_controller,
		 																		FIX2INT( rb_retransmission_threshold_maximum ) );

		return rb_replication_settings_controller;
	}

/*************************
*  slowestClockValue  *
*************************/

VALUE rb_RPDB_ReplicationSettingsController_slowestClockValue( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_slowestClockValue( c_replication_settings_controller ) );
}

	/*****************************
	*  setSlowestClockValue  *
	*****************************/

	VALUE rb_RPDB_ReplicationSettingsController_setSlowestClockValue(	VALUE	rb_replication_settings_controller, 
																		VALUE	rb_slowest_clock_value )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

		RPDB_ReplicationSettingsController_setSlowestClockValue(	c_replication_settings_controller,
		 															FIX2INT( rb_slowest_clock_value ) );

		return rb_replication_settings_controller;
	}

/*****************************
*  fastestClockSkewValue  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_clockskew.html
VALUE rb_RPDB_ReplicationSettingsController_fastestClockSkewValue( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return INT2FIX( RPDB_ReplicationSettingsController_fastestClockSkewValue( c_replication_settings_controller ) );
}

	/*********************************
	*  setFastestClockSkewValue  *
	*********************************/

	VALUE rb_RPDB_ReplicationSettingsController_setFastestClockSkewValue(	VALUE	rb_replication_settings_controller, 
																			VALUE	rb_fastest_clock_value )	{

		RPDB_ReplicationSettingsController*	c_replication_settings_controller;
		C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );
		RPDB_ReplicationSettingsController_setFastestClockSkewValue(	c_replication_settings_controller,
		 																FIX2INT( rb_fastest_clock_value ) );

		return rb_replication_settings_controller;
	}

/*************************************************
*  acknowledgementPolicySettingsController  *
*************************************************/

VALUE rb_RPDB_ReplicationSettingsController_electionSettingsController( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return RUBY_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( RPDB_ReplicationSettingsController_electionSettingsController( c_replication_settings_controller ) );
}

/*********************************
*  timeoutSettingsController  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationSettingsController_timeoutSettingsController( VALUE	rb_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller );

	return RUBY_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( RPDB_ReplicationSettingsController_timeoutSettingsController( c_replication_settings_controller ) );
}

/*
	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_transport.html
	VALUE rb_RPDB_ReplicationSettingsController_transportCallbackFunction( VALUE	rb_replication_settings_controller )	{
	RPDB_ReplicationSettingsController_transportCallbackFunction();
	
	}

	VALUE rb_RPDB_ReplicationSettingsController_setTransportCallbackFunction( VALUE	rb_replication_settings_controller )	{
	RPDB_ReplicationSettingsController_setTransportCallbackFunction();

	}
*/
