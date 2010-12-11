/*
 *		Rbdb::Database::DatabaseSettingsController::DatabaseSettingsEncryptionController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseEncryptionSettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseEncryptionSettingsController.h>

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
extern	VALUE	rb_Rbdb_DatabaseEncryptionSettingsController;

void Init_rb_Rbdb_DatabaseEncryptionSettingsController()	{

	rb_Rbdb_DatabaseEncryptionSettingsController			=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																							"Encryption",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseEncryptionSettingsController, 	"new",											rb_Rbdb_DatabaseEncryptionSettingsController_new,											-1 	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"initialize",								rb_Rbdb_DatabaseEncryptionSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"parent_environment",				rb_Rbdb_DatabaseEncryptionSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"parent_database",					rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"parent_settings_controller",					rb_Rbdb_DatabaseEncryptionSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"parent_database_settings_controller",					rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController,					0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"encrypted?",								rb_Rbdb_DatabaseEncryptionSettingsController_encrypted,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"encryption?",							"encrypted?" 	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"turn_encryption_on",				rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOn,				1 	);
	rb_define_method(						rb_Rbdb_DatabaseEncryptionSettingsController, 	"turn_encryption_off",			rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOff,				1 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_new(	int			argc,
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
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_database == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller	=	rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	else if ( rb_parent_database_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseController_settingsController( rb_parent_database_controller );
	}

	Rbdb_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_encryption_settings_controller	= RUBY_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( Rbdb_DatabaseEncryptionSettingsController_new( c_parent_database_settings_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_database_encryption_settings_controller,
							RBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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
	
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_encryption_settings_controller	=	rb_iv_get(	rb_database_encryption_settings_controller,
																																				RBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_encryption_settings_controller;
}

/**************
*  encrypted  *
**************/

//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller )	{

	Rbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
	C_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );
												
	BOOL	c_encrypted		=	Rbdb_DatabaseEncryptionSettingsController_encrypted( c_database_encryption_settings_controller );
	
	VALUE	rb_encrypted	=	( c_encrypted ? Qtrue : Qfalse );
	
	return rb_encrypted;
}

	/***********************
	*  turn_encryption_on  *
	***********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																																				VALUE	rb_encryption_password )	{

		Rbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		char*	c_encryption_password	=	StringValuePtr( rb_encryption_password );

		Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOn(	c_database_encryption_settings_controller,
																																c_encryption_password );

		return rb_database_encryption_settings_controller;
	}

	/************************
	*  turn_encryption_off  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																																				VALUE	rb_encryption_password )	{

		Rbdb_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		char*	c_encryption_password	=	StringValuePtr( rb_encryption_password );

		Rbdb_DatabaseEncryptionSettingsController_turnEncryptionOff(	c_database_encryption_settings_controller,
																																	c_encryption_password );
		
		return rb_database_encryption_settings_controller;
	}
