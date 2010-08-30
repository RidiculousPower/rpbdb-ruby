/*
 *		RPDB_settingsController:RPDB_DatabaseRecordSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_DatabaseRecordSettingsController.h>
#include "rb_RPDB_DatabaseRecordSettingsController.h"

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;

void Init_RPDB_DatabaseRecordSettingsController()	{

	rb_RPDB_DatabaseRecordSettingsController		=		rb_define_class_under(			rb_RPDB_DatabaseSettingsController, 
																																							"ReadWrite",	
																																							rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DatabaseRecordSettingsController, 	"new",																								rb_RPDB_DatabaseRecordSettingsController_new,																						1 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"initialize",																					rb_RPDB_DatabaseRecordSettingsController_init,																					1 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"parent_environment",																	rb_RPDB_DatabaseRecordSettingsController_parentEnvironment,															0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordSettingsController, 	"environment",																				"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"parent_database",																		rb_RPDB_DatabaseRecordSettingsController_parentDatabase,																0 	);
	rb_define_alias(						rb_RPDB_DatabaseRecordSettingsController, 	"database",																						"parent_database"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"database_allocates_memory_using_malloc?",						rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingMalloc,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_allocates_memory_using_malloc_on",			rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_allocates_memory_using_malloc_off",		rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff,			0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"database_allocates_memory_using_realloc?",						rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingRealloc,						0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_allocates_memory_using_realloc_on",		rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn,			0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_allocates_memory_using_realloc_off",		rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff,		0 	);
                    					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"application_allocates_memory?",											rb_RPDB_DatabaseRecordSettingsController_applicationAllocatesMemory,										0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_application_allocates_memory_on",								rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOn,							0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_application_allocates_memory_off",							rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOff,							0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"database_frees_memory?",															rb_RPDB_DatabaseRecordSettingsController_databaseFreesMemory,														0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_frees_memory_on",											rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOn,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_database_frees_memory_off",											rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOff,										0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"partial_access?",																		rb_RPDB_DatabaseRecordSettingsController_partialAccess,																	0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_partial_access_on",															rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOn,														0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_partial_access_off",														rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOff,													0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"sync_prior_to_write_return?",												rb_RPDB_DatabaseRecordSettingsController_syncPriorToWriteReturn,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_sync_prior_to_write_return_on",									rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOn,									0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"turn_sync_prior_to_write_return_off",								rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOff,									0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"data_buffer_size",																		rb_RPDB_DatabaseRecordSettingsController_dataBufferSize,																0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"data_buffer_size=",																	rb_RPDB_DatabaseRecordSettingsController_setDataBufferSize,															0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"set_data_buffer_size",																rb_RPDB_DatabaseRecordSettingsController_setDataBufferSize,															0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"partial_read_write_size",														rb_RPDB_DatabaseRecordSettingsController_partialReadWriteSize,													0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"partial_read_write_size=",														rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteSize,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"set_partial_read_write_size",												rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteSize,												0 	);
                    					                                                                                                                                                                                					
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"partial_read_write_offset",													rb_RPDB_DatabaseRecordSettingsController_partialReadWriteOffset,												0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"partial_read_write_offset=",													rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteOffset,											0 	);
	rb_define_method(						rb_RPDB_DatabaseRecordSettingsController, 	"set_partial_read_write_offset",											rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteOffset,											0 	);
}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/
	
VALUE rb_RPDB_DatabaseRecordSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																										VALUE	rb_parent_database_settings_controller )	{

	RPDB_DatabaseSettingsController*	c_parent_database_settings_controller;
	C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_database_settings_controller, c_parent_database_settings_controller );

	VALUE	rb_database_record_settings_controller	=	RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( RPDB_DatabaseRecordSettingsController_new( c_parent_database_settings_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_database_settings_controller;
	
	rb_obj_call_init(	rb_database_record_settings_controller,
					 1, 
					 argv );
	
	return rb_database_record_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_DatabaseRecordSettingsController_init(	VALUE	rb_database_record_settings_controller,
																											VALUE	rb_parent_database_settings_controller __attribute__ ((unused )) )	{
	
	return rb_database_record_settings_controller;
}


/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_DatabaseRecordSettingsController_parentEnvironment( c_database_record_settings_controller ) );

}

/***************************************
*  Database  *
***************************************/
VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return RUBY_RPDB_DATABASE( RPDB_DatabaseRecordSettingsController_parentDatabase( c_database_record_settings_controller ) );

}

