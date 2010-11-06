/*
 *		RPDB::SettingsController::DatabaseSettingsController::CursorSettingsController::CursorReadWriteSettingsController
 *		RPDB::DatabaseController::Database::CursorController::Cursor::CursorSettingsController::CursorReadWriteSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseCursorReadWriteSettingsController.h"
#include "rb_RPDB_DatabaseCursorSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_Database.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseCursorController;
extern	VALUE	rb_RPDB_DatabaseCursor;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorReadWriteSettingsController;

void Init_RPDB_DatabaseCursorReadWriteSettingsController()	{

	rb_RPDB_DatabaseCursorReadWriteSettingsController				=	rb_define_class_under(	rb_RPDB_DatabaseCursorSettingsController, 
																																										"ReadWrite",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"new",																					rb_RPDB_DatabaseCursorReadWriteSettingsController_new,																		-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"initialize",																		rb_RPDB_DatabaseCursorReadWriteSettingsController_initialize,																		-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"parent_environment",														rb_RPDB_DatabaseCursorReadWriteSettingsController_parentEnvironment,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"environment",																	"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"parent_database",															rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabase,													0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"database",																			"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"permit_write?",																rb_RPDB_DatabaseCursorReadWriteSettingsController_permitWrite,														0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_permit_write_on",													rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn,											0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_permit_write_off",												rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff,											0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"ignore_lease?",																rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease,														0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_ignore_lease_on",													rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn,													0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_ignore_lease_off",												rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff,													0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"write_locks_instead_of_read_locks?",						rb_RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks,						0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_on",		rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_off",		rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff,		0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"return_multiple_data_items?",									rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems,								0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_return_multiple_data_items_on",						rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_return_multiple_data_items_off",					rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff,					0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"return_multiple_key_data_pairs?",							rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs,							0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_return_multiple_key_data_pairs_on",				rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"turn_return_multiple_key_data_pairs_off",			rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff,			0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_new(	int			argc,
																															VALUE*	args,
																															VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_database_cursor_controller									=	Qnil;
	VALUE	rb_parent_database_cursor															=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_cursor_settings_controller					=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_controller, rb_RPDB_DatabaseCursorController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor, rb_RPDB_DatabaseCursor ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_settings_controller, rb_RPDB_DatabaseCursorSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent database cursor controller> ]",
			"[ <parent database cursor> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database cursor settings controller> ]"
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
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_cursor_settings_controller	=	rb_RPDB_DatabaseSettingsController_cursorSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_parent_database_cursor_settings_controller, c_database_cursor_settings_controller );		

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller	=	RPDB_DatabaseCursorSettingsController_readWriteSettingsController( c_database_cursor_settings_controller );

	VALUE	rb_database_cursor_read_write_settings_controller	=	RUBY_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( c_database_cursor_read_write_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_cursor_read_write_settings_controller,
							RPDB_RB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER,
							rb_parent_database_cursor_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_cursor_settings_controller };
	rb_obj_call_init(	rb_database_cursor_read_write_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_read_write_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController( rb_database_cursor_record_read_write_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabase(	VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController( rb_database_cursor_record_read_write_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController( rb_database_cursor_record_read_write_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_record_read_write_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPDB_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_cursor_settings_controller  *
***********************************************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller	=	rb_iv_get(	rb_database_cursor_record_read_write_settings_controller,
																																					RPDB_RB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER );

	return rb_parent_database_cursor_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*****************
*  permit_write  *
*****************/

//	DB_WRITECURSOR			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_permitWrite( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_permitWrite( c_database_cursor_record_read_write_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/********************
	*  permit_write_on  *
	********************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( c_database_cursor_record_read_write_settings_controller );
		
		return rb_database_cursor_record_read_write_settings_controller;
	}

	/*********************
	*  permit_write_off  *
	*********************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

/*****************
*  ignore_lease  *
*****************/

//	DB_IGNORE_LEASE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease( c_database_cursor_record_read_write_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/********************
	*  ignore_lease_on  *
	********************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

	/*********************
	*  ignore_lease_off  *
	*********************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

/**************************************
*  write_locks_instead_of_read_locks  *
**************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_cursor_record_read_write_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/**********************************************
	*  turn_write_locks_instead_of_read_locks_on  *
	**********************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

	/***********************************************
	*  turn_write_locks_instead_of_read_locks_off  *
	***********************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

/*******************************
*  return_multiple_data_items  *
*******************************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( c_database_cursor_record_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/***************************************
	*  turn_return_multiple_data_items_on  *
	***************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

	/****************************************
	*  turn_return_multiple_data_items_off  *
	****************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );
	
		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

/***********************************
*  return_multiple_key_data_pairs  *
***********************************/

//	FIX - this is only for put, and only to organize key/data pairs in a particular way. We should hide this functionality and only 
//	enable one multiple data item. 

//	In the case of Btree or Hash databases, the multiple key and data pairs can be iterated over using the DB_MULTIPLE_KEY_NEXT macro.
//	In the case of Queue or Recno databases, the multiple record number and data pairs can be iterated over using the DB_MULTIPLE_RECNO_NEXT macro.
//	DB_MULTIPLE_KEY			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( c_database_cursor_record_read_write_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/*******************************************
	*  turn_return_multiple_key_data_pairs_on  *
	*******************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( VALUE	rb_database_cursor_record_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( c_database_cursor_record_read_write_settings_controller );
				
		return rb_database_cursor_record_read_write_settings_controller;
	}

	/********************************************
	*  turn_return_multiple_key_data_pairs_off  *
	********************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( VALUE	rb_database_cursor_record_read_write_settings_controller )	{
	
		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_record_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller );
	
		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( c_database_cursor_record_read_write_settings_controller );

		return rb_database_cursor_record_read_write_settings_controller;
	}

