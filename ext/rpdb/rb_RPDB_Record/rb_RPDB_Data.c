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

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_record;
	
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
*  environment  *
***************************************/

VALUE rb_RPDB_Data_parentEnvironment(	VALUE	rb_data )	{

	RPDB_Data*			c_data;
	C_RPDB_DATA( rb_data, c_data );

	RPDB_Environment*	c_environment	=	RPDB_Data_parentEnvironment( c_data );

	return RUBY_RPDB_ENVIRONMENT( c_environment );

}

//	Functions need to be added here
	