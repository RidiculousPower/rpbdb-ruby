/*
 *		RPDB::MemoryPoolController::MemoryPoolFile::MemoryPoolFilePageController::MemoryPoolFilePage
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolFilePage.h"
#include "rb_RPDB_MemoryPoolFile.h"
#include "rb_RPDB_MemoryPoolFileController.h"
#include "rb_RPDB_MemoryPoolController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolFilePage.h>

#include <rpdb/RPDB_MemoryPoolFilePageSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_MemoryPoolController;
extern	VALUE	rb_RPDB_MemoryPoolFileController;
extern	VALUE	rb_RPDB_MemoryPoolFilePageController;
extern	VALUE	rb_RPDB_MemoryPoolFile;
extern	VALUE	rb_RPDB_MemoryPoolFilePage;
extern	VALUE	rb_RPDB_MemoryPoolFilePageSettingsController;

void Init_RPDB_MemoryPoolFilePage()	{

	rb_RPDB_MemoryPoolFilePage	=	rb_define_class_under(	rb_RPDB_Environment, 
																																	"PageController",			
																																	rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFilePage, 	"new",																													rb_RPDB_MemoryPoolFilePage_new,																							-1 	);
	rb_define_method(						rb_RPDB_MemoryPoolFilePage, 	"initialize",																										rb_RPDB_MemoryPoolFilePage_init,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_MemoryPoolFilePage, 	"settings_controller",																					rb_RPDB_MemoryPoolFilePage_settingsController,															0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_MemoryPoolFilePage, 	"parent_environment",																						rb_RPDB_MemoryPoolFilePage_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPDB_MemoryPoolFilePage, 	"write_page_to_cache",																					rb_RPDB_MemoryPoolFilePage_writePageToCache,																				0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"write_to_cache",																								"write_page_to_cache"	);
	rb_define_alias(						rb_RPDB_MemoryPoolFilePage, 	"write",																												"write_page_to_cache"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFilePage_new( int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_memory_pool_controller						=	Qnil;
	VALUE	rb_parent_memory_pool_file_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file									=	Qnil;
	VALUE	rb_parent_memory_pool_file_page_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_RPDB_MemoryPoolController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_controller, rb_RPDB_MemoryPoolFileController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file, rb_RPDB_MemoryPoolFile ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_page_controller, rb_RPDB_MemoryPoolFilePageController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]",
			"[ <parent memory pool file controller> ]",
			"[ <parent memory pool file> ]",
			"[ <parent memory pool file page controller> ]"
		)
	);

	RPDB_MemoryPoolFilePageController*	c_memory_pool_file_page_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_parent_memory_pool_file_page_controller, c_memory_pool_file_page_controller );

	//	FIX - this is probably not correct
	RPDB_MemoryPoolFilePage*	c_memory_pool_file_page	=	RPDB_MemoryPoolFilePage_new( c_memory_pool_file_page_controller );

	VALUE	rb_memory_pool_file_page	=	RUBY_RPDB_MEMORY_POOL_FILE_PAGE( c_memory_pool_file_page );
	
	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file_page,
							RPDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER,
							rb_parent_memory_pool_file_page_controller );
	
	VALUE	argv[]	=	{ rb_parent_memory_pool_file_page_controller };
	rb_obj_call_initialize(	rb_memory_pool_file_page,
										 1, 
										 argv );
	
	return rb_memory_pool_file_page;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFilePage_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/

VALUE rb_RPDB_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_local_memory_pool_file_page_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_file_page_settings_controller = rb_iv_get(	rb_memory_pool_file_page,
																																					RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_MemoryPoolFilePage*		c_memory_pool_file_page;
		C_RPDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );
	
		RPDB_MemoryPoolFilePageSettingsController*	c_local_memory_pool_file_page_settings_controller	=	RPDB_MemoryPoolFilePage_settingsController( c_memory_pool_file_page );

		rb_local_memory_pool_file_page_settings_controller	=	RUBY_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_local_memory_pool_file_page_settings_controller );

		rb_iv_set(	rb_memory_pool_file_page,
								RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
								rb_local_memory_pool_file_page_settings_controller );
	}

	return rb_local_memory_pool_file_page_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFileController( rb_memory_pool_file_page );
	VALUE	rb_parent_environment							=	rb_RPDB_MemoryPoolController_parentEnvironment( rb_parent_memory_pool_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file_controller	=	rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFileController( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_controller			=	rb_RPDB_MemoryPoolFileController_parentMemoryPoolController( rb_parent_memory_pool_file_controller );
	
	return rb_parent_memory_pool_controller;
}

/***************************************
*  parent_memory_pool_file_controller  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file	=	rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFile( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_file_controller	=	rb_RPDB_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file );
	
	return rb_parent_memory_pool_file_controller;
}

/***************************************
*  parent_memory_pool_file  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file_page_controller	=	rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFilePageController( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_file									=	rb_RPDB_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file_page_controller );
	
	return rb_parent_memory_pool_file;
}

/***************************************
*  parent_memory_pool_file  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentMemoryPoolFilePageController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file	=	rb_iv_get(	rb_memory_pool_file_page,
																									RPDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER );
	
	return rb_parent_memory_pool_file;
}

/*************************
*  writePageToCache  *
*************************/

//	The DB_MPOOLFILE->put method returns a reference to a page in the cache, setting the priority of the page as specified by the priority parameter.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fput.html
VALUE rb_RPDB_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page )	{

	RPDB_MemoryPoolFilePage*		c_memory_pool_file_page;
	C_RPDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );

	RPDB_MemoryPoolFilePageController_writePageToCache( c_memory_pool_file_page );
	
	return rb_memory_pool_file_page;
}





