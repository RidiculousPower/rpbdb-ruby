/*
 *		RPDB::RPDB_DatabaseController::RPDB_Database::(RPDB_DatabaseCursorController::RPDB_DatabaseCursor::)RPDB_Record::RPDB_DBT => RPDB_SecondaryKeys
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_SecondaryKeys.h"
#include "rb_RPDB_Record.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_SecondaryKeys.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_SecondaryKeys;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_Key;

void Init_RPDB_SecondaryKey()	{

	rb_RPDB_Key		=	rb_define_class_under(	rb_RPDB_Record, 
																					"SecondaryKeys", 		
																					rb_cObject );

	//	FIX - this class hasn't been considered thoroughly yet

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_SecondaryKeys_new(	int			argc,
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
	
	VALUE	rb_secondary_keys	=	RUBY_RPDB_SECONDARY_KEYS( RPDB_SecondaryKeys_new( c_parent_record ) );

	//	store reference to parent
	rb_iv_set(	rb_secondary_keys,
							RPDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD,
							rb_parent_record );

	VALUE	argv[]	=	{ rb_parent_record };
	rb_obj_call_init(	rb_secondary_keys,
										 1, 
										 argv );
	
	return rb_secondary_keys;	
}


/*************
*  self.new  *
*************/

VALUE rb_RPDB_SecondaryKeys_initialize(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_SecondaryKeys_parentEnvironment(	VALUE	rb_secondary_keys )	{

	VALUE	rb_parent_database_controller	=	rb_RPDB_SecondaryKeys_parentDatabaseController( rb_secondary_keys );
	VALUE	rb_parent_environment					=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPDB_SecondaryKeys_parentDatabaseController(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_database						=	rb_RPDB_SecondaryKeys_parentDatabase( rb_secondary_keys );
	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_SecondaryKeys_parentDatabase(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_record		=	rb_RPDB_SecondaryKeys_parentRecord( rb_secondary_keys );
	VALUE	rb_parent_database	=	rb_RPDB_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_RPDB_SecondaryKeys_parentRecord(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_secondary_keys,
																				RPDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}


/*****************
*  keyData  *
*****************/

VALUE rb_RPDB_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
 												VALUE	rb_key )	{

	RPDB_SecondaryKeys*	c_secondary_keys;
	C_RPDB_SECONDARY_KEYS( rb_secondary_keys, c_secondary_keys );

	RPDB_Key*				c_key;
	C_RPDB_KEY( rb_key, c_key );

	RPDB_SecondaryKeys_addSecondaryKey(	c_secondary_keys,
											c_key );

	return rb_secondary_keys;
}

/******************
*  setKeyData  *
******************/

VALUE rb_RPDB_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
													VALUE	rb_index )	{

	RPDB_SecondaryKeys*	c_secondary_keys;
	C_RPDB_SECONDARY_KEYS( rb_secondary_keys, c_secondary_keys );

	RPDB_SecondaryKeys_secondaryKeyForIndex(	c_secondary_keys,
												FIX2INT( rb_index ) );

	return RUBY_RPDB_KEY( RPDB_SecondaryKeys_secondaryKeyForIndex(	c_secondary_keys,
																		FIX2INT( rb_index ) ) );
}
