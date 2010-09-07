/*
 *		RPDB::DatabaseController::Database::DatabaseSettingsController::DatabaseErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_ErrorController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>

#include <rpdb/RPDB_DatabaseErrorSettingsController.h>
#include <rpdb/RPDB_DatabaseErrorSettingsController_internal.h>
#include <rpdb/RPDB_RuntimeStorageController_internal.h>
#include "rb_RPDB_DatabaseErrorSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseErrorSettingsController;

void Init_RPDB_DatabaseErrorSettingsController()	{

	rb_RPDB_DatabaseErrorSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																				"Error",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseErrorSettingsController, 	"new",										rb_RPDB_DatabaseErrorSettingsController_new,										1 	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"initialize",							rb_RPDB_DatabaseErrorSettingsController_init,										1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_environment",			rb_RPDB_DatabaseErrorSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"environment",						"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_database",				rb_RPDB_DatabaseErrorSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"database",								"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"file",										rb_RPDB_DatabaseErrorSettingsController_file,										0 	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"file=",									rb_RPDB_DatabaseErrorSettingsController_setFile,								1 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"set_file",								"file=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"prefix",									rb_RPDB_DatabaseErrorSettingsController_prefix,									0 	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"prefix=",								rb_RPDB_DatabaseErrorSettingsController_setPrefix,							1 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"set_prefix",							"prefix=" 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseErrorSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_error_settings_controller	= RUBY_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( RPDB_DatabaseErrorSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_error_settings_controller,
					 1, 
					 argv );
	
	return rb_database_error_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseErrorSettingsController_init(	VALUE	rb_database_error_settings_controller,
																										VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_error_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseErrorSettingsController_parentEnvironment( c_database_error_settings_controller ) );
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseErrorSettingsController_parentDatabase( c_database_error_settings_controller ) );

}

/*************
*  file  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errfile.html
VALUE rb_RPDB_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller )	{
	
	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	RPDB_DatabaseErrorSettingsController_file( c_database_error_settings_controller );

	//	FIX - i don't know how to call IO.new on our FILE*
	//	We get the FILE* with fileno
	//	I think we create the Ruby File from a FILE* with IO.for_fd( FILE* )
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/****************
*  setFile  *
****************/

VALUE rb_RPDB_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
														VALUE	rb_error_file )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	FILE*	c_error_file	=	(FILE*) rb_funcall(	rb_error_file,
													rb_intern( "fileno" ),
													0 );

	RPDB_DatabaseErrorSettingsController_setFile(	c_database_error_settings_controller,
	 												c_error_file );
	
	return rb_database_error_settings_controller;
}

/**************
*  prefix  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errpfx.html
VALUE rb_RPDB_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	return rb_str_new2( RPDB_DatabaseErrorSettingsController_prefix( c_database_error_settings_controller ) );
}

/******************
*  setPrefix  *
******************/

VALUE rb_RPDB_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
															VALUE		rb_error_prefix )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	RPDB_DatabaseErrorSettingsController_setPrefix(	c_database_error_settings_controller,
	 													StringValuePtr( rb_error_prefix ) );

	return rb_database_error_settings_controller;
}

/****************************
*  setErrorCallbackMethod  *
****************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errcall.html
VALUE rb_RPDB_DatabaseErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_database_error_settings_controller,
 																		VALUE									(*error_callback_method)(	VALUE			environment,
																												   							const VALUE		error_prefix_string,
																												   							const VALUE		error_message	)	)	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
/****************************
*  errorCallbackMethod  *
****************************/
/*
void (*error_callback_method)(	RBDB*			environment,
								const VALUE		error_prefix_string,
								const VALUE		error_message	) RPDB_DatabaseErrorSettingsController_errorCallbackMethod( VALUE	rb_database_error_settings_controller )	{
	
	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
