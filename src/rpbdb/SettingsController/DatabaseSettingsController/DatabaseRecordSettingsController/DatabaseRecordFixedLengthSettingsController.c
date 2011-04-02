/*
 *		RPbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseSettingsFixedRecordController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseRecordFixedLengthSettingsController.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseSettingsController.h"
#include "SettingsController.h"
#include "DatabaseController.h"
#include "Database.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/Database.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseController.h>

#include <rpbdb/DatabaseRecordSettingsController.h>
#include <rpbdb/DatabaseRecordFixedLengthSettingsController.h>


#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRPbdb;
VALUE	extern	rb_RPbdb_Environment;
VALUE	extern	rb_RPbdb_Database;
VALUE	extern	rb_RPbdb_DatabaseController;
VALUE	extern	rb_RPbdb_SettingsController;
VALUE	extern	rb_RPbdb_DatabaseSettingsController;
VALUE	extern	rb_RPbdb_DatabaseRecordSettingsController;
VALUE	extern	rb_RPbdb_DatabaseRecordFixedLengthSettingsController;
VALUE	extern	rb_RPbdb_Record;

void Init_rb_RPbdb_DatabaseRecordFixedLengthSettingsController()	{

	rb_RPbdb_DatabaseRecordFixedLengthSettingsController		=	rb_define_class_under(	rb_RPbdb_DatabaseRecordSettingsController, 
																																						"FixedLength",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"new",									rb_RPbdb_DatabaseRecordFixedLengthSettingsController_new,										-1 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"initialize",						rb_RPbdb_DatabaseRecordFixedLengthSettingsController_initialize,										-1 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"parent_environment",		rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"environment",					"parent_environment"	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"parent_database",			rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"database",							"parent_database"	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"parent_settings_controller",			rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"parent_database_settings_controller",			rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController,					0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"parent_database_record_settings_controller",			rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseRecordSettingsController,					0 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"record_length",				rb_RPbdb_DatabaseRecordFixedLengthSettingsController_recordLength,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"record_length=",				rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setRecordLength,				1 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"set_record_length",		"record_length=" 	);
                    					
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"padding_byte",					rb_RPbdb_DatabaseRecordFixedLengthSettingsController_paddingByte,						0 	);
	rb_define_method(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"padding_byte=",				rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setPaddingByte,					1 	);
	rb_define_alias(						rb_RPbdb_DatabaseRecordFixedLengthSettingsController, 	"set_padding_byte",			"padding_byte="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPbdb_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_RPbdb_DatabaseRecordSettingsController ) ) ),
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
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_RPbdb_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	RPbdb_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	RPbdb_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller	=	RPbdb_DatabaseRecordSettingsController_fixedLengthSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_fixed_length_settings_controller	= RUBY_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( c_database_record_fixed_length_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_record_fixed_length_settings_controller,
							RPBDB_RB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
							rb_parent_database_record_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };	
	rb_obj_call_init(	rb_database_record_fixed_length_settings_controller,
										 1, 
										 argv );
	
	return rb_database_record_fixed_length_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																VALUE*		args __attribute__ ((unused)),
																																VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentEnvironment(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController( rb_database_record_fixed_length_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabase(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController( rb_database_record_fixed_length_settings_controller );
	VALUE	rb_parent_database												=	rb_RPbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController( rb_database_record_fixed_length_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseRecordSettingsController( rb_database_record_fixed_length_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_record_settings_controller  *
***********************************************/

VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_fixed_length_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_fixed_length_settings_controller,
																																		RPBDB_RB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}

/******************
*  record_length  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_len.html
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_recordLength( VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPbdb_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	return INT2FIX( RPbdb_DatabaseRecordFixedLengthSettingsController_recordLength( c_database_record_fixed_length_settings_controller ) );
}

/**********************
*  set_record_length  *
**********************/

//	The DB->set_re_len method configures a database, not only operations performed using the specified DB name.
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setRecordLength(	VALUE	rb_database_record_fixed_length_settings_controller,
																		VALUE	rb_record_length )	{

	RPbdb_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	RPbdb_DatabaseRecordFixedLengthSettingsController_setRecordLength(	c_database_record_fixed_length_settings_controller,
	 																FIX2INT( rb_record_length ) );
	
	return rb_database_record_fixed_length_settings_controller;
}

/*****************
*  padding_byte  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_paddingByte( VALUE	rb_database_record_fixed_length_settings_controller )	{

	RPbdb_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	int		c_padding_byte	=	RPbdb_DatabaseRecordFixedLengthSettingsController_paddingByte( c_database_record_fixed_length_settings_controller );

	VALUE	rb_padding_byte	=	Qnil;

	if ( c_padding_byte )	{
		rb_padding_byte = INT2FIX( c_padding_byte );
	}
	
	rb_padding_byte	=	rb_funcall(	rb_padding_byte,
																rb_intern( "chr" ),
																0 );

	return rb_padding_byte;
}

/*********************
*  set_padding_byte  *
*********************/
	
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_pad.html
VALUE rb_RPbdb_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	VALUE	rb_database_record_fixed_length_settings_controller, 
																																					VALUE	rb_record_padding_byte )	{

	RPbdb_DatabaseRecordFixedLengthSettingsController*	c_database_record_fixed_length_settings_controller;
	C_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller );

	int	c_padding_byte	=	0;
	
	//	rb_record_padding_byte should be a 1-char string or a number
	if (		TYPE( rb_record_padding_byte ) == T_STRING
			&&	RSTRING_LEN( rb_record_padding_byte ) == 1 )	{

		char*	c_char_padding_byte	=	StringValuePtr( rb_record_padding_byte );

		c_padding_byte	= (int)	*c_char_padding_byte;

	}
	else if ( TYPE( rb_record_padding_byte ) == T_FIXNUM )	{
	
		c_padding_byte	=	FIX2INT( rb_record_padding_byte );
	
	}
	else	{
		rb_raise( rb_eArgError, "Padding byte must be either integer or character." );
	}


	RPbdb_DatabaseRecordFixedLengthSettingsController_setPaddingByte(	c_database_record_fixed_length_settings_controller,
																																		c_padding_byte );

	return rb_database_record_fixed_length_settings_controller;
}
