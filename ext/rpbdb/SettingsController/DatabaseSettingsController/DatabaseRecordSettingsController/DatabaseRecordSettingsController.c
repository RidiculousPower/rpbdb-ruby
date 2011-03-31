/*
 *		RPbdb_settingsController:RPbdb_DatabaseRecordSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "RPbdb.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseRecordFixedLengthSettingsController.h"
#include "DatabaseRecordVariableLengthSettingsController.h"
#include "DatabaseRecordReadWriteSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordFixedLengthSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordVariableLengthSettingsController;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_SettingsController;

void Init_rb_RPbdb_DatabaseRecordSettingsController()	{

	rb_RPbdb_DatabaseRecordSettingsController		=		rb_define_class_under(			rb_RPbdb_DatabaseSettingsController, 
																																							"Record",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseRecordSettingsController, 	"new",																								rb_RPbdb_DatabaseRecordSettingsController_new,																						-1 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"initialize",																					rb_RPbdb_DatabaseRecordSettingsController_initialize,																					-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"parent_environment",																	rb_RPbdb_DatabaseRecordSettingsController_parentEnvironment,															0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordSettingsController, 	"environment",																				"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"parent_database",																		rb_RPbdb_DatabaseRecordSettingsController_parentDatabase,																0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordSettingsController, 	"database",																						"parent_database"	);                    					
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"parent_settings_controller",													rb_RPbdb_DatabaseRecordSettingsController_parentSettingsController,																0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"parent_database_settings_controller",								rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController,																0 	);


	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"fixed_length_settings_controller",										rb_RPbdb_DatabaseRecordSettingsController_fixedLengthSettingsController,																0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"variable_length_settings_controller",										rb_RPbdb_DatabaseRecordSettingsController_variableLengthSettingsController,																0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordSettingsController, 	"read_write_settings_controller",										rb_RPbdb_DatabaseRecordSettingsController_readWriteSettingsController,																0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordSettingsController, 	"read_write_settings",																"read_write_settings_controller"	);                    					
	rb_define_alias(						rb_RPbdb_DatabaseRecordSettingsController, 	"read_write",																					"read_write_settings_controller"	);                    					

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPbdb_DatabaseRecordSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ) ) ),
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

	RPbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		

	RPbdb_DatabaseRecordSettingsController*	c_database_record_settings_controller	=	RPbdb_DatabaseSettingsController_recordSettingsController( c_database_settings_controller );

	VALUE	rb_database_record_settings_controller	=	RUBY_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_database_record_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_record_settings_controller,
							RPBDB_RB_DATABASE_RECORD_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_record_settings_controller,
										 1, 
										 argv );
	
	return rb_database_record_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{
	
	return rb_self;
}


/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_database_record_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_database_record_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_parentSettingsController(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_database_record_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_record_settings_controller,
																															RPBDB_RB_DATABASE_RECORD_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*************************************
*  fixed_length_settings_controller  *
*************************************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_fixedLengthSettingsController(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_database_record_fixed_length_settings_controller	=	Qnil;
	
	if ( ( rb_database_record_fixed_length_settings_controller = rb_iv_get(	rb_database_record_settings_controller,
																																					RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_database_record_fixed_length_settings_controller	=	rb_RPbdb_DatabaseRecordFixedLengthSettingsController_new(	1,
																																																										& rb_database_record_settings_controller,
																																																										rb_RPbdb_DatabaseRecordFixedLengthSettingsController );
		rb_iv_set(	rb_database_record_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER,
								rb_database_record_fixed_length_settings_controller );
	}
	
	return rb_database_record_fixed_length_settings_controller;
}

/****************************************
*  variable_length_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_variableLengthSettingsController(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_database_record_variable_length_settings_controller	=	Qnil;
	
	if ( ( rb_database_record_variable_length_settings_controller = rb_iv_get(	rb_database_record_settings_controller,
																																							RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_database_record_variable_length_settings_controller	=	rb_RPbdb_DatabaseRecordVariableLengthSettingsController_new(	1,
																																																													& rb_database_record_settings_controller,
																																																													rb_RPbdb_DatabaseRecordVariableLengthSettingsController );
		rb_iv_set(	rb_database_record_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER,
								rb_database_record_variable_length_settings_controller );
	}
	
	return rb_database_record_variable_length_settings_controller;
}

/****************************************
*  read_write_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseRecordSettingsController_readWriteSettingsController(	VALUE	rb_database_record_settings_controller )	{

	VALUE	rb_database_record_read_write_settings_controller	=	Qnil;
	
	if ( ( rb_database_record_read_write_settings_controller = rb_iv_get(	rb_database_record_settings_controller,
																																				RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_database_record_read_write_settings_controller	=	rb_RPbdb_DatabaseRecordReadWriteSettingsController_new(	1,
																																																								& rb_database_record_settings_controller,
																																																								rb_RPbdb_DatabaseRecordReadWriteSettingsController );
		rb_iv_set(	rb_database_record_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER,
								rb_database_record_read_write_settings_controller );
	}
	
	return rb_database_record_read_write_settings_controller;
}

