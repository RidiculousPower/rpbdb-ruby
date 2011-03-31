/*
 *		RPbdb
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "BaseStandardIncludes.h"

#include "RPbdb.h"
#include "RPbdb_internal.h"

#include "Environment.h"

#include "DatabaseController.h"
#include "Database.h"
#include "DatabaseCursorController.h"
#include "DatabaseCursor.h"
#include "DatabaseSequenceController.h"
#include "DatabaseSequence.h"
#include "DatabaseJoinController.h"
#include "DatabaseJoinCursor.h"

#include "Lock.h"
#include "LockController.h"

#include "Log.h"
#include "LogController.h"
#include "LogCursor.h"
#include "LogCursorController.h"
#include "LogSequenceNumber.h"

#include "MemoryPoolController.h"
#include "MemoryPoolFile.h"
#include "MemoryPoolFileController.h"
#include "MemoryPoolFilePage.h"
#include "MemoryPoolFilePageController.h"

#include "Mutex.h"
#include "MutexController.h"

#include "Record.h"
#include "Data.h"
#include "Key.h"
#include "SecondaryKeys.h"

#include "ReplicationController.h"
#include "RemoteSite.h"

#include "Transaction.h"
#include "TransactionController.h"

#include "SettingsController.h"

#include "DatabaseSettingsController.h"
#include "DatabaseAssociationSettingsController.h"
#include "DatabaseCacheSettingsController.h"
#include "DatabaseCachePrioritySettingsController.h"
#include "DatabaseCompactSettingsController.h"
#include "DatabaseCursorSettingsController.h"
#include "DatabaseCursorReadWriteSettingsController.h"
#include "DatabaseCursorCacheSettingsController.h"
#include "DatabaseCursorCachePrioritySettingsController.h"
#include "DatabaseEncryptionSettingsController.h"
#include "DatabaseErrorSettingsController.h"
#include "DatabaseJoinSettingsController.h"
#include "DatabaseRecordFixedLengthSettingsController.h"
#include "DatabaseRecordReadWriteSettingsController.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseSequenceSettingsController.h"
#include "DatabaseTypeSettingsController.h"
#include "DatabaseTypeBtreeSettingsController.h"
#include "DatabaseTypeHashSettingsController.h"
#include "DatabaseTypeQueueSettingsController.h"
#include "DatabaseTypeRecnoSettingsController.h"
#include "DatabaseRecordSettingsController.h"
#include "DatabaseRecordVariableLengthSettingsController.h"
#include "DatabaseVerbositySettingsController.h"
#include "DatabaseVerificationSettingsController.h"

#include "DebugSettingsController.h"
#include "DebugVerbositySettingsController.h"

#include "DirectorySettingsController.h"

#include "EnvironmentCacheSettingsController.h"

#include "ErrorSettingsController.h"

#include "FileSettingsController.h"
#include "FileVerbositySettingsController.h"

#include "DatabaseJoinSettingsController.h"

#include "LockSettingsController.h"
#include "LockDeadlockDetectorSettingsController.h"
#include "LockDeadlockDetectorVerbositySettingsController.h"

#include "LogSettingsController.h"

#include "MemoryPoolSettingsController.h"
#include "MemoryPoolReadWriteSettingsController.h"
#include "MemoryPoolFileSettingsController.h"
#include "MemoryPoolFilePageSettingsController.h"
#include "MemoryPoolFileCacheSettingsController.h"
#include "MemoryPoolFileCachePrioritySettingsController.h"

#include "MessageSettingsController.h"

#include "MutexSettingsController.h"

#include "ReplicationSettingsController.h"
#include "ReplicationElectionSettingsController.h"
#include "ReplicationTimeoutSettingsController.h"
#include "ReplicationVerbositySettingsController.h"

#include "ThreadSettingsController.h"

#include "TransactionSettingsController.h"

#include "DatabaseObject.h"
#include "DatabaseObject_internal.h"
#include "DatabaseObjectCursor.h"
#include "DatabaseObjectDatabase.h"

#include <rpbdb/main.h>
#include <rpbdb/Environment.h>
#include <rpbdb/Database_internal.h>
#include <rpbdb/DatabaseSettingsController.h>
#include <rpbdb/DatabaseTypeSettingsController.h>
#include <rpbdb/RuntimeStorageController.h>
#include <rpbdb/RuntimeStorage.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	rb_mRPbdb;

VALUE	rb_RPbdb_Environment;
	VALUE	rb_RPbdb_DatabaseController;
		VALUE	rb_RPbdb_Database;
		
			VALUE rb_RPbdb_DatabaseType_const_module;
			VALUE	rb_RPbdb_DatabaseBtreeType_const;
			VALUE	rb_RPbdb_DatabaseHashType_const;
			VALUE	rb_RPbdb_DatabaseQueueType_const;
			VALUE	rb_RPbdb_DatabaseRecnoType_const;

			VALUE	rb_RPbdb_BtreeDatabase;
			VALUE	rb_RPbdb_HashDatabase;
			VALUE	rb_RPbdb_QueueDatabase;
			VALUE	rb_RPbdb_RecnoDatabase;
		
		VALUE	rb_RPbdb_DatabaseObjectDatabase;
			VALUE	rb_RPbdb_DatabaseCursorController;
				VALUE	rb_RPbdb_DatabaseCursor;
				VALUE	rb_RPbdb_DatabaseObjectCursor;
VALUE	rb_RPbdb_DatabaseSequenceController;
VALUE	rb_RPbdb_DatabaseSequence;

	VALUE	rb_RPbdb_Error;
	VALUE	rb_RPbdb_ErrorController;
	VALUE	rb_RPbdb_DatabaseJoinContainer;
	VALUE	rb_RPbdb_DatabaseJoinController;
	VALUE	rb_RPbdb_DatabaseJoinCursor;
	VALUE	rb_RPbdb_Lock;
VALUE	rb_RPbdb_LockController;
VALUE	rb_RPbdb_Log;
VALUE	rb_RPbdb_LogController;
VALUE	rb_RPbdb_LogCursor;
VALUE	rb_RPbdb_LogCursorController;
VALUE	rb_RPbdb_LogSequenceNumber;
VALUE	rb_RPbdb_MemoryPoolController;
VALUE	rb_RPbdb_MemoryPoolFile;
VALUE	rb_RPbdb_MemoryPoolFileController;
VALUE	rb_RPbdb_MemoryPoolFilePage;
VALUE	rb_RPbdb_MemoryPoolFilePageController;
VALUE	rb_RPbdb_Mutex;
VALUE	rb_RPbdb_MutexController;

		VALUE	rb_RPbdb_Record;
		VALUE	rb_RPbdb_Data;
		VALUE	rb_RPbdb_Key;
		VALUE	rb_RPbdb_SecondaryKeys;

VALUE	rb_RPbdb_ReplicationController;
VALUE	rb_RPbdb_RemoteSite;

VALUE	rb_RPbdb_Transaction;
VALUE	rb_RPbdb_TransactionController;


VALUE	rb_RPbdb_SettingsController;
	VALUE	rb_RPbdb_DatabaseSettingsController;
		VALUE	rb_RPbdb_DatabaseAssociationSettingsController;
		VALUE	rb_RPbdb_DatabaseCacheSettingsController;
		VALUE	rb_RPbdb_DatabaseCachePrioritySettingsController;
		VALUE	rb_RPbdb_DatabaseCompactSettingsController;
		VALUE	rb_RPbdb_DatabaseCursorSettingsController;
		VALUE	rb_RPbdb_DatabaseCursorReadWriteSettingsController;
		VALUE	rb_RPbdb_DatabaseCursorCacheSettingsController;
		VALUE	rb_RPbdb_DatabaseCursorCachePrioritySettingsController;
		VALUE	rb_RPbdb_DatabaseEncryptionSettingsController;
		VALUE	rb_RPbdb_DatabaseErrorSettingsController;
		VALUE	rb_RPbdb_DatabaseRecordFixedLengthSettingsController;
		VALUE	rb_RPbdb_DatabaseRecordReadWriteSettingsController;
		VALUE	rb_RPbdb_DatabaseRecordSettingsController;
		VALUE	rb_RPbdb_DatabaseSequenceSettingsController;
		VALUE	rb_RPbdb_DatabaseTypeSettingsController;
		VALUE	rb_RPbdb_DatabaseTypeBtreeSettingsController;
		VALUE	rb_RPbdb_DatabaseTypeHashSettingsController;
		VALUE	rb_RPbdb_DatabaseTypeQueueSettingsController;
		VALUE	rb_RPbdb_DatabaseTypeRecnoSettingsController;
		VALUE	rb_RPbdb_DatabaseRecordSettingsController;
		VALUE	rb_RPbdb_DatabaseRecordVariableLengthSettingsController;
		VALUE	rb_RPbdb_DatabaseVerbositySettingsController;
		VALUE	rb_RPbdb_DatabaseVerificationSettingsController;
	VALUE	rb_RPbdb_DebugSettingsController;
VALUE	rb_RPbdb_DebugVerbositySettingsController;
	VALUE	rb_RPbdb_DirectorySettingsController;
	VALUE	rb_RPbdb_EnvironmentCacheSettingsController;
	VALUE	rb_RPbdb_ErrorSettingsController;
	VALUE	rb_RPbdb_FileSettingsController;
	VALUE	rb_RPbdb_FileVerbositySettingsController;
VALUE	rb_RPbdb_DatabaseJoinSettingsController;
VALUE	rb_RPbdb_LockSettingsController;
VALUE	rb_RPbdb_LockDeadlockDetectorSettingsController;
VALUE	rb_RPbdb_LockDeadlockDetectorVerbositySettingsController;
VALUE	rb_RPbdb_LogSettingsController;
VALUE	rb_RPbdb_MemoryPoolSettingsController;
VALUE	rb_RPbdb_MemoryPoolReadWriteSettingsController;
VALUE	rb_RPbdb_MemoryPoolFileSettingsController;
VALUE	rb_RPbdb_MemoryPoolFilePageSettingsController;
VALUE	rb_RPbdb_MemoryPoolFileCacheSettingsController;
VALUE	rb_RPbdb_MemoryPoolFileCachePrioritySettingsController;
VALUE	rb_RPbdb_MessageSettingsController;
VALUE	rb_RPbdb_MutexSettingsController;
VALUE	rb_RPbdb_ReplicationSettingsController;
VALUE	rb_RPbdb_ReplicationElectionSettingsController;
VALUE	rb_RPbdb_ReplicationTimeoutSettingsController;
VALUE	rb_RPbdb_ReplicationVerbositySettingsController;
VALUE	rb_RPbdb_ThreadSettingsController;
VALUE	rb_RPbdb_TransactionSettingsController;

VALUE rb_cFileString;

/*********
*  initialize  *
*********/

