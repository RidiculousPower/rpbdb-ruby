/*
 *		RPbdb::RPbdb_SettingsController::RPbdb_EnvironmentCacheSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "EnvironmentCacheSettingsController.h"
#include "SettingsController.h"

#include "Environment.h"
#include "RPbdb.h"

#include <rpbdb/Environment.h>
#include <rpbdb/EnvironmentCacheSettingsController.h>
#include <rpbdb/SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_EnvironmentSettingsController;
extern	VALUE	rb_RPbdb_EnvironmentCacheSettingsController;

void Init_rb_RPbdb_EnvironmentCacheSettingsController()	{

	rb_RPbdb_EnvironmentCacheSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																																		"Cache",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_EnvironmentCacheSettingsController, 	"new",																rb_RPbdb_EnvironmentCacheSettingsController_new,														-1 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"initialize",													rb_RPbdb_EnvironmentCacheSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"parent_environment",									rb_RPbdb_EnvironmentCacheSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_EnvironmentCacheSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"parent_settings_controller",					rb_RPbdb_EnvironmentCacheSettingsController_parentSettingsController,								0 	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"buffering?",														rb_RPbdb_EnvironmentCacheSettingsController_buffering,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"turn_buffering_on",														rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOn,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"turn_buffering_off",														rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOff,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"max_size_in_bytes",														rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInBytes,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"max_size_in_kbytes",														rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInKBytes,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"max_size_in_mbytes",														rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInMBytes,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"max_size_in_gbytes",														rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInGBytes,													0 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_bytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInBytes,													1 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_kbytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytes,													1 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_mbytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytes,													1 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_gbytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytes,													1 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_gbytes_mbytes_kbytes_bytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes,													4 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_mbytes_kbytes_bytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes,													3 	);
	rb_define_method(						rb_RPbdb_EnvironmentCacheSettingsController, 	"set_max_size_in_kbytes_bytes",														rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes,													2 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_EnvironmentCacheSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}

	RPbdb_SettingsController*	c_parent_settings_controller;
	C_RPBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_environment_cache_settings_controller	= RUBY_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( RPbdb_SettingsController_cacheSettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_environment_cache_settings_controller,
							RPBDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_environment_cache_settings_controller,
									 1, 
									 argv );
	
	return rb_environment_cache_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_EnvironmentCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPbdb_EnvironmentCacheSettingsController_parentEnvironment(	VALUE	rb_environment_cache_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_EnvironmentCacheSettingsController_parentSettingsController( rb_environment_cache_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/
VALUE rb_RPbdb_EnvironmentCacheSettingsController_parentSettingsController(	VALUE	rb_environment_cache_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_environment_cache_settings_controller,
																										RPBDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/***************
*  buffering?  *
***************/

//	DB_DIRECT_DB            http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPbdb_EnvironmentCacheSettingsController_buffering( VALUE	rb_environment_cache_settings_controller )	{

	RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return ( RPbdb_EnvironmentCacheSettingsController_buffering( c_environment_cache_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/**********************
	*  turn_buffering_on  *
	**********************/

	VALUE rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOn( VALUE	rb_environment_cache_settings_controller )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );
	
		RPbdb_EnvironmentCacheSettingsController_turnBufferingOn( c_environment_cache_settings_controller );
	
		return rb_environment_cache_settings_controller;
	}

	/***********************
	*  turn_buffering_off  *
	***********************/

	VALUE rb_RPbdb_EnvironmentCacheSettingsController_turnBufferingOff( VALUE	rb_environment_cache_settings_controller )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_turnBufferingOff( c_environment_cache_settings_controller );

		return rb_environment_cache_settings_controller;
	}


/**********************
*  max_size_in_bytes  *
**********************/

//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	uint64_t	c_max_size_in_bytes		=	RPbdb_EnvironmentCacheSettingsController_maxSizeInBytes( c_environment_cache_settings_controller );
	VALUE			rb_max_size_in_bytes	= ULL2NUM( c_max_size_in_bytes );

	return rb_max_size_in_bytes;
}

