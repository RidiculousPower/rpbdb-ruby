/*
 *		Rbdb::LogController::Log::LogSequenceNumber
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_LogSequenceNumber.h"
#include "rb_Rbdb_LogController.h"
#include "rb_Rbdb_LogCursor.h"
#include "rb_Rbdb_LogCursorController.h"
#include "rb_Rbdb_Log.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_LogSequenceNumber.h>

#include <rbdb/Rbdb_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Log;
extern	VALUE	rb_Rbdb_LogSequenceNumber;
extern	VALUE	rb_Rbdb_LogSettingsController;
extern	VALUE	rb_Rbdb_LogController;

void Init_Rbdb_LogSequenceNumber()	{

	rb_Rbdb_LogSequenceNumber	=	rb_define_class_under(	rb_Rbdb_Environment, 
																											"SequenceNumber",			
																											rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_LogSequenceNumber, 	"new",																													rb_Rbdb_LogSequenceNumber_new,											-1 	);
	rb_define_method(						rb_Rbdb_LogSequenceNumber, 	"initialize",																										rb_Rbdb_LogSequenceNumber_initialize,											-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_LogSequenceNumber, 	"settings_controller",																					rb_Rbdb_LogSequenceNumber_settingsController,				0 	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_Rbdb_LogSequenceNumber, 	"parent_environment",																						rb_Rbdb_LogSequenceNumber_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"environment",																									"parent_environment"	);

	//	FIX - separate out compare methods for == and <> and > and <
	rb_define_method(						rb_Rbdb_LogSequenceNumber, 	"compare",																											rb_Rbdb_LogSequenceNumber_compare,									0 	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"==",																														"parent_environment"	);
	rb_define_alias(						rb_Rbdb_LogSequenceNumber, 	"<>",																														"parent_environment"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_LogSequenceNumber_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_log_controller				=	Qnil;
	VALUE	rb_parent_log										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_log_controller, rb_Rbdb_LogController ),
																						R_MatchAncestorInstance( rb_parent_log, rb_Rbdb_Log ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent log controller> ]",
			"[ <parent log> ]"
		)
	);

	Rbdb_Log*			c_parent_log;
	C_Rbdb_LOG( rb_parent_log, c_parent_log );
	
	VALUE	rb_log_sequence_number	=	RUBY_RBDB_LOG_SEQUENCE_NUMBER( Rbdb_LogSequenceNumber_new( c_parent_log ) );
	
	//	store reference to parent
	rb_iv_set(	rb_log_sequence_number,
							Rbdb_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG,
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

VALUE rb_Rbdb_LogSequenceNumber_initialize(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self )	{


	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_sequence_number,
																												Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_LogSequenceNumber*		c_log_sequence_number;
		C_Rbdb_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );
	
		Rbdb_LogSettingsController*	c_local_log_settings_controller	=	Rbdb_LogSequenceNumber_settingsController( c_log_sequence_number );

		rb_local_log_settings_controller	=	RUBY_RBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_sequence_number,
								Rbdb_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_Rbdb_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_controller		=	rb_Rbdb_LogSequenceNumber_parentLogController( rb_log_sequence_number );
	VALUE	rb_parent_environment				=	rb_Rbdb_LogController_parentEnvironment( rb_parent_log_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_log_controller  *
***************************************/

VALUE rb_Rbdb_LogSequenceNumber_parentLogController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_cursor_controller		=	rb_Rbdb_LogSequenceNumber_parentLogCursorController( rb_log_sequence_number );
	VALUE	rb_parent_log_controller					=	rb_Rbdb_LogCursorController_parentLogController( rb_parent_log_cursor_controller );
	
	return rb_parent_log_controller;
}

/***************************************
*  parent_log_cursor_controller  *
***************************************/

VALUE rb_Rbdb_LogSequenceNumber_parentLogCursorController(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log_cursor						=	rb_Rbdb_LogSequenceNumber_parentLogCursor( rb_log_sequence_number );
	VALUE	rb_parent_log_cursor_controller	=	rb_Rbdb_LogCursor_parentLogCursorController( rb_parent_log_cursor );
	
	return rb_parent_log_cursor_controller;
}

/***************************************
*  parent_log_cursor  *
***************************************/

VALUE rb_Rbdb_LogSequenceNumber_parentLogCursor(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log					=	rb_Rbdb_LogSequenceNumber_parentLog( rb_log_sequence_number );
	VALUE	rb_parent_log_cursor	=	rb_Rbdb_LogSequenceNumber_parentLogCursor( rb_parent_log );
	
	return rb_parent_log_cursor;
}

/***************************************
*  parent_log  *
***************************************/

VALUE rb_Rbdb_LogSequenceNumber_parentLog(	VALUE	rb_log_sequence_number )	{

	VALUE	rb_parent_log	=	rb_iv_get(	rb_log_sequence_number,
																		Rbdb_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG );
	
	return rb_parent_log;
}

/****************
*  compare  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_compare.html
VALUE rb_Rbdb_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
 																VALUE	rb_log_sequence_number_two)	{
	
	Rbdb_LogSequenceNumber*	c_log_sequence_number;
	C_Rbdb_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	Rbdb_LogSequenceNumber*	c_log_sequence_number_two;
	C_Rbdb_LOG_SEQUENCE_NUMBER( rb_log_sequence_number_two, c_log_sequence_number_two );

	return INT2FIX( Rbdb_LogSequenceNumber_compare(	c_log_sequence_number,
														c_log_sequence_number_two	) );
}


