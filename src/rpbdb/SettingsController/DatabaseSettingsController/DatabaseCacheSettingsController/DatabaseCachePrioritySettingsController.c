/*
 *		RPbdb::Database::Cursor::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseCachePrioritySettingsController.h"

#include "DatabaseSettingsController.h"
#include "DatabaseCacheSettingsController.h"

#include "DatabaseSettingsController.h"
#include "SettingsController.h"

#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseCacheSettingsController.h>
#include <rpbdb/DatabaseCachePrioritySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;
extern	VALUE	rb_RPbdb_DatabaseCacheSettingsController;
extern	VALUE	rb_RPbdb_DatabaseCachePrioritySettingsController;

void Init_rb_RPbdb_DatabaseCachePrioritySettingsController()	{

	rb_RPbdb_DatabaseCachePrioritySettingsController	=	rb_define_class_under(	rb_RPbdb_DatabaseCacheSettingsController, 
																																						"Priority",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseCachePrioritySettingsController, 	"new",											rb_RPbdb_DatabaseCachePrioritySettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"initialize",								rb_RPbdb_DatabaseCachePrioritySettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"parent_environment",				rb_RPbdb_DatabaseCachePrioritySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"parent_database",					rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"parent_settings_controller",					rb_RPbdb_DatabaseCachePrioritySettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"parent_database_settings_controller",					rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"parent_database_cache_settings_controller",					rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController,					0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"current_priority",					rb_RPbdb_DatabaseCachePrioritySettingsController_priority,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"priority",									"current_priority"	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"very_low?",								rb_RPbdb_DatabaseCachePrioritySettingsController_veryLow,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"set_to_very_low",							rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryLow,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_very_low?",		rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_very_low?",			rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow,				0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"low?",											rb_RPbdb_DatabaseCachePrioritySettingsController_low,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"set_to_low",									rb_RPbdb_DatabaseCachePrioritySettingsController_setLow,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_low?",					rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastLow,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_low?",					rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostLow,						0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"default?",									rb_RPbdb_DatabaseCachePrioritySettingsController_default,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"set_to_default",							rb_RPbdb_DatabaseCachePrioritySettingsController_setDefault,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_default?",			rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_default?",			rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostDefault,				0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"high?",										rb_RPbdb_DatabaseCachePrioritySettingsController_high,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"set_to_high",									rb_RPbdb_DatabaseCachePrioritySettingsController_setHigh,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_high?",				rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_high?",					rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostHigh,						0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"very_high?",								rb_RPbdb_DatabaseCachePrioritySettingsController_veryHigh,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"set_to_very_high",						rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryHigh,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_very_high?",		rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_very_high?",		rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh,				0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment													=	Qnil;
	VALUE	rb_parent_database_controller									=	Qnil;
	VALUE	rb_parent_database														=	Qnil;
	VALUE	rb_parent_settings_controller				=	Qnil;
	VALUE	rb_parent_database_settings_controller				=	Qnil;
	VALUE	rb_parent_database_cache_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment,													rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller,									rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database,														rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller,									rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller,				rb_RPbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cache_settings_controller,	rb_RPbdb_DatabaseCacheSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database cache settings controller> ]"
		)
	);

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil
			&&	rb_parent_database_cache_settings_controller == Qnil )	{
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
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_cache_settings_controller	=	rb_RPbdb_DatabaseSettingsController_cacheSettingsController( rb_parent_database_settings_controller );
	}

	RPbdb_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_parent_database_cache_settings_controller, c_database_cache_settings_controller );		

	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller	=	RPbdb_DatabaseCacheSettingsController_priorityController( c_database_cache_settings_controller );

	VALUE	rb_database_cache_priority_settings_controller	=	RUBY_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cache_priority_settings_controller );

	rb_iv_set(	rb_database_cache_priority_settings_controller,
							RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER,
							rb_parent_database_cache_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_cache_settings_controller };
	rb_obj_call_init(	rb_database_cache_priority_settings_controller,
										1, 
										argv );
	
	return rb_database_cache_priority_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_environment										=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );

	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_database											=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );

	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );

	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cache_settings_controller	=	rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_database_settings_controller				=	rb_RPbdb_DatabaseCacheSettingsController_parentDatabaseSettingsController( rb_parent_database_cache_settings_controller );

	return rb_parent_database_settings_controller;
}

/**********************************************
*  parent_database_cache_settings_controller  *
**********************************************/

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cache_settings_controller	=	rb_iv_get(	rb_database_cache_priority_settings_controller,
																																		RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER );

	return rb_parent_database_cache_settings_controller;
}


