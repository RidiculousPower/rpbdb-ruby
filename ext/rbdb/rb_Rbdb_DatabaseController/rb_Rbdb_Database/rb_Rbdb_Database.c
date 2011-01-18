/*
 *		Rbdb::DatabaseController::Database
 *
 *
 */

#include "rb_Rbdb.h"
#include "rb_Rbdb_internal.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_DatabaseObject_internal.h"
#include "rb_Rbdb_Database_internal.h"
#include "rb_Rbdb_DatabaseController.h"

#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Environment.h"

#include "rb_Rbdb_DatabaseCursorController.h"
#include "rb_Rbdb_DatabaseCursor.h"
#include "rb_Rbdb_DatabaseJoinController.h"
#include "rb_Rbdb_DatabaseJoinCursor.h"
#include "rb_Rbdb_DatabaseSequenceController.h"
#include "rb_Rbdb_DatabaseSequence.h"

#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"

#include "rb_Rbdb_DatabaseRecordReadWriteSettingsController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseCursor.h>
#include <rbdb/Rbdb_Database_internal.h>
#include <rbdb/Rbdb_Data_internal.h>
#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_DatabaseCursorController.h>
#include <rbdb/Rbdb_DatabaseJoinController.h>

#include <rbdb/Rbdb_Record.h>
#include <rbdb/Rbdb_Key.h>
#include <rbdb/Rbdb_Data.h>
#include <rbdb/Rbdb_DBT.h>
#include <rbdb/Rbdb_DBT_internal.h>
#include <rbdb/Rbdb_SecondaryKeys.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordReadWriteSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>

#include <rargs.h>

#include <string.h>

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_BtreeDatabase;
extern	VALUE	rb_Rbdb_HashDatabase;
extern	VALUE	rb_Rbdb_QueueDatabase;
extern	VALUE	rb_Rbdb_RecnoDatabase;
extern	VALUE	rb_Rbdb_DatabaseCursor;
extern	VALUE	rb_Rbdb_DatabaseObjectCursor;
extern	VALUE	rb_Rbdb_DatabaseCursorController;
extern	VALUE	rb_Rbdb_DatabaseJoinController;
extern	VALUE	rb_Rbdb_DatabaseSequenceController;

extern	VALUE	rb_Rbdb_Key;
extern	VALUE	rb_Rbdb_Data;
extern	VALUE	rb_Rbdb_SecondaryKeys;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;

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

extern VALUE rb_Rbdb_DatabaseType_const_module;
extern VALUE rb_Rbdb_DatabaseBtreeType_const;
extern VALUE rb_Rbdb_DatabaseHashType_const;
extern VALUE rb_Rbdb_DatabaseQueueType_const;
extern VALUE rb_Rbdb_DatabaseRecnoType_const;

#define RBDB_RUBY_ERROR_INVALID_DATABASE_DATA			"Provided data was invalid. Database requires object that can be automatically converted to string."

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_Rbdb_Database()	{

	rb_Rbdb_Database		=	rb_define_class_under(	rb_mRbdb, 
																								"Database",
																								rb_cObject );

	rb_Rbdb_DatabaseType_const_module			=	rb_define_module_under(	rb_Rbdb_Database,
																																	"Type" );
																																	
	rb_define_const(						rb_Rbdb_DatabaseType_const_module,		"Btree",						rb_str_new2( "Btree" ) );
	rb_Rbdb_DatabaseBtreeType_const	=	rb_const_get(	rb_Rbdb_DatabaseType_const_module,		rb_intern( "Btree" ) );
	rb_define_const(						rb_Rbdb_DatabaseType_const_module,		"Hash",							rb_str_new2( "Hash" ) );
	rb_Rbdb_DatabaseHashType_const	=	rb_const_get(	rb_Rbdb_DatabaseType_const_module,		rb_intern( "Hash" ) );
	rb_define_const(						rb_Rbdb_DatabaseType_const_module,		"Queue",						rb_str_new2( "Queue" ) );
	rb_Rbdb_DatabaseQueueType_const	=	rb_const_get(	rb_Rbdb_DatabaseType_const_module,		rb_intern( "Queue" ) );
	rb_define_const(						rb_Rbdb_DatabaseType_const_module,		"Recno",						rb_str_new2( "Recno" ) );
	rb_Rbdb_DatabaseRecnoType_const	=	rb_const_get(	rb_Rbdb_DatabaseType_const_module,		rb_intern( "Recno" ) );

	rb_define_singleton_method(	rb_Rbdb_Database, 	"new",																					rb_Rbdb_Database_new,																				-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"initialize",																		rb_Rbdb_Database_initialize,																			-1 	);

	rb_define_singleton_method(	rb_Rbdb_Database, 	"use",																					rb_Rbdb_Database_use,																				-1 	);

	rb_define_method(						rb_Rbdb_Database, 	"settings_controller",													rb_Rbdb_Database_settingsController,												0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"settings",																			"settings_controller"	);                            				
	rb_define_alias(						rb_Rbdb_Database, 	"set",																					"settings_controller"	);                            				
	rb_define_alias(						rb_Rbdb_Database, 	"set_to",																				"settings_controller"	);                            				
	rb_define_alias(						rb_Rbdb_Database, 	"is_set_to",																		"settings_controller"	);                            				
	rb_define_method(						rb_Rbdb_Database, 	"parent_environment",														rb_Rbdb_Database_parentEnvironment,													0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"parent_environment",														"parent_environment"	);                            				
	rb_define_alias(						rb_Rbdb_Database, 	"environment",																	"parent_environment"	);                            				

	rb_define_method(						rb_Rbdb_Database, 	"filename",																			rb_Rbdb_Database_filename,																	0 	);
	rb_define_method(						rb_Rbdb_Database, 	"name",																					rb_Rbdb_Database_name,																			0 	);
	rb_define_method(						rb_Rbdb_Database, 	"rename",																				rb_Rbdb_Database_rename,																		1 	);
	rb_define_method(						rb_Rbdb_Database, 	"handle",																				rb_Rbdb_Database_handle,																		0 	);

	rb_define_method(						rb_Rbdb_Database, 	"open",																					rb_Rbdb_Database_open,																			0 	);
	rb_define_method(						rb_Rbdb_Database, 	"is_open?",																			rb_Rbdb_Database_isOpen,																		0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"open?",																				"is_open?"	);                                        				
	rb_define_method(						rb_Rbdb_Database, 	"close",																				rb_Rbdb_Database_close,																			0 	);
	rb_define_method(						rb_Rbdb_Database, 	"empty!",																				rb_Rbdb_Database_empty,																			0 	);
	rb_define_method(						rb_Rbdb_Database, 	"erase!",																				rb_Rbdb_Database_erase,																			0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"delete!",																			"erase!"	);                            				
	rb_define_method(						rb_Rbdb_Database, 	"sync!",																				rb_Rbdb_Database_sync,																			0 	);

	rb_define_method(						rb_Rbdb_Database, 	"key_exists?",																	rb_Rbdb_Database_keyExists,																	-1 	);
	rb_define_alias(						rb_Rbdb_Database, 	"exists?",																			"key_exists?" );                                    				
	rb_define_method(						rb_Rbdb_Database, 	"all_keys_exist?",															rb_Rbdb_Database_keysExist,																	-1 	);
	rb_define_alias(						rb_Rbdb_Database, 	"keys_exist?",																	"all_keys_exist?" );                                    				
	rb_define_method(						rb_Rbdb_Database, 	"write",																				rb_Rbdb_Database_write,																			-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"retrieve",																			rb_Rbdb_Database_retrieve,																	-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"retrieve_primary_key",													rb_Rbdb_Database_retrievePrimaryKey,												-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"delete",																				rb_Rbdb_Database_delete,																		-1 	);
                    					                                                                                                                        				
	rb_define_method(						rb_Rbdb_Database, 	"is_secondary_database?",												rb_Rbdb_Database_isSecondary,																0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"is_secondary_index?",													"is_secondary_database?"	);
	rb_define_alias(						rb_Rbdb_Database, 	"is_secondary?",																"is_secondary_database?"	);
	rb_define_alias(						rb_Rbdb_Database, 	"secondary_database?",													"is_secondary_database?"	);
	rb_define_alias(						rb_Rbdb_Database, 	"secondary_index?",															"is_secondary_database?"	);
	rb_define_alias(						rb_Rbdb_Database, 	"secondary?",																		"is_secondary_database?"	);
	rb_define_method(						rb_Rbdb_Database, 	"primary_database",															rb_Rbdb_Database_primaryDatabase,																0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"primary",																			"primary_database"	);
	rb_define_method(						rb_Rbdb_Database, 	"secondary_key_creation_callback_method",				rb_Rbdb_Database_secondaryKeyCreationCallbackMethod,				0 	);
	rb_define_method(						rb_Rbdb_Database, 	"create_secondary_index",												rb_Rbdb_Database_createSecondaryIndex,											-1 	);
	rb_define_alias(						rb_Rbdb_Database, 	"has_secondary_index",													"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"has_index",																		"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"create_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"new_secondary",																"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"new_index",																		"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"associate_secondary_database",									"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"associate_secondary",													"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"associate",																		"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"use_as_secondary_index",												"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"use_as_secondary",															"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"create_secondary_index_with_database",					"create_secondary_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"create_secondary_with_database",								"create_secondary_index"	);
	rb_define_method(						rb_Rbdb_Database, 	"create_secondary_index_with_unsorted_duplicates",	rb_Rbdb_Database_createSecondaryIndexWithUnsortedDuplicates,											-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"create_secondary_index_with_sorted_duplicates",	rb_Rbdb_Database_createSecondaryIndexWithSortedDuplicates,											-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"set_unique_for_index",													rb_Rbdb_Database_setUniqueForIndex,											-1 	);
	rb_define_method(						rb_Rbdb_Database, 	"unique_for_index",															rb_Rbdb_Database_uniqueForIndex,												-1 	);


	rb_define_method(						rb_Rbdb_Database, 	"secondary_database_with_index",								rb_Rbdb_Database_secondaryDatabaseWithIndex,								1 	);
	rb_define_alias(						rb_Rbdb_Database, 	"database_with_index",													"secondary_database_with_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"secondary_database",														"secondary_database_with_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"secondary",																		"secondary_database_with_index"	);
	rb_define_alias(						rb_Rbdb_Database, 	"index",																				"secondary_database_with_index"	);
                    					
	rb_define_method(						rb_Rbdb_Database, 	"verify",																				rb_Rbdb_Database_verify,																		0 	);

	rb_define_method(						rb_Rbdb_Database, 	"cursor_controller",														rb_Rbdb_Database_cursorController,													0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"cursors",																			"cursor_controller"	);
	rb_define_method(						rb_Rbdb_Database, 	"cursor",																				rb_Rbdb_Database_cursor,																		0 	);
	rb_define_method(						rb_Rbdb_Database, 	"object_cursor",																rb_Rbdb_Database_objectCursor,															0 	);

	rb_define_method(						rb_Rbdb_Database, 	"iterate",																			rb_Rbdb_Database_iterate,																		0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"each",																					"iterate"	);
	rb_define_method(						rb_Rbdb_Database, 	"iterate_duplicates",														rb_Rbdb_Database_iterateDuplicates,													0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"each_duplicate",																"iterate_duplicates"	);
	rb_define_method(						rb_Rbdb_Database, 	"iterate_keys",																	rb_Rbdb_Database_iterateKeys,																0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"each_key",																			"iterate_keys"	);

	rb_define_method(						rb_Rbdb_Database, 	"sequence_controller",													rb_Rbdb_Database_sequenceController,													-1 	);
	rb_define_alias(						rb_Rbdb_Database, 	"sequences",																		"sequence_controller"	);
	rb_define_alias(						rb_Rbdb_Database, 	"sequence",																			"sequence_controller"	);

	rb_define_method(						rb_Rbdb_Database, 	"join_controller",															rb_Rbdb_Database_joinController,													0 	);
	rb_define_alias(						rb_Rbdb_Database, 	"joins",																				"join_controller"	);
	rb_define_alias(						rb_Rbdb_Database, 	"join",																					"join_controller"	);

	rb_Rbdb_BtreeDatabase		=	rb_define_class_under(		rb_Rbdb_Database, 
																											"Btree",
																											rb_Rbdb_Database );
	rb_define_singleton_method(	rb_Rbdb_BtreeDatabase, 	"new",																					rb_Rbdb_Database_new,																					-1 	);
	rb_define_method(						rb_Rbdb_BtreeDatabase, 	"initialize",																		rb_Rbdb_Database_initialize,																	-1 	);

	rb_Rbdb_HashDatabase		=	rb_define_class_under(		rb_Rbdb_Database, 
																											"Hash",
																											rb_Rbdb_Database );
	rb_define_singleton_method(	rb_Rbdb_HashDatabase, 	"new",																					rb_Rbdb_Database_new,																					-1 	);
	rb_define_method(						rb_Rbdb_HashDatabase, 	"initialize",																		rb_Rbdb_Database_initialize,																	-1 	);

	rb_Rbdb_RecnoDatabase		=	rb_define_class_under(		rb_Rbdb_Database, 
																											"Recno",
																											rb_Rbdb_Database );
	rb_define_singleton_method(	rb_Rbdb_RecnoDatabase, 	"new",																					rb_Rbdb_Database_new,																					-1 	);
	rb_define_method(						rb_Rbdb_RecnoDatabase, 	"initialize",																		rb_Rbdb_Database_initialize,																	-1 	);

	rb_Rbdb_QueueDatabase		=	rb_define_class_under(		rb_Rbdb_Database, 
																											"Queue",
																											rb_Rbdb_Database );
	rb_define_singleton_method(	rb_Rbdb_QueueDatabase, 	"new",																					rb_Rbdb_Database_new,																					-1 	);
	rb_define_method(						rb_Rbdb_QueueDatabase, 	"initialize",																		rb_Rbdb_Database_initialize,																	-1 	);

}

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_Rbdb_Database_new(	int			argc,
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
				R_OptionalParameter(	R_MatchAncestorInstance(					rb_parent_environment,							rb_Rbdb_Environment ),
															R_MatchAncestorInstance(					rb_parent_database_controller,			rb_Rbdb_DatabaseController ),
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
				R_Parameter(					R_MatchAncestorInstance(					rb_parent_environment,							rb_Rbdb_Environment ),
															R_MatchAncestorInstance(					rb_parent_database_controller,			rb_Rbdb_DatabaseController ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if ( rb_parent_environment_path != Qnil )	{
		rb_parent_environment	=	rb_Rbdb_Environment_new(	1,
																											& rb_parent_environment_path,
																											rb_Rbdb_Environment );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_database_controller = rb_Rbdb_Environment_databaseController( rb_parent_environment );
	}
	
	Rbdb_DatabaseController*	c_parent_database_controller;
	char*	c_database_name		=	NULL;
	if ( rb_database_name != Qnil )	{
		rb_database_name	=	rb_obj_as_string( rb_database_name );
		c_database_name	=	StringValuePtr( rb_database_name );
	}
	else {
		rb_raise( rb_eArgError, "Database name is required to be non-nil." );
	}

	C_RBDB_DATABASE_CONTROLLER( rb_parent_database_controller, c_parent_database_controller );
	
	Rbdb_Database*	c_database	=	Rbdb_DatabaseController_newDatabase(	c_parent_database_controller,
																																			c_database_name );
	
	Rbdb_DatabaseSettingsController*			c_database_settings_controller				=	Rbdb_Database_settingsController( c_database );
	Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller		=	Rbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	DBTYPE	c_database_type	=	DB_UNKNOWN;

	if ( rb_database_type != Qnil )	{
		
		if ( TYPE( rb_database_type ) != T_STRING )	{
			rb_database_type = rb_obj_as_string( rb_database_type );
		}
		char*	c_database_type_string	=	StringValuePtr( rb_database_type );

		if (			strcmp( c_database_type_string, "Btree" ) == 0 )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
			c_database_type	=	DB_BTREE;
		}
		else if ( strcmp( c_database_type_string, "Hash" ) == 0 )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
			c_database_type	=	DB_HASH;
		}
		else if ( strcmp( c_database_type_string, "Queue" ) == 0 )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
			c_database_type	=	DB_QUEUE;
		}
		else if ( strcmp( c_database_type_string, "Recno" ) == 0 )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
			c_database_type	=	DB_RECNO;
		}
	}
	else if ( rb_klass_self != rb_Rbdb_Database )	{
		
		if (			rb_klass_self == rb_Rbdb_BtreeDatabase )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
			c_database_type	=	DB_BTREE;
		}
		else if (	rb_klass_self == rb_Rbdb_HashDatabase )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToHash( c_database_type_settings_controller );
			c_database_type	=	DB_HASH;
		}
		else if (	rb_klass_self == rb_Rbdb_QueueDatabase )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToQueue( c_database_type_settings_controller );
			c_database_type	=	DB_QUEUE;
		}
		else if (	rb_klass_self == rb_Rbdb_RecnoDatabase )	{
			Rbdb_DatabaseTypeSettingsController_setTypeToRecno( c_database_type_settings_controller );
			c_database_type	=	DB_RECNO;
		}
		else {
			c_database_type	=	DB_UNKNOWN;
		}

	}
	else {
		c_database_type	=	Rbdb_DatabaseTypeSettingsController_databaseType( c_database_type_settings_controller );
	}

	VALUE	rb_database	=	Qnil;
	switch ( c_database_type )	{
		
		case DB_BTREE:
			rb_database	=	RUBY_RBDB_BTREE_DATABASE( c_database );
			break;
			
		case DB_HASH:
			rb_database	=	RUBY_RBDB_HASH_DATABASE( c_database );
			break;

		case DB_QUEUE:
			rb_database	=	RUBY_RBDB_QUEUE_DATABASE( c_database );
			break;

		case DB_RECNO:
			rb_database	=	RUBY_RBDB_RECNO_DATABASE( c_database );
			break;

		default:
			rb_raise( rb_eArgError, "Unknown database type." );
			break;
		
	}

	//	store reference to parent
	rb_iv_set(	rb_database,
							RBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER,
							rb_parent_database_controller );
	
	//	store reference to ruby instance by c instance
	rb_Rbdb_Database_internal_storeRubyRuntimeInstanceForCInstance( rb_database );

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
VALUE rb_Rbdb_Database_initialize(	int			argc __attribute__((unused)),
																		VALUE*	args __attribute__((unused)),
																		VALUE		rb_database_self )	{
		
	return rb_database_self;
}

