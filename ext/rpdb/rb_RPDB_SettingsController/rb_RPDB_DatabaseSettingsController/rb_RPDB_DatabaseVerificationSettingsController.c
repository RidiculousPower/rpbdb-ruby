/*
 *		RPDB::Database::DatabaseVerificationController::DatabaseVerificationSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseVerificationSettingsController.h>
#include "rb_RPDB_DatabaseVerificationSettingsController.h"
#include "rb_RPDB_Environment.h"

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseVerificationSettingsController;

void Init_RPDB_DatabaseVerificationSettingsController()	{

	rb_RPDB_DatabaseVerificationSettingsController	=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Verification",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseVerificationSettingsController, 	"new",																				rb_RPDB_DatabaseVerificationSettingsController_new,									-1 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"initialize",																	rb_RPDB_DatabaseVerificationSettingsController_init,									-1 	);
                    					                                                                                        				
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"parent_environment",													rb_RPDB_DatabaseVerificationSettingsController_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationSettingsController, 	"environment",																"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"parent_database",														rb_RPDB_DatabaseVerificationSettingsController_parentDatabase,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationSettingsController, 	"database",																		"parent_database"	);
                    					                                                                                        				
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"file",																				rb_RPDB_DatabaseVerificationSettingsController_file,									0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"file=",																			rb_RPDB_DatabaseVerificationSettingsController_setFile,								1 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationSettingsController, 	"setFile",																		"file="	);
                    					
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"aggressive_key_data_pair_dump?",							rb_RPDB_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_aggressive_key_data_pair_dump_on",			rb_RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn,		0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_aggressive_key_data_pair_dump_off",			rb_RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff,		0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"printable_characters?",											rb_RPDB_DatabaseVerificationSettingsController_printableCharacters,					0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_printable_characters_on",								rb_RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_printable_characters_off",							rb_RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOff,				0 	);
                    					                                                                                            		
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"skip_order_check?",													rb_RPDB_DatabaseVerificationSettingsController_skipOrderCheck,							0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_skip_order_check_on",										rb_RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_skip_order_check_off",									rb_RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOff,					0 	);
                    					                                                                                            		
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"only_order_check?",													rb_RPDB_DatabaseVerificationSettingsController_onlyOrderCheck,							0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_only_order_check_on",										rb_RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_only_order_check_off",									rb_RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff,					0 	);
                    					                                                                                            		
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"force_order_check?",													rb_RPDB_DatabaseVerificationSettingsController_forceOrderCheck,						0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_force_order_check_on",									rb_RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationSettingsController, 	"turn_force_order_check_off",									rb_RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOff,					0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseVerificationSettingsController_new(	int			argc,
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
			"[ <parent environment > ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_verification_settings_controller	= RUBY_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( RPDB_DatabaseVerificationSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_verification_settings_controller,
					 1, 
					 argv );
	
	return rb_database_verification_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseVerificationSettingsController_init(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseVerificationSettingsController_parentEnvironment(	VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseVerificationSettingsController_parentEnvironment( c_database_verification_settings_controller ) );

}

/***************************************
*  database  *
***************************************/
VALUE rb_RPDB_DatabaseVerificationSettingsController_parentDatabase(	VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseVerificationSettingsController_parentDatabase( c_database_verification_settings_controller ) );

}

/*************
*  file  *
*************/

VALUE rb_RPDB_DatabaseVerificationSettingsController_file(	VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	FILE*	c_file;

	//	FIX - how do we return proper ruby file?
	c_file	=	RPDB_DatabaseVerificationSettingsController_file( c_database_verification_settings_controller );
	
	VALUE	rb_file	=	Qnil;
	
	return rb_file;	
}

/*****************
*  setFile  *
*****************/

VALUE rb_RPDB_DatabaseVerificationSettingsController_setFile(	VALUE	rb_database_verification_settings_controller, 
																															VALUE	rb_data_output_file )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	FILE*	c_error_file	=	(FILE*) rb_funcall(	rb_data_output_file,
																						rb_intern( "fileno" ),
																						0 );

	RPDB_DatabaseVerificationSettingsController_setFile(	c_database_verification_settings_controller,
																												c_error_file );

	return rb_database_verification_settings_controller;
}

/**********************************
*  aggressiveKeyDataPairDump  *
**********************************/

//	DB_AGGRESSIVE						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( RPDB_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( c_database_verification_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/******************************************
	*  turnAggressiveKeyDataPairDumpOn  *
	******************************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( c_database_verification_settings_controller );
		
		return rb_database_verification_settings_controller;
	}

	/******************************************
	*  turnAggressiveKeyDataPairDumpOff  *
	******************************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/******************************
*  printableCharacters  *
******************************/

//	DB_PRINTABLE						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_DatabaseVerificationSettingsController_printableCharacters( VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( RPDB_DatabaseVerificationSettingsController_printableCharacters( c_database_verification_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/**********************************
	*  turnPrintableCharactersOn  *
	**********************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOn( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOn( c_database_verification_settings_controller );
		
		return rb_database_verification_settings_controller;		
	}

	/**********************************
	*  turnPrintableCharactersOff  *
	**********************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOff( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnPrintableCharactersOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**********************
*  skipOrderCheck  *
**********************/

//	DB_NOORDERCHK						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_DatabaseVerificationSettingsController_skipOrderCheck( VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( RPDB_DatabaseVerificationSettingsController_skipOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/******************************
	*  turnSkipOrderCheckOn  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/******************************
	*  turnSkipOrderCheckOff  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**********************
*  onlyOrderCheck  *
**********************/

//	DB_NOORDERCHK						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_DatabaseVerificationSettingsController_onlyOrderCheck( VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( RPDB_DatabaseVerificationSettingsController_onlyOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/******************************
	*  turnOnlyOrderCheckOn  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn(	VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/******************************
	*  turnOnlyOrderCheckOff  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

/**************************
*  forceOrderCheck  *
**************************/

VALUE rb_RPDB_DatabaseVerificationSettingsController_forceOrderCheck(	VALUE	rb_database_verification_settings_controller )	{

	RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
	C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

	return ( RPDB_DatabaseVerificationSettingsController_forceOrderCheck( c_database_verification_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/******************************
	*  turnForceOrderCheckOn  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOn(	VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOn( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}

	/******************************
	*  turnForceOrderCheckOff  *
	******************************/

	VALUE rb_RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOff(	VALUE	rb_database_verification_settings_controller )	{

		RPDB_DatabaseVerificationSettingsController*	c_database_verification_settings_controller;
		C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller );

		RPDB_DatabaseVerificationSettingsController_turnForceOrderCheckOff( c_database_verification_settings_controller );

		return rb_database_verification_settings_controller;
	}
