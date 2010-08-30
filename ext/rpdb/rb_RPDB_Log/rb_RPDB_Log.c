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

#include "rb_RPDB_Log.h"
#include "rb_RPDB_LogController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_Log.h>
//#include <rpdb/RPDB_LogSequenceNumber.h>

#include <rpdb/RPDB_LogSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Log;
extern	VALUE	rb_RPDB_LogController;
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

VALUE rb_RPDB_Log_new(	VALUE	klass __attribute__ ((unused)),
												VALUE	rb_parent_log_controller )	{
	
	RPDB_LogController*	c_parent_log_controller;
	C_RPDB_LOG_CONTROLLER( rb_parent_log_controller, c_parent_log_controller );
	
	VALUE	rb_log	=	RUBY_RPDB_LOG( RPDB_Log_new( c_parent_log_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_log_controller;
	
	rb_obj_call_init(	rb_log,
					 1, 
					 argv );
	
	return rb_log;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Log_init(	VALUE	rb_log,
												VALUE	rb_parent_log_controller __attribute__ ((unused)) )	{

	return rb_log;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Log_settingsController(	VALUE	rb_log )	{
	
	RPDB_Log*					c_log;
	C_RPDB_LOG( rb_log, c_log );

	return RUBY_RPDB_LOG_SETTINGS_CONTROLLER( RPDB_Log_settingsController( c_log ) );
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_Log_parentEnvironment(	VALUE	rb_log )	{

	RPDB_Log*			c_log;
	C_RPDB_LOG( rb_log, c_log );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Log_parentEnvironment( c_log ) );

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


