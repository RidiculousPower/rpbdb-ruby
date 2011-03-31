/*
 *		RPbdb::SettingsController::MutexSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MutexSettingsController.h" 
#include "SettingsController.h" 
#include "RPbdb.h" 

#include "Environment.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MutexSettingsController.h> 
#include <rpbdb/SettingsController.h> 

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_SettingsController;
extern	VALUE	rb_RPbdb_MutexSettingsController;

void Init_rb_RPbdb_MutexSettingsController()	{

	rb_RPbdb_MutexSettingsController		=	rb_define_class_under(	rb_RPbdb_SettingsController, 
																																		"Mutex",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MutexSettingsController, 	"new",																rb_RPbdb_MutexSettingsController_new,														-1 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"initialize",													rb_RPbdb_MutexSettingsController_initialize,														-1 	);

	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"parent_environment",									rb_RPbdb_MutexSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPbdb_MutexSettingsController, 				"environment",												"parent_environment"	);
	rb_define_method(			rb_RPbdb_MutexSettingsController,				"parent_settings_controller",					rb_RPbdb_MutexSettingsController_parentSettingsController,								0 	);

	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"spin_time_before_blocking_for_test_and_spin_mutexes",														rb_RPbdb_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"set_spin_time_before_blocking_for_test_and_spin_mutexes",														rb_RPbdb_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes,													1 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"max_allowable_mutexes",														rb_RPbdb_MutexSettingsController_maxAllowableMutexes,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"set_max_allowable_mutexes",														rb_RPbdb_MutexSettingsController_setMaxAllowableMutexes,													1 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"increment_for_adding_mutexes",														rb_RPbdb_MutexSettingsController_incrementForAddingMutexes,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"set_increment_for_adding_mutexes",														rb_RPbdb_MutexSettingsController_setIncrementForAddingMutexes,													1 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"mutex_alignment",														rb_RPbdb_MutexSettingsController_mutexAlignment,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"set_mutex_alignment",														rb_RPbdb_MutexSettingsController_setMutexAlignment,													1 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"associated_with_single_process?",														rb_RPbdb_MutexSettingsController_associatedWithSingleProcess,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"turn_associated_with_single_process_on",														rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOn,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"turn_associated_with_single_process_off",														rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOff,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"self_blocking?",														rb_RPbdb_MutexSettingsController_selfBlocking,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"turn_self_blocking_on",														rb_RPbdb_MutexSettingsController_turnSelfBlockingOn,													0 	);
	rb_define_method(			rb_RPbdb_MutexSettingsController, 				"turn_self_blocking_off",														rb_RPbdb_MutexSettingsController_turnSelfBlockingOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_MutexSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment					=	Qnil;
	VALUE	rb_parent_settings_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_settings_controller, rb_RPbdb_SettingsController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent settings controller> ]"
		)
	);
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_settings_controller == Qnil )	{			

		rb_parent_environment = rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	if ( rb_parent_environment != Qnil )	{
		rb_parent_settings_controller = rb_RPbdb_Environment_settingsController( rb_parent_environment );	
	}

	RPbdb_SettingsController*	c_parent_settings_controller;
	C_RPBDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_mutex_settings_controller	= RUBY_RPBDB_MUTEX_SETTINGS_CONTROLLER( RPbdb_MutexSettingsController_new( c_parent_settings_controller ) );	

	rb_iv_set(	rb_mutex_settings_controller,
							RPBDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER,
							rb_parent_settings_controller );

	VALUE	argv[]	=	{ rb_parent_settings_controller };
	rb_obj_call_init(	rb_mutex_settings_controller,
										 1, 
										 argv );
	
	return rb_mutex_settings_controller;		
}

/***************
*  initialize  *
***************/

VALUE rb_RPbdb_MutexSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{
	
	return rb_self;
}


/***********************
*  parent_environment  *
***********************/

VALUE rb_RPbdb_MutexSettingsController_parentEnvironment(	VALUE	rb_mutex_settings_controller )	{

	VALUE	rb_parent_settings_controller							=	rb_RPbdb_MutexSettingsController_parentSettingsController( rb_mutex_settings_controller );
	VALUE	rb_parent_environment											=	rb_RPbdb_SettingsController_parentEnvironment( rb_parent_settings_controller );
	
	return rb_parent_environment;
}

/*******************************
*  parent_settings_controller  *
*******************************/

VALUE rb_RPbdb_MutexSettingsController_parentSettingsController(	VALUE	rb_mutex_settings_controller )	{

	VALUE	rb_parent_settings_controller	=	rb_iv_get(	rb_mutex_settings_controller,
																										RPBDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER );

	return rb_parent_settings_controller;
}

