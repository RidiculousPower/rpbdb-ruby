/*
 *		RPDB::DatabaseController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseController.h"

#include "rb_RPDB.h"
#include "rb_RPDB_internal.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_Environment.h"

#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseController.h>

#include <rpdb/RPDB_RuntimeStorageController.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;

void Init_RPDB_DatabaseController()	{

	rb_RPDB_DatabaseController	=	rb_define_class_under(	rb_RPDB_Environment, 
																												"DatabaseController",			
																												rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseController, 	"new",														rb_RPDB_DatabaseController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseController, 	"initialize",											rb_RPDB_DatabaseController_init,										-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_DatabaseController, 	"settings_controller",						rb_RPDB_DatabaseController_settingsController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"settings",												"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"set",														"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"set_to",													"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"is_set_to",											"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseController, 	"parent_environment",							rb_RPDB_DatabaseController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"environment",										"parent_environment"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseController, 	"new_database",										rb_RPDB_DatabaseController_newDatabase,							1 	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"new",														"new_database"	);
	rb_define_method(						rb_RPDB_DatabaseController, 	"close_all_databases",						rb_RPDB_DatabaseController_closeAllDatabases,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseController, 	"close_all",											"close_all_databases"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_DatabaseController_new(	int			argc,
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
		rb_parent_environment	=	rb_RPDB_defaultEnvironment( rb_mRPDB );
	}
	
	if ( rb_parent_environment == Qnil )	{
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND );
	}
	
	/*------------------------------------------------------*/

	RPDB_Environment*	c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	RPDB_DatabaseController*	c_database_controller	=	RPDB_Environment_databaseController( c_parent_environment );

	VALUE	rb_database_controller	=	RUBY_RPDB_DATABASE_CONTROLLER( c_database_controller );

	//	store reference to parent environment
	rb_iv_set(	rb_database_controller,
							RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );
	
	return rb_database_controller;	
}
	
/*********
*  init  *
*********/
	
VALUE rb_RPDB_DatabaseController_init(	int			argc __attribute__((unused)),
																				VALUE*	args __attribute__((unused)),
																				VALUE		rb_database_controller )	{

	return rb_database_controller;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPDB_DatabaseController_settingsController(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_RPDB_DatabaseController_parentEnvironment( rb_database_controller );
	
	VALUE	rb_settings_controller					=	rb_RPDB_Environment_settingsController( rb_parent_environment );
	VALUE	rb_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_settings_controller );
	
	return rb_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_RPDB_DatabaseController_parentEnvironment(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_database_controller,
																						RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_ENVIRONMENT );

	return rb_parent_environment;
}

/*****************
*  new_database  *
*  new           *
*****************/

//	Return a name that has been created or creates it if necessary
VALUE rb_RPDB_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																							VALUE		rb_database_name )	{
	
	VALUE	args[ 2 ];
	args[ 0 ]	=	rb_database_name;
	args[ 1 ] = rb_database_controller;
	VALUE	rb_database	=	rb_RPDB_Database_new(	2,
																						args,
																						rb_RPDB_Database );
		
	return rb_database;
}

/************************
*  close_all_databases  *
*  close_all            *
************************/

//	Close all Databases
VALUE rb_RPDB_DatabaseController_closeAllDatabases( VALUE rb_database_controller )	{

	RPDB_DatabaseController*	c_database_controller;
	C_RPDB_DATABASE_CONTROLLER( rb_database_controller, c_database_controller );

	RPDB_DatabaseController_closeAllDatabases( c_database_controller );

	return rb_database_controller;
}
