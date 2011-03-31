/*
 *		RPbdb::SettingsController::JoinSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "RPbdb.h"
#include "DatabaseSettingsController.h"
#include "Database.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "DatabaseJoinSettingsController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/DatabaseJoinSettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>

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
extern	VALUE	rb_RPbdb_DatabaseJoinSettingsController;

void Init_rb_RPbdb_DatabaseJoinSettingsController()	{

	rb_RPbdb_DatabaseJoinSettingsController		=	rb_define_class_under(	rb_RPbdb_DatabaseSettingsController, 
																																			"Join",	
																																			rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseJoinSettingsController, 	"new",																							rb_RPbdb_DatabaseJoinSettingsController_new,											-1 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"initialize",																				rb_RPbdb_DatabaseJoinSettingsController_initialize,											-1 	);
                    					                                                                        														
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"parent_environment",																rb_RPbdb_DatabaseJoinSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPbdb_DatabaseJoinSettingsController, 	"environment",																			"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"parent_database",																	rb_RPbdb_DatabaseJoinSettingsController_parentDatabase,						0 	);
	rb_define_alias(						rb_RPbdb_DatabaseJoinSettingsController, 	"database",																					"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"parent_settings_controller",												rb_RPbdb_DatabaseJoinSettingsController_parentSettingsController,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"parent_database_settings_controller",							rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController,						0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"degree_one_isolation?",														rb_RPbdb_DatabaseJoinController_degreeOneIsolation,											0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_degree_one_isolation_on",											rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOn,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_degree_one_isolation_off",										rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOff,								0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"write_locks_instead_of_read_locks?",								rb_RPbdb_DatabaseJoinController_writeLocksInsteadOfReadLocks,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_write_locks_instead_of_read_locks_on",				rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_write_locks_instead_of_read_locks_off",				rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff,			0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"no_sort_before_join?",															rb_RPbdb_DatabaseJoinController_noSortBeforeJoin,												0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_no_sort_before_join_on",											rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOn,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseJoinSettingsController, 	"turn_no_sort_before_join_off",											rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOff,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPbdb_DatabaseJoinSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self __attribute__ ((unused)) __attribute__ ((unused )) )	{
	
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

	RPbdb_DatabaseJoinSettingsController*	c_database_join_settings_controller	=	RPbdb_DatabaseSettingsController_joinSettingsController( c_database_settings_controller );

	VALUE	rb_join_settings_controller	= RUBY_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_join_settings_controller,
							RPBDB_RB_DATABASE_JOIN_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
							rb_parent_database_settings_controller );

	VALUE	argv[]	=		{ rb_parent_database_settings_controller };
	rb_obj_call_init(	rb_join_settings_controller,
										1, 
										argv );
	
	return rb_join_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseJoinSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseJoinSettingsController_parentEnvironment(	VALUE	rb_join_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController( rb_join_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseJoinSettingsController_parentDatabase(	VALUE	rb_join_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController( rb_join_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseJoinSettingsController_parentSettingsController(	VALUE	rb_join_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController( rb_join_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController(	VALUE	rb_join_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_join_settings_controller,
																															RPBDB_RB_DATABASE_JOIN_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/**************************
*  degree_one_isolation?  *
**************************/

//	DB_READ_UNCOMMITTED				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPbdb_DatabaseJoinController_degreeOneIsolation( VALUE	rb_join_settings_controller )	{

	RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPbdb_DatabaseJoinController_degreeOneIsolation( c_join_settings_controller )	?	Qtrue
																																												:	Qfalse );
}

	/*********************************
	*  turn_degree_one_isolation_on  *
	*********************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOn( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPbdb_DatabaseJoinController_turnDegreeOneIsolationOn( c_join_settings_controller );
		
		return rb_join_settings_controller;
	}

	/**********************************
	*  turn_degree_one_isolation_off  *
	**********************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOff( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );
	
		RPbdb_DatabaseJoinController_turnDegreeOneIsolationOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

/***************************************
*  write_locks_instead_of_read_locks?  *
***************************************/

//	DB_RMW						http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPbdb_DatabaseJoinController_writeLocksInsteadOfReadLocks( VALUE	rb_join_settings_controller )	{

	RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPbdb_DatabaseJoinController_writeLocksInsteadOfReadLocks( c_join_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/**********************************************
	*  turn_write_locks_instead_of_read_locks_on  *
	**********************************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( c_join_settings_controller );

		return rb_join_settings_controller;
	}

	/***********************************************
	*  turn_write_locks_instead_of_read_locks_off  *
	***********************************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

/*************************
*  no_sort_before_join?  *
*************************/

//	DB_JOIN_NOSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
VALUE rb_RPbdb_DatabaseJoinController_noSortBeforeJoin( VALUE	rb_join_settings_controller )	{

	RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
	C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

	return ( RPbdb_DatabaseJoinController_noSortBeforeJoin( c_join_settings_controller )	?	Qtrue
																					:	Qfalse );
}

	/********************************
	*  turn_no_sort_before_join_on  *
	********************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOn( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOn( c_join_settings_controller );

		return rb_join_settings_controller;
	}

	/*********************************
	*  turn_no_sort_before_join_off  *
	*********************************/

	VALUE rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOff( VALUE	rb_join_settings_controller )	{

		RPbdb_DatabaseJoinSettingsController*	c_join_settings_controller;
		C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_join_settings_controller, c_join_settings_controller );

		RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOff( c_join_settings_controller );

		return rb_join_settings_controller;
	}

