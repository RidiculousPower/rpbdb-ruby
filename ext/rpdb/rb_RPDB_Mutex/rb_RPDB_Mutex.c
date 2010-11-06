/*
 *		RPDB::MutexController::Mutex
 *
 *	
 */
 
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Mutex.h"
#include "rb_RPDB_MutexController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Mutex.h>

#include <rpdb/RPDB_MutexSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Mutex;
extern	VALUE	rb_RPDB_MutexController;
extern	VALUE	rb_RPDB_MutexSettingsController;
	
void Init_RPDB_Mutex()	{

	rb_RPDB_Mutex	=	rb_define_class_under(	rb_RPDB_MutexController, 
																					"Mutex",			
																					rb_cObject );

	rb_define_singleton_method(	rb_RPDB_Mutex, 	"new",																													rb_RPDB_Mutex_new,													-1 	);
	rb_define_method(						rb_RPDB_Mutex, 	"initialize",																										rb_RPDB_Mutex_init,												-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_Mutex, 	"settings_controller",																					rb_RPDB_Mutex_settingsController,					0 	);
	rb_define_alias(						rb_RPDB_Mutex, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_Mutex, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_Mutex, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_Mutex, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_Mutex, 	"parent_environment",																						rb_RPDB_Mutex_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPDB_Mutex, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPDB_Mutex, 	"open",																													rb_RPDB_Mutex_open,												0 	);
	rb_define_method(						rb_RPDB_Mutex, 	"close",																												rb_RPDB_Mutex_close,											0 	);
	rb_define_method(						rb_RPDB_Mutex, 	"lock",																													rb_RPDB_Mutex_lock,												0 	);
	rb_define_method(						rb_RPDB_Mutex, 	"unlock",																												rb_RPDB_Mutex_unlock,											0 	);

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_alloc.html
VALUE rb_RPDB_Mutex_new(	int			argc,
													VALUE*	args,
													VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_environment									=	Qnil;
	VALUE	rb_parent_mutex_controller						=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_mutex_controller, rb_RPDB_MutexController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent mutex controller> ]"
		)
	);

	RPDB_MutexController*		c_parent_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_parent_mutex_controller, c_parent_mutex_controller );
	
	VALUE	rb_mutex	=	RUBY_RPDB_MUTEX( RPDB_Mutex_new( c_parent_mutex_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_mutex,
							RPDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER,
							rb_parent_mutex_controller );

	VALUE	argv[]	=	{ rb_parent_mutex_controller };
	rb_obj_call_initialize(	rb_mutex,
										 1, 
										 argv );
	
	return rb_mutex;	
}


/*************
*  new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_alloc.html
VALUE rb_RPDB_Mutex_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Mutex_settingsController(	VALUE	rb_mutex )	{

	VALUE	rb_local_mutex_settings_controller	=	Qnil;
	
	if ( ( rb_local_mutex_settings_controller = rb_iv_get(	rb_mutex,
																													RPDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Mutex*		c_mutex;
		C_RPDB_MUTEX( rb_mutex, c_mutex );
	
		RPDB_MutexSettingsController*	c_local_mutex_settings_controller	=	RPDB_Mutex_settingsController( c_mutex );

		rb_local_mutex_settings_controller	=	RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( c_local_mutex_settings_controller );

		rb_iv_set(	rb_mutex,
								RPDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER,
								rb_local_mutex_settings_controller );
	}

	return rb_local_mutex_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_Mutex_parentEnvironment(	VALUE	rb_mutex )	{

	VALUE	rb_parent_mutex_controller	=	rb_RPDB_Mutex_parentMutexController( rb_mutex );
	VALUE	rb_parent_environment				=	rb_RPDB_MutexController_parentEnvironment( rb_parent_mutex_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_mutex_controller  *
***************************************/
VALUE rb_RPDB_Mutex_parentMutexController(	VALUE	rb_mutex )	{

	VALUE	rb_mutex_controller	=	rb_iv_get(	rb_mutex,
																					RPDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER );
	return rb_mutex_controller;
}

/*************
*  open  *
*************/

VALUE rb_RPDB_Mutex_open( VALUE	rb_mutex )	{

	RPDB_Mutex*		c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	RPDB_Mutex_open( c_mutex );

	return rb_mutex;
}

/*************
*  close  *
*************/

VALUE rb_RPDB_Mutex_close( VALUE	rb_mutex )	{

	RPDB_Mutex*		c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	RPDB_Mutex_close( c_mutex );

	return rb_mutex;
}

/*************
*  lock  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_lock.html
VALUE rb_RPDB_Mutex_lock( VALUE	rb_mutex )	{

	RPDB_Mutex*		c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	RPDB_Mutex_lock( c_mutex );

	return rb_mutex;
}

/*************
*  unlock  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_unlock.html
VALUE rb_RPDB_Mutex_unlock( VALUE	rb_mutex )	{

	RPDB_Mutex*		c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	RPDB_Mutex_unlock( c_mutex );

	return rb_mutex;
}
