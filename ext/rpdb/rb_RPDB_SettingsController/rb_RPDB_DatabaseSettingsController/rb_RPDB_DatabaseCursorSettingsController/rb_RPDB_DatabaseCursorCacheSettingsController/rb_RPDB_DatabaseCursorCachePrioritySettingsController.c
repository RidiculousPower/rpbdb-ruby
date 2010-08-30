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

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorCachePrioritySettingsController.h>
#include "rb_RPDB_DatabaseCursorCachePrioritySettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCachePrioritySettingsController;

void Init_RPDB_DatabaseCursorCachePrioritySettingsController()	{

	rb_RPDB_DatabaseCursorCachePrioritySettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseCursorCacheSettingsController, 
																																										"CachePriority",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"new",											rb_RPDB_DatabaseCursorCachePrioritySettingsController_new,											1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorCachePrioritySettingsController, 	"initialize",								rb_RPDB_DatabaseCursorCachePrioritySettingsController_init,											1 	);
                    					
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

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_new(	VALUE	klass __attribute__ ((unused )),
																																	VALUE	rb_parent_database_cursor_cache_settings_controller )	{
	
	RPDB_DatabaseCursorCacheSettingsController*	c_parent_database_cursor_cache_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_parent_database_cursor_cache_settings_controller, c_parent_database_cursor_cache_settings_controller );
	
	VALUE	rb_database_cursor_cache_priority_settings_controller	= RUBY_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( RPDB_DatabaseCursorCachePrioritySettingsController_new( c_parent_database_cursor_cache_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_cursor_cache_settings_controller;
	
	rb_obj_call_init(	rb_database_cursor_cache_priority_settings_controller,
					 1, 
					 argv );
	
	return rb_database_cursor_cache_priority_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_init(	VALUE	rb_database_cursor_cache_priority_settings_controller,
																																	VALUE	rb_parent_database_cursor_cache_settings_controller __attribute__ ((unused )) )	{

	return rb_database_cursor_cache_priority_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorCachePrioritySettingsController_parentEnvironment( c_database_cursor_cache_priority_settings_controller ) );
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabase( c_database_cursor_cache_priority_settings_controller ) );
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
*  veryLow  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_veryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*****************
*  setVeryLow  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  atLeastVeryLow  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  atMostVeryLow  *
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
*  setLow  *
*************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setLow( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*****************
*  atLeastLow  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*********************
*  atMostLow  *
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
*  setDefault  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setDefault( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  atLeastDefault  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

/*********************
*  atMostDefault  *
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
*  setHigh  *
*****************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	RPDB_DatabaseCursorCachePrioritySettingsController_setHigh( c_database_cursor_cache_priority_settings_controller );

	return rb_database_cursor_cache_priority_settings_controller;
}

/*********************
*  atLeastHigh  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*********************
*  atMostHigh  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

/*****************
*  veryHigh  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

/*********************
*  setVeryHigh  *
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
*  atMostVeryHigh  *
*********************/

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_database_cursor_cache_priority_settings_controller )	{

	RPDB_DatabaseCursorCachePrioritySettingsController*	c_database_cursor_cache_priority_settings_controller;
	C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller );

	return ( RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( c_database_cursor_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
}
