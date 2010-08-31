/*
 *		RPDB::Module
 *
 *
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_BaseStandardIncludes.h"

#include "rb_RPDB.h"
#include "rb_RPDB_internal.h"

#include "rb_RPDB_DatabaseObject.h"
#include "rb_RPDB_DatabaseObject_internal.h"
#include "rb_RPDB_DatabaseObjectDatabase.h"
#include "rb_RPDB_DatabaseObjectCursor.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB_Environment_internal.h"

#include "rb_RPDB_Database.h"
#include "rb_RPDB_Database_internal.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_DatabaseJoinController.h"
#include "rb_RPDB_DatabaseCursorController.h"
#include "rb_RPDB_DatabaseCursor.h"

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseCursorSettingsController.h"
#include "rb_RPDB_DatabaseCursorReadWriteSettingsController.h"
#include "rb_RPDB_DatabaseReadWriteSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_Database_internal.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_DatabaseCursorController.h>
#include <rpdb/RPDB_DatabaseCursor.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_RuntimeStorageController.h>

#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorSettingsController.h>
#include <rpdb/RPDB_DatabaseCursorReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeBtreeSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseObjectDatabase;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseObjectCursor;
extern	VALUE	rb_RPDB_DatabaseCursor;

#define RPDB_RUBY_ENVIRONMENT_CLASS																	"RPDB::Environment"
#define RPDB_RUBY_DATABASE_CLASS																		"RPDB::Environment::DatabaseController::Database"

#define RPDB_RUBY_CLASS_VARIABLE_ENVIRONMENT_STORAGE								"@rpdb__environment"
#define RPDB_RUBY_CLASS_VARIABLE_DATABASE_STORAGE										"@rpdb__database_storage"
#define RPDB_RUBY_CLASS_VARIABLE_PRIMARY_KEY_METHOD									"@rpdb__primary_key_method"	
#define RPDB_RUBY_CLASS_VARIABLE_UNIQUE_SECONDARY_KEY_METHODS				"@rpdb__unique_secondary_key_methods"	
#define RPDB_RUBY_CLASS_VARIABLE_NONUNIQUE_SECONDARY_KEY_METHODS		"@rpdb__nonunique_secondary_key_methods"	
#define RPDB_RUBY_CLASS_VARIABLE_STORED_INITIALIZE_ARGUMENTS				"@rpdb__stored_initialize_arguments"	
#define RPDB_RUBY_CLASS_VARIABLE_IDENTIFY_AS_WAITLIST								"@rpdb__identify_for_rpdb_as_wait_list"
#define RPDB_RUBY_CLASS_VARIABLE_IDENTIFY_AS												"@rpdb__identify_for_rpdb_as"
#define RPDB_RUBY_CLASS_VARIABLE_INITIALIZED												"@rpdb__initialized"
#define RPDB_RUBY_CLASS_VARIABLE_CONFIGURED													"@rpdb__configured"
#define RPDB_RUBY_CLASS_VARIABLE_CURSOR_CONTEXT_STORAGE							"@rpdb__cursor_context_storage"
#define RPDB_RUBY_CLASS_VARIABLE_UNIQUE_JOIN_DECLARATION_HASH					"@rpdb__unique_join_declaration_hash"

#define RPDB_RUBY_ERROR_PRIMARY_KEY_MISSING																				"Primary key method has not been specified."
#define RPDB_RUBY_ERROR_MISSING_DATABASE																					"RPDB object missing database."
#define RPDB_RUBY_ERROR_DEFAULT_ENVIRONMENT_NULL																	"Environment was missing."
#define RPDB_RUBY_ERROR_ENVIRONMENT_NULL																					"Default environment was missing."
#define RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY_METHOD																	"RPDB object lacks method to retrieve sufficient information for unique key."
#define RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY																				"RPDB object lacks sufficient information for unique key."
#define RPDB_RUBY_ERROR_DATABASE_ARGUMENT_UNKNOWN_TYPE														"Database parameter was of unknown type."
#define RPDB_RUBY_ERROR_ENVIRONMENT_UNKNOWN_TYPE																	"Environment parameter was of unknown type."
#define RPDB_RUBY_ERROR_MULTIPLE_WRITE_REQUIRES_CALL_TO_CLASS_OBJECT							"Multiple record write requires call to class object."
#define RPDB_RUBY_ERROR_MULTIPLE_RETRIEVE_REQUIRES_CALL_TO_CLASS_OBJECT						"Multiple record retrieve requires call to class object."
#define RPDB_RUBY_ERROR_MULTIPLE_DELETE_REQUIRES_CALL_TO_CLASS_OBJECT							"Multiple record delete requires call to class object."
#define RPDB_RUBY_ERROR_INSTANCE_RETRIEVE_REQUIRES_OBJECT_TO_HOLD_RETRIEVE_DATA		"Retrieval by instance requires object instance to hold retrieval data."
#define RPDB_RUBY_ERROR_RETRIEVAL_KEY_WAS_NOT_UNIQUE															"Retrieval key was not unique."
#define RPDB_RUBY_ERROR_TOO_MANY_ARGUMENTS_PROVIDED_FOR_DB_OBJECT_INITIALIZE			"RPDB object has too many methods specified for arguments to initialize (%ld); expected %i."
#define RPDB_RUBY_ERROR_TOO_FEW_ARGUMENTS_PROVIDED_FOR_DB_OBJECT_INITIALIZE				"RPDB object has too few methods specified for arguments to initialize (%ld); expected %i."
#define RPDB_RUBY_ERROR_INITIALIZE_ARGUMENT_METHOD_DOES_NOT_EXIST									"Method provided for RPDB object initialize (%s) does not exist."
#define RPDB_RUBY_ERROR_CURSOR_FOR_JOIN_REPORTED_NO_RECORD												"Cursor requested for join reported no record exists for key."
#define RPDB_RUBY_ERROR_IDENTIFY_AS_CALLED_ON_INSTANCE														":identify_for_rpdb_as should only called on a class, not an instance."
#define RPDB_RUBY_ERROR_UNABLE_TO_FIND_ENUMERATION_FRAME													"Unable to find previous enumeration frame for corresponding iteration cursor."
#define RPDB_RUBY_ERROR_NO_DATABASE_FOR_INDEX																			"No database existed for requested index."
#define RPDB_RUBY_ERROR_CURSOR_SET_KEY_DID_NOT_EXIST                              "Key specified to locate cursor did not exist."


//	These are not called from anywhere else and cause warnings if put in the _internal file, which is used elsewhere
//	This seems to be due to the static qualification
//	Keeping them here does no harm.

static int rb_RPDB_DatabaseObject_internal_retrieveCursorsForEachParameterDescriptionForJoinCursor(	VALUE	rb_key_method_symbol,
                                                                                                    VALUE	rb_key_value,
                                                                                                    VALUE	rb_passed_args );

static int rb_RPDB_DatabaseObject_internal_iterateEnvironments(	VALUE	rb_environment,
                                                                VALUE	rb_identify_for_rpdb_as_array,
                                                                VALUE	rb_passed_args );

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
														Module Definition (Ruby Init)
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Module()	{
	
	rb_define_method(						rb_mRPDB,	"configure_rpdb",												rb_RPDB_DatabaseObject_configureRPDB,									0 );
                                                                                                                              
	rb_define_method(						rb_mRPDB,	"init_rpdb",														rb_RPDB_DatabaseObject_initRPDB,											0 );
	rb_define_singleton_method(	rb_mRPDB,	"init_rpdb",														rb_RPDB_DatabaseObject_initRPDB,											0 );
		                                                                                                                          
	rb_define_method(						rb_mRPDB,	"identify_for_rpdb_as",									rb_RPDB_DatabaseObject_identifyAs,										0 );
                        			                                                                                                      
	rb_define_method(						rb_mRPDB,	"initialized?",													rb_RPDB_DatabaseObject_hasInitialized,								0 );
	rb_define_alias(						rb_mRPDB,	"has_initialized?",											"initialized?" );                                     
                        			                                                                                                      
	rb_define_method(						rb_mRPDB,	"configured?",													rb_RPDB_DatabaseObject_hasConfigured,									0 );
	rb_define_alias(						rb_mRPDB, "has_configured?",											"configured?" );                                      
                        			                                                                                                      
	rb_define_method(						rb_mRPDB,	"environment",													rb_RPDB_DatabaseObject_environment,										0 );
	rb_define_method(						rb_mRPDB,	"environment=",													rb_RPDB_DatabaseObject_setEnvironment,								1 );

	//	Default database for write/retrieve/delete
	//	Setting a default automatically adds the database to permissible list
	rb_define_method(						rb_mRPDB,	"database",															rb_RPDB_DatabaseObject_database,											0 );
	rb_define_method(						rb_mRPDB,	"database_for_index",										rb_RPDB_DatabaseObject_databaseForIndex,							1);
	rb_define_alias(						rb_mRPDB,	"index",																"database_for_index" );
	rb_define_method(						rb_mRPDB,	"database=",														rb_RPDB_DatabaseObject_setDatabase,										1 );
	rb_define_alias(						rb_mRPDB,	"set_database",													"database=" );
	rb_define_method(						rb_mRPDB,	"databases",														rb_RPDB_DatabaseObject_databases,											0 );
	rb_define_method(						rb_mRPDB,	"set_store_as_class",										rb_RPDB_DatabaseObject_setStoreAsClass,								1 );
	rb_define_method(						rb_mRPDB,	"cursor",																rb_RPDB_DatabaseObject_cursor,												-1 );
	rb_define_method(						rb_mRPDB,	"cursors",															rb_RPDB_DatabaseObject_cursors,												0 );

	//	Primary key method for retrieving object
	rb_define_method(						rb_mRPDB,	"primary_key_value",										rb_RPDB_DatabaseObject_primaryKeyValue,								0 );
	rb_define_method(						rb_mRPDB,	"primary_key_method",										rb_RPDB_DatabaseObject_primaryKeyMethod,							0 );
	rb_define_alias(						rb_mRPDB,	"primary_key",													"primary_key_method" );
	rb_define_method(						rb_mRPDB,	"primary_key_method=",									rb_RPDB_DatabaseObject_setPrimaryKeyMethod,						1 );
	rb_define_alias(						rb_mRPDB,	"key_method="	,													"primary_key_method=" );
	rb_define_alias(						rb_mRPDB,	"set_primary_key_method",								"primary_key_method=" );

	//	Secondary key methods (optional) for retrieving object                                                  				
	//	Each key method will have a corresponding database created in the same location as the primary          				
	//	with the extension __idx__<rpdb/secondaryKeyMethod>      
	
	rb_define_method(						rb_mRPDB,	"key_methods",													rb_RPDB_DatabaseObject_keyMethods,										0 );
	rb_define_method(						rb_mRPDB,	"unique_key_methods",										rb_RPDB_DatabaseObject_uniqueKeyMethods,							0 );
	rb_define_method(						rb_mRPDB,	"seconday_key_methods",									rb_RPDB_DatabaseObject_secondaryKeyMethods,						0 );
	rb_define_method(						rb_mRPDB,	"unique_secondary_key_methods",					rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods,			0 );
	rb_define_method(						rb_mRPDB,	"non_unique_secondary_key_methods",			rb_RPDB_DatabaseObject_nonUniqueSecondaryKeyMethods,	0 );
	                      			
	rb_define_method(						rb_mRPDB,	"unique_secondary_key_methods+=",				rb_RPDB_DatabaseObject_addUniqueSecondaryKeyMethod,		-1 );
	rb_define_alias(						rb_mRPDB,	"add_unique_key_method",								"unique_secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_unique_key_methods",								"unique_secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_unique_secondary_key_method",			"unique_secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_unique_secondary_key_methods",			"unique_secondary_key_methods+=" );
	rb_define_method(						rb_mRPDB,	"declare_unique_join",									rb_RPDB_DatabaseObject_declareUniqueJoin,							-1 );
	rb_define_method(						rb_mRPDB,	"is_unique_join?",											rb_RPDB_DatabaseObject_isUniqueJoin,									-1 );
	rb_define_method(						rb_mRPDB,	"secondary_key_methods+=",							rb_RPDB_DatabaseObject_addSecondaryKeyMethod,					-1 );
	rb_define_alias(						rb_mRPDB,	"add_key_method",												"secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_key_methods",											"secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_secondary_key_method",							"secondary_key_methods+=" );
	rb_define_alias(						rb_mRPDB,	"add_secondary_key_methods",						"secondary_key_methods+=" );
                        			
	rb_define_method(						rb_mRPDB,	"keys",																	rb_RPDB_DatabaseObject_keys,													0 );
	rb_define_method(						rb_mRPDB,	"unique_key",														rb_RPDB_DatabaseObject_uniqueKey,											0 );
	rb_define_alias(						rb_mRPDB,	"has_unique_key?",											"unique_key" );
	rb_define_method(						rb_mRPDB,	"unique_keys",													rb_RPDB_DatabaseObject_uniqueKeys,										0 );
	rb_define_method(						rb_mRPDB,	"secondary_keys",												rb_RPDB_DatabaseObject_secondaryKeys,									0 );
	rb_define_method(						rb_mRPDB,	"unique_secondary_keys",								rb_RPDB_DatabaseObject_uniqueSecondaryKeys,						0 );
	rb_define_method(						rb_mRPDB,	"non_unique_secondary_keys",						rb_RPDB_DatabaseObject_nonUniqueSecondaryKeys,				0 );
	
	//	Write methods
	rb_define_method(						rb_mRPDB,	"write",																rb_RPDB_DatabaseObject_write,													-1 );
	rb_define_alias(						rb_mRPDB,	"write_to_db",													"write" );

	//	Retrieve methods	
	rb_define_method(						rb_mRPDB,	"retrieve",															rb_RPDB_DatabaseObject_retrieve,											-1 );
	rb_define_alias(						rb_mRPDB,	"retrieve_from_db",											"retrieve" );

	rb_define_method(						rb_mRPDB,	"exists?",															rb_RPDB_DatabaseObject_exists,												-1 );
	rb_define_alias(						rb_mRPDB,	"exists_in_db?",												"exists?" );

	//	Delete methods
	rb_define_method(						rb_mRPDB,	"delete",																rb_RPDB_DatabaseObject_delete,												-1 );
	rb_define_alias(						rb_mRPDB,	"delete_from_db",												"delete" );

	rb_define_method(						rb_mRPDB,	"iterate",															rb_RPDB_DatabaseObject_iterate,												-1 	);
	rb_define_alias(						rb_mRPDB,	"each",																	"iterate"	);
	rb_define_method(						rb_mRPDB,	"iterate_duplicates",										rb_RPDB_DatabaseObject_iterateDuplicates,							-1 	);
	rb_define_alias(						rb_mRPDB,	"each_duplicate",												"iterate_duplicates"	);
	rb_define_method(						rb_mRPDB,	"iterate_keys",													rb_RPDB_DatabaseObject_iterateKeys,										-1 	);
	rb_define_alias(						rb_mRPDB,	"each_key",															"iterate_keys"	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
														Module Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

//	This is a module - rb_self refers to the object currently implementing the module

/*************
*  initRPDB  *
*************/

