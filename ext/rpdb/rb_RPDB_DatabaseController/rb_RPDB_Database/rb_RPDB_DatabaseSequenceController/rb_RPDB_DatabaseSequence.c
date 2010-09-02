/*
 *		RPDB::DatabaseController::Database::SequenceController::Sequence
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseSequence.h"

#include "rb_RPDB_Database_internal.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseSequence.h>
#include <rpdb/RPDB_DatabaseSequenceController.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_DatabaseSequenceSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_DatabaseSequenceController;
extern	VALUE	rb_RPDB_DatabaseSequence;
extern	VALUE	rb_RPDB_DatabaseJoinsSettingsController;
extern	VALUE	rb_RPDB_DatabaseSequenceSettingsController;

void Init_RPDB_DatabaseSequence()	{

	rb_RPDB_DatabaseSequence		=	rb_define_class_under(	rb_RPDB_DatabaseSequenceController, 
																													"Sequence",				
																													rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseSequence, 	"new",																	rb_RPDB_DatabaseSequence_new,															1 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"initialize",														rb_RPDB_DatabaseSequence_init,														1 	);
	                                                                                          				
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"settings_controller",									rb_RPDB_DatabaseSequence_settingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_RPDB_DatabaseSequence, 	"parent_environment",										rb_RPDB_DatabaseSequence_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_RPDB_DatabaseSequence, 	"parent_database",											rb_RPDB_DatabaseSequence_parentDatabase,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"database",															"parent_database"	);

	rb_define_method(						rb_RPDB_DatabaseSequence, 	"parent_sequence_controller",						rb_RPDB_DatabaseSequence_parentDatabaseSequenceController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"sequence_controller",									"parent_sequence_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"parent_controller",										"parent_sequence_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSequence, 	"controller",														"parent_sequence_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"open",																	rb_RPDB_DatabaseSequence_openSequence,										0 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"close",																rb_RPDB_DatabaseSequence_closeSequence,										0 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"delete",																rb_RPDB_DatabaseSequence_deleteSequence,									0 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"step",																	rb_RPDB_DatabaseSequence_step,														0 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"step_by",															rb_RPDB_DatabaseSequence_stepBy,													1 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"step_backward",												rb_RPDB_DatabaseSequence_stepBackward,										0 	);
	rb_define_method(						rb_RPDB_DatabaseSequence, 	"step_backward_by",											rb_RPDB_DatabaseSequence_stepBackwardBy,									1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPDB_DatabaseSequence_new(	VALUE	klass __attribute__((unused)),
																		VALUE	rb_parent_database_sequence_controller )	{
	
	RPDB_DatabaseSequenceController*	c_parent_database_sequence_controller;
	C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_parent_database_sequence_controller, c_parent_database_sequence_controller );
	
	VALUE	rb_database_sequence	=	RUBY_RPDB_DATABASE_SEQUENCE( RPDB_DatabaseSequence_new( c_parent_database_sequence_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_sequence_controller;
	
	rb_obj_call_init(	rb_database_sequence,
						1, 
						argv );
	
	return rb_database_sequence;		
}


/*********
*  init  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPDB_DatabaseSequence_init(	VALUE	rb_database_sequence,
																			VALUE	rb_parent_database_sequence_controller __attribute__((unused)) )	{

	return rb_database_sequence;
}

/***********************
*  settingsController  *
***********************/

VALUE rb_RPDB_DatabaseSequence_settingsController(	VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	return RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( RPDB_DatabaseSequence_settingsController( c_database_sequence ) );
}

/****************
*  environment  *
****************/

VALUE rb_RPDB_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseSequence_parentEnvironment( c_database_sequence ) );
}

/****************
*  parent_database  *
****************/

VALUE rb_RPDB_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseSequence_parentDatabase( c_database_sequence ) );
}

/*******************************
*  parent_sequence_controller  *
*******************************/

VALUE rb_RPDB_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseSequence_parentDatabase( c_database_sequence ) );
}

/*******************************************************************************************************************************************************************************************
																		Opening, Closing, Deleting
*******************************************************************************************************************************************************************************************/

/*****************
*  openSequence  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_open.html
VALUE rb_RPDB_DatabaseSequence_openSequence(	VALUE	rb_database_sequence,
																							VALUE	rb_stored_at_key __attribute__((unused))	)	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );
	
	//	we need to create a record from rb_stored_at_key
	RPDB_Record*	record	=	RPDB_Record_new( c_database_sequence->parent_database_sequence_controller->parent_database );

	RPDB_DatabaseSequence_openSequence(	c_database_sequence,
	 										record );
	
	return rb_database_sequence;
}

/******************
*  closeSequence  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_close.html
VALUE rb_RPDB_DatabaseSequence_closeSequence( VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_closeSequence( c_database_sequence );
	
	return rb_database_sequence;
}

/*******************
*  deleteSequence  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_remove.html
VALUE rb_RPDB_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_deleteSequence( c_database_sequence );

	return rb_database_sequence;
}

/*******************************************************************************************************************************************************************************************
																		Stepping
*******************************************************************************************************************************************************************************************/

/*********
*  step  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPDB_DatabaseSequence_step( VALUE	rb_database_sequence )	{

	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_step( c_database_sequence );

	return rb_database_sequence;
}

/************
*  step_by  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPDB_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
 																				VALUE	rb_step_value	)	{
	
	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_stepBy(	c_database_sequence,
	 															FIX2INT( rb_step_value ) );
	
	return rb_database_sequence;
}

/******************
*  step_backward  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPDB_DatabaseSequence_stepBackward(	VALUE	rb_database_sequence 	)	{
	
	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_stepBackward(	c_database_sequence );
	
	return rb_database_sequence;
}

/*********************
*  step_backward_by  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPDB_DatabaseSequence_stepBackwardBy(	VALUE	rb_database_sequence,
 																								VALUE	rb_step_value	)	{
	
	RPDB_DatabaseSequence*		c_database_sequence;
	C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPDB_DatabaseSequence_stepBy(	c_database_sequence,
																- FIX2INT( rb_step_value ) );
	
	return rb_database_sequence;
}

