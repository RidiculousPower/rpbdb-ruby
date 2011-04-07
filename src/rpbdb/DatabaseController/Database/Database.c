/*
 *		RPbdb::DatabaseController::Database
 *
 *
 */

#include "RPbdb.h"
#include "RPbdb_internal.h"
#include "Database.h"
#include "DatabaseObject_internal.h"
#include "Database_internal.h"
#include "DatabaseController.h"

#include "DatabaseController.h"
#include "Environment.h"

#include "DatabaseCursorController.h"
#include "DatabaseCursor.h"
#include "DatabaseJoinController.h"
#include "DatabaseJoinCursor.h"
#include "DatabaseSequenceController.h"
#include "DatabaseSequence.h"

#include "SettingsController.h"
#include "DatabaseSettingsController.h"

#include "DatabaseRecordReadWriteSettingsController.h"

#include "Types.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>
#include <rpbdb/DatabaseCursor.h>
#include <rpbdb/Database_internal.h>
#include <rpbdb/Data_internal.h>
#include <rpbdb/DatabaseController.h>
#include <rpbdb/DatabaseCursorController.h>
#include <rpbdb/DatabaseJoinController.h>

#include <rpbdb/Record.h>
#include <rpbdb/Key.h>
#include <rpbdb/Data.h>
#include <rpbdb/DBT.h>
#include <rpbdb/DBT_internal.h>
#include <rpbdb/SecondaryKeys.h>

#include <rpbdb/SettingsController.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseRecordSettingsController.h>
#include <rpbdb/DatabaseRecordReadWriteSettingsController.h>
#include <rpbdb/DatabaseRecordReadWriteSettingsController_internal.h>
#include <rpbdb/DatabaseTypeSettingsController.h>

#include <rargs.h>
#include <cerialize.h>
#include <rcerialize.h>

#include <string.h>

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_BtreeDatabase;
extern	VALUE	rb_RPbdb_HashDatabase;
extern	VALUE	rb_RPbdb_QueueDatabase;
extern	VALUE	rb_RPbdb_RecnoDatabase;
extern	VALUE	rb_RPbdb_DatabaseCursor;
extern	VALUE	rb_RPbdb_DatabaseObjectCursor;
extern	VALUE	rb_RPbdb_DatabaseCursorController;
extern	VALUE	rb_RPbdb_DatabaseJoinController;
extern	VALUE	rb_RPbdb_DatabaseSequenceController;

extern	VALUE	rb_RPbdb_Key;
extern	VALUE	rb_RPbdb_Data;
extern	VALUE	rb_RPbdb_SecondaryKeys;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_DatabaseSettingsController;

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

extern VALUE rb_cFileString;

extern VALUE rb_RPbdb_DatabaseType_const_module;
extern VALUE rb_RPbdb_DatabaseBtreeType_const;
extern VALUE rb_RPbdb_DatabaseHashType_const;
extern VALUE rb_RPbdb_DatabaseQueueType_const;
extern VALUE rb_RPbdb_DatabaseRecnoType_const;

