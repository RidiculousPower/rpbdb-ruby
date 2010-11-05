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

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_Record.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Key.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

#include <rargs.h>

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

VALUE rb_RPDB_Key_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_database					=	Qnil;
	VALUE	rb_parent_record						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPDB_Record ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]",
			"[ <parent record> ]"
		)
	);
	
	RPDB_Record*			c_parent_record;
	C_RPDB_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_key	=	RUBY_RPDB_KEY( RPDB_Key_new( c_parent_record ) );

	//	store reference to parent
	rb_iv_set(	rb_key,
							RPDB_RB_KEY_VARIABLE_PARENT_RECORD,
							rb_parent_record );

	VALUE	argv[]	=	{ rb_parent_record };
	rb_obj_call_init(	rb_key,
					 1, 
					 argv );
	
	return rb_key;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Key_init(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self )	{

	return rb_self;
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
*  parent_environment  *
***************************************/

VALUE rb_RPDB_Key_parentEnvironment(	VALUE	rb_key )	{

	VALUE	rb_parent_database_controller	=	rb_RPDB_Key_parentDatabaseController( rb_key );
	VALUE	rb_parent_environment					=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPDB_Key_parentDatabaseController(	VALUE	rb_key )	{
	
	VALUE	rb_parent_database						=	rb_RPDB_Key_parentDatabase( rb_key );
	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_Key_parentDatabase(	VALUE	rb_key )	{
	
	VALUE	rb_parent_record		=	rb_RPDB_Key_parentRecord( rb_key );
	VALUE	rb_parent_database	=	rb_RPDB_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_RPDB_Key_parentRecord(	VALUE	rb_key )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_key,
																				RPDB_RB_DATA_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}

//	Functions need to be added here
