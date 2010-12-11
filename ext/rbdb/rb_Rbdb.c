/*
 *		Rbdb
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_BaseStandardIncludes.h"

#include "rb_Rbdb.h"
#include "rb_Rbdb_internal.h"

#include "rb_Rbdb_Environment.h"

#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_DatabaseCursorController.h"
#include "rb_Rbdb_DatabaseCursor.h"
#include "rb_Rbdb_DatabaseSequenceController.h"
#include "rb_Rbdb_DatabaseSequence.h"
#include "rb_Rbdb_DatabaseJoinController.h"
#include "rb_Rbdb_DatabaseJoinCursor.h"

#include "rb_Rbdb_Lock.h"
#include "rb_Rbdb_LockController.h"

#include "rb_Rbdb_Log.h"
#include "rb_Rbdb_LogController.h"
#include "rb_Rbdb_LogCursor.h"
#include "rb_Rbdb_LogCursorController.h"
#include "rb_Rbdb_LogSequenceNumber.h"

#include "rb_Rbdb_MemoryPoolController.h"
#include "rb_Rbdb_MemoryPoolFile.h"
#include "rb_Rbdb_MemoryPoolFileController.h"
#include "rb_Rbdb_MemoryPoolFilePage.h"
#include "rb_Rbdb_MemoryPoolFilePageController.h"

#include "rb_Rbdb_Mutex.h"
#include "rb_Rbdb_MutexController.h"

#include "rb_Rbdb_Record.h"
#include "rb_Rbdb_Data.h"
#include "rb_Rbdb_Key.h"
#include "rb_Rbdb_SecondaryKeys.h"

#include "rb_Rbdb_ReplicationController.h"
#include "rb_Rbdb_RemoteSite.h"

#include "rb_Rbdb_Transaction.h"
#include "rb_Rbdb_TransactionController.h"

#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_DatabaseAssociationSettingsController.h"
#include "rb_Rbdb_DatabaseCacheSettingsController.h"
#include "rb_Rbdb_DatabaseCachePrioritySettingsController.h"
#include "rb_Rbdb_DatabaseCompactSettingsController.h"
#include "rb_Rbdb_DatabaseCursorSettingsController.h"
#include "rb_Rbdb_DatabaseCursorReadWriteSettingsController.h"
#include "rb_Rbdb_DatabaseCursorCacheSettingsController.h"
#include "rb_Rbdb_DatabaseCursorCachePrioritySettingsController.h"
#include "rb_Rbdb_DatabaseEncryptionSettingsController.h"
#include "rb_Rbdb_DatabaseErrorSettingsController.h"
#include "rb_Rbdb_DatabaseJoinSettingsController.h"
#include "rb_Rbdb_DatabaseRecordFixedLengthSettingsController.h"
#include "rb_Rbdb_DatabaseRecordReadWriteSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_DatabaseSequenceSettingsController.h"
#include "rb_Rbdb_DatabaseTypeSettingsController.h"
#include "rb_Rbdb_DatabaseTypeBtreeSettingsController.h"
#include "rb_Rbdb_DatabaseTypeHashSettingsController.h"
#include "rb_Rbdb_DatabaseTypeQueueSettingsController.h"
#include "rb_Rbdb_DatabaseTypeRecnoSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_DatabaseRecordVariableLengthSettingsController.h"
#include "rb_Rbdb_DatabaseVerbositySettingsController.h"
#include "rb_Rbdb_DatabaseVerificationSettingsController.h"

#include "rb_Rbdb_DebugSettingsController.h"
#include "rb_Rbdb_DebugVerbositySettingsController.h"

#include "rb_Rbdb_DirectorySettingsController.h"

#include "rb_Rbdb_EnvironmentCacheSettingsController.h"

#include "rb_Rbdb_ErrorSettingsController.h"

#include "rb_Rbdb_FileSettingsController.h"
#include "rb_Rbdb_FileVerbositySettingsController.h"

#include "rb_Rbdb_DatabaseJoinSettingsController.h"

#include "rb_Rbdb_LockSettingsController.h"
#include "rb_Rbdb_LockDeadlockDetectorSettingsController.h"
#include "rb_Rbdb_LockDeadlockDetectorVerbositySettingsController.h"

#include "rb_Rbdb_LogSettingsController.h"

#include "rb_Rbdb_MemoryPoolSettingsController.h"
#include "rb_Rbdb_MemoryPoolReadWriteSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileSettingsController.h"
#include "rb_Rbdb_MemoryPoolFilePageSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileCacheSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileCachePrioritySettingsController.h"

#include "rb_Rbdb_MessageSettingsController.h"

#include "rb_Rbdb_MutexSettingsController.h"

#include "rb_Rbdb_ReplicationSettingsController.h"
#include "rb_Rbdb_ReplicationElectionSettingsController.h"
#include "rb_Rbdb_ReplicationTimeoutSettingsController.h"
#include "rb_Rbdb_ReplicationVerbositySettingsController.h"

#include "rb_Rbdb_ThreadSettingsController.h"

#include "rb_Rbdb_TransactionSettingsController.h"

#include "rb_Rbdb_DatabaseObject.h"
#include "rb_Rbdb_DatabaseObject_internal.h"
#include "rb_Rbdb_DatabaseObjectCursor.h"
#include "rb_Rbdb_DatabaseObjectDatabase.h"

#include <rbdb/Rbdb_main.h>
#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database_internal.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DatabaseTypeSettingsController.h>
#include <rbdb/Rbdb_RuntimeStorageController.h>
#include <rbdb/Rbdb_RuntimeStorage.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	rb_mRbdb;

VALUE	rb_Rbdb_Environment;
	VALUE	rb_Rbdb_DatabaseController;
		VALUE	rb_Rbdb_Database;
		
			VALUE rb_Rbdb_DatabaseType_const_module;
			VALUE	rb_Rbdb_DatabaseBtreeType_const;
			VALUE	rb_Rbdb_DatabaseHashType_const;
			VALUE	rb_Rbdb_DatabaseQueueType_const;
			VALUE	rb_Rbdb_DatabaseRecnoType_const;

			VALUE	rb_Rbdb_BtreeDatabase;
			VALUE	rb_Rbdb_HashDatabase;
			VALUE	rb_Rbdb_QueueDatabase;
			VALUE	rb_Rbdb_RecnoDatabase;
		
		VALUE	rb_Rbdb_DatabaseObjectDatabase;
			VALUE	rb_Rbdb_DatabaseCursorController;
				VALUE	rb_Rbdb_DatabaseCursor;
				VALUE	rb_Rbdb_DatabaseObjectCursor;
VALUE	rb_Rbdb_DatabaseSequenceController;
VALUE	rb_Rbdb_DatabaseSequence;

	VALUE	rb_Rbdb_Error;
	VALUE	rb_Rbdb_ErrorController;
	VALUE	rb_Rbdb_DatabaseJoinContainer;
	VALUE	rb_Rbdb_DatabaseJoinController;
	VALUE	rb_Rbdb_DatabaseJoinCursor;
	VALUE	rb_Rbdb_Lock;
VALUE	rb_Rbdb_LockController;
VALUE	rb_Rbdb_Log;
VALUE	rb_Rbdb_LogController;
VALUE	rb_Rbdb_LogCursor;
VALUE	rb_Rbdb_LogCursorController;
VALUE	rb_Rbdb_LogSequenceNumber;
VALUE	rb_Rbdb_MemoryPoolController;
VALUE	rb_Rbdb_MemoryPoolFile;
VALUE	rb_Rbdb_MemoryPoolFileController;
VALUE	rb_Rbdb_MemoryPoolFilePage;
VALUE	rb_Rbdb_MemoryPoolFilePageController;
VALUE	rb_Rbdb_Mutex;
VALUE	rb_Rbdb_MutexController;

		VALUE	rb_Rbdb_Record;
		VALUE	rb_Rbdb_Data;
		VALUE	rb_Rbdb_Key;
		VALUE	rb_Rbdb_SecondaryKeys;

VALUE	rb_Rbdb_ReplicationController;
VALUE	rb_Rbdb_RemoteSite;

VALUE	rb_Rbdb_Transaction;
VALUE	rb_Rbdb_TransactionController;


VALUE	rb_Rbdb_SettingsController;
	VALUE	rb_Rbdb_DatabaseSettingsController;
		VALUE	rb_Rbdb_DatabaseAssociationSettingsController;
		VALUE	rb_Rbdb_DatabaseCacheSettingsController;
		VALUE	rb_Rbdb_DatabaseCachePrioritySettingsController;
		VALUE	rb_Rbdb_DatabaseCompactSettingsController;
		VALUE	rb_Rbdb_DatabaseCursorSettingsController;
		VALUE	rb_Rbdb_DatabaseCursorReadWriteSettingsController;
		VALUE	rb_Rbdb_DatabaseCursorCacheSettingsController;
		VALUE	rb_Rbdb_DatabaseCursorCachePrioritySettingsController;
		VALUE	rb_Rbdb_DatabaseEncryptionSettingsController;
		VALUE	rb_Rbdb_DatabaseErrorSettingsController;
		VALUE	rb_Rbdb_DatabaseRecordFixedLengthSettingsController;
		VALUE	rb_Rbdb_DatabaseRecordReadWriteSettingsController;
		VALUE	rb_Rbdb_DatabaseRecordSettingsController;
		VALUE	rb_Rbdb_DatabaseSequenceSettingsController;
		VALUE	rb_Rbdb_DatabaseTypeSettingsController;
		VALUE	rb_Rbdb_DatabaseTypeBtreeSettingsController;
		VALUE	rb_Rbdb_DatabaseTypeHashSettingsController;
		VALUE	rb_Rbdb_DatabaseTypeQueueSettingsController;
		VALUE	rb_Rbdb_DatabaseTypeRecnoSettingsController;
		VALUE	rb_Rbdb_DatabaseRecordSettingsController;
		VALUE	rb_Rbdb_DatabaseRecordVariableLengthSettingsController;
		VALUE	rb_Rbdb_DatabaseVerbositySettingsController;
		VALUE	rb_Rbdb_DatabaseVerificationSettingsController;
	VALUE	rb_Rbdb_DebugSettingsController;
VALUE	rb_Rbdb_DebugVerbositySettingsController;
	VALUE	rb_Rbdb_DirectorySettingsController;
	VALUE	rb_Rbdb_EnvironmentCacheSettingsController;
	VALUE	rb_Rbdb_ErrorSettingsController;
	VALUE	rb_Rbdb_FileSettingsController;
	VALUE	rb_Rbdb_FileVerbositySettingsController;
VALUE	rb_Rbdb_DatabaseJoinSettingsController;
VALUE	rb_Rbdb_LockSettingsController;
VALUE	rb_Rbdb_LockDeadlockDetectorSettingsController;
VALUE	rb_Rbdb_LockDeadlockDetectorVerbositySettingsController;
VALUE	rb_Rbdb_LogSettingsController;
VALUE	rb_Rbdb_MemoryPoolSettingsController;
VALUE	rb_Rbdb_MemoryPoolReadWriteSettingsController;
VALUE	rb_Rbdb_MemoryPoolFileSettingsController;
VALUE	rb_Rbdb_MemoryPoolFilePageSettingsController;
VALUE	rb_Rbdb_MemoryPoolFileCacheSettingsController;
VALUE	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController;
VALUE	rb_Rbdb_MessageSettingsController;
VALUE	rb_Rbdb_MutexSettingsController;
VALUE	rb_Rbdb_ReplicationSettingsController;
VALUE	rb_Rbdb_ReplicationElectionSettingsController;
VALUE	rb_Rbdb_ReplicationTimeoutSettingsController;
VALUE	rb_Rbdb_ReplicationVerbositySettingsController;
VALUE	rb_Rbdb_ThreadSettingsController;
VALUE	rb_Rbdb_TransactionSettingsController;


/*********
*  initialize  *
*********/