#define RPBDB_RUBY_ERROR_INVALID_DATABASE_DATA			"Provided data was invalid. Database requires object that can be automatically converted to string."

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_RPbdb_Database()	{

	rb_RPbdb_Database		=	rb_define_class_under(	rb_mRPbdb, 
																								"Database",
																								rb_cObject );

	rb_RPbdb_DatabaseType_const_module			=	rb_define_module_under(	rb_RPbdb_Database,
																																	"Type" );
																																	
	rb_define_const(						rb_RPbdb_DatabaseType_const_module,		"Btree",						rb_str_new2( "Btree" ) );
	rb_RPbdb_DatabaseBtreeType_const	=	rb_const_get(	rb_RPbdb_DatabaseType_const_module,		rb_intern( "Btree" ) );
	rb_define_const(						rb_RPbdb_DatabaseType_const_module,		"Hash",							rb_str_new2( "Hash" ) );
	rb_RPbdb_DatabaseHashType_const	=	rb_const_get(	rb_RPbdb_DatabaseType_const_module,		rb_intern( "Hash" ) );
	rb_define_const(						rb_RPbdb_DatabaseType_const_module,		"Queue",						rb_str_new2( "Queue" ) );
	rb_RPbdb_DatabaseQueueType_const	=	rb_const_get(	rb_RPbdb_DatabaseType_const_module,		rb_intern( "Queue" ) );
	rb_define_const(						rb_RPbdb_DatabaseType_const_module,		"Recno",						rb_str_new2( "Recno" ) );
	rb_RPbdb_DatabaseRecnoType_const	=	rb_const_get(	rb_RPbdb_DatabaseType_const_module,		rb_intern( "Recno" ) );

	rb_define_singleton_method(	rb_RPbdb_Database, 	"new",																					rb_RPbdb_Database_new,																				-1 	);
	rb_define_method(						rb_RPbdb_Database, 	"initialize",																		rb_RPbdb_Database_initialize,																			-1 	);

	rb_define_singleton_method(	rb_RPbdb_Database, 	"use",																					rb_RPbdb_Database_use,																				-1 	);

	rb_define_method(						rb_RPbdb_Database, 	"settings_controller",													rb_RPbdb_Database_settingsController,												0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"settings",																			"settings_controller"	);                            				
	rb_define_alias(						rb_RPbdb_Database, 	"set",																					"settings_controller"	);                            				
	rb_define_alias(						rb_RPbdb_Database, 	"set_to",																				"settings_controller"	);                            				
	rb_define_alias(						rb_RPbdb_Database, 	"is_set_to",																		"settings_controller"	);                            				
	rb_define_method(						rb_RPbdb_Database, 	"parent_environment",														rb_RPbdb_Database_parentEnvironment,													0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"parent_environment",														"parent_environment"	);                            				
	rb_define_alias(						rb_RPbdb_Database, 	"environment",																	"parent_environment"	);                            				

	rb_define_method(						rb_RPbdb_Database, 	"filename",																			rb_RPbdb_Database_filename,																	0 	);
	rb_define_method(						rb_RPbdb_Database, 	"name",																					rb_RPbdb_Database_name,																			0 	);
	rb_define_method(						rb_RPbdb_Database, 	"rename",																				rb_RPbdb_Database_rename,																		1 	);
	rb_define_method(						rb_RPbdb_Database, 	"handle",																				rb_RPbdb_Database_handle,																		0 	);

	rb_define_method(						rb_RPbdb_Database, 	"open",																					rb_RPbdb_Database_open,																			0 	);
	rb_define_method(						rb_RPbdb_Database, 	"is_open?",																			rb_RPbdb_Database_isOpen,																		0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"open?",																				"is_open?"	);                                        				
	rb_define_method(						rb_RPbdb_Database, 	"close",																				rb_RPbdb_Database_close,																			0 	);
	rb_define_method(						rb_RPbdb_Database, 	"empty!",																				rb_RPbdb_Database_empty,																			0 	);
	rb_define_method(						rb_RPbdb_Database, 	"erase!",																				rb_RPbdb_Database_erase,																			0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"delete!",																			"erase!"	);                            				
	rb_define_method(						rb_RPbdb_Database, 	"sync!",																				rb_RPbdb_Database_sync,																			0 	);

	rb_define_method(						rb_RPbdb_Database, 	"has_key?",                                     rb_RPbdb_Database_keyExists,																	-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"key_exists?",																	"has_key?" );                                    				
	rb_define_alias(						rb_RPbdb_Database, 	"exists?",																			"has_key?" );                                    				
	rb_define_method(						rb_RPbdb_Database, 	"all_keys_exist?",															rb_RPbdb_Database_keysExist,																	-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"keys_exist?",																	"all_keys_exist?" );                                    				
	rb_define_method(						rb_RPbdb_Database, 	"write",																				rb_RPbdb_Database_write,																			-1 	);
	rb_define_method(						rb_RPbdb_Database, 	"retrieve",																			rb_RPbdb_Database_retrieve,																	-1 	);
	rb_define_method(						rb_RPbdb_Database, 	"retrieve_primary_key",													rb_RPbdb_Database_retrievePrimaryKey,												-1 	);
	rb_define_method(						rb_RPbdb_Database, 	"delete",																				rb_RPbdb_Database_delete,																		-1 	);
                    					                                                                                                                        				
	rb_define_method(						rb_RPbdb_Database, 	"is_secondary_database?",												rb_RPbdb_Database_isSecondary,																0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"is_secondary_index?",													"is_secondary_database?"	);
	rb_define_alias(						rb_RPbdb_Database, 	"is_secondary?",																"is_secondary_database?"	);
	rb_define_alias(						rb_RPbdb_Database, 	"secondary_database?",													"is_secondary_database?"	);
	rb_define_alias(						rb_RPbdb_Database, 	"secondary_index?",															"is_secondary_database?"	);
	rb_define_alias(						rb_RPbdb_Database, 	"secondary?",																		"is_secondary_database?"	);
	rb_define_method(						rb_RPbdb_Database, 	"primary_database",															rb_RPbdb_Database_primaryDatabase,																0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"primary",																			"primary_database"	);
	rb_define_method(						rb_RPbdb_Database, 	"secondary_key_creation_callback_method",				rb_RPbdb_Database_secondaryKeyCreationCallbackMethod,				0 	);
	rb_define_method(						rb_RPbdb_Database, 	"create_secondary_index",												rb_RPbdb_Database_createSecondaryIndex,											-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_secondary_index",													"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_index",																		"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"create_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"new_secondary",																"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"new_index",																		"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"associate_secondary_database",									"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"associate_secondary",													"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"associate",																		"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"use_as_secondary_index",												"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"use_as_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"create_secondary_index_with_database",					"create_secondary_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"create_secondary_with_database",								"create_secondary_index"	);
	rb_define_method(						rb_RPbdb_Database, 	"create_secondary_index_with_unsorted_duplicates",	rb_RPbdb_Database_createSecondaryIndexWithUnsortedDuplicates,											-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_secondary_index_with_unsorted_duplicates",     "create_secondary_index_with_unsorted_duplicates"	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_index_with_unsorted_duplicates",								"create_secondary_index_with_unsorted_duplicates"	);
	rb_define_method(						rb_RPbdb_Database, 	"create_secondary_index_with_sorted_duplicates",	rb_RPbdb_Database_createSecondaryIndexWithSortedDuplicates,											-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_secondary_index_with_sorted_duplicates",				"create_secondary_index_with_sorted_duplicates"	);
	rb_define_alias(						rb_RPbdb_Database, 	"has_index_with_sorted_duplicates",								"create_secondary_index_with_sorted_duplicates"	);
	rb_define_method(						rb_RPbdb_Database, 	"set_unique_for_index",													rb_RPbdb_Database_setUniqueForIndex,											-1 	);
	rb_define_method(						rb_RPbdb_Database, 	"unique_for_index",															rb_RPbdb_Database_uniqueForIndex,												-1 	);


	rb_define_method(						rb_RPbdb_Database, 	"secondary_database_with_index",								rb_RPbdb_Database_secondaryDatabaseWithIndex,								1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"database_with_index",													"secondary_database_with_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"secondary_database",														"secondary_database_with_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"secondary",																		"secondary_database_with_index"	);
	rb_define_alias(						rb_RPbdb_Database, 	"index",																				"secondary_database_with_index"	);
                    					
	rb_define_method(						rb_RPbdb_Database, 	"verify",																				rb_RPbdb_Database_verify,																		0 	);

	rb_define_method(						rb_RPbdb_Database, 	"cursor_controller",														rb_RPbdb_Database_cursorController,													0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"cursors",																			"cursor_controller"	);
	rb_define_method(						rb_RPbdb_Database, 	"cursor",																				rb_RPbdb_Database_cursor,																		0 	);

	rb_define_method(						rb_RPbdb_Database, 	"iterate",																			rb_RPbdb_Database_iterate,																		0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"each",																					"iterate"	);
	rb_define_method(						rb_RPbdb_Database, 	"iterate_duplicates",														rb_RPbdb_Database_iterateDuplicates,													0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"each_duplicate",																"iterate_duplicates"	);
	rb_define_method(						rb_RPbdb_Database, 	"iterate_keys",																	rb_RPbdb_Database_iterateKeys,																0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"each_key",																			"iterate_keys"	);

	rb_define_method(						rb_RPbdb_Database, 	"sequence_controller",													rb_RPbdb_Database_sequenceController,													-1 	);
	rb_define_alias(						rb_RPbdb_Database, 	"sequences",																		"sequence_controller"	);
	rb_define_alias(						rb_RPbdb_Database, 	"sequence",																			"sequence_controller"	);

	rb_define_method(						rb_RPbdb_Database, 	"join_controller",															rb_RPbdb_Database_joinController,													0 	);
	rb_define_alias(						rb_RPbdb_Database, 	"joins",																				"join_controller"	);
	rb_define_alias(						rb_RPbdb_Database, 	"join",																					"join_controller"	);

	rb_RPbdb_BtreeDatabase		=	rb_define_class_under(		rb_RPbdb_Database, 
																											"Btree",
																											rb_RPbdb_Database );
	rb_define_singleton_method(	rb_RPbdb_BtreeDatabase, 	"new",																					rb_RPbdb_Database_new,																					-1 	);
	rb_define_method(						rb_RPbdb_BtreeDatabase, 	"initialize",																		rb_RPbdb_Database_initialize,																	-1 	);

	rb_RPbdb_HashDatabase		=	rb_define_class_under(		rb_RPbdb_Database, 
																											"Hash",
																											rb_RPbdb_Database );
	rb_define_singleton_method(	rb_RPbdb_HashDatabase, 	"new",																					rb_RPbdb_Database_new,																					-1 	);
	rb_define_method(						rb_RPbdb_HashDatabase, 	"initialize",																		rb_RPbdb_Database_initialize,																	-1 	);

	rb_RPbdb_RecnoDatabase		=	rb_define_class_under(		rb_RPbdb_Database, 
																											"Recno",
																											rb_RPbdb_Database );
	rb_define_singleton_method(	rb_RPbdb_RecnoDatabase, 	"new",																					rb_RPbdb_Database_new,																					-1 	);
	rb_define_method(						rb_RPbdb_RecnoDatabase, 	"initialize",																		rb_RPbdb_Database_initialize,																	-1 	);

	rb_RPbdb_QueueDatabase		=	rb_define_class_under(		rb_RPbdb_Database, 
																											"Queue",
																											rb_RPbdb_Database );
	rb_define_singleton_method(	rb_RPbdb_QueueDatabase, 	"new",																					rb_RPbdb_Database_new,																					-1 	);
	rb_define_method(						rb_RPbdb_QueueDatabase, 	"initialize",																		rb_RPbdb_Database_initialize,																	-1 	);

  //  Foreign support for Rcerialize (temporary)
  //  Class permits recovery of files for secondary keys
	rb_cFileString		=	rb_define_class_under(		rb_cFile, 
                                                "String",
                                                rb_cString );

}

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_RPbdb_Database_new(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self )	{

	VALUE	rb_database_name							=	Qnil;
	VALUE	rb_parent_database_controller	=	Qnil;
	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_environment_path		=	Qnil;
	VALUE	rb_database_type							=	Qnil;

	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(
				R_Parameter(					R_MatchStringSymbol(							rb_database_name )				
				),
				R_OptionalParameter(	R_MatchAncestorInstance(					rb_parent_environment,							rb_RPbdb_Environment ),
															R_MatchAncestorInstance(					rb_parent_database_controller,			rb_RPbdb_DatabaseController ),
															R_MatchString(										rb_parent_environment_path ),
															R_MatchSymbol(										rb_database_type )
				),
				R_OptionalParameter(	R_IfElse( R_IfValueEquals(				rb_database_type,										Qnil,
																				R_MatchSymbol(					rb_database_type ) ) )
				)
			),
			1,
			"<database name>",
			"<database name>, <environment>",
			"<database name>, <database controller>",
			"<database name>, <environment>, <database type>",
			"<database name>, <database controller>, <database type>"
		),
		R_DescribeParameterSet(
			R_ParameterSet(
				R_Parameter(					R_MatchAncestorInstance(					rb_parent_environment,							rb_RPbdb_Environment ),
															R_MatchAncestorInstance(					rb_parent_database_controller,			rb_RPbdb_DatabaseController ),
															R_MatchString(										rb_parent_environment_path ),
															R_MatchSymbol(										rb_database_type )
				),
				R_Parameter(					R_MatchStringSymbol(							rb_database_name )				
				),
				R_OptionalParameter(	R_IfElse( R_IfValueEquals(				rb_database_type,										Qnil,
																				R_MatchSymbol(					rb_database_type ) ) )
				)
			),
			2,
			"<environment>, <database name>",
			"<database controller>, <database name>",
			"<environment>, <database name>, <database type>",
			"<database controller>, <database name>, <database type>"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_environment_path == Qnil )	{
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if ( rb_parent_environment_path != Qnil )	{
		rb_parent_environment	=	rb_RPbdb_Environment_new(	1,
																											& rb_parent_environment_path,
																											rb_RPbdb_Environment );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_database_controller = rb_RPbdb_Environment_databaseController( rb_parent_environment );
	}
	
	RPbdb_DatabaseController*	c_parent_database_controller;
	char*	c_database_name		=	NULL;
	if ( rb_database_name != Qnil )	{
		rb_database_name	=	rb_obj_as_string( rb_database_name );
		c_database_name	=	StringValuePtr( rb_database_name );
	}
	else {
		rb_raise( rb_eArgError, "Database name is required to be non-nil." );
	}

	C_RPBDB_DATABASE_CONTROLLER( rb_parent_database_controller, c_parent_database_controller );
	
	RPbdb_Database*	c_database	=	RPbdb_DatabaseController_newDatabase(	c_parent_database_controller,
																																			c_database_name );
	
	RPbdb_DatabaseSettingsController*			c_database_settings_controller				=	RPbdb_Database_settingsController( c_database );
	RPbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller		=	RPbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	DBTYPE	c_database_type	=	DB_UNKNOWN;

	if ( rb_database_type != Qnil )	{
		
		if ( TYPE( rb_database_type ) != T_STRING )	{
			rb_database_type = rb_obj_as_string( rb_database_type );
		}
		char*	c_database_type_string	=	StringValuePtr( rb_database_type );

		if (			strcmp( c_database_type_string, "Btree" ) == 0 )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
			c_database_type	=	DB_BTREE;
		}
		else if ( strcmp( c_database_type_string, "Hash" ) == 0 )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
			c_database_type	=	DB_HASH;
		}
		else if ( strcmp( c_database_type_string, "Queue" ) == 0 )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
			c_database_type	=	DB_QUEUE;
		}
		else if ( strcmp( c_database_type_string, "Recno" ) == 0 )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
			c_database_type	=	DB_RECNO;
		}
	}
	else if ( rb_klass_self != rb_RPbdb_Database )	{
		
		if (			rb_klass_self == rb_RPbdb_BtreeDatabase )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
			c_database_type	=	DB_BTREE;
		}
		else if (	rb_klass_self == rb_RPbdb_HashDatabase )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
			c_database_type	=	DB_HASH;
		}
		else if (	rb_klass_self == rb_RPbdb_QueueDatabase )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
			c_database_type	=	DB_QUEUE;
		}
		else if (	rb_klass_self == rb_RPbdb_RecnoDatabase )	{
			RPbdb_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
			c_database_type	=	DB_RECNO;
		}
		else {
			c_database_type	=	DB_UNKNOWN;
		}

	}
	else {
		c_database_type	=	RPbdb_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller );
	}

	VALUE	rb_database	=	Qnil;
	switch ( c_database_type )	{
		
		case DB_BTREE:
			rb_database	=	RUBY_RPBDB_BTREE_DATABASE( c_database );
			break;
			
		case DB_HASH:
			rb_database	=	RUBY_RPBDB_HASH_DATABASE( c_database );
			break;

		case DB_QUEUE:
			rb_database	=	RUBY_RPBDB_QUEUE_DATABASE( c_database );
			break;

		case DB_RECNO:
			rb_database	=	RUBY_RPBDB_RECNO_DATABASE( c_database );
			break;

		default:
			rb_raise( rb_eArgError, "Unknown database type." );
			break;
		
	}

	//	store reference to parent
	rb_iv_set(	rb_database,
							RPBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER,
							rb_parent_database_controller );
	
	//	store reference to ruby instance by c instance
	rb_RPbdb_Database_internal_storeRubyRuntimeInstanceForCInstance( rb_database );

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
VALUE rb_RPbdb_Database_initialize(	int			argc __attribute__((unused)),
																		VALUE*	args __attribute__((unused)),
																		VALUE		rb_database_self )	{
		
	return rb_database_self;
}

/********
*  use  *
********/

VALUE rb_RPbdb_Database_use(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self )	{
	
	VALUE	rb_database	=	rb_RPbdb_Database_new(	argc,
																						args,
																						rb_klass_self );
	
	//	returns non-db value if block is run in open
	rb_database = rb_RPbdb_Database_open( rb_database );
	
	return rb_database;
}

