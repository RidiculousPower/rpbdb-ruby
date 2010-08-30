/*
 *		RPDB::SettingsController::FileSettingsController
 *
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_FileSettingsController.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_FileSettingsController.h>
#include <rpdb/RPDB_FileVerbositySettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_FileSettingsController;
extern	VALUE	rb_RPDB_FileVerbositySettingsController;

void Init_RPDB_FileSettingsController()	{

	rb_RPDB_FileSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"MemoryPool",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_FileSettingsController, 	"new",																rb_RPDB_FileSettingsController_init,														1 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"initialize",													rb_RPDB_FileSettingsController_init,														1 	);

	rb_define_method(			rb_RPDB_FileSettingsController, 				"parent_environment",									rb_RPDB_FileSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_FileSettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_intermediateDirectoryMode,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_setIntermediateDirectoryMode,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_tempDirectory,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_setTempDirectory,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_permitEnvironmentBasedFileNaming,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_useEnvironmentHomePermissionsForFileNaming,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_createIfNecessary,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnCreateIfNecessaryOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnCreateIfNecessaryOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_isErrorIfDBExistsBeforeCreate,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_openReadOnly,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnOpenReadOnlyOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnOpenReadOnlyOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_forceRemoval,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnForceRemovalOn,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_turnForceRemovalOff,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_fileCreationMode,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_setFileCreationMode,													0 	);
	rb_define_method(			rb_RPDB_FileSettingsController, 				"shm_key",														rb_RPDB_FileSettingsController_verbositySettingsController,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_FileSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																					VALUE	rb_parent_settings_controller )	{

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_file_settings_controller	= RUBY_RPDB_FILE_SETTINGS_CONTROLLER( RPDB_FileSettingsController_new( c_parent_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_settings_controller;
	
	rb_obj_call_init(	rb_file_settings_controller,
					 1, 
					 argv );
	
	return rb_file_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_FileSettingsController_init(	VALUE	rb_file_settings_controller,
																						VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{
	
	return rb_file_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_FileSettingsController_parentEnvironment(	VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_FileSettingsController_parentEnvironment( c_file_settings_controller ) );
}

/*********************************
*  intermediateDirectoryMode  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_intermediate_dir_mode.html
VALUE rb_RPDB_FileSettingsController_intermediateDirectoryMode( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_intermediateDirectoryMode( c_file_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/*************************************
	*  setIntermediateDirectoryMode  *
	*************************************/

	VALUE rb_RPDB_FileSettingsController_setIntermediateDirectoryMode(	VALUE	rb_file_settings_controller, 
																		VALUE	rb_mode )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_setIntermediateDirectoryMode(	c_file_settings_controller,
																	StringValuePtr( rb_mode ) );

		return rb_file_settings_controller;
	}

/*********************
*  tempDirectory  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_tmp_dir.html
VALUE rb_RPDB_FileSettingsController_tempDirectory( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return rb_str_new2( RPDB_FileSettingsController_tempDirectory( c_file_settings_controller ) );
}

	/*************************
	*  setTempDirectory  *
	*************************/

	VALUE rb_RPDB_FileSettingsController_setTempDirectory(	VALUE		rb_file_settings_controller, 
																													VALUE	rb_temp_directory )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

									//	FIX - change to use ruby directory

		char*	c_temp_directory	=	StringValuePtr( rb_temp_directory );

		RPDB_FileSettingsController_setTempDirectory(	c_file_settings_controller,
																									c_temp_directory );

		return rb_file_settings_controller;
	}

/*********************************
*  permitEnvironmentNaming  *
*********************************/

//	DB_USE_ENVIRON          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_FileSettingsController_permitEnvironmentBasedFileNaming( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_permitEnvironmentBasedFileNaming( c_file_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/*************************************
	*  turnPermitEnvironmentNamingOn  *
	*************************************/

	VALUE rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*************************************
	*  turnPermitEnvironmentNamingOff  *
	*************************************/

	VALUE rb_RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnPermitEnvironmentBasedFileNamingOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/****************************
*  useEnvironmentHome  *
****************************/

