/*
 *		RPbdb::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MemoryPoolReadWriteSettingsController.h"
#include "MemoryPoolSettingsController.h"
#include "SettingsController.h"

#include "Environment.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MemoryPoolReadWriteSettingsController.h>
#include <rpbdb/MemoryPoolSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_MemoryPoolSettingsController;
extern	VALUE	rb_RPbdb_MemoryPoolReadWriteSettingsController;

void Init_rb_RPbdb_MemoryPoolReadWriteSettingsController()	{

	rb_RPbdb_MemoryPoolReadWriteSettingsController		=	rb_define_class_under(	rb_RPbdb_MemoryPoolSettingsController, 
																																						"ReadWrite",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MemoryPoolReadWriteSettingsController, 	"new",																rb_RPbdb_MemoryPoolReadWriteSettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"initialize",													rb_RPbdb_MemoryPoolReadWriteSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"parent_environment",									rb_RPbdb_MemoryPoolReadWriteSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController,				"parent_settings_controller",					rb_RPbdb_MemoryPoolReadWriteSettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController,				"parent_memory_pool_settings_controller",					rb_RPbdb_MemoryPoolReadWriteSettingsController_parentMemoryPoolSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"max_open_files",														rb_RPbdb_MemoryPoolReadWriteSettingsController_maxOpenFiles,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"set_max_open_files",														rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxOpenFiles,													1 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"max_sequential_writes",														rb_RPbdb_MemoryPoolReadWriteSettingsController_maxSequentialWrites,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"set_max_sequential_writes",														rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites,													1 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"time_to_sleep_before_next_write",														rb_RPbdb_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"set_time_to_sleep_before_next_write",														rb_RPbdb_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite,													1 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"max_mapped_database_size",														rb_RPbdb_MemoryPoolReadWriteSettingsController_maxMappedDatabaseSize,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"set_max_mapped_database_size",														rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxMappedDatabaseSize,													1 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"pagefault_shared_regions?",														rb_RPbdb_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_pagefault_shared_regions_on",														rb_RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn,													0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_pagefault_shared_regions_off",														rb_RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff,													0 	);

	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"do_not_write_to_temporary_backing_file?",					rb_RPbdb_MemoryPoolReadWriteSettingsController_doNotWriteToTemporaryBackingFile,							0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"no_temporary_backing_file?",												"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"no_temp_backing_file?",														"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"no_backing_file?",																	"do_not_write_to_temporary_backing_file?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"no_temp_file?",																		"do_not_write_to_temporary_backing_file?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_do_not_write_to_temporary_backing_file_on",		rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOn,										0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temporary_backing_file_on",								"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temp_backing_file_on",											"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_backing_file_on",													"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temp_file_on",															"turn_do_not_write_to_temporary_backing_file_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_do_not_write_to_temporary_backing_file_off",	rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOff,				0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temporary_backing_file_off",								"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temp_backing_file_off",										"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_backing_file_off",													"turn_do_not_write_to_temporary_backing_file_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_no_temp_file_off",														"turn_do_not_write_to_temporary_backing_file_off"	);

	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"use_system_memory_for_storage?",										rb_RPbdb_MemoryPoolReadWriteSettingsController_useSystemMemoryForStorage,											0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"use_system_memory?",																"use_system_memory_for_storage?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"system_memory?",																		"use_system_memory_for_storage?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_use_system_memory_for_storage_on",						rb_RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOn,								0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_use_system_memory_on",												"turn_use_system_memory_for_storage_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_system_memory_on",														"turn_use_system_memory_for_storage_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_use_system_memory_for_storage_off",						rb_RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOff,							0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_use_system_memory_off",												"turn_use_system_memory_for_storage_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_system_memory_off",														"turn_use_system_memory_for_storage_off"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"application_has_exclusive_access?",								rb_RPbdb_MemoryPoolReadWriteSettingsController_applicationHasExclusiveAccess,									0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"exclusive_access?",																"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"exclusive?",																				"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"private_access?",																	"application_has_exclusive_access?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"private?",																					"application_has_exclusive_access?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_has_exclusive_access_on",					rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOn,						0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_exclusive_access_on",													"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_exclusive_on",																"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_private_access_on",														"turn_application_has_exclusive_access_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_private_on",																	"turn_application_has_exclusive_access_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_has_exclusive_access_off",				rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOff,					0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_exclusive_access_off",												"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_exclusive_off",																"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_private_access_off",													"turn_application_has_exclusive_access_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_private_off",																	"turn_application_has_exclusive_access_off"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_allocates_memory_using_malloc?",					rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc,						0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_uses_malloc?",														"database_allocates_memory_using_malloc?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_malloc?",																	"database_allocates_memory_using_malloc?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"malloc?",																					"database_allocates_memory_using_malloc?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_allocates_memory_using_malloc_on",		rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn,			0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_uses_malloc_on",											"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_malloc_on",													"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_malloc_on",																		"turn_database_allocates_memory_using_malloc_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_allocates_memory_using_malloc_off",	rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff,			0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_uses_malloc_off",										"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_malloc_off",													"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_malloc_off",																	"turn_database_allocates_memory_using_malloc_off"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_allocates_memory_using_realloc?",					rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc,						0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_uses_realloc?",														"database_allocates_memory_using_realloc?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_realloc?",																"database_allocates_memory_using_realloc?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"realloc?",																					"database_allocates_memory_using_realloc?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_allocates_memory_using_realloc_on",	rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn,			0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_uses_realloc_on",										"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_realloc_on",													"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_realloc_on",																	"turn_database_allocates_memory_using_realloc_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_allocates_memory_using_realloc_off",	rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff,		0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_uses_realloc_off",										"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_realloc_off",												"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_realloc_off",																	"turn_database_allocates_memory_using_realloc_off"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"application_allocates_memory?",										rb_RPbdb_MemoryPoolReadWriteSettingsController_applicationAllocatesMemory,										0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"application_allocates?",														"application_allocates_memory?"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"application?",																			"application_allocates_memory?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_allocates_memory_on",							rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOn,							0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_allocates_on",										"turn_application_allocates_memory_on"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_on",															"turn_application_allocates_memory_on"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_allocates_memory_off",						rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOff,							0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_allocates_off",										"turn_application_allocates_memory_off"	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_application_off",															"turn_application_allocates_memory_off"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_frees_memory?",														rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseFreesMemory,														0 	);
	rb_define_alias(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"database_frees?",																	"database_frees_memory?"	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_frees_memory_on",										rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOn,											0 	);
	rb_define_method(			rb_RPbdb_MemoryPoolReadWriteSettingsController, 				"turn_database_frees_memory_off",										rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOff,										0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment											=	Qnil;
	VALUE	rb_parent_settings_controller							=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_RPbdb_MemoryPoolSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_memory_pool_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_memory_pool_settings_controller = rb_RPbdb_SettingsController_memoryPoolSettingsController( rb_parent_settings_controller );
	}

	RPbdb_MemoryPoolSettingsController*	c_parent_memory_pool_settings_controller;
	C_RPBDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_parent_memory_pool_settings_controller, c_parent_memory_pool_settings_controller );

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller	=	RPbdb_MemoryPoolSettingsController_readWriteSettingsController( c_parent_memory_pool_settings_controller );

	VALUE	rb_memory_pool_read_write_settings_controller	= RUBY_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( c_memory_pool_read_write_settings_controller );

	rb_iv_set(	rb_memory_pool_read_write_settings_controller,
							RPBDB_RB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_settings_controller };
	rb_obj_call_init(	rb_memory_pool_read_write_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_read_write_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_parentEnvironment(	VALUE	rb_memory_pool_read_write_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_MemoryPoolReadWriteSettingsController_parentSettingsController( rb_memory_pool_read_write_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_parentSettingsController(	VALUE	rb_memory_pool_read_write_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller		=	rb_RPbdb_MemoryPoolReadWriteSettingsController_parentMemoryPoolSettingsController( rb_memory_pool_read_write_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_RPbdb_MemoryPoolSettingsController_parentSettingsController( rb_parent_memory_pool_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_memory_pool_settings_controller  *
*******************************************/

VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_read_write_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller	=	rb_iv_get(	rb_memory_pool_read_write_settings_controller,
																																RPBDB_RB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_settings_controller;
}

/*******************
*  max_open_files  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_openfd.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_maxOpenFiles( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	return INT2FIX( RPbdb_MemoryPoolReadWriteSettingsController_maxOpenFiles( c_memory_pool_record_read_write_settings_controller ) );
}

	/***********************
	*  set_max_open_files  *
	***********************/

	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	VALUE	rb_memory_pool_read_write_settings_controller, 
																			VALUE	rb_max_open_files )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	c_memory_pool_record_read_write_settings_controller,
																		FIX2INT( rb_max_open_files ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/**************************
*  max_sequential_writes  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_maxwrite.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_maxSequentialWrites( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	return INT2FIX( RPbdb_MemoryPoolReadWriteSettingsController_maxSequentialWrites( c_memory_pool_record_read_write_settings_controller ) );
}

	/******************************
	*  set_max_sequential_writes  *
	******************************/

	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	VALUE	rb_memory_pool_read_write_settings_controller,
																					VALUE	rb_max_sequential_writes )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	c_memory_pool_record_read_write_settings_controller,
																			FIX2INT( rb_max_sequential_writes ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/************************************
*  time_to_sleep_before_next_write  *
************************************/

VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	return INT2FIX( RPbdb_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( c_memory_pool_record_read_write_settings_controller ) );
}

	/****************************************
	*  set_time_to_sleep_before_next_write  *
	****************************************/

	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	VALUE	rb_memory_pool_read_write_settings_controller, 
																						VALUE	rb_time_to_sleep_before_next_write )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	c_memory_pool_record_read_write_settings_controller,
																					FIX2INT( rb_time_to_sleep_before_next_write ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/*****************************
*  max_mapped_database_size  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_mp_mmapsize.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_maxMappedDatabaseSize( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	size_t	c_max_mapped_db_size	=	RPbdb_MemoryPoolReadWriteSettingsController_maxMappedDatabaseSize( c_memory_pool_record_read_write_settings_controller );
	VALUE		rb_max_mapped_db_size	=	LONG2NUM( c_max_mapped_db_size );

	return rb_max_mapped_db_size;
}

	/*********************************
	*  set_max_mapped_database_size  *
	*********************************/

	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_setMaxMappedDatabaseSize(	VALUE	rb_memory_pool_read_write_settings_controller, 
																																					VALUE	rb_max_mapped_db_size )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		size_t	c_max_mapped_db_size	=	NUM2LONG( rb_max_mapped_db_size );

		RPbdb_MemoryPoolReadWriteSettingsController_setMaxMappedDatabaseSize(	c_memory_pool_record_read_write_settings_controller,
																																					c_max_mapped_db_size );

		return rb_memory_pool_read_write_settings_controller;
	}

/******************************
*  pagefault_shared_regions?  *
******************************/

//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	BOOL	c_pagefault_shared_regions	=	RPbdb_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions(	c_memory_pool_record_read_write_settings_controller );
	VALUE	rb_pagefault_shared_regions	=	( c_pagefault_shared_regions ? Qtrue : Qfalse );

	return rb_pagefault_shared_regions;
}

	/*************************************
	*  turn_pagefault_shared_regions_on  *
	*************************************/

	//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( c_memory_pool_record_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/**************************************
	*  turn_pagefault_shared_regions_off  *
	**************************************/

	//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( c_memory_pool_record_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}


/********************************************
*  do_not_write_to_temporary_backing_file?  *
********************************************/

//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_doNotWriteToTemporaryBackingFile( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_doNotWriteToTemporaryBackingFile( c_memory_pool_record_read_write_settings_controller )	?	Qtrue
																																																																							:	Qfalse );
}

	/***************************************************
	*  turn_do_not_write_to_temporary_backing_file_on  *
	***************************************************/

	//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	//	Note: method default inverts flag default
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOn( c_memory_pool_record_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/****************************************************
	*  turn_do_not_write_to_temporary_backing_file_off  *
	****************************************************/

	//	DB_MPOOL_NOFILE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_flags.html
	//	Note: method default inverts flag default
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_record_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDoNotWriteToTemporaryBackingFileOff( c_memory_pool_record_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}
	
/***********************************
*  use_system_memory_for_storage?  *
***********************************/

//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_useSystemMemoryForStorage( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_useSystemMemoryForStorage( c_memory_pool_read_write_settings_controller )	?	Qtrue
																																																																:	Qfalse );
}

	/******************************************
	*  turn_use_system_memory_for_storage_on  *
	******************************************/

	//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/*******************************************
	*  turn_use_system_memory_for_storage_off  *
	*******************************************/

	//	DB_SYSTEM_MEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnUseSystemMemoryForStorageOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

/**************************************
*  application_has_exclusive_access?  *
**************************************/

//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_applicationHasExclusiveAccess( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_applicationHasExclusiveAccess( c_memory_pool_read_write_settings_controller )	?	Qtrue
																																																								:	Qfalse );
}

	/*********************************************
	*  turn_application_has_exclusive_access_on  *
	*********************************************/

	//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/**********************************************
	*  turn_application_has_exclusive_access_off  *
	**********************************************/

	//	DB_PRIVATE				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationHasExclusiveAccessOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}
	
/********************************************
*  database_allocates_memory_using_malloc?  *
********************************************/

//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingMalloc( c_memory_pool_read_write_settings_controller )	?	Qtrue
																														:	Qfalse );
}

	/***************************************************
	*  turn_database_allocates_memory_using_malloc_on  *
	***************************************************/

	//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/****************************************************
	*  turn_database_allocates_memory_using_malloc_off  *
	****************************************************/

	//	DB_DBT_MALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

/*********************************************
*  database_allocates_memory_using_realloc?  *
*********************************************/

//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_databaseAllocatesMemoryUsingRealloc( c_memory_pool_read_write_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/****************************************************
	*  turn_database_allocates_memory_using_realloc_on  *
	****************************************************/

	//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/*****************************************************
	*  turn_database_allocates_memory_using_realloc_off  *
	*****************************************************/

	//	DB_DBT_REALLOC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

/**********************************
*  application_allocates_memory?  *
**********************************/

//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_applicationAllocatesMemory( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_applicationAllocatesMemory( c_memory_pool_read_write_settings_controller )	?	Qtrue
																												:	Qfalse );
}

	/*****************************************
	*  turn_application_allocates_memory_on  *
	*****************************************/

	//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/******************************************
	*  turn_application_allocates_memory_off  *
	******************************************/

	//	DB_DBT_USERMEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnApplicationAllocatesMemoryOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

/***************************
*  database_frees_memory?  *
***************************/

//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_databaseFreesMemory( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return ( RPbdb_MemoryPoolReadWriteSettingsController_databaseFreesMemory( c_memory_pool_read_write_settings_controller )	?	Qtrue
																																																													:	Qfalse );
}

	/**********************************
	*  turn_database_frees_memory_on  *
	**********************************/

	//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/***********************************
	*  turn_database_frees_memory_off  *
	***********************************/

	//	DB_DBT_APPMALLOC	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbt_class.html
	VALUE rb_RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPbdb_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPbdb_MemoryPoolReadWriteSettingsController_turnDatabaseFreesMemoryOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

