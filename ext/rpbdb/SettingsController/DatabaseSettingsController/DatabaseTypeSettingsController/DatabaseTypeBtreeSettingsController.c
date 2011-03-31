/*
 *		RPbdb::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeBtreeSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseTypeBtreeSettingsController.h"
#include "DatabaseTypeSettingsController.h"
#include "DatabaseSettingsController.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseController.h"
#include "SettingsController.h"
#include "Database.h"

#include "RPbdb.h"


#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseTypeBtreeSettingsController.h>
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
extern	VALUE	rb_RPbdb_DatabaseTypeBtreeSettingsController;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_RPbdb_SettingsController;

void Init_rb_RPbdb_DatabaseTypeBtreeSettingsController()	{

	rb_RPbdb_DatabaseTypeBtreeSettingsController		=	rb_define_class_under(	rb_RPbdb_DatabaseTypeSettingsController, 
																																					"Btree",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"new",																	rb_RPbdb_DatabaseTypeBtreeSettingsController_new,															-1 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"initialize",														rb_RPbdb_DatabaseTypeBtreeSettingsController_initialize,															-1 	);
                    					                                                                            					
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"parent_environment",										rb_RPbdb_DatabaseTypeBtreeSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"parent_database",											rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabase,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"database",															"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"parent_settings_controller",	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"parent_database_settings_controller",	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"parent_database_type_settings_controller",	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseTypeSettingsController,										0 	);

	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"database_type",													rb_RPbdb_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"type",																		"database_type"	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"is_btree?",															rb_RPbdb_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"is_hash?",																rb_RPbdb_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"is_recno?",															rb_RPbdb_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"is_queue?",															rb_RPbdb_DatabaseTypeSettingsController_isQueue,							0 	);

	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"record_number_retrieval?",							rb_RPbdb_DatabaseTypeBtreeSettingsController_recordNumberRetrieval,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_on",			rb_RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_off",			rb_RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff,			0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"reverse_splitting?",										rb_RPbdb_DatabaseTypeBtreeSettingsController_reverseSplitting,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_on",						rb_RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_off",						rb_RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff,					0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page",								rb_RPbdb_DatabaseTypeBtreeSettingsController_minimumKeysPerPage,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page=",								rb_RPbdb_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage,						1 	);
	rb_define_alias(						rb_RPbdb_DatabaseTypeBtreeSettingsController, 	"set_minimum_keys_per_page",						"minimum_keys_per_page="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_new(	int			argc,
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

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller	=	RPbdb_DatabaseTypeSettingsController_btreeController( c_database_type_settings_controller );

	VALUE	rb_database_type_btree_settings_controller	= RUBY_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( c_database_type_btree_settings_controller );

	if ( rb_parent_database != Qnil )	{

		if ( rb_parent_database_settings_controller == Qnil )	{
			rb_parent_database_settings_controller = rb_RPbdb_Database_settingsController( rb_parent_database );
		}

		//	store reference to parent database settings controller
		rb_iv_set(	rb_database_type_btree_settings_controller,
								RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );

	}

	//	store reference to parent type settings controller
	rb_iv_set(	rb_database_type_btree_settings_controller,
							RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );
	
	//	if we have a parent database in addition to our parent environmental settings controller, set it as parent as well
	//	it's possible we were passed a database settings controller with a parent database
	if (		rb_parent_database == Qnil
			&&	rb_parent_database_settings_controller != Qnil )	{
		
		rb_parent_database	=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_type_btree_settings_controller,
								RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
								rb_parent_database );	
	}
	
	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_btree_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_btree_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_parentEnvironment(	VALUE	rb_database_type_btree_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController( rb_database_type_btree_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabase(	VALUE	rb_database_type_btree_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController( rb_database_type_btree_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_parentSettingsController(	VALUE	rb_database_type_btree_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController( rb_database_type_btree_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_btree_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_btree_settings_controller,
																															RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	if ( rb_parent_database_settings_controller == Qnil )	{
	
		VALUE	rb_parent_database_type_settings_controller		=	rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseTypeSettingsController( rb_database_type_btree_settings_controller );
		
		rb_parent_database_settings_controller							=	rb_RPbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );

	}
		
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_btree_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_btree_settings_controller,
																																	RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*****************************
*  record_number_retrieval?  *
*****************************/

