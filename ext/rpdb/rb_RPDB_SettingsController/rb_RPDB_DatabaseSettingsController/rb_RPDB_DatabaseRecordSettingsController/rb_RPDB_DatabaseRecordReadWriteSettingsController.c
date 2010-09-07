/*
*		RPDB::SettingsController::DatabaseSettingsController::DatabaseReadWriteSettingsController
*		RPDB::DatabaseController::Database::DatabaseSettingsController::DatabaseReadWriteSettingsController
*
*/

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseRecordReadWriteSettingsController.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordReadWriteSettingsController;

void Init_RPDB_DatabaseRecordReadWriteSettingsController()	{

	rb_RPDB_DatabaseRecordReadWriteSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																								"ReadWrite",	
																																								rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"new",																rb_RPDB_DatabaseRecordReadWriteSettingsController_new,							1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"initialize",													rb_RPDB_DatabaseRecordReadWriteSettingsController_init,							1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_environment",									rb_RPDB_DatabaseRecordReadWriteSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_database",										rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"database",														"parent_database"	);

	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"storage_type",												rb_RPDB_DatabaseRecordReadWriteSettingsController_storageType,															0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"storage_type=",											rb_RPDB_DatabaseRecordReadWriteSettingsController_setStorageType,														1 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_storage_type",										"storage_type=" 	);                                                          				

	//	FIX - this should take a file or a file name
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"filename",																			rb_RPDB_DatabaseRecordReadWriteSettingsController_filename,															0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"filename=",																		rb_RPDB_DatabaseRecordReadWriteSettingsController_setFilename,													1 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_filename",																	"filename=" 	);                                                          				
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"prohibit_sync_on_close?",											rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose,									0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_sync_on_close_on",								rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_sync_on_close_off",							rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff,						0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"ignoreLease?",																	rb_RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease,													0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_on",													rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_off",												rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff,										0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"returnMultiple?",															rb_RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_return_multiple_on",											rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_return_multiple_off",											rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff,								0 	);
                    					                                                                                            	                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"prohibit_duplicate_data?",											rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitDuplicateData,								0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_duplicate_data_on",							rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_duplicate_data_off",							rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOff,					0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"prohibit_overwrite?",													rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitOverwrite,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_overwrite_on",										rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_overwrite_off",									rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff,							0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"prohibit_page_compaction?",										rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction,								0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_page_compaction_on",							rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_page_compaction_off",						rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff,				0 	);
                    					                                                                                            	                                                                            			
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"return_pages_to_filesystem?",									rb_RPDB_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem,							0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_return_pages_to_filesystem_on",						rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_return_pages_to_filesystem_off",					rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff,				0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_access?",															rb_RPDB_DatabaseRecordReadWriteSettingsController_partialAccess,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_on",												rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_off",											rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff,									0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"truncate_file_on_open?",												rb_RPDB_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_truncate_file_on_open_on",								rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_truncate_file_on_open_off",								rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff,						0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"write_locks_instead_of_read_locks?",						rb_RPDB_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks,					0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_on",		rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn,		0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_off",		rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff,	0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates?",													rb_RPDB_DatabaseRecordReadWriteSettingsController_unsortedDuplicates,														0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_unsorted_duplicates_on",									rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn,											0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates_on",												"turn_unsorted_duplicates_on" 	);                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_unsorted_duplicates_off",									rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff,										0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates_off",											"turn_unsorted_duplicates_off" 	);                                                          				
	                  					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates?",														rb_RPDB_DatabaseRecordReadWriteSettingsController_sortedDuplicates,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_sorted_duplicates_on",										rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates_on",													"turn_sorted_duplicates_on" 	);                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_sorted_duplicates_off",										rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates_off",												"turn_sorted_duplicates_off" 	);                                                          				

	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"database_allocates_memory_using_malloc?",						rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_malloc_on",			rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_malloc_off",		rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"database_allocates_memory_using_realloc?",						rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_realloc_on",		rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_realloc_off",		rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff,		0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"application_allocates_memory?",											rb_RPDB_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_application_allocates_memory_on",								rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_application_allocates_memory_off",							rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff,							0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"database_frees_memory?",															rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseFreesMemory,														0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_frees_memory_on",											rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_database_frees_memory_off",											rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff,										0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_access?",																		rb_RPDB_DatabaseRecordReadWriteSettingsController_partialAccess,																	0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_on",															rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn,														0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_off",														rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff,													0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"sync_prior_to_write_return?",												rb_RPDB_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_sync_prior_to_write_return_on",									rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_sync_prior_to_write_return_off",								rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff,									0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"data_buffer_size",																		rb_RPDB_DatabaseRecordReadWriteSettingsController_dataBufferSize,																0 	);

	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"data_buffer_size=",																	rb_RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize,															0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_data_buffer_size",																rb_RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize,															0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_size",														rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize,													0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_size=",														rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_size",												rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize,												0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_offset",													rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_offset=",													rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_offset",											rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset,											0 	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	 c_parent_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_parent_database_record_settings_controller );

	VALUE	rb_database_record_read_write_settings_controller	= RUBY_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseRecordReadWriteSettingsController_new(  c_parent_database_record_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_record_settings_controller;
	
	rb_obj_call_init(	rb_database_record_read_write_settings_controller,
										1, 
										argv );
	
	return rb_database_record_read_write_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_init(	VALUE	rb_database_record_read_write_settings_controller,
																												VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_record_read_write_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseRecordReadWriteSettingsController_parentEnvironment( c_database_record_read_write_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabase(	VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseRecordReadWriteSettingsController_parentDatabase( c_database_record_read_write_settings_controller ) );

}

/*******************************************************************************************************************************************************************************************
																		File Settings
*******************************************************************************************************************************************************************************************/

/*****************
*  filename  *
*****************/

//	In-memory databases never intended to be preserved on disk may be created by setting the file parameter to NULL.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_filename( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return rb_str_new2( RPDB_DatabaseRecordReadWriteSettingsController_filename( c_database_record_read_write_settings_controller ) );
}

/*********************
*  setFilename  *
*********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setFilename(	VALUE	rb_database_record_read_write_settings_controller,
																VALUE	rb_filename	)	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setFilename(	c_database_record_read_write_settings_controller,
															StringValuePtr( rb_filename ) );
	
	return rb_database_record_read_write_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/****************************
*  prohibitSyncOnClose  *
****************************/

//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*********************************
	*  turnProhibitSyncOnCloseOn  *
	*********************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/************************************
	*  turnProhibitSyncOnCloseOff  *
	************************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************
*  ignoreLease  *
********************/

//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );

}

	/****************************
	*  turnIgnoreLeaseOn  *
	****************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************
	*  turnIgnoreLeaseOff  *
	****************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}
		
/**********************
*  returnMultiple  *
**********************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple( c_database_record_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/******************************
	*  turnReturnMultipleOn  *
	******************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/******************************
	*  turnReturnMultipleOff  *
	******************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/****************************
*  prohibitDuplicateData  *
****************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Btree and Hash only
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitDuplicateData( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitDuplicateData( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/*************************************
	*  turnProhibitDuplicateDataOn  *
	*************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/************************************
	*  turnProhibitDuplicateDataOff  *
	************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/*************************
*  prohibitOverwrite  *
*************************/

