/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseCompactSettingsController
 *		RPDB::DatabaseController::Database::SettingsController::CompactSettingsController
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseCompactSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>

#include <rpdb/RPDB_DatabaseCompactSettingsController.h>
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
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseCompactSettingsController;

void Init_RPDB_DatabaseCompactSettingsController()	{

	rb_RPDB_DatabaseCompactSettingsController				=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Compact",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCompactSettingsController, 	"new",												rb_RPDB_DatabaseCompactSettingsController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"initialize",									rb_RPDB_DatabaseCompactSettingsController_init,											-1 	);
                    					                                                                      		
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"parent_environment",					rb_RPDB_DatabaseCompactSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseCompactSettingsController, 	"environment",								"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"parent_database",						rb_RPDB_DatabaseCompactSettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseCompactSettingsController, 	"database",										"parent_database"	);
                    					                                                                      		
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"fill_percent",								rb_RPDB_DatabaseCompactSettingsController_fillPercent,							0 	);
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"set_fill_percent",						rb_RPDB_DatabaseCompactSettingsController_setFillPercent,						1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"max_pages_to_compact",				rb_RPDB_DatabaseCompactSettingsController_maxPagesToCompact,				0 	);
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"max_pages_to_compact=",			rb_RPDB_DatabaseCompactSettingsController_setMaxPagesToCompact,			1 	);
	rb_define_alias(						rb_RPDB_DatabaseCompactSettingsController, 	"set_max_pages_to_compact",		"max_pages_to_compact="	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"timeout",										rb_RPDB_DatabaseCompactSettingsController_timeout,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCompactSettingsController, 	"timeout=",										rb_RPDB_DatabaseCompactSettingsController_setTimeout,								1 	);
	rb_define_alias(						rb_RPDB_DatabaseCompactSettingsController, 	"set_timeout",								"timeout=" 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseCompactSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ) ) ),
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

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		
	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller	=	RPDB_DatabaseSettingsController_compactSettingsController( c_database_settings_controller );

	VALUE	rb_database_compact_settings_controller	= RUBY_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_compact_settings_controller,
							RPDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_compact_settings_controller,
										 1, 
										 argv );
	
	return rb_database_compact_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseCompactSettingsController_init(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCompactSettingsController_parentEnvironment(	VALUE	rb_database_compact_settings_controller )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCompactSettingsController_parentEnvironment( c_database_compact_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCompactSettingsController_parentDatabase(	VALUE	rb_database_compact_settings_controller )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCompactSettingsController_parentDatabase( c_database_compact_settings_controller ) );

}

/*********************
*  fillPercent  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_RPDB_DatabaseCompactSettingsController_fillPercent( VALUE	rb_database_compact_settings_controller )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPDB_DatabaseCompactSettingsController_fillPercent( c_database_compact_settings_controller ) );
}

/*************************
*  setFillPercent  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the goal for filling pages, specified as a percentage between 1 and 100. 
//	Any page in a Btree or Recno databases not at or above this percentage full will be considered for compaction. 
//	The default behavior is to consider every page for compaction, regardless of its page fill percentage.
VALUE rb_RPDB_DatabaseCompactSettingsController_setFillPercent(	VALUE	rb_database_compact_settings_controller, 
																	VALUE	rb_fill_percent )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPDB_DatabaseCompactSettingsController_setFillPercent(	c_database_compact_settings_controller,
	 														FIX2INT( rb_fill_percent ) );

	return rb_database_compact_settings_controller;
}

/*************************
*  maxPagesToCompact  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_RPDB_DatabaseCompactSettingsController_maxPagesToCompact( VALUE	rb_database_compact_settings_controller )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPDB_DatabaseCompactSettingsController_maxPagesToCompact( c_database_compact_settings_controller ) );
}

/*****************************
*  setMaxPagesToCompact  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, the call will return after that number of pages have been freed.
VALUE rb_RPDB_DatabaseCompactSettingsController_setMaxPagesToCompact(	VALUE	rb_database_compact_settings_controller, 
																		VALUE	rb_max_pages_to_compact )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPDB_DatabaseCompactSettingsController_setMaxPagesToCompact(	c_database_compact_settings_controller,
	 																FIX2INT( rb_max_pages_to_compact ) );

	return rb_database_compact_settings_controller;
}

/****************
*  timeout  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_RPDB_DatabaseCompactSettingsController_timeout( VALUE	rb_database_compact_settings_controller )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	return INT2FIX( RPDB_DatabaseCompactSettingsController_timeout( c_database_compact_settings_controller ) );

}

/********************
*  setTimeout  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	If non-zero, and no txnid parameter was specified, the lock timeout set for implicit transactions, in microseconds.
VALUE rb_RPDB_DatabaseCompactSettingsController_setTimeout(	VALUE	rb_database_compact_settings_controller, 
																VALUE	rb_timeout )	{

	RPDB_DatabaseCompactSettingsController*	c_database_compact_settings_controller;
	C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller );

	RPDB_DatabaseCompactSettingsController_setTimeout(	c_database_compact_settings_controller,
	 													FIX2INT( rb_timeout ) );

	return rb_database_compact_settings_controller;
}