/********
*  use  *
********/

VALUE rb_Rbdb_Database_use(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self )	{
	
	VALUE	rb_database	=	rb_Rbdb_Database_new(	argc,
																						args,
																						rb_klass_self );
	
	//	returns non-db value if block is run in open
	rb_database = rb_Rbdb_Database_open( rb_database );
	
	return rb_database;
}

/************************
*  settings_controller  *
*  settings             *
************************/
VALUE rb_Rbdb_Database_settingsController( VALUE	rb_database )	{

	VALUE	rb_local_database_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_settings_controller = rb_iv_get(	rb_database,
																														RBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_local_database_settings_controller	=	rb_Rbdb_DatabaseSettingsController_new(	1,
																																										& rb_database,
																																										rb_Rbdb_DatabaseSettingsController );
		rb_iv_set(	rb_database,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER,
								rb_local_database_settings_controller );
	}

	return rb_local_database_settings_controller;
}

/***********************
*  parent_environment  *
*  environment         *
***********************/

VALUE rb_Rbdb_Database_parentEnvironment(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_Rbdb_Database_parentDatabaseController( rb_database );
	VALUE	rb_parent_environment					=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/*******************************
*  parent_database_controller  *
*  database_controller         *
*  controller                  *
*******************************/

VALUE rb_Rbdb_Database_parentDatabaseController(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_iv_get(	rb_database,
																										RBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER );

	return rb_parent_database_controller;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************
*  filename  *
*************/

VALUE rb_Rbdb_Database_filename( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	return rb_str_new2( Rbdb_Database_filename( c_database ) );	
}

/*********
*  name  *
*********/

VALUE rb_Rbdb_Database_name( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	char*	c_database_name		=	Rbdb_Database_name( c_database );
	VALUE	rb_database_name	=	rb_str_new2( c_database_name );

	return rb_database_name;	
}

/***********
*  rename  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_rename.html
VALUE rb_Rbdb_Database_rename(	VALUE	rb_database,
																VALUE	rb_name	)	{
	
	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	rb_name	=	rb_obj_as_string( rb_name );

	char*	c_name	=	StringValuePtr( rb_name );

	Rbdb_Database_rename(	c_database,
												c_name );
						
	return rb_database;
}

/***********
*  handle  *
***********/

VALUE rb_Rbdb_Database_handle( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	VALUE	rb_database_name		=	rb_Rbdb_Database_name( rb_database );
	VALUE	rb_database_handle	=	STRING2SYM( rb_database_name );

	return rb_database_handle;	
}

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_Rbdb_Database_open( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	Rbdb_Database_open( c_database );

	if ( rb_block_given_p() )	{
		VALUE	rb_return	=	rb_yield( rb_database );
		rb_Rbdb_Database_close( rb_database );
		return rb_return;
	}

	return rb_database;
}

/*************
*  is_open?  *
*************/

VALUE rb_Rbdb_Database_isOpen( VALUE	rb_database )	{
	
	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );
	
	if ( Rbdb_Database_isOpen( c_database ) )	{
		return Qtrue;
	}
	
	return Qfalse;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_Rbdb_Database_close( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	rb_Rbdb_Database_internal_removeCallbackInfoFromHash( rb_database );
	
	Rbdb_Database_close( c_database );

	return rb_database;
}

/***********
*  empty!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_truncate.html
VALUE rb_Rbdb_Database_empty( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	Rbdb_Database_empty( c_database );

	return rb_database;
}

/***********
*  erase!  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_remove.html
VALUE rb_Rbdb_Database_erase( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	Rbdb_Database_erase( c_database );

	return rb_database;
}

/*********
*  copy  *
*********/

//	Duplicate in Same Environment (requires resetIDs)
	/*
VALUE rb_Rbdb_Database_copy( VALUE	rb_database )	{
	Rbdb_Database_copy();

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
VALUE rb_Rbdb_Database_copyToForeignEnvironment( VALUE	rb_database )	{
	Rbdb_Database_copyToForeignEnvironment();

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
VALUE rb_Rbdb_Database_sync( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	Rbdb_Database_sync( c_database );

	return rb_database;	
}

/******************
*  is_secondary?  *
******************/

VALUE rb_Rbdb_Database_isSecondary(	VALUE	rb_database )	{
	
	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	BOOL	c_is_secondary	=	Rbdb_Database_isSecondary( c_database );
	
	VALUE	rb_is_secondary	=	c_is_secondary ? Qtrue : Qfalse;

	return rb_is_secondary;
}

/*********************
*  primary_database  *
*********************/

VALUE rb_Rbdb_Database_primaryDatabase(	VALUE	rb_primary_or_secondary_database )	{
	
	Rbdb_Database*		c_primary_or_secondary_database;
	C_RBDB_DATABASE( rb_primary_or_secondary_database, c_primary_or_secondary_database );
	
	if ( Rbdb_Database_isSecondary( c_primary_or_secondary_database ) == FALSE )	{
		return rb_primary_or_secondary_database;
	}
	
	Rbdb_Database*		c_primary_database	=	NULL;
	c_primary_database	=	Rbdb_Database_primaryDatabase( c_primary_or_secondary_database );
	
	VALUE	rb_primary_database	=	Qnil;
	if ( c_primary_database != NULL )	{
		rb_primary_database	=	rb_Rbdb_Database_internal_rubyRuntimeInstanceForCInstance( c_primary_database );
	}

	return rb_primary_database;
}

/*************************
*  secondary_index_name  *
*************************/

//	primary returns nil
VALUE rb_Rbdb_Database_secondaryIndexName(	VALUE	rb_secondary_database )	{
	
	VALUE	rb_index	=	Qnil;
	if ( rb_Rbdb_Database_isSecondary( rb_secondary_database ) )	{
		Rbdb_Database*		c_secondary_database;
		C_RBDB_DATABASE( rb_secondary_database, c_secondary_database );
		rb_index	=	ID2SYM( rb_intern( c_secondary_database->index_name ) );
	}
	return rb_index;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

VALUE rb_Rbdb_Database_secondaryKeyCreationCallbackMethod(	int			argc,
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
	if ( rb_Rbdb_Database_isSecondary( rb_primary_or_secondary_database ) == Qtrue )	{
		rb_primary_database	=	rb_Rbdb_Database_primaryDatabase( rb_primary_or_secondary_database );
		rb_index						=	rb_Rbdb_Database_secondaryIndexName( rb_primary_or_secondary_database );
	}
	else {
		rb_primary_database	=	rb_primary_or_secondary_database;
	}
	
	if ( rb_index == Qnil )	{
		rb_raise( rb_eArgError, "Could not determine index name for secondary database." );
	}
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRbdb,
																				RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_primary_database_handle	=	rb_Rbdb_Database_handle( rb_primary_database );	
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
VALUE rb_Rbdb_Database_createSecondaryIndex(	int			argc, 
																							VALUE*	args,
																							VALUE		rb_primary_database_self	)	{

	return rb_Rbdb_Database_internal_createSecondaryIndex(	argc,
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
VALUE rb_Rbdb_Database_createSecondaryIndexWithUnsortedDuplicates(	int			argc, 
																														VALUE*	args,
																														VALUE		rb_primary_database_self	)	{

	return rb_Rbdb_Database_internal_createSecondaryIndex(	argc,
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
VALUE rb_Rbdb_Database_createSecondaryIndexWithSortedDuplicates(	int			argc, 
																																	VALUE*	args,
																																	VALUE		rb_primary_database_self	)	{

	return rb_Rbdb_Database_internal_createSecondaryIndex(	argc,
																													args,
																													rb_primary_database_self,
																													TRUE,
																													TRUE );

}

/**********************
*  databaseWithIndex  *
**********************/

VALUE rb_Rbdb_Database_databaseWithIndex(	VALUE	rb_primary_database,
																					VALUE	rb_index_name )	{
	
	VALUE	rb_which_database	=	Qnil;																																			
	if ( rb_index_name != Qnil )	{																																						
		rb_which_database	=	rb_Rbdb_Database_requireSecondaryDatabaseWithIndex(	rb_primary_database,			
																																						rb_index_name );								
	}																																																		
	else {																																															
		rb_which_database	=	rb_primary_database;																													
	}																																																		

	return rb_which_database;
}

/******************************
*  secondaryDatabaseWithIndex  *
******************************/

VALUE rb_Rbdb_Database_secondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																										VALUE	rb_index_name )	{
	
	//	make sure that store/retrieve by symbol
	if ( TYPE( rb_index_name ) == T_STRING )	{
		rb_index_name	=	STRING2SYM( rb_index_name );
	}
	
	VALUE	rb_secondary_database_hash	=	rb_Rbdb_Database_secondaryDatabaseHash( rb_primary_database );
	
	VALUE	rb_database_with_index			=	rb_hash_aref(	rb_secondary_database_hash,
																										rb_index_name );
																									
	return rb_database_with_index;
}

/*************************************
*  requireSecondaryDatabaseWithIndex  *
*************************************/

VALUE rb_Rbdb_Database_requireSecondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																													VALUE	rb_index_name )	{
	
	VALUE	rb_database_with_index				=	rb_Rbdb_Database_secondaryDatabaseWithIndex(	rb_primary_database,
																																											rb_index_name );

	if ( rb_database_with_index == Qnil )	{
		rb_raise( rb_eArgError, "Requested secondary index %s was missing for database %s.",	RSTRING_PTR( rb_obj_as_string( rb_index_name ) ),
																																													RSTRING_PTR( rb_Rbdb_Database_name( rb_primary_database ) ) );
	}
	return rb_database_with_index;
}

/**************************
*  secondaryDatabaseHash  *
**************************/

VALUE rb_Rbdb_Database_secondaryDatabaseHash( VALUE rb_primary_database )	{
	
	VALUE	rb_secondary_database_hash	=	rb_iv_get(	rb_primary_database,
																									RBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES );
	if ( rb_secondary_database_hash == Qnil )	{
		rb_secondary_database_hash = rb_hash_new();
		rb_iv_set(	rb_primary_database,
								RBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES,
								rb_secondary_database_hash );
	}
	return rb_secondary_database_hash;
}

/************
*  compact  *
************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
VALUE rb_Rbdb_Database_compact(	VALUE	rb_database, 
									VALUE	start_record, 
									VALUE	stop_record )	{
	Rbdb_Database_compact();


}

VALUE rb_Rbdb_Database_compactAllRecords( VALUE	rb_database )	{
	Rbdb_Database_compactAllRecords();


}
*/
/****************
*  upgrade  *
****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_upgrade.html
VALUE rb_Rbdb_Database_upgrade( VALUE	rb_database )	{
	Rbdb_Database_upgrade();

}
*/
/************************
*  resetDatabaseIDs  *
************************/
/*
//	For copying database and using duplicate in same environment 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
VALUE rb_Rbdb_Database_resetDatabaseIDs( VALUE	rb_database )	{
	Rbdb_Database_resetDatabaseIDs();

}
*/
/****************************************
*  prepareDatabaseForFileTransfer  *
****************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_lsn_reset.html
VALUE rb_Rbdb_Database_prepareDatabaseForFileTransfer( VALUE	rb_database )	{
	Rbdb_Database_prepareDatabaseForFileTransfer();
	
}
*/

/**********************
*  unique_for_index?  *
**********************/

VALUE rb_Rbdb_Database_uniqueForIndex(	int			argc,
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
		VALUE																							rb_database_for_index												=	rb_Rbdb_Database_secondaryDatabaseWithIndex(	rb_database,
																																																																									rb_this_index );
		Rbdb_Database*																		c_database_for_index;
		C_RBDB_DATABASE( rb_database_for_index, c_database_for_index );
		
		Rbdb_DatabaseSettingsController*									c_database_settings_controller							=	Rbdb_Database_settingsController( c_database_for_index );
		Rbdb_DatabaseRecordSettingsController*						c_database_record_settings_controller				=	Rbdb_DatabaseSettingsController_recordSettingsController( c_database_settings_controller );
		Rbdb_DatabaseRecordReadWriteSettingsController*		c_database_read_write_settings_controller		=	Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( c_database_record_settings_controller );
		BOOL	c_database_has_duplicates	=	Rbdb_DatabaseRecordReadWriteSettingsController_duplicates( c_database_read_write_settings_controller );
		if ( ! c_database_has_duplicates )	{
			rb_index_is_unique = Qtrue;
			break;
		}
	
	}	

	//	if we don't already have a unique index then we need to check for index combinations declared unique
	if ( rb_index_is_unique != Qtrue ) {
		
		VALUE	rb_unique_indexes_for_database	=	rb_Rbdb_Database_internal_uniqueIndexesHash( rb_database );	

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

VALUE rb_Rbdb_Database_setUniqueForIndex(	int			argc,
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
	
	VALUE	rb_unique_indexes_for_database	=	rb_Rbdb_Database_internal_uniqueIndexesHash( rb_database );	

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

/***********
*  cursor  *
***********/

VALUE rb_Rbdb_Database_cursor( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_Rbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_Rbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );
		
	return rb_database_cursor;
}	

/*************
*  cursor  *
************/

VALUE rb_Rbdb_Database_objectCursor( VALUE	rb_database )	{

	VALUE	rb_database_cursor_controller	=	rb_Rbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_Rbdb_DatabaseCursorController_objectCursor( rb_database_cursor_controller );

	return rb_database_cursor;
}	

/************
*  iterate  *
************/

VALUE rb_Rbdb_Database_iterate( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor						=	rb_Rbdb_Database_cursor( rb_database );

	//	set the cursor position
	
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_Rbdb_DatabaseCursor_iterate(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_Rbdb_DatabaseCursor_iterate, rb_database_cursor,
											rb_Rbdb_DatabaseCursor_close, rb_database_cursor );
	}
	
	return rb_database;
}

/*****************
*  iterate_keys  *
*****************/

VALUE rb_Rbdb_Database_iterateKeys( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_Rbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_Rbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_Rbdb_DatabaseCursor_iterateKeys(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_Rbdb_DatabaseCursor_iterateKeys, rb_database_cursor,
											rb_Rbdb_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/*****************
*  iterate_keys  *
*****************/

VALUE rb_Rbdb_Database_iterateDuplicates( VALUE	rb_database )	{
	
	VALUE	rb_database_cursor_controller	=	rb_Rbdb_Database_cursorController( rb_database );	
	VALUE	rb_database_cursor						=	rb_Rbdb_DatabaseCursorController_cursor( rb_database_cursor_controller );

	//	set the cursor position
	rb_funcall(	rb_database_cursor,
							rb_intern( "first" ),
							0 );

	//	if we have a block we can simply let our function iterate and return self
	if ( rb_block_given_p() )	{
		rb_Rbdb_DatabaseCursor_iterateDuplicates(	rb_database_cursor	);		
	}
	//	otherwise we return the enumerator and let the user catch the exception to finish
	else {
		return rb_ensure( rb_Rbdb_DatabaseCursor_iterateDuplicates, rb_database_cursor,
											rb_Rbdb_DatabaseCursor_close, rb_database_cursor );
	}

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*************************
*  cursorController  *
*************************/

VALUE rb_Rbdb_Database_cursorController( VALUE	rb_database )	{

	VALUE	rb_cursor_controller	=	Qnil;
	
	if ( ( rb_cursor_controller = rb_iv_get(	rb_database,
																						RBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Database*		c_database;
		C_RBDB_DATABASE( rb_database, c_database );

		rb_cursor_controller	=	rb_Rbdb_DatabaseCursorController_new(	1,
																																	& rb_database,
																																	rb_Rbdb_DatabaseCursorController );

		rb_iv_set(	rb_database,
								RBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER,
								rb_cursor_controller );
	}

	return rb_cursor_controller;
}

/*******************
*  joinController  *
*******************/

VALUE rb_Rbdb_Database_joinController( VALUE	rb_database )	{
	
	VALUE	rb_join_controller	=	Qnil;
	
	if ( ( rb_join_controller = rb_iv_get(	rb_database,
																					RBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Database*		c_database;
		C_RBDB_DATABASE( rb_database, c_database );
	
		rb_join_controller	=	rb_Rbdb_DatabaseJoinController_new(	1,
																															& rb_database,
																															rb_Rbdb_DatabaseJoinController );

		rb_iv_set(	rb_database,
								RBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER,
								rb_join_controller );
	}

	return rb_join_controller;
}

/***********************
*  sequenceController  *
***********************/

VALUE rb_Rbdb_Database_sequenceController(	int			argc,
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
																							RBDB_RB_DATABASE_SEQUENCE_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Database*		c_database;
		C_RBDB_DATABASE( rb_database, c_database );
	
		rb_sequence_controller	=	rb_Rbdb_DatabaseSequenceController_new(	1,
																																			& rb_database,
																																			rb_Rbdb_DatabaseSequenceController );

		rb_iv_set(	rb_database,
								RBDB_RB_DATABASE_SEQUENCE_CONTROLLER,
								rb_sequence_controller );
	}

	//	if a sequence was specified, return it instead of the controller
	if ( rb_sequence_name != Qnil )	{
		return rb_Rbdb_DatabaseSequenceController_sequence(	rb_sequence_controller,
																												rb_sequence_name );
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
VALUE rb_Rbdb_Database_write(	int			argc, 
															VALUE*	args, 
															VALUE		rb_primary_database )	{

	VALUE	rb_key																			=	Qnil;
	VALUE	rb_data																			=	Qnil;
	VALUE	rb_hash_descriptor_key_data_or_datas_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_primary_database,

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
	
	VALUE	rb_return	=	rb_primary_database;
	
	if (				rb_hash_descriptor_key_data_or_datas_array != Qnil ) {

		R_IterateHashDescriptor(	rb_hash_descriptor_key_data_or_datas_array, 
															rb_Rbdb_Database_write );

	}
	else if (		rb_key != Qnil
					&&	rb_args_array != Qnil )	{
		
		R_IterateArrayDescriptor(	rb_args_array,
															rb_Rbdb_Database_write,
															rb_key  );
	}
	else if (		rb_args_array != Qnil )	{
	
		R_IterateArrayDescriptor(	rb_args_array,
															rb_Rbdb_Database_write  );

	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		Rbdb_Database*	c_database	=	NULL;
		Rbdb_Record*		c_record		=	NULL;

		do {
			
			C_RBDB_DATABASE( rb_primary_database, c_database );
			
			c_record	=	rb_Rbdb_Database_internal_recordForRubyKeyData(	rb_primary_database,
																																	rb_key,
																																	rb_data );
			
			Rbdb_Database_write(	c_database,
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
VALUE rb_Rbdb_Database_append(	VALUE	rb_database,
																VALUE	append_record	)	{
	Rbdb_Database_appendRecord();

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
VALUE rb_Rbdb_Database_keyExists(	int			argc,
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
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(		rb_index ) ),
												R_Parameter(	R_MatchArray(			rb_args_array ) ) ),
			R_ListOrder( 4 ),
			":index,  [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
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
																					rb_Rbdb_Database_keyExists );

	}
	else if (		rb_args_array != Qnil )	{
		
		rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																					rb_Rbdb_Database_keyExists  );

		rb_return = R_SimplifyArray( rb_return );
	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
			
		Rbdb_Database*		c_database;
		VALUE	rb_database	=	rb_Rbdb_Database_databaseWithIndex( rb_database,
																														rb_index );
		C_RBDB_DATABASE( rb_database, c_database );

		Rbdb_Key*	c_key	=	Rbdb_Key_new( NULL );

		VALUE		rb_result				=	Qnil;
		VALUE		rb_return_array	=	rb_ary_new();

		do {
			
			rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																												rb_key,
																												c_key,
																												TRUE );

			rb_result	=	( Rbdb_Database_keyExists(	c_database,
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

/***************
*  keys_exist  *
***************/

//	returns if the specified keys all appear in the database
VALUE rb_Rbdb_Database_keysExist(	int			argc,
																	VALUE*	args,
																	VALUE		rb_database )	{

	//	we need at least one key
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
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(		rb_index ) ),
												R_Parameter(	R_MatchArray(			rb_args_array ) ) ),
			R_ListOrder( 4 ),
			":index,  [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
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
																					rb_Rbdb_Database_keysExist );

	}
	else if (		rb_args_array != Qnil )	{
		
		rb_return	=	rb_ary_new();
		
		VALUE	rb_secondary_database	=	Qnil;
		if ( rb_index != Qnil )	{
			rb_secondary_database	=	rb_Rbdb_Database_secondaryDatabaseWithIndex(	rb_database,
																																						rb_index );
		}
		
		do {
		
			VALUE rb_key_exists	=	rb_Rbdb_Database_keysExist(	RARRAY_LEN( rb_args_array ),
																												RARRAY_PTR( rb_args_array ),
																												( rb_secondary_database == Qnil ? rb_database : rb_secondary_database ) );
			rb_ary_push(	rb_return,
										rb_key_exists );

		}	while ( R_Arg( rb_args_array ) );
		
	}
	//	rb_index, rb_key and rb_key
	else if (		rb_key != Qnil )	{
				
		VALUE	rb_args_with_index[]	=	{ rb_index, rb_key };

		VALUE	rb_keys_exist	=	Qtrue;

		//	for each key
		do	{
			//	check if key exists
			if ( rb_index != Qnil )	{
				if ( ( rb_keys_exist	=	rb_Rbdb_Database_keyExists(	2,
																														rb_args_with_index,
																														rb_database ) ) == Qfalse )	{
					break;
				}
			}
			else if ( ( rb_keys_exist	=	rb_Rbdb_Database_keyExists(	1,
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
VALUE rb_Rbdb_Database_retrieve(	int			argc, 
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
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 2 ),
			":index, [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
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
	
	if (		rb_hash_descriptor_index_key_or_keys_array != Qnil ) {

		VALUE	rb_return_array	=	rb_ary_new();

		do	{

			if ( RHASH_SIZE( rb_hash_descriptor_index_key_or_keys_array ) == 1 )	{
			
				VALUE	rb_return_hash	=	R_IterateHashDescriptor(	rb_hash_descriptor_index_key_or_keys_array, 
																													rb_Rbdb_Database_retrieve );
				
				rb_return	=	R_SimplifyHash( rb_return_hash );
			}
			else {
					
				//	we want to perform a join here rather than multiple retrieves
				VALUE	rb_database_join_controller	=	rb_Rbdb_Database_joinController( rb_database );

				rb_return	=	rb_Rbdb_DatabaseJoinController_join(	1,
																													& rb_hash_descriptor_index_key_or_keys_array,
																													rb_database_join_controller );
				
				//	if we have a unique index, return the data
				VALUE	rb_indexes	=	rb_funcall(	rb_hash_descriptor_index_key_or_keys_array,
																				rb_intern( "keys" ),
																				0 );
				if ( rb_Rbdb_Database_uniqueForIndex( RARRAY_LEN( rb_indexes ),
																							RARRAY_PTR( rb_indexes ),
																							rb_database ) == Qtrue )	{
					//	get first (only) data from join
					VALUE	rb_return_enumerator	=	rb_Rbdb_DatabaseCursor_iterate( rb_return );
					//	get key/data
					VALUE	rb_return_key_data_pair_array	=	rb_return	=	rb_funcall(	rb_return_enumerator,
																																				rb_intern( "next" ),
																																				0 );
					//	we want the data
					rb_return = RARRAY_PTR( rb_return_key_data_pair_array )[1];
				}
					
			}

			rb_ary_push(	rb_return_array,
										rb_return );

		}	while ( R_Arg( rb_hash_descriptor_index_key_or_keys_array ) );

		rb_return	=	R_SimplifyArray( rb_return_array );

	}
	//	index or key plus args array
	else if ( rb_args_array != Qnil )	{

		if ( rb_index != Qnil )	{

			do {

				rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																							rb_Rbdb_Database_retrieve,
																							rb_index );

			}	while ( R_Arg( rb_args_array ) );

			rb_return =	R_SimplifyArray( rb_return );

		}
		else {
			
			rb_return = R_SplatArrayDescriptor(	rb_args_array,
																					rb_Rbdb_Database_retrieve	);

		}
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		Rbdb_Database*	c_database	=	NULL;
		Rbdb_Record*		c_record		=	NULL;

		rb_database	=	rb_Rbdb_Database_databaseWithIndex( rb_database,
																											rb_index );
		C_RBDB_DATABASE( rb_database, c_database );

		rb_return		=	rb_ary_new();

		VALUE	rb_data			=	Qnil;

		do {
			
			c_record	=	rb_Rbdb_Database_internal_recordForRubyKey(	rb_database,
																															rb_key );

			c_record	=	Rbdb_Database_retrieveRecord(	c_database,
																								c_record );
			
			rb_data	=	rb_Rbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
																																		c_record->data,
																																		FALSE );
			
			rb_ary_push(	rb_return,
										rb_data );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	R_SimplifyArray( rb_return );
		
	}
	
	return rb_return;
}

/*************************
*  retrieve_primary_key  *
**************************/

//	database.retrieve_primary_key( :index, secondary_key )
//	database.retrieve_primary_key( :index => secondary_key_in_index )
//	database.retrieve_primary_key( :index => [ secondary_keys_in_index, ... ] )
//	database.retrieve_primary_key( [ any args ] )
VALUE rb_Rbdb_Database_retrievePrimaryKey(	int			argc, 
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
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 2 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 1 ),
			":index, [ <arg> ], ..."
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 3 ),
			":index, <key, ...>"
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 4 ),
			"[ <arg> ], ..."
		)
		
		//----------------------------------------------//

	)
	
	VALUE	rb_return	=	Qnil;
	
	if (		rb_hash_descriptor_index_key_or_keys_array != Qnil ) {

		//	we want to perform a join here rather than multiple retrieves
		VALUE	rb_database_join_controller	=	rb_Rbdb_Database_joinController( rb_database );
		rb_return	=	rb_ary_new();
		do	{
		
			VALUE	rb_join_cursor	=	rb_Rbdb_DatabaseJoinController_join(	1,
																																		& rb_hash_descriptor_index_key_or_keys_array,
																																		rb_database_join_controller );
			
			if ( rb_join_cursor != Qnil )	{
				
				//	make sure we can actually get a primary key from our join - this is true if
				//	* any one secondary database does not have duplicates
				//	* we have declared that the set of columns being joined produces a unique result					
				VALUE	rb_indexes	=	rb_funcall(	rb_hash_descriptor_index_key_or_keys_array,
																				rb_intern( "keys" ),
																				0 );																			
				if ( rb_Rbdb_Database_uniqueForIndex( RARRAY_LEN( rb_indexes ),
																							RARRAY_PTR( rb_indexes ),
																							rb_database ) == Qtrue )	{
					//	get primary key
					VALUE	rb_return_key	=	rb_funcall(	rb_join_cursor,
																						rb_intern( "first_key" ),
																						0 );
					rb_ary_push(	rb_return,
												rb_return_key );
				}
				//	FIX - if we have 1 element in our join cursor, use its key
				/*
				else if (  )	{
				
				}
				*/
				else {
					rb_raise( rb_eArgError, "Cannot return primary key unless unique index is provided." );
				}
			}
			else {

				rb_ary_push(	rb_return,
											Qnil );
			}


		}	while ( R_Arg( rb_hash_descriptor_index_key_or_keys_array ) );

		rb_return =	R_SimplifyArray( rb_return );
		
	}
	//	index or key plus args array
	else if ( rb_args_array != Qnil )	{

		if ( rb_index != Qnil )	{

			do {

				rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																							rb_Rbdb_Database_retrievePrimaryKey,
																							rb_index );

			}	while ( R_Arg( rb_args_array ) );

			rb_return =	R_SimplifyArray( rb_return );

		}
		else {
			
			rb_return = R_SplatArrayDescriptor(	rb_args_array,
																					rb_Rbdb_Database_retrievePrimaryKey	);

		}
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		Rbdb_Database*	c_database	=	NULL;
		Rbdb_Record*		c_record		=	NULL;

			VALUE	rb_database	=	rb_Rbdb_Database_databaseWithIndex( rb_database,
																															rb_index );
			C_RBDB_DATABASE( rb_database, c_database );

		rb_return		=	rb_ary_new();

		VALUE	rb_key			=	Qnil;

		do {
			
			c_record	=	rb_Rbdb_Database_internal_recordForRubyKey(	rb_database,
																															rb_key );

			c_record	=	Rbdb_Database_retrieveRecord(	c_database,
																								c_record );
			
			rb_key	=	rb_Rbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
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
VALUE rb_Rbdb_Database_retrievePair(	int			argc, 
																			VALUE*	args,
																			VALUE		rb_database )	{

	VALUE	rb_index																		=	Qnil;
	VALUE	rb_key																			=	Qnil;
	VALUE	rb_data																			=	Qnil;
	VALUE	rb_hash_descriptor_index_key_or_keys_array	=	Qnil;
	VALUE	rb_args_array																= Qnil;

	R_DefineAndParse( argc, args, rb_database,

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchHash(	rb_hash_descriptor_index_key_or_keys_array,
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 3 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 2 ),
			":index, [ <arg> ], ..."
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
			R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 5 ),
			"[ <arg> ], ..."
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

	Rbdb_Database*	c_database	=	NULL;
	Rbdb_Record*		c_record		=	rb_Rbdb_Database_internal_recordForRubyKeyData(	rb_database,
																																								rb_key,
																																								rb_data );

	c_record	=	Rbdb_Database_retrieveRecord(	c_database,
																						c_record );
	
	rb_data	=	rb_Rbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
																																c_record->data,
																																FALSE );

	c_record	=	Rbdb_Database_retrieveMatchingRecord(	c_database,
																										c_record );

	rb_data	=	RUBY_STRING_FOR_DATA_IN_RBDB_RECORD( c_record );

	return rb_data;
}

/************************************
*  retrievePartialKey  *
************************************/
/*
//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_Rbdb_Database_retrievePartialKey(	VALUE	rb_database,
 																			VALUE						partial_key )	{

	//	FIX - RARGS

	Rbdb_Database_retrievePartialKey();
	
}
*/
/************************************
*  retrievePartialData  *
************************************/
/*
//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_Rbdb_Database_retrievePartialData(	VALUE	rb_database,
 																				VALUE						data )	{

//	FIX - RARGS

	Rbdb_Database_retrievePartialData();

}
*/

/**********************************************
*  retrieveMultipleObjectCursorForKey  *
**********************************************/
/*
VALUE rb_Rbdb_Database_retrieveMultipleObjectCursor(	VALUE	rb_database,
 																							VALUE					data_object )	{

//	FIX - RARGS
	Rbdb_Database_retrieveMultipleObjectCursorForKey();
	
}
*/
/**************************************************
*  retrieveMultipleObjectCursorForPartialKey  *
**************************************************/
/*
VALUE rb_Rbdb_Database_retrieveMultipleObjectCursorForPartialKey(	VALUE	rb_database,
 																									VALUE					data_object )	{

//	FIX - RARGS
	Rbdb_Database_retrieveMultipleObjectCursorForPartialKey();
	
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
Rbdb_KeyRange* Rbdb_Database_relativePositionOfKey(	VALUE	rb_database,
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
VALUE rb_Rbdb_Database_shiftQueue( VALUE	rb_database )	{

	Rbdb_Database_shiftQueue();
	
}
*/
/**************************
*  shiftQueueOrWait  *
**************************/
/*
//	Only relevant for Queue databases
//	DB_CONSUME_WAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_Rbdb_Database_shiftQueueOrWait( VALUE	rb_database )	{
	Rbdb_Database_shiftQueueOrWait();

}

*/

/***********
*  verify  *
***********/

//	FIX - flesh out functions

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_verify.html
VALUE rb_Rbdb_Database_verify( VALUE	rb_database )	{

	Rbdb_Database*		c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	Rbdb_Database_verify( c_database );

	return rb_database;
}

/*******************************************************************************************************************************************************************************************
																		Data Deletion
*******************************************************************************************************************************************************************************************/

/***************************
*  deleteDataForKey  *
***************************/

VALUE rb_Rbdb_Database_delete(	int			argc, 
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
																										R_HashKey(	R_Symbol() ),
																										R_HashData(	R_Any() ) ) ) ),
			R_ListOrder( 4 ),
			"{ :index   =>  <key>, ... }, ...",
			"{ :index   =>  [ <keys> ], ... }, ..."
			 
		),

		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchArray(		rb_args_array ) ) ),
			R_ListOrder( 3 ),
			":index, [ <keys> ], ..."
		),
		
		//----------------------------------------------//

		R_DescribeParameterSet(	
			R_ParameterSet(		R_Parameter(	R_MatchSymbol(	rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),
			R_ListOrder( 2 ),
			":index, <key, ...>"
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
																					rb_Rbdb_Database_delete );

		rb_return =	R_SimplifyHash( rb_return );

	}
	else if (		rb_args_array != Qnil )	{

		if ( rb_index != Qnil )	{

			do {

				rb_return	=	R_IterateArrayDescriptor(	rb_args_array,
																							rb_Rbdb_Database_delete,
																							rb_index );

			}	while ( R_Arg( rb_args_array ) );

			rb_return =	R_SimplifyArray( rb_return );

		}
		else {
			
			rb_return = R_SplatArrayDescriptor(	rb_args_array,
																					rb_Rbdb_Database_delete	);

		}
		
	}
	//	rb_index, rb_key and rb_key
	else if (				rb_key != Qnil )	{
			
		Rbdb_Database*	c_database	=	NULL;
		VALUE	rb_database	=	rb_Rbdb_Database_databaseWithIndex( rb_database,
																														rb_index );
		C_RBDB_DATABASE( rb_database, c_database );

		Rbdb_Record*		c_record	=	NULL;

		do {
			
			c_record	=	rb_Rbdb_Database_internal_recordForRubyKey(	rb_database,
																															rb_key );

			Rbdb_Database_deleteRecord(	c_database,
																	c_record );

			//	remaining args are keys
		} while ( R_Arg( rb_key ) );
		
		rb_return =	R_SimplifyArray( rb_return );
		
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

VALUE	rb_Rbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	VALUE	rb_primary_database_self,
																																						VALUE	rb_index,
																																						VALUE	rb_callback_object )	{


	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRbdb,
																				RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash);
	}

	//	get database hash, set if it doesn't exist
	VALUE	rb_primary_database_handle	=	rb_Rbdb_Database_handle( rb_primary_database_self );	
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

VALUE rb_Rbdb_Database_internal_initRubyRuntimeStorage(	VALUE rb_ruby_runtime_storage_database )	{

	Rbdb_Database*	c_ruby_runtime_storage_database;
	C_RBDB_DATABASE( rb_ruby_runtime_storage_database, c_ruby_runtime_storage_database );

	Rbdb_DatabaseSettingsController*			c_database_settings_controller			=	Rbdb_Database_settingsController( c_ruby_runtime_storage_database );
	Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	Rbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );
	
	//	Set the database type - BTree since we will be searching by pointer and don't want to create a ton of junk records
	Rbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );	

	//	Open the database with our settings
	Rbdb_Database_internal_openWithoutRuntimeStorage( c_ruby_runtime_storage_database );
	
	return rb_ruby_runtime_storage_database;	
}

/**********************************
*  storeRubyInstanceForCInstance  *
**********************************/

VALUE rb_Rbdb_Database_internal_storeRubyRuntimeInstanceForCInstance(	VALUE rb_database )	{

	VALUE						rb_ruby_runtime_database	=	rb_Rbdb_internal_rubyRuntimeDatabase( rb_mRbdb );
	Rbdb_Database*	c_ruby_runtime_database;
	C_RBDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );

	Rbdb_Database*	c_database;
	C_RBDB_DATABASE( rb_database, c_database );

	uintptr_t	c_database_address	=	(uintptr_t) c_database;
	uintptr_t	rb_database_address	=	(uintptr_t) rb_database;
	Rbdb_Database_writeRawKeyDataPair(	c_ruby_runtime_database,
																			& c_database_address,
																			sizeof( uintptr_t ),
																			& rb_database_address,
																			sizeof( uintptr_t ) );
	
	return rb_database;
}

/*****************************
*  RubyInstanceForCInstance  *
*****************************/

VALUE rb_Rbdb_Database_internal_rubyRuntimeInstanceForCInstance(	void* c_rbdb_instance )	{
	//	we store a reference to our Ruby instance so that we can return the same object to the callback
	//	this is necessary to ensure extended methods, etc, remain
	VALUE						rb_ruby_runtime_database	=	rb_Rbdb_internal_rubyRuntimeDatabase( rb_mRbdb );
	Rbdb_Database*	c_ruby_runtime_database;
	C_RBDB_DATABASE( rb_ruby_runtime_database, c_ruby_runtime_database );
	
	uintptr_t	c_rbdb_instance_address	=	(uintptr_t) c_rbdb_instance;
	
	Rbdb_Record*	c_record	=	NULL;
	//	get address of corresponding VALUE
	c_record	=	Rbdb_Database_retrieveRawKey(	c_ruby_runtime_database,
																						& c_rbdb_instance_address,
																						sizeof( uintptr_t ) );
	uintptr_t*	rb_database_address	=	Rbdb_Record_rawData( c_record );
	VALUE	rb_database	=	(VALUE) *rb_database_address;
	
	Rbdb_Record_free( & c_record );
	
	return rb_database;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

//	This is the actual C method that gets called when a callback is set
RBDB_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_secondaryKeyCreationCallbackMethod(	Rbdb_Database*			c_secondary_database, 
																																																	Rbdb_Record*				c_record, 
																																																	Rbdb_SecondaryKeys*	c_secondary_keys )	{
	
	//	get our Ruby instance corresponding to our C instance
	VALUE	rb_secondary_database		=	rb_Rbdb_Database_internal_rubyRuntimeInstanceForCInstance(	c_secondary_database );
	
	VALUE	rb_key	=	rb_str_new(	c_record->key->wrapped_bdb_dbt->data,
															c_record->key->wrapped_bdb_dbt->size );
	VALUE	rb_data	=	rb_str_new(	c_record->data->wrapped_bdb_dbt->data,
															c_record->data->wrapped_bdb_dbt->size );
	
	VALUE	rb_database_settings_controller										=	rb_Rbdb_Database_settingsController( rb_secondary_database );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_settings_controller );	
	VALUE	rb_should_serialize_data													=	rb_Rbdb_DatabaseRecordReadWriteSettingsController_serializeData( rb_database_record_read_write_settings_controller );
	
	//	if serialization is on, unserialize the key and object
	if ( rb_should_serialize_data == Qtrue )	{
	
		rb_key		=	rb_Rbdb_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_key );
		rb_data		=	rb_Rbdb_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_data );
	}
	
	VALUE	rb_callback_object	=	rb_Rbdb_Database_secondaryKeyCreationCallbackMethod(	0,
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
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );
			break;
	}

	rb_secondary_keys	=	rb_funcall2(	rb_callback_object,
																		rb_intern( "call" ),
																		RARRAY_LEN( rb_args ),
																		RARRAY_PTR( rb_args ) );

	//	if nil, don't index
	if ( rb_secondary_keys == Qnil )	{
		return RBDB_SECONDARY_KEY_CREATION_FAILED_DO_NOT_INDEX;
	}

	return rb_Rbdb_Database_internal_processSecondaryKeyReturn(	rb_secondary_database,
																															rb_secondary_keys,
																															c_secondary_keys );	
}

/******************************
*  processSecondaryKeyReturn  *
******************************/

RBDB_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																												VALUE									rb_secondary_keys,
																																												Rbdb_SecondaryKeys*		c_secondary_keys )	{

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
			Rbdb_Key*	c_key	=	Rbdb_DBT_internal_newFromBDBDBT(	NULL,
																													& c_keys[ which_key_index ] );
			rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_secondary_database,
																												rb_this_key,
																												c_key,
																												TRUE );
			//	NULLify pointer to BDB key so that freeing Rbdb_Key won't free the BDB key
			c_key->wrapped_bdb_dbt	=	NULL;
			Rbdb_Key_free( & c_key );
		}
		
		if ( number_of_keys > 1 )	{
		
			//	store the array of keys in the DBT that gets returned to BDB
			c_secondary_keys->wrapped_bdb_dbt->data	=	c_keys;
			c_secondary_keys->wrapped_bdb_dbt->size	=	number_of_keys;

			return RBDB_RECORD_ALLOCATED_BY_APPLICATION_FOR_MULTIPLE_SECONDARY_KEYS;
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
		rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_secondary_database,
																											rb_secondary_keys, 
																											(Rbdb_DBT*) c_secondary_keys,
																											TRUE );
	}

	return FALSE;
}

