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

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseTypeQueueSettingsController.h>
#include "rb_RPDB_DatabaseTypeQueueSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeQueueSettingsController;

void Init_RPDB_DatabaseTypeQueueSettingsController()	{

	rb_RPDB_DatabaseTypeQueueSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Queue",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeQueueSettingsController, 	"new",																				rb_RPDB_DatabaseTypeQueueSettingsController_new,																	1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeQueueSettingsController, 	"initialize",																	rb_RPDB_DatabaseTypeQueueSettingsController_init,																	1 	);
                    					
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
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_database_type_settings_controller )	{

	RPDB_DatabaseTypeSettingsController*	c_parent_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_parent_database_type_settings_controller );

	VALUE	rb_database_type_queue_settings_controller	=	RUBY_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( RPDB_DatabaseTypeQueueSettingsController_new( c_parent_database_type_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_type_settings_controller;
	
	rb_obj_call_init(	rb_database_type_queue_settings_controller,
					 1, 
					 argv );
	
	return rb_database_type_queue_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_init(	VALUE	rb_database_type_queue_settings_controller,
																												VALUE	rb_parent_database_type_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_type_queue_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentEnvironment(	VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseTypeQueueSettingsController_parentEnvironment( c_database_type_queue_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_parentDatabase(	VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseTypeQueueSettingsController_parentDatabase( c_database_type_queue_settings_controller ) );
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*********************************
*  returnKeyDataPairsInOrder  *
*********************************/

//	DB_INORDER					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return ( RPDB_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( c_database_type_queue_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*****************************************
	*  turnReturnKeyDataPairsInOrderOn  *
	*****************************************/

	VALUE rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( VALUE	rb_database_type_queue_settings_controller )	{

		RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

	/*****************************************
	*  turnReturnKeyDataPairsInOrderOff  *
	*****************************************/

	VALUE rb_RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( VALUE	rb_database_type_queue_settings_controller )	{

		RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
		C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

		RPDB_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( c_database_type_queue_settings_controller );

		return rb_database_type_queue_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/*****************************************
*  numberOfPagesForUnderlyingData  *
*****************************************/

//	For Queue Databases		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_q_extentsize.html
VALUE rb_RPDB_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( VALUE	rb_database_type_queue_settings_controller )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	return FIX2INT( RPDB_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( c_database_type_queue_settings_controller ) );
}

/*****************************************
*  setNumberOfPagesForUnderlyingData  *
*****************************************/

VALUE rb_RPDB_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	VALUE	rb_database_type_queue_settings_controller, 
																						VALUE	rb_number_of_pages_for_underlying_data )	{

	RPDB_DatabaseTypeQueueSettingsController*	c_database_type_queue_settings_controller;
	C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller );

	RPDB_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	c_database_type_queue_settings_controller,
																					FIX2INT( rb_number_of_pages_for_underlying_data ) );
	
	return rb_database_type_queue_settings_controller;
}
