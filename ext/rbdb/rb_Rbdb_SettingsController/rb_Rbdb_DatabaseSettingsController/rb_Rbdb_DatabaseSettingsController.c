/*
 *		Rbdb::Database::DatabaseSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_DatabaseController.h"

#include "rb_Rbdb_DatabaseAssociationSettingsController.h"
#include "rb_Rbdb_DatabaseErrorSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_DatabaseTypeSettingsController.h"
#include "rb_Rbdb_DatabaseCursorSettingsController.h"
#include "rb_Rbdb_DatabaseCacheSettingsController.h"
#include "rb_Rbdb_DatabaseJoinSettingsController.h"
#include "rb_Rbdb_DatabaseSequenceSettingsController.h"

#include "rb_Rbdb_DatabaseSettingsController.h"

#include "rb_Rbdb_SettingsController.h"

#include <rbdb/Rbdb_SettingsController.h>

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseErrorSettingsController.h>

#include <rbdb/Rbdb_DatabaseAssociationSettingsController.h>
#include <rbdb/Rbdb_DatabaseCursorSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordReadWriteSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DatabaseJoinSettingsController;
extern	VALUE	rb_Rbdb_DatabaseErrorSettingsController;

extern	VALUE	rb_Rbdb_DatabaseAssociationSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCacheSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCursorSettingsController;
extern	VALUE	rb_Rbdb_DatabaseTypeSettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_Rbdb_DatabaseSequenceSettingsController;

void Init_Rbdb_DatabaseSettingsController()	{

	rb_Rbdb_DatabaseSettingsController		=	rb_define_class_under(	rb_Rbdb_SettingsController, 
																																	"Database",	
																																	rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseSettingsController, 	"new",																rb_Rbdb_DatabaseSettingsController_new,														-1 	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController,		"initialize",													rb_Rbdb_DatabaseSettingsController_initialize,													-1 	);
                    					                                                                    		  	
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"parent_environment",									rb_Rbdb_DatabaseSettingsController_parentEnvironment,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"parent_database",										rb_Rbdb_DatabaseSettingsController_parentDatabase,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"database",														"parent_database"	);
                    					                                                                          	
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"checksum?",													rb_Rbdb_DatabaseSettingsController_checksum,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"turn_checksum_on",										rb_Rbdb_DatabaseSettingsController_turnChecksumOn,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"turn_checksum_off",									rb_Rbdb_DatabaseSettingsController_turnChecksumOff,								0 	);
                    					                                                                          	
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"transaction_durability?",						rb_Rbdb_DatabaseSettingsController_transactionDurability,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"durability?",												"transaction_durability?"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"turn_transaction_durability_on",			rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOn,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"turn_durability_on",									"turn_transaction_durability_on"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"turn_transaction_durability_off",		rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOff,	0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"turn_durability_off",								"turn_transaction_durability_off"	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"pagesize",														rb_Rbdb_DatabaseSettingsController_pagesize,											0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"page_size",													"pagesize"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"set_page_size",													rb_Rbdb_DatabaseSettingsController_setPagesize,										1 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"page_size=",													"set_page_size" 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"set_pagesize",												"set_page_size"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"pagesize=",													"set_page_size"	);
//	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"max_size_page_in",										rb_Rbdb_DatabaseSettingsController_maxSizePageIn,									0 	);

	//	FIX - shouldn't this be in the file settings controller?                                	
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"is_big_endian?",											rb_Rbdb_DatabaseSettingsController_isBigEndian,										0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"big_endian?",												"is_big_endian?" 	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"set_byte_order_to_big_endian",				rb_Rbdb_DatabaseSettingsController_setByteOrderToBigEndian,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"set_to_big_endian",									"set_byte_order_to_big_endian"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"is_little_endian?",									rb_Rbdb_DatabaseSettingsController_isLittleEndian,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"little_endian?",											"is_little_endian?" 	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"set_byte_order_to_little_endian",		rb_Rbdb_DatabaseSettingsController_setByteOrderToLittleEndian,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"set_to_little_endian",								"set_byte_order_to_little_endian"	);
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"is_byte_swapped?",										rb_Rbdb_DatabaseSettingsController_isByteswapped,									0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"byte_swapped?",											"is_byte_swapped?" 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"byteswapped?",												"is_byte_swapped?" 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"is_byteswapped?",												"is_byte_swapped?" 	);

	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"error_settings_controller",					rb_Rbdb_DatabaseSettingsController_errorSettingsController,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"errors",															"error_settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"association_settings_controller",		rb_Rbdb_DatabaseSettingsController_associationSettingsController,	0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"association",												"association_settings_controller"	);
	
	//	any names set for cache controller should be duplicated below in _new to undef on environment-based controllers
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"cache_settings_controller",					rb_Rbdb_DatabaseSettingsController_cacheSettingsController,			0 	);

	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"cursor_settings_controller",					rb_Rbdb_DatabaseSettingsController_cursorSettingsController,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"cursors",														"cursor_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"cursor",															"cursor_settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"sequence_settings_controller",				rb_Rbdb_DatabaseSettingsController_sequenceSettingsController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"sequences",													"sequence_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"sequence",														"sequence_settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"join_settings_controller",						rb_Rbdb_DatabaseSettingsController_joinSettingsController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"join_settings",											"join_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"joins",															"join_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"join",																"join_settings_controller"	);
                                                                                                      		
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"type_settings_controller",						rb_Rbdb_DatabaseSettingsController_typeSettingsController,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"types",															"type_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"type",																"type_settings_controller"	);
                    					                                                                        		
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"record_read_write_settings_controller",			rb_Rbdb_DatabaseRecordSettingsController_readWriteSettingsController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"read_write",													"record_read_write_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"readwrite",													"record_read_write_settings_controller"	);
                    					                                                                        		
	rb_define_method(						rb_Rbdb_DatabaseSettingsController, 	"record_settings_controller",					rb_Rbdb_DatabaseSettingsController_recordSettingsController,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"records",														"record_settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSettingsController, 	"record",															"record_settings_controller"	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseSettingsController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	
	Rbdb_DatabaseSettingsController*	c_database_settings_controller	=	NULL;
	if ( rb_parent_database != Qnil )	{
		Rbdb_Database*	c_parent_database;
		C_Rbdb_DATABASE( rb_parent_database, c_parent_database );
		
		c_database_settings_controller	=	Rbdb_Database_settingsController( c_parent_database );
	}
	else if ( rb_parent_settings_controller != Qnil )	{
		Rbdb_SettingsController*	c_settings_controller;
		C_Rbdb_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_settings_controller );		
		c_database_settings_controller	=	Rbdb_SettingsController_databaseSettingsController( c_settings_controller );
	}

	VALUE	rb_database_settings_controller	=	RUBY_Rbdb_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller );

	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
								rb_parent_database);
		//	if we create with a database we also want to make sure we can get a reference to the parent settings controller
		if ( rb_parent_environment == Qnil )	{
			rb_parent_environment = rb_Rbdb_Database_parentEnvironment( rb_parent_database );
		}
		rb_parent_settings_controller	=	rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
								rb_parent_settings_controller);	
	}
	
	VALUE*	argv		=	NULL;
	if ( rb_parent_database != Qnil )	{
		VALUE args[] =	{ rb_parent_database };	
		argv = args;
	}
	else {
		VALUE args[] =	{ rb_parent_settings_controller };
		argv = args;
	}
	
	//	if we have a parent environment, undefine database cache controller in instance
	if ( rb_parent_environment != Qnil )	{
		VALUE	rb_database_settings_controller_singleton_class	=	rb_singleton_class( rb_database_settings_controller );
		rb_undef_method( rb_database_settings_controller_singleton_class, "cache_settings_controllers" );
	}

	rb_obj_call_init(	rb_database_settings_controller,
										1, 
										argv );
	
	return rb_database_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseSettingsController_parentEnvironment(	VALUE	rb_database_settings_controller )	{
	
	VALUE	rb_parent_settings_controller			=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_database_settings_controller );
	VALUE	rb_parent_environment							=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseSettingsController_parentDatabase(	VALUE	rb_database_settings_controller )	{

	VALUE	rb_parent_database	=	rb_iv_get(	rb_database_settings_controller,
																					Rbdb_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE );

	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSettingsController_parentSettingsController(	VALUE	rb_database_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_database_settings_controller,
																										Rbdb_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/**************
*  checksum?  *
**************/

