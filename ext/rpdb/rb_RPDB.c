/*
 *		RPDB
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

#include "rb_RPDB_Environment.h"

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_DatabaseCursorController.h"
#include "rb_RPDB_DatabaseCursor.h"
#include "rb_RPDB_DatabaseSequenceController.h"
#include "rb_RPDB_DatabaseSequence.h"
#include "rb_RPDB_DatabaseJoinController.h"
#include "rb_RPDB_DatabaseJoinCursor.h"

#include "rb_RPDB_Lock.h"
#include "rb_RPDB_LockController.h"

#include "rb_RPDB_Log.h"
#include "rb_RPDB_LogController.h"
#include "rb_RPDB_LogCursor.h"
#include "rb_RPDB_LogCursorController.h"
#include "rb_RPDB_LogSequenceNumber.h"

#include "rb_RPDB_MemoryPoolController.h"
#include "rb_RPDB_MemoryPoolFile.h"
#include "rb_RPDB_MemoryPoolFileController.h"
#include "rb_RPDB_MemoryPoolFilePage.h"
#include "rb_RPDB_MemoryPoolFilePageController.h"

#include "rb_RPDB_Mutex.h"
#include "rb_RPDB_MutexController.h"

#include "rb_RPDB_Record.h"
#include "rb_RPDB_Data.h"
#include "rb_RPDB_Key.h"
#include "rb_RPDB_SecondaryKeys.h"

#include "rb_RPDB_ReplicationController.h"
#include "rb_RPDB_RemoteSite.h"

#include "rb_RPDB_Transaction.h"
#include "rb_RPDB_TransactionController.h"

#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_DatabaseAssociationSettingsController.h"
#include "rb_RPDB_DatabaseCacheSettingsController.h"
#include "rb_RPDB_DatabaseCachePrioritySettingsController.h"
#include "rb_RPDB_DatabaseCompactSettingsController.h"
#include "rb_RPDB_DatabaseCursorSettingsController.h"
#include "rb_RPDB_DatabaseCursorReadWriteSettingsController.h"
#include "rb_RPDB_DatabaseCursorCacheSettingsController.h"
#include "rb_RPDB_DatabaseCursorCachePrioritySettingsController.h"
#include "rb_RPDB_DatabaseEncryptionSettingsController.h"
#include "rb_RPDB_DatabaseErrorSettingsController.h"
#include "rb_RPDB_DatabaseFixedRecordSettingsController.h"
#include "rb_RPDB_DatabaseReadWriteSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseSequenceSettingsController.h"
#include "rb_RPDB_DatabaseTypeSettingsController.h"
#include "rb_RPDB_DatabaseTypeBtreeSettingsController.h"
#include "rb_RPDB_DatabaseTypeHashSettingsController.h"
#include "rb_RPDB_DatabaseTypeQueueSettingsController.h"
#include "rb_RPDB_DatabaseTypeRecnoSettingsController.h"
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseVariableRecordSettingsController.h"
#include "rb_RPDB_DatabaseVerbositySettingsController.h"
#include "rb_RPDB_DatabaseVerificationSettingsController.h"

#include "rb_RPDB_DebugSettingsController.h"
#include "rb_RPDB_DebugVerbositySettingsController.h"

#include "rb_RPDB_DirectorySettingsController.h"

#include "rb_RPDB_EnvironmentCacheSettingsController.h"

#include "rb_RPDB_FileSettingsController.h"
#include "rb_RPDB_FileVerbositySettingsController.h"

#include "rb_RPDB_DatabaseJoinSettingsController.h"

#include "rb_RPDB_LockSettingsController.h"
#include "rb_RPDB_LockDeadlockDetectorSettingsController.h"
#include "rb_RPDB_LockDeadlockDetectorVerbositySettingsController.h"

#include "rb_RPDB_LogSettingsController.h"

#include "rb_RPDB_MemoryPoolSettingsController.h"
#include "rb_RPDB_MemoryPoolReadWriteSettingsController.h"
#include "rb_RPDB_MemoryPoolFileSettingsController.h"
#include "rb_RPDB_MemoryPoolFilePageSettingsController.h"
#include "rb_RPDB_MemoryPoolFileCachePrioritySettingsController.h"

#include "rb_RPDB_MessageSettingsController.h"

#include "rb_RPDB_MutexSettingsController.h"

#include "rb_RPDB_ReplicationSettingsController.h"
#include "rb_RPDB_ReplicationElectionSettingsController.h"
#include "rb_RPDB_ReplicationTimeoutSettingsController.h"
#include "rb_RPDB_ReplicationVerbositySettingsController.h"

#include "rb_RPDB_ThreadSettingsController.h"

#include "rb_RPDB_TransactionSettingsController.h"

#include "rb_RPDB_DatabaseObject.h"
#include "rb_RPDB_DatabaseObject_internal.h"
#include "rb_RPDB_DatabaseObjectCursor.h"
#include "rb_RPDB_DatabaseObjectDatabase.h"

#include <rpdb/RPDB_main.h>
#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database_internal.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DatabaseTypeSettingsController.h>
#include <rpdb/RPDB_RuntimeStorageController.h>
#include <rpdb/RPDB_RuntimeStorage.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

//	FIX - fixed record, variable record should be moved under record controller

VALUE	rb_mRPDB;

VALUE	rb_RPDB_Environment;
	VALUE	rb_RPDB_DatabaseController;
		VALUE	rb_RPDB_Database;
		VALUE	rb_RPDB_DatabaseObjectDatabase;
			VALUE	rb_RPDB_DatabaseCursorController;
				VALUE	rb_RPDB_DatabaseCursor;
				VALUE	rb_RPDB_DatabaseObjectCursor;
VALUE	rb_RPDB_DatabaseSequenceController;
VALUE	rb_RPDB_DatabaseSequence;

	VALUE	rb_RPDB_Error;
	VALUE	rb_RPDB_ErrorController;
	VALUE	rb_RPDB_DatabaseJoinController;
	VALUE	rb_RPDB_DatabaseJoinCursor;
	VALUE	rb_RPDB_Lock;
VALUE	rb_RPDB_LockController;
VALUE	rb_RPDB_Log;
VALUE	rb_RPDB_LogController;
VALUE	rb_RPDB_LogCursor;
VALUE	rb_RPDB_LogCursorController;
VALUE	rb_RPDB_LogSequenceNumber;
VALUE	rb_RPDB_MemoryPoolController;
VALUE	rb_RPDB_MemoryPoolFile;
VALUE	rb_RPDB_MemoryPoolFileController;
VALUE	rb_RPDB_MemoryPoolFilePage;
VALUE	rb_RPDB_MemoryPoolFilePageController;
VALUE	rb_RPDB_Mutex;
VALUE	rb_RPDB_MutexController;

		VALUE	rb_RPDB_Record;
		VALUE	rb_RPDB_Data;
		VALUE	rb_RPDB_Key;
		VALUE	rb_RPDB_SecondaryKeys;

VALUE	rb_RPDB_ReplicationController;
VALUE	rb_RPDB_RemoteSite;

VALUE	rb_RPDB_Transaction;
VALUE	rb_RPDB_TransactionController;


VALUE	rb_RPDB_SettingsController;
	VALUE	rb_RPDB_DatabaseSettingsController;
		VALUE	rb_RPDB_DatabaseAssociationSettingsController;
		VALUE	rb_RPDB_DatabaseCacheSettingsController;
		VALUE	rb_RPDB_DatabaseCachePrioritySettingsController;
		VALUE	rb_RPDB_DatabaseCompactSettingsController;
		VALUE	rb_RPDB_DatabaseCursorSettingsController;
		VALUE	rb_RPDB_DatabaseCursorReadWriteSettingsController;
		VALUE	rb_RPDB_DatabaseCursorCacheSettingsController;
		VALUE	rb_RPDB_DatabaseCursorCachePrioritySettingsController;
		VALUE	rb_RPDB_DatabaseEncryptionSettingsController;
		VALUE	rb_RPDB_DatabaseErrorSettingsController;
		VALUE	rb_RPDB_DatabaseFixedRecordSettingsController;
		VALUE	rb_RPDB_DatabaseReadWriteSettingsController;
		VALUE	rb_RPDB_DatabaseRecordSettingsController;
		VALUE	rb_RPDB_DatabaseSequenceSettingsController;
		VALUE	rb_RPDB_DatabaseTypeSettingsController;
		VALUE	rb_RPDB_DatabaseTypeBtreeSettingsController;
		VALUE	rb_RPDB_DatabaseTypeHashSettingsController;
		VALUE	rb_RPDB_DatabaseTypeQueueSettingsController;
		VALUE	rb_RPDB_DatabaseTypeRecnoSettingsController;
		VALUE	rb_RPDB_DatabaseRecordSettingsController;
		VALUE	rb_RPDB_DatabaseVariableRecordSettingsController;
		VALUE	rb_RPDB_DatabaseVerbositySettingsController;
		VALUE	rb_RPDB_DatabaseVerificationSettingsController;
	VALUE	rb_RPDB_DebugSettingsController;
VALUE	rb_RPDB_DebugVerbositySettingsController;
	VALUE	rb_RPDB_DirectorySettingsController;
	VALUE	rb_RPDB_EnvironmentCacheSettingsController;
	VALUE	rb_RPDB_ErrorSettingsController;
	VALUE	rb_RPDB_FileSettingsController;
	VALUE	rb_RPDB_FileVerbositySettingsController;
VALUE	rb_RPDB_DatabaseJoinSettingsController;
VALUE	rb_RPDB_LockSettingsController;
VALUE	rb_RPDB_LockDeadlockDetectorSettingsController;
VALUE	rb_RPDB_LockDeadlockDetectorVerbositySettingsController;
VALUE	rb_RPDB_LogSettingsController;
VALUE	rb_RPDB_MemoryPoolSettingsController;
VALUE	rb_RPDB_MemoryPoolReadWriteSettingsController;
VALUE	rb_RPDB_MemoryPoolFileSettingsController;
VALUE	rb_RPDB_MemoryPoolFilePageSettingsController;
VALUE	rb_RPDB_MemoryPoolFileCachePrioritySettingsController;
VALUE	rb_RPDB_MessageSettingsController;
VALUE	rb_RPDB_MutexSettingsController;
VALUE	rb_RPDB_ReplicationSettingsController;
VALUE	rb_RPDB_ReplicationElectionSettingsController;
VALUE	rb_RPDB_ReplicationTimeoutSettingsController;
VALUE	rb_RPDB_ReplicationVerbositySettingsController;
VALUE	rb_RPDB_ThreadSettingsController;
VALUE	rb_RPDB_TransactionSettingsController;


/*********
*  init  *
*********/

