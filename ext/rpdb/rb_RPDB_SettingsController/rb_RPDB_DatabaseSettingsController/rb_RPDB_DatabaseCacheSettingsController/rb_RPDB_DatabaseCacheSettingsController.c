/*
 *		RPDB::RPDB_SettingsController::RPDB_DatabaseCacheSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseCacheSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseCacheSettingsController.h>
#include <rpdb/RPDB_DatabaseCachePrioritySettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;

extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseCacheSettingsController;
extern	VALUE	rb_RPDB_DatabaseCachePrioritySettingsController;

void Init_RPDB_DatabaseCacheSettingsController()	{

	rb_RPDB_DatabaseCacheSettingsController			=		rb_define_class_under(	rb_RPDB_DatabaseSettingsController, 			
																																					"Cache",							
																																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseCacheSettingsController, 	"new",																					rb_RPDB_DatabaseCacheSettingsController_new,												1 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"initialize",																		rb_RPDB_DatabaseCacheSettingsController_init,												1 	);

	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"parent_environment",														rb_RPDB_DatabaseCacheSettingsController_parentEnvironment,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseCacheSettingsController, 	"environment",																	"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"parent_database",															rb_RPDB_DatabaseCacheSettingsController_parentDatabase,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseCacheSettingsController, 	"database",																			"parent_database"	);

	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"max_size_in_bytes",														rb_RPDB_DatabaseCacheSettingsController_maxSizeInBytes,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"max_size_in_kbytes",														rb_RPDB_DatabaseCacheSettingsController_maxSizeInKBytes,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"max_size_in_mbytes",														rb_RPDB_DatabaseCacheSettingsController_maxSizeInMBytes,									0 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"max_size_in_gbytes",														rb_RPDB_DatabaseCacheSettingsController_maxSizeInGBytes,									0 	);

	//	FIX - these can be made to work with = assignments in various forms (for instance as an array)
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_bytes",												rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInBytes,									1 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_kbytes",												rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytes,								1 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_mbytes",												rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytes,								1 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_gbytes",												rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytes,								1 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_gbytes_mbytes_kbytes_bytes",		rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes,				4 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_mbytes_kbytes_bytes",					rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytesKBytesBytes,						3 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"set_max_size_in_kbytes_bytes",									rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytesBytes,							2 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"number_cache_regions",													rb_RPDB_DatabaseCacheSettingsController_numberCacheRegions,								0 	);
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"number_cache_regions=",												rb_RPDB_DatabaseCacheSettingsController_setNumberCacheRegions,								1 	);
	rb_define_alias(						rb_RPDB_DatabaseCacheSettingsController, 	"set_number_cache_regions",											"number_cache_regions=" 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseCacheSettingsController, 	"priority_controller",													rb_RPDB_DatabaseCacheSettingsController_priorityController,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseCacheSettingsController, 	"priority",																			"priority_controller"	);	
	rb_define_alias(						rb_RPDB_DatabaseCacheSettingsController, 	"priorities",																		"priority_controller"	);	
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_DatabaseCacheSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_database_settings_controller )	{
	
	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );
	
	VALUE	rb_database_cache_settings_controller	= RUBY_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( RPDB_DatabaseCacheSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_cache_settings_controller,
					 					1, 
					 					argv );
	
	return rb_database_cache_settings_controller;		
}

/*********
*  init  *
*********/

