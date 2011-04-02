/*
 *		RPbdb::SettingsController::ReplicationTimeoutSettingsController
 *
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/
 
#include "Environment.h"

#include "ReplicationTimeoutSettingsController.h"
#include "ReplicationSettingsController.h"
#include "SettingsController.h"

#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/ReplicationTimeoutSettingsController.h>
#include <rpbdb/ReplicationSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_ReplicationSettingsController;
extern	VALUE	rb_RPbdb_ReplicationTimeoutSettingsController;

void Init_rb_RPbdb_ReplicationTimeoutSettingsController()	{

	rb_RPbdb_ReplicationTimeoutSettingsController		=	rb_define_class_under(	rb_RPbdb_ReplicationSettingsController, 
																																						"Timeout",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_ReplicationTimeoutSettingsController, 	"new",																rb_RPbdb_ReplicationTimeoutSettingsController_new,														-1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"initialize",													rb_RPbdb_ReplicationTimeoutSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"parent_environment",									rb_RPbdb_ReplicationTimeoutSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController,				"parent_settings_controller",					rb_RPbdb_ReplicationTimeoutSettingsController_parentSettingsController,								0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController,				"parent_replication_settings_controller",					rb_RPbdb_ReplicationTimeoutSettingsController_parentReplicationSettingsController,								0 	);

	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_timeout,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_setTimeout,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"wait_time_before_checkpoint_write",														rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_wait_time_before_checkpoint_write",														rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"wait_time_before_retry_connection",														rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_wait_time_before_retry_connection",														rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"election_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_electionTimeout,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_election_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_setElectionTimeout,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"wait_time_before_retry_election",														rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_wait_time_before_retry_election",														rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"full_election_participation_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_full_election_participation_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"heartbeat_monitor_pulse",														rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatMonitorPulse,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_heartbeat_monitor_pulse",														rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"heartbeat_broadcast_pulse",														rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_heartbeat_broadcast_pulse",														rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse,													1 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"lease_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_leaseTimeout,													0 	);
	rb_define_method(						rb_RPbdb_ReplicationTimeoutSettingsController, 	"set_lease_timeout",														rb_RPbdb_ReplicationTimeoutSettingsController_setLeaseTimeout,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_settings_controller								=	Qnil;
	VALUE	rb_parent_replication_settings_controller		=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_replication_settings_controller, rb_RPbdb_ReplicationSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <no argument> ]",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent replication settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_replication_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_replication_settings_controller	=	rb_RPbdb_SettingsController_replicationSettingsController( rb_parent_settings_controller );
	}

	RPbdb_ReplicationSettingsController*	c_parent_replication_settings_controller;
	C_RPBDB_REPLICATION_SETTINGS_CONTROLLER( rb_parent_replication_settings_controller, c_parent_replication_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller	=	RPbdb_ReplicationSettingsController_timeoutSettingsController( c_parent_replication_settings_controller );

	VALUE	rb_replication_timeout_settings_controller	= RUBY_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( c_replication_timeout_settings_controller );

	rb_iv_set(	rb_replication_timeout_settings_controller,
							RPBDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER,
							rb_parent_replication_settings_controller );

	VALUE	argv[]	=	{ rb_parent_replication_settings_controller };
	rb_obj_call_init(	rb_replication_timeout_settings_controller,
										1, 
										argv );
	
	return rb_replication_timeout_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentEnvironment(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_ReplicationTimeoutSettingsController_parentSettingsController( rb_replication_timeout_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentSettingsController(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller		=	rb_RPbdb_ReplicationTimeoutSettingsController_parentReplicationSettingsController( rb_replication_timeout_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_RPbdb_ReplicationSettingsController_parentSettingsController( rb_parent_replication_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_replication_settings_controller  *
*******************************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_parentReplicationSettingsController(	VALUE	rb_replication_timeout_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller	=	rb_iv_get(	rb_replication_timeout_settings_controller,
																																RPBDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER );

	return rb_parent_replication_settings_controller;
}

/************
*  timeout  *
************/

