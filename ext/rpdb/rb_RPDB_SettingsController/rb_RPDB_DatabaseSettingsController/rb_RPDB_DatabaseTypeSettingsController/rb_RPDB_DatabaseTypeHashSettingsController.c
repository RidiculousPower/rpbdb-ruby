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

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseTypeHashSettingsController.h>
#include "rb_RPDB_DatabaseTypeHashSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeHashSettingsController;

void Init_RPDB_DatabaseTypeHashSettingsController()	{

	rb_RPDB_DatabaseTypeHashSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Hash",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeHashSettingsController, 	"new",															rb_RPDB_DatabaseTypeHashSettingsController_new,										1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeHashSettingsController, 	"initialize",												rb_RPDB_DatabaseTypeHashSettingsController_init,									1 	);
                    					                                                                                                                                                  	
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

VALUE rb_RPDB_DatabaseTypeHashSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																											VALUE	rb_parent_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_parent_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_parent_database_type_settings_controller );
	
	VALUE	rb_database_type_hash_settings_controller	= RUBY_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( RPDB_DatabaseTypeHashSettingsController_new( c_parent_database_type_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_type_settings_controller;
	
	rb_obj_call_init(	rb_database_type_hash_settings_controller,
					 1, 
					 argv );
	
	return rb_database_type_hash_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_DatabaseTypeHashSettingsController_init(	VALUE	rb_database_type_hash_settings_controller,
																												VALUE	rb_parent_database_type_settings_controller __attribute__ ((unused )) )	{

	return rb_database_type_hash_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentEnvironment(	VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseTypeHashSettingsController_parentEnvironment( c_database_type_hash_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeHashSettingsController_parentDatabase(	VALUE	rb_database_type_hash_settings_controller )	{

	RPDB_DatabaseTypeHashSettingsController*	c_database_type_hash_settings_controller;
	C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseTypeHashSettingsController_parentDatabase( c_database_type_hash_settings_controller ) );

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
