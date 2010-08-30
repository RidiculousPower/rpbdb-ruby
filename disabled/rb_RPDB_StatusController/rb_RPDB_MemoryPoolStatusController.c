/*
- statistics																	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_stat.html
*/

	#include "RPBDB_MemoryPoolStatistics.h"
	#include "RPBDB_MemoryPoolFileController.h"

RPBDB_MemoryPoolStatusController* RPBDB_MemoryPoolStatusController_new()	{
	
	RPBDB_MemoryPoolStatusController*		memory_pool_status_controller = calloc( 1, sizeof( RPBDB_MemoryPoolStatusController ) );

	return memory_pool_status_controller;
}

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_stat.html
RPBDB_MemoryPoolStatistics* RPBDB_Environment_memoryPoolStatusController( RPBDB *self )	{
	
}

/*************
*	 file	 *
*************/

VALUE rb_RPBDB_MemoryPoolSettingsController_file( VALUE memory_pool_settings_controller )	{
	RPBDB_MemoryPoolSettingsController_file();

}

	#include "RPBDB_Environment.h"
	#include "RPBDB_MemoryPoolSettingsController.h"
	#include "RPBDB_MemoryPoolStatistics.h"
	#include "RPBDB_MemoryPoolFileController.h"


/***************************
*			free			*
***************************/
VALUE rb_RPBDB_MemoryPoolStatusController_free(	RPBDB_MemoryPoolStatusController* memory_pool_status_controller )	{

/***************************
*	settingsController	*
***************************/
RPBDB_MemoryPoolStatusSettingsController* RPBDB_MemoryPoolStatusController_settingsController(	RPBDB_MemoryPoolStatusController* memory_pool_status_controller )	{
	return memory_pool_status_controller->settings_controller;
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_MemoryPoolStatusController_parentEnvironment(	RPBDB_MemoryPoolStatusSettingsController* memory_pool_status_controller )	{
	return memory_pool_status_controller->environment_settings_controller;
}

