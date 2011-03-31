/*
 *		RPbdb_settingsController:RPbdb_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseVerbositySettingsController.h"
#include "DatabaseSettingsController.h"
#include "DatabaseController.h"
#include "Database.h"

#include "SettingsController.h"

#include "RPbdb.h"

#include "Environment.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseVerbositySettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseVerbositySettingsController;

void Init_rb_RPbdb_DatabaseVerbositySettingsController()	{

	rb_RPbdb_DatabaseVerbositySettingsController	=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																							"Verbosity",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseVerbositySettingsController, 	"new",																											rb_RPbdb_DatabaseVerbositySettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"initialize",																								rb_RPbdb_DatabaseVerbositySettingsController_initialize,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"parent_environment",																				rb_RPbdb_DatabaseVerbositySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseVerbositySettingsController, 	"environment",																							"parent_environment"	);                                              	
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"parent_database",																					rb_RPbdb_DatabaseVerbositySettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseVerbositySettingsController, 	"database",																									"parent_database"	);                                                  	
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"parent_settings_controller",																rb_RPbdb_DatabaseVerbositySettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"parent_database_settings_controller",											rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController,				0 	);

	//	FIX - rename functions according to ruby method
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"display_additional_information_for_database_register_flag?",							rb_RPbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_database_register_flag_on",			rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_database_register_flag_off",			rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff,				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_database == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_database_controller	=	rb_RPbdb_Environment_databaseController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );			
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );	
	}
	else if ( rb_parent_database_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseController_settingsController( rb_parent_database_controller );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );	
	}

	RPbdb_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	RPbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller	=	RPbdb_DatabaseSettingsController_verbositySettingsController( c_parent_database_settings_controller );

	VALUE	rb_database_verbosity_settings_controller	= RUBY_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_verbosity_settings_controller,
							RPBDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_verbosity_settings_controller,
										 1, 
										 argv );
	
	return rb_database_verbosity_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_verbosity_settings_controller,
																															RPBDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/**************************************************************
*  display_additional_information_for_database_register_flag  *
**************************************************************/

//	DB_VERB_REGISTER        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller )	{

	RPbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return ( RPbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( c_database_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/**********************************************************************
	*  turn_display_additional_information_for_database_register_flag_on  *
	**********************************************************************/

	VALUE rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller )	{

		RPbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}

	/***********************************************************************
	*  turn_display_additional_information_for_database_register_flag_off  *
	***********************************************************************/

	VALUE rb_RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller )	{

		RPbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}