VALUE rb_RPDB_DatabaseObject_initRPDB( VALUE	rb_klass_self )	{
	
	//	we don't want the actual superclass, we want the next ancestor (which might be a module)
	VALUE	rb_superclass_self	=	rb_ary_entry( rb_funcall(	rb_klass_self,
																rb_intern( "ancestors" ),
																0 ), 1 );

	//	do nothing - classes implement; we are only declaring so that function 
	//	is always declared when RPDB is included
	
	//	we want to look up the call chain until we find an object that responds to init_rpdb
	//	
	
	if ( rb_obj_respond_to(	rb_superclass_self,
							rb_intern( RPDB_FUNCTION_INIT ),
							0 ) )	{
		
		//	since we might have a module rather than a superclass we need to manually call up the function chain
		//	theoretically this should be no different than calling super; we shall see if that is the case
		rb_funcall(	rb_superclass_self,
					rb_intern( RPDB_FUNCTION_INIT ),
					0 );
	}
	
	return rb_klass_self;
}

/******************
*  configureRPDB  *
******************/

VALUE rb_RPDB_DatabaseObject_configureRPDB( VALUE	rb_klass_self )	{
	
	//	do nothing - classes implement; we are only declaring so that function 
	//	is always declared when RPDB is included
	return rb_klass_self;
}

/******************
*  hasConfigured  *
******************/

VALUE rb_RPDB_DatabaseObject_hasConfigured( VALUE rb_self )	{
	
	VALUE	rb_has_configured	=	rb_iv_get(	rb_self,
												RPDB_RUBY_CLASS_VARIABLE_CONFIGURED );
	
	return ( rb_has_configured == Qtrue ? Qtrue : Qfalse );
}

/*******************
*  hasInitialized  *
*******************/

VALUE rb_RPDB_DatabaseObject_hasInitialized( VALUE rb_self )	{
	
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
    
	VALUE	rb_has_initialized	=	rb_iv_get(	rb_klass,
												RPDB_RUBY_CLASS_VARIABLE_INITIALIZED );

	return ( rb_has_initialized == Qtrue ? Qtrue : Qfalse );
}

/*****************
*  identifiesAs  *
*****************/

//	set identifiers for class
VALUE rb_RPDB_DatabaseObject_identifyAs(	VALUE	rb_klass_self __attribute__((unused)) )	{

	//	do nothing - classes implement; we are only declaring so that function 
	//	is always declared when RPDB is included
	return Qnil;
}


/******************************
*  classnameAsPathsafeString  *
******************************/

VALUE rb_RPDB_DatabaseObject_pathsafeClassname( VALUE	rb_self )	{
	
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
		
	//	And finally, we want to remove any ":" from the string
	VALUE	rb_pathsafe_class_name	=	rb_funcall(	rb_obj_as_string( rb_klass ),
													rb_intern( "gsub" ),
													2,
													rb_str_new2( "::" ),
													rb_str_new2( "." ) );
	
	return rb_pathsafe_class_name;	
}

/*******************
*  setEnvironment  *
*******************/

VALUE rb_RPDB_DatabaseObject_setEnvironment(	VALUE	rb_self,
																							VALUE	rb_environment )	{

	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	rb_iv_set(	rb_klass,
							RPDB_RUBY_CLASS_VARIABLE_ENVIRONMENT_STORAGE,
							rb_environment );
	
	return rb_self;
}

/****************
*  environment  *
****************/

VALUE rb_RPDB_DatabaseObject_environment(	VALUE	rb_self )	{

	VALUE	rb_environment	=	rb_RPDB_DatabaseObject_internal_getEnvironment( rb_self );
	
	if ( rb_environment == Qnil )	{
		rb_environment	=	rb_RPDB_DatabaseObject_requireDefaultEnvironment( rb_self );
	}
	
	return rb_environment;
}

/*************
*  database  *
*************/

//	Returns default database for this class - defaults to classname.to_s if not set
VALUE rb_RPDB_DatabaseObject_database(	VALUE	rb_self )	{
	
	//	we need our primary key method as our index
	VALUE	rb_primary_index_method	=	rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self );
	
	//	See if we have a database set already 
	VALUE	rb_database = rb_RPDB_DatabaseObject_internal_getDatabase( rb_self,
																		rb_primary_index_method );
	
	//	If we do, return it
	if ( rb_database != Qnil )	{
		return rb_database;
	}
	
	/*-----------
	|  Default	|
	-----------*/
	
	//	Default database is pathsafe classname of rb_self
	VALUE	rb_pathsafe_class_name	=	rb_RPDB_DatabaseObject_pathsafeClassname( rb_self );
	
	//	If we get here, we don't have a database set, so we're going to set one using our class name
	rb_RPDB_DatabaseObject_setDatabase(	rb_self, 
																			rb_pathsafe_class_name );
	
	//	Now we've set a database, we can return it normally
	return rb_RPDB_DatabaseObject_database( rb_self );
}

/**************
*  databases  *
**************/

VALUE rb_RPDB_DatabaseObject_databases( VALUE rb_self )	{

	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	VALUE	rb_databases	=	rb_iv_get(	rb_klass,
											RPDB_RUBY_CLASS_VARIABLE_DATABASE_STORAGE );
											
	if ( rb_databases == Qnil )	{
		rb_databases = rb_hash_new();
		rb_iv_set(	rb_klass,
					RPDB_RUBY_CLASS_VARIABLE_DATABASE_STORAGE,
					rb_databases );
	}
	return rb_databases;
}

/*********************
*  databaseForIndex  *
*********************/

//	Returns default database for this class - defaults to classname.to_s if not set
VALUE rb_RPDB_DatabaseObject_databaseForIndex(	VALUE	rb_self,
												VALUE	rb_index_method )	{

	VALUE	rb_database	=	Qnil;
	
	if ( rb_index_method == Qnil )	{
	
		rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
	}
	else {
		
		rb_database	=	rb_RPDB_DatabaseObject_internal_getDatabase(	rb_self,
																		rb_index_method );
	}
	
	return rb_database;
}

/****************
*  setDatabase  *
****************/

//	Sets default database for this class - defaults to classname.to_s if not set
VALUE rb_RPDB_DatabaseObject_setDatabase(	VALUE	rb_self,
																					VALUE	rb_database_or_name )	{

	//	Args
	//		1 Arg:
	//			* Database name string or symbol in default environment or database

	VALUE	rb_database	=	Qnil;
	
	VALUE	rb_database_name_string	=	Qnil;

	//	If database is a string, turn it into a symbol
	if ( TYPE( rb_database_or_name ) == T_STRING )	{
		
		rb_database_name_string	=	rb_obj_clone( rb_database_or_name );
		rb_database_or_name	=	STRING2SYM( rb_database_or_name );
	}
	//	if we have a symbol, get the database from the database controller
	if ( TYPE( rb_database_or_name ) == T_SYMBOL )	{
		
		//	Get our c_database_controller so we can wrap the new database ourselves for DB Object
		RPDB_Environment*	c_environment	=	NULL;
		C_RPDB_ENVIRONMENT( rb_RPDB_DatabaseObject_environment( rb_self ), c_environment );
		char*	c_database_name	=	StringValuePtr( rb_database_name_string );
		RPDB_Database*	c_database	=	RPDB_DatabaseController_newDatabase(	RPDB_Environment_databaseController( c_environment ),
																																				c_database_name );
		
		rb_database	=	RUBY_RPDB_DATABASE_OBJECT_DATABASE( c_database );
	}
	//	otherwise we have an object - do parity checks for methods we require
	//	we can't have nothing because we required 1 arg
	else	{
		
		rb_database	=	rb_database_or_name;
		
		rb_RPDB_DatabaseObject_internal_requireObjectVerifyAsDatabase( rb_database );				
	}
	
	VALUE	rb_primary_key_method	=	rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self );
	
	//	assuming we got here we can store our database
	rb_RPDB_DatabaseObject_internal_storeDatabase(	rb_self,
													rb_database,
													rb_primary_key_method );

	//	done
	return rb_self;
}

/*******************
*  store_as_class  *
*******************/

//	Sets default database for this class - defaults to classname.to_s if not set
VALUE rb_RPDB_DatabaseObject_setStoreAsClass(	VALUE	rb_self,
																							VALUE	rb_store_as_class	)	{
	
	//	Set database to pathsafe version of superclass
	rb_RPDB_DatabaseObject_setDatabase(	rb_self,
																			rb_RPDB_DatabaseObject_pathsafeClassname(	rb_store_as_class ) );
	return rb_self;
}

/*******************************************************************************************************************************************************************************************
															Key Methods
*******************************************************************************************************************************************************************************************/

/*********************
*  primaryKeyMethod  *
*********************/

//	Returns primary key method for this class - write/retrieve requires non-nil return value
VALUE rb_RPDB_DatabaseObject_primaryKeyMethod(	VALUE	rb_self )	{

	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	return rb_iv_get(	rb_klass,
						RPDB_RUBY_CLASS_VARIABLE_PRIMARY_KEY_METHOD );
}

/************************
*  setPrimaryKeyMethod  *
************************/

//	Sets primary key method for this class - required for write/retrieve
VALUE rb_RPDB_DatabaseObject_setPrimaryKeyMethod(	VALUE	rb_self,
													VALUE	rb_primary_key_method	)	{

	//	Args: :primary_key_method

	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	rb_iv_set(	rb_klass,
				RPDB_RUBY_CLASS_VARIABLE_PRIMARY_KEY_METHOD,
				rb_primary_key_method );

	//	check if we have a database set for nil - if so it was set before the primary key was specified and we need to move it over
	VALUE	rb_databases			=	rb_RPDB_DatabaseObject_databases( rb_self );
	VALUE	rb_primary_database		=	Qnil;

	//	if the primary key is not specified before the call is made to database (for instance to open it)
	//	then we end up with a database stored in reference to nil key
	//	we want to move that over to the primary key index as soon as it is set
	if ( ( rb_primary_database = rb_hash_aref(	rb_databases,
												Qnil ) ) != Qnil )	{
		
		//	copy the key over
		rb_hash_aset(	rb_databases,
						rb_primary_key_method,
						rb_primary_database );
		
		//	delete the key stored at nil
		rb_funcall(	rb_databases,
					rb_intern( "delete" ),
					1,
					Qnil );
	}

	return rb_self;
}

/********************
*  primaryKeyValue  *
********************/

VALUE rb_RPDB_DatabaseObject_primaryKeyValue(	VALUE	rb_self )	{
	
	return rb_funcall(	rb_self,
						SYM2ID( rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self ) ),
						0 );
}

/************************
*  secondaryKeyMethods  *
************************/

//	Returns all secondary key methods
VALUE rb_RPDB_DatabaseObject_secondaryKeyMethods(	VALUE	rb_self )	{
	
	//	unique methods first, non-unique methods second
	return rb_ary_concat(	rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods( rb_self ),
							rb_RPDB_DatabaseObject_nonUniqueSecondaryKeyMethods( rb_self ) );
}

/**************************
*  addSecondaryKeyMethod  *
**************************/

VALUE rb_RPDB_DatabaseObject_addSecondaryKeyMethod(	int	argc,
 														VALUE*	args,
														VALUE	rb_self	)	{

	//	Args: :secondary_key_method, ...
	rb_RPDB_DatabaseObject_internal_addSecondaryKeyMethods(	rb_self,
																RPDB_RUBY_CLASS_VARIABLE_NONUNIQUE_SECONDARY_KEY_METHODS,
																argc,
																args	);

	return rb_self;
}

/********************************
*  addUniqueSecondaryKeyMethod  *
********************************/

VALUE rb_RPDB_DatabaseObject_addUniqueSecondaryKeyMethod(	int	argc,
															VALUE*	args,
															VALUE	rb_self	)	{

	//	Args: :unique_secondary_key_method, ...
	rb_RPDB_DatabaseObject_internal_addSecondaryKeyMethods(	rb_self,
																RPDB_RUBY_CLASS_VARIABLE_UNIQUE_SECONDARY_KEY_METHODS,
																argc,
																args	);
	
	return rb_self;
}	

/******************************
*  uniqueSecondaryKeyMethods  *
******************************/

VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods(	VALUE	rb_self )	{
	
	return rb_RPDB_DatabaseObject_internal_getClassInstanceArray(	rb_self,
																	RPDB_RUBY_CLASS_VARIABLE_UNIQUE_SECONDARY_KEY_METHODS	);
}


/*************************************
*  non_unique_secondary_key_methods  *
*************************************/

VALUE rb_RPDB_DatabaseObject_nonUniqueSecondaryKeyMethods(	VALUE	rb_self )	{
	
	return rb_RPDB_DatabaseObject_internal_getClassInstanceArray(	rb_self,
																	RPDB_RUBY_CLASS_VARIABLE_NONUNIQUE_SECONDARY_KEY_METHODS	);
}

/************************
*  declare_unique_join  *
************************/

//	Return keyMethod that will produce a unique key - nil if none exists
VALUE rb_RPDB_DatabaseObject_declareUniqueJoin(	int		argc,
												VALUE*	args,
												VALUE	rb_self )	{
	
	//	we are taking a series of arguments, each of which is an index, and recording them together
	
	VALUE	rb_unique_join_declaration_hash	=	rb_RPDB_DatabaseObject_internal_uniqueJoinDeclarationHash( rb_self );
	
	//	we store each index in order from the others
	//	@rpdom__unique_joins[ :index ][ ... ]
	int	c_which_arg;
	for ( c_which_arg = 0 ; c_which_arg < argc ; c_which_arg++ )	{
		
		VALUE	rb_this_index	=	args[ c_which_arg ];

		//	for each index, add each index
		int	c_which_arg_2;
		VALUE	rb_indexes_array	=	rb_ary_new();
		//	push this index to start
		rb_ary_push(	rb_indexes_array,
						rb_this_index );
		for ( c_which_arg_2 = 0 ; c_which_arg_2 < argc ; c_which_arg_2++ )	{		

			VALUE	rb_this_other_index	=	args[ c_which_arg_2 ];
			
			if ( rb_this_other_index != rb_this_index )	{
				//	tack on each additional index
				rb_ary_push(	rb_indexes_array,
								rb_this_other_index );
			}
		}
		//	push array of ordered indexes to chain in hash lookup
		rb_RPDB_DatabaseObject_internal_addChainedMember(	rb_unique_join_declaration_hash,
															rb_indexes_array );
	}
	
	//	in the future if we retrieve all of these indexes together we know we are returning only one record
	//	easy to look up - simply ask for all of the indexes in any order
	//	since we stored all indexes in each case we know any order will match or not
	//	@rpdom__unique_joins[ :index ][ ... ]
	
	return rb_self;
}