//	Called from ruby when RPDB module is initialized
void Init_rpdb()	{

	//	Init singleton properties (including its status as a module)

	rb_mRPDB 	=	rb_define_module( "RPDB" );

	//	override of extend so we can auto-extend both ways for RPDB
	rb_define_singleton_method(	rb_cObject,	"extend",															rb_RPDB_extend,												1 );

	rb_define_singleton_method(	rb_mRPDB,		"included",														rb_RPDB_included,											1 );
	rb_define_singleton_method(	rb_mRPDB,		"extended",														rb_RPDB_extended,											1 );
	rb_define_singleton_method(	rb_mRPDB,		"included_for?",											rb_RPDB_includedFor,									-1 );
	rb_define_singleton_method(	rb_mRPDB,		"extends?",														rb_RPDB_extends,											-1 );

	rb_define_singleton_method(	rb_mRPDB, 	"current_working_environment",				rb_RPDB_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRPDB, 	"current_environment",								rb_RPDB_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRPDB, 	"current_working_environment=",				rb_RPDB_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPDB, 	"set_current_working_environment",		rb_RPDB_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPDB, 	"current_environment=",								rb_RPDB_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPDB, 	"set_current_environment",						rb_RPDB_setCurrentWorkingEnvironment,	1 );
	
	rb_define_singleton_method(	rb_mRPDB, 	"version",														rb_RPDB_version,											0 );
	rb_define_singleton_method(	rb_mRPDB, 	"version_major",											rb_RPDB_versionMajor,									0 );
	rb_define_singleton_method(	rb_mRPDB, 	"version_minor",											rb_RPDB_versionMinor,									0 );
	rb_define_singleton_method(	rb_mRPDB, 	"version_patch",											rb_RPDB_versionPatch,									0 );
	rb_define_singleton_method(	rb_mRPDB, 	"version_parts",											rb_RPDB_versionData,									0 );
		
	Init_RPDB_Module();

		Init_RPDB_Environment();
		
		Init_RPDB_DatabaseController();
		Init_RPDB_Database();
		Init_RPDB_DatabaseObjectDatabase();
		Init_RPDB_DatabaseCursorController();
		Init_RPDB_DatabaseCursor();
		Init_RPDB_DatabaseJoinController();
		Init_RPDB_DatabaseJoinCursor();
		Init_RPDB_DatabaseObjectCursor();
		Init_RPDB_DatabaseSequenceController();
		Init_RPDB_DatabaseSequence();

		//	Record/Key/Data
		Init_RPDB_Record();
		Init_RPDB_Key();
		Init_RPDB_Data();

		//	Locks
//		Init_RPDB_LockController();
//		Init_RPDB_Lock();

		//	Transactions
		Init_RPDB_TransactionController();
		Init_RPDB_Transaction();

		//	Settings
		Init_RPDB_SettingsController();

		//	Database Settings
		Init_RPDB_DatabaseSettingsController();
		Init_RPDB_DatabaseAssociationSettingsController();
		Init_RPDB_DatabaseCacheSettingsController();
		Init_RPDB_DatabaseCachePrioritySettingsController();
		Init_RPDB_DatabaseCompactSettingsController();
		Init_RPDB_DatabaseCursorSettingsController();
		Init_RPDB_DatabaseCursorReadWriteSettingsController();
		Init_RPDB_DatabaseCacheSettingsController();
		Init_RPDB_DatabaseCursorCacheSettingsController();
		Init_RPDB_DatabaseCursorCachePrioritySettingsController();
		Init_RPDB_DatabaseEncryptionSettingsController();
		Init_RPDB_DatabaseErrorSettingsController();
		Init_RPDB_DatabaseReadWriteSettingsController();
		Init_RPDB_DatabaseRecordSettingsController();
		Init_RPDB_DatabaseFixedRecordSettingsController();
		Init_RPDB_DatabaseSequenceSettingsController();
		Init_RPDB_DatabaseTypeSettingsController();
		Init_RPDB_DatabaseTypeBtreeSettingsController();
		Init_RPDB_DatabaseTypeHashSettingsController();
		Init_RPDB_DatabaseTypeQueueSettingsController();
		Init_RPDB_DatabaseTypeRecnoSettingsController();
		Init_RPDB_DatabaseVariableRecordSettingsController();
		Init_RPDB_DatabaseVerificationSettingsController();

		Init_RPDB_DebugSettingsController();
		Init_RPDB_DebugVerbositySettingsController();
		
		Init_RPDB_LogSettingsController();
		Init_RPDB_MemoryPoolSettingsController();

		rb_RPDB_internal_initRuntimeStorages( rb_mRPDB );

}

