/*
 *		RPDB_settingsController:RPDB_DebugSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DebugSettingsController.h"
#include "rb_RPDB_DebugVerbositySettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"

#include "rb_RPDB.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DebugSettingsController.h>
#include <rpdb/RPDB_DebugVerbositySettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRPDB;
VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_Database;
VALUE	extern	rb_RPDB_SettingsController;
VALUE	extern	rb_RPDB_DebugSettingsController;
VALUE	extern	rb_RPDB_DebugVerbositySettingsController;

void Init_RPDB_DebugSettingsController()	{

	rb_RPDB_DebugSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																															"Debug",	
																															rb_cObject );

	rb_define_singleton_method(	rb_RPDB_DebugSettingsController, 	"new",																																	rb_RPDB_DebugSettingsController_new,									-1 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"initialize",																														rb_RPDB_DebugSettingsController_initialize,									-1 	);
                    					                                                                                        				
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"parent_environment",																										rb_RPDB_DebugSettingsController_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPDB_DebugSettingsController, 	"environment",																													"parent_environment"	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"parent_settings_controller",																						rb_RPDB_DebugSettingsController_parentSettingsController,							0 	);
                    					                                                                                        				
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"run_normal_recovery_before_opening_environment?",											rb_RPDB_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment,									0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_run_normal_recovery_before_opening_environment_on",								rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn,								0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_run_normal_recovery_before_opening_environment_off",							rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff,				0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"run_catastrophic_recovery_before_opening_environment?",								rb_RPDB_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment,		0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_run_catastrophic_recovery_before_opening_environment_on",					rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn,		0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_run_catastrophic_recovery_before_opening_environment_off",				rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff,					0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"open_in_lockdown?",																										rb_RPDB_DebugSettingsController_openInLockdown,				0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_open_in_lockdown_on",																							rb_RPDB_DebugSettingsController_turnOpenInLockdownOn,				0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_open_in_lockdown_off",																						rb_RPDB_DebugSettingsController_turnOpenInLockdownOff,							0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"register_for_recovery?",																								rb_RPDB_DebugSettingsController_registerForRecovery,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_register_for_recovery_on",																				rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOn,					0 	);                    					                                                                                        									    		
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_register_for_recovery_off",																				rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOff,							0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"prohibit_panic?",																												rb_RPDB_DebugSettingsController_prohibitPanic,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_prohibit_panic_on",																								rb_RPDB_DebugSettingsController_turnProhibitPanicOn,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_prohibit_panic_off",																							rb_RPDB_DebugSettingsController_turnProhibitPanicOff,						0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"panic?",																																rb_RPDB_DebugSettingsController_panic,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_panic_on",																												rb_RPDB_DebugSettingsController_turnPanicOn,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_panic_off",																												rb_RPDB_DebugSettingsController_turnPanicOff,					0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"yield_cpu_for_stress_test?",																						rb_RPDB_DebugSettingsController_yieldCPUForStressTest,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_yield_cpu_for_stress_test_on",																		rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOn,					0 	);
	rb_define_method(						rb_RPDB_DebugSettingsController, 	"turn_yield_cpu_for_stress_test_off",																		rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOff,					0 	);

	rb_define_method(						rb_RPDB_DebugSettingsController, 	"verbosity_settings_controller",																				rb_RPDB_DebugSettingsController_verbositySettingsController,					0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_DebugSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment																	=	Qnil;
	VALUE	rb_parent_settings_controller													=	Qnil;
	VALUE	rb_parent_debug_settings_controller										=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPDB_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"<no args>",
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil
			&&	rb_parent_debug_settings_controller == Qnil )	{
		rb_parent_environment = rb_RPDB_currentWorkingEnvironment( rb_mRPDB );
	}
	
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPDB_Environment_settingsController( rb_parent_environment );
	}

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );
	
	RPDB_DebugSettingsController*	c_debug_settings_controller	=	RPDB_SettingsController_debugSettingsController( c_parent_settings_controller );
	
	VALUE	rb_debug_settings_controller	= RUBY_RPDB_DEBUG_SETTINGS_CONTROLLER( c_debug_settings_controller );

	//	store reference to parent
	rb_iv_set(	rb_debug_settings_controller,
							RPDB_RB_DEBUG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );
	
	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_debug_settings_controller,
										 1, 
										 argv );
	
	return rb_debug_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_DebugSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DebugSettingsController_parentEnvironment(	VALUE	rb_debug_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_DebugSettingsController_parentSettingsController( rb_debug_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_DebugSettingsController_parentSettingsController(	VALUE	rb_debug_settings_controller )	{

	VALUE	rb_parent_database_settings_controller	=	rb_iv_get(	rb_debug_settings_controller,
																															RPDB_RB_DEBUG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_database_settings_controller;
}

/****************************************************
*  run_normal_recovery_before_opening_environment?  *
****************************************************/

