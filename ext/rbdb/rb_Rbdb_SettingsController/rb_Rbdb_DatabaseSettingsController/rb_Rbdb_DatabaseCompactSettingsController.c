/*
 *		Rbdb::SettingsController::DatabaseSettingsController::DatabaseCompactSettingsController
 *		Rbdb::DatabaseController::Database::SettingsController::CompactSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseCompactSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseSettingsController.h>

#include <rbdb/Rbdb_DatabaseCompactSettingsController.h>
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
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCompactSettingsController;

void Init_Rbdb_DatabaseCompactSettingsController()	{

	rb_Rbdb_DatabaseCompactSettingsController				=	rb_define_class_under(	rb_Rbdb_DatabaseSettingsController, 
																																						"Compact",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseCompactSettingsController, 	"new",												rb_Rbdb_DatabaseCompactSettingsController_new,											-1 	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"initialize",									rb_Rbdb_DatabaseCompactSettingsController_initialize,											-1 	);
                    					                                                                      		
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"parent_environment",					rb_Rbdb_DatabaseCompactSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCompactSettingsController, 	"environment",								"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"parent_database",						rb_Rbdb_DatabaseCompactSettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseCompactSettingsController, 	"database",										"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"parent_settings_controller",						rb_Rbdb_DatabaseCompactSettingsController_parentSettingsController,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"parent_database_settings_controller",						rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController,						0 	);
                    					                                                                      		
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"fill_percent",								rb_Rbdb_DatabaseCompactSettingsController_fillPercent,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"set_fill_percent",						rb_Rbdb_DatabaseCompactSettingsController_setFillPercent,						1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"max_pages_to_compact",				rb_Rbdb_DatabaseCompactSettingsController_maxPagesToCompact,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"max_pages_to_compact=",			rb_Rbdb_DatabaseCompactSettingsController_setMaxPagesToCompact,			1 	);
	rb_define_alias(						rb_Rbdb_DatabaseCompactSettingsController, 	"set_max_pages_to_compact",		"max_pages_to_compact="	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"timeout",										rb_Rbdb_DatabaseCompactSettingsController_timeout,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseCompactSettingsController, 	"timeout=",										rb_Rbdb_DatabaseCompactSettingsController_setTimeout,								1 	);
	rb_define_alias(						rb_Rbdb_DatabaseCompactSettingsController, 	"set_timeout",								"timeout=" 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseCompactSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ) ) ),
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

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller	=	Rbdb_DatabaseSettingsController_compactSettingsController( c_database_settings_controller );

	VALUE	rb_database_compact_settings_controller	= RUBY_RBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_compact_settings_controller,
							Rbdb_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseCompactSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseCompactSettingsController_parentEnvironment(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_environment										=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );

	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseCompactSettingsController_parentDatabase(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_database											=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );

	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseCompactSettingsController_parentSettingsController(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController( rb_database_compact_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );

	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_compact_settings_controller )	{

	VALUE	rb_parent_database_compact_settings_controller	=	rb_iv_get(	rb_database_compact_settings_controller,
																																			Rbdb_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_compact_settings_controller;
}

/*****************
*  fill_percent  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_Rbdb_DatabaseCompactSettingsController_fillPercent( VALUE	rb_database_compact_settings_controller )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( Rbdb_DatabaseCompactSettingsController_fillPercent( c_database_compact_settings_controller ) );
}

/*********************
*  set_fill_percent  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_Rbdb_DatabaseCompactSettingsController_setFillPercent(	VALUE	rb_database_compact_settings_controller, 
																	VALUE	rb_fill_percent )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	Rbdb_DatabaseCompactSettingsController_setFillPercent(	c_database_compact_settings_controller,
	 														FIX2INT( rb_fill_percent ) );

	return rb_database_compact_settings_controller;
}

/*************************
*  max_pages_to_compact  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_Rbdb_DatabaseCompactSettingsController_maxPagesToCompact( VALUE	rb_database_compact_settings_controller )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( Rbdb_DatabaseCompactSettingsController_maxPagesToCompact( c_database_compact_settings_controller ) );
}

/*****************************
*  set_max_pages_to_compact  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_Rbdb_DatabaseCompactSettingsController_setMaxPagesToCompact(	VALUE	rb_database_compact_settings_controller, 
																		VALUE	rb_max_pages_to_compact )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	Rbdb_DatabaseCompactSettingsController_setMaxPagesToCompact(	c_database_compact_settings_controller,
	 																FIX2INT( rb_max_pages_to_compact ) );

	return rb_database_compact_settings_controller;
}

/************
*  timeout  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_Rbdb_DatabaseCompactSettingsController_timeout( VALUE	rb_database_compact_settings_controller )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( Rbdb_DatabaseCompactSettingsController_timeout( c_database_compact_settings_controller ) );

}

/****************
*  set_timeout  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_Rbdb_DatabaseCompactSettingsController_setTimeout(	VALUE	rb_database_compact_settings_controller, 
																VALUE	rb_timeout )	{

	Rbdb_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_Rbdb_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	Rbdb_DatabaseCompactSettingsController_setTimeout(	c_database_compact_settings_controller,
	 													FIX2INT( rb_timeout ) );

	return rb_database_compact_settings_controller;
}