//	Called from ruby when RPbdb module is initialized
void Init_rpbdb()	{

	//	Init singleton properties (including its status as a module)

	rb_mRPbdb 	=	rb_define_module( "RPbdb" );

  rb_define_const( rb_mRPbdb, "NoSecondaryKeys", ID2SYM( rb_intern( "rpbdb_no_secondary_keys_key_return_value" ) ) );

	//	override of extend so we can auto-extend both ways for RPbdb
	rb_define_singleton_method(	rb_cObject,	"extend",															rb_RPbdb_extend,												1 );

	rb_define_singleton_method(	rb_mRPbdb,		"included",														rb_RPbdb_included,											1 );
	rb_define_singleton_method(	rb_mRPbdb,		"extended",														rb_RPbdb_extended,											1 );
	rb_define_singleton_method(	rb_mRPbdb,		"included_for?",											rb_RPbdb_includedFor,									-1 );
	rb_define_singleton_method(	rb_mRPbdb,		"extends?",														rb_RPbdb_extends,											-1 );

	rb_define_singleton_method(	rb_mRPbdb, 	"current_working_environment",				rb_RPbdb_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"current_environment",								rb_RPbdb_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"current_working_environment=",				rb_RPbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPbdb, 	"set_current_working_environment",		rb_RPbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPbdb, 	"current_environment=",								rb_RPbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRPbdb, 	"set_current_environment",						rb_RPbdb_setCurrentWorkingEnvironment,	1 );
	
	rb_define_singleton_method(	rb_mRPbdb, 	"version",														rb_RPbdb_version,											0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"version_major",											rb_RPbdb_versionMajor,									0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"version_minor",											rb_RPbdb_versionMinor,									0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"version_patch",											rb_RPbdb_versionPatch,									0 );
	rb_define_singleton_method(	rb_mRPbdb, 	"version_parts",											rb_RPbdb_versionData,									0 );
		
	Init_rb_RPbdb_Module();

		Init_rb_RPbdb_Environment();
		
		Init_rb_RPbdb_Database();
		Init_rb_RPbdb_DatabaseController();
		Init_rb_RPbdb_DatabaseObjectDatabase();
		Init_rb_RPbdb_DatabaseCursor();
		Init_rb_RPbdb_DatabaseCursorController();
		Init_rb_RPbdb_DatabaseJoinController();
		Init_rb_RPbdb_DatabaseJoinCursor();
		Init_rb_RPbdb_DatabaseObjectCursor();
		Init_rb_RPbdb_DatabaseSequence();
		Init_rb_RPbdb_DatabaseSequenceController();

		//	Record/Key/Data
		Init_rb_RPbdb_Record();
		Init_rb_RPbdb_Key();
		Init_rb_RPbdb_Data();

		//	Locks
//		Init_rb_RPbdb_LockController();
//		Init_rb_RPbdb_Lock();

		//	Transactions
		Init_rb_RPbdb_TransactionController();
		Init_rb_RPbdb_Transaction();

		//	Settings
		Init_rb_RPbdb_SettingsController();

		//	Database Settings
		Init_rb_RPbdb_DatabaseSettingsController();
		Init_rb_RPbdb_DatabaseAssociationSettingsController();
		Init_rb_RPbdb_DatabaseCacheSettingsController();
		Init_rb_RPbdb_DatabaseCachePrioritySettingsController();
		Init_rb_RPbdb_DatabaseCompactSettingsController();
		Init_rb_RPbdb_DatabaseCursorSettingsController();
		Init_rb_RPbdb_DatabaseCursorReadWriteSettingsController();
		Init_rb_RPbdb_DatabaseCacheSettingsController();
		Init_rb_RPbdb_DatabaseCursorCacheSettingsController();
		Init_rb_RPbdb_DatabaseCursorCachePrioritySettingsController();
		Init_rb_RPbdb_DatabaseEncryptionSettingsController();
		Init_rb_RPbdb_DatabaseErrorSettingsController();
		Init_rb_RPbdb_DatabaseJoinSettingsController();
		Init_rb_RPbdb_DatabaseRecordSettingsController();
		Init_rb_RPbdb_DatabaseRecordReadWriteSettingsController();
		Init_rb_RPbdb_DatabaseRecordFixedLengthSettingsController();
		Init_rb_RPbdb_DatabaseRecordVariableLengthSettingsController();
		Init_rb_RPbdb_DatabaseSequenceSettingsController();
		Init_rb_RPbdb_DatabaseTypeSettingsController();
		Init_rb_RPbdb_DatabaseTypeBtreeSettingsController();
		Init_rb_RPbdb_DatabaseTypeHashSettingsController();
		Init_rb_RPbdb_DatabaseTypeQueueSettingsController();
		Init_rb_RPbdb_DatabaseTypeRecnoSettingsController();
		Init_rb_RPbdb_DatabaseVerificationSettingsController();
		Init_rb_RPbdb_DatabaseVerbositySettingsController();

		Init_rb_RPbdb_DebugSettingsController();
		Init_rb_RPbdb_DebugVerbositySettingsController();
		
		Init_rb_RPbdb_DirectorySettingsController();
		
		Init_rb_RPbdb_EnvironmentCacheSettingsController();
		
		Init_rb_RPbdb_ErrorSettingsController();
		
		Init_rb_RPbdb_FileSettingsController();
		Init_rb_RPbdb_FileVerbositySettingsController();
		
		Init_rb_RPbdb_LogSettingsController();
		
		Init_rb_RPbdb_LockSettingsController();
		Init_rb_RPbdb_LockDeadlockDetectorSettingsController();
		Init_rb_RPbdb_LockDeadlockDetectorVerbositySettingsController();
		
		Init_rb_RPbdb_MemoryPoolSettingsController();
		Init_rb_RPbdb_MemoryPoolFileSettingsController();
		Init_rb_RPbdb_MemoryPoolFilePageSettingsController();
		Init_rb_RPbdb_MemoryPoolFileCacheSettingsController();
		Init_rb_RPbdb_MemoryPoolFileCachePrioritySettingsController();
		Init_rb_RPbdb_MemoryPoolReadWriteSettingsController();
		
		Init_rb_RPbdb_MessageSettingsController();
		
		Init_rb_RPbdb_MutexSettingsController();
		
		Init_rb_RPbdb_ReplicationSettingsController();
		Init_rb_RPbdb_ReplicationElectionSettingsController();
		Init_rb_RPbdb_ReplicationTimeoutSettingsController();
		Init_rb_RPbdb_ReplicationVerbositySettingsController();
		
		Init_rb_RPbdb_ThreadSettingsController();
		
		Init_rb_RPbdb_TransactionSettingsController();
		
		rb_RPbdb_internal_initRuntimeStorages( rb_mRPbdb );

}

