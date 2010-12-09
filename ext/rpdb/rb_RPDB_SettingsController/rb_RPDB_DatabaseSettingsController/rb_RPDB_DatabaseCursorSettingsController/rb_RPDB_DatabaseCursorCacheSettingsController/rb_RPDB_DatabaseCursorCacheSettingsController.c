/*
 *		Rbdb::SettingsController::DatabaseSettingsController::CursorSettingsController::CursorCacheSettingsController
 *		Rbdb::DatabaseController::Database::CursorController::Cursor::CursorSettingsController::CursorCacheSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseCursorCacheSettingsController.h"
#include "rb_Rbdb_DatabaseCursorCachePrioritySettingsController.h"
#include "rb_Rbdb_DatabaseCursorSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseCursorCacheSettingsController.h>

#include <rbdb/Rbdb_DatabaseCursorCachePrioritySettingsController.h>

#include <rbdb/Rbdb_DatabaseCursorSettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_Database.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseCursorController;
extern	VALUE	rb_Rbdb_DatabaseCursor;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCursorSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCursorCachePrioritySettingsController;

void Init_Rbdb_DatabaseCursorCacheSettingsController()	{

	rb_Rbdb_DatabaseCursorCacheSettingsController			=	rb_define_class_under(	rb_Rbdb_DatabaseCursorSettingsController, 
																																							"Cache",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseCursorCacheSettingsController, 	"new",											rb_Rbdb_DatabaseCursorCacheSettingsController_new,												-1 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"initialize",								rb_Rbdb_DatabaseCursorCacheSettingsController_initialize,												-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"parent_environment",				rb_Rbdb_DatabaseCursorCacheSettingsController_parentEnvironment,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"parent_database",					rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabase,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"parent_settings_controller",					rb_Rbdb_DatabaseCursorCacheSettingsController_parentSettingsController,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"parent_database_settings_controller",					rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"parent_database_cursor_settings_controller",					rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController,							0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"priority_settings_controller",			rb_Rbdb_DatabaseCursorCacheSettingsController_prioritySettingsController,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorCacheSettingsController, 	"priority",													"priority_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_controller, rb_Rbdb_DatabaseCursorController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor, rb_Rbdb_DatabaseCursor ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_settings_controller, rb_Rbdb_DatabaseCursorSettingsController ) ) ),
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
			&&	rb_parent_database_settings_controller == Qnil
			&&	rb_parent_database_cursor_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database_cursor != Qnil )	{
		rb_parent_database_cursor_settings_controller = rb_Rbdb_DatabaseSettingsController_cursorSettingsController( rb_parent_database_cursor );	
	}
	else if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_cursor_settings_controller	=	rb_Rbdb_DatabaseSettingsController_cursorSettingsController( rb_parent_database_settings_controller );
	}

	Rbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_Rbdb_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_parent_database_cursor_settings_controller, c_database_cursor_settings_controller );		

	Rbdb_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller	=	Rbdb_DatabaseCursorSettingsController_cacheSettingsController( c_database_cursor_settings_controller );

	VALUE	rb_database_cursor_cache_settings_controller	= RUBY_Rbdb_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( c_database_cursor_cache_settings_controller );
	
	//	store reference to parent
	rb_iv_set(	rb_database_cursor_cache_settings_controller,
							Rbdb_RB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER,
							rb_parent_database_cursor_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_cursor_settings_controller };
	rb_obj_call_init(	rb_database_cursor_cache_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_cache_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_environment														=	rb_Rbdb_DatabaseCursorSettingsController_parentEnvironment( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_Rbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_cursor_settings_controller  *
***********************************************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_iv_get(	rb_database_cursor_cache_settings_controller,
																																					Rbdb_RB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER );

	return rb_parent_database_cursor_cache_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*********************************
*  priority_settings_controller  *
*********************************/

VALUE rb_Rbdb_DatabaseCursorCacheSettingsController_prioritySettingsController( VALUE rb_database_cursor_cache_settings_controller )	{

	VALUE	rb_database_cursor_cache_priority_settings_controller	=	Qnil;
	if ( ( rb_database_cursor_cache_priority_settings_controller = rb_iv_get(	rb_database_cursor_cache_settings_controller,
																																						Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_database_cursor_cache_priority_settings_controller	=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_new(	1,
																																																												& rb_database_cursor_cache_settings_controller,
																																																												rb_Rbdb_DatabaseCursorCachePrioritySettingsController );
		rb_iv_set(	rb_database_cursor_cache_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER,
								rb_database_cursor_cache_priority_settings_controller );
	}
	
	return rb_database_cursor_cache_priority_settings_controller;
}
