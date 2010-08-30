/*
 *		RPDB::ReplicationController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Record.h"
#include "rb_RPDB_ReplicationController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ReplicationController.h>

#include <rpdb/RPDB_ReplicationSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;

extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_ReplicationController;
extern	VALUE	rb_RPDB_DatabaseReplicationSettingsController;
extern	VALUE	rb_RPDB_ReplicationSettingsController;

void Init_RPDB_ReplicationController()	{

	rb_RPDB_ReplicationController		=	rb_define_class_under(	rb_RPDB_Environment, 
																														"ReplicationController", 		
																														rb_cObject );

	rb_define_singleton_method(	rb_RPDB_ReplicationController, 	"new",											rb_RPDB_ReplicationController_new,												-1 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"initialize",								rb_RPDB_ReplicationController_init,												-1 	);
                                                                          
	rb_define_method(						rb_RPDB_ReplicationController, 	"settings_controller",			rb_RPDB_ReplicationController_settingsController,					0 	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"settings",									"settings_controller"	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"set",											"settings_controller"	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"set_to",										"settings_controller"	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"is_set_to",								"settings_controller"	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"parent_environment",				rb_RPDB_ReplicationController_parentEnvironment,					0 	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"environment",							"parent_environment"	);
                                                                          
	rb_define_method(						rb_RPDB_ReplicationController, 	"init_replication_id",			rb_RPDB_ReplicationController_initReplicationID,					0 	);
	rb_define_alias(						rb_RPDB_ReplicationController, 	"init_id",									"init_replication_id"	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"start",										rb_RPDB_ReplicationController_start,											0 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"process_message",					rb_RPDB_ReplicationController_processMessage,							0 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"sync",											rb_RPDB_ReplicationController_sync,												0 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"call_election",						rb_RPDB_ReplicationController_callElection,								0 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"add_remote_site",					rb_RPDB_ReplicationController_addRemoteSite,							0 	);
	rb_define_method(						rb_RPDB_ReplicationController, 	"site_list",								rb_RPDB_ReplicationController_siteList,										0 	);


}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_ReplicationController_new(	VALUE	klass __attribute__ ((unused )),
																					VALUE	rb_parent_environment )	{
	
	RPDB_Environment*		c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_replication_controller	=	RUBY_RPDB_REPLICATION_CONTROLLER( RPDB_ReplicationController_new( c_parent_environment ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_environment;
	
	rb_obj_call_init(	rb_replication_controller,
					 1, 
					 argv );
	
	return rb_replication_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_ReplicationController_init(	VALUE	rb_replication_controller,
																					VALUE	rb_parent_environment __attribute__ ((unused )) )	{

	return rb_replication_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_ReplicationController_settingsController(	VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	return RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( RPDB_ReplicationController_settingsController( c_replication_controller ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_ReplicationController_parentEnvironment(	VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_ReplicationController_parentEnvironment( c_replication_controller ) );

}

/*************************
*  initReplicationID  *
*************************/

//	We need to keep a track of existing replication environments and assign each of them a unique ID
//	Each replication controller needs unique IDs for every environment with which it replicates;
//	multiple environmental replication controllers may have different unique IDs for the same remote environments.
//	So A may see B, C, D wheras B might refer to A, C, D as E, F, G. This is acceptable, but not required.
VALUE rb_RPDB_ReplicationController_initReplicationID(	VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	return INT2FIX( RPDB_ReplicationController_initReplicationID( c_replication_controller ) );
}

/*************
*  start  *
*************/

//	In addition to specified message processing threads, the replication manager creates and manages a few of its own threads of control.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
VALUE rb_RPDB_ReplicationController_start(	VALUE	rb_replication_controller,
 											VALUE	rb_number_of_threads_for_message_processing	)	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPDB_ReplicationController_start(	c_replication_controller,
										FIX2INT( rb_number_of_threads_for_message_processing ) );
	
	return rb_replication_controller;
}

/*********************
*  processMessage  *
*********************/

//	If DB_ENV->rep_process_message method returns DB_REP_NOTPERM then the ret_lsnp parameter will contain the log sequence number 
//	of this permanent log message that could not be written to disk. If DB_ENV->rep_process_message method returns DB_REP_ISPERM 
//	then the ret_lsnp parameter will contain largest log sequence number of the permanent records that are now written to disk 
//	as a result of processing this message. In all other cases the value of ret_lsnp is undefined.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_message.html
VALUE rb_RPDB_ReplicationController_processMessage(	VALUE	rb_replication_controller,
 														VALUE	rb_control_record,
														VALUE	rb_replication_record	)	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPDB_Record*					c_control_record;
	C_RPDB_RECORD( rb_control_record, c_control_record );

	RPDB_Record*					c_replication_record;
	C_RPDB_RECORD( rb_replication_record, c_replication_record );

	RPDB_ReplicationController_processMessage(	c_replication_controller,
												c_control_record,
												c_replication_record );
	
	return rb_replication_controller;
}

/*************
*  sync  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_sync.html
VALUE rb_RPDB_ReplicationController_sync( VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPDB_ReplicationController_sync( c_replication_controller );

	return rb_replication_controller;
}

/*********************
*  callElection  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_elect.html
VALUE rb_RPDB_ReplicationController_callElection( VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPDB_ReplicationController_callElection( c_replication_controller );
	
	return rb_replication_controller;
}

/*********************
*  addRemoteSite  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_remote_site.html
VALUE rb_RPDB_ReplicationController_addRemoteSite(	VALUE	rb_replication_controller,
 													VALUE	remote_host,
													VALUE	remote_port	)	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPDB_ReplicationController_addRemoteSite(	c_replication_controller,
												StringValuePtr( remote_host ),
												FIX2INT( remote_port ) );

	return rb_replication_controller;
}

/*****************
*  siteList  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_site_list.html
VALUE rb_RPDB_ReplicationController_siteList( VALUE	rb_replication_controller )	{

	RPDB_ReplicationController*	c_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	//	FIX - return array
	
	RPDB_ReplicationController_siteList( c_replication_controller );
	
	return rb_replication_controller;
}

