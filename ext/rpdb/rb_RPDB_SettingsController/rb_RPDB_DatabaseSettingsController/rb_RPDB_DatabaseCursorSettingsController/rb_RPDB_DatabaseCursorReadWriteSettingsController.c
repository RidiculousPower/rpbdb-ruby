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

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorReadWriteSettingsController.h>
#include "rb_RPDB_DatabaseCursorReadWriteSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorReadWriteSettingsController;

void Init_RPDB_DatabaseCursorReadWriteSettingsController()	{

	rb_RPDB_DatabaseCursorReadWriteSettingsController				=	rb_define_class_under(	rb_RPDB_DatabaseCursorSettingsController, 
																																										"ReadWrite",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"new",																					rb_RPDB_DatabaseCursorReadWriteSettingsController_new,																		1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorReadWriteSettingsController, 	"initialize",																		rb_RPDB_DatabaseCursorReadWriteSettingsController_init,																		1 	);
                    					
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

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																															VALUE	rb_parent_database_cursor_settings_controller )	{
	
	RPDB_DatabaseCursorSettingsController*	c_parent_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_parent_database_cursor_settings_controller, c_parent_database_cursor_settings_controller );
	
	VALUE	rb_database_cursor_read_write_settings_controller	=	RUBY_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorReadWriteSettingsController_new( c_parent_database_cursor_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_cursor_settings_controller;
	
	rb_obj_call_init(	rb_database_cursor_read_write_settings_controller,
					 1, 
					 argv );
	
	return rb_database_cursor_read_write_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_init(	VALUE	rb_database_cursor_read_write_settings_controller,
																															VALUE	rb_parent_database_cursor_settings_controller __attribute__ ((unused )) )	{

	return rb_database_cursor_read_write_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorReadWriteSettingsController_parentEnvironment( c_database_cursor_read_write_settings_controller ) );
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabase(	VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursorReadWriteSettingsController_parentDatabase( c_database_cursor_read_write_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/********************
*  permitWrite  *
********************/

//	DB_WRITECURSOR			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_cursor.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_permitWrite( VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_permitWrite( c_database_cursor_read_write_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/************************
	*  permitWriteOn  *
	************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( c_database_cursor_read_write_settings_controller );
		
		return rb_database_cursor_read_write_settings_controller;
	}

	/************************
	*  permitWriteOff  *
	************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

/********************
*  ignoreLease  *
********************/

//	DB_IGNORE_LEASE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease( VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease( c_database_cursor_read_write_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/************************
	*  ignoreLeaseOn  *
	************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

	/************************
	*  ignoreLeaseOff  *
	************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

/************************************
*  writeLocksInsteadOfReadLocks  *
************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_cursor_read_write_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOn  *
	****************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOff  *
	****************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

/********************************
*  returnMultipleDataItems  *
********************************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( c_database_cursor_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/************************************
	*  returnMultipleDataItemsOn  *
	************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

	/************************************
	*  returnMultipleDataItemsOff  *
	************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );
	
		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

/***********************************
*  returnMultipleKeyDataPairs  *
***********************************/

//	FIX - this is only for put, and only to organize key/data pairs in a particular way. We should hide this functionality and only 
//	enable one multiple data item. 

//	In the case of Btree or Hash databases, the multiple key and data pairs can be iterated over using the DB_MULTIPLE_KEY_NEXT macro.
//	In the case of Queue or Recno databases, the multiple record number and data pairs can be iterated over using the DB_MULTIPLE_RECNO_NEXT macro.
//	DB_MULTIPLE_KEY			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( VALUE	rb_database_cursor_read_write_settings_controller )	{

	RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
	C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

	return ( RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( c_database_cursor_read_write_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/***************************************
	*  returnMultipleKeyDataPairsOn  *
	***************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( VALUE	rb_database_cursor_read_write_settings_controller )	{

		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );

		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( c_database_cursor_read_write_settings_controller );
				
		return rb_database_cursor_read_write_settings_controller;
	}

	/***************************************
	*  returnMultipleKeyDataPairsOff  *
	***************************************/

	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( VALUE	rb_database_cursor_read_write_settings_controller )	{
	
		RPDB_DatabaseCursorReadWriteSettingsController*	c_database_cursor_read_write_settings_controller;
		C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_read_write_settings_controller );
	
		RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( c_database_cursor_read_write_settings_controller );

		return rb_database_cursor_read_write_settings_controller;
	}

