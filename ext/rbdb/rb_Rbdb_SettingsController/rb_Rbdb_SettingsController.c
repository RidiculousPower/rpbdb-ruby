/*
 *		Rbdb::SettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_SettingsController.h"

#include "rb_Rbdb_DebugSettingsController.h"
#include "rb_Rbdb_FileSettingsController.h"
#include "rb_Rbdb_ErrorSettingsController.h"
#include "rb_Rbdb_LogSettingsController.h"
#include "rb_Rbdb_LockSettingsController.h"
#include "rb_Rbdb_ReplicationSettingsController.h"

#include "rb_Rbdb.h"

#include "rb_Rbdb_DatabaseSettingsController.h"
#include "rb_Rbdb_MemoryPoolSettingsController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_SettingsController.h>
#include <rbdb/Rbdb_DatabaseSettingsController.h>
#include <rbdb/Rbdb_DirectorySettingsController.h>
#include <rbdb/Rbdb_FileSettingsController.h>
#include <rbdb/Rbdb_ErrorSettingsController.h>
#include <rbdb/Rbdb_MemoryPoolSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_SettingsController;

extern	VALUE	rb_Rbdb_DebugSettingsController;
extern	VALUE	rb_Rbdb_FileSettingsController;
extern	VALUE	rb_Rbdb_ErrorSettingsController;
extern	VALUE	rb_Rbdb_LogSettingsController;
extern	VALUE	rb_Rbdb_LockSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolSettingsController;
extern	VALUE	rb_Rbdb_DatabaseSettingsController;
extern	VALUE	rb_Rbdb_DirectorySettingsController;
extern	VALUE	rb_Rbdb_ReplicationSettingsController;

void Init_rb_Rbdb_SettingsController()	{

		rb_Rbdb_SettingsController		=	rb_define_class_under(	rb_mRbdb, 
																														"Settings",	
																														rb_cObject );

		rb_define_singleton_method(	rb_Rbdb_SettingsController, 	"new",																rb_Rbdb_SettingsController_new,														-1 	);
		rb_define_method(						rb_Rbdb_SettingsController, 	"initialize",													rb_Rbdb_SettingsController_initialize,														-1 	);

		rb_define_method(						rb_Rbdb_SettingsController, 	"parent_environment",									rb_Rbdb_SettingsController_parentEnvironment,								0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"environment",												"parent_environment"	);

		rb_define_method(						rb_Rbdb_SettingsController, 	"shm_key",														rb_Rbdb_SettingsController_SHMkey,													0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"shm",																"shm_key"	);
		rb_define_method(						rb_Rbdb_SettingsController, 	"shm_key=",														rb_Rbdb_SettingsController_setSHMkey,												1 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"shm=",																"shm_key=" );
		rb_define_alias(						rb_Rbdb_SettingsController, 	"set_shm_key",												"shm_key=" );
		rb_define_alias(						rb_Rbdb_SettingsController, 	"set_shm",														"shm_key=" );
                      					
		rb_define_method(						rb_Rbdb_SettingsController, 	"file_settings_controller",						rb_Rbdb_SettingsController_fileSettingsController,					0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"files",															"file_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"file",																"file_settings_controller"	);
                      					
		rb_define_method(						rb_Rbdb_SettingsController, 	"error_settings_controller",					rb_Rbdb_SettingsController_errorSettingsController,					0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"errors",															"error_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"error",															"error_settings_controller"	);

		rb_define_method(						rb_Rbdb_SettingsController, 	"lock_settings_controller",						rb_Rbdb_SettingsController_lockSettingsController,						0 	);

		rb_define_method(						rb_Rbdb_SettingsController, 	"log_settings_controller",						rb_Rbdb_SettingsController_logSettingsController,						0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"logs",																"log_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"log",																"log_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"logging",														"log_settings_controller"	);

		rb_define_method(						rb_Rbdb_SettingsController, 	"replication_settings_controller",		rb_Rbdb_SettingsController_replicationSettingsController,						0 	);
                      					
		rb_define_method(						rb_Rbdb_SettingsController, 	"memory_pool_settings_controller",		rb_Rbdb_SettingsController_memoryPoolSettingsController,		0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"memory_pool",												"memory_pool_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"memory",															"memory_pool_settings_controller"	);
                      					
		rb_define_method(						rb_Rbdb_SettingsController, 	"database_settings_controller",				rb_Rbdb_SettingsController_databaseSettingsController,			0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"databases",													"database_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"database",														"database_settings_controller"	);
                      					
		rb_define_method(						rb_Rbdb_SettingsController, 	"directory_settings_controller",			rb_Rbdb_SettingsController_directorySettingsController,			0 	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"directories",												"directory_settings_controller"	);
		rb_define_alias(						rb_Rbdb_SettingsController, 	"directory",													"directory_settings_controller"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_SettingsController_new(	int				argc,
																			VALUE*		args,
																			VALUE			rb_klass_self )	{

	VALUE	rb_parent_environment	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter( R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);
	
	if ( rb_parent_environment == Qnil )	{
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}

	Rbdb_Environment*		c_parent_environment;
	C_RBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );

	Rbdb_SettingsController*	settings_controller	=	Rbdb_Environment_settingsController( c_parent_environment );

	VALUE	rb_settings_controller	= RUBY_RBDB_SETTINGS_CONTROLLER( settings_controller );

	rb_iv_set(	rb_settings_controller,
							RBDB_RB_SETTINGS_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_settings_controller,
										1, 
										argv );
	
	return rb_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_Rbdb_SettingsController_initialize(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_settings_controller_self )	{
	
	return rb_settings_controller_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_SettingsController_parentEnvironment(	VALUE	rb_settings_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_settings_controller,
																						RBDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/************
*  shm_key  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_shm_key.html
//	For getting the SHMKey
VALUE rb_Rbdb_SettingsController_SHMkey( VALUE	rb_settings_controller )	{
	
	Rbdb_SettingsController*	c_settings_controller;
	C_RBDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );
	
	long c_shm_key	=	Rbdb_SettingsController_SHMkey( c_settings_controller );
	
	//	return a Bignum
	VALUE	rb_shm_key	=	INT2NUM( c_shm_key );
	
	return rb_shm_key;
}

/****************
*  set_shm_key  *
****************/