/********************************************************
*  spin_time_before_blocking_for_test_and_spin_mutexes  *
********************************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_tas_spins.html
VALUE rb_RPbdb_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPbdb_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( c_mutex_settings_controller ) );
}

	/************************************************************
	*  set_spin_time_before_blocking_for_test_and_spin_mutexes  *
	************************************************************/

	VALUE rb_RPbdb_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	VALUE	rb_mutex_settings_controller, 
																							VALUE	rb_spin_times_before_blocking_for_test_and_spin_mutexes )	{

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	c_mutex_settings_controller,
																						FIX2INT( rb_spin_times_before_blocking_for_test_and_spin_mutexes ) );

		return rb_mutex_settings_controller;
	}

/**************************
*  max_allowable_mutexes  *
**************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPbdb_MutexSettingsController_maxAllowableMutexes( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPbdb_MutexSettingsController_maxAllowableMutexes( c_mutex_settings_controller ) );
}

	/******************************
	*  set_max_allowable_mutexes  *
	******************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPbdb_MutexSettingsController_setMaxAllowableMutexes(	VALUE	rb_mutex_settings_controller, 
																																VALUE	rb_max_allowable_mutexes )	{

		VALUE	rb_parent_environment	=	rb_RPbdb_MutexSettingsController_parentEnvironment( rb_mutex_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Maximum allowable mutexes can only be set before environment is opened." );	
		}

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_setMaxAllowableMutexes(	c_mutex_settings_controller,
																FIX2INT( rb_max_allowable_mutexes ) );

		return rb_mutex_settings_controller;
	}

/*********************************
*  increment_for_adding_mutexes  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPbdb_MutexSettingsController_incrementForAddingMutexes( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPbdb_MutexSettingsController_incrementForAddingMutexes( c_mutex_settings_controller ) );
}

	/*************************************
	*  set_increment_for_adding_mutexes  *
	*************************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPbdb_MutexSettingsController_setIncrementForAddingMutexes(	VALUE	rb_mutex_settings_controller, 
																			VALUE	rb_increment_for_adding_mutexes )	{

		VALUE	rb_parent_environment	=	rb_RPbdb_MutexSettingsController_parentEnvironment( rb_mutex_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Increment for adding mutexes can only be set before environment is opened." );	
		}

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_setIncrementForAddingMutexes(	c_mutex_settings_controller,
																	FIX2INT( rb_increment_for_adding_mutexes ) );
	
		return rb_mutex_settings_controller;
	}

/********************
*  mutex_alignment  *
********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPbdb_MutexSettingsController_mutexAlignment( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	uint32_t	c_mutex_alignment		=	RPbdb_MutexSettingsController_mutexAlignment( c_mutex_settings_controller );
	VALUE			rb_mutex_alignment	=	LONG2NUM( c_mutex_alignment );

	return rb_mutex_alignment;
}

	/************************
	*  set_mutex_alignment  *
	************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPbdb_MutexSettingsController_setMutexAlignment(	VALUE	rb_mutex_settings_controller, 
																VALUE	rb_increment_for_adding_mutexes )	{

		VALUE	rb_parent_environment	=	rb_RPbdb_MutexSettingsController_parentEnvironment( rb_mutex_settings_controller );
		if (		rb_parent_environment != Qnil
				&&	rb_RPbdb_Environment_isOpen( rb_parent_environment ) == Qtrue )	{
			rb_raise( rb_eRuntimeError, "Mutex alignment can only be set before environment is opened." );	
		}

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		uint32_t		c_mutex_alignment	=	NUM2LONG( rb_increment_for_adding_mutexes );

		RPbdb_MutexSettingsController_setMutexAlignment(	c_mutex_settings_controller,
																										c_mutex_alignment );
	
		return rb_mutex_settings_controller;
	}

/************************************
*  associated_with_single_process?  *
************************************/

VALUE rb_RPbdb_MutexSettingsController_associatedWithSingleProcess( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPbdb_MutexSettingsController_associatedWithSingleProcess( c_mutex_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/*******************************************
	*  turn_associated_with_single_process_on  *
	*******************************************/

	VALUE rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOn( VALUE	rb_mutex_settings_controller )	{

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/********************************************
	*  turn_associated_with_single_process_off  *
	********************************************/

	VALUE rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOff( VALUE	rb_mutex_settings_controller )	{

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

/******************
*  self_blocking  *
******************/

VALUE rb_RPbdb_MutexSettingsController_selfBlocking( VALUE	rb_mutex_settings_controller )	{

	RPbdb_MutexSettingsController*	c_mutex_settings_controller;
	C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPbdb_MutexSettingsController_selfBlocking( c_mutex_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/**************************
	*  turn_self_blocking_on  *
	**************************/

	VALUE rb_RPbdb_MutexSettingsController_turnSelfBlockingOn( VALUE	rb_mutex_settings_controller )	{

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_turnSelfBlockingOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/***************************
	*  turn_self_blocking_off  *
	***************************/

	VALUE rb_RPbdb_MutexSettingsController_turnSelfBlockingOff( VALUE	rb_mutex_settings_controller )	{

		RPbdb_MutexSettingsController*	c_mutex_settings_controller;
		C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPbdb_MutexSettingsController_turnSelfBlockingOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}
