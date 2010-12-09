/*
 *		Rbdb::SettingsController::MemoryPoolSettingsController::MemoryPoolFileSettingsController::MemoryPoolFilePageSettingsController::MemoryPoolFilePageSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_MemoryPoolFileCacheSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileCachePrioritySettingsController.h"
#include "rb_Rbdb_MemoryPoolFileSettingsController.h"
#include "rb_Rbdb_MemoryPoolSettingsController.h"
#include "rb_Rbdb_SettingsController.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_Environment.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_MemoryPoolFileCacheSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolFileSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>


#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_MemoryPoolFileCacheSettingsController;

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController;

void Init_Rbdb_MemoryPoolFileCacheSettingsController()	{

	rb_Rbdb_MemoryPoolFileCacheSettingsController		=	rb_define_class_under(	rb_Rbdb_MemoryPoolFileSettingsController, 
																																						"Cache",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MemoryPoolFileCacheSettingsController,				"new",																rb_Rbdb_MemoryPoolFileCacheSettingsController_new,														-1 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController, 				"initialize",													rb_Rbdb_MemoryPoolFileCacheSettingsController_initialize,														-1 	);

	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController, 				"parent_environment",									rb_Rbdb_MemoryPoolFileCacheSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFileCacheSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController,				"parent_settings_controller",					rb_Rbdb_MemoryPoolFileCacheSettingsController_parentSettingsController,								0 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController,				"parent_memory_pool_settings_controller",					rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController,								0 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController,				"parent_memory_pool_file_settings_controller",					rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController,								0 	);
                                    			                                                                                                    				
	rb_define_method(						rb_Rbdb_MemoryPoolFileCacheSettingsController, 				"priority_settings_controller",									rb_Rbdb_MemoryPoolFileCacheSettingsController_prioritySettingsController,			0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment														=	Qnil;
	VALUE	rb_parent_settings_controller										=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_Rbdb_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_Rbdb_MemoryPoolFileSettingsController ) ) ),
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

		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_memory_pool_settings_controller = rb_Rbdb_SettingsController_memoryPoolSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_memory_pool_settings_controller != Qnil )	{
		rb_parent_memory_pool_file_settings_controller	=	rb_Rbdb_MemoryPoolSettingsController_fileSettingsController( rb_parent_memory_pool_settings_controller );
	}

	Rbdb_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	Rbdb_MemoryPoolFileCacheSettingsController*	c_memory_pool_file_cache_settings_controller	=	Rbdb_MemoryPoolFileSettingsController_cacheSettingsController( c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_cache_settings_controller	= RUBY_Rbdb_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( c_memory_pool_file_cache_settings_controller );

	rb_iv_set(	rb_memory_pool_file_cache_settings_controller,
							Rbdb_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_file_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_settings_controller };	
	rb_obj_call_init(	rb_memory_pool_file_cache_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_cache_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_MemoryPoolFileCacheSettingsController_parentSettingsController( rb_memory_pool_file_cache_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller		=	rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController( rb_memory_pool_file_cache_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_Rbdb_MemoryPoolSettingsController_parentSettingsController( rb_parent_memory_pool_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_memory_pool_settings_controller  *
*******************************************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_settings_controller		=	rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController( rb_memory_pool_file_cache_settings_controller );
	VALUE	rb_parent_memory_pool_settings_controller					=	rb_Rbdb_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController( rb_parent_memory_pool_file_settings_controller );
	
	return rb_parent_memory_pool_settings_controller;	
}

/************************************************
*  parent_memory_pool_file_settings_controller  *
************************************************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_settings_controller	=	rb_iv_get(	rb_memory_pool_file_cache_settings_controller,
																																			Rbdb_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_file_settings_controller;
}

/************************
*  priority_controller  *
************************/

VALUE rb_Rbdb_MemoryPoolFileCacheSettingsController_prioritySettingsController( VALUE	rb_memory_pool_file_cache_settings_controller )	{

	VALUE	rb_memory_pool_file_cache_priority_settings_controller	=	Qnil;
	
	if ( ( rb_memory_pool_file_cache_priority_settings_controller = rb_iv_get(	rb_memory_pool_file_cache_settings_controller,
																																							Rbdb_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_memory_pool_file_cache_priority_settings_controller	=	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_new(	1,
																																																													& rb_memory_pool_file_cache_settings_controller,
																																																													rb_Rbdb_MemoryPoolFileCachePrioritySettingsController );
		rb_iv_set(	rb_memory_pool_file_cache_priority_settings_controller,
								Rbdb_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER,
								rb_memory_pool_file_cache_settings_controller );
	}
	
	return rb_memory_pool_file_cache_priority_settings_controller;
}
