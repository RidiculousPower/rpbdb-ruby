/*
 *		Rbdb::Database::Cursor::CursorSettingsController::CursorCacheSettingsController::CursorSettingsCachePriorityController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseCachePrioritySettingsController.h"

#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_DatabaseCacheSettingsController.h"

#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseCacheSettingsController.h>
#include <rbdb/Rbdb_DatabaseCachePrioritySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCacheSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCachePrioritySettingsController;

void Init_rb_Rbdb_DatabaseCachePrioritySettingsController()	{

	rb_Rbdb_DatabaseCachePrioritySettingsController	=	rb_define_class_under(	rb_Rbdb_DatabaseCacheSettingsController, 
																																						"Priority",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseCachePrioritySettingsController, 	"new",											rb_Rbdb_DatabaseCachePrioritySettingsController_new,										-1 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"initialize",								rb_Rbdb_DatabaseCachePrioritySettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"parent_environment",				rb_Rbdb_DatabaseCachePrioritySettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"environment",							"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"parent_database",					rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"database",									"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"parent_settings_controller",					rb_Rbdb_DatabaseCachePrioritySettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"parent_database_settings_controller",					rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"parent_database_cache_settings_controller",					rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController,					0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"current_priority",					rb_Rbdb_DatabaseCachePrioritySettingsController_priority,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"priority",									"current_priority"	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"very_low?",								rb_Rbdb_DatabaseCachePrioritySettingsController_veryLow,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"set_to_very_low",							rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryLow,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_very_low?",		rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_very_low?",			rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow,				0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"low?",											rb_Rbdb_DatabaseCachePrioritySettingsController_low,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"set_to_low",									rb_Rbdb_DatabaseCachePrioritySettingsController_setLow,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_low?",					rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastLow,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_low?",					rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostLow,						0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"default?",									rb_Rbdb_DatabaseCachePrioritySettingsController_default,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"set_to_default",							rb_Rbdb_DatabaseCachePrioritySettingsController_setDefault,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_default?",			rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_default?",			rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostDefault,				0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"high?",										rb_Rbdb_DatabaseCachePrioritySettingsController_high,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"set_to_high",									rb_Rbdb_DatabaseCachePrioritySettingsController_setHigh,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_high?",				rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_high?",					rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostHigh,						0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"very_high?",								rb_Rbdb_DatabaseCachePrioritySettingsController_veryHigh,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"set_to_very_high",						rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryHigh,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_least_very_high?",		rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseCachePrioritySettingsController, 	"is_at_most_very_high?",		rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh,				0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment,													rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller,									rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database,														rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller,									rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller,				rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_cache_settings_controller,	rb_Rbdb_DatabaseCacheSettingsController ) ) ),
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
		rb_parent_database_cache_settings_controller	=	rb_Rbdb_DatabaseSettingsController_cacheSettingsController( rb_parent_database_settings_controller );
	}

	Rbdb_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_parent_database_cache_settings_controller, c_database_cache_settings_controller );		

	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller	=	Rbdb_DatabaseCacheSettingsController_priorityController( c_database_cache_settings_controller );

	VALUE	rb_database_cache_priority_settings_controller	=	RUBY_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cache_priority_settings_controller );

	rb_iv_set(	rb_database_cache_priority_settings_controller,
							RBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_environment										=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );

	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_database											=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );

	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );

	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cache_settings_controller	=	rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController( rb_database_cache_priority_settings_controller );
	VALUE	rb_parent_database_settings_controller				=	rb_Rbdb_DatabaseCacheSettingsController_parentDatabaseSettingsController( rb_parent_database_cache_settings_controller );

	return rb_parent_database_settings_controller;
}

/**********************************************
*  parent_database_cache_settings_controller  *
**********************************************/

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController(	VALUE	rb_database_cache_priority_settings_controller )	{

	VALUE	rb_parent_database_cache_settings_controller	=	rb_iv_get(	rb_database_cache_priority_settings_controller,
																																		RBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER );

	return rb_parent_database_cache_settings_controller;
}


/*************
*  priority  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_priority( VALUE	rb_database_cache_priority_settings_controller )	{
	
	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_priority( c_database_cache_priority_settings_controller ) );
}

/*************
*  very_low  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_veryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_veryLow( c_database_cache_priority_settings_controller ) );
}

	/*****************
	*  set_very_low  *
	*****************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
		
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		Rbdb_DatabaseCachePrioritySettingsController_setVeryLow( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/**********************
	*  at_least_very_low  *
	**********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( c_database_cache_priority_settings_controller ) );
	}

	/*********************
	*  at_most_very_low  *
	*********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( c_database_cache_priority_settings_controller ) );
	}

/********
*  low  *
********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_low( VALUE	rb_database_cache_priority_settings_controller )	{

	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_low( c_database_cache_priority_settings_controller ) );
}

	/************
	*  set_low  *
	************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setLow( VALUE	rb_database_cache_priority_settings_controller )	{

		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		Rbdb_DatabaseCachePrioritySettingsController_setLow( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/*****************
	*  at_least_low  *
	*****************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( VALUE	rb_database_cache_priority_settings_controller )	{

		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( c_database_cache_priority_settings_controller ) );
	}

	/****************
	*  at_most_low  *
	****************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostLow( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtMostLow( c_database_cache_priority_settings_controller ) );
	}

/************
*  default  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_default( VALUE	rb_database_cache_priority_settings_controller )	{

	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_default( c_database_cache_priority_settings_controller ) );
}

	/****************
	*  set_default  *
	****************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setDefault( VALUE	rb_database_cache_priority_settings_controller )	{

		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		Rbdb_DatabaseCachePrioritySettingsController_setDefault( c_database_cache_priority_settings_controller );

		return Qnil;
	}

	/*********************
	*  at_least_default  *
	*********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_database_cache_priority_settings_controller )	{
		
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( c_database_cache_priority_settings_controller ) );
	}

	/********************
	*  at_most_default  *
	********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( c_database_cache_priority_settings_controller ) );
	}

/*********
*  high  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_high( VALUE	rb_database_cache_priority_settings_controller )	{
	
	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_high( c_database_cache_priority_settings_controller ) );
}

	/*************
	*  set_high  *
	*************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setHigh( VALUE	rb_database_cache_priority_settings_controller )	{
		
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		Rbdb_DatabaseCachePrioritySettingsController_setHigh( c_database_cache_priority_settings_controller );

		return Qnil;
	}

	/******************
	*  at_least_high  *
	******************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( c_database_cache_priority_settings_controller ) );
	}

	/*****************
	*  at_most_high  *
	*****************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( c_database_cache_priority_settings_controller ) );
	}

/**************
*  very_high  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_veryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
	Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
	C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
	
	return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_veryHigh( c_database_cache_priority_settings_controller ) );
}

	/******************
	*  set_very_high  *
	******************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );

		Rbdb_DatabaseCachePrioritySettingsController_setVeryHigh( c_database_cache_priority_settings_controller );
		
		return Qnil;
	}

	/***********************
	*  at_least_very_high  *
	***********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( c_database_cache_priority_settings_controller ) );
	}

	/**********************
	*  at_most_very_high  *
	**********************/

	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_database_cache_priority_settings_controller )	{
	
		Rbdb_DatabaseCachePrioritySettingsController*	c_database_cache_priority_settings_controller;
		C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller );
		
		return INT2FIX( Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( c_database_cache_priority_settings_controller ) );
	}