/***********************
*  max_size_in_kbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInKBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	uint32_t	c_max_size_in_kbytes		=	RPbdb_EnvironmentCacheSettingsController_maxSizeInKBytes( c_environment_cache_settings_controller );
	VALUE			rb_max_size_in_kbytes	= LONG2NUM( c_max_size_in_kbytes );

	return rb_max_size_in_kbytes;
}

/***********************
*  max_size_in_mbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInMBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	uint32_t	c_max_size_in_mbytes		=	RPbdb_EnvironmentCacheSettingsController_maxSizeInMBytes( c_environment_cache_settings_controller );
	VALUE			rb_max_size_in_mbytes		= LONG2NUM( c_max_size_in_mbytes );

	return rb_max_size_in_mbytes;
}

/***********************
*  max_size_in_gbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPbdb_EnvironmentCacheSettingsController_maxSizeInGBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	uint32_t	c_max_size_in_gbytes		=	RPbdb_EnvironmentCacheSettingsController_maxSizeInGBytes( c_environment_cache_settings_controller );
	VALUE			rb_max_size_in_gbytes		= LONG2NUM( c_max_size_in_gbytes );

	return rb_max_size_in_gbytes;
}

	/**************************
	*  set_max_size_in_bytes  *
	**************************/

	//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_environment_cache_settings_controller, 
																																			VALUE	rb_max_size_in_bytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInBytes(	c_environment_cache_settings_controller,
																																NUM2LONG( rb_max_size_in_bytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_kbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_kbytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	c_environment_cache_settings_controller,
																																NUM2LONG( rb_max_size_kbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_mbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_mbytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	c_environment_cache_settings_controller,
																																NUM2LONG( rb_max_size_mbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_gbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_environment_cache_settings_controller, 
																																				VALUE	rb_max_size_gbytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	c_environment_cache_settings_controller,
																																FIX2INT( rb_max_size_gbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***********************************************
	*  set_max_size_in_gbytes_mbytes_kbytes_bytes  *
	***********************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																							VALUE	rb_max_size_gbytes, 
																							VALUE	rb_additional_max_size_mbytes, 
																							VALUE	rb_additional_max_size_kbytes, 
																							VALUE	rb_additional_max_size_bytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		uint32_t	c_max_size_in_gbytes	=	NUM2LONG( rb_max_size_gbytes );
		uint32_t	c_max_size_in_mbytes	=	NUM2LONG( rb_additional_max_size_mbytes );
		uint32_t	c_max_size_in_kbytes	=	NUM2LONG( rb_additional_max_size_kbytes );
		uint32_t	c_max_size_in_bytes		=	NUM2LONG( rb_additional_max_size_bytes );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	c_environment_cache_settings_controller,
																																									c_max_size_in_gbytes,
																																									c_max_size_in_mbytes,
																																									c_max_size_in_kbytes,
																																									c_max_size_in_bytes );

		return rb_environment_cache_settings_controller;
	}

	/****************************************
	*  set_max_size_in_mbytes_kbytes_bytes  *
	****************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																																									VALUE	rb_max_size_mbytes, 
																																									VALUE	rb_additional_max_size_kbytes, 
																																									VALUE	rb_additional_max_size_bytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		uint32_t	c_max_size_in_mbytes	=	NUM2ULONG( rb_max_size_mbytes );
		uint32_t	c_max_size_in_kbytes	=	NUM2ULONG( rb_additional_max_size_kbytes );
		uint32_t	c_max_size_in_bytes		=	NUM2ULONG( rb_additional_max_size_bytes );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	c_environment_cache_settings_controller,
																																						c_max_size_in_mbytes,
																																						c_max_size_in_kbytes,
																																						c_max_size_in_bytes );

		return rb_environment_cache_settings_controller;
	}

	/*********************************
	*  set_max_size_in_kbytes_bytes  *
	*********************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																		  		VALUE	rb_max_size_kbytes, 
																		  		VALUE	rb_additional_max_size_bytes )	{

		RPbdb_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPbdb_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	c_environment_cache_settings_controller,
																																			FIX2INT( rb_max_size_kbytes ),
																																			FIX2INT( rb_additional_max_size_bytes ));

		return rb_environment_cache_settings_controller;
	}

