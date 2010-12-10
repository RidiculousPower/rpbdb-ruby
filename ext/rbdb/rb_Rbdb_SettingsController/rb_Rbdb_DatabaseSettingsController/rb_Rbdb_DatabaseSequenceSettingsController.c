/*
 *		Rbdb::SettingsController::SequenceSettingsController
 *		Rbdb::DatabaseController::Database::SequenceController::Sequence::DatabaseSequenceSettingsController
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseSequenceSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseSequenceSettingsController.h>
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
extern	VALUE	rb_Rbdb_DatabaseSequenceSettingsController;

void Init_Rbdb_DatabaseSequenceSettingsController()	{

	rb_Rbdb_DatabaseSequenceSettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																					"Sequence",	
																																					rb_cObject );

 rb_define_singleton_method(	rb_Rbdb_DatabaseSequenceSettingsController, 	"new",											rb_Rbdb_DatabaseSequenceSettingsController_new,									-1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"initialize",								rb_Rbdb_DatabaseSequenceSettingsController_initialize,								-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"parent_environment",				rb_Rbdb_DatabaseSequenceSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"parent_database",					rb_Rbdb_DatabaseSequenceSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"parent_settings_controller",					rb_Rbdb_DatabaseSequenceSettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"parent_database_settings_controller",					rb_Rbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController,				0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"increasing?",								rb_Rbdb_DatabaseSequenceSettingsController_increasing,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_as_increasing",				rb_Rbdb_DatabaseSequenceSettingsController_setAsIncreasing,				0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"decreasing?",								rb_Rbdb_DatabaseSequenceSettingsController_decreasing,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_as_decreasing",				rb_Rbdb_DatabaseSequenceSettingsController_setAsDecreasing,				0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"wrap?",											rb_Rbdb_DatabaseSequenceSettingsController_wrap,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_to_wrap",							rb_Rbdb_DatabaseSequenceSettingsController_setToWrap,							0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_minimum",						rb_Rbdb_DatabaseSequenceSettingsController_rangeMinimum,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_min",								"range_minimum"	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_min=",								rb_Rbdb_DatabaseSequenceSettingsController_setRangeMinimum,				1 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_range_minimum",				"range_min=" 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_range_min",						"range_min=" 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_maximum",						rb_Rbdb_DatabaseSequenceSettingsController_rangeMaximum,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_max",								"range_maximum"	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"range_maximum=",						rb_Rbdb_DatabaseSequenceSettingsController_setRangeMaximum,				1 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_range_maximum",				"range_maximum=" 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_range_max",						"range_maximum=" 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"cache_size",								rb_Rbdb_DatabaseSequenceSettingsController_cacheSize,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_cache_size",							rb_Rbdb_DatabaseSequenceSettingsController_setCacheSize,					1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"initial_value",						rb_Rbdb_DatabaseSequenceSettingsController_initialValue,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_to_initial_value",						rb_Rbdb_DatabaseSequenceSettingsController_setInitialValue,				1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"default_step_value",				rb_Rbdb_DatabaseSequenceSettingsController_defaultStepValue,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequenceSettingsController, 	"set_to_default_step_value",			rb_Rbdb_DatabaseSequenceSettingsController_setDefaultStepValue,		1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_Rbdb_DatabaseSequenceSettingsController_new(	int			argc,
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

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller	=	Rbdb_DatabaseSettingsController_sequenceSettingsController( c_database_settings_controller );

	VALUE	rb_database_sequence_settings_controller	=	RUBY_RBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_sequence_settings_controller,
							Rbdb_RB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_sequence_settings_controller,
										 1, 
										 argv );
	
	return rb_database_sequence_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_parentEnvironment(	VALUE	rb_database_sequence_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController( rb_database_sequence_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_parentDatabase(	VALUE	rb_database_sequence_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController( rb_database_sequence_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_parentSettingsController(	VALUE	rb_database_sequence_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController( rb_database_sequence_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_sequence_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_sequence_settings_controller,
																															Rbdb_RB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/***************
*  increasing  *
***************/

//	DB_SEQ_INC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_increasing( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return ( Rbdb_DatabaseSequenceSettingsController_increasing( c_database_sequence_settings_controller )	?	Qtrue
																											:	Qfalse );

}