/***********
*  extend  *
***********/

//	replacement for Object.extend that will also include if module == RPDB
VALUE rb_RPDB_extend(	VALUE	rb_self,
											VALUE	rb_module )	{
	
	//	extend can be called on a class or instance - in either case we want to call include on the class	
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	//	call extend as expected
	rb_call_super( 1, & rb_module );
	
	if ( rb_module == rb_mRPDB )	{

		//	now call include if needed
		VALUE	rb_included_classes_hash	=	rb_RPDB_internal_includedForClassesHash();
		if ( rb_hash_aref(	rb_included_classes_hash,
												rb_klass ) == Qnil )	{
			
			rb_include_module(	rb_self,
													rb_module );
		}	
	}
	
	return rb_self;
}

/*************
*  included  *
*************/

VALUE rb_RPDB_included(	VALUE	rb_module_self,
												VALUE	rb_included_in_module_or_class )	{

	VALUE	rb_included_classes_hash	=	rb_RPDB_internal_includedForClassesHash();
	
	//	if we haven't included yet, take note and initialize
	if ( rb_hash_aref(	rb_included_classes_hash,
											rb_included_in_module_or_class ) == Qnil )	{

		//	mark as included so we don't get stuck in a loop from extend	
		rb_hash_aset(	rb_included_classes_hash,
									rb_included_in_module_or_class,
									Qtrue );
	
		//	if not extended, call extend on class - we've marked class as included, so extend won't call it
		VALUE	rb_extended_classes_hash	=	rb_RPDB_internal_extendedClassesHash();
		if ( rb_hash_aref(	rb_extended_classes_hash,
												rb_included_in_module_or_class ) == Qnil )	{

			rb_extend_object(	rb_included_in_module_or_class,
												rb_module_self );
		}
				
		rb_RPDB_internal_configureIfNecessary(	rb_module_self,
																						rb_included_in_module_or_class );
	}
	
	return rb_module_self;
}