/************************
*  settings_controller  *
*  settings             *
************************/
VALUE rb_RPbdb_Database_settingsController( VALUE	rb_database )	{

	VALUE	rb_local_database_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_settings_controller = rb_iv_get(	rb_database,
																														RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_local_database_settings_controller	=	rb_RPbdb_DatabaseSettingsController_new(	1,
																																										& rb_database,
																																										rb_RPbdb_DatabaseSettingsController );
		rb_iv_set(	rb_database,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER,
								rb_local_database_settings_controller );
	}

	return rb_local_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_RPbdb_Database_parentEnvironment(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_RPbdb_Database_parentDatabaseController( rb_database );
	VALUE	rb_parent_environment					=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/*******************************
*  parent_database_controller  *
*  database_controller         *
*  controller                  *
*******************************/

VALUE rb_RPbdb_Database_parentDatabaseController(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_iv_get(	rb_database,
																										RPBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER );

	return rb_parent_database_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/**********************
*  cursor_controller  *
**********************/

VALUE rb_RPbdb_Database_cursorController( VALUE	rb_database )	{

	VALUE	rb_cursor_controller	=	Qnil;
	
	if ( ( rb_cursor_controller = rb_iv_get(	rb_database,
																						RPBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Database*		c_database;
		C_RPBDB_DATABASE( rb_database, c_database );

		rb_cursor_controller	=	rb_RPbdb_DatabaseCursorController_new(	1,
																																	& rb_database,
																																	rb_RPbdb_DatabaseCursorController );

		rb_iv_set(	rb_database,
								RPBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER,
								rb_cursor_controller );
	}

	return rb_cursor_controller;
}

/********************
*  join_controller  *
********************/

VALUE rb_RPbdb_Database_joinController( VALUE	rb_database )	{
	
	VALUE	rb_join_controller	=	Qnil;
	
	if ( ( rb_join_controller = rb_iv_get(	rb_database,
																					RPBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Database*		c_database;
		C_RPBDB_DATABASE( rb_database, c_database );
	
		rb_join_controller	=	rb_RPbdb_DatabaseJoinController_new(	1,
																															& rb_database,
																															rb_RPbdb_DatabaseJoinController );

		rb_iv_set(	rb_database,
								RPBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER,
								rb_join_controller );
	}

	return rb_join_controller;
}

/************************
*  sequence_controller  *
************************/

VALUE rb_RPbdb_Database_sequenceController(	int			argc,
																						VALUE*	args,
																						VALUE		rb_database )	{
	
	VALUE	rb_sequence_name	=	Qnil;
	R_DefineAndParse( argc, args, rb_database,
		R_DescribeParameterSet(
			R_ParameterSet(
				R_OptionalParameter(	R_MatchStringSymbol( rb_sequence_name ) )
			),
			1,
			"<no args>",
			"<:sequence name>",
			"<'sequence name'>"
		)
	)
	
	VALUE	rb_sequence_controller	=	Qnil;
	
	if ( ( rb_sequence_controller = rb_iv_get(	rb_database,
																							RPBDB_RB_DATABASE_SEQUENCE_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Database*		c_database;
		C_RPBDB_DATABASE( rb_database, c_database );
	
		rb_sequence_controller	=	rb_RPbdb_DatabaseSequenceController_new(	1,
																																			& rb_database,
																																			rb_RPbdb_DatabaseSequenceController );

		rb_iv_set(	rb_database,
								RPBDB_RB_DATABASE_SEQUENCE_CONTROLLER,
								rb_sequence_controller );
	}

	//	if a sequence was specified, return it instead of the controller
	if ( rb_sequence_name != Qnil )	{
		return rb_RPbdb_DatabaseSequenceController_sequence(	rb_sequence_controller,
																												rb_sequence_name );
	}

	return rb_sequence_controller;
}


/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************
*  filename  *
*************/

VALUE rb_RPbdb_Database_filename( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	return rb_str_new2( RPbdb_Database_filename( c_database ) );	
}

/*********
*  name  *
*********/

VALUE rb_RPbdb_Database_name( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	char*	c_database_name		=	RPbdb_Database_name( c_database );
	VALUE	rb_database_name	=	rb_str_new2( c_database_name );

	return rb_database_name;	
}

/***********
*  rename  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_rename.html
VALUE rb_RPbdb_Database_rename(	VALUE	rb_database,
																VALUE	rb_name	)	{
	
	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	rb_name	=	rb_obj_as_string( rb_name );

	char*	c_name	=	StringValuePtr( rb_name );

	RPbdb_Database_rename(	c_database,
												c_name );
						
	return rb_database;
}

/***********
*  handle  *
***********/

VALUE rb_RPbdb_Database_handle( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	VALUE	rb_database_name		=	rb_RPbdb_Database_name( rb_database );
	VALUE	rb_database_handle	=	STRING2SYM( rb_database_name );

	return rb_database_handle;	
}

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPbdb_Database_open( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	BOOL	c_should_close_database	=	TRUE;

	if ( RPbdb_Database_isOpen( c_database ) )	{
		c_should_close_database	=	FALSE;
	}
	else {
		RPbdb_Database_open( c_database );
	}

	if ( rb_block_given_p() )	{

		VALUE	rb_return	=	rb_yield( rb_database );

		if ( c_should_close_database )	{
			rb_RPbdb_Database_close( rb_database );
		}

		return rb_return;
	}

	return rb_database;
}

/*************
*  is_open?  *
*************/

VALUE rb_RPbdb_Database_isOpen( VALUE	rb_database )	{
	
	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );
	
	if ( RPbdb_Database_isOpen( c_database ) )	{
		return Qtrue;
	}
	
	return Qfalse;
}

/**********
*  close  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPbdb_Database_close( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	rb_RPbdb_Database_internal_removeCallbackInfoFromHash( rb_database );
	
	RPbdb_Database_close( c_database );

  if ( rb_RPbdb_Database_isSecondary( rb_database ) == Qtrue )  {
    rb_RPbdb_Database_internal_removeSecondaryDatabaseFromHash( rb_database );
  }
  
	return rb_database;
}

/***********
*  empty!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_truncate.html
VALUE rb_RPbdb_Database_empty( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	RPbdb_Database_empty( c_database );

	return rb_database;
}

/***********
*  erase!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_remove.html
VALUE rb_RPbdb_Database_erase( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	RPbdb_Database_erase( c_database );

	return rb_database;
}

/*********
*  copy  *
*********/

//	Duplicate in Same Environment (requires resetIDs)
	/*
VALUE rb_RPbdb_Database_copy( VALUE	rb_database )	{
	RPbdb_Database_copy();

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
VALUE rb_RPbdb_Database_copyToForeignEnvironment( VALUE	rb_database )	{
	RPbdb_Database_copyToForeignEnvironment();

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
VALUE rb_RPbdb_Database_sync( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	RPbdb_Database_sync( c_database );

	return rb_database;	
}

/******************
*  is_secondary?  *
******************/

VALUE rb_RPbdb_Database_isSecondary(	VALUE	rb_database )	{
	
	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	BOOL	c_is_secondary	=	RPbdb_Database_isSecondary( c_database );
	
	VALUE	rb_is_secondary	=	c_is_secondary ? Qtrue : Qfalse;

	return rb_is_secondary;
}

/*********************
*  primary_database  *
*********************/

VALUE rb_RPbdb_Database_primaryDatabase(	VALUE	rb_primary_or_secondary_database )	{
	
	RPbdb_Database*		c_primary_or_secondary_database;
	C_RPBDB_DATABASE( rb_primary_or_secondary_database, c_primary_or_secondary_database );
	
	if ( RPbdb_Database_isSecondary( c_primary_or_secondary_database ) == FALSE )	{
		return rb_primary_or_secondary_database;
	}
	
	RPbdb_Database*		c_primary_database	=	NULL;
	c_primary_database	=	RPbdb_Database_primaryDatabase( c_primary_or_secondary_database );
	
	VALUE	rb_primary_database	=	Qnil;
	if ( c_primary_database != NULL )	{
		rb_primary_database	=	rb_RPbdb_Database_internal_rubyRuntimeInstanceForCInstance( c_primary_database );
	}

	return rb_primary_database;
}

/*************************
*  secondary_index_name  *
*************************/

//	primary returns nil
VALUE rb_RPbdb_Database_secondaryIndexName(	VALUE	rb_secondary_database )	{
	
	VALUE	rb_index	=	Qnil;
	if ( rb_RPbdb_Database_isSecondary( rb_secondary_database ) )	{
		RPbdb_Database*		c_secondary_database;
		C_RPBDB_DATABASE( rb_secondary_database, c_secondary_database );
		rb_index	=	ID2SYM( rb_intern( c_secondary_database->index_name ) );
	}
	return rb_index;
}

/*******************************************
*  secondary_key_creation_callback_method  *
*******************************************/

VALUE rb_RPbdb_Database_secondaryKeyCreationCallbackMethod(	int			argc,
																														VALUE*	args,
																														VALUE		rb_primary_or_secondary_database )	{
	
	VALUE	rb_index	=	Qnil;
	R_DefineAndParse( argc, args, rb_primary_or_secondary_database,
		R_DescribeParameterSet(
			R_ParameterSet(			R_OptionalParameter(		R_MatchStringSymbol( rb_index )	) ),
			1,
			"<no args>",
			":index",
			"'index'"
		)
	)
	
	VALUE	rb_primary_database	=	Qnil;
	if ( rb_RPbdb_Database_isSecondary( rb_primary_or_secondary_database ) == Qtrue )	{
		rb_primary_database	=	rb_RPbdb_Database_primaryDatabase( rb_primary_or_secondary_database );
		rb_index						=	rb_RPbdb_Database_secondaryIndexName( rb_primary_or_secondary_database );
	}
	else {
		rb_primary_database	=	rb_primary_or_secondary_database;
	}
	
	if ( rb_index == Qnil )	{
		rb_raise( rb_eArgError, "Could not determine index name for secondary database." );
	}
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPbdb,
																				RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_primary_database_handle	=	rb_RPbdb_Database_handle( rb_primary_database );	
	VALUE	rb_database_callbacks	=	rb_hash_aref(	rb_callbacks_hash,
																							rb_primary_database_handle );
	if ( rb_database_callbacks == Qnil )	{
		rb_database_callbacks = rb_hash_new();
		rb_hash_aset(	rb_callbacks_hash,
									rb_primary_database_handle,
									rb_database_callbacks );
	}
	
	VALUE	rb_callback_object	=	rb_hash_aref(	rb_database_callbacks,
																						rb_index );
																						
	return rb_callback_object;
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
VALUE rb_RPbdb_Database_createSecondaryIndex(	int			argc, 
																							VALUE*	args,
																							VALUE		rb_primary_database_self	)	{

	return rb_RPbdb_Database_internal_createSecondaryIndex(	argc,
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
VALUE rb_RPbdb_Database_createSecondaryIndexWithUnsortedDuplicates(	int			argc, 
																														VALUE*	args,
																														VALUE		rb_primary_database_self	)	{

	return rb_RPbdb_Database_internal_createSecondaryIndex(	argc,
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
VALUE rb_RPbdb_Database_createSecondaryIndexWithSortedDuplicates(	int			argc, 
																																	VALUE*	args,
																																	VALUE		rb_primary_database_self	)	{

	return rb_RPbdb_Database_internal_createSecondaryIndex(	argc,
																													args,
																													rb_primary_database_self,
																													TRUE,
																													TRUE );

}

/************************
*  database_with_index  *
************************/

VALUE rb_RPbdb_Database_databaseWithIndex(	VALUE	rb_primary_database,
																					VALUE	rb_index_name )	{
	
	VALUE	rb_which_database	=	Qnil;																																			
	if ( rb_index_name != Qnil )	{																																						
		rb_which_database	=	rb_RPbdb_Database_requireSecondaryDatabaseWithIndex(	rb_primary_database,			
																																						rb_index_name );								
	}																																																		
	else {																																															
		rb_which_database	=	rb_primary_database;																													
	}																																																		

	return rb_which_database;
}

/**********************************
*  secondary_database_with_index  *
**********************************/

VALUE rb_RPbdb_Database_secondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																										VALUE	rb_index_name )	{
	
	//	make sure that store/retrieve by symbol
	if ( TYPE( rb_index_name ) == T_STRING )	{
		rb_index_name	=	STRING2SYM( rb_index_name );
	}
	
	VALUE	rb_secondary_database_hash	=	rb_RPbdb_Database_secondaryDatabaseHash( rb_primary_database );
	
	VALUE	rb_database_with_index			=	rb_hash_aref(	rb_secondary_database_hash,
																										rb_index_name );
																									
	return rb_database_with_index;
}

/******************************************
*  require_secondary_database_with_index  *
******************************************/

VALUE rb_RPbdb_Database_requireSecondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																													VALUE	rb_index_name )	{
	
	VALUE	rb_database_with_index				=	rb_RPbdb_Database_secondaryDatabaseWithIndex(	rb_primary_database,
																																											rb_index_name );

	if ( rb_database_with_index == Qnil )	{
		rb_raise( rb_eArgError, "Requested secondary index %s was missing for database %s.",	RSTRING_PTR( rb_obj_as_string( rb_index_name ) ),
																																													RSTRING_PTR( rb_RPbdb_Database_name( rb_primary_database ) ) );
	}
	return rb_database_with_index;
}

/****************************
*  secondary_database_hash  *
****************************/

VALUE rb_RPbdb_Database_secondaryDatabaseHash( VALUE rb_primary_database )	{
	
	VALUE	rb_secondary_database_hash	=	rb_iv_get(	rb_primary_database,
																									RPBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES );
	if ( rb_secondary_database_hash == Qnil )	{
		rb_secondary_database_hash = rb_hash_new();
		rb_iv_set(	rb_primary_database,
								RPBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES,
								rb_secondary_database_hash );
	}
	return rb_secondary_database_hash;
}

/************
*  compact  *
************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
VALUE rb_RPbdb_Database_compact(	VALUE	rb_database, 
									VALUE	start_record, 
									VALUE	stop_record )	{
	RPbdb_Database_compact();


}

VALUE rb_RPbdb_Database_compactAllRecords( VALUE	rb_database )	{
	RPbdb_Database_compactAllRecords();


}
*/

/************
*  upgrade  *
************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_upgrade.html
VALUE rb_RPbdb_Database_upgrade( VALUE	rb_database )	{
	RPbdb_Database_upgrade();

}
*/

/***********************
*  reset_database_ids  *
***********************/
/*
//	For copying database and using duplicate in same environment 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
VALUE rb_RPbdb_Database_resetDatabaseIDs( VALUE	rb_database )	{
	RPbdb_Database_resetDatabaseIDs();

}
*/

/***************************************
*  prepare_database_for_file_transfer  *
***************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_lsn_reset.html
VALUE rb_RPbdb_Database_prepareDatabaseForFileTransfer( VALUE	rb_database )	{
	RPbdb_Database_prepareDatabaseForFileTransfer();
	
}
*/

/**********************
*  unique_for_index?  *
**********************/

VALUE rb_RPbdb_Database_uniqueForIndex(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database )	{

	VALUE	rb_index	=	Qnil;
	R_DefineAndParse( argc, args, rb_database,
		R_DescribeParameterSet(		
			R_ParameterSet(				R_Parameter(		R_MatchStringSymbol( rb_index ) ) ),
			1,
			":index",
			"'index'" 
		)
	)

	VALUE	rb_index_is_unique	=	Qfalse;

	//	* create ruby array from args minus rb_index
	
	//	first, check to see if any provided index does not have duplicates; if so, it can be considered unique
	int		c_which_index;
	for ( c_which_index = 0 ; c_which_index < argc ; c_which_index++ )	{
		
		VALUE	rb_this_index	=	args[ c_which_index ];
		
		//	if database returns only one entry for this request
		VALUE																							rb_database_for_index												=	rb_RPbdb_Database_secondaryDatabaseWithIndex(	rb_database,
																																																																									rb_this_index );
		RPbdb_Database*																		c_database_for_index;
		C_RPBDB_DATABASE( rb_database_for_index, c_database_for_index );
		
		RPbdb_DatabaseSettingsController*									c_database_settings_controller							=	RPbdb_Database_settingsController( c_database_for_index );
		RPbdb_DatabaseRecordSettingsController*						c_database_record_settings_controller				=	RPbdb_DatabaseSettingsController_recordSettingsController( c_database_settings_controller );
		RPbdb_DatabaseRecordReadWriteSettingsController*		c_database_read_write_settings_controller		=	RPbdb_DatabaseRecordSettingsController_readWriteSettingsController( c_database_record_settings_controller );
		BOOL	c_database_has_duplicates	=	RPbdb_DatabaseRecordReadWriteSettingsController_duplicates( c_database_read_write_settings_controller );
		if ( ! c_database_has_duplicates )	{
			rb_index_is_unique = Qtrue;
			break;
		}
	
	}	

	//	if we don't already have a unique index then we need to check for index combinations declared unique
	if ( rb_index_is_unique != Qtrue ) {
		
		VALUE	rb_unique_indexes_for_database	=	rb_RPbdb_Database_internal_uniqueIndexesHash( rb_database );	

		//	* first arg is used as index for lookup (already in rb_index)		
		//	* lookup unique index combinations for index
		VALUE	rb_unique_index_combinations	=	rb_hash_aref(	rb_unique_indexes_for_database,
																												rb_index );
		
		VALUE	rb_indexes	=	rb_ary_new4(	R_ArgsRemaining(),
																			R_RemainingArgs() );		

		//	* sort ruby args array
		rb_ary_sort( rb_indexes );
		
		//	we operate on duplicates so we can match [A, B, C] as unique if [A, B] is unique
		VALUE	rb_indexes_duplicate					=	Qnil;
		BOOL	c_indexes_duplicate_modified	=	TRUE;
		
		//	if we have unique index combinations
		if ( rb_unique_index_combinations != Qnil )	{

			//	* iterate unique index combinations (already sorted) and compare each to sorted ruby args array
			for ( c_which_index = 0 ; c_which_index < RARRAY_LEN( rb_unique_index_combinations ) ; c_which_index++ )	{
				
				//	re-duplicate if we don't have a fresh copy
				if (	c_indexes_duplicate_modified )	{
					rb_indexes_duplicate					=	rb_ary_dup( rb_indexes );
					c_indexes_duplicate_modified	=	FALSE;
				}
				
				VALUE	rb_this_unique_index_combination	=	RARRAY_PTR( rb_unique_index_combinations )[ c_which_index ];
				
				//	if this unique index combination has more members than provided args, it cannot match
				if ( RARRAY_LEN( rb_this_unique_index_combination ) > R_ArgsRemaining() )	{
					continue;
				}
				//	otherwise if it has less members, we can duplicate args and remove all members that unique index combination does not have
				else if ( RARRAY_LEN( rb_this_unique_index_combination ) < R_ArgsRemaining() ) {
					
					//	for each arg in rb_indexes_duplicate
					int	c_which_duplicate_index;
					for( c_which_duplicate_index = 0 ; c_which_duplicate_index < RARRAY_LEN( rb_indexes_duplicate ) ; c_which_duplicate_index++ )	{
											
						VALUE	rb_this_duplicate_index	=	RARRAY_PTR( rb_indexes_duplicate )[ c_which_duplicate_index ];
						
						//	check if unique index combination has arg
						if ( rb_ary_includes(	rb_this_unique_index_combination,
																	rb_this_duplicate_index ) == Qfalse )	{
						
							VALUE	rb_which_duplicate_index	=	INT2FIX( c_which_duplicate_index );
						
							//	if not, remove from rb_indexes_duplicate
							rb_funcall(	rb_indexes_duplicate,
													rb_intern( "delete_at" ),
													1,
													rb_which_duplicate_index );
							
						}
					}
						
					//	note that we modified rb_indexes_duplicate
					c_indexes_duplicate_modified	=	TRUE;

				}

				//	and then we compare arrays for equality:
				//	if our sorted args matches a unique index combination we can break (rb_index_is_unique is true)
				if ( rb_ary_cmp( rb_indexes_duplicate, rb_this_unique_index_combination ) == INT2FIX( 0 ) )	{
					rb_index_is_unique = Qtrue;
					break;
				}
			}
		}

	}
	
	return rb_index_is_unique;
}

/*************************
*  set_unique_for_index  *
*************************/

VALUE rb_RPbdb_Database_setUniqueForIndex(	int			argc,
																					VALUE*	args,
																					VALUE		rb_database	)	{

	VALUE	rb_index	=	Qnil;
	R_DefineAndParse( argc, args, rb_database,
		R_DescribeParameterSet(		
			R_ParameterSet(				R_Parameter(		R_MatchStringSymbol( rb_index ) ) ),
			1,
			":index",
			"'index'" 
		)
	)
	
	VALUE	rb_unique_indexes_for_database	=	rb_RPbdb_Database_internal_uniqueIndexesHash( rb_database );	

	//	for each index
	int	c_which_arg = 0;
	do	{
		
		//	get any existing unique index combinations for this index
		VALUE	rb_unique_index_combinations_for_index	=	rb_hash_aref(	rb_unique_indexes_for_database,
																																	rb_index );
		//	if there are none, instantiate array
		if ( rb_unique_index_combinations_for_index == Qnil )	{
			rb_unique_index_combinations_for_index = rb_ary_new();
			rb_hash_aset(	rb_unique_indexes_for_database,
										rb_index,
										rb_unique_index_combinations_for_index );
		}
	
		//	* create unique indexes array
		VALUE	rb_this_unique_index_combination	=	rb_ary_new4(	argc,
																														args );
		
		//	* remove current index from unique indexes array
		VALUE	rb_which_arg	=	INT2FIX( c_which_arg );
		rb_funcall(	rb_this_unique_index_combination,
								rb_intern( "delete_at" ),
								1,
								rb_which_arg );

		//	* sort unique indexes array
		rb_ary_sort( rb_this_unique_index_combination );

		//	* push unique indexes array onto hash index in database's unique index storage unless it's already there
		if ( rb_ary_includes(	rb_unique_index_combinations_for_index,
													rb_this_unique_index_combination ) == Qfalse )	{
			
			rb_ary_push(	rb_unique_index_combinations_for_index,
										rb_this_unique_index_combination );
		}
		
		c_which_arg++;
		
	}	while ( R_Arg( rb_index ) );
	
	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Write Actions
*******************************************************************************************************************************************************************************************/

/**********
*  write  *
**********/

//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records.
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPbdb_Database_write(	int			argc, 
															VALUE*	args, 
															VALUE		rb_primary_database )	{

	VALUE	rb_key												=	Qnil;
	VALUE	rb_data												=	Qnil;
	VALUE	rb_hash_descriptor_key_data		=	Qnil;

	R_DefineAndParse( argc, args, rb_primary_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchHash(    rb_hash_descriptor_key_data,
                                                        R_HashKey(	R_Any() ),
                                                        R_HashData(	R_Any() ) ) ) )
      ),
			R_ListOrder( 2 ),
			"{ <key> =>  <data>, ... }"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(     rb_key ) ),
												R_Parameter(	R_MatchAny(     rb_data ) ) ),
			R_ListOrder( 1 ),
			"<key>, <data>, ..."
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	rb_primary_database;
	
	if (				rb_hash_descriptor_key_data != Qnil ) {

		R_IterateHashDescriptor(	rb_hash_descriptor_key_data, 
															rb_RPbdb_Database_write );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		RPbdb_Database*	c_database	=	NULL;
		RPbdb_Record*		c_record		=	NULL;
		C_RPBDB_DATABASE( rb_primary_database, c_database );

		do {
			
			c_record	=	rb_RPbdb_Database_internal_recordForRubyKeyData(	rb_primary_database,
																																	rb_key,
																																	rb_data );
			
			RPbdb_Database_write(	c_database,
														c_record	);

			//	remaining args are data
		} while ( R_Arg( rb_data ) );
		
	}
	
	return rb_return;
}	

/***********
*  append  *
***********/
/*
//	DB_APPEND			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Queue or Recno only
VALUE rb_RPbdb_Database_append(	VALUE	rb_database,
																VALUE	append_record	)	{
	RPbdb_Database_appendRecord();

}

*/

/*******************************************************************************************************************************************************************************************
																		Key Retrieval
*******************************************************************************************************************************************************************************************/

/***************
*  key_exists  *
***************/

//	returns if the specified key appears in the database
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_exists.html	
VALUE rb_RPbdb_Database_keyExists(	int			argc,
																	VALUE*	args,
																	VALUE		rb_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
                                                      R_HashKey(	R_Symbol() ),
                                                      R_HashData(	R_Any() ) ) ) )
      ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }"
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
                          R_Parameter(	R_MatchAny(			rb_key ) ) )
      ),
			R_ListOrder( 2 ),
			":index, <key>"
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) )
			),
      R_ListOrder( 1 ),
			"<key>"
		)

		//----------------------------------------------//

	)

	VALUE	rb_return	=	Qnil;

	if (				rb_hash_descriptor_index_key != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key, 
																					rb_RPbdb_Database_keyExists );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		RPbdb_Database*		c_database;
		VALUE	rb_database	=	rb_RPbdb_Database_databaseWithIndex( rb_database,
																														rb_index );
		C_RPBDB_DATABASE( rb_database, c_database );

		RPbdb_Key*	c_key	=	RPbdb_Key_new( NULL );

		VALUE		rb_result				=	Qnil;
		VALUE		rb_return_array	=	rb_ary_new();

		do {
			
			rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																												rb_key,
																												c_key,
																												TRUE );

			rb_result	=	( RPbdb_Database_keyExists(	c_database,
																							c_key )	?	Qtrue
																											:	Qfalse );

			rb_ary_push(	rb_return_array,
										rb_result );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return = R_SimplifyArray( rb_return_array );
	}
	
	return rb_return;
}