/*************
*  priority  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_priority( VALUE	rb_database_cache_priority_settings_controller )	{
	
	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_priority( c_database_cache_priority_settings_controller ) );
}

/*************
*  very_low  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_veryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_veryLow( c_database_cache_priority_settings_controller ) );
}

	/*****************
	*  set_very_low  *
	*****************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
		
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		RPbdb_DatabaseCachePrioritySettingsController_setVeryLow( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/**********************
	*  at_least_very_low  *
	**********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( c_database_cache_priority_settings_controller ) );
	}

	/*********************
	*  at_most_very_low  *
	*********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( c_database_cache_priority_settings_controller ) );
	}

/********
*  low  *
********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_low( VALUE	rb_database_cache_priority_settings_controller )	{

	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_low( c_database_cache_priority_settings_controller ) );
}

	/************
	*  set_low  *
	************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setLow( VALUE	rb_database_cache_priority_settings_controller )	{

		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		RPbdb_DatabaseCachePrioritySettingsController_setLow( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/*****************
	*  at_least_low  *
	*****************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( VALUE	rb_database_cache_priority_settings_controller )	{

		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( c_database_cache_priority_settings_controller ) );
	}

	/****************
	*  at_most_low  *
	****************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtMostLow( c_database_cache_priority_settings_controller ) );
	}

/************
*  default  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_default( VALUE	rb_database_cache_priority_settings_controller )	{

	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_default( c_database_cache_priority_settings_controller ) );
}

	/****************
	*  set_default  *
	****************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setDefault( VALUE	rb_database_cache_priority_settings_controller )	{

		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		RPbdb_DatabaseCachePrioritySettingsController_setDefault( c_database_cache_priority_settings_controller );

		return Qnil;
	}

	/*********************
	*  at_least_default  *
	*********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_database_cache_priority_settings_controller )	{
		
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( c_database_cache_priority_settings_controller ) );
	}

	/********************
	*  at_most_default  *
	********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( c_database_cache_priority_settings_controller ) );
	}

/*********
*  high  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_high( VALUE	rb_database_cache_priority_settings_controller )	{
	
	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_high( c_database_cache_priority_settings_controller ) );
}

	/*************
	*  set_high  *
	*************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setHigh( VALUE	rb_database_cache_priority_settings_controller )	{
		
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		RPbdb_DatabaseCachePrioritySettingsController_setHigh( c_database_cache_priority_settings_controller );

		return Qnil;
	}

	/******************
	*  at_least_high  *
	******************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( c_database_cache_priority_settings_controller ) );
	}

	/*****************
	*  at_most_high  *
	*****************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( c_database_cache_priority_settings_controller ) );
	}

/**************
*  very_high  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_veryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
	RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_veryHigh( c_database_cache_priority_settings_controller ) );
}

	/******************
	*  set_very_high  *
	******************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		RPbdb_DatabaseCachePrioritySettingsController_setVeryHigh( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/***********************
	*  at_least_very_high  *
	***********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( c_database_cache_priority_settings_controller ) );
	}

	/**********************
	*  at_most_very_high  *
	**********************/

	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		RPbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( c_database_cache_priority_settings_controller ) );
	}
