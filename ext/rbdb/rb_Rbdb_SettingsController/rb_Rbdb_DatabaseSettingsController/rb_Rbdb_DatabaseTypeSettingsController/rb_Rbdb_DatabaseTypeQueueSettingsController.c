/*
 *		Rbdb::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeQueueSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseTypeQueueSettingsController.h"

#include "rb_Rbdb_DatabaseTypeSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseTypeQueueSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_Database.h>

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
extern	VALUE	rb_Rbdb_DatabaseTypeSettingsController;
extern	VALUE	rb_Rbdb_DatabaseTypeQueueSettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;
extern	VALUE	rb_Rbdb_Record;

void Init_Rbdb_DatabaseTypeQueueSettingsController()	{

	rb_Rbdb_DatabaseTypeQueueSettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseTypeSettingsController, 
																																					"Queue",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseTypeQueueSettingsController, 	"new",																				rb_Rbdb_DatabaseTypeQueueSettingsController_new,																	-1 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"initialize",																	rb_Rbdb_DatabaseTypeQueueSettingsController_initialize,																	-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"parent_environment",													rb_Rbdb_DatabaseTypeQueueSettingsController_parentEnvironment,										0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"environment",																"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"parent_database",														rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabase,												0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"database",																		"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"parent_settings_controller",	rb_Rbdb_DatabaseTypeQueueSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"parent_database_settings_controller",	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"parent_database_type_settings_controller",	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController,										0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"database_type",													rb_Rbdb_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"type",																		"database_type"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"is_btree?",															rb_Rbdb_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"is_hash?",																rb_Rbdb_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"is_recno?",															rb_Rbdb_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"is_queue?",															rb_Rbdb_DatabaseTypeSettingsController_isQueue,							0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"return_key_data_pairs_in_order?",						rb_Rbdb_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"turn_return_key_data_pairs_in_order_on",			rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"turn_return_key_data_pairs_in_order_off",		rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff,			0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"number_of_pages_for_underlying_data",				rb_Rbdb_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"number_of_pages_for_underlying_data=",				rb_Rbdb_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData,		1 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeQueueSettingsController, 	"set_number_of_pages_for_underlying_data",		"number_of_pages_for_underlying_data="	);
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_new(	int			argc,
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
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_type_settings_controller, rb_Rbdb_DatabaseTypeSettingsController ) ) ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{

		//	if we have a parent_database we need to get the environment database type settings controller so we don't loop
		if ( ( rb_parent_database = rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller ) ) != Qnil )	{
			
			Rbdb_DatabaseSettingsController*	c_database_settings_controller;
			C_Rbdb_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );			
			
			Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	Rbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

			rb_parent_database_type_settings_controller	=	RUBY_RBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller );
		}
		else {
			
			rb_parent_database_type_settings_controller	=	rb_Rbdb_DatabaseSettingsController_typeSettingsController( rb_parent_database_settings_controller );
		}

	}

	Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller;
	C_Rbdb_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_database_type_settings_controller );		

	Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller	=	Rbdb_DatabaseTypeSettingsController_queueController( c_database_type_settings_controller );

	VALUE	rb_database_type_queue_settings_controller	=	RUBY_RBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( c_database_type_queue_settings_controller );

	if ( rb_parent_database != Qnil )	{

		if ( rb_parent_database_settings_controller == Qnil )	{
			rb_parent_database_settings_controller = rb_Rbdb_Database_settingsController( rb_parent_database );
		}

		//	store reference to parent database settings controller
		rb_iv_set(	rb_database_type_queue_settings_controller,
								Rbdb_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );

	}

	//	store reference to parent type settings controller
	rb_iv_set(	rb_database_type_queue_settings_controller,
							Rbdb_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );

	//	if we have a parent database in addition to our parent environmental settings controller, set it as parent as well
	//	it's possible we were passed a database settings controller with a parent database
	if (		rb_parent_database == Qnil
			&&	rb_parent_database_settings_controller != Qnil )	{
		
		rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_type_queue_settings_controller,
								Rbdb_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
								rb_parent_database );	
	}

	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_queue_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_queue_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentEnvironment(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabase(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController( rb_database_type_queue_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_queue_settings_controller,
																															Rbdb_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	if ( rb_parent_database_settings_controller == Qnil )	{
	
		VALUE	rb_parent_database_type_settings_controller		=	rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController( rb_database_type_queue_settings_controller );
		
		rb_parent_database_settings_controller							=	rb_Rbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );

	}
		
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_queue_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_queue_settings_controller,
																																	Rbdb_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/************************************
*  return_key_data_pairs_in_order?  *
************************************/

//	DB_INORDER					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( VALUE	rb_database_type_queue_settings_controller )	{

	Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_Rbdb_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return ( Rbdb_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( c_database_type_queue_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*******************************************
	*  turn_return_key_data_pairs_in_order_on  *
	*******************************************/

	VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( VALUE	rb_database_type_queue_settings_controller )	{

		Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_Rbdb_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

	/********************************************
	*  turn_return_key_data_pairs_in_order_off  *
	********************************************/

	VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( VALUE	rb_database_type_queue_settings_controller )	{

		Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_Rbdb_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/****************************************
*  number_of_pages_for_underlying_data  *
****************************************/

//	For Queue Databases		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_q_extentsize.html
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( VALUE	rb_database_type_queue_settings_controller )	{

	Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_Rbdb_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	int		c_number_of_pages_for_underlying_data		=	Rbdb_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( c_database_type_queue_settings_controller );
	VALUE	rb_number_of_pages_for_underlying_data	=	INT2FIX( c_number_of_pages_for_underlying_data );

	return rb_number_of_pages_for_underlying_data;
}

/********************************************
*  set_number_of_pages_for_underlying_data  *
********************************************/

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	VALUE	rb_database_type_queue_settings_controller, 
																																											VALUE	rb_number_of_pages_for_underlying_data )	{

	Rbdb_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_Rbdb_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	Rbdb_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	c_database_type_queue_settings_controller,
																																							FIX2INT( rb_number_of_pages_for_underlying_data ) );
	
	return rb_database_type_queue_settings_controller;
}
