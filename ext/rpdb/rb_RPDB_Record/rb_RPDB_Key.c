/*
 *		RPDB::RPDB_DatabaseController::RPDB_Database::(RPDB_DatabaseCursorController::RPDB_DatabaseCursor::)RPDB_Record::RPDB_DBT => RPDB_Key
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Key.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Key.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_Key;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Key()	{

	rb_RPDB_Key		=	rb_define_class_under(	rb_RPDB_Record, 
																					"Key", 		
																					rb_cObject );

	//	FIX - this class hasn't been considered thoroughly yet

}

/*************
*  new  *
*************/

VALUE rb_RPDB_Key_new(	VALUE	klass __attribute__ ((unused )),
												VALUE	rb_parent_record )	{
	
	RPDB_Record*			c_parent_record;
	C_RPDB_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_key	=	RUBY_RPDB_KEY( RPDB_Key_new( c_parent_record ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_record;
	
	rb_obj_call_init(	rb_key,
					 1, 
					 argv );
	
	return rb_key;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Key_init(	VALUE	rb_key,
												VALUE	rb_parent_record __attribute__ ((unused )) )	{

	return rb_key;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Key_settingsController(	VALUE	rb_key )	{

	RPDB_Key*	c_key;
	C_RPDB_KEY( rb_key, c_key );

	return RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_Key_settingsController( c_key ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_Key_parentEnvironment(	VALUE	rb_key )	{

	RPDB_Key*		c_key;
	C_RPDB_KEY( rb_key, c_key );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Key_parentEnvironment( c_key ) );

}

//	Functions need to be added here
