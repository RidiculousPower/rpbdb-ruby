/*
 *		RPDB:RPDB_SettingsController:RPDB_MemoryPoolSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolSettingsController.h"

#include "rb_RPDB_Environment.h"

#include "rb_RPDB_SettingsController.h"

#include <rpdb/RPDB_SettingsController.h>

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolSettingsController.h>
#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;

void Init_RPDB_MemoryPoolSettingsController()	{

	rb_RPDB_MemoryPoolSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"MemoryPool",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolSettingsController, 	"new",																							rb_RPDB_MemoryPoolSettingsController_new,																						1 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"initialize",																				rb_RPDB_MemoryPoolSettingsController_init,																					1 	);
                            
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"parent_environment",																rb_RPDB_MemoryPoolSettingsController_parentEnvironment,															0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"environment",																			"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"on",																								rb_RPDB_MemoryPoolSettingsController_on,																						0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"off",																							rb_RPDB_MemoryPoolSettingsController_off,																						0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_on",																					rb_RPDB_MemoryPoolSettingsController_turnOn,																				0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_off",																					rb_RPDB_MemoryPoolSettingsController_turnOff,																				0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"memory_mapping?",																	rb_RPDB_MemoryPoolSettingsController_memoryMapping,																	0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"mapping?",																					"memory_mapping?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_memory_mapping_on",														rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOn,														0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_memory_mapping_off",													rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOff,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"do_not_write_to_temporary_backing_file?",					rb_RPDB_MemoryPoolSettingsController_doNotWriteToTemporaryBackingFile,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"no_temporary_backing_file?",												"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"no_temp_backing_file?",														"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"no_backing_file?",																	"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"no_temp_file?",																		"do_not_write_to_temporary_backing_file?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_do_not_write_to_temporary_backing_file_on",		rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOn,										0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temporary_backing_file_on",								"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temp_backing_file_on",											"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_backing_file_on",													"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temp_file_on",															"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_do_not_write_to_temporary_backing_file_off",	rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOff,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temporary_backing_file_off",								"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temp_backing_file_off",										"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_backing_file_off",													"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_no_temp_file_off",														"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"remove_file_with_last_reference?",									rb_RPDB_MemoryPoolSettingsController_removeFileWithLastReference,										0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_remove_file_with_last_reference_on",					rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOn,							0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_remove_file_with_last_reference_off",					rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOff,						0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"use_system_memory_for_storage?",										rb_RPDB_MemoryPoolSettingsController_useSystemMemoryForStorage,											0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"use_system_memory?",																"use_system_memory_for_storage?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"system_memory?",																		"use_system_memory_for_storage?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_use_system_memory_for_storage_on",						rb_RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOn,								0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_use_system_memory_on",												"turn_use_system_memory_for_storage_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_system_memory_on",														"turn_use_system_memory_for_storage_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_use_system_memory_for_storage_off",						rb_RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOff,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_use_system_memory_off",												"turn_use_system_memory_for_storage_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_system_memory_off",														"turn_use_system_memory_for_storage_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"application_has_exclusive_access?",								rb_RPDB_MemoryPoolSettingsController_applicationHasExclusiveAccess,									0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"exclusive_access?",																"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"exclusive?",																				"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"private_access?",																	"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"private?",																					"application_has_exclusive_access?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_has_exclusive_access_on",					rb_RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOn,						0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_exclusive_access_on",													"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_exclusive_on",																"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_private_access_on",														"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_private_on",																	"turn_application_has_exclusive_access_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_has_exclusive_access_off",				rb_RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOff,					0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_exclusive_access_off",												"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_exclusive_off",																"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_private_access_off",													"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_private_off",																	"turn_application_has_exclusive_access_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"database_allocates_memory_using_malloc?",					rb_RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingMalloc,						0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"database_uses_malloc?",														"database_allocates_memory_using_malloc?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"database_malloc?",																	"database_allocates_memory_using_malloc?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"malloc?",																					"database_allocates_memory_using_malloc?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_allocates_memory_using_malloc_on",		rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn,			0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_uses_malloc_on",											"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_malloc_on",													"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_malloc_on",																		"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_allocates_memory_using_malloc_off",	rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff,			0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_uses_malloc_off",										"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_malloc_off",													"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_malloc_off",																	"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"database_allocates_memory_using_realloc?",					rb_RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingRealloc,						0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"database_uses_realloc?",														"database_allocates_memory_using_realloc?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"database_realloc?",																"database_allocates_memory_using_realloc?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"realloc?",																					"database_allocates_memory_using_realloc?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_allocates_memory_using_realloc_on",	rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn,			0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_uses_realloc_on",										"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_realloc_on",													"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_realloc_on",																	"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_allocates_memory_using_realloc_off",	rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff,		0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_uses_realloc_off",										"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_realloc_off",												"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_realloc_off",																	"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"application_allocates_memory?",										rb_RPDB_MemoryPoolSettingsController_applicationAllocatesMemory,										0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"application_allocates?",														"application_allocates_memory?"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"application?",																			"application_allocates_memory?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_allocates_memory_on",							rb_RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOn,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_allocates_on",										"turn_application_allocates_memory_on"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_on",															"turn_application_allocates_memory_on"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_allocates_memory_off",						rb_RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOff,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_allocates_off",										"turn_application_allocates_memory_off"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_application_off",															"turn_application_allocates_memory_off"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"database_frees_memory?",														rb_RPDB_MemoryPoolSettingsController_databaseFreesMemory,														0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"database_frees?",																	"database_frees_memory?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_frees_memory_on",										rb_RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOn,											0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_database_frees_memory_off",										rb_RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOff,										0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"pagesize_factor_mismatch_should_fail?",						rb_RPDB_MemoryPoolSettingsController_pagesizeFactorMismatchShouldFail,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"pagesize_mismatch_should_fail?",										"pagesize_factor_mismatch_should_fail?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_factor_mismatch_should_fail_on",			rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOn,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_mismatch_should_fail_on",						"pagesize_factor_mismatch_should_fail?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_factor_mismatch_should_fail_off",		rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOff,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_mismatch_should_fail_off",						"pagesize_factor_mismatch_should_fail?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"file_settings_controller",													rb_RPDB_MemoryPoolSettingsController_fileSettingsController,												0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_MemoryPoolSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																								VALUE	rb_parent_settings_controller )	{

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller	=	RPDB_SettingsController_memoryPoolSettingsController( c_parent_settings_controller );

	VALUE	rb_memory_pool_settings_controller	=	RUBY_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_memory_pool_settings_controller );

	VALUE	argv[ 1 ];	
	argv[ 0 ]	=	rb_parent_settings_controller;
	rb_obj_call_init(	rb_memory_pool_settings_controller,
										1, 
										argv );
	
	return rb_memory_pool_settings_controller;		
}

/*********
*  init  *
*********/

