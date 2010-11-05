/*
 *		RPDB::LogController::Log
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB.h"
#include "rb_RPDB_Log.h"
#include "rb_RPDB_LogController.h"
#include "rb_RPDB_LogCursorController.h"
#include "rb_RPDB_LogCursor.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_Log.h>
#include <rpdb/RPDB_LogCursor.h>
#include <rpdb/RPDB_LogCursorController.h>
//#include <rpdb/RPDB_LogSequenceNumber.h>

#include <rpdb/RPDB_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Log;
extern	VALUE	rb_RPDB_LogController;
extern	VALUE	rb_RPDB_LogCursorController;
extern	VALUE	rb_RPDB_LogCursor;
extern	VALUE	rb_RPDB_LogSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_LogSequenceNumber;

void Init_RPDB_Log()	{

	rb_RPDB_Log	=	rb_define_class_under(		rb_RPDB_Environment, 
																					"Log",			
																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_Log, 	"new",																													rb_RPDB_Log_new,												-1 	);
	rb_define_method(						rb_RPDB_Log, 	"initialize",																										rb_RPDB_Log_init,											-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_Log, 	"settings_controller",																					rb_RPDB_Log_settingsController,				0 	);
	rb_define_alias(						rb_RPDB_Log, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_Log, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_Log, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_Log, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_Log, 	"parent_environment",																						rb_RPDB_Log_parentEnvironment,					0 	);
	rb_define_alias(						rb_RPDB_Log, 	"environment",																									"parent_environment"	);

	//	FIX - what's log_record? isn't that self?
	rb_define_method(						rb_RPDB_Log, 	"record",																												rb_RPDB_Log_logRecord,														0 	);
	rb_define_method(						rb_RPDB_Log, 	"sequence_number",																							rb_RPDB_Log_logSequenceNumber,										0 	);
	rb_define_alias(						rb_RPDB_Log, 	"lsn",																													"log_sequence_number"	);		
	rb_define_method(						rb_RPDB_Log, 	"filename",																											rb_RPDB_Log_filename,															0 	);
		
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_Log_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment							=	Qnil;
	VALUE	rb_parent_log_controller					=	Qnil;
	VALUE	rb_parent_log_cursor_controller		=	Qnil;
	VALUE	rb_parent_log_cursor							=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_RPDB_LogController ),
																						R_MatchAncestorInstance( rb_parent_log_cursor_controller, rb_RPDB_LogCursorController ),
																						R_MatchAncestorInstance( rb_parent_log_cursor, rb_RPDB_LogCursor ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]",
			"[ <parent log cursor controller> ]",
			"[ <parent log cursor> ]"
		)
	);
	
	RPDB_LogController*	c_parent_log_controller;
	C_RPDB_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log	=	RUBY_RPDB_LOG( RPDB_Log_new( c_parent_log_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_log,
							RPDB_RB_LOG_VARIABLE_PARENT_LOG_CURSOR,
							rb_parent_log_cursor );
	
	VALUE	argv[]	=	{ rb_parent_log_controller };
	rb_obj_call_init(	rb_log,
					 1, 
					 argv );
	
	return rb_log;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Log_init(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Log_settingsController(	VALUE	rb_log )	{
	
	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log,
																												RPDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Log*		c_log;
		C_RPDB_LOG( rb_log, c_log );
	
		RPDB_LogSettingsController*	c_local_log_settings_controller	=	RPDB_Log_settingsController( c_log );

		rb_local_log_settings_controller	=	RUBY_RPDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log,
								RPDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_Log_parentEnvironment(	VALUE	rb_log )	{

	VALUE	rb_parent_log_controller			=	rb_RPDB_Log_parentLogController( rb_log );
	VALUE	rb_parent_environment					=	rb_RPDB_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/
VALUE rb_RPDB_Log_parentLogController(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor_controller		=	rb_RPDB_Log_parentLogCursorController( rb_log );
	VALUE	rb_parent_log_controller					=	rb_RPDB_LogCursorController_parentLogController( rb_parent_log_cursor_controller );
	
	return rb_parent_log_controller;
}

/***************************************
*  parent_log_cursor_controller  *
***************************************/
VALUE rb_RPDB_Log_parentLogCursorController(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor							=	rb_RPDB_Log_parentLogCursor( rb_log );
	VALUE	rb_parent_log_cursor_controller		=	rb_RPDB_LogCursor_parentLogCursorController( rb_parent_log_cursor );
	
	return rb_parent_log_cursor_controller;
}

/***************************************
*  parent_log_cursor  *
***************************************/
VALUE rb_RPDB_Log_parentLogCursor(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor	=	rb_iv_get(	rb_log,
																						RPDB_RB_LOG_VARIABLE_PARENT_LOG_CURSOR );

	return rb_parent_log_cursor;
}

/*****************
*  logRecord  *
*****************/

VALUE rb_RPDB_Log_logRecord( VALUE	rb_log )	{

	RPDB_Log*			c_log;
	C_RPDB_LOG( rb_log, c_log );

	return RUBY_RPDB_RECORD( RPDB_Log_logRecord( c_log ) );
}

/*************************
*  sequenceNumbers  *
*************************/

VALUE rb_RPDB_Log_logSequenceNumber( VALUE	rb_log )	{

	RPDB_Log*			c_log;
	C_RPDB_LOG( rb_log, c_log );

	return RUBY_RPDB_LOG_SEQUENCE_NUMBER( RPDB_Log_logSequenceNumber( c_log ) );	
}

/*************
*  file  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_file.html
VALUE rb_RPDB_Log_filename( VALUE	rb_log )	{

	RPDB_Log*			c_log;
	C_RPDB_LOG( rb_log, c_log );

	return rb_str_new2( RPDB_Log_filename( c_log ) );
}