/*******************
*  key_exists_raw  *
*******************/

VALUE rb_RPbdb_Database_keyExistsRaw(	int			argc,
                                      VALUE*	args,
                                      VALUE		rb_database )	{

	VALUE	rb_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_database,
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

  RPbdb_Database*		c_database;

  C_RPBDB_DATABASE( rb_database, c_database );

  RPbdb_Key*	c_key	=	RPbdb_Key_new( NULL );

  VALUE		rb_key_exists     =	Qnil;
  VALUE		rb_return_array   =	rb_ary_new();

  do {
    
    rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_database,
                                                      rb_key,
                                                      c_key,
                                                      TRUE );

    rb_key_exists	=	( RPbdb_Database_keyExists(	c_database,
                                                c_key )	?	Qtrue
                                                        :	Qfalse );

    rb_ary_push(	rb_return_array,
                  rb_key_exists );

    //	remaining args are keys
  } while ( R_Arg( rb_key ) );

  rb_return_array = R_SimplifyArray( rb_return_array );

  return rb_return_array;
}

/***************
*  keys_exist  *
***************/

//	returns if the specified keys all appear in the database
VALUE rb_RPbdb_Database_keysExist(	int			argc,
																	VALUE*	args,
																	VALUE		rb_database )	{

	//	we need at least one key
	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key>, ..."
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

	if (				rb_hash_descriptor_index_key != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key, 
																					rb_RPbdb_Database_keysExist );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
				
		VALUE	rb_args_with_index[]	=	{ rb_index, rb_key };

		VALUE	rb_keys_exist	=	Qtrue;

		//	for each key
		do	{
			//	check if key exists
			if ( rb_index != Qnil )	{
				if ( ( rb_keys_exist	=	rb_RPbdb_Database_keyExists(	2,
																														rb_args_with_index,
																														rb_database ) ) == Qfalse )	{
					break;
				}
			}
			else if ( ( rb_keys_exist	=	rb_RPbdb_Database_keyExists(	1,
																															& rb_key,
																															rb_database ) ) == Qfalse )	{
				//	if any key does not exist, break and return false
				break;
			}
		} while ( R_Arg( rb_key ) );
		
		rb_return = rb_keys_exist;
	}

	return rb_return;
}

