/*
 *		Rbdb::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeRecnoSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseTypeRecnoSettingsController.h"

#include "rb_Rbdb_DatabaseTypeSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseTypeRecnoSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

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
extern	VALUE	rb_Rbdb_DatabaseTypeRecnoSettingsController;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_Rbdb_DatabaseTypeRecnoSettingsController()	{

	rb_Rbdb_DatabaseTypeRecnoSettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseTypeSettingsController, 
																																					"Recno",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"new",																rb_Rbdb_DatabaseTypeRecnoSettingsController_new,													-1 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"initialize",													rb_Rbdb_DatabaseTypeRecnoSettingsController_initialize,													-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"parent_environment",									rb_Rbdb_DatabaseTypeRecnoSettingsController_parentEnvironment,						0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"parent_database",										rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabase,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"database",														"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"parent_settings_controller",	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"parent_database_settings_controller",	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"parent_database_type_settings_controller",	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController,										0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"database_type",													rb_Rbdb_DatabaseTypeSettingsController_databaseType,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"type",																		"database_type"	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"is_btree?",															rb_Rbdb_DatabaseTypeSettingsController_isBTree,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"is_hash?",																rb_Rbdb_DatabaseTypeSettingsController_isHash,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"is_recno?",															rb_Rbdb_DatabaseTypeSettingsController_isRecno,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"is_queue?",															rb_Rbdb_DatabaseTypeSettingsController_isQueue,							0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"record_renumbering?",								rb_Rbdb_DatabaseTypeRecnoSettingsController_recordRenumbering,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"turn_record_renumbering_on",					rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"turn_record_renumbering_off",				rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff,			0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"snapshot_isolation?",								rb_Rbdb_DatabaseTypeRecnoSettingsController_snapshotIsolation,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"turn_snapshot_isolation_on",					rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"turn_snapshot_isolation_off",				rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff,			0 	);

	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"source_file",												rb_Rbdb_DatabaseTypeRecnoSettingsController_sourceFile,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"source_file=",												rb_Rbdb_DatabaseTypeRecnoSettingsController_setSourceFile,								1 	);
	rb_define_alias(						rb_Rbdb_DatabaseTypeRecnoSettingsController, 	"set_source_file",										"source_file="	);
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_new(	int			argc,
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

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller	=	Rbdb_DatabaseTypeSettingsController_recnoController( c_database_type_settings_controller );

	VALUE	rb_database_type_recno_settings_controller	= RUBY_RBDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( c_database_type_recno_settings_controller );

	if ( rb_parent_database != Qnil )	{

		if ( rb_parent_database_settings_controller == Qnil )	{
			rb_parent_database_settings_controller = rb_Rbdb_Database_settingsController( rb_parent_database );
		}

		//	store reference to parent database settings controller
		rb_iv_set(	rb_database_type_recno_settings_controller,
								Rbdb_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER,
								rb_parent_database_settings_controller );

	}

	//	store reference to parent type settings controller
	rb_iv_set(	rb_database_type_recno_settings_controller,
							Rbdb_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER,
							rb_parent_database_type_settings_controller );

	//	if we have a parent database in addition to our parent environmental settings controller, set it as parent as well
	//	it's possible we were passed a database settings controller with a parent database
	if (		rb_parent_database == Qnil
			&&	rb_parent_database_settings_controller != Qnil )	{
		
		rb_parent_database	=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_iv_set(	rb_database_type_recno_settings_controller,
								Rbdb_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE,
								rb_parent_database );	
	}

	VALUE	argv[]	=	{ rb_parent_database_type_settings_controller };
	rb_obj_call_init(	rb_database_type_recno_settings_controller,
										 1, 
										 argv );
	
	return rb_database_type_recno_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentEnvironment(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabase(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController( rb_database_type_recno_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_database_type_recno_settings_controller,
																															Rbdb_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER );

	if ( rb_parent_database_settings_controller == Qnil )	{
	
		VALUE	rb_parent_database_type_settings_controller		=	rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController( rb_database_type_recno_settings_controller );
		
		rb_parent_database_settings_controller							=	rb_Rbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController( rb_parent_database_type_settings_controller );

	}
		
	return rb_parent_database_settings_controller;
}

/*********************************************
*  parent_database_type_settings_controller  *
*********************************************/

VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_recno_settings_controller )	{

	VALUE	rb_parent_database_type_settings_controller	=	rb_iv_get(	rb_database_type_recno_settings_controller,
																																	Rbdb_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER );

	return rb_parent_database_type_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/************************
*  record_renumbering?  *
************************/

//	DB_RENUMBER				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_recordRenumbering( VALUE	rb_database_type_recno_settings_controller )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( Rbdb_DatabaseTypeRecnoSettingsController_recordRenumbering( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*******************************
	*  turn_record_renumbering_on  *
	*******************************/

	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( VALUE	rb_database_type_recno_settings_controller )	{

		Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/********************************
	*  turn_record_renumbering_off  *
	********************************/

	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( VALUE	rb_database_type_recno_settings_controller )	{

		Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		Rbdb_DatabaseTypeRecnoSettingsController_turnRecordRenumberingOff( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

/************************
*  snapshot_isolation?  *
************************/

//	DB_SNAPSHOT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_snapshotIsolation( VALUE	rb_database_type_recno_settings_controller )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	return ( Rbdb_DatabaseTypeRecnoSettingsController_snapshotIsolation( c_database_type_recno_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*******************************
	*  turn_snapshot_isolation_on  *
	*******************************/

	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( VALUE	rb_database_type_recno_settings_controller )	{

		Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOn( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

	/********************************
	*  turn_snapshot_isolation_off  *
	********************************/

	VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( VALUE	rb_database_type_recno_settings_controller )	{

		Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
		C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

		Rbdb_DatabaseTypeRecnoSettingsController_turnSnapshotIsolationOff( c_database_type_recno_settings_controller );
	
		return rb_database_type_recno_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Set Settings
*******************************************************************************************************************************************************************************************/

/****************
*  source_file  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_re_source.html
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_sourceFile( VALUE	rb_database_type_recno_settings_controller )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	//	FIX - wrap in ruby file
	Rbdb_DatabaseTypeRecnoSettingsController_sourceFile( c_database_type_recno_settings_controller );
	
	return rb_database_type_recno_settings_controller;
}

/********************
*  set_source_file  *
********************/

//	FIX - take ruby file and use source from within
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_setSourceFile(	VALUE	rb_database_type_recno_settings_controller,
																																	VALUE	rb_file_path __attribute__ ((unused )) )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	char*	c_source_file_path;

	Rbdb_DatabaseTypeRecnoSettingsController_setSourceFile(	c_database_type_recno_settings_controller,
																													c_source_file_path );
	
	return rb_database_type_recno_settings_controller;
}	

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/

/*******************************
*  set_append_callback_method  *
*******************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_append_recno.html
VALUE rb_Rbdb_DatabaseTypeRecnoSettingsController_setAppendCallbackMethod(	VALUE	rb_database_type_recno_settings_controller,
 																		VALUE(*append_callback_method)(	VALUE		database,
																										VALUE		record ) )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

	Rbdb_DatabaseTypeRecnoSettingsController_setAppendCallbackMethod();


}
*/
/***************************
*  append_callback_method  *
***************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_append_recno.html
void (*append_callback_method)(	VALUE		database,
								VALUE		record ) Rbdb_DatabaseTypeRecnoSettingsController_appendCallback( VALUE	rb_database_type_recno_settings_controller )	{

	Rbdb_DatabaseTypeRecnoSettingsController*	c_database_type_recno_settings_controller;
	C_Rbdb_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller );

}
*/