/*
*		Rbdb::SettingsController::DatabaseSettingsController::DatabaseReadWriteSettingsController
*		Rbdb::DatabaseController::Database::DatabaseSettingsController::DatabaseReadWriteSettingsController
*
*/

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseRecordReadWriteSettingsController.h"
#include "rb_Rbdb_DatabaseRecordSettingsController.h"
#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_Database_internal.h"
#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_DatabaseRecordReadWriteSettingsController.h>
#include <rbdb/Rbdb_DatabaseRecordSettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_Database.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_DatabaseRecordReadWriteSettingsController;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_DatabaseRecordSettingsController;

void Init_rb_Rbdb_DatabaseRecordReadWriteSettingsController()	{

	rb_Rbdb_DatabaseRecordReadWriteSettingsController		=	rb_define_class_under(	rb_Rbdb_DatabaseRecordSettingsController, 
																																								"ReadWrite",	
																																								rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"new",																rb_Rbdb_DatabaseRecordReadWriteSettingsController_new,							-1 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"initialize",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_initialize,							-1 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"parent_environment",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"parent_database",										rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabase,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"database",														"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"parent_settings_controller",			rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"parent_database_settings_controller",			rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"parent_database_record_settings_controller",			rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController,				0 	);

	//	FIX - this should take a file or a file name
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"filename",																			rb_Rbdb_DatabaseRecordReadWriteSettingsController_filename,															0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"filename=",																		rb_Rbdb_DatabaseRecordReadWriteSettingsController_setFilename,													1 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"set_filename",																	"filename=" 	);                                                          				
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"prohibit_sync_on_close?",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_sync_on_close_on",								rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_sync_on_close_off",							rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff,						0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"ignore_lease?",																	rb_Rbdb_DatabaseRecordReadWriteSettingsController_ignoreLease,													0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_on",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_ignore_lease_off",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff,										0 	);
                    					                                                                                    					                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"return_multiple?",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_returnMultiple,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_return_multiple_on",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_return_multiple_off",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff,								0 	);
                    					                                                                                            	                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"write_data_only_if_non_duplicate?",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_writeDataOnlyIfNonDuplicate,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_write_data_only_if_non_duplicate_on",							rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOn,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_write_data_only_if_non_duplicate_off",							rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOff,					0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"prohibit_overwrite?",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitOverwrite,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_overwrite_on",										rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_overwrite_off",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff,							0 	);
                    					                                                                                        			                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"prohibit_page_compaction?",										rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction,								0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_page_compaction_on",							rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_prohibit_page_compaction_off",						rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff,				0 	);
                    					                                                                                            	                                                                            			
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"return_pages_to_filesystem?",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_return_pages_to_filesystem_on",						rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn,				0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_return_pages_to_filesystem_off",					rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff,				0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"partial_access?",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialAccess,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_on",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_off",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff,									0 	);
                    					                                                                                                                                                                          			
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"truncate_file_on_open?",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_truncate_file_on_open_on",								rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_truncate_file_on_open_off",								rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff,						0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"write_locks_instead_of_read_locks?",						rb_Rbdb_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks,					0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_on",		rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn,		0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_write_locks_instead_of_read_locks_off",		rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff,	0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates?",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_unsortedDuplicates,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_unsorted_duplicates_on",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn,											0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates_on",												"turn_unsorted_duplicates_on" 	);                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_unsorted_duplicates_off",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff,										0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"unsorted_duplicates_off",											"turn_unsorted_duplicates_off" 	);                                                          				
	                  					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates?",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_sortedDuplicates,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_sorted_duplicates_on",										rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates_on",													"turn_sorted_duplicates_on" 	);                                                          				
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"with_sorted_duplicates",													"turn_sorted_duplicates_on" 	);                                                          				
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_sorted_duplicates_off",										rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"sorted_duplicates_off",												"turn_sorted_duplicates_off" 	);                                                          				
	rb_define_alias(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"without_sorted_duplicates",												"turn_sorted_duplicates_off" 	);                                                          				

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"duplicates?",																	rb_Rbdb_DatabaseRecordReadWriteSettingsController_duplicates,														0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"database_allocates_memory_using_malloc?",						rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_malloc_on",			rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_malloc_off",		rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff,			0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"database_allocates_memory_using_realloc?",						rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc,						0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_realloc_on",		rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn,			0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_allocates_memory_using_realloc_off",		rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff,		0 	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"application_allocates_memory?",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_application_allocates_memory_on",								rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn,							0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_application_allocates_memory_off",							rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff,							0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"database_frees_memory?",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseFreesMemory,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_frees_memory_on",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_database_frees_memory_off",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff,										0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"partial_access?",																		rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialAccess,																	0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_on",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_partial_access_off",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff,													0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"sync_prior_to_write_return?",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_sync_prior_to_write_return_on",									rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_sync_prior_to_write_return_off",								rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff,									0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"data_buffer_size",																		rb_Rbdb_DatabaseRecordReadWriteSettingsController_dataBufferSize,																0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"set_data_buffer_size",																rb_Rbdb_DatabaseRecordReadWriteSettingsController_setDataBufferSize,															1 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_size",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteSize,													0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_size",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize,												1 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"partial_read_write_offset",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"set_partial_read_write_offset",											rb_Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset,											1 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"serialize_data?",																		rb_Rbdb_DatabaseRecordReadWriteSettingsController_serializeData,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_serialize_data_on",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSerializeDataOn,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_serialize_data_off",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSerializeDataOff,											0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"store_key_typing?",																	rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeKeyTyping,															0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_key_typing_on",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOn,												1 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_key_typing_off",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOff,												0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"store_data_typing?",																	rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeDataTyping,															0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_data_typing_on",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOn,												1 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_data)typing_off",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOff,												0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"record_typing?",																			rb_Rbdb_DatabaseRecordReadWriteSettingsController_recordTyping,															0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_record_typing_on",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOn,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_record_typing_off",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOff,											0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"store_file_not_path?",																rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeFileNotPath,															0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_file_not_path_on",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOn,												0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_store_file_not_path_off",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOff,											0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"creation_stamp?",																		rb_Rbdb_DatabaseRecordReadWriteSettingsController_creationStamp,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_creation_stamp_on",															rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOn,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_creation_stamp_off",														rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOff,											0 	);

	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"modification_stamp?",																rb_Rbdb_DatabaseRecordReadWriteSettingsController_modificationStamp,														0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_modification_stamp_on",													rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOn,											0 	);
	rb_define_method(						rb_Rbdb_DatabaseRecordReadWriteSettingsController, 	"turn_modification_stamp_off",												rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOff,											0 	);
	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_new(	int			argc,
																															VALUE*	args,
																															VALUE		rb_klass_self )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_database_controller													=	Qnil;
	VALUE	rb_parent_database																		=	Qnil;
	VALUE	rb_parent_record																			=	Qnil;
	VALUE	rb_parent_database_settings_controller								=	Qnil;
	VALUE	rb_parent_database_record_settings_controller					=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment,														rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_database_controller,										rb_Rbdb_DatabaseController ),
																						R_MatchAncestorInstance( rb_parent_database,															rb_Rbdb_Database ),
																						R_MatchAncestorInstance( rb_parent_record,																rb_Rbdb_Record ),
																						R_MatchAncestorInstance( rb_parent_database_settings_controller,					rb_Rbdb_DatabaseSettingsController ),
																						R_MatchAncestorInstance( rb_parent_settings_controller,										rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_database_record_settings_controller,		rb_Rbdb_DatabaseRecordSettingsController ) ) ),
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
			&&	rb_parent_database_settings_controller == Qnil
			&&	rb_parent_database_record_settings_controller == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	if ( rb_parent_database_controller != Qnil ) {
		rb_parent_environment	=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );			
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_SettingsController_databaseSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_database != Qnil )	{
		rb_parent_database_settings_controller	=	rb_Rbdb_Database_settingsController( rb_parent_database );
	}
	if ( rb_parent_database_settings_controller != Qnil )	{
		rb_parent_database_record_settings_controller	=	rb_Rbdb_DatabaseSettingsController_recordSettingsController( rb_parent_database_settings_controller );
	}

	Rbdb_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_parent_database_record_settings_controller, c_database_record_settings_controller );		

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller	=	Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( c_database_record_settings_controller );

	VALUE	rb_database_record_read_write_settings_controller	= RUBY_RBDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( c_database_record_read_write_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_database_record_read_write_settings_controller,
							RBDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER,
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

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_DatabaseSettingsController_parentEnvironment( rb_parent_database_settings_controller );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabase(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_database												=	rb_Rbdb_DatabaseSettingsController_parentDatabase( rb_parent_database_settings_controller );
	
	return rb_parent_database;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_settings_controller		=	rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_DatabaseSettingsController_parentSettingsController( rb_parent_database_settings_controller );
	
	return rb_parent_settings_controller;
}

/****************************************
*  parent_database_settings_controller  *
****************************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller		=	rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController( rb_database_record_read_write_settings_controller );
	VALUE	rb_parent_database_settings_controller					=	rb_Rbdb_DatabaseRecordSettingsController_parentDatabaseSettingsController( rb_parent_database_record_settings_controller );
	
	return rb_parent_database_settings_controller;
}

/***********************************************
*  parent_database_record_settings_controller  *
***********************************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_parentDatabaseRecordSettingsController(	VALUE	rb_database_record_read_write_settings_controller )	{

	VALUE	rb_parent_database_record_settings_controller	=	rb_iv_get(	rb_database_record_read_write_settings_controller,
																																		RBDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER );

	return rb_parent_database_record_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Switch Settings
*******************************************************************************************************************************************************************************************/

/****************************
*  prohibit_sync_on_close?  *
****************************/

//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_prohibitSyncOnClose( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/***********************************
	*  turn_prohibit_sync_on_close_on  *
	***********************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/************************************
	*  turn_prohibit_sync_on_close_off  *
	************************************/

	//	DB_NOSYNC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitSyncOnCloseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/******************
*  ignore_lease?  *
******************/

//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_ignoreLease( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_ignoreLease( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );

}

	/**************************
	*  turn_ignore_lease_on?  *
	**************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/**************************
	*  turn_ignore_lease_off  *
	**************************/

	//	DB_IGNORE_LEASE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnIgnoreLeaseOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}
		
