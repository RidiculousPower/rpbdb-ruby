/*
 *		RPDB_settingsController:RPDB_DatabaseRecordSettingsController
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

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>
#include "rb_RPDB_DatabaseRecordSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordFixedLengthSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordVariableLengthSettingsController;

void Init_RPDB_DatabaseRecordSettingsController()	{

	rb_RPDB_DatabaseRecordSettingsController		=		rb_define_class_under(			rb_RPDB_DatabaseSettingsController, 
																																							"ReadWrite",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordSettingsController, 	"new",																								rb_RPDB_DatabaseRecordSettingsController_new,																						1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"initialize",																					rb_RPDB_DatabaseRecordSettingsController_init,																					1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"parent_environment",																	rb_RPDB_DatabaseRecordSettingsController_parentEnvironment,															0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordSettingsController, 	"environment",																				"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"parent_database",																		rb_RPDB_DatabaseRecordSettingsController_parentDatabase,																0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordSettingsController, 	"database",																						"parent_database"	);                    					
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseRecordSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_record_settings_controller	=	RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_DatabaseRecordSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_record_settings_controller,
					 1, 
					 argv );
	
	return rb_database_record_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordSettingsController_init(	VALUE	rb_database_record_settings_controller,
																											VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_record_settings_controller;
}


/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseRecordSettingsController_parentEnvironment( c_database_record_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseRecordSettingsController_parentDatabase( c_database_record_settings_controller ) );

}

