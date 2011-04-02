/*
 *		RPbdb::RPbdb_DatabaseController::RPbdb_Database::(RPbdb_DatabaseCursorController::RPbdb_DatabaseCursor::)RPbdb_Record::RPBDB_DBT => RPbdb_SecondaryKeys
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "SecondaryKeys.h"
#include "Record.h"
#include "DatabaseController.h"
#include "Database.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>

#include <rpbdb/Key.h>
#include <rpbdb/SecondaryKeys.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_SecondaryKeys;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_Key;

void Init_rb_RPbdb_SecondaryKey()	{

	rb_RPbdb_Key		=	rb_define_class_under(	rb_RPbdb_Record, 
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

VALUE rb_RPbdb_SecondaryKeys_new(	int			argc,
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
	
	VALUE	rb_secondary_keys	=	RUBY_RPBDB_SECONDARY_KEYS( RPbdb_SecondaryKeys_new( c_parent_record ) );

	//	store reference to parent
	rb_iv_set(	rb_secondary_keys,
							RPBDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD,
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

VALUE rb_RPbdb_SecondaryKeys_initialize(	int				argc __attribute__ ((unused)),
																	VALUE*		args __attribute__ ((unused)),
																	VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_SecondaryKeys_parentEnvironment(	VALUE	rb_secondary_keys )	{

	VALUE	rb_parent_database_controller	=	rb_RPbdb_SecondaryKeys_parentDatabaseController( rb_secondary_keys );
	VALUE	rb_parent_environment					=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database_controller  *
***************************************/

VALUE rb_RPbdb_SecondaryKeys_parentDatabaseController(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_database						=	rb_RPbdb_SecondaryKeys_parentDatabase( rb_secondary_keys );
	VALUE	rb_parent_database_controller	=	rb_RPbdb_Database_parentDatabaseController( rb_parent_database );
	
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPbdb_SecondaryKeys_parentDatabase(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_record		=	rb_RPbdb_SecondaryKeys_parentRecord( rb_secondary_keys );
	VALUE	rb_parent_database	=	rb_RPbdb_Record_parentDatabase( rb_parent_record );
	
	return rb_parent_database;
}

/***************************************
*  parent_record  *
***************************************/

VALUE rb_RPbdb_SecondaryKeys_parentRecord(	VALUE	rb_secondary_keys )	{
	
	VALUE	rb_parent_record	=	rb_iv_get(	rb_secondary_keys,
																				RPBDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD );
	return rb_parent_record;
}


/*****************
*  keyData  *
*****************/

VALUE rb_RPbdb_SecondaryKeys_addSecondaryKey(	VALUE	rb_secondary_keys,
																							VALUE	rb_key )	{

	RPbdb_SecondaryKeys*	c_secondary_keys;
	C_RPBDB_SECONDARY_KEYS( rb_secondary_keys, c_secondary_keys );

	RPbdb_Key*				c_key;
	C_RPBDB_KEY( rb_key, c_key );

	RPbdb_SecondaryKeys_addSecondaryKey(	(RPbdb_SecondaryKeysUnused*) c_secondary_keys,
																			c_key );

	return rb_secondary_keys;
}

/******************
*  setKeyData  *
******************/

VALUE rb_RPbdb_SecondaryKeys_secondaryKeyForIndex(	VALUE	rb_secondary_keys,
													VALUE	rb_index )	{

	RPbdb_SecondaryKeys*	c_secondary_keys;
	C_RPBDB_SECONDARY_KEYS( rb_secondary_keys, c_secondary_keys );

	RPbdb_SecondaryKeys_secondaryKeyForIndex(	(RPbdb_SecondaryKeysUnused*) c_secondary_keys,
																						FIX2INT( rb_index ) );

	return RUBY_RPBDB_KEY( RPbdb_SecondaryKeys_secondaryKeyForIndex(	(RPbdb_SecondaryKeysUnused*) c_secondary_keys,
																																	FIX2INT( rb_index ) ) );
}
