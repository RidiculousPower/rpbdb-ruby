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

#include "rb_RPDB_DatabaseTypeSettingsController.h"

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include "rb_RPDB_SettingsController.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>

#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeBtreeSettingsController.h>


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
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeBtreeSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_Record;

void Init_RPDB_DatabaseTypeSettingsController()	{

	//	FIX - get rid of type controller and have only individual type controllers
	//	put type controller functions in database settings
	rb_RPDB_DatabaseTypeSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																				"Type",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeSettingsController, 	"new",										rb_RPDB_DatabaseTypeSettingsController_new,									-1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"initialize",							rb_RPDB_DatabaseTypeSettingsController_initialize,								-1 	);
                    					
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

VALUE rb_RPDB_DatabaseTypeSettingsController_new(	int			argc,
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

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPDB_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	VALUE	rb_database_type_settings_controller	= RUBY_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_type_settings_controller,
							RPDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_type_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_settings_controller;		
}

/*************
*  initialize  *
*************/

VALUE rb_RPDB_DatabaseTypeSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentEnvironment(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabase(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentSettingsController(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_settings_controller,
																															RPDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*********************
*  database_type  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get_type.html
VALUE rb_RPDB_DatabaseTypeSettingsController_databaseType( VALUE	rb_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	//	FIX - return a constant instead of an int
	return INT2FIX( RPDB_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller ) );
}

/*****************
*  is_btree?  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isBTree( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isBTree( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );	
}

/*****************
*  set_to_btree  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToBTree( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	RPDB_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  is_hash?  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isHash( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isHash( c_database_type_settings_controller )	?	Qtrue
																								:	Qfalse );
}

/*****************
*  set_to_hash  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToHash( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  is_recno?  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isRecno( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

	return ( RPDB_DatabaseTypeSettingsController_isRecno( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );
}

/*****************
*  set_to_recno  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToRecno( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*****************
*  is_queue?  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isQueue( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return ( RPDB_DatabaseTypeSettingsController_isQueue( c_database_type_settings_controller )	?	Qtrue
																									:	Qfalse );
}

/*****************
*  set_to_queue  *
*****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToQueue( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/*************************
*  btree_controller  *
*************************/

VALUE rb_RPDB_DatabaseTypeSettingsController_btreeController( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_btreeController( c_database_type_settings_controller ) );
}

/*************************
*  hash_controller  *
*************************/

VALUE rb_RPDB_DatabaseTypeSettingsController_hashController( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_hashController( c_database_type_settings_controller ) );
}

/*************************
*  queue_controller  *
*************************/

VALUE rb_RPDB_DatabaseTypeSettingsController_queueController( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_queueController( c_database_type_settings_controller ) );
}

/*************************
*  recno_controller  *
*************************/

VALUE rb_RPDB_DatabaseTypeSettingsController_recnoController( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	return RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeSettingsController_recnoController( c_database_type_settings_controller ) );
}
