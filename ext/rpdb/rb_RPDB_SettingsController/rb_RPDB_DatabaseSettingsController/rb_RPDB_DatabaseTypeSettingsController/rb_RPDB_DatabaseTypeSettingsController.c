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
#include "rb_RPDB_DatabaseTypeBtreeSettingsController.h"
#include "rb_RPDB_DatabaseTypeHashSettingsController.h"
#include "rb_RPDB_DatabaseTypeQueueSettingsController.h"
#include "rb_RPDB_DatabaseTypeRecnoSettingsController.h"

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
extern	VALUE	rb_RPDB_DatabaseTypeHashSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeQueueSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeRecnoSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_Record;

extern VALUE rb_RPDB_DatabaseType_const_module;
extern VALUE rb_RPDB_DatabaseBtreeType_const;
extern VALUE rb_RPDB_DatabaseHashType_const;
extern VALUE rb_RPDB_DatabaseQueueType_const;
extern VALUE rb_RPDB_DatabaseRecnoType_const;

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
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"parent_settings_controller",				rb_RPDB_DatabaseTypeSettingsController_parentSettingsController,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"parent_database_settings_controller",				rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController,			0 	);
                    					
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

	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"hash_controller",				rb_RPDB_DatabaseTypeSettingsController_hashController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"hash",										"hash_controller"	);

	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"queue_controller",				rb_RPDB_DatabaseTypeSettingsController_queueController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"queue",									"queue_controller"	);

	rb_define_method(						rb_RPDB_DatabaseTypeSettingsController, 	"recno_controller",				rb_RPDB_DatabaseTypeSettingsController_recnoController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeSettingsController, 	"recno",									"recno_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
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
	else if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );
	}

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPDB_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	//	unlike other controllers, with the type controller we have two options
	//	* settings controller parent => controller w/settings controller methods: btree, hash, queue, recno
	//	* database parent => specific type controller

	if ( rb_parent_database == Qnil )	{
		rb_parent_database	=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	
	VALUE	rb_database_type_settings_controller	=	Qnil;
	
	if ( rb_parent_database != Qnil )	{
		
		const DBTYPE		c_database_type	=	RPDB_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller );

		VALUE	rb_database_specific_type_settings_controller	=	Qnil;
		switch( c_database_type )	{
			
			case DB_BTREE:
				rb_database_specific_type_settings_controller	=	rb_RPDB_DatabaseTypeBtreeSettingsController_new(	1,
																																																					& rb_parent_database,
																																																					rb_RPDB_DatabaseTypeBtreeSettingsController );
				break;
				
			case DB_HASH:
				rb_database_specific_type_settings_controller	=	rb_RPDB_DatabaseTypeHashSettingsController_new(		1,
																																																					& rb_parent_database,
																																																					rb_RPDB_DatabaseTypeHashSettingsController );				
				break;
			
			case DB_QUEUE:
				rb_database_specific_type_settings_controller	=	rb_RPDB_DatabaseTypeQueueSettingsController_new(	1,
																																																					& rb_parent_database,
																																																					rb_RPDB_DatabaseTypeQueueSettingsController );
				break;
			
			case DB_RECNO:
				rb_database_specific_type_settings_controller	=	rb_RPDB_DatabaseTypeRecnoSettingsController_new(	1,
																																																					& rb_parent_database,
																																																					rb_RPDB_DatabaseTypeRecnoSettingsController );
				break;
			
			case DB_UNKNOWN:
				rb_raise( rb_eRuntimeError, "Database was of unknown type; could not instantiate type settings controller." );
				break;
		}
		
		//	if we have a database parent then we need to extent our specific type controller to include
		//	* :type
		//	* :is_btree?, :is_hash?, :is_queue?, :is_recno?

		VALUE	rb_database_specific_type_settings_controller_singleton_class	=	rb_singleton_class( rb_database_specific_type_settings_controller );

		rb_define_method(		rb_database_specific_type_settings_controller_singleton_class, 	"database_type",					rb_RPDB_DatabaseTypeSettingsController_databaseType,				0 	);
		rb_define_alias(		rb_database_specific_type_settings_controller_singleton_class, 	"type",										"database_type"	);
		rb_define_method(		rb_database_specific_type_settings_controller_singleton_class, 	"is_btree?",							rb_RPDB_DatabaseTypeSettingsController_isBTree,							0 	);
		rb_define_method(		rb_database_specific_type_settings_controller_singleton_class, 	"is_hash?",								rb_RPDB_DatabaseTypeSettingsController_isHash,							0 	);
		rb_define_method(		rb_database_specific_type_settings_controller_singleton_class, 	"is_queue?",							rb_RPDB_DatabaseTypeSettingsController_isQueue,							0 	);
		rb_define_method(		rb_database_specific_type_settings_controller_singleton_class, 	"is_recno?",							rb_RPDB_DatabaseTypeSettingsController_isRecno,							0 	);

		rb_database_type_settings_controller	=	rb_database_specific_type_settings_controller;
	}
	else {
		
		rb_database_type_settings_controller	= RUBY_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller );

		VALUE	argv[]	=	{ rb_parent_database_settings_controller };
		rb_obj_call_init(	rb_database_type_settings_controller,
											1, 
											argv );
		
	}

	//	store reference to parent
	rb_iv_set(	rb_database_type_settings_controller,
							RPDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );


	return rb_database_type_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_DatabaseTypeSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentEnvironment(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabase(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentSettingsController(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_database_type_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_settings_controller,
																															RPDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/******************
*  database_type  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get_type.html
VALUE rb_RPDB_DatabaseTypeSettingsController_databaseType( VALUE	rb_database_type_settings_controller )	{

	VALUE		rb_klass			=	rb_class_of( rb_database_type_settings_controller );
	VALUE		rb_ancestors	=	rb_mod_ancestors( rb_klass );
	
	VALUE		rb_database_type	=	Qnil;
	
	if ( rb_ary_includes( rb_ancestors, rb_RPDB_DatabaseTypeSettingsController ) == Qtrue )	{

		RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
		C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );

		DBTYPE	c_database_type	=	RPDB_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller );
			
		switch( c_database_type )	{
			
			case DB_BTREE:
				rb_database_type	=	rb_RPDB_DatabaseBtreeType_const;
				break;
				
			case DB_HASH:
				rb_database_type	=	rb_RPDB_DatabaseHashType_const;
				break;
			
			case DB_QUEUE:
				rb_database_type	=	rb_RPDB_DatabaseQueueType_const;
				break;
			
			case DB_RECNO:
				rb_database_type	=	rb_RPDB_DatabaseRecnoType_const;
				break;
			
			case DB_UNKNOWN:
				rb_raise( rb_eRuntimeError, "Database was of unknown type." );
				break;
		}

	}
	else {
		
		if (			rb_ary_includes( rb_ancestors, rb_RPDB_DatabaseTypeBtreeSettingsController ) == Qtrue )	{
			rb_database_type	=	rb_RPDB_DatabaseBtreeType_const;
		}
		else if ( rb_ary_includes( rb_ancestors, rb_RPDB_DatabaseTypeHashSettingsController ) == Qtrue )	{
			rb_database_type	=	rb_RPDB_DatabaseHashType_const;
		}
		else if ( rb_ary_includes( rb_ancestors, rb_RPDB_DatabaseTypeQueueSettingsController ) == Qtrue )	{
			rb_database_type	=	rb_RPDB_DatabaseQueueType_const;
		}
		else if ( rb_ary_includes( rb_ancestors, rb_RPDB_DatabaseTypeRecnoSettingsController ) == Qtrue )	{
			rb_database_type	=	rb_RPDB_DatabaseRecnoType_const;
		}
		else {
			rb_raise( rb_eRuntimeError, "Database was of unknown type." );
		}

	}

	return rb_database_type;
}

/**************
*  is_btree?  *
**************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isBTree( VALUE		rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type	=	rb_RPDB_DatabaseTypeSettingsController_databaseType( rb_database_type_settings_controller );
	
	VALUE	rb_is_type				=	( rb_database_type == rb_RPDB_DatabaseBtreeType_const ? Qtrue : Qfalse );
		
	return rb_is_type;
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

/*************
*  is_hash?  *
*************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isHash(	VALUE		rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type	=	rb_RPDB_DatabaseTypeSettingsController_databaseType( rb_database_type_settings_controller );
	
	VALUE	rb_is_type				=	( rb_database_type == rb_RPDB_DatabaseHashType_const ? Qtrue : Qfalse );
		
	return rb_is_type;
}

/****************
*  set_to_hash  *
****************/

VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToHash( VALUE	rb_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller );
	
	RPDB_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
	
	return rb_database_type_settings_controller;
}

/**************
*  is_recno?  *
**************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isRecno(	VALUE		rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type	=	rb_RPDB_DatabaseTypeSettingsController_databaseType( rb_database_type_settings_controller );
	
	VALUE	rb_is_type				=	( rb_database_type == rb_RPDB_DatabaseRecnoType_const ? Qtrue : Qfalse );
		
	return rb_is_type;
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

/**************
*  is_queue?  *
**************/

VALUE rb_RPDB_DatabaseTypeSettingsController_isQueue( VALUE		rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type	=	rb_RPDB_DatabaseTypeSettingsController_databaseType( rb_database_type_settings_controller );
	
	VALUE	rb_is_type				=	( rb_database_type == rb_RPDB_DatabaseQueueType_const ? Qtrue : Qfalse );
		
	return rb_is_type;
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

/*********************
*  btree_controller  *
*********************/

VALUE rb_RPDB_DatabaseTypeSettingsController_btreeController( VALUE	rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type_btree_settings_controller	=	Qnil;
	
	if ( ( rb_database_type_btree_settings_controller = rb_iv_get(	rb_database_type_settings_controller,
																																	RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_database_type_btree_settings_controller	=	rb_RPDB_DatabaseTypeBtreeSettingsController_new(	1,
																																																		& rb_database_type_settings_controller,
																																																		rb_RPDB_DatabaseTypeBtreeSettingsController );
		rb_iv_set(	rb_database_type_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER,
								rb_database_type_btree_settings_controller );
	}
	
	return rb_database_type_btree_settings_controller;
}

/********************
*  hash_controller  *
********************/

VALUE rb_RPDB_DatabaseTypeSettingsController_hashController( VALUE	rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type_hash_settings_controller	=	Qnil;
	
	if ( ( rb_database_type_hash_settings_controller = rb_iv_get(	rb_database_type_settings_controller,
																																RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_database_type_hash_settings_controller	=	rb_RPDB_DatabaseTypeHashSettingsController_new(	1,
																																																& rb_database_type_settings_controller,
																																																rb_RPDB_DatabaseTypeHashSettingsController );

		rb_iv_set(	rb_database_type_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER,
								rb_database_type_hash_settings_controller );
	}
	
	return rb_database_type_hash_settings_controller;
}

/*********************
*  queue_controller  *
*********************/

VALUE rb_RPDB_DatabaseTypeSettingsController_queueController( VALUE	rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type_queue_settings_controller	=	Qnil;
	
	if ( ( rb_database_type_queue_settings_controller = rb_iv_get(	rb_database_type_settings_controller,
																																	RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_database_type_queue_settings_controller	=	rb_RPDB_DatabaseTypeQueueSettingsController_new(	1,
																																																		& rb_database_type_settings_controller,
																																																		rb_RPDB_DatabaseTypeQueueSettingsController );
		rb_iv_set(	rb_database_type_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER,
								rb_database_type_queue_settings_controller );
	}
	
	return rb_database_type_queue_settings_controller;
}

/*********************
*  recno_controller  *
*********************/

VALUE rb_RPDB_DatabaseTypeSettingsController_recnoController( VALUE	rb_database_type_settings_controller )	{
	
	VALUE	rb_database_type_recno_settings_controller	=	Qnil;
	
	if ( ( rb_database_type_recno_settings_controller = rb_iv_get(	rb_database_type_settings_controller,
																																	RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_database_type_recno_settings_controller	=	rb_RPDB_DatabaseTypeRecnoSettingsController_new(	1,
																																																		& rb_database_type_settings_controller,
																																																		rb_RPDB_DatabaseTypeRecnoSettingsController );
		rb_iv_set(	rb_database_type_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER,
								rb_database_type_recno_settings_controller );
	}
	
	return rb_database_type_recno_settings_controller;
}
