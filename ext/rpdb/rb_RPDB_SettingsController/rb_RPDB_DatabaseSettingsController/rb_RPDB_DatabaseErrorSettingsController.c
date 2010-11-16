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

#include "rb_RPDB_DatabaseErrorSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"

#include "rb_RPDB.h"

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_SettingsController.h"


#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_ErrorController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>

#include <rpdb/RPDB_DatabaseErrorSettingsController.h>
#include <rpdb/RPDB_DatabaseErrorSettingsController_internal.h>
#include <rpdb/RPDB_RuntimeStorageController_internal.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseErrorSettingsController;

void Init_RPDB_DatabaseErrorSettingsController()	{

	rb_RPDB_DatabaseErrorSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																				"Error",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseErrorSettingsController, 	"new",										rb_RPDB_DatabaseErrorSettingsController_new,										-1 	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"initialize",							rb_RPDB_DatabaseErrorSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_environment",			rb_RPDB_DatabaseErrorSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"environment",						"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_database",				rb_RPDB_DatabaseErrorSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseErrorSettingsController, 	"database",								"parent_database"	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_settings_controller",				rb_RPDB_DatabaseErrorSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_RPDB_DatabaseErrorSettingsController, 	"parent_database_settings_controller",				rb_RPDB_DatabaseErrorSettingsController_parentDatabaseSettingsController,					0 	);
                    					
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
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseErrorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ) ) ),
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
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );
	}

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller	=	RPDB_DatabaseSettingsController_errorSettingsController( c_database_settings_controller );

	VALUE	rb_database_error_settings_controller	= RUBY_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_error_settings_controller,
							RPDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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

VALUE rb_RPDB_DatabaseErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DatabaseErrorSettingsController_parentSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPDB_DatabaseErrorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_error_settings_controller,
																															RPDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*********
*  file  *
*********/

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

/*************
*  set_file  *
*************/

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

/***********
*  prefix  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errpfx.html
VALUE rb_RPDB_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	RPDB_DatabaseErrorSettingsController_prefix( c_database_error_settings_controller );

	VALUE	rb_error_prefix	=	Qnil;

	if ( c_error_prefix != NULL )	{
		rb_error_prefix	=	rb_str_new2( c_error_prefix );
	}

	return rb_error_prefix;
}

/***************
*  set_prefix  *
***************/

VALUE rb_RPDB_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																													VALUE		rb_error_prefix )	{

	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	StringValuePtr( rb_error_prefix );

	RPDB_DatabaseErrorSettingsController_setPrefix(	c_database_error_settings_controller,
																									c_error_prefix );

	return rb_database_error_settings_controller;
}

/******************************
*  set_error_callback_method  *
******************************/
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
/**************************
*  error_callback_method  *
**************************/
/*
void (*error_callback_method)(	RBDB*			environment,
								const VALUE		error_prefix_string,
								const VALUE		error_message	) RPDB_DatabaseErrorSettingsController_errorCallbackMethod( VALUE	rb_database_error_settings_controller )	{
	
	RPDB_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