/*******************************
*  removeCallbackInfoFromHash  *
*******************************/

VALUE rb_Rbdb_Database_internal_removeCallbackInfoFromHash(	VALUE		rb_secondary_database )	{
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_iv_get(	rb_mRbdb,
																				RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS,
								rb_callbacks_hash );
	}

	VALUE	rb_primary_database	=	rb_Rbdb_Database_primaryDatabase( rb_secondary_database );

	//	return the array of callback info (callback object, callback method in object)
	VALUE	rb_primary_database_handle	=	rb_Rbdb_Database_handle( rb_primary_database );	

	VALUE	rb_database_callbacks	=	rb_hash_aref(	rb_callbacks_hash,
																							rb_primary_database_handle );
	if ( rb_database_callbacks == Qnil )	{
		rb_database_callbacks = rb_hash_new();
		rb_hash_aset(	rb_callbacks_hash,
									rb_primary_database_handle,
									rb_database_callbacks );
	}
		
	VALUE	rb_index		=	rb_Rbdb_Database_secondaryIndexName( rb_secondary_database );
	
	//	we use a ruby call here instead of a C call so we don't pass any blocks that might have
	//	been passed to rb_Rbdb_Database_open (which calls rb_Rbdb_Database_close when finished with the block)
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

VALUE rb_Rbdb_Database_internal_createSecondaryIndex(	int			argc,
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
	Rbdb_Database*	c_primary_database		=	NULL;
	Rbdb_Database*	c_secondary_database		=	NULL;
	C_RBDB_DATABASE( rb_primary_database_self, c_primary_database );	
	char*						c_index_name					=	NULL;
	if ( rb_ary_includes(	rb_callback_ancestors,
												rb_Rbdb_Database ) == Qtrue )	{
		rb_database	= rb_callback_object;
	}
	//	otherwise instantiate one now
	else	{
	
		VALUE	rb_primary_database_controller	=	rb_Rbdb_Database_parentDatabaseController( rb_primary_database_self );
		
		rb_index			= rb_obj_as_string( rb_index );
		c_index_name	=	StringValuePtr( rb_index );
		
		char*	c_primary_database_name					=	Rbdb_Database_name( c_primary_database );
		char*	c_secondary_database_name				=	Rbdb_Database_internal_secondaryDatabaseNameForIndex( c_index_name,
																																																	c_primary_database_name );
		VALUE	rb_secondary_database_name			=	rb_str_new2( c_secondary_database_name );
		free( c_secondary_database_name );
		rb_secondary_database									=	rb_Rbdb_DatabaseController_newDatabase(	rb_primary_database_controller,
																																										rb_secondary_database_name );

		C_RBDB_DATABASE( rb_secondary_database, c_secondary_database );

		//	create secondary database
		Rbdb_Database_internal_configureDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																																												c_secondary_database,
																																												c_index_name,
																																												c_with_duplicates,
																																												c_with_sorted_duplicates );
	}

	if ( c_secondary_database == NULL )	{
		C_RBDB_DATABASE( rb_secondary_database, c_secondary_database );
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
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK );			
			break;
	}
	
	//	When an insert is made we need our Rbdb callback to call the Ruby Rbdb callback
	//	our Ruby Rbdb callback calls the ruby method that has been specified and returns it to Rbdb
	Rbdb_Database_setSecondaryKeyCreationCallbackMethod(	c_secondary_database,
																												& rb_Rbdb_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Now we need to make sure that we have our appropriate info when we reach our internal callback

	rb_Rbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	rb_primary_database_self,
																																				rb_index,
																																				rb_callback_object );
	
	//	store reference to secondary database in primary
	//	doesn't need to be weak b/c the secondary will be managed by the primary
	VALUE	rb_secondary_database_hash		=	rb_Rbdb_Database_secondaryDatabaseHash( rb_primary_database_self );
	if ( TYPE( rb_index ) == T_STRING )	{
		rb_index = ID2SYM( rb_to_id( rb_index ) );
	}
	rb_hash_aset(	rb_secondary_database_hash,
								rb_index,
								rb_secondary_database );
	
	//	associate secondary as index to primary
	Rbdb_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																									c_secondary_database,
																									c_index_name,
																									& rb_Rbdb_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Returns primary database so associations can be chained
	return rb_secondary_database;	
}

