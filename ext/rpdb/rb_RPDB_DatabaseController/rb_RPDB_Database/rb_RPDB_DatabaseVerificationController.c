/*
 *		RPDB::DatabaseController::Database::DatabaseVerificationController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseVerificationController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseVerificationController.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseVerificationSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseVerificationController;
extern	VALUE	rb_RPDB_DatabaseVerificationSettingsController;
extern	VALUE	rb_RPDB_SettingsController;

void Init_RPDB_DatabaseVerificationController()	{

	rb_RPDB_DatabaseVerificationController		=	rb_define_class_under(	rb_RPDB_Database, 
																													"VerificationController",				
																													rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseVerificationController, 	"new",																	rb_RPDB_DatabaseVerificationController_new,										1 	);
	rb_define_method(						rb_RPDB_DatabaseVerificationController, 	"initialize",														rb_RPDB_DatabaseVerificationController_init,									1 	);
	                                                                                          				                                                                          
	rb_define_method(						rb_RPDB_DatabaseVerificationController, 	"settings_controller",									rb_RPDB_DatabaseVerificationController_settingsController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"settings",															"settings_controller"	);                                      
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"set",																	"settings_controller"	);                                      
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"set_to",																"settings_controller"	);                                      
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"is_set_to",														"settings_controller"	);                                      
                                                                                                                                                                              
	rb_define_method(						rb_RPDB_DatabaseVerificationController, 	"parent_environment",										rb_RPDB_DatabaseVerificationController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"environment",													"parent_environment"	);                                      
                                                                                                                                                                              
	rb_define_method(						rb_RPDB_DatabaseVerificationController, 	"parent_database",											rb_RPDB_DatabaseVerificationController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseVerificationController, 	"database",															"parent_database"	);                                          
                    					                                                                                                                                                
	rb_define_method(						rb_RPDB_DatabaseVerificationController, 	"verify",																rb_RPDB_DatabaseVerificationController_verifyDatabase,				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/


/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseVerificationController_new(	VALUE	klass __attribute__((unused)),
																									VALUE	rb_parent_database )	{
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_database_verification_controller	=	RUBY_RPDB_DATABASE_VERIFICATION_CONTROLLER( RPDB_DatabaseVerificationController_new( c_parent_database ) );	

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database;
	
	rb_obj_call_init(	rb_database_verification_controller,
						1, 
						argv );
	
	return rb_database_verification_controller;
}

/********
*  new  *
********/

VALUE rb_RPDB_DatabaseVerificationController_init(	VALUE	rb_database_verification_controller,
																										VALUE	rb_parent_database __attribute__((unused)) )	{


	return rb_database_verification_controller;
}

/***********************
*  settingsController  *
***********************/
VALUE rb_RPDB_DatabaseVerificationController_settingsController(	VALUE	rb_database_verification_controller )	{

	RPDB_DatabaseVerificationController*	c_database_verification_controller;
	C_RPDB_DATABASE_VERIFICATION_CONTROLLER( rb_database_verification_controller, c_database_verification_controller );

	return RUBY_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( RPDB_DatabaseVerificationController_settingsController( c_database_verification_controller ) );
}

/****************
*  environment  *
****************/
VALUE rb_RPDB_DatabaseVerificationController_parentEnvironment(	VALUE	rb_database_verification_controller )	{

	RPDB_DatabaseVerificationController*	c_database_verification_controller;
	C_RPDB_DATABASE_VERIFICATION_CONTROLLER( rb_database_verification_controller, c_database_verification_controller );

	return RUBY_RPDB_ENVIRONMENT(	RPDB_DatabaseVerificationController_parentEnvironment( c_database_verification_controller ) );
}

/********************
*  parent_database  *
********************/
VALUE rb_RPDB_DatabaseVerificationController_parentDatabase(	VALUE	rb_database_verification_controller )	{

	RPDB_DatabaseVerificationController*	c_database_verification_controller;
	C_RPDB_DATABASE_VERIFICATION_CONTROLLER( rb_database_verification_controller, c_database_verification_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseVerificationController_parentDatabase( c_database_verification_controller ) );
}

/***********
*  verify  *
***********/

//	FIX - flesh out functions

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_DatabaseVerificationController_verifyDatabase( VALUE	rb_database_verification_controller )	{

	RPDB_DatabaseVerificationController*	c_database_verification_controller;
	C_RPDB_DATABASE_VERIFICATION_CONTROLLER( rb_database_verification_controller, c_database_verification_controller );

	RPDB_DatabaseVerificationController_verifyDatabase( c_database_verification_controller );

	return rb_database_verification_controller;
}