/*******************
*  keys_exist_raw  *
*******************/

//	returns if the specified keys all appear in the database
VALUE rb_RPbdb_Database_keysExistRaw(	int			argc,
                                      VALUE*	args,
                                      VALUE		rb_database )	{

	VALUE	rb_key																			=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	VALUE	rb_return	=	Qnil;

  VALUE	rb_keys_exist	=	Qtrue;

  //	for each key
  do	{
    //	check if key exists
    if ( ( rb_keys_exist	=	rb_RPbdb_Database_keyExists(	1,
                                                        & rb_key,
                                                        rb_database ) ) == Qfalse )	{
      //	if any key does not exist, break and return false
      break;
    }
  } while ( R_Arg( rb_key ) );
  
  rb_return = rb_keys_exist;

	return rb_return;
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
VALUE rb_RPbdb_Database_retrieve(	int			argc, 
																	VALUE*	args,
																	VALUE		rb_database )	{


	VALUE	rb_index											=	Qnil;
	VALUE	rb_key												=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
                                                      R_HashKey(	R_Symbol() ),
                                                      R_HashData(	R_Any() ) ) ) )
      ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }"
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
                          R_Parameter(	R_MatchAny(			rb_key ) ) )
      ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) )
      ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	Qnil;

  VALUE	rb_return_array	=	rb_ary_new();
	
	if (		rb_hash_descriptor_index_key != Qnil ) {

		do	{

			if ( RHASH_SIZE( rb_hash_descriptor_index_key ) == 1 )	{
			
				VALUE	rb_return_hash	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key, 
																													rb_RPbdb_Database_retrieve );
				
				rb_return	=	R_SimplifyHash( rb_return_hash );
			}
			else {
					
				//	we want to perform a join here rather than multiple retrieves
				VALUE	rb_database_join_controller	=	rb_RPbdb_Database_joinController( rb_database );

				VALUE	rb_join_cursor	=	rb_RPbdb_DatabaseJoinController_join(	1,
																																			& rb_hash_descriptor_index_key,
																																			rb_database_join_controller );
				
				if ( rb_join_cursor != Qnil )	{
					rb_return	=	rb_RPbdb_DatabaseJoinCursor_first( rb_join_cursor );
				}
					
			}

			rb_ary_push(	rb_return_array,
										rb_return );

		}	while ( R_Arg( rb_hash_descriptor_index_key ) );

		rb_return	=	R_SimplifyArray( rb_return_array );

	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		RPbdb_Database*	c_database	=	NULL;
		RPbdb_Record*		c_record		=	NULL;

		rb_database	=	rb_RPbdb_Database_databaseWithIndex( rb_database,
																											rb_index );
		C_RPBDB_DATABASE( rb_database, c_database );

		rb_return_array		=	rb_ary_new();

		VALUE	rb_data			=	Qnil;

		do {
			
			c_record	=	rb_RPbdb_Database_internal_recordForRubyKey(	rb_database,
																															rb_key );

			c_record	=	RPbdb_Database_retrieveRecord(	c_database,
																								c_record );
			
			if ( c_record->result )	{
				rb_data	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
																																			c_record->data,
																																			FALSE );
			}
			
			RPbdb_Record_free( & c_record );
			
			rb_ary_push(	rb_return_array,
										rb_data );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );

		rb_return	=	R_SimplifyArray( rb_return_array );
				
	}
	
	return rb_return;
}

/*****************
*  retrieve_raw  *
*****************/

//	database.retrieve_hash( primary_key )
//	database.retrieve_hash( :index, secondary_key )
//	database.retrieve_hash( :index => secondary_key_in_index )
//	database.retrieve_hash( [ any args ] )
VALUE rb_RPbdb_Database_retrieveRaw(	int			argc, 
                                    VALUE*	args,
                                    VALUE		rb_database )	{

	VALUE	rb_key												=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	VALUE	rb_return	=	Qnil;

  RPbdb_Database*	c_database	=	NULL;
  RPbdb_Record*		c_record		=	NULL;

  C_RPBDB_DATABASE( rb_database, c_database );

  rb_return		=	rb_ary_new();

  VALUE	rb_data			=	Qnil;

  do {
    
    c_record	=	rb_RPbdb_Database_internal_recordForRubyKey(	rb_database,
                                                            rb_key );

    c_record	=	RPbdb_Database_retrieveRecord(	c_database,
                                              c_record );
    
    if ( c_record->result )	{
      rb_data	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                    c_record->data,
                                                                    FALSE );
    }
    
    RPbdb_Record_free( & c_record );
    
    rb_ary_push(	rb_return,
                  rb_data );

    //	remaining args are keys
  } while ( R_Arg( rb_key ) );
  
  rb_return =	R_SimplifyArray( rb_return );
	
	return rb_return;

}

/*************************
*  retrieve_primary_key  *
**************************/

//	database.retrieve_primary_key( :index, secondary_key )
//	database.retrieve_primary_key( :index => secondary_key_in_index )
//	database.retrieve_primary_key( :index => [ secondary_keys_in_index, ... ] )
//	database.retrieve_primary_key( [ any args ] )
VALUE rb_RPbdb_Database_retrievePrimaryKey(	int			argc, 
																						VALUE*	args,
																						VALUE		rb_primary_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_primary_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 1 ),
			"{ :index   =>  <key>, ... }"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key>"
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	Qnil;
	
	if (		rb_hash_descriptor_index_key != Qnil ) {

		VALUE	rb_return_array	=	rb_ary_new();

		do	{

			if ( RHASH_SIZE( rb_hash_descriptor_index_key ) == 1 )	{
			
				VALUE	rb_return_hash	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key, 
																													rb_RPbdb_Database_retrievePrimaryKey );
				
				rb_return	=	R_SimplifyHash( rb_return_hash );
			}
			else {
					
				//	we want to perform a join here rather than multiple retrieves
				VALUE	rb_database_join_controller	=	rb_RPbdb_Database_joinController( rb_primary_database );

				VALUE	rb_join_cursor	=	rb_RPbdb_DatabaseJoinController_join(	1,
																																			& rb_hash_descriptor_index_key,
																																			rb_database_join_controller );
				
				if ( rb_join_cursor != Qnil )	{
					rb_return	=	rb_RPbdb_DatabaseJoinCursor_firstKey( rb_join_cursor );
				}
			}

			rb_ary_push(	rb_return_array,
										rb_return );

		}	while ( R_Arg( rb_hash_descriptor_index_key ) );

		rb_return	=	R_SimplifyArray( rb_return_array );
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		RPbdb_Database*	c_database	=	NULL;
		RPbdb_Record*		c_record		=	NULL;

		VALUE	rb_database	=	rb_RPbdb_Database_databaseWithIndex( rb_primary_database,
																														rb_index );
		C_RPBDB_DATABASE( rb_database, c_database );

		rb_return		=	rb_ary_new();

		VALUE	rb_key			=	Qnil;

		do {
			
			c_record	=	rb_RPbdb_Database_internal_recordForRubyKey(	rb_database,
																															rb_key );

			c_record	=	RPbdb_Database_retrieveRecord(	c_database,
																								c_record );
			
			rb_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
																																		c_record->key,
																																		TRUE );

			rb_ary_push(	rb_return,
										rb_key );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	R_SimplifyArray( rb_return );
		
	}
	
	return rb_return;
}

