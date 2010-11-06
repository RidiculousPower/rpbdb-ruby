/*
 *		RPDB::RPDB_DatabaseController::RPDB_Database::(RPDB_DatabaseCursorController::RPDB_DatabaseCursor::)RPDB_Record
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Record.h"

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Record.h>
#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_Data.h>
#include <rpdb/RPDB_SecondaryKeys.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;	
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_Key;
extern	VALUE	rb_RPDB_SecondaryKeys;
extern	VALUE	rb_RPDB_Data;
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Record()	{

	rb_RPDB_Record		=	rb_define_class_under(	rb_RPDB_Database, 
																							"Record", 		
																							rb_cObject );
	
	//	FIX - this class hasn't been considered thoroughly yet
	
}

/*************
*  self.new  *
*************/

VALUE rb_RPDB_Record_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database					=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]"
		)
	);

	RPDB_Database*			c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_record	=	RUBY_RPDB_RECORD( RPDB_Record_new( c_parent_database ) );

	//	store reference to parent
	rb_iv_set(	rb_record,
							RPDB_RB_RECORD_VARIABLE_PARENT_DATABASE,
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

VALUE rb_RPDB_Record_initialize(	int				argc __attribute__ ((unused)),
														VALUE*		args __attribute__ ((unused)),
														VALUE			rb_self )	{

	return rb_self;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Record_settingsController(	VALUE	rb_record )	{

	VALUE	rb_local_record_settings_controller	=	Qnil;
	
	if ( ( rb_local_record_settings_controller = rb_iv_get(	rb_record,
																													RPDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Record*		c_record;
		C_RPDB_RECORD( rb_record, c_record );
	
		RPDB_DatabaseRecordSettingsController*	c_local_record_settings_controller	=	RPDB_Record_settingsController( c_record );

		rb_local_record_settings_controller	=	RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_local_record_settings_controller );

		rb_iv_set(	rb_record,
								RPDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER,
								rb_local_record_settings_controller );
	}

	return rb_local_record_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_Record_parentEnvironment(	VALUE	rb_record )	{

	VALUE	rb_parent_database_controller		=	rb_RPDB_Record_parentDatabase( rb_record );
	VALUE	rb_parent_environment						=	rb_RPDB_Database_parentDatabaseController( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPDB_Record_parentDatabaseController(	VALUE	rb_record )	{

	VALUE	rb_parent_database						=	rb_RPDB_Record_parentDatabase( rb_record );
	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_Record_parentDatabase(	VALUE	rb_record )	{

	VALUE	rb_parent_database	=	rb_iv_get(	rb_record,
																					RPDB_RB_RECORD_VARIABLE_PARENT_DATABASE );
	
	return rb_parent_database;
}


/*******************************************************************************************************************************************************************************************
																		Record Management Public Methods
*******************************************************************************************************************************************************************************************/


/******************
*  primaryKey  *
******************/

VALUE rb_RPDB_Record_primaryKey( VALUE	rb_record )	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return RUBY_RPDB_KEY( RPDB_Record_primaryKey( c_record ) );
}

/**********************
*  secondaryKeys  *
**********************/

VALUE rb_RPDB_Record_retrievalKey( VALUE	rb_record )	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return RUBY_RPDB_KEY( RPDB_Record_retrievalKey( c_record ) );		
}

/*******************************************************************************************************************************************************************************************
																		Retrieval Status Public Methods
*******************************************************************************************************************************************************************************************/

/******************
*  setStatus  *
******************/

VALUE rb_RPDB_Record_setExistsInDatabase(	VALUE	rb_record,
											VALUE	rb_data_status	)	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	RPDB_Record_setExistsInDatabase(	c_record,
										( rb_data_status == Qtrue	?	TRUE 
																	:	FALSE ) );

	return rb_record;
}

/**************
*  status  *
**************/

VALUE rb_RPDB_Record_existsInDatabase( VALUE	rb_record )	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return ( RPDB_Record_existsInDatabase( c_record )	?	Qtrue
														:	Qfalse );
}

/******************
*  setStatus  *
******************/

VALUE rb_RPDB_Record_setRequiresUpdateToDatabase(	VALUE	rb_record,
													VALUE	rb_data_status	)	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	RPDB_Record_setRequiresUpdateToDatabase(	c_record,
												( rb_data_status == Qtrue	?	TRUE 
																			:	FALSE ) );

	return rb_record;
}

/**************
*  status  *
**************/

VALUE rb_RPDB_Record_requiresUpdateToDatabase( VALUE	rb_record )	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return ( RPDB_Record_requiresUpdateToDatabase( c_record )	?	Qtrue
																:	Qfalse );
}
