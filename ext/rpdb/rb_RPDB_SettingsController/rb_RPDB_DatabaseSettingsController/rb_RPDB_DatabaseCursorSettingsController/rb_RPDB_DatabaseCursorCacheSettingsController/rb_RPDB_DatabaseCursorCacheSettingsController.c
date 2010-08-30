/*
 *		RPDB::SettingsController::DatabaseSettingsController::CursorSettingsController::CursorCacheSettingsController
 *		RPDB::DatabaseController::Database::CursorController::Cursor::CursorSettingsController::CursorCacheSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorCacheSettingsController.h>
#include "rb_RPDB_DatabaseCursorCacheSettingsController.h"

#include <rpdb/RPDB_DatabaseCursorCachePrioritySettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCachePrioritySettingsController;

void Init_RPDB_DatabaseCursorCacheSettingsController()	{

	rb_RPDB_DatabaseCursorCacheSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseCursorSettingsController, 
																																							"Cache",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorCacheSettingsController, 	"new",											rb_RPDB_DatabaseCursorCacheSettingsController_new,												1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"initialize",								rb_RPDB_DatabaseCursorCacheSettingsController_init,												1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"parent_environment",				rb_RPDB_DatabaseCursorCacheSettingsController_parentEnvironment,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"parent_database",					rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabase,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"database",									"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"priority_controller",			rb_RPDB_DatabaseCursorCacheSettingsController_priorityController,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"priority",									"priority_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																													VALUE	rb_parent_database_cursor_settings_controller )	{
	
	RPDB_DatabaseCursorSettingsController*	c_parent_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_parent_database_cursor_settings_controller, c_parent_database_cursor_settings_controller );
	
	VALUE	rb_database_cursor_cache_settings_controller	= RUBY_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorCacheSettingsController_new( c_parent_database_cursor_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_cursor_settings_controller;
	
	rb_obj_call_init(	rb_database_cursor_cache_settings_controller,
					 1, 
					 argv );
	
	return rb_database_cursor_cache_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_init(	VALUE	rb_database_cursor_cache_settings_controller,
																													VALUE	rb_parent_database_cursor_settings_controller __attribute__ ((unused )) )	{

	return rb_database_cursor_cache_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller )	{

	RPDB_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorCacheSettingsController_parentEnvironment( c_database_cursor_cache_settings_controller ) );
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller )	{

	RPDB_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursorCacheSettingsController_parentDatabase( c_database_cursor_cache_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/**************************
*  priorityController  *
**************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_priorityController( VALUE rb_database_cursor_cache_settings_controller )	{

	RPDB_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( RPDB_DatabaseCursorCacheSettingsController_priorityController( c_database_cursor_cache_settings_controller ) );
}