//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseSettingsController_checksum( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return( Rbdb_DatabaseSettingsController_checksum( c_database_settings_controller )	?	Qtrue
																																											:	Qfalse );
}

	/*********************
	*  turn_checksum_on  *
	*********************/

	//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_Rbdb_DatabaseSettingsController_turnChecksumOn( VALUE	rb_database_settings_controller )	{

		VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
		if (rb_parent_database != Qnil
				&&	rb_Rbdb_Database_isOpen( rb_parent_database ) )	{
			rb_raise( rb_eRuntimeError, "Checksum settings can only be changed before database is opened." );
		}

		Rbdb_DatabaseSettingsController*	c_database_settings_controller;
		C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		Rbdb_DatabaseSettingsController_turnChecksumOn( c_database_settings_controller );

		return rb_database_settings_controller;
	}

	/**********************
	*  turn_checksum_off  *
	**********************/

	//	DB_CHKSUM				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_Rbdb_DatabaseSettingsController_turnChecksumOff( VALUE	rb_database_settings_controller )	{

		VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
		if (		rb_parent_database != Qnil
				&&	rb_Rbdb_Database_isOpen( rb_parent_database ) )	{
			rb_raise( rb_eRuntimeError, "Checksum settings can only be changed before database is opened." );
		}

		Rbdb_DatabaseSettingsController*	c_database_settings_controller;
		C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		Rbdb_DatabaseSettingsController_turnChecksumOff( c_database_settings_controller );

		return rb_database_settings_controller;
	}

