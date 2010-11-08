/*
 *		RPDB_settingsController:RPDB_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseVerbositySettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseVerbositySettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseVerbositySettingsController;

void Init_RPDB_DatabaseVerbositySettingsController()	{

	rb_RPDB_DatabaseVerbositySettingsController	=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																							"Verbosity",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseVerbositySettingsController, 	"new",																											rb_RPDB_DatabaseVerbositySettingsController_new,										-1 	);
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"initialize",																								rb_RPDB_DatabaseVerbositySettingsController_initialize,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_environment",																				rb_RPDB_DatabaseVerbositySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerbositySettingsController, 	"environment",																							"parent_environment"	);                                              	
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_database",																					rb_RPDB_DatabaseVerbositySettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerbositySettingsController, 	"database",																									"parent_database"	);                                                  	
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_settings_controller",																rb_RPDB_DatabaseVerbositySettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_database_settings_controller",											rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController,				0 	);

	//	FIX - rename functions according to ruby method
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"display_additional_information_for_register?",							rb_RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_register_on",			rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_register_off",			rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff,				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ) ) ),
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
		
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );			
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );	
	}
	else if ( rb_parent_database_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_DatabaseController_settingsController( rb_parent_database_controller );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );	
	}

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller	=	RPDB_DatabaseSettingsController_verbositySettingsController( c_parent_database_settings_controller );

	VALUE	rb_database_verbosity_settings_controller	= RUBY_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_verbosity_settings_controller,
							RPDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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

VALUE rb_RPDB_DatabaseVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_parentSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_verbosity_settings_controller,
																															RPDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/**************************************************************
*  display_additional_information_for_database_register_flag  *
**************************************************************/

//	DB_VERB_REGISTER        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller )	{

	RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return ( RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( c_database_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/**********************************************************************
	*  turn_display_additional_information_for_database_register_flag_on  *
	**********************************************************************/

	VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller )	{

		RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}

	/***********************************************************************
	*  turn_display_additional_information_for_database_register_flag_off  *
	***********************************************************************/

	VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller )	{

		RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}
