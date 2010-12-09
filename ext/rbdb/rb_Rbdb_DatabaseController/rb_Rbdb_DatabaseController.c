/*
 *		Rbdb::DatabaseController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseController.h"

#include "rb_Rbdb.h"
#include "rb_Rbdb_internal.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_Environment.h"

#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseController.h>

#include <rbdb/Rbdb_RuntimeStorageController.h>

#include <rbdb/Rbdb_DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;

void Init_Rbdb_DatabaseController()	{

	rb_Rbdb_DatabaseController	=	rb_define_class_under(	rb_Rbdb_Database, 
																												"Controller",			
																												rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseController, 	"new",														rb_Rbdb_DatabaseController_new,											-1 	);
	rb_define_method(						rb_Rbdb_DatabaseController, 	"initialize",											rb_Rbdb_DatabaseController_initialize,										-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_DatabaseController, 	"settings_controller",						rb_Rbdb_DatabaseController_settingsController,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"settings",												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"set",														"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"set_to",													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"is_set_to",											"settings_controller"	);
	rb_define_method(						rb_Rbdb_DatabaseController, 	"parent_environment",							rb_Rbdb_DatabaseController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"environment",										"parent_environment"	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseController, 	"new_database",										rb_Rbdb_DatabaseController_newDatabase,							1 	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"new",														"new_database"	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"database",												"new_database"	);
	rb_define_method(						rb_Rbdb_DatabaseController, 	"close_all_databases",						rb_Rbdb_DatabaseController_closeAllDatabases,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseController, 	"close_all",											"close_all_databases"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseController_new(	int			argc,
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment == Qnil )	{
			rb_raise( rb_eArgError, Rbdb_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND );
	}
	
	/*------------------------------------------------------*/

	Rbdb_Environment*	c_parent_environment;
	C_Rbdb_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	Rbdb_DatabaseController*	c_database_controller	=	Rbdb_Environment_databaseController( c_parent_environment );

	VALUE	rb_database_controller	=	RUBY_Rbdb_DATABASE_CONTROLLER( c_database_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_controller,
							Rbdb_RB_ALL_VARIABLE_PARENT_ENVIRONMENT,
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
	
VALUE rb_Rbdb_DatabaseController_initialize(	int			argc __attribute__((unused)),
																				VALUE*	args __attribute__((unused)),
																				VALUE		rb_database_controller )	{

	return rb_database_controller;
}

/************************
*  settings_controller  *
************************/
VALUE rb_Rbdb_DatabaseController_settingsController(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_database_controller );
	
	VALUE	rb_settings_controller					=	rb_Rbdb_Environment_settingsController( rb_parent_environment );
	VALUE	rb_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_settings_controller );
	
	return rb_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_Rbdb_DatabaseController_parentEnvironment(	VALUE rb_database_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_database_controller,
																						Rbdb_RB_ALL_VARIABLE_PARENT_ENVIRONMENT );

	return rb_parent_environment;
}

/*****************
*  self.new_database  *
*  self.new           *
*****************/

//	Return a name that has been created or creates it if necessary
VALUE rb_Rbdb_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																							VALUE		rb_database_name )	{
	
	VALUE	args[ 2 ];
	args[ 0 ]	=	rb_database_name;
	args[ 1 ] = rb_database_controller;
	VALUE	rb_database	=	rb_Rbdb_Database_new(	2,
																						args,
																						rb_Rbdb_Database );
		
	return rb_database;
}

/************************
*  close_all_databases  *
*  close_all            *
************************/

//	Close all Databases
VALUE rb_Rbdb_DatabaseController_closeAllDatabases( VALUE rb_database_controller )	{

	Rbdb_DatabaseController*	c_database_controller;
	C_Rbdb_DATABASE_CONTROLLER( rb_database_controller, c_database_controller );

	Rbdb_DatabaseController_closeAllDatabases( c_database_controller );

	return rb_database_controller;
}
