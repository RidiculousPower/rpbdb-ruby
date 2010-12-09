/*
 *		Rbdb::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeHashSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseTypeHashSettingsController.h"
#include "rb_Rbdb_DatabaseTypeSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseTypeHashSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseTypeSettingsController;
extern	VALUE	rb_Rbdb_DatabaseTypeHashSettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_Record;

void Init_Rbdb_DatabaseTypeHashSettingsController()	{

	rb_Rbdb_DatabaseTypeHashSettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseTypeSettingsController, 
																																					"Hash",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseTypeHashSettingsController, 	"new",															rb_Rbdb_DatabaseTypeHashSettingsController_new,										-1 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"initialize",												rb_Rbdb_DatabaseTypeHashSettingsController_initialize,									-1 	);
                    					                                                                                                                                                  	
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"parent_environment",								rb_Rbdb_DatabaseTypeHashSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"environment",											"parent_environment"	);                                        	
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"parent_database",									rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"database",													"parent_database"	);                                            	
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"parent_settings_controller",	rb_Rbdb_DatabaseTypeHashSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"parent_database_settings_controller",	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"parent_database_type_settings_controller",	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController,										0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"database_type",													rb_Rbdb_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"type",																		"database_type"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"is_btree?",															rb_Rbdb_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"is_hash?",																rb_Rbdb_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"is_recno?",															rb_Rbdb_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"is_queue?",															rb_Rbdb_DatabaseTypeSettingsController_isQueue,							0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"table_size",												rb_Rbdb_DatabaseTypeHashSettingsController_tableSize,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"table_size=",											rb_Rbdb_DatabaseTypeHashSettingsController_setTableSize,					1 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"set_table_size",										"table_size="	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"hash_density_factor",							rb_Rbdb_DatabaseTypeHashSettingsController_hashDensityFactor,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"hash_density_factor=",							rb_Rbdb_DatabaseTypeHashSettingsController_setHashDensityFactor,	1 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeHashSettingsController, 	"set_hash_density_factor",					"hash_density_factor="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_type_settings_controller, rb_Rbdb_DatabaseTypeSettingsController ) ) ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{

		//	if we have a parent_database we need to get the environment database type settings controller so we don't loop
		if ( ( rb_parent_database = rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller ) ) != Qnil )	{
			
			Rbdb_DatabaseSettingsController*	c_database_settings_controller;
			C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );			
			
			Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	Rbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

			rb_parent_database_type_settings_controller	=	RUBY_Rbdb_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller );
		}
		else {
			
			rb_parent_database_type_settings_controller	=	rb_Rbdb_DatabaseSettingsController_typeSettingsController( rb_parent_database_settings_controller );
		}

	}

	Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_Rbdb_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_database_type_settings_controller );		

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller	=	Rbdb_DatabaseTypeSettingsController_hashController( c_database_type_settings_controller );

	VALUE	rb_database_type_hash_settings_controller	= RUBY_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller );

	if ( rb_parent_database != Qnil )	{

		if ( rb_parent_database_settings_controller == Qnil )	{
			rb_parent_database_settings_controller = rb_Rbdb_Database_settingsController( rb_parent_database );
		}

		//	store reference to parent database settings controller
		rb_iv_set(	rb_database_type_hash_settings_controller,
								Rbdb_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );

	}

	//	store reference to parent type settings controller
	rb_iv_set(	rb_database_type_hash_settings_controller,
							Rbdb_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );

	//	if we have a parent database in addition to our parent environmental settings controller, set it as parent as well
	//	it's possible we were passed a database settings controller with a parent database
	if (		rb_parent_database == Qnil
			&&	rb_parent_database_settings_controller != Qnil )	{
		
		rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_type_hash_settings_controller,
								Rbdb_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
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

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_hash_settings_controller,
																															Rbdb_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	if ( rb_parent_database_settings_controller == Qnil )	{
	
		VALUE	rb_parent_database_type_settings_controller		=	rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController( rb_database_type_hash_settings_controller );
		
		rb_parent_database_settings_controller							=	rb_Rbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );

	}
		
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_hash_settings_controller,
																																	Rbdb_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/***************
*  table_size  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_nelem.html
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( Rbdb_DatabaseTypeHashSettingsController_tableSize( c_database_type_hash_settings_controller ) );
}

/*******************
*  set_table_size  *
*******************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																VALUE	rb_number_of_elements )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	Rbdb_DatabaseTypeHashSettingsController_setTableSize(	c_database_type_hash_settings_controller,
															FIX2INT( rb_number_of_elements ) );

	return rb_database_type_hash_settings_controller;
}

/************************
*  hash_density_factor  *
************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_ffactor.html
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( Rbdb_DatabaseTypeHashSettingsController_hashDensityFactor( c_database_type_hash_settings_controller ) );
}

/****************************
*  set_hash_density_factor  *
****************************/

VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																		VALUE	rb_density )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	Rbdb_DatabaseTypeHashSettingsController_setHashDensityFactor(	c_database_type_hash_settings_controller,
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
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setHashMethod(	VALUE	rb_database_type_hash_settings_controller,
 																VALUE(*hash_method)(	VALUE			database, 
																					const VALUE				bytes, 
																					VALUE				length ) )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );


}
*/
/****************
*  hash_method  *
****************/
/*
VALUE(*hash_method)(	VALUE			database, 
					const VALUE				bytes, 
					VALUE				length ) Rbdb_DatabaseTypeHashSettingsController_hashMethod( VALUE	rb_database_type_hash_settings_controller )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/***********************
*  set_compare_method  *
***********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_compare.html
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setCompareMethod(		VALUE	rb_database_type_hash_settings_controller,
 																	VALUE(*compare_method)(	VALUE			database, 
																							const VALUE		data_one, 
																							const VALUE		data_two ) )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/******************
*  compare_method  *
******************/
/*
VALUE(*compare_method)(	VALUE		database, 
						const DBT*			data_one, 
						const DBT*			data_two ) Rbdb_DatabaseTypeHashSettingsController_compareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*********************************
*  set_duplicate_compare_method  *
*********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_dup_compare.html
VALUE rb_Rbdb_DatabaseTypeHashSettingsController_setDuplicateCompareMethod(	VALUE	rb_database_type_hash_settings_controller,
 																			VALUE(*duplicate_compare_method)(	VALUE			database, 
																												const VALUE		data_one, 
																												const VALUE		data_two ) )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*****************************
*  duplicate_compare_method  *
*****************************/
/*
VALUE(*duplicate_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) Rbdb_DatabaseTypeHashSettingsController_duplicateCompareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	Rbdb_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_Rbdb_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
