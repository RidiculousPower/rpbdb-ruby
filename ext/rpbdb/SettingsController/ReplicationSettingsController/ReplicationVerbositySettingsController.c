/*
 *		RPbdb::SettingsController::SettingsVerbosityController::SettingsVerbosityReplicationController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "ReplicationVerbositySettingsController.h"
#include "ReplicationSettingsController.h"
#include "SettingsController.h"

#include "Environment.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/ReplicationVerbositySettingsController.h>
#include <rpbdb/ReplicationSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_ThreadSettingsController;

extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_ReplicationSettingsController;
extern	VALUE	rb_RPbdb_ReplicationVerbositySettingsController;

void Init_rb_RPbdb_ReplicationVerbositySettingsController()	{

	rb_RPbdb_ReplicationVerbositySettingsController		=	rb_define_class_under(	rb_RPbdb_ReplicationSettingsController, 
																																							"Verbosity",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_ReplicationVerbositySettingsController, 	"new",																rb_RPbdb_ReplicationVerbositySettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"initialize",													rb_RPbdb_ReplicationVerbositySettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"parent_environment",									rb_RPbdb_ReplicationVerbositySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_ReplicationVerbositySettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController,					"parent_settings_controller",					rb_RPbdb_ReplicationVerbositySettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController,					"parent_replication_settings_controller",					rb_RPbdb_ReplicationVerbositySettingsController_parentReplicationSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_all_replication_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayAllReplicationInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_all_replication_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_all_replication_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_election_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayElectionInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_election_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_election_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_replication_master_lease_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayReplicationMasterLeaseInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_replication_master_lease_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_replication_master_lease_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_misc_processing_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayMiscProcessingInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_misc_processing_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_misc_processing_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_message_processing_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayMessageProcessingInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_message_processing_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_message_processing_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_client_synchronization_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayClientSynchronizationInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_client_synchronization_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_client_synchronization_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_manager_connection_failure_information?",														rb_RPbdb_ReplicationVerbositySettingsController_displayManagerConnectionFailureInformation,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_manager_connection_failure_information_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_manager_connection_failure_information_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOff,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"display_manager_misc_processing?",														rb_RPbdb_ReplicationVerbositySettingsController_displayManagerMiscProcessing,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_manager_misc_processing_on",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOn,													0 	);
	rb_define_method(			rb_RPbdb_ReplicationVerbositySettingsController, 				"turn_display_manager_misc_processing_off",														rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_ReplicationVerbositySettingsController_new(	int			argc,
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
			&&	rb_parent_settings_controller == Qnil )	{			

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

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller	=	RPbdb_ReplicationSettingsController_verbositySettingsController( c_parent_replication_settings_controller );

	VALUE	rb_replication_verbosity_settings_controller	= RUBY_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( c_replication_verbosity_settings_controller );

	rb_iv_set(	rb_replication_verbosity_settings_controller,
							RPBDB_RB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER,
							rb_parent_replication_settings_controller );

	VALUE	argv[]	=	{ rb_parent_replication_settings_controller };
	rb_obj_call_init(	rb_replication_verbosity_settings_controller,
										 1, 
										 argv );
	
	return rb_replication_verbosity_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_ReplicationVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_ReplicationVerbositySettingsController_parentEnvironment(	VALUE	rb_replication_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_ReplicationVerbositySettingsController_parentSettingsController( rb_replication_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_ReplicationVerbositySettingsController_parentSettingsController(	VALUE	rb_replication_verbosity_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller		=	rb_RPbdb_ReplicationVerbositySettingsController_parentReplicationSettingsController( rb_replication_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_RPbdb_ReplicationSettingsController_parentSettingsController( rb_parent_replication_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_replication_settings_controller  *
*******************************************/

VALUE rb_RPbdb_ReplicationVerbositySettingsController_parentReplicationSettingsController(	VALUE	rb_replication_verbosity_settings_controller )	{

	VALUE	rb_parent_replication_settings_controller	=	rb_iv_get(	rb_replication_verbosity_settings_controller,
																																RPBDB_RB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER );

	return rb_parent_replication_settings_controller;
}

