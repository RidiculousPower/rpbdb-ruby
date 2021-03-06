/*
 *		RPbdb::SettingsController::FileSettingsController
 *
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "SettingsController.h"
#include "FileSettingsController.h"
#include "FileVerbositySettingsController.h"

#include "Environment.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/SettingsController.h>
#include <rpbdb/FileSettingsController.h>
#include <rpbdb/FileVerbositySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_FileSettingsController;
extern	VALUE	rb_RPbdb_FileVerbositySettingsController;

void Init_rb_RPbdb_FileSettingsController()	{

	rb_RPbdb_FileSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																																		"File",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_FileSettingsController, 	"new",																rb_RPbdb_FileSettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"initialize",													rb_RPbdb_FileSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_FileSettingsController, 				"parent_environment",									rb_RPbdb_FileSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_FileSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_FileSettingsController,					"parent_settings_controller",					rb_RPbdb_FileSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_FileSettingsController, 				"intermediate_directory_mode",														rb_RPbdb_FileSettingsController_intermediateDirectoryMode,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"set_intermediate_directory_mode",														rb_RPbdb_FileSettingsController_setIntermediateDirectoryMode,													1 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"temp_directory",														rb_RPbdb_FileSettingsController_tempDirectory,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"set_temp_directory",														rb_RPbdb_FileSettingsController_setTempDirectory,													1 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"permit_environment_based_file_naming?",														rb_RPbdb_FileSettingsController_permitEnvironmentBasedFileNaming,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_permit_environment_based_file_naming_on",														rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_permit_environment_based_file_naming_off",														rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"use_environment_home_permissions_for_file_naming?",														rb_RPbdb_FileSettingsController_useEnvironmentHomePermissionsForFileNaming,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_use_environment_home_permissions_for_file_naming_on",														rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_use_environment_home_permissions_for_file_naming_off",														rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"create_if_necessary?",														rb_RPbdb_FileSettingsController_createIfNecessary,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_create_if_necessary_on",														rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_create_if_necessary_off",														rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"is_error_if_database_exists_before_create?",														rb_RPbdb_FileSettingsController_isErrorIfDBExistsBeforeCreate,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_is_error_if_database_exists_before_create_on",														rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_is_error_if_database_exists_before_create_off",														rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"open_read_only?",														rb_RPbdb_FileSettingsController_openReadOnly,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_open_read_only_on",														rb_RPbdb_FileSettingsController_turnOpenReadOnlyOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_open_read_only_off",														rb_RPbdb_FileSettingsController_turnOpenReadOnlyOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"force_removal?",														rb_RPbdb_FileSettingsController_forceRemoval,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_force_removal_on",														rb_RPbdb_FileSettingsController_turnForceRemovalOn,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"turn_force_removal_off",														rb_RPbdb_FileSettingsController_turnForceRemovalOff,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"file_creation_mode",														rb_RPbdb_FileSettingsController_fileCreationMode,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"set_file_creation_mode",														rb_RPbdb_FileSettingsController_setFileCreationMode,													0 	);
	rb_define_method(			rb_RPbdb_FileSettingsController, 				"verbosity_settings_controller",														rb_RPbdb_FileSettingsController_verbositySettingsController,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_FileSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_debug_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_debug_settings_controller == Qnil )	{
		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}

	RPbdb_SettingsController*	c_parent_settings_controller;
	C_RPBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );
	
	RPbdb_FileSettingsController*	c_file_settings_controller	=	RPbdb_SettingsController_fileSettingsController( c_parent_settings_controller );
	
	VALUE	rb_file_settings_controller	= RUBY_RPBDB_FILE_SETTINGS_CONTROLLER( c_file_settings_controller );

	rb_iv_set(	rb_file_settings_controller,
							RPBDB_RB_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_file_settings_controller,
										 1, 
										 argv );
	
	return rb_file_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_FileSettingsController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_FileSettingsController_parentEnvironment(	VALUE	rb_file_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_FileSettingsController_parentSettingsController( rb_file_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_FileSettingsController_parentSettingsController(	VALUE	rb_file_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_file_settings_controller,
																										RPBDB_RB_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********************************
*  intermediate_directory_mode  *
********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_intermediate_dir_mode.html
VALUE rb_RPbdb_FileSettingsController_intermediateDirectoryMode( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	char*	c_intermediate_directory_mode		=	RPbdb_FileSettingsController_intermediateDirectoryMode( c_file_settings_controller );
	VALUE	rb_intermediate_directory_mode	=	rb_str_new2( c_intermediate_directory_mode );

	return rb_intermediate_directory_mode;
}

	/************************************
	*  set_intermediate_directory_mode  *
	************************************/

	VALUE rb_RPbdb_FileSettingsController_setIntermediateDirectoryMode(	VALUE	rb_file_settings_controller, 
																																			VALUE	rb_mode )	{

		VALUE	rb_parent_environment	=	rb_RPbdb_FileSettingsController_parentEnvironment( rb_file_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Intermediate directory mode can only be set before environment is opened." );	
		}

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		char*	c_mode	=	StringValuePtr( rb_mode );

		RPbdb_FileSettingsController_setIntermediateDirectoryMode(	c_file_settings_controller,
																															c_mode );

		return rb_file_settings_controller;
	}