//	Called from ruby when Rbdb module is initialized
void Init_rbdb()	{

	//	Init singleton properties (including its status as a module)

	rb_mRbdb 	=	rb_define_module( "Rbdb" );

	//	override of extend so we can auto-extend both ways for Rbdb
	rb_define_singleton_method(	rb_cObject,	"extend",															rb_Rbdb_extend,												1 );

	rb_define_singleton_method(	rb_mRbdb,		"included",														rb_Rbdb_included,											1 );
	rb_define_singleton_method(	rb_mRbdb,		"extended",														rb_Rbdb_extended,											1 );
	rb_define_singleton_method(	rb_mRbdb,		"included_for?",											rb_Rbdb_includedFor,									-1 );
	rb_define_singleton_method(	rb_mRbdb,		"extends?",														rb_Rbdb_extends,											-1 );

	rb_define_singleton_method(	rb_mRbdb, 	"current_working_environment",				rb_Rbdb_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRbdb, 	"current_environment",								rb_Rbdb_currentWorkingEnvironment,		0 );
	rb_define_singleton_method(	rb_mRbdb, 	"current_working_environment=",				rb_Rbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRbdb, 	"set_current_working_environment",		rb_Rbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRbdb, 	"current_environment=",								rb_Rbdb_setCurrentWorkingEnvironment,	1 );
	rb_define_singleton_method(	rb_mRbdb, 	"set_current_environment",						rb_Rbdb_setCurrentWorkingEnvironment,	1 );
	
	rb_define_singleton_method(	rb_mRbdb, 	"version",														rb_Rbdb_version,											0 );
	rb_define_singleton_method(	rb_mRbdb, 	"version_major",											rb_Rbdb_versionMajor,									0 );
	rb_define_singleton_method(	rb_mRbdb, 	"version_minor",											rb_Rbdb_versionMinor,									0 );
	rb_define_singleton_method(	rb_mRbdb, 	"version_patch",											rb_Rbdb_versionPatch,									0 );
	rb_define_singleton_method(	rb_mRbdb, 	"version_parts",											rb_Rbdb_versionData,									0 );
		
	Init_rb_Rbdb_Module();

		Init_rb_Rbdb_Environment();
		
		Init_rb_Rbdb_Database();
		Init_rb_Rbdb_DatabaseController();
		Init_rb_Rbdb_DatabaseObjectDatabase();
		Init_rb_Rbdb_DatabaseCursor();
		Init_rb_Rbdb_DatabaseCursorController();
		Init_rb_Rbdb_DatabaseJoinController();
		Init_rb_Rbdb_DatabaseJoinCursor();
		Init_rb_Rbdb_DatabaseObjectCursor();
		Init_rb_Rbdb_DatabaseSequence();
		Init_rb_Rbdb_DatabaseSequenceController();

		//	Record/Key/Data
		Init_rb_Rbdb_Record();
		Init_rb_Rbdb_Key();
		Init_rb_Rbdb_Data();

		//	Locks
//		Init_rb_Rbdb_LockController();
//		Init_rb_Rbdb_Lock();

		//	Transactions
		Init_rb_Rbdb_TransactionController();
		Init_rb_Rbdb_Transaction();

		//	Settings
		Init_rb_Rbdb_SettingsController();

		//	Database Settings
		Init_rb_Rbdb_DatabaseSettingsController();
		Init_rb_Rbdb_DatabaseAssociationSettingsController();
		Init_rb_Rbdb_DatabaseCacheSettingsController();
		Init_rb_Rbdb_DatabaseCachePrioritySettingsController();
		Init_rb_Rbdb_DatabaseCompactSettingsController();
		Init_rb_Rbdb_DatabaseCursorSettingsController();
		Init_rb_Rbdb_DatabaseCursorReadWriteSettingsController();
		Init_rb_Rbdb_DatabaseCacheSettingsController();
		Init_rb_Rbdb_DatabaseCursorCacheSettingsController();
		Init_rb_Rbdb_DatabaseCursorCachePrioritySettingsController();
		Init_rb_Rbdb_DatabaseEncryptionSettingsController();
		Init_rb_Rbdb_DatabaseErrorSettingsController();
		Init_rb_Rbdb_DatabaseJoinSettingsController();
		Init_rb_Rbdb_DatabaseRecordSettingsController();
		Init_rb_Rbdb_DatabaseRecordReadWriteSettingsController();
		Init_rb_Rbdb_DatabaseRecordFixedLengthSettingsController();
		Init_rb_Rbdb_DatabaseRecordVariableLengthSettingsController();
		Init_rb_Rbdb_DatabaseSequenceSettingsController();
		Init_rb_Rbdb_DatabaseTypeSettingsController();
		Init_rb_Rbdb_DatabaseTypeBtreeSettingsController();
		Init_rb_Rbdb_DatabaseTypeHashSettingsController();
		Init_rb_Rbdb_DatabaseTypeQueueSettingsController();
		Init_rb_Rbdb_DatabaseTypeRecnoSettingsController();
		Init_rb_Rbdb_DatabaseVerificationSettingsController();
		Init_rb_Rbdb_DatabaseVerbositySettingsController();

		Init_rb_Rbdb_DebugSettingsController();
		Init_rb_Rbdb_DebugVerbositySettingsController();
		
		Init_rb_Rbdb_DirectorySettingsController();
		
		Init_rb_Rbdb_EnvironmentCacheSettingsController();
		
		Init_rb_Rbdb_ErrorSettingsController();
		
		Init_rb_Rbdb_FileSettingsController();
		Init_rb_Rbdb_FileVerbositySettingsController();
		
		Init_rb_Rbdb_LogSettingsController();
		
		Init_rb_Rbdb_LockSettingsController();
		Init_rb_Rbdb_LockDeadlockDetectorSettingsController();
		Init_rb_Rbdb_LockDeadlockDetectorVerbositySettingsController();
		
		Init_rb_Rbdb_MemoryPoolSettingsController();
		Init_rb_Rbdb_MemoryPoolFileSettingsController();
		Init_rb_Rbdb_MemoryPoolFilePageSettingsController();
		Init_rb_Rbdb_MemoryPoolFileCacheSettingsController();
		Init_rb_Rbdb_MemoryPoolFileCachePrioritySettingsController();
		Init_rb_Rbdb_MemoryPoolReadWriteSettingsController();
		
		Init_rb_Rbdb_MessageSettingsController();
		
		Init_rb_Rbdb_MutexSettingsController();
		
		Init_rb_Rbdb_ReplicationSettingsController();
		Init_rb_Rbdb_ReplicationElectionSettingsController();
		Init_rb_Rbdb_ReplicationTimeoutSettingsController();
		Init_rb_Rbdb_ReplicationVerbositySettingsController();
		
		Init_rb_Rbdb_ThreadSettingsController();
		
		Init_rb_Rbdb_TransactionSettingsController();
		
		rb_Rbdb_internal_initRuntimeStorages( rb_mRbdb );

}

