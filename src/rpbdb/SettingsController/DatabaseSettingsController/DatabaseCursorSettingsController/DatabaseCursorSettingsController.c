/*
 *		RPbdb::DatabaseController::Database::CursorController::Cursor::CursorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseCursorSettingsController.h"
#include "DatabaseCursorReadWriteSettingsController.h"
#include "DatabaseCursor.h"

#include "RPbdb.h"

#include "DatabaseSettingsController.h"
#include "DatabaseCacheSettingsController.h"
#include "DatabaseCachePrioritySettingsController.h"
#include "DatabaseCursorCacheSettingsController.h"
#include "DatabaseCursorCachePrioritySettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseCursor.h>

#include <rpbdb/DatabaseCursorSettingsController.h>
#include <rpbdb/DatabaseCursorCacheSettingsController.h>
#include <rpbdb/DatabaseCursorReadWriteSettingsController.h>
#include <rpbdb/DatabaseCursorSettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_DatabaseCursorController;
extern	VALUE	rb_RPbdb_DatabaseCursor;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseCursorSettingsController;
extern	VALUE	rb_RPbdb_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPbdb_DatabaseCursorReadWriteSettingsController;
extern	VALUE	rb_RPbdb_SettingsController;

void Init_rb_RPbdb_DatabaseCursorSettingsController()	{

	rb_RPbdb_DatabaseCursorSettingsController				=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																						"Cursor",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseCursorSettingsController, 	"new",																		rb_RPbdb_DatabaseCursorSettingsController_new,																	-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"initialize",															rb_RPbdb_DatabaseCursorSettingsController_initialize,																-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_environment",											rb_RPbdb_DatabaseCursorSettingsController_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursorSettingsController, 	"environment",														"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_database",												rb_RPbdb_DatabaseCursorSettingsController_parentDatabase,											0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursorSettingsController, 	"database",																"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_database_cursor",									rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseCursor,											0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_cursor",													"parent_database_cursor"	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_settings_controller",							rb_RPbdb_DatabaseCursorSettingsController_parentSettingsController,											0 	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"parent_database_settings_controller",							rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController,											0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"duplicate_retains_location?",						rb_RPbdb_DatabaseCursorSettingsController_duplicateRetainsLocation,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_on",			rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_off",		rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff,			0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"cache_settings_controller",							rb_RPbdb_DatabaseCursorSettingsController_cacheSettingsController,							0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursorSettingsController, 	"cache",																	"cache_settings_controller"	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCursorSettingsController, 	"read_write_settings_controller",					rb_RPbdb_DatabaseCursorSettingsController_readWriteSettingsController,					0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCursorSettingsController, 	"read_write",															"read_write_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseCursorSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_database_cursor															=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_database_cursor, rb_RPbdb_DatabaseCursor ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent database cursor> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_database_cursor == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
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

	RPbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller	=	NULL;
	if ( rb_parent_database_cursor != Qnil )	{
		RPbdb_DatabaseCursor*	c_parent_database_cursor;
		C_RPBDB_DATABASE_CURSOR( rb_parent_database_cursor, c_parent_database_cursor );
		
		c_database_cursor_settings_controller	=	RPbdb_DatabaseCursor_settingsController( c_parent_database_cursor );
	}
	else if ( rb_parent_database_settings_controller != Qnil )	{
		RPbdb_DatabaseSettingsController*	c_database_settings_controller;
		C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
		c_database_cursor_settings_controller	=	RPbdb_DatabaseSettingsController_cursorSettingsController( c_database_settings_controller );
	}

	VALUE	rb_database_cursor_settings_controller	=	RUBY_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller );

	//	store reference to parent
	if ( rb_parent_database_cursor != Qnil )	{
	
		rb_iv_set(	rb_database_cursor_settings_controller,
								RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR,
								rb_parent_database_cursor );
		VALUE	rb_parent_database	=	rb_RPbdb_DatabaseCursor_parentDatabase( rb_parent_database_cursor );
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
	
		rb_iv_set(	rb_database_cursor_settings_controller,
								RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );
	}

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_cursor_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseCursorSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentEnvironment(	VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_database_cursor_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabase(	VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_database_cursor_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************
*  parent_database_cursor  *
***************************/

VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseCursor(	VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_parent_database_cursor	=	rb_iv_get(	rb_database_cursor_settings_controller,
																								RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR );

	return rb_parent_database_cursor;
}

/*******************************
*  parent_settings_controller  *
*******************************/
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentSettingsController(	VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_database_cursor_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/
VALUE rb_RPbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_cursor_settings_controller,
																															RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/********************************
*  duplicate_retains_location?  *
********************************/

//	DB_POSITION		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPbdb_DatabaseCursorSettingsController_duplicateRetainsLocation( VALUE	rb_database_cursor_settings_controller )	{

	RPbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return ( RPbdb_DatabaseCursorSettingsController_duplicateRetainsLocation( c_database_cursor_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/***************************************
	*  turn_duplicate_retains_location_on  *
	***************************************/

	VALUE rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( VALUE	rb_database_cursor_settings_controller )	{

		RPbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );
	
		RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( c_database_cursor_settings_controller );
	
		return rb_database_cursor_settings_controller;
	}

	/****************************************
	*  turn_duplicate_retains_location_off  *
	****************************************/

	VALUE rb_RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( VALUE	rb_database_cursor_settings_controller )	{

		RPbdb_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

		RPbdb_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( c_database_cursor_settings_controller );

		return rb_database_cursor_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/******************************
*  cache_settings_controller  *
******************************/

VALUE rb_RPbdb_DatabaseCursorSettingsController_cacheSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_database_cursor_cache_settings_controller	=	Qnil;
	
	if ( ( rb_database_cursor_cache_settings_controller = rb_iv_get(	rb_database_cursor_settings_controller,
																																		RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_database_cursor_cache_settings_controller	=	rb_RPbdb_DatabaseCursorCacheSettingsController_new(	1,
																																																				& rb_database_cursor_settings_controller,
																																																				rb_RPbdb_DatabaseCursorCacheSettingsController );
		rb_iv_set(	rb_database_cursor_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER,
								rb_database_cursor_cache_settings_controller );
	}
	
	return rb_database_cursor_cache_settings_controller;
}

/***********************************
*  read_write_settings_controller  *
***********************************/

VALUE rb_RPbdb_DatabaseCursorSettingsController_readWriteSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	VALUE	rb_database_cursor_read_write_settings_controller	=	Qnil;
	
	if ( ( rb_database_cursor_read_write_settings_controller = rb_iv_get(	rb_database_cursor_settings_controller,
																																				RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_database_cursor_read_write_settings_controller	=	rb_RPbdb_DatabaseCursorReadWriteSettingsController_new(	1,
																																																								& rb_database_cursor_settings_controller,
																																																								rb_RPbdb_DatabaseCursorReadWriteSettingsController );
		rb_iv_set(	rb_database_cursor_settings_controller,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER,
								rb_database_cursor_read_write_settings_controller );
	}
	
	return rb_database_cursor_read_write_settings_controller;
}
