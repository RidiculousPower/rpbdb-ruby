/*
 *		Rbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseErrorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseErrorSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"

#include "rb_Rbdb.h"

#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_SettingsController.h"


#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_ErrorController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordReadWriteSettingsController.h>

#include <rbdb/Rbdb_DatabaseErrorSettingsController.h>
#include <rbdb/Rbdb_DatabaseErrorSettingsController_internal.h>
#include <rbdb/Rbdb_RuntimeStorageController_internal.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/
	
extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseErrorSettingsController;

void Init_Rbdb_DatabaseErrorSettingsController()	{

	rb_Rbdb_DatabaseErrorSettingsController			=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																				"Error",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseErrorSettingsController, 	"new",										rb_Rbdb_DatabaseErrorSettingsController_new,										-1 	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"initialize",							rb_Rbdb_DatabaseErrorSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"parent_environment",			rb_Rbdb_DatabaseErrorSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseErrorSettingsController, 	"environment",						"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"parent_database",				rb_Rbdb_DatabaseErrorSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseErrorSettingsController, 	"database",								"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"parent_settings_controller",				rb_Rbdb_DatabaseErrorSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"parent_database_settings_controller",				rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController,					0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"file",										rb_Rbdb_DatabaseErrorSettingsController_file,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"file=",									rb_Rbdb_DatabaseErrorSettingsController_setFile,								1 	);
	rb_define_alias(						rb_Rbdb_DatabaseErrorSettingsController, 	"set_file",								"file=" 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"prefix",									rb_Rbdb_DatabaseErrorSettingsController_prefix,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseErrorSettingsController, 	"prefix=",								rb_Rbdb_DatabaseErrorSettingsController_setPrefix,							1 	);
	rb_define_alias(						rb_Rbdb_DatabaseErrorSettingsController, 	"set_prefix",							"prefix=" 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ) ) ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller	=	Rbdb_DatabaseSettingsController_errorSettingsController( c_database_settings_controller );

	VALUE	rb_database_error_settings_controller	= RUBY_RBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_error_settings_controller,
							Rbdb_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseErrorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_parentEnvironment(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_parentDatabase(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_parentSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController( rb_database_error_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_error_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_error_settings_controller,
																															Rbdb_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*********
*  file  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errfile.html
VALUE rb_Rbdb_DatabaseErrorSettingsController_file( VALUE	rb_database_error_settings_controller )	{
	
	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	Rbdb_DatabaseErrorSettingsController_file( c_database_error_settings_controller );

	//	FIX - i don't know how to call IO.new on our FILE*
	//	We get the FILE* with fileno
	//	I think we create the Ruby File from a FILE* with IO.for_fd( FILE* )
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;
}

/*************
*  set_file  *
*************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_setFile(	VALUE	rb_database_error_settings_controller, 
														VALUE	rb_error_file )	{

	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	FILE*	c_error_file	=	(FILE*) rb_funcall(	rb_error_file,
													rb_intern( "fileno" ),
													0 );

	Rbdb_DatabaseErrorSettingsController_setFile(	c_database_error_settings_controller,
	 												c_error_file );
	
	return rb_database_error_settings_controller;
}

/***********
*  prefix  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errpfx.html
VALUE rb_Rbdb_DatabaseErrorSettingsController_prefix( VALUE	rb_database_error_settings_controller )	{

	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	Rbdb_DatabaseErrorSettingsController_prefix( c_database_error_settings_controller );

	VALUE	rb_error_prefix	=	Qnil;

	if ( c_error_prefix != NULL )	{
		rb_error_prefix	=	rb_str_new2( c_error_prefix );
	}

	return rb_error_prefix;
}

/***************
*  set_prefix  *
***************/

VALUE rb_Rbdb_DatabaseErrorSettingsController_setPrefix(	VALUE			rb_database_error_settings_controller, 
																													VALUE		rb_error_prefix )	{

	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );

	char*	c_error_prefix	=	StringValuePtr( rb_error_prefix );

	Rbdb_DatabaseErrorSettingsController_setPrefix(	c_database_error_settings_controller,
																									c_error_prefix );

	return rb_database_error_settings_controller;
}

/******************************
*  set_error_callback_method  *
******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_errcall.html
VALUE rb_Rbdb_DatabaseErrorSettingsController_setErrorCallbackMethod(	VALUE	rb_database_error_settings_controller,
 																		VALUE									(*error_callback_method)(	VALUE			environment,
																												   							const VALUE		error_prefix_string,
																												   							const VALUE		error_message	)	)	{

	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
/**************************
*  error_callback_method  *
**************************/
/*
void (*error_callback_method)(	RBDB*			environment,
								const VALUE		error_prefix_string,
								const VALUE		error_message	) Rbdb_DatabaseErrorSettingsController_errorCallbackMethod( VALUE	rb_database_error_settings_controller )	{
	
	Rbdb_DatabaseErrorSettingsController*	c_database_error_settings_controller;
	C_Rbdb_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller );
}
*/
