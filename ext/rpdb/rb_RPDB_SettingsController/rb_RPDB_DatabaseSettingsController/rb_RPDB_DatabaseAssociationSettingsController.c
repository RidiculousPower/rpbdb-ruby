/*
 *		RPDB::Database::DatabaseSettingsController::DatabaseAssociationSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseAssociationSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseAssociationSettingsController.h>

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
extern	VALUE	rb_RPDB_DatabaseAssociationSettingsController;

void Init_RPDB_DatabaseAssociationSettingsController()	{

	rb_RPDB_DatabaseAssociationSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Association",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseAssociationSettingsController, 	"new",																						rb_RPDB_DatabaseAssociationSettingsController_new,													-1 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController,	"initialize",																			rb_RPDB_DatabaseAssociationSettingsController_init,													-1 	);

	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"parent_environment",															rb_RPDB_DatabaseAssociationSettingsController_parentEnvironment,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseAssociationSettingsController, 	"environment",																		"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"parent_database",																rb_RPDB_DatabaseAssociationSettingsController_parentDatabase,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseAssociationSettingsController, 	"database",																				"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"secondary_association_creates_index?",						rb_RPDB_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex,					0 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"turn_secondary_association_creates_index_on",		rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"turn_secondary_association_creates_index_off",		rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff,				0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"immutable_secondary_key?",												rb_RPDB_DatabaseAssociationSettingsController_immutableSecondaryKey,								0 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"turn_immutable_secondary_key_on",								rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController, 	"turn_immutable_secondary_key_off",								rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff,						0 	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_DatabaseAssociationSettingsController_new(	int			argc,
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
	RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller	=	RPDB_DatabaseSettingsController_associationSettingsController( c_database_settings_controller );

	VALUE	rb_database_association_settings_controller	=	RUBY_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller );

	rb_iv_set(	rb_database_association_settings_controller,
							RPDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	rb_obj_call_initialize(	rb_database_association_settings_controller,
					 					1, 
					 					argv );
	
	return rb_database_association_settings_controller;		
}

/*********
*  initialize  *
*********/

VALUE rb_RPDB_DatabaseAssociationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{	
	return rb_self;
}

/**********************
*  parent_environment  *
**********************/

VALUE rb_RPDB_DatabaseAssociationSettingsController_parentEnvironment(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPDB_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_environment										=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/*******************
*  parent_database  *
*******************/

VALUE rb_RPDB_DatabaseAssociationSettingsController_parentDatabase(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPDB_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_database											=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************
*  parent_settings_controller  *
*******************/

VALUE rb_RPDB_DatabaseAssociationSettingsController_parentSettingsController(	VALUE	rb_database_association_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_RPDB_DatabaseAssociationSettingsController_parentDatabaseSettingsController(rb_database_association_settings_controller );
	VALUE	rb_parent_settings_controller						=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}


/*******************
*  parent_database_settings_controller  *
*******************/

VALUE rb_RPDB_DatabaseAssociationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_association_settings_controller )	{
	
	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_association_settings_controller,
																															RPDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER );
	
	return rb_parent_database_settings_controller;
}

/*****************
*  index_primary  *
*****************/

//	DB_CREATE	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_associate.html
//	If the secondary database is empty, walk through the primary and create an index to it in the empty secondary. This operation is potentially very expensive.
//	Care should be taken not to use a newly-populated secondary database in another thread of control until the DB->associate call has returned successfully in the first thread.
//	If transactions are not being used, care should be taken not to modify a primary database being used to populate a secondary database in another thread of control, 
//	until the DB->associate call has returned successfully in the first thread. 
//	If transactions are being used, Berkeley DB will perform appropriate locking and the application need not do any special operation ordering.
VALUE rb_RPDB_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( VALUE	rb_database_association_settings_controller )	{

	RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	RPDB_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( c_database_association_settings_controller );
	
	return rb_database_association_settings_controller;
}

	/*******************
	*  index_primary_on  *
	*******************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/********************
	*  index_primary_off  *
	********************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

/**************************
*  immutable_secondary_key  *
**************************/

//	DB_IMMUTABLE_KEY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_associate.html
//	This flag can be used to optimize updates when the secondary key in a primary record will never be changed after the primary record is inserted. 
//	For immutable secondary keys, a best effort is made to avoid calling the secondary callback function when primary records are updated. 
//	This optimization may reduce the overhead of update operations significantly if the callback function is expensive.
//	Be sure to specify this flag only if the secondary key in the primary record is never changed. 
//	If this rule is violated, the secondary index will become corrupted, that is, it will become out of sync with the primary.
VALUE rb_RPDB_DatabaseAssociationSettingsController_immutableSecondaryKey( VALUE	rb_database_association_settings_controller )	{

	RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	RPDB_DatabaseAssociationSettingsController_immutableSecondaryKey( c_database_association_settings_controller );

	return rb_database_association_settings_controller;
}

	/****************************
	*  immutable_secondary_key_on  *
	****************************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/*****************************
	*  immutable_secondary_key_off  *
	*****************************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}