/*****************************
*  retrieve_primary_key_raw  *
*****************************/
/*
//	database.retrieve_primary_key( :index, secondary_key )
//	database.retrieve_primary_key( :index => secondary_key_in_index )
//	database.retrieve_primary_key( :index => [ secondary_keys_in_index, ... ] )
//	database.retrieve_primary_key( [ any args ] )
VALUE rb_RPbdb_Database_retrievePrimaryKeyRaw(	int			argc, 
                                              VALUE*	args,
                                              VALUE		rb_database )	{

}
*/

/***********************
*  retrieve_exact_pair *
*  retrieve_pair       *
***********************/

//	database.retrieve_pair( primary_key, data )
//	database.retrieve_pair( primary_key => data )
//	database.retrieve_pair( :index, secondary_key, data )
//	database.retrieve_pair( :index, secondary_key => data )
//	database.retrieve_pair( :index => {	secondary_key => data } )
VALUE rb_RPbdb_Database_retrieveExactPair(	int			argc, 
                                          VALUE*	args,
                                          VALUE		rb_database )	{

	VALUE	rb_index											=	Qnil;
	VALUE	rb_key												=	Qnil;
	VALUE	rb_data												=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ),
																			R_MatchAny(			rb_data ) ) ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)

	RPbdb_Database*	c_database	=	NULL;
	RPbdb_Record*		c_record		=	rb_RPbdb_Database_internal_recordForRubyKeyData(	rb_database,
																																								rb_key,
																																								rb_data );

	c_record	=	RPbdb_Database_retrieveRecord(	c_database,
																						c_record );
	
	rb_data	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
																																c_record->data,
																																FALSE );

	c_record	=	RPbdb_Database_retrieveMatchingRecord(	c_database,
																										c_record );

  rb_data	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                c_record->data,
                                                                FALSE );

	return rb_data;
}


/***************************
*  retrieve_exact_pair_raw *
*  retrieve_pair_raw       *
***************************/
/*
VALUE rb_RPbdb_Database_retrieveExactPairRaw(	int			argc, 
                                              VALUE*	args,
                                              VALUE		rb_database )	{

}
*/
/*************************
*  retrieve_partial_key  *
*************************/
/*
//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPbdb_Database_retrievePartialKey(	VALUE	rb_database,
 																			VALUE						partial_key )	{

	//	FIX - RARGS

	RPbdb_Database_retrievePartialKey();
	
}
*/

/*****************************
*  retrieve_partial_key_raw  *
*****************************/
/*
//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPbdb_Database_retrievePartialKey(	VALUE	rb_database,
 																			VALUE						partial_key )	{

	//	FIX - RARGS

	RPbdb_Database_retrievePartialKey();
	
}

*/
/**************************
*  retrieve_partial_data  *
**************************/
/*
//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_RPbdb_Database_retrievePartialData(	VALUE	rb_database,
 																				VALUE						data )	{

//	FIX - RARGS

	RPbdb_Database_retrievePartialData();

}
*/

/******************************
*  retrieve_partial_data_raw  *
******************************/
/*
//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_RPbdb_Database_retrievePartialData(	VALUE	rb_database,
 																				VALUE						data )	{

//	FIX - RARGS

	RPbdb_Database_retrievePartialData();

}
*/

/*******************************************************************************************************************************************************************************************
																		Data Deletion
*******************************************************************************************************************************************************************************************/

/************************
*  delete_data_for_key  *
************************/

VALUE rb_RPbdb_Database_delete(	int			argc, 
																VALUE*	args,
																VALUE		rb_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key,
                                                      R_HashKey(	R_Symbol() ),
                                                      R_HashData(	R_Any() ) ) ) )
      ),
			R_ListOrder( 4 ),
			"{ :index   =>  <key>, ... }, ..."
			 
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
                          R_Parameter(	R_MatchAny(			rb_key ) ) )
      ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
      R_ExactMatch(
        R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) )
      ),
			R_ListOrder( 1 ),
			"<key>, ..."
		)

		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	rb_database;
	
	if (		rb_hash_descriptor_index_key != Qnil ) {

		rb_return	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key, 
																					rb_RPbdb_Database_delete );

		rb_return =	R_SimplifyHash( rb_return );

	}
	else if (		rb_args_array != Qnil )	{

		if ( rb_index != Qnil )	{

			do {

				rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																							rb_RPbdb_Database_delete,
																							rb_index );

			}	while ( R_Arg( rb_args_array ) );

			rb_return =	R_SimplifyArray( rb_return );

		}
		else {
			
			rb_return = R_SplatArrayDescriptor(	rb_args_array,
																					rb_RPbdb_Database_delete	);

		}
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		RPbdb_Database*	c_database	=	NULL;
		VALUE	rb_database_for_index	=	rb_RPbdb_Database_databaseWithIndex(  rb_database,
                                                                        rb_index );
		C_RPBDB_DATABASE( rb_database_for_index, c_database );

		RPbdb_Record*		c_record	=	NULL;

		do {
			
			c_record	=	rb_RPbdb_Database_internal_recordForRubyKey(	rb_database_for_index,
                                                                rb_key );

			RPbdb_Database_deleteRecord(	c_database,
                                    c_record );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	R_SimplifyArray( rb_return );
		
	}
	
	return rb_return;
}

/****************************
*  delete_data_for_key_raw  *
****************************/
/*
VALUE rb_RPbdb_Database_deleteDataForKeyRaw(	int			argc, 
                                            VALUE*	args,
                                            VALUE		rb_database )	{

}
*/

/*******************************************************************************************************************************************************************************************
																		Cursor Operations
*******************************************************************************************************************************************************************************************/

/***********
*  cursor  *
***********/

VALUE rb_RPbdb_Database_cursor( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPbdb_Database_cursorController( rb_database );	
	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );
	VALUE	rb_database_cursor						=	rb_RPbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );
		
	return rb_database_cursor;
}	

/************
*  iterate  *
************/

VALUE rb_RPbdb_Database_iterate( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor						=	rb_RPbdb_Database_cursor( rb_database );

	//	set the cursor position
	
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPbdb_DatabaseCursor_iterate(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPbdb_DatabaseCursor_iterate, rb_database_cursor,
											rb_RPbdb_DatabaseCursor_close, rb_database_cursor );
	}
	
	return rb_database;
}

/*****************
*  iterate_keys  *
*****************/

VALUE rb_RPbdb_Database_iterateKeys( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPbdb_DatabaseCursor_iterateKeys(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPbdb_DatabaseCursor_iterateKeys, rb_database_cursor,
											rb_RPbdb_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/***********************
*  iterate_duplicates  *
***********************/

VALUE rb_RPbdb_Database_iterateDuplicates( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_RPbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_RPbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_RPbdb_DatabaseCursor_iterateDuplicates(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_RPbdb_DatabaseCursor_iterateDuplicates, rb_database_cursor,
											rb_RPbdb_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Btree Specific
*******************************************************************************************************************************************************************************************/

/*****************************
*  relative_position_of_key  *
*****************************/
/*

//	returns an estimate of the proportion of keys that are less than, equal to, and greater than the specified key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_key_range.html
//	Requires Btree
RPbdb_KeyRange* RPbdb_Database_relativePositionOfKey(	VALUE	rb_database,
																										VALUE	rb_key )	{

//	FIX - RARGS

}
*/

/**********************************
*  relative_position_of_key_raw  *
**********************************/
/*

//	returns an estimate of the proportion of keys that are less than, equal to, and greater than the specified key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_key_range.html
//	Requires Btree
RPbdb_KeyRange* RPbdb_Database_relativePositionOfHashKey(	VALUE	rb_database,
                                                        VALUE	rb_key )	{

//	FIX - RARGS

}
*/

/*******************************************************************************************************************************************************************************************
																		Queue Specific
*******************************************************************************************************************************************************************************************/

/******************
*  shift_queue  *
******************/
	/*
//	Only relevant for Queue databases
//	DB_CONSUME				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPbdb_Database_shiftQueue( VALUE	rb_database )	{

	RPbdb_Database_shiftQueue();
	
}
*/
/**************************
*  shift_queue_or_wait  *
**************************/
/*
//	Only relevant for Queue databases
//	DB_CONSUME_WAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPbdb_Database_shiftQueueOrWait( VALUE	rb_database )	{
	RPbdb_Database_shiftQueueOrWait();

}

*/

/***********
*  verify  *
***********/

//	FIX - flesh out functions

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_RPbdb_Database_verify( VALUE	rb_database )	{

	RPbdb_Database*		c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	RPbdb_Database_verify( c_database );

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/**************************************************
*  setSecondaryKeyCreationCallbackMethodInfoHash  *
**************************************************/

VALUE	rb_RPbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	VALUE	rb_primary_database_self,
																																						VALUE	rb_index,
																																						VALUE	rb_callback_object )	{


	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPbdb,
																				RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash);
	}

	//	get database hash, set if it doesn't exist
	VALUE	rb_primary_database_handle	=	rb_RPbdb_Database_handle( rb_primary_database_self );	
	VALUE	rb_database_callback_hash	=	rb_hash_aref(	rb_callbacks_hash,
																									rb_primary_database_handle );
	
	if ( rb_database_callback_hash == Qnil )	{
		rb_database_callback_hash = rb_hash_new();
		rb_hash_aset(	rb_callbacks_hash,
									rb_primary_database_handle,
									rb_database_callback_hash );
	}
	
	if ( TYPE( rb_index ) == T_STRING )	{
		rb_index	=	ID2SYM( rb_to_id( rb_index ) );
	}
	
	rb_hash_aset(	rb_database_callback_hash,
								rb_index,
								rb_callback_object );

	return rb_database_callback_hash;
}

/***************************
*  initRubyRuntimeStorage  *
***************************/

VALUE rb_RPbdb_Database_internal_initRubyRuntimeStorage(	VALUE rb_ruby_runtime_storage_database )	{

	RPbdb_Database*	c_ruby_runtime_storage_database;
	C_RPBDB_DATABASE( rb_ruby_runtime_storage_database, c_ruby_runtime_storage_database );

	RPbdb_DatabaseSettingsController*			c_database_settings_controller			=	RPbdb_Database_settingsController( c_ruby_runtime_storage_database );
	RPbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );
	
	//	Set the database type - BTree since we will be searching by pointer and don't want to create a ton of junk records
	RPbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );	

	//	Open the database with our settings
	RPbdb_Database_internal_openWithoutRuntimeStorage( c_ruby_runtime_storage_database );
	
	return rb_ruby_runtime_storage_database;	
}

