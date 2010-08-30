/*
 *		RPDB::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsFixedRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseFixedRecordSettingsController.h>
#include "rb_RPDB_DatabaseFixedRecordSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_Database;
VALUE	extern	rb_RPDB_DatabaseSettingsController;
VALUE	extern	rb_RPDB_DatabaseRecordSettingsController;
VALUE	extern	rb_RPDB_DatabaseFixedRecordSettingsController;

void Init_RPDB_DatabaseFixedRecordSettingsController()	{

	rb_RPDB_DatabaseFixedRecordSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseRecordSettingsController, 
																																						"FixedRecord",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseFixedRecordSettingsController, 	"new",									rb_RPDB_DatabaseFixedRecordSettingsController_new,										1 	);
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"initialize",						rb_RPDB_DatabaseFixedRecordSettingsController_init,										1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"parent_environment",		rb_RPDB_DatabaseFixedRecordSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"environment",					"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"parent_database",			rb_RPDB_DatabaseFixedRecordSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"database",							"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"record_length",				rb_RPDB_DatabaseFixedRecordSettingsController_recordLength,						0 	);
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"record_length=",				rb_RPDB_DatabaseFixedRecordSettingsController_setRecordLength,				1 	);
	rb_define_alias(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"set_record_length",		"record_length=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"padding_byte",					rb_RPDB_DatabaseFixedRecordSettingsController_paddingByte,						0 	);
	rb_define_method(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"padding_byte=",				rb_RPDB_DatabaseFixedRecordSettingsController_setPaddingByte,					1 	);
	rb_define_alias(						rb_RPDB_DatabaseFixedRecordSettingsController, 	"set_padding_byte",			"padding_byte="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																													VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_fixed_record_settings_controller	= RUBY_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( RPDB_DatabaseFixedRecordSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_fixed_record_settings_controller,
					 1, 
					 argv );
	
	return rb_database_fixed_record_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseFixedRecordSettingsController_init(	VALUE	rb_database_fixed_record_settings_controller,
																													VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_fixed_record_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_parentEnvironment(	VALUE	rb_database_fixed_record_settings_controller )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseFixedRecordSettingsController_parentEnvironment( c_database_fixed_record_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_parentDatabase(	VALUE	rb_database_fixed_record_settings_controller )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseFixedRecordSettingsController_parentDatabase( c_database_fixed_record_settings_controller ) );

}

/*********************
*  recordLength  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_len.html
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_recordLength( VALUE	rb_database_fixed_record_settings_controller )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	return INT2FIX( RPDB_DatabaseFixedRecordSettingsController_recordLength( c_database_fixed_record_settings_controller ) );
}

/************************
*  setRecordLength  *
************************/

//	The DB->set_re_len method configures a database, not only operations performed using the specified DB name.
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_setRecordLength(	VALUE	rb_database_fixed_record_settings_controller,
																		VALUE	rb_record_length )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	RPDB_DatabaseFixedRecordSettingsController_setRecordLength(	c_database_fixed_record_settings_controller,
	 																FIX2INT( rb_record_length ) );
	
	return rb_database_fixed_record_settings_controller;
}

/********************
*  paddingByte  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_paddingByte( VALUE	rb_database_fixed_record_settings_controller )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	return INT2FIX( RPDB_DatabaseFixedRecordSettingsController_paddingByte( c_database_fixed_record_settings_controller ) );
}

/************************
*  setPaddingByte  *
************************/
	
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPDB_DatabaseFixedRecordSettingsController_setPaddingByte(	VALUE	rb_database_fixed_record_settings_controller, 
																		VALUE	rb_record_padding_byte )	{

	RPDB_DatabaseFixedRecordSettingsController*	c_database_fixed_record_settings_controller;
	C_RPDB_DATABASE_FIXED_RECORD_SETTINGS_CONTROLLER( rb_database_fixed_record_settings_controller, c_database_fixed_record_settings_controller );

	RPDB_DatabaseFixedRecordSettingsController_setPaddingByte(	c_database_fixed_record_settings_controller,
	 															FIX2INT( rb_record_padding_byte ) );

	return rb_database_fixed_record_settings_controller;
}
