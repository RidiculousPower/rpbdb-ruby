/*
 *		RPbdb::LogController::LogCursorController::LogCursor
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "LogCursor.h"
#include "LogCursorController.h"
#include "LogController.h"
#include "LogSequenceNumber.h"

#include <rpbdb/Environment.h>

#include <rpbdb/LogSettingsController.h>

#include <rpbdb/Record.h>

#include <rpbdb/LogCursor.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_LogCursor;
extern	VALUE	rb_RPbdb_LogCursorController;
extern	VALUE	rb_RPbdb_LogController;
extern	VALUE	rb_RPbdb_LogSettingsController;
extern	VALUE	rb_RPbdb_LogSequenceNumber;
extern	VALUE	rb_RPbdb_Record;

void Init_rb_RPbdb_LogCursor()	{

	rb_RPbdb_LogCursor	=	rb_define_class_under(	rb_RPbdb_Environment, 
																										"LogCursor",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_LogCursor, 	"new",																													rb_RPbdb_LogCursor_new,														-1 	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"initialize",																										rb_RPbdb_LogCursor_initialize,														-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_LogCursor, 	"settings_controller",																					rb_RPbdb_LogCursor_settingsController,												0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"parent_environment",																						rb_RPbdb_LogCursor_parentEnvironment,							0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_LogCursor, 	"open",																													rb_RPbdb_LogCursor_open,														0 	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"close",																												rb_RPbdb_LogCursor_close,													0 	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_current",																							rb_RPbdb_LogCursor_retrieveCurrentLogRecord,				0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"current",																											"retrieve_current"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_first",																								rb_RPbdb_LogCursor_retrieveFirstLogRecord,					0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"first",																												"retrieve_first"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_last",																								rb_RPbdb_LogCursor_retrieveLastLogRecord,					0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"last",																													"retrieve_last"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_next",																								rb_RPbdb_LogCursor_retrieveNextLogRecord,					0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"next",																													"retrieve_next"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_previous",																						rb_RPbdb_LogCursor_retrievePreviousLogRecord,			0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"previous",																											"retrieve_previous"	);
	rb_define_method(						rb_RPbdb_LogCursor, 	"retrieve_log",																									rb_RPbdb_LogCursor_retrieveLogRecord,							0 	);
	rb_define_alias(						rb_RPbdb_LogCursor, 	"retrieve",																											"retrieve_log"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/


/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LogCursor_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	VALUE	rb_parent_log_cursor_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_RPbdb_LogController ),
																						R_MatchAncestorInstance( rb_parent_log_cursor_controller, rb_RPbdb_LogCursorController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]",
			"[ <parent log cursor controller> ]"
		)
	);
	
	RPbdb_LogCursorController*	c_parent_log_cursor_controller;
	C_RPBDB_LOG_CURSOR_CONTROLLER( rb_parent_log_cursor_controller, c_parent_log_cursor_controller );
	
	VALUE	rb_log_cursor	=	RUBY_RPBDB_LOG_CURSOR( RPbdb_LogCursor_new( c_parent_log_cursor_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_log_cursor,
							RPBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER,
							rb_parent_log_controller );

	VALUE	argv[]	=	{ rb_parent_log_cursor_controller };
	rb_obj_call_init(	rb_log_cursor,
					 1, 
					 argv );
	
	return rb_log_cursor;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LogCursor_initialize(	int				argc __attribute__ ((unused)),
															VALUE*		args __attribute__ ((unused)),
															VALUE			rb_self )	{
	

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_LogCursor_settingsController(	VALUE	rb_log_cursor )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_cursor,
																												RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_LogCursor*		c_log_cursor;
		C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );
	
		RPbdb_LogSettingsController*	c_local_log_settings_controller	=	RPbdb_LogCursor_settingsController( c_log_cursor );

		rb_local_log_settings_controller	=	RUBY_RPBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_cursor,
								RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_LogCursor_parentEnvironment(	VALUE	rb_log_cursor )	{

	VALUE	rb_parent_log_controller	=	rb_RPbdb_LogCursor_parentLogController( rb_log_cursor );
	VALUE	rb_parent_environment			=	rb_RPbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;	
}

/***************************************
*  parent_log_controller  *
***************************************/
VALUE rb_RPbdb_LogCursor_parentLogController(	VALUE	rb_log_cursor )	{

	VALUE	rb_parent_log_cursor_controller	=	rb_RPbdb_LogCursor_parentLogCursorController( rb_log_cursor );
	VALUE	rb_parent_log_controller				=	rb_RPbdb_LogCursorController_parentLogController( rb_parent_log_cursor_controller );
	
	return rb_parent_log_controller;
}

/***************************************
*  parent_log_cursor_controller  *
***************************************/
VALUE rb_RPbdb_LogCursor_parentLogCursorController(	VALUE	rb_log_cursor )	{
	
	VALUE	rb_parent_log_cursor_controller	=	rb_iv_get(	rb_log_cursor,
																											RPBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER );
	return rb_parent_log_cursor_controller;
}

/*************
*  open  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_cursor.html
VALUE rb_RPbdb_LogCursor_open( VALUE	rb_log_cursor )	{
	
	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );
	
	RPbdb_LogCursor_open( c_log_cursor );
	
	return rb_log_cursor;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/logc_close.html
VALUE rb_RPbdb_LogCursor_close( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );
	
	RPbdb_LogCursor_close( c_log_cursor );

	return rb_log_cursor;
}

/*********************************
*  retrieveCurrentLogRecord  *
*********************************/

VALUE rb_RPbdb_LogCursor_retrieveCurrentLogRecord( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrieveCurrentLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveFirstLogRecord  *
*****************************/

VALUE rb_RPbdb_LogCursor_retrieveFirstLogRecord( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrieveFirstLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveLastLogRecord  *
*****************************/

VALUE rb_RPbdb_LogCursor_retrieveLastLogRecord( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrieveLastLogRecord( c_log_cursor ) );
}

/*****************************
*  retrieveNextLogRecord  *
*****************************/

VALUE rb_RPbdb_LogCursor_retrieveNextLogRecord( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrieveNextLogRecord( c_log_cursor ) );
}

/*********************************
*  retrievePreviousLogRecord  *
*********************************/

VALUE rb_RPbdb_LogCursor_retrievePreviousLogRecord( VALUE	rb_log_cursor )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrievePreviousLogRecord( c_log_cursor ) );
}

/*************************
*  retrieveLogRecord  *
*************************/

VALUE rb_RPbdb_LogCursor_retrieveLogRecord(	VALUE	rb_log_cursor,
											VALUE	rb_log_sequence_number )	{

	RPbdb_LogCursor*	c_log_cursor;
	C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor );

	RPbdb_LogSequenceNumber*	c_log_sequence_number;
	C_RPBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	return RUBY_RPBDB_RECORD( RPbdb_LogCursor_retrieveLogRecord(	c_log_cursor,
								 									c_log_sequence_number	) );
}
