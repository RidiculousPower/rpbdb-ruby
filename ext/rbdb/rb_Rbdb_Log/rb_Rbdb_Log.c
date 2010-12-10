/*
 *		Rbdb::LogController::Log
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb.h"
#include "rb_Rbdb_Log.h"
#include "rb_Rbdb_LogController.h"
#include "rb_Rbdb_LogCursorController.h"
#include "rb_Rbdb_LogCursor.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Record.h>

#include <rbdb/Rbdb_Log.h>
#include <rbdb/Rbdb_LogCursor.h>
#include <rbdb/Rbdb_LogCursorController.h>
//#include <rbdb/Rbdb_LogSequenceNumber.h>

#include <rbdb/Rbdb_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Log;
extern	VALUE	rb_Rbdb_LogController;
extern	VALUE	rb_Rbdb_LogCursorController;
extern	VALUE	rb_Rbdb_LogCursor;
extern	VALUE	rb_Rbdb_LogSettingsController;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_LogSequenceNumber;

void Init_Rbdb_Log()	{

	rb_Rbdb_Log	=	rb_define_class_under(		rb_Rbdb_Environment, 
																					"Log",			
																					rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_Log, 	"new",																													rb_Rbdb_Log_new,												-1 	);
	rb_define_method(						rb_Rbdb_Log, 	"initialize",																										rb_Rbdb_Log_initialize,											-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_Log, 	"settings_controller",																					rb_Rbdb_Log_settingsController,				0 	);
	rb_define_alias(						rb_Rbdb_Log, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Log, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Log, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Log, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_Rbdb_Log, 	"parent_environment",																						rb_Rbdb_Log_parentEnvironment,					0 	);
	rb_define_alias(						rb_Rbdb_Log, 	"environment",																									"parent_environment"	);

	//	FIX - what's log_record? isn't that self?
	rb_define_method(						rb_Rbdb_Log, 	"record",																												rb_Rbdb_Log_logRecord,														0 	);
	rb_define_method(						rb_Rbdb_Log, 	"sequence_number",																							rb_Rbdb_Log_logSequenceNumber,										0 	);
	rb_define_alias(						rb_Rbdb_Log, 	"lsn",																													"log_sequence_number"	);		
	rb_define_method(						rb_Rbdb_Log, 	"filename",																											rb_Rbdb_Log_filename,															0 	);
		
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Log_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment							=	Qnil;
	VALUE	rb_parent_log_controller					=	Qnil;
	VALUE	rb_parent_log_cursor_controller		=	Qnil;
	VALUE	rb_parent_log_cursor							=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_Rbdb_LogController ),
																						R_MatchAncestorInstance( rb_parent_log_cursor_controller, rb_Rbdb_LogCursorController ),
																						R_MatchAncestorInstance( rb_parent_log_cursor, rb_Rbdb_LogCursor ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]",
			"[ <parent log cursor controller> ]",
			"[ <parent log cursor> ]"
		)
	);
	
	Rbdb_LogController*	c_parent_log_controller;
	C_Rbdb_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log	=	RUBY_RBDB_LOG( Rbdb_Log_new( c_parent_log_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_log,
							Rbdb_RB_LOG_VARIABLE_PARENT_LOG_CURSOR,
							rb_parent_log_cursor );
	
	VALUE	argv[]	=	{ rb_parent_log_controller };
	rb_obj_call_init(	rb_log,
					 1, 
					 argv );
	
	return rb_log;	
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Log_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_Log_settingsController(	VALUE	rb_log )	{
	
	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log,
																												Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Log*		c_log;
		C_Rbdb_LOG( rb_log, c_log );
	
		Rbdb_LogSettingsController*	c_local_log_settings_controller	=	Rbdb_Log_settingsController( c_log );

		rb_local_log_settings_controller	=	RUBY_RBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log,
								Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_Rbdb_Log_parentEnvironment(	VALUE	rb_log )	{

	VALUE	rb_parent_log_controller			=	rb_Rbdb_Log_parentLogController( rb_log );
	VALUE	rb_parent_environment					=	rb_Rbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/
VALUE rb_Rbdb_Log_parentLogController(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor_controller		=	rb_Rbdb_Log_parentLogCursorController( rb_log );
	VALUE	rb_parent_log_controller					=	rb_Rbdb_LogCursorController_parentLogController( rb_parent_log_cursor_controller );
	
	return rb_parent_log_controller;
}

/***************************************
*  parent_log_cursor_controller  *
***************************************/
VALUE rb_Rbdb_Log_parentLogCursorController(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor							=	rb_Rbdb_Log_parentLogCursor( rb_log );
	VALUE	rb_parent_log_cursor_controller		=	rb_Rbdb_LogCursor_parentLogCursorController( rb_parent_log_cursor );
	
	return rb_parent_log_cursor_controller;
}

/***************************************
*  parent_log_cursor  *
***************************************/
VALUE rb_Rbdb_Log_parentLogCursor(	VALUE	rb_log )	{

	VALUE	rb_parent_log_cursor	=	rb_iv_get(	rb_log,
																						Rbdb_RB_LOG_VARIABLE_PARENT_LOG_CURSOR );

	return rb_parent_log_cursor;
}

/*****************
*  logRecord  *
*****************/

VALUE rb_Rbdb_Log_logRecord( VALUE	rb_log )	{

	Rbdb_Log*			c_log;
	C_Rbdb_LOG( rb_log, c_log );

	return RUBY_RBDB_RECORD( Rbdb_Log_logRecord( c_log ) );
}

/*************************
*  sequenceNumbers  *
*************************/

VALUE rb_Rbdb_Log_logSequenceNumber( VALUE	rb_log )	{

	Rbdb_Log*			c_log;
	C_Rbdb_LOG( rb_log, c_log );

	return RUBY_RBDB_LOG_SEQUENCE_NUMBER( Rbdb_Log_logSequenceNumber( c_log ) );	
}

/*************
*  file  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_file.html
VALUE rb_Rbdb_Log_filename( VALUE	rb_log )	{

	Rbdb_Log*			c_log;
	C_Rbdb_LOG( rb_log, c_log );

	return rb_str_new2( Rbdb_Log_filename( c_log ) );
}


