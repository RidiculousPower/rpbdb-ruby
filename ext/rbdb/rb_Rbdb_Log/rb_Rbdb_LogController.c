/*
 *		Rbdb::LogController
 *
 *		BDB logging implementation for applications described here: 
 *      http://www.oracle.com/technology/documentation/berkeley-db/db/ref/apprec/def.html
 *
 *		Description of process for full backup with BDB:
 *      http://www.oracle.com/technology/documentation/berkeley-db/db/ref/transapp/archival.html
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_LogController.h"
#include "rb_Rbdb_LogSequenceNumber.h"

#include "rb_Rbdb_Record.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_LogController.h>

#include <rbdb/Rbdb_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_LogController;
extern	VALUE	rb_Rbdb_LogSettingsController;
extern	VALUE	rb_Rbdb_LogSequenceNumber;;

void Init_rb_Rbdb_LogController()	{

	rb_Rbdb_LogController	=	rb_define_class_under(	rb_Rbdb_Environment, 
																									"LogController",			
																									rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_LogController, 	"new",																													rb_Rbdb_LogController_new,										-1 	);
	rb_define_method(						rb_Rbdb_LogController, 	"initialize",																										rb_Rbdb_LogController_initialize,									-1 	);
                                                                                          		                                                                        
	rb_define_method(						rb_Rbdb_LogController, 	"settings_controller",																					rb_Rbdb_LogController_settingsController,		0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"settings",																											"settings_controller"	);                      
	rb_define_alias(						rb_Rbdb_LogController, 	"set",																													"settings_controller"	);                      
	rb_define_alias(						rb_Rbdb_LogController, 	"set_to",																												"settings_controller"	);                      
	rb_define_alias(						rb_Rbdb_LogController, 	"is_set_to",																										"settings_controller"	);                      
	rb_define_method(						rb_Rbdb_LogController, 	"parent_environment",																						rb_Rbdb_LogController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"environment",																									"parent_environment"	);

	//	FIX - make append deal transparently with whatever needs to be written, string or record, etc.
	rb_define_method(						rb_Rbdb_LogController, 	"append_string",																								rb_Rbdb_LogController_appendStringToCurrentLog,						0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"puts",																													"append_string"	);                            
	rb_define_method(						rb_Rbdb_LogController, 	"flush_logs_to_disk",																						rb_Rbdb_LogController_flushLogsToDisk,				0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"flush_logs",																										"flush_logs_to_disk"	);                      
	rb_define_alias(						rb_Rbdb_LogController, 	"flush",																												"flush_logs_to_disk"	);                      
	rb_define_method(						rb_Rbdb_LogController, 	"append_log_record",																						rb_Rbdb_LogController_appendLogRecord,				0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"append_record",																								"append_log_record"	);                              
	rb_define_alias(						rb_Rbdb_LogController, 	"put_record",																										"append_log_record"	);                              
	rb_define_alias(						rb_Rbdb_LogController, 	"write_record",																									"append_log_record"	);                              
	rb_define_alias(						rb_Rbdb_LogController, 	"write",																												"append_log_record"	);                              
	rb_define_method(						rb_Rbdb_LogController, 	"cursor_controller",																						rb_Rbdb_LogController_cursorController,				0 	);
	rb_define_alias(						rb_Rbdb_LogController, 	"cursors",																											"cursor_controller"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_LogController_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);
	
	Rbdb_Environment*	c_parent_environment;
	C_RBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_log_controller	=	RUBY_RBDB_LOG_CONTROLLER( Rbdb_LogController_new( c_parent_environment ) );

	//	store reference to parent
	rb_iv_set(	rb_log_controller,
							RBDB_RB_LOG_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );
	
	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_log_controller,
					 1, 
					 argv );
	
	return rb_log_controller;	
}


/*************
*  self.new  *
*************/

VALUE rb_Rbdb_LogController_initialize(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_LogController_settingsController(	VALUE	rb_log_controller )	{

	VALUE	rb_local_log_settings_controller	=	Qnil;
	
	if ( ( rb_local_log_settings_controller = rb_iv_get(	rb_log_controller,
																												RBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_LogController*		c_log_controller;
		C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller );
	
		Rbdb_LogSettingsController*	c_local_log_settings_controller	=	Rbdb_LogController_settingsController( c_log_controller );

		rb_local_log_settings_controller	=	RUBY_RBDB_LOG_SETTINGS_CONTROLLER( c_local_log_settings_controller );

		rb_iv_set(	rb_log_controller,
								RBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_local_log_settings_controller );
	}

	return rb_local_log_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_Rbdb_LogController_parentEnvironment(	VALUE	rb_log_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_log_controller,
																						RBDB_RB_LOG_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );
	
	return rb_parent_environment;
}

/*********************
*  appendString  *
*********************/

//	FIX
	
//	The DB_ENV->log_printf method appends an informational message to the Berkeley DB database environment log files.
//	The DB_ENV->log_printf method allows applications to include information in the database environment log files, 
//	for later review using the db_printlog utility. This method is intended for debugging and performance tuning.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_printf.html
VALUE rb_Rbdb_LogController_appendStringToCurrentLog(	int			argc __attribute__ ((unused)),
																											VALUE*	args __attribute__ ((unused)),
																											VALUE	rb_log_controller )	{

	Rbdb_LogController*	c_log_controller;
	C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller );

	//	FIX - not implemented
	char*	c_log_string	=	NULL;

	Rbdb_LogController_appendStringToCurrentLog(	c_log_controller,
																								c_log_string );

	return rb_log_controller;
}

/*************************
*  flushLogsToDisk  *
*************************/

//	All log records with DB_LSN values less than or equal to the lsn parameter are written to disk. If lsn is NULL, all records in the log are flushed.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_flush.html	
VALUE rb_Rbdb_LogController_flushLogsToDisk(	VALUE	rb_log_controller,
 												VALUE	rb_log_sequence_number )	{

	Rbdb_LogController*	c_log_controller;
	C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller );

	Rbdb_LogSequenceNumber*	c_log_sequence_number;
	C_RBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number );

	Rbdb_LogController_flushLogsToDisk(	c_log_controller,
											c_log_sequence_number	);

	return rb_log_controller;	
}

/*********************
*  appendRecord  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/log_put.html
VALUE rb_Rbdb_LogController_appendLogRecord(	VALUE	rb_log_controller,
 												VALUE	rb_log_record )	{

	Rbdb_LogController*	c_log_controller;
	C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller );

	Rbdb_Record*		c_log_record;
	C_RBDB_RECORD( rb_log_record, c_log_record );

	Rbdb_LogController_appendLogRecord(	c_log_controller,
											c_log_record	);
	
	return rb_log_controller;
}

/*************************
*  cursorController  *
*************************/

VALUE rb_Rbdb_LogController_cursorController( VALUE	rb_log_controller )	{

	Rbdb_LogController*	c_log_controller;
	C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller );

	Rbdb_LogController_cursorController( c_log_controller );

	return rb_log_controller;
}






