/*
 *		RPbdb::MemoryPoolController::MemoryPoolFile::MemoryPoolFilePageController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MemoryPoolFilePageController.h"
#include "MemoryPoolFile.h"
#include "MemoryPoolFileController.h"
#include "MemoryPoolFilePage.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MemoryPoolFilePageController.h>
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
extern	VALUE	rb_RPbdb_MemoryPoolFilePageSettingsController;
extern	VALUE	rb_RPbdb_MemoryPoolFile;
extern	VALUE	rb_RPbdb_MemoryPoolFilePage;


void Init_rb_RPbdb_MemoryPoolFilePageController()	{

	rb_RPbdb_MemoryPoolFilePageController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																																	"PageController",			
																																	rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MemoryPoolFilePageController, 	"new",																													rb_RPbdb_MemoryPoolFilePageController_new,																							-1 	);
	rb_define_method(						rb_RPbdb_MemoryPoolFilePageController, 	"initialize",																										rb_RPbdb_MemoryPoolFilePageController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_MemoryPoolFilePageController, 	"settings_controller",																					rb_RPbdb_MemoryPoolFilePageController_settingsController,															0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_MemoryPoolFilePageController, 	"parent_environment",																						rb_RPbdb_MemoryPoolFilePageController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_MemoryPoolFilePageController, 	"retrieve_page_from_cache",																			rb_RPbdb_MemoryPoolFilePageController_retrievePageFromCache,																				0 	);
	rb_define_alias(						rb_RPbdb_MemoryPoolFilePageController, 	"retrieve_page",																								"retrieve_page_from_cache"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolFilePageController_new(	int			argc,
																								VALUE*	args,
																								VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment												=	Qnil;
	VALUE	rb_parent_memory_pool_controller						=	Qnil;
	VALUE	rb_parent_memory_pool_file_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file									=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_RPbdb_MemoryPoolController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_controller, rb_RPbdb_MemoryPoolFileController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file, rb_RPbdb_MemoryPoolFile ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]",
			"[ <parent memory pool file controller> ]",
			"[ <parent memory pool file> ]"
		)
	);

	RPbdb_MemoryPoolFile*	c_parent_memory_pool_file;
	C_RPBDB_MEMORY_POOL_FILE( rb_parent_memory_pool_file, c_parent_memory_pool_file );
	
	//	FIX - should probably open page controller through file
	RPbdb_MemoryPoolFilePageController*	c_memory_pool_file_page_controller	=	RPbdb_MemoryPoolFilePageController_new( c_parent_memory_pool_file );
	
	VALUE	rb_memory_pool_file_page_controller	=	RUBY_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( c_memory_pool_file_page_controller );

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file_page_controller,
							RPBDB_RB_MEMORY_POOL_FILE_PAGE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE,
							rb_parent_memory_pool_file );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file };
	
	rb_obj_call_init(	rb_memory_pool_file_page_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_page_controller;	
}

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MemoryPoolFilePageController_initialize(	int				argc __attribute__ ((unused)),
																									VALUE*		args __attribute__ ((unused)),
																									VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_MemoryPoolFilePageController_settingsController(	VALUE	rb_memory_pool_file_page_controller )	{

	VALUE	rb_local_memory_pool_file_page_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_file_page_settings_controller = rb_iv_get(	rb_memory_pool_file_page_controller,
																																					RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_MemoryPoolFilePageController*		c_memory_pool_file_page_controller;
		C_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller );
	
		RPbdb_MemoryPoolFilePageSettingsController*	c_local_memory_pool_file_page_settings_controller	=	RPbdb_MemoryPoolFilePageController_settingsController( c_memory_pool_file_page_controller );

		rb_local_memory_pool_file_page_settings_controller	=	RUBY_RPBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_local_memory_pool_file_page_settings_controller );

		rb_iv_set(	rb_memory_pool_file_page_controller,
								RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER,
								rb_local_memory_pool_file_page_settings_controller );
	}

	return rb_local_memory_pool_file_page_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/

VALUE rb_RPbdb_MemoryPoolFilePageController_parentEnvironment(	VALUE	rb_memory_pool_file_page_controller )	{

	VALUE	rb_parent_memory_pool_file_controller		=	rb_RPbdb_MemoryPoolFilePage_parentMemoryPoolController( rb_memory_pool_file_page_controller );
	VALUE	rb_parent_environment										=	rb_RPbdb_MemoryPoolFileController_parentEnvironment( rb_parent_memory_pool_file_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/

VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolController(	VALUE	rb_memory_pool_file_page_controller )	{

	VALUE	rb_parent_memory_pool_file						=	rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFile( rb_memory_pool_file_page_controller );
	VALUE	rb_parent_memory_pool_controller			=	rb_RPbdb_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file );
	
	return rb_parent_memory_pool_controller;
}

/***************************************
*  parent_memory_pool_file_controller  *
***************************************/

VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file_page_controller )	{

	VALUE	rb_parent_memory_pool_file						=	rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFile( rb_memory_pool_file_page_controller );
	VALUE	rb_parent_memory_pool_file_controller	=	rb_RPbdb_MemoryPoolFile_parentMemoryPoolFileController( rb_parent_memory_pool_file );
	
	return rb_parent_memory_pool_file_controller;
}

/***************************************
*  parent_memory_pool_file  *
***************************************/

VALUE rb_RPbdb_MemoryPoolFilePageController_parentMemoryPoolFile(	VALUE	rb_memory_pool_file_page_controller )	{

	VALUE	rb_parent_memory_pool_file	=	rb_iv_get(	rb_memory_pool_file_page_controller,
																									RPBDB_RB_MEMORY_POOL_FILE_PAGE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE );
	return rb_parent_memory_pool_file;
}


/*****************************
*  retrievePageFromCache  *
*****************************/

//	If the flags parameter is set to DB_MPOOL_LAST or DB_MPOOL_NEW, the page number of the created page 
//	is copied into the memory location to which the pgnoaddr parameter refers. 
//	Otherwise, the pgnoaddr parameter is the page to create or retrieve.
//	Page numbers begin at 0; that is, the first page in the file is page number 0, not page number 1.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPbdb_MemoryPoolFilePageController_retrievePageFromCache(	VALUE	rb_memory_pool_file_page_controller,
																	VALUE	rb_page_number_address	)	{

	RPbdb_MemoryPoolFilePageController*		c_memory_pool_file_page_controller;
	C_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller );

	return RUBY_RPBDB_MEMORY_POOL_FILE_PAGE( RPbdb_MemoryPoolFilePageController_retrievePageFromCache(	c_memory_pool_file_page_controller,
								 															FIX2INT( rb_page_number_address ) ) );
}






