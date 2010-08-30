/*
 *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeRecnoSettingsController
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

#include <rpdb/RPDB_DatabaseTypeRecnoSettingsController.h>
#include "rb_RPDB_DatabaseTypeRecnoSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
extern	VALUE	rb_RPDB_DatabaseTypeRecnoSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_DatabaseTypeRecnoSettingsController()	{

	rb_RPDB_DatabaseTypeRecnoSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Recno",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeRecnoSettingsController, 	"new",																rb_RPDB_DatabaseTypeRecnoSettingsController_new,													1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"initialize",													rb_RPDB_DatabaseTypeRecnoSettingsController_init,													1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"parent_environment",									rb_RPDB_DatabaseTypeRecnoSettingsController_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"parent_database",										rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabase,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"database",														"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"record_renumbering?",								rb_RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering,						0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"turn_record_renumbering_on",					rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"turn_record_renumbering_off",				rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"snapshot_isolation?",								rb_RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation,						0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"turn_snapshot_isolation_on",					rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"turn_snapshot_isolation_off",				rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff,			0 	);

	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"source_file",												rb_RPDB_DatabaseTypeRecnoSettingsController_sourceFile,										0 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"source_file=",												rb_RPDB_DatabaseTypeRecnoSettingsController_setSourceFile,								1 	);
	rb_define_alias(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"set_source_file",										"source_file="	);
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_database_type_settings_controller )	{
	
	RPDB_DatabaseTypeSettingsController*	c_parent_database_type_settings_controller;
	C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_parent_database_type_settings_controller, c_parent_database_type_settings_controller );
	
	VALUE	rb_database_type_recno_settings_controller	= RUBY_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( RPDB_DatabaseTypeRecnoSettingsController_new( c_parent_database_type_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_type_settings_controller;
	
	rb_obj_call_init(	rb_database_type_recno_settings_controller,
					 1, 
					 argv );
	
	return rb_database_type_recno_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_init(	VALUE	rb_database_type_recno_settings_controller,
																												VALUE	rb_parent_database_type_settings_controller __attribute__ ((unused )) )	{

	return rb_database_type_recno_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentEnvironment(	VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseTypeRecnoSettingsController_parentEnvironment( c_database_type_recno_settings_controller ) );

}


/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabase(	VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return RUBY_RPDB_DATABASE(	RPDB_DatabaseTypeRecnoSettingsController_parentDatabase( c_database_type_recno_settings_controller ) );

}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  recordRenumbering  *
*************************/

//	DB_RENUMBER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*********************************
	*  turnRecordRenumberingOn  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/*********************************
	*  turnRecordRenumberingOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

/*****************
*  snapshot  *
*****************/

//	DB_SNAPSHOT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*********************************
	*  turnSnapshotIsolationOn  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/*********************************
	*  turnSnapshotIsolationOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/******************
*  sourceFile  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_source.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_sourceFile( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	//	FIX - wrap in ruby file
	RPDB_DatabaseTypeRecnoSettingsController_sourceFile( c_database_type_recno_settings_controller );
	
	return rb_database_type_recno_settings_controller;
}

/*********************
*  setSourceFile  *
*********************/

//	FIX - take ruby file and use source from within
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_setSourceFile(	VALUE	rb_database_type_recno_settings_controller,
																																	VALUE	rb_file_path __attribute__ ((unused )) )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	char*	c_source_file_path;

	RPDB_DatabaseTypeRecnoSettingsController_setSourceFile(	c_database_type_recno_settings_controller,
																													c_source_file_path );
	
	return rb_database_type_recno_settings_controller;
}	

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/

/*********************************
*  setAppendCallbackMethod  *
*********************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_append_recno.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_setAppendCallbackMethod(	VALUE	rb_database_type_recno_settings_controller,
 																		VALUE(*append_callback_method)(	VALUE		database,
																										VALUE		record ) )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	RPDB_DatabaseTypeRecnoSettingsController_setAppendCallbackMethod();


}
*/
/*****************************
*  appendCallbackMethod  *
*****************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_append_recno.html
void (*append_callback_method)(	VALUE		database,
								VALUE		record ) RPDB_DatabaseTypeRecnoSettingsController_appendCallback( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

}
*/