/********************
*  is_unique_join?  *
********************/

//	Return keyMethod that will produce a unique key - nil if none exists
VALUE rb_RPDB_DatabaseObject_isUniqueJoin(	int		argc,
											VALUE*	args,
											VALUE	rb_self )	{

	VALUE	rb_unique_join_declaration_hash	=	rb_RPDB_DatabaseObject_internal_uniqueJoinDeclarationHash( rb_self );
	//	rb_lookup_hash gets iterated
	VALUE	rb_lookup_hash		=	rb_unique_join_declaration_hash;
	
	//	this should be empty at the end if we have a declared unique join
	VALUE	rb_last_result_hash	=	Qnil;
	
	int	c_which_index;
	for ( c_which_index = 0 ; c_which_index < argc ; c_which_index++ )	{
		
		VALUE	rb_this_index	=	args[ c_which_index ];
		
		//	for each index, see if it is in the hash
		if (	( rb_last_result_hash	=	rb_hash_aref(	rb_lookup_hash,
															rb_this_index ) ) )	{
			//	if this index is not in the hash then it is not declared a unique join
			return Qfalse;
		}
	}
	
	//	if we got here we know we matched all of our indexes
	//	this is not sufficient to know if we have a unique join
	//	the last check we have to do is make sure that the last index in the lookup hash is an empty hash
	if ( RHASH_SIZE( rb_last_result_hash ) == 0 )	{
		return Qtrue;
	}
	
	return Qfalse;
}
	
/**********************
*  unique_key_method  *
**********************/

//	Return keyMethod that will produce a unique key - nil if none exists
VALUE rb_RPDB_DatabaseObject_uniqueKeyMethod(	VALUE	rb_self )	{
	
	VALUE	rb_unique_key_methods	=	rb_RPDB_DatabaseObject_uniqueKeyMethods( rb_self );
		
	//	iterate each unique key method, if method has non-nil value, return method
	
	VALUE	rb_this_unique_key_method;
	int	which_key_index		= 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_unique_key_methods ) ; which_key_index++) {
		
		rb_this_unique_key_method = RARRAY_PTR( rb_unique_key_methods )[ which_key_index ];
		
		//	Now we have to make sure we have a value for this method
		//	If not, we keep going
		if ( rb_funcall(	rb_self,
							SYM2ID( rb_this_unique_key_method ),
							0 ) != Qnil ) {
			
			return rb_this_unique_key_method;
		}
	}
	
	return Qnil;
}

/************************
*  uniqueKeyMethods  *
************************/

//	Returns array of all uniqueKeyMethods
VALUE rb_RPDB_DatabaseObject_uniqueKeyMethods(	VALUE	rb_self )	{
	
	//	primary key + unique secondary keys
	
	VALUE	rb_primary_key_method				=	rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self );
	
	VALUE	rb_unique_secondary_key_methods		=	rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods( rb_self );
	
	VALUE	unique_key_method_array_return	=	Qnil;
	if (	rb_primary_key_method != Qnil
		&&	rb_unique_secondary_key_methods != Qnil )	{
		
		//	We want primary key method first in the return array
		unique_key_method_array_return	=	rb_ary_concat(	rb_ary_push(	rb_ary_new(),
																			rb_primary_key_method ),
															rb_unique_secondary_key_methods );
	}
	else if ( rb_primary_key_method != Qnil )	{
		unique_key_method_array_return	=	rb_ary_new();
		rb_ary_push(	unique_key_method_array_return,
						rb_primary_key_method );
	}
	else if ( rb_unique_secondary_key_methods != Qnil )	{
		return rb_unique_secondary_key_methods;
	}
	
	return unique_key_method_array_return;
}

/****************
*  keyMethods  *
****************/

VALUE rb_RPDB_DatabaseObject_keyMethods(	VALUE	rb_self )	{
	
	//	primary key + secondary keys
	
	VALUE	rb_primary_key_method		=	rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self );
	
	VALUE	rb_secondary_key_methods	=	rb_RPDB_DatabaseObject_secondaryKeyMethods( rb_self );
	
	//	We want primary key method first in the return array
	return rb_ary_concat(	rb_ary_push(	rb_ary_new(),
											rb_primary_key_method ),
							rb_secondary_key_methods );
}

/****************
*  primaryKey  *
****************/

//	return unique key method
VALUE rb_RPDB_DatabaseObject_primaryKey( VALUE	rb_self )	{

	return rb_funcall(	rb_self,
						SYM2ID( rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self ) ),
						0 );
						
}
	
/****************
*  uniqueKey  *
****************/

//	return unique key method
VALUE rb_RPDB_DatabaseObject_uniqueKey( VALUE	rb_self )	{

	VALUE	rb_primary_key_method	=	rb_RPDB_DatabaseObject_primaryKeyMethod( rb_self );
	
	if ( rb_primary_key_method == Qnil )	{
		
		rb_raise( rb_eRuntimeError, RPDB_RUBY_ERROR_PRIMARY_KEY_MISSING );
	}

	//	First, check primary key
	VALUE	rb_primary_key	=	rb_RPDB_DatabaseObject_primaryKey( rb_self );
	
	//	If we have primary key, return key value
	if ( rb_primary_key != Qnil )	{
		return rb_primary_key;
	}
			
	//	Second, check unique secondary keys
	VALUE	rb_unique_secondary_key_methods	=	rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods( rb_self );

	//	If we have no primary key (and got here) and also have no secondary key methods, return nil
	if ( rb_unique_secondary_key_methods == Qnil )	{
		return Qnil;
	}
	
	//	If we have unique seconday key, return hash ( :key_method => key_value )
	VALUE	rb_this_unique_key_value		=	Qnil;
	VALUE	rb_this_unique_key_method		=	Qnil;

	int	which_key_index		= 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_unique_secondary_key_methods ) ; which_key_index++ ) {

		rb_this_unique_key_method = RARRAY_PTR( rb_unique_secondary_key_methods )[ which_key_index ];
			
		rb_this_unique_key_value	=	rb_funcall(	rb_self,
													SYM2ID( rb_this_unique_key_method ),
													0 );
		
		if ( rb_this_unique_key_value != Qnil )	{
			
			VALUE	rb_secondary_key_hash	=	rb_hash_new();

			rb_hash_aset(	rb_secondary_key_hash,
							rb_this_unique_key_method,
							rb_this_unique_key_value );
			
			return rb_secondary_key_hash;
		}
	}
		
	//	If we got here we have no unique key value
	return Qnil;	
}	

/****************
*  uniqueKeys  *
*****************/

//	return all unique keys
VALUE rb_RPDB_DatabaseObject_uniqueKeys(	VALUE	rb_self )	{
	
	//	get unique key methods
	VALUE	rb_unique_key_methods	=	rb_RPDB_DatabaseObject_uniqueKeyMethods( rb_self );
	
	//	iterate calling methods and push each non-nil key onto return hash
	VALUE	rb_this_unique_key_method	= 0;
	VALUE	rb_return_hash	=	rb_hash_new();
	VALUE	key;
	
	if ( rb_unique_key_methods == Qnil )	{
		return Qnil;
	}
		
	int	which_key_index = 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_unique_key_methods ) ; which_key_index++) {
		
		rb_this_unique_key_method = RARRAY_PTR( rb_unique_key_methods )[ which_key_index ];
		
		key	=	rb_funcall(	rb_self,
							SYM2ID( rb_this_unique_key_method ),
							0 );
		if ( key != Qnil )	{
			
			rb_hash_aset(	rb_return_hash,
							rb_this_unique_key_method,
							key );
		}
	}
	
	return rb_return_hash;	
}	

/************************************************
*  isUniqueKey  *
************************************************/

VALUE rb_RPDB_DatabaseObject_isUniqueKeyMethod(	VALUE	rb_self,
													VALUE	rb_key_method_symbol )	{
	
	return rb_ary_includes(	rb_RPDB_DatabaseObject_uniqueKeyMethods( rb_self ), 
							rb_key_method_symbol );
}

/********************
*  secondaryKeys  *
*******************/

//	return all secondary keys
VALUE rb_RPDB_DatabaseObject_secondaryKeys(	VALUE	rb_self )	{

	//	get key methods
	VALUE	rb_key_methods	=	rb_RPDB_DatabaseObject_secondaryKeyMethods( rb_self );
	
	//	iterate calling methods and push each non-nil key onto return hash
	VALUE	rb_this_key_method	= 0;
	VALUE	rb_return_hash	=	rb_hash_new();
	VALUE	key;
	
	int	which_key_index = 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_key_methods ) ; which_key_index++) {
		
		rb_this_key_method = RARRAY_PTR( rb_key_methods )[ which_key_index ];
		
		key	=	rb_funcall(	rb_self,
							SYM2ID( rb_this_key_method ),
							0 );

		if ( key != Qnil )	{
			
			rb_hash_aset(	rb_return_hash,
							rb_this_key_method,
							key );
		}
	}
	
	return rb_return_hash;	
}

/************************
*  uniqueSecondaryKey  *
***********************/

//	return first unique secondary key
VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKey(	VALUE	rb_self )	{
	
	VALUE	rb_unique_secondary_keys	=	rb_RPDB_DatabaseObject_uniqueSecondaryKeys( rb_self );
	
	VALUE	rb_return_value = Qnil;
	if (	rb_unique_secondary_keys != Qnil
		&&	RARRAY_LEN( rb_unique_secondary_keys ) > 0 )	{
		
		return rb_ary_entry( rb_unique_secondary_keys, 0 );
	}
	return rb_return_value; 
}
	
/*************************
*  uniqueSecondaryKeys  *
************************/

//	return all unique secondary keys
VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKeys(	VALUE	rb_self )	{

	//	get key methods
	VALUE	rb_key_methods	=	rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods( rb_self );
	
	//	iterate calling methods and push each non-nil key onto return hash
	VALUE	rb_this_key_method	= 0;
	VALUE	rb_return_hash	=	rb_hash_new();
	VALUE	rb_this_key;
	
	int	which_key_index		= 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_key_methods ) ; which_key_index++) {
		
		rb_this_key_method = RARRAY_PTR( rb_key_methods )[ which_key_index ];
		
		rb_this_key	=	rb_funcall(	rb_self,
									SYM2ID( rb_this_key_method ),
									0 );
		if ( rb_this_key != Qnil )	{
			
			rb_hash_aset(	rb_return_hash,
							rb_this_key_method,
							rb_this_key );
		}
	}
	
	return rb_return_hash;	
}

/****************************
*  nonUniqueSecondaryKeys  *
***************************/

//	return all non-unique secondary keys
VALUE rb_RPDB_DatabaseObject_nonUniqueSecondaryKeys(	VALUE	rb_self )	{

	//	get key methods
	VALUE	rb_key_methods	=	rb_RPDB_DatabaseObject_nonUniqueSecondaryKeyMethods( rb_self );
	
	//	iterate calling methods and push each non-nil key onto return hash
	VALUE	rb_this_key_method	= Qnil;
	VALUE	rb_return_hash		= rb_hash_new();
	VALUE	rb_this_key			= Qnil;

	int	which_key_index		= 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_key_methods ) ; which_key_index++) {
		
		rb_this_key_method = RARRAY_PTR( rb_key_methods )[ which_key_index ];
		
		rb_this_key	=	rb_funcall(	rb_self,
									SYM2ID( rb_this_key_method ),
									0 );
		if ( rb_this_key != Qnil )	{
			
			rb_hash_aset(	rb_return_hash,
							rb_this_key_method,
							rb_this_key );
		}
	}
		
	return rb_return_hash;	
}

/************
*  keys  *
************/

//	return unique key
VALUE rb_RPDB_DatabaseObject_keys(	VALUE	rb_self )	{
	
	//	get key methods
	VALUE	rb_key_methods	=	rb_RPDB_DatabaseObject_keyMethods( rb_self );
	
	//	iterate calling methods and push each non-nil key onto return hash
	VALUE	rb_this_key_method	= Qnil;
	VALUE	rb_return_hash		= rb_hash_new();
	VALUE	rb_this_key			= Qnil;

	int	which_key_index		= 0;
	for ( which_key_index = 0 ; which_key_index < RARRAY_LEN( rb_key_methods ) ; which_key_index++) {
		
		rb_this_key_method = RARRAY_PTR( rb_key_methods )[ which_key_index ];

		rb_this_key	=	rb_funcall(	rb_self,
									SYM2ID( rb_this_key_method ),
									0 );
		if ( rb_this_key != Qnil )	{
			
			rb_hash_aset(	rb_return_hash,
							rb_this_key_method,
							rb_this_key );
		}
	}
	
	return rb_return_hash;	
}	

/*******************************************************************************************************************************************************************************************
																Require ... Methods
*******************************************************************************************************************************************************************************************/

/********************************
*  requireEnvironment  *
*******************************/

VALUE rb_RPDB_DatabaseObject_requireEnvironment( VALUE rb_self )	{

	VALUE	rb_environment	=	rb_RPDB_DatabaseObject_environment( rb_self );
	
	if ( rb_environment == Qnil )	{
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_DEFAULT_ENVIRONMENT_NULL );
	}
	return rb_environment;
}

/********************************
*  requireDefaultEnvironment  *
*******************************/

VALUE rb_RPDB_DatabaseObject_requireDefaultEnvironment( VALUE rb_self __attribute__((unused)) )	{
	
	//	Ask runtime storage if a default environment exists
	RPDB_Environment*	c_default_environment	=	RPDB_RuntimeStorageController_defaultEnvironment( RPDB_RuntimeStorageController_sharedInstance() );
	if ( c_default_environment == NULL )	{
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_ENVIRONMENT_NULL );
	}
	return RUBY_RPDB_ENVIRONMENT( c_default_environment );
}

/****************************
*  requireDatabaseForIndex  *
***************************/

