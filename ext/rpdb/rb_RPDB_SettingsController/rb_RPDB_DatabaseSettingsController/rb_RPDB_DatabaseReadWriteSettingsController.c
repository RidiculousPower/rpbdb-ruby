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

#include "rb_RPDB_DatabaseReadWriteSettingsController.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseReadWriteSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseReadWriteSettingsController;

void Init_RPDB_DatabaseReadWriteSettingsController()	{

	rb_RPDB_DatabaseReadWriteSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 
																																					"ReadWrite",	
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseReadWriteSettingsController, 	"new",																rb_RPDB_DatabaseReadWriteSettingsController_new,							1 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"initialize",													rb_RPDB_DatabaseReadWriteSettingsController_init,							1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"parent_environment",									rb_RPDB_DatabaseReadWriteSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseReadWriteSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"parent_database",										rb_RPDB_DatabaseReadWriteSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseReadWriteSettingsController, 	"database",														"parent_database"	);

	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"storage_type",												rb_RPDB_DatabaseReadWriteSettingsController_storageType,															0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"storage_type=",											rb_RPDB_DatabaseReadWriteSettingsController_setStorageType,														1 	);
	rb_define_alias(						rb_RPDB_DatabaseReadWriteSettingsController, 	"set_storage_type",										"storage_type=" 	);                                                          				

	//	FIX - this should take a file or a file name
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"filename",																			rb_RPDB_DatabaseReadWriteSettingsController_filename,															0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"filename=",																		rb_RPDB_DatabaseReadWriteSettingsController_setFilename,													1 	);
	rb_define_alias(						rb_RPDB_DatabaseReadWriteSettingsController, 	"set_filename",																	"filename=" 	);                                                          				
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"prohibit_sync_on_close?",											rb_RPDB_DatabaseReadWriteSettingsController_prohibitSyncOnClose,									0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_sync_on_close_on",								rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOn,						0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_sync_on_close_off",							rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOff,						0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"ignoreLease?",																	rb_RPDB_DatabaseReadWriteSettingsController_ignoreLease,													0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_ignore_lease_on",													rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOn,										0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_ignore_lease_off",												rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOff,										0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"returnMultiple?",															rb_RPDB_DatabaseReadWriteSettingsController_returnMultiple,												0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_return_multiple_on",											rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_return_multiple_off",											rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOff,								0 	);
                    					                                                                                            	                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"prohibit_duplicate_data?",											rb_RPDB_DatabaseReadWriteSettingsController_prohibitDuplicateData,								0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_duplicate_data_on",							rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_duplicate_data_off",							rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOff,					0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"prohibit_overwrite?",													rb_RPDB_DatabaseReadWriteSettingsController_prohibitOverwrite,										0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_overwrite_on",										rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_overwrite_off",									rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOff,							0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"prohibit_page_compaction?",										rb_RPDB_DatabaseReadWriteSettingsController_prohibitPageCompaction,								0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_page_compaction_on",							rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOn,					0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_prohibit_page_compaction_off",						rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOff,				0 	);
                    					                                                                                            	                                                                            			
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"return_pages_to_filesystem?",									rb_RPDB_DatabaseReadWriteSettingsController_returnPagesToFilesystem,							0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_return_pages_to_filesystem_on",						rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOn,				0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_return_pages_to_filesystem_off",					rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOff,				0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"partial_access?",															rb_RPDB_DatabaseReadWriteSettingsController_partialAccess,												0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_partial_access_on",												rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_partial_access_off",											rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOff,									0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"truncate_file_on_open?",												rb_RPDB_DatabaseReadWriteSettingsController_truncateFileOnOpen,										0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_truncate_file_on_open_on",								rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_truncate_file_on_open_off",								rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOff,						0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"write_locks_instead_of_read_locks?",						rb_RPDB_DatabaseReadWriteSettingsController_writeLocksInsteadOfReadLocks,					0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_on",		rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn,		0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_off",		rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff,	0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"duplicates?",																	rb_RPDB_DatabaseReadWriteSettingsController_duplicates,														0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_duplicates_on",														rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOn,											0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_duplicates_off",													rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOff,										0 	);
	                  					
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"sorted_duplicates?",														rb_RPDB_DatabaseReadWriteSettingsController_sortedDuplicates,											0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_sorted_duplicates_on",										rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOn,								0 	);
	rb_define_method(						rb_RPDB_DatabaseReadWriteSettingsController, 	"turn_sorted_duplicates_off",										rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOff,							0 	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_read_write_settings_controller	= RUBY_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( RPDB_DatabaseReadWriteSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_read_write_settings_controller,
										1, 
										argv );
	
	return rb_database_read_write_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_init(	VALUE	rb_database_read_write_settings_controller,
																												VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_read_write_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseReadWriteSettingsController_parentEnvironment( c_database_read_write_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseReadWriteSettingsController_parentDatabase(	VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseReadWriteSettingsController_parentDatabase( c_database_read_write_settings_controller ) );

}

/*******************************************************************************************************************************************************************************************
																		File Settings
*******************************************************************************************************************************************************************************************/

/*****************
*  filename  *
*****************/

//	In-memory databases never intended to be preserved on disk may be created by setting the file parameter to NULL.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_filename( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return rb_str_new2( RPDB_DatabaseReadWriteSettingsController_filename( c_database_read_write_settings_controller ) );
}

/*********************
*  setFilename  *
*********************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_setFilename(	VALUE	rb_database_read_write_settings_controller,
																VALUE	rb_filename	)	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	RPDB_DatabaseReadWriteSettingsController_setFilename(	c_database_read_write_settings_controller,
															StringValuePtr( rb_filename ) );
	
	return rb_database_read_write_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/****************************
*  prohibitSyncOnClose  *
****************************/

//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitSyncOnClose( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_prohibitSyncOnClose( c_database_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*********************************
	*  turnProhibitSyncOnCloseOn  *
	*********************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/************************************
	*  turnProhibitSyncOnCloseOff  *
	************************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/********************
*  ignoreLease  *
********************/

//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_ignoreLease( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_ignoreLease( c_database_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );

}

	/****************************
	*  turnIgnoreLeaseOn  *
	****************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/****************************
	*  turnIgnoreLeaseOff  *
	****************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}
		
/**********************
*  returnMultiple  *
**********************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_returnMultiple( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_returnMultiple( c_database_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/******************************
	*  turnReturnMultipleOn  *
	******************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/******************************
	*  turnReturnMultipleOff  *
	******************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/****************************
*  prohibitDuplicateData  *
****************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Btree and Hash only
VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitDuplicateData( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_prohibitDuplicateData( c_database_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/*************************************
	*  turnProhibitDuplicateDataOn  *
	*************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/************************************
	*  turnProhibitDuplicateDataOff  *
	************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/*************************
*  prohibitOverwrite  *
*************************/