/*****************************************
*  databaseAllocatesMemoryUsingMalloc  *
*****************************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingMalloc( c_database_record_settings_controller )	?	Qtrue
																																:	Qfalse );
	
}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOn  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingMallocOff  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( c_database_record_settings_controller );	

		return rb_database_record_settings_controller;
	}

/*********************************************
*  databaseAllocatesMemoryUsingRealloc  *
*********************************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingRealloc( c_database_record_settings_controller )	?	Qtrue
																																	:	Qfalse );	
}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOn  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );	

		return rb_database_record_settings_controller;
	}

	/*************************************************
	*  turnDatabaseAllocatesMemoryUsingReallocOff  *
	*************************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

/*********************************
*  applicationAllocatesMemory  *
*********************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_applicationAllocatesMemory( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_applicationAllocatesMemory( c_database_record_settings_controller )	?	Qtrue
																														:	Qfalse );
	
}

	/*****************************************
	*  turnApplicationAllocatesMemoryOn  *
	*****************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

	/*****************************************
	*  turnApplicationAllocatesMemoryOff  *
	*****************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

/*****************************
*  databaseFreesMemory  *
*****************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_databaseFreesMemory( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_databaseFreesMemory( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );
	
}

	/*********************************
	*  turnDatabaseFreesMemoryOn  *
	*********************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOn( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

	/*********************************
	*  turnDatabaseFreesMemoryOff  *
	*********************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOff( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

/*********************
*  partialAccess  *
*********************/

VALUE rb_RPDB_DatabaseRecordSettingsController_partialAccess( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_partialAccess( c_database_record_settings_controller )	?	Qtrue
																											:	Qfalse );
	
}

	/*****************************
	*  turnPartialAccessOn  *
	*****************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnPartialAccessOn( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}

	/*****************************
	*  turnPartialAccessOff  *
	*****************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnPartialAccessOff( c_database_record_settings_controller );
	
		return rb_database_record_settings_controller;
	}
	
/*****************************
*  syncPriorToWriteReturn  *
*****************************/

//	DB_DSYNC_DB             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
VALUE rb_RPDB_DatabaseRecordSettingsController_syncPriorToWriteReturn( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return ( RPDB_DatabaseRecordSettingsController_syncPriorToWriteReturn( c_database_record_settings_controller )	?	Qtrue
																													:	Qfalse );

}

	/**************************************
	*  turnSyncPriorToWriteReturnOn  *
	**************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOn( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOn( c_database_record_settings_controller );

		return rb_database_record_settings_controller;
	}

	/************************************
	*  turnSyncPriorToWriteReturnOff  *
	************************************/

	VALUE rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOff( VALUE	rb_database_record_settings_controller )	{

		RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
		C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

		RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOff( c_database_record_settings_controller );

		return rb_database_record_settings_controller;
	}

/*********************
*  dataBufferSize  *
*********************/

VALUE rb_RPDB_DatabaseRecordSettingsController_dataBufferSize( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordSettingsController_dataBufferSize( c_database_record_settings_controller ) );
}	

/*************************
*  setDataBufferSize  *
*************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_setDataBufferSize(	VALUE	rb_database_record_settings_controller, 
																	VALUE	rb_buffer_size )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordSettingsController_setDataBufferSize(	c_database_record_settings_controller,
																FIX2INT( rb_buffer_size ) );
	
	return rb_database_record_settings_controller;
}	

/*****************************
*  partialReadWriteSize  *
*****************************/

//	Returns size of partial write (if applicable)
//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records. 
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
VALUE rb_RPDB_DatabaseRecordSettingsController_partialReadWriteSize( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordSettingsController_partialReadWriteSize( c_database_record_settings_controller ) );
}	

/*********************************
*  setPartialReadWriteSize  *
*********************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteSize(	VALUE	rb_database_record_settings_controller, 
																			VALUE	rb_partial_read_write_size )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordSettingsController_setPartialReadWriteSize(	c_database_record_settings_controller,
																	FIX2INT( rb_partial_read_write_size ) );

	return rb_database_record_settings_controller;
}	

/*****************************
*  partialReadWriteOffset  *
*****************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_partialReadWriteOffset( VALUE	rb_database_record_settings_controller )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	return INT2FIX( RPDB_DatabaseRecordSettingsController_partialReadWriteOffset( c_database_record_settings_controller ) );
}	

/*********************************
*  setPartialReadWriteOffset  *
*********************************/

VALUE rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteOffset(	VALUE	rb_database_record_settings_controller, 
																			VALUE	rb_partial_read_write_offset )	{

	RPDB_DatabaseRecordSettingsController*	c_database_record_settings_controller;
	C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller );

	RPDB_DatabaseRecordSettingsController_setPartialReadWriteOffset(	c_database_record_settings_controller,
	 																	FIX2INT( rb_partial_read_write_offset ) );

	return rb_database_record_settings_controller;
}
