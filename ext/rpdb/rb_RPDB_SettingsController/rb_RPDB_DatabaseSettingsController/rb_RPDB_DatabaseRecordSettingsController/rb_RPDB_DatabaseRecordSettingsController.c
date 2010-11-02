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

#include "rb_RPDB.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordFixedLengthSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordVariableLengthSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_SettingsController;

void Init_RPDB_DatabaseRecordSettingsController()	{

	rb_RPDB_DatabaseRecordSettingsController		=		rb_define_class_under(			rb_RPDB_DatabaseSettingsController, 
																																							"Record",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordSettingsController, 	"new",																								rb_RPDB_DatabaseRecordSettingsController_new,																						-1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"initialize",																					rb_RPDB_DatabaseRecordSettingsController_init,																					-1 	);
                    					
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
	
VALUE rb_RPDB_DatabaseRecordSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment > ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]"
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

	RPDB_DatabaseSettingsController*	c_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_database_settings_controller );		

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller	=	RPDB_DatabaseSettingsController_recordSettingsController( c_database_settings_controller );

	VALUE	rb_database_record_settings_controller	=	RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_database_record_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_settings_controller };
	
	rb_obj_call_init(	rb_database_record_settings_controller,
										 1, 
										 argv );
	
	return rb_database_record_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordSettingsController_init(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{
	
	return rb_self;
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

