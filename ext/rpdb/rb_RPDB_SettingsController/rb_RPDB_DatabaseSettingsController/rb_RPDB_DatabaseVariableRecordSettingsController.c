/*
 *		RPDB::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsVariableRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseVariableRecordSettingsController.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseVariableRecordSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_DatabaseVariableRecordSettingsController;

void Init_RPDB_DatabaseVariableRecordSettingsController()	{

	rb_RPDB_DatabaseVariableRecordSettingsController	=	rb_define_class_under(	rb_RPDB_DatabaseRecordSettingsController, 
																																							"VariableRecord",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseVariableRecordSettingsController, 	"new",												rb_RPDB_DatabaseVariableRecordSettingsController_new,										1 	);
	rb_define_method(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"initialize",									rb_RPDB_DatabaseVariableRecordSettingsController_init,									1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"parent_environment",					rb_RPDB_DatabaseVariableRecordSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"environment",								"parent_environment"	);                                              	
	rb_define_method(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"parent_database",						rb_RPDB_DatabaseVariableRecordSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"database",										"parent_database"	);                                                  	
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"record_delimeter",						rb_RPDB_DatabaseVariableRecordSettingsController_recordDelimeter,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"record_delimeter=",					rb_RPDB_DatabaseVariableRecordSettingsController_setRecordDelimeter,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseVariableRecordSettingsController, 	"set_record_delimeter",				"record_delimeter="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseVariableRecordSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																														VALUE	rb_parent_database_settings_controller )	{
	
	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_variable_record_settings_controller	= RUBY_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER( RPDB_DatabaseVariableRecordSettingsController_new( c_parent_database_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_variable_record_settings_controller,
					 1, 
					 argv );
	
	return rb_database_variable_record_settings_controller;		
}

	/*************
	*  new  *
	*************/

VALUE rb_RPDB_DatabaseVariableRecordSettingsController_init(	VALUE	rb_database_variable_record_settings_controller,
																															VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{

	return rb_database_variable_record_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseVariableRecordSettingsController_parentEnvironment(	VALUE	rb_database_variable_record_settings_controller )	{

	RPDB_DatabaseVariableRecordSettingsController*	c_database_variable_record_settings_controller;
	C_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER( rb_database_variable_record_settings_controller, c_database_variable_record_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseVariableRecordSettingsController_parentEnvironment( c_database_variable_record_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseVariableRecordSettingsController_parentDatabase(	VALUE	rb_database_variable_record_settings_controller )	{

	RPDB_DatabaseVariableRecordSettingsController*	c_database_variable_record_settings_controller;
	C_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER( rb_database_variable_record_settings_controller, c_database_variable_record_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseVariableRecordSettingsController_parentDatabase( c_database_variable_record_settings_controller ) );

}

	/************************
	*  recordDelimeter  *
	************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_delim.html
VALUE rb_RPDB_DatabaseVariableRecordSettingsController_recordDelimeter( VALUE	rb_database_variable_record_settings_controller )	{

	RPDB_DatabaseVariableRecordSettingsController*	c_database_variable_record_settings_controller;
	C_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER( rb_database_variable_record_settings_controller, c_database_variable_record_settings_controller );

	return INT2FIX( RPDB_DatabaseVariableRecordSettingsController_recordDelimeter( c_database_variable_record_settings_controller ) );
}

	/****************************
	*  setRecordDelimeter  *
	****************************/

VALUE rb_RPDB_DatabaseVariableRecordSettingsController_setRecordDelimeter(	VALUE	rb_database_variable_record_settings_controller, 
																			VALUE	rb_record_delimeter )	{

	RPDB_DatabaseVariableRecordSettingsController*	c_database_variable_record_settings_controller;
	C_RPDB_DATABASE_VARIABLE_RECORD_SETTINGS_CONTROLLER( rb_database_variable_record_settings_controller, c_database_variable_record_settings_controller );

	RPDB_DatabaseVariableRecordSettingsController_setRecordDelimeter(	c_database_variable_record_settings_controller,
																		FIX2INT( rb_record_delimeter ) );
	
	return rb_database_variable_record_settings_controller;
}
