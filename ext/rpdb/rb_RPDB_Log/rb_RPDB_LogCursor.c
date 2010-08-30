/*
 *		RPDB::LogController::LogCursorController::LogCursor
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_LogCursor.h"
#include "rb_RPDB_LogCursorController.h"
#include "rb_RPDB_LogSequenceNumber.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_LogSettingsController.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_LogCursor.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_LogCursor;
extern	VALUE	rb_RPDB_LogCursorController;
extern	VALUE	rb_RPDB_LogSettingsController;
extern	VALUE	rb_RPDB_LogSequenceNumber;
extern	VALUE	rb_RPDB_Record;

void Init_RPDB_LogCursor()	{

	rb_RPDB_LogCursor	=	rb_define_class_under(	rb_RPDB_Environment, 
																										"LogCursor",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LogCursor, 	"new",																													rb_RPDB_LogCursor_new,														-1 	);
	rb_define_method(						rb_RPDB_LogCursor, 	"initialize",																										rb_RPDB_LogCursor_init,														-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_LogCursor, 	"settings_controller",																					rb_RPDB_LogCursor_settingsController,												0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"parent_environment",																						rb_RPDB_LogCursor_parentEnvironment,							0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPDB_LogCursor, 	"open",																													rb_RPDB_LogCursor_open,														0 	);
	rb_define_method(						rb_RPDB_LogCursor, 	"close",																												rb_RPDB_LogCursor_close,													0 	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_current",																							rb_RPDB_LogCursor_retrieveCurrentLogRecord,				0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"current",																											"retrieve_current"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_first",																								rb_RPDB_LogCursor_retrieveFirstLogRecord,					0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"first",																												"retrieve_first"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_last",																								rb_RPDB_LogCursor_retrieveLastLogRecord,					0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"last",																													"retrieve_last"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_next",																								rb_RPDB_LogCursor_retrieveNextLogRecord,					0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"next",																													"retrieve_next"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_previous",																						rb_RPDB_LogCursor_retrievePreviousLogRecord,			0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"previous",																											"retrieve_previous"	);
	rb_define_method(						rb_RPDB_LogCursor, 	"retrieve_log",																									rb_RPDB_LogCursor_retrieveLogRecord,							0 	);
	rb_define_alias(						rb_RPDB_LogCursor, 	"retrieve",																											"retrieve_log"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/


/*************
*  new  *
*************/

VALUE rb_RPDB_LogCursor_new(	VALUE	klass __attribute__ ((unused)),
															VALUE	rb_parent_log_cursor_controller )	{
	
	RPDB_LogCursorController*	c_parent_log_cursor_controller;
	C_RPDB_LOG_CURSOR_CONTROLLER( rb_parent_log_cursor_controller, c_parent_log_cursor_controller );
	
	VALUE	rb_log_cursor	=	RUBY_RPDB_LOG_CURSOR( RPDB_LogCursor_new( c_parent_log_cursor_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_log_cursor_controller;
	
	rb_obj_call_init(	rb_log_cursor,
					 1, 
					 argv );
	
	return rb_log_cursor;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_LogCursor_init(	VALUE	rb_log_cursor,
															VALUE	rb_parent_log_cursor_controller __attribute__ ((unused)) )	{
	

	return rb_log_cursor;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_LogCursor_settingsController(	VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_LOG_SETTINGS_CONTROLLER( RPDB_LogCursor_settingsController( c_log_cursor ) );
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_LogCursor_parentEnvironment(	VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_ENVIRONMENT( RPDB_LogCursor_parentEnvironment( c_log_cursor ) );
}

/*************
*  open  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_cursor.html
VALUE rb_RPDB_LogCursor_open( VALUE	rb_log_cursor )	{
	
	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );
	
	RPDB_LogCursor_open( c_log_cursor );
	
	return rb_log_cursor;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/logc_close.html
VALUE rb_RPDB_LogCursor_close( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );
	
	RPDB_LogCursor_close( c_log_cursor );

	return rb_log_cursor;
}

/*********************************
*  retrieveCurrentLogRecord  *
*********************************/

VALUE rb_RPDB_LogCursor_retrieveCurrentLogRecord( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrieveCurrentLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveFirstLogRecord  *
*****************************/

VALUE rb_RPDB_LogCursor_retrieveFirstLogRecord( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrieveFirstLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveLastLogRecord  *
*****************************/

VALUE rb_RPDB_LogCursor_retrieveLastLogRecord( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrieveLastLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveNextLogRecord  *
*****************************/

VALUE rb_RPDB_LogCursor_retrieveNextLogRecord( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrieveNextLogRecord( c_log_cursor ) );
}

/*********************************
*  retrievePreviousLogRecord  *
*********************************/

VALUE rb_RPDB_LogCursor_retrievePreviousLogRecord( VALUE	rb_log_cursor )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrievePreviousLogRecord( c_log_cursor ) );
}

/*************************
*  retrieveLogRecord  *
*************************/

VALUE rb_RPDB_LogCursor_retrieveLogRecord(	VALUE	rb_log_cursor,
											VALUE	rb_log_sequence_number )	{

	RPDB_LogCursor*	c_log_cursor;
	C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	RPDB_LogSequenceNumber*	c_log_sequence_number;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	return RUBY_RPDB_RECORD( RPDB_LogCursor_retrieveLogRecord(	c_log_cursor,
								 									c_log_sequence_number	) );
}