/**********************************
*  storeRubyInstanceForCInstance  *
**********************************/

VALUE rb_RPbdb_Database_internal_storeRubyRuntimeInstanceForCInstance(	VALUE rb_database )	{

	VALUE						rb_ruby_runtime_database	=	rb_RPbdb_internal_rubyRuntimeDatabase( rb_mRPbdb );
	RPbdb_Database*	c_ruby_runtime_database;
	C_RPBDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );

	RPbdb_Database*	c_database;
	C_RPBDB_DATABASE( rb_database, c_database );

	uintptr_t	c_database_address	=	(uintptr_t) c_database;
	uintptr_t	rb_database_address	=	(uintptr_t) rb_database;
	RPbdb_Database_writeRawKeyDataPair(	c_ruby_runtime_database,
																			& c_database_address,
																			sizeof( uintptr_t ),
																			& rb_database_address,
																			sizeof( uintptr_t ) );
	
	return rb_database;
}

/*****************************
*  RubyInstanceForCInstance  *
*****************************/

VALUE rb_RPbdb_Database_internal_rubyRuntimeInstanceForCInstance(	void* c_rpbdb_instance )	{
	//	we store a reference to our Ruby instance so that we can return the same object to the callback
	//	this is necessary to ensure extended methods, etc, remain
	VALUE						rb_ruby_runtime_database	=	rb_RPbdb_internal_rubyRuntimeDatabase( rb_mRPbdb );
	RPbdb_Database*	c_ruby_runtime_database;
	C_RPBDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );
	
	uintptr_t	c_rpbdb_instance_address	=	(uintptr_t) c_rpbdb_instance;
	
	RPbdb_Record*	c_record	=	NULL;
	//	get address of corresponding VALUE
	c_record	=	RPbdb_Database_retrieveRawKey(	c_ruby_runtime_database,
																						& c_rpbdb_instance_address,
																						sizeof( uintptr_t ) );
	uintptr_t*	rb_database_address	=	RPbdb_Record_rawData( c_record );
	VALUE	rb_database	=	(VALUE) *rb_database_address;
	
	RPbdb_Record_free( & c_record );
	
	return rb_database;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

//	This is the actual C method that gets called when a callback is set
RPBDB_SECONDARY_KEY_CREATION_RETURN rb_RPbdb_Database_internal_secondaryKeyCreationCallbackMethod(	RPbdb_Database*			c_secondary_database, 
																																																	RPbdb_Record*				c_record, 
																																																	RPbdb_SecondaryKeys*	c_secondary_keys )	{
	
	//	get our Ruby instance corresponding to our C instance
	VALUE	rb_secondary_database		=	rb_RPbdb_Database_internal_rubyRuntimeInstanceForCInstance(	c_secondary_database );
	
	VALUE	rb_key	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance(	rb_secondary_database,
																																			c_record->key,
																																			TRUE );
	VALUE	rb_data	=	rb_RPbdb_Database_internal_unpackDBTForRubyInstance(	rb_secondary_database,
																																			c_record->data,
																																			FALSE );

	VALUE	rb_callback_object	=	rb_RPbdb_Database_secondaryKeyCreationCallbackMethod(	0,
																																										NULL,
																																										rb_secondary_database );	
	if ( rb_callback_object == Qnil )	{
		rb_raise( rb_eRuntimeError, "Could not find callback info for secondary database." );
	}

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
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );
			break;
	}

	rb_secondary_keys	=	rb_funcall2(	rb_callback_object,
																		rb_intern( "call" ),
																		RARRAY_LEN( rb_args ),
																		RARRAY_PTR( rb_args ) );

	//	if nil, don't index
	if ( rb_secondary_keys == rb_const_get( rb_mRPbdb, rb_intern( "NoSecondaryKeys" ) ) )	{
		return RPBDB_SECONDARY_KEY_CREATION_FAILED_DO_NOT_INDEX;
	}

	return rb_RPbdb_Database_internal_processSecondaryKeyReturn(	rb_secondary_database,
																															rb_secondary_keys,
																															c_secondary_keys );	
}

/******************************
*  processSecondaryKeyReturn  *
******************************/

RPBDB_SECONDARY_KEY_CREATION_RETURN rb_RPbdb_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																												VALUE									rb_secondary_keys,
																																												RPbdb_SecondaryKeys*		c_secondary_keys )	{

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
		
		RPbdb_Database*	c_secondary_database;
		C_RPBDB_DATABASE( rb_secondary_database, c_secondary_database );
		
		RPbdb_Record*	c_record	=	RPbdb_Record_new( c_secondary_database );
		RPbdb_Key_free( & c_record->key );
		RPbdb_Data_free( & c_record->data );
		
		//	iterate ruby keys in array and store in location in c array
		VALUE		rb_this_key		=	Qnil;
		int	which_key_index		= 0;
		for ( which_key_index = 0 ; which_key_index < number_of_keys ; which_key_index++) {
			
			//	get a name for the current key
			rb_this_key = RARRAY_PTR( rb_secondary_keys )[ which_key_index ];
			
			//	pack the key into the DBT at which_key_index
			c_record->key	=	RPbdb_DBT_internal_newFromBDBDBT(	c_record,
																												& c_keys[ which_key_index ] );
			rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_secondary_database,
																												rb_this_key,
																												c_record->key,
																												TRUE );
			//	NULLify pointer to BDB key so that freeing RPbdb_Key won't free the BDB key
			c_record->key->wrapped_bdb_dbt	=	NULL;
			RPbdb_Key_free( & c_record->key );
		}
		
		RPbdb_Record_free( & c_record );
		
		if ( number_of_keys > 1 )	{
		
			//	store the array of keys in the DBT that gets returned to BDB
			c_secondary_keys->wrapped_bdb_dbt->data	=	c_keys;
			c_secondary_keys->wrapped_bdb_dbt->size	=	number_of_keys;

			return RPBDB_RECORD_ALLOCATED_BY_APPLICATION_FOR_MULTIPLE_SECONDARY_KEYS;
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
		rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_secondary_database,
																											rb_secondary_keys, 
																											(RPbdb_DBT*) c_secondary_keys,
																											TRUE );
	}

	return FALSE;
}

/*******************************
*  removeCallbackInfoFromHash  *
*******************************/

VALUE rb_RPbdb_Database_internal_removeCallbackInfoFromHash(	VALUE		rb_secondary_database )	{
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRPbdb,
																				RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	VALUE	rb_primary_database	=	rb_RPbdb_Database_primaryDatabase( rb_secondary_database );

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_primary_database_handle	=	rb_RPbdb_Database_handle( rb_primary_database );	

	VALUE	rb_database_callbacks	=	rb_hash_aref(	rb_callbacks_hash,
																							rb_primary_database_handle );
	if ( rb_database_callbacks == Qnil )	{
		rb_database_callbacks = rb_hash_new();
		rb_hash_aset(	rb_callbacks_hash,
									rb_primary_database_handle,
									rb_database_callbacks );
	}
		
	VALUE	rb_index		=	rb_RPbdb_Database_secondaryIndexName( rb_secondary_database );
	
	//	we use a ruby call here instead of a C call so we don't pass any blocks that might have
	//	been passed to rb_RPbdb_Database_open (which calls rb_RPbdb_Database_close when finished with the block)
	//	if we call in C, the block gets called twice (second time by rb_delete)
	rb_funcall(	rb_database_callbacks,
							rb_intern( "delete" ),
							1,
							rb_index );
	return rb_secondary_database;
}

/*************************
*  createSecondaryIndex  *
*************************/

VALUE rb_RPbdb_Database_internal_createSecondaryIndex(	int			argc,
																											VALUE*	args,
																											VALUE		rb_primary_database_self,
																											BOOL		c_with_duplicates,
																											BOOL		c_with_sorted_duplicates )	{

	VALUE	rb_index								=	Qnil;
	VALUE	rb_secondary_database		=	Qnil;
	
	VALUE	rb_callback_proc				=	Qnil;
	VALUE	rb_callback_object			=	Qnil;
	VALUE	rb_callback_method			=	Qnil;
	
	VALUE	rb_callback_method_name_in_object			=	Qnil;
	VALUE	rb_callback_method_name_in_primary		=	Qnil;
	
	//	we always have :index
	//	sometimes we have <secondary database>

	R_DefineAndParse( argc, args, rb_primary_database_self,

		R_DescribeParameterSet(
																								//	:index
			R_ParameterSet(		R_Parameter(						R_MatchStringSymbol(																			rb_index ) ),
																								//	[ <secondary_database> ]
												R_Parameter(						R_MatchBlockLambdaWithArity(															rb_callback_proc, 0, 1, 2, 3, -1, -2 ),
																								//	proc
																								R_MatchLambdaWithArity(																		rb_callback_proc, 0, 1, 2, 3, -1, -2 ),
																								//	:method_in_primary
																								R_MatchStringSymbol(																			rb_callback_method_name_in_primary ),
																								//	<method_in_primary>
																								R_MatchMethod(																						rb_callback_method ),
																								//	<callback_object>, :method_in_object
																								R_Group(			R_MatchAny(																	rb_callback_object ),	
																															R_MatchStringSymbol(												rb_callback_method_name_in_object ) ),
																								//	:method_in_object, <callback_object>
																								R_Group(			R_MatchStringSymbol(												rb_callback_method_name_in_object ),
																															R_MatchAny(																	rb_callback_object ) ),
																								//	{ <callback_object> => :method_in_object }
																								R_Hash(				R_HashKey(	R_MatchAny(											rb_callback_object ) ),
																															R_HashData(	R_MatchStringSymbol(						rb_callback_method_name_in_object ) ) ),
																								//	{ :method_in_object => <callback_object> }
																								R_Hash(				R_HashKey(	R_MatchStringSymbol(						rb_callback_method_name_in_object ) ),
																															R_HashData(	R_MatchAny(											rb_callback_object ) ) ) ) ),
			R_ListOrder( 1 ),
			":index, & block",
			":index, <callback_proc>",
			":index, :callback_method_in_primary",
			":index, <callback_method_in_primary>",
			":index, <callback_object>, & block",
			":index, <callback_object>, :callback_method_in_object",
			":index, <callback_object>, 'callback_method_in_object'",
			":index, <callback_object> => :callback_method_in_object",
			":index, <callback_object> => 'callback_method_in_object'",
			":index, :callback_method_in_object, <callback_object>",
			":index, 'callback_method_in_object', <callback_object>",
			":index, :callback_method_in_object => <callback_object>",
			":index, 'callback_method_in_object'=> <callback_object>"

		)
	);
	
	if ( rb_callback_proc != Qnil )	{
		rb_callback_object	=	rb_callback_proc;
	}
	else if ( rb_callback_method != Qnil )	{
		rb_callback_object	=	rb_callback_method;
	}
	else if ( rb_callback_method_name_in_primary != Qnil )	{
		rb_callback_object	=	rb_funcall(	rb_primary_database_self,
																			rb_intern( "method" ),
																			1,
																			rb_callback_method_name_in_primary );
	}
	else if ( rb_callback_method_name_in_object != Qnil )	{
		rb_callback_object	=	rb_funcall(	rb_callback_object,
																			rb_intern( "method" ),
																			1,
																			rb_callback_method_name_in_object );
	}
	
	//	see if callback object is a database instance - if it is then we use it instead of creating a new one
	VALUE	rb_callback_class	=	rb_class_of( rb_callback_object );
	VALUE	rb_callback_ancestors	=	rb_mod_ancestors( rb_callback_class );
	VALUE	rb_database	=	Qnil;
	RPbdb_Database*	c_primary_database		=	NULL;
	RPbdb_Database*	c_secondary_database		=	NULL;
	C_RPBDB_DATABASE( rb_primary_database_self, c_primary_database );	
	char*						c_index_name					=	NULL;
	if ( rb_ary_includes(	rb_callback_ancestors,
												rb_RPbdb_Database ) == Qtrue )	{
		rb_database	= rb_callback_object;
	}
	//	otherwise instantiate one now
	else	{
	
		VALUE	rb_primary_database_controller	=	rb_RPbdb_Database_parentDatabaseController( rb_primary_database_self );
		
		rb_index			= rb_obj_as_string( rb_index );
		c_index_name	=	StringValuePtr( rb_index );
		
		char*	c_primary_database_name					=	RPbdb_Database_name( c_primary_database );
		char*	c_secondary_database_name				=	RPbdb_Database_internal_secondaryDatabaseNameForIndex( c_index_name,
																																																	c_primary_database_name );
		VALUE	rb_secondary_database_name			=	rb_str_new2( c_secondary_database_name );
		free( c_secondary_database_name );
		rb_secondary_database									=	rb_RPbdb_DatabaseController_newDatabase(	rb_primary_database_controller,
																																										rb_secondary_database_name );

		C_RPBDB_DATABASE( rb_secondary_database, c_secondary_database );

		//	create secondary database
		RPbdb_Database_internal_configureDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																																												c_secondary_database,
																																												c_index_name,
																																												c_with_duplicates,
																																												c_with_sorted_duplicates );
	}

	if ( c_secondary_database == NULL )	{
		C_RPBDB_DATABASE( rb_secondary_database, c_secondary_database );
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
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );			
			break;
	}
	
	//	When an insert is made we need our RPbdb callback to call the Ruby RPbdb callback
	//	our Ruby RPbdb callback calls the ruby method that has been specified and returns it to RPbdb
	RPbdb_Database_setSecondaryKeyCreationCallbackMethod(	c_secondary_database,
																												& rb_RPbdb_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Now we need to make sure that we have our appropriate info when we reach our internal callback

	rb_RPbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	rb_primary_database_self,
																																				rb_index,
																																				rb_callback_object );
	
	//	store reference to secondary database in primary
	//	doesn't need to be weak b/c the secondary will be managed by the primary
	VALUE	rb_secondary_database_hash		=	rb_RPbdb_Database_secondaryDatabaseHash( rb_primary_database_self );
	if ( TYPE( rb_index ) == T_STRING )	{
		rb_index = ID2SYM( rb_to_id( rb_index ) );
	}
	rb_hash_aset(	rb_secondary_database_hash,
								rb_index,
								rb_secondary_database );
	
	//	associate secondary as index to primary
	RPbdb_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																									c_secondary_database,
																									c_index_name,
																									& rb_RPbdb_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Returns primary database so associations can be chained
	return rb_secondary_database;	
}

