/*
 *		RPDB::Database::DatabaseSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseSettingsController.h"

#include "rb_RPDB_SettingsController.h"

#include <rpdb/RPDB_SettingsController.h>

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseErrorSettingsController.h>

#include <rpdb/RPDB_DatabaseAssociationSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseJoinSettingsController;
extern	VALUE	rb_RPDB_DatabaseErrorSettingsController;

extern	VALUE	rb_RPDB_DatabaseAssociationSettingsController;
extern	VALUE	rb_RPDB_DatabaseCursorSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_DatabaseSequenceSettingsController;

void Init_RPDB_DatabaseSettingsController()	{

	rb_RPDB_DatabaseSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																	"Database",	
																																	rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseSettingsController, 	"new",																rb_RPDB_DatabaseSettingsController_new,														1 	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController,		"initialize",													rb_RPDB_DatabaseSettingsController_init,													1 	);
                    					                                                                    		  	
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"parent_environment",									rb_RPDB_DatabaseSettingsController_parentEnvironment,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"parent_database",										rb_RPDB_DatabaseSettingsController_parentDatabase,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"database",														"parent_database"	);
                    					                                                                          	
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"checksum?",													rb_RPDB_DatabaseSettingsController_checksum,											0 	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"turn_checksum_on",										rb_RPDB_DatabaseSettingsController_turnChecksumOn,								0 	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"turn_checksum_off",									rb_RPDB_DatabaseSettingsController_turnChecksumOff,								0 	);
                    					                                                                          	
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"transaction_durability?",						rb_RPDB_DatabaseSettingsController_transactionDurability,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"durability?",												"transaction_durability?"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"turn_transaction_durability_on",			rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOn,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"turn_durability_on",									"turn_transaction_durability_on"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"turn_transaction_durability_off",		rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOff,	0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"turn_durability_off",								"turn_transaction_durability_off"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"pagesize",														rb_RPDB_DatabaseSettingsController_pagesize,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"page_size",													"pagesize"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"pagesize=",													rb_RPDB_DatabaseSettingsController_setPageSize,										1 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"page_size=",													"pagesize" 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"set_pagesize",												"pagesize"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"set_page_size",											"pagesize"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"max_size_page_in",										rb_RPDB_DatabaseSettingsController_maxSizePageIn,									0 	);

	//	FIX - shouldn't this be in the file settings controller?                                	
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"is_big_endian?",											rb_RPDB_DatabaseSettingsController_isBigEndian,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"big_endian?",												"is_big_endian?" 	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"set_byte_order_to_big_endian",				rb_RPDB_DatabaseSettingsController_setByteOrderToBigEndian,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"set_to_big_endian",									"set_byte_order_to_big_endian"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"is_little_endian?",									rb_RPDB_DatabaseSettingsController_isLittleEndian,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"little_endian?",											"is_little_endian?" 	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"set_byte_order_to_little_endian",		rb_RPDB_DatabaseSettingsController_setByteOrderToLittleEndian,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"set_to_little_endian",								"set_byte_order_to_little_endian"	);
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"is_byte_swapped?",										rb_RPDB_DatabaseSettingsController_isByteswapped,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"byte_swapped?",											"is_byte_swapped?" 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"byteswapped?",												"is_byte_swapped?" 	);

	//	FIX - shouldn't this be environment settings rather than under DB? or otherwise the error controller under DB?
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"error_settings_controller",					rb_RPDB_DatabaseSettingsController_errorSettingsController,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"errors",															"error_settings_controller"	);

	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"association_settings_controller",		rb_RPDB_DatabaseSettingsController_associationSettingsController,	0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"association",												"association_settings_controller"	);
                    					                                                                        		
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"cursor_settings_controller",					rb_RPDB_DatabaseSettingsController_cursorSettingsController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"cursors",														"cursor_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"cursor",															"cursor_settings_controller"	);

	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"sequence_settings_controller",				rb_RPDB_DatabaseSettingsController_sequenceSettingsController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"sequences",													"sequence_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"sequence",														"sequence_settings_controller"	);

	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"join_settings_controller",						rb_RPDB_DatabaseSettingsController_joinSettingsController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"join_settings",											"join_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"joins",															"join_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"join",																"join_settings_controller"	);
                                                                                                      		
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"type_settings_controller",						rb_RPDB_DatabaseSettingsController_typeSettingsController,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"types",															"type_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"type",																"type_settings_controller"	);
                    					                                                                        		
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"record_read_write_settings_controller",			rb_RPDB_DatabaseRecordSettingsController_readWriteSettingsController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"read_write",													"record_read_write_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"readwrite",													"record_read_write_settings_controller"	);
                    					                                                                        		
	rb_define_method(						rb_RPDB_DatabaseSettingsController, 	"record_settings_controller",					rb_RPDB_DatabaseSettingsController_recordSettingsController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"records",														"record_settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseSettingsController, 	"record",															"record_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																							VALUE	rb_parent_settings_controller )	{
	
	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPDB_DatabaseSettingsController*	c_database_settings_controller	=	RPDB_SettingsController_databaseSettingsController( c_parent_settings_controller );
	
	VALUE	rb_database_settings_controller	=	RUBY_RPDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller );

	VALUE	argv[ 1 ];	
	argv[ 0 ]	=	rb_parent_settings_controller;
	rb_obj_call_init(	rb_database_settings_controller,
										1, 
										argv );
	
	return rb_database_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_DatabaseSettingsController_init(	VALUE	rb_database_settings_controller,
																								VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{

	return rb_database_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseSettingsController_parentEnvironment(	VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseSettingsController_parentEnvironment( c_database_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseSettingsController_parentDatabase(	VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseSettingsController_parentDatabase( c_database_settings_controller ) );

}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/****************
*  checksum  *
****************/

