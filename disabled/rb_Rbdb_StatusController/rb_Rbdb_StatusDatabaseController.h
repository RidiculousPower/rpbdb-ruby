/*
* (databases_array) all (implied)
- (databases_array) active
- (databases_array) inactive		
*/

#include "RPBDB_Database.h"

RPBDB_StatusDatabaseController* RPBDB_StatusDatabaseController_new()	{
	
	RPBDB_StatusDatabaseController*		status_database_controller = calloc( 1, sizeof( RPBDB_StatusDatabaseController ) );

	//	Not much that we have to do here - controllers will be lazy-loaded
	return status_database_controller;
}

VALUE rb_RPBDB_StatusDatabaseController_all( RPBDB *self )	{
	
}

VALUE rb_RPBDB_StatusDatabaseController_active( RPBDB *self )	{
	
}

VALUE rb_RPBDB_StatusDatabaseController_inactive( RPBDB *self )	{
	
}	


	#include "RPBDB_Database.h"


/***************************
*			free			*
***************************/
VALUE rb_RPBDB_StatusDatabaseController_free(	RPBDB_StatusDatabaseController* status_database_controller )	{

/***************************
*	settingsController	*
***************************/
RPBDB_StatusDatabaseSettingsController* RPBDB_StatusDatabaseController_settingsController(	RPBDB_StatusDatabaseController* status_database_controller )	{
	return status_database_controller->settings_controller;
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_StatusDatabaseController_parentEnvironment(	RPBDB_StatusDatabaseSettingsController* status_database_controller )	{
	return status_database_controller->environment_settings_controller;
}