VALUE rb_RPDB_DatabaseObject_requireDatabaseForIndex(	VALUE	rb_self,
														VALUE	rb_index)	{
	
	VALUE	rb_database	=	rb_RPDB_DatabaseObject_databaseForIndex(	rb_self,
																		rb_index );
	
	if ( rb_database == Qnil )	{
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
	}
	return rb_database;
}

/********************************
*  requireUniqueKeyMethod  *
*******************************/

VALUE rb_RPDB_DatabaseObject_requireUniqueKeyMethod( VALUE rb_self )	{
	
	VALUE	rb_unique_key_method	=	Qnil;
	//	Make sure we have a key sufficient for retrieving
	if ( ( rb_unique_key_method = rb_RPDB_DatabaseObject_uniqueKeyMethod( rb_self ) ) == Qnil )	{		
		//	Throw an error - missing key
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY_METHOD );
	}	

	return rb_unique_key_method;
}

/****************************
*  requireUniqueKey  *
***************************/

VALUE rb_RPDB_DatabaseObject_requireUniqueKey( VALUE rb_self )	{
	
	VALUE	rb_unique_key_method	=	rb_RPDB_DatabaseObject_requireUniqueKeyMethod( rb_self );
	
	VALUE	rb_unique_key	=	Qnil;
	
	//	Make sure we have a key sufficient for retrieving
	if ( ( rb_unique_key = rb_funcall(	rb_self,
										SYM2ID( rb_unique_key_method ),
										0 ) ) == Qnil )	{		
		//	Throw an error - missing key
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY );
	}

	return rb_unique_key;
}

/*******************************************************************************************************************************************************************************************
																Write Methods
*******************************************************************************************************************************************************************************************/

/****************
*  write  *
****************/

VALUE rb_RPDB_DatabaseObject_write(	int	argc,
										VALUE*	args,
										VALUE	rb_self )	{

	//	Two cases:
	//	* rb_self is a Class
	//	* rb_self is an instance of Class
	
	//	If we have a class, we expect an array of objects to write
	if ( TYPE( rb_self ) == T_CLASS )	{
		
		//	Write each object to database
		int		which_object	=	0;
		for ( which_object = 0 ; which_object < argc ; which_object++ )	{
			
			//	Presumes that objects are passed since it's a DBObject class
			rb_funcall(	args[ which_object ],
						rb_intern( "write" ),
						0 );
		}
	}
	//	If we have an instance, we write it
	else	{
		
		//	Make sure we have a database set or fail
		if ( NIL_P( rb_RPDB_DatabaseObject_database( rb_self ) ) )	{
			//	Throw an error - missing database
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
		}
		
		rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
		
		RPDB_Record*	c_record	=	rb_RPDB_DatabaseObject_internal_compactRetrievalObject( rb_self );		

		RPDB_Database_write(	c_record->parent_database,
								c_record );
	}
	
	return rb_self;
}

/*******************************************************************************************************************************************************************************************
															Retrieval Methods
*******************************************************************************************************************************************************************************************/

/************************
*  exists  *
************************/

VALUE rb_RPDB_DatabaseObject_exists(	int	argc,
										VALUE*	args,
										VALUE	rb_self )	{
	
	//	Args: parameter_generic, ...

	//	FIX - does not currently work for key/data pair - only for key
	
	//	Two cases:
	//	* rb_self is a Class
	//	* rb_self is an instance of Class
	
	BOOL	exists	=	Qfalse;
	
	//	If we have a class, we expect an array of objects to write
	if ( TYPE( rb_self ) == T_CLASS )	{
		
		//	FIX - this needs more investigation as to what it should be doing
		
		int		which_object	=	0;
		for ( which_object = 0 ; which_object < argc ; which_object++ )	{
			
			//	Make sure we have a database set or fail
			if ( NIL_P( rb_RPDB_DatabaseObject_database( rb_self ) ) )	{
				//	Throw an error - missing database
				rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
			}
			
			rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
			
			//	we have an argument (string, object, etc) that needs to be deleted from the database as the key
			
			RPDB_Database*		c_database;
			C_RPDB_DATABASE_OBJECT_DATABASE( rb_RPDB_DatabaseObject_database( rb_self ), c_database );
			
			RPDB_Record*	c_record	=	RPDB_Record_new( c_database );
			
			//	so we need to prepare the key using our key prep function for DB object since it's a DBObject db
			rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ which_object ],
																				c_record->key->wrapped_bdb_dbt );
			
			//	and then we can call delete on the db with the prepared key
			if ( RPDB_Database_retrieveRecord(	c_database,
												c_record ) == NULL )	{
				//	a record doesn't exist - return false
				return Qfalse;
			}											
		}
		//	If we got here all records existed
		return Qtrue;
	}
	//	If we have an instance
	else	{
		
		//	Make sure we have a database set or fail
		if ( NIL_P( rb_RPDB_DatabaseObject_database( rb_self ) ) )	{
			//	Throw an error - missing database
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
		}
		
		rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
		
		VALUE	rb_key	=	Qnil;
		//	Make sure we have a key sufficient for retrieving
		if ( ( rb_key = rb_RPDB_DatabaseObject_uniqueKey( rb_self ) ) == Qnil )	{		
			//	Throw an error - missing key
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY );
		}
		
		VALUE	rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
		
		RPDB_Database*	c_database	=	NULL;
		C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );
		
		//	We need to load our rb_key into a raw c key (void*) with defined byte length
		RPDB_Record*	c_record	=	RPDB_Record_new( c_database );
		
		rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																			c_record->key->wrapped_bdb_dbt );
		
		if ( RPDB_Database_retrieveRecord(	c_database,
											c_record ) )	{
			exists = Qtrue;
		}
		
		RPDB_Record_free( & c_record );
		
	}
	
	return exists;
}

/************************
*  retrieve  *
************************/

//	If called on class, creates object for first requested key that has corresponding data
//	If called on an instance, returns current database record for object
VALUE rb_RPDB_DatabaseObject_retrieve(	int	argc,
										VALUE*	args,
										VALUE	rb_self )	{

	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
	
	//	Two cases:
	//	* rb_self is a Class
	//	* rb_self is an instance of Class
	//	If we have a class, we expect an array of objects to retrieve
	//	Returns first object that exists
	VALUE	return_object	=	Qnil;
	if ( TYPE( rb_self ) == T_CLASS )	{
		
		//	Retrieve includes retrieve multiple - if a secondary index allows duplicates, duplicate retrieval is implied
		//	Retrieve multiple can mean two things
		//	* retrieving multiple individual objects
		//	* retrieving a cursor for multiple duplicates
		//	Both should be possible in any combination
		//	Results are returned :key_method => result_object_or_cursor
		
		//	send rb_self (class) and args (objects to retrieve)
		return_object	=	rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameters(	argc,
																										args,
																										rb_self );
		
	}
	//	If we have an instance, we return the current db record corresponding - we can simply pass self to internal retrieve
	else	{
		
		//	you can't retrieve multiple on an instance (so no cursors and no join cursors are returned, only single records as rb_new_self)
		//	Arguments on rb_self instance are treated as initialize arguments
		
		return_object	=	rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedData(	rb_self );
	}

	//	Failure - we return nil (which does not change rb_self)
	RETURN_SIMPLIFIED_RUBY_ARRAY( return_object );
}

/*******************************************************************************************************************************************************************************************
															Deletion Methods
*******************************************************************************************************************************************************************************************/

/********************
*  delete  *
********************/

VALUE rb_RPDB_DatabaseObject_delete(	int	argc,
										VALUE*	args,
										VALUE	rb_self )	{
	
	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
	
	//	Two cases:
	//	* rb_self is a Class
	//	* rb_self is an instance of Class
	
	//	If we have a class, we expect an array of objects to write
	if ( TYPE( rb_self ) == T_CLASS )	{
		
		//	Delete each key from database
		int		which_object	=	0;
		for ( which_object = 0 ; which_object < argc ; which_object++ )	{
			
			//	Make sure we have a database set or fail
			if ( NIL_P( rb_RPDB_DatabaseObject_database( rb_self ) ) )	{
				//	Throw an error - missing database
				rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
			}
			
			//	we have an argument (string, object, etc) that needs to be deleted from the database as the key
			
			RPDB_Database*		c_database;
			C_RPDB_DATABASE_OBJECT_DATABASE( rb_RPDB_DatabaseObject_database( rb_self ), c_database );
			
			RPDB_Record*	c_record	=	RPDB_Record_new( c_database );
			
			//	so we need to prepare the key using our key prep function for DB object since it's a DBObject db
			rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	args[ which_object ],
																				c_record->key->wrapped_bdb_dbt );

			//	and then we can call delete on the db with the prepared key
			RPDB_Database_deleteRecord(	c_database,
											c_record );
		}
	}
	//	If we have an instance, we write it
	else	{
	
		//	Make sure we have a database set or fail
		if ( NIL_P( rb_RPDB_DatabaseObject_database( rb_self ) ) )	{
			//	Throw an error - missing database
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_DATABASE );
		}
		
		VALUE	rb_key	=	Qnil;
		//	Make sure we have a key sufficient for retrieving
		if ( ( rb_key = rb_RPDB_DatabaseObject_uniqueKey( rb_self ) ) == Qnil )	{		
			//	Throw an error - missing key
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY );
		}

		VALUE	rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
		
		RPDB_Database*	c_database	=	NULL;
		C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );
				
		//	We need to load our rb_key into a raw c key (void*) with defined byte length
		RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

		rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																			c_record->key->wrapped_bdb_dbt );
			
		RPDB_Database_deleteRecord(	c_database,
										c_record );
		
		RPDB_Record_free( & c_record );
	}
	
	return rb_self;
}

/*************
*  cursor  *
************/

VALUE rb_RPDB_DatabaseObject_cursor( int	argc,
									 VALUE*	args,
									 VALUE	rb_self )	{

	VALUE	rb_index				=	Qnil;
	rb_scan_args(	argc,
					args,
					"01",
					& rb_index );
	
	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );

	VALUE	rb_database	=	Qnil;
	if ( rb_index != Qnil )	{
		rb_database	=	rb_RPDB_DatabaseObject_databaseForIndex(	rb_self,
																	rb_index );
	}
	else {
		rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
	}

	VALUE	rb_database_object_cursor	=	Qnil;
	rb_database_object_cursor	=	rb_RPDB_DatabaseObjectDatabase_cursor( rb_database );
	
	return rb_database_object_cursor;
}

/*************
*  cursors  *
************/

VALUE rb_RPDB_DatabaseObject_cursors( VALUE rb_self )	{

	VALUE	rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
	
	return rb_RPDB_Database_cursorController( rb_database );
}

/*************
*  iterate  *
************/

VALUE rb_RPDB_DatabaseObject_iterate(	int	argc,
										VALUE*	args,
										VALUE	rb_self )	{
		
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
	
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}
	
	//	Make sure that databases are open
	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );

	//	Get a database object cursor on the database for class
	VALUE	rb_cursor	=	rb_RPDB_DatabaseObject_cursor( 1,
															& rb_index,
															rb_self );

	rb_RPDB_DatabaseObject_internal_beginCursorContext(	rb_self,
															rb_cursor );
	
	if ( rb_RPDB_DatabaseObjectCursor_retrieveFirst( rb_cursor ) == Qnil )	{
		return Qnil;
	}

	//	Call iterate on the cursor
	VALUE	return_value	=	rb_RPDB_DatabaseObjectCursor_iterate(	argc,
																		args,
																		rb_cursor );

	rb_RPDB_DatabaseObject_internal_endCursorContext(	rb_self,
														rb_cursor );

	return return_value;
}

/*************
*  iterateDuplicates  *
************/

VALUE rb_RPDB_DatabaseObject_iterateDuplicates(	int	argc,
													VALUE*	args,
													VALUE	rb_self )	{

	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}

	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );

	VALUE	rb_cursor	=	Qnil;

	//	to iterate duplicates we need to have a key set to start on
	//	that means we need to have a cursor that has already set the key
	//	we can't just use one cursor for the object because multiple threads may simultaneously ask the class to iterate
	//
	//	so we need to know how to get the cursor being used in a block "outside" the duplicate iteration that sets the key
	//	there seem to be two ways to get the cursor
	//	1. look up the call stack to find the last iteration block, which we are inside
	//	2. identify the context in which the last enumerator was returned and see if it matches part of our current backtrace context
	//	we can't simply pass the cursor in because if we start by iterating the object then we don't have a name to the cursor
	//	and if we don't use a block to iterate, but rather use an enumerator, then we don't have an easy way to tell
	//
	//	we can't use the object as an identifier because different portions of the object could be used for different non-associated iterations
	//	
	//	it doesn't make sense to iterate more than once or to iterate duplicates more than once at the same time
	//	so it would seem that we can identify the cursor by the context in which it is called
	//
	//	- unless the context changes, for instance if a sub-function of the calling context continues the sub-iteration 
	//	(this is possible particularly if we are using enumerators rather than blocks) so to find the context in these cases 
	//	we need to know the last context in which an enumerator was returned
	//	when we get the duplicate iterator cursor we can find it by looking up the call stack to match the last call context with the current call context stack
	
	//	if we have :iterate or :iterate_keys in the backtrace we know we are inside a block
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
	VALUE	rb_iterate_frame		=	rb_hash_new();
	VALUE	rb_iterate_keys_frame	=	rb_hash_new();
	rb_hash_aset(	rb_iterate_frame,
					ID2SYM( rb_intern( "method" ) ),
					ID2SYM( rb_intern( "iterate" ) ) );
	rb_hash_aset(	rb_iterate_frame,
					ID2SYM( rb_intern( "object" ) ),
					rb_klass );
	rb_hash_aset(	rb_iterate_keys_frame,
					ID2SYM( rb_intern( "method" ) ),
					ID2SYM( rb_intern( "iterate_keys" ) ) );
	rb_hash_aset(	rb_iterate_keys_frame,
					ID2SYM( rb_intern( "object" ) ),
					rb_klass );
	VALUE	rb_backtrace_frame_hash	=	rb_funcall(	rb_mKernel,
													rb_intern( "backtrace_frame_with" ),
													2,
													rb_iterate_frame,
													rb_iterate_keys_frame );
	if ( rb_backtrace_frame_hash != Qnil )	{
	
		//	we are inside a block, we need the cursor from the frame hash (the object where our :iterate or :iterate_keys context is located)
		rb_cursor	=	rb_hash_aref(	rb_backtrace_frame_hash,
										ID2SYM( rb_intern( "object" ) ) );
	}
	
	//	if we don't, we presume we are iterating using enumerators rather than blocks
	else if ( ( rb_cursor = rb_RPDB_DatabaseObject_internal_cursorForCallingContext( rb_self ) ) == Qnil )	{

		//	if we can't find the last corresponding enumeration frame, throw an error
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_UNABLE_TO_FIND_ENUMERATION_FRAME );
	}
	
	RPDB_DatabaseCursor*	c_database_cursor	=	NULL;
	C_RPDB_DATABASE_OBJECT_CURSOR( rb_cursor, c_database_cursor );
	
	//	Call iterate on the cursor
	return rb_RPDB_DatabaseObjectCursor_iterateDuplicates(	argc,
															args,
															rb_cursor );	
}

