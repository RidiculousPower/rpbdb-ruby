/*
 *		RPDB::MemoryPoolController::MemoryPoolFile
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MemoryPoolFile.h"
 
#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MemoryPoolFile.h>

#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_MemoryPoolFile;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolController;
extern	VALUE	rb_RPDB_MemoryPoolFileController;

void Init_RPDB_MemoryPoolFile()	{

	rb_RPDB_MemoryPoolFile	=	rb_define_class_under(	rb_RPDB_Environment, 
																															"File",			
																															rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFile, 	"new",										rb_RPDB_MemoryPoolFile_new,										-1 	);
	rb_define_method(						rb_RPDB_MemoryPoolFile, 	"initialize",							rb_RPDB_MemoryPoolFile_init,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_RPDB_MemoryPoolFile, 	"settings_controller",		rb_RPDB_MemoryPoolFile_settingsController,		0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFile, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFile, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFile, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_RPDB_MemoryPoolFile, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_RPDB_MemoryPoolFile, 	"parent_environment",			rb_RPDB_MemoryPoolFile_parentEnvironment,			0 	);
	rb_define_alias(						rb_RPDB_MemoryPoolFile, 	"environment",						"parent_environment"	);                              	

	rb_define_method(						rb_RPDB_MemoryPoolFile, 	"sync",										rb_RPDB_MemoryPoolFile_sync,									0 	);
	rb_define_method(						rb_RPDB_MemoryPoolFile, 	"close",									rb_RPDB_MemoryPoolFile_close,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_MemoryPoolFile_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_memory_pool_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_RPDB_MemoryPoolController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_controller, rb_RPDB_MemoryPoolFileController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]",
			"[ <parent memory pool file controller> ]"
		)
	);
	
	RPDB_MemoryPoolFileController*	c_parent_memory_pool_file_controller;
	C_RPDB_MEMORY_POOL_FILE_CONTROLLER( rb_parent_memory_pool_file_controller, c_parent_memory_pool_file_controller );
	
	VALUE	rb_memory_pool_file		=	RUBY_RPDB_MEMORY_POOL_FILE( RPDB_MemoryPoolFile_new( c_parent_memory_pool_file_controller ) );	

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file,
							RPDB_RB_MEMORY_POOL_FILE_VARIABLE_PARENT_MEMORY_POOL_FILE_CONTROLLER,
							rb_parent_memory_pool_file_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_controller };
	rb_obj_call_init(	rb_memory_pool_file,
					 					1, 
					 					argv );
	
	return rb_memory_pool_file;	
}

/*************
*  new  *
*************/
	
VALUE rb_RPDB_MemoryPoolFile_init(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file )	{

	RPDB_MemoryPoolFile*	c_memory_pool_file;
	C_RPDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	return RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( RPDB_MemoryPoolFile_settingsController( c_memory_pool_file ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file )	{

	RPDB_MemoryPoolFile*	c_memory_pool_file;
	C_RPDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MemoryPoolFile_parentEnvironment( c_memory_pool_file ) );

}

/*************
*  sync  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fsync.html
VALUE rb_RPDB_MemoryPoolFile_sync( VALUE	rb_memory_pool_file )	{

	RPDB_MemoryPoolFile*	c_memory_pool_file;
	C_RPDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	RPDB_MemoryPoolFile_sync( c_memory_pool_file );
	
	return rb_memory_pool_file;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fclose.html
VALUE rb_RPDB_MemoryPoolFile_close( VALUE	rb_memory_pool_file )	{

	RPDB_MemoryPoolFile*	c_memory_pool_file;
	C_RPDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	RPDB_MemoryPoolFile_close( c_memory_pool_file );
	
	return rb_memory_pool_file;
}
