/*
 *		RPDB::LogController::Log::LogSequenceNumber
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_LogSequenceNumber.h"
#include "rb_RPDB_Log.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_LogSequenceNumber.h>

#include <rpdb/RPDB_LogSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Log;
extern	VALUE	rb_RPDB_LogSequenceNumber;
extern	VALUE	rb_RPDB_LogSettingsController;

void Init_RPDB_LogSequenceNumber()	{

	rb_RPDB_LogSequenceNumber	=	rb_define_class_under(	rb_RPDB_Environment, 
																											"SequenceNumber",			
																											rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LogSequenceNumber, 	"new",																													rb_RPDB_LogSequenceNumber_new,											-1 	);
	rb_define_method(						rb_RPDB_LogSequenceNumber, 	"initialize",																										rb_RPDB_LogSequenceNumber_init,											-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_LogSequenceNumber, 	"settings_controller",																					rb_RPDB_LogSequenceNumber_settingsController,				0 	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_LogSequenceNumber, 	"parent_environment",																						rb_RPDB_LogSequenceNumber_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"environment",																									"parent_environment"	);

	//	FIX - separate out compare methods for == and <> and > and <
	rb_define_method(						rb_RPDB_LogSequenceNumber, 	"compare",																											rb_RPDB_LogSequenceNumber_compare,									0 	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"==",																														"parent_environment"	);
	rb_define_alias(						rb_RPDB_LogSequenceNumber, 	"<>",																														"parent_environment"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_LogSequenceNumber_new(	VALUE	klass __attribute__ ((unused)),
																			VALUE	rb_parent_log )	{
	
	RPDB_Log*			c_parent_log;
	C_RPDB_LOG( rb_parent_log, c_parent_log );
	
	VALUE	rb_log_sequence_number	=	RUBY_RPDB_LOG_SEQUENCE_NUMBER( RPDB_LogSequenceNumber_new( c_parent_log ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_log;
	
	rb_obj_call_init(	rb_log_sequence_number,
					 1, 
					 argv );
	
	return rb_log_sequence_number;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_LogSequenceNumber_init(	VALUE	rb_log_sequence_number,
																			VALUE	rb_parent_log __attribute__ ((unused)) )	{


	return rb_log_sequence_number;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_LogSequenceNumber_settingsController(	VALUE	rb_log_sequence_number )	{

	RPDB_LogSequenceNumber*	c_log_sequence_number;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	return RUBY_RPDB_LOG_SETTINGS_CONTROLLER( RPDB_LogSequenceNumber_settingsController( c_log_sequence_number ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_LogSequenceNumber_parentEnvironment(	VALUE	rb_log_sequence_number )	{

	RPDB_LogSequenceNumber*	c_log_sequence_number;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	return RUBY_RPDB_ENVIRONMENT( RPDB_LogSequenceNumber_parentEnvironment( c_log_sequence_number ) );

}

/****************
*  compare  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_compare.html
VALUE rb_RPDB_LogSequenceNumber_compare(	VALUE	rb_log_sequence_number,
 																VALUE	rb_log_sequence_number_two)	{
	
	RPDB_LogSequenceNumber*	c_log_sequence_number;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	RPDB_LogSequenceNumber*	c_log_sequence_number_two;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number_two, c_log_sequence_number_two );

	return INT2FIX( RPDB_LogSequenceNumber_compare(	c_log_sequence_number,
														c_log_sequence_number_two	) );
}