/**********************
*  uniqueIndexesHash  *
**********************/

VALUE rb_Rbdb_Database_internal_uniqueIndexesHash( VALUE	rb_database )	{

	VALUE	rb_unique_indexes_for_database	=	rb_iv_get(	rb_database,
																											RBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES );
	if ( rb_unique_indexes_for_database == Qnil )	{		
		rb_unique_indexes_for_database = rb_hash_new();
		rb_iv_set(	rb_database,
								RBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES,
								rb_unique_indexes_for_database );
	}
	
	return rb_unique_indexes_for_database;
}


/*******************************************************************************************************************************************************************************************
																		Type Storage Methods
*******************************************************************************************************************************************************************************************/

/*************************
*  recordForRubyKeyData  *
*************************/

Rbdb_Record* rb_Rbdb_Database_internal_recordForRubyKeyData(	VALUE	rb_database,
																															VALUE	rb_key,
																															VALUE	rb_data )	{
		
	Rbdb_Database*	c_database;
	C_RBDB_DATABASE( rb_database, c_database );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database );
	
	rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_key,
																										c_record->key,
																										TRUE );

	rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_data,
																										c_record->data,
																										FALSE );
	
	return c_record;
}

/*********************
*  recordForRubyKey  *
*********************/

Rbdb_Record* rb_Rbdb_Database_internal_recordForRubyKey(	VALUE	rb_database,
																													VALUE	rb_key )	{

	Rbdb_Database*	c_database;
	C_RBDB_DATABASE( rb_database, c_database );
	
	Rbdb_Record*	c_record	=	Rbdb_Record_new( c_database );
	
	rb_Rbdb_Database_internal_packDBTForRubyInstance(	rb_database,
																										rb_key,
																										c_record->key,
																										TRUE );

	return c_record;
}

