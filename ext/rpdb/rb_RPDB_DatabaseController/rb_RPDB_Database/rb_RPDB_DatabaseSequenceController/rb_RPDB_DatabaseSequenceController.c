/*
 *		Rbdb::DatabaseController::Database::SequenceController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseSequenceController.h"
#include "rb_Rbdb_DatabaseController.h"

#include "rb_Rbdb_Database.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseSequenceController.h>
#include <rbdb/Rbdb_DatabaseSequence.h>

#include <rbdb/Rbdb_DatabaseSequenceSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseSequence;
extern	VALUE	rb_Rbdb_DatabaseSequenceController;
extern	VALUE	rb_Rbdb_DatabaseSequenceSettingsController;

void Init_Rbdb_DatabaseSequenceController()	{

	rb_Rbdb_DatabaseSequenceController		=	rb_define_class_under(	rb_Rbdb_Database, 
																																	"SequenceController",				
																																	rb_cObject );
	
	rb_define_singleton_method(	rb_Rbdb_DatabaseSequenceController, 	"new",																	rb_Rbdb_DatabaseSequenceController_new,															-1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceController, 	"initialize",														rb_Rbdb_DatabaseSequenceController_initialize,														-1 	);
	                                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseSequenceController, 	"settings_controller",									rb_Rbdb_DatabaseSequenceController_settingsController,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSequenceController, 	"parent_environment",										rb_Rbdb_DatabaseSequenceController_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_Rbdb_DatabaseSequenceController, 	"parent_database",											rb_Rbdb_DatabaseSequenceController_parentDatabase,									0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"database",															"parent_database"	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceController, 	"create_sequence",											rb_Rbdb_DatabaseSequenceController_createSequence,									-1 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"sequence",															"create_sequence"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceController, 	"[]",																		"create_sequence"	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseSequenceController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_database_sequence_controller_class __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database	=	Qnil;

	/*------------------------------------------------------*/

	VALUE	rb_parent_database_or_environment				=	Qnil;
	VALUE	rb_parent_database_name_in_environment	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_parent_database_or_environment,
								& rb_parent_database_name_in_environment );

	if ( rb_parent_database_name_in_environment == Qnil )	{
		rb_parent_database = rb_parent_database_or_environment;
	}
	else {
		VALUE	rb_parent_environment		=	rb_parent_database_or_environment;
		VALUE	rb_database_controller	=	rb_Rbdb_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_Rbdb_Database_new( 1,
																								& rb_database_controller,
																								rb_Rbdb_Database );
	}

	/*------------------------------------------------------*/
	
	
	Rbdb_Database*		c_parent_database;
	C_Rbdb_DATABASE( rb_parent_database, c_parent_database );
	
	Rbdb_DatabaseSequenceController*	c_sequence_controller	=	Rbdb_Database_sequenceController( c_parent_database );
	
	VALUE	rb_database_sequence_controller	=	RUBY_Rbdb_DATABASE_SEQUENCE_CONTROLLER( c_sequence_controller );	
	
	//	store reference to parent
	rb_iv_set(	rb_database_sequence_controller,
							Rbdb_RB_DATABASE_SEQUENCE_CONTROLLER_VARIABLE_PARENT_DATABASE,
							rb_parent_database );
	
	rb_obj_call_init(	rb_database_sequence_controller,
										1, 
										& rb_parent_database );
	
	return rb_database_sequence_controller;		
}


/*********
*  initialize  * 
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_Rbdb_DatabaseSequenceController_initialize(	int			argc __attribute__ ((unused)),
																								VALUE*	args __attribute__ ((unused)),
																								VALUE		rb_database_sequence_controller )	{

	return rb_database_sequence_controller;
}

/************************
*  settings_controller  *
************************/

VALUE rb_Rbdb_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_database_sequence_settings_controller	=	Qnil;
	
	if ( ( rb_database_sequence_settings_controller = rb_iv_get(	rb_database_sequence_controller,
																																Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_DatabaseSequenceController*		c_database_sequence_controller;
		C_Rbdb_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );
	
		Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller	=	Rbdb_DatabaseSequenceController_settingsController( c_database_sequence_controller );

		rb_database_sequence_settings_controller	=	RUBY_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller );

		rb_iv_set(	rb_database_sequence_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER,
								rb_database_sequence_settings_controller );
	}

	return rb_database_sequence_settings_controller;
}

/****************
*  environment  *
****************/

VALUE rb_Rbdb_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_parent_database_controller	=	rb_Rbdb_DatabaseSequenceController_parentDatabaseController( rb_database_sequence_controller );
	VALUE	rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_database_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSequenceController_parentDatabaseController(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_parent_database						=	rb_Rbdb_DatabaseSequenceController_parentDatabase( rb_database_sequence_controller );
	VALUE	rb_parent_database_controller	=	rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_parent_database	=		rb_iv_get(	rb_database_sequence_controller,
																						Rbdb_RB_ALL_VARIABLE_PARENT_DATABASE );
	return rb_parent_database;
}

/********************
*  create_sequence  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_Rbdb_DatabaseSequenceController_createSequence(	int			argc __attribute__((unused)),
																													VALUE*	argv __attribute__((unused)),
																													VALUE		rb_database_sequence_controller )	{

		
	//	FIX - parse args

	Rbdb_DatabaseSequenceController*		c_database_sequence_controller;
	C_Rbdb_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );

	return RUBY_Rbdb_DATABASE_SEQUENCE( Rbdb_DatabaseSequenceController_createSequence( c_database_sequence_controller ) );	
}