//	DB_REP_ACK_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_timeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_timeout( c_replication_timeout_settings_controller ) );
}

/****************
*  set_timeout  *
****************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setTimeout(		VALUE	rb_replication_timeout_settings_controller, 
																	VALUE	rb_timeout )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setTimeout(	c_replication_timeout_settings_controller,
															FIX2INT( rb_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/**************************************
*  wait_time_before_checkpoint_write  *
**************************************/

//	DB_REP_CHECKPOINT_DELAY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( c_replication_timeout_settings_controller ) );
}

/******************************************
*  set_wait_time_before_checkpoint_write  *
******************************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	VALUE	rb_replication_timeout_settings_controller, 
																						VALUE	rb_wait_time_before_checkpoint_write )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_checkpoint_write ) );

	return rb_replication_timeout_settings_controller;
}

/**************************************
*  wait_time_before_retry_connection  *
**************************************/

//	DB_REP_CONNECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( c_replication_timeout_settings_controller ) );
}

/******************************************
*  set_wait_time_before_retry_connection  *
******************************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	VALUE	rb_replication_timeout_settings_controller,
																						VALUE	rb_wait_time_before_retry_connection )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_retry_connection ) );

	return rb_replication_timeout_settings_controller;
}

/*********************
*  election_timeout  *
*********************/

//	DB_REP_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_electionTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_electionTimeout( c_replication_timeout_settings_controller ) );
}

/*************************
*  set_election_timeout  *
*************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setElectionTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																		VALUE	rb_election_timeout )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setElectionTimeout(	c_replication_timeout_settings_controller,
																	FIX2INT( rb_election_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/************************************
*  wait_time_before_retry_election  *
************************************/

//	DB_REP_ELECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( c_replication_timeout_settings_controller ) );
}

/****************************************
*  set_wait_time_before_retry_election  *
****************************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	VALUE	rb_replication_timeout_settings_controller, 
																					VALUE	rb_wait_time_before_retry_election )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	c_replication_timeout_settings_controller,
																				FIX2INT( rb_wait_time_before_retry_election ) );

	return rb_replication_timeout_settings_controller;
}

/****************************************
*  full_election_participation_timeout  *
****************************************/

//	DB_REP_FULL_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( c_replication_timeout_settings_controller ) );
}

/********************************************
*  set_full_election_participation_timeout  *
********************************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																							VALUE	rb_full_election_participation_timeout )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_full_election_participation_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/****************************
*  heartbeat_monitor_pulse  *
****************************/

//	DB_REP_HEARTBEAT_MONITOR
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( c_replication_timeout_settings_controller ) );
}

/********************************
*  set_heartbeat_monitor_pulse  *
********************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_monitor_pulse )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_monitor_pulse ) );

	return rb_replication_timeout_settings_controller;
}

/******************************
*  heartbeat_broadcast_pulse  *
******************************/

//	DB_REP_HEARTBEAT_SEND
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( c_replication_timeout_settings_controller ) );
}

/**********************************
*  set_heartbeat_broadcast_pulse  *
**********************************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_broadcast_pulse )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );
	RPbdb_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_broadcast_pulse ) );
	
	return rb_replication_timeout_settings_controller;
}

/******************
*  lease_timeout  *
******************/

//	DB_REP_LEASE_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPbdb_ReplicationTimeoutSettingsController_leaseTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPbdb_ReplicationTimeoutSettingsController_leaseTimeout( c_replication_timeout_settings_controller ) );
}

/**********************
*  set_lease_timeout  *
**********************/

VALUE rb_RPbdb_ReplicationTimeoutSettingsController_setLeaseTimeout(	VALUE	rb_replication_timeout_settings_controller,
																		VALUE	rb_lease_timeout )	{

	RPbdb_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPbdb_ReplicationTimeoutSettingsController_setLeaseTimeout(	c_replication_timeout_settings_controller,
																FIX2INT( rb_lease_timeout ) );

	return rb_replication_timeout_settings_controller;
}
