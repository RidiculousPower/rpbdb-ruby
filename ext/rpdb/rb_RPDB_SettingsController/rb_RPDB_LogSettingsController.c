/*
 *		RPDB::SettingsController::LogSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_LogSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"
#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_LogSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_LogSettingsController;

void Init_RPDB_LogSettingsController()	{

	rb_RPDB_LogSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																														"Log",	
																														rb_cObject );

	rb_define_singleton_method(	rb_RPDB_LogSettingsController, 	"new",																				rb_RPDB_LogSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"initialize",																	rb_RPDB_LogSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPDB_LogSettingsController, 				"parent_environment",													rb_RPDB_LogSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"environment",																"parent_environment"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"parent_settings_controller",									rb_RPDB_LogSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPDB_LogSettingsController, 				"on?",																				rb_RPDB_LogSettingsController_on,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_on",																		rb_RPDB_LogSettingsController_turnOn,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"off?",																				rb_RPDB_LogSettingsController_off,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_off",																		rb_RPDB_LogSettingsController_turnOff,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"disable_system_buffering?",									rb_RPDB_LogSettingsController_disableSystemBuffering,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"system_buffering?",													"disable_system_buffering?"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_disable_system_buffering_on",						rb_RPDB_LogSettingsController_turnDisableSystemBufferingOn,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_system_buffering_on",										"turn_disable_system_buffering_on"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_disable_system_buffering_off",					rb_RPDB_LogSettingsController_turnDisableSystemBufferingOff,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_system_buffering_off",									"turn_disable_system_buffering_off"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"flush_before_return_from_write?",						rb_RPDB_LogSettingsController_flushBeforeReturnFromWrite,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"flush_after_write?",													"flush_before_return_from_write?"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_flush_before_return_from_write_on",			rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOn,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_flush_after_write_on",									"turn_flush_before_return_from_write_on"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_flush_before_return_from_write_off",		rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOff,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_flush_after_write_off",									"turn_flush_before_return_from_write_off"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"autoremove_logs?",														rb_RPDB_LogSettingsController_autoremoveLogs,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"autoremove?",																"autoremove_logs?"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_autoremove_logs_on",										rb_RPDB_LogSettingsController_turnAutoremoveLogsOn,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_autoremove_on",													"turn_autoremove_logs_on"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_autoremove_logs_off",										rb_RPDB_LogSettingsController_turnAutoremoveOff,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_autoremove_off",												"turn_autoremove_logs_off"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"log_in_memory?",															rb_RPDB_LogSettingsController_logInMemory,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"in_memory?",																	"log_in_memory?"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_log_in_memory_on",											rb_RPDB_LogSettingsController_turnLogInMemoryOn,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_log_in_memory_off",											rb_RPDB_LogSettingsController_turnLogInMemoryOff,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"zero_at_creation?",													rb_RPDB_LogSettingsController_zeroAtCreation,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_zero_at_creation_on",										rb_RPDB_LogSettingsController_turnZeroAtCreationOn,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_zero_at_creation_off",									rb_RPDB_LogSettingsController_turnZeroAtCreationOff,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"force_flush_after_record_write?",						rb_RPDB_LogSettingsController_forceFlushAfterRecordWrite,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"flush_after_write?",													"force_flush_after_record_write?"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_force_flush_after_record_write_on",			rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOn,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_flush_after_write_on",									"turn_force_flush_after_record_write_on"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"turn_force_flush_after_record_write_off",		rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOff,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"turn_flush_after_write_off",									"turn_force_flush_after_record_write_off"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"buffer_size",																rb_RPDB_LogSettingsController_bufferSize,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"set_buffer_size",														rb_RPDB_LogSettingsController_setBufferSize,													1 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"directory",																	rb_RPDB_LogSettingsController_directory,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"set_directory",															rb_RPDB_LogSettingsController_setDirectory,													1 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"mode",																				rb_RPDB_LogSettingsController_mode,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"set_mode",																		rb_RPDB_LogSettingsController_setMode,													1 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"max_log_size",																rb_RPDB_LogSettingsController_maxLogSize,													0 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"max_size",																		"max_log_size"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"set_max_log_size",														rb_RPDB_LogSettingsController_setMaxLogSize,													1 	);
	rb_define_alias(			rb_RPDB_LogSettingsController, 				"set_max_size",																"set_max_log_size"	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"max_region_size",														rb_RPDB_LogSettingsController_maxRegionSize,													0 	);
	rb_define_method(			rb_RPDB_LogSettingsController, 				"set_max_region_size",												rb_RPDB_LogSettingsController_setMaxRegionSize,													1 	);

}


/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/
	
VALUE rb_RPDB_LogSettingsController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );	
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	RPDB_LogSettingsController*	c_log_settings_controller	=	RPDB_SettingsController_logSettingsController( c_parent_settings_controller );

	VALUE	rb_log_settings_controller	= RUBY_RPDB_LOG_SETTINGS_CONTROLLER( c_log_settings_controller );

	rb_iv_set(	rb_log_settings_controller,
							RPDB_RB_LOG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_log_settings_controller,
										 1, 
										 argv );
	
	return rb_log_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_LogSettingsController_initialize(	int				argc __attribute__ ((unused)),
																					VALUE*		args __attribute__ ((unused)),
																					VALUE			rb_self )	{
	
	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_LogSettingsController_parentEnvironment(	VALUE	rb_log_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_LogSettingsController_parentSettingsController( rb_log_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_LogSettingsController_parentSettingsController(	VALUE	rb_log_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_log_settings_controller,
																										RPDB_RB_LOG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********
*  on?  *
********/