/*********************
*  return_multiple?  *
*********************/

//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_returnMultiple( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_returnMultiple( c_database_record_read_write_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/****************************
	*  turn_return_multiple_on  *
	****************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	*  turn_return_multiple_off  *
	*****************************/

	//	DB_MULTIPLE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnMultipleOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/*****************************
*  write_data_only_if_non_duplicate?  *
*****************************/

//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Btree and Hash only
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_writeDataOnlyIfNonDuplicate( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_writeDataOnlyIfNonDuplicate( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/************************************
	*  turn_write_data_only_if_non_duplicate_on  *
	************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/*************************************
	*  turn_write_data_only_if_non_duplicate_off  *
	*************************************/

	//	DB_NODUPDATA			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	//	Btree and Hash only
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteDataOnlyIfNonDuplicateOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/************************
*  prohibit_overwrite?  *
************************/

//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_prohibitOverwrite( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/*******************************
	*  turn_prohibit_overwrite_on  *
	*******************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	*  turn_prohibit_overwrite_off  *
	********************************/

	//	DB_NOOVERWRITE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitOverwriteOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/******************************
*  prohibit_page_compaction?  *
******************************/

//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
//	Must be set for Hash
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return( Rbdb_DatabaseRecordReadWriteSettingsController_prohibitPageCompaction( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/*************************************
	*  turn_prohibit_page_compaction_on  *
	*************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/**************************************
	*  turn_prohibit_page_compaction_off  *
	**************************************/

	//	DB_FREELIST_ONLY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
	//	Must be set for Hash
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnProhibitPageCompactionOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  return_pages_to_filesystem?  *
********************************/

//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_returnPagesToFilesystem( c_database_record_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );

}

	/***************************************
	*  turn_return_pages_to_filesystem_on  *
	***************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turn_return_pages_to_filesystem_off  *
	****************************************/

	//	DB_FREE_SPACE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		Rbdb_DatabaseRecordReadWriteSettingsController_turnReturnPagesToFilesystemOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/***************************
*  truncate_file_on_open?  *
***************************/

//	DB_TRUNCATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_truncateFileOnOpen( c_database_record_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );

}

	/**********************************
	*  turn_truncate_file_on_open_on  *
	**********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/***********************************
	*  turn_truncate_file_on_open_off  *
	***********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnTruncateFileOnOpenOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/***************************************
*  write_locks_instead_of_read_locks?  *
***************************************/

//	DB_RMW					http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_writeLocksInsteadOfReadLocks( c_database_record_read_write_settings_controller )	?	Qtrue
																																	:	Qfalse );

}

	/**********************************************
	*  turn_write_locks_instead_of_read_locks_on  *
	**********************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/***********************************************
	*  turn_write_locks_instead_of_read_locks_off  *
	***********************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}


/********************
*  partial_access?  *
********************/

