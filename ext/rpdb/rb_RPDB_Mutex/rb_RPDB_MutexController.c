/*
 *		RPDB::MutexController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_MutexController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_MutexController.h>
#include <rpdb/RPDB_Mutex.h>

#include <rpdb/RPDB_MutexSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_MutexController;
VALUE	extern	rb_RPDB_MutexSettingsController;
VALUE	extern	rb_RPDB_Mutex;

void Init_RPDB_MutexController()	{

	rb_RPDB_MutexController	=	rb_define_class_under(	rb_RPDB_Environment, 
																										"MutexController",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_MutexController, 	"new",																													rb_RPDB_MutexController_new,																							-1 	);
	rb_define_method(						rb_RPDB_MutexController, 	"initialize",																										rb_RPDB_MutexController_init,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_MutexController, 	"settings_controller",																					rb_RPDB_MutexController_settingsController,															0 	);
	rb_define_alias(						rb_RPDB_MutexController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_MutexController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_MutexController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_MutexController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_MutexController, 	"parent_environment",																						rb_RPDB_MutexController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPDB_MutexController, 	"environment",																									"parent_environment"	);

//	rb_define_method(						rb_RPDB_MutexController, 	"mutex",																						rb_RPDB_MutexController_mutex,																				0 	);
	rb_define_method(						rb_RPDB_MutexController, 	"close_all",																										rb_RPDB_MutexController_closeAllMutexes,																				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

VALUE	rb_RPDB_MutexController_new(	VALUE	klass __attribute__ ((unused)),
																		VALUE	rb_parent_environment )	{
	
	RPDB_Environment*	c_parent_environment;
	C_RPDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_mutex_controller	=	RUBY_RPDB_MUTEX_CONTROLLER( RPDB_MutexController_new( c_parent_environment ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_environment;
	
	rb_obj_call_init(	rb_mutex_controller,
					 1, 
					 argv );
	
	return rb_mutex_controller;	
}

/*************
*  new  *
*************/

VALUE	rb_RPDB_MutexController_init(	VALUE	rb_mutex_controller,
																		VALUE	rb_parent_environment __attribute__ ((unused)) )	{
	
	return rb_mutex_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE	rb_RPDB_MutexController_settingsController(	VALUE	rb_mutex_controller )	{

	RPDB_MutexController*	c_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );

	return RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( RPDB_MutexController_settingsController( c_mutex_controller ) );
}

/***************************************
*  environment  *
***************************************/
VALUE	rb_RPDB_MutexController_parentEnvironment(	VALUE	rb_mutex_controller )	{

	RPDB_MutexController*		c_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_MutexController_parentEnvironment( c_mutex_controller ) );
}

/*************************
*  closeAllMutexes  *
*************************/

VALUE	rb_RPDB_MutexController_closeAllMutexes( VALUE	rb_mutex_controller )	{

	RPDB_MutexController*		c_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );

	RPDB_MutexController_closeAllMutexes( c_mutex_controller );

	return rb_mutex_controller;
}
