/*
 *		RPDB::DatabaseController::Database::CursorController::Cursor::CursorSettingsController
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

#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorCacheSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorReadWriteSettingsController.h>

#include "rb_RPDB_DatabaseCursorSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorReadWriteSettingsController;

void Init_RPDB_DatabaseCursorSettingsController()	{

	rb_RPDB_DatabaseCursorSettingsController				=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Cursor",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorSettingsController, 	"new",																		rb_RPDB_DatabaseCursorSettingsController_new,																	1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"initialize",															rb_RPDB_DatabaseCursorSettingsController_init,																1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"parent_environment",											rb_RPDB_DatabaseCursorSettingsController_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"environment",														"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"parent_database",												rb_RPDB_DatabaseCursorSettingsController_parentDatabase,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"database",																"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"duplicate_retains_location?",						rb_RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation,						0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_on",			rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_off",		rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"cache_settings_controller",							rb_RPDB_DatabaseCursorSettingsController_cacheSettingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"cache",																	"cache_settings_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"record_read_write_settings_controller",					rb_RPDB_DatabaseCursorSettingsController_readWriteSettingsController,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"read_write",															"record_read_write_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_cursor_settings_controller	=	RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( RPDB_DatabaseCursorSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_cursor_settings_controller,
					 1, 
					 argv );
	
	return rb_database_cursor_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorSettingsController_init(	VALUE	rb_database_cursor_settings_controller,
																											VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_cursor_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorSettingsController_parentEnvironment(	VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorSettingsController_parentEnvironment( c_database_cursor_settings_controller ) );
	
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorSettingsController_parentDatabase(	VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursorSettingsController_parentDatabase( c_database_cursor_settings_controller ) );
}

/**********************************
*  duplicateRetainsLocation  *
**********************************/

//	DB_POSITION		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return ( RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation( c_database_cursor_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/**************************************
	*  duplicateRetainsLocationOn  *
	**************************************/

	VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( VALUE	rb_database_cursor_settings_controller )	{

		RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );
	
		RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( c_database_cursor_settings_controller );
	
		return rb_database_cursor_settings_controller;
	}

	/**************************************
	*  duplicateRetainsLocationOff  *
	**************************************/

	VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( VALUE	rb_database_cursor_settings_controller )	{

		RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

		RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( c_database_cursor_settings_controller );

		return rb_database_cursor_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/****************************
*  cacheController  *
****************************/

VALUE rb_RPDB_DatabaseCursorSettingsController_cacheSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorSettingsController_cacheSettingsController( c_database_cursor_settings_controller ) );
}

/******************************
*  readWriteController  *
******************************/

VALUE rb_RPDB_DatabaseCursorSettingsController_readWriteSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorSettingsController_readWriteSettingsController( c_database_cursor_settings_controller ) );
}