//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseSettingsController_checksum( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return( RPDB_DatabaseSettingsController_checksum( c_database_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/************************
	*  turnChecksumOn  *
	************************/

	//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_RPDB_DatabaseSettingsController_turnChecksumOn( VALUE	rb_database_settings_controller )	{

		RPDB_DatabaseSettingsController*	c_database_settings_controller;
		C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		RPDB_DatabaseSettingsController_turnChecksumOn( c_database_settings_controller );

		return rb_database_settings_controller;
	}

	/************************
	*  turnChecksumOff  *
	************************/

	//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_RPDB_DatabaseSettingsController_turnChecksumOff( VALUE	rb_database_settings_controller )	{

		RPDB_DatabaseSettingsController*	c_database_settings_controller;
		C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		RPDB_DatabaseSettingsController_turnChecksumOff( c_database_settings_controller );

		return rb_database_settings_controller;
	}

/*************
*  logs  *
*************/

//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseSettingsController_transactionDurability( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return( RPDB_DatabaseSettingsController_transactionDurability( c_database_settings_controller )	?	Qtrue
																										:	Qfalse );

}

	/******************
	*  turnLogsOn  *
	******************/

	//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOn( VALUE	rb_database_settings_controller )	{

		RPDB_DatabaseSettingsController*	c_database_settings_controller;
		C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		RPDB_DatabaseSettingsController_turnTransactionDurabilityOn( c_database_settings_controller );

		return rb_database_settings_controller;
	}

	/********************
	*  turnLogsOff  *
	********************/

	//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOff( VALUE	rb_database_settings_controller )	{

		RPDB_DatabaseSettingsController*	c_database_settings_controller;
		C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		RPDB_DatabaseSettingsController_turnTransactionDurabilityOff( c_database_settings_controller );

		return rb_database_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/****************
*  pagesize  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_pagesize.html
VALUE rb_RPDB_DatabaseSettingsController_pagesize( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( RPDB_DatabaseSettingsController_pagesize( c_database_settings_controller )	?	Qtrue
																							:	Qfalse );
}

/********************
*  setPageSize  *
********************/