/***************************
*  packDBTForRubyInstance  *
***************************/

void rb_Rbdb_Database_internal_packDBTForRubyInstance(	VALUE				rb_database,
																												VALUE				rb_object,
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data )	{

	enum ruby_value_type		c_type	=	TYPE( rb_object );

	//	if we have data, create a footer
	if ( ! key_not_data )	{
		Rbdb_Data_internal_createFooter( (Rbdb_Data*) c_dbt );
	}

	switch ( c_type )	{

		case T_FILE:
			rb_Rbdb_Database_internal_DBTForRubyFile(	rb_database,
																								rb_object,
																								c_dbt,
																								key_not_data );
			break;

		case T_SYMBOL:
			rb_Rbdb_Database_internal_DBTForRubySymbol(	rb_database,
																									rb_object,
																									c_dbt,
																									key_not_data );
			break;

		case T_REGEXP:
			rb_Rbdb_Database_internal_DBTForRubyRegexp(	rb_database,
																									rb_object,
																									c_dbt,
																									key_not_data );
			break;

		case T_CLASS:
			rb_Rbdb_Database_internal_DBTForRubyClassName(	rb_database,
																											rb_object,
																											c_dbt,
																											key_not_data );
			break;

		case T_STRING:
			rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																									rb_object,
																									c_dbt,
																									key_not_data );
			break;

		case T_COMPLEX:
			rb_Rbdb_Database_internal_DBTForRubyComplex(	rb_database,
																										rb_object,
																										c_dbt,
																										key_not_data );
			break;

		case T_RATIONAL:
			rb_Rbdb_Database_internal_DBTForRubyRational(	rb_database,
																										rb_object,
																										c_dbt,
																										key_not_data );
			break;
			
		case T_BIGNUM:
		case T_FIXNUM:
			rb_Rbdb_Database_internal_DBTForRubyInteger(	rb_database,
																										rb_object,
																										c_dbt,
																										key_not_data );
			break;
			
		case T_FLOAT:
			rb_Rbdb_Database_internal_DBTForRubyFloat(	rb_database,
																									rb_object,
																									c_dbt,
																									key_not_data );
			break;
			
		case T_TRUE:
		case T_FALSE:
			rb_Rbdb_Database_internal_DBTForRubyTrueFalse(	rb_database,
																											rb_object,
																											c_dbt,
																											key_not_data );
			break;
			
		case T_ARRAY:
		case T_HASH:
		case T_STRUCT:
		case T_OBJECT:
		case T_MODULE:
		case T_DATA:
		default:			
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
	}

}