/**********************
*  uniqueIndexesHash  *
**********************/

VALUE rb_RPbdb_Database_internal_uniqueIndexesHash( VALUE	rb_database )	{

	VALUE	rb_unique_indexes_for_database	=	rb_iv_get(	rb_database,
																											RPBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES );
	if ( rb_unique_indexes_for_database == Qnil )	{		
		rb_unique_indexes_for_database = rb_hash_new();
		rb_iv_set(	rb_database,
								RPBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES,
								rb_unique_indexes_for_database );
	}
	
	return rb_unique_indexes_for_database;
}

/************************************
*  removeSecondaryDatabaseFromHash  *
************************************/

VALUE rb_RPbdb_Database_internal_removeSecondaryDatabaseFromHash( VALUE rb_database ) {
  
  VALUE rb_secondary_database_hash  = rb_RPbdb_Database_secondaryDatabaseHash( rb_database );
  
  rb_hash_delete( rb_secondary_database_hash,
                  rb_database );
  
  return rb_secondary_database_hash;
}


/*******************************************************************************************************************************************************************************************
																		Type Storage Methods
*******************************************************************************************************************************************************************************************/

/*************************
*  recordForRubyKeyData  *
*************************/

RPbdb_Record* rb_RPbdb_Database_internal_recordForRubyKeyData(	VALUE	rb_database,
																															VALUE	rb_key,
																															VALUE	rb_data )	{
		
	RPbdb_Database*	c_database;
	C_RPBDB_DATABASE( rb_database, c_database );
	
	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_key,
																										c_record->key,
																										TRUE );

	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_data,
																										c_record->data,
																										FALSE );

	return c_record;
}

/*********************
*  recordForRubyKey  *
*********************/

RPbdb_Record* rb_RPbdb_Database_internal_recordForRubyKey(	VALUE	rb_database,
																													VALUE	rb_key )	{

	RPbdb_Database*	c_database;
	C_RPBDB_DATABASE( rb_database, c_database );
	
	RPbdb_Record*	c_record	=	RPbdb_Record_new( c_database );
	
	rb_RPbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_key,
																										c_record->key,
																										TRUE );

	return c_record;
}

/***************************
*  packDBTForRubyInstance  *
***************************/

void rb_RPbdb_Database_internal_packDBTForRubyInstance(	VALUE				rb_database,
																												VALUE				rb_object,
																												RPbdb_DBT*		c_dbt,
																												BOOL				key_not_data )	{

	CerializeType	c_database_storage_type	=	CerializeType_Raw;

	VALUE	rb_key_storage_class	=	Qnil;
	VALUE	rb_data_storage_class	=	Qnil;

	VALUE	rb_database_settings_controller										=	rb_RPbdb_Database_settingsController( rb_database );
	VALUE	rb_database_record_settings_controller						=	rb_RPbdb_DatabaseSettingsController_recordSettingsController( rb_database_settings_controller );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_RPbdb_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_record_settings_controller );
	
  RPbdb_DatabaseRecordReadWriteSettingsController* c_database_record_read_write_settings_controller;
  C_RPBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

  
	//	if record typing, get key or data type from object
	if ( rb_RPbdb_DatabaseRecordReadWriteSettingsController_recordTyping( rb_database_record_read_write_settings_controller ) == Qtrue )	{

		c_database_storage_type	=	Rcerialize_storageTypeForRubyInstance( rb_object );

    //  if we have record typing then we know we have a type
    c_dbt->has_type = TRUE;
    
    //  if we have data and a time stamp then we have a data footer instead of a type footer
    if ( ! key_not_data ) {
      
      if ( RPbdb_DatabaseRecordReadWriteSettingsController_internal_hasFooter( c_database_record_read_write_settings_controller ) )  {
        
        c_dbt->has_footer = TRUE;
      }
    }

	}
	//	if store typing, get key or data type from storeType setting
	else if (				( key_not_data 
							&&	( rb_key_storage_class	= rb_RPbdb_DatabaseRecordReadWriteSettingsController_storeKeyTyping( rb_database_record_read_write_settings_controller ) ) != Qfalse )
					||	(			rb_data_storage_class	= rb_RPbdb_DatabaseRecordReadWriteSettingsController_storeDataTyping( rb_database_record_read_write_settings_controller ) ) != Qfalse )	{

		if ( key_not_data )	{
			c_database_storage_type	=	Rcerialize_storageTypeForRubyClass( rb_key_storage_class );
		}
		else {
			c_database_storage_type	=	Rcerialize_storageTypeForRubyClass( rb_data_storage_class );
		}

	}
	//	if no typing, type remains CerializeType_Raw
	
	CerializedData*	c_cerialized_data	=	Rcerialize_packRubyInstance(	rb_object,
																																		c_database_storage_type,
																																		key_not_data );
	
	c_dbt->wrapped_bdb_dbt->data	=	c_cerialized_data->data;
	c_dbt->wrapped_bdb_dbt->size	=	c_cerialized_data->size;
	c_dbt->type                   = *c_cerialized_data->type;
  
	//	set app-malloc so DB frees combined data
	c_dbt->wrapped_bdb_dbt->flags |= DB_DBT_APPMALLOC;

	c_cerialized_data->data	=	NULL;
	CerializedData_free( & c_cerialized_data );

}
	
/*******************************************************************************************************************************************************************************************
																		Type Retrieval Methods
*******************************************************************************************************************************************************************************************/

/*****************************
*  unpackDBTForRubyInstance  *
*****************************/

VALUE rb_RPbdb_Database_internal_unpackDBTForRubyInstance(	VALUE				rb_database,
																													RPbdb_DBT*		c_dbt,
																													BOOL				key_not_data )	{

	VALUE	rb_key_storage_class	=	Qnil;
	VALUE	rb_data_storage_class	=	Qnil;

	VALUE	rb_database_settings_controller										=	rb_RPbdb_Database_settingsController( rb_database );
	VALUE	rb_database_record_settings_controller						=	rb_RPbdb_DatabaseSettingsController_recordSettingsController( rb_database_settings_controller );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_RPbdb_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_record_settings_controller );

	CerializedData*	c_cerialized_data     = CerializedData_new(	& c_dbt->wrapped_bdb_dbt->data,
                                                              c_dbt->wrapped_bdb_dbt->size );
	CerializeType	c_database_storage_type	=	CerializeType_Raw;
	
	//	if record typing, we already have our type in the record we are unpacking
	//	if store typing, get key or data type from storeType setting
  if (	(			key_not_data 
            &&	( rb_key_storage_class	= rb_RPbdb_DatabaseRecordReadWriteSettingsController_storeKeyTyping( rb_database_record_read_write_settings_controller ) ) != Qfalse )
        ||	(		rb_data_storage_class	= rb_RPbdb_DatabaseRecordReadWriteSettingsController_storeDataTyping( rb_database_record_read_write_settings_controller ) ) != Qfalse )	{
		
		if ( key_not_data )	{
			c_database_storage_type	=	Rcerialize_storageTypeForRubyClass( rb_key_storage_class );
		}
		else {
			c_database_storage_type	=	Rcerialize_storageTypeForRubyClass( rb_data_storage_class );
		}
    
    //  set type - write, etc., will remove type
    CerializedData_setType( c_cerialized_data,
                            c_database_storage_type );
    
	}
	//	if no typing, type remains CerializeType_Raw  

	//	unpack dbt for RPbdbType (Raw stores as string)
	//	FIX - structs won't work yet, since as_class doesn't work yet
	VALUE	rb_return	=	Rcerialize_unpackRubyInstance(	c_cerialized_data,
																										Qnil );
	
	return rb_return;
}

//	for convenience
void bdbstat( RPbdb_Database* database );
void bdbstat( RPbdb_Database* database )	{
	database->wrapped_bdb_database->stat_print( database->wrapped_bdb_database, DB_STAT_ALL );
}

