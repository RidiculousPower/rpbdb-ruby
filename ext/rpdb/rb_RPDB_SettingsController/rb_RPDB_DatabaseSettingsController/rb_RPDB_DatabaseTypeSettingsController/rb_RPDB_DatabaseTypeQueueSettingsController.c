/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeQueueSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseTypeQueueSettingsController.h"

#include "rb_RPDB_DatabaseTypeSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseTypeQueueSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_Database.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeQueueSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_Record;

void Init_RPDB_DatabaseTypeQueueSettingsController()	{

	rb_RPDB_DatabaseTypeQueueSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Queue",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeQueueSettingsController, 	"new",																				rb_RPDB_DatabaseTypeQueueSettingsController_new,																	-1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"initialize",																	rb_RPDB_DatabaseTypeQueueSettingsController_initialize,																	-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"parent_environment",													rb_RPDB_DatabaseTypeQueueSettingsController_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"environment",																"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"parent_database",														rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabase,												0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"database",																		"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"return_key_data_pairs_in_order?",						rb_RPDB_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder,						0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"turn_return_key_data_pairs_in_order_on",			rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"turn_return_key_data_pairs_in_order_off",		rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"number_of_pages_for_underlying_data",				rb_RPDB_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData,				0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"number_of_pages_for_underlying_data=",				rb_RPDB_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData,		1 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"set_number_of_pages_for_underlying_data",		"number_of_pages_for_underlying_data="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_type_settings_controller						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_type_settings_controller, rb_RPDB_DatabaseTypeSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database type settings controller> ]"
		)
	);

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil
			&&	rb_parent_database_type_settings_controller == Qnil )	{
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
		rb_parent_database_type_settings_controller	=	rb_RPDB_DatabaseSettingsController_typeSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_database_type_settings_controller );		

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller	=	RPDB_DatabaseTypeSettingsController_queueController( c_database_type_settings_controller );

	VALUE	rb_database_type_queue_settings_controller	=	RUBY_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( c_database_type_queue_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_type_queue_settings_controller,
							RPDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_queue_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_queue_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentEnvironment(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabase(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller		=	rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_database_settings_controller				=	rb_RPDB_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_queue_settings_controller,
																																	RPDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/***********************************
*  return_key_data_pairs_in_order  *
***********************************/

//	DB_INORDER					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return ( RPDB_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( c_database_type_queue_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*******************************************
	*  turn_return_key_data_pairs_in_order_on  *
	*******************************************/

	VALUE rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( VALUE	rb_database_type_queue_settings_controller )	{

		RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

	/***************************************
	*  return_key_data_pairs_in_order_off  *
	***************************************/

	VALUE rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( VALUE	rb_database_type_queue_settings_controller )	{

		RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/****************************************
*  number_of_pages_for_underlying_data  *
****************************************/

//	For Queue Databases		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_q_extentsize.html
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return FIX2INT( RPDB_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( c_database_type_queue_settings_controller ) );
}

/********************************************
*  set_number_of_pages_for_underlying_data  *
********************************************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	VALUE	rb_database_type_queue_settings_controller, 
																						VALUE	rb_number_of_pages_for_underlying_data )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	RPDB_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	c_database_type_queue_settings_controller,
																					FIX2INT( rb_number_of_pages_for_underlying_data ) );
	
	return rb_database_type_queue_settings_controller;
}