/*****************************************
*  display_all_replication_information?  *
*****************************************/

//	DB_VERB_REPLICATION     	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayAllReplicationInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayAllReplicationInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/************************************************
	*  turn_display_all_replication_information_on  *
	************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOn( c_replication_verbosity_settings_controller );
		
		return rb_replication_verbosity_settings_controller;
	}

	/*************************************************
	*  turn_display_all_replication_information_off  *
	*************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{
		
		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayAllReplicationInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/**********************************
*  display_election_information?  *
**********************************/

//	DB_VERB_REP_ELECT    		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayElectionInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayElectionInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/*****************************************
	*  turn_display_election_information_on  *
	*****************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/******************************************
	*  turn_display_election_information_off  *
	******************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayElectionInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/**************************************************
*  display_replication_master_lease_information?  *
**************************************************/

//	DB_VERB_REP_LEASE       	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayReplicationMasterLeaseInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayReplicationMasterLeaseInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/*********************************************************
	*  turn_display_replication_master_lease_information_on  *
	*********************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/**********************************************************
	*  turn_display_replication_master_lease_information_off  *
	**********************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayReplicationMasterLeaseInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/*****************************************
*  display_misc_processing_information?  *
*****************************************/

//	DB_VERB_REP_MISC        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayMiscProcessingInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayMiscProcessingInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/************************************************
	*  turn_display_misc_processing_information_on  *
	************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/*************************************************
	*  turn_display_misc_processing_information_off  *
	*************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayMiscProcessingInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/********************************************
*  display_message_processing_information?  *
********************************************/

//	DB_VERB_REP_MSGS        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayMessageProcessingInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayMessageProcessingInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/***************************************************
	*  turn_display_message_processing_information_on  *
	***************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/****************************************************
	*  turn_display_message_processing_information_off  *
	****************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayMessageProcessingInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/************************************************
*  display_client_synchronization_information?  *
************************************************/

//	DB_VERB_REP_SYNC        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayClientSynchronizationInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayClientSynchronizationInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/*******************************************************
	*  turn_display_client_synchronization_information_on  *
	*******************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/********************************************************
	*  turn_display_client_synchronization_information_off  *
	********************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
														
		RPbdb_ReplicationVerbositySettingsController_turnDisplayClientSynchronizationInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/****************************************************
*  display_manager_connection_failure_information?  *
****************************************************/

//	DB_VERB_REPMGR_CONNFAIL 	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayManagerConnectionFailureInformation( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
	return ( RPbdb_ReplicationVerbositySettingsController_displayManagerConnectionFailureInformation( c_replication_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/***********************************************************
	*  turn_display_manager_connection_failure_information_on  *
	***********************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );
													
		RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/************************************************************
	*  turn_display_manager_connection_failure_information_off  *
	************************************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );

		RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerConnectionFailureInformationOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

/*************************************
*  display_manager_misc_processing?  *
*************************************/

//	DB_VERB_REPMGR_MISC     	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_ReplicationVerbositySettingsController_displayManagerMiscProcessing( VALUE	rb_replication_verbosity_settings_controller )	{

	RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
	C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );

	return ( RPbdb_ReplicationVerbositySettingsController_displayManagerMiscProcessing( c_replication_verbosity_settings_controller )	?	Qtrue
																																																																		:	Qfalse );
}

	/********************************************
	*  turn_display_manager_misc_processing_on  *
	********************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOn( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );

		RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOn( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}

	/*********************************************
	*  turn_display_manager_misc_processing_off  *
	*********************************************/

	VALUE rb_RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOff( VALUE	rb_replication_verbosity_settings_controller )	{

		RPbdb_ReplicationVerbositySettingsController*	c_replication_verbosity_settings_controller;
		C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller );

		RPbdb_ReplicationVerbositySettingsController_turnDisplayManagerMiscProcessingOff( c_replication_verbosity_settings_controller );

		return rb_replication_verbosity_settings_controller;
	}
