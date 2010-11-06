/*
 *		RPDB::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsVariableRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseRecordVariableLengthSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordVariableLengthSettingsController.h>

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
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordVariableLengthSettingsController;
extern	VALUE	rb_RPDB_Record;

void Init_RPDB_DatabaseRecordVariableLengthSettingsController()	{

	rb_RPDB_DatabaseRecordVariableLengthSettingsController	=	rb_define_class_under(	rb_RPDB_DatabaseRecordSettingsController, 
																																							"VariableLength",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"new",												rb_RPDB_DatabaseRecordVariableLengthSettingsController_new,										-1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"initialize",									rb_RPDB_DatabaseRecordVariableLengthSettingsController_init,									-1 	);
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"parent_environment",					rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"environment",								"parent_environment"	);                                              	
	rb_define_method(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"parent_database",						rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"database",										"parent_database"	);                                                  	
                    					                                                                                                                                                        	
	rb_define_method(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"record_delimeter",						rb_RPDB_DatabaseRecordVariableLengthSettingsController_recordDelimeter,				0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"record_delimeter=",					rb_RPDB_DatabaseRecordVariableLengthSettingsController_setRecordDelimeter,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordVariableLengthSettingsController, 	"set_record_delimeter",				"record_delimeter="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPDB_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_RPDB_DatabaseRecordSettingsController ) ) ),
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
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_RPDB_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	RPDB_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller	=	RPDB_DatabaseRecordSettingsController_variableLengthSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_variable_length_settings_controller	= RUBY_RPDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_record_variable_length_settings_controller,
							RPDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
							rb_parent_database_record_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_record_settings_controller };
	rb_obj_call_initialize(	rb_database_record_variable_length_settings_controller,
										1, 
										argv );
	
	return rb_database_record_variable_length_settings_controller;		
}

	/*************
	*  new  *
	*************/

VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabase(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController( rb_database_record_variable_length_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPDB_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***************************************
*  parent_database_record_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_variable_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_variable_length_settings_controller,
																																		RPDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}
	/************************
	*  recordDelimeter  *
	************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_delim.html
VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_recordDelimeter( VALUE	rb_database_record_variable_length_settings_controller )	{

	RPDB_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RPDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordVariableLengthSettingsController_recordDelimeter( c_database_record_variable_length_settings_controller ) );
}

	/****************************
	*  setRecordDelimeter  *
	****************************/

VALUE rb_RPDB_DatabaseRecordVariableLengthSettingsController_setRecordDelimeter(	VALUE	rb_database_record_variable_length_settings_controller, 
																			VALUE	rb_record_delimeter )	{

	RPDB_DatabaseRecordVariableLengthSettingsController*	c_database_record_variable_length_settings_controller;
	C_RPDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller );

	RPDB_DatabaseRecordVariableLengthSettingsController_setRecordDelimeter(	c_database_record_variable_length_settings_controller,
																		FIX2INT( rb_record_delimeter ) );
	
	return rb_database_record_variable_length_settings_controller;
}
