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

#include "FileSettingsController.h"
#include "SettingsController.h"
#include "FileVerbositySettingsController.h"

#include "Environment.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/FileVerbositySettingsController.h>
#include <rpbdb/FileSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb; 
extern	VALUE	rb_RPbdb_Environment; 
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_FileSettingsController;
extern	VALUE	rb_RPbdb_FileVerbositySettingsController;

void Init_rb_RPbdb_FileVerbositySettingsController()	{

	rb_RPbdb_FileVerbositySettingsController		=	rb_define_class_under(	rb_RPbdb_FileSettingsController, 
																																			"Verbosity",	
																																			rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_FileVerbositySettingsController, 	"new",																rb_RPbdb_FileVerbositySettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"initialize",													rb_RPbdb_FileVerbositySettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"parent_environment",									rb_RPbdb_FileVerbositySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_FileVerbositySettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"parent_settings_controller",					rb_RPbdb_FileVerbositySettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"parent_file_settings_controller",					rb_RPbdb_FileVerbositySettingsController_parentFileSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"display_additional_information_during_open_close_rename_file_operations?",														rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations,													0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"turn_display_additional_information_during_open_close_rename_file_operations_on",														rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn,													0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"turn_display_additional_information_during_open_close_rename_file_operations_off",														rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff,													0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"display_additional_information_during_all_file_operations?",														rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations,													0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"turn_display_additional_information_during_all_file_operations_on",														rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn,													0 	);
	rb_define_method(			rb_RPbdb_FileVerbositySettingsController, 				"turn_display_additional_information_during_all_file_operations_off",														rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_FileVerbositySettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_file_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_file_settings_controller, rb_RPbdb_FileSettingsController ) ) ),
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
		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_file_settings_controller = rb_RPbdb_SettingsController_fileSettingsController( rb_parent_settings_controller );
	}

	RPbdb_FileSettingsController*	c_parent_file_settings_controller;
	C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_parent_file_settings_controller, c_parent_file_settings_controller );
	
	RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller	=	RPbdb_FileSettingsController_verbositySettingsController( c_parent_file_settings_controller );
	
	VALUE	rb_file_verbosity_settings_controller	= RUBY_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( c_file_verbosity_settings_controller );

	rb_iv_set(	rb_file_verbosity_settings_controller,
							RPBDB_RB_FILE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_FILE_SETTINGS_CONTROLLER,
							rb_parent_file_settings_controller );

	VALUE	argv[]	=	{ rb_parent_file_settings_controller };
	rb_obj_call_init(	rb_file_verbosity_settings_controller,
					 1, 
					 argv );
	
	return rb_file_verbosity_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_FileVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_FileVerbositySettingsController_parentEnvironment(	VALUE	rb_file_verbosity_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_FileVerbositySettingsController_parentSettingsController( rb_file_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_FileVerbositySettingsController_parentSettingsController(	VALUE	rb_file_verbosity_settings_controller )	{

	VALUE	rb_parent_file_settings_controller		=	rb_RPbdb_FileVerbositySettingsController_parentFileSettingsController( rb_file_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller					=	rb_RPbdb_FileSettingsController_parentSettingsController( rb_parent_file_settings_controller );
	
	return rb_parent_settings_controller;	
}

/************************************
*  parent_file_settings_controller  *
************************************/

VALUE rb_RPbdb_FileVerbositySettingsController_parentFileSettingsController(	VALUE	rb_file_verbosity_settings_controller )	{

	VALUE	rb_parent_file_settings_controller	=	rb_iv_get(	rb_file_verbosity_settings_controller,
																													RPBDB_RB_FILE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_FILE_SETTINGS_CONTROLLER );

	return rb_parent_file_settings_controller;
}

/*****************************************************************************
*  display_additional_information_during_open_close_rename_file_operations?  *
*****************************************************************************/

//	DB_VERB_FILEOPS         	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( VALUE	rb_file_verbosity_settings_controller )	{

	RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
	C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

	return ( RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringOpenCloseRenameFileOperations( c_file_verbosity_settings_controller )	?	Qtrue
																																							:	Qfalse );
}

	/************************************************************************************
	*  turn_display_additional_information_during_open_close_rename_file_operations_on  *
	************************************************************************************/

	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( VALUE	rb_file_verbosity_settings_controller )	{

		RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOn( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

	/*************************************************************************************
	*  turn_display_additional_information_during_open_close_rename_file_operations_off  *
	*************************************************************************************/

	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( VALUE	rb_file_verbosity_settings_controller )	{

		RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringOpenCloseRenameFileOperationsOff( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

/***************************************************************
*  display_additional_information_during_all_file_operations?  *
***************************************************************/

//	DB_VERB_FILEOPS_ALL     	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( VALUE	rb_file_verbosity_settings_controller )	{

	RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
	C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

	return ( RPbdb_FileVerbositySettingsController_displayAdditionalInformationDuringAllFileOperations( c_file_verbosity_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/**********************************************************************
	*  turn_display_additional_information_during_all_file_operations_on  *
	**********************************************************************/

	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( VALUE	rb_file_verbosity_settings_controller )	{

		RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOn( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}

	/***********************************************************************
	*  turn_display_additional_information_during_all_file_operations_off  *
	***********************************************************************/

	VALUE rb_RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( VALUE	rb_file_verbosity_settings_controller )	{

		RPbdb_FileVerbositySettingsController*	c_file_verbosity_settings_controller;
		C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller );

		RPbdb_FileVerbositySettingsController_turnDisplayAdditionalInformationDuringAllFileOperationsOff( c_file_verbosity_settings_controller );

		return rb_file_verbosity_settings_controller;
	}
