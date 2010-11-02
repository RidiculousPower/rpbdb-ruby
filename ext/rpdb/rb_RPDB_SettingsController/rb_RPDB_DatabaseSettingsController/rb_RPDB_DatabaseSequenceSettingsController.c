/*
 *		RPDB::SettingsController::SequenceSettingsController
 *		RPDB::DatabaseController::Database::SequenceController::Sequence::DatabaseSequenceSettingsController
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseSequenceSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseSequenceSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseSequenceSettingsController;

void Init_RPDB_DatabaseSequenceSettingsController()	{

	rb_RPDB_DatabaseSequenceSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																					"Sequence",	
																																					rb_cObject );

 rb_define_singleton_method(	rb_RPDB_DatabaseSequenceSettingsController, 	"new",											rb_RPDB_DatabaseSequenceSettingsController_new,									-1 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"initialize",								rb_RPDB_DatabaseSequenceSettingsController_init,								-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"parent_environment",				rb_RPDB_DatabaseSequenceSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"parent_database",					rb_RPDB_DatabaseSequenceSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"database",									"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"increasing",								rb_RPDB_DatabaseSequenceSettingsController_increasing,						0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_as_increasing",				rb_RPDB_DatabaseSequenceSettingsController_setAsIncreasing,				0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"decreasing",								rb_RPDB_DatabaseSequenceSettingsController_decreasing,						0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_as_decreasing",				rb_RPDB_DatabaseSequenceSettingsController_setAsDecreasing,				0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"wrap",											rb_RPDB_DatabaseSequenceSettingsController_wrap,									0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_to_wrap",							rb_RPDB_DatabaseSequenceSettingsController_setToWrap,							0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_minimum",						rb_RPDB_DatabaseSequenceSettingsController_rangeMinimum,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_min",								"range_minimum"	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_min=",								rb_RPDB_DatabaseSequenceSettingsController_setRangeMinimum,				1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_range_minimum",				"range_min=" 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_range_min",						"range_min=" 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_maximum",						rb_RPDB_DatabaseSequenceSettingsController_rangeMaximum,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_max",								"range_maximum"	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"range_maximum=",						rb_RPDB_DatabaseSequenceSettingsController_setRangeMaximum,				1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_range_maximum",				"range_maximum=" 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_range_max",						"range_maximum=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"cache_size",								rb_RPDB_DatabaseSequenceSettingsController_cacheSize,							0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"cache_size=",							rb_RPDB_DatabaseSequenceSettingsController_setCacheSize,					1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_cache_size",						"cache_size=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"initial_value",						rb_RPDB_DatabaseSequenceSettingsController_initialValue,					0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"initial_value=",						rb_RPDB_DatabaseSequenceSettingsController_setInitialValue,				1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_initial_value",				"initial_value="	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"default_step_value",				rb_RPDB_DatabaseSequenceSettingsController_defaultStepValue,			0 	);
	rb_define_method(						rb_RPDB_DatabaseSequenceSettingsController, 	"default_step_value=",			rb_RPDB_DatabaseSequenceSettingsController_setDefaultStepValue,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseSequenceSettingsController, 	"set_default_step_value",		"default_step_value=" 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseSequenceSettingsController_new(	int			argc,
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

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );
	}

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller	=	RPDB_DatabaseSettingsController_sequenceSettingsController( c_database_settings_controller );

	VALUE	rb_database_sequence_settings_controller	=	RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	
	rb_obj_call_init(	rb_database_sequence_settings_controller,
										 1, 
										 argv );
	
	return rb_database_sequence_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_init(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseSequenceSettingsController_parentEnvironment(	VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseSequenceSettingsController_parentEnvironment( c_database_sequence_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseSequenceSettingsController_parentDatabase(	VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseSequenceSettingsController_parentDatabase( c_database_sequence_settings_controller ) );

}

/*****************
*  increasing  *
*****************/

//	DB_SEQ_INC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_increasing( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return ( RPDB_DatabaseSequenceSettingsController_increasing( c_database_sequence_settings_controller )	?	Qtrue
																											:	Qfalse );

}

