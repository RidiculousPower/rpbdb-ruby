/*
 *		RPbdb::RPbdb_DatabaseController::RPbdb_Database::(RPbdb_DatabaseCursorController::RPbdb_DatabaseCursor::)RPbdb_Record
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "Record.h"

#include "DatabaseController.h"
#include "Database.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>

#include <rpbdb/Record.h>
#include <rpbdb/Key.h>
#include <rpbdb/Data.h>
#include <rpbdb/SecondaryKeys.h>

#include <rpbdb/DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;	
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_RPbdb_Key;
extern	VALUE	rb_RPbdb_SecondaryKeys;
extern	VALUE	rb_RPbdb_Data;
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_RPbdb_Record()	{

	rb_RPbdb_Record		=	rb_define_class_under(	rb_RPbdb_Database, 
																							"Record", 		
																							rb_cObject );
	
	//	FIX - this class hasn't been considered thoroughly yet
	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Record_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database					=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]"
		)
	);

	RPbdb_Database*			c_parent_database;
	C_RPBDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_record	=	RUBY_RPBDB_RECORD( RPbdb_Record_new( c_parent_database ) );

	//	store reference to parent
	rb_iv_set(	rb_record,
							RPBDB_RB_RECORD_VARIABLE_PARENT_DATABASE,
							rb_parent_database );

	VALUE	argv[]	=	{ rb_parent_database };
	rb_obj_call_init(	rb_record,
					 1, 
					 argv );
	
	return rb_record;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Record_initialize(	int				argc __attribute__ ((unused)),
														VALUE*		args __attribute__ ((unused)),
														VALUE			rb_self )	{

	return rb_self;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_Record_settingsController(	VALUE	rb_record )	{

	VALUE	rb_local_record_settings_controller	=	Qnil;
	
	if ( ( rb_local_record_settings_controller = rb_iv_get(	rb_record,
																													RPBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Record*		c_record;
		C_RPBDB_RECORD( rb_record, c_record );
	
		RPbdb_DatabaseRecordSettingsController*	c_local_record_settings_controller	=	RPbdb_Record_settingsController( c_record );

		rb_local_record_settings_controller	=	RUBY_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_local_record_settings_controller );

		rb_iv_set(	rb_record,
								RPBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER,
								rb_local_record_settings_controller );
	}

	return rb_local_record_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_Record_parentEnvironment(	VALUE	rb_record )	{

	VALUE	rb_parent_database_controller		=	rb_RPbdb_Record_parentDatabase( rb_record );
	VALUE	rb_parent_environment						=	rb_RPbdb_Database_parentDatabaseController( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPbdb_Record_parentDatabaseController(	VALUE	rb_record )	{

	VALUE	rb_parent_database						=	rb_RPbdb_Record_parentDatabase( rb_record );
	VALUE	rb_parent_database_controller	=	rb_RPbdb_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPbdb_Record_parentDatabase(	VALUE	rb_record )	{

	VALUE	rb_parent_database	=	rb_iv_get(	rb_record,
																					RPBDB_RB_RECORD_VARIABLE_PARENT_DATABASE );
	
	return rb_parent_database;
}


/*******************************************************************************************************************************************************************************************
																		Record Management Public Methods
*******************************************************************************************************************************************************************************************/


/******************
*  primaryKey  *
******************/

VALUE rb_RPbdb_Record_primaryKey( VALUE	rb_record )	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	return RUBY_RPBDB_KEY( RPbdb_Record_primaryKey( c_record ) );
}

/**********************
*  secondaryKeys  *
**********************/

VALUE rb_RPbdb_Record_retrievalKey( VALUE	rb_record )	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	return RUBY_RPBDB_KEY( RPbdb_Record_retrievalKey( c_record ) );		
}

/*******************************************************************************************************************************************************************************************
																		Retrieval Status Public Methods
*******************************************************************************************************************************************************************************************/

/******************
*  setStatus  *
******************/

VALUE rb_RPbdb_Record_setExistsInDatabase(	VALUE	rb_record,
											VALUE	rb_data_status	)	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	RPbdb_Record_setExistsInDatabase(	c_record,
										( rb_data_status == Qtrue	?	TRUE 
																	:	FALSE ) );

	return rb_record;
}

/**************
*  status  *
**************/

VALUE rb_RPbdb_Record_existsInDatabase( VALUE	rb_record )	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	return ( RPbdb_Record_existsInDatabase( c_record )	?	Qtrue
														:	Qfalse );
}

/******************
*  setStatus  *
******************/

VALUE rb_RPbdb_Record_setRequiresUpdateToDatabase(	VALUE	rb_record,
													VALUE	rb_data_status	)	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	RPbdb_Record_setRequiresUpdateToDatabase(	c_record,
												( rb_data_status == Qtrue	?	TRUE 
																			:	FALSE ) );

	return rb_record;
}

/**************
*  status  *
**************/

VALUE rb_RPbdb_Record_requiresUpdateToDatabase( VALUE	rb_record )	{

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	return ( RPbdb_Record_requiresUpdateToDatabase( c_record )	?	Qtrue
																:	Qfalse );
}
