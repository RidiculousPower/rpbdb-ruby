/*
 *		Rbdb::MutexController
 *
 *	
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_MutexController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_MutexController.h>
#include <rbdb/Rbdb_Mutex.h>

#include <rbdb/Rbdb_MutexSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_Rbdb_Environment;
VALUE	extern	rb_Rbdb_MutexController;
VALUE	extern	rb_Rbdb_MutexSettingsController;
VALUE	extern	rb_Rbdb_Mutex;

void Init_rb_Rbdb_MutexController()	{

	rb_Rbdb_MutexController	=	rb_define_class_under(	rb_Rbdb_Environment, 
																										"MutexController",			
																										rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_MutexController, 	"new",																													rb_Rbdb_MutexController_new,																							-1 	);
	rb_define_method(						rb_Rbdb_MutexController, 	"initialize",																										rb_Rbdb_MutexController_initialize,																						-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_MutexController, 	"settings_controller",																					rb_Rbdb_MutexController_settingsController,															0 	);
	rb_define_alias(						rb_Rbdb_MutexController, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_MutexController, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_MutexController, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_MutexController, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_Rbdb_MutexController, 	"parent_environment",																						rb_Rbdb_MutexController_parentEnvironment,																0 	);
	rb_define_alias(						rb_Rbdb_MutexController, 	"environment",																									"parent_environment"	);

//	rb_define_method(						rb_Rbdb_MutexController, 	"mutex",																						rb_Rbdb_MutexController_mutex,																				0 	);
	rb_define_method(						rb_Rbdb_MutexController, 	"close_all",																										rb_Rbdb_MutexController_closeAllMutexes,																				0 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE	rb_Rbdb_MutexController_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment									=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]"
		)
	);

	Rbdb_Environment*	c_parent_environment;
	C_RBDB_ENVIRONMENT( rb_parent_environment, c_parent_environment );
	
	VALUE	rb_mutex_controller	=	RUBY_RBDB_MUTEX_CONTROLLER( Rbdb_MutexController_new( c_parent_environment ) );

	//	store reference to parent
	rb_iv_set(	rb_mutex_controller,
							RBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT,
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

VALUE	rb_Rbdb_MutexController_initialize(	int				argc __attribute__ ((unused)),
																		VALUE*		args __attribute__ ((unused)),
																		VALUE			rb_self )	{
	
	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE	rb_Rbdb_MutexController_settingsController(	VALUE	rb_mutex_controller )	{

	VALUE	rb_local_mutex_settings_controller	=	Qnil;
	
	if ( ( rb_local_mutex_settings_controller = rb_iv_get(	rb_mutex_controller,
																													RBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_MutexController*		c_mutex_controller;
		C_RBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );
	
		Rbdb_MutexSettingsController*	c_local_mutex_settings_controller	=	Rbdb_MutexController_settingsController( c_mutex_controller );

		rb_local_mutex_settings_controller	=	RUBY_RBDB_MUTEX_SETTINGS_CONTROLLER( c_local_mutex_settings_controller );

		rb_iv_set(	rb_mutex_controller,
								RBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER,
								rb_local_mutex_settings_controller );
	}

	return rb_local_mutex_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE	rb_Rbdb_MutexController_parentEnvironment(	VALUE	rb_mutex_controller )	{

	VALUE	rb_parent_environment	=	rb_iv_get(	rb_mutex_controller,
																						RBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT );
	return rb_parent_environment;
}

/*************************
*  closeAllMutexes  *
*************************/

VALUE	rb_Rbdb_MutexController_closeAllMutexes( VALUE	rb_mutex_controller )	{

	Rbdb_MutexController*		c_mutex_controller;
	C_RBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller );

	Rbdb_MutexController_closeAllMutexes( c_mutex_controller );

	return rb_mutex_controller;
}
