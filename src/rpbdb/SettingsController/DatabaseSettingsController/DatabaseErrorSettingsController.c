/*
 *		RPbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseErrorSettingsController.h"
#include "DatabaseSettingsController.h"

#include "RPbdb.h"

#include "DatabaseController.h"
#include "Database.h"
#include "SettingsController.h"


#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/ErrorController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseRecordReadWriteSettingsController.h>

#include <rpbdb/DatabaseErrorSettingsController.h>
#include <rpbdb/DatabaseErrorSettingsController_internal.h>
#include <rpbdb/RuntimeStorageController_internal.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseErrorSettingsController;

void Init_rb_RPbdb_DatabaseErrorSettingsController()	{

	rb_RPbdb_DatabaseErrorSettingsController			=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																				"Error",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseErrorSettingsController, 	"new",										rb_RPbdb_DatabaseErrorSettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"initialize",							rb_RPbdb_DatabaseErrorSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"parent_environment",			rb_RPbdb_DatabaseErrorSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseErrorSettingsController, 	"environment",						"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"parent_database",				rb_RPbdb_DatabaseErrorSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPbdb_DatabaseErrorSettingsController, 	"database",								"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"parent_settings_controller",				rb_RPbdb_DatabaseErrorSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"parent_database_settings_controller",				rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController,					0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"file",										rb_RPbdb_DatabaseErrorSettingsController_file,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"file=",									rb_RPbdb_DatabaseErrorSettingsController_setFile,								1 	);
	rb_define_alias(						rb_RPbdb_DatabaseErrorSettingsController, 	"set_file",								"file=" 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"prefix",									rb_RPbdb_DatabaseErrorSettingsController_prefix,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseErrorSettingsController, 	"prefix=",								rb_RPbdb_DatabaseErrorSettingsController_setPrefix,							1 	);
	rb_define_alias(						rb_RPbdb_DatabaseErrorSettingsController, 	"set_prefix",							"prefix=" 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );
	}

	RPbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller	=	RPbdb_DatabaseSettingsController_errorSettingsController( c_database_settings_controller );

	VALUE	rb_database_error_settings_controller	= RUBY_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_error_settings_controller,
							RPBDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[] =	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_error_settings_controller,
										 1, 
										 argv );
	
	return rb_database_error_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_parentSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_error_settings_controller,
																															RPBDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errfile.html
VALUE rb_RPbdb_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller )	{
	
	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	RPbdb_DatabaseErrorSettingsController_file( c_database_error_settings_controller );

	//	FIX - i don't know how to call IO.new on our FILE*
	//	We get the FILE* with fileno
	//	I think we create the Ruby File from a FILE* with IO.for_fd( FILE* )
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/*************
*  set_file  *
*************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
														VALUE	rb_error_file )	{

	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	FILE*	c_error_file	=	(FILE*) rb_funcall(	rb_error_file,
													rb_intern( "fileno" ),
													0 );

	RPbdb_DatabaseErrorSettingsController_setFile(	c_database_error_settings_controller,
	 												c_error_file );
	
	return rb_database_error_settings_controller;
}

/***********
*  prefix  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errpfx.html
VALUE rb_RPbdb_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller )	{

	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	RPbdb_DatabaseErrorSettingsController_prefix( c_database_error_settings_controller );

	VALUE	rb_error_prefix	=	Qnil;

	if ( c_error_prefix != NULL )	{
		rb_error_prefix	=	rb_str_new2( c_error_prefix );
	}

	return rb_error_prefix;
}

/***************
*  set_prefix  *
***************/

VALUE rb_RPbdb_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																													VALUE		rb_error_prefix )	{

	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	StringValuePtr( rb_error_prefix );

	RPbdb_DatabaseErrorSettingsController_setPrefix(	c_database_error_settings_controller,
																									c_error_prefix );

	return rb_database_error_settings_controller;
}

/******************************
*  set_error_callback_method  *
******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errcall.html
VALUE rb_RPbdb_DatabaseErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_database_error_settings_controller,
 																		VALUE									(*error_callback_method)(	VALUE			environment,
																												   							const VALUE		error_prefix_string,
																												   							const VALUE		error_message	)	)	{

	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
/**************************
*  error_callback_method  *
**************************/
/*
void (*error_callback_method)(	RPBDB*			environment,
								const VALUE		error_prefix_string,
								const VALUE		error_message	) RPbdb_DatabaseErrorSettingsController_errorCallbackMethod( VALUE	rb_database_error_settings_controller )	{
	
	RPbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
