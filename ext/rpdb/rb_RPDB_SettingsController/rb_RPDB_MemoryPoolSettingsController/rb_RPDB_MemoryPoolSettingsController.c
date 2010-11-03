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
#include "rb_RPDB.h"

#include <rpdb/RPDB_SettingsController.h>

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolSettingsController.h>
#include <rpdb/RPDB_MemoryPoolReadWriteSettingsController.h>
#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolReadWriteSettingsController;

void Init_RPDB_MemoryPoolSettingsController()	{

	rb_RPDB_MemoryPoolSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"MemoryPool",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolSettingsController, 	"new",																							rb_RPDB_MemoryPoolSettingsController_new,																						-1 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"initialize",																				rb_RPDB_MemoryPoolSettingsController_init,																					-1 	);
                            
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
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"remove_file_with_last_reference?",									rb_RPDB_MemoryPoolSettingsController_removeFileWithLastReference,										0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_remove_file_with_last_reference_on",					rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOn,							0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_remove_file_with_last_reference_off",					rb_RPDB_MemoryPoolSettingsController_turnRemoveFileWithLastReferenceOff,						0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"pagesize_factor_mismatch_should_fail?",						rb_RPDB_MemoryPoolSettingsController_pagesizeFactorMismatchShouldFail,							0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"pagesize_mismatch_should_fail?",										"pagesize_factor_mismatch_should_fail?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_factor_mismatch_should_fail_on",			rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOn,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_mismatch_should_fail_on",						"pagesize_factor_mismatch_should_fail?"	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_factor_mismatch_should_fail_off",		rb_RPDB_MemoryPoolSettingsController_turnPageSizeFactorMismatchShouldFailOff,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"turn_pagesize_mismatch_should_fail_off",						"pagesize_factor_mismatch_should_fail?"	);

	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"file_settings_controller",													rb_RPDB_MemoryPoolSettingsController_fileSettingsController,												0 	);
	rb_define_method(			rb_RPDB_MemoryPoolSettingsController, 				"read_write_settings_controller",										rb_RPDB_MemoryPoolSettingsController_readWriteSettingsController,				0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"read_writes",																			"read_write_settings_controller"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"read_write",																				"read_write_settings_controller"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"readwrites",																				"read_write_settings_controller"	);
	rb_define_alias(			rb_RPDB_MemoryPoolSettingsController, 				"readwrite",																				"read_write_settings_controller"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_MemoryPoolSettingsController_new(	int			argc,
																								VALUE*	args,
																								VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller	=	RPDB_SettingsController_memoryPoolSettingsController( c_parent_settings_controller );

	VALUE	rb_memory_pool_settings_controller	=	RUBY_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_memory_pool_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_memory_pool_settings_controller,
										1, 
										argv );
	
	return rb_memory_pool_settings_controller;		
}

/*********
*  init  *
*********/

VALUE rb_RPDB_MemoryPoolSettingsController_init(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{
	
	return rb_self;
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

	RPDB_MemoryPoolFileSettingsController* c_memory_pool_file_settings_controller	=	RPDB_MemoryPoolSettingsController_fileSettingsController( c_memory_pool_settings_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_memory_pool_file_settings_controller );
}

/**************************************************
*  readWriteSettingsController  *
**************************************************/

VALUE rb_RPDB_MemoryPoolSettingsController_readWriteSettingsController( VALUE	rb_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller );

	RPDB_MemoryPoolReadWriteSettingsController* c_memory_pool_read_write_settings_controller	=	RPDB_MemoryPoolSettingsController_readWriteSettingsController( c_memory_pool_settings_controller );

	return RUBY_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( c_memory_pool_read_write_settings_controller );
}