//	DB_RECOVER              http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Run normal recovery on this environment before opening it for normal use. 
//	If this flag is set, the DB_CREATE and DB_INIT_TXN flags must also be set, because the regions will be removed and re-created, 
//	and transactions are required for application recovery.
VALUE rb_RPDB_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_runNormalRecoveryBeforeOpeningEnvironment( c_debug_settings_controller )	?	Qtrue
																																																									:	Qfalse );
}

	/***********************************************************
	*  turn_run_normal_recovery_before_opening_environment_on  *
	***********************************************************/

	VALUE rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/************************************************************
	*  turn_run_normal_recovery_before_opening_environment_off  *
	************************************************************/

	VALUE rb_RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnRunNormalRecoveryBeforeOpeningEnvironmentOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/**********************************************************
*  run_catastrophic_recovery_before_opening_environment?  *
**********************************************************/

//	DB_RECOVER_FATAL        http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Run catastrophic recovery on this environment before opening it for normal use. 
//	If this flag is set, the DB_CREATE and DB_INIT_TXN flags must also be set, because the regions will be removed and re-created, 
//	and transactions are required for application recovery.
VALUE rb_RPDB_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_runCatastrophicRecoveryBeforeOpeningEnvironment( c_debug_settings_controller )	?	Qtrue
																															:	Qfalse );
}

	/*****************************************************************
	*  turn_run_catastrophic_recovery_before_opening_environment_on  *
	*****************************************************************/

	//	DB_RECOVER_FATAL        http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );
	
		RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/******************************************************************
	*  turn_run_catastrophic_recovery_before_opening_environment_off  *
	******************************************************************/

	//	DB_RECOVER_FATAL        http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	VALUE rb_RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnRunCatastrophicRecoveryBeforeOpeningEnvironmentOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/**********************
*  open_in_lockdown?  *
**********************/

//	DB_LOCKDOWN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Lock shared Berkeley DB environment files and memory-mapped databases into memory.
VALUE rb_RPDB_DebugSettingsController_openInLockdown( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_openInLockdown( c_debug_settings_controller )	?	Qtrue
																							:	Qfalse );
}

	/*****************************
	*  turn_open_in_lockdown_on  *
	*****************************/

	//	DB_LOCKDOWN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	//	Lock shared Berkeley DB environment files and memory-mapped databases into memory.
	VALUE rb_RPDB_DebugSettingsController_turnOpenInLockdownOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnOpenInLockdownOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/******************************
	*  turn_open_in_lockdown_off  *
	******************************/

	//	DB_LOCKDOWN             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
	//	Lock shared Berkeley DB environment files and memory-mapped databases into memory.
	VALUE rb_RPDB_DebugSettingsController_turnOpenInLockdownOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnOpenInLockdownOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/***************************************************
*  register_for_recovery?  *
***************************************************/

//	DB_REGISTER             http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	Check to see if recovery needs to be performed before opening the database environment. 
//	(For this check to be accurate, all processes using the environment must specify DB_REGISTER when opening the environment.) 
//	If recovery needs to be performed for any reason (including the initial use of the DB_REGISTER flag), and DB_RECOVER is also specified, 
//	recovery will be performed and the open will proceed normally. If recovery needs to be performed and DB_RECOVER is not specified, 
//	DB_RUNRECOVERY will be returned. If recovery does not need to be performed, the DB_RECOVER flag will be ignored. 
//	See Architecting Transactional Data Store applications for more information.
VALUE rb_RPDB_DebugSettingsController_registerForRecovery( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_registerForRecovery( c_debug_settings_controller )	?	Qtrue
																													:	Qfalse );
}

	/**********************************************************
	*  turn_register_for_recovery_on  *
	**********************************************************/

	VALUE rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnRegisterForRecoveryOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/***********************************************************
	*  turn_register_for_recovery_off  *
	***********************************************************/

	VALUE rb_RPDB_DebugSettingsController_turnRegisterForRecoveryOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnRegisterForRecoveryOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/********************
*  prohibit_panic?  *
********************/

