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

#include "rb_RPDB_MemoryPoolFileSettingsController.h"
#include "rb_RPDB_MemoryPoolFileCacheSettingsController.h"
#include "rb_RPDB_MemoryPoolFilePageSettingsController.h"
#include "rb_RPDB_MemoryPoolSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_MemoryPoolFileSettingsController.h>
#include <rpdb/RPDB_MemoryPoolFileCachePrioritySettingsController.h>
#include <rpdb/RPDB_MemoryPoolFilePageSettingsController.h>
#include <rpdb/RPDB_MemoryPoolSettingsController.h>
#include <rpdb/RPDB_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_MemoryPoolFileSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MemoryPoolSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileCacheSettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFileCachePrioritySettingsController;
extern	VALUE	rb_RPDB_MemoryPoolFilePageSettingsController;

void Init_RPDB_MemoryPoolFileSettingsController()	{

	rb_RPDB_MemoryPoolFileSettingsController		=	rb_define_class_under(	rb_RPDB_MemoryPoolSettingsController, 
																																				"File",	
																																				rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MemoryPoolFileSettingsController, 	"new",																rb_RPDB_MemoryPoolFileSettingsController_new,																								-1 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"initialize",													rb_RPDB_MemoryPoolFileSettingsController_initialize,																								-1 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController,					"parent_settings_controller",					rb_RPDB_MemoryPoolFileSettingsController_parentSettingsController,								0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController,					"parent_memory_pool_settings_controller",					rb_RPDB_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController,								0 	);

	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"parent_environment",									rb_RPDB_MemoryPoolFileSettingsController_parentEnvironment,																		0 	);
	rb_define_alias(			rb_RPDB_MemoryPoolFileSettingsController, 				"environment",												"parent_environment"	);
                                    			                                                                                                    				
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"create_with_number_initial_bytes_numbering",														rb_RPDB_MemoryPoolFileSettingsController_createWithInitialNullBytesNumbering,								0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_create_with_initial_null_bytes_numbering",														rb_RPDB_MemoryPoolFileSettingsController_setCreateWithInitialNullBytesNumbering,			0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"file_id",														rb_RPDB_MemoryPoolFileSettingsController_fileID,																					0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_file_id",														rb_RPDB_MemoryPoolFileSettingsController_setFileID,																				0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"file_type",														rb_RPDB_MemoryPoolFileSettingsController_fileType,																				0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_file_type",														rb_RPDB_MemoryPoolFileSettingsController_setFileType,																			0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"log_sequence_number_offset",														rb_RPDB_MemoryPoolFileSettingsController_logSequenceNumberOffset,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_log_sequence_number_offset",														rb_RPDB_MemoryPoolFileSettingsController_setLogSequenceNumberOffset,											0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"max_file_size_in_bytes",														rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInBytes,															0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"max_file_size_in_kbytes",														rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInKBytes,															0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"max_file_size_in_mbytes",														rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInMBytes,															0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"max_file_size_in_gbytes",														rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInGBytes,															0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_max_file_size_in_bytes",														rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInBytes,														0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_max_file_size_in_kbytes",														rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInKBytes,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_max_file_size_in_mbytes",														rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInMBytes,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_max_file_size_in_gbytes",														rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInGBytes,													0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"cookie",														rb_RPDB_MemoryPoolFileSettingsController_cookie,																					0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"set_cookie",														rb_RPDB_MemoryPoolFileSettingsController_setCookie,																				0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"cache_settings_controller",														rb_RPDB_MemoryPoolFileSettingsController_cacheSettingsController,									0 	);
	rb_define_method(			rb_RPDB_MemoryPoolFileSettingsController, 				"page_settings_controller",														rb_RPDB_MemoryPoolFileSettingsController_pageSettingsController,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPDB_MemoryPoolFileSettingsController_new(	int			argc,
																										VALUE*	args,
																										VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment											=	Qnil;
	VALUE	rb_parent_settings_controller							=	Qnil;
	VALUE	rb_parent_memory_pool_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ),
																						R_MatchAncestorInstance( rb_parent_memory_pool_settings_controller, rb_RPDB_MemoryPoolSettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]",
			"[ <parent memory pool settings controller> ]"
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

	RPDB_MemoryPoolSettingsController*	c_parent_memory_pool_settings_controller;
	C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_parent_memory_pool_settings_controller, c_parent_memory_pool_settings_controller );

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller	=	RPDB_MemoryPoolSettingsController_fileSettingsController( c_parent_memory_pool_settings_controller );

	VALUE	rb_memory_pool_file_settings_controller	= RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_memory_pool_file_settings_controller );

	rb_iv_set(	rb_memory_pool_file_settings_controller,
							RPDB_RB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER,
							rb_parent_memory_pool_settings_controller );

	VALUE	argv[]	=	{ rb_parent_memory_pool_settings_controller };
	rb_obj_call_init(	rb_memory_pool_file_settings_controller,
										 1, 
										 argv );
	
	return rb_memory_pool_file_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self )	{
	
	return rb_self;
}

