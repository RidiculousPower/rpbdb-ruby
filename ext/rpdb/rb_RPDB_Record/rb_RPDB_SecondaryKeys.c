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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_SecondaryKeys.h>


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
*  new  *
*************/

VALUE rb_RPDB_SecondaryKeys_new(	VALUE	klass __attribute__ ((unused )),
																	VALUE	rb_parent_record )	{
	
	RPDB_Record*			c_parent_record;
	C_RPDB_RECORD( rb_parent_record, c_parent_record );
	
	VALUE	rb_secondary_keys	=	RUBY_RPDB_SECONDARY_KEYS( RPDB_SecondaryKeys_new( c_parent_record ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_record;
	
	rb_obj_call_init(	rb_secondary_keys,
					 1, 
					 argv );
	
	return rb_secondary_keys;	
}


/*************
*  new  *
*************/

VALUE rb_RPDB_SecondaryKeys_init(	VALUE	rb_secondary_keys,
																	VALUE	rb_parent_record __attribute__ ((unused )) )	{

	return rb_secondary_keys;
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
