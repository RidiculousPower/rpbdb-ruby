/*
 *		RPBDB::StatusController
 *
 *
 */

	#include "RPBDB_Statistics.h"

	/****************
	*	Prototypes	*
	****************/

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*	 new	 *
*************/

RPBDB_StatusController* RPBDB_StatusController_new()	{

	RPBDB_StatusController*		status_controller = calloc( 1, sizeof( RPBDB_StatusController ) );

	return status_controller;
}



/******************
*	 statistics	  *
******************/

//	Requires specification of output using either:
//
//	* RPBDB.settingsController.messageController.callback
//	* RPBDB.settingsController.messageController.file
//
//	If this method is called and neither file or callback have been set, file will temporarily be set to stdout.
//	After output, file will be set back to NULL.
//
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_stat.html
RPBDB_Statistics* RPBDB_StatusController_statistics( RPBDB_StatusController* status_controller )	{

	VALUE			temporarily_set_stdout;

	//	If there isn't a file set for statistics we want to set it to stdout
	if ( ! RPBDB_MessageSettingsController_file( RPBDB_SettingsController_messageSettingsController( RPBDB_Environment_settingsController( status_controller->parent_environment ) ) ) ) )

		RPBDB_MessageSettingsController_file( RPBDB_SettingsController_messageSettingsController( RPBDB_Environment_settingsController( status_controller->parent_environment ) ) ), stdout );

		temporarily_set_stdout = TRUE;
	}

	status_controller->parent_environment->wrapped_bdb_environment->stat_print(	&( status_controller->parent_environment->wrapped_bdb_environment ), 
																			RPBDB_MessageSettingsController_file(	
																				RPBDB_SettingsController_messageSettingsController( 
																					RPBDB_Environment_settingsController( status_controller->parent_environment ) ) ) );

	if ( temporarily_set_stdout )	{

		RPBDB_MessageSettingsController_file( RPBDB_SettingsController_messageController( RPBDB_Environment_settingsController( status_controller->parent_environment ) ) ), NULL )	{
	}
}

/*****************************
*	 checkForThreadFailure	 *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_failchk.html
VALUE rb_RPBDB_StatusController_checkForThreadFailure( RPBDB_StatusController* status_controller )	{
	status_controller->parent_environment->failchk( &( status_controller->parent_environment->wrapped_bdb_environment ), 0 );
}




	#include "RPBDB_MessageSettingsController.h"
	#include "RPBDB_SettingsController.h"
	#include "RPBDB_Environment.h"
	#include "RPBDB_Statistics.h"


/***************************
*			free			*
***************************/
VALUE rb_RPBDB_StatusController_free(	RPBDB_StatusController* status_controller )	{

/***************************
*	settingsController	*
***************************/
VALUE rb_RPBDB_StatusController_settingsController(	RPBDB_StatusController* status_controller )	{
	return status_controller->settings_controller;
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_StatusController_parentEnvironment(	VALUE status_controller )	{
	RPBDB_StatusController_parentEnvironment();
	return status_controller->environment_settings_controller;
}