VALUE rb_RPDB_DatabaseCacheSettingsController_init(	VALUE	rb_database_cache_settings_controller,
																										VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{

	return rb_database_cache_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseCacheSettingsController_parentEnvironment(	VALUE	rb_database_cache_settings_controller )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseCacheSettingsController_parentEnvironment( c_database_cache_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseCacheSettingsController_parentDatabase(	VALUE	rb_database_cache_settings_controller )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseCacheSettingsController_parentDatabase( c_database_cache_settings_controller ) );

}

/********************
*  maxSizeInBytes  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_cachesize.html
//	Because databases opened within Berkeley DB environments use the cache specified to the environment, 
//	it is an error to attempt to set a cache in a database created within an environment.
VALUE rb_RPDB_DatabaseCacheSettingsController_maxSizeInBytes( VALUE	rb_database_cache_settings_controller )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	return INT2NUM( RPDB_DatabaseCacheSettingsController_maxSizeInBytes( c_database_cache_settings_controller ) );
}

	/********************
	*  maxSizeInKBytes  *
	********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_cachesize.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_maxSizeInKBytes( VALUE	rb_database_cache_settings_controller )	{
		
		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		return INT2NUM( RPDB_DatabaseCacheSettingsController_maxSizeInKBytes( c_database_cache_settings_controller ) );
	}

	/********************
	*  maxSizeInMBytes  *
	********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_cachesize.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_maxSizeInMBytes( VALUE	rb_database_cache_settings_controller )	{
	
		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		return INT2NUM( RPDB_DatabaseCacheSettingsController_maxSizeInMBytes( c_database_cache_settings_controller ) );
	}

	/********************
	*  maxSizeInGBytes  *
	********************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_cachesize.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_maxSizeInGBytes( VALUE	rb_database_cache_settings_controller )	{
		
		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		return INT2FIX( RPDB_DatabaseCacheSettingsController_maxSizeInGBytes( c_database_cache_settings_controller ) );
	}

/************************
*  setMaxSizeInBytes  *
************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_set_cachesize.html
//	Because databases opened within Berkeley DB environments use the cache specified to the environment, 
//	it is an error to attempt to set a cache in a database created within an environment.
VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInBytes(	VALUE	rb_database_cache_settings_controller, 
																	VALUE	rb_max_size_in_bytes )	{
	
	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	RPDB_DatabaseCacheSettingsController_setMaxSizeInBytes(	c_database_cache_settings_controller,
	 															FIX2INT( rb_max_size_in_bytes ) );
	
	return rb_database_cache_settings_controller;
}

	/************************
	*  setMaxSizeInKBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytes(	VALUE	rb_database_cache_settings_controller, 
																		VALUE	rb_max_size_kbytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytes(	c_database_cache_settings_controller,
		 															FIX2INT( rb_max_size_kbytes ) );

		return rb_database_cache_settings_controller;
	}

	/************************
	*  setMaxSizeInMBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytes(	VALUE	rb_database_cache_settings_controller, 
																		VALUE	rb_max_size_mbytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytes(	c_database_cache_settings_controller,
		 															FIX2INT( rb_max_size_mbytes ) );

		return rb_database_cache_settings_controller;
	}

	/************************
	*  setMaxSizeInGBytes  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytes(	VALUE	rb_database_cache_settings_controller, 
																		VALUE	rb_max_size_gbytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytes(	c_database_cache_settings_controller,
		 															FIX2INT( rb_max_size_gbytes ) );

		return rb_database_cache_settings_controller;
	}

	/****************************************
	*  setMaxSizeInGBytesMBytesKBytesBytes  *
	****************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																						VALUE	rb_max_size_gbytes, 
																						VALUE	rb_additional_max_size_mbytes, 
																						VALUE	rb_additional_max_size_kbytes, 
																						VALUE	rb_additional_max_size_in_bytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );
		
		RPDB_DatabaseCacheSettingsController_setMaxSizeInGBytesMBytesKBytesBytes(	c_database_cache_settings_controller,
		 																			FIX2INT( rb_max_size_gbytes ),
																					FIX2INT( rb_additional_max_size_mbytes ),
																					FIX2INT( rb_additional_max_size_kbytes ),
																					FIX2INT( rb_additional_max_size_in_bytes ) );

		return rb_database_cache_settings_controller;
	}

	/************************************
	*  setMaxSizeInMBytesKBytesBytes  *
	************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																					VALUE	rb_max_size_mbytes, 
																					VALUE	rb_additional_max_size_kbytes, 
																					VALUE	rb_additional_max_size_bytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );
		
		RPDB_DatabaseCacheSettingsController_setMaxSizeInMBytesKBytesBytes(	c_database_cache_settings_controller,
																				FIX2INT( rb_max_size_mbytes ),
																				FIX2INT( rb_additional_max_size_kbytes ),
																				FIX2INT( rb_additional_max_size_bytes ) );

		return rb_database_cache_settings_controller;
	}

	/****************************
	*  setMaxSizeInKBytesBytes  *
	****************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_cache_max.html
	VALUE rb_RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytesBytes(	VALUE	rb_database_cache_settings_controller, 
																			VALUE	rb_max_size_kbytes, 
																			VALUE	rb_additional_max_size_bytes )	{

		RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
		C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

		RPDB_DatabaseCacheSettingsController_setMaxSizeInKBytesBytes(	c_database_cache_settings_controller,
																		FIX2INT( rb_max_size_kbytes ),
																		FIX2INT( rb_additional_max_size_bytes ) );

		return rb_database_cache_settings_controller;
	}

/**************************
*  numberCacheRegions  *
**************************/

VALUE rb_RPDB_DatabaseCacheSettingsController_numberCacheRegions( VALUE	rb_database_cache_settings_controller )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	return INT2FIX( RPDB_DatabaseCacheSettingsController_numberCacheRegions( c_database_cache_settings_controller ) );
}

