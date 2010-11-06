/*
 *		RPDB::SettingsController::MutexSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MutexSettingsController.h" 
#include "rb_RPDB_SettingsController.h" 
#include "rb_RPDB.h" 

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MutexSettingsController.h> 
#include <rpdb/RPDB_SettingsController.h> 

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MutexSettingsController;

void Init_RPDB_MutexSettingsController()	{

	rb_RPDB_MutexSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"Mutex",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MutexSettingsController, 	"new",																rb_RPDB_MutexSettingsController_new,														-1 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"initialize",													rb_RPDB_MutexSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPDB_MutexSettingsController, 				"parent_environment",									rb_RPDB_MutexSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MutexSettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_MutexSettingsController, 				"spin_time_before_blocking_for_test_and_spin_mutexes",														rb_RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"set_spin_time_before_blocking_for_test_and_spin_mutexes",														rb_RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"max_allowable_mutexes",														rb_RPDB_MutexSettingsController_maxAllowableMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"set_max_allowable_mutexes",														rb_RPDB_MutexSettingsController_setMaxAllowableMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"increment_for_adding_mutexes",														rb_RPDB_MutexSettingsController_incrementForAddingMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"set_increment_for_adding_mutexes",														rb_RPDB_MutexSettingsController_setIncrementForAddingMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"mutex_alignment",														rb_RPDB_MutexSettingsController_mutexAlignment,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"set_mutex_alignment",														rb_RPDB_MutexSettingsController_setMutexAlignment,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"associate_with_single_process?",														rb_RPDB_MutexSettingsController_associatedWithSingleProcess,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"turn_associate_with_single_process_on",														rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"turn_associate_with_single_process_off",														rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"self_blocking?",														rb_RPDB_MutexSettingsController_selfBlocking,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"turn_self_blocking_on",														rb_RPDB_MutexSettingsController_turnSelfBlockingOn,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"turn_self_blocking_off",														rb_RPDB_MutexSettingsController_turnSelfBlockingOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPDB_MutexSettingsController_new(	int			argc,
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

	VALUE	rb_mutex_settings_controller	= RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( RPDB_MutexSettingsController_new( c_parent_settings_controller ) );	

	rb_iv_set(	rb_mutex_settings_controller,
							RPDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_mutex_settings_controller,
										 1, 
										 argv );
	
	return rb_mutex_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPDB_MutexSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{
	
	return rb_self;
}


/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_MutexSettingsController_parentEnvironment(	VALUE	rb_mutex_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPDB_MutexSettingsController_parentSettingsController( rb_mutex_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPDB_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPDB_MutexSettingsController_parentSettingsController(	VALUE	rb_mutex_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_mutex_settings_controller,
																										RPDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/*********************************************************
*  spin_times_before_blocking_for_test_and_spin_mutexes  *
*********************************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_tas_spins.html
VALUE rb_RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( c_mutex_settings_controller ) );
}

	/*************************************************************
	*  set_spin_times_before_blocking_for_test_and_spin_mutexes  *
	*************************************************************/

	VALUE rb_RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	VALUE	rb_mutex_settings_controller, 
																							VALUE	rb_spin_times_before_blocking_for_test_and_spin_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	c_mutex_settings_controller,
																						FIX2INT( rb_spin_times_before_blocking_for_test_and_spin_mutexes ) );

		return rb_mutex_settings_controller;
	}

/**************************
*  max_allowable_mutexes  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_maxAllowableMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_maxAllowableMutexes( c_mutex_settings_controller ) );
}

	/******************************
	*  set_max_allowable_mutexes  *
	******************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPDB_MutexSettingsController_setMaxAllowableMutexes(	VALUE	rb_mutex_settings_controller, 
																	VALUE	rb_max_allowable_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setMaxAllowableMutexes(	c_mutex_settings_controller,
																FIX2INT( rb_max_allowable_mutexes ) );

		return rb_mutex_settings_controller;
	}

/*********************************
*  increment_for_adding_mutexes  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_incrementForAddingMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_incrementForAddingMutexes( c_mutex_settings_controller ) );
}

	/*************************************
	*  set_increment_for_adding_mutexes  *
	*************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPDB_MutexSettingsController_setIncrementForAddingMutexes(	VALUE	rb_mutex_settings_controller, 
																			VALUE	rb_increment_for_adding_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setIncrementForAddingMutexes(	c_mutex_settings_controller,
																	FIX2INT( rb_increment_for_adding_mutexes ) );
	
		return rb_mutex_settings_controller;
	}

/********************
*  mutex_alignment  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_mutexAlignment( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_mutexAlignment( c_mutex_settings_controller ) );
}

	/************************
	*  set_mutex_alignment  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPDB_MutexSettingsController_setMutexAlignment(	VALUE	rb_mutex_settings_controller, 
																VALUE	rb_increment_for_adding_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setMutexAlignment(	c_mutex_settings_controller,
															FIX2INT( rb_increment_for_adding_mutexes ) );
	
		return rb_mutex_settings_controller;
	}

/************************************
*  associated_with_single_process?  *
************************************/

VALUE rb_RPDB_MutexSettingsController_associatedWithSingleProcess( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPDB_MutexSettingsController_associatedWithSingleProcess( c_mutex_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/*******************************************
	*  turn_associated_with_single_process_on  *
	*******************************************/

	VALUE rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/********************************************
	*  turn_associated_with_single_process_off  *
	********************************************/

	VALUE rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

/******************
*  self_blocking  *
******************/

VALUE rb_RPDB_MutexSettingsController_selfBlocking( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPDB_MutexSettingsController_selfBlocking( c_mutex_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/**************************
	*  turn_self_blocking_on  *
	**************************/

	VALUE rb_RPDB_MutexSettingsController_turnSelfBlockingOn( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnSelfBlockingOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/***************************
	*  turn_self_blocking_off  *
	***************************/

	VALUE rb_RPDB_MutexSettingsController_turnSelfBlockingOff( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnSelfBlockingOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}