/*************
*  iterate  *
************/

VALUE rb_RPDB_DatabaseObject_iterateKeys(	int	argc,
											VALUE*	args,
											VALUE	rb_self )	{
	
	//	2 possible args:
	//	* index
	//	* item per segment
	VALUE	rb_items_per_segment	=	Qnil;
	VALUE	rb_index				=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		VALUE	this_arg	=	args[ which_arg ];
		
		if ( TYPE( this_arg ) == T_SYMBOL )	{
			rb_index				=	this_arg;			
		}
		else if ( TYPE( this_arg ) == T_FIXNUM ) {
			rb_items_per_segment	=	this_arg;
		}
	}
	
	//	we need a way that we can re-use cursors for iteration when appropriate rather than creating one for every iteration
	//	when each is called, a cursor is opened for the iteration; 
	//	
	//	there are several ways it makes sense to iterate a database:
	//	* iterate (by unique key)
	//	* iterate_duplicate (every duplicate for current key)
	//	* iterate_keys (every unique key, ignoring whether data has duplicates)
	//
	//	iterate is always going to start with a new cursor, as it doesn't make sense to iterate inside an iteration
	//	iterate_duplicates only makes sense inside an iteration, as it requires the cursor be set to a unique key
	//	iterate_keys is always goign to start with a new cursor, as it doesn't make sense to iterate inside an iteration
	//
	
	
	rb_RPDB_DatabaseObject_internal_ensureInitialized( rb_self );
				
	VALUE	rb_cursor		=	rb_RPDB_DatabaseObject_cursor( 1,
																& rb_index,
																rb_self );

	rb_RPDB_DatabaseObject_internal_beginCursorContext(	rb_self,
															rb_cursor );
	
	if ( rb_RPDB_DatabaseCursor_retrieveFirst( rb_cursor ) == Qnil )	{
		return Qnil;
	}
	
	//	Call iterate on the cursor
	VALUE	rb_return_value	=	rb_RPDB_DatabaseObjectCursor_iterateKeys(	1,
																			& rb_items_per_segment,
																			rb_cursor );

	rb_RPDB_DatabaseObject_internal_endCursorContext(	rb_self,
														rb_cursor );
	
	return rb_return_value;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
														Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/****************************
*  cursorForCallingContext  *
***************************/

VALUE rb_RPDB_DatabaseObject_internal_cursorForCallingContext( VALUE rb_self )	{

	//	when we are looking for the contextual iterator, we look up the current backtrace
	//	at each level of the backtrace we have an object and a method;
	//	if this object and method match keys present in self (tracking calling contexts for iteration in this iteration class) return cursor

	VALUE	rb_cursor_context_storage_hash	=	rb_RPDB_DatabaseObject_internal_cursorContextStorageHash( rb_self );
	
	VALUE	rb_args			=	rb_ary_new();
	VALUE	rb_cursor		=	Qnil;
	rb_ary_push(	rb_args,
					rb_cursor_context_storage_hash );
	rb_ary_push(	rb_args,
					rb_cursor );
	
	if ( RHASH_SIZE( rb_cursor_context_storage_hash ) )	{

		 rb_cursor	=	rb_rescue(	rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_wrapper, 
									rb_args,
									rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_return_cursor, 
									rb_args );		
	}
	
	return rb_cursor;	
		
}

/********************************************
*  each_backtrace_frame_exception_wrapper  *
*******************************************/

VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_wrapper( VALUE rb_args )	{

	rb_block_call(	rb_mKernel, 
					rb_intern( "each_backtrace_frame" ), 
					0,
					NULL, 
					rb_RPDB_DatabaseObject_internal_each_backtrace_frame, 
					rb_args );
	return Qnil;
}

/****************************************************
*  each_backtrace_frame_exception_return_cursor  *
***************************************************/

VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_return_cursor( VALUE rb_args )	{
	//	return cursor, which is index 1
	return rb_ary_entry( rb_args, 1 );
}

/****************************
*  each_backtrace_frame  *
***************************/

//	walk up the stack one frame at a time
//	for each frame we need to see if object/method are defined in our context storage hash
VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame(	VALUE	rb_this_backtrace_frame_hash, 
																VALUE	rb_args )	{
																
	VALUE	rb_cursor_context_storage_hash	=	rb_ary_entry( rb_args, 0 );
	VALUE	rb_cursor_return				=	rb_ary_entry( rb_args, 1 );
	
	//	each frame is identifiable as object/method
	VALUE	rb_this_frame_object	=	rb_hash_aref(	rb_this_backtrace_frame_hash,
														ID2SYM( rb_intern( "object" ) ) );
	VALUE	rb_this_frame_method	=	rb_hash_aref(	rb_this_backtrace_frame_hash,
														ID2SYM( rb_intern( "method" ) ) );
	
	VALUE	rb_cursor_object_context_hash	=	rb_RPDB_DatabaseObject_internal_cursorObjectContextStorageHash(	rb_cursor_context_storage_hash,
																													rb_this_frame_object);
	
	if ( RHASH_SIZE( rb_cursor_object_context_hash ) )	{
	
		rb_cursor_return	=	rb_hash_aref(	rb_cursor_object_context_hash,
												rb_this_frame_method );
		if ( rb_cursor_return != Qnil )	{
			rb_ary_store( rb_args, 1, rb_cursor_return );
			rb_raise( rb_eStopIteration, "iteration reached an end" );
		}
	}
	
	return Qnil;
}

/************************
*  beginCursorContext  *
***********************/

void rb_RPDB_DatabaseObject_internal_beginCursorContext(	VALUE	rb_self,
															VALUE	rb_cursor )	{


	VALUE	rb_object_context	=	rb_funcall(	rb_mKernel,
												rb_intern( "__sender__" ),
												0 );
	VALUE	rb_caller_context	=	rb_funcall(	rb_mKernel,
												rb_intern( "__caller__" ),
												0 );
	
	//	if there was no block when we got an enumerator, we store the calling context (specific to the iteration class)
	VALUE	rb_cursor_context_storage_hash	=	rb_RPDB_DatabaseObject_internal_cursorContextStorageHash( rb_self );

	//	since we are sub-sorting by object we need the object hash [ object ]
	VALUE	rb_cursor_object_context_hash	=	rb_RPDB_DatabaseObject_internal_cursorObjectContextStorageHash(	rb_cursor_context_storage_hash,
																													rb_object_context );

	//	add current context ([ object ][ method ] = cursor) to context storage hash 
	rb_hash_aset(	rb_cursor_object_context_hash,
					rb_caller_context,
					rb_cursor );
					
}

/************************
*  endCursorContext  *
***********************/

void rb_RPDB_DatabaseObject_internal_endCursorContext(	VALUE	rb_self,
																												VALUE	rb_cursor __attribute__((unused)) )	{

	//	remove current context ([ object ][ method ] = cursor) to context storage hash 
	VALUE	rb_object_context	=	rb_funcall(	rb_mKernel,
																				rb_intern( "__sender__" ),
																				0 );
	VALUE	rb_caller_context	=	rb_funcall(	rb_mKernel,
																				rb_intern( "__caller__" ),
																				0 );
	
	//	if there was no block when we got an enumerator, we store the calling context (specific to the iteration class)
	VALUE	rb_cursor_context_storage_hash	=	rb_RPDB_DatabaseObject_internal_cursorContextStorageHash( rb_self );
	
	//	since we are sub-sorting by object we need the object hash [ object ]
	VALUE	rb_cursor_object_context_hash	=	rb_RPDB_DatabaseObject_internal_cursorObjectContextStorageHash(	rb_cursor_context_storage_hash,
																																																				rb_object_context);
	
	//	add current context ([ object ][ method ] = cursor) to context storage hash 
	rb_hash_delete(	rb_cursor_object_context_hash,
									rb_caller_context );
}

/********************************
*  cursorContextStorageHash  *
*******************************/

VALUE rb_RPDB_DatabaseObject_internal_cursorContextStorageHash( VALUE rb_self )	{

	
	//	We store databases in our class instance inside a hash by method
	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
	
	//	Create our hash if it doesn't exist yet
	VALUE	rb_cursor_context_storage_hash	=	Qnil;
	if ( ( rb_cursor_context_storage_hash	=	rb_iv_get(	rb_klass,
															RPDB_RUBY_CLASS_VARIABLE_CURSOR_CONTEXT_STORAGE ) ) == Qnil )	{
		rb_cursor_context_storage_hash	=	rb_hash_new();
		rb_iv_set(	rb_klass,
					RPDB_RUBY_CLASS_VARIABLE_CURSOR_CONTEXT_STORAGE,
					rb_cursor_context_storage_hash );
	}
	
	return rb_cursor_context_storage_hash;	
}

/************************************
*  cursorObjectContextStorageHash  *
***********************************/

VALUE rb_RPDB_DatabaseObject_internal_cursorObjectContextStorageHash(	VALUE	rb_cursor_context_storage_hash,
																		VALUE	rb_object_context )	{

	//	since we are sub-sorting by object we need the object hash [ object ]
	VALUE	rb_cursor_object_context_hash	=	rb_hash_aref(	rb_cursor_context_storage_hash,
																rb_object_context );
	if ( rb_cursor_object_context_hash == Qnil )	{
		rb_cursor_object_context_hash	=	rb_hash_new();
		rb_hash_aset(	rb_cursor_context_storage_hash,
						rb_object_context,
						rb_cursor_object_context_hash );
	}
	
	return rb_cursor_object_context_hash;
}

/*******************************************************************************************************************************************************************************************
														Internal Storage Methods
*******************************************************************************************************************************************************************************************/

/********************
*  getEnvironment  *
*******************/

VALUE rb_RPDB_DatabaseObject_internal_getEnvironment(	VALUE	rb_self )	{
	
	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	return rb_iv_get(	rb_klass,
						RPDB_RUBY_CLASS_VARIABLE_ENVIRONMENT_STORAGE );
}

/********************
*  storeDatabase  *
*******************/

//	Databases are stored in the class DatabaseObject they belong to
void rb_RPDB_DatabaseObject_internal_storeDatabase(	VALUE	rb_self,
														VALUE	rb_database,
														VALUE	rb_index_method	)	{
	
	if ( TYPE( rb_index_method ) == T_STRING )	{
		rb_index_method	=	STRING2SYM( rb_index_method );
	}
	
	rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceHash(	rb_self,
																		RPDB_RUBY_CLASS_VARIABLE_DATABASE_STORAGE,
																		rb_index_method,
																		rb_database );
}

/****************
*  getDatabase  *
***************/

VALUE rb_RPDB_DatabaseObject_internal_getDatabase( VALUE	rb_self,
													VALUE	rb_index_method )	{

	return rb_RPDB_DatabaseObject_internal_getObjectFromClassInstanceHash(	rb_self,
																			RPDB_RUBY_CLASS_VARIABLE_DATABASE_STORAGE,
																			rb_index_method );
}

/************************************
*  storeObjectInClassInstanceArray  *
***********************************/

VALUE rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceArray(	VALUE	rb_self,
																		char*	c_class_instance_array_name,
																		VALUE	rb_index_method	)	{
	
	//	We store databases in our class instance inside a hash by method
	VALUE	rb_storage	=	rb_RPDB_DatabaseObject_internal_getClassInstanceArray(	rb_self,
																					c_class_instance_array_name );
	
	//	All databases are stored by key method
	rb_ary_push(	rb_storage,
					rb_index_method );
	
	return rb_self;
}

/************************************
*  getObjectFromClassInstanceArray  *
***********************************/

VALUE rb_RPDB_DatabaseObject_internal_getClassInstanceArray(	VALUE	rb_self,
																char*	c_class_instance_hash_name )	{
	
	//	We store databases in our class instance inside a hash by method
	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
	
	//	Create our hash if it doesn't exist yet
	VALUE	rb_storage	=	Qnil;
	if ( ( rb_storage	=	rb_iv_get(	rb_klass,
										c_class_instance_hash_name ) ) == Qnil )	{
		rb_storage	=	rb_ary_new();
		rb_iv_set(	rb_klass,
					c_class_instance_hash_name,
					rb_storage );
	}
	
	return rb_storage;
}
	
/************************************
*  storeObjectInClassInstanceHash  *
***********************************/

VALUE rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceHash(	VALUE	rb_self,
																		char*	rb_class_instance_hash_name,
																		VALUE	rb_index_method,
																		VALUE	rb_object  )	{

	//	We store databases in our class instance inside a hash by method
	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
	
	//	Create our hash if it doesn't exist yet
	VALUE	rb_storage	=	Qnil;
	if ( ( rb_storage	=	rb_iv_get(	rb_klass,
										rb_class_instance_hash_name ) ) == Qnil )	{
		rb_storage	=	rb_hash_new();
		rb_iv_set(	rb_klass,
					rb_class_instance_hash_name,
					rb_storage	);
	}
	
	//	All databases are stored by key method
	rb_hash_aset(	rb_storage,
					rb_index_method,
					rb_object );
	
	return rb_self;
}

/************************************
*  getObjectFromClassInstanceHash  *
***********************************/

VALUE rb_RPDB_DatabaseObject_internal_getObjectFromClassInstanceHash(	VALUE	rb_self,
																		char*	rb_class_instance_hash_name,
																		VALUE	rb_index_method )	{

	//	We store databases in our class instance inside a hash by method
	VALUE	rb_klass	=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );
	
	//	Create our hash if it doesn't exist yet
	VALUE	rb_storage	=	Qnil;
	if ( ( rb_storage	=	rb_iv_get(	rb_klass,
										rb_class_instance_hash_name ) ) == Qnil )	{
		rb_storage	=	rb_hash_new();
		rb_iv_set(	rb_klass,
					rb_class_instance_hash_name,
					rb_storage	);
	}
	
	//	if we have a key return it, otherwise return nil
	if ( rb_hash_lookup(	rb_storage,
							rb_index_method ) )	{
							
		return	rb_hash_aref(	rb_storage,
							 rb_index_method );
	}
	
	//	All databases are stored by key method
	return Qnil;
}

/*******************************************************************************************************************************************************************************************
											Storage Packaging Methods
*******************************************************************************************************************************************************************************************/

