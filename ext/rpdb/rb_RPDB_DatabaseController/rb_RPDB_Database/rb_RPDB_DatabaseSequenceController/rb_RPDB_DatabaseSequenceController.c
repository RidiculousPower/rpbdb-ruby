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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseSequenceController.h>
#include <rpdb/RPDB_DatabaseSequence.h>

#include <rpdb/RPDB_DatabaseSequenceSettingsController.h>

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
	
	rb_define_singleton_method(	rb_RPDB_DatabaseSequenceController, 	"new",																	rb_RPDB_DatabaseSequenceController_new,															1 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceController, 	"initialize",														rb_RPDB_DatabaseSequenceController_init,														1 	);
	                                                                                          				
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

VALUE rb_RPDB_DatabaseSequenceController_new(	VALUE	klass __attribute__((unused)),
																							VALUE	rb_parent_database )	{
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_database_sequence_controller	=	RUBY_RPDB_DATABASE_SEQUENCE_CONTROLLER( RPDB_DatabaseSequenceController_new( c_parent_database ) );	
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database;
	
	rb_obj_call_init(	rb_database_sequence_controller,
										1, 
										argv );
	
	return rb_database_sequence_controller;		
}


/*********
*  init  * 
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPDB_DatabaseSequenceController_init(	VALUE	rb_database_sequence_controller,
																								VALUE	rb_parent_database __attribute__((unused)) )	{

	return rb_database_sequence_controller;
}

/************************
*  settings_controller  *
************************/

VALUE rb_RPDB_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller )	{

	RPDB_DatabaseSequenceController*		c_database_sequence_controller;
	C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );

	return RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( RPDB_DatabaseSequenceController_settingsController( c_database_sequence_controller ) );	
}

/****************
*  environment  *
****************/

VALUE rb_RPDB_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller )	{

	RPDB_DatabaseSequenceController*		c_database_sequence_controller;
	C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseSequenceController_parentEnvironment( c_database_sequence_controller ) );	
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller )	{

	RPDB_DatabaseSequenceController*		c_database_sequence_controller;
	C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseSequenceController_parentDatabase( c_database_sequence_controller ) );	
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


