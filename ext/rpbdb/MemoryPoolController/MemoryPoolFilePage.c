/*
 *		RPbdb::MemoryPoolController::MemoryPoolFile::MemoryPoolFilePageController::MemoryPoolFilePage
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MemoryPoolFilePage.h"
#include "MemoryPoolFile.h"
#include "MemoryPoolFileController.h"
#include "MemoryPoolController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MemoryPoolFilePage.h>

#include <rpbdb/MemoryPoolFilePageSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_MemoryPoolController;
extern	VALUE	rb_RPbdb_MemoryPoolFileController;
extern	VALUE	rb_RPbdb_MemoryPoolFilePageController;
extern	VALUE	rb_RPbdb_MemoryPoolFile;
extern	VALUE	rb_RPbdb_MemoryPoolFilePage;
extern	VALUE	rb_RPbdb_MemoryPoolFilePageSettingsController;

void Init_rb_RPbdb_MemoryPoolFilePage()	{

	rb_RPbdb_MemoryPoolFilePage	=	rb_define_class_under(	rb_RPbdb_Environment, 
																																	"PageController",			
																																	rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MemoryPoolFilePage, 	"new",																													rb_RPbdb_MemoryPoolFilePage_new,																							-1 	);
	rb_define_method(						rb_RPbdb_MemoryPoolFilePage, 	"initialize",																										rb_RPbdb_MemoryPoolFilePage_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_MemoryPoolFilePage, 	"settings_controller",																					rb_RPbdb_MemoryPoolFilePage_settingsController,															0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_MemoryPoolFilePage, 	"parent_environment",																						rb_RPbdb_MemoryPoolFilePage_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_MemoryPoolFilePage, 	"write_page_to_cache",																					rb_RPbdb_MemoryPoolFilePage_writePageToCache,																				0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"write_to_cache",																								"write_page_to_cache"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePage, 	"write",																												"write_page_to_cache"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolFilePage_new( int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_memory_pool_controller						=	Qnil;
	VALUE	rb_parent_memory_pool_file_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file									=	Qnil;
	VALUE	rb_parent_memory_pool_file_page_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_RPbdb_MemoryPoolController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_controller, rb_RPbdb_MemoryPoolFileController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file, rb_RPbdb_MemoryPoolFile ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_page_controller, rb_RPbdb_MemoryPoolFilePageController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]",
			"[ <parent memory pool file controller> ]",
			"[ <parent memory pool file> ]",
			"[ <parent memory pool file page controller> ]"
		)
	);

	RPbdb_MemoryPoolFilePageController*	c_memory_pool_file_page_controller;
	C_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_parent_memory_pool_file_page_controller, c_memory_pool_file_page_controller );

	//	FIX - this is probably not correct
	RPbdb_MemoryPoolFilePage*	c_memory_pool_file_page	=	RPbdb_MemoryPoolFilePage_new( c_memory_pool_file_page_controller );

	VALUE	rb_memory_pool_file_page	=	RUBY_RPBDB_MEMORY_POOL_FILE_PAGE( c_memory_pool_file_page );
	
	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file_page,
							RPBDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER,
							rb_parent_memory_pool_file_page_controller );
	
	VALUE	argv[]	=	{ rb_parent_memory_pool_file_page_controller };
	rb_obj_call_init(	rb_memory_pool_file_page,
										 1, 
										 argv );
	
	return rb_memory_pool_file_page;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolFilePage_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/

VALUE rb_RPbdb_MemoryPoolFilePage_settingsController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_local_memory_pool_file_page_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_file_page_settings_controller = rb_iv_get(	rb_memory_pool_file_page,
																																					RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_MemoryPoolFilePage*		c_memory_pool_file_page;
		C_RPBDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );
	
		RPbdb_MemoryPoolFilePageSettingsController*	c_local_memory_pool_file_page_settings_controller	=	RPbdb_MemoryPoolFilePage_settingsController( c_memory_pool_file_page );

		rb_local_memory_pool_file_page_settings_controller	=	RUBY_RPBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_local_memory_pool_file_page_settings_controller );

		rb_iv_set(	rb_memory_pool_file_page,
								RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
								rb_local_memory_pool_file_page_settings_controller );
	}

	return rb_local_memory_pool_file_page_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_MemoryPoolFilePage_parentEnvironment(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_controller	=	rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFileController( rb_memory_pool_file_page );
	VALUE	rb_parent_environment							=	rb_RPbdb_MemoryPoolController_parentEnvironment( rb_parent_memory_pool_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file_controller	=	rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFileController( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_controller			=	rb_RPbdb_MemoryPoolFileController_parentMemoryPoolController( rb_parent_memory_pool_file_controller );
	
	return rb_parent_memory_pool_controller;
}

/***************************************
*  parent_memory_pool_file_controller  *
***************************************/
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file	=	rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFile( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_file_controller	=	rb_RPbdb_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file );
	
	return rb_parent_memory_pool_file_controller;
}

/***************************************
*  parent_memory_pool_file  *
***************************************/
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file_page_controller	=	rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFilePageController( rb_memory_pool_file_page );
	VALUE	rb_parent_memory_pool_file									=	rb_RPbdb_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file_page_controller );
	
	return rb_parent_memory_pool_file;
}

/***************************************
*  parent_memory_pool_file  *
***************************************/
VALUE rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolFilePageController(	VALUE	rb_memory_pool_file_page )	{

	VALUE	rb_parent_memory_pool_file	=	rb_iv_get(	rb_memory_pool_file_page,
																									RPBDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER );
	
	return rb_parent_memory_pool_file;
}

/*************************
*  writePageToCache  *
*************************/

//	The DB_MPOOLFILE->put method returns a reference to a page in the cache, setting the priority of the page as specified by the priority parameter.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fput.html
VALUE rb_RPbdb_MemoryPoolFilePage_writePageToCache( VALUE	rb_memory_pool_file_page )	{

	RPbdb_MemoryPoolFilePage*		c_memory_pool_file_page;
	C_RPBDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page );

	RPbdb_MemoryPoolFilePageController_writePageToCache( c_memory_pool_file_page );
	
	return rb_memory_pool_file_page;
}





