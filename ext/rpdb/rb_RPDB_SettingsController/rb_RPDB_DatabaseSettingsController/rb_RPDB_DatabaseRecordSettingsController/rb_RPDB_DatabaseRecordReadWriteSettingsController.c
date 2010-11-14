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
#include "rb_RPDB_DatabaseRecordSettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseRecordReadWriteSettingsController.h>
#include <rpdb/RPDB_DatabaseRecordSettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_Database.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;

void Init_RPDB_DatabaseRecordReadWriteSettingsController()	{

	rb_RPDB_DatabaseRecordReadWriteSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseRecordSettingsController, 
																																								"ReadWrite",	
																																								rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"new",																rb_RPDB_DatabaseRecordReadWriteSettingsController_new,							-1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"initialize",													rb_RPDB_DatabaseRecordReadWriteSettingsController_initialize,							-1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_environment",									rb_RPDB_DatabaseRecordReadWriteSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_database",										rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"database",														"parent_database"	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_settings_controller",			rb_RPDB_DatabaseRecordReadWriteSettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_database_settings_controller",			rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController,				0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"parent_database_record_settings_controller",			rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController,				0 	);

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
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"ignore_lease?",																	rb_RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease,													0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_on",													rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_off",												rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff,										0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"return_multiple?",															rb_RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple,												0 	);
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
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"with_sorted_duplicates",													"turn_sorted_duplicates_on" 	);                                                          				
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_sorted_duplicates_off",										rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates_off",												"turn_sorted_duplicates_off" 	);                                                          				
	rb_define_alias(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"without_sorted_duplicates",												"turn_sorted_duplicates_off" 	);                                                          				

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
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_data_buffer_size",																rb_RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize,															1 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_size",														rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize,													0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_size",												rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize,												1 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_offset",													rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_offset",											rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset,											1 	);

	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"serialize_data?",																		rb_RPDB_DatabaseRecordReadWriteSettingsController_serializeData,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_serialize_data_on",															rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOn,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordReadWriteSettingsController, 	"turn_serialize_data_off",														rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOff,											0 	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_new(	int			argc,
																															VALUE*	args,
																															VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_record																			=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_record_settings_controller					=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller, rb_RPDB_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_record, rb_RPDB_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller, rb_RPDB_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller, rb_RPDB_DatabaseRecordSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent database controller> ]",
			"[ <parent database> ]",
			"[ <parent record> ]",
			"[ <parent settings controller> ]",
			"[ <parent database settings controller> ]",
			"[ <parent database record settings controller> ]"
		)
	);

	//	if we were passed a database we want its settings controller
	//	if we were passed an environment or database controller or settings controller we want its database settings controller

	if (		rb_parent_database == Qnil
			&&	rb_parent_environment == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_database_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_RPDB_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_RPDB_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller	=	RPDB_DatabaseRecordSettingsController_readWriteSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_read_write_settings_controller	= RUBY_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( c_database_record_read_write_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_record_read_write_settings_controller,
							RPDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
							rb_parent_database_record_settings_controller );

	VALUE	argv[]	=	{ rb_parent_database_record_settings_controller };
	rb_obj_call_init(	rb_database_record_read_write_settings_controller,
										1, 
										argv );
	
	return rb_database_record_read_write_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabase(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_database												=	rb_RPDB_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_RPDB_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_RPDB_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_record_settings_controller  *
***********************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_read_write_settings_controller,
																																		RPDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/****************************
*  prohibit_sync_on_close?  *
****************************/

//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/***********************************
	*  turn_prohibit_sync_on_close_on  *
	***********************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/************************************
	*  turn_prohibit_sync_on_close_off  *
	************************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/******************
*  ignore_lease?  *
******************/

//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_ignoreLease( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );

}

	/**************************
	*  turn_ignore_lease_on?  *
	**************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/**************************
	*  turn_ignore_lease_off  *
	**************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}
		
/*********************
*  return_multiple?  *
*********************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_returnMultiple( c_database_record_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/****************************
	*  turn_return_multiple_on  *
	****************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	*  turn_return_multiple_off  *
	*****************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/*****************************
*  prohibit_duplicate_data?  *
*****************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Btree and Hash only
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitDuplicateData( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitDuplicateData( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/************************************
	*  turn_prohibit_duplicate_data_on  *
	************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*************************************
	*  turn_prohibit_duplicate_data_off  *
	*************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitDuplicateDataOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/************************
*  prohibit_overwrite?  *
************************/

//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*******************************
	*  turn_prohibit_overwrite_on  *
	*******************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	*  turn_prohibit_overwrite_off  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/******************************
*  prohibit_page_compaction?  *
******************************/

//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	Must be set for Hash
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return( RPDB_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turn_prohibit_page_compaction_on  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/**************************************
	*  turn_prohibit_page_compaction_off  *
	**************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  return_pages_to_filesystem?  *
********************************/

//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/***************************************
	*  turn_return_pages_to_filesystem_on  *
	***************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turn_return_pages_to_filesystem_off  *
	****************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		RPDB_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/***************************
*  truncate_file_on_open?  *
***************************/

//	DB_TRUNCATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/**********************************
	*  turn_truncate_file_on_open_on  *
	**********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/***********************************
	*  turn_truncate_file_on_open_off  *
	***********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/***************************************
*  write_locks_instead_of_read_locks?  *
***************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_record_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );

}

	/**********************************************
	*  turn_write_locks_instead_of_read_locks_on  *
	**********************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/***********************************************
	*  turn_write_locks_instead_of_read_locks_off  *
	***********************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}


/********************
*  partial_access?  *
********************/

//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialAccess( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_partialAccess( c_database_record_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/***************************
	*  turn_partial_access_on  *
	***************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************
	*  turn_partial_access_off  *
	****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************************
*  database_allocates_memory_using_malloc?  *
********************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( c_database_record_settings_controller )	?	Qtrue
																																:	Qfalse );
	
}

	/***************************************************
	*  turn_database_allocates_memory_using_malloc_on  *
	***************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/****************************************************
	*  turn_database_allocates_memory_using_malloc_off  *
	****************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

/*********************************************
*  database_allocates_memory_using_realloc?  *
*********************************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( c_database_record_settings_controller )	?	Qtrue
																																	:	Qfalse );	
}

	/****************************************************
	*  turn_database_allocates_memory_using_realloc_on  *
	****************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

	/*****************************************************
	*  turn_database_allocates_memory_using_realloc_off  *
	*****************************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/**********************************
*  application_allocates_memory?  *
**********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( c_database_record_settings_controller )	?	Qtrue
																														:	Qfalse );
	
}

	/*****************************************
	*  turn_application_allocates_memory_on  *
	*****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/******************************************
	*  turn_application_allocates_memory_off  *
	******************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/***************************
*  database_frees_memory?  *
***************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );
	
}

	/**********************************
	*  turn_database_frees_memory_on  *
	**********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/***********************************
	*  turn_database_frees_memory_off  *
	***********************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  sync_prior_to_write_return?  *
********************************/

