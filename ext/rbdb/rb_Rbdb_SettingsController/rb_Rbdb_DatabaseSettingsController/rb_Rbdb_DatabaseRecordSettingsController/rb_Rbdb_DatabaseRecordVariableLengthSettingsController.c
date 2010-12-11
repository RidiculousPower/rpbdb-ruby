/*
 *		Rbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsVariableRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseRecordVariableLengthSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordVariableLengthSettingsController.h>

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
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordVariableLengthSettingsController;
extern	VALUE	rb_Rbdb_Record;

void Init_rb_Rbdb_DatabaseRecordVariableLengthSettingsController()	{

	rb_Rbdb_DatabaseRecordVariableLengthSettingsController	=	rb_define_class_under(	rb_Rbdb_DatabaseRecordSettingsController, 
																																							"VariableLength",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"new",												rb_Rbdb_DatabaseRecordVariableLengthSettingsController_new,										-1 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"initialize",									rb_Rbdb_DatabaseRecordVariableLengthSettingsController_initialize,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_environment",					rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"environment",								"parent_environment"	);                                              	
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database",						rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"database",										"parent_database"	);                                                  	
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_settings_controller",						rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database_settings_controller",						rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"parent_database_record_settings_controller",						rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController,				0 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"delimeter_byte",						rb_Rbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"delimeter_byte=",					rb_Rbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte,		1 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordVariableLengthSettingsController, 	"set_delimeter_byte",				"delimeter_byte="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_Rbdb_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_Rbdb_DatabaseRecordSettingsController ) ) ),
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
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_Rbdb_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	Rbdb_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	Rbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller	=	Rbdb_DatabaseRecordSettingsController_variableLengthSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_variable_length_settings_controller	= RUBY_RBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_record_variable_length_settings_controller,
							RBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabase(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_Rbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_record_settings_controller  *
***********************************************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_variable_length_settings_controller,
																																		RBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}
	/*********************
	*  delimeter_byte  *
	*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_delim.html
VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( VALUE	rb_database_record_variable_length_settings_controller )	{

	Rbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

	int		c_delimeter_byte	=	Rbdb_DatabaseRecordVariableLengthSettingsController_delimeterByte( c_database_record_variable_length_settings_controller );
	VALUE	rb_delimeter_byte	=	INT2FIX( c_delimeter_byte );

	rb_delimeter_byte	=	rb_funcall(	rb_delimeter_byte,
																	rb_intern( "chr" ),
																	0 );

	return rb_delimeter_byte;
}

	/*************************
	*  set_delimeter_byte  *
	*************************/

VALUE rb_Rbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	VALUE	rb_database_record_variable_length_settings_controller, 
																																								VALUE	rb_delimeter_byte )	{

	Rbdb_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

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

	Rbdb_DatabaseRecordVariableLengthSettingsController_setDelimeterByte(	c_database_record_variable_length_settings_controller,
																																				c_delimeter_byte );
	
	return rb_database_record_variable_length_settings_controller;
}