//	DB_USE_ENVIRON_ROOT     http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_useEnvironmentHomePermissionsForFileNaming( c_file_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*********************************
	*  turnUseEnvironmentHomeOn  *
	*********************************/

	VALUE rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*********************************
	*  turnUseEnvironmentHomeOff  *
	*********************************/

	VALUE rb_RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnUseEnvironmentHomePermissionsForFileNamingOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*********************************
*  createIfNecessary  *
*********************************/

//	DB_CREATE               http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_FileSettingsController_createIfNecessary( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_createIfNecessary( c_file_settings_controller )	?	Qtrue
																							:	Qfalse );
}

	/*************************************
	*  turnCreateIfNecessaryOn  *
	*************************************/

	VALUE rb_RPDB_FileSettingsController_turnCreateIfNecessaryOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnCreateIfNecessaryOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/**************************************
	*  turnCreateIfNecessaryOff  *
	**************************************/

	VALUE rb_RPDB_FileSettingsController_turnCreateIfNecessaryOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnCreateIfNecessaryOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/**************************************
*  isErrorIfDBExistsBeforeCreate  *
**************************************/

//	DB_EXCL					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_FileSettingsController_isErrorIfDBExistsBeforeCreate( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_isErrorIfDBExistsBeforeCreate( c_file_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/********************************************
	*  turnIsErrorIfDBExistsBeforeCreateOn  *
	********************************************/

	VALUE rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*********************************************
	*  turnIsErrorIfDBExistsBeforeCreateOff  *
	*********************************************/

	VALUE rb_RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnIsErrorIfDBExistsBeforeCreateOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*************************
*  openReadOnly  *
*************************/

//	DB_RDONLY					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_FileSettingsController_openReadOnly( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_openReadOnly( c_file_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/********************************
	*  turnOpenReadOnlyOn  *
	********************************/

	VALUE rb_RPDB_FileSettingsController_turnOpenReadOnlyOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnOpenReadOnlyOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/********************************
	*  turnOpenReadOnlyOff  *
	********************************/

	VALUE rb_RPDB_FileSettingsController_turnOpenReadOnlyOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnOpenReadOnlyOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*************************
*  forceRemoval  *
*************************/

//	DB_FORCE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_remove.html
VALUE rb_RPDB_FileSettingsController_forceRemoval( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return ( RPDB_FileSettingsController_forceRemoval( c_file_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/*********************************
	*  turnForceRemovalOn  *
	*********************************/

	VALUE rb_RPDB_FileSettingsController_turnForceRemovalOn( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnForceRemovalOn( c_file_settings_controller );

		return rb_file_settings_controller;
	}

	/*********************************
	*  turnForceRemovalOff  *
	*********************************/

	VALUE rb_RPDB_FileSettingsController_turnForceRemovalOff( VALUE	rb_file_settings_controller )	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_turnForceRemovalOff( c_file_settings_controller );

		return rb_file_settings_controller;
	}

/*************************
*  fileCreationMode  *
*************************/

VALUE rb_RPDB_FileSettingsController_fileCreationMode( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return INT2FIX( RPDB_FileSettingsController_fileCreationMode( c_file_settings_controller )	);
}

	/****************************
	*  setFileCreationMode  *
	****************************/

	VALUE rb_RPDB_FileSettingsController_setFileCreationMode(	VALUE	rb_file_settings_controller,
	 															VALUE	rb_mode	)	{

		RPDB_FileSettingsController*	c_file_settings_controller;
		C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

		RPDB_FileSettingsController_setFileCreationMode(	c_file_settings_controller,
															FIX2INT( rb_mode ) );

		return rb_file_settings_controller;
	}

/*************************************
*  verbositySettingsController  *
*************************************/

VALUE rb_RPDB_FileSettingsController_verbositySettingsController( VALUE	rb_file_settings_controller )	{

	RPDB_FileSettingsController*	c_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller );

	return RUBY_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( RPDB_FileSettingsController_verbositySettingsController( c_file_settings_controller ) );
}