/****************************************
*  prepareRubyObjectForDatabaseStorage  *
****************************************/

void rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	VALUE	rb_key,
																		DBT*	c_key_dbt	)	{
	
	//	We will need to marshall at least our object (rb_self) and potentially also the key
	VALUE	rb_marshal_class	=	RUBY_CLASS( "Marshal" );

	VALUE	rb_marshal_key;
		
	//	We need the key to be in string form
	switch ( TYPE( rb_key ) )	{
			
		case T_STRING:
			//	Make sure we always encode UTF-8
			//	FIX - figure out a better way to deal with encodings so we don't just flatten them to UTF-8
			//	Perhaps create a storage database that will keep track of default string storage type
			rb_key	=	rb_funcall(	rb_key,
									rb_intern( "encode" ),
									1,
									rb_str_new2( "UTF-8" ) );
		case T_CLASS:
		case T_OBJECT:
		case T_MODULE:
		case T_HASH:
		case T_ARRAY:
        case T_STRUCT:
        case T_FILE:
        case T_DATA:
        case T_SYMBOL:
		case T_REGEXP:
        case T_BIGNUM:
		case T_FIXNUM:
		case T_FLOAT:
		case T_TRUE:
		case T_FALSE:
			//	For all these, we marshal, otherwise we wouldn't know how to load		
			rb_marshal_key	=	rb_funcall(	rb_marshal_class,
											rb_intern( "dump" ),
											1,
											rb_key );
			
			c_key_dbt->data		=	strdup( (void*) StringValuePtr( rb_marshal_key ) );
			c_key_dbt->size		=	( RSTRING_LEN( rb_marshal_key ) + 1 ) * sizeof( char );
			c_key_dbt->flags	|=	DB_DBT_APPMALLOC;
			break;			
	}
}

/****************************************
*  unpackRubyObjectFromDatabaseStorage  *
****************************************/

VALUE rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( VALUE		rb_marshal_encoded_string )	{
	
	if ( RSTRING_LEN( rb_marshal_encoded_string ) == 0 )	{
		return Qnil;
	}
	
	VALUE	rb_marshal_class	=	RUBY_CLASS( "Marshal" );
	
	//	and unmarshal it
	VALUE	rb_self		=	rb_funcall(	rb_marshal_class,
										rb_intern( "load" ),
										1,
										rb_marshal_encoded_string );
	
	
	
	return rb_self;
}


/****************************
*  compactRetrievalObject  *
***************************/

RPDB_Record* rb_RPDB_DatabaseObject_internal_compactRetrievalObject( VALUE	rb_self )	{
	
	VALUE	rb_key	=	Qnil;

	VALUE	rb_database	=	rb_RPDB_DatabaseObject_database( rb_self );
	RPDB_Database*	c_database	=	NULL;
	C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );
	
	//	We need to load our rb_key into a raw c key (void*) with defined byte length
	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

	/********
	*  Key  *
	********/
	
	//	get primary key if available
	if ( ( rb_key = rb_RPDB_DatabaseObject_uniqueKey( rb_self ) ) == Qnil )	{
		//	Throw an error - missing key
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MISSING_UNIQUE_KEY );
	}

	rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key,
																		c_record->key->wrapped_bdb_dbt );

	/*********
	*  Data  *
	*********/
	
	//	We will need to marshall at least our object (rb_self) and potentially also the key
	VALUE	rb_marshal_class	=	RUBY_CLASS( "Marshal" );
	
	//	The data is always rb_self (an object), so it needs to be marshalled
	VALUE	rb_marshal_string	=	rb_funcall(	rb_marshal_class,
												rb_intern( "dump" ),
												1,
												rb_self );
	
	//	alloc memory to prevent local stack stomping during recursion
	uint32_t	c_marshal_string_length			=	RSTRING_LEN( rb_marshal_string );
	uint32_t	c_data_length					=	( c_marshal_string_length + 1 ) * sizeof( char );
	
	void*		c_data							=	calloc( c_data_length, sizeof( char ) );
	memcpy( c_data, (void*) StringValuePtr( rb_marshal_string ), c_data_length );
	
	c_record->data->wrapped_bdb_dbt->data		=	c_data;
	c_record->data->wrapped_bdb_dbt->size		=	c_data_length;
	c_record->data->wrapped_bdb_dbt->flags		|=	DB_DBT_APPMALLOC;

	return c_record;
}

/****************************************
*  extractRetrievalKey  *
****************************************/

VALUE rb_RPDB_DatabaseObject_internal_extractRetrievalKey( RPDB_Record* c_retrieval_record )	{
	
	void*	c_string_for_marshalled_ruby_self	=	RPDB_Record_rawKey( c_retrieval_record );
	
	//	Turn stored C string (converted from rb string for marshal data) back into Ruby string
	VALUE	rb_marshal_string	=	rb_str_new( c_string_for_marshalled_ruby_self,
												RPDB_Record_keySize( c_retrieval_record ) );
	
	
	return rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_marshal_string );	
}

/****************************************
*  extractRetrievalData  *
****************************************/

VALUE rb_RPDB_DatabaseObject_internal_extractRetrievalData( RPDB_Record* c_retrieval_record )	{

	void*	c_string_for_marshalled_ruby_self	=	RPDB_Record_rawData( c_retrieval_record );
	
	//	Turn stored C string (converted from rb string for marshal data) back into Ruby string
	VALUE	rb_marshal_string	=	rb_str_new( c_string_for_marshalled_ruby_self,
												RPDB_Record_dataSize( c_retrieval_record ) );
	
													
	return rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( rb_marshal_string );	
}



/*******************************************************************************************************************************************************************************************
													Internal Retrieval Methods
*******************************************************************************************************************************************************************************************/

/************************************************
*  retrieveEachOfMultipleFromParameterArray  *
************************************************/

//	This is the function that iterates retrieval of multiple distinct parameters (each a record)
VALUE rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameters(	int	argc,
																					VALUE*	args,
																					VALUE	rb_klass_self )	{
	
	VALUE	rb_return_array			=	rb_ary_new();
	int		which_object			=	0;
	for ( which_object = 0 ; which_object < argc ; which_object++ )	{
		
		rb_ary_push(	rb_return_array,
						rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataFromParameterDescription(	rb_klass_self,
																													args[ which_object ] ) );
	}
	return rb_return_array;
}

/************************************************
*  retrievePackedDataFromPreparedParameterDescription  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataFromParameterDescription(	VALUE	rb_klass_self,
																									   VALUE	rb_unique_key_parameter )	{
	
	//	We have either
	//	* primary key or unique secondary key
	//	* non-unique secondary key
	//	We already know the name of the key_method (that's what's specified)
	//	* it's a symbol or string, in which case it's a primary key
	//	* it's a hash :key_method => :key_value
	//	We can look up whether the secondary key method returns a unique key or not
	
	//	Now process the symbol or array or hash
	
	//	If we have an array we have a series of primary keys
	//	we are returning each item in order (flattening with rest of return items)
	VALUE	rb_return_array	=	rb_ary_new();
	if ( TYPE( rb_unique_key_parameter ) == T_ARRAY )	{
		
		rb_ary_push(	rb_return_array,
						rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameterDataArray(	rb_klass_self,
																											rb_unique_key_parameter ) );		
	}
	//	otherwise it's a hash with unique key(s)
	//	If we have a hash we have one or more secondary or primary keys
	//	we return either a record or a duplicates cursor or a join cursor
	else if ( TYPE( rb_unique_key_parameter ) == T_HASH )	{
		
		rb_ary_push(	rb_return_array,
					rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataHash(	rb_klass_self,
																							rb_unique_key_parameter ) );		
	}
	//	If it's not a hash or array we have a primary key - we return the record
	else	{
		
		rb_ary_push(	rb_return_array,
						rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataPrimaryKey(	rb_klass_self,
																									rb_unique_key_parameter ) );
	}
	RETURN_SIMPLIFIED_RUBY_ARRAY( rb_return_array );
}

/************************************************
*  retrievePackedDataFromPreparedParameterDescriptionArray  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameterDataArray(	VALUE	rb_klass_self,
																							VALUE	rb_unique_key_parameter )	{
	
	//	iterate the array and push each result onto return array
	VALUE	rb_return_array	=	rb_ary_new();
	VALUE	rb_this_primary_key_or_secondary_method_hash		=	Qnil;
	int		which_array_item	=	0;
	for( which_array_item = 0 ; which_array_item < RARRAY_LEN( rb_unique_key_parameter ) ; which_array_item++ )	{
		
		//	get ruby value for our item
		rb_this_primary_key_or_secondary_method_hash	=	RARRAY_PTR( rb_unique_key_parameter )[ which_array_item ];
		
		//	retrieve item for ruby value by recursing
		//	we want to return the same structure passed in
		//	if it's a string or symbol we push it onto return array
		//	if it's an array we push an array 
		//	if it's a hash we push the item or cursor depending on multiples
		rb_ary_push(	rb_return_array,
						rb_funcall(	rb_klass_self,
									rb_intern( "retrieve" ),
									1,
									rb_this_primary_key_or_secondary_method_hash ) );
	}
	return rb_return_array;
}	

/************************************************
*  retrievePackedDataFromPreparedParameterDescriptionHash  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataHash(	VALUE	rb_klass_self,
																					VALUE	rb_unique_key_parameter )	{
	
	//	Each hash corresponds to one retrieval item or set
	
	//	if we have only one key pair then either
	//	* unique key - one record (we return contents as prepared)
	//	* non-unique key - multiple records (cursor)
	VALUE	rb_return_object	=	Qnil;
	if ( RHASH_SIZE( rb_unique_key_parameter ) == 1 )	{
		
		rb_return_object	=	rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataMethodValueKeyHash(	rb_klass_self,
																															rb_unique_key_parameter	);
	}
	//	if we have more than one key pair then we are returning a join cursor
	else if ( RHASH_SIZE( rb_unique_key_parameter ) > 1 ) {

		//	foreach item: 
		VALUE	rb_passed_args	=	rb_ary_new();
		//	push the class
		rb_ary_push(	rb_passed_args,
						rb_klass_self );
		
		//	foreach item (once): 
		rb_hash_foreach(	rb_unique_key_parameter, 
							& rb_RPDB_DatabaseObject_internal_retrieveCursorsForEachParameterDescriptionForJoinCursor,
							rb_passed_args );
		
		//	rb_passed_args should end up with 1 element (rb_klass_self) + rb_self
		
		//	our cursor array is our passed args array minus the first index (rb_klass_self)
		VALUE	rb_cursor_array	=	rb_passed_args;
		//	chop off rb_klass_self and we have our cursor array
		rb_ary_shift( rb_cursor_array );

		//	If the last element in our array is false, one of the cursors failed to retrieve (record didn't exist)
		if ( RARRAY_PTR( rb_cursor_array )[ RARRAY_LEN( rb_cursor_array ) ] == Qfalse )	{
			return Qnil;
			//	rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CURSOR_FOR_JOIN_REPORTED_NO_RECORD );
		}
		
		VALUE	rb_index_name	=	rb_ary_shift( rb_cursor_array );
		
		//	now we have to create the join cursor - we name the name primary_name__join__idx-idx-idx
		rb_return_object	=	rb_RPDB_DatabaseJoinController_join(	rb_RPDB_Database_joinController( rb_RPDB_DatabaseObject_database( rb_klass_self ) ),
																		rb_index_name,
																		rb_cursor_array );
	}
	
	return rb_return_object;
}

/************************************************
*  retrievePackedDataFromPreparedParameterDescriptionPrimaryKey  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataPrimaryKey(	VALUE	rb_klass_self,
																						 VALUE	rb_unique_key_parameter )	{
	
	//	we don't know which database corresponds to our retrieval key, but we do know the key method
	//	so we can ask the object's class for the corresponding database
	VALUE	rb_database	=	rb_RPDB_DatabaseObject_database(	rb_klass_self );	
	RPDB_Database*	c_database	=	NULL;
	C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );
		
	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );
	
	//	we know how to produce our retrieval key
	//	call packRubyObjectForDatabaseStorage on our key value (rb_key_value)
	rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_unique_key_parameter,
																		c_record->key->wrapped_bdb_dbt );
	
	RPDB_Database_retrieveRecord(	c_database,
									c_record );
	
	VALUE	rb_object	=	rb_RPDB_DatabaseObject_internal_extractRetrievalData( c_record );
	
	RPDB_Record_free( & c_record );
	
	return rb_object;
}

/************************************************
*  retrievePackedDataFromPreparedParameterDescriptionMethodValueKeyHash  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataMethodValueKeyHash(	VALUE	rb_klass_self,
																							VALUE	rb_unique_key_parameter )	{
	
	//	We know here that we only ever have one element in our hash
	//	Calling "first" on the hash gives us the first element as a 2 element array
	VALUE	rb_unique_key_parameter_interior_array		= rb_funcall(	rb_unique_key_parameter,
																		rb_intern( "first" ),
																		0 );
																																				
	VALUE	rb_key_method_symbol		= rb_ary_entry( rb_unique_key_parameter_interior_array, 0 );
	VALUE	rb_key_value				= rb_ary_entry( rb_unique_key_parameter_interior_array, 1 );
	
	//	make sure we have symbols rather than strings for our key
	
	if ( TYPE( rb_key_method_symbol ) == T_STRING )	{
		rb_key_method_symbol	=	STRING2SYM( rb_key_method_symbol );
	}
	
	VALUE	rb_return_object	=	Qnil;
	
	//	check if key is in unique keys then we retrieve and return the item
	if ( rb_RPDB_DatabaseObject_isUniqueKeyMethod(	rb_klass_self,
													rb_key_method_symbol ) != Qfalse )	{
		
		//	we have been creating an object for retrieval - this requires that we have initialization arguments
		//	if we are retrieving an object we never actually use these initialization arguments
		//	they are only employed for the convenience of creating an object for retrieval
		//	so instead of creating an object for retrieval, let's get the necessary information to create a retrieval key
		//	and retrieve from the appropriate database
		
		//	we don't know which database corresponds to our retrieval key, but we do know the key method
		//	so we can ask the object's class for the corresponding database
		VALUE	rb_database	=	rb_RPDB_DatabaseObject_databaseForIndex(	rb_klass_self,
																			rb_key_method_symbol );
		RPDB_Database*	c_database	=	NULL;
		C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );

		RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

		//	we know how to produce our retrieval key
		//	call packRubyObjectForDatabaseStorage on our key value (rb_key_value)
		rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_key_value,
																			c_record->key->wrapped_bdb_dbt );
				
		if ( RPDB_Database_retrieveRecord(	c_database,
											c_record ) != NULL )	{

			rb_return_object	=	rb_RPDB_DatabaseObject_internal_extractRetrievalData( c_record );
		}
		
		RPDB_Record_free( & c_record );
	}
	//	if it's not, get a cursor
	else {
		
		rb_return_object	=	rb_RPDB_DatabaseObject_internal_retrieveCursorForParameterDescription(	rb_klass_self, 
																																			rb_key_method_symbol,
																																			rb_key_value );
	}
	return rb_return_object;
}	

/************************************************
*  retrieveCursorForSecondaryIndexFromParameterDescription  *
************************************************/