/****************************
*  setNumberCacheRegions  *
*****************************/

VALUE rb_RPDB_DatabaseCacheSettingsController_setNumberCacheRegions(	VALUE	rb_database_cache_settings_controller, 
																		VALUE	rb_number_cache_regions )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	RPDB_DatabaseCacheSettingsController_setNumberCacheRegions(	c_database_cache_settings_controller,
	 																FIX2INT( rb_number_cache_regions ) );
	
	return rb_database_cache_settings_controller;
}

/*********************
*  cacheUpdate  *
*********************/

	//	To be included in a later version:

/*
	//	Check cache statistics and attempt to estimate best size database. 
	//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/am_conf/cachesize.html
	RPDB_CacheUpdate* RPDB_DatabaseCacheSettingsController_cacheUpdate( VALUE	rb_database_cache_settings_controller )	{

		//	When using the Btree access method, you must have a cache big enough for the minimum working set for a single access.
		//		This will include a root page, one or more internal pages (depending on the depth of your tree), and a leaf page. 
		//	If your keys are of moderate size (a few tens of bytes) and your pages are on the order of 4KB to 8KB, most Btree applications will be only three levels.
		//	The rule-of-thumb is that cache is good, and more cache is better. 
		//	 Generally, applications benefit from increasing the cache size up to a point, at which the performance will stop improving as the cache size increases. 
		//		When this point is reached, one of two things have happened: 
		//			either the cache is large enough that the application is almost never having to retrieve information from disk, 
		//				or, 
		//			your application is doing truly random accesses, 
		//			and therefore increasing size of the cache doesn't significantly increase the odds of finding the next requested information in the cache.
		//	That said, it is important not to increase your cache size beyond the capabilities of your system, as that will result in reduced performance.
		//	Under many operating systems, tying down enough virtual memory will cause your memory and potentially your program to be swapped. 
		//		This is especially likely on systems without unified OS buffer caches and virtual memory spaces, 
		//		as the buffer cache was allocated at boot time and so cannot be adjusted based on application requests for large amounts of virtual memory.
		//	For example, even if accesses are truly random within a Btree, your access pattern will favor internal pages to leaf pages, 
		//		so your cache should be large enough to hold all internal pages. In the steady state, this requires at most one I/O per operation to retrieve the appropriate leaf page.
		//	You can use the db_stat utility to monitor the effectiveness of your cache.
	}
*/

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/**************************
*  priorityController  *
**************************/

VALUE rb_RPDB_DatabaseCacheSettingsController_priorityController( VALUE	rb_database_cache_settings_controller )	{

	RPDB_DatabaseCacheSettingsController*	c_database_cache_settings_controller;
	C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller );

	return RUBY_RPDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( RPDB_DatabaseCacheSettingsController_priorityController( c_database_cache_settings_controller ) );
}
