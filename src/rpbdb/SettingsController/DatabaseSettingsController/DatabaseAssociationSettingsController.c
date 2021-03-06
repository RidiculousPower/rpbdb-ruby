/*
 *		RPbdb::Database::DatabaseSettingsController::DatabaseAssociationSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseAssociationSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>

#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseAssociationSettingsController.h>

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
extern	VALUE	rb_RPbdb_DatabaseAssociationSettingsController;

void Init_rb_RPbdb_DatabaseAssociationSettingsController()	{

	rb_RPbdb_DatabaseAssociationSettingsController		=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																						"Association",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseAssociationSettingsController, 	"new",																						rb_RPbdb_DatabaseAssociationSettingsController_new,													-1 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController,	"initialize",																			rb_RPbdb_DatabaseAssociationSettingsController_initialize,													-1 	);

	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"parent_environment",															rb_RPbdb_DatabaseAssociationSettingsController_parentEnvironment,									0 	);
	rb_define_alias(						rb_RPbdb_DatabaseAssociationSettingsController, 	"environment",																		"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"parent_database",																rb_RPbdb_DatabaseAssociationSettingsController_parentDatabase,										0 	);
	rb_define_alias(						rb_RPbdb_DatabaseAssociationSettingsController, 	"database",																				"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"parent_settings_controller",											rb_RPbdb_DatabaseAssociationSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"parent_database_settings_controller",						rb_RPbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController,										0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"secondary_association_creates_index?",						rb_RPbdb_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"turn_secondary_association_creates_index_on",		rb_RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn,				0 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"turn_secondary_association_creates_index_off",		rb_RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff,				0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"immutable_secondary_key?",												rb_RPbdb_DatabaseAssociationSettingsController_immutableSecondaryKey,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"turn_immutable_secondary_key_on",								rb_RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn,							0 	);
	rb_define_method(						rb_RPbdb_DatabaseAssociationSettingsController, 	"turn_immutable_secondary_key_off",								rb_RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff,						0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment,										rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller,						rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database,											rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller,						rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller,	rb_RPbdb_DatabaseSettingsController ) ) ),
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
	RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller	=	RPbdb_DatabaseSettingsController_associationSettingsController( c_database_settings_controller );

	VALUE	rb_database_association_settings_controller	=	RUBY_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller );

	rb_iv_set(	rb_database_association_settings_controller,
							RPBDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_database_association_settings_controller,
					 					1, 
					 					argv );
	
	return rb_database_association_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_parentEnvironment(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_environment										=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_parentDatabase(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_database											=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_parentSettingsController(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}


/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_association_settings_controller )	{
	
	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_association_settings_controller,
																															RPBDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER );
	
	return rb_parent_database_settings_controller;
}

/*****************************************
*  secondary_association_creates_index?  *
*****************************************/

//	DB_CREATE	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_associate.html
//	If the secondary database is empty, walk through the primary and create an index to it in the empty secondary. This operation is potentially very expensive.
//	Care should be taken not to use a newly-populated secondary database in another thread of control until the DB->associate call has returned successfully in the first thread.
//	If transactions are not being used, care should be taken not to modify a primary database being used to populate a secondary database in another thread of control, 
//	until the DB->associate call has returned successfully in the first thread. 
//	If transactions are being used, Berkeley DB will perform appropriate locking and the application need not do any special operation ordering.
VALUE rb_RPbdb_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( VALUE	rb_database_association_settings_controller )	{

	RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	BOOL	c_secondary_creates_index		= RPbdb_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( c_database_association_settings_controller );
	
	VALUE	rb_secondary_creates_index	=	( c_secondary_creates_index ? Qtrue : Qfalse );
	
	return rb_secondary_creates_index;
}

	/************************************************
	*  turn_secondary_association_creates_index_on  *
	************************************************/

	VALUE rb_RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( VALUE	rb_database_association_settings_controller )	{

		RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/*************************************************
	*  turn_secondary_association_creates_index_off  *
	*************************************************/

	VALUE rb_RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( VALUE	rb_database_association_settings_controller )	{

		RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

/*****************************
*  immutable_secondary_key?  *
*****************************/

//	DB_IMMUTABLE_KEY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_associate.html
//	This flag can be used to optimize updates when the secondary key in a primary record will never be changed after the primary record is inserted. 
//	For immutable secondary keys, a best effort is made to avoid calling the secondary callback function when primary records are updated. 
//	This optimization may reduce the overhead of update operations significantly if the callback function is expensive.
//	Be sure to specify this flag only if the secondary key in the primary record is never changed. 
//	If this rule is violated, the secondary index will become corrupted, that is, it will become out of sync with the primary.
VALUE rb_RPbdb_DatabaseAssociationSettingsController_immutableSecondaryKey( VALUE	rb_database_association_settings_controller )	{

	RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	BOOL	c_immutable_secondary_key		=	RPbdb_DatabaseAssociationSettingsController_immutableSecondaryKey( c_database_association_settings_controller );

	VALUE	rb_immutable_secondary_key	=	( c_immutable_secondary_key ? Qtrue : Qfalse );
	
	return rb_immutable_secondary_key;
}

	/************************************
	*  turn_immutable_secondary_key_on  *
	************************************/

	VALUE rb_RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( VALUE	rb_database_association_settings_controller )	{

		RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/*************************************
	*  turn_immutable_secondary_key_off  *
	*************************************/

	VALUE rb_RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( VALUE	rb_database_association_settings_controller )	{

		RPbdb_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}
