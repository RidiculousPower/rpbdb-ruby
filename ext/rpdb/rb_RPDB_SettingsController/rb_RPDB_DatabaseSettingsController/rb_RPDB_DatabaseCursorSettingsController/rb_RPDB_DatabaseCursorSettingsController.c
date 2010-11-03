/*
 *		RPDB::DatabaseController::Database::CursorController::Cursor::CursorSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseCursorSettingsController.h"

#include "rb_RPDB.h"

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorCacheSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>

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
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorReadWriteSettingsController;
extern	VALUE	rb_RPDB_SettingsController;

void Init_RPDB_DatabaseCursorSettingsController()	{

	rb_RPDB_DatabaseCursorSettingsController				=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Cursor",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCursorSettingsController, 	"new",																		rb_RPDB_DatabaseCursorSettingsController_new,																	-1 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"initialize",															rb_RPDB_DatabaseCursorSettingsController_init,																-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"parent_environment",											rb_RPDB_DatabaseCursorSettingsController_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"environment",														"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"parent_database",												rb_RPDB_DatabaseCursorSettingsController_parentDatabase,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"database",																"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"duplicate_retains_location?",						rb_RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation,						0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_on",			rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"turn_duplicate_retains_location_off",		rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"cache_settings_controller",							rb_RPDB_DatabaseCursorSettingsController_cacheSettingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"cache",																	"cache_settings_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCursorSettingsController, 	"record_read_write_settings_controller",					rb_RPDB_DatabaseCursorSettingsController_readWriteSettingsController,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseCursorSettingsController, 	"read_write",															"record_read_write_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorSettingsController_new(	int			argc,
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

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller	=	RPDB_DatabaseSettingsController_cursorSettingsController( c_database_settings_controller );

	VALUE	rb_database_cursor_settings_controller	=	RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_cursor_settings_controller,
										 1, 
										 argv );
	
	return rb_database_cursor_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseCursorSettingsController_init(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCursorSettingsController_parentEnvironment(	VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCursorSettingsController_parentEnvironment( c_database_cursor_settings_controller ) );
	
}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCursorSettingsController_parentDatabase(	VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCursorSettingsController_parentDatabase( c_database_cursor_settings_controller ) );
}

/**********************************
*  duplicateRetainsLocation  *
**********************************/

//	DB_POSITION		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_dup.html
VALUE rb_RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return ( RPDB_DatabaseCursorSettingsController_duplicateRetainsLocation( c_database_cursor_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/**************************************
	*  duplicateRetainsLocationOn  *
	**************************************/

	VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( VALUE	rb_database_cursor_settings_controller )	{

		RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );
	
		RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOn( c_database_cursor_settings_controller );
	
		return rb_database_cursor_settings_controller;
	}

	/**************************************
	*  duplicateRetainsLocationOff  *
	**************************************/

	VALUE rb_RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( VALUE	rb_database_cursor_settings_controller )	{

		RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
		C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

		RPDB_DatabaseCursorSettingsController_turnDuplicateRetainsLocationOff( c_database_cursor_settings_controller );

		return rb_database_cursor_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/****************************
*  cacheController  *
****************************/

VALUE rb_RPDB_DatabaseCursorSettingsController_cacheSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorSettingsController_cacheSettingsController( c_database_cursor_settings_controller ) );
}

/******************************
*  readWriteController  *
******************************/

VALUE rb_RPDB_DatabaseCursorSettingsController_readWriteSettingsController( VALUE	rb_database_cursor_settings_controller )	{

	RPDB_DatabaseCursorSettingsController*	c_database_cursor_settings_controller;
	C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseCursorSettingsController_readWriteSettingsController( c_database_cursor_settings_controller ) );
}
