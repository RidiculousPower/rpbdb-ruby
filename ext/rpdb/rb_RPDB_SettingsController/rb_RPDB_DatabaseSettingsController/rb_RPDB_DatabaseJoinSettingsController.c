/*
 *		RPDB::SettingsController::JoinSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseJoinSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_DatabaseJoinSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;	
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseJoinSettingsController;

void Init_RPDB_DatabaseJoinSettingsController()	{

	rb_RPDB_DatabaseJoinSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																			"Join",	
																																			rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseJoinSettingsController, 	"new",																							rb_RPDB_DatabaseJoinSettingsController_new,											1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"initialize",																				rb_RPDB_DatabaseJoinSettingsController_init,											1 	);
                    					                                                                        														
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"parent_environment",																rb_RPDB_DatabaseJoinSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinSettingsController, 	"environment",																			"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"parent_database",																	rb_RPDB_DatabaseJoinSettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinSettingsController, 	"database",																					"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"degree_one_isolation?",														rb_RPDB_DatabaseJoinController_degreeOneIsolation,											0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_degree_one_isolation_on",											rb_RPDB_DatabaseJoinController_turnDegreeOneIsolationOn,								0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_degree_one_isolation_off",										rb_RPDB_DatabaseJoinController_turnDegreeOneIsolationOff,								0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"write_locks_instead_of_read_locks?",								rb_RPDB_DatabaseJoinController_writeLocksInsteadOfReadLocks,						0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_write_locks_instead_of_read_locks_on",				rb_RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_write_locks_instead_of_read_locks_off",				rb_RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff,			0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"no_sort_before_join?",															rb_RPDB_DatabaseJoinController_noSortBeforeJoin,												0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_no_sort_before_join_on",											rb_RPDB_DatabaseJoinController_turnNoSortBeforeJoinOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseJoinSettingsController, 	"turn_no_sort_before_join_off",											rb_RPDB_DatabaseJoinController_turnNoSortBeforeJoinOff,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseJoinSettingsController_new(	VALUE	rb_klass __attribute__ ((unused )),
																									VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_join_settings_controller	= RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( RPDB_DatabaseJoinSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_join_settings_controller,
						1, 
						argv );
	
	return rb_join_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseJoinSettingsController_init(	VALUE	rb_join_settings_controller,
																										VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{
	
	return rb_join_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseJoinSettingsController_parentEnvironment(	VALUE	rb_join_settings_controller )	{

	RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseJoinSettingsController_parentEnvironment( c_join_settings_controller ) );
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_RPDB_DatabaseJoinSettingsController_parentDatabase(	VALUE	rb_join_settings_controller )	{

	RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseJoinSettingsController_parentDatabase( c_join_settings_controller ) );
}

/*****************************
*  degreeOneIsolation  *
*****************************/

//	DB_READ_UNCOMMITTED				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPDB_DatabaseJoinController_degreeOneIsolation( VALUE	rb_join_settings_controller )	{

	RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPDB_DatabaseJoinController_degreeOneIsolation( c_join_settings_controller )	?	Qtrue
																					:	Qfalse );
}

	/********************************
	*  turnDegreeOneIsolationOn  *
	********************************/

	VALUE rb_RPDB_DatabaseJoinController_turnDegreeOneIsolationOn( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPDB_DatabaseJoinController_turnDegreeOneIsolationOn( c_join_settings_controller );
		
		return rb_join_settings_controller;
	}

	/********************************
	*  turnDegreeOneIsolationOff  *
	********************************/

	VALUE rb_RPDB_DatabaseJoinController_turnDegreeOneIsolationOff( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );
	
		RPDB_DatabaseJoinController_turnDegreeOneIsolationOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

/******************************************
*  writeLocksInsteadOfReadLocks  *
******************************************/

//	DB_RMW						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPDB_DatabaseJoinController_writeLocksInsteadOfReadLocks( VALUE	rb_join_settings_controller )	{

	RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPDB_DatabaseJoinController_writeLocksInsteadOfReadLocks( c_join_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/********************************************
	*  turnWriteLocksInsteadOfReadLocksOn  *
	********************************************/

	VALUE rb_RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( c_join_settings_controller );

		return rb_join_settings_controller;
	}

	/********************************************
	*  turnWriteLocksInsteadOfReadLocksOff  *
	********************************************/

	VALUE rb_RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPDB_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

/******************************************
*  writeLocksInsteadOfReadLocks  *
******************************************/

//	DB_JOIN_NOSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPDB_DatabaseJoinController_noSortBeforeJoin( VALUE	rb_join_settings_controller )	{

	RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPDB_DatabaseJoinController_noSortBeforeJoin( c_join_settings_controller )	?	Qtrue
																					:	Qfalse );
}

	/********************************************
	*  turnWriteLocksInsteadOfReadLocksOn  *
	********************************************/

	VALUE rb_RPDB_DatabaseJoinController_turnNoSortBeforeJoinOn( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPDB_DatabaseJoinController_turnNoSortBeforeJoinOn( c_join_settings_controller );

		return rb_join_settings_controller;
	}

	/********************************************
	*  turnWriteLocksInsteadOfReadLocksOff  *
	********************************************/

	VALUE rb_RPDB_DatabaseJoinController_turnNoSortBeforeJoinOff( VALUE	rb_join_settings_controller )	{

		RPDB_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPDB_DatabaseJoinController_turnNoSortBeforeJoinOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