/***********
*  extend  *
***********/

//	replacement for Object.extend that will also include if module == RPbdb
VALUE rb_RPbdb_extend(	VALUE	rb_self,
											VALUE	rb_module )	{
	
	//	extend can be called on a class or instance - in either case we want to call include on the class	
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	//	call extend as expected
	rb_call_super( 1, & rb_module );
	
	if ( rb_module == rb_mRPbdb )	{

		//	now call include if needed
		VALUE	rb_included_classes_hash	=	rb_RPbdb_internal_includedForClassesHash();
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

VALUE rb_RPbdb_included(	VALUE	rb_module_self,
												VALUE	rb_included_in_module_or_class )	{

	VALUE	rb_included_classes_hash	=	rb_RPbdb_internal_includedForClassesHash();
	
	//	if we haven't included yet, take note and initialize
	if ( rb_hash_aref(	rb_included_classes_hash,
											rb_included_in_module_or_class ) == Qnil )	{

		//	mark as included so we don't get stuck in a loop from extend	
		rb_hash_aset(	rb_included_classes_hash,
									rb_included_in_module_or_class,
									Qtrue );
	
		//	if not extended, call extend on class - we've marked class as included, so extend won't call it
		VALUE	rb_extended_classes_hash	=	rb_RPbdb_internal_extendedClassesHash();
		if ( rb_hash_aref(	rb_extended_classes_hash,
												rb_included_in_module_or_class ) == Qnil )	{

			rb_extend_object(	rb_included_in_module_or_class,
												rb_module_self );
		}
				
		rb_RPbdb_internal_configureIfNecessary(	rb_module_self,
																						rb_included_in_module_or_class );
	}
	
	return rb_module_self;
}

/*************
*  extended  *
*************/

VALUE rb_RPbdb_extended(	VALUE	rb_module_self,
												VALUE	rb_extended_module_or_class )	{
	
	//	mark as extended so we don't get stuck in a loop from include
	VALUE	rb_extended_classes_hash	=	rb_RPbdb_internal_extendedClassesHash();
	
	//	if we haven't extended yet, take note and initialize
	if ( rb_hash_aref(	rb_extended_classes_hash,
											rb_extended_module_or_class ) == Qnil )	{
		
		//	store extended module or class constant
		rb_hash_aset(	rb_extended_classes_hash,
					 				rb_extended_module_or_class,
					 				Qtrue );
		
		rb_RPbdb_internal_configureIfNecessary(	rb_module_self,
																						rb_extended_module_or_class );
		
	}
	return rb_module_self;
}

/******************
*  included_for?  *
******************/

VALUE rb_RPbdb_includedFor(	int			argc,
														VALUE*	args,
														VALUE		rb_module_self __attribute__ ((unused )) )		{
	
	//	get included classes array from module
	VALUE	rb_included_classes_hash	=	rb_RPbdb_internal_includedForClassesHash();

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

VALUE rb_RPbdb_extends(	int			argc,
												VALUE*	args,
												VALUE		rb_module_self __attribute__ ((unused )) )	{
	
	//	get included classes array from module
	VALUE	rb_extended_classes_hash	=	rb_RPbdb_internal_extendedClassesHash();
	
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

VALUE rb_RPbdb_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	//	change default environment to current working environment
	//	when a new environment is opened, the current working environment is set to it
	//	it can also be changed by specifying new cwe	
	//	when the environment closes if it is the cwe then it is removed
	//	only open environments can be the cwe
	//	additionally, cwe can stack, but any time one is closed it is removed from the stack, even if not current
	
	VALUE	rb_current_working_environment_stack	=	rb_RPbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	VALUE	rb_current_working_environment				=	rb_ary_entry(	rb_current_working_environment_stack, 0 );
	
	return rb_current_working_environment;	
}

/*********************************
*  current_working_environment=  *
*********************************/

VALUE rb_RPbdb_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																						VALUE	rb_environment )	{

	RPbdb_Environment*	c_environment	=	NULL;
	C_RPBDB_ENVIRONMENT( rb_environment, c_environment );

	RPbdb_RuntimeStorageController_setCurrentWorkingEnvironment( RPbdb_RuntimeStorageController_sharedInstance(),
																															c_environment );
	
	VALUE	rb_current_working_environment_stack	=	rb_RPbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	
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
VALUE rb_RPbdb_version( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return rb_str_new2( RPbdb_version() );
}

/******************
*  version_major  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPbdb_versionMajor( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( RPbdb_versionMajor() );
}

/******************
*  version_minor  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPbdb_versionMinor( VALUE rb_module_self __attribute__ ((unused )) )	{
		
	return INT2FIX( RPbdb_versionMinor() );
}

/******************
*  version_patch  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPbdb_versionPatch( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( RPbdb_versionPatch() );
}

/*****************
*  version_data  *
*****************/

//	Returns an array:
//	* major
//	* minor
//	* patch
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_RPbdb_versionData(	VALUE	rb_module_self __attribute__ ((unused )) )	{
	
	int					major;
	int					minor;
	int					patch;
	
	RPbdb_versionData(	& major,
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

void rb_RPbdb_internal_initRuntimeStorages( VALUE rb_module_self )	{

	//	Now init ruby runtime storage
	RPbdb_RuntimeStorageController*		c_runtime_storage_controller	=	RPbdb_RuntimeStorageController_sharedInstance();
	RPbdb_DatabaseController*					c_database_controller					=	RPbdb_Environment_databaseController(	c_runtime_storage_controller->runtime_environment );
	RPbdb_Database*										c_runtime_storage_database		=	RPbdb_Database_new(	c_database_controller,
																																												"ruby_databases_by_c_reference" );
	RPbdb_DatabaseSettingsController*			c_database_settings_controller			=	RPbdb_Database_settingsController( c_runtime_storage_database );
	RPbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	RPbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	RPbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
	
	VALUE	rb_runtime_storage_database	=	RUBY_RPBDB_DATABASE( c_runtime_storage_database );

	rb_iv_set(	rb_module_self,
							RPBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE,
							rb_runtime_storage_database );
}

/************************
*  rubyRuntimeDatabase  *
************************/

VALUE rb_RPbdb_internal_rubyRuntimeDatabase(	VALUE rb_module_self )	{

	VALUE	rb_runtime_storage_database	=	rb_iv_get(	rb_module_self,
																									RPBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE );
	return rb_runtime_storage_database;
}

/***************************
*  configure_if_necessary  *
***************************/

VALUE rb_RPbdb_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass )	{
		
	//	check if we've initialized
	if ( rb_RPbdb_DatabaseObject_hasConfigured( rb_klass ) == Qfalse )	{
		
		//	activate class
		//	if identifiers are empty, uses default environment
		rb_RPbdb_DatabaseObject_internal_activateClass(	rb_klass );
		
		//	note that we've configured
		rb_RPbdb_DatabaseObject_internal_setHasConfigured(	rb_klass,
																											Qtrue );
	}
	return rb_module_self;
}


/*********************************
*  environmentToIdentifiersHash  *
*********************************/

VALUE rb_RPbdb_internal_environmentsToIdentifiersHash()	{
	
	//	get the environment identifiers hash from the RPbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPbdb,
																													RPBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS );

	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
							  RPBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS,
							  rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/************************
*  extendedClassesHash  *
************************/

VALUE rb_RPbdb_internal_extendedClassesHash()	{

	//	get the environment identifiers hash from the RPbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPbdb,
																													RPBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{

		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/***************************
*  includedForClassesHash  *
***************************/

VALUE rb_RPbdb_internal_includedForClassesHash()	{
	
	//	get the environment identifiers hash from the RPbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRPbdb,
																													RPBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/*******************************
*  inititializeWaitingClasses  *
*******************************/

//	initialization takes place immediately after configuration has taken place for all pending classes for given environment
VALUE rb_RPbdb_internal_initializeWaitingClasses()	{
	
	//	get initWaitList array from module
	VALUE	rb_init_wait_list	=	rb_RPbdb_internal_classesWaitingForInitialization();
	
	//	iterate classes in array, calling initRPbdb on each and removing from wait list
	VALUE	rb_this_class;
	while ( ( rb_this_class = rb_ary_shift( rb_init_wait_list ) ) != Qnil )	{
		
		rb_RPbdb_DatabaseObject_internal_callInitRPbdb( rb_this_class );
	}
	
	return Qtrue;
}

/****************************************
*  classesWaitingForDefaultEnvironment  *
****************************************/

//	array tracks classes that will configure when the next environment opens
VALUE rb_RPbdb_internal_classesWaitingForDefaultEnvironment()	{
	
	VALUE	rb_current_working_environment_wait_list_array	=	rb_iv_get(	rb_mRPbdb,
																															RPBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY );
	
	if ( rb_current_working_environment_wait_list_array == Qnil )	{
		rb_current_working_environment_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY,
								rb_current_working_environment_wait_list_array );
	}
	
	return rb_current_working_environment_wait_list_array;
}

/************************************
*  classesWaitingForIdentification  *
************************************/

//	array tracks classes that will wait to identify with an appropriate environment
VALUE rb_RPbdb_internal_classesWaitingForIdentification()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRPbdb,
																											RPBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/************************************
*  classesWaitingForInitialization  *
************************************/

//	initialization takes place immediately after all classes have ben configured for the given environment
VALUE rb_RPbdb_internal_classesWaitingForInitialization()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRPbdb,
																											RPBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRPbdb,
								RPBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/*********************************************
*  deleteFromCurrentWorkingEnvironmentStack  *
*********************************************/

VALUE rb_RPbdb_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																	VALUE	rb_environment )	{

	VALUE	rb_current_working_environment_stack	=	rb_RPbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	
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

VALUE rb_RPbdb_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self )	{
	
	VALUE	rb_stack_array	=	rb_iv_get(	rb_module_self,
																			RPBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK );

	if ( rb_stack_array == Qnil )	{
		rb_stack_array	=	rb_ary_new();
		rb_iv_set(	rb_module_self,
								RPBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK,
								rb_stack_array );
	}
	return rb_stack_array;
}