VALUE rb_RPDB_DatabaseObject_internal_retrieveCursorForParameterDescription(	VALUE	rb_self,
																					VALUE	rb_key_method_symbol,
																					VALUE	rb_key_value  )	{
		
	VALUE	rb_secondary_database	=	rb_RPDB_DatabaseObject_requireDatabaseForIndex(	rb_self,
																							rb_key_method_symbol );

	unsigned long	c_obj_id				=	(unsigned long) rb_obj_id( rb_self );
	char			c_obj_id_string[ 20 ];
	sprintf( c_obj_id_string, "%lu", c_obj_id );
	
	VALUE	rb_obj_id_string	=	rb_str_new2( c_obj_id_string );

	//	to prevent conflict in threaded environment, use key_method_symbol-key_value-obj_id
	//	this permits any object to have one thread per key method symbol/value request
	//	presumably there is no reason that the same object would be explicitly requesting a cursor for the same key/value pair more than once at the same time
	VALUE	rb_key_value_string	=	rb_str_concat( rb_str_concat( rb_str_concat(	rb_str_concat(	rb_sym_to_s( rb_key_method_symbol ), 
																									rb_str_new( "-", 1 ) ),
																									rb_obj_as_string( rb_key_value ) ),
																									rb_str_new( "-", 1 ) ),
																									rb_obj_id_string );
	
	VALUE	rb_cursor_name		=	rb_key_value_string;
	
	RPDB_Database*	c_secondary_database	=	NULL;
	C_RPDB_DATABASE_OBJECT_DATABASE( rb_secondary_database, c_secondary_database );
	
	RPDB_DatabaseCursor*	c_cursor	=	RPDB_DatabaseCursorController_cursor(	RPDB_Database_cursorController( c_secondary_database ) );
	//	We get the C cursor so we can wrap it as an rb_RPDB_DatabaseObjectCursor
	VALUE	rb_cursor	=	RUBY_RPDB_DATABASE_OBJECT_CURSOR( c_cursor );
	
	//	FIX - we probably want to add a method that gets called here that can be overridden for settings, etc.
	
	rb_RPDB_DatabaseCursor_open( rb_cursor );
	
	//	set cursor to first record
	//	we call via rb_funcall so that the class determines whether or not to use RPDB_DatabaseCursor or RPDB_DatabaseObjectCursor
	VALUE	rb_current	=	rb_funcall(	rb_cursor,
										rb_intern( "retrieve" ),
										1,
										rb_key_value );

    if ( rb_current == Qnil )   {
		return Qnil;
    }
	
	return rb_cursor;
}
	
/****************************************************
*  retrieveJoinCursorForEachParameterDescription  *
***************************************************/

//	rb_passed_args should end up with 1 element (rb_self) + 1 element (idx-idx string) + # of elements in hash
static int rb_RPDB_DatabaseObject_internal_retrieveCursorsForEachParameterDescriptionForJoinCursor(	VALUE	rb_key_method_symbol,
																							VALUE	rb_key_value,
																							VALUE	rb_passed_args )	{
	
	VALUE	rb_self					=	rb_ary_entry( rb_passed_args, 0 );
		
	VALUE	rb_join_cursor_name	=	Qnil;
	if ( RARRAY_LEN( rb_passed_args ) == 1 )	{
		rb_join_cursor_name	=	rb_str_new( "", 0 );
		//	join cursor name is passed args [ 1 ]
		rb_ary_push(	rb_passed_args,
						rb_join_cursor_name );
	}
	else {
		rb_join_cursor_name		=	rb_ary_entry( rb_passed_args, 1 );
	}

	//	make sure we have symbols rather than strings for our key
	if ( TYPE( rb_key_method_symbol ) == T_STRING )	{
		rb_key_method_symbol	=	STRING2SYM( rb_key_method_symbol );
	}
	
	VALUE	rb_cursor				=	rb_RPDB_DatabaseObject_internal_retrieveCursorForParameterDescription(	rb_self,
																												rb_key_method_symbol,
																												rb_key_value );
	
	//	If we get no record for setting our cursor we push false and fail
	if ( rb_cursor == Qnil )	{
		rb_ary_push(	rb_passed_args,
						Qfalse );
		return ST_STOP;		
	}
	
	RPDB_DatabaseCursor*	c_cursor	=	NULL;
	C_RPDB_DATABASE_OBJECT_CURSOR( rb_cursor, c_cursor );
	VALUE	rb_cursor_name	=	rb_str_new2( c_cursor->name );
	
	if ( RSTRING_LEN( rb_join_cursor_name ) == 0 )	{
		rb_join_cursor_name	=	rb_str_concat( rb_join_cursor_name, rb_cursor_name );
	}
	else {
		rb_join_cursor_name	=	rb_str_concat( rb_str_concat(	rb_join_cursor_name, 
																	rb_str_new( "-", 1 ) ),
																	rb_cursor_name );
	}
		
	VALUE	rb_current_record		=	rb_RPDB_DatabaseObjectCursor_current( rb_cursor );

	//	If we get no record for setting our cursor we push false and fail
	if ( rb_current_record == Qnil )	{
		
		rb_ary_push(	rb_passed_args,
						Qfalse );
		return ST_STOP;
	}

	//	push cursor for return
	rb_ary_push(	rb_passed_args,
					rb_cursor );
	
	return ST_CONTINUE;
}

/********************************************************
*  retrievePackedDataFromPreparedParameterDescription  *
*******************************************************/

//	This is the function that actually names retrieving our prepared key from the data and returning an extracted record
VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedData(	VALUE	rb_self	)	{
	
	//	Make sure we have sufficient key info for retrieval
	VALUE	rb_unique_key_method	=	rb_RPDB_DatabaseObject_requireUniqueKeyMethod( rb_self );
	VALUE	rb_unique_key			=	rb_RPDB_DatabaseObject_requireUniqueKey( rb_self );
	
	//	We need to get the database. Since our unique key might be in a secondary, we use our method (databaseForIndex) that works 
	//	on both primary and unique secondary keys.
	VALUE	rb_database	=	rb_RPDB_DatabaseObject_requireDatabaseForIndex(	rb_self,
																				rb_unique_key_method );
	RPDB_Database*	c_database	=	NULL;
	C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database );
	
	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

	rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_unique_key,
																		c_record->key->wrapped_bdb_dbt );
	
	//	The data is always rb_self (an object), so it needs to be unmarshalled - retrieve our object
	RPDB_Database_retrieveRecord(	c_database,
									c_record );
	
	//	And extract our object
	VALUE	retrieved_rb_self	=	rb_RPDB_DatabaseObject_internal_extractRetrievalData( c_record );
	
	RPDB_Record_free( & c_record );
	
	//	If we failed we return Qnil (default)
	return retrieved_rb_self;	
}

/************************************
*  verifyObjectAsEnvironment  *
************************************/

VALUE rb_RPDB_DatabaseObject_internal_verifyObjectAsEnvironment( VALUE rb_object __attribute__((unused)) )	{
	
	//	DatabaseObject currently requires nothing from environment, so no checks are made
	//	Any checks can be added here.
	
	return Qtrue;
}

/************************************
*  verifyObjectAsDatabase  *
************************************/

VALUE rb_RPDB_DatabaseObject_internal_verifyObjectAsDatabase( VALUE rb_object )	{
	
	VALUE	rb_given_object_methods	=	rb_ary_new();
	
	//	retrieve
	rb_ary_push(	rb_given_object_methods,
					ID2SYM( rb_intern( "retrieve" ) ) );
	
	//	write
	rb_ary_push(	rb_given_object_methods,
					ID2SYM( rb_intern( "write" ) ) );
	
	//	delete
	rb_ary_push(	rb_given_object_methods,
					ID2SYM( rb_intern( "delete" ) ) );
	
	return rb_RPDB_DatabaseObject_internal_verifyObjectHasMethods(	rb_object,
																	rb_given_object_methods );
}

/************************************
*  requireObjectVerifyAsEnvironment  *
************************************/

void rb_RPDB_DatabaseObject_internal_requireObjectVerifyAsEnvironment( VALUE rb_object __attribute__((unused)) )	{
	
	//	make sure object is of class RPDB::Environment
	
	//	FIX - for now we dont' verify

}

/************************************
*  requireObjectVerifyAsDatabase  *
************************************/

void rb_RPDB_DatabaseObject_internal_requireObjectVerifyAsDatabase( VALUE rb_object )	{
	
	if ( rb_RPDB_DatabaseObject_internal_verifyObjectAsDatabase( rb_object ) == Qfalse )	{
		rb_raise( rb_eArgError, RPDB_RUBY_ERROR_DATABASE_ARGUMENT_UNKNOWN_TYPE );
	}
}

/************************************
*  verifyObjectHasMethods  *
************************************/

VALUE rb_RPDB_DatabaseObject_internal_verifyObjectHasMethods(	VALUE	rb_object,
																VALUE	rb_method_symbol_array )	{
	
	VALUE	rb_verifies	=	Qtrue;
	int	which_method	=	0;
	for ( which_method = 0 ; which_method < RARRAY_LEN( rb_method_symbol_array ) ; which_method++ )	{
		if ( rb_obj_method(	rb_object,
							RARRAY_PTR( rb_method_symbol_array )[ which_method ] ) == Qnil )	{
			rb_verifies	=	Qfalse;
			break;
		}
	}
	return rb_verifies;
}

/*******************************************************************************************************************************************************************************************
											Secondary Index Callback Method
*******************************************************************************************************************************************************************************************/

/********************************
*  addSecondaryKeyMethods  *
*******************************/

VALUE rb_RPDB_DatabaseObject_internal_addSecondaryKeyMethods(	VALUE		rb_self,
																char*		c_secondary_key_class_instance_variable,
																int			argc,
																VALUE*		args	)	{
	
	VALUE	rb_secondary_key_method	=	Qnil;
	int	which_arg	=	0;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
		
		rb_secondary_key_method	=	args[ which_arg ];
		
		//	Store the non-unique secondary key method in array in class instance
		rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceArray(	rb_self,
																			c_secondary_key_class_instance_variable,
																			rb_secondary_key_method );

		//	now we have to create the database and associate it with the primary
		rb_RPDB_DatabaseObject_internal_createAndAssociateSecondaryDatabase(	rb_self,
																				rb_secondary_key_method	);
	}
	
	return rb_self;
}

/****************************************
*  createAndAssociateSecondaryDatabase  *
****************************************/

VALUE rb_RPDB_DatabaseObject_internal_createAndAssociateSecondaryDatabase(	VALUE	rb_self,
																			VALUE	rb_index_method_symbol )	{
	
	//	Get the primary from self
	VALUE	rb_primary_database	=	rb_funcall(	rb_self,
												rb_intern( "database" ),
												0 );
	
	RPDB_Database*	c_primary_database	=	NULL;
	C_RPDB_DATABASE_OBJECT_DATABASE( rb_primary_database, c_primary_database );
	
	VALUE	rb_index_method_string	=	rb_sym_to_s( rb_index_method_symbol );
	char*	c_index_method_string	=	StringValuePtr( rb_index_method_string );
	
	//	check to see if database already exists; if it does not, create it
	RPDB_Database*	c_secondary_database	=	RPDB_Database_databaseForSecondaryIndex(	c_primary_database,
																							c_index_method_string );
	if ( c_secondary_database == NULL )	{
		
		c_secondary_database	=	RPDB_Database_internal_createDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																														c_index_method_string,
																														TRUE );
	}
	
	VALUE	rb_secondary_database	=	RUBY_RPDB_DATABASE_OBJECT_DATABASE( c_secondary_database );
		
	rb_RPDB_DatabaseObject_internal_storeDatabase(	rb_self,
													rb_secondary_database,
													rb_index_method_symbol	);
	
	RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
														c_secondary_database,
														c_index_method_string,
														& rb_RPDB_DatabaseObject_internal_secondaryKeyCreationCallbackMethod );
	
	return rb_self;
}

/****************************************
*  secondaryKeyCreationCallbackMethod  *
****************************************/

//	This is the actual C method that gets called when a callback is set
RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_DatabaseObject_internal_secondaryKeyCreationCallbackMethod(	RPDB_Database*			c_secondary_database, 
																											RPDB_Record*			c_record, 
																											RPDB_SecondaryKeys*	c_secondary_keys )	{
	
	//	The DatabaseObject module callback functions entirely differently than the standard callback. 
	//	Here our goal has nothing to do with a ruby function.
	//	Intead, we are dealing with a ruby object, extracting stored info to call one of its methods.
	//	The method can return either valid database data (any object that converts automatically to a string),
	//	or an array of valid database data. In the second case, each item is taken as a secondary key.
	
	//	So we have c_record, whose data holds our ruby object
	VALUE	rb_self	=	rb_RPDB_DatabaseObject_internal_extractRetrievalData( c_record );
	
	//	Get the index method 
	//	In this case we know that we have set the index name to be the same as the index method
	char*	index_method	=	c_secondary_database->index_name;
		
	//	Call the index method on object - it returns either an array of keys or a single key
	VALUE	rb_secondary_key_or_keys	=	rb_funcall(	rb_self,
													   rb_intern( index_method ),
													   0 );
		
	//	If we have an array we need to create our record that holds multiple data items
	if ( TYPE( rb_secondary_key_or_keys ) == T_ARRAY )	{
		
		//	for each item, prepare our data; size and data are concatenated each time
		//	we have a function that will prepare individual ruby object for raw data and size
		//	we need to end up with contiguous data and its sum total size in a single record
 		//	so count how many records we have and create an array of pointers to data and size
		int	number_of_keys = 0;
		if ( rb_secondary_key_or_keys != Qnil )	{			
			number_of_keys	=	RARRAY_LEN( rb_secondary_key_or_keys );
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
			rb_this_key = RARRAY_PTR( rb_secondary_key_or_keys )[ which_key_index ];
						
			//	pack the key into the DBT at which_key_index
			rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_this_key,
																				& c_keys[ which_key_index ] );			
			
		}
		
		if ( number_of_keys > 1 )	{
		
			//	store the array of keys in the DBT that gets returned to BDB
			c_secondary_keys->wrapped_bdb_dbt->data	=	c_keys;
			c_secondary_keys->wrapped_bdb_dbt->size	=	number_of_keys;

			//	return RPDB_RECORD_CONTAINS_MULTIPLE_SECONDARY_KEYS
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
		rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	rb_secondary_key_or_keys, 
																			c_secondary_keys->wrapped_bdb_dbt );
	}
	
	//	We didn't allocate and we are indexing
	return FALSE;
}

