/*
 *		RPDB::DatabaseController::Database
 *
 *
 */

#include <rargs.h>

#include "rb_RPDB.h"
#include "rb_RPDB_internal.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_DatabaseObject_internal.h"
#include "rb_RPDB_Database_internal.h"
#include "rb_RPDB_DatabaseController.h"

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Environment.h"

#include "rb_RPDB_DatabaseCursorController.h"
#include "rb_RPDB_DatabaseCursor.h"
#include "rb_RPDB_DatabaseJoinController.h"
#include "rb_RPDB_DatabaseJoinCursor.h"
#include "rb_RPDB_DatabaseSequenceController.h"
#include "rb_RPDB_DatabaseSequence.h"

#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"

#include "rb_RPDB_DatabaseRecordReadWriteSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseCursor.h>
#include <rpdb/RPDB_Database_internal.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_DatabaseCursorController.h>
#include <rpdb/RPDB_DatabaseJoinController.h>

#include <rpdb/RPDB_Record.h>
#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_Data.h>
#include <rpdb/RPDB_SecondaryKeys.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursor;
extern	VALUE	rb_RPDB_DatabaseObjectCursor;
extern	VALUE	rb_RPDB_DatabaseCursorController;
extern	VALUE	rb_RPDB_DatabaseJoinController;
extern	VALUE	rb_RPDB_DatabaseSequenceController;

extern	VALUE	rb_RPDB_Key;
extern	VALUE	rb_RPDB_Data;
extern	VALUE	rb_RPDB_SecondaryKeys;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;

extern VALUE rb_cArray;
extern VALUE rb_cHash;
extern VALUE rb_cStruct;
extern VALUE rb_cString;
extern VALUE rb_cRegexp;
extern VALUE rb_cClass;
extern VALUE rb_cSymbol;
extern VALUE rb_cBignum;
extern VALUE rb_cFixnum;
extern VALUE rb_cFloat;
extern VALUE rb_cTrueClass;
extern VALUE rb_cFalseClass;

#define RPDB_RUBY_ERROR_INVALID_DATABASE_DATA			"Provided data was invalid. Database requires object that can be automatically converted to string."

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Database()	{

	rb_RPDB_Database		=	rb_define_class_under(	rb_mRPDB, 
																								"Database",
																								rb_cObject );

	rb_define_singleton_method(	rb_RPDB_Database, 	"new",																					rb_RPDB_Database_new,																				-1 	);
	rb_define_method(						rb_RPDB_Database, 	"initialize",																		rb_RPDB_Database_initialize,																			-1 	);

	rb_define_method(						rb_RPDB_Database, 	"settings_controller",													rb_RPDB_Database_settingsController,												0 	);
	rb_define_alias(						rb_RPDB_Database, 	"settings",																			"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"set",																					"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"set_to",																				"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"is_set_to",																		"settings_controller"	);                            				
	rb_define_method(						rb_RPDB_Database, 	"parent_environment",														rb_RPDB_Database_parentEnvironment,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"parent_environment",														"parent_environment"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"environment",																	"parent_environment"	);                            				

	rb_define_method(						rb_RPDB_Database, 	"filename",																			rb_RPDB_Database_filename,																	0 	);
	rb_define_method(						rb_RPDB_Database, 	"name",																					rb_RPDB_Database_name,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"rename",																				rb_RPDB_Database_rename,																		1 	);
	rb_define_method(						rb_RPDB_Database, 	"handle",																				rb_RPDB_Database_handle,																		0 	);

	rb_define_method(						rb_RPDB_Database, 	"open",																					rb_RPDB_Database_open,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"is_open?",																			rb_RPDB_Database_isOpen,																		0 	);
	rb_define_alias(						rb_RPDB_Database, 	"open?",																				"is_open?"	);                                        				
	rb_define_method(						rb_RPDB_Database, 	"close",																				rb_RPDB_Database_close,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"empty!",																				rb_RPDB_Database_empty,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"erase!",																				rb_RPDB_Database_erase,																			0 	);
	rb_define_alias(						rb_RPDB_Database, 	"delete!",																			"erase!"	);                            				
	rb_define_method(						rb_RPDB_Database, 	"sync!",																				rb_RPDB_Database_sync,																			0 	);

	rb_define_method(						rb_RPDB_Database, 	"key_exists?",																	rb_RPDB_Database_keyExists,																	-1 	);
	rb_define_alias(						rb_RPDB_Database, 	"exists?",																			"key_exists?" );                                    				
	rb_define_method(						rb_RPDB_Database, 	"write",																				rb_RPDB_Database_write,																			-1 	);
	rb_define_method(						rb_RPDB_Database, 	"retrieve",																			rb_RPDB_Database_retrieve,																	-1 	);
	rb_define_method(						rb_RPDB_Database, 	"delete",																				rb_RPDB_Database_delete,																		-1 	);
                    					                                                                                                                        				
	rb_define_method(						rb_RPDB_Database, 	"is_secondary_database?",												rb_RPDB_Database_isSecondary,																0 	);
	rb_define_alias(						rb_RPDB_Database, 	"is_secondary_index?",													"is_secondary_database?"	);
	rb_define_alias(						rb_RPDB_Database, 	"is_secondary?",																"is_secondary_database?"	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary_database?",													"is_secondary_database?"	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary_index?",															"is_secondary_database?"	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary?",																		"is_secondary_database?"	);
	rb_define_method(						rb_RPDB_Database, 	"primary_database",															rb_RPDB_Database_primaryDatabase,																0 	);
	rb_define_alias(						rb_RPDB_Database, 	"primary",																			"primary_database"	);
	rb_define_method(						rb_RPDB_Database, 	"secondary_key_creation_callback_method",				rb_RPDB_Database_secondaryKeyCreationCallbackMethod,				0 	);
	rb_define_method(						rb_RPDB_Database, 	"set_secondary_key_creation_callback_method",		rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod,			-1 	);
	rb_define_method(						rb_RPDB_Database, 	"create_secondary_index",												rb_RPDB_Database_createSecondaryIndex,											-1 	);
	rb_define_alias(						rb_RPDB_Database, 	"create_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"new_secondary",																"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"new_index",																		"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"associate_secondary_database",									"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"associate_secondary",													"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"associate",																		"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"use_as_secondary_index",												"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"use_as_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"create_secondary_index_with_database",					"create_secondary_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"create_secondary_with_database",								"create_secondary_index"	);


	rb_define_method(						rb_RPDB_Database, 	"secondary_database_with_index",								rb_RPDB_Database_secondaryDatabaseWithIndex,								1 	);
	rb_define_alias(						rb_RPDB_Database, 	"database_with_index",													"secondary_database_with_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary_database",														"secondary_database_with_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary",																		"secondary_database_with_index"	);
	rb_define_alias(						rb_RPDB_Database, 	"index",																				"secondary_database_with_index"	);
                    					
	rb_define_method(						rb_RPDB_Database, 	"cursor_controller",														rb_RPDB_Database_cursorController,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"cursors",																			"cursor_controller"	);
	rb_define_method(						rb_RPDB_Database, 	"cursor",																				rb_RPDB_Database_cursor,																		0 	);
	rb_define_method(						rb_RPDB_Database, 	"object_cursor",																rb_RPDB_Database_objectCursor,															0 	);

	rb_define_method(						rb_RPDB_Database, 	"iterate",																			rb_RPDB_Database_iterate,																		0 	);
	rb_define_alias(						rb_RPDB_Database, 	"each",																					"iterate"	);
	rb_define_method(						rb_RPDB_Database, 	"iterate_duplicates",														rb_RPDB_Database_iterateDuplicates,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"each_duplicate",																"iterate_duplicates"	);
	rb_define_method(						rb_RPDB_Database, 	"iterate_keys",																	rb_RPDB_Database_iterateKeys,																0 	);
	rb_define_alias(						rb_RPDB_Database, 	"each_key",																			"iterate_keys"	);

	rb_define_method(						rb_RPDB_Database, 	"sequence_controller",													rb_RPDB_Database_sequenceController,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"sequences",																		"sequence_controller"	);
	rb_define_alias(						rb_RPDB_Database, 	"sequence",																			"sequence_controller"	);

	rb_define_method(						rb_RPDB_Database, 	"join_controller",															rb_RPDB_Database_joinController,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"joins",																				"join_controller"	);
	rb_define_alias(						rb_RPDB_Database, 	"join",																					"join_controller"	);
}

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_RPDB_Database_new(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self __attribute__((unused)) )	{

	VALUE	rb_database_name							=	Qnil;
	VALUE	rb_parent_database_controller	=	Qnil;
	VALUE	rb_parent_environment					=	Qnil;
	
	/*------------------------------------------------------*/

	VALUE	rb_parent_environment_or_directory_or_database_controller	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_database_name,
								& rb_parent_environment_or_directory_or_database_controller );
	
	//	if we have a second parameter, figure out what it is
	if ( rb_parent_environment_or_directory_or_database_controller != Qnil ) {
		
		//	if we have a path, initialize environment
		if ( TYPE( rb_parent_environment_or_directory_or_database_controller ) == T_STRING )	{
			rb_parent_environment	=	rb_RPDB_Environment_new(	1,
																												& rb_parent_environment_or_directory_or_database_controller,
																												rb_RPDB_Environment );
			rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		}
		//	otherwise see if we have an environment or database controller
		else {
			
			VALUE	rb_arg_klass			=	rb_class_of( rb_parent_environment_or_directory_or_database_controller );
			VALUE	rb_arg_ancestors	=	rb_mod_ancestors( rb_arg_klass );
			//	database controller
			if ( rb_ary_includes(	rb_arg_ancestors,
														rb_RPDB_DatabaseController ) == Qtrue )	{

				rb_parent_database_controller	=	rb_parent_environment_or_directory_or_database_controller;
			}
			//	environment
			else if ( rb_ary_includes(	rb_arg_ancestors,
																	rb_RPDB_Environment ) == Qtrue )	{
				
				rb_parent_environment					=	rb_parent_environment_or_directory_or_database_controller;
			}
		}
	}
	else {
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
		rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
	}

	
	//	Raise exceptions if we can't find a parent database controller
	if (		rb_parent_database_controller == Qnil )	{
		
		if ( rb_parent_environment == Qnil )	{
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND );
		}
		else {
			rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		}
		
		if ( rb_parent_database_controller == Qnil )	{
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MESSAGE_DATABASE_CONTROLLER_NOT_FOUND );
		}
	}

	/*------------------------------------------------------*/

	RPDB_DatabaseController*	c_parent_database_controller;
	char*	c_database_name		=	NULL;
	if ( rb_database_name != Qnil )	{
		rb_database_name	=	rb_obj_as_string( rb_database_name );
		c_database_name	=	StringValuePtr( rb_database_name );
	}
	C_RPDB_DATABASE_CONTROLLER( rb_parent_database_controller, c_parent_database_controller );
	
	RPDB_Database*	c_database	=	RPDB_DatabaseController_newDatabase(	c_parent_database_controller,
																																			c_database_name );
	
	VALUE	rb_database	=	RUBY_RPDB_DATABASE( c_database );

	//	store reference to parent
	rb_iv_set(	rb_database,
							RPDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER,
							rb_parent_database_controller );
	
	//	store reference to ruby instance by c instance
	rb_RPDB_Database_internal_storeRubyRuntimeInstanceForCInstance( rb_database );

	VALUE	argv[]	=	{ rb_parent_database_controller };
	rb_obj_call_init(	rb_database,
										1, 
										argv );

	return rb_database;	
}

