/*
 *		RPbdb::MutexController::Mutex
 *
 *	
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "Mutex.h"
#include "MutexController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Mutex.h>

#include <rpbdb/MutexSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Mutex;
extern	VALUE	rb_RPbdb_MutexController;
extern	VALUE	rb_RPbdb_MutexSettingsController;
	
void Init_rb_RPbdb_Mutex()	{

	rb_RPbdb_Mutex	=	rb_define_class_under(	rb_RPbdb_MutexController, 
																					"Mutex",			
																					rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_Mutex, 	"new",																													rb_RPbdb_Mutex_new,													-1 	);
	rb_define_method(						rb_RPbdb_Mutex, 	"initialize",																										rb_RPbdb_Mutex_initialize,												-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_Mutex, 	"settings_controller",																					rb_RPbdb_Mutex_settingsController,					0 	);
	rb_define_alias(						rb_RPbdb_Mutex, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Mutex, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Mutex, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Mutex, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_Mutex, 	"parent_environment",																						rb_RPbdb_Mutex_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPbdb_Mutex, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_Mutex, 	"open",																													rb_RPbdb_Mutex_open,												0 	);
	rb_define_method(						rb_RPbdb_Mutex, 	"close",																												rb_RPbdb_Mutex_close,											0 	);
	rb_define_method(						rb_RPbdb_Mutex, 	"lock",																													rb_RPbdb_Mutex_lock,												0 	);
	rb_define_method(						rb_RPbdb_Mutex, 	"unlock",																												rb_RPbdb_Mutex_unlock,											0 	);

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_alloc.html
VALUE rb_RPbdb_Mutex_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment									=	Qnil;
	VALUE	rb_parent_mutex_controller						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_mutex_controller, rb_RPbdb_MutexController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent mutex controller> ]"
		)
	);

	RPbdb_MutexController*		c_parent_mutex_controller;
	C_RPBDB_MUTEX_CONTROLLER( rb_parent_mutex_controller, c_parent_mutex_controller );
	
	VALUE	rb_mutex	=	RUBY_RPBDB_MUTEX( RPbdb_Mutex_new( c_parent_mutex_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_mutex,
							RPBDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER,
							rb_parent_mutex_controller );

	VALUE	argv[]	=	{ rb_parent_mutex_controller };
	rb_obj_call_init(	rb_mutex,
										 1, 
										 argv );
	
	return rb_mutex;	
}


/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_alloc.html
VALUE rb_RPbdb_Mutex_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPbdb_Mutex_settingsController(	VALUE	rb_mutex )	{

	VALUE	rb_local_mutex_settings_controller	=	Qnil;
	
	if ( ( rb_local_mutex_settings_controller = rb_iv_get(	rb_mutex,
																													RPBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Mutex*		c_mutex;
		C_RPBDB_MUTEX( rb_mutex, c_mutex );
	
		RPbdb_MutexSettingsController*	c_local_mutex_settings_controller	=	RPbdb_Mutex_settingsController( c_mutex );

		rb_local_mutex_settings_controller	=	RUBY_RPBDB_MUTEX_SETTINGS_CONTROLLER( c_local_mutex_settings_controller );

		rb_iv_set(	rb_mutex,
								RPBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER,
								rb_local_mutex_settings_controller );
	}

	return rb_local_mutex_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPbdb_Mutex_parentEnvironment(	VALUE	rb_mutex )	{

	VALUE	rb_parent_mutex_controller	=	rb_RPbdb_Mutex_parentMutexController( rb_mutex );
	VALUE	rb_parent_environment				=	rb_RPbdb_MutexController_parentEnvironment( rb_parent_mutex_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_mutex_controller  *
***************************************/
VALUE rb_RPbdb_Mutex_parentMutexController(	VALUE	rb_mutex )	{

	VALUE	rb_mutex_controller	=	rb_iv_get(	rb_mutex,
																					RPBDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER );
	return rb_mutex_controller;
}

/*************
*  open  *
*************/

VALUE rb_RPbdb_Mutex_open( VALUE	rb_mutex )	{

	RPbdb_Mutex*		c_mutex;
	C_RPBDB_MUTEX( rb_mutex, c_mutex );

	RPbdb_Mutex_open( c_mutex );

	return rb_mutex;
}

/*************
*  close  *
*************/

VALUE rb_RPbdb_Mutex_close( VALUE	rb_mutex )	{

	RPbdb_Mutex*		c_mutex;
	C_RPBDB_MUTEX( rb_mutex, c_mutex );

	RPbdb_Mutex_close( c_mutex );

	return rb_mutex;
}

/*************
*  lock  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_lock.html
VALUE rb_RPbdb_Mutex_lock( VALUE	rb_mutex )	{

	RPbdb_Mutex*		c_mutex;
	C_RPBDB_MUTEX( rb_mutex, c_mutex );

	RPbdb_Mutex_lock( c_mutex );

	return rb_mutex;
}

/*************
*  unlock  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_unlock.html
VALUE rb_RPbdb_Mutex_unlock( VALUE	rb_mutex )	{

	RPbdb_Mutex*		c_mutex;
	C_RPBDB_MUTEX( rb_mutex, c_mutex );

	RPbdb_Mutex_unlock( c_mutex );

	return rb_mutex;
}