/*******************
*  DBTForRubyFile  *
*******************/

void rb_Rbdb_Database_internal_DBTForRubyFile(	VALUE				rb_database,
																								VALUE				rb_file,
																								Rbdb_DBT*		c_dbt,
																								BOOL				key_not_data )	{

	VALUE	rb_database_settings_controller										=	rb_Rbdb_Database_settingsController( rb_database );
	VALUE	rb_database_record_settings_controller						=	rb_Rbdb_DatabaseSettingsController_recordSettingsController( rb_database_settings_controller );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_record_settings_controller );

	//	if we store the whole file
	if ( rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeFileNotPath( rb_database_record_read_write_settings_controller ) == Qtrue )	{
		
		//	read lines into array
		VALUE	rb_file_lines	=	rb_funcall(	rb_file,
																			rb_intern( "readlines" ),
																			0 );

		VALUE	rb_file_contents	=	rb_funcall(	rb_file_lines,
																					rb_intern( "join" ),
																					1,
																					rb_str_new( "\n", 1 ) );
		
		//	store as string
		rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																								rb_file_contents,
																								c_dbt,
																								key_not_data );
		
		//	set data to beginning of array
		if ( key_not_data )	{
			
			Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
												RbdbType_File );
		}
		else {
		
			Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
													RbdbType_File );
		}

	}
	//	if we store file path
	else {
		
		//	get file path
		VALUE	rb_file_path	=	rb_funcall(	rb_file,
																			rb_intern( "path" ),
																			0 );
		
		//	store as string
		rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																								rb_file_path,
																								c_dbt,
																								key_not_data );


		if ( key_not_data )	{
		
			Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
												RbdbType_FilePath );

		}
		else {
		
			Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
													RbdbType_FilePath );

		}
		
	}
	
}