//	DB_NOPANIC				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
//
//	If set, Berkeley DB will ignore any panic state in the database environment. 
//
//	Database environments in a panic state normally refuse all attempts to call Berkeley DB functions, returning DB_RUNRECOVERY.
//	This functionality should never be used for purposes other than debugging.
//	Calling DB_ENV->set_flags with the DB_NOPANIC flag only affects the specified DB_ENV name 
//	(and any other Berkeley DB names opened within the scope of that name).
//
//	The DB_NOPANIC flag may be used to configure Berkeley DB at any time during the life of the application.
//
VALUE rb_RPDB_DebugSettingsController_prohibitPanic( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_prohibitPanic( c_debug_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/***************************
	*  turn_prohibit_panic_on  *
	***************************/

	VALUE rb_RPDB_DebugSettingsController_turnProhibitPanicOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnProhibitPanicOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/****************************
	*  turn_prohibit_panic_off  *
	****************************/

	VALUE rb_RPDB_DebugSettingsController_turnProhibitPanicOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnProhibitPanicOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/***********
*  panic?  *
***********/

//	DB_PANIC_ENVIRONMENT    http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
//
//	If set, Berkeley DB will set the panic state for the database environment. 
//
//	Database environments in a panic state normally refuse all attempts to call Berkeley DB functions, returning DB_RUNRECOVERY.
//
//	This flag may not be specified using the environment's DB_CONFIG file.
//
//	Calling DB_ENV->set_flags with the DB_PANIC_ENVIRONMENT flag affects the database environment, including all threads of control accessing the database environment.
//
//	The DB_PANIC_ENVIRONMENT flag may be used to configure Berkeley DB only after the DB_ENV->open method is called.
VALUE rb_RPDB_DebugSettingsController_panic( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_panic( c_debug_settings_controller )	?	Qtrue
																				:	Qfalse );
}

	/******************
	*  turn_panic_on  *
	******************/

	//	DB_PANIC_ENVIRONMENT    http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_DebugSettingsController_turnPanicOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnPanicOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/*******************
	*  turn_panic_off  *
	*******************/

	//	DB_PANIC_ENVIRONMENT    http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
	VALUE rb_RPDB_DebugSettingsController_turnPanicOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnPanicOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/******************************
*  yield_cpu_for_stress_test  *
******************************/

//	DB_YIELDCPU				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_flags.html
//
//	If set, Berkeley DB will yield the processor immediately after each page or mutex acquisition. 
//
//	This functionality should never be used for purposes other than stress testing.
//
//	Calling DB_ENV->set_flags with the DB_YIELDCPU flag only affects the specified DB_ENV name 
//	(and any other Berkeley DB names opened within the scope of that name). 
//
//	For consistent behavior across the environment, all DB_ENV names opened in the environment must either set the 
//	DB_YIELDCPU flag or the flag should be specified in the DB_CONFIG configuration file.
//
//	The DB_YIELDCPU flag may be used to configure Berkeley DB at any time during the life of the application.
VALUE rb_RPDB_DebugSettingsController_yieldCPUForStressTest( VALUE	rb_debug_settings_controller )	{

	RPDB_DebugSettingsController*	c_debug_settings_controller;
	C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

	return ( RPDB_DebugSettingsController_yieldCPUForStressTest( c_debug_settings_controller )	?	Qtrue
																								:	Qfalse );
}

	/**************************************
	*  turn_yield_cpu_for_stress_test_on  *
	**************************************/

	VALUE rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOn( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnYieldCPUForStressTestOn( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

	/***************************************
	*  turn_yield_cpu_for_stress_test_off  *
	***************************************/

	VALUE rb_RPDB_DebugSettingsController_turnYieldCPUForStressTestOff( VALUE	rb_debug_settings_controller )	{

		RPDB_DebugSettingsController*	c_debug_settings_controller;
		C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller );

		RPDB_DebugSettingsController_turnYieldCPUForStressTestOff( c_debug_settings_controller );

		return rb_debug_settings_controller;
	}

/**********************************
*  verbosity_settings_controller  *
**********************************/

VALUE rb_RPDB_DebugSettingsController_verbositySettingsController( VALUE	rb_debug_settings_controller )	{

	VALUE	rb_debug_verbosity_settings_controller	=	Qnil;
	
	if ( ( rb_debug_verbosity_settings_controller = rb_iv_get(	rb_debug_settings_controller,
																															RPDB_RB_SETTINGS_VARIABLE_DEBUG_VERBOSITY_SETTINGS_CONTROLLER ) == Qnil ) )	{
	
		rb_debug_verbosity_settings_controller	=	rb_RPDB_DebugVerbositySettingsController_new(	1,
																																														& rb_debug_settings_controller,
																																														rb_RPDB_DebugVerbositySettingsController );
		rb_iv_set(	rb_debug_settings_controller,
								RPDB_RB_SETTINGS_VARIABLE_DEBUG_VERBOSITY_SETTINGS_CONTROLLER,
								rb_debug_verbosity_settings_controller );
	}
	
	return rb_debug_verbosity_settings_controller;
}