/*************
*  extended  *
*************/

VALUE rb_RPDB_extended(	VALUE	rb_module_self,
												VALUE	rb_extended_module_or_class )	{
	
	//	mark as extended so we don't get stuck in a loop from include
	VALUE	rb_extended_classes_hash	=	rb_RPDB_internal_extendedClassesHash();
	
	//	if we haven't extended yet, take note and initialize
	if ( rb_hash_aref(	rb_extended_classes_hash,
											rb_extended_module_or_class ) == Qnil )	{
		
		//	store extended module or class constant
		rb_hash_aset(	rb_extended_classes_hash,
					 				rb_extended_module_or_class,
					 				Qtrue );
		
		rb_RPDB_internal_configureIfNecessary(	rb_module_self,
																						rb_extended_module_or_class );
		
	}
	return rb_module_self;
}

/******************
*  included_for?  *
******************/

VALUE rb_RPDB_includedFor(	int			argc,
														VALUE*	args,
														VALUE		rb_module_self __attribute__ ((unused )) )		{
	
	//	get included classes array from module
	VALUE	rb_included_classes_hash	=	rb_RPDB_internal_includedForClassesHash();

	int	which_arg;
	for ( which_arg = 0 ; which_arg < argc ; which_arg++ )	{
	
		VALUE	rb_klass_or_module	=	args[ which_arg ];

		//	check if hash includes class
		if ( rb_hash_aref(	rb_included_classes_hash,
												rb_klass_or_module ) == Qnil )	{
			return Qfalse;
		}

	}
	
	return Qtrue;
}

