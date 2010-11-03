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
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"initialize",													rb_RPDB_EnvironmentCacheSettingsController_init,														-1 	);
                        			                                        
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"parent_environment",									rb_RPDB_EnvironmentCacheSettingsController_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_EnvironmentCacheSettingsController, 	"environment",												"parent_environment"	);

	//	FIX - make one max_size and set_max_size function w/dynamic options
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_buffering,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOn,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOff,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytesKBytesBytes,													0 	);
	rb_define_method(						rb_RPDB_EnvironmentCacheSettingsController, 	"shm_key",														rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytesBytes,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

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

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	
	rb_obj_call_init(	rb_environment_cache_settings_controller,
									 1, 
									 argv );
	
	return rb_environment_cache_settings_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_EnvironmentCacheSettingsController_init(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_EnvironmentCacheSettingsController_parentEnvironment(	VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_EnvironmentCacheSettingsController_parentEnvironment( c_environment_cache_settings_controller ) );
}

/********************
*  buffering  *
********************/

//	DB_DIRECT_DB            http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_buffering( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return ( RPDB_EnvironmentCacheSettingsController_buffering( c_environment_cache_settings_controller )	?	Qtrue
																											:	Qfalse );
}

	/************************
	*  turnBufferingOn  *
	************************/

	VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOn( VALUE	rb_environment_cache_settings_controller )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );
	
		RPDB_EnvironmentCacheSettingsController_turnBufferingOn( c_environment_cache_settings_controller );
	
		return rb_environment_cache_settings_controller;
	}

	/************************
	*  turnBufferingOff  *
	************************/

	VALUE rb_RPDB_EnvironmentCacheSettingsController_turnBufferingOff( VALUE	rb_environment_cache_settings_controller )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_turnBufferingOff( c_environment_cache_settings_controller );

		return rb_environment_cache_settings_controller;
	}


/************************
*  maxSizeInBytes  *
************************/

//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInBytes( c_environment_cache_settings_controller ) );
}

/********************
*  maxSizeInKBytes  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInKBytes( c_environment_cache_settings_controller ) );
}

/********************
*  maxSizeInMBytes  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInMBytes( c_environment_cache_settings_controller ) );
}

/********************
*  maxSizeInGBytes  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cachesize.html
VALUE rb_RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes( VALUE	rb_environment_cache_settings_controller )	{

	RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
	C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

	return INT2NUM( RPDB_EnvironmentCacheSettingsController_maxSizeInGBytes( c_environment_cache_settings_controller ) );
}

	/************************
	*  setMaxSizeInBytes  *
	************************/

	//http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_in_bytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInBytes(	c_environment_cache_settings_controller,
		 															NUM2LONG( rb_max_size_in_bytes ) );

		return rb_environment_cache_settings_controller;
	}

	/************************
	*  setMaxSizeInKBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_kbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInKBytes(	c_environment_cache_settings_controller,
		 																NUM2LONG( rb_max_size_kbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/************************
	*  setMaxSizeInMBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_mbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInMBytes(	c_environment_cache_settings_controller,
																		NUM2LONG( rb_max_size_mbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/************************
	*  setMaxSizeInGBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_environment_cache_settings_controller, 
																			VALUE	rb_max_size_gbytes )	{

		RPDB_EnvironmentCacheSettingsController*	c_environment_cache_settings_controller;
		C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller );

		RPDB_EnvironmentCacheSettingsController_setMaxSizeInGBytes(	c_environment_cache_settings_controller,
																		FIX2INT( rb_max_size_gbytes ) );

		return rb_environment_cache_settings_controller;
	}

	/****************************************
	*  setMaxSizeInGBytesMBytesKBytesBytes  *
	****************************************/

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

	/********************************
	*  setMaxSizeInMBytesKBytesBytes  *
	********************************/

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

	/****************************
	*  setMaxSizeInKBytesBytes  *
	****************************/

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

