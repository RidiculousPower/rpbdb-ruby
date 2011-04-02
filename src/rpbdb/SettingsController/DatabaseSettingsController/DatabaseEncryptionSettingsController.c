/*
 *		RPbdb::Database::DatabaseSettingsController::DatabaseSettingsEncryptionController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseEncryptionSettingsController.h"
#include "DatabaseController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "Database.h"

#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseEncryptionSettingsController.h>

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
extern	VALUE	rb_RPbdb_DatabaseEncryptionSettingsController;

void Init_rb_RPbdb_DatabaseEncryptionSettingsController()	{

	rb_RPbdb_DatabaseEncryptionSettingsController			=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																							"Encryption",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseEncryptionSettingsController, 	"new",											rb_RPbdb_DatabaseEncryptionSettingsController_new,											-1 	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"initialize",								rb_RPbdb_DatabaseEncryptionSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"parent_environment",				rb_RPbdb_DatabaseEncryptionSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"parent_database",					rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"parent_settings_controller",					rb_RPbdb_DatabaseEncryptionSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"parent_database_settings_controller",					rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController,					0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"encrypted?",								rb_RPbdb_DatabaseEncryptionSettingsController_encrypted,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"encryption?",							"encrypted?" 	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"turn_encryption_on",				rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOn,				1 	);
	rb_define_method(						rb_RPbdb_DatabaseEncryptionSettingsController, 	"turn_encryption_off",			rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOff,				1 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_new(	int			argc,
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
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_database == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller	=	rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	else if ( rb_parent_database_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseController_settingsController( rb_parent_database_controller );
	}

	RPbdb_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_encryption_settings_controller	= RUBY_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( RPbdb_DatabaseEncryptionSettingsController_new( c_parent_database_settings_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_database_encryption_settings_controller,
							RPBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_encryption_settings_controller,
										 1, 
										 argv );
	
	return rb_database_encryption_settings_controller;		
}

/***************
*  initialize  *
***************/
	
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_encryption_settings_controller	=	rb_iv_get(	rb_database_encryption_settings_controller,
																																				RPBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_encryption_settings_controller;
}

/**************
*  encrypted  *
**************/

//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPbdb_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller )	{

	RPbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
	C_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );
												
	BOOL	c_encrypted		=	RPbdb_DatabaseEncryptionSettingsController_encrypted( c_database_encryption_settings_controller );
	
	VALUE	rb_encrypted	=	( c_encrypted ? Qtrue : Qfalse );
	
	return rb_encrypted;
}

	/***********************
	*  turn_encryption_on  *
	***********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																																				VALUE	rb_encryption_password )	{

		RPbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		char*	c_encryption_password	=	StringValuePtr( rb_encryption_password );

		RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	c_database_encryption_settings_controller,
																																c_encryption_password );

		return rb_database_encryption_settings_controller;
	}

	/************************
	*  turn_encryption_off  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																																				VALUE	rb_encryption_password )	{

		RPbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		char*	c_encryption_password	=	StringValuePtr( rb_encryption_password );

		RPbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	c_database_encryption_settings_controller,
																																	c_encryption_password );
		
		return rb_database_encryption_settings_controller;
	}