//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitOverwrite( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_prohibitOverwrite( c_database_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/********************************
	*  turnProhibitOverwriteOn  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/********************************
	*  turnProhibitOverwriteOff  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/********************************
*  prohibitPageCompaction  *
********************************/

//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	Must be set for Hash
VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitPageCompaction( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return( RPDB_DatabaseReadWriteSettingsController_prohibitPageCompaction( c_database_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turnProhibitPageCompactionOn  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/*************************************
	*  turnProhibitPageCompactionOff  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/********************************
*  returnPagesToFilesystem  *
********************************/

//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_returnPagesToFilesystem( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_returnPagesToFilesystem( c_database_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turnReturnPagesToFilesystemOn  *
	*************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/****************************************
	*  turnReturnPagesToFilesystemOff  *
	****************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOff( c_database_read_write_settings_controller );
		
		return rb_database_read_write_settings_controller;
	}

/*********************
*  partialAccess  *
*********************/

//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_partialAccess( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_partialAccess( c_database_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*****************************
	*  turnPartialAccessOn  *
	*****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/*****************************
	*  turnPartialAccessOff  *
	*****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/*****************************
*  truncateFileOnOpen  *
*****************************/

//	DB_TRUNCATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_truncateFileOnOpen( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_truncateFileOnOpen( c_database_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/************************************
	*  turnTruncateFileOnOpenOn  *
	************************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/*********************************
	*  turnTruncateFileOnOpenOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/************************************
*  writeLocksInsteadOfReadLocks  *
************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_read_write_settings_controller )	{

	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

	return ( RPDB_DatabaseReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );

}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOn  *
	****************************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

	/****************************************
	*  turnWriteLocksInsteadOfReadLocksOff  *
	****************************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_read_write_settings_controller )	{

		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );

		RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_read_write_settings_controller );

		return rb_database_read_write_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
														Switch Settings
*******************************************************************************************************************************************************************************************/

/*************************
*  permitDuplicates  *
*************************/

//	DB_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_duplicates( VALUE	rb_database_read_write_settings_controller )	{
	
	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
	
	return ( RPDB_DatabaseReadWriteSettingsController_duplicates( c_database_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*****************************
	 *  turnPermitDuplicatesOn  *
	 *****************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOn( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOn( c_database_read_write_settings_controller );
		
		return rb_database_read_write_settings_controller;
	}

	/*********************************
	 *  turnPermitDuplicatesOff  *
	 *********************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOff( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOff( c_database_read_write_settings_controller );
		
		return rb_database_read_write_settings_controller;
	}

/**********************
*  sortDuplicates  *
**********************/

//	DB_DUPSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseReadWriteSettingsController_sortedDuplicates( VALUE	rb_database_read_write_settings_controller )	{
	
	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
	
	return ( RPDB_DatabaseReadWriteSettingsController_sortedDuplicates( c_database_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/******************************
	 *  turnSortDuplicatesOn  *
	 ******************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOn( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOn( c_database_read_write_settings_controller );
		
		return rb_database_read_write_settings_controller;
	}

	/******************************
	 *  turnSortDuplicatesOff  *
	 ******************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOff( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOff( c_database_read_write_settings_controller );
		
		return rb_database_read_write_settings_controller;
	}

/**********************
*  serializeData  *
**********************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_serializeData( VALUE	rb_database_read_write_settings_controller )	{
	
	RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
	C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
	
	return rb_iv_get(	rb_database_read_write_settings_controller,
										RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA ) == Qtrue ? Qtrue
																																																												:	Qfalse;
}

	/******************************
	 *  turnSerializeDataOn  *
	 ******************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSerializeDataOn( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		rb_iv_set(	rb_database_read_write_settings_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qtrue );
		
		return rb_database_read_write_settings_controller;
	}

	/******************************
	 *  turnSerializeDataOff  *
	 ******************************/

	VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSerializeDataOff( VALUE	rb_database_read_write_settings_controller )	{
		
		RPDB_DatabaseReadWriteSettingsController*	c_database_read_write_settings_controller;
		C_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( rb_database_read_write_settings_controller, c_database_read_write_settings_controller );
		
		rb_iv_set(	rb_database_read_write_settings_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qfalse );
		
		return rb_database_read_write_settings_controller;
	}

/****************
*  storageType  *
****************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_storageType( VALUE rb_database_read_write_settings_controller )	{
	
	VALUE		rb_class_to_specify_type	=	rb_iv_get(	rb_database_read_write_settings_controller,
																									RPDB_RUBY_CLASS_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE );
	
	return rb_class_to_specify_type;
}

/*******************
*  setStorageType  *
*******************/

VALUE rb_RPDB_DatabaseReadWriteSettingsController_setStorageType(	VALUE rb_database_read_write_settings_controller,
																																	VALUE	rb_class_to_specify_type )	{
	
	rb_iv_set(	rb_database_read_write_settings_controller,
							RPDB_RUBY_CLASS_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE,
							rb_class_to_specify_type );
	
	return rb_database_read_write_settings_controller;
}