/*********************
*  DBTForRubySymbol  *
*********************/

void rb_Rbdb_Database_internal_DBTForRubySymbol(	VALUE				rb_database,
																									VALUE				rb_symbol,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data )	{

	rb_symbol	=	rb_obj_as_string(	rb_symbol );

	rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																							rb_symbol,
																							c_dbt,
																							key_not_data );

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Symbol );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Symbol );

	}
	
}

/*********************
*  DBTForRubyRegexp  *
*********************/

void rb_Rbdb_Database_internal_DBTForRubyRegexp(	VALUE				rb_database,
																									VALUE				rb_regexp,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data )	{

	rb_regexp				=	rb_funcall(	rb_regexp,
																rb_intern( "source" ),
																0 );

	rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																							rb_regexp,
																							c_dbt,
																							key_not_data );

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Regexp );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Regexp );

	}

}

/************************
*  DBTForRubyClassName  *
************************/

void rb_Rbdb_Database_internal_DBTForRubyClassName(	VALUE				rb_database,
																										VALUE				rb_class,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data )	{

	rb_class				=	rb_obj_as_string(	rb_class );

	rb_Rbdb_Database_internal_DBTForRubyString(	rb_database,
																							rb_class,
																							c_dbt,
																							key_not_data );

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_ClassName );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_ClassName );

	}
	
}

/*********************
*  DBTForRubyString  *
*********************/

void rb_Rbdb_Database_internal_DBTForRubyString(	VALUE				rb_database __attribute__ ((unused)),
																									VALUE				rb_string,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data )	{

	if ( key_not_data )	{
		Rbdb_Key_setRawData(	(Rbdb_Data*) c_dbt,
													strdup( StringValuePtr(	rb_string ) ),
													RSTRING_LEN( rb_string ) * sizeof( char ) );	
	}
	else {
		Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
													strdup( StringValuePtr(	rb_string ) ),
													RSTRING_LEN( rb_string ) * sizeof( char ) );
	}
	c_dbt->wrapped_bdb_dbt->flags		|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_String );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_String );

	}
}

/**********************
*  DBTForRubyComplex  *
**********************/

void rb_Rbdb_Database_internal_DBTForRubyComplex(	VALUE				rb_database __attribute__ ((unused)),
																									VALUE				rb_complex_number,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data )	{

	//	store real - double
	VALUE	rb_real_part				=		rb_funcall(	rb_complex_number,
																						rb_intern( "real" ),
																						0 );
	VALUE	rb_imaginary_part		=		rb_funcall(	rb_complex_number,
																						rb_intern( "imaginary" ),
																						0 );
	
	RbdbStorage_Complex*	c_complex_number	=	calloc( 1, sizeof( RbdbStorage_Complex ) );
	c_complex_number->real				=	NUM2DBL( rb_real_part );
	c_complex_number->imaginary		=	NUM2DBL( rb_imaginary_part );

	if ( key_not_data )	{

		Rbdb_Key_setRawData(	(Rbdb_Key*) c_dbt,
													c_complex_number,
													sizeof( RbdbStorage_Complex ) );
	}
	else {
		
		Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
													c_complex_number,
													sizeof( RbdbStorage_Complex ) );
	}
	
	c_dbt->wrapped_bdb_dbt->flags	|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Complex );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Complex );

	}
}

/***********************
*  DBTForRubyRational  *
***********************/

void rb_Rbdb_Database_internal_DBTForRubyRational(	VALUE				rb_database __attribute__ ((unused)),
																										VALUE				rb_rational_number,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data )	{

	//	store numerator - double
	VALUE	rb_numerator				=		rb_funcall(	rb_rational_number,
																						rb_intern( "numerator" ),
																						0 );
	VALUE	rb_denominator			=		rb_funcall(	rb_rational_number,
																						rb_intern( "denominator" ),
																						0 );

	RbdbStorage_Rational*	c_rational_number	=	calloc( 1, sizeof( RbdbStorage_Rational ) );
	c_rational_number->numerator			=	NUM2DBL( rb_numerator );
	c_rational_number->denominator		=	NUM2DBL( rb_denominator );

	Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
												c_rational_number,
												sizeof( RbdbStorage_Rational ) );
	c_dbt->wrapped_bdb_dbt->flags	|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Rational );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Rational );

	}
}

/**********************
*  DBTForRubyInteger  *
**********************/

void rb_Rbdb_Database_internal_DBTForRubyInteger(	VALUE				rb_database __attribute__ ((unused)),
																									VALUE				rb_integer,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data )	{

	long*	c_long							=		calloc( 1, sizeof( long ) );
	*c_long										=		NUM2LONG( rb_integer );

	if ( key_not_data )	{
	
		Rbdb_Key_setRawData(	(Rbdb_Data*) c_dbt,
													c_long,
													sizeof( long ) );
	}
	else {
		
		Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
													c_long,
													sizeof( long ) );
	}

	c_dbt->wrapped_bdb_dbt->flags	|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Integer );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Integer );

	}
}

/********************
*  DBTForRubyFloat  *
********************/

void rb_Rbdb_Database_internal_DBTForRubyFloat(	VALUE				rb_database __attribute__ ((unused)),
																								VALUE				rb_float,
																								Rbdb_DBT*		c_dbt,
																								BOOL				key_not_data )	{

	double*	c_double					=		calloc( 1, sizeof( double ) );
	*c_double									=		NUM2DBL( rb_float );

	if ( key_not_data )	{
	
		Rbdb_Key_setRawData(	(Rbdb_Key*) c_dbt,
													c_double,
													sizeof( double ) );
	}
	else {
		
		Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
													c_double,
													sizeof( double ) );
	}

	c_dbt->wrapped_bdb_dbt->flags	|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_Float );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_Float );

	}
}

/************************
*  DBTForRubyTrueFalse  *
************************/

void rb_Rbdb_Database_internal_DBTForRubyTrueFalse(	VALUE				rb_database __attribute__ ((unused)),
																										VALUE				rb_true_false,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data )	{

	BOOL*	bool_key						=		calloc( 1, sizeof( BOOL ) );
	*bool_key									=		( rb_true_false == Qtrue	?	Qtrue
																													:	Qfalse );
	
	if ( key_not_data )	{

		Rbdb_Key_setRawData(	(Rbdb_Key*) c_dbt,
													bool_key,
													sizeof( BOOL ) );
	}
	else {
		
		Rbdb_Data_setRawData(	(Rbdb_Data*) c_dbt,
													bool_key,
													sizeof( BOOL ) );
	}

	c_dbt->wrapped_bdb_dbt->flags	|=	DB_DBT_APPMALLOC;

	if ( key_not_data )	{
	
		Rbdb_Key_setType(	(Rbdb_Key*) c_dbt,
											RbdbType_TrueFalse );

	}
	else {
	
		Rbdb_Data_setType(	(Rbdb_Data*) c_dbt,
												RbdbType_TrueFalse );

	}
}


