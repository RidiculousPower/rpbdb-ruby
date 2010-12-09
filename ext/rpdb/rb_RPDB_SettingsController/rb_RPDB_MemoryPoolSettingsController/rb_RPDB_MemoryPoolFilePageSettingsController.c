/*
 *		Rbdb::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb.h"

#include "rb_Rbdb_MemoryPoolFilePageSettingsController.h"
#include "rb_Rbdb_MemoryPoolFileSettingsController.h"
#include "rb_Rbdb_MemoryPoolSettingsController.h"
#include "rb_Rbdb_SettingsController.h"

#include <rbdb/Rbdb_MemoryPoolFilePageSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolFileSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolSettingsController.h>
#include <rbdb/Rbdb_SettingsController.h>

#include <rbdb/Rbdb_Environment.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRbdb;
VALUE	extern	rb_Rbdb_Environment;
VALUE	extern	rb_Rbdb_SettingsController;
VALUE	extern	rb_Rbdb_MemoryPoolSettingsController;
VALUE	extern	rb_Rbdb_MemoryPoolFileSettingsController;
VALUE	extern	rb_Rbdb_MemoryPoolFilePageSettingsController;

void Init_Rbdb_MemoryPoolFilePageSettingsController()	{

	rb_Rbdb_MemoryPoolFilePageSettingsController		=	rb_define_class_under(	rb_Rbdb_MemoryPoolFileSettingsController, 
																																						"Page",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MemoryPoolFilePageSettingsController, 	"new",																rb_Rbdb_MemoryPoolFilePageSettingsController_new,														-1 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"initialize",													rb_Rbdb_MemoryPoolFilePageSettingsController_initialize,														-1 	);

	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"parent_environment",									rb_Rbdb_MemoryPoolFilePageSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController,					"parent_settings_controller",					rb_Rbdb_MemoryPoolFilePageSettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController,					"parent_memory_pool_settings_controller",					rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolSettingsController,								0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController,					"parent_memory_pool_file_settings_controller",					rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolFileSettingsController,								0 	);

	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"get_page_creates_page_if_does_not_exist?",														rb_Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_creates_page_if_does_not_exist_on",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_creates_page_if_does_not_exist_off",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"get_page_writes_copy_before_eviction?",														rb_Rbdb_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_writes_copy_before_eviction_on",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_writes_copy_before_eviction_off",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"get_page_writes_before_eviction_without_copy?",														rb_Rbdb_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_writes_before_eviction_without_copy_on",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_writes_before_eviction_without_copy_off",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"get_page_returns_last_page?",														rb_Rbdb_MemoryPoolFilePageSettingsController_getPageReturnsLastPage,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_returns_last_page_on",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_returns_last_page_off",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"get_page_creates_new_page?",														rb_Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesNewPage,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_creates_new_page_on",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn,													0 	);
	rb_define_method(			rb_Rbdb_MemoryPoolFilePageSettingsController, 				"turn_get_page_creates_new_page_off",														rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment														=	Qnil;
	VALUE	rb_parent_settings_controller										=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_Rbdb_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_Rbdb_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_Rbdb_MemoryPoolFileSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]",
			"[ <parent memory pool file settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_memory_pool_settings_controller == Qnil )	{			

		rb_parent_environment = rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_Rbdb_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_memory_pool_settings_controller = rb_Rbdb_SettingsController_memoryPoolSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_memory_pool_settings_controller != Qnil )	{
		rb_parent_memory_pool_file_settings_controller	=	rb_Rbdb_MemoryPoolSettingsController_fileSettingsController( rb_parent_memory_pool_settings_controller );
	}

	Rbdb_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller	=	Rbdb_MemoryPoolFileSettingsController_pageSettingsController( c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_page_settings_controller	= RUBY_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_memory_pool_file_page_settings_controller );

	rb_iv_set(	rb_memory_pool_file_page_settings_controller,
							Rbdb_RB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_file_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_settings_controller };
	rb_obj_call_init(	rb_memory_pool_file_page_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_page_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_page_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_Rbdb_MemoryPoolFilePageSettingsController_parentSettingsController( rb_memory_pool_file_page_settings_controller );
	VALUE	rb_parent_environment											=	rb_Rbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller	=	rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolSettingsController( rb_memory_pool_file_page_settings_controller );
	VALUE	rb_parent_settings_controller							=	rb_Rbdb_MemoryPoolSettingsController_parentSettingsController( rb_parent_memory_pool_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_memory_pool_settings_controller  *
*******************************************/

VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_page_settings_controller		=	rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolFileSettingsController( rb_memory_pool_file_page_settings_controller );
	VALUE	rb_parent_memory_pool_settings_controller							=	rb_Rbdb_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController( rb_parent_memory_pool_file_page_settings_controller );
	
	return rb_parent_memory_pool_settings_controller;	
}

/************************************************
*  parent_memory_pool_file_settings_controller  *
************************************************/

VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_parentMemoryPoolFileSettingsController(	VALUE	rb_memory_pool_file_page_settings_controller )	{

	VALUE	rb_parent_memory_pool_file_settings_controller	=	rb_iv_get(	rb_memory_pool_file_page_settings_controller,
																																			Rbdb_RB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_file_settings_controller;
}

/*********************************************
*  get_page_creates_page_if_does_not_exist?  *
*********************************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	DB_MPOOL_CREATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( VALUE	rb_memory_pool_file_page_settings_controller )	{

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/****************************************************
	*  turn_get_page_creates_page_if_does_not_exist_on  *
	****************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( c_memory_pool_file_page_settings_controller );
	
		return rb_memory_pool_file_page_settings_controller;
	}

	/*****************************************************
	*  turn_get_page_creates_page_if_does_not_exist_off  *
	*****************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( c_memory_pool_file_page_settings_controller );
	
		return rb_memory_pool_file_page_settings_controller;
	}

/******************************************
*  get_page_writes_copy_before_eviction?  *
******************************************/

//	The page will be modified and must be written to the source file before being evicted from the pool. 
//	For files open with the DB_MULTIVERSION flag set, a new copy of the page will be made if this is the first time the specified transaction is modifying it.
//	DB_MPOOL_DIRTY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( VALUE	rb_memory_pool_file_page_settings_controller )	{

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( Rbdb_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*************************************************
	*  turn_get_page_writes_copy_before_eviction_on  *
	*************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/**************************************************
	*  turn_get_page_writes_copy_before_eviction_off  *
	**************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

/**************************************************
*  get_page_writes_before_eviction_without_copy?  *
**************************************************/

//	The page will be modified and must be written to the source file before being evicted from the pool. 
//	No copy of the page will be made, regardless of the DB_MULTIVERSION setting. 
//	This flag is only intended for use in situations where a transaction name is not available, such as during aborts or recovery.
//	DB_MPOOL_EDIT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( VALUE	rb_memory_pool_file_page_settings_controller )	{

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( Rbdb_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/*********************************************************
	*  turn_get_page_writes_before_eviction_without_copy_on  *
	*********************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/**********************************************************
	*  turn_get_page_writes_before_eviction_without_copy_off  *
	**********************************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}
	
/********************************
*  get_page_returns_last_page?  *
********************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	Return the last page of the source file, and copy its page number into the memory location to which pgnoaddr refers.
//	DB_MPOOL_LAST		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( VALUE	rb_memory_pool_file_page_settings_controller )	{

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( Rbdb_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/***************************************
	*  turn_get_page_returns_last_page_on  *
	***************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/****************************************
	*  turn_get_page_returns_last_page_off  *
	****************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}	
	
/*******************************
*  get_page_creates_new_page?  *
*******************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	Create a new page in the file, and copy its page number into the memory location to which pgnoaddr refers. 
//	In this case, the pgin method, if specified, is not called.
//	DB_MPOOL_NEW		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( VALUE	rb_memory_pool_file_page_settings_controller )	{

	Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( Rbdb_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																																													:	Qfalse );
}

	/**************************************
	*  turn_get_page_creates_new_page_on  *
	**************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/***************************************
	*  turn_get_page_creates_new_page_off  *
	***************************************/

	VALUE rb_Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		Rbdb_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_Rbdb_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		Rbdb_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}