/********************************
*  identifiesWithCurrentlyOpenEnvironment  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_identifiesWithCurrentlyOpenEnvironment(	VALUE	rb_klass_self,
																				VALUE	rb_environments_hash )	{
	
	VALUE	rb_identifiers	=	rb_RPDB_DatabaseObject_internal_identifiers( rb_klass_self );
	
	//	passed args for the foreach loop
	VALUE	rb_passed_args	=	rb_ary_new();
	
	//	push the class
	rb_ary_push(	rb_passed_args,
					rb_klass_self );
	
	int	which_identifier;
	for ( which_identifier = 0 ; which_identifier < RARRAY_LEN( rb_identifiers ) ; which_identifier++ )	{
		//	push identifiers onto passed args
		rb_ary_push(	rb_passed_args,
						RARRAY_PTR( rb_identifiers )[ which_identifier ] );
	}
	
	//	iterate RPDB.environments as environment => identify_for_rpdb_as
	rb_hash_foreach(	rb_environments_hash, 
						& rb_RPDB_DatabaseObject_internal_iterateEnvironments,
						rb_passed_args );
			
	//	check whether we succeeded - rb_passed_args should == Qnil if we're done
	//	if we didn't succeed, see if default environment is acceptable
	if (	rb_passed_args == Qnil
		||	rb_RPDB_DatabaseObject_internal_initWithDefaultEnvironment(	rb_klass_self ) )	{
		return Qtrue;
	}
		
	return Qfalse;
}

/********************************
*  identifiesWithCurrentlyOpenEnvironment  *
********************************/

//	checks if object identifies with possibility of default environment
VALUE rb_RPDB_DatabaseObject_internal_identifiersAllowDefaultEnvironment(	VALUE	rb_self )	{

	VALUE	rb_identifiers		=	rb_RPDB_DatabaseObject_internal_identifiers( rb_self );
	
	if (	rb_identifiers == Qnil
		||	RARRAY_LEN( rb_identifiers ) == 0
		||	rb_funcall(	rb_identifiers,
						rb_intern( "include?" ),
						1,
						Qtrue ) )	{
		return Qtrue;
	}
	return Qfalse;
}
	
/********************************
*  identifiesWithCurrentlyOpenEnvironment  *
********************************/

//	inits with default environment if permitted
//	returns whether succeeded
VALUE rb_RPDB_DatabaseObject_internal_initWithDefaultEnvironment(	VALUE	rb_klass_self )	{

	//	check if rb_identifiers is nil or empty or if RPDB::Default is in rb_identifiers- if not, return Qfalse
	if ( rb_RPDB_DatabaseObject_internal_identifiersAllowDefaultEnvironment( rb_klass_self ) )	{
	
		//	if it is, get the default environment and return a ruby-wrapped version
		RPDB_Environment*	c_default_environment	=	RPDB_RuntimeStorageController_defaultEnvironment( RPDB_RuntimeStorageController_sharedInstance() );
		
		VALUE	rb_default_environment	=	RUBY_RPDB_ENVIRONMENT( c_default_environment );
		
		rb_RPDB_DatabaseObject_internal_configureWithEnvironment(	rb_klass_self,
																rb_default_environment );
		
		return Qtrue;
	}
	
	return Qfalse;
}	

/************************************************
*  iterateEnvironments  *
************************************************/

//	rb_passed_args should end up with 1 element (rb_self) + 1 element (idx-idx string) + # of elements in hash
static int rb_RPDB_DatabaseObject_internal_iterateEnvironments(	VALUE	rb_environment,
																	VALUE	rb_identify_for_rpdb_as_array,
																	VALUE	rb_passed_args )	{

	VALUE	rb_klass	=	rb_ary_shift( rb_passed_args );
	
	//	rb_passed_args holds rb_klass and then current identifiers we are testing
	int	which_identifier;
	for ( which_identifier = 0 ; which_identifier < RARRAY_LEN( rb_identify_for_rpdb_as_array ) ; which_identifier++ )	{

		VALUE	rb_identifier_string	=	RARRAY_PTR( rb_identify_for_rpdb_as_array )[ which_identifier ];

		//	ask if environment.identifies_as( Const )
		//	we're looking for one of the identifiers - the first one is our environment
		if (  rb_RPDB_Environment_identifiesAs(	1,
													& rb_identifier_string,
													rb_environment ) )	{
			
			rb_RPDB_DatabaseObject_internal_configureWithEnvironment(	rb_klass,
																		rb_environment );
			//	set rb_passed_args to Qnil to show we have nothing left to do
			rb_passed_args	=	Qnil;
						
			//	and break
			return ST_STOP;
		}
	}
	
	return ST_CONTINUE;
}

/********************************
*  activateClass  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_activateClass(	VALUE	rb_klass_self )	{
	
	//	activateModuleClass is called when the class has included or extended RPDB,
	
	//	if we have RPDB included/extended
	//	then we register the class with RPDB
	//	if we load a new environment and an RPDB class is included/extended
	//	then we call the class configuration method, which configures the class and writes it to db 
	//	
	//	that way we can load a new environment for every instance
	//	and only load a transaction for every page load
	//	
	//	when an environment opens it checks to see if any classes are waiting to initialize
	//	if there are, it checks to see if they identify
	//	* if they identify and the environment provides the identity, then the environment initializes the classes
	//	* if they do not identify and are not required to identify, then the environment initializes the classes anyway (as the default environment)
	//	* if they do not identify and are required to identify, the environment ignores the classes	
	
	//	get environments; if at least one environment is open, 
	//	check to see if an open environment answers to one of identifiers
	VALUE	rb_environments_hash	=	rb_RPDB_internal_environmentsToIdentifiersHash();
		
	if ( RHASH_SIZE( rb_environments_hash ) > 0 )	{
		
		VALUE	rb_identifiers	=	rb_RPDB_DatabaseObject_internal_identifiers( rb_klass_self );
		
		if (	rb_identifiers != Qnil )	{

			Check_Type(	rb_identifiers,
						T_ARRAY );
			
			if ( RARRAY_LEN( rb_identifiers ) > 0 )	{
			
				//	check if open environments provide identifiers
				if ( rb_RPDB_DatabaseObject_internal_identifiesWithCurrentlyOpenEnvironment(	rb_klass_self,
																								rb_environments_hash ) == Qfalse )	{
					
					//	otherwise, check if object identifies with RPDB::Default
					if ( rb_RPDB_DatabaseObject_internal_initWithDefaultEnvironment( rb_klass_self ) == Qfalse )	{
						
						rb_RPDB_DatabaseObject_internal_addToAppropriateWaitlist( rb_klass_self );
						return Qfalse;
					}
				}
			}
		}
		//	no identifiers; see if we have a default environment
		else {
			
			//	check if object identifies with RPDB::Default
			if ( rb_RPDB_DatabaseObject_internal_initWithDefaultEnvironment( rb_klass_self ) == Qfalse )	{
					
				rb_RPDB_DatabaseObject_internal_addToAppropriateWaitlist( rb_klass_self );
				return Qfalse;
			}
			
		}

	}
	else {
		
		//	if we don't have any environments yet then we can add to the appropriate waitlist
		rb_RPDB_DatabaseObject_internal_addToAppropriateWaitlist(	rb_klass_self );
	}
	
	return Qtrue;
}

/********************************
*  addToAppropriateWaitlist  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_addToAppropriateWaitlist( VALUE	rb_klass_self )	{
		
	if ( rb_RPDB_DatabaseObject_internal_identifiersAllowDefaultEnvironment( rb_klass_self ) )	{
		//	add to default waitlist if appropriate
		rb_RPDB_DatabaseObject_internal_markForDefaultEnvironment( rb_klass_self );
	}
	//	if we are adding to default waitlist we don't need to worry about identifiers, since the next db will match
	else {
		rb_RPDB_DatabaseObject_internal_markForIdentification( rb_klass_self );
	}
	return rb_klass_self;
}

/********************************
*  configureWithEnvironment  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_configureWithEnvironment(	VALUE	rb_klass_self,
																	VALUE	rb_environment )	{
	
	//	if it does, set the environment for the class
	rb_RPDB_DatabaseObject_setEnvironment(	rb_klass_self,
											rb_environment );
	
	//	and call configureRPDB
	rb_funcall(	rb_klass_self,
				rb_intern( RPDB_FUNCTION_CONFIGURE ),
				0 );

	//	mark for init (happens after all waiting classes have configured)
	rb_RPDB_DatabaseObject_internal_markForInitialization( rb_klass_self );

	//	mark as initialized for this environment; when environment closes, classes will go back on wait lists
	rb_RPDB_Environment_internal_markClassConfigured(	rb_environment,
														rb_klass_self );
	
	return rb_klass_self;
}

/********************************
*  ensureInitializedAndOpen  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_ensureInitialized( VALUE	rb_self )	{

	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	//	Make sure we have an environment or fail
	rb_RPDB_DatabaseObject_requireEnvironment( rb_klass );
	
	//	Make sure class is initialized or initialize it
	if ( ! rb_RPDB_DatabaseObject_hasInitialized( rb_klass ) )	{
		
		rb_RPDB_DatabaseObject_internal_callInitRPDB( rb_klass );
	}
	
	return rb_self;
}

/********************************
*  setHasConfigured  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_setHasConfigured(	VALUE	rb_klass_self,
															VALUE	rb_true_or_false )	{

	rb_iv_set(	rb_klass_self,
				RPDB_RUBY_CLASS_VARIABLE_CONFIGURED,
				rb_true_or_false );
	//	We have Qtrue, Qfalse or Qnil and want to return Qtrue or Qfalse
	return ( rb_klass_self == Qtrue ? Qtrue : Qfalse );
}

/********************************
*  setHasInitialized  *
********************************/

VALUE rb_RPDB_DatabaseObject_internal_setHasInitialized(	VALUE	rb_klass_self,
															VALUE	rb_true_or_false  )	{
	rb_iv_set(	rb_klass_self,
				RPDB_RUBY_CLASS_VARIABLE_INITIALIZED,
				rb_true_or_false );	
	//	We have Qtrue, Qfalse or Qnil and want to return Qtrue or Qfalse
	return ( rb_klass_self == Qtrue ? Qtrue : Qfalse );
}

/******************************
*  markForDefaultEnvironment  *
******************************/

//	config class with next environment that loads
VALUE rb_RPDB_DatabaseObject_internal_markForDefaultEnvironment( VALUE rb_klass_self )	{
	
	VALUE	rb_default_environment_wait_list	=	rb_RPDB_internal_classesWaitingForDefaultEnvironment();
		
	rb_ary_push(	rb_default_environment_wait_list,
					rb_klass_self );

	return rb_klass_self;
	
}

/******************************
*  markForIdentification  *
******************************/

//	config class to wait for environment that identifies to load
VALUE rb_RPDB_DatabaseObject_internal_markForIdentification( VALUE rb_klass_self )	{
	
	//	get initWaitList array from module
	VALUE	rb_identification_wait_list	=	rb_RPDB_internal_classesWaitingForIdentification();

	rb_ary_push(	rb_identification_wait_list,
					rb_klass_self );
	
	return rb_klass_self;	
}

/******************************
*  markForInitialization  *
******************************/

VALUE rb_RPDB_DatabaseObject_internal_markForInitialization( VALUE rb_klass_self )	{
	
	//	get initWaitList array from module
	VALUE	rb_initialization_wait_list	=	rb_RPDB_internal_classesWaitingForInitialization();
	
	rb_ary_push(	rb_initialization_wait_list,
					rb_klass_self );
	
	return rb_klass_self;	
}

/******************************
*  identifiers  *
******************************/

VALUE rb_RPDB_DatabaseObject_internal_identifiers( VALUE rb_self )	{

	VALUE	rb_identifiers	=	rb_funcall(	rb_self,
											rb_intern( RPDB_FUNCTION_IDENTIFY_AS ),
											0 );
	return rb_identifiers;
}

/******************************
*  callInitRPDBChain  *
******************************/

//	We have issues with module inheritance; we avoid them by calling up the chain of ancestors
//	This should also make it unnecessary to call super in initRPDB
VALUE rb_RPDB_DatabaseObject_internal_callInitRPDB( VALUE rb_self )	{
	
	//	Mark that we have initialized
	rb_RPDB_DatabaseObject_internal_setHasInitialized(	rb_self,
														Qtrue );
	
	rb_funcall(	rb_self,
				rb_intern( RPDB_FUNCTION_INIT ),
				0 );

	return rb_self;
}


/******************************
*  uniqueJoinDeclarationHash  *
******************************/

VALUE rb_RPDB_DatabaseObject_internal_uniqueJoinDeclarationHash( VALUE rb_self )	{
	
	VALUE	rb_unique_join_declaration_hash	=	rb_iv_get(	rb_self,
														  RPDB_RUBY_CLASS_VARIABLE_UNIQUE_JOIN_DECLARATION_HASH );
	
	if ( rb_unique_join_declaration_hash == Qnil )	{
		rb_unique_join_declaration_hash = rb_hash_new();
		rb_iv_set(	rb_self,
				  RPDB_RUBY_CLASS_VARIABLE_UNIQUE_JOIN_DECLARATION_HASH,
				  rb_unique_join_declaration_hash );
	}
	
	return rb_unique_join_declaration_hash;
}

/*********************
*  addChainedMember  *
*********************/

void rb_RPDB_DatabaseObject_internal_addChainedMember(	VALUE	rb_hash_self,
														VALUE	rb_array_of_items )	{
	//	iterate array items and add in chain to hash
	int	c_which_index;
	for( c_which_index = 0 ; c_which_index < RARRAY_LEN( rb_array_of_items ) ; c_which_index++ )	{
		
		VALUE	rb_this_index	=	RARRAY_PTR( rb_array_of_items )[ c_which_index ];
		
		//	we can set destructively - doesn't matter if we overwrite existing keys
		rb_hash_aset(	rb_hash_self,
					 rb_this_index,
					 rb_hash_new() );
	}
}
