/*
 *		RPbdb::MutexController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "MutexController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/MutexController.h>
#include <rpbdb/Mutex.h>

#include <rpbdb/MutexSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPbdb_Environment;
VALUE	extern	rb_RPbdb_MutexController;
VALUE	extern	rb_RPbdb_MutexSettingsController;
VALUE	extern	rb_RPbdb_Mutex;

void Init_rb_RPbdb_MutexController()	{

	rb_RPbdb_MutexController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																										"MutexController",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_MutexController, 	"new",																													rb_RPbdb_MutexController_new,																							-1 	);
	rb_define_method(						rb_RPbdb_MutexController, 	"initialize",																										rb_RPbdb_MutexController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_MutexController, 	"settings_controller",																					rb_RPbdb_MutexController_settingsController,															0 	);
	rb_define_alias(						rb_RPbdb_MutexController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MutexController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MutexController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_MutexController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_MutexController, 	"parent_environment",																						rb_RPbdb_MutexController_parentEnvironment,																0 	);
	rb_define_alias(						rb_RPbdb_MutexController, 	"environment",																									"parent_environment"	);

//	rb_define_method(						rb_RPbdb_MutexController, 	"mutex",																						rb_RPbdb_MutexController_mutex,																				0 	);
	rb_define_method(						rb_RPbdb_MutexController, 	"close_all",																										rb_RPbdb_MutexController_closeAllMutexes,																				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE	rb_RPbdb_MutexController_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment									=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);

	RPbdb_Environment*	c_parent_environment;
	C_RPBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_mutex_controller	=	RUBY_RPBDB_MUTEX_CONTROLLER( RPbdb_MutexController_new( c_parent_environment ) );

	//	store reference to parent
	rb_iv_set(	rb_mutex_controller,
							RPBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
							rb_parent_environment );

	VALUE	argv[]	=	{ rb_parent_environment };
	rb_obj_call_init(	rb_mutex_controller,
										 1, 
										 argv );
	
	return rb_mutex_controller;	
}

/*************
*  self.new  *
*************/

VALUE	rb_RPbdb_MutexController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE	rb_RPbdb_MutexController_settingsController(	VALUE	rb_mutex_controller )	{

	VALUE	rb_local_mutex_settings_controller	=	Qnil;
	
	if ( ( rb_local_mutex_settings_controller = rb_iv_get(	rb_mutex_controller,
																													RPBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_MutexController*		c_mutex_controller;
		C_RPBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );
	
		RPbdb_MutexSettingsController*	c_local_mutex_settings_controller	=	RPbdb_MutexController_settingsController( c_mutex_controller );

		rb_local_mutex_settings_controller	=	RUBY_RPBDB_MUTEX_SETTINGS_CONTROLLER( c_local_mutex_settings_controller );

		rb_iv_set(	rb_mutex_controller,
								RPBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER,
								rb_local_mutex_settings_controller );
	}

	return rb_local_mutex_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE	rb_RPbdb_MutexController_parentEnvironment(	VALUE	rb_mutex_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_mutex_controller,
																						RPBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/*************************
*  closeAllMutexes  *
*************************/

VALUE	rb_RPbdb_MutexController_closeAllMutexes( VALUE	rb_mutex_controller )	{

	RPbdb_MutexController*		c_mutex_controller;
	C_RPBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );

	RPbdb_MutexController_closeAllMutexes( c_mutex_controller );

	return rb_mutex_controller;
}