VALUE rb_RPDB_MemoryPoolSettingsController_init(	VALUE	rb_memory_pool_settings_controller,
																									VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{
	
	return rb_memory_pool_settings_controller;
}


/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolSettingsController_parentEnvironment(	VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolSettingsController_parentEnvironment( c_memory_pool_settings_controller ) );
}

/*********
*  on  *
*********/

//	DB_INIT_MPOOL			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_MemoryPoolSettingsController_on( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_on( c_memory_pool_settings_controller )	?	Qtrue
																						:	Qfalse );
}

/*************
*  off  *
*************/

//	DB_INIT_MPOOL			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_MemoryPoolSettingsController_off( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_off( c_memory_pool_settings_controller )	?	Qtrue
																							:	Qfalse );
}

	/*************
	*  turnOn  *
	*************/

	//	DB_INIT_MPOOL			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*************
	*  turnOff  *
	*************/

	//	DB_INIT_MPOOL			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/*********************
*  memoryMapping  *
*********************/

//	DB_NOMMAP 				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
//	Note: function default inverts default from flag
VALUE rb_RPDB_MemoryPoolSettingsController_memoryMapping( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_memoryMapping( c_memory_pool_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/*****************************
	*  turnMemoryMappingOn  *
	*****************************/

	//	DB_NOMMAP 				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	//	Note: function default inverts default from flag
	VALUE rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnMemoryMappingOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*****************************
	*  turnMemoryMappingOff  *
	*****************************/

	//	DB_NOMMAP 				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	//	Note: function default inverts default from flag
	VALUE rb_RPDB_MemoryPoolSettingsController_turnMemoryMappingOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnMemoryMappingOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/*****************************************
*  doNotWriteToTemporaryBackingFile  *
*****************************************/

//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
VALUE rb_RPDB_MemoryPoolSettingsController_doNotWriteToTemporaryBackingFile( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_doNotWriteToTemporaryBackingFile( c_memory_pool_settings_controller )	?	Qtrue
																																																										:	Qfalse );
}

	/*********************************************
	*  turnDoNotWriteToTemporaryBackingFileOn  *
	*********************************************/

	//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	//	Note: method default inverts flag default
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*************************************************
	*  turnDoNotWriteToTemporaryBackingFileOff  *
	*************************************************/

	//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	//	Note: method default inverts flag default
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDoNotWriteToTemporaryBackingFileOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/*************************************
*  removeFileWithLastReference  *
*************************************/

//	DB_MPOOL_UNLINK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
VALUE rb_RPDB_MemoryPoolSettingsController_removeFileWithLastReference( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_removeFileWithLastReference( c_memory_pool_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/*****************************************
	*  turnRemoveFileWithLastReferenceOn  *
	*****************************************/

	//	DB_MPOOL_UNLINK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*****************************************
	*  turnRemoveFileWithLastReferenceOff  *
	*****************************************/

	//	DB_MPOOL_UNLINK			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/*********************************
*  useSystemMemoryForStorage  *
*********************************/

//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_MemoryPoolSettingsController_useSystemMemoryForStorage( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_useSystemMemoryForStorage( c_memory_pool_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*****************************************
	*  turnUseSystemMemoryForStorageOn  *
	*****************************************/

	//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*****************************************
	*  turnUseSystemMemoryForStorageOff  *
	*****************************************/

	//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnUseSystemMemoryForStorageOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/*************************************
*  applicationHasExclusiveAccess  *
*************************************/

//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_MemoryPoolSettingsController_applicationHasExclusiveAccess( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_applicationHasExclusiveAccess( c_memory_pool_settings_controller )	?	Qtrue
																																																								:	Qfalse );
}

	/*********************************************
	*  turnApplicationHasExclusiveAccessOn  *
	*********************************************/

	//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*********************************************
	*  turnApplicationHasExclusiveAccessOff  *
	*********************************************/

	//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnApplicationHasExclusiveAccessOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}
	
/*****************************************
*  databaseAllocatesMemoryUsingMalloc  *
*****************************************/

//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingMalloc( c_memory_pool_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOn  *
	*************************************************/

	//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOff  *
	*************************************************/

	//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/********************************************
*  databaseAllocatesMemoryUsingRealloc  *
********************************************/

//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_databaseAllocatesMemoryUsingRealloc( c_memory_pool_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/****************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOn  *
	****************************************************/

	//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/****************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOff  *
	****************************************************/

	//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/************************************
*  applicationAllocatesMemory  *
************************************/

//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_MemoryPoolSettingsController_applicationAllocatesMemory( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_applicationAllocatesMemory( c_memory_pool_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/****************************************
	*  turnApplicationAllocatesMemoryOn  *
	****************************************/

	//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/****************************************
	*  turnApplicationAllocatesMemoryOff  *
	****************************************/

	//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnApplicationAllocatesMemoryOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/******************************
*  databaseFreesMemory  *
******************************/

//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPDB_MemoryPoolSettingsController_databaseFreesMemory( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_databaseFreesMemory( c_memory_pool_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/**********************************
	*  turnDatabaseFreesMemoryOn  *
	**********************************/

	//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/**************************************
	*  turnDatabaseFreesMemoryOff  *
	**************************************/

	//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnDatabaseFreesMemoryOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

/******************************************
*  pagesizeFactorMismatchShouldFail  *
******************************************/

//	Attempts to open files which are not a multiple of the page size in length will fail, by default. 
//	If the DB_ODDFILESIZE flag is set, any partial page at the end of the file will be ignored and the open will proceed.
//	DB_ODDFILESIZE	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fopen.html
VALUE rb_RPDB_MemoryPoolSettingsController_pagesizeFactorMismatchShouldFail( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	return ( RPDB_MemoryPoolSettingsController_pagesizeFactorMismatchShouldFail( c_memory_pool_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/**************************************************
	*  turnPageSizeFactorMismatchShouldFailOn  *
	**************************************************/

	VALUE rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOn( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOn( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}

	/**************************************************
	*  turnPageSizeFactorMismatchShouldFailOff  *
	**************************************************/

	VALUE rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOff( VALUE	rb_memory_pool_settings_controller )	{

		RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
		C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

		RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOff( c_memory_pool_settings_controller );

		return rb_memory_pool_settings_controller;
	}


/**************************************************
*  fileSettingsController  *
**************************************************/

VALUE rb_RPDB_MemoryPoolSettingsController_fileSettingsController( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	RPDB_MemoryPoolSettingsController_fileSettingsController( c_memory_pool_settings_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( RPDB_MemoryPoolSettingsController_fileSettingsController( c_memory_pool_settings_controller ) );
}
