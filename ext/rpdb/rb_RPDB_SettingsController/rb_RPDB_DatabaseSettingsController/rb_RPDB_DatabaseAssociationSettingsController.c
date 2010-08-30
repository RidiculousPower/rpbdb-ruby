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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseAssociationSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;

extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseAssociationSettingsController;

void Init_RPDB_DatabaseAssociationSettingsController()	{

	rb_RPDB_DatabaseAssociationSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																						"Association",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseAssociationSettingsController, 	"new",																						rb_RPDB_DatabaseAssociationSettingsController_new,													1 	);
	rb_define_method(						rb_RPDB_DatabaseAssociationSettingsController,	"initialize",																			rb_RPDB_DatabaseAssociationSettingsController_init,													1 	);

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

VALUE rb_RPDB_DatabaseAssociationSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																													VALUE	rb_parent_database_settings_controller )	{
	
	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_association_settings_controller	=	RUBY_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( 
																												RPDB_DatabaseAssociationSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_association_settings_controller,
					 					1, 
					 					argv );
	
	return rb_database_association_settings_controller;		
}

/*********
*  init  *
*********/

VALUE rb_RPDB_DatabaseAssociationSettingsController_init(	VALUE	rb_database_association_settings_controller,
																													VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{	
	return rb_database_association_settings_controller;
}

/**********************
*  parentEnvironment  *
**********************/

VALUE rb_RPDB_DatabaseAssociationSettingsController_parentEnvironment(	VALUE	rb_database_association_settings_controller )	{

	RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseAssociationSettingsController_parentEnvironment( c_database_association_settings_controller ) );
}

/*******************
*  parentDatabase  *
*******************/
VALUE rb_RPDB_DatabaseAssociationSettingsController_parentDatabase(	VALUE	rb_database_association_settings_controller )	{

	RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
	C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseAssociationSettingsController_parentDatabase( c_database_association_settings_controller ) );
}

/*****************
*  indexPrimary  *
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
	*  indexPrimaryOn  *
	*******************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/********************
	*  indexPrimaryOff  *
	********************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

/**************************
*  immutableSecondaryKey  *
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
	*  immutableSecondaryKeyOn  *
	****************************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}

	/*****************************
	*  immutableSecondaryKeyOff  *
	*****************************/

	VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( VALUE	rb_database_association_settings_controller )	{

		RPDB_DatabaseAssociationSettingsController*	c_database_association_settings_controller;
		C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller );

		RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( c_database_association_settings_controller );

		return rb_database_association_settings_controller;
	}