/**********************
*  set_as_increasing  *
**********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setAsIncreasing( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setAsIncreasing( c_database_sequence_settings_controller );

	return rb_database_sequence_settings_controller;
}

/***************
*  decreasing  *
***************/

//	DB_SEQ_DEC              http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_decreasing( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return ( Rbdb_DatabaseSequenceSettingsController_decreasing( c_database_sequence_settings_controller )	?	Qtrue
																											:	Qfalse );
	
}

/**********************
*  set_as_decreasing  *
**********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setAsDecreasing( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setAsDecreasing( c_database_sequence_settings_controller );
	
	return rb_database_sequence_settings_controller;
}

/*********
*  wrap  *
*********/

//	DB_SEQ_WRAP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_wrap( VALUE	rb_database_sequence_settings_controller )	{
	
	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );
	
	return( Rbdb_DatabaseSequenceSettingsController_wrap( c_database_sequence_settings_controller )	?	Qtrue
																										:	Qfalse );	
}

/****************
*  set_to_wrap  *
****************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setToWrap( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setToWrap( c_database_sequence_settings_controller );
	
	return rb_database_sequence_settings_controller;
}

/******************
*  range_minimum  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_range.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_rangeMinimum( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( Rbdb_DatabaseSequenceSettingsController_rangeMinimum( c_database_sequence_settings_controller ) );	
}

/**********************
*  set_range_minimum  *
**********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setRangeMinimum(	VALUE	rb_database_sequence_settings_controller, 
																	VALUE	rb_range_minimum )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setRangeMinimum(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_range_minimum ) );
	
	return rb_database_sequence_settings_controller;
}

/******************
*  range_maximum  *
******************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_rangeMaximum( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( Rbdb_DatabaseSequenceSettingsController_rangeMaximum( c_database_sequence_settings_controller ) );
}

/**********************
*  set_range_maximum  *
**********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setRangeMaximum(	VALUE	rb_database_sequence_settings_controller,
																	VALUE	rb_range_maximum )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setRangeMaximum(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_range_maximum ) );
	
	return rb_database_sequence_settings_controller;
}

/***************
*  cache_size  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_cachesize.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_cacheSize( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( Rbdb_DatabaseSequenceSettingsController_cacheSize( c_database_sequence_settings_controller ) );
}

/*******************
*  set_cache_size  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_cachesize.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_setCacheSize(	VALUE	rb_database_sequence_settings_controller,
 																VALUE	rb_number_of_cached_elements	)	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setCacheSize(	c_database_sequence_settings_controller,
	 														FIX2INT( rb_number_of_cached_elements ) );
	
	return rb_database_sequence_settings_controller;
}

/******************
*  initial_value  *
******************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_initialValue( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( Rbdb_DatabaseSequenceSettingsController_initialValue( c_database_sequence_settings_controller ) );
}

/**********************
*  set_initial_value  *
**********************/

//	The DB_SEQUENCE->initial_value method may not be called after the DB_SEQUENCE->open method is called.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_initial_value.html
VALUE rb_Rbdb_DatabaseSequenceSettingsController_setInitialValue(	VALUE	rb_database_sequence_settings_controller,
 																	VALUE	rb_initial_value )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setInitialValue(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_initial_value ) );

	return rb_database_sequence_settings_controller;
}

/***********************
*  default_step_value  *
***********************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_defaultStepValue( VALUE	rb_database_sequence_settings_controller )	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( Rbdb_DatabaseSequenceSettingsController_defaultStepValue( c_database_sequence_settings_controller ) );
}

/***************************
*  set_default_step_value  *
***************************/

VALUE rb_Rbdb_DatabaseSequenceSettingsController_setDefaultStepValue(	VALUE	rb_database_sequence_settings_controller,
 																		VALUE	rb_default_step_value	)	{

	Rbdb_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_Rbdb_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	Rbdb_DatabaseSequenceSettingsController_setDefaultStepValue(	c_database_sequence_settings_controller,
	 																FIX2INT( rb_default_step_value ) );

	return rb_database_sequence_settings_controller;
}
