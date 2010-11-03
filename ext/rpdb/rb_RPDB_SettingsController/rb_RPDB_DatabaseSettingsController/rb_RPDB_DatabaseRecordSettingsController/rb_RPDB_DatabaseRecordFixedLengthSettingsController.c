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

#include "rb_RPDB_DatabaseRecordFixedLengthSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseController.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordFixedLengthSettingsController.h>


#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRPDB;
VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_Database;
VALUE	extern	rb_RPDB_DatabaseController;
VALUE	extern	rb_RPDB_SettingsController;
VALUE	extern	rb_RPDB_DatabaseSettingsController;
VALUE	extern	rb_RPDB_DatabaseRecordSettingsController;
VALUE	extern	rb_RPDB_DatabaseRecordFixedLengthSettingsController;
VALUE	extern	rb_RPDB_Record;

void Init_RPDB_DatabaseRecordFixedLengthSettingsController()	{

	rb_RPDB_DatabaseRecordFixedLengthSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseRecordSettingsController, 
																																						"FixedLength",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"new",									rb_RPDB_DatabaseRecordFixedLengthSettingsController_new,										-1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"initialize",						rb_RPDB_DatabaseRecordFixedLengthSettingsController_init,										-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"parent_environment",		rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"environment",					"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"parent_database",			rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"database",							"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"record_length",				rb_RPDB_DatabaseRecordFixedLengthSettingsController_recordLength,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"record_length=",				rb_RPDB_DatabaseRecordFixedLengthSettingsController_setRecordLength,				1 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"set_record_length",		"record_length=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"padding_byte",					rb_RPDB_DatabaseRecordFixedLengthSettingsController_paddingByte,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"padding_byte=",				rb_RPDB_DatabaseRecordFixedLengthSettingsController_setPaddingByte,					1 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordFixedLengthSettingsController, 	"set_padding_byte",			"padding_byte="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_new(	int			argc,
																																VALUE*	args,
																																VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_record																			=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_record_settings_controller					=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPDB_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_RPDB_DatabaseRecordSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent record> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database record settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_RPDB_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller	=	RPDB_DatabaseRecordSettingsController_fixedLengthSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_fixed_length_settings_controller	= RUBY_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( c_database_record_fixed_length_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_record_fixed_length_settings_controller,
										 1, 
										 argv );
	
	return rb_database_record_fixed_length_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_init(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseRecordFixedLengthSettingsController_parentEnvironment( c_database_record_fixed_length_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabase(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseRecordFixedLengthSettingsController_parentDatabase( c_database_record_fixed_length_settings_controller ) );

}

/*********************
*  recordLength  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_len.html
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_recordLength( VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordFixedLengthSettingsController_recordLength( c_database_record_fixed_length_settings_controller ) );
}

/************************
*  setRecordLength  *
************************/

//	The DB->set_re_len method configures a database, not only operations performed using the specified DB name.
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setRecordLength(	VALUE	rb_database_record_fixed_length_settings_controller,
																		VALUE	rb_record_length )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	RPDB_DatabaseRecordFixedLengthSettingsController_setRecordLength(	c_database_record_fixed_length_settings_controller,
	 																FIX2INT( rb_record_length ) );
	
	return rb_database_record_fixed_length_settings_controller;
}

/********************
*  paddingByte  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_paddingByte( VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordFixedLengthSettingsController_paddingByte( c_database_record_fixed_length_settings_controller ) );
}

/************************
*  setPaddingByte  *
************************/
	
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPDB_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	VALUE	rb_database_record_fixed_length_settings_controller, 
																		VALUE	rb_record_padding_byte )	{

	RPDB_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	RPDB_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	c_database_record_fixed_length_settings_controller,
	 															FIX2INT( rb_record_padding_byte ) );

	return rb_database_record_fixed_length_settings_controller;
}