/*************
*  extends?  *
*************/

VALUE rb_RPDB_extends(	int			argc,
												VALUE*	args,
												VALUE		rb_module_self __attribute__ ((unused )) )	{
	
	//	get included classes array from module
	VALUE	rb_extended_classes_hash	=	rb_RPDB_internal_extendedClassesHash();
	
	int	which_class;
	for ( which_class = 0 ; which_class < argc ; which_class++ )	{
		
		VALUE	rb_klass_or_module	=	args[ which_class ];
		
		//	check if hash includes class
		if ( rb_hash_aref(	rb_extended_classes_hash,
							rb_klass_or_module ) == Qnil )	{
			return Qfalse;
		}
		
	}
	
	return Qtrue;
}

/*******************************************************************************************************************************************************************************************
 																																				Environment Storage
*******************************************************************************************************************************************************************************************/

/********************************
*  current_working_environment  *
********************************/

VALUE rb_RPDB_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	//	change default environment to current working environment
	//	when a new environment is opened, the current working environment is set to it
	//	it can also be changed by specifying new cwe	
	//	when the environment closes if it is the cwe then it is removed
	//	only open environments can be the cwe
	//	additionally, cwe can stack, but any time one is closed it is removed from the stack, even if not current
	
	VALUE	rb_current_working_environment_stack	=	rb_RPDB_internal_currentWorkingEnvironmentStack( rb_module_self );
	VALUE	rb_current_working_environment				=	rb_ary_entry(	rb_current_working_environment_stack, 0 );
	
	return rb_current_working_environment;	
}

