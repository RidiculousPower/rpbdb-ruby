/*
 *		Rbdb::Rbdb_DatabaseController::Rbdb_Database::(Rbdb_DatabaseCursorController::Rbdb_DatabaseCursor::)Rbdb_Record::Rbdb_DBT => Rbdb_Data
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb_Data.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_Record.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_Data.h>

#include <rbdb/Rbdb_DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_Data;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_Rbdb_Data()	{

	rb_Rbdb_Data		=	rb_define_class_under(	rb_Rbdb_Record, 
																						"Data", 		
																						rb_cObject );

	//	FIX - this class hasn't been considered thoroughly yet

}


/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Data_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database					=	Qnil;
	VALUE	rb_parent_record						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_Rbdb_Record ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]",
			"[ <parent record> ]"
		)
	);

	Rbdb_Record*		c_parent_record;
	C_Rbdb_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_data	=	RUBY_Rbdb_DATA( Rbdb_Data_new( c_parent_record ) );
	
	//	store reference to parent
	rb_iv_set(	rb_data,
							Rbdb_RB_DATA_VARIABLE_PARENT_RECORD,
							rb_parent_record );

	VALUE	argv[]	=	{ rb_parent_record };
	rb_obj_call_init(	rb_data,
										1, 
										argv );
	
	return rb_data;		
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Data_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self)	{


	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_Data_settingsController(	VALUE	rb_data )	{

	VALUE	rb_local_record_settings_controller	=	Qnil;
	
	if ( ( rb_local_record_settings_controller = rb_iv_get(	rb_data,
																													Rbdb_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Data*		c_data;
		C_Rbdb_DATA( rb_data, c_data );
	
		Rbdb_DatabaseRecordSettingsController*	c_local_record_settings_controller	=	Rbdb_Data_settingsController( c_data );

		rb_local_record_settings_controller	=	RUBY_Rbdb_DATABASE_RECORD_SETTINGS_CONTROLLER( c_local_record_settings_controller );

		rb_iv_set(	rb_data,
								Rbdb_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER,
								rb_local_record_settings_controller );
	}

	return rb_local_record_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_Rbdb_Data_parentEnvironment(	VALUE	rb_data )	{

	VALUE	rb_parent_database_controller	=	rb_Rbdb_Data_parentDatabaseController( rb_data );
	VALUE	rb_parent_environment					=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_Rbdb_Data_parentDatabaseController(	VALUE	rb_data )	{
	
	VALUE	rb_parent_database						=	rb_Rbdb_Data_parentDatabase( rb_data );
	VALUE	rb_parent_database_controller	=	rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_Rbdb_Data_parentDatabase(	VALUE	rb_data )	{
	
	VALUE	rb_parent_record		=	rb_Rbdb_Data_parentRecord( rb_data );
	VALUE	rb_parent_database	=	rb_Rbdb_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_Rbdb_Data_parentRecord(	VALUE	rb_data )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_data,
																				Rbdb_RB_DATA_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}

//	Functions need to be added here
	