//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialAccess( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	BOOL	c_partial_access	=	Rbdb_DatabaseRecordReadWriteSettingsController_partialAccess( c_database_record_read_write_settings_controller );
	VALUE	rb_partial_access	=	( c_partial_access ? Qtrue : Qfalse );

	return rb_partial_access;
}

	/***************************
	*  turn_partial_access_on  *
	***************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOn( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************
	*  turn_partial_access_off  *
	****************************/

	//	DB_DBT_PARTIAL		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnPartialAccessOff( c_database_record_read_write_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/********************************************
*  database_allocates_memory_using_malloc?  *
********************************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( c_database_record_settings_controller )	?	Qtrue
																																:	Qfalse );
	
}

	/***************************************************
	*  turn_database_allocates_memory_using_malloc_on  *
	***************************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/****************************************************
	*  turn_database_allocates_memory_using_malloc_off  *
	****************************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

/*********************************************
*  database_allocates_memory_using_realloc?  *
*********************************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	BOOL	c_database_allocates_memory_using_realloc		=	Rbdb_DatabaseRecordReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( c_database_record_settings_controller );
	VALUE	rb_database_allocates_memory_using_realloc	=	( c_database_allocates_memory_using_realloc ? Qtrue : Qfalse );

	return rb_database_allocates_memory_using_realloc;
}

	/****************************************************
	*  turn_database_allocates_memory_using_realloc_on  *
	****************************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );	

		return rb_database_record_read_write_settings_controller;
	}

	/*****************************************************
	*  turn_database_allocates_memory_using_realloc_off  *
	*****************************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/**********************************
*  application_allocates_memory?  *
**********************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_applicationAllocatesMemory( c_database_record_settings_controller )	?	Qtrue
																														:	Qfalse );
	
}

	/*****************************************
	*  turn_application_allocates_memory_on  *
	*****************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/******************************************
	*  turn_application_allocates_memory_off  *
	******************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnApplicationAllocatesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/***************************
*  database_frees_memory?  *
***************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_databaseFreesMemory( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );
	
}

	/**********************************
	*  turn_database_frees_memory_on  *
	**********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

	/***********************************
	*  turn_database_frees_memory_off  *
	***********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnDatabaseFreesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_read_write_settings_controller;
	}

/********************************
*  sync_prior_to_write_return?  *
********************************/

