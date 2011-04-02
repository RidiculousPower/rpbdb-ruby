/*
 *		RPbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsVariableRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseRecordVariableLengthSettingsController.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include "Environment.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/Database.h>
#include <rpbdb/DatabaseController.h>
#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseRecordSettingsController.h>
#include <rpbdb/DatabaseRecordVariableLengthSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordVariableLengthSettingsController;
extern	VALUE	rb_RPbdb_Record;

void Init_rb_RPbdb_DatabaseRecordVariableLengthSettingsController()	{

	rb_RPbdb_DatabaseRecordVariableLengthSettingsController	=	rb_define_class_under(	rb_RPbdb_DatabaseRecordSettingsController, 
																																							"VariableLength",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"new",												rb_RPbdb_DatabaseRecordVariableLengthSettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"initialize",									rb_RPbdb_DatabaseRecordVariableLengthSettingsController_initialize,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_environment",					rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"environment",								"parent_environment"	);                                              	
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database",						rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"database",										"parent_database"	);                                                  	
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_settings_controller",						rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database_settings_controller",						rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database_record_settings_controller",						rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController,				0 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"delimeter_byte",						rb_RPbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"delimeter_byte=",					rb_RPbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte,		1 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordVariableLengthSettingsController, 	"set_delimeter_byte",				"delimeter_byte="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_record																			=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_record_settings_controller					=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPbdb_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_RPbdb_DatabaseRecordSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent record> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database record settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_RPbdb_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	RPbdb_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	RPbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller	=	RPbdb_DatabaseRecordSettingsController_variableLengthSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_variable_length_settings_controller	= RUBY_RPBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_record_variable_length_settings_controller,
							RPBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
							rb_parent_database_record_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_record_settings_controller };
	rb_obj_call_init(	rb_database_record_variable_length_settings_controller,
										1, 
										argv );
	
	return rb_database_record_variable_length_settings_controller;		
}

	/***************
	*  initialize  *
	***************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_record_settings_controller  *
***********************************************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_variable_length_settings_controller,
																																		RPBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}
	/*********************
	*  delimeter_byte  *
	*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_delim.html
VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( VALUE	rb_database_record_variable_length_settings_controller )	{

	RPbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

	int		c_delimeter_byte	=	RPbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( c_database_record_variable_length_settings_controller );
	VALUE	rb_delimeter_byte	=	INT2FIX( c_delimeter_byte );

	rb_delimeter_byte	=	rb_funcall(	rb_delimeter_byte,
																	rb_intern( "chr" ),
																	0 );

	return rb_delimeter_byte;
}

	/*************************
	*  set_delimeter_byte  *
	*************************/

VALUE rb_RPbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	VALUE	rb_database_record_variable_length_settings_controller, 
																																								VALUE	rb_delimeter_byte )	{

	RPbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

	int	c_delimeter_byte	=	0;
	
	//	rb_delimeter_byte should be a 1-char string or a number
	if (		TYPE( rb_delimeter_byte ) == T_STRING
			&&	RSTRING_LEN( rb_delimeter_byte ) == 1 )	{

		char*	c_char_delimeter_byte	=	StringValuePtr( rb_delimeter_byte );

		c_delimeter_byte	= (int)	*c_char_delimeter_byte;

	}
	else if ( TYPE( rb_delimeter_byte ) == T_FIXNUM )	{
	
		c_delimeter_byte	=	FIX2INT( rb_delimeter_byte );
	
	}
	else	{
		rb_raise( rb_eArgError, "Padding byte must be either integer or character." );
	}

	RPbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	c_database_record_variable_length_settings_controller,
																																				c_delimeter_byte );
	
	return rb_database_record_variable_length_settings_controller;
}
