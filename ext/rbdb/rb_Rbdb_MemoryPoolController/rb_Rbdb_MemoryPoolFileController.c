/*
 *		Rbdb::MemoryPoolFileController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_MemoryPoolFileController.h"
#include "rb_Rbdb_MemoryPoolController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_MemoryPoolFileController.h>
#include <rbdb/Rbdb_MemoryPoolFile.h>
#include <rbdb/Rbdb_MemoryPoolFilePage.h>

#include <rbdb/Rbdb_MemoryPoolFileSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;	
extern	VALUE	rb_Rbdb_MemoryPoolController;
extern	VALUE	rb_Rbdb_MemoryPoolFileController;
extern	VALUE	rb_Rbdb_MemoryPoolFileSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolFilePage;
extern	VALUE	rb_Rbdb_MemoryPoolFile;

void Init_rb_Rbdb_MemoryPoolFileController()	{

	rb_Rbdb_MemoryPoolFileController	=	rb_define_class_under(	rb_Rbdb_Environment, 
																															"FileController",			
																															rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MemoryPoolFileController, 	"new",										rb_Rbdb_MemoryPoolFileController_new,										-1 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFileController, 	"initialize",							rb_Rbdb_MemoryPoolFileController_initialize,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_Rbdb_MemoryPoolFileController, 	"settings_controller",		rb_Rbdb_MemoryPoolFileController_settingsController,		0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_Rbdb_MemoryPoolFileController, 	"parent_environment",			rb_Rbdb_MemoryPoolFileController_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"environment",						"parent_environment"	);                              	
                                                                                                                                                  	
	rb_define_method(						rb_Rbdb_MemoryPoolFileController, 	"create_file",						rb_Rbdb_MemoryPoolFileController_createFile,						0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"create",									"create_file"	);                                      	
	rb_define_method(						rb_Rbdb_MemoryPoolFileController, 	"open_file",							rb_Rbdb_MemoryPoolFileController_openFile,							0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFileController, 	"open",										"open_file"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MemoryPoolFileController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment										=	Qnil;
	VALUE	rb_parent_memory_pool_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_Rbdb_MemoryPoolController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]"
		)
	);

	Rbdb_MemoryPoolController*	c_parent_memory_pool_controller;
	C_RBDB_MEMORY_POOL_CONTROLLER( rb_parent_memory_pool_controller, c_parent_memory_pool_controller );

	VALUE	rb_memory_pool_file_controller	=	RUBY_RBDB_MEMORY_POOL_FILE_CONTROLLER( Rbdb_MemoryPoolFileController_new( c_parent_memory_pool_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file_controller,
							RBDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER,
							rb_parent_memory_pool_controller );
	
	VALUE	argv[]	=	{ rb_parent_memory_pool_controller };
	rb_obj_call_init(	rb_memory_pool_file_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_controller;	
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MemoryPoolFileController_initialize(	int				argc __attribute__ ((unused)),
																							VALUE*		args __attribute__ ((unused)),
																							VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/

VALUE rb_Rbdb_MemoryPoolFileController_settingsController(	VALUE	rb_memory_pool_file_controller )	{

	VALUE	rb_local_memory_pool_file_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_file_settings_controller = rb_iv_get(	rb_memory_pool_file_controller,
																																		RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_MemoryPoolFileController*		c_memory_pool_file_controller;
		C_RBDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );
	
		Rbdb_MemoryPoolFileSettingsController*	c_local_memory_pool_settings_controller	=	Rbdb_MemoryPoolFileController_settingsController( c_memory_pool_file_controller );

		rb_local_memory_pool_file_settings_controller	=	RUBY_RBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_local_memory_pool_settings_controller );

		rb_iv_set(	rb_memory_pool_file_controller,
								RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
								rb_local_memory_pool_file_settings_controller );
	}

	return rb_local_memory_pool_file_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_Rbdb_MemoryPoolFileController_parentEnvironment(	VALUE	rb_memory_pool_file_controller )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_Rbdb_MemoryPoolFileController_parentMemoryPoolController( rb_memory_pool_file_controller );
	VALUE	rb_parent_environment							=	rb_Rbdb_MemoryPoolController_parentEnvironment( rb_parent_memory_pool_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/
VALUE rb_Rbdb_MemoryPoolFileController_parentMemoryPoolController(	VALUE	rb_memory_pool_file_controller )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_iv_get(	rb_memory_pool_file_controller,
																												RBDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER );
	
	return rb_parent_memory_pool_controller;
}

/*****************
*  createFile  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fcreate.html
VALUE rb_Rbdb_MemoryPoolFileController_createFile( VALUE	rb_memory_pool_file_controller )	{

	Rbdb_MemoryPoolFileController*		c_memory_pool_file_controller;
	C_RBDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );

	return RUBY_RBDB_MEMORY_POOL_FILE_PAGE( Rbdb_MemoryPoolFileController_createFile( c_memory_pool_file_controller ) );	
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
VALUE rb_Rbdb_MemoryPoolFileController_openFile(	VALUE	rb_memory_pool_file_controller,
 													VALUE	rb_file_path,
													//	This should be broken down into functions that specify the type of mode, probably
													VALUE	rb_chmod_mode,
													//	How do we determine how large pagesize should be?
													VALUE	rb_pagesize_in_bytes )	{

	Rbdb_MemoryPoolFileController*		c_memory_pool_file_controller;
	C_RBDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller );
	
	return RUBY_RBDB_MEMORY_POOL_FILE( Rbdb_MemoryPoolFileController_openFile(	c_memory_pool_file_controller,
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
VALUE rb_Rbdb_MemoryPoolFileController_setPageInMethod(		VALUE	rb_memory_pool_file_controller,
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
						VALUE		page_cookie	) Rbdb_MemoryPoolFileController_pageInMethod(		VALUE	rb_memory_pool_file_controller )	{
	
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
VALUE rb_Rbdb_MemoryPoolFileController_setPageOutMethod(		VALUE	rb_memory_pool_file_controller,
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
						VALUE		page_cookie	) Rbdb_MemoryPoolFileController_pageOutMethod(		VALUE	rb_memory_pool_file_controller )	{
	
}

*/