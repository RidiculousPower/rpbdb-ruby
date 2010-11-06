/*
 *		RPDB::SettingsController::DatabaseSettingsController::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *		RPDB::DatabaseController::Database::CursorController::Cursor::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseCursorCachePrioritySettingsController.h"
#include "rb_RPDB_DatabaseCursorCacheSettingsController.h"
#include "rb_RPDB_DatabaseCursorSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorCachePrioritySettingsController.h>
#include <rpdb/RPDB_DatabaseCursorCacheSettingsController.h>
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

void Init_RPDB_DatabaseCursorCachePrioritySettingsController()	{

	rb_RPDB_DatabaseCursorCachePrioritySettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseCursorCacheSettingsController, 
																																										"Priority",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"new",											rb_RPDB_DatabaseCursorCachePrioritySettingsController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"initialize",								rb_RPDB_DatabaseCursorCachePrioritySettingsController_initialize,											-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"parent_environment",				rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"parent_database",					rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"database",									"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"priority",									rb_RPDB_DatabaseCursorCachePrioritySettingsController_priority,									0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"very_low?",								rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryLow,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"set_very_low",							rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow,								0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_very_low?",		rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow,					0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_very_low?",			rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow,					0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"low?",											rb_RPDB_DatabaseCursorCachePrioritySettingsController_low,											0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"set_low",									rb_RPDB_DatabaseCursorCachePrioritySettingsController_setLow,										0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_low?",					rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow,							0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_low?",					rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostLow,							0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"default?",									rb_RPDB_DatabaseCursorCachePrioritySettingsController_default,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"set_default",							rb_RPDB_DatabaseCursorCachePrioritySettingsController_setDefault,								0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_default?",			rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault,					0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_default?",			rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostDefault,					0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"high?",										rb_RPDB_DatabaseCursorCachePrioritySettingsController_high,											0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"set_high",									rb_RPDB_DatabaseCursorCachePrioritySettingsController_setHigh,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_high?",				rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh,						0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_high?",					rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh,							0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"very_high?",								rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"set_very_high",						rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryHigh,							0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_very_high?",		rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh,				0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_very_high?",		rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh,					0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_new(	int			argc,
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
	VALUE	rb_parent_database_cursor_cache_settings_controller		=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_controller, rb_RPDB_DatabaseCursorController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor, rb_RPDB_DatabaseCursor ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_settings_controller, rb_RPDB_DatabaseCursorSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_cache_settings_controller, rb_RPDB_DatabaseCursorCacheSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent database cursor controller> ]",
			"[ <parent database cursor> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database cursor settings controller> ]",
			"[ <parent database cursor cache settings controller> ]"
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
	if ( rb_parent_database_cursor_settings_controller != Qnil )	{
		rb_parent_database_cursor_cache_settings_controller = rb_RPDB_DatabaseCursorCacheSettingsController_priorityController( rb_parent_database_cursor_settings_controller );
	}

	RPDB_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_parent_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller );		

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller	=	RPDB_DatabaseCursorCacheSettingsController_priorityController( c_database_cursor_cache_settings_controller );
	
	VALUE	rb_database_cursor_cache_priority_settings_controller	= RUBY_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cursor_cache_priority_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_cursor_cache_priority_settings_controller,
							RPDB_RB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER,
							rb_parent_database_cursor_cache_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_cursor_cache_settings_controller };
	rb_obj_call_init(	rb_database_cursor_cache_priority_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_cache_priority_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPDB_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***************************************
*  parent_database_cursor_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database_cursor_settings_controller				=	rb_RPDB_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_parent_database_cursor_cache_settings_controller );
	
	return rb_parent_database_cursor_settings_controller;
}

/***************************************
*  parent_database_cursor_cache_settings_controller  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_iv_get(	rb_database_cursor_cache_priority_settings_controller,
																																					RPDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_cursor_cache_settings_controller;
}

/*****************
*  priority  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_priority( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	//	FIX - return constant
	return INT2FIX( RPDB_DatabaseCursorCachePrioritySettingsController_priority( c_database_cursor_cache_priority_settings_controller ) );
}

/*****************
*  very_low  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_veryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*****************
*  set_very_low  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  at_least_very_low  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  at_most_very_low  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/************
*  low  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_low( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_low( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

/*************
*  set_low  *
*************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*****************
*  at_least_low  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*********************
*  at_most_low  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*****************
*  default  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_default( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_default( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*****************
*  set_default  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setDefault( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  at_least_default  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  at_most_default  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*************
*  high  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_high( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_high( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

/*****************
*  set_high  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setHigh( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  at_least_high  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*********************
*  at_most_high  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*****************
*  very_high  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*********************
*  set_very_high  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setVeryHigh( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*************************
*  atLeastVeryHigh  *
*************************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  at_most_very_high  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}
