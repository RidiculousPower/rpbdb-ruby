/*
 *		RPDB::SettingsController::MemoryPoolSettingsController::MemoryPoolFileSettingsController::MemoryPoolFilePageSettingsController::MemoryPoolFilePagePrioritySettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_MemoryPoolFileCachePrioritySettingsController.h>

#include "rb_RPDB_Environment.h"

#include "rb_RPDB_MemoryPoolFileCachePrioritySettingsController.h"

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_MemoryPoolFileCachePrioritySettingsController;

extern	VALUE	rb_RPDB_Environment;
//	FIX - create this
//extern	VALUE	rb_RPDB_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileCacheSettingsController;


void Init_RPDB_MemoryPoolFileCachePrioritySettingsController()	{

	rb_RPDB_MemoryPoolFileCachePrioritySettingsController		=	rb_define_class_under(	rb_RPDB_MemoryPoolFileSettingsController, 
																																										"Priority",	
																																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 	"new",																rb_RPDB_MemoryPoolFileCachePrioritySettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"initialize",													rb_RPDB_MemoryPoolFileCachePrioritySettingsController_init,														-1 	);

	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"parent_environment",									rb_RPDB_MemoryPoolFileCachePrioritySettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_parentEnvironment,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_currentPriority,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_low,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostLow,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_default,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setDefault,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_high,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileCachePrioritySettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller							=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller				=	Qnil;
//	VALUE	rb_parent_memory_pool_file_cache_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_RPDB_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_RPDB_MemoryPoolFileSettingsController )/*,
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_cache_settings_controller, rb_RPDB_MemoryPoolFileCacheSettingsController )*/ ) ),
			R_ListOrder( 1 ),
			"[ <parent environment > ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]",
			"[ <parent memory pool file settings controller> ]",
			"[ <parent memory pool file cache settings controller> ]"
		)
	);

	RPDB_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_cache_priority_settings_controller	= RUBY_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( RPDB_MemoryPoolFileCachePrioritySettingsController_new( c_parent_memory_pool_file_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_memory_pool_file_settings_controller;
	
	rb_obj_call_init(	rb_memory_pool_file_cache_priority_settings_controller,
					 1, 
					 argv );
	
	return rb_memory_pool_file_cache_priority_settings_controller;		
}

/************
*  init  *
************/

VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_init(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/

VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolFileCachePrioritySettingsController_parentEnvironment( c_memory_pool_file_cache_priority_settings_controller ) );
}

/*************************
*  currentPriority  *
*************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_currentPriority( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

														//	FIX - constant
	return INT2FIX( RPDB_MemoryPoolFileCachePrioritySettingsController_currentPriority( c_memory_pool_file_cache_priority_settings_controller ) );
}

/*****************
*  veryLow  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( RPDB_MemoryPoolFileCachePrioritySettingsController_veryLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/*****************
	*  setVeryLow  *
	*****************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryLow( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*********************
	*  atLeastVeryLow  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{
	
		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );
	
		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/*********************
	*  atMostVeryLow  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );
	
		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

/************
*  low  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_low( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( RPDB_MemoryPoolFileCachePrioritySettingsController_low( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************
	*  setLow  *
	*************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		RPDB_MemoryPoolFileCachePrioritySettingsController_setLow( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*****************
	*  atLeastLow  *
	*****************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

	/*****************
	*  atMostLow  *
	******************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostLow( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

/*****************
*  default  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_default( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( RPDB_MemoryPoolFileCachePrioritySettingsController_default( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/*****************
	*  setDefault  *
	*****************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		RPDB_MemoryPoolFileCachePrioritySettingsController_setDefault( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*********************
	*  atLeastDefault  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastDefault( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/*********************
	*  atMostDefault  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostDefault( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

/*************
*  high  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_high( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( RPDB_MemoryPoolFileCachePrioritySettingsController_high( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*****************
	*  setHigh  *
	*****************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		RPDB_MemoryPoolFileCachePrioritySettingsController_setHigh( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*********************
	*  atLeastHigh  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

	/*****************
	*  atMostHigh  *
	*****************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																			:	Qfalse );
	}

/*****************
*  veryHigh  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_set_priority.html
VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_veryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

	RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

	return ( RPDB_MemoryPoolFileCachePrioritySettingsController_veryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																	:	Qfalse );
}

	/*********************
	*  setVeryHigh  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		RPDB_MemoryPoolFileCachePrioritySettingsController_setVeryHigh( c_memory_pool_file_cache_priority_settings_controller );

		return rb_memory_pool_file_cache_priority_settings_controller;
	}

	/*************************
	*  atLeastVeryHigh  *
	*************************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtLeastVeryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}

	/*********************
	*  atMostVeryHigh  *
	*********************/

	VALUE rb_RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_memory_pool_file_cache_priority_settings_controller )	{

		RPDB_MemoryPoolFileCachePrioritySettingsController*	c_memory_pool_file_cache_priority_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller );

		return ( RPDB_MemoryPoolFileCachePrioritySettingsController_isAtMostVeryHigh( c_memory_pool_file_cache_priority_settings_controller )	?	Qtrue
																																				:	Qfalse );
	}