//	For setting the SHMKey
VALUE rb_Rbdb_SettingsController_setSHMkey(	VALUE	rb_settings_controller, 
																						VALUE	rb_shm_key )	{

	VALUE	rb_environment	=	rb_Rbdb_SettingsController_parentEnvironment( rb_settings_controller );
	
	if ( rb_Rbdb_Environment_isOpen( rb_environment ) )	{
		rb_raise( rb_eRuntimeError, "SHM key can only be specified before environment is opened." );
	}

	Rbdb_SettingsController*	c_settings_controller;
	C_RBDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller );

	long	c_shm_key	=	NUM2LONG( rb_shm_key );

	Rbdb_SettingsController_setSHMkey(	c_settings_controller,
																			c_shm_key );
										
	return rb_settings_controller;
}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*****************************
*  debug_settings_controller  *
*****************************/

VALUE rb_Rbdb_SettingsController_debugSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_debug_settings_controller	=	Qnil;
	
	if ( ( rb_debug_settings_controller = rb_iv_get(	rb_settings_controller,
																									RBDB_RB_SETTINGS_VARIABLE_DEBUG_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_debug_settings_controller	=	rb_Rbdb_DebugSettingsController_new(	1,
																																					& rb_settings_controller,
																																					rb_Rbdb_DebugSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_DEBUG_SETTINGS_CONTROLLER,
								rb_debug_settings_controller );
	}
	
	return rb_debug_settings_controller;
}

/*****************************
*  file_settings_controller  *
*****************************/

VALUE rb_Rbdb_SettingsController_fileSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_file_settings_controller	=	Qnil;
	
	if ( ( rb_file_settings_controller = rb_iv_get(	rb_settings_controller,
																									RBDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
	
		rb_file_settings_controller	=	rb_Rbdb_FileSettingsController_new(	1,
																																			& rb_settings_controller,
																																			rb_Rbdb_FileSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER,
								rb_file_settings_controller );
	}
	
	return rb_file_settings_controller;
}

/******************************
*  error_settings_controller  *
******************************/

VALUE rb_Rbdb_SettingsController_errorSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_error_settings_controller	=	Qnil;

	if ( ( rb_error_settings_controller = rb_iv_get(	rb_settings_controller,
																										RBDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_error_settings_controller	=	rb_Rbdb_ErrorSettingsController_new(	1,
																																					& rb_settings_controller,
																																					rb_Rbdb_ErrorSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER,
								rb_error_settings_controller );
	}

	return rb_error_settings_controller;
}

/****************************
*  log_settings_controller  *
****************************/

VALUE rb_Rbdb_SettingsController_logSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_log_settings_controller	=	Qnil;

	if ( ( rb_log_settings_controller = rb_iv_get(	rb_settings_controller,
																									RBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_log_settings_controller	=	rb_Rbdb_LogSettingsController_new(	1,
																																			& rb_settings_controller,
																																			rb_Rbdb_LogSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER,
								rb_log_settings_controller );
	}

	return rb_log_settings_controller;	
}

/*****************************
*  lock_settings_controller  *
*****************************/

VALUE rb_Rbdb_SettingsController_lockSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_lock_settings_controller	=	Qnil;

	if ( ( rb_lock_settings_controller = rb_iv_get(	rb_settings_controller,
																									RBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_lock_settings_controller	=	rb_Rbdb_LockSettingsController_new(	1,
																																			& rb_settings_controller,
																																			rb_Rbdb_LockSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER,
								rb_lock_settings_controller );
	}

	return rb_lock_settings_controller;	
}

/************************************
*  replication_settings_controller  *
************************************/

VALUE rb_Rbdb_SettingsController_replicationSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_replication_settings_controller	=	Qnil;

	if ( ( rb_replication_settings_controller = rb_iv_get(	rb_settings_controller,
																													RBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_replication_settings_controller	=	rb_Rbdb_ReplicationSettingsController_new(	1,
																																											& rb_settings_controller,
																																											rb_Rbdb_ReplicationSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER,
								rb_replication_settings_controller );
	}

	return rb_replication_settings_controller;	
}

/************************************
*  memory_pool_settings_controller  *
************************************/

VALUE rb_Rbdb_SettingsController_memoryPoolSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_memory_pool_settings_controller	=	Qnil;

	if ( ( rb_memory_pool_settings_controller = rb_iv_get(	rb_settings_controller,
																													RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_memory_pool_settings_controller	=	rb_Rbdb_MemoryPoolSettingsController_new( 1,
																																										& rb_settings_controller,
																																										rb_Rbdb_MemoryPoolSettingsController );
		
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER,
								rb_memory_pool_settings_controller );
	}

	return rb_memory_pool_settings_controller;	
}


/*********************************
*  database_settings_controller  *
*********************************/

VALUE rb_Rbdb_SettingsController_databaseSettingsController( VALUE	rb_settings_controller )	{

	VALUE	rb_database_settings_controller	=	Qnil;
	if ( ( rb_database_settings_controller = rb_iv_get(	rb_settings_controller,
																											RBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_database_settings_controller	=	rb_Rbdb_DatabaseSettingsController_new( 1,
																																							& rb_settings_controller,
																																							rb_Rbdb_DatabaseSettingsController );		

		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER,
								rb_database_settings_controller );
	}

	return rb_database_settings_controller;
}

/**********************************
*  directory_settings_controller  *
**********************************/

VALUE rb_Rbdb_SettingsController_directorySettingsController( VALUE	rb_settings_controller )	{
	
	VALUE	rb_directory_settings_controller	=	Qnil;

	if ( ( rb_directory_settings_controller = rb_iv_get(	rb_settings_controller,
																												RBDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER ) ) == Qnil )	{

		rb_directory_settings_controller	=	rb_Rbdb_DatabaseSettingsController_new( 1,
																																								& rb_settings_controller,
																																								rb_Rbdb_DirectorySettingsController );		
			
		rb_iv_set(	rb_settings_controller,
								RBDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER,
								rb_directory_settings_controller );
	}

	return rb_directory_settings_controller;
}