//	DB_INIT_LOG			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
VALUE rb_RPDB_LogSettingsController_on( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_on( c_log_settings_controller )	?	Qtrue
																																			:	Qfalse );
}

	/************
	*  turn_on  *
	************/

	VALUE rb_RPDB_LogSettingsController_turnOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnOn( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/*********
*  off?  *
*********/

VALUE rb_RPDB_LogSettingsController_off( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_off( c_log_settings_controller )	?	Qtrue
																																				:	Qfalse );
}

	/*************
	*  turn_off  *
	*************/

	VALUE rb_RPDB_LogSettingsController_turnOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/******************************
*  disable_system_buffering?  *
******************************/

//	DB_LOG_DIRECT		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_log_set_config.html
//	Inverted from BDB Default
VALUE rb_RPDB_LogSettingsController_disableSystemBuffering( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_disableSystemBuffering( c_log_settings_controller )	?	Qtrue
																				:	Qfalse );
}

	/*************************************
	*  turn_disable_system_buffering_on  *
	*************************************/

	VALUE rb_RPDB_LogSettingsController_turnDisableSystemBufferingOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnDisableSystemBufferingOn( c_log_settings_controller );
	
		return rb_log_settings_controller;
	}

	/**************************************
	*  turn_disable_system_buffering_off  *
	**************************************/

	VALUE rb_RPDB_LogSettingsController_turnDisableSystemBufferingOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnDisableSystemBufferingOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/***********************************
*  flush_before_return_from_write  *
***********************************/

//	DB_LOG_DSYNC		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_log_set_config.html
VALUE rb_RPDB_LogSettingsController_flushBeforeReturnFromWrite( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_flushBeforeReturnFromWrite( c_log_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/*******************************************
	*  turn_flush_before_return_from_write_on  *
	*******************************************/

	VALUE rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOn( c_log_settings_controller );

		return rb_log_settings_controller;
	}

	/********************************************
	*  turn_flush_before_return_from_write_off  *
	********************************************/

	VALUE rb_RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnFlushBeforeReturnFromWriteOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/********************
*  autoremove_logs  *
********************/

//	DB_LOG_AUTO_REMOVE	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_log_set_config.html
VALUE rb_RPDB_LogSettingsController_autoremoveLogs( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_autoremoveLogs( c_log_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/***********************
	*  turn_autoremove_on  *
	***********************/

	VALUE rb_RPDB_LogSettingsController_turnAutoremoveLogsOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnAutoremoveLogsOn( c_log_settings_controller );

		return rb_log_settings_controller;
	}

	/************************
	*  turn_autoremove_off  *
	************************/

	VALUE rb_RPDB_LogSettingsController_turnAutoremoveOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnAutoremoveOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/******************
*  log_in_memory  *
******************/

//	DB_LOG_IN_MEMORY	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_log_set_config.html
VALUE rb_RPDB_LogSettingsController_logInMemory( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_logInMemory( c_log_settings_controller )	?	Qtrue
																																								:	Qfalse );
}

	/**************************
	*  turn_log_in_memory_on  *
	**************************/

	VALUE rb_RPDB_LogSettingsController_turnLogInMemoryOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnLogInMemoryOn( c_log_settings_controller );

		return rb_log_settings_controller;
	}

	/***************************
	*  turn_log_in_memory_off  *
	***************************/

	VALUE rb_RPDB_LogSettingsController_turnLogInMemoryOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnLogInMemoryOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/**********************
*  zero_at_creation?  *
**********************/

