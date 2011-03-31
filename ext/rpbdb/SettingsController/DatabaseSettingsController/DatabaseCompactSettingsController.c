/*
 *		RPbdb::SettingsController::DatabaseSettingsController::DatabaseCompactSettingsController
 *		RPbdb::DatabaseController::Database::SettingsController::CompactSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseCompactSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>

#include <rpbdb/DatabaseSettingsController.h>

#include <rpbdb/DatabaseCompactSettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseController.h>
#include <rpbdb/Database.h>

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
extern	VALUE	rb_RPbdb_DatabaseCompactSettingsController;

void Init_rb_RPbdb_DatabaseCompactSettingsController()	{

	rb_RPbdb_DatabaseCompactSettingsController				=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																						"Compact",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseCompactSettingsController, 	"new",												rb_RPbdb_DatabaseCompactSettingsController_new,											-1 	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"initialize",									rb_RPbdb_DatabaseCompactSettingsController_initialize,											-1 	);
                    					                                                                      		
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"parent_environment",					rb_RPbdb_DatabaseCompactSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCompactSettingsController, 	"environment",								"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"parent_database",						rb_RPbdb_DatabaseCompactSettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_RPbdb_DatabaseCompactSettingsController, 	"database",										"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"parent_settings_controller",						rb_RPbdb_DatabaseCompactSettingsController_parentSettingsController,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"parent_database_settings_controller",						rb_RPbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController,						0 	);
                    					                                                                      		
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"fill_percent",								rb_RPbdb_DatabaseCompactSettingsController_fillPercent,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"set_fill_percent",						rb_RPbdb_DatabaseCompactSettingsController_setFillPercent,						1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"max_pages_to_compact",				rb_RPbdb_DatabaseCompactSettingsController_maxPagesToCompact,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"max_pages_to_compact=",			rb_RPbdb_DatabaseCompactSettingsController_setMaxPagesToCompact,			1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCompactSettingsController, 	"set_max_pages_to_compact",		"max_pages_to_compact="	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"timeout",										rb_RPbdb_DatabaseCompactSettingsController_timeout,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseCompactSettingsController, 	"timeout=",										rb_RPbdb_DatabaseCompactSettingsController_setTimeout,								1 	);
	rb_define_alias(						rb_RPbdb_DatabaseCompactSettingsController, 	"set_timeout",								"timeout=" 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
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

	RPbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller	=	RPbdb_DatabaseSettingsController_compactSettingsController( c_database_settings_controller );

	VALUE	rb_database_compact_settings_controller	= RUBY_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_compact_settings_controller,
							RPBDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_compact_settings_controller,
										 1, 
										 argv );
	
	return rb_database_compact_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_parentEnvironment(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_environment										=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );

	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_parentDatabase(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_database											=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );

	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_parentSettingsController(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );

	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_compact_settings_controller	=	rb_iv_get(	rb_database_compact_settings_controller,
																																			RPBDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_compact_settings_controller;
}

/*****************
*  fill_percent  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_RPbdb_DatabaseCompactSettingsController_fillPercent( VALUE	rb_database_compact_settings_controller )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPbdb_DatabaseCompactSettingsController_fillPercent( c_database_compact_settings_controller ) );
}

/*********************
*  set_fill_percent  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_RPbdb_DatabaseCompactSettingsController_setFillPercent(	VALUE	rb_database_compact_settings_controller, 
																	VALUE	rb_fill_percent )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPbdb_DatabaseCompactSettingsController_setFillPercent(	c_database_compact_settings_controller,
	 														FIX2INT( rb_fill_percent ) );

	return rb_database_compact_settings_controller;
}

/*************************
*  max_pages_to_compact  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_RPbdb_DatabaseCompactSettingsController_maxPagesToCompact( VALUE	rb_database_compact_settings_controller )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPbdb_DatabaseCompactSettingsController_maxPagesToCompact( c_database_compact_settings_controller ) );
}

/*****************************
*  set_max_pages_to_compact  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_RPbdb_DatabaseCompactSettingsController_setMaxPagesToCompact(	VALUE	rb_database_compact_settings_controller, 
																		VALUE	rb_max_pages_to_compact )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPbdb_DatabaseCompactSettingsController_setMaxPagesToCompact(	c_database_compact_settings_controller,
	 																FIX2INT( rb_max_pages_to_compact ) );

	return rb_database_compact_settings_controller;
}

/************
*  timeout  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_RPbdb_DatabaseCompactSettingsController_timeout( VALUE	rb_database_compact_settings_controller )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPbdb_DatabaseCompactSettingsController_timeout( c_database_compact_settings_controller ) );

}

/****************
*  set_timeout  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_RPbdb_DatabaseCompactSettingsController_setTimeout(	VALUE	rb_database_compact_settings_controller, 
																VALUE	rb_timeout )	{

	RPbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPbdb_DatabaseCompactSettingsController_setTimeout(	c_database_compact_settings_controller,
	 													FIX2INT( rb_timeout ) );

	return rb_database_compact_settings_controller;
}
