/*
 *		RPbdb::ReplicationController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "Record.h"
#include "ReplicationController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/ReplicationController.h>

#include <rpbdb/ReplicationSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;

extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_ReplicationController;
extern	VALUE	rb_RPbdb_DatabaseReplicationSettingsController;
extern	VALUE	rb_RPbdb_ReplicationSettingsController;

void Init_rb_RPbdb_ReplicationController()	{

	rb_RPbdb_ReplicationController		=	rb_define_class_under(	rb_RPbdb_Environment, 
																														"ReplicationController", 		
																														rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_ReplicationController, 	"new",											rb_RPbdb_ReplicationController_new,												-1 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"initialize",								rb_RPbdb_ReplicationController_initialize,												-1 	);
                                                                          
	rb_define_method(						rb_RPbdb_ReplicationController, 	"settings_controller",			rb_RPbdb_ReplicationController_settingsController,					0 	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"settings",									"settings_controller"	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"set",											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"set_to",										"settings_controller"	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"is_set_to",								"settings_controller"	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"parent_environment",				rb_RPbdb_ReplicationController_parentEnvironment,					0 	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"environment",							"parent_environment"	);
                                                                          
	rb_define_method(						rb_RPbdb_ReplicationController, 	"init_replication_id",			rb_RPbdb_ReplicationController_initReplicationID,					0 	);
	rb_define_alias(						rb_RPbdb_ReplicationController, 	"init_id",									"init_replication_id"	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"start",										rb_RPbdb_ReplicationController_start,											0 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"process_message",					rb_RPbdb_ReplicationController_processMessage,							0 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"sync",											rb_RPbdb_ReplicationController_sync,												0 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"call_election",						rb_RPbdb_ReplicationController_callElection,								0 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"add_remote_site",					rb_RPbdb_ReplicationController_addRemoteSite,							0 	);
	rb_define_method(						rb_RPbdb_ReplicationController, 	"site_list",								rb_RPbdb_ReplicationController_siteList,										0 	);


}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_ReplicationController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);
	
	RPbdb_Environment*		c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_replication_controller	=	RUBY_RPBDB_REPLICATION_CONTROLLER( RPbdb_ReplicationController_new( c_parent_environment ) );

	//	store reference to parent
	rb_iv_set(	rb_replication_controller,
							RPBDB_RB_REPLICATION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_replication_controller,
										 1, 
										 argv );
	
	return rb_replication_controller;		
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_ReplicationController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_ReplicationController_settingsController(	VALUE	rb_replication_controller )	{

	VALUE	rb_local_replication_settings_controller	=	Qnil;
	
	if ( ( rb_local_replication_settings_controller = rb_iv_get(	rb_replication_controller,
																																RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_ReplicationController*		c_replication_controller;
		C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );
	
		RPbdb_ReplicationSettingsController*	c_local_replication_settings_controller	=	RPbdb_ReplicationController_settingsController( c_replication_controller );

		rb_local_replication_settings_controller	=	RUBY_RPBDB_REPLICATION_SETTINGS_CONTROLLER( c_local_replication_settings_controller );

		rb_iv_set(	rb_replication_controller,
								RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER,
								rb_local_replication_settings_controller );
	}

	return rb_local_replication_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_ReplicationController_parentEnvironment(	VALUE	rb_replication_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_replication_controller,
																						RPBDB_RB_REPLICATION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );

	return rb_parent_environment;
}

/*************************
*  initReplicationID  *
*************************/

//	We need to keep a track of existing replication environments and assign each of them a unique ID
//	Each replication controller needs unique IDs for every environment with which it replicates;
//	multiple environmental replication controllers may have different unique IDs for the same remote environments.
//	So A may see B, C, D wheras B might refer to A, C, D as E, F, G. This is acceptable, but not required.
VALUE rb_RPbdb_ReplicationController_initReplicationID(	VALUE	rb_replication_controller )	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	return INT2FIX( RPbdb_ReplicationController_initReplicationID( c_replication_controller ) );
}

/*************
*  start  *
*************/

//	In addition to specified message processing threads, the replication manager creates and manages a few of its own threads of control.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_start.html
VALUE rb_RPbdb_ReplicationController_start(	VALUE	rb_replication_controller,
 											VALUE	rb_number_of_threads_for_message_processing	)	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPbdb_ReplicationController_start(	c_replication_controller,
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
VALUE rb_RPbdb_ReplicationController_processMessage(	VALUE	rb_replication_controller,
 														VALUE	rb_control_record,
														VALUE	rb_replication_record	)	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPbdb_Record*					c_control_record;
	C_RPBDB_RECORD( rb_control_record, c_control_record );

	RPbdb_Record*					c_replication_record;
	C_RPBDB_RECORD( rb_replication_record, c_replication_record );

	RPbdb_ReplicationController_processMessage(	c_replication_controller,
												c_control_record,
												c_replication_record );
	
	return rb_replication_controller;
}

/*************
*  sync  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_sync.html
VALUE rb_RPbdb_ReplicationController_sync( VALUE	rb_replication_controller )	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPbdb_ReplicationController_sync( c_replication_controller );

	return rb_replication_controller;
}

/*********************
*  callElection  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/rep_elect.html
VALUE rb_RPbdb_ReplicationController_callElection( VALUE	rb_replication_controller )	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPbdb_ReplicationController_callElection( c_replication_controller );
	
	return rb_replication_controller;
}

/*********************
*  addRemoteSite  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_remote_site.html
VALUE rb_RPbdb_ReplicationController_addRemoteSite(	VALUE	rb_replication_controller,
 													VALUE	remote_host,
													VALUE	remote_port	)	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	RPbdb_ReplicationController_addRemoteSite(	c_replication_controller,
												StringValuePtr( remote_host ),
												FIX2INT( remote_port ) );

	return rb_replication_controller;
}

/*****************
*  siteList  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/repmgr_site_list.html
VALUE rb_RPbdb_ReplicationController_siteList( VALUE	rb_replication_controller )	{

	RPbdb_ReplicationController*	c_replication_controller;
	C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller );

	//	FIX - return array
	
	RPbdb_ReplicationController_siteList( c_replication_controller );
	
	return rb_replication_controller;
}

