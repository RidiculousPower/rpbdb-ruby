/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController
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

#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include "rb_RPDB_DatabaseTypeSettingsController.h"

#include <rpdb/RPDB_DatabaseTypeBtreeSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeBtreeSettingsController;

void Init_RPDB_DatabaseTypeSettingsController()	{

	//	FIX - get rid of type controller and have only individual type controllers
	//	put type controller functions in database settings
	rb_RPDB_DatabaseTypeSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																				"TypeSettingsController",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeSettingsController, 	"new",										rb_RPDB_DatabaseTypeSettingsController_new,									1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"initialize",							rb_RPDB_DatabaseTypeSettingsController_init,								1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"parent_environment",			rb_RPDB_DatabaseTypeSettingsController_parentEnvironment,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"environment",						"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"parent_database",				rb_RPDB_DatabaseTypeSettingsController_parentDatabase,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"database",								"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"database_type",					rb_RPDB_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"type",										"database_type"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"is_btree?",							rb_RPDB_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"set_type_to_btree",			rb_RPDB_DatabaseTypeSettingsController_setTypeToBTree,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"is_hash?",								rb_RPDB_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"set_type_to_hash",				rb_RPDB_DatabaseTypeSettingsController_setTypeToHash,				0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"is_recno?",							rb_RPDB_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"set_type_to_recno",			rb_RPDB_DatabaseTypeSettingsController_setTypeToRecno,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"is_queue?",							rb_RPDB_DatabaseTypeSettingsController_isQueue,							0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"set_type_to_queue",			rb_RPDB_DatabaseTypeSettingsController_setTypeToQueue,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"btree_controller",				rb_RPDB_DatabaseTypeSettingsController_btreeController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"btree",									"btree_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																									VALUE	rb_parent_database_settings_controller )	{
	
	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_type_settings_controller	= RUBY_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_type_settings_controller,
					 1, 
					 argv );
	
	return rb_database_type_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeSettingsController_init(	VALUE	rb_database_type_settings_controller,
																										VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{

	return rb_database_type_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentEnvironment(	VALUE	rb_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseTypeSettingsController_parentEnvironment( c_database_type_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabase(	VALUE	rb_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseTypeSettingsController_parentDatabase( c_database_type_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*********************
*  databaseType  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get_type.html
VALUE rb_RPDB_DatabaseTypeSettingsController_databaseType( VALUE	rb_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	//	FIX - return a constant instead of an int
	return INT2FIX( RPDB_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller ) );
}

/*****************
*  isBTree  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isBTree( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isBTree( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );	
}

/*****************
*  setToBTree  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToBTree( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	RPDB_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  isHash  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isHash( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isHash( c_database_type_settings_controller )	?	Qtrue
																								:	Qfalse );
}

/*****************
*  setToHash  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToHash( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  isRecno  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isRecno( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	return ( RPDB_DatabaseTypeSettingsController_isRecno( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );
}

/*****************
*  setToRecno  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToRecno( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  isQueue  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isQueue( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isQueue( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );
}

/*****************
*  setToQueue  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToQueue( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*************************
*  btreeController  *
*************************/

VALUE rb_RPDB_DatabaseTypeSettingsController_btreeController( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_btreeController( c_database_type_settings_controller ) );
}

