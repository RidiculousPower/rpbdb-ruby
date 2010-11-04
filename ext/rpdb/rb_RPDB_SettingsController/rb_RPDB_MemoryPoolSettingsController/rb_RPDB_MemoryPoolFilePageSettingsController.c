/*
 *		RPDB::SettingsController::FileSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include "rb_RPDB_MemoryPoolFilePageSettingsController.h"
#include "rb_RPDB_MemoryPoolFileSettingsController.h"
#include "rb_RPDB_MemoryPoolSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include <rpdb/RPDB_MemoryPoolFilePageSettingsController.h>
#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>
#include <rpdb/RPDB_MemoryPoolSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rpdb/RPDB_Environment.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRPDB;
VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_SettingsController;
VALUE	extern	rb_RPDB_MemoryPoolSettingsController;
VALUE	extern	rb_RPDB_MemoryPoolFileSettingsController;
VALUE	extern	rb_RPDB_MemoryPoolFilePageSettingsController;

void Init_RPDB_MemoryPoolFilePageSettingsController()	{

	rb_RPDB_MemoryPoolFilePageSettingsController		=	rb_define_class_under(	rb_RPDB_MemoryPoolFileSettingsController, 
																																						"Page",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFilePageSettingsController, 	"new",																rb_RPDB_MemoryPoolFilePageSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"initialize",													rb_RPDB_MemoryPoolFilePageSettingsController_init,														-1 	);

	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"parent_environment",									rb_RPDB_MemoryPoolFilePageSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_getPageReturnsLastPage,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesNewPage,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment														=	Qnil;
	VALUE	rb_parent_settings_controller										=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_RPDB_MemoryPoolSettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_settings_controller, rb_RPDB_MemoryPoolFileSettingsController ) ) ),
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

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}
	if ( rb_parent_settings_controller != Qnil )	{
		rb_parent_memory_pool_settings_controller = rb_RPDB_SettingsController_memoryPoolSettingsController( rb_parent_settings_controller );
	}
	if ( rb_parent_memory_pool_settings_controller != Qnil )	{
		rb_parent_memory_pool_file_settings_controller	=	rb_RPDB_MemoryPoolFileSettingsController_pageSettingsController( rb_parent_memory_pool_settings_controller );
	}

	RPDB_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller	=	RPDB_MemoryPoolFileSettingsController_pageSettingsController( c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_page_settings_controller	= RUBY_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_memory_pool_file_page_settings_controller );

	rb_iv_set(	rb_memory_pool_file_page_settings_controller,
							RPDB_RB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_file_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_settings_controller };
	rb_obj_call_init(	rb_memory_pool_file_page_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_page_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_MemoryPoolFilePageSettingsController_init(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self )	{
	
	return rb_self;
}

/***************************************
*  environment  *
***************************************/

VALUE rb_RPDB_MemoryPoolFilePageSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolFilePageSettingsController_parentEnvironment( c_memory_pool_file_page_settings_controller ) );
}

/*****************************************
*  getPageCreatesPageIfDoesNotExist  *
*****************************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	DB_MPOOL_CREATE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( RPDB_MemoryPoolFilePageSettingsController_getPageCreatesPageIfDoesNotExist( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*********************************************
	*  turnGetPageCreatesPageIfDoesNotExistOn  *
	*********************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOn( c_memory_pool_file_page_settings_controller );
	
		return rb_memory_pool_file_page_settings_controller;
	}

	/*************************************************
	*  turnGetPageCreatesPageIfDoesNotExistOff  *
	*************************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesPageIfDoesNotExistOff( c_memory_pool_file_page_settings_controller );
	
		return rb_memory_pool_file_page_settings_controller;
	}

/*****************************************
*  getPageWritesCopyBeforeEviction  *
*****************************************/

//	The page will be modified and must be written to the source file before being evicted from the pool. 
//	For files open with the DB_MULTIVERSION flag set, a new copy of the page will be made if this is the first time the specified transaction is modifying it.
//	DB_MPOOL_DIRTY		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( RPDB_MemoryPoolFilePageSettingsController_getPageWritesCopyBeforeEviction( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																		:	Qfalse );
}

	/*********************************************
	*  turnGetPageWritesCopyBeforeEvictionOn  *
	*********************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/*********************************************
	*  turnGetPageWritesCopyBeforeEvictionOff  *
	*********************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageWritesCopyBeforeEvictionOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

/*********************************************
*  getPageWritesBeforeEvictionWithoutCopy  *
*********************************************/

//	The page will be modified and must be written to the source file before being evicted from the pool. 
//	No copy of the page will be made, regardless of the DB_MULTIVERSION setting. 
//	This flag is only intended for use in situations where a transaction name is not available, such as during aborts or recovery.
//	DB_MPOOL_EDIT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( RPDB_MemoryPoolFilePageSettingsController_getPageWritesBeforeEvictionWithoutCopy( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/*************************************************************
	*  turnWriteBeforeEvictionButProhibitMultiversionCopyOn  *
	*************************************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/*************************************************************
	*  turnWriteBeforeEvictionButProhibitMultiversionCopyOff  *
	*************************************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnWriteBeforeEvictionButProhibitMultiversionCopyOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}
	
/*****************************
*  getPageReturnsLastPage  *
*****************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	Return the last page of the source file, and copy its page number into the memory location to which pgnoaddr refers.
//	DB_MPOOL_LAST		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( RPDB_MemoryPoolFilePageSettingsController_getPageReturnsLastPage( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************************************
	*  turnGetPageReturnsLastPageOn  *
	*************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/*************************************
	*  turnGetPageReturnsLastPageOff  *
	*************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageReturnsLastPageOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}	
	
/*****************************
*  getPageCreatesNewPage  *
*****************************/

//	The DB_MPOOL_CREATE, DB_MPOOL_LAST, and DB_MPOOL_NEW flags are mutually exclusive.
//	Create a new page in the file, and copy its page number into the memory location to which pgnoaddr refers. 
//	In this case, the pgin method, if specified, is not called.
//	DB_MPOOL_NEW		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fget.html
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( VALUE	rb_memory_pool_file_page_settings_controller )	{

	RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

	return ( RPDB_MemoryPoolFilePageSettingsController_getPageCreatesNewPage( c_memory_pool_file_page_settings_controller )	?	Qtrue
																																:	Qfalse );
}

	/*************************************
	*  turnGetPageCreatesNewPageOn  *
	*************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOn( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}

	/*************************************
	*  turnGetPageCreatesNewPageOff  *
	*************************************/

	VALUE rb_RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( VALUE	rb_memory_pool_file_page_settings_controller )	{

		RPDB_MemoryPoolFilePageSettingsController*	c_memory_pool_file_page_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller );

		RPDB_MemoryPoolFilePageSettingsController_turnGetPageCreatesNewPageOff( c_memory_pool_file_page_settings_controller );

		return rb_memory_pool_file_page_settings_controller;
	}