/****************************
*  transaction_durability?  *
****************************/

//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseSettingsController_transactionDurability( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return( Rbdb_DatabaseSettingsController_transactionDurability( c_database_settings_controller )	?	Qtrue
																																																	:	Qfalse );

}

	/***********************************
	*  turn_transaction_durability_on  *
	***********************************/

	//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOn( VALUE	rb_database_settings_controller )	{

		Rbdb_DatabaseSettingsController*	c_database_settings_controller;
		C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		Rbdb_DatabaseSettingsController_turnTransactionDurabilityOn( c_database_settings_controller );

		return rb_database_settings_controller;
	}

	/************************************
	*  turn_transaction_durability_off  *
	************************************/

	//	DB_TXN_NOT_DURABLE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
	VALUE rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOff( VALUE	rb_database_settings_controller )	{

		Rbdb_DatabaseSettingsController*	c_database_settings_controller;
		C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

		Rbdb_DatabaseSettingsController_turnTransactionDurabilityOff( c_database_settings_controller );

		return rb_database_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/*************
*  pagesize  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_pagesize.html
VALUE rb_Rbdb_DatabaseSettingsController_pagesize( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return INT2NUM( Rbdb_DatabaseSettingsController_pagesize( c_database_settings_controller ) );
}

/*****************
*  set_pagesize  *
*****************/

VALUE rb_Rbdb_DatabaseSettingsController_setPagesize(	VALUE	rb_database_settings_controller, 
																											VALUE	rb_pagesize )	{

	VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
	if (		rb_parent_database != Qnil
			&&	rb_Rbdb_Database_isOpen( rb_parent_database ) )	{
		rb_raise( rb_eRuntimeError, "Checksum settings can only be changed before database is opened." );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	Rbdb_DatabaseSettingsController_setPageSize(	c_database_settings_controller,
													FIX2INT( rb_pagesize ) );
													
	return rb_database_settings_controller;													
}

/*******************
*  is_big_endian?  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_Rbdb_DatabaseSettingsController_isBigEndian( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( Rbdb_DatabaseSettingsController_isBigEndian( c_database_settings_controller )	?	Qtrue
																							:	Qfalse );


}

/*********************************
*  set_byte_order_to_big_endian  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_Rbdb_DatabaseSettingsController_setByteOrderToBigEndian( VALUE	rb_database_settings_controller )	{

	VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
	if (		rb_parent_database != Qnil
			&&	rb_Rbdb_Database_isOpen( rb_parent_database ) )	{
		rb_raise( rb_eRuntimeError, "Endian ordering can only be set before database is opened." );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	Rbdb_DatabaseSettingsController_setByteOrderToBigEndian( c_database_settings_controller );

	return rb_database_settings_controller;
}

/**********************
*  is_little_endian?  *
**********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_lorder.html
//	Byte order for stored integers in database
VALUE rb_Rbdb_DatabaseSettingsController_isLittleEndian( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( Rbdb_DatabaseSettingsController_isLittleEndian( c_database_settings_controller )	?	Qtrue
																								:	Qfalse );
}

/************************************
*  set_byte_order_to_little_endian  *
************************************/

VALUE rb_Rbdb_DatabaseSettingsController_setByteOrderToLittleEndian( VALUE	rb_database_settings_controller )	{

	VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
	if (		rb_parent_database != Qnil
			&&	rb_Rbdb_Database_isOpen( rb_parent_database ) )	{
		rb_raise( rb_eRuntimeError, "Endian ordering can only be set before database is opened." );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	Rbdb_DatabaseSettingsController_setByteOrderToLittleEndian( c_database_settings_controller );

	return rb_database_settings_controller;
}

/********************
*  is_byteswapped?  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get_byteswapped.html
VALUE rb_Rbdb_DatabaseSettingsController_isByteswapped( VALUE	rb_database_settings_controller )	{

	VALUE	rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_database_settings_controller );
	if (		rb_parent_database == Qnil
			||	rb_Rbdb_Database_isOpen( rb_parent_database ) == Qfalse )	{
		rb_raise( rb_eRuntimeError, "Can only check whether database is byteswapped after database has been opened." );
	}

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return ( Rbdb_DatabaseSettingsController_isByteswapped( c_database_settings_controller )	?	Qtrue
																																														:	Qfalse );
}

/****************
*  max_size_in  *
****************/
/*
//	Return the maximum size possible for the database given page size, etc. 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/am_misc/dbsizes.html
//	Not a built in function - we will have to get page size, etc. in order to calculate.
VALUE rb_Rbdb_DatabaseSettingsController_maxSizePageIn( VALUE	rb_database_settings_controller )	{

	Rbdb_DatabaseSettingsController*	c_database_settings_controller;
	C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller );

	return INT2FIX( Rbdb_DatabaseSettingsController_maxSizePageIn( c_database_settings_controller ) );
}
*/
/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/******************************
*  error_settings_controller  *
******************************/

VALUE rb_Rbdb_DatabaseSettingsController_errorSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_error_settings_controller	=	Qnil;
	if ( ( rb_database_error_settings_controller = rb_iv_get(	rb_database_settings_controller,
																														Rbdb_RB_SETTINGS_VARIABLE_DATABASE_ERROR_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_error_settings_controller	=	rb_Rbdb_DatabaseErrorSettingsController_new(	1,
																																													& rb_database_settings_controller,
																																													rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_ERROR_SETTINGS_CONTROLLER,
								rb_database_error_settings_controller );
	}

	return rb_database_error_settings_controller;
}

/************************************
*  association_settings_controller  *
************************************/

VALUE rb_Rbdb_DatabaseSettingsController_associationSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_association_settings_controller	=	Qnil;
	if ( ( rb_database_association_settings_controller = rb_iv_get(	rb_database_settings_controller,
																														Rbdb_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_association_settings_controller	=	rb_Rbdb_DatabaseAssociationSettingsController_new(	1,
																																																			& rb_database_settings_controller,
																																																			rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER,
								rb_database_association_settings_controller );
	}

	return rb_database_association_settings_controller;
}

/*****************************
*  join_settings_controller  *
*****************************/

VALUE rb_Rbdb_DatabaseSettingsController_joinSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_join_settings_controller	=	Qnil;
	if ( ( rb_database_join_settings_controller = rb_iv_get(	rb_database_settings_controller,
																														Rbdb_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_join_settings_controller	=	rb_Rbdb_DatabaseJoinSettingsController_new(	1,
																																												& rb_database_settings_controller,
																																												rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER,
								rb_database_join_settings_controller );
	}

	return rb_database_join_settings_controller;
}

/******************************
*  cache_settings_controller  *
******************************/

//	this is only defined on databases opened without an environment
VALUE rb_Rbdb_DatabaseSettingsController_cacheSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_cache_settings_controller	=	Qnil;
	if ( ( rb_database_cache_settings_controller = rb_iv_get(	rb_database_settings_controller,
																														Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_cache_settings_controller	=	rb_Rbdb_DatabaseCacheSettingsController_new(	1,
																																													& rb_database_settings_controller,
																																													rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER,
								rb_database_cache_settings_controller );
	}

	return rb_database_cache_settings_controller;
}

/*******************************
*  cursor_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSettingsController_cursorSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_cursor_settings_controller	=	Qnil;
	if ( ( rb_database_cursor_settings_controller = rb_iv_get(	rb_database_settings_controller,
																															Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_cursor_settings_controller	=	rb_Rbdb_DatabaseCursorSettingsController_new(	1,
																																														& rb_database_settings_controller,
																																														rb_Rbdb_DatabaseCursorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER,
								rb_database_cursor_settings_controller );
	}

	return rb_database_cursor_settings_controller;
}

/*********************************
*  sequence_settings_controller  *
*********************************/

VALUE rb_Rbdb_DatabaseSettingsController_sequenceSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_sequence_settings_controller	=	Qnil;
	if ( ( rb_database_sequence_settings_controller = rb_iv_get(	rb_database_settings_controller,
																																Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_sequence_settings_controller	=	rb_Rbdb_DatabaseSequenceSettingsController_new(	1,
																																																& rb_database_settings_controller,
																																																rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER,
								rb_database_sequence_settings_controller );
	}

	return rb_database_sequence_settings_controller;
}

/*****************************
*  type_settings_controller  *
*****************************/

VALUE rb_Rbdb_DatabaseSettingsController_typeSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_type_settings_controller	=	Qnil;
	if ( ( rb_database_type_settings_controller = rb_iv_get(	rb_database_settings_controller,
																														Rbdb_RB_SETTINGS_VARIABLE_DATABASE_TYPE_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_type_settings_controller	=	rb_Rbdb_DatabaseTypeSettingsController_new(	1,
																																												& rb_database_settings_controller,
																																												rb_Rbdb_DatabaseTypeSettingsController );

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_TYPE_SETTINGS_CONTROLLER,
								rb_database_type_settings_controller );
	}

	return rb_database_type_settings_controller;
}

/*******************************
*  record_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSettingsController_recordSettingsController( VALUE	rb_database_settings_controller )	{

	VALUE	rb_database_record_settings_controller	=	Qnil;
	if ( ( rb_database_record_settings_controller = rb_iv_get(	rb_database_settings_controller,
																															Rbdb_RB_SETTINGS_VARIABLE_DATABASE_RECORD_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_record_settings_controller	=	rb_Rbdb_DatabaseRecordSettingsController_new(	1,
																																														& rb_database_settings_controller,
																																														rb_Rbdb_DatabaseErrorSettingsController );		

		rb_iv_set(	rb_database_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_DATABASE_RECORD_SETTINGS_CONTROLLER,
								rb_database_record_settings_controller );
	}

	return rb_database_record_settings_controller;
}