/*******************************************************************************************************************************************************************************************
																		Type Retrieval Methods
*******************************************************************************************************************************************************************************************/

/*****************************
*  unpackDBTForRubyInstance  *
*****************************/

VALUE rb_Rbdb_Database_internal_unpackDBTForRubyInstance(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data )	{

	Rbdb_DatabaseRecordStorageType		c_database_storage_type	=	( key_not_data	?	Rbdb_Key_type( c_dbt ) 
																																							:	Rbdb_Data_type( c_dbt ) );

	VALUE	rb_return	=	Qnil;

	switch ( c_database_storage_type )	{

		case RbdbType_File:
		case RbdbType_FilePath:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbFile(	rb_database,
																																		c_dbt,
																																		key_not_data );
			break;

		case RbdbType_Symbol:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbSymbol(	rb_database,
																																			c_dbt,
																																			key_not_data );
			break;

		case RbdbType_Regexp:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbRegexp(	rb_database,
																																			c_dbt,
																																			key_not_data );
			break;

		case RbdbType_ClassName:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbClassName(	rb_database,
																																				c_dbt,
																																				key_not_data );
			break;

		case RbdbType_String:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																			c_dbt,
																																			key_not_data );
			break;

		case RbdbType_Complex:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbComplex(	rb_database,
																																			c_dbt,
																																			key_not_data );
			break;

		case RbdbType_Rational:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbRational(	rb_database,
																																				c_dbt,
																																				key_not_data );
			break;
			
		case RbdbType_Integer:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbInteger(	rb_database,
																																			c_dbt,
																																			key_not_data );
			break;
			
		case RbdbType_Float:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbFloat(	rb_database,
																																		c_dbt,
																																		key_not_data );
			break;
			
		case RbdbType_TrueFalse:
			rb_return	=	rb_Rbdb_Database_internal_RubyObjectForRbdbTrueFalse(	rb_database,
																																				c_dbt,
																																				key_not_data );
			break;
			
		default:			
			//	unexpected data
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
	}

	return rb_return;
}
			
/**************************
*  RubyObjectForRbdbFile  *
**************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbFile(	VALUE				rb_database,
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data )	{

	VALUE	rb_file	=	Qnil;

	VALUE	rb_database_settings_controller										=	rb_Rbdb_Database_settingsController( rb_database );
	VALUE	rb_database_record_settings_controller						=	rb_Rbdb_DatabaseSettingsController_recordSettingsController( rb_database_settings_controller );
	VALUE	rb_database_record_read_write_settings_controller	=	rb_Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( rb_database_record_settings_controller );

	//	if we store the whole file
	if ( rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeFileNotPath( rb_database_record_read_write_settings_controller ) == Qtrue )	{

		//	create ruby string from file data
		rb_file	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																	c_dbt,
																																	key_not_data );

	}
	//	if we store file path
	else {
		
		//	get file path
		VALUE	rb_file_path	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																							c_dbt,
																																							key_not_data );
		
		//	create file with path
		rb_file		=	rb_funcall(	rb_cFile,
														rb_intern( "new" ),
														1,
														rb_file_path );
	}
	
	return rb_file;
}

/****************************
*  RubyObjectForRbdbSymbol  *
****************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbSymbol(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data )	{

	VALUE	rb_symbol	=	Qnil;
	VALUE	rb_symbol_as_string	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																									c_dbt,
																																									key_not_data );
	
	if ( rb_symbol_as_string != Qnil )	{
		rb_symbol	=	ID2SYM( rb_to_id( rb_symbol_as_string ) );
	}
	
	return rb_symbol;
}

/****************************
*  RubyObjectForRbdbRegexp  *
****************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbRegexp(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data )	{

	VALUE	rb_regexp	=	Qnil;
	VALUE	rb_regexp_as_string	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																									c_dbt,
																																									key_not_data );
	
	if ( rb_regexp_as_string != Qnil )	{
		rb_regexp	=	rb_funcall(	rb_cRegexp,
														rb_intern( "new" ),
														1,
														rb_regexp_as_string );
	}
	
	return rb_regexp;
}

/*******************************
*  RubyObjectForRbdbClassName  *
*******************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbClassName(	VALUE				rb_database,
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data )	{

	VALUE	rb_class	=	Qnil;
	VALUE	rb_class_name	=	rb_Rbdb_Database_internal_RubyObjectForRbdbString(	rb_database,
																																						c_dbt,
																																						key_not_data );
	
	if ( rb_class_name != Qnil )	{
		rb_class	=	rb_path_to_class( rb_class_name );
	}
	
	return rb_class;
}

/****************************
*  RubyObjectForRbdbString  *
****************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbString(	VALUE				rb_database __attribute__ ((unused)),
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data )	{

	VALUE			rb_string	=	Qnil;

	char*	c_string	=	(char*) Rbdb_DBT_data( c_dbt );

	uint32_t	c_size	=	( key_not_data	?	Rbdb_Key_size( c_dbt )
																			:	Rbdb_Data_size( c_dbt ) );

	rb_string	=	rb_str_new(	c_string,
													c_size );

	return rb_string;
}

/*****************************
*  RubyObjectForRbdbComplex  *
*****************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbComplex(	VALUE				rb_database __attribute__ ((unused)),
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data __attribute__ ((unused)) )	{

	RbdbStorage_Complex*	c_complex_number	=	(RbdbStorage_Complex*) Rbdb_DBT_data( c_dbt );

	VALUE	rb_complex_number	=	rb_Complex(	DBL2NUM( c_complex_number->real ),
																				DBL2NUM( c_complex_number->imaginary )	);

	return rb_complex_number;
}

/******************************
*  RubyObjectForRbdbRational  *
******************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbRational(	VALUE				rb_database __attribute__ ((unused)),
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data __attribute__ ((unused)) )	{

	RbdbStorage_Rational*	c_rational_number	=	(RbdbStorage_Rational*) Rbdb_DBT_data( c_dbt );

	VALUE	rb_rational_number	=	rb_Rational(	DBL2NUM( c_rational_number->numerator ),
																						DBL2NUM( c_rational_number->denominator )	);

	return rb_rational_number;
}

/*****************************
*  RubyObjectForRbdbInteger  *
*****************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbInteger(	VALUE				rb_database __attribute__ ((unused)),
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data __attribute__ ((unused)) )	{

	RbdbStorage_Integer*	c_integer	=	(RbdbStorage_Integer*) Rbdb_DBT_data( c_dbt );

	VALUE	rb_integer	=	LONG2NUM( c_integer->integer_value );

	return rb_integer;
}

/***************************
*  RubyObjectForRbdbFloat  *
***************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbFloat(	VALUE				rb_database __attribute__ ((unused)),
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data __attribute__ ((unused)) )	{

	RbdbStorage_Float*	c_float	=	(RbdbStorage_Float*) Rbdb_DBT_data( c_dbt );

	VALUE	rb_float	=	LONG2NUM( c_float->float_value );

	return rb_float;
}

/*******************************
*  RubyObjectForRbdbTrueFalse  *
*******************************/

VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbTrueFalse(	VALUE				rb_database __attribute__ ((unused)),
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data __attribute__ ((unused)) )	{

	RbdbStorage_TrueFalse*	c_true_false	=	(RbdbStorage_TrueFalse*) Rbdb_DBT_data( c_dbt );

	VALUE	rb_true_false	=	( c_true_false->truefalse	?	Qtrue 
																									:	Qfalse );

	return rb_true_false;
}

/*******************************************************************************************************************************************************************************************
																		Type Methods
*******************************************************************************************************************************************************************************************/

/*******************************
*  storageTypeForRubyInstance  *
*******************************/

Rbdb_DatabaseRecordStorageType rb_Rbdb_Database_internal_storageTypeForRubyInstance(	VALUE		rb_object )	{
	
	enum ruby_value_type		c_ruby_type	=	TYPE( rb_object );
	
	Rbdb_DatabaseRecordStorageType	c_type	=	RbdbType_Raw;
	
	switch ( c_ruby_type )	{

		case T_FILE:
			c_type	=	RbdbType_File;
			break;

		case T_SYMBOL:
			c_type	=	RbdbType_Symbol;
			break;

		case T_REGEXP:
			c_type	=	RbdbType_Regexp;
			break;

		case T_CLASS:
			c_type	=	RbdbType_ClassName;
			break;

		case T_STRING:
			c_type	=	RbdbType_String;
			break;

		case T_COMPLEX:
			c_type	=	RbdbType_Complex;
			break;

		case T_RATIONAL:
			c_type	=	RbdbType_Rational;
			break;
			
		case T_BIGNUM:
		case T_FIXNUM:
			c_type	=	RbdbType_Integer;
			break;
			
		case T_FLOAT:
			c_type	=	RbdbType_Float;
			break;
			
		case T_TRUE:
		case T_FALSE:
			c_type	=	RbdbType_TrueFalse;
			break;
			
		case T_ARRAY:
		case T_HASH:
		case T_STRUCT:
		case T_OBJECT:
		case T_MODULE:
		case T_DATA:
		default:			
			//	serialization is turned off, so we don't know how to handle these types			
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
	}
	
	return c_type;
}

/****************************
*  storageTypeForRubyClass  *
****************************/

Rbdb_DatabaseRecordStorageType rb_Rbdb_Database_internal_storageTypeForRubyClass( VALUE rb_class )	{

	Rbdb_DatabaseRecordStorageType	c_type	=	RbdbType_Raw;
	
	if (			rb_class == rb_cFile )	{
		c_type	=	RbdbType_File;	
	}
	else if ( rb_class == rb_cSymbol )	{
		c_type	=	RbdbType_Symbol;
	}
	else if ( rb_class == rb_cRegexp )	{
		c_type	=	RbdbType_Regexp;
	}
	else if ( rb_class == rb_cClass )	{
		c_type	=	RbdbType_ClassName;
	}
	else if ( rb_class == rb_cString )	{
		c_type	=	RbdbType_String;
	}
	else if ( rb_class == rb_cInteger )	{
		c_type	=	RbdbType_Integer;
	}
	else if ( rb_class == rb_cFloat )	{
		c_type	=	RbdbType_Float;
	}
	else if ( rb_class == rb_cComplex )	{
		c_type	=	RbdbType_Complex;
	}
	else if ( rb_class == rb_cRational )	{
		c_type	=	RbdbType_Rational;
	}
	else if (	rb_class == rb_cTrueClass
				||	rb_class == rb_cFalseClass )	{
		c_type	=	RbdbType_TrueFalse;
	}
	else {
		//	we don't know how to handle these types
		rb_raise( rb_eArgError, RBDB_RUBY_ERROR_INVALID_DATABASE_DATA );		
	}

	return c_type;
}
