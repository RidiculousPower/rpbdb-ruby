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

#include "rb_RPDB_FileSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_FileVerbositySettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_FileVerbositySettingsController.h>
#include <rpdb/RPDB_FileSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB; 
extern	VALUE	rb_RPDB_Environment; 
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_FileSettingsController;
extern	VALUE	rb_RPDB_FileVerbositySettingsController;

void Init_RPDB_FileVerbositySettingsController()	{

	rb_RPDB_FileVerbositySettingsController		=	rb_define_class_under(	rb_RPDB_FileSettingsController, 
																			"Verbosity",	
																			rb_cObject );

	rb_define_singleton_method(	rb_RPDB_FileVerbositySettingsController, 	"new",																rb_RPDB_FileVerbositySettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"initialize",													rb_RPDB_FileVerbositySettingsController_init,														-1 	);

	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"parent_environment",									rb_RPDB_FileVerbositySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_FileVerbositySettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations,													0 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn,													0 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff,													0 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations,													0 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn,													0 	);
	rb_define_method(			rb_RPDB_FileVerbositySettingsController, 				"shm_key",														rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_FileVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_file_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_file_settings_controller, rb_RPDB_FileSettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent file settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_file_settings_controller == Qnil )	{
		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_file_settings_controller = rb_RPDB_FileSettingsController_verbositySettingsController( rb_parent_settings_controller );
	}

	RPDB_FileSettingsController*	c_parent_file_settings_controller;
	C_RPDB_FILE_SETTINGS_CONTROLLER( rb_parent_file_settings_controller, c_parent_file_settings_controller );
	
	RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller	=	RPDB_FileSettingsController_verbositySettingsController( c_parent_file_settings_controller );
	
	VALUE	rb_file_verbosity_settings_controller	= RUBY_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( c_file_verbosity_settings_controller );

	VALUE	argv[]	=	{ rb_parent_file_settings_controller };
	
	rb_obj_call_init(	rb_file_verbosity_settings_controller,
					 1, 
					 argv );
	
	return rb_file_verbosity_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_FileVerbositySettingsController_init(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_FileVerbositySettingsController_parentEnvironment(	VALUE	rb_file_verbosity_settings_controller )	{

	RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
	C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_FileVerbositySettingsController_parentEnvironment( c_file_verbosity_settings_controller ) );
}

/*************************************************************************
*  displayAdditionalInformationDuringOpenCloseRenameFileOperations  *
*************************************************************************/

//	DB_VERB_FILEOPS         	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( VALUE	rb_file_verbosity_settings_controller )	{

	RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
	C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

	return ( RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( c_file_verbosity_settings_controller )	?	Qtrue
																																							:	Qfalse );
}

	/*****************************************************************************
	*  turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn  *
	*****************************************************************************/

	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( VALUE	rb_file_verbosity_settings_controller )	{

		RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

	/*****************************************************************************
	*  turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff  *
	*****************************************************************************/

	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( VALUE	rb_file_verbosity_settings_controller )	{

		RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

/*************************************************************
*  displayAdditionalInformationDuringAllFileOperations  *
*************************************************************/

//	DB_VERB_FILEOPS_ALL     	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( VALUE	rb_file_verbosity_settings_controller )	{

	RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
	C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

	return ( RPDB_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( c_file_verbosity_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/*****************************************************************
	*  turnDisplayAdditionalInformationDuringAllFileOperationsOn  *
	*****************************************************************/

	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( VALUE	rb_file_verbosity_settings_controller )	{

		RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

	/*****************************************************************
	*  turnDisplayAdditionalInformationDuringAllFileOperationsOff  *
	*****************************************************************/

	VALUE rb_RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( VALUE	rb_file_verbosity_settings_controller )	{

		RPDB_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPDB_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}
