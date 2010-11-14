/*
 *		RPDB::RPDB_SettingsController::RPDB_EnvironmentCacheSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_EnvironmentCacheSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_EnvironmentCacheSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_EnvironmentSettingsController;
extern	VALUE	rb_RPDB_EnvironmentCacheSettingsController;

void Init_RPDB_EnvironmentCacheSettingsController()	{

	rb_RPDB_EnvironmentCacheSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"Cache",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_EnvironmentCacheSettingsController, 	"new",																rb_RPDB_EnvironmentCacheSettingsController_new,														-1 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"initialize",													rb_RPDB_EnvironmentCacheSettingsController_initialize,														-1 	);
                        			                                        
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"parent_environment",									rb_RPDB_EnvironmentCacheSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_EnvironmentCacheSettingsController, 	"environment",												"parent_environment"	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"parent_settings_controller",					rb_RPDB_EnvironmentCacheSettingsController_parentSettingsController,								0 	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"buffering?",														rb_RPDB_EnvironmentCacheSettingsController_buffering,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"turn_buffering_on",														rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOn,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"turn_buffering_off",														rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOff,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"max_size_in_bytes",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"max_size_in_kbytes",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"max_size_in_mbytes",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"max_size_in_gbytes",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_bytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes,													1 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_kbytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes,													1 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_mbytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes,													1 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_gbytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes,													1 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_gbytes_mbytes_kbytes_bytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes,													4 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_mbytes_kbytes_bytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes,													3 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"set_max_size_in_kbytes_bytes",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes,													2 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_EnvironmentCacheSettingsController_new(	int			argc,
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

	VALUE	rb_environment_cache_settings_controller	= RUBY_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( RPDB_SettingsController_cacheSettingsController( c_parent_settings_controller ) );

	rb_iv_set(	rb_environment_cache_settings_controller,
							RPDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
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

VALUE rb_RPDB_EnvironmentCacheSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/
VALUE rb_RPDB_EnvironmentCacheSettingsController_parentEnvironment(	VALUE	rb_environment_cache_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_EnvironmentCacheSettingsController_parentSettingsController( rb_environment_cache_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/
VALUE rb_RPDB_EnvironmentCacheSettingsController_parentSettingsController(	VALUE	rb_environment_cache_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_environment_cache_settings_controller,
																										RPDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/***************
*  buffering?  *
***************/

//	DB_DIRECT_DB            http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_buffering( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return ( RPDB_EnvironmentCacheSettingsController_buffering( c_environment_cache_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/**********************
	*  turn_buffering_on  *
	**********************/

	VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOn( VALUE	rb_environment_cache_settings_controller )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );
	
		RPDB_EnvironmentCacheSettingsController_turnBufferingOn( c_environment_cache_settings_controller );
	
		return rb_environment_cache_settings_controller;
	}

	/***********************
	*  turn_buffering_off  *
	***********************/

	VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOff( VALUE	rb_environment_cache_settings_controller )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_turnBufferingOff( c_environment_cache_settings_controller );

		return rb_environment_cache_settings_controller;
	}


/**********************
*  max_size_in_bytes  *
**********************/

//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInBytes( c_environment_cache_settings_controller ) );
}

/***********************
*  max_size_in_kbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes( c_environment_cache_settings_controller ) );
}

/***********************
*  max_size_in_mbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes( c_environment_cache_settings_controller ) );
}

/***********************
*  max_size_in_gbytes  *
***********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes( c_environment_cache_settings_controller ) );
}

	/**************************
	*  set_max_size_in_bytes  *
	**************************/

	//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_environment_cache_settings_controller, 
																																			VALUE	rb_max_size_in_bytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes(	c_environment_cache_settings_controller,
		 															NUM2LONG( rb_max_size_in_bytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_kbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_kbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	c_environment_cache_settings_controller,
		 																NUM2LONG( rb_max_size_kbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_mbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_mbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	c_environment_cache_settings_controller,
																		NUM2LONG( rb_max_size_mbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***************************
	*  set_max_size_in_gbytes  *
	***************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_gbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	c_environment_cache_settings_controller,
																		FIX2INT( rb_max_size_gbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/***********************************************
	*  set_max_size_in_gbytes_mbytes_kbytes_bytes  *
	***********************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																							VALUE	rb_max_size_gbytes, 
																							VALUE	rb_additional_max_size_mbytes, 
																							VALUE	rb_additional_max_size_kbytes, 
																							VALUE	rb_additional_max_size_bytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	c_environment_cache_settings_controller,
																						FIX2INT( rb_max_size_gbytes ),
																						FIX2INT( rb_additional_max_size_mbytes ),
																						FIX2INT( rb_additional_max_size_kbytes ),
																						FIX2INT( rb_additional_max_size_bytes ) );

		return rb_environment_cache_settings_controller;
	}

	/****************************************
	*  set_max_size_in_mbytes_kbytes_bytes  *
	****************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																						VALUE	rb_max_size_mbytes, 
																						VALUE	rb_additional_max_size_kbytes, 
																						VALUE	rb_additional_max_size_bytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	c_environment_cache_settings_controller,
																				FIX2INT( rb_max_size_mbytes ),
																				FIX2INT( rb_additional_max_size_kbytes ),
																				FIX2INT( rb_additional_max_size_bytes ) );

		return rb_environment_cache_settings_controller;
	}

	/*********************************
	*  set_max_size_in_kbytes_bytes  *
	*********************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_environment_cache_settings_controller, 
																		  		VALUE	rb_max_size_kbytes, 
																		  		VALUE	rb_additional_max_size_bytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes(	c_environment_cache_settings_controller,
																			FIX2INT( rb_max_size_kbytes ),
																			FIX2INT( rb_additional_max_size_bytes ));

		return rb_environment_cache_settings_controller;
	}