/*************************
*  setAsIncreasing  *
*************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setAsIncreasing( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setAsIncreasing( c_database_sequence_settings_controller );

	return rb_database_sequence_settings_controller;
}

/*****************
*  decreasing  *
*****************/

//	DB_SEQ_DEC              http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_decreasing( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return ( RPDB_DatabaseSequenceSettingsController_decreasing( c_database_sequence_settings_controller )	?	Qtrue
																											:	Qfalse );
	
}

/*************************
*  setAsDecreasing  *
*************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setAsDecreasing( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setAsDecreasing( c_database_sequence_settings_controller );
	
	return rb_database_sequence_settings_controller;
}

/*************
*  wrap  *
*************/

//	DB_SEQ_WRAP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_flags.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_wrap( VALUE	rb_database_sequence_settings_controller )	{
	
	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );
	
	return( RPDB_DatabaseSequenceSettingsController_wrap( c_database_sequence_settings_controller )	?	Qtrue
																										:	Qfalse );	
}

/*****************
*  setToWrap  *
*****************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setToWrap( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setToWrap( c_database_sequence_settings_controller );
	
	return rb_database_sequence_settings_controller;
}

/*********************
*  rangeMinimum  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_range.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_rangeMinimum( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( RPDB_DatabaseSequenceSettingsController_rangeMinimum( c_database_sequence_settings_controller ) );	
}

/*************************
*  setRangeMinimum  *
*************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setRangeMinimum(	VALUE	rb_database_sequence_settings_controller, 
																	VALUE	rb_range_minimum )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setRangeMinimum(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_range_minimum ) );
	
	return rb_database_sequence_settings_controller;
}

/*********************
*  rangeMaximum  *
*********************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_rangeMaximum( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( RPDB_DatabaseSequenceSettingsController_rangeMaximum( c_database_sequence_settings_controller ) );
}

/************************
*  setRangeMaximum  *
************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setRangeMaximum(	VALUE	rb_database_sequence_settings_controller,
																	VALUE	rb_range_maximum )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setRangeMaximum(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_range_maximum ) );
	
	return rb_database_sequence_settings_controller;
}

/****************
*  cacheSize  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_cachesize.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_cacheSize( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( RPDB_DatabaseSequenceSettingsController_cacheSize( c_database_sequence_settings_controller ) );
}

/********************
*  setCacheSize  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_set_cachesize.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_setCacheSize(	VALUE	rb_database_sequence_settings_controller,
 																VALUE	rb_number_of_cached_elements	)	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setCacheSize(	c_database_sequence_settings_controller,
	 														FIX2INT( rb_number_of_cached_elements ) );
	
	return rb_database_sequence_settings_controller;
}

/********************
*  initialValue  *
********************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_initialValue( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( RPDB_DatabaseSequenceSettingsController_initialValue( c_database_sequence_settings_controller ) );
}

/**********************
*  setInitialValue  *
**********************/

//	The DB_SEQUENCE->initial_value method may not be called after the DB_SEQUENCE->open method is called.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_initial_value.html
VALUE rb_RPDB_DatabaseSequenceSettingsController_setInitialValue(	VALUE	rb_database_sequence_settings_controller,
 																	VALUE	rb_initial_value )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setInitialValue(	c_database_sequence_settings_controller,
	 															FIX2INT( rb_initial_value ) );

	return rb_database_sequence_settings_controller;
}

/************************
*  defaultStepValue  *
************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_defaultStepValue( VALUE	rb_database_sequence_settings_controller )	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	return INT2FIX( RPDB_DatabaseSequenceSettingsController_defaultStepValue( c_database_sequence_settings_controller ) );
}

/************************
*  setDefaultStepValue  *
************************/

VALUE rb_RPDB_DatabaseSequenceSettingsController_setDefaultStepValue(	VALUE	rb_database_sequence_settings_controller,
 																		VALUE	rb_default_step_value	)	{

	RPDB_DatabaseSequenceSettingsController*	c_database_sequence_settings_controller;
	C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller );

	RPDB_DatabaseSequenceSettingsController_setDefaultStepValue(	c_database_sequence_settings_controller,
	 																FIX2INT( rb_default_step_value ) );

	return rb_database_sequence_settings_controller;
}
