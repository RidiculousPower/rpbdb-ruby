/*
 *		RPBDB::Database::DatabaseStatusController
 *
 *
 */

	#include "RPBDB_CompactInfo.h"
	#include "RPBDB_DatabaseMessageSettingsController.h"

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
	
RPBDB_DatabaseStatusController* RPBDB_DatabaseStatusController_new( VALUE database )	{

	RPBDB_DatabaseStatusController*		database_status_controller = calloc( 1, sizeof( RPBDB_DatabaseStatusController ) );

	database_status_controller->parent_database = database;

	return database_status_controller;
}

/*********************
*	 lastCompacted	 *
*********************/

//	Data about last compaction
RPBDB_CompactInfo* RPBDB_DatabaseStatusController_compacted( RPBDB_DatabaseStatusController* database_status_controller )	{

	return database_status_controller->compact_info;

}

VALUE rb_RPBDB_DatabaseStatusController_compacted( RPBDB_DatabaseStatusController* database_status_controller, VALUE last_compacted )	{

	database_status_controller->compact_info->last_compacted = last_compacted;
}

/*****************
*	 statistics	 *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_stat.html
VALUE rb_RPBDB_DatabaseStatusController_statistics( RPBDB_DatabaseStatusController* database_status_controller )	{

	DB*					database;
	VALUE				statistics;
	
	database = database_status_controller->parent_database;
	
	database->stat(	database,
					RPBDB_TransactionController_currentTransaction( RPBDB_Environment_transactionController( &( database->parent_environment ) ) ), 
					statistics, 
					RPBDB_DatabaseStatusController_internal_statisticsFlags( database_status_controller ) );
	return statistics;
}

/************************
*	 printStatistics	*
************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_stat.html
VALUE rb_RPBDB_DatabaseStatusController_printStatistics( RPBDB_DatabaseStatusController* database_status_controller )	{

	DB*					database;

	database = database_status_controller->parent_database;
	
	database->stat_print( database, RPBDB_DatabaseStatusController_internal_statisticsFlags( database_status_controller ) );
}

/*********************
*	 databaseFile	 *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_fd.html
//	File descriptor for underlying database
VALUE rb_RPBDB_DatabaseStatusController_databaseFile( RPBDB_DatabaseStatusController* database_status_controller )	{

	VALUE				file_descriptor;
	DB*					database;
	int*				file_descriptor_address;

	database = database_status_controller->parent_database;

	database->fd( database, &file_descriptor );

	//	Is this right for the pointer?
	file_descriptor = file_descriptor_address;
	
	return file_descriptor;
}

/*****************
*	 cacheFile	 *
*****************/

	//	Not sure what this was intended to be?
VALUE rb_RPBDB_DatabaseStatusController_cacheFile( RPBDB_DatabaseStatusController* database_status_controller )	{
	
}


/*****************
*	 statusMessageCallback	 *
*****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_msgcall.html
VALUE rb_RPBDB_DatabaseMessageSettingsController_statusMessageCallback( RPBDB_DatabaseMessageSettingsController* database_message_settings_controller )	{

	DB*					database;

	database = database_message_settings_controller->parent_settings_controller->parent_database;

	callback_method = void (*RPBDB_DatabaseMessageSettingsController_internal_callback)( const DB_ENV environment, VALUE message );

	database->set_msgcall( database, callback_function );
}
*/
/****************************
*	 callbackForProgress	*
****************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_feedback.html
VALUE rb_RPBDB_DatabaseMessageSettingsController_callbackForProgress( RPBDB_DatabaseMessageSettingsController* database_message_settings_controller )	{

	DB*					database;

	database = database_message_settings_controller->parent_settings_controller->parent_database;

	callback_method = void (*RPBDB_DatabaseMessageSettingsController_internal_callbackForProgress)( DB* database, VALUEoperation_code, VALUEpercent_progress );

	database->set_feedback( database, callback_function );
}
*/

/*************
*	 messageFile	 *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_msgfile.html
VALUE rb_RPBDB_DatabaseMessageSettingsController_messageFile( RPBDB_DatabaseMessageSettingsController* database_message_settings_controller )	{

	DB*					database;

	database = database_message_settings_controller->parent_settings_controller->parent_database->wrapped_bdb_database;

	if ( database_message_settings_controller->file == NULL )	{
		database->get_msgfile( database, &( database_message_settings_controller->file ) );
	}

	return database_message_settings_controller->file;
}

/*************
*	 setMessageFile	 *
*************/

//	Presumably this VALUE needs to be closed at some point?
VALUE rb_RPBDB_DatabaseMessageSettingsController_setMessageFile( RPBDB_DatabaseMessageSettingsController* database_message_settings_controller, VALUE file )	{

	DB*					database;

	database = database_message_settings_controller->parent_settings_controller->parent_database;

	database->set_msgfile( database, file );
}

/*************
*	 setMessageFileFromPath	 *
*************/

VALUE rb_RPBDB_DatabaseMessageSettingsController_setMessageFileFromPath( RPBDB_DatabaseMessageSettingsController* database_message_settings_controller, VALUE file_path )	{

	VALUE		file;

	file = fopen( file_path, 'w');

	if ( file == NULL )	{
		RPBDB_ErrorController_throwError(	database_message_settings_controller->parent_settings_controller->parent_database->parent_environment ),
										RP_ERROR_NO_FILE_AT_PATH,
										'RPBDB_DatabaseMessageSettingsController_file',
										'Could not open file at path.' )
		return;
	}

	RPBDB_DatabaseMessageSettingsController_setFile( database_message_settings_controller, file );
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*****************
*	 callback	 *
*****************/

VALUE rb_RPBDB_DatabaseMessageSettingsController_internal_callback( const DB_ENV environment, VALUE message )	{

}

/****************************
*	 callbackForProgress	*
****************************/

VALUE rb_RPBDB_DatabaseMessageSettingsController_internal_callbackForProgress( DB* database, VALUEoperation_code, VALUEpercent_progress )	{

}

/**************************
*	 statisticsFlags	  *
**************************/

VALUE rb_RPBDB_DatabaseStatusController_internal_statisticsFlags( RPBDB_DatabaseStatusController* database_status_controller )	{

}


	#include "RPBDB_TransactionController.h"
	#include "RPBDB_DatabaseMessageSettingsController.h"
	#include "RPBDB_ErrorController.h"
	#include "RPBDB_CompactInfo.h"

	#include "RPBDB_DatabaseStatusController_internal.h"
	#include "RPBDB_DatabaseMessageSettingsController_internal.h"

/***************************
*			free			*
***************************/
VALUE rb_RPBDB_DatabaseStatusController_free(	RPBDB_DatabaseStatusController* database_status_controller )	{

/***************************
*	settingsController	*
***************************/
RPBDB_DatabaseStatusSettingsController* RPBDB_DatabaseStatusController_settingsController(	RPBDB_DatabaseStatusController* database_status_controller )	{
	return database_status_controller->settings_controller;
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_DatabaseStatusController_parentEnvironment(	RPBDB_DatabaseStatusSettingsController* database_status_controller )	{
	return database_status_controller->environment_settings_controller;
}