//	DB_LOG_ZERO			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_log_set_config.html
VALUE rb_RPDB_LogSettingsController_zeroAtCreation( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_zeroAtCreation( c_log_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/*****************************
	*  turn_zero_at_creation_on  *
	*****************************/

	VALUE rb_RPDB_LogSettingsController_turnZeroAtCreationOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnZeroAtCreationOn( c_log_settings_controller );

		return rb_log_settings_controller;
	}

	/******************************
	*  turn_zero_at_creation_off  *
	******************************/

	VALUE rb_RPDB_LogSettingsController_turnZeroAtCreationOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnZeroAtCreationOff( c_log_settings_controller );

		return rb_log_settings_controller;
	}

/************************************
*  force_flush_after_record_write?  *
************************************/

VALUE rb_RPDB_LogSettingsController_forceFlushAfterRecordWrite( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return ( RPDB_LogSettingsController_forceFlushAfterRecordWrite( c_log_settings_controller )	?	Qtrue
																									:	Qfalse );
}

	/*******************************************
	*  turn_force_flush_after_record_write_on  *
	*******************************************/

	VALUE rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOn( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOn( c_log_settings_controller );
	
		return rb_log_settings_controller;
	}

	/********************************************
	*  turn_force_flush_after_record_write_off  *
	********************************************/

	VALUE rb_RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOff( VALUE	rb_log_settings_controller )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_turnForceFlushAfterRecordWriteOff( c_log_settings_controller );
	
		return rb_log_settings_controller;
	}

/****************
*  buffer_size  *
****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lg_bsize.html
VALUE rb_RPDB_LogSettingsController_bufferSize( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return INT2FIX( RPDB_LogSettingsController_bufferSize( c_log_settings_controller ) );
}

	/********************
	*  set_buffer_size  *
	********************/

	VALUE rb_RPDB_LogSettingsController_setBufferSize(	VALUE	rb_log_settings_controller, 
														VALUE	rb_buffer_size )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_setBufferSize(	c_log_settings_controller,
		 											FIX2INT( rb_buffer_size ) );

		return rb_log_settings_controller;
	}

/**************
*  directory  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lg_dir.html
VALUE rb_RPDB_LogSettingsController_directory( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return rb_str_new2( RPDB_LogSettingsController_directory( c_log_settings_controller ) );
}

	/******************
	*  set_directory  *
	******************/

	VALUE rb_RPDB_LogSettingsController_setDirectory(	VALUE	rb_log_settings_controller, 
														VALUE	rb_directory )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_setDirectory(	c_log_settings_controller,
													StringValuePtr( rb_directory ) );

		return rb_log_settings_controller;
	}

/*********
*  mode  *
*********/

//	Set the absolute file mode for created log files. This method is only useful for the rare Berkeley DB application that does not control its umask value.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lg_mode.html
VALUE rb_RPDB_LogSettingsController_mode( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return INT2FIX( RPDB_LogSettingsController_mode( c_log_settings_controller ) );
}

	/*************
	*  set_mode  *
	*************/

	VALUE rb_RPDB_LogSettingsController_setMode(	VALUE	rb_log_settings_controller, 
													VALUE	rb_mode )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_setMode(	c_log_settings_controller,
												FIX2INT( rb_mode ) );

		return rb_log_settings_controller;
	}

/*****************
*  max_log_size  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lg_max.html
VALUE rb_RPDB_LogSettingsController_maxLogSize( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return INT2FIX( RPDB_LogSettingsController_maxLogSize( c_log_settings_controller ) );
}

	/*********************
	*  set_max_log_size  *
	*********************/

	VALUE rb_RPDB_LogSettingsController_setMaxLogSize(	VALUE	rb_log_settings_controller, 
														VALUE	rb_max_size )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_setMaxLogSize(	c_log_settings_controller,
													FIX2INT( rb_max_size ) );

		return rb_log_settings_controller;
	}

/********************
*  max_region_size  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_lg_regionmax.html
VALUE rb_RPDB_LogSettingsController_maxRegionSize( VALUE	rb_log_settings_controller )	{

	RPDB_LogSettingsController*	c_log_settings_controller;
	C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

	return INT2FIX( RPDB_LogSettingsController_maxRegionSize(	c_log_settings_controller ) );
}

	/************************
	*  set_max_region_size  *
	************************/

	VALUE rb_RPDB_LogSettingsController_setMaxRegionSize(	VALUE	rb_log_settings_controller, 
															VALUE	rb_max_region_size )	{

		RPDB_LogSettingsController*	c_log_settings_controller;
		C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller );

		RPDB_LogSettingsController_setMaxRegionSize(	c_log_settings_controller,
														FIX2INT( rb_max_region_size ) );

		return rb_log_settings_controller;
	}
