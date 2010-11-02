/*
 *		RPDB::DatabaseController::Database::SequenceController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseSequenceController.h"

#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseSequenceController.h>
#include <rpdb/RPDB_DatabaseSequence.h>

#include <rpdb/RPDB_DatabaseSequenceSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSequence;
extern	VALUE	rb_RPDB_DatabaseSequenceController;
extern	VALUE	rb_RPDB_DatabaseSequenceSettingsController;

void Init_RPDB_DatabaseSequenceController()	{

	rb_RPDB_DatabaseSequenceController		=	rb_define_class_under(	rb_RPDB_Database, 
																																	"SequenceController",				
																																	rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseSequenceController, 	"new",																	rb_RPDB_DatabaseSequenceController_new,															-1 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"initialize",														rb_RPDB_DatabaseSequenceController_init,														-1 	);
	                                                                                          				
	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"settings_controller",									rb_RPDB_DatabaseSequenceController_settingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"parent_environment",										rb_RPDB_DatabaseSequenceController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"parent_database",											rb_RPDB_DatabaseSequenceController_parentDatabase,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"database",															"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"create_sequence",											rb_RPDB_DatabaseSequenceController_createSequence,									-1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"sequence",															"create_sequence"	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceController, 	"[]",																		"create_sequence"	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  * 
********/

VALUE rb_RPDB_DatabaseSequenceController_new(	int			argc,
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
		VALUE	rb_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_RPDB_Database_new( 1,
																								& rb_database_controller,
																								rb_RPDB_Database );
	}

	/*------------------------------------------------------*/
	
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	RPDB_DatabaseSequenceController*	c_sequence_controller	=	RPDB_Database_sequenceController( c_parent_database );
	
	VALUE	rb_database_sequence_controller	=	RUBY_RPDB_DATABASE_SEQUENCE_CONTROLLER( c_sequence_controller );	
	
	rb_iv_set(	rb_database_sequence_controller,
							RPDB_RB_ALL_VARIABLE_PARENT_DATABASE,
							rb_parent_database );
	
	rb_obj_call_init(	rb_database_sequence_controller,
										1, 
										& rb_parent_database );
	
	return rb_database_sequence_controller;		
}


/*********
*  init  * 
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPDB_DatabaseSequenceController_init(	int			argc __attribute__ ((unused)),
																								VALUE*	args __attribute__ ((unused)),
																								VALUE		rb_database_sequence_controller )	{

	return rb_database_sequence_controller;
}

/************************
*  settings_controller  *
************************/

VALUE rb_RPDB_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_database_sequence_settings_controller	=	Qnil;
	
	if ( ( rb_database_sequence_settings_controller = rb_iv_get(	rb_database_sequence_controller,
																																RPDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_DatabaseSequenceController*		c_database_sequence_controller;
		C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );
	
		RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller	=	RPDB_DatabaseSequenceController_settingsController( c_database_sequence_controller );

		rb_database_sequence_settings_controller	=	RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller );

		rb_iv_set(	rb_database_sequence_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER,
								rb_database_sequence_settings_controller );
	}

	return rb_database_sequence_settings_controller;
}

/****************
*  environment  *
****************/

VALUE rb_RPDB_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_parent_database	=	rb_RPDB_DatabaseSequenceController_parentDatabase( rb_database_sequence_controller );
	
	VALUE	rb_parent_environment	=	rb_RPDB_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller )	{

	VALUE	rb_parent_database	=		rb_iv_get(	rb_database_sequence_controller,
																						RPDB_RB_ALL_VARIABLE_PARENT_DATABASE );
	return rb_parent_database;
}

/********************
*  create_sequence  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPDB_DatabaseSequenceController_createSequence(	int			argc __attribute__((unused)),
																													VALUE*	argv __attribute__((unused)),
																													VALUE		rb_database_sequence_controller )	{

		
	//	FIX - parse args

	RPDB_DatabaseSequenceController*		c_database_sequence_controller;
	C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );

	return RUBY_RPDB_DATABASE_SEQUENCE( RPDB_DatabaseSequenceController_createSequence( c_database_sequence_controller ) );	
}


