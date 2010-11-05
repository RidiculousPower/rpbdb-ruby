/*
 *		RPDB::RPDB_DatabaseController::RPDB_Database::(RPDB_DatabaseCursorController::RPDB_DatabaseCursor::)RPDB_Record::RPDB_DBT => RPDB_Data
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Environment.h"
#include "rb_RPDB_Data.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_Data.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_Data;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Data()	{

	rb_RPDB_Data		=	rb_define_class_under(	rb_RPDB_Record, 
																						"Data", 		
																						rb_cObject );

	//	FIX - this class hasn't been considered thoroughly yet

}


/*************
*  new  *
*************/

VALUE rb_RPDB_Data_new(	int			argc,
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

	RPDB_Record*		c_parent_record;
	C_RPDB_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_data	=	RUBY_RPDB_DATA( RPDB_Data_new( c_parent_record ) );
	
	//	store reference to parent
	rb_iv_set(	rb_data,
							RPDB_RB_DATA_VARIABLE_PARENT_RECORD,
							rb_parent_record );

	VALUE	argv[]	=	{ rb_parent_record };
	rb_obj_call_init(	rb_data,
										1, 
										argv );
	
	return rb_data;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_Data_init(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self)	{


	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Data_settingsController(	VALUE	rb_data )	{

	RPDB_Data*					c_data;
	C_RPDB_DATA( rb_data, c_data );

	return RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_Data_settingsController( c_data ) );

}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_Data_parentEnvironment(	VALUE	rb_data )	{

	VALUE	rb_parent_database_controller	=	rb_RPDB_Data_parentDatabaseController( rb_data );
	VALUE	rb_parent_environment					=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPDB_Data_parentDatabaseController(	VALUE	rb_data )	{
	
	VALUE	rb_parent_database						=	rb_RPDB_Data_parentDatabase( rb_data );
	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_Data_parentDatabase(	VALUE	rb_data )	{
	
	VALUE	rb_parent_record		=	rb_RPDB_Data_parentRecord( rb_data );
	VALUE	rb_parent_database	=	rb_RPDB_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_RPDB_Data_parentRecord(	VALUE	rb_data )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_data,
																				RPDB_RB_DATA_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}

//	Functions need to be added here
	