/*********************************
*  current_working_environment=  *
*********************************/

VALUE rb_RPDB_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																						VALUE	rb_environment )	{

	RPDB_Environment*	c_environment	=	NULL;
	C_RPDB_ENVIRONMENT( rb_environment, c_environment );

	RPDB_RuntimeStorageController_setCurrentWorkingEnvironment( RPDB_RuntimeStorageController_sharedInstance(),
																															c_environment );
	
	VALUE	rb_current_working_environment_stack	=	rb_RPDB_internal_currentWorkingEnvironmentStack( rb_module_self );
	
	//	stick new environment at top of stack
	rb_ary_unshift(	rb_current_working_environment_stack,
									rb_environment );
	
	return rb_module_self;
}

/*******************************************************************************************************************************************************************************************
 																																				Version Info
*******************************************************************************************************************************************************************************************/

/************
*  version  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPDB_version( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return rb_str_new2( RPDB_version() );
}

/******************
*  version_major  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPDB_versionMajor( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( RPDB_versionMajor() );
}

/******************
*  version_minor  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPDB_versionMinor( VALUE rb_module_self __attribute__ ((unused )) )	{
		
	return INT2FIX( RPDB_versionMinor() );
}

/******************
*  version_patch  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPDB_versionPatch( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( RPDB_versionPatch() );
}

/*****************
*  version_data  *
*****************/

//	Returns an array:
//	* major
//	* minor
//	* patch
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPDB_versionData(	VALUE	rb_module_self __attribute__ ((unused )) )	{
	
	int					major;
	int					minor;
	int					patch;
	
	RPDB_versionData(	& major,
										& minor,
										& patch );
	
	//	Create our hash to return
	VALUE				rb_return_hash	=	rb_hash_new();
	
	//	major				
	rb_hash_aset(	rb_return_hash,
								ID2SYM( rb_intern( "major" ) ),
								INT2FIX( major ) );
	
	//	minor
	rb_hash_aset(	rb_return_hash,
								ID2SYM( rb_intern( "minor" ) ),
								INT2FIX( minor ) );
	
	//	patch	
	rb_hash_aset(	rb_return_hash,
								ID2SYM( rb_intern( "patch" ) ),
								INT2FIX( patch ) );
	
	return rb_return_hash;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************************
*  initRuntimeStorages  *
************************/

void rb_RPDB_internal_initRuntimeStorages( VALUE rb_module_self )	{

	//	Now init ruby runtime storage
	RPDB_RuntimeStorageController*		c_runtime_storage_controller	=	RPDB_RuntimeStorageController_sharedInstance();
	RPDB_DatabaseController*					c_database_controller					=	RPDB_Environment_databaseController(	c_runtime_storage_controller->runtime_environment );
	RPDB_Database*										c_runtime_storage_database		=	RPDB_Database_new(	c_database_controller,
																																												"ruby_databases_by_c_reference" );
	RPDB_DatabaseSettingsController*			c_database_settings_controller			=	RPDB_Database_settingsController( c_runtime_storage_database );
	RPDB_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPDB_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	RPDB_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
	
	VALUE	rb_runtime_storage_database	=	RUBY_RPDB_DATABASE( c_runtime_storage_database );

	rb_iv_set(	rb_module_self,
							RPDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE,
							rb_runtime_storage_database );
}

/************************
*  rubyRuntimeDatabase  *
************************/

VALUE rb_RPDB_internal_rubyRuntimeDatabase(	VALUE rb_module_self )	{

	VALUE	rb_runtime_storage_database	=	rb_iv_get(	rb_module_self,
																									RPDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE );
	return rb_runtime_storage_database;
}

/***************************
*  configure_if_necessary  *
***************************/

VALUE rb_RPDB_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass )	{
		
	//	check if we've initialized
	if ( rb_RPDB_DatabaseObject_hasConfigured( rb_klass ) == Qfalse )	{
		
		//	activate class
		//	if identifiers are empty, uses default environment
		rb_RPDB_DatabaseObject_internal_activateClass(	rb_klass );
		
		//	note that we've configured
		rb_RPDB_DatabaseObject_internal_setHasConfigured(	rb_klass,
																											Qtrue );
	}
	return rb_module_self;
}


