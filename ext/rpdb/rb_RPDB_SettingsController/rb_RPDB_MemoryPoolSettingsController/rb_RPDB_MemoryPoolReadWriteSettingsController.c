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

#include "rb_RPDB_MemoryPoolReadWriteSettingsController.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolReadWriteSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolReadWriteSettingsController;

void Init_RPDB_MemoryPoolReadWriteSettingsController()	{

	rb_RPDB_MemoryPoolReadWriteSettingsController		=	rb_define_class_under(	rb_RPDB_MemoryPoolReadWriteSettingsController, 
																																		"ReadWrite",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolReadWriteSettingsController, 	"new",																rb_RPDB_MemoryPoolReadWriteSettingsController_init,														1 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"initialize",													rb_RPDB_MemoryPoolReadWriteSettingsController_init,														1 	);

	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"parent_environment",									rb_RPDB_MemoryPoolReadWriteSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_maxOpenFiles,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxOpenFiles,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_maxSequentialWrites,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_maxMappedDBSize,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxMappedDBSize,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolReadWriteSettingsController, 				"shm_key",														rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																													VALUE	rb_parent_memory_pool_settings_controller )	{

	RPDB_MemoryPoolSettingsController*	c_parent_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_parent_memory_pool_settings_controller, c_parent_memory_pool_settings_controller );

	VALUE	rb_memory_pool_read_write_settings_controller	= RUBY_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( RPDB_MemoryPoolReadWriteSettingsController_new( c_parent_memory_pool_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_memory_pool_settings_controller;
	
	rb_obj_call_init(	rb_memory_pool_read_write_settings_controller,
					 1, 
					 argv );
	
	return rb_memory_pool_read_write_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_init(	VALUE	rb_memory_pool_read_write_settings_controller,
																													VALUE	rb_parent_memory_pool_settings_controller __attribute__ ((unused )) )	{
	
	return rb_memory_pool_read_write_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_parentEnvironment(	VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolReadWriteSettingsController_parentEnvironment( c_memory_pool_read_write_settings_controller ) );
}

/*********************
*  maxOpenFiles  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_openfd.html
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxOpenFiles( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return INT2FIX( RPDB_MemoryPoolReadWriteSettingsController_maxOpenFiles( c_memory_pool_read_write_settings_controller ) );
}

	/*************************
	*  setMaxOpenFiles  *
	*************************/

	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	VALUE	rb_memory_pool_read_write_settings_controller, 
																			VALUE	rb_max_open_files )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_setMaxOpenFiles(	c_memory_pool_read_write_settings_controller,
																		FIX2INT( rb_max_open_files ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/*****************************
*  maxSequentialWrites  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_maxwrite.html
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxSequentialWrites( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return INT2FIX( RPDB_MemoryPoolReadWriteSettingsController_maxSequentialWrites( c_memory_pool_read_write_settings_controller ) );
}

	/*****************************
	*  setMaxSequentialWrites  *
	*****************************/

	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	VALUE	rb_memory_pool_read_write_settings_controller,
																					VALUE	rb_max_sequential_writes )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_setMaxSequentialWrites(	c_memory_pool_read_write_settings_controller,
																			FIX2INT( rb_max_sequential_writes ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/************************************
*  timeToSleepBeforeNextWrite  *
************************************/

VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return INT2FIX( RPDB_MemoryPoolReadWriteSettingsController_timeToSleepBeforeNextWrite( c_memory_pool_read_write_settings_controller ) );
}

	/****************************************
	*  setTimeToSleepBeforeNextWrite  *
	****************************************/

	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	VALUE	rb_memory_pool_read_write_settings_controller, 
																						VALUE	rb_time_to_sleep_before_next_write )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_setTimeToSleepBeforeNextWrite(	c_memory_pool_read_write_settings_controller,
																					FIX2INT( rb_time_to_sleep_before_next_write ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/************************
*  maxMappedDBSize  *
************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_mp_mmapsize.html
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_maxMappedDBSize( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return INT2FIX( RPDB_MemoryPoolReadWriteSettingsController_maxMappedDBSize( c_memory_pool_read_write_settings_controller ) );
}

	/****************************
	*  setMaxMappedDBSize  *
	****************************/

	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_setMaxMappedDBSize(	VALUE	rb_memory_pool_read_write_settings_controller, 
																				VALUE	rb_max_mapped_db_size )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_setMaxMappedDBSize(	c_memory_pool_read_write_settings_controller,
																		FIX2INT( rb_max_mapped_db_size ) );

		return rb_memory_pool_read_write_settings_controller;
	}

/*****************************
*  pagefaultSharedRegions  *
*****************************/

//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions( VALUE	rb_memory_pool_read_write_settings_controller )	{

	RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
	C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

	return INT2FIX( RPDB_MemoryPoolReadWriteSettingsController_pagefaultSharedRegions(	c_memory_pool_read_write_settings_controller ) );
}

	/*************************************
	*  turnPagefaultSharedRegionsOn  *
	*************************************/

	//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOn( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}

	/*************************************
	*  turnPagefaultSharedRegionsOff  *
	*************************************/

	//	DB_REGION_INIT          http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( VALUE	rb_memory_pool_read_write_settings_controller )	{

		RPDB_MemoryPoolReadWriteSettingsController*	c_memory_pool_read_write_settings_controller;
		C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_read_write_settings_controller, c_memory_pool_read_write_settings_controller );

		RPDB_MemoryPoolReadWriteSettingsController_turnPagefaultSharedRegionsOff( c_memory_pool_read_write_settings_controller );

		return rb_memory_pool_read_write_settings_controller;
	}
