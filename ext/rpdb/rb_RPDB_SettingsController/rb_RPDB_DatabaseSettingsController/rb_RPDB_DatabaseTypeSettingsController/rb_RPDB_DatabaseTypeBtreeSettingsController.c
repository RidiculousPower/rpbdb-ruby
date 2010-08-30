/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeBtreeSettingsController
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

#include <rpdb/RPDB_DatabaseTypeBtreeSettingsController.h>
#include "rb_RPDB_DatabaseTypeBtreeSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeBtreeSettingsController;

void Init_RPDB_DatabaseTypeBtreeSettingsController()	{

	rb_RPDB_DatabaseTypeBtreeSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Btree",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeBtreeSettingsController, 	"new",																	rb_RPDB_DatabaseTypeBtreeSettingsController_new,															1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"initialize",														rb_RPDB_DatabaseTypeBtreeSettingsController_init,															1 	);
                    					                                                                            					
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"parent_environment",										rb_RPDB_DatabaseTypeBtreeSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"parent_database",											rb_RPDB_DatabaseTypeBtreeSettingsController_parentDatabase,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"database",															"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"record_number_retrieval?",							rb_RPDB_DatabaseTypeBtreeSettingsController_recordNumberRetrieval,						0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_on",			rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_off",			rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"reverse_splitting?",										rb_RPDB_DatabaseTypeBtreeSettingsController_reverseSplitting,									0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_on",						rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn,						0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_off",						rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff,					0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page",								rb_RPDB_DatabaseTypeBtreeSettingsController_minimumKeysPerPage,								0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page=",								rb_RPDB_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage,						1 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"set_minimum_keys_per_page",						"minimum_keys_per_page="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_parent_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_parent_database_type_settings_controller );

	VALUE	rb_database_type_btree_settings_controller	= RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeBtreeSettingsController_new( c_parent_database_type_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_type_settings_controller;
	
	rb_obj_call_init(	rb_database_type_btree_settings_controller,
					 1, 
					 argv );
	
	return rb_database_type_btree_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_init(	VALUE	rb_database_type_btree_settings_controller,
																												VALUE	rb_parent_database_type_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_type_btree_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_parentEnvironment(	VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseTypeBtreeSettingsController_parentEnvironment( c_database_type_btree_settings_controller ) );
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_parentDatabase(	VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseTypeBtreeSettingsController_parentDatabase( c_database_type_btree_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*****************************
*  recordNumberRetrieval  *
*****************************/

//	DB_RECNUM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return ( RPDB_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( c_database_type_btree_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/************************************
	*  turnRecordNumberRetrievalOn  *
	************************************/

	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( VALUE	rb_database_type_btree_settings_controller )	{

		RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

		RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

	/*************************************
	*  turnRecordNumberRetrievalOff  *
	*************************************/

	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( VALUE	rb_database_type_btree_settings_controller )	{

		RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

		RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

/*************************
*  reverseSplitting  *
*************************/

//	DB_REVSPLITOFF		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_reverseSplitting( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return ( RPDB_DatabaseTypeBtreeSettingsController_reverseSplitting( c_database_type_btree_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/******************************
	*  turnReverseSplittingOn  *
	******************************/

	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( VALUE	rb_database_type_btree_settings_controller )	{
	
		RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );
	
		RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

	/********************************
	*  turnReverseSplittingOff  *
	********************************/
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( VALUE	rb_database_type_btree_settings_controller )	{
	
		RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );
	
		RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/**************************
*  minimumKeysPerPage  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_minkey.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	RPDB_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( c_database_type_btree_settings_controller );
	
	return rb_database_type_btree_settings_controller;
}

/******************************
*  setMinimumKeysPerPage  *
******************************/

VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	VALUE	rb_database_type_btree_settings_controller,
																			VALUE	rb_minimum_keys_per_page )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	RPDB_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	c_database_type_btree_settings_controller,
																		FIX2INT( rb_minimum_keys_per_page) );

	return rb_database_type_btree_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/
	
/********************************
*  setPrefixCompareMethod  *
********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_prefix.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_setPrefixCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
	 																	VALUE(*prefix_compare_method)(	VALUE			database, 
																										const VALUE		data_one, 
																										const VALUE		data_two ) )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/****************************
*  prefixCompareMethod  *
****************************/
/*
VALUE (*prefix_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPDB_DatabaseTypeBtreeSettingsController_prefixCompareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*************************
*  setCompareMethod  *
*************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_compare.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_setCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
 																	VALUE(*compare_method)(	VALUE			database, 
																							const VALUE		data_one, 
																							const VALUE		data_two ) )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*********************
*  compareMethod  *
*********************/
/*
VALUE(*compare_method)(	VALUE		database, 
						const DBT*			data_one, 
						const DBT*			data_two ) RPDB_DatabaseTypeBtreeSettingsController_compareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/**********************************
*  setDuplicateCompareMethod  *
**********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_dup_compare.html
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_setDuplicateCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
 																			VALUE(*duplicate_compare_method)(	VALUE			database, 
																												const VALUE		data_one, 
																												const VALUE		data_two ) )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*****************************
*  duplicateCompareMethod  *
*****************************/
/*
VALUE(*duplicate_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPDB_DatabaseTypeBtreeSettingsController_duplicateCompareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPDB_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/