//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/********************************
	*  turnProhibitOverwriteOn  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	*  turnProhibitOverwriteOff  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  prohibitPageCompaction  *
********************************/

//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	Must be set for Hash
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return( RPDB_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turnProhibitPageCompactionOn  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*************************************
	*  turnProhibitPageCompactionOff  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  returnPagesToFilesystem  *
********************************/

//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turnReturnPagesToFilesystemOn  *
	*************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turnReturnPagesToFilesystemOff  *
	****************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/*****************************
*  truncateFileOnOpen  *
*****************************/

//	DB_TRUNCATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/************************************
	*  turnTruncateFileOnOpenOn  *
	************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*********************************
	*  turnTruncateFileOnOpenOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/************************************
*  writeLocksInsteadOfReadLocks  *
************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_record_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );

}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOn  *
	****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOff  *
	****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}


/*********************
*  partialAccess  *
*********************/

//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialAccess( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_partialAccess( c_database_record_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*****************************
	*  turnPartialAccessOn  *
	*****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	*  turnPartialAccessOff  *
	*****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/*****************************************
*  databaseAllocatesMemoryUsingMalloc  *
*****************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( c_database_record_settings_controller )	?	Qtrue
																																:	Qfalse );
	
}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOn  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOff  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

/*********************************************
*  databaseAllocatesMemoryUsingRealloc  *
*********************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( c_database_record_settings_controller )	?	Qtrue
																																	:	Qfalse );	
}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOn  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOff  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/*********************************
*  applicationAllocatesMemory  *
*********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( c_database_record_settings_controller )	?	Qtrue
																														:	Qfalse );
	
}

	/*****************************************
	*  turnApplicationAllocatesMemoryOn  *
	*****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/*****************************************
	*  turnApplicationAllocatesMemoryOff  *
	*****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/*****************************
*  databaseFreesMemory  *
*****************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );
	
}

	/*********************************
	*  turnDatabaseFreesMemoryOn  *
	*********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/*********************************
	*  turnDatabaseFreesMemoryOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/*****************************
*  syncPriorToWriteReturn  *
*****************************/

//	DB_DSYNC_DB             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/**************************************
	*  turnSyncPriorToWriteReturnOn  *
	**************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/************************************
	*  turnSyncPriorToWriteReturnOff  *
	************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/*********************
*  dataBufferSize  *
*********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_dataBufferSize( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_dataBufferSize( c_database_record_settings_controller ) );
}	

/*************************
*  setDataBufferSize  *
*************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	VALUE	rb_database_record_read_write_settings_controller, 
																	VALUE	rb_buffer_size )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	c_database_record_settings_controller,
																FIX2INT( rb_buffer_size ) );
	
	return rb_database_record_read_write_settings_controller;
}	

/*****************************
*  partialReadWriteSize  *
*****************************/

//	Returns size of partial write (if applicable)
//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records. 
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( c_database_record_settings_controller ) );
}	

