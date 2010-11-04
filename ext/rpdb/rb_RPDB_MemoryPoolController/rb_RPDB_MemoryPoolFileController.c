/*
 *		RPDB::MemoryPoolFileController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolFileController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolFileController.h>
#include <rpdb/RPDB_MemoryPoolFile.h>
#include <rpdb/RPDB_MemoryPoolFilePage.h>

#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;	
extern	VALUE	rb_RPDB_MemoryPoolController;
extern	VALUE	rb_RPDB_MemoryPoolFileController;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFilePage;
extern	VALUE	rb_RPDB_MemoryPoolFile;

void Init_RPDB_MemoryPoolFileController()	{

	rb_RPDB_MemoryPoolFileController	=	rb_define_class_under(	rb_RPDB_Environment, 
																															"FileController",			
																															rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFileController, 	"new",										rb_RPDB_MemoryPoolFileController_new,										-1 	);
	rb_define_method(						rb_RPDB_MemoryPoolFileController, 	"initialize",							rb_RPDB_MemoryPoolFileController_init,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_RPDB_MemoryPoolFileController, 	"settings_controller",		rb_RPDB_MemoryPoolFileController_settingsController,		0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_RPDB_MemoryPoolFileController, 	"parent_environment",			rb_RPDB_MemoryPoolFileController_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"environment",						"parent_environment"	);                              	
                                                                                                                                                  	
	rb_define_method(						rb_RPDB_MemoryPoolFileController, 	"create_file",						rb_RPDB_MemoryPoolFileController_createFile,						0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"create",									"create_file"	);                                      	
	rb_define_method(						rb_RPDB_MemoryPoolFileController, 	"open_file",							rb_RPDB_MemoryPoolFileController_openFile,							0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFileController, 	"open",										"open_file"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFileController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment										=	Qnil;
	VALUE	rb_parent_memory_pool_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_RPDB_MemoryPoolController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]"
		)
	);

	RPDB_MemoryPoolController*	c_parent_memory_pool_controller;
	C_RPDB_MEMORY_POOL_CONTROLLER( rb_parent_memory_pool_controller, c_parent_memory_pool_controller );

	VALUE	rb_memory_pool_file_controller	=	RUBY_RPDB_MEMORY_POOL_FILE_CONTROLLER( RPDB_MemoryPoolFileController_new( c_parent_memory_pool_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file_controller,
							RPDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER,
							rb_parent_memory_pool_controller );
	
	VALUE	argv[]	=	{ rb_parent_memory_pool_controller };
	rb_obj_call_init(	rb_memory_pool_file_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_controller;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFileController_init(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_MemoryPoolFileController_settingsController(	VALUE	rb_memory_pool_file_controller )	{

	RPDB_MemoryPoolFileController*	c_memory_pool_file_controller;
	C_RPDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( RPDB_MemoryPoolFileController_settingsController( c_memory_pool_file_controller ) );

}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolFileController_parentEnvironment(	VALUE	rb_memory_pool_file_controller )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_RPDB_MemoryPoolFileController_parentMemoryPoolController( rb_memory_pool_file_controller );
	VALUE	rb_parent_environment							=	rb_RPDB_MemoryPoolController_parentEnvironment( rb_parent_memory_pool_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/
VALUE rb_RPDB_MemoryPoolFileController_parentMemoryPoolController(	VALUE	rb_memory_pool_file_controller )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_iv_get(	rb_memory_pool_file_controller,
																												RPDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER );
	
	return rb_parent_memory_pool_controller;
}

/*****************
*  createFile  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fcreate.html
VALUE rb_RPDB_MemoryPoolFileController_createFile( VALUE	rb_memory_pool_file_controller )	{

	RPDB_MemoryPoolFileController*		c_memory_pool_file_controller;
	C_RPDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );

	return RUBY_RPDB_MEMORY_POOL_FILE_PAGE( RPDB_MemoryPoolFileController_createFile( c_memory_pool_file_controller ) );	
}

/*****************
*  openFile  *
*****************/

//	The file parameter is the name of the file to be opened. 
//	If file is NULL, a private temporary file is created that cannot be shared with any other process 
//	(although it may be shared with other threads of control in the same process).
//	The pagesize parameter is the size, in bytes, of the unit of transfer between the application and the cache, 
//	although it is not necessarily the unit of transfer between the cache and the underlying filesystem.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fopen.html
VALUE rb_RPDB_MemoryPoolFileController_openFile(	VALUE	rb_memory_pool_file_controller,
 													VALUE	rb_file_path,
													//	This should be broken down into functions that specify the type of mode, probably
													VALUE	rb_chmod_mode,
													//	How do we determine how large pagesize should be?
													VALUE	rb_pagesize_in_bytes )	{

	RPDB_MemoryPoolFileController*		c_memory_pool_file_controller;
	C_RPDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );
	
	return RUBY_RPDB_MEMORY_POOL_FILE( RPDB_MemoryPoolFileController_openFile(	c_memory_pool_file_controller,
																					StringValuePtr( rb_file_path ),
																					FIX2INT( rb_chmod_mode ),
																					NUM2INT( rb_pagesize_in_bytes ) ) );	
}

/*******************************************************************************************************************************************************************************************
																		Callback Public Methods
*******************************************************************************************************************************************************************************************/

/**************************
*  setPageInMethod  *
**************************/
/*
//	The ftype parameter specifies the type of file for which the page-in and page-out functions will be called.
//	The ftype value for a file must be a non-zero positive number less than 128 
//	(0 and negative numbers are reserved for internal use by the Berkeley DB library).
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_register.html
VALUE rb_RPDB_MemoryPoolFileController_setPageInMethod(		VALUE	rb_memory_pool_file_controller,
															VALUE								file_type,
															VALUE								(*page_in_method)(	VALUE			environment,
															   														VALUE			page_data,
															   														VALUE		page_cookie	))	{
}
*/
/**********************
*  pageInMethod  *
**********************/
/*
VALUE(*page_in_method)(	VALUE			environment,
						VALUE			page_data,
						VALUE		page_cookie	) RPDB_MemoryPoolFileController_pageInMethod(		VALUE	rb_memory_pool_file_controller )	{
	
}
*/
/**************************
*  setPageOutMethod  *
**************************/
/*
//	The ftype parameter specifies the type of file for which the page-in and page-out functions will be called.
//	The ftype value for a file must be a non-zero positive number less than 128 
//	(0 and negative numbers are reserved for internal use by the Berkeley DB library).
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_register.html
VALUE rb_RPDB_MemoryPoolFileController_setPageOutMethod(		VALUE	rb_memory_pool_file_controller,
															VALUE								file_type,
															VALUE								(*page_out_method)(	VALUE			environment,
															   									 					VALUE			page_data,
															   									 					VALUE		page_cookie	) )	{
	
}
*/
/**********************
*  pageOutMethod  *
**********************/
/*
VALUE(*page_out_method)(	VALUE			environment,
						VALUE			page_data,
						VALUE		page_cookie	) RPDB_MemoryPoolFileController_pageOutMethod(		VALUE	rb_memory_pool_file_controller )	{
	
}

*/