/*******************
*  temp_directory  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tmp_dir.html
VALUE rb_RPbdb_FileSettingsController_tempDirectory( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return rb_str_new2( RPbdb_FileSettingsController_tempDirectory( c_file_settings_controller ) );
}

	/***********************
	*  set_temp_directory  *
	***********************/

	VALUE rb_RPbdb_FileSettingsController_setTempDirectory(	VALUE		rb_file_settings_controller, 
																													VALUE	rb_temp_directory )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

									//	FIX - change to use ruby directory

		char*	c_temp_directory	=	StringValuePtr( rb_temp_directory );

		RPbdb_FileSettingsController_setTempDirectory(	c_file_settings_controller,
																									c_temp_directory );

		return rb_file_settings_controller;
	}

/******************************************
*  permit_environment_based_file_naming?  *
******************************************/

//	DB_USE_ENVIRON          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPbdb_FileSettingsController_permitEnvironmentBasedFileNaming( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_permitEnvironmentBasedFileNaming( c_file_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*************************************************
	*  turn_permit_environment_based_file_naming_on  *
	*************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/**************************************************
	*  turn_permit_environment_based_file_naming_off  *
	**************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/******************************************************
*  use_environment_home_permissions_for_file_naming?  *
******************************************************/

//	DB_USE_ENVIRON_ROOT     http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPbdb_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( c_file_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*************************************************************
	*  turn_use_environment_home_permissions_for_file_naming_on  *
	*************************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/**************************************************************
	*  turn_use_environment_home_permissions_for_file_naming_off  *
	**************************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*************************
*  create_if_necessary?  *
*************************/

//	DB_CREATE               http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPbdb_FileSettingsController_createIfNecessary( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_createIfNecessary( c_file_settings_controller )	?	Qtrue
																							:	Qfalse );
}

	/********************************
	*  turn_create_if_necessary_on  *
	********************************/

	VALUE rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnCreateIfNecessaryOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*********************************
	*  turn_create_if_necessary_off  *
	*********************************/

	VALUE rb_RPbdb_FileSettingsController_turnCreateIfNecessaryOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnCreateIfNecessaryOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/***********************************************
*  is_error_if_database_exists_before_create?  *
***********************************************/

//	DB_EXCL					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPbdb_FileSettingsController_isErrorIfDBExistsBeforeCreate( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_isErrorIfDBExistsBeforeCreate( c_file_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/******************************************************
	*  turn_is_error_if_database_exists_before_create_on  *
	******************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*******************************************************
	*  turn_is_error_if_database_exists_before_create_off  *
	*******************************************************/

	VALUE rb_RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/********************
*  open_read_only?  *
********************/

//	DB_RDONLY					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPbdb_FileSettingsController_openReadOnly( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_openReadOnly( c_file_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/***************************
	*  turn_open_read_only_on  *
	***************************/

	VALUE rb_RPbdb_FileSettingsController_turnOpenReadOnlyOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnOpenReadOnlyOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/****************************
	*  turn_open_read_only_off  *
	****************************/

	VALUE rb_RPbdb_FileSettingsController_turnOpenReadOnlyOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnOpenReadOnlyOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*******************
*  force_removal?  *
*******************/

//	DB_FORCE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_remove.html
VALUE rb_RPbdb_FileSettingsController_forceRemoval( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPbdb_FileSettingsController_forceRemoval( c_file_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/**************************
	*  turn_force_removal_on  *
	**************************/

	VALUE rb_RPbdb_FileSettingsController_turnForceRemovalOn( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnForceRemovalOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/***************************
	*  turn_force_removal_off  *
	***************************/

	VALUE rb_RPbdb_FileSettingsController_turnForceRemovalOff( VALUE	rb_file_settings_controller )	{

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_turnForceRemovalOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/***********************
*  file_creation_mode  *
***********************/

VALUE rb_RPbdb_FileSettingsController_fileCreationMode( VALUE	rb_file_settings_controller )	{

	RPbdb_FileSettingsController*	c_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return INT2FIX( RPbdb_FileSettingsController_fileCreationMode( c_file_settings_controller )	);
}

	/***************************
	*  set_file_creation_mode  *
	***************************/

	VALUE rb_RPbdb_FileSettingsController_setFileCreationMode(	VALUE	rb_file_settings_controller,
	 															VALUE	rb_mode	)	{

		VALUE	rb_parent_environment	=	rb_RPbdb_FileSettingsController_parentEnvironment( rb_file_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "File creation mode can only be set before environment is opened." );	
		}

		RPbdb_FileSettingsController*	c_file_settings_controller;
		C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPbdb_FileSettingsController_setFileCreationMode(	c_file_settings_controller,
															FIX2INT( rb_mode ) );

		return rb_file_settings_controller;
	}

/**********************************
*  verbosity_settings_controller  *
**********************************/

VALUE rb_RPbdb_FileSettingsController_verbositySettingsController( VALUE	rb_file_settings_controller )	{

	VALUE	rb_file_verbosity_settings_controller	=	Qnil;
	
	if ( ( rb_file_verbosity_settings_controller = rb_iv_get(	rb_file_settings_controller,
																														RPBDB_RB_SETTINGS_VARIABLE_FILE_VERBOSITY_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_file_verbosity_settings_controller	=	rb_RPbdb_FileVerbositySettingsController_new(	1,
																																													& rb_file_settings_controller,
																																													rb_RPbdb_FileVerbositySettingsController );
		rb_iv_set(	rb_file_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_FILE_VERBOSITY_SETTINGS_CONTROLLER,
								rb_file_verbosity_settings_controller );
	}
	
	return rb_file_verbosity_settings_controller;
}
