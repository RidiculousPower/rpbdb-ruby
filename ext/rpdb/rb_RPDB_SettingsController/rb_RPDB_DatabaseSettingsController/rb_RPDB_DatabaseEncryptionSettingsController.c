/*
 *		RPDB::Database::DatabaseSettingsController::DatabaseSettingsEncryptionController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseEncryptionSettingsController.h>
#include "rb_RPDB_DatabaseEncryptionSettingsController.h"

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseEncryptionSettingsController;

void Init_RPDB_DatabaseEncryptionSettingsController()	{

	rb_RPDB_DatabaseEncryptionSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																							"Encryption",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseEncryptionSettingsController, 	"new",											rb_RPDB_DatabaseEncryptionSettingsController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"initialize",								rb_RPDB_DatabaseEncryptionSettingsController_init,										-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"parent_environment",				rb_RPDB_DatabaseEncryptionSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseEncryptionSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"parent_database",					rb_RPDB_DatabaseEncryptionSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseEncryptionSettingsController, 	"database",									"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"encrypted?",								rb_RPDB_DatabaseEncryptionSettingsController_encrypted,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseEncryptionSettingsController, 	"encryption?",							"encrypted?" 	);
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"turn_encryption_on",				rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseEncryptionSettingsController, 	"turn_encryption_off",			rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOff,				0 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseEncryptionSettingsController_new(	int			argc,
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
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_encryption_settings_controller	= RUBY_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( RPDB_DatabaseEncryptionSettingsController_new( c_parent_database_settings_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_database_encryption_settings_controller,
							RPDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_encryption_settings_controller,
										 1, 
										 argv );
	
	return rb_database_encryption_settings_controller;		
}

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseEncryptionSettingsController_init(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentEnvironment(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentDatabase(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseEncryptionSettingsController_parentDatabaseSettingsController( rb_database_encryption_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseEncryptionSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_encryption_settings_controller )	{

	VALUE	rb_parent_database_encryption_settings_controller	=	rb_iv_get(	rb_database_encryption_settings_controller,
																																				RPDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_encryption_settings_controller;
}

/*****************
*  encrypted  *
*****************/

//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
//	DB_ENCRYPT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseEncryptionSettingsController_encrypted( VALUE	rb_database_encryption_settings_controller )	{

	RPDB_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
	C_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );
												
	return ( RPDB_DatabaseEncryptionSettingsController_encrypted( c_database_encryption_settings_controller )	?	Qtrue
																												:	Qfalse	);
}

	/*************************
	*  turnEncryptionOn  *
	*************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOn(	VALUE	rb_database_encryption_settings_controller,
																			VALUE	rb_encryption_password )	{

		RPDB_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		RPDB_DatabaseEncryptionSettingsController_turnEncryptionOn(	c_database_encryption_settings_controller,
		 																StringValuePtr( rb_encryption_password ) );

		return rb_database_encryption_settings_controller;
	}

	/*************************
	*  turnEncryptionOff  *
	*************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_encrypt.html
	VALUE rb_RPDB_DatabaseEncryptionSettingsController_turnEncryptionOff(	VALUE	rb_database_encryption_settings_controller, 
																			VALUE	rb_encryption_password )	{

		RPDB_DatabaseEncryptionSettingsController*	c_database_encryption_settings_controller;
		C_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller );

		RPDB_DatabaseEncryptionSettingsController_turnEncryptionOff(	c_database_encryption_settings_controller,
		 																StringValuePtr( rb_encryption_password ) );
		
		return rb_database_encryption_settings_controller;
	}
