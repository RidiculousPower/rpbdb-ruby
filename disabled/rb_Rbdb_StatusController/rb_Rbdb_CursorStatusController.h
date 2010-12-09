/*
- (true_or_false) open                                              		
- (true_or_false) closed                                            		
- (true_or_false) hasError
- (error) error
*/
/*
* (cursors_array) all (implied)
- (cursors_array) active
- (cursors_array) inactive
*/

	#include "RPBDB_DatabaseCursorStatusController.h"
	#include "RPBDB_DatabaseCursor.h"

RPBDB_DatabaseCursorStatusController* RPBDB_DatabaseCursorStatusController_new()	{
	
	RPBDB_DatabaseCursorStatusController*		cursor_status_controller = calloc( 1, sizeof( RPBDB_DatabaseCursorStatusController ) );

	return cursor_status_controller;
}

VALUE rb_RPBDB_DatabaseCursorStatusController_active( RPBDB_DatabaseCursorStatusController* cursor_status_controller )	{

	//	Ask database controller for all open database cursors
}

VALUE rb_RPBDB_DatabaseCursorStatusController_inactive( RPBDB_DatabaseCursorStatusController* cursor_status_controller )	{
	
	//	Ask database controller for all database cursors that have been opened and then closed (but not freed)
}

VALUE rb_RPBDB_DatabaseCursorStatusController_hasError( RPBDB_DatabaseCursorStatusController* cursor_status_controller )	{
	
	//	Ask database controller for all database cursors that have errors 
}

	#include "RPBDB_DatabaseCursorStatusController.h"
	#include "RPBDB_DatabaseCursor.h"


/***************************
*			free			*
***************************/
VALUE rb_RPBDB_CursorStatusController_free(	RPBDB_CursorStatusController* cursor_status_controller )	{

/***************************
*	settingsController	*
***************************/
RPBDB_CursorStatusSettingsController* RPBDB_CursorStatusController_settingsController(	RPBDB_CursorStatusController* cursor_status_controller )	{
	return cursor_status_controller->settings_controller;
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_CursorStatusController_parentEnvironment(	RPBDB_CursorStatusSettingsController* cursor_status_controller )	{
	return cursor_status_controller->environment_settings_controller;
}

