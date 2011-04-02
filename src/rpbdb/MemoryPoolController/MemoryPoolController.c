/*
 *		RPbdb::MemoryPoolController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MemoryPoolController.h"

#include "LogSequenceNumber.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MemoryPoolController.h>
#include <rpbdb/MemoryPoolFileController.h>

#include <rpbdb/MemoryPoolSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_MemoryPoolController;
extern	VALUE	rb_RPbdb_MemoryPoolSettingsController;
extern	VALUE	rb_RPbdb_MemoryPoolFileController;
extern	VALUE	rb_RPbdb_LogSequenceNumber;

void Init_rb_RPbdb_MemoryPoolController()	{

	rb_RPbdb_MemoryPoolController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																													"MemoryPoolController",			
																													rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MemoryPoolController, 	"new",										rb_RPbdb_MemoryPoolController_new,										-1 	);
	rb_define_method(						rb_RPbdb_MemoryPoolController, 	"initialize",							rb_RPbdb_MemoryPoolController_initialize,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_RPbdb_MemoryPoolController, 	"settings_controller",		rb_RPbdb_MemoryPoolController_settingsController,		0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolController, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_RPbdb_MemoryPoolController, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_RPbdb_MemoryPoolController, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_RPbdb_MemoryPoolController, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_RPbdb_MemoryPoolController, 	"parent_environment",			rb_RPbdb_MemoryPoolController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolController, 	"environment",						"parent_environment"	);                              	

	rb_define_method(						rb_RPbdb_MemoryPoolController, 	"trickle_clean",					rb_RPbdb_MemoryPoolController_trickleClean,					0 	);
	rb_define_method(						rb_RPbdb_MemoryPoolController, 	"flush",									rb_RPbdb_MemoryPoolController_flush,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);

	RPbdb_Environment*	c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	VALUE	rb_memory_pool_controller	=	RUBY_RPBDB_MEMORY_POOL_CONTROLLER( RPbdb_MemoryPoolController_new( c_parent_environment ) );

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_controller,
							RPBDB_RB_MEMORY_POOL_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );
	
	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_memory_pool_controller,
					 1, 
					 argv );
	
	return rb_memory_pool_controller;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_MemoryPoolController_settingsController(	VALUE	rb_memory_pool_controller )	{

	VALUE	rb_local_memory_pool_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_settings_controller = rb_iv_get(	rb_memory_pool_controller,
																																RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_MemoryPoolController*		c_memory_pool_controller;
		C_RPBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );
	
		RPbdb_MemoryPoolSettingsController*	c_local_memory_pool_settings_controller	=	RPbdb_MemoryPoolController_settingsController( c_memory_pool_controller );

		rb_local_memory_pool_settings_controller	=	RUBY_RPBDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_local_memory_pool_settings_controller );

		rb_iv_set(	rb_memory_pool_controller,
								RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER,
								rb_local_memory_pool_settings_controller );
	}

	return rb_local_memory_pool_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_MemoryPoolController_parentEnvironment(	VALUE	rb_memory_pool_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_memory_pool_controller,
																						RPBDB_RB_MEMORY_POOL_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/*********************
*  trickleClean  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_trickle.html
VALUE rb_RPbdb_MemoryPoolController_trickleClean(	VALUE	rb_memory_pool_controller, 
													VALUE	rb_percent_of_pages_to_clean )	{

	RPbdb_MemoryPoolController*		c_memory_pool_controller;
	C_RPBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	RPbdb_MemoryPoolController_trickleClean(	c_memory_pool_controller,
												FIX2INT( rb_percent_of_pages_to_clean ) );
	
	return rb_memory_pool_controller;
}

/*************
*  flush  *
*************/

//	The purpose of the lsn parameter is to enable a transaction manager to ensure, as part of a checkpoint, that all pages modified by a certain time have been written to disk.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_sync.html
VALUE rb_RPbdb_MemoryPoolController_flush(	VALUE	rb_memory_pool_controller, 
											VALUE	rb_write_all_records_before_lsn )	{

	RPbdb_MemoryPoolController*		c_memory_pool_controller;
	C_RPBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	RPbdb_LogSequenceNumber*		c_write_all_records_before_lsn;
	C_RPBDB_LOG_SEQUENCE_NUMBER( rb_write_all_records_before_lsn, c_write_all_records_before_lsn );

	RPbdb_MemoryPoolController_flush(	c_memory_pool_controller,
										c_write_all_records_before_lsn	);	

	return rb_memory_pool_controller;
}

/*************************
*  setMallocMethod  *
*************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPbdb_MemoryPoolController_setMallocMethod(	VALUE	rb_memory_pool_controller,
 													VALUE									(*malloc_method)( VALUE )	)	{
	RPbdb_MemoryPoolController_setMallocMethod();

}
*/
/*********************
*  mallocMethod  *
*********************/
/*
void *(*malloc_method)( VALUE ) RPbdb_MemoryPoolController_mallocMethod( VALUE	rb_memory_pool_controller )	{
	
}
*/
/*************************
*  setReallocMethod  *
*************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPbdb_MemoryPoolController_setReallocMethod(	VALUE	rb_memory_pool_controller,
 													VALUE										(*realloc_method)( VALUE, VALUE ) )	{
	RPbdb_MemoryPoolController_setReallocMethod();

}
*/
/*********************
*  reallocMethod  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
void *(*realloc_method)( VALUE, VALUE ) RPbdb_MemoryPoolController_reallocMethod( VALUE	rb_memory_pool_controller )	{

}
*/
/*********************
*  setFreeMethod  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPbdb_MemoryPoolController_setFreeMethod(	VALUE	rb_memory_pool_controller,
 												VALUE								(*free_method)( VALUE )	)	{
	RPbdb_MemoryPoolController_setFreeMethod();
		
}
*/
/*****************
*  freeMethod  *
*****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
void *(*free_method)( VALUE ) RPbdb_MemoryPoolController_freeMethod( VALUE	rb_memory_pool_controller )	{

}
*/

/************************
*  fileController  *
************************/

VALUE rb_RPbdb_MemoryPoolController_fileController( VALUE	rb_memory_pool_controller )	{

	RPbdb_MemoryPoolController*		c_memory_pool_controller;
	C_RPBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	return RUBY_RPBDB_MEMORY_POOL_FILE_CONTROLLER( RPbdb_MemoryPoolController_fileController( c_memory_pool_controller ) );
}


