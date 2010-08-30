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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ReplicationTimeoutSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_ReplicationTimeoutSettingsController;

void Init_RPDB_ReplicationTimeoutSettingsController()	{

	rb_define_singleton_method(	rb_RPDB_ReplicationTimeoutSettingsController, 	"new",																rb_RPDB_ReplicationTimeoutSettingsController_init,														1 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"initialize",													rb_RPDB_ReplicationTimeoutSettingsController_init,														1 	);
                        			                                        
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"parent_environment",									rb_RPDB_ReplicationTimeoutSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_ReplicationTimeoutSettingsController, 	"environment",												"parent_environment"	);
                        			            			                                                                                              				
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_timeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_electionTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setElectionTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_leaseTimeout,													0 	);
	rb_define_method(						rb_RPDB_ReplicationTimeoutSettingsController, 	"shm_key",														rb_RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_replication_settings_controller )	{

	RPDB_ReplicationSettingsController*	c_parent_replication_settings_controller;
	C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_parent_replication_settings_controller, c_parent_replication_settings_controller );

	VALUE	rb_replication_timeout_settings_controller	= RUBY_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( RPDB_ReplicationTimeoutSettingsController_new( c_parent_replication_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_replication_settings_controller;
	
	rb_obj_call_init(	rb_replication_timeout_settings_controller,
					 1, 
					 argv );
	
	return rb_replication_timeout_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_init(	VALUE	rb_replication_timeout_settings_controller,
																													VALUE	rb_parent_replication_settings_controller __attribute__ ((unused )) )	{
	
	return rb_replication_timeout_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_ReplicationTimeoutSettingsController_parentEnvironment(	VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_ReplicationTimeoutSettingsController_parentEnvironment( c_replication_timeout_settings_controller ) );
}

/****************
*  timeout  *
****************/

//	DB_REP_ACK_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_timeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_timeout( c_replication_timeout_settings_controller ) );
}

/******************
*  setTimeout  *
******************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setTimeout(		VALUE	rb_replication_timeout_settings_controller, 
																	VALUE	rb_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setTimeout(	c_replication_timeout_settings_controller,
															FIX2INT( rb_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/**************************************
*  waitTimeBeforeCheckpointWrite  *
**************************************/

//	DB_REP_CHECKPOINT_DELAY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeCheckpointWrite( c_replication_timeout_settings_controller ) );
}

/*****************************************
*  setWaitTimeBeforeCheckpointWrite  *
*****************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	VALUE	rb_replication_timeout_settings_controller, 
																						VALUE	rb_wait_time_before_checkpoint_write )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeCheckpointWrite(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_checkpoint_write ) );

	return rb_replication_timeout_settings_controller;
}

/*************************************
*  waitTimeBeforeRetryConnection  *
*************************************/

//	DB_REP_CONNECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryConnection( c_replication_timeout_settings_controller ) );
}

/*****************************************
*  setWaitTimeBeforeRetryConnection  *
*****************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	VALUE	rb_replication_timeout_settings_controller,
																						VALUE	rb_wait_time_before_retry_connection )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryConnection(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_wait_time_before_retry_connection ) );

	return rb_replication_timeout_settings_controller;
}

/*************************
*  electionTimeout  *
*************************/

//	DB_REP_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_electionTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_electionTimeout( c_replication_timeout_settings_controller ) );
}

/*************************
*  setElectionTimeout  *
*************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setElectionTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																		VALUE	rb_election_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setElectionTimeout(	c_replication_timeout_settings_controller,
																	FIX2INT( rb_election_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/*************************************
*  waitTimeBeforeRetryElection  *
*************************************/

//	DB_REP_ELECTION_RETRY
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_waitTimeBeforeRetryElection( c_replication_timeout_settings_controller ) );
}

/*****************************************
*  setWaitTimeBeforeRetryElection  *
*****************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	VALUE	rb_replication_timeout_settings_controller, 
																					VALUE	rb_wait_time_before_retry_election )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setWaitTimeBeforeRetryElection(	c_replication_timeout_settings_controller,
																				FIX2INT( rb_wait_time_before_retry_election ) );

	return rb_replication_timeout_settings_controller;
}

/*****************************************
*  fullElectionParticipationTimeout  *
*****************************************/

//	DB_REP_FULL_ELECTION_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_fullElectionParticipationTimeout( c_replication_timeout_settings_controller ) );
}

/********************************************
*  setFullElectionParticipationTimeout  *
********************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	VALUE	rb_replication_timeout_settings_controller, 
																							VALUE	rb_full_election_participation_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setFullElectionParticipationTimeout(	c_replication_timeout_settings_controller,
																					FIX2INT( rb_full_election_participation_timeout ) );

	return rb_replication_timeout_settings_controller;
}

/*********************************
*  heartbeatMonitorPulse  *
*********************************/

//	DB_REP_HEARTBEAT_MONITOR
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_heartbeatMonitorPulse( c_replication_timeout_settings_controller ) );
}

/*************************************
*  setHeartbeatMonitorPulse  *
*************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_monitor_pulse )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setHeartbeatMonitorPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_monitor_pulse ) );

	return rb_replication_timeout_settings_controller;
}

/*********************************
*  heartbeatBroadcastPulse  *
*********************************/

//	DB_REP_HEARTBEAT_SEND
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_heartbeatBroadcastPulse( c_replication_timeout_settings_controller ) );
}

/*************************************
*  setHeartbeatBroadcastPulse  *
*************************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	VALUE	rb_replication_timeout_settings_controller, 
																				VALUE	rb_heartbeat_broadcast_pulse )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );
	RPDB_ReplicationTimeoutSettingsController_setHeartbeatBroadcastPulse(	c_replication_timeout_settings_controller,
																			FIX2INT( rb_heartbeat_broadcast_pulse ) );
	
	return rb_replication_timeout_settings_controller;
}

/*********************
*  leaseTimeout  *
*********************/

//	DB_REP_LEASE_TIMEOUT
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_timeout.html
VALUE rb_RPDB_ReplicationTimeoutSettingsController_leaseTimeout( VALUE	rb_replication_timeout_settings_controller )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	return INT2FIX( RPDB_ReplicationTimeoutSettingsController_leaseTimeout( c_replication_timeout_settings_controller ) );
}

/************************
*  setLeaseTimeout  *
************************/

VALUE rb_RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout(	VALUE	rb_replication_timeout_settings_controller,
																		VALUE	rb_lease_timeout )	{

	RPDB_ReplicationTimeoutSettingsController*	c_replication_timeout_settings_controller;
	C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller );

	RPDB_ReplicationTimeoutSettingsController_setLeaseTimeout(	c_replication_timeout_settings_controller,
																FIX2INT( rb_lease_timeout ) );

	return rb_replication_timeout_settings_controller;
}