/***************
*  initialize  *
***************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_RPDB_Database_initialize(	int			argc __attribute__((unused)),
															VALUE*	args __attribute__((unused)),
															VALUE		rb_database_self )	{
		
	return rb_database_self;
}

/************************
*  settings_controller  *
*  settings             *
************************/
VALUE rb_RPDB_Database_settingsController( VALUE	rb_database )	{

	VALUE	rb_local_database_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_settings_controller = rb_iv_get(	rb_database,
																														RPDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_local_database_settings_controller	=	rb_RPDB_DatabaseSettingsController_new(	1,
																																										& rb_database,
																																										rb_RPDB_DatabaseSettingsController );
		rb_iv_set(	rb_database,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER,
								rb_local_database_settings_controller );
	}

	return rb_local_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_RPDB_Database_parentEnvironment(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_database );
	VALUE	rb_parent_environment					=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/*******************************
*  parent_database_controller  *
*  database_controller         *
*  controller                  *
*******************************/

VALUE rb_RPDB_Database_parentDatabaseController(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_iv_get(	rb_database,
																										RPDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER );

	return rb_parent_database_controller;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************
*  filename  *
*************/

VALUE rb_RPDB_Database_filename( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return rb_str_new2( RPDB_Database_filename( c_database ) );	
}

/*********
*  name  *
*********/

VALUE rb_RPDB_Database_name( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	char*	c_database_name		=	RPDB_Database_name( c_database );
	VALUE	rb_database_name	=	rb_str_new2( c_database_name );

	return rb_database_name;	
}

/***********
*  rename  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_rename.html
VALUE rb_RPDB_Database_rename(	VALUE	rb_database,
																VALUE	rb_name	)	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	rb_name	=	rb_obj_as_string( rb_name );

	char*	c_name	=	StringValuePtr( rb_name );

	RPDB_Database_rename(	c_database,
												c_name );
						
	return rb_database;
}

/***********
*  handle  *
***********/

VALUE rb_RPDB_Database_handle( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	VALUE	rb_database_name		=	rb_RPDB_Database_name( rb_database );
	VALUE	rb_database_handle	=	STRING2SYM( rb_database_name );

	return rb_database_handle;	
}

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_Database_open( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_open( c_database );

	return rb_database;
}

/*************
*  is_open?  *
*************/

VALUE rb_RPDB_Database_isOpen( VALUE	rb_database )	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );
	
	if ( RPDB_Database_isOpen( c_database ) )	{
		return Qtrue;
	}
	
	return Qfalse;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPDB_Database_close( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	rb_RPDB_Database_internal_removeCallbackInfoFromHash( rb_database );
	
	RPDB_Database_close( c_database );

	return rb_database;
}

/***********
*  empty!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_truncate.html
VALUE rb_RPDB_Database_empty( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_empty( c_database );

	return rb_database;
}

/***********
*  erase!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_remove.html
VALUE rb_RPDB_Database_erase( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_erase( c_database );

	return rb_database;
}

/*********
*  copy  *
*********/

//	Duplicate in Same Environment (requires resetIDs)
	/*
VALUE rb_RPDB_Database_copy( VALUE	rb_database )	{
	RPDB_Database_copy();

	//	Copy database file or logical db
	//	reset IDs
	//	return new name
}
*/

/********************************
*  copy_to_foreign_environment  *
********************************/

//	Copy to Foreign Environment (requires log.resetLSN)	
	/*
VALUE rb_RPDB_Database_copyToForeignEnvironment( VALUE	rb_database )	{
	RPDB_Database_copyToForeignEnvironment();

	//	copy database file or logical db
	//	reset LSN
	//	add to new environment
	//	return new name
}
*/

/*********
*  sync  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_sync.html
VALUE rb_RPDB_Database_sync( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_sync( c_database );

	return rb_database;	
}

/******************
*  is_secondary?  *
******************/

VALUE rb_RPDB_Database_isSecondary(	VALUE	rb_database )	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	BOOL	c_is_secondary	=	RPDB_Database_isSecondary( c_database );
	
	VALUE	rb_is_secondary	=	c_is_secondary ? Qtrue : Qfalse;

	return rb_is_secondary;
}