//	DB_DSYNC_DB             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return ( Rbdb_DatabaseRecordReadWriteSettingsController_syncPriorToWriteReturn( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/***************************************
	*  turn_sync_prior_to_write_return_on  *
	***************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOn( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

	/****************************************
	*  turn_sync_prior_to_write_return_off  *
	****************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( VALUE	rb_database_record_read_write_settings_controller )	{

		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

		Rbdb_DatabaseRecordReadWriteSettingsController_turnSyncPriorToWriteReturnOff( c_database_record_settings_controller );

		return rb_database_record_read_write_settings_controller;
	}

/***********************
*  unsorted_duplicates?  *
***********************/

//	DB_DUP				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_unsortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*******************************
	 *  turn_unsorted_duplicates_on  *
	 ******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	 *  turn_unsorted_duplicates_off  *
	 *******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnUnsortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/*********************
*  sorted_duplicates?  *
*********************/

//	DB_DUPSORT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_flags.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_sortedDuplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_sortedDuplicates( c_database_record_read_write_settings_controller )	?	Qtrue
																																																																:	Qfalse );
}

	/*****************************
	 *  turn_sorted_duplicates_on  *
	 ****************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/******************************
	 *  turn_sorted_duplicates_off  *
	 *****************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnSortedDuplicatesOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/****************
*  duplicates?  *
****************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_duplicates( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	VALUE	rb_has_duplicates	=	Qfalse;
	
	if ( Rbdb_DatabaseRecordReadWriteSettingsController_duplicates( c_database_record_read_write_settings_controller ) ) {
		rb_has_duplicates = Qtrue;
	}
	
	return rb_has_duplicates;
}

/********************
*  serialize_data?  *
********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_serializeData( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	VALUE	rb_should_serialize	=	rb_iv_get(	rb_database_record_read_write_settings_controller,
																					RBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA );
	
	if ( rb_should_serialize == Qnil )	{
		rb_should_serialize = Qfalse;
	}
	return rb_should_serialize;
}

	/****************************
	 *  turn_serialize_data_on  *
	 ***************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSerializeDataOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qtrue );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	 *  turn_serialize_data_off  *
	 ****************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnSerializeDataOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		rb_iv_set(	rb_database_record_read_write_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA,
								Qfalse );
		
		return rb_database_record_read_write_settings_controller;
	}

/**********************
*  store_key_typing?  *
**********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeKeyTyping( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_storeKeyTyping( c_database_record_read_write_settings_controller )	?	Qtrue
																																																													:	Qfalse );
}

	/******************************
	 *  turn_store_key_typing_on  *
	 *****************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOn(	VALUE	rb_database_record_read_write_settings_controller,
																																								VALUE	rb_record_storage_class )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordStorageType	c_record_storage_type	=	rb_Rbdb_Database_internal_storageTypeForRubyClass( rb_record_storage_class );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOn(	c_database_record_read_write_settings_controller,
																																					c_record_storage_type );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*******************************
	 *  turn_store_key_typing_off  *
	 ******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreKeyTypingOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/***********************
*  store_data_typing?  *
***********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeDataTyping( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_storeDataTyping( c_database_record_read_write_settings_controller )	?	Qtrue
																																																															:	Qfalse );
}

	/*******************************
	 *  turn_store_data_typing_on  *
	 ******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOn(	VALUE	rb_database_record_read_write_settings_controller,
																																									VALUE	rb_record_storage_class )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordStorageType	c_record_storage_type	=	rb_Rbdb_Database_internal_storageTypeForRubyClass( rb_record_storage_class );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOn( c_database_record_read_write_settings_controller,
																																					c_record_storage_type );
		
		return rb_database_record_read_write_settings_controller;
	}

	/********************************
	 *  turn_store_data_typing_off  *
	 *******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreDataTypingOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/********************
*  record_typing?  *
********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_recordTyping( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_recordTyping( c_database_record_read_write_settings_controller )	?	Qtrue
																																																														:	Qfalse );
}

	/****************************
	 *  turn_record_typing_on  *
	 ***************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*****************************
	 *  turn_record_typing_off  *
	 ****************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnRecordTypingOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/************************
*  creation_timestamp?  *
************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_creationStamp( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_creationStamp( c_database_record_read_write_settings_controller )	?	Qtrue
																																																																:	Qfalse );
}

	/********************************
	 *  turn_creation_timestamp_on  *
	 *******************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*********************************
	 *  turn_creation_timestamp_off  *
	 ********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnCreationStampOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/****************************
*  modification_timestamp?  *
****************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_modificationStamp( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_modificationStamp( c_database_record_read_write_settings_controller )	?	Qtrue
																																																																		:	Qfalse );
}

	/************************************
	 *  turn_modification_timestamp_on  *
	 ***********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/*************************************
	 *  turn_modification_timestamp_off  *
	 ************************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnModificationStampOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

/*************************
*  store_file_not_path?  *
*************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_storeFileNotPath( VALUE	rb_database_record_read_write_settings_controller )	{
	
	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
	
	return ( Rbdb_DatabaseRecordReadWriteSettingsController_storeFileNotPath( c_database_record_read_write_settings_controller )	?	Qtrue
																																																																:	Qfalse );
}

	/*********************************
	 *  turn_store_file_not_path_on  *
	 ********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOn( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOn( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

	/**********************************
	 *  turn_store_file_not_path_off  *
	 *********************************/

	VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOff( VALUE	rb_database_record_read_write_settings_controller )	{
		
		Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
		C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );
		
		Rbdb_DatabaseRecordReadWriteSettingsController_turnStoreFileNotPathOff( c_database_record_read_write_settings_controller );
		
		return rb_database_record_read_write_settings_controller;
	}

		
	