//	DB_DSYNC_DB             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/***************************************
	*  turn_sync_prior_to_write_return_on  *
	***************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turn_sync_prior_to_write_return_off  *
	****************************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( VALUE	rb_database_record_read_write_settings_controller )	{

		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/***********************
*  unsorted_duplicates?  *
***********************/

//	DB_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( RPDB_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*******************************
	 *  turn_unsorted_duplicates_on  *
	 ******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	 *  turn_unsorted_duplicates_on  *
	 *******************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/*********************
*  sorted_duplicates?  *
*********************/

//	DB_DUPSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_sortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( RPDB_DatabaseRecordReadWriteSettingsController_sortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																																																																:	Qfalse );
}

	/*****************************
	 *  turn_sorted_duplicates_on  *
	 ****************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/******************************
	 *  turn_sorted_duplicates_off  *
	 *****************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		RPDB_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/********************
*  serialize_data?  *
********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_serializeData( VALUE	rb_database_record_read_write_settings_controller )	{
	
	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return rb_iv_get(	rb_database_record_read_write_settings_controller,
										RPDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA ) == Qtrue ? Qtrue
																																																												:	Qfalse;
}

	/****************************
	 *  turn_serialize_data_on  *
	 ***************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qtrue );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	 *  turn_serialize_data_off  *
	 ****************************/

	VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_turnSerializeDataOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qfalse );
		
		return rb_database_record_read_write_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
														Switch Settings