/***********
*  extend  *
***********/

//	replacement for Object.extend that will also include if module == Rbdb
VALUE rb_Rbdb_extend(	VALUE	rb_self,
											VALUE	rb_module )	{
	
	//	extend can be called on a class or instance - in either case we want to call include on the class	
	VALUE	rb_klass		=	( ( TYPE( rb_self ) == T_CLASS ) ? rb_self : rb_funcall( rb_self, rb_intern( "class" ), 0 ) );

	//	call extend as expected
	rb_call_super( 1, & rb_module );
	
	if ( rb_module == rb_mRbdb )	{

		//	now call include if needed
		VALUE	rb_included_classes_hash	=	rb_Rbdb_internal_includedForClassesHash();
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

VALUE rb_Rbdb_included(	VALUE	rb_module_self,
												VALUE	rb_included_in_module_or_class )	{

	VALUE	rb_included_classes_hash	=	rb_Rbdb_internal_includedForClassesHash();
	
	//	if we haven't included yet, take note and initialize
	if ( rb_hash_aref(	rb_included_classes_hash,
											rb_included_in_module_or_class ) == Qnil )	{

		//	mark as included so we don't get stuck in a loop from extend	
		rb_hash_aset(	rb_included_classes_hash,
									rb_included_in_module_or_class,
									Qtrue );
	
		//	if not extended, call extend on class - we've marked class as included, so extend won't call it
		VALUE	rb_extended_classes_hash	=	rb_Rbdb_internal_extendedClassesHash();
		if ( rb_hash_aref(	rb_extended_classes_hash,
												rb_included_in_module_or_class ) == Qnil )	{

			rb_extend_object(	rb_included_in_module_or_class,
												rb_module_self );
		}
				
		rb_Rbdb_internal_configureIfNecessary(	rb_module_self,
																						rb_included_in_module_or_class );
	}
	
	return rb_module_self;
}

/*************
*  extended  *
*************/

VALUE rb_Rbdb_extended(	VALUE	rb_module_self,
												VALUE	rb_extended_module_or_class )	{
	
	//	mark as extended so we don't get stuck in a loop from include
	VALUE	rb_extended_classes_hash	=	rb_Rbdb_internal_extendedClassesHash();
	
	//	if we haven't extended yet, take note and initialize
	if ( rb_hash_aref(	rb_extended_classes_hash,
											rb_extended_module_or_class ) == Qnil )	{
		
		//	store extended module or class constant
		rb_hash_aset(	rb_extended_classes_hash,
					 				rb_extended_module_or_class,
					 				Qtrue );
		
		rb_Rbdb_internal_configureIfNecessary(	rb_module_self,
																						rb_extended_module_or_class );
		
	}
	return rb_module_self;
}

/******************
*  included_for?  *
******************/

VALUE rb_Rbdb_includedFor(	int			argc,
														VALUE*	args,
														VALUE		rb_module_self __attribute__ ((unused )) )		{
	
	//	get included classes array from module
	VALUE	rb_included_classes_hash	=	rb_Rbdb_internal_includedForClassesHash();

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

VALUE rb_Rbdb_extends(	int			argc,
												VALUE*	args,
												VALUE		rb_module_self __attribute__ ((unused )) )	{
	
	//	get included classes array from module
	VALUE	rb_extended_classes_hash	=	rb_Rbdb_internal_extendedClassesHash();
	
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

VALUE rb_Rbdb_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	//	change default environment to current working environment
	//	when a new environment is opened, the current working environment is set to it
	//	it can also be changed by specifying new cwe	
	//	when the environment closes if it is the cwe then it is removed
	//	only open environments can be the cwe
	//	additionally, cwe can stack, but any time one is closed it is removed from the stack, even if not current
	
	VALUE	rb_current_working_environment_stack	=	rb_Rbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	VALUE	rb_current_working_environment				=	rb_ary_entry(	rb_current_working_environment_stack, 0 );
	
	return rb_current_working_environment;	
}

/*********************************
*  current_working_environment=  *
*********************************/

VALUE rb_Rbdb_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																						VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment	=	NULL;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );

	Rbdb_RuntimeStorageController_setCurrentWorkingEnvironment( Rbdb_RuntimeStorageController_sharedInstance(),
																															c_environment );
	
	VALUE	rb_current_working_environment_stack	=	rb_Rbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	
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
VALUE rb_Rbdb_version( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return rb_str_new2( Rbdb_version() );
}

/******************
*  version_major  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_Rbdb_versionMajor( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( Rbdb_versionMajor() );
}

/******************
*  version_minor  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_Rbdb_versionMinor( VALUE rb_module_self __attribute__ ((unused )) )	{
		
	return INT2FIX( Rbdb_versionMinor() );
}

/******************
*  version_patch  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_Rbdb_versionPatch( VALUE rb_module_self __attribute__ ((unused )) )	{
	
	return INT2FIX( Rbdb_versionPatch() );
}

/*****************
*  version_data  *
*****************/

//	Returns an array:
//	* major
//	* minor
//	* patch
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_version.html
VALUE rb_Rbdb_versionData(	VALUE	rb_module_self __attribute__ ((unused )) )	{
	
	int					major;
	int					minor;
	int					patch;
	
	Rbdb_versionData(	& major,
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

void rb_Rbdb_internal_initRuntimeStorages( VALUE rb_module_self )	{

	//	Now init ruby runtime storage
	Rbdb_RuntimeStorageController*		c_runtime_storage_controller	=	Rbdb_RuntimeStorageController_sharedInstance();
	Rbdb_DatabaseController*					c_database_controller					=	Rbdb_Environment_databaseController(	c_runtime_storage_controller->runtime_environment );
	Rbdb_Database*										c_runtime_storage_database		=	Rbdb_Database_new(	c_database_controller,
																																												"ruby_databases_by_c_reference" );
	Rbdb_DatabaseSettingsController*			c_database_settings_controller			=	Rbdb_Database_settingsController( c_runtime_storage_database );
	Rbdb_DatabaseTypeSettingsController*	c_database_type_settings_controller	=	Rbdb_DatabaseSettingsController_typeSettingsController( c_database_settings_controller );

	Rbdb_DatabaseTypeSettingsController_setTypeToBTree( c_database_type_settings_controller );
	
	VALUE	rb_runtime_storage_database	=	RUBY_RBDB_DATABASE( c_runtime_storage_database );

	rb_iv_set(	rb_module_self,
							RBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE,
							rb_runtime_storage_database );
}

/************************
*  rubyRuntimeDatabase  *
************************/

VALUE rb_Rbdb_internal_rubyRuntimeDatabase(	VALUE rb_module_self )	{

	VALUE	rb_runtime_storage_database	=	rb_iv_get(	rb_module_self,
																									RBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE );
	return rb_runtime_storage_database;
}

/***************************
*  configure_if_necessary  *
***************************/

VALUE rb_Rbdb_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass )	{
		
	//	check if we've initialized
	if ( rb_Rbdb_DatabaseObject_hasConfigured( rb_klass ) == Qfalse )	{
		
		//	activate class
		//	if identifiers are empty, uses default environment
		rb_Rbdb_DatabaseObject_internal_activateClass(	rb_klass );
		
		//	note that we've configured
		rb_Rbdb_DatabaseObject_internal_setHasConfigured(	rb_klass,
																											Qtrue );
	}
	return rb_module_self;
}


/*********************************
*  environmentToIdentifiersHash  *
*********************************/

VALUE rb_Rbdb_internal_environmentsToIdentifiersHash()	{
	
	//	get the environment identifiers hash from the Rbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRbdb,
																													RBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS );

	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
							  RBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS,
							  rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/************************
*  extendedClassesHash  *
************************/

VALUE rb_Rbdb_internal_extendedClassesHash()	{

	//	get the environment identifiers hash from the Rbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRbdb,
																													RBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{

		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/***************************
*  includedForClassesHash  *
***************************/

VALUE rb_Rbdb_internal_includedForClassesHash()	{
	
	//	get the environment identifiers hash from the Rbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_iv_get(	rb_mRbdb,
																													RBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH );
	
	//	init if necessary
	if ( rb_environment_to_identifiers_hash == Qnil )	{
		rb_environment_to_identifiers_hash	=	rb_hash_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH,
								rb_environment_to_identifiers_hash );
	}
	
	return rb_environment_to_identifiers_hash;
}

/*******************************
*  inititializeWaitingClasses  *
*******************************/

//	initialization takes place immediately after configuration has taken place for all pending classes for given environment
VALUE rb_Rbdb_internal_initializeWaitingClasses()	{
	
	//	get initWaitList array from module
	VALUE	rb_init_wait_list	=	rb_Rbdb_internal_classesWaitingForInitialization();
	
	//	iterate classes in array, calling initRbdb on each and removing from wait list
	VALUE	rb_this_class;
	while ( ( rb_this_class = rb_ary_shift( rb_init_wait_list ) ) != Qnil )	{
		
		rb_Rbdb_DatabaseObject_internal_callInitRbdb( rb_this_class );
	}
	
	return Qtrue;
}

/****************************************
*  classesWaitingForDefaultEnvironment  *
****************************************/

//	array tracks classes that will configure when the next environment opens
VALUE rb_Rbdb_internal_classesWaitingForDefaultEnvironment()	{
	
	VALUE	rb_current_working_environment_wait_list_array	=	rb_iv_get(	rb_mRbdb,
																															RBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY );
	
	if ( rb_current_working_environment_wait_list_array == Qnil )	{
		rb_current_working_environment_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY,
								rb_current_working_environment_wait_list_array );
	}
	
	return rb_current_working_environment_wait_list_array;
}

/************************************
*  classesWaitingForIdentification  *
************************************/

//	array tracks classes that will wait to identify with an appropriate environment
VALUE rb_Rbdb_internal_classesWaitingForIdentification()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRbdb,
																											RBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/************************************
*  classesWaitingForInitialization  *
************************************/

//	initialization takes place immediately after all classes have ben configured for the given environment
VALUE rb_Rbdb_internal_classesWaitingForInitialization()	{
	
	VALUE	rb_init_classes_wait_list_array	=	rb_iv_get(	rb_mRbdb,
																											RBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY );
	if ( rb_init_classes_wait_list_array == Qnil )	{
		rb_init_classes_wait_list_array = rb_ary_new();
		rb_iv_set(	rb_mRbdb,
								RBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY,
								rb_init_classes_wait_list_array );
	}
	
	return rb_init_classes_wait_list_array;
}

/*********************************************
*  deleteFromCurrentWorkingEnvironmentStack  *
*********************************************/

VALUE rb_Rbdb_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																	VALUE	rb_environment )	{

	VALUE	rb_current_working_environment_stack	=	rb_Rbdb_internal_currentWorkingEnvironmentStack( rb_module_self );
	
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

VALUE rb_Rbdb_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self )	{
	
	VALUE	rb_stack_array	=	rb_iv_get(	rb_module_self,
																			RBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK );

	if ( rb_stack_array == Qnil )	{
		rb_stack_array	=	rb_ary_new();
		rb_iv_set(	rb_module_self,
								RBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK,
								rb_stack_array );
	}
	return rb_stack_array;
}

