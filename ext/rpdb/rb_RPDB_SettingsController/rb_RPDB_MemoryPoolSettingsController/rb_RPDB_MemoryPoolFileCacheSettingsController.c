/*
 *		RPDB::SettingsController::MemoryPoolSettingsController::MemoryPoolFileSettingsController::MemoryPoolFilePageSettingsController::MemoryPoolFilePageSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolFileCacheSettingsController.h"
#include "rb_RPDB_MemoryPoolFileSettingsController.h"
#include "rb_RPDB_MemoryPoolSettingsController.h"
#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_MemoryPoolFileCacheSettingsController.h>
#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>
#include <rpdb/RPDB_MemoryPoolSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>


#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_MemoryPoolFileCacheSettingsController;

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileCachePrioritySettingsController;

void Init_RPDB_MemoryPoolFileCacheSettingsController()	{

	rb_RPDB_MemoryPoolFileCacheSettingsController		=	rb_define_class_under(	rb_RPDB_MemoryPoolFileSettingsController, 
																																						"Cache",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFileCacheSettingsController,				"new",																rb_RPDB_MemoryPoolFileCacheSettingsController_new,														-1 	);
	rb_define_method(						rb_RPDB_MemoryPoolFileCacheSettingsController, 				"initialize",													rb_RPDB_MemoryPoolFileCacheSettingsController_init,														-1 	);

	rb_define_method(						rb_RPDB_MemoryPoolFileCacheSettingsController, 				"parent_environment",									rb_RPDB_MemoryPoolFileCacheSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFileCacheSettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(						rb_RPDB_MemoryPoolFileCacheSettingsController, 				"priority",														rb_RPDB_MemoryPoolFileCacheSettingsController_prioritySettingsController,			0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment														=	Qnil;
	VALUE	rb_parent_settings_controller										=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_RPDB_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_RPDB_MemoryPoolFileSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]",
			"[ <parent memory pool file settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_memory_pool_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_memory_pool_settings_controller = rb_RPDB_SettingsController_memoryPoolSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_memory_pool_settings_controller != Qnil )	{
		rb_parent_memory_pool_file_settings_controller	=	rb_RPDB_MemoryPoolFileSettingsController_pageSettingsController( rb_parent_memory_pool_settings_controller );
	}

	RPDB_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	RPDB_MemoryPoolFileCacheSettingsController*	c_memory_pool_file_cache_settings_controller	=	RPDB_MemoryPoolFileSettingsController_cacheSettingsController( c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_cache_settings_controller	= RUBY_RPDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( c_memory_pool_file_cache_settings_controller );

	rb_iv_set(	rb_memory_pool_file_cache_settings_controller,
							RPDB_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_file_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_settings_controller };	
	rb_obj_call_init(	rb_memory_pool_file_cache_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_cache_settings_controller;		
}

/************
*  init  *
************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_init(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

}

/***************************************
*  parent_settings_controller  *
***************************************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

}

/***************************************
*  parent_memory_pool_settings_controller  *
***************************************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

}

/***************************************
*  parent_memory_pool_file_settings_controller  *
***************************************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller	=	rb_iv_get(	rb_memory_pool_file_cache_settings_controller,
																																RPDB_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_settings_controller;
}

/**************************
*  priorityController  *
**************************/

VALUE rb_RPDB_MemoryPoolFileCacheSettingsController_prioritySettingsController( VALUE	rb_memory_pool_file_cache_settings_controller )	{

	RPDB_MemoryPoolFileCacheSettingsController*	c_memory_pool_file_cache_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_settings_controller, c_memory_pool_file_cache_settings_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( RPDB_MemoryPoolFileCacheSettingsController_prioritySettingsController( c_memory_pool_file_cache_settings_controller ) );
}
