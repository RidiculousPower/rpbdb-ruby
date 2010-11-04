/*
 *		RPDB::SettingsDirectoryController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DirectorySettingsController.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DebugSettingsController.h>
#include <rpdb/RPDB_DirectorySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DirectorySettingsController;

void Init_RPDB_DirectorySettingsController()	{

	rb_RPDB_DirectorySettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"Directory",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DirectorySettingsController, 	"new",																rb_RPDB_DirectorySettingsController_new,															-1 	);
	rb_define_method(			rb_RPDB_DirectorySettingsController, 				"initialize",													rb_RPDB_DirectorySettingsController_init,															-1 	);

	rb_define_method(			rb_RPDB_DirectorySettingsController, 				"parent_environment",									rb_RPDB_DirectorySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_DirectorySettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_DirectorySettingsController, 				"home_directory",											rb_RPDB_DirectorySettingsController_homeDirectory,													0 	);
	rb_define_alias(			rb_RPDB_DirectorySettingsController, 				"home",																"home_directory"	);
	rb_define_method(			rb_RPDB_DirectorySettingsController, 				"data_directories",										rb_RPDB_DirectorySettingsController_dataDirectories,													0 	);
	rb_define_method(			rb_RPDB_DirectorySettingsController, 				"add_data_directory",									rb_RPDB_DirectorySettingsController_addDataDirectory,													0 	);
	rb_define_alias(			rb_RPDB_DirectorySettingsController, 				"add_data_directories",								"add_data_directory"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DirectorySettingsController_new(	int				argc,
																								VALUE*		args,
																								VALUE			rb_klass_self )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_directory_settings_controller	= RUBY_RPDB_DIRECTORY_SETTINGS_CONTROLLER( RPDB_SettingsController_directorySettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_directory_settings_controller,
							RPDB_RB_DIRECTORY_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_directory_settings_controller,
										1, 
										argv );
	
	return rb_directory_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DirectorySettingsController_init(	int				argc __attribute__ ((unused)),
																								VALUE*		args __attribute__ ((unused)),
																								VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DirectorySettingsController_parentEnvironment(	VALUE	rb_directory_settings_controller )	{
	
	VALUE	rb_parent_environment	=	rb_iv_get(	rb_directory_settings_controller,
																						RPDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT );

	return rb_parent_environment;
}


/*********************
*  homeDirectory  *
*********************/

//	Get home directory
//	Environment's home directory	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_DirectorySettingsController_homeDirectory( VALUE	rb_directory_settings_controller )	{

	RPDB_DirectorySettingsController*	c_directory_settings_controller;
	C_RPDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller );

	return rb_str_new2( RPDB_DirectorySettingsController_homeDirectory( c_directory_settings_controller ) );
}

/************************
*  dataDirectories  *
************************/

//	Get data directories
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_data_dir.html
//
//	Set the path of a directory to be used as the location of the access method database files. Paths specified to the DB->open function will be searched relative to this path. 
//	
//	Paths set using this method are additive, and specifying more than one will result in each specified directory being searched for database files. 
//	If any directories are specified, created database files will always be created in the first path specified.
//
//	If no database directories are specified, database files must be named either by absolute paths or relative to the environment home directory. 
//
//	The DB_ENV->set_data_dir method may not be called after the DB_ENV->open method is called. 
//
//	We can let BDB manage this for us
VALUE rb_RPDB_DirectorySettingsController_dataDirectories( VALUE	rb_directory_settings_controller )	{

	RPDB_DirectorySettingsController*	c_directory_settings_controller;
	C_RPDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller );

									//	FIX - return in array
	RPDB_DirectorySettingsController_dataDirectories( c_directory_settings_controller );

	return rb_directory_settings_controller;
}

/************************
*  dataDirectories  *
************************/

//	Add a data directory
VALUE rb_RPDB_DirectorySettingsController_addDataDirectory(	VALUE	rb_directory_settings_controller, 
																VALUE	rb_directory  )	{

	RPDB_DirectorySettingsController*	c_directory_settings_controller;
	C_RPDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller );

									//	FIX - use ruby dir
	RPDB_DirectorySettingsController_addDataDirectory(	c_directory_settings_controller,
														StringValuePtr( rb_directory ) );
	
	return rb_directory_settings_controller;
}
