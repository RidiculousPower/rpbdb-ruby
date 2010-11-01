/*
 *		RPDB::MemoryPoolController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolController.h"

#include "rb_RPDB_LogSequenceNumber.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolController.h>
#include <rpdb/RPDB_MemoryPoolFileController.h>

#include <rpdb/RPDB_MemoryPoolSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_MemoryPoolController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileController;
extern	VALUE	rb_RPDB_LogSequenceNumber;

void Init_RPDB_MemoryPoolController()	{

	rb_RPDB_MemoryPoolController	=	rb_define_class_under(	rb_RPDB_Environment, 
																													"MemoryPoolController",			
																													rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolController, 	"new",										rb_RPDB_MemoryPoolController_new,										-1 	);
	rb_define_method(						rb_RPDB_MemoryPoolController, 	"initialize",							rb_RPDB_MemoryPoolController_init,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_RPDB_MemoryPoolController, 	"settings_controller",		rb_RPDB_MemoryPoolController_settingsController,		0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolController, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolController, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolController, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolController, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_RPDB_MemoryPoolController, 	"parent_environment",			rb_RPDB_MemoryPoolController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolController, 	"environment",						"parent_environment"	);                              	

	rb_define_method(						rb_RPDB_MemoryPoolController, 	"trickle_clean",					rb_RPDB_MemoryPoolController_trickleClean,					0 	);
	rb_define_method(						rb_RPDB_MemoryPoolController, 	"flush",									rb_RPDB_MemoryPoolController_flush,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolController_new(	int			argc,
																				VALUE*	args,
																				VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment > ]"
		)
	);

	RPDB_Environment*	c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	VALUE	rb_memory_pool_controller	=	RUBY_RPDB_MEMORY_POOL_CONTROLLER( RPDB_MemoryPoolController_new( c_parent_environment ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_environment;
	
	rb_obj_call_init(	rb_memory_pool_controller,
					 1, 
					 argv );
	
	return rb_memory_pool_controller;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolController_init(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_MemoryPoolController_settingsController(	VALUE	rb_memory_pool_controller )	{

	RPDB_MemoryPoolController*	c_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	return RUBY_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( RPDB_MemoryPoolController_settingsController( c_memory_pool_controller ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolController_parentEnvironment(	VALUE	rb_memory_pool_controller )	{

	RPDB_MemoryPoolController*		c_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolController_parentEnvironment( c_memory_pool_controller ) );

}

/*********************
*  trickleClean  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_trickle.html
VALUE rb_RPDB_MemoryPoolController_trickleClean(	VALUE	rb_memory_pool_controller, 
													VALUE	rb_percent_of_pages_to_clean )	{

	RPDB_MemoryPoolController*		c_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	RPDB_MemoryPoolController_trickleClean(	c_memory_pool_controller,
												FIX2INT( rb_percent_of_pages_to_clean ) );
	
	return rb_memory_pool_controller;
}

/*************
*  flush  *
*************/

//	The purpose of the lsn parameter is to enable a transaction manager to ensure, as part of a checkpoint, that all pages modified by a certain time have been written to disk.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_sync.html
VALUE rb_RPDB_MemoryPoolController_flush(	VALUE	rb_memory_pool_controller, 
											VALUE	rb_write_all_records_before_lsn )	{

	RPDB_MemoryPoolController*		c_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	RPDB_LogSequenceNumber*		c_write_all_records_before_lsn;
	C_RPDB_LOG_SEQUENCE_NUMBER( rb_write_all_records_before_lsn, c_write_all_records_before_lsn );

	RPDB_MemoryPoolController_flush(	c_memory_pool_controller,
										c_write_all_records_before_lsn	);	

	return rb_memory_pool_controller;
}

/*************************
*  setMallocMethod  *
*************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPDB_MemoryPoolController_setMallocMethod(	VALUE	rb_memory_pool_controller,
 													VALUE									(*malloc_method)( VALUE )	)	{
	RPDB_MemoryPoolController_setMallocMethod();

}
*/
/*********************
*  mallocMethod  *
*********************/
/*
void *(*malloc_method)( VALUE ) RPDB_MemoryPoolController_mallocMethod( VALUE	rb_memory_pool_controller )	{
	
}
*/
/*************************
*  setReallocMethod  *
*************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPDB_MemoryPoolController_setReallocMethod(	VALUE	rb_memory_pool_controller,
 													VALUE										(*realloc_method)( VALUE, VALUE ) )	{
	RPDB_MemoryPoolController_setReallocMethod();

}
*/
/*********************
*  reallocMethod  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
void *(*realloc_method)( VALUE, VALUE ) RPDB_MemoryPoolController_reallocMethod( VALUE	rb_memory_pool_controller )	{

}
*/
/*********************
*  setFreeMethod  *
*********************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
VALUE rb_RPDB_MemoryPoolController_setFreeMethod(	VALUE	rb_memory_pool_controller,
 												VALUE								(*free_method)( VALUE )	)	{
	RPDB_MemoryPoolController_setFreeMethod();
		
}
*/
/*****************
*  freeMethod  *
*****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_alloc.html
void *(*free_method)( VALUE ) RPDB_MemoryPoolController_freeMethod( VALUE	rb_memory_pool_controller )	{

}
*/

/************************
*  fileController  *
************************/

VALUE rb_RPDB_MemoryPoolController_fileController( VALUE	rb_memory_pool_controller )	{

	RPDB_MemoryPoolController*		c_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_CONTROLLER( RPDB_MemoryPoolController_fileController( c_memory_pool_controller ) );
}


