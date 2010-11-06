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

#include "rb_RPDB_DatabaseTypeRecnoSettingsController.h"

#include "rb_RPDB_DatabaseTypeSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseTypeRecnoSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

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
extern	VALUE	rb_RPDB_DatabaseTypeRecnoSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_DatabaseTypeRecnoSettingsController()	{

	rb_RPDB_DatabaseTypeRecnoSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
																																					"Recno",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseTypeRecnoSettingsController, 	"new",																rb_RPDB_DatabaseTypeRecnoSettingsController_new,													-1 	);
	rb_define_method(						rb_RPDB_DatabaseTypeRecnoSettingsController, 	"initialize",													rb_RPDB_DatabaseTypeRecnoSettingsController_initialize,													-1 	);
                    					
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

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_new(	int			argc,
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

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller	=	RPDB_DatabaseTypeSettingsController_recnoController( c_database_type_settings_controller );

	VALUE	rb_database_type_recno_settings_controller	= RUBY_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( c_database_type_recno_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_type_recno_settings_controller,
							RPDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_recno_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_recno_settings_controller;		
}

/*************
*  initialize  *
*************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{

	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentEnvironment(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_database  *
***************************************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabase(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/***************************************
*  parent_database_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller		=	rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_database_settings_controller				=	rb_RPDB_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***************************************
*  parent_database_type_settings_controller  *
***************************************/

VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_recno_settings_controller,
																																	RPDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  record_renumbering  *
*************************/

//	DB_RENUMBER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( RPDB_DatabaseTypeRecnoSettingsController_recordRenumbering( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*********************************
	*  turn_record_renumbering_on  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/*********************************
	*  turn_record_renumbering_off  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

/*****************
*  snapshot_isolation  *
*****************/

//	DB_SNAPSHOT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( RPDB_DatabaseTypeRecnoSettingsController_snapshotIsolation( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*********************************
	*  turn_snapshot_isolation_on  *
	*********************************/

	VALUE rb_RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( VALUE	rb_database_type_recno_settings_controller )	{

		RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		RPDB_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/*********************************
	*  turn_snapshot_isolation_off  *
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
*  source_file  *
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
*  set_source_file  *
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
*  set_append_callback_method  *
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
*  append_callback_method  *
*****************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_append_recno.html
void (*append_callback_method)(	VALUE		database,
								VALUE		record ) RPDB_DatabaseTypeRecnoSettingsController_appendCallback( VALUE	rb_database_type_recno_settings_controller )	{

	RPDB_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

}
*/