/*********************
*  primary_database  *
*********************/

VALUE rb_RPDB_Database_primaryDatabase(	VALUE	rb_primary_or_secondary_database )	{
	
	RPDB_Database*		c_primary_or_secondary_database;
	C_RPDB_DATABASE( rb_primary_or_secondary_database, c_primary_or_secondary_database );
	
	if ( RPDB_Database_isSecondary( c_primary_or_secondary_database ) == FALSE )	{
		return rb_primary_or_secondary_database;
	}
	
	RPDB_Database*		c_primary_database	=	NULL;
	c_primary_database	=	RPDB_Database_primaryDatabase( c_primary_or_secondary_database );
	
	VALUE	rb_primary_database	=	Qnil;
	if ( c_primary_database != NULL )	{
		rb_primary_database	=	rb_RPDB_Database_internal_rubyRuntimeInstanceForCInstance( c_primary_database );
	}

	return rb_primary_database;
}

/***********************************************
*  set_secondary_key_creation_callback_method  *
***********************************************/

VALUE rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod(	int			argc, 
																															VALUE*	args,
																															VALUE		rb_secondary_database	)	{

	VALUE	rb_callback_method														=	Qnil;
	VALUE	rb_callback_object														=	Qnil;
	VALUE	rb_callback_proc															= Qnil;

	R_DefineAndParse( argc, args, rb_secondary_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchBlockLambdaWithArity(					rb_callback_proc, 0, 1, 2, 3, -1, -2 ) ) ),
			R_ListOrder( 1 ),
			"& block"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchProcWithArity(									rb_callback_proc, 0, 1, 2, 3, -1, -2 ) ) ),
			R_ListOrder( 2 ),
			"<callback_proc>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchMethod(												rb_callback_method ) ) ),
			R_ListOrder( 3 ),
			"<callback_method_in_self>"
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchStringSymbol(									rb_callback_method ) ) ),
			R_ListOrder( 3 ),
			":callback_method_in_self"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(														rb_callback_object ) ),
												R_Parameter(	R_MatchStringSymbol(									rb_callback_method ) ) ),
			R_ListOrder( 4 ),
			"<callback_object>, :callback_method_in_object"
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_Hash(	R_HashKey(	R_MatchAny(						rb_callback_object) ),
																							R_HashData( R_MatchStringSymbol(	rb_callback_method ) ) ) ) ),
			R_ListOrder( 5 ),
			"<callback_object> => :callback_method_in_object",
			"'callback_object' => <callback_method_in_object>"
		)

		//----------------------------------------------//

	)

	if ( rb_callback_proc != Qnil )	{
		//	store proc
		rb_callback_object	= rb_callback_proc;
	}
	else if (		TYPE( rb_callback_method ) == T_SYMBOL
					||	TYPE( rb_callback_method ) == T_STRING )	{
		//	store method object
		rb_callback_object	=	rb_funcall(	( rb_callback_object == Qnil ? rb_secondary_database : rb_callback_object ),
																			rb_intern( "method" ),
																			1,
																			rb_callback_method );
	}
	else if ( rb_callback_method != Qnil ) {
		rb_callback_object	=	rb_callback_method;
	}


	VALUE	rb_arity	=	rb_funcall(	rb_callback_object,
																rb_intern( "arity" ),
																0 );

	int	c_arity	=	FIX2INT( rb_arity );
	switch ( c_arity )	{
		case 1:
		case 2:
		case 3:
		case -1:
		case -2:
			break;
		default:
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );			
			break;
	}
	
	RPDB_Database*		c_secondary_database;
	C_RPDB_DATABASE( rb_secondary_database, c_secondary_database );

	//	When an insert is made we need our RPDB callback to call the Ruby RPDB callback
	//	our Ruby RPDB callback calls the ruby method that has been specified and returns it to RPDB
	RPDB_Database_setSecondaryKeyCreationCallbackMethod(	c_secondary_database,
																												& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Now we need to make sure that we have our appropriate info when we reach our internal callback

	rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_secondary_database,
																																						rb_callback_object,
																																						rb_callback_method );
	
	//	Returns the database
	return rb_secondary_database;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

VALUE rb_RPDB_Database_secondaryKeyCreationCallbackMethod(	VALUE	rb_secondary_database )	{
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPDB,
																				RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_secondary_database_id	=	rb_obj_id( rb_secondary_database );
	
	VALUE	rb_callback_info_hash	=	rb_hash_aref(	rb_callbacks_hash,
																							rb_secondary_database_id );
	
	return rb_callback_info_hash;
}

/***************************
*  create_secondary_index  *
***************************/

//	index name, callback method in primary database
//	index name, callback object, callback method
//	index name, callback lambda
//	index name, secondary_database, callback method in primary database
//	index name, secondary_database, callback object, callback method
//	index name, secondary_database, callback lambda
VALUE rb_RPDB_Database_createSecondaryIndex(	int			argc, 
																							VALUE*	args,
																							VALUE		rb_primary_database_self	)	{

	return rb_RPDB_Database_internal_createSecondaryIndex(	argc,
																													args,
																													rb_primary_database_self,
																													FALSE,
																													FALSE );
}

/*******************************************
*  create_secondary_index_with_duplicates  *
*******************************************/

//	index name, callback method in primary database
//	index name, callback object, callback method
//	index name, callback lambda
//	index name, secondary_database, callback method in primary database
//	index name, secondary_database, callback object, callback method
//	index name, secondary_database, callback lambda
VALUE rb_RPDB_Database_createSecondaryIndexWithDuplicates(	int			argc, 
																														VALUE*	args,
																														VALUE		rb_primary_database_self	)	{

	return rb_RPDB_Database_internal_createSecondaryIndex(	argc,
																													args,
																													rb_primary_database_self,
																													TRUE,
																													FALSE );

}

/**************************************************
*  create_secondary_index_with_sorted_duplicates  *
**************************************************/

//	index name, callback method in primary database
//	index name, callback object, callback method
//	index name, callback lambda
//	index name, secondary_database, callback method in primary database
//	index name, secondary_database, callback object, callback method
//	index name, secondary_database, callback lambda
VALUE rb_RPDB_Database_createSecondaryIndexWithSortedDuplicates(	int			argc, 
																																	VALUE*	args,
																																	VALUE		rb_primary_database_self	)	{

	return rb_RPDB_Database_internal_createSecondaryIndex(	argc,
																													args,
																													rb_primary_database_self,
																													TRUE,
																													TRUE );

}

/******************************
*  secondaryDatabaseWithIndex  *
******************************/

VALUE rb_RPDB_Database_secondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																										VALUE	rb_index_name )	{
	
	//	make sure that store/retrieve by symbol
	if ( TYPE( rb_index_name ) == T_STRING )	{
		rb_index_name	=	STRING2SYM( rb_index_name );
	}
	
	VALUE	rb_secondary_database_hash	=	rb_RPDB_Database_secondaryDatabaseHash( rb_primary_database );
	
	VALUE	rb_database_with_index				=	rb_hash_aref(	rb_secondary_database_hash,
																											rb_index_name );
																									
	return rb_database_with_index;
}

/*************************************
*  requireSecondaryDatabaseWithIndex  *
*************************************/

VALUE rb_RPDB_Database_requireSecondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																													VALUE	rb_index_name )	{
	
	VALUE	rb_database_with_index				=	rb_RPDB_Database_secondaryDatabaseWithIndex(	rb_primary_database,
																																											rb_index_name );

	if ( rb_database_with_index == Qnil )	{
		rb_raise( rb_eArgError, "Requested secondary index was missing." );
	}
	return rb_database_with_index;
}

/**************************
*  secondaryDatabaseHash  *
**************************/

VALUE rb_RPDB_Database_secondaryDatabaseHash( VALUE rb_primary_database )	{
	
	VALUE	rb_secondary_database_hash	=	rb_iv_get(	rb_primary_database,
																									RPDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES );
	if ( rb_secondary_database_hash == Qnil )	{
		rb_secondary_database_hash = rb_hash_new();
		rb_iv_set(	rb_primary_database,
								RPDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES,
								rb_secondary_database_hash );
	}
	return rb_secondary_database_hash;
}

/************
*  compact  *
************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
VALUE rb_RPDB_Database_compact(	VALUE	rb_database, 
									VALUE	start_record, 
									VALUE	stop_record )	{
	RPDB_Database_compact();


}

VALUE rb_RPDB_Database_compactAllRecords( VALUE	rb_database )	{
	RPDB_Database_compactAllRecords();


}
*/
/****************
*  upgrade  *
****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_upgrade.html
VALUE rb_RPDB_Database_upgrade( VALUE	rb_database )	{
	RPDB_Database_upgrade();

}
*/
/************************
*  resetDatabaseIDs  *
************************/
/*
//	For copying database and using duplicate in same environment 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
VALUE rb_RPDB_Database_resetDatabaseIDs( VALUE	rb_database )	{
	RPDB_Database_resetDatabaseIDs();

}
*/
/****************************************
*  prepareDatabaseForFileTransfer  *
****************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_lsn_reset.html
VALUE rb_RPDB_Database_prepareDatabaseForFileTransfer( VALUE	rb_database )	{
	RPDB_Database_prepareDatabaseForFileTransfer();
	
}
*/

/***********
*  cursor  *
***********/

VALUE rb_RPDB_Database_cursor( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPDB_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPDB_DatabaseCursorController_cursor( rb_database_cursor_controller );
		
	return rb_database_cursor;
}	

/*************
*  cursor  *
************/

VALUE rb_RPDB_Database_objectCursor( VALUE	rb_database )	{

	VALUE	rb_database_cursor_controller	=	rb_RPDB_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPDB_DatabaseCursorController_objectCursor( rb_database_cursor_controller );

	return rb_database_cursor;
}	

/************
*  iterate  *
************/

VALUE rb_RPDB_Database_iterate( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor						=	rb_RPDB_Database_cursor( rb_database );

	//	set the cursor position
	/*
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );
*/
	rb_RPDB_DatabaseCursor_retrieveFirst( rb_database_cursor );
	
	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPDB_DatabaseCursor_iterate(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPDB_DatabaseCursor_iterate, rb_database_cursor,
											rb_RPDB_DatabaseCursor_close, rb_database_cursor );
	}
	
	return rb_database;
}

/*****************
*  iterate_keys  *
*****************/

VALUE rb_RPDB_Database_iterateKeys( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPDB_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPDB_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPDB_DatabaseCursor_iterateKeys(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPDB_DatabaseCursor_iterateKeys, rb_database_cursor,
											rb_RPDB_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/*****************
*  iterate_keys  *
*****************/

VALUE rb_RPDB_Database_iterateDuplicates( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPDB_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPDB_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPDB_DatabaseCursor_iterateDuplicates(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPDB_DatabaseCursor_iterateDuplicates, rb_database_cursor,
											rb_RPDB_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*************************
*  cursorController  *
*************************/

VALUE rb_RPDB_Database_cursorController( VALUE	rb_database )	{

	VALUE	rb_cursor_controller	=	Qnil;
	
	if ( ( rb_cursor_controller = rb_iv_get(	rb_database,
																						RPDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Database*		c_database;
		C_RPDB_DATABASE( rb_database, c_database );

		rb_cursor_controller	=	rb_RPDB_DatabaseCursorController_new(	1,
																																	& rb_database,
																																	rb_RPDB_DatabaseCursorController );

		rb_iv_set(	rb_database,
								RPDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER,
								rb_cursor_controller );
	}

	return rb_cursor_controller;
}

/*******************
*  joinController  *
*******************/

VALUE rb_RPDB_Database_joinController( VALUE	rb_database )	{
	
	VALUE	rb_join_controller	=	Qnil;
	
	if ( ( rb_join_controller = rb_iv_get(	rb_database,
																					RPDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Database*		c_database;
		C_RPDB_DATABASE( rb_database, c_database );
	
		rb_join_controller	=	rb_RPDB_DatabaseJoinController_new(	1,
																															& rb_database,
																															rb_RPDB_DatabaseJoinController );

		rb_iv_set(	rb_database,
								RPDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER,
								rb_join_controller );
	}

	return rb_join_controller;
}

/***********************
*  sequenceController  *
***********************/

VALUE rb_RPDB_Database_sequenceController( VALUE	rb_database )	{
	
	VALUE	rb_sequence_controller	=	Qnil;
	
	if ( ( rb_sequence_controller = rb_iv_get(	rb_database,
																							RPDB_RB_DATABASE_SEQUENCE_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Database*		c_database;
		C_RPDB_DATABASE( rb_database, c_database );
	
		rb_sequence_controller	=	rb_RPDB_DatabaseSequenceController_new(	1,
																																			& rb_database,
																																			rb_RPDB_DatabaseSequenceController );

		rb_iv_set(	rb_database,
								RPDB_RB_DATABASE_SEQUENCE_CONTROLLER,
								rb_sequence_controller );
	}

	return rb_sequence_controller;
}

/*******************************************************************************************************************************************************************************************
																		Write Actions
*******************************************************************************************************************************************************************************************/

/**********************
*  write  *
**********************/

//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records.
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_Database_write(	int			argc, 
															VALUE*	args, 
															VALUE		rb_database )	{

	VALUE	rb_key																			=	Qnil;
	VALUE	rb_data																			=	Qnil;
	VALUE	rb_hash_descriptor_key_data_or_datas_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_key_data_or_datas_array,
																										R_HashKey(	R_Type(	R_ANY ) ),
																										R_HashData(	R_Type( R_ANY ) ) ) ) ),
			R_ListOrder( 2 ),
			"{ <key>   =>  <data>, ... }, ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 4 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 3 ),
			"key, [ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(		rb_key ) ),
												R_Parameter(	R_MatchAny(		rb_data ) ) ),
			R_ListOrder( 1 ),
			"<key>, <data, ...>"
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	rb_database;
	
	if (				rb_hash_descriptor_key_data_or_datas_array != Qnil ) {

		R_IterateHashDescriptor(	rb_hash_descriptor_key_data_or_datas_array, 
															rb_RPDB_Database_write );

	}
	else if (		rb_key != Qnil
					&&	rb_args_array != Qnil )	{
		
		R_IterateArrayDescriptor(	rb_args_array,
															rb_RPDB_Database_write,
															rb_key  );
	}
	else if (		rb_args_array != Qnil )	{
	
		R_IterateArrayDescriptor(	rb_args_array,
															rb_RPDB_Database_write  );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		RPDB_Database*	c_database	=	NULL;
		RPDB_Record*		c_record		=	NULL;

		do {
			
			PREPARE_RECORD_FROM_KEY_DATA_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, Qnil, rb_key, rb_data );
			
			RPDB_Database_write(	c_database,
														c_record	);

			//	remaining args are data
		} while ( R_Arg( rb_data ) );
		
	}
	
	return rb_return;
}	

/**********************
*  append  *
**********************/
/*
//	DB_APPEND			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Queue or Recno only
VALUE rb_RPDB_Database_append(	VALUE	rb_database,
																VALUE	append_record	)	{
	RPDB_Database_appendRecord();

}

*/

/*******************************************************************************************************************************************************************************************
																		Key Retrieval
*******************************************************************************************************************************************************************************************/

/***************
*  key_exists  *
*  keys_exist  *
***************/

//	returns if the specified key appears in the database
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_exists.html	
VALUE rb_RPDB_Database_keyExists(	int			argc,
																	VALUE*	args,
																	VALUE		rb_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Type(	R_SYMBOL ) ),
																										R_HashData(	R_Type( R_ANY ) ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchType(		rb_index,		
																											R_SYMBOL ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(		rb_key ) ),
												R_Parameter(	R_MatchArray(			rb_args_array ) ) ),
			R_ListOrder( 4 ),
			":index,  [ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 5 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	VALUE	rb_return	=	Qnil;

	if (				rb_hash_descriptor_index_key_or_keys_array != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key_or_keys_array, 
																					rb_RPDB_Database_keyExists );

	}
	else if (		rb_args_array != Qnil )	{
		
		rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																					rb_RPDB_Database_keyExists  );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		RPDB_Database*		c_database;
		PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_database, c_database, rb_index );

		RPDB_Key*	c_key	=	RPDB_Key_new( NULL );

		VALUE		rb_result				=	Qnil;
		VALUE		rb_return_array	=	rb_ary_new();

		do {
			
			rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_database,
																																					rb_key,
																																					c_key->wrapped_bdb_dbt,
																																					TRUE );

			rb_result	=	( RPDB_Database_keyExists(	c_database,
																							c_key )	?	Qtrue
																											:	Qfalse );

			rb_ary_push(	rb_return_array,
										rb_result );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return = SIMPLIFIED_RUBY_ARRAY( rb_return_array );
	}
	
	return SIMPLIFIED_RUBY_ARRAY( rb_return );
}

/*******************************************************************************************************************************************************************************************
																		Data Retrieval
*******************************************************************************************************************************************************************************************/

/**************************
*  retrieve_data_for_key  *
*  retrieve_for_key       *
*  retrieve               *
**************************/

//	database.retrieve( primary_key )
//	database.retrieve( :index, secondary_key )
//	database.retrieve( :index => secondary_key_in_index )
//	database.retrieve( :index => [ secondary_keys_in_index, ... ] )
//	database.retrieve( [ any args ] )
VALUE rb_RPDB_Database_retrieve(	int			argc, 
																	VALUE*	args,
																	VALUE		rb_database )	{


	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Type(	R_SYMBOL ) ),
																										R_HashData(	R_Type( R_ANY ) ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchType(		rb_index,		
																											R_SYMBOL ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 3 ),
			"key, [ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 4 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	Qnil;
	
	if (		rb_hash_descriptor_index_key_or_keys_array != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key_or_keys_array, 
																					rb_RPDB_Database_retrieve );

		rb_return =	SIMPLIFIED_RUBY_HASH( rb_return );

	}
	else if (		rb_args_array != Qnil )	{

		rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																					rb_RPDB_Database_retrieve  );
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		RPDB_Database*	c_database	=	NULL;
		RPDB_Record*		c_record		=	NULL;

		PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_database, c_database, rb_index );

		rb_return		=	rb_ary_new();

		VALUE	rb_data			=	Qnil;

		do {
			
			PREPARE_RECORD_FROM_KEY_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, rb_index, rb_key );

			c_record	=	RPDB_Database_retrieveRecord(	c_database,
																								c_record );
			
			rb_data = RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );			

			rb_ary_push(	rb_return,
										rb_data );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	SIMPLIFIED_RUBY_ARRAY( rb_return );
		
	}
	
	return rb_return;
}

/******************
*  retrieve_pair  *
*  retrieve_exact *
******************/
	//	FIX - RARGS

//	database.retrieve_pair( primary_key, data )
//	database.retrieve_pair( primary_key => data )
//	database.retrieve_pair( :index, secondary_key, data )
//	database.retrieve_pair( :index, secondary_key => data )
//	database.retrieve_pair( :index => {	secondary_key => data } )
VALUE rb_RPDB_Database_retrievePair(	int			argc, 
																			VALUE*	args,
																			VALUE		rb_database )	{

//	FIX - RARGS
	
	VALUE	rb_key	=	Qnil;
	VALUE	rb_data	=	Qnil;
	PARSE_RUBY_ARGS_FOR_KEY_DATA_HASH_OR_ARRAY( argc, args, rb_database, rb_RPDB_Database_retrievePair, TRUE, rb_key, rb_data );

	RPDB_Database*	c_database	=	NULL;
	RPDB_Record*		c_record		=	NULL;	
	PREPARE_RECORD_FROM_KEY_DATA_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, Qnil, rb_key, rb_data );

	c_record	=	RPDB_Database_retrieveMatchingRecord(	c_database,
																										c_record );

	rb_data	=	RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );

	return rb_data;
}

/************************************
*  retrievePartialKey  *
************************************/
/*
//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPDB_Database_retrievePartialKey(	VALUE	rb_database,
 																			VALUE						partial_key )	{

	//	FIX - RARGS

	RPDB_Database_retrievePartialKey();
	
}
*/
/************************************
*  retrievePartialData  *
************************************/
/*
//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_RPDB_Database_retrievePartialData(	VALUE	rb_database,
 																				VALUE						data )	{

//	FIX - RARGS

	RPDB_Database_retrievePartialData();

}
*/

/**********************************************
*  retrieveMultipleObjectCursorForKey  *
**********************************************/
/*
VALUE rb_RPDB_Database_retrieveMultipleObjectCursor(	VALUE	rb_database,
 																							VALUE					data_object )	{

//	FIX - RARGS
	RPDB_Database_retrieveMultipleObjectCursorForKey();
	
}
*/
/**************************************************
*  retrieveMultipleObjectCursorForPartialKey  *
**************************************************/
/*
VALUE rb_RPDB_Database_retrieveMultipleObjectCursorForPartialKey(	VALUE	rb_database,
 																									VALUE					data_object )	{

//	FIX - RARGS
	RPDB_Database_retrieveMultipleObjectCursorForPartialKey();
	
}
*/
/*******************************************************************************************************************************************************************************************
																		Btree Specific
*******************************************************************************************************************************************************************************************/

/*****************************
*  relativePositionOfKey  *
*****************************/
/*

//	returns an estimate of the proportion of keys that are less than, equal to, and greater than the specified key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_key_range.html
//	Requires Btree
RPDB_KeyRange* RPDB_Database_relativePositionOfKey(	VALUE	rb_database,
																										VALUE	rb_key )	{

//	FIX - RARGS

}
*/
/*******************************************************************************************************************************************************************************************
																		Queue Specific
*******************************************************************************************************************************************************************************************/

/******************
*  shiftQueue  *
******************/
	/*
//	Only relevant for Queue databases
//	DB_CONSUME				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_Database_shiftQueue( VALUE	rb_database )	{

	RPDB_Database_shiftQueue();
	
}
*/
/**************************
*  shiftQueueOrWait  *
**************************/
/*
//	Only relevant for Queue databases
//	DB_CONSUME_WAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_Database_shiftQueueOrWait( VALUE	rb_database )	{
	RPDB_Database_shiftQueueOrWait();

}

*/

/***********
*  verify  *
***********/

//	FIX - flesh out functions

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPDB_Database_verify( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_verify( c_database );

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Data Deletion
*******************************************************************************************************************************************************************************************/

/***************************
*  deleteDataForKey  *
***************************/

VALUE rb_RPDB_Database_delete(	int			argc, 
																VALUE*	args,
																VALUE		rb_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Type(	R_SYMBOL ) ),
																										R_HashData(	R_Type( R_ANY ) ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchType(		rb_index,		
																											R_SYMBOL ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 4 ),
			"key, [ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 5 ),
			"[ <arg> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	rb_database;
	
	if (		rb_hash_descriptor_index_key_or_keys_array != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key_or_keys_array, 
																					rb_RPDB_Database_delete );

	}
	else if (		rb_args_array != Qnil )	{

		rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																					rb_RPDB_Database_retrieve  );
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		RPDB_Database*	c_database	=	NULL;
		PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_database, c_database, rb_index );

		do {
			
			RPDB_Database*	c_database	=	NULL;
			RPDB_Record*		c_record		=	NULL;
			PREPARE_RECORD_FROM_KEY_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, rb_index, rb_key );

			RPDB_Database_deleteRecord(	c_database,
																	c_record );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	SIMPLIFIED_RUBY_ARRAY( rb_return );
		
	}
	
	return rb_return;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/**************************************************
*  setSecondaryKeyCreationCallbackMethodInfoHash  *
**************************************************/

VALUE	rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database,
																																								VALUE	rb_callback_object,
																																								VALUE	rb_callback_method )	{


	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPDB,
																				RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash);
	}
	
	//	Create a new hash for our object and method
	VALUE	rb_new_callback_info	=	rb_hash_new();
	
	//	:object
	rb_hash_aset(	rb_new_callback_info,
								ID2SYM( rb_intern( "object" ) ),
								rb_callback_object );		
	//	:method
	rb_hash_aset(	rb_new_callback_info,
								ID2SYM( rb_intern( "method" ) ),
								rb_callback_method );

	VALUE	rb_secondary_database_id	=	rb_obj_id( rb_secondary_database );

	//	Put the callback info array in the hash by database
	rb_hash_aset(	rb_callbacks_hash,
								rb_secondary_database_id,
								rb_new_callback_info );

	return Qnil;
}

/***************************
*  initRubyRuntimeStorage  *
***************************/

VALUE rb_RPDB_Database_internal_initRubyRuntimeStorage(	VALUE rb_ruby_runtime_storage_database )	{

	RPDB_Database*	c_ruby_runtime_storage_database;
	C_RPDB_DATABASE( rb_ruby_runtime_storage_database, c_ruby_runtime_storage_database );

	RPDB_DatabaseSettingsController*			c_database_settings_controller			=	RPDB_Database_settingsController( c_ruby_runtime_storage_database );
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPDB_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );
	
	//	Set the database type - BTree since we will be searching by pointer and don't want to create a ton of junk records
	RPDB_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );	

	//	Open the database with our settings
	RPDB_Database_internal_openWithoutRuntimeStorage( c_ruby_runtime_storage_database );
	
	return rb_ruby_runtime_storage_database;	
}

/**********************************
*  storeRubyInstanceForCInstance  *
**********************************/

VALUE rb_RPDB_Database_internal_storeRubyRuntimeInstanceForCInstance(	VALUE rb_database )	{

	VALUE						rb_ruby_runtime_database	=	rb_RPDB_internal_rubyRuntimeDatabase( rb_mRPDB );
	RPDB_Database*	c_ruby_runtime_database;
	C_RPDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );

	RPDB_Database*	c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	uintptr_t	c_database_address	=	(uintptr_t) c_database;
	uintptr_t	rb_database_address	=	(uintptr_t) rb_database;
	RPDB_Database_writeRawKeyDataPair(	c_ruby_runtime_database,
																			& c_database_address,
																			sizeof( uintptr_t ),
																			& rb_database_address,
																			sizeof( uintptr_t ) );
	
	return rb_database;
}

/*****************************
*  RubyInstanceForCInstance  *
*****************************/

VALUE rb_RPDB_Database_internal_rubyRuntimeInstanceForCInstance(	void* c_rpdb_instance )	{
	//	we store a reference to our Ruby instance so that we can return the same object to the callback
	//	this is necessary to ensure extended methods, etc, remain
	VALUE						rb_ruby_runtime_database	=	rb_RPDB_internal_rubyRuntimeDatabase( rb_mRPDB );
	RPDB_Database*	c_ruby_runtime_database;
	C_RPDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );
	
	uintptr_t	c_rpdb_instance_address	=	(uintptr_t) c_rpdb_instance;
	
	RPDB_Record*	c_record	=	NULL;
	//	get address of corresponding VALUE
	c_record	=	RPDB_Database_retrieveRawKey(	c_ruby_runtime_database,
																						& c_rpdb_instance_address,
																						sizeof( uintptr_t ) );
	uintptr_t*	rb_database_address	=	RPDB_Record_rawData( c_record );
	VALUE	rb_database	=	(VALUE) *rb_database_address;
	
	RPDB_Record_free( & c_record );
	
	return rb_database;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

//	This is the actual C method that gets called when a callback is set
RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod(	RPDB_Database*			c_secondary_database, 
																																																	RPDB_Record*				c_record, 
																																																	RPDB_SecondaryKeys*	c_secondary_keys )	{
	
	//	get our Ruby instance corresponding to our C instance
	VALUE	rb_secondary_database		=	rb_RPDB_Database_internal_rubyRuntimeInstanceForCInstance(	c_secondary_database );
	
	VALUE	rb_key	=	rb_str_new(	c_record->key->wrapped_bdb_dbt->data,
															c_record->key->wrapped_bdb_dbt->size );
	VALUE	rb_data	=	rb_str_new(	c_record->data->wrapped_bdb_dbt->data,
															c_record->data->wrapped_bdb_dbt->size );
	
	VALUE	rb_database_settings_controller										=	rb_RPDB_Database_settingsController( rb_secondary_database );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_RPDB_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_settings_controller );	
	VALUE	rb_should_serialize_data													=	rb_RPDB_DatabaseRecordReadWriteSettingsController_serializeData( rb_database_record_read_write_settings_controller );
	
	//	if serialization is on, unserialize the key and object
	if ( rb_should_serialize_data == Qtrue )	{
	
		rb_key		=	rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_key );
		rb_data		=	rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_data );
	}

	VALUE	rb_callback_info_hash	=	rb_RPDB_Database_secondaryKeyCreationCallbackMethod(	rb_secondary_database );	
	if ( rb_callback_info_hash == Qnil )	{
		rb_raise( rb_eRuntimeError, "Could not find callback info for secondary database." );
	}
	VALUE	rb_callback_object		=	rb_hash_aref(	rb_callback_info_hash,
																							ID2SYM( rb_intern( "object" ) ) );

	//	Call our ruby callback and translate returns from ruby callback to return to C function	
	VALUE		rb_secondary_keys	=	Qnil;
	
	VALUE	rb_arity	=	rb_funcall(	rb_callback_object,
																rb_intern( "arity" ),
																0 );

	VALUE	rb_args	=	rb_ary_new();

	int	c_arity	=	FIX2INT( rb_arity );
	switch ( c_arity )	{
		
		//	* 3 args gets database, key, data
		//	-1 (*args) and -2 (arg, *args) are the same as 3
		case 3:			
		case -1:
		case -2:
			rb_ary_push(	rb_args,
										rb_secondary_database );
			rb_ary_push(	rb_args,
										rb_key );
			rb_ary_push(	rb_args,
										rb_data );
			break;

		//	* 2 args gets key, data
		case 2:
			rb_ary_push(	rb_args,
										rb_key );
			rb_ary_push(	rb_args,
										rb_data );
			break;

		//	* 1 arg gets data
		case 1:
			rb_ary_push(	rb_args,
										rb_data );
			break;
		
		default:
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );
			break;
	}

	rb_secondary_keys	=	rb_funcall2(	rb_callback_object,
																		rb_intern( "call" ),
																		RARRAY_LEN( rb_args ),
																		RARRAY_PTR( rb_args ) );

	//	if nil, don't index
	if ( rb_secondary_keys == Qnil )	{
		return RPDB_SECONDARY_KEY_CREATION_FAILED_DO_NOT_INDEX;
	}

	return rb_RPDB_Database_internal_processSecondaryKeyReturn(	rb_secondary_database,
																															rb_secondary_keys,
																															c_secondary_keys );	
}

/******************************
*  processSecondaryKeyReturn  *
******************************/

RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																												VALUE									rb_secondary_keys,
																																												RPDB_SecondaryKeys*		c_secondary_keys )	{

	//	If we have an array we need to create our record that holds multiple data items
	if ( TYPE( rb_secondary_keys ) == T_ARRAY )	{
		
		//	for each item, prepare our data; size and data are concatenated each time
		//	we have a function that will prepare individual ruby object for raw data and size
		//	we need to end up with contiguous data and its sum total size in a single record
 		//	so count how many records we have and create an array of pointers to data and size
		int	number_of_keys = 0;
		if ( rb_secondary_keys != Qnil )	{			
			number_of_keys	=	RARRAY_LEN( rb_secondary_keys );
		}
		
		//	when we have multiple keys, each key is a DBT
		//	the array of DBTs are then put in a DBT as data
		//	and size is set to the number of DBT items
		//	and the DBT_MULTIPLE flag is set
		
		DBT*		c_keys	=	calloc( number_of_keys, sizeof( DBT ) );
		
		//	iterate ruby keys in array and store in location in c array
		VALUE		rb_this_key		=	Qnil;
		int	which_key_index		= 0;
		for ( which_key_index = 0 ; which_key_index < number_of_keys ; which_key_index++) {
			
			//	get a name for the current key
			rb_this_key = RARRAY_PTR( rb_secondary_keys )[ which_key_index ];
			
			//	pack the key into the DBT at which_key_index
			rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_secondary_database,
																																					rb_this_key,
																																					& c_keys[ which_key_index ],
																																					TRUE );	
		}
		
		if ( number_of_keys > 1 )	{
		
			//	store the array of keys in the DBT that gets returned to BDB
			c_secondary_keys->wrapped_bdb_dbt->data	=	c_keys;
			c_secondary_keys->wrapped_bdb_dbt->size	=	number_of_keys;

			return RPDB_RECORD_ALLOCATED_BY_APPLICATION_FOR_MULTIPLE_SECONDARY_KEYS;
		}
		else {
			
			c_secondary_keys->wrapped_bdb_dbt->data	=	c_keys[ 0 ].data;
			c_secondary_keys->wrapped_bdb_dbt->size	=	c_keys[ 0 ].size;
			
			free( c_keys );
		}

	}
	//	Otherwise we just prepare our single key in the return record
	else	{
		
		//	prepare our data into record
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_secondary_database,
																																				rb_secondary_keys, 
																																				c_secondary_keys->wrapped_bdb_dbt,
																																				TRUE );
	}

	return FALSE;
}

/*******************************
*  removeCallbackInfoFromHash  *
*******************************/

VALUE rb_RPDB_Database_internal_removeCallbackInfoFromHash(	VALUE	rb_secondary_database )	{
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPDB,
																				RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_secondary_database_id	=	rb_obj_id( rb_secondary_database );
	
	return rb_hash_delete(	rb_callbacks_hash,
													rb_secondary_database_id );
}

/****************
*  storageType  *
****************/

enum ruby_value_type rb_RPDB_Database_internal_storageType( VALUE rb_database )	{
	
	VALUE	rb_database_settings_controller							=	rb_RPDB_Database_settingsController( rb_database );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_RPDB_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_settings_controller );	
	VALUE	rb_class_to_specify_type										=	rb_RPDB_DatabaseRecordReadWriteSettingsController_storageType( rb_database_record_read_write_settings_controller );

	if ( rb_class_to_specify_type == rb_cArray ) {
		return T_ARRAY;
	}
	if ( rb_class_to_specify_type == rb_cHash ) {
		return T_HASH;
	}
	if ( rb_class_to_specify_type == rb_cStruct ) {
		return T_STRUCT;
	}
	if ( rb_class_to_specify_type == rb_cString ) {
		return T_STRING;
	}
	if ( rb_class_to_specify_type == rb_cRegexp ) {
		return T_REGEXP;
	}
	if ( rb_class_to_specify_type == rb_cClass ) {
		return T_CLASS;
	}
	if ( rb_class_to_specify_type == rb_cSymbol ) {
		return T_SYMBOL;
	}
	if ( rb_class_to_specify_type == rb_cBignum ) {
		return T_BIGNUM;
	}
	if ( rb_class_to_specify_type == rb_cFixnum ) {
		return T_FIXNUM;
	}
	if ( rb_class_to_specify_type == rb_cFloat ) {
		return T_FLOAT;
	}
	if ( rb_class_to_specify_type == rb_cTrueClass ) {
		return T_TRUE;
	}
	if ( rb_class_to_specify_type == rb_cFalseClass ) {
		return T_FALSE;
	}
	else {
		return T_STRING;
	}
}

/********************************************
*  packRubyObjectOrValueForDatabaseStorage  *
********************************************/

void rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	VALUE		rb_database,
																																				VALUE		rb_key_or_data,
																																				DBT*		c_key_dbt,
																																				BOOL		c_convert_string_encoding )	{
	
	VALUE	rb_database_settings_controller							=	rb_RPDB_Database_settingsController( rb_database );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_RPDB_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_settings_controller );	
	VALUE	rb_should_serialize_data										=	rb_RPDB_DatabaseRecordReadWriteSettingsController_serializeData( rb_database_record_read_write_settings_controller );
	
	//	if serialization is on, unserialize the key and object
	if ( rb_should_serialize_data == Qtrue )	{
		rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key_or_data,
																																			c_key_dbt,
																																			c_convert_string_encoding );
	}
	else {
		rb_RPDB_Database_internal_packRubyValueForDatabaseStorage(	rb_database,
																																rb_key_or_data,
																																c_key_dbt );
	}
}

/************************************
*  packRubyValueForDatabaseStorage  *
************************************/

void rb_RPDB_Database_internal_packRubyValueForDatabaseStorage(	VALUE		rb_database,
																																VALUE		rb_key_or_data,
																																DBT*		c_key_or_data_dbt )	{
	long*			long_key;
	double*		double_key;
	int*			int_key;
	BOOL*			bool_key;
		
	enum ruby_value_type		c_database_storage_types	=	rb_RPDB_Database_internal_storageType( rb_database );
	
	switch ( c_database_storage_types )	{
						
		case T_ARRAY:
			//	array is treated as multiple individual records for the same key
			
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;

		case T_HASH:
			//	hash is treated as multiple individual records with different keys

			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;

		case T_STRUCT:
			//	each value from struct is stored
			
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;

		case T_FILE:
			//	file contents are stored as byte string
			
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;

		case T_STRING:
			//	simple string
			//	FIX - here and elsewhere, are strdup necessary?
			c_key_or_data_dbt->data		=	strdup( StringValuePtr(	rb_key_or_data ) );
			c_key_or_data_dbt->size		=	RSTRING_LEN( rb_key_or_data ) * sizeof( char );
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_REGEXP:
		case T_CLASS:
			//	store string value
			rb_key_or_data				=	rb_obj_as_string(	rb_key_or_data );
			c_key_or_data_dbt->data		=	strdup( StringValuePtr(	rb_key_or_data ) );
			c_key_or_data_dbt->size		=	RSTRING_LEN( rb_key_or_data ) * sizeof( char );
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_SYMBOL:
			//	store symbol ID
			
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
			
		case T_BIGNUM:
			//	to long
			long_key				=	calloc( 1, sizeof( long ) );
			*long_key				=	NUM2LONG( rb_key_or_data );
			c_key_or_data_dbt->data		=	long_key;
			c_key_or_data_dbt->size		=	sizeof( long );			
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FIXNUM:
			//	to int
			int_key					=	calloc( 1, sizeof( int ) );
			*int_key				=	FIX2INT( rb_key_or_data );
			c_key_or_data_dbt->data		=	int_key;
			c_key_or_data_dbt->size		=	sizeof( int );			
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FLOAT:
			//	to float
			double_key				=	calloc( 1, sizeof( double ) );
			*double_key				=	NUM2DBL( rb_key_or_data );
			c_key_or_data_dbt->data		=	double_key;
			c_key_or_data_dbt->size		=	sizeof( float );			
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_TRUE:
			//	to BOOL
			bool_key				=	calloc( 1, sizeof( BOOL ) );
			*bool_key				=	TRUE;
			c_key_or_data_dbt->data		=	bool_key;
			c_key_or_data_dbt->size		=	sizeof( BOOL );			
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FALSE:
			bool_key				=	calloc( 1, sizeof( BOOL ) );
			*bool_key				=	FALSE;
			c_key_or_data_dbt->data		=	bool_key;
			c_key_or_data_dbt->size		=	sizeof( BOOL );			
			c_key_or_data_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;

		case T_OBJECT:
		case T_MODULE:
		case T_DATA:
		default:			
			//	serialization is turned off, so we don't know how to handle these types			
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
	}
}

