/*
 *		RPDB::SettingsController::ReplicationTimeoutSettingsController
 *
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/
 
#include "rb_RPDB_Environment.h"

#include "rb_RPDB_ReplicationTimeoutSettingsController.h"
#include "rb_RPDB_ReplicationSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ReplicationTimeoutSettingsController.h>
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
extern	VALUE	rb_RPDB_ReplicationTimeoutSettingsController;

void Init_RPDB_ReplicationTimeoutSettingsController()	{

	rb_RPDB_ReplicationTimeoutSettingsController		=	rb_define_class_under(	rb_RPDB_ReplicationSettingsController, 
																																						"Timeout",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_ReplicationTimeoutSettingsController, 	"new",																rb_RPDB_ReplicationTimeoutSettingsController_new,														-1 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"initialize",													rb_RPDB_ReplicationTimeoutSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"parent_environment",									rb_RPDB_ReplicationTimeoutSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_ReplicationTimeoutSettingsController, 	"environment",												"parent_environment"	);
                        			            			                                                                                              				
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"timeout",														rb_RPDB_ReplicationTimeoutSettingsController_timeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_setTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"wait_time_before_checkpoint_write",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_wait_time_before_checkpoint_write",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"wait_time_before_retry_connection",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_wait_time_before_retry_connection",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"election_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_electionTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_election_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_setElectionTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"wait_time_before_retry_election",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_wait_time_before_retry_election",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"full_election_participation_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_full_election_participation_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"heartbeat_monitor_pulse",														rb_RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_heartbeat_monitor_pulse",														rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"heartbeat_broadcast_pulse",														rb_RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_heartbeat_broadcast_pulse",														rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"lease_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_leaseTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"set_lease_timeout",														rb_RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_new(	int			argc,
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

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller	=	RPDB_ReplicationSettingsController_timeoutSettingsController( c_parent_replication_settings_controller );

	VALUE	rb_replication_timeout_settings_controller	= RUBY_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( c_replication_timeout_settings_controller );

	rb_iv_set(	rb_replication_timeout_settings_controller,
							RPDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_replication_settings_controller };
	rb_obj_call_init(	rb_replication_timeout_settings_controller,
										1, 
										argv );
	
	return rb_replication_timeout_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_parentEnvironment(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_ReplicationTimeoutSettingsController_parentSettingsController( rb_replication_timeout_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_parentSettingsController(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller		=	rb_RPDB_ReplicationTimeoutSettingsController_parentReplicationSettingsController( rb_replication_timeout_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_RPDB_ReplicationTimeoutSettingsController_parentSettingsController( rb_parent_replication_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_replication_settings_controller  *
*******************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_parentReplicationSettingsController(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller	=	rb_iv_get(	rb_replication_timeout_settings_controller,
																																RPDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER );

	return rb_parent_replication_settings_controller;
}

/************
*  timeout  *
************/

//	DB_REP_ACK_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_timeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_timeout( c_replication_timeout_settings_controller ) );
}

/****************
*  set_timeout  *
****************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setTimeout(		VALUE	rb_replication_timeout_settings_controller, 
																	VALUE	rb_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setTimeout(	c_replication_timeout_settings_controller,
															FIX2INT( rb_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/**************************************
*  wait_time_before_checkpoint_write  *
**************************************/

//	DB_REP_CHECKPOINT_DELAY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( c_replication_timeout_settings_controller ) );
}

/******************************************
*  set_wait_time_before_checkpoint_write  *
******************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	VALUE	rb_replication_timeout_settings_controller, 
																						VALUE	rb_wait_time_before_checkpoint_write )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_checkpoint_write ) );

	return rb_replication_timeout_settings_controller;
}

/**************************************
*  wait_time_before_retry_connection  *
**************************************/

//	DB_REP_CONNECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( c_replication_timeout_settings_controller ) );
}

/******************************************
*  set_wait_time_before_retry_connection  *
******************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	VALUE	rb_replication_timeout_settings_controller,
																						VALUE	rb_wait_time_before_retry_connection )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_retry_connection ) );

	return rb_replication_timeout_settings_controller;
}

/*********************
*  election_timeout  *
*********************/

//	DB_REP_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_electionTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_electionTimeout( c_replication_timeout_settings_controller ) );
}

/*************************
*  set_election_timeout  *
*************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setElectionTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																		VALUE	rb_election_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setElectionTimeout(	c_replication_timeout_settings_controller,
																	FIX2INT( rb_election_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/************************************
*  wait_time_before_retry_election  *
************************************/

//	DB_REP_ELECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( c_replication_timeout_settings_controller ) );
}

/****************************************
*  set_wait_time_before_retry_election  *
****************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	VALUE	rb_replication_timeout_settings_controller, 
																					VALUE	rb_wait_time_before_retry_election )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	c_replication_timeout_settings_controller,
																				FIX2INT( rb_wait_time_before_retry_election ) );

	return rb_replication_timeout_settings_controller;
}

/****************************************
*  full_election_participation_timeout  *
****************************************/

//	DB_REP_FULL_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( c_replication_timeout_settings_controller ) );
}

/********************************************
*  set_full_election_participation_timeout  *
********************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																							VALUE	rb_full_election_participation_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_full_election_participation_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/****************************
*  heartbeat_monitor_pulse  *
****************************/

//	DB_REP_HEARTBEAT_MONITOR
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( c_replication_timeout_settings_controller ) );
}

/********************************
*  set_heartbeat_monitor_pulse  *
********************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_monitor_pulse )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_monitor_pulse ) );

	return rb_replication_timeout_settings_controller;
}

/******************************
*  heartbeat_broadcast_pulse  *
******************************/

//	DB_REP_HEARTBEAT_SEND
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( c_replication_timeout_settings_controller ) );
}

/**********************************
*  set_heartbeat_broadcast_pulse  *
**********************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_broadcast_pulse )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );
	RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_broadcast_pulse ) );
	
	return rb_replication_timeout_settings_controller;
}

/******************
*  lease_timeout  *
******************/

//	DB_REP_LEASE_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_leaseTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_leaseTimeout( c_replication_timeout_settings_controller ) );
}

/**********************
*  set_lease_timeout  *
**********************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout(	VALUE	rb_replication_timeout_settings_controller,
																		VALUE	rb_lease_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout(	c_replication_timeout_settings_controller,
																FIX2INT( rb_lease_timeout ) );

	return rb_replication_timeout_settings_controller;
}