//	DB_RECNUM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return ( RPbdb_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( c_database_type_btree_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/************************************
	*  turn_record_number_retrieval_on  *
	************************************/

	VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( VALUE	rb_database_type_btree_settings_controller )	{

		RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

		RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

	/*************************************
	*  turn_record_number_retrieval_off  *
	*************************************/

	VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( VALUE	rb_database_type_btree_settings_controller )	{

		RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

		RPbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

/***********************
*  reverse_splitting?  *
***********************/

//	DB_REVSPLITOFF		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_reverseSplitting( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	return ( RPbdb_DatabaseTypeBtreeSettingsController_reverseSplitting( c_database_type_btree_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/******************************
	*  turn_reverse_splitting_on  *
	******************************/

	VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( VALUE	rb_database_type_btree_settings_controller )	{
	
		RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );
	
		RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

	/*******************************
	*  turn_reverse_splitting_off  *
	*******************************/
	VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( VALUE	rb_database_type_btree_settings_controller )	{
	
		RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
		C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );
	
		RPbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( c_database_type_btree_settings_controller );

		return rb_database_type_btree_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/**************************
*  minimum_keys_per_page  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_minkey.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	int		c_minimum_keys_per_page	=	RPbdb_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( c_database_type_btree_settings_controller );
	
	VALUE	rb_minimum_keys_per_page	=	INT2FIX( c_minimum_keys_per_page );
	
	return rb_minimum_keys_per_page;
}

/******************************
*  set_minimum_keys_per_page  *
******************************/

VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	VALUE	rb_database_type_btree_settings_controller,
																			VALUE	rb_minimum_keys_per_page )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

	int	c_minimum_keys_per_page	=	FIX2INT( rb_minimum_keys_per_page);

	RPbdb_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	c_database_type_btree_settings_controller,
																																	c_minimum_keys_per_page );

	return rb_database_type_btree_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/
	
/******************************
*  set_prefix_compare_method  *
******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_prefix.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_setPrefixCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
	 																	VALUE(*prefix_compare_method)(	VALUE			database, 
																										const VALUE		data_one, 
																										const VALUE		data_two ) )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/**************************
*  prefix_compare_method  *
**************************/
/*
VALUE (*prefix_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPbdb_DatabaseTypeBtreeSettingsController_prefixCompareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/***********************
*  set_compare_method  *
***********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_bt_compare.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_setCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
 																	VALUE(*compare_method)(	VALUE			database, 
																							const VALUE		data_one, 
																							const VALUE		data_two ) )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*******************
*  compare_method  *
*******************/
/*
VALUE(*compare_method)(	VALUE		database, 
						const DBT*			data_one, 
						const DBT*			data_two ) RPbdb_DatabaseTypeBtreeSettingsController_compareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*********************************
*  set_duplicate_compare_method  *
*********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_dup_compare.html
VALUE rb_RPbdb_DatabaseTypeBtreeSettingsController_setDuplicateCompareMethod(	VALUE	rb_database_type_btree_settings_controller,
 																			VALUE(*duplicate_compare_method)(	VALUE			database, 
																												const VALUE		data_one, 
																												const VALUE		data_two ) )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/
/*****************************
*  duplicate_compare_method  *
*****************************/
/*
VALUE(*duplicate_compare_method)(	VALUE		database, 
									const DBT*			data_one, 
									const DBT*			data_two ) RPbdb_DatabaseTypeBtreeSettingsController_duplicateCompareMethod( VALUE	rb_database_type_btree_settings_controller )	{

	RPbdb_DatabaseTypeBtreeSettingsController*	c_database_type_btree_settings_controller;
	C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller );

}
*/