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

#include "rb_RPDB_MemoryPoolFilePageSettingsController.h"

#include <rpdb/RPDB_MemoryPoolFilePageSettingsController.h>

#include <rpdb/RPDB_Environment.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_SettingsController;
VALUE	extern	rb_RPDB_MemoryPoolFilePageSettingsController;

void Init_RPDB_MemoryPoolFilePageSettingsController()	{

	rb_RPDB_MemoryPoolFilePageSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																						"MemoryPool",	
																																						rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFilePageSettingsController, 	"new",																rb_RPDB_MemoryPoolFilePageSettingsController_init,														1 	);
	rb_define_method(			rb_RPDB_MemoryPoolFilePageSettingsController, 				"initialize",													rb_RPDB_MemoryPoolFilePageSettingsController_init,														1 	);

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
	
VALUE rb_RPDB_MemoryPoolFilePageSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																												VALUE	rb_parent_memory_pool_file_settings_controller )	{
	
	RPDB_MemoryPoolFileSettingsController*	c_parent_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_parent_memory_pool_file_settings_controller, c_parent_memory_pool_file_settings_controller );

	VALUE	rb_memory_pool_file_page_settings_controller	= RUBY_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( RPDB_MemoryPoolFilePageSettingsController_new( c_parent_memory_pool_file_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_memory_pool_file_settings_controller;
	
	rb_obj_call_init(	rb_memory_pool_file_page_settings_controller,
					 1, 
					 argv );
	
	return rb_memory_pool_file_page_settings_controller;		
}

/*************
*  init  *
*************/

VALUE rb_RPDB_MemoryPoolFilePageSettingsController_init(	VALUE	rb_memory_pool_file_page_settings_controller,
																													VALUE	rb_parent_memory_pool_file_settings_controller __attribute__ ((unused )) )	{
	
	return rb_memory_pool_file_page_settings_controller;
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