/*************************
*  createSecondaryIndex  *
*************************/

VALUE rb_RPDB_Database_internal_createSecondaryIndex(	int			argc,
																											VALUE*	args,
																											VALUE		rb_primary_database_self,
																											BOOL		c_with_duplicates,
																											BOOL		c_with_sorted_duplicates )	{

	VALUE	rb_index								=	Qnil;
	VALUE	rb_secondary_database		=	Qnil;
	
	VALUE	rb_callback_proc				=	Qnil;
	VALUE	rb_callback_object			=	Qnil;
	VALUE	rb_callback_method			=	Qnil;
	
	VALUE	rb_callback_method_name_in_secondary	=	Qnil;
	VALUE	rb_callback_method_name_in_primary		=	Qnil;
	
	//	we always have :index
	//	sometimes we have <secondary database>

	R_DefineAndParse( argc, args, rb_primary_database_self,

		R_DescribeParameterSet(
																								//	:index
			R_ParameterSet(		R_Parameter(						R_MatchSymbol(																						rb_index ) ),
																								//	[ <secondary_database> ]
												R_OptionalParameter(		R_MatchAncestorInstance(																	rb_secondary_database,
																																																					rb_RPDB_Database ) ),
																								//	& block	
												R_Parameter(						R_MatchBlockLambdaWithArity(															rb_callback_proc, 0, 1, 2, 3, -1, -2 ),
																								//	proc
																								R_MatchLambdaWithArity(																		rb_callback_proc, 0, 1, 2, 3, -1, -2 ),
																								//	<method>
																								R_MatchMethod(																						rb_callback_method ),
																								//	:method_in_...
																								R_IfElse(			R_IfValue(	rb_secondary_database,
																																					//	:method_in_secondary
																																					R_MatchStringSymbol(						rb_callback_method_name_in_secondary ) ),
																																					//	:method_in_primary
																															R_Else(			R_MatchStringSymbol(						rb_callback_method_name_in_primary ) ) ),
																								//	{ <callback_object> => :method_in_object }
																								R_Hash(				R_HashKey(	R_MatchAny(											rb_callback_object ) ),
																															R_HashData(	R_MatchStringSymbol(						rb_callback_method ) ) ),
																								//	<callback_object>, :method_in_object
																								R_Group(			R_MatchAny(																	rb_callback_object ),	
																															R_MatchStringSymbol(												rb_callback_method ) ),
																								//	<secondary database configured with callback>
																								//	this is at the end rather than with the secondary_database argument so that it is only tested if we reach the end
																								R_IfElse(			R_IfValue(	rb_secondary_database,
																																					R_ObjectReturnsNonNil(	rb_secondary_database, "secondary_key_creation_callback_method" ) ) ) ) ),
			R_ListOrder( 1 ),
			":index, & block",
			":index, <callback_proc>",
			":index, <callback_method>",
			":index, :callback_method_in_secondary",
			":index, <callback_object>, :callback_method_in_object",
			":index, <callback_object>, 'callback_method_in_object'",
			":index, <callback_object> => 'callback_method_in_object'",
			":index, <callback_object> => :callback_method_in_object",
			":index, <secondary database>, & block",
			":index, <secondary database>, <callback_proc>",
			":index, <secondary database>, <callback_method>",
			":index, <secondary database>, :callback_method_in_secondary",
			":index, <secondary database>, <callback_object>, :callback_method_in_object",
			":index, <secondary database>, <callback_object>, 'callback_method_in_object'",
			":index, <secondary database>, <callback_object> => 'callback_method_in_object'",
			":index, <secondary database>, <callback_object> => :callback_method_in_object"
		)
	);

	RPDB_Database*	c_primary_database		=	NULL;
	C_RPDB_DATABASE( rb_primary_database_self, c_primary_database );
	
	RPDB_Database*	c_secondary_database	=	NULL;
	char*						c_index_name					=	NULL;
	
	//	if it's already set we don't need to set it
	BOOL	should_set_secondary_callback_info	=	TRUE;
	
	//	if we don't have the secondary database yet we need to create it
	if ( rb_secondary_database == Qnil )	{
	
		VALUE	rb_primary_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_primary_database_self );
		
		rb_index = rb_obj_as_string( rb_index );
		c_index_name	=	StringValuePtr( rb_index );
		
		char*	c_primary_database_name					=	RPDB_Database_name( c_primary_database );
		char*	c_secondary_database_name				=	RPDB_Database_internal_secondaryDatabaseNameForIndex( c_index_name,
																																																	c_primary_database_name );
		VALUE	rb_secondary_database_name			=	rb_str_new2( c_secondary_database_name );
		free( c_secondary_database_name );
		rb_secondary_database									=	rb_RPDB_DatabaseController_newDatabase(	rb_primary_database_controller,
																																										rb_secondary_database_name );

		C_RPDB_DATABASE( rb_secondary_database, c_secondary_database );

		//	create secondary database
		RPDB_Database_internal_configureDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																																												c_secondary_database,
																																												c_index_name,
																																												c_with_duplicates,
																																												c_with_sorted_duplicates );

	}
	//	if we have secondary database with callback method already set
	else if (		rb_secondary_database != Qnil
					&&	rb_callback_method_name_in_secondary == Qnil
					&&	rb_callback_object == Qnil
					&&	rb_callback_proc == Qnil )	{
		
		should_set_secondary_callback_info = FALSE;
	}
		
	//	now we have our secondary database - if we still need to set callback info, we do so now
	if ( should_set_secondary_callback_info )	{

		VALUE	rb_args	=	rb_ary_new();

		//	if we have a proc - don't need a method name
		if ( rb_callback_proc != Qnil )	{
			rb_ary_push(	rb_args,
										rb_callback_proc );
		}
		//	method name in primary
		else if ( rb_callback_method_name_in_primary != Qnil )	{
			rb_ary_push(	rb_args,
										rb_primary_database_self );
			rb_ary_push(	rb_args,
										rb_callback_method_name_in_primary );
		}
		//	method in secondary
		else if ( rb_callback_method_name_in_secondary != Qnil )	{
			rb_ary_push(	rb_args,
										rb_secondary_database );
			rb_ary_push(	rb_args,
										rb_callback_method_name_in_secondary );
		}
		//	method in callback object
		else if ( rb_callback_object != Qnil )	{
			rb_ary_push(	rb_args,
										rb_callback_object );
			rb_ary_push(	rb_args,
										rb_callback_method );		
		}
	
		rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod( RARRAY_LEN( rb_args ),
																														RARRAY_PTR( rb_args ),
																														rb_secondary_database );
	}

	//	store reference to secondary database in primary
	//	doesn't need to be weak b/c the secondary will be managed by the primary
	VALUE	rb_secondary_database_hash		=	rb_RPDB_Database_secondaryDatabaseHash( rb_primary_database_self );
	if ( TYPE( rb_index ) == T_STRING )	{
		rb_index = ID2SYM( rb_to_id( rb_index ) );
	}
	rb_hash_aset(	rb_secondary_database_hash,
								rb_index,
								rb_secondary_database );
	
	//	associate secondary as index to primary
	RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																									c_secondary_database,
																									c_index_name,
																									& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Returns primary database so associations can be chained
	return rb_secondary_database;	
}
