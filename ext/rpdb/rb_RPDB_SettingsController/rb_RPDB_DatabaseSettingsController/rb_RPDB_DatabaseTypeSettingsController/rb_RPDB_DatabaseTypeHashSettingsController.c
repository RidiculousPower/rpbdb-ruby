/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeHashSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseTypeHashSettingsController.h"
#include "rb_RPDB_DatabaseTypeSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseTypeHashSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeHashSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_Record;

void Init_RPDB_DatabaseTypeHashSettingsController()	{

	rb_RPDB_DatabaseTypeHashSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Hash",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeHashSettingsController, 	"new",															rb_RPDB_DatabaseTypeHashSettingsController_new,										-1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"initialize",												rb_RPDB_DatabaseTypeHashSettingsController_init,									-1 	);
                    					                                                                                                                                                  	
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"parent_environment",								rb_RPDB_DatabaseTypeHashSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeHashSettingsController, 	"environment",											"parent_environment"	);                                        	
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"parent_database",									rb_RPDB_DatabaseTypeHashSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeHashSettingsController, 	"database",													"parent_database"	);                                            	
                    					                                                                                                                                                  	
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"table_size",												rb_RPDB_DatabaseTypeHashSettingsController_tableSize,							0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"table_size=",											rb_RPDB_DatabaseTypeHashSettingsController_setTableSize,					1 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeHashSettingsController, 	"set_table_size",										"table_size="	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"hash_density_factor",							rb_RPDB_DatabaseTypeHashSettingsController_hashDensityFactor,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"hash_density_factor=",							rb_RPDB_DatabaseTypeHashSettingsController_setHashDensityFactor,	1 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeHashSettingsController, 	"set_hash_density_factor",					"hash_density_factor="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_type_settings_controller, rb_RPDB_DatabaseTypeSettingsController ) ) ),
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
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_type_settings_controller	=	rb_RPDB_DatabaseSettingsController_typeSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_database_type_settings_controller );		

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller	=	RPDB_DatabaseTypeSettingsController_hashController( c_database_type_settings_controller );

	VALUE	rb_database_type_hash_settings_controller	= RUBY_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_type_hash_settings_controller,
							RPDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_initialize(	rb_database_type_hash_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_hash_settings_controller;		
}

/*************
*  initialize  *
*************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller		=	rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController( rb_database_type_hash_settings_controller );
	VALUE	rb_parent_database_settings_controller				=	rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***************************************
*  parent_database_type_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_hash_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_hash_settings_controller,
																																	RPDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/******************
*  tableSize  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_nelem.html
VALUE rb_RPDB_DatabaseTypeHashSettingsController_tableSize( VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( RPDB_DatabaseTypeHashSettingsController_tableSize( c_database_type_hash_settings_controller ) );
}

/*********************
*  setTableSize  *
*********************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_setTableSize(	VALUE	rb_database_type_hash_settings_controller, 
																VALUE	rb_number_of_elements )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	RPDB_DatabaseTypeHashSettingsController_setTableSize(	c_database_type_hash_settings_controller,
															FIX2INT( rb_number_of_elements ) );

	return rb_database_type_hash_settings_controller;
}

/**************************
*  hashDensityFactor  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_ffactor.html
VALUE rb_RPDB_DatabaseTypeHashSettingsController_hashDensityFactor( VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return INT2FIX( RPDB_DatabaseTypeHashSettingsController_hashDensityFactor( c_database_type_hash_settings_controller ) );
}

/******************************
*  setHashDensityFactor  *
******************************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_setHashDensityFactor(	VALUE	rb_database_type_hash_settings_controller, 
																		VALUE	rb_density )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	RPDB_DatabaseTypeHashSettingsController_setHashDensityFactor(	c_database_type_hash_settings_controller,
																	FIX2INT( rb_density ) );

	return rb_database_type_hash_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/
	
/**********************
*  setHashMethod  *
**********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_hash.html
VALUE rb_RPDB_DatabaseTypeHashSettingsController_setHashMethod(	VALUE	rb_database_type_hash_settings_controller,
 																VALUE(*hash_method)(	VALUE			database, 
																					const VALUE				bytes, 
																					VALUE				length ) )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );


}
*/
/******************
*  hashMethod  *
******************/
/*
VALUE(*hash_method)(	VALUE			database, 
					const VALUE				bytes, 
					VALUE				length ) RPDB_DatabaseTypeHashSettingsController_hashMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/**************************
*  setCompareMethod  *
**************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_h_compare.html
VALUE rb_RPDB_DatabaseTypeHashSettingsController_setCompareMethod(		VALUE	rb_database_type_hash_settings_controller,
 																	VALUE(*compare_method)(	VALUE			database, 
																							const VALUE		data_one, 
																							const VALUE		data_two ) )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*********************
*  compareMethod  *
*********************/
/*
VALUE(*compare_method)(	VALUE		database, 
						const DBT*			data_one, 
						const DBT*			data_two ) RPDB_DatabaseTypeHashSettingsController_compareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/**********************************
*  setDuplicateCompareMethod  *
**********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_dup_compare.html
VALUE rb_RPDB_DatabaseTypeHashSettingsController_setDuplicateCompareMethod(	VALUE	rb_database_type_hash_settings_controller,
 																			VALUE(*duplicate_compare_method)(	VALUE			database, 
																												const VALUE		data_one, 
																												const VALUE		data_two ) )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
/*****************************
*  duplicateCompareMethod  *
*****************************/
/*
VALUE(*duplicate_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPDB_DatabaseTypeHashSettingsController_duplicateCompareMethod( VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

}
*/
