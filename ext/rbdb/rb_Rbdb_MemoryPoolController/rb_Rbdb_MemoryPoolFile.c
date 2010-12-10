/*
 *		Rbdb::MemoryPoolController::MemoryPoolFile
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_MemoryPoolFile.h"
#include "rb_Rbdb_MemoryPoolController.h"
#include "rb_Rbdb_MemoryPoolFileController.h"
 
#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_MemoryPoolFile.h>

#include <rbdb/Rbdb_MemoryPoolFileSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_MemoryPoolFile;
extern	VALUE	rb_Rbdb_MemoryPoolFileSettingsController;
extern	VALUE	rb_Rbdb_MemoryPoolController;
extern	VALUE	rb_Rbdb_MemoryPoolFileController;

void Init_Rbdb_MemoryPoolFile()	{

	rb_Rbdb_MemoryPoolFile	=	rb_define_class_under(	rb_Rbdb_Environment, 
																															"File",			
																															rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MemoryPoolFile, 	"new",										rb_Rbdb_MemoryPoolFile_new,										-1 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFile, 	"initialize",							rb_Rbdb_MemoryPoolFile_initialize,									-1 	);
                                                                                          	                                                      	
	rb_define_method(						rb_Rbdb_MemoryPoolFile, 	"settings_controller",		rb_Rbdb_MemoryPoolFile_settingsController,		0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFile, 	"settings",								"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFile, 	"set",										"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFile, 	"set_to",									"settings_controller"	);                              	
	rb_define_alias(						rb_Rbdb_MemoryPoolFile, 	"is_set_to",							"settings_controller"	);                              	
	rb_define_method(						rb_Rbdb_MemoryPoolFile, 	"parent_environment",			rb_Rbdb_MemoryPoolFile_parentEnvironment,			0 	);
	rb_define_alias(						rb_Rbdb_MemoryPoolFile, 	"environment",						"parent_environment"	);                              	

	rb_define_method(						rb_Rbdb_MemoryPoolFile, 	"sync",										rb_Rbdb_MemoryPoolFile_sync,									0 	);
	rb_define_method(						rb_Rbdb_MemoryPoolFile, 	"close",									rb_Rbdb_MemoryPoolFile_close,									0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_MemoryPoolFile_new(	int			argc,
																	VALUE*	args,
																	VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_memory_pool_controller				=	Qnil;
	VALUE	rb_parent_memory_pool_file_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_controller, rb_Rbdb_MemoryPoolController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_file_controller, rb_Rbdb_MemoryPoolFileController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent memory pool controller> ]",
			"[ <parent memory pool file controller> ]"
		)
	);
	
	Rbdb_MemoryPoolFileController*	c_parent_memory_pool_file_controller;
	C_Rbdb_MEMORY_POOL_FILE_CONTROLLER( rb_parent_memory_pool_file_controller, c_parent_memory_pool_file_controller );
	
	VALUE	rb_memory_pool_file		=	RUBY_RBDB_MEMORY_POOL_FILE( Rbdb_MemoryPoolFile_new( c_parent_memory_pool_file_controller ) );	

	//	store reference to parent
	rb_iv_set(	rb_memory_pool_file,
							Rbdb_RB_MEMORY_POOL_FILE_VARIABLE_PARENT_MEMORY_POOL_FILE_CONTROLLER,
							rb_parent_memory_pool_file_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_file_controller };
	rb_obj_call_init(	rb_memory_pool_file,
					 					1, 
					 					argv );
	
	return rb_memory_pool_file;	
}

/*************
*  self.new  *
*************/
	
VALUE rb_Rbdb_MemoryPoolFile_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/

VALUE rb_Rbdb_MemoryPoolFile_settingsController(	VALUE	rb_memory_pool_file )	{

	VALUE	rb_local_memory_pool_file_settings_controller	=	Qnil;
	
	if ( ( rb_local_memory_pool_file_settings_controller = rb_iv_get(	rb_memory_pool_file,
																																Rbdb_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_MemoryPoolFile*		c_memory_pool_file;
		C_Rbdb_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );
	
		Rbdb_MemoryPoolFileSettingsController*	c_local_memory_pool_file_settings_controller	=	Rbdb_MemoryPoolFile_settingsController( c_memory_pool_file );

		rb_local_memory_pool_file_settings_controller	=	RUBY_RBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_local_memory_pool_file_settings_controller );

		rb_iv_set(	rb_memory_pool_file,
								Rbdb_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER,
								rb_local_memory_pool_file_settings_controller );
	}

	return rb_local_memory_pool_file_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_Rbdb_MemoryPoolFile_parentEnvironment(	VALUE	rb_memory_pool_file )	{

	VALUE	rb_parent_memory_pool_controller		=	rb_Rbdb_MemoryPoolFile_parentMemoryPoolController( rb_memory_pool_file );
	VALUE	rb_parent_environment								=	rb_Rbdb_MemoryPoolController_parentEnvironment( rb_parent_memory_pool_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_memory_pool_controller  *
***************************************/
VALUE rb_Rbdb_MemoryPoolFile_parentMemoryPoolController(	VALUE	rb_memory_pool_file )	{

	VALUE	rb_parent_memory_pool_file_controller	=	rb_Rbdb_MemoryPoolFile_parentMemoryPoolFileController( rb_memory_pool_file );
	VALUE	rb_parent_memory_pool_controller			=	rb_Rbdb_MemoryPoolFileController_parentMemoryPoolController( rb_parent_memory_pool_file_controller );
	
	return rb_parent_memory_pool_controller;
}

/***************************************
*  parent_memory_pool_file_controller  *
***************************************/
VALUE rb_Rbdb_MemoryPoolFile_parentMemoryPoolFileController(	VALUE	rb_memory_pool_file )	{

	VALUE	rb_parent_memory_pool_file_controller	=	rb_iv_get(	rb_memory_pool_file,
																														Rbdb_RB_MEMORY_POOL_FILE_VARIABLE_PARENT_MEMORY_POOL_FILE_CONTROLLER );
	return rb_parent_memory_pool_file_controller;
}

/*************
*  sync  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fsync.html
VALUE rb_Rbdb_MemoryPoolFile_sync( VALUE	rb_memory_pool_file )	{

	Rbdb_MemoryPoolFile*	c_memory_pool_file;
	C_Rbdb_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	Rbdb_MemoryPoolFile_sync( c_memory_pool_file );
	
	return rb_memory_pool_file;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_fclose.html
VALUE rb_Rbdb_MemoryPoolFile_close( VALUE	rb_memory_pool_file )	{

	Rbdb_MemoryPoolFile*	c_memory_pool_file;
	C_Rbdb_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file );

	Rbdb_MemoryPoolFile_close( c_memory_pool_file );
	
	return rb_memory_pool_file;
}
