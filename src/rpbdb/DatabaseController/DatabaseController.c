/*
 *		RPbdb::DatabaseController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseController.h"

#include "RPbdb.h"
#include "RPbdb_internal.h"
#include "Database.h"
#include "Environment.h"

#include "SettingsController.h"
#include "DatabaseSettingsController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>
#include <rpbdb/DatabaseController.h>

#include <rpbdb/RuntimeStorageController.h>

#include <rpbdb/DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;

void Init_rb_RPbdb_DatabaseController()	{

	rb_RPbdb_DatabaseController	=	rb_define_class_under(	rb_RPbdb_Database, 
																												"Controller",			
																												rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseController, 	"new",														rb_RPbdb_DatabaseController_new,											-1 	);
	rb_define_method(						rb_RPbdb_DatabaseController, 	"initialize",											rb_RPbdb_DatabaseController_initialize,										-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_DatabaseController, 	"settings_controller",						rb_RPbdb_DatabaseController_settingsController,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"settings",												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"set",														"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"set_to",													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"is_set_to",											"settings_controller"	);
	rb_define_method(						rb_RPbdb_DatabaseController, 	"parent_environment",							rb_RPbdb_DatabaseController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"environment",										"parent_environment"	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseController, 	"new_database",										rb_RPbdb_DatabaseController_newDatabase,							1 	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"new",														"new_database"	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"database",												"new_database"	);
	rb_define_method(						rb_RPbdb_DatabaseController, 	"close_all_databases",						rb_RPbdb_DatabaseController_closeAllDatabases,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseController, 	"close_all",											"close_all_databases"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseController_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass __attribute__((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_environment_name		=	Qnil;
	
	/*------------------------------------------------------*/

	VALUE	rb_parent_environment_or_name_string_or_symbol	=	Qnil;
	rb_scan_args(	argc,
								args,
								"01",
								& rb_parent_environment_or_name_string_or_symbol );
	
	//	if we have an environment name/handle
	if (		TYPE( rb_parent_environment_or_name_string_or_symbol ) == T_STRING
			||	TYPE( rb_parent_environment_or_name_string_or_symbol ) == T_SYMBOL )	{

		rb_parent_environment_name		=	rb_parent_environment_or_name_string_or_symbol;
	}
	//	or if we have an environment
	else if ( rb_parent_environment_or_name_string_or_symbol != Qnil ) {
	
		rb_parent_environment	=	rb_parent_environment_or_name_string_or_symbol;
	}
	
	//	or no argument; default environment
	if ( rb_parent_environment == Qnil )	{	
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment == Qnil )	{
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND );
	}
	
	/*------------------------------------------------------*/

	RPbdb_Environment*	c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	RPbdb_DatabaseController*	c_database_controller	=	RPbdb_Environment_databaseController( c_parent_environment );

	VALUE	rb_database_controller	=	RUBY_RPBDB_DATABASE_CONTROLLER( c_database_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_controller,
							RPBDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );
	
	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_database_controller,
										1, 
										argv );
	
	return rb_database_controller;	
}
	
/*********
*  initialize  *
*********/
	
VALUE rb_RPbdb_DatabaseController_initialize(	int			argc __attribute__((unused)),
																				VALUE*	args __attribute__((unused)),
																				VALUE		rb_database_controller )	{

	return rb_database_controller;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPbdb_DatabaseController_settingsController(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_RPbdb_DatabaseController_parentEnvironment( rb_database_controller );
	
	VALUE	rb_settings_controller					=	rb_RPbdb_Environment_settingsController( rb_parent_environment );
	VALUE	rb_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_settings_controller );
	
	return rb_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_RPbdb_DatabaseController_parentEnvironment(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_database_controller,
																						RPBDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT );

	return rb_parent_environment;
}

/*****************
*  self.new_database  *
*  self.new           *
*****************/

//	Return a name that has been created or creates it if necessary
VALUE rb_RPbdb_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																							VALUE		rb_database_name )	{
	
	VALUE	args[ 2 ];
	args[ 0 ]	=	rb_database_name;
	args[ 1 ] = rb_database_controller;
	VALUE	rb_database	=	rb_RPbdb_Database_new(	2,
																						args,
																						rb_RPbdb_Database );
		
	return rb_database;
}

/************************
*  close_all_databases  *
*  close_all            *
************************/

//	Close all Databases
VALUE rb_RPbdb_DatabaseController_closeAllDatabases( VALUE rb_database_controller )	{

	RPbdb_DatabaseController*	c_database_controller;
	C_RPBDB_DATABASE_CONTROLLER( rb_database_controller, c_database_controller );

	RPbdb_DatabaseController_closeAllDatabases( c_database_controller );

	return rb_database_controller;
}
