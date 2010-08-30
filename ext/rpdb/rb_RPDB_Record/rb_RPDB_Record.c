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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Record.h>
#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_Data.h>
#include <rpdb/RPDB_SecondaryKeys.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

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
*  new  *
*************/

VALUE rb_RPDB_Record_new(	VALUE	klass __attribute__ ((unused )),
													VALUE	rb_parent_database )	{
	
	RPDB_Database*			c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	
	VALUE	rb_record	=	RUBY_RPDB_RECORD( RPDB_Record_new( c_parent_database ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database;
	
	rb_obj_call_init(	rb_record,
					 1, 
					 argv );
	
	return rb_record;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Record_init(	VALUE	rb_record,
														VALUE	rb_parent_database __attribute__ ((unused )) )	{

	return rb_record;
}


/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Record_settingsController(	VALUE	rb_record )	{

	RPDB_Record*	c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_Record_settingsController( c_record ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_Record_parentEnvironment(	VALUE	rb_record )	{

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Record_parentEnvironment( c_record ) );

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