/*******************************************************************************************************************************************************************************************
														Switch Settings
*******************************************************************************************************************************************************************************************/

/*********************
*  data_buffer_size  *
*********************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_dataBufferSize( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( Rbdb_DatabaseRecordReadWriteSettingsController_dataBufferSize( c_database_record_settings_controller ) );
}	

/*************************
*  set_data_buffer_size  *
*************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	VALUE	rb_database_record_read_write_settings_controller, 
																	VALUE	rb_buffer_size )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	Rbdb_DatabaseRecordReadWriteSettingsController_setDataBufferSize(	c_database_record_settings_controller,
																FIX2INT( rb_buffer_size ) );
	
	return rb_database_record_read_write_settings_controller;
}	

/****************************
*  partial_read_write_size  *
****************************/

//	Returns size of partial write (if applicable)
//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records. 
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteSize( c_database_record_settings_controller ) );
}	

/********************************
*  set_partial_read_write_size  *
********************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_size )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteSize(	c_database_record_settings_controller,
																	FIX2INT( rb_partial_read_write_size ) );

	return rb_database_record_read_write_settings_controller;
}	

/******************************
*  partial_read_write_offset  *
******************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	return INT2FIX( Rbdb_DatabaseRecordReadWriteSettingsController_partialReadWriteOffset( c_database_record_settings_controller ) );
}	

/**********************************
*  set_partial_read_write_offset  *
**********************************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	VALUE	rb_database_record_read_write_settings_controller, 
																			VALUE	rb_partial_read_write_offset )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_settings_controller );

	Rbdb_DatabaseRecordReadWriteSettingsController_setPartialReadWriteOffset(	c_database_record_settings_controller,
	 																	FIX2INT( rb_partial_read_write_offset ) );

	return rb_database_record_read_write_settings_controller;
}

/*************
*  filename  *
*************/

