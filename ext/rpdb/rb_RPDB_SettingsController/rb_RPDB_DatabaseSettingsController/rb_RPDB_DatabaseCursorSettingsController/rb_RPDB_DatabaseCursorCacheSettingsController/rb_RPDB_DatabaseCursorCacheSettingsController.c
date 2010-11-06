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

#include "rb_RPDB_DatabaseCursorCacheSettingsController.h"
#include "rb_RPDB_DatabaseCursorSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorCacheSettingsController.h>

#include <rpdb/RPDB_DatabaseCursorCachePrioritySettingsController.h>

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
extern	VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCachePrioritySettingsController;

void Init_RPDB_DatabaseCursorCacheSettingsController()	{

	rb_RPDB_DatabaseCursorCacheSettingsController			=	rb_define_class_under(	rb_RPDB_DatabaseCursorSettingsController, 
																																							"Cache",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorCacheSettingsController, 	"new",											rb_RPDB_DatabaseCursorCacheSettingsController_new,												-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCacheSettingsController, 	"initialize",								rb_RPDB_DatabaseCursorCacheSettingsController_init,												-1 	);
                    					
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

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_new(	int			argc,
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
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
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

	RPDB_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller	=	RPDB_DatabaseCursorSettingsController_cacheSettingsController( c_database_cursor_settings_controller );

	VALUE	rb_database_cursor_cache_settings_controller	= RUBY_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( c_database_cursor_cache_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_cursor_cache_settings_controller,
							RPDB_RB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER,
							rb_parent_database_cursor_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_cursor_settings_controller };
	rb_obj_call_initialize(	rb_database_cursor_cache_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_cache_settings_controller;		
}

/************
*  initialize  *
************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_environment														=	rb_RPDB_DatabaseCursorSettingsController_parentEnvironment( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPDB_DatabaseCursorSettingsController_parentSettingsController( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***************************************
*  parent_database_cursor_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_iv_get(	rb_database_cursor_cache_settings_controller,
																																					RPDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_cursor_cache_settings_controller;
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
