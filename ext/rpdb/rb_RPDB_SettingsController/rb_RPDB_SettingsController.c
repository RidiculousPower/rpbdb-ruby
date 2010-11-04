/*
 *		RPDB::SettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB.h"

#include "rb_RPDB_DatabaseSettingsController.h"
#include "rb_RPDB_MemoryPoolSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>
#include <rpdb/RPDB_DirectorySettingsController.h>
#include <rpdb/RPDB_FileSettingsController.h>
#include <rpdb/RPDB_ErrorSettingsController.h>
#include <rpdb/RPDB_MemoryPoolSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;

extern	VALUE	rb_RPDB_FileSettingsController;
extern	VALUE	rb_RPDB_ErrorSettingsController;
extern	VALUE	rb_RPDB_LogSettingsController;
extern	VALUE	rb_RPDB_LockSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
extern	VALUE	rb_RPDB_DirectorySettingsController;
extern	VALUE	rb_RPDB_ReplicationSettingsController;

void Init_RPDB_SettingsController()	{

		//	FIX - needs parentEnvironment
		rb_RPDB_SettingsController		=	rb_define_class_under(	rb_RPDB_Environment, 
																														"Settings",	
																														rb_cObject );

																		rb_define_const(				rb_RPDB_Environment, 
																														"SettingsController", 
																														rb_RPDB_SettingsController);

		rb_define_singleton_method(	rb_RPDB_SettingsController, 	"new",																rb_RPDB_SettingsController_new,														-1 	);
		rb_define_method(						rb_RPDB_SettingsController, 	"initialize",													rb_RPDB_SettingsController_init,														-1 	);

		rb_define_method(						rb_RPDB_SettingsController, 	"parent_environment",									rb_RPDB_SettingsController_parentEnvironment,								0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"environment",												"parent_environment"	);

		rb_define_method(						rb_RPDB_SettingsController, 	"shm_key",														rb_RPDB_SettingsController_SHMkey,													0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"shm",																"shm_key"	);
		rb_define_method(						rb_RPDB_SettingsController, 	"shm_key=",														rb_RPDB_SettingsController_setSHMkey,												1 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"shm=",																"shm_key=" );
		rb_define_alias(						rb_RPDB_SettingsController, 	"set_shm_key",												"shm_key=" );
		rb_define_alias(						rb_RPDB_SettingsController, 	"set_shm",														"shm_key=" );
                      					
		rb_define_method(						rb_RPDB_SettingsController, 	"file_settings_controller",						rb_RPDB_SettingsController_fileSettingsController,					0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"files",															"file_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"file",																"file_settings_controller"	);
                      					
		rb_define_method(						rb_RPDB_SettingsController, 	"error_settings_controller",					rb_RPDB_SettingsController_errorSettingsController,					0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"errors",															"error_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"error",															"error_settings_controller"	);

		rb_define_method(						rb_RPDB_SettingsController, 	"log_settings_controller",						rb_RPDB_SettingsController_logSettingsController,						0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"logs",																"log_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"log",																"log_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"logging",														"log_settings_controller"	);
                      					
		rb_define_method(						rb_RPDB_SettingsController, 	"memory_pool_settings_controller",		rb_RPDB_SettingsController_memoryPoolSettingsController,		0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"memory_pool",												"memory_pool_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"memory",															"memory_pool_settings_controller"	);
                      					
		rb_define_method(						rb_RPDB_SettingsController, 	"database_settings_controller",				rb_RPDB_SettingsController_databaseSettingsController,			0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"databases",													"database_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"database",														"database_settings_controller"	);
                      					
		rb_define_method(						rb_RPDB_SettingsController, 	"directory_settings_controller",			rb_RPDB_SettingsController_directorySettingsController,			0 	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"directories",												"directory_settings_controller"	);
		rb_define_alias(						rb_RPDB_SettingsController, 	"directory",													"directory_settings_controller"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_SettingsController_new(	int				argc,
																			VALUE*		args,
																			VALUE			rb_klass_self )	{

	VALUE	rb_parent_environment	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter( R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ) ) ),
		R_ListOrder( 1 ),
		"[ <parent environment> ]"
		)
	);
	
	if ( rb_parent_environment == Qnil )	{
		rb_parent_environment	=	rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}

	RPDB_Environment*		c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	RPDB_SettingsController*	settings_controller	=	RPDB_Environment_settingsController( c_parent_environment );

	VALUE	rb_settings_controller	= RUBY_RPDB_SETTINGS_CONTROLLER( settings_controller );

	rb_iv_set(	rb_settings_controller,
							RPDB_RB_SETTINGS_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_settings_controller,
										1, 
										argv );
	
	return rb_settings_controller;		
}

/*********
*  init  *
*********/