/*********************************
*  setPartialReadWriteSize  *
*********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_size )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	c_database_record_settings_controller,
																	FIX2INT( rb_partial_read_write_size ) );

	return rb_database_record_read_write_settings_controller;
}	

/*****************************
*  partialReadWriteOffset  *
*****************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( c_database_record_settings_controller ) );
}	

/*********************************
*  setPartialReadWriteOffset  *
*********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_offset )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	c_database_record_settings_controller,
	 																	FIX2INT( rb_partial_read_write_offset ) );

	return rb_database_record_read_write_settings_controller;
}


/*******************************************************************************************************************************************************************************************
														Switch Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  permitDuplicates  *
*************************/

//	DB_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( RPDB_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*****************************
	 *  turnPermitDuplicatesOn  *
	 *****************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*********************************
	 *  turnPermitDuplicatesOff  *
	 *********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/**********************
*  sortDuplicates  *
**********************/

//	DB_DUPSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_sortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( RPDB_DatabaseRecordReadWriteSettingsController_sortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/******************************
	 *  turnSortDuplicatesOn  *
	 ******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/******************************
	 *  turnSortDuplicatesOff  *
	 ******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/**********************
*  serializeData  *
**********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_serializeData( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return rb_iv_get(	rb_database_record_read_write_settings_controller,
										RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA ) == Qtrue ? Qtrue
																																																												:	Qfalse;
}

	/******************************
	 *  turnSerializeDataOn  *
	 ******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qtrue );
		
		return rb_database_record_read_write_settings_controller;
	}

	/******************************
	 *  turnSerializeDataOff  *
	 ******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qfalse );
		
		return rb_database_record_read_write_settings_controller;
	}

/****************
*  storageType  *
****************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_storageType( VALUE rb_database_record_read_write_settings_controller )	{
	
	VALUE		rb_class_to_specify_type	=	rb_iv_get(	rb_database_record_read_write_settings_controller,
																									RPDB_RUBY_CLASS_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE );
	
	return rb_class_to_specify_type;
}

/*******************
*  setStorageType  *
*******************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setStorageType(	VALUE rb_database_record_read_write_settings_controller,
																																	VALUE	rb_class_to_specify_type )	{
	
	rb_iv_set(	rb_database_record_read_write_settings_controller,
							RPDB_RUBY_CLASS_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE,
							rb_class_to_specify_type );
	
	return rb_database_record_read_write_settings_controller;
}