VALUE rb_RPDB_DatabaseSettingsController_setPageSize(	VALUE	rb_database_settings_controller, 
														VALUE	rb_pagesize )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	RPDB_DatabaseSettingsController_setPageSize(	c_database_settings_controller,
													FIX2INT( rb_pagesize ) );
													
	return rb_database_settings_controller;													
}

/*********************
*  isBigEndian  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_RPDB_DatabaseSettingsController_isBigEndian( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( RPDB_DatabaseSettingsController_isBigEndian( c_database_settings_controller )	?	Qtrue
																							:	Qfalse );


}

/*********************************
*  setByteOrderToBigEndian  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_RPDB_DatabaseSettingsController_setByteOrderToBigEndian( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	RPDB_DatabaseSettingsController_setByteOrderToBigEndian( c_database_settings_controller );

	return rb_database_settings_controller;
}

/*********************
*  isLittleEndian  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_RPDB_DatabaseSettingsController_isLittleEndian( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( RPDB_DatabaseSettingsController_isLittleEndian( c_database_settings_controller )	?	Qtrue
																								:	Qfalse );
}

/*************************************
*  setByteOrderToLittleEndian  *
*************************************/

VALUE rb_RPDB_DatabaseSettingsController_setByteOrderToLittleEndian( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	RPDB_DatabaseSettingsController_setByteOrderToLittleEndian( c_database_settings_controller );

	return rb_database_settings_controller;
}

/********************
*  isByteswapped  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get_byteswapped.html
VALUE rb_RPDB_DatabaseSettingsController_isByteswapped( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( RPDB_DatabaseSettingsController_isByteswapped( c_database_settings_controller )	?	Qtrue
																								:	Qfalse );
}

/*****************
*  maxSizeIn  *
*****************/

//	Return the maximum size possible for the database given page size, etc. 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/am_misc/dbsizes.html
//	Not a built in function - we will have to get page size, etc. in order to calculate.
VALUE rb_RPDB_DatabaseSettingsController_maxSizePageIn( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return INT2FIX( RPDB_DatabaseSettingsController_maxSizePageIn( c_database_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/********************************
*  errorSettingsController  *
********************************/

VALUE rb_RPDB_DatabaseSettingsController_errorSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_errorSettingsController( c_database_settings_controller ) );
}

/****************************
*  associateController  *
****************************/

VALUE rb_RPDB_DatabaseSettingsController_associationSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_associationSettingsController( c_database_settings_controller ) );
}

/****************************
*  joinController  *
****************************/

VALUE rb_RPDB_DatabaseSettingsController_joinSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_joinSettingsController( c_database_settings_controller ) );
}

/*****************************
*  cursorController  *
*****************************/

VALUE rb_RPDB_DatabaseSettingsController_cursorSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_cursorSettingsController( c_database_settings_controller ) );
}

/*******************************
*  sequenceSettingsController  *
*******************************/

VALUE rb_RPDB_DatabaseSettingsController_sequenceSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_sequenceSettingsController( c_database_settings_controller ) );
}

/*****************************
*  typeSettingsController  *
*****************************/

VALUE rb_RPDB_DatabaseSettingsController_typeSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_typeSettingsController( c_database_settings_controller ) );
}

/*************************************
*  readWriteSettingsController  *
*************************************/

VALUE		rb_RPDB_DatabaseRecordSettingsController_readWriteSettingsController( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return RUBY_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseRecordSettingsController_readWriteSettingsController( c_database_record_settings_controller ) );
}

/*************************************
*  recordSettingsController  *
************************************/

VALUE rb_RPDB_DatabaseSettingsController_recordSettingsController( VALUE	rb_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_DatabaseSettingsController_recordSettingsController( c_database_settings_controller ) );
}