VALUE rb_RPDB_SettingsController_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_settings_controller_self )	{
	
	return rb_settings_controller_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_SettingsController_parentEnvironment(	VALUE	rb_settings_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_settings_controller,
																						RPDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/************
*  shm_key  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_shm_key.html
//	For getting the SHMKey
VALUE rb_RPDB_SettingsController_SHMkey( VALUE	rb_settings_controller )	{
	
	RPDB_SettingsController*	c_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );
	
	//	return a Bignum
	return INT2NUM( RPDB_SettingsController_SHMkey( c_settings_controller ) );
}

/****************
*  set_shm_key  *
****************/

//	For setting the SHMKey
VALUE rb_RPDB_SettingsController_setSHMkey(	VALUE	rb_settings_controller, 
																						VALUE	shm_key )	{

	RPDB_SettingsController*	c_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

	RPDB_SettingsController_setSHMkey(	c_settings_controller,
																			NUM2LONG( shm_key ) );
										
	return rb_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*****************************
*  file_settings_controller  *
*****************************/

VALUE rb_RPDB_SettingsController_fileSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_file_settings_controller	=	Qnil;
	
	if ( ( rb_file_settings_controller = rb_iv_get(	rb_settings_controller,
																									RPDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

		RPDB_FileSettingsController*	c_file_settings_controller	=	RPDB_SettingsController_fileSettingsController( c_settings_controller );

		rb_file_settings_controller	=	RUBY_RPDB_FILE_SETTINGS_CONTROLLER( c_file_settings_controller );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER,
								rb_file_settings_controller );
	}
	
	return rb_file_settings_controller;
}

/******************************
*  error_settings_controller  *
******************************/

VALUE rb_RPDB_SettingsController_errorSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_error_settings_controller	=	Qnil;

	if ( ( rb_error_settings_controller = rb_iv_get(	rb_settings_controller,
																										RPDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER ) ) == Qnil )	{

		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

		RPDB_ErrorSettingsController*	c_error_settings_controller	=	RPDB_SettingsController_errorSettingsController( c_settings_controller );

		rb_error_settings_controller	=	RUBY_RPDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER,
								rb_error_settings_controller );
	}

	return rb_error_settings_controller;
}

/****************************
*  log_settings_controller  *
****************************/

VALUE rb_RPDB_SettingsController_logSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_log_settings_controller	=	Qnil;

	if ( ( rb_log_settings_controller = rb_iv_get(	rb_settings_controller,
																									RPDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{

		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

		RPDB_LogSettingsController*	c_log_settings_controller	=	RPDB_SettingsController_logSettingsController( c_settings_controller );

		rb_log_settings_controller	=	RUBY_RPDB_LOG_SETTINGS_CONTROLLER( c_log_settings_controller );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_log_settings_controller );
	}

	return rb_log_settings_controller;	
}

/****************************
*  lock_settings_controller  *
****************************/

VALUE rb_RPDB_SettingsController_lockSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_lock_settings_controller	=	Qnil;

	if ( ( rb_lock_settings_controller = rb_iv_get(	rb_settings_controller,
																									RPDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER ) ) == Qnil )	{

		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

		RPDB_LockSettingsController*	c_lock_settings_controller	=	RPDB_SettingsController_lockSettingsController( c_settings_controller );

		rb_lock_settings_controller	=	RUBY_RPDB_LOCK_SETTINGS_CONTROLLER( c_lock_settings_controller );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER,
								rb_lock_settings_controller );
	}

	return rb_lock_settings_controller;	
}

/****************************
*  replication_settings_controller  *
****************************/

VALUE rb_RPDB_SettingsController_replicationSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_replication_settings_controller	=	Qnil;

	if ( ( rb_replication_settings_controller = rb_iv_get(	rb_settings_controller,
																													RPDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER ) ) == Qnil )	{

		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

		RPDB_ReplicationSettingsController*	c_replication_settings_controller	=	RPDB_SettingsController_replicationSettingsController( c_settings_controller );

		rb_replication_settings_controller	=	RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER,
								rb_replication_settings_controller );
	}

	return rb_replication_settings_controller;	
}

/************************************
*  memory_pool_settings_controller  *
************************************/

VALUE rb_RPDB_SettingsController_memoryPoolSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_memory_pool_settings_controller	=	Qnil;

	if ( ( rb_memory_pool_settings_controller = rb_iv_get(	rb_settings_controller,
																													RPDB_RB_SETTINGS_VARIABLE_MEMORY_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_memory_pool_settings_controller	=	rb_RPDB_MemoryPoolSettingsController_new( 1,
																																										& rb_settings_controller,
																																										rb_RPDB_MemoryPoolSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_MEMORY_SETTINGS_CONTROLLER,
								rb_memory_pool_settings_controller );
	}

	return rb_memory_pool_settings_controller;	
}


/*********************************
*  database_settings_controller  *
*********************************/

VALUE rb_RPDB_SettingsController_databaseSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_database_settings_controller	=	Qnil;
	if ( ( rb_database_settings_controller = rb_iv_get(	rb_settings_controller,
																											RPDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_settings_controller	=	rb_RPDB_DatabaseSettingsController_new( 1,
																																							& rb_settings_controller,
																																							rb_RPDB_DatabaseSettingsController );		

		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER,
								rb_database_settings_controller );
	}

	return rb_database_settings_controller;
}

/**********************************
*  directory_settings_controller  *
**********************************/

VALUE rb_RPDB_SettingsController_directorySettingsController( VALUE	rb_settings_controller )	{
	
	VALUE	rb_directory_settings_controller	=	Qnil;

	if ( ( rb_directory_settings_controller = rb_iv_get(	rb_settings_controller,
																												RPDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER ) ) == Qnil )	{

		RPDB_SettingsController*	c_settings_controller;
		C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );
		
		RPDB_DirectorySettingsController*	c_directory_settings_controller	=	RPDB_SettingsController_directorySettingsController( c_settings_controller );
		
		rb_directory_settings_controller	=	RUBY_RPDB_DIRECTORY_SETTINGS_CONTROLLER( c_directory_settings_controller );
			
		rb_iv_set(	rb_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER,
								rb_directory_settings_controller );
	}

	return rb_directory_settings_controller;
}
