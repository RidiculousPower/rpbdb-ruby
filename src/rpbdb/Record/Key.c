/*
 *		RPbdb::RPbdb_DatabaseController::RPbdb_Database::(RPbdb_DatabaseCursorController::RPbdb_DatabaseCursor::)RPbdb_Record::RPBDB_DBT => RPbdb_Key
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "Key.h"

#include "DatabaseController.h"
#include "Database.h"
#include "Record.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>

#include <rpbdb/Key.h>

#include <rpbdb/DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_Key;
extern	VALUE	rb_RPbdb_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_RPbdb_Key()	{

	rb_RPbdb_Key		=	rb_define_class_under(	rb_RPbdb_Record, 
																					"Key", 		
																					rb_cObject );

	//	FIX - this class hasn't been considered thoroughly yet

}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Key_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_database					=	Qnil;
	VALUE	rb_parent_record						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPbdb_Record ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]",
			"[ <parent record> ]"
		)
	);
	
	RPbdb_Record*			c_parent_record;
	C_RPBDB_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_key	=	RUBY_RPBDB_KEY( RPbdb_Key_new( c_parent_record ) );

	//	store reference to parent
	rb_iv_set(	rb_key,
							RPBDB_RB_KEY_VARIABLE_PARENT_RECORD,
							rb_parent_record );

	VALUE	argv[]	=	{ rb_parent_record };
	rb_obj_call_init(	rb_key,
					 1, 
					 argv );
	
	return rb_key;		
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Key_initialize(	int				argc __attribute__ ((unused)),
												VALUE*		args __attribute__ ((unused)),
												VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_Key_settingsController(	VALUE	rb_key )	{

	VALUE	rb_local_record_settings_controller	=	Qnil;
	
	if ( ( rb_local_record_settings_controller = rb_iv_get(	rb_key,
																													RPBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Key*		c_key;
		C_RPBDB_KEY( rb_key, c_key );
	
		RPbdb_DatabaseRecordSettingsController*	c_local_record_settings_controller	=	RPbdb_Key_settingsController( c_key );

		rb_local_record_settings_controller	=	RUBY_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_local_record_settings_controller );

		rb_iv_set(	rb_key,
								RPBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER,
								rb_local_record_settings_controller );
	}

	return rb_local_record_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_Key_parentEnvironment(	VALUE	rb_key )	{

	VALUE	rb_parent_database_controller	=	rb_RPbdb_Key_parentDatabaseController( rb_key );
	VALUE	rb_parent_environment					=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPbdb_Key_parentDatabaseController(	VALUE	rb_key )	{
	
	VALUE	rb_parent_database						=	rb_RPbdb_Key_parentDatabase( rb_key );
	VALUE	rb_parent_database_controller	=	rb_RPbdb_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPbdb_Key_parentDatabase(	VALUE	rb_key )	{
	
	VALUE	rb_parent_record		=	rb_RPbdb_Key_parentRecord( rb_key );
	VALUE	rb_parent_database	=	rb_RPbdb_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_RPbdb_Key_parentRecord(	VALUE	rb_key )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_key,
																				RPBDB_RB_DATA_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}

//	Functions need to be added here