*******************************************************************************************************************************************************************************************/

/*********************
*  data_buffer_size  *
*********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_dataBufferSize( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_dataBufferSize( c_database_record_settings_controller ) );
}	

/*************************
*  set_data_buffer_size  *
*************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	VALUE	rb_database_record_read_write_settings_controller, 
																	VALUE	rb_buffer_size )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	c_database_record_settings_controller,
																FIX2INT( rb_buffer_size ) );
	
	return rb_database_record_read_write_settings_controller;
}	

/****************************
*  partial_read_write_size  *
****************************/

//	Returns size of partial write (if applicable)
//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records. 
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( c_database_record_settings_controller ) );
}	

/********************************
*  set_partial_read_write_size  *
********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_size )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	c_database_record_settings_controller,
																	FIX2INT( rb_partial_read_write_size ) );

	return rb_database_record_read_write_settings_controller;
}	

/******************************
*  partial_read_write_offset  *
******************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( c_database_record_settings_controller ) );
}	

/**********************************
*  set_partial_read_write_offset  *
**********************************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_offset )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	c_database_record_settings_controller,
	 																	FIX2INT( rb_partial_read_write_offset ) );

	return rb_database_record_read_write_settings_controller;
}

/*************
*  filename  *
*************/

//	In-memory databases never intended to be preserved on disk may be created by setting the file parameter to NULL.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_filename( VALUE	rb_database_record_read_write_settings_controller )	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return rb_str_new2( RPDB_DatabaseRecordReadWriteSettingsController_filename( c_database_record_read_write_settings_controller ) );
}

/*****************
*  set_filename  *
*****************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setFilename(	VALUE	rb_database_record_read_write_settings_controller,
																VALUE	rb_filename	)	{

	RPDB_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	RPDB_DatabaseRecordReadWriteSettingsController_setFilename(	c_database_record_read_write_settings_controller,
															StringValuePtr( rb_filename ) );
	
	return rb_database_record_read_write_settings_controller;
}


/*****************
*  storage_type  *
*****************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_storageType( VALUE rb_database_record_read_write_settings_controller )	{
	
	VALUE		rb_class_to_specify_type	=	rb_iv_get(	rb_database_record_read_write_settings_controller,
																									RPDB_RB_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE );
	
	return rb_class_to_specify_type;
}

/*********************
*  set_storage_type  *
*********************/

VALUE rb_RPDB_DatabaseRecordReadWriteSettingsController_setStorageType(	VALUE rb_database_record_read_write_settings_controller,
																																	VALUE	rb_class_to_specify_type )	{
	
	rb_iv_set(	rb_database_record_read_write_settings_controller,
							RPDB_RB_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE,
							rb_class_to_specify_type );
	
	return rb_database_record_read_write_settings_controller;
}


/*************************************
*  set_write_failed_callback_method  *
*************************************/
/*
VALUE rb_RPDB_MessageSettingsController_setWriteFailedCallbackMethod(	VALUE	rb_message_settings_controller,
 																	void *(write_failed_callback_method)( VALUE	environment ) )	{
	RPDB_MessageSettingsController_setWriteFailedCallbackMethod();
	

}
*/
/*********************************
*  write_failed_callback_method  *
*********************************/
/*
void *(write_failed_callback_method)( VALUE	environment ) RPDB_MessageSettingsController_writeFailedCallbackMethod(	VALUE	rb_message_settings_controller )	{
	
}
*/
