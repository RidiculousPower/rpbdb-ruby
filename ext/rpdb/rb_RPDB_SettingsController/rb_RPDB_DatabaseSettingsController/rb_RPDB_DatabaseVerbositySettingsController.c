/*
 *		Rbdb_settingsController:Rbdb_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseVerbositySettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseVerbositySettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseVerbositySettingsController;

void Init_Rbdb_DatabaseVerbositySettingsController()	{

	rb_Rbdb_DatabaseVerbositySettingsController	=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																							"Verbosity",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseVerbositySettingsController, 	"new",																											rb_Rbdb_DatabaseVerbositySettingsController_new,										-1 	);
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"initialize",																								rb_Rbdb_DatabaseVerbositySettingsController_initialize,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"parent_environment",																				rb_Rbdb_DatabaseVerbositySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseVerbositySettingsController, 	"environment",																							"parent_environment"	);                                              	
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"parent_database",																					rb_Rbdb_DatabaseVerbositySettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseVerbositySettingsController, 	"database",																									"parent_database"	);                                                  	
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"parent_settings_controller",																rb_Rbdb_DatabaseVerbositySettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"parent_database_settings_controller",											rb_Rbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController,				0 	);

	//	FIX - rename functions according to ruby method
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"display_additional_information_for_database_register_flag?",							rb_Rbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_database_register_flag_on",			rb_Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerbositySettingsController, 	"turn_display_additional_information_for_database_register_flag_off",			rb_Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff,				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseVerbositySettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ) ) ),
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
		
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_database_controller	=	rb_Rbdb_Environment_databaseController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );			
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );	
	}
	else if ( rb_parent_database_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseController_settingsController( rb_parent_database_controller );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );	
	}

	Rbdb_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	Rbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller	=	Rbdb_DatabaseSettingsController_verbositySettingsController( c_parent_database_settings_controller );

	VALUE	rb_database_verbosity_settings_controller	= RUBY_Rbdb_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_verbosity_settings_controller,
							Rbdb_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseVerbositySettingsController_parentSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController( rb_database_verbosity_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseVerbositySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verbosity_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_verbosity_settings_controller,
																															Rbdb_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/**************************************************************
*  display_additional_information_for_database_register_flag  *
**************************************************************/

//	DB_VERB_REGISTER        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_Rbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller )	{

	Rbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_Rbdb_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return ( Rbdb_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( c_database_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/**********************************************************************
	*  turn_display_additional_information_for_database_register_flag_on  *
	**********************************************************************/

	VALUE rb_Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller )	{

		Rbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_Rbdb_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}

	/***********************************************************************
	*  turn_display_additional_information_for_database_register_flag_off  *
	***********************************************************************/

	VALUE rb_Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller )	{

		Rbdb_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_Rbdb_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		Rbdb_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}
