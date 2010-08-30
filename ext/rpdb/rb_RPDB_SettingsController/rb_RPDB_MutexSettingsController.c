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

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MutexSettingsController.h> 

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_MutexSettingsController;

void Init_RPDB_MutexSettingsController()	{

	rb_RPDB_MutexSettingsController		=	rb_define_class_under(	rb_RPDB_SettingsController, 
																																		"MemoryPool",	
																																		rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MutexSettingsController, 	"new",																rb_RPDB_MutexSettingsController_init,														1 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"initialize",													rb_RPDB_MutexSettingsController_init,														1 	);

	rb_define_method(			rb_RPDB_MutexSettingsController, 				"parent_environment",									rb_RPDB_MutexSettingsController_parentEnvironment,								0 	);
	rb_define_alias(			rb_RPDB_MutexSettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_maxAllowableMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_setMaxAllowableMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_incrementForAddingMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_setIncrementForAddingMutexes,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_mutexAlignment,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_setMutexAlignment,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_associatedWithSingleProcess,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_selfBlocking,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_turnSelfBlockingOn,													0 	);
	rb_define_method(			rb_RPDB_MutexSettingsController, 				"shm_key",														rb_RPDB_MutexSettingsController_turnSelfBlockingOff,													0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE rb_RPDB_MutexSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																						VALUE	rb_parent_settings_controller )	{

	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	VALUE	rb_mutex_settings_controller	= RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( RPDB_MutexSettingsController_new( c_parent_settings_controller ) );	

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_settings_controller;
	
	rb_obj_call_init(	rb_mutex_settings_controller,
					 1, 
					 argv );
	
	return rb_mutex_settings_controller;		
}

/*************
*  new  *
*************/

VALUE rb_RPDB_MutexSettingsController_init(	VALUE	rb_mutex_settings_controller,
																						VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{
	
	return rb_mutex_settings_controller;
}


/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_MutexSettingsController_parentEnvironment(	VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MutexSettingsController_parentEnvironment( c_mutex_settings_controller ) );
}

/*****************************************************
*  spinTimesBeforeBlockingForTestAndSpinMutexes  *
*****************************************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_tas_spins.html
VALUE rb_RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( c_mutex_settings_controller ) );
}

	/*********************************************************
	*  setSpinTimesBeforeBlockingForTestAndSpinMutexes  *
	*********************************************************/

	VALUE rb_RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	VALUE	rb_mutex_settings_controller, 
																							VALUE	rb_spin_times_before_blocking_for_test_and_spin_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	c_mutex_settings_controller,
																						FIX2INT( rb_spin_times_before_blocking_for_test_and_spin_mutexes ) );

		return rb_mutex_settings_controller;
	}

/*****************************
*  maxAllowableMutexes  *
*****************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_maxAllowableMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_maxAllowableMutexes( c_mutex_settings_controller ) );
}

	/*****************************
	*  setMaxAllowableMutexes  *
	*****************************/

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
*  incrementForAddingMutexes  *
*********************************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_incrementForAddingMutexes( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_incrementForAddingMutexes( c_mutex_settings_controller ) );
}

	/*************************************
	*  setIncrementForAddingMutexes  *
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

/*********************
*  mutexAlignment  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
VALUE rb_RPDB_MutexSettingsController_mutexAlignment( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return INT2FIX( RPDB_MutexSettingsController_mutexAlignment( c_mutex_settings_controller ) );
}

	/*************************
	*  setMutexAlignment  *
	*************************/

	//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_set_max.html
	VALUE rb_RPDB_MutexSettingsController_setMutexAlignment(	VALUE	rb_mutex_settings_controller, 
																VALUE	rb_increment_for_adding_mutexes )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_setMutexAlignment(	c_mutex_settings_controller,
															FIX2INT( rb_increment_for_adding_mutexes ) );
	
		return rb_mutex_settings_controller;
	}

/*************************
*  setMutexAlignment  *
*************************/

VALUE rb_RPDB_MutexSettingsController_associatedWithSingleProcess( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPDB_MutexSettingsController_associatedWithSingleProcess( c_mutex_settings_controller )	?	Qtrue
																										:	Qfalse );
}

	/*************************
	*  setMutexAlignment  *
	*************************/

	VALUE rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/*****************************************
	*  turnAssociatedWithSingleProcessOff  *
	*****************************************/

	VALUE rb_RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnAssociatedWithSingleProcessOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

/*********************
*  selfBlocking  *
*********************/

VALUE rb_RPDB_MutexSettingsController_selfBlocking( VALUE	rb_mutex_settings_controller )	{

	RPDB_MutexSettingsController*	c_mutex_settings_controller;
	C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

	return ( RPDB_MutexSettingsController_selfBlocking( c_mutex_settings_controller )	?	Qtrue
																						:	Qfalse );
}

	/*************************
	*  turnSelfBlockingOn  *
	*************************/

	VALUE rb_RPDB_MutexSettingsController_turnSelfBlockingOn( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnSelfBlockingOn( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}

	/*****************************
	*  turnSelfBlockingOff  *
	*****************************/

	VALUE rb_RPDB_MutexSettingsController_turnSelfBlockingOff( VALUE	rb_mutex_settings_controller )	{

		RPDB_MutexSettingsController*	c_mutex_settings_controller;
		C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller );

		RPDB_MutexSettingsController_turnSelfBlockingOff( c_mutex_settings_controller );

		return rb_mutex_settings_controller;
	}
