/*
 *		RPbdb::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeHashSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseTypeHashSettingsController.h"
#include "DatabaseTypeSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseTypeHashSettingsController.h>
#include <rpbdb/DatabaseTypeSettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseTypeSettingsController;
extern	VALUE	rb_RPbdb_DatabaseTypeHashSettingsController;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_Record;

void Init_rb_RPbdb_DatabaseTypeHashSettingsController()	{

	rb_RPbdb_DatabaseTypeHashSettingsController		=	rb_define_class_under(	rb_RPbdb_DatabaseTypeSettingsController, 
																																					"Hash",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseTypeHashSettingsController, 	"new",															rb_RPbdb_DatabaseTypeHashSettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"initialize",												rb_RPbdb_DatabaseTypeHashSettingsController_initialize,									-1 	);
                    					                                                                                                                                                  	
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"parent_environment",								rb_RPbdb_DatabaseTypeHashSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"environment",											"parent_environment"	);                                        	
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"parent_database",									rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"database",													"parent_database"	);                                            	
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"parent_settings_controller",	rb_RPbdb_DatabaseTypeHashSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"parent_database_settings_controller",	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"parent_database_type_settings_controller",	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController,										0 	);

	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"database_type",													rb_RPbdb_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"type",																		"database_type"	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"is_btree?",															rb_RPbdb_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"is_hash?",																rb_RPbdb_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"is_recno?",															rb_RPbdb_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"is_queue?",															rb_RPbdb_DatabaseTypeSettingsController_isQueue,							0 	);

	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"table_size",												rb_RPbdb_DatabaseTypeHashSettingsController_tableSize,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"table_size=",											rb_RPbdb_DatabaseTypeHashSettingsController_setTableSize,					1 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"set_table_size",										"table_size="	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"hash_density_factor",							rb_RPbdb_DatabaseTypeHashSettingsController_hashDensityFactor,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"hash_density_factor=",							rb_RPbdb_DatabaseTypeHashSettingsController_setHashDensityFactor,	1 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeHashSettingsController, 	"set_hash_density_factor",					"hash_density_factor="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_type_settings_controller						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_type_settings_controller, rb_RPbdb_DatabaseTypeSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database type settings controller> ]"
		)
	);

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil
			&&	rb_parent_database_type_settings_controller == Qnil )	{
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
	if ( rb_parent_database_settings_controller != Qnil )	{

		//	if we have a parent_database we need to get the environment database type settings controller so we don't loop
		if ( ( rb_parent_database = rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller ) ) != Qnil )	{
			
			RPbdb_DatabaseSettingsController*	c_database_settings_controller;
			C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );			
			
			RPbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

			rb_parent_database_type_settings_controller	=	RUBY_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller );
		}
		else {
			
			rb_parent_database_type_settings_controller	=	rb_RPbdb_DatabaseSettingsController_typeSettingsController( rb_parent_database_settings_controller );
		}

	}

	RPbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_database_type_settings_controller );		

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller	=	RPbdb_DatabaseTypeSettingsController_hashController( c_database_type_settings_controller );

	VALUE	rb_database_type_hash_settings_controller	= RUBY_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller );

	if ( rb_parent_database != Qnil )	{

		if ( rb_parent_database_settings_controller == Qnil )	{
			rb_parent_database_settings_controller = rb_RPbdb_Database_settingsController( rb_parent_database );
		}

		//	store reference to parent database settings controller
		rb_iv_set(	rb_database_type_hash_settings_controller,
								RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );

	}

	//	store reference to parent type settings controller
	rb_iv_set(	rb_database_type_hash_settings_controller,
							RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );

	//	if we have a parent database in addition to our parent environmental settings controller, set it as parent as well
	//	it's possible we were passed a database settings controller with a parent database
	if (		rb_parent_database == Qnil
			&&	rb_parent_database_settings_controller != Qnil )	{
		
		rb_parent_database	=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_type_hash_settings_controller,
								RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
								rb_parent_database );	
	}
	
	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_hash_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_hash_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_hash_settings_controller,
																															RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	if ( rb_parent_database_settings_controller == Qnil )	{
	
		VALUE	rb_parent_database_type_settings_controller		=	rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController( rb_database_type_hash_settings_controller );
		
		rb_parent_database_settings_controller							=	rb_RPbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );

	}
		
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_hash_settings_controller,
																																	RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/***************
*  table_size  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_nelem.html
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( RPbdb_DatabaseTypeHashSettingsController_tableSize( c_database_type_hash_settings_controller ) );
}

/*******************
*  set_table_size  *
*******************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																VALUE	rb_number_of_elements )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	RPbdb_DatabaseTypeHashSettingsController_setTableSize(	c_database_type_hash_settings_controller,
															FIX2INT( rb_number_of_elements ) );

	return rb_database_type_hash_settings_controller;
}

/************************
*  hash_density_factor  *
************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_ffactor.html
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( RPbdb_DatabaseTypeHashSettingsController_hashDensityFactor( c_database_type_hash_settings_controller ) );
}

/****************************
*  set_hash_density_factor  *
****************************/

VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																		VALUE	rb_density )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	RPbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	c_database_type_hash_settings_controller,
																	FIX2INT( rb_density ) );

	return rb_database_type_hash_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/
	
/********************
*  set_hash_method  *
********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_hash.html
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setHashMethod(	VALUE	rb_database_type_hash_settings_controller,
 																VALUE(*hash_method)(	VALUE			database, 
																					const VALUE				bytes, 
																					VALUE				length ) )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );


}
*/
/****************
*  hash_method  *
****************/
/*
VALUE(*hash_method)(	VALUE			database, 
					const VALUE				bytes, 
					VALUE				length ) RPbdb_DatabaseTypeHashSettingsController_hashMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/***********************
*  set_compare_method  *
***********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_compare.html
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setCompareMethod(		VALUE	rb_database_type_hash_settings_controller,
 																	VALUE(*compare_method)(	VALUE			database, 
																							const VALUE		data_one, 
																							const VALUE		data_two ) )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/******************
*  compare_method  *
******************/
/*
VALUE(*compare_method)(	VALUE		database, 
						const DBT*			data_one, 
						const DBT*			data_two ) RPbdb_DatabaseTypeHashSettingsController_compareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*********************************
*  set_duplicate_compare_method  *
*********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_dup_compare.html
VALUE rb_RPbdb_DatabaseTypeHashSettingsController_setDuplicateCompareMethod(	VALUE	rb_database_type_hash_settings_controller,
 																			VALUE(*duplicate_compare_method)(	VALUE			database, 
																												const VALUE		data_one, 
																												const VALUE		data_two ) )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*****************************
*  duplicate_compare_method  *
*****************************/
/*
VALUE(*duplicate_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPbdb_DatabaseTypeHashSettingsController_duplicateCompareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
