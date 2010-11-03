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

	VALUE	rb_memory_pool_file_page	=	RUBY_RPDB_MEMORY_POOL_FILE_PAGE( RPDB_MemoryPoolFilePage_new( c_memory_pool_file_page_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_memory_pool_file_page_controller;
	
	rb_obj_call_init(	rb_memory_pool_file_page,
					 1, 
					 argv );
	
	return rb_memory_pool_file_page;	
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFilePage_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page )	{

	RPDB_MemoryPoolFilePage*	c_memory_pool_file_page;
	C_RPDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );

	return RUBY_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( RPDB_MemoryPoolFilePage_settingsController( c_memory_pool_file_page ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page )	{

	RPDB_MemoryPoolFilePage*		c_memory_pool_file_page;
	C_RPDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolFilePage_parentEnvironment( c_memory_pool_file_page ) );

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





