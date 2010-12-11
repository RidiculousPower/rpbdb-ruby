/*
 *		Rbdb::Database::DatabaseVerificationController::DatabaseVerificationSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseVerificationSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb_DatabaseSettingsController.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseVerificationSettingsController.h>

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
extern	VALUE	rb_Rbdb_DatabaseVerificationSettingsController;

void Init_rb_Rbdb_DatabaseVerificationSettingsController()	{

	rb_Rbdb_DatabaseVerificationSettingsController	=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																						"Verification",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseVerificationSettingsController, 	"new",																				rb_Rbdb_DatabaseVerificationSettingsController_new,									-1 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"initialize",																	rb_Rbdb_DatabaseVerificationSettingsController_initialize,									-1 	);
                    					                                                                                        				
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"parent_environment",													rb_Rbdb_DatabaseVerificationSettingsController_parentEnvironment,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseVerificationSettingsController, 	"environment",																"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"parent_database",														rb_Rbdb_DatabaseVerificationSettingsController_parentDatabase,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseVerificationSettingsController, 	"database",																		"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"parent_settings_controller",									rb_Rbdb_DatabaseVerificationSettingsController_parentSettingsController,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"parent_database_settings_controller",				rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController,							0 	);
                    					                                                                                        				
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"file",																				rb_Rbdb_DatabaseVerificationSettingsController_file,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"set_file",																			rb_Rbdb_DatabaseVerificationSettingsController_setFile,								1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"aggressive_key_data_pair_dump?",							rb_Rbdb_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_aggressive_key_data_pair_dump_on",			rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn,		0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_aggressive_key_data_pair_dump_off",			rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff,		0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"printable_characters?",											rb_Rbdb_DatabaseVerificationSettingsController_printableCharacters,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_printable_characters_on",								rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOn,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_printable_characters_off",							rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOff,				0 	);
                    					                                                                                            		
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"skip_order_check?",													rb_Rbdb_DatabaseVerificationSettingsController_skipOrderCheck,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_skip_order_check_on",										rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOn,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_skip_order_check_off",									rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOff,					0 	);
                    					                                                                                            		
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"only_order_check?",													rb_Rbdb_DatabaseVerificationSettingsController_onlyOrderCheck,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_only_order_check_on",										rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_only_order_check_off",									rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff,					0 	);
                    					                                                                                            		
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"force_order_check?",													rb_Rbdb_DatabaseVerificationSettingsController_forceOrderCheck,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_force_order_check_on",									rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOn,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseVerificationSettingsController, 	"turn_force_order_check_off",									rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOff,					0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_new(	int			argc,
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
	C_RBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller	=	Rbdb_DatabaseSettingsController_verificationSettingsController( c_parent_database_settings_controller );

	VALUE	rb_database_verification_settings_controller	= RUBY_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( c_database_verification_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_verification_settings_controller,
							RBDB_RB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_verification_settings_controller,
										 1, 
										 argv );
	
	return rb_database_verification_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentEnvironment(	VALUE	rb_database_verification_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController( rb_database_verification_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentDatabase(	VALUE	rb_database_verification_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController( rb_database_verification_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentSettingsController(	VALUE	rb_database_verification_settings_controller )	{
	
	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController( rb_database_verification_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;	
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verification_settings_controller )	{
	
	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_verification_settings_controller,
																															RBDB_RB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*********
*  file  *
*********/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_file(	VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	FILE*	c_file;

	//	FIX - how do we return proper ruby file?
	c_file	=	Rbdb_DatabaseVerificationSettingsController_file( c_database_verification_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;	
}

/*************
*  set_file  *
*************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_setFile(	VALUE	rb_database_verification_settings_controller, 
																															VALUE	rb_data_output_file )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	FILE*	c_error_file	=	(FILE*) rb_funcall(	rb_data_output_file,
																						rb_intern( "fileno" ),
																						0 );

	Rbdb_DatabaseVerificationSettingsController_setFile(	c_database_verification_settings_controller,
																												c_error_file );

	return rb_database_verification_settings_controller;
}

/***********************************
*  aggressive_key_data_pair_dump?  *
***********************************/

//	DB_AGGRESSIVE						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_Rbdb_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( Rbdb_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( c_database_verification_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/******************************************
	*  turn_aggressive_key_data_pair_dump_on  *
	******************************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( c_database_verification_settings_controller );
		
		return rb_database_verification_settings_controller;
	}

	/*******************************************
	*  turn_aggressive_key_data_pair_dump_off  *
	*******************************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**************************
*  printable_characters?  *
**************************/

//	DB_PRINTABLE						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_Rbdb_DatabaseVerificationSettingsController_printableCharacters( VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( Rbdb_DatabaseVerificationSettingsController_printableCharacters( c_database_verification_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*********************************
	*  turn_printable_characters_on  *
	*********************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOn( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOn( c_database_verification_settings_controller );
		
		return rb_database_verification_settings_controller;		
	}

	/**********************************
	*  turn_printable_characters_off  *
	**********************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOff( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**********************
*  skip_order_check?  *
**********************/

//	DB_NOORDERCHK						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_Rbdb_DatabaseVerificationSettingsController_skipOrderCheck( VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( Rbdb_DatabaseVerificationSettingsController_skipOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*****************************
	*  turn_skip_order_check_on  *
	*****************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/******************************
	*  turn_skip_order_check_off  *
	******************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**********************
*  only_order_check?  *
**********************/

//	DB_NOORDERCHK						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_Rbdb_DatabaseVerificationSettingsController_onlyOrderCheck( VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( Rbdb_DatabaseVerificationSettingsController_onlyOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*****************************
	*  turn_only_order_check_on  *
	*****************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn(	VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/******************************
	*  turn_only_order_check_off  *
	******************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/***********************
*  force_order_check?  *
***********************/

VALUE rb_Rbdb_DatabaseVerificationSettingsController_forceOrderCheck(	VALUE	rb_database_verification_settings_controller )	{

	Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( Rbdb_DatabaseVerificationSettingsController_forceOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/******************************
	*  turn_force_order_check_on  *
	******************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOn(	VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/*******************************
	*  turn_force_order_check_off  *
	*******************************/

	VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOff(	VALUE	rb_database_verification_settings_controller )	{

		Rbdb_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}