//	We have a general settings controller and a particular settings controller
//	No setting is applied until the particular settings controller is created
//	At that point, any non-NULL values will be applied to the particular instance. 

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_parentEnvironment(	VALUE	rb_memory_pool_file_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_MemoryPoolFileSettingsController_parentSettingsController( rb_memory_pool_file_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_parentSettingsController(	VALUE	rb_memory_pool_file_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller		=	rb_RPDB_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController( rb_memory_pool_file_settings_controller );
	VALUE	rb_parent_settings_controller								=	rb_RPDB_MemoryPoolSettingsController_parentSettingsController( rb_parent_memory_pool_settings_controller );
	
	return rb_parent_settings_controller;	
}

/*******************************************
*  parent_memory_pool_settings_controller  *
*******************************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_parentMemoryPoolSettingsController(	VALUE	rb_memory_pool_file_settings_controller )	{

	VALUE	rb_parent_memory_pool_settings_controller	=	rb_iv_get(	rb_memory_pool_file_settings_controller,
																																RPDB_RB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER );

	return rb_parent_memory_pool_settings_controller;
}

/*********************************************
*  create_with_initial_null_bytes_numbering  *
*********************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_clear_len.html
VALUE rb_RPDB_MemoryPoolFileSettingsController_createWithInitialNullBytesNumbering( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );
											
	return INT2NUM( RPDB_MemoryPoolFileSettingsController_createWithInitialNullBytesNumbering( c_memory_pool_file_settings_controller ) );
}

	/*************************************************
	*  set_create_with_initial_null_bytes_numbering  *
	*************************************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setCreateWithInitialNullBytesNumbering( VALUE	rb_memory_pool_file_settings_controller, 
																								VALUE	rb_initial_null_bytes )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setCreateWithInitialNullBytesNumbering(	c_memory_pool_file_settings_controller,
																							FIX2INT( rb_initial_null_bytes ) );

		return rb_memory_pool_file_settings_controller;
	}

/************
*  file_id  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_fileid.html
VALUE rb_RPDB_MemoryPoolFileSettingsController_fileID( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

										//	FIX - file
	return INT2FIX( RPDB_MemoryPoolFileSettingsController_fileID( c_memory_pool_file_settings_controller ) );
}

	/****************
	*  set_file_id  *
	****************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setFileID(	VALUE	rb_memory_pool_file_settings_controller, 
																														VALUE	rb_file_id __attribute__ ((unused )) )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );
	
		uint8_t*	c_file_id;

											//	FIX - file
		RPDB_MemoryPoolFileSettingsController_setFileID(	c_memory_pool_file_settings_controller,
																											c_file_id );

		return rb_memory_pool_file_settings_controller;
	}

/**************
*  file_type  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_ftype.html
//	The ftype parameter sets the file's type for the purposes of input and output processing. 
//	The ftype must be the same as a ftype parameter previously specified to the DB_ENV->memp_register method.
VALUE rb_RPDB_MemoryPoolFileSettingsController_fileType( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2FIX( RPDB_MemoryPoolFileSettingsController_fileType( c_memory_pool_file_settings_controller ) );
}

	/******************
	*  set_file_type  *
	******************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setFileType(	VALUE	rb_memory_pool_file_settings_controller, 
																	VALUE	rb_file_type )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setFileType(	c_memory_pool_file_settings_controller,
															rb_file_type );

		return rb_memory_pool_file_settings_controller;
	}

/*******************************
*  log_sequence_number_offset  *
*******************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_lsn_offset.html
VALUE rb_RPDB_MemoryPoolFileSettingsController_logSequenceNumberOffset( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2FIX( RPDB_MemoryPoolFileSettingsController_logSequenceNumberOffset( c_memory_pool_file_settings_controller ) );
}

	/***********************************
	*  set_log_sequence_number_offset  *
	***********************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setLogSequenceNumberOffset(	VALUE	rb_memory_pool_file_settings_controller, 
																				VALUE	rb_log_sequence_number_offset )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setLogSequenceNumberOffset(	c_memory_pool_file_settings_controller,
																			FIX2INT( rb_log_sequence_number_offset ) );

		return rb_memory_pool_file_settings_controller;
	}

/***************************
*  max_file_size_in_bytes  *
***************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_maxsize.html
VALUE rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInBytes( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2NUM( RPDB_MemoryPoolFileSettingsController_maxFileSizeInBytes( c_memory_pool_file_settings_controller ) );
}

/****************************
*  max_file_size_in_kbytes  *
****************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInKBytes( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2NUM( RPDB_MemoryPoolFileSettingsController_maxFileSizeInKBytes( c_memory_pool_file_settings_controller ) );
}

/****************************
*  max_file_size_in_mbytes  *
****************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInMBytes( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2NUM( RPDB_MemoryPoolFileSettingsController_maxFileSizeInMBytes( c_memory_pool_file_settings_controller ) );
}

/****************************
*  max_file_size_in_gbytes  *
****************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_maxFileSizeInGBytes( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return INT2FIX( RPDB_MemoryPoolFileSettingsController_maxFileSizeInGBytes( c_memory_pool_file_settings_controller ) );
}

	/*******************************
	*  set_max_file_size_in_bytes  *
	*******************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																			VALUE	rb_max_file_size_in_bytes )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInBytes(	c_memory_pool_file_settings_controller,
																		NUM2INT( rb_max_file_size_in_bytes ) );

		return rb_memory_pool_file_settings_controller;
	}

	/********************************
	*  set_max_file_size_in_kbytes  *
	********************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInKBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																			VALUE	rb_size_in_kbytes )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInKBytes(	c_memory_pool_file_settings_controller,
																		NUM2INT( rb_size_in_kbytes ) );

		return rb_memory_pool_file_settings_controller;
	}

	/********************************
	*  set_max_file_size_in_mbytes  *
	********************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInMBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																			VALUE	rb_size_in_mbytes )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInMBytes(	c_memory_pool_file_settings_controller,
																		NUM2INT( rb_size_in_mbytes ) );

		return rb_memory_pool_file_settings_controller;
	}

	/********************************
	*  set_max_file_size_in_gbytes  *
	********************************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInGBytes(	VALUE	rb_memory_pool_file_settings_controller, 
																			VALUE	rb_size_in_gbytes )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_MemoryPoolFileSettingsController_setMaxFileSizeInGBytes(	c_memory_pool_file_settings_controller,
																		FIX2INT( rb_size_in_gbytes ) );

		return rb_memory_pool_file_settings_controller;
	}

/***********
*  cookie  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/memp_set_pgcookie.html
VALUE rb_RPDB_MemoryPoolFileSettingsController_cookie( VALUE	rb_memory_pool_file_settings_controller )	{

	RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
	C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

	return RUBY_RPDB_RECORD( RPDB_MemoryPoolFileSettingsController_cookie( c_memory_pool_file_settings_controller ) );
}

	/***************
	*  set_cookie  *
	***************/

	VALUE rb_RPDB_MemoryPoolFileSettingsController_setCookie(	VALUE	rb_memory_pool_file_settings_controller, 
																VALUE	rb_cookie )	{

		RPDB_MemoryPoolFileSettingsController*	c_memory_pool_file_settings_controller;
		C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller );

		RPDB_Record*		c_cookie;
		C_RPDB_RECORD( rb_cookie, c_cookie );

		RPDB_MemoryPoolFileSettingsController_setCookie(	c_memory_pool_file_settings_controller,
															c_cookie );

		return rb_memory_pool_file_settings_controller;
	}

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/******************************
*  cache_settings_controller  *
******************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_cacheSettingsController( VALUE	rb_memory_pool_file_settings_controller )	{

	VALUE	rb_memory_pool_file_cache_settings_controller	=	Qnil;
	
	if ( ( rb_memory_pool_file_cache_settings_controller = rb_iv_get(	rb_memory_pool_file_settings_controller,
																																		RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_memory_pool_file_cache_settings_controller	=	rb_RPDB_MemoryPoolFileCacheSettingsController_new(	1,
																																																				& rb_memory_pool_file_settings_controller,
																																																				rb_RPDB_MemoryPoolFileCacheSettingsController );
		rb_iv_set(	rb_memory_pool_file_cache_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER,
								rb_memory_pool_file_settings_controller );
	}
	
	return rb_memory_pool_file_cache_settings_controller;
}

/*****************************
*  page_settings_controller  *
*****************************/

VALUE rb_RPDB_MemoryPoolFileSettingsController_pageSettingsController( VALUE	rb_memory_pool_file_settings_controller )	{

	VALUE	rb_memory_pool_file_page_settings_controller	=	Qnil;
	
	if ( ( rb_memory_pool_file_page_settings_controller = rb_iv_get(	rb_memory_pool_file_settings_controller,
																																		RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_memory_pool_file_page_settings_controller	=	rb_RPDB_MemoryPoolFilePageSettingsController_new(	1,
																																																			& rb_memory_pool_file_settings_controller,
																																																			rb_RPDB_MemoryPoolFilePageSettingsController );
		rb_iv_set(	rb_memory_pool_file_page_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER,
								rb_memory_pool_file_settings_controller );
	}
	
	return rb_memory_pool_file_page_settings_controller;
}
