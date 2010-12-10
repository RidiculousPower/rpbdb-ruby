/*
 *		Rbdb::SettingsController::MemoryPoolSettingsController::MemoryPoolFileSettingsController::MemoryPoolFilePageSettingsController::MemoryPoolFilePagePrioritySettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Environment.h"

#include "rb_Rbdb_MemoryPoolFileCachePrioritySettingsController.h"
#include "rb_Rbdb_MemoryPoolFileCacheSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileSettingsController.h"
#include "rb_Rbdb_MemoryPoolSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb.h"


#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_MemoryPoolFileCachePrioritySettingsController.h>
#include <rbdb/Rbdb_MemoryPoolFileCacheSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolFileSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_Rbdb_SettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController;

void Init_Rbdb_MemoryPoolFileCachePrioritySettingsController()	{

	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController		=	rb_define_class_under(	rb_Rbdb_MemoryPoolFileCacheSettingsController, 
																																										"Priority",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 	"new",																rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"initialize",													rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"parent_environment",									rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController,				"parent_settings_controller",																	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController,				"parent_memory_pool_settings_controller",											rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController,				"parent_memory_pool_file_settings_controller",								rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController,				"parent_memory_pool_file_cache_settings_controller",					rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileCacheSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"current_priority",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_currentPriority,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"very_low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"set_to_very_low",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_least_very_low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_most_very_low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_low,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"set_to_low",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_least_low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_most_low?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostLow,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"default?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_default,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"set_to_default",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setDefault,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_least_default?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_most_default?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_high,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"set_to_high",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_least_high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_most_high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"very_high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"set_to_very_high",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_least_very_high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, 				"is_at_most_very_high?",														rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller							=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_cache_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_Rbdb_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_Rbdb_MemoryPoolFileSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_Rbdb_MemoryPoolFileCacheSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]",
			"[ <parent memory pool file settings controller> ]",
			"[ <parent memory pool file cache settings controller> ]"
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
	if ( rb_parent_memory_pool_file_settings_controller != Qnil )	{
		rb_parent_memory_pool_file_cache_settings_controller = rb_Rbdb_MemoryPoolFileSettingsController_cacheSettingsController( rb_parent_memory_pool_file_settings_controller );
	}

	Rbdb_MemoryPoolFileCacheSettingsController*	c_parent_memory_pool_file_cache_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_cache_settings_controller, c_parent_memory_pool_file_cache_settings_controller );

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_parent_memory_pool_file_cache_priority_settings_controller	=	Rbdb_MemoryPoolFileCacheSettingsController_prioritySettingsController( c_parent_memory_pool_file_cache_settings_controller );

	VALUE	rb_memory_pool_file_cache_priority_settings_controller	= RUBY_RBDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_parent_memory_pool_file_cache_priority_settings_controller );

	rb_iv_set(	rb_memory_pool_file_cache_priority_settings_controller,
							Rbdb_RB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_file_cache_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_settings_controller };
	rb_obj_call_init(	rb_memory_pool_file_cache_priority_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_cache_priority_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																				VALUE*		args __attribute__ ((unused)),
																																				VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentSettingsController( rb_memory_pool_file_cache_priority_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller		=	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolSettingsController( rb_memory_pool_file_cache_priority_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_Rbdb_MemoryPoolSettingsController_parentSettingsController( rb_parent_memory_pool_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_memory_pool_settings_controller  *
*******************************************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_settings_controller		=	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileSettingsController( rb_memory_pool_file_cache_priority_settings_controller );
	VALUE	rb_parent_memory_pool_settings_controller					=	rb_Rbdb_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController( rb_parent_memory_pool_file_settings_controller );
	
	return rb_parent_memory_pool_settings_controller;	
}

/************************************************
*  parent_memory_pool_file_settings_controller  *
************************************************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_cache_settings_controller		=	rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileCacheSettingsController( rb_memory_pool_file_cache_priority_settings_controller );
	VALUE	rb_parent_memory_pool_file_settings_controller					=	rb_Rbdb_MemoryPoolFileCacheSettingsController_parentMemoryPoolFileSettingsController( rb_parent_memory_pool_file_cache_settings_controller );
	
	return rb_parent_memory_pool_file_settings_controller;	
}

/******************************************************
*  parent_memory_pool_file_cache_settings_controller  *
******************************************************/

VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_parentMemoryPoolFileCacheSettingsController(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_cache_settings_controller	=	rb_iv_get(	rb_memory_pool_file_cache_priority_settings_controller,
																																						Rbdb_RB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_file_cache_settings_controller;
}

/*********************
*  current_priority  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_currentPriority( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	int		c_current_priority	=	Rbdb_MemoryPoolFileCachePrioritySettingsController_currentPriority( c_memory_pool_file_cache_priority_settings_controller );

	VALUE	rb_current_priority	=	INT2FIX( c_current_priority );
	
	return rb_current_priority;
}

/*************
*  very_low  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	BOOL	c_is_very_low	=	Rbdb_MemoryPoolFileCachePrioritySettingsController_veryLow( c_memory_pool_file_cache_priority_settings_controller );

	VALUE	rb_is_very_low	=	( c_is_very_low ? Qtrue : Qfalse );

	return rb_is_very_low;
}

	/*****************
	*  set_very_low  *
	*****************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryLow( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/**********************
	*  at_least_very_low  *
	**********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{
	
		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );
	
		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/*********************
	*  at_most_very_low  *
	*********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );
	
		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

/********
*  low  *
********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_low( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_low( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/************
	*  set_low  *
	************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		Rbdb_MemoryPoolFileCachePrioritySettingsController_setLow( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*****************
	*  at_least_low  *
	*****************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

	/****************
	*  at_most_low  *
	****************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

/************
*  default  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_default( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_default( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/****************
	*  set_default  *
	****************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		Rbdb_MemoryPoolFileCachePrioritySettingsController_setDefault( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*********************
	*  at_least_default  *
	*********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/********************
	*  at_most_default  *
	********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

/*********
*  high  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_high( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_high( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************
	*  set_high  *
	*************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		Rbdb_MemoryPoolFileCachePrioritySettingsController_setHigh( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/******************
	*  at_least_high  *
	******************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

	/*****************
	*  at_most_high  *
	*****************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

/**************
*  very_high  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_veryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_veryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/******************
	*  set_very_high  *
	******************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		Rbdb_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/***********************
	*  at_least_very_high  *
	***********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/**********************
	*  at_most_very_high  *
	**********************/

	VALUE rb_Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		Rbdb_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( Rbdb_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}
