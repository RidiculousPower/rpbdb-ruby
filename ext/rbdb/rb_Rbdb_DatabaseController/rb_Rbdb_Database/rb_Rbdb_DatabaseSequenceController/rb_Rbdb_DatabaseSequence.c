/*
 *		Rbdb::DatabaseController::Database::SequenceController::Sequence
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseSequence.h"
#include "rb_Rbdb_DatabaseSequenceController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb_Database_internal.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseSequence.h>
#include <rbdb/Rbdb_DatabaseSequenceController.h>

#include <rbdb/Rbdb_Record.h>

#include <rbdb/Rbdb_DatabaseSequenceSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_DatabaseSequenceController;
extern	VALUE	rb_Rbdb_DatabaseSequence;
extern	VALUE	rb_Rbdb_DatabaseJoinsSettingsController;
extern	VALUE	rb_Rbdb_DatabaseSequenceSettingsController;

void Init_Rbdb_DatabaseSequence()	{

	rb_Rbdb_DatabaseSequence		=	rb_define_class_under(	rb_Rbdb_DatabaseSequenceController, 
																												"Sequence",				
																												rb_cObject );
	
	rb_define_singleton_method(	rb_Rbdb_DatabaseSequence, 	"new",																	rb_Rbdb_DatabaseSequence_new,															-1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"initialize",														rb_Rbdb_DatabaseSequence_initialize,														-1 	);
	                                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"settings_controller",									rb_Rbdb_DatabaseSequence_settingsController,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_environment",										rb_Rbdb_DatabaseSequence_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_database",											rb_Rbdb_DatabaseSequence_parentDatabase,									0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"database",															"parent_database"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_sequence_controller",						rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"sequence_controller",									"parent_sequence_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"parent_controller",										"parent_sequence_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"controller",														"parent_sequence_controller"	);
	
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"open",																	rb_Rbdb_DatabaseSequence_openSequence,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"close",																rb_Rbdb_DatabaseSequence_closeSequence,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"delete",																rb_Rbdb_DatabaseSequence_deleteSequence,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step",																	rb_Rbdb_DatabaseSequence_step,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step_by",															rb_Rbdb_DatabaseSequence_stepBy,													1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step_backward",												rb_Rbdb_DatabaseSequence_stepBackward,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step_backward_by",											rb_Rbdb_DatabaseSequence_stepBackwardBy,									1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_Rbdb_DatabaseSequence_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_database						=	Qnil;
	VALUE	rb_parent_database_sequence_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_database_sequence_controller, rb_Rbdb_DatabaseSequenceController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]",
			"[ <parent database sequence controller> ]"
		)
	);

	Rbdb_DatabaseSequenceController*	c_parent_database_sequence_controller;
	C_Rbdb_DATABASE_SEQUENCE_CONTROLLER( rb_parent_database_sequence_controller, c_parent_database_sequence_controller );
	
	VALUE	rb_database_sequence	=	RUBY_RBDB_DATABASE_SEQUENCE( Rbdb_DatabaseSequence_new( c_parent_database_sequence_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_database_sequence,
							Rbdb_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER,
							rb_parent_database_sequence_controller );

	VALUE	argv[]	=	{ rb_parent_database_sequence_controller };
	rb_obj_call_init(	rb_database_sequence,
										1, 
										argv );
	
	return rb_database_sequence;		
}


/*********
*  initialize  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_Rbdb_DatabaseSequence_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  settingsController  *
***********************/

VALUE rb_Rbdb_DatabaseSequence_settingsController(	VALUE	rb_database_sequence )	{

	VALUE	rb_local_database_sequence_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_sequence_settings_controller = rb_iv_get(	rb_database_sequence,
																																			Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_DatabaseSequence*		c_database_sequence;
		C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );
	
		Rbdb_DatabaseSequenceSettingsController*	c_local_database_sequence_settings_controller	=	Rbdb_DatabaseSequence_settingsController( c_database_sequence );

		rb_local_database_sequence_settings_controller	=	RUBY_RBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_local_database_sequence_settings_controller );

		rb_iv_set(	rb_database_sequence,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER,
								rb_local_database_sequence_settings_controller );
	}

	return rb_local_database_sequence_settings_controller;
}

/****************
*  environment  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_controller		=	rb_Rbdb_DatabaseSequence_parentDatabaseController( rb_database_sequence );
	VALUE	rb_parent_environment						=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/****************
*  parent_database_controller  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database							=	rb_Rbdb_DatabaseSequence_parentDatabase( rb_database_sequence );
	VALUE	rb_parent_database_controller		= rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
	return rb_parent_database_controller;
}

/****************
*  parent_database  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController( rb_database_sequence );
	VALUE	rb_parent_database											=	rb_Rbdb_DatabaseSequenceController_parentDatabase( rb_parent_database_sequence_controller );
	return rb_parent_database;
}

/*******************************
*  parent_sequence_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_iv_get(	rb_database_sequence,
																															Rbdb_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER );
	return rb_parent_database_sequence_controller;
}

/*******************************************************************************************************************************************************************************************
																		Opening, Closing, Deleting
*******************************************************************************************************************************************************************************************/

/*****************
*  openSequence  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_open.html
VALUE rb_Rbdb_DatabaseSequence_openSequence(	VALUE	rb_database_sequence,
																							VALUE	rb_stored_at_key __attribute__((unused))	)	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );
	
	//	we need to create a record from rb_stored_at_key
	Rbdb_Record*	record	=	Rbdb_Record_new( c_database_sequence->parent_database_sequence_controller->parent_database );

	Rbdb_DatabaseSequence_openSequence(	c_database_sequence,
	 										record );
	
	return rb_database_sequence;
}

/******************
*  closeSequence  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_close.html
VALUE rb_Rbdb_DatabaseSequence_closeSequence( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_closeSequence( c_database_sequence );
	
	return rb_database_sequence;
}

/*******************
*  deleteSequence  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_remove.html
VALUE rb_Rbdb_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_deleteSequence( c_database_sequence );

	return rb_database_sequence;
}

/*******************************************************************************************************************************************************************************************
																		Stepping
*******************************************************************************************************************************************************************************************/

/*********
*  step  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_Rbdb_DatabaseSequence_step( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_step( c_database_sequence );

	return rb_database_sequence;
}

/************
*  step_by  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_Rbdb_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
 																				VALUE	rb_step_value	)	{
	
	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_stepBy(	c_database_sequence,
	 															FIX2INT( rb_step_value ) );
	
	return rb_database_sequence;
}

/******************
*  step_backward  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_Rbdb_DatabaseSequence_stepBackward(	VALUE	rb_database_sequence 	)	{
	
	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_stepBackward(	c_database_sequence );
	
	return rb_database_sequence;
}

/*********************
*  step_backward_by  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_Rbdb_DatabaseSequence_stepBackwardBy(	VALUE	rb_database_sequence,
 																								VALUE	rb_step_value	)	{
	
	Rbdb_DatabaseSequence*		c_database_sequence;
	C_Rbdb_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_stepBy(	c_database_sequence,
																- FIX2INT( rb_step_value ) );
	
	return rb_database_sequence;
}