/*********************************
*  environmentToIdentifiersHash  *
*********************************/

VALUE rb_RPDB_internal_environmentsToIdentifiersHash()	{
	
	//	get the environment identifiers hash from the RPDB module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPDB,
																													RPDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS );

	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
							  RPDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS,
							  rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/************************
*  extendedClassesHash  *
************************/

VALUE rb_RPDB_internal_extendedClassesHash()	{

	//	get the environment identifiers hash from the RPDB module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPDB,
																													RPDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{

		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/***************************
*  includedForClassesHash  *
***************************/

VALUE rb_RPDB_internal_includedForClassesHash()	{
	
	//	get the environment identifiers hash from the RPDB module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPDB,
																													RPDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/*******************************
*  inititializeWaitingClasses  *
*******************************/

//	initialization takes place immediately after configuration has taken place for all pending classes for given environment
VALUE rb_RPDB_internal_initializeWaitingClasses()	{
	
	//	get initWaitList array from module
	VALUE	rb_init_wait_list	=	rb_RPDB_internal_classesWaitingForInitialization();
	
	//	iterate classes in array, calling initRPDB on each and removing from wait list
	VALUE	rb_this_class;
	while ( ( rb_this_class = rb_ary_shift( rb_init_wait_list ) ) != Qnil )	{
		
		rb_RPDB_DatabaseObject_internal_callInitRPDB( rb_this_class );
	}
	
	return Qtrue;
}

/****************************************
*  classesWaitingForDefaultEnvironment  *
****************************************/

//	array tracks classes that will configure when the next environment opens
VALUE rb_RPDB_internal_classesWaitingForDefaultEnvironment()	{
	
	VALUE	rb_current_working_environment_wait_list_array	=	rb_iv_get(	rb_mRPDB,
																															RPDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY );
	
	if ( rb_current_working_environment_wait_list_array == Qnil )	{
		rb_current_working_environment_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY,
								rb_current_working_environment_wait_list_array );
	}
	
	return rb_current_working_environment_wait_list_array;
}

/************************************
*  classesWaitingForIdentification  *
************************************/

//	array tracks classes that will wait to identify with an appropriate environment
VALUE rb_RPDB_internal_classesWaitingForIdentification()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRPDB,
																											RPDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/************************************
*  classesWaitingForInitialization  *
************************************/

//	initialization takes place immediately after all classes have ben configured for the given environment
VALUE rb_RPDB_internal_classesWaitingForInitialization()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRPDB,
																											RPDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPDB,
								RPDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/*********************************************
*  deleteFromCurrentWorkingEnvironmentStack  *
*********************************************/

VALUE rb_RPDB_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																	VALUE	rb_environment )	{

	VALUE	rb_current_working_environment_stack	=	rb_RPDB_internal_currentWorkingEnvironmentStack( rb_module_self );
	
	VALUE	rb_environment_index	=	rb_funcall(		rb_current_working_environment_stack,
																							rb_intern( "index" ),
																							1,
																							& rb_environment,
																							rb_current_working_environment_stack );

	if ( rb_environment_index != Qnil )	{
		rb_ary_delete( rb_current_working_environment_stack, rb_environment_index );
	}
	
	return rb_module_self;
}

/***********************************
*  currentWorkingEnvironmentStack  *
***********************************/

VALUE rb_RPDB_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self )	{
	
	VALUE	rb_stack_array	=	rb_iv_get(	rb_module_self,
																			RPDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK );

	if ( rb_stack_array == Qnil )	{
		rb_stack_array	=	rb_ary_new();
		rb_iv_set(	rb_module_self,
								RPDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK,
								rb_stack_array );
	}
	return rb_stack_array;
}

