/*
 *		RPbdb::LogController::Log::LogSequenceNumber
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "LogSequenceNumber.h"
#include "LogController.h"
#include "LogCursor.h"
#include "LogCursorController.h"
#include "Log.h"

#include <rpbdb/Environment.h>

#include <rpbdb/LogSequenceNumber.h>

#include <rpbdb/LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Log;
extern	VALUE	rb_RPbdb_LogSequenceNumber;
extern	VALUE	rb_RPbdb_LogSettingsController;
extern	VALUE	rb_RPbdb_LogController;

void Init_rb_RPbdb_LogSequenceNumber()	{

	rb_RPbdb_LogSequenceNumber	=	rb_define_class_under(	rb_RPbdb_Environment, 
																											"SequenceNumber",			
																											rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_LogSequenceNumber, 	"new",																													rb_RPbdb_LogSequenceNumber_new,											-1 	);
	rb_define_method(						rb_RPbdb_LogSequenceNumber, 	"initialize",																										rb_RPbdb_LogSequenceNumber_initialize,											-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_LogSequenceNumber, 	"settings_controller",																					rb_RPbdb_LogSequenceNumber_settingsController,				0 	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_LogSequenceNumber, 	"parent_environment",																						rb_RPbdb_LogSequenceNumber_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"environment",																									"parent_environment"	);

	//	FIX - separate out compare methods for == and <> and > and <
	rb_define_method(						rb_RPbdb_LogSequenceNumber, 	"compare",																											rb_RPbdb_LogSequenceNumber_compare,									0 	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"==",																														"parent_environment"	);
	rb_define_alias(						rb_RPbdb_LogSequenceNumber, 	"<>",																														"parent_environment"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LogSequenceNumber_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	VALUE	rb_parent_log										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_RPbdb_LogController ),
																						R_MatchAncestorInstance( rb_parent_log, rb_RPbdb_Log ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]",
			"[ <parent log> ]"
		)
	);

	RPbdb_Log*			c_parent_log;
	C_RPBDB_LOG( rb_parent_log, c_parent_log );
	
	VALUE	rb_log_sequence_number	=	RUBY_RPBDB_LOG_SEQUENCE_NUMBER( RPbdb_LogSequenceNumber_new( c_parent_log ) );
	
	//	store reference to parent
	rb_iv_set(	rb_log_sequence_number,
							RPBDB_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG,
							rb_parent_log );

	VALUE	argv[]	=	{ rb_parent_log };
	rb_obj_call_init(	rb_log_sequence_number,
										 1, 
										 argv );
	
	return rb_log_sequence_number;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_LogSequenceNumber_initialize(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self )	{


	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_sequence_number,
																												RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_LogSequenceNumber*		c_log_sequence_number;
		C_RPBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );
	
		RPbdb_LogSettingsController*	c_local_log_settings_controller	=	RPbdb_LogSequenceNumber_settingsController( c_log_sequence_number );

		rb_local_log_settings_controller	=	RUBY_RPBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_sequence_number,
								RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_controller		=	rb_RPbdb_LogSequenceNumber_parentLogController( rb_log_sequence_number );
	VALUE	rb_parent_environment				=	rb_RPbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/

VALUE rb_RPbdb_LogSequenceNumber_parentLogController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_cursor_controller		=	rb_RPbdb_LogSequenceNumber_parentLogCursorController( rb_log_sequence_number );
	VALUE	rb_parent_log_controller					=	rb_RPbdb_LogCursorController_parentLogController( rb_parent_log_cursor_controller );
	
	return rb_parent_log_controller;
}

/***************************************
*  parent_log_cursor_controller  *
***************************************/

VALUE rb_RPbdb_LogSequenceNumber_parentLogCursorController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_cursor						=	rb_RPbdb_LogSequenceNumber_parentLogCursor( rb_log_sequence_number );
	VALUE	rb_parent_log_cursor_controller	=	rb_RPbdb_LogCursor_parentLogCursorController( rb_parent_log_cursor );
	
	return rb_parent_log_cursor_controller;
}

/***************************************
*  parent_log_cursor  *
***************************************/

VALUE rb_RPbdb_LogSequenceNumber_parentLogCursor(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log					=	rb_RPbdb_LogSequenceNumber_parentLog( rb_log_sequence_number );
	VALUE	rb_parent_log_cursor	=	rb_RPbdb_LogSequenceNumber_parentLogCursor( rb_parent_log );
	
	return rb_parent_log_cursor;
}

/***************************************
*  parent_log  *
***************************************/

VALUE rb_RPbdb_LogSequenceNumber_parentLog(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log	=	rb_iv_get(	rb_log_sequence_number,
																		RPBDB_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG );
	
	return rb_parent_log;
}

/****************
*  compare  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_compare.html
VALUE rb_RPbdb_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
 																VALUE	rb_log_sequence_number_two)	{
	
	RPbdb_LogSequenceNumber*	c_log_sequence_number;
	C_RPBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	RPbdb_LogSequenceNumber*	c_log_sequence_number_two;
	C_RPBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number_two, c_log_sequence_number_two );

	return INT2FIX( RPbdb_LogSequenceNumber_compare(	c_log_sequence_number,
														c_log_sequence_number_two	) );
}


