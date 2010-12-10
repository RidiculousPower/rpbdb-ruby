/*
 *		Rbdb::SettingsController::DatabaseSettingsController::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *		Rbdb::DatabaseController::Database::CursorController::Cursor::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseCursorCachePrioritySettingsController.h"
#include "rb_Rbdb_DatabaseCursorCacheSettingsController.h"
#include "rb_Rbdb_DatabaseCursorSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseCursorCachePrioritySettingsController.h>
#include <rbdb/Rbdb_DatabaseCursorCacheSettingsController.h>
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

void Init_Rbdb_DatabaseCursorCachePrioritySettingsController()	{

	rb_Rbdb_DatabaseCursorCachePrioritySettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseCursorCacheSettingsController, 
																																										"Priority",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"new",																					rb_Rbdb_DatabaseCursorCachePrioritySettingsController_new,											-1 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"initialize",																		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_initialize,											-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_environment",														rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"environment",																	"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_database",															rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"database",																			"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_settings_controller",										rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentSettingsController,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_database_settings_controller",					rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_database_cursor_settings_controller",		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"parent_database_cursor_cache_settings_controller",		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController,						0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"current_priority",									rb_Rbdb_DatabaseCursorCachePrioritySettingsController_priority,									0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"very_low?",								rb_Rbdb_DatabaseCursorCachePrioritySettingsController_veryLow,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"set_to_very_low",							rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryLow,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_very_low?",		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_very_low?",			rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow,					0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"low?",											rb_Rbdb_DatabaseCursorCachePrioritySettingsController_low,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"set_to_low",									rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setLow,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_low?",					rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastLow,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_low?",					rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostLow,							0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"default?",									rb_Rbdb_DatabaseCursorCachePrioritySettingsController_default,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"set_to_default",							rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setDefault,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_default?",			rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_default?",			rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostDefault,					0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"high?",										rb_Rbdb_DatabaseCursorCachePrioritySettingsController_high,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"set_to_high",									rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setHigh,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_high?",				rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_high?",					rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostHigh,							0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"very_high?",								rb_Rbdb_DatabaseCursorCachePrioritySettingsController_veryHigh,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"set_to_very_high",						rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryHigh,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_least_very_high?",		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseCursorCachePrioritySettingsController, 	"is_at_most_very_high?",		rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh,					0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_controller, rb_Rbdb_DatabaseCursorController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor, rb_Rbdb_DatabaseCursor ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_settings_controller, rb_Rbdb_DatabaseCursorSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cursor_cache_settings_controller, rb_Rbdb_DatabaseCursorCacheSettingsController ) ) ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_cursor_settings_controller	=	rb_Rbdb_DatabaseSettingsController_cursorSettingsController( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database_cursor != Qnil )	{
		rb_parent_database_cursor_settings_controller = rb_Rbdb_DatabaseSettingsController_cursorSettingsController( rb_parent_database_cursor );	
	}
	if ( rb_parent_database_cursor_settings_controller != Qnil )	{
		rb_parent_database_cursor_cache_settings_controller = rb_Rbdb_DatabaseCursorSettingsController_cacheSettingsController( rb_parent_database_cursor_settings_controller );
	}

	Rbdb_DatabaseCursorCacheSettingsController*	c_database_cursor_cache_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_parent_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller );		

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller	=	Rbdb_DatabaseCursorCacheSettingsController_priorityController( c_database_cursor_cache_settings_controller );
	
	VALUE	rb_database_cursor_cache_priority_settings_controller	= RUBY_RBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cursor_cache_priority_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_cursor_cache_priority_settings_controller,
							Rbdb_RB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER,
							rb_parent_database_cursor_cache_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_cursor_cache_settings_controller };
	rb_obj_call_init(	rb_database_cursor_cache_priority_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_cache_priority_settings_controller;		
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_settings_controller		=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_Rbdb_DatabaseCursorSettingsController_parentDatabaseSettingsController( rb_parent_database_cursor_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_cursor_settings_controller  *
***********************************************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController( rb_database_cursor_cache_priority_settings_controller );
	VALUE	rb_parent_database_cursor_settings_controller				=	rb_Rbdb_DatabaseCursorCacheSettingsController_parentDatabaseCursorSettingsController( rb_parent_database_cursor_cache_settings_controller );
	
	return rb_parent_database_cursor_settings_controller;
}

/*****************************************************
*  parent_database_cursor_cache_settings_controller  *
*****************************************************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cursor_cache_settings_controller	=	rb_iv_get(	rb_database_cursor_cache_priority_settings_controller,
																																					Rbdb_RB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER );

	return rb_parent_database_cursor_cache_settings_controller;
}

/*************
*  priority  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_priority( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	//	FIX - return constant
	return INT2FIX( Rbdb_DatabaseCursorCachePrioritySettingsController_priority( c_database_cursor_cache_priority_settings_controller ) );
}

/*************
*  very_low  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_veryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_veryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*****************
*  set_very_low  *
*****************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/**********************
*  at_least_very_low  *
**********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  at_most_very_low  *
*********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/********
*  low  *
********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_low( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_low( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

/************
*  set_low  *
************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	Rbdb_DatabaseCursorCachePrioritySettingsController_setLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*****************
*  at_least_low  *
*****************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																																																		:	Qfalse );
}

/****************
*  at_most_low  *
****************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/************
*  default  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_default( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_default( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/****************
*  set_default  *
****************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	Rbdb_DatabaseCursorCachePrioritySettingsController_setDefault( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  at_least_default  *
*********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  at_most_default  *
*********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********
*  high  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_high( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_high( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

/*************
*  set_high  *
*************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	Rbdb_DatabaseCursorCachePrioritySettingsController_setHigh( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/******************
*  at_least_high  *
******************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*****************
*  at_most_high  *
*****************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/**************
*  very_high  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_veryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_veryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/******************
*  set_very_high  *
******************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	Rbdb_DatabaseCursorCachePrioritySettingsController_setVeryHigh( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/********************
*  atLeastVeryHigh  *
********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/**********************
*  at_most_very_high  *
**********************/

VALUE rb_Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	Rbdb_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_Rbdb_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( Rbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}