//	In-memory databases never intended to be preserved on disk may be created by setting the file parameter to NULL.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_filename( VALUE	rb_database_record_read_write_settings_controller )	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	return rb_str_new2( Rbdb_DatabaseRecordReadWriteSettingsController_filename( c_database_record_read_write_settings_controller ) );
}

/*****************
*  set_filename  *
*****************/

VALUE rb_Rbdb_DatabaseRecordReadWriteSettingsController_setFilename(	VALUE	rb_database_record_read_write_settings_controller,
																VALUE	rb_filename	)	{

	Rbdb_DatabaseRecordReadWriteSettingsController*	c_database_record_read_write_settings_controller;
	C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller );

	Rbdb_DatabaseRecordReadWriteSettingsController_setFilename(	c_database_record_read_write_settings_controller,
															StringValuePtr( rb_filename ) );
	
	return rb_database_record_read_write_settings_controller;
}



/*************************************
*  set_write_failed_callback_method  *
*************************************/
/*
VALUE rb_Rbdb_MessageSettingsController_setWriteFailedCallbackMethod(	VALUE	rb_message_settings_controller,
 																	void *(write_failed_callback_method)( VALUE	environment ) )	{
	Rbdb_MessageSettingsController_setWriteFailedCallbackMethod();
	

}
*/
/*********************************
*  write_failed_callback_method  *
*********************************/
/*
void *(write_failed_callback_method)( VALUE	environment ) Rbdb_MessageSettingsController_writeFailedCallbackMethod(	VALUE	rb_message_settings_controller )	{
	
}
*/
