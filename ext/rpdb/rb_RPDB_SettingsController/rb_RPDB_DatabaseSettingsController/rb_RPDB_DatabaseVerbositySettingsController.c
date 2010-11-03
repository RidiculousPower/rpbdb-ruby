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

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseVerbositySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

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
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"initialize",																								rb_RPDB_DatabaseVerbositySettingsController_init,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_environment",																				rb_RPDB_DatabaseVerbositySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerbositySettingsController, 	"environment",																							"parent_environment"	);                                              	
	rb_define_method(						rb_RPDB_DatabaseVerbositySettingsController, 	"parent_database",																					rb_RPDB_DatabaseVerbositySettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerbositySettingsController, 	"database",																									"parent_database"	);                                                  	

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
*  new  *
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

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_verbosity_settings_controller	= RUBY_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( RPDB_DatabaseVerbositySettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_verbosity_settings_controller,
					 1, 
					 argv );
	
	return rb_database_verbosity_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseVerbositySettingsController_init(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentEnvironment(	VALUE	rb_database_verbosity_settings_controller )	{

	RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseVerbositySettingsController_parentEnvironment( c_database_verbosity_settings_controller ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseVerbositySettingsController_parentDatabase(	VALUE	rb_database_verbosity_settings_controller )	{

	RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseVerbositySettingsController_parentDatabase( c_database_verbosity_settings_controller ) );

}

/*****************************************************
*  displayAdditionalInformationForDBRegisterFlag  *
*****************************************************/

//	DB_VERB_REGISTER        	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_verbose.html
VALUE rb_RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( VALUE	rb_database_verbosity_settings_controller )	{

	RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
	C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

	return ( RPDB_DatabaseVerbositySettingsController_displayAdditionalInformationForDBRegisterFlag( c_database_verbosity_settings_controller )	?	Qtrue
																																					:	Qfalse );
}

	/*************************************************************
	*  turnDisplayAdditionalInformationForDBRegisterFlagOn  *
	*************************************************************/

	VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( VALUE	rb_database_verbosity_settings_controller )	{

		RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOn( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}

	/*************************************************************
	*  turnDisplayAdditionalInformationForDBRegisterFlagOff  *
	*************************************************************/

	VALUE rb_RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( VALUE	rb_database_verbosity_settings_controller )	{

		RPDB_DatabaseVerbositySettingsController*	c_database_verbosity_settings_controller;
		C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller );

		RPDB_DatabaseVerbositySettingsController_turnDisplayAdditionalInformationForDBRegisterFlagOff( c_database_verbosity_settings_controller );

		return rb_database_verbosity_settings_controller;
	}
