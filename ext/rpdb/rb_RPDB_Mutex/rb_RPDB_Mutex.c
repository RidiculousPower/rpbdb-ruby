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

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Mutex.h>

#include <rpdb/RPDB_MutexSettingsController.h>

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
VALUE rb_RPDB_Mutex_new(	VALUE	klass __attribute__ ((unused)),
													VALUE	rb_parent_mutex_controller )	{
	
	RPDB_MutexController*		c_parent_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_parent_mutex_controller, c_parent_mutex_controller );
	
	VALUE	rb_mutex	=	RUBY_RPDB_MUTEX( RPDB_Mutex_new( c_parent_mutex_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_mutex_controller;
	
	rb_obj_call_init(	rb_mutex,
					 1, 
					 argv );
	
	return rb_mutex;	
}


/*************
*  new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/mutex_alloc.html
VALUE rb_RPDB_Mutex_init(	VALUE	rb_mutex __attribute__ ((unused)),
													VALUE	rb_parent_mutex_controller )	{

	RPDB_MutexController*		c_parent_mutex_controller;
	C_RPDB_MUTEX_CONTROLLER( rb_parent_mutex_controller, c_parent_mutex_controller );

	return RUBY_RPDB_MUTEX( RPDB_Mutex_new( c_parent_mutex_controller ) );
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_Mutex_settingsController(	VALUE	rb_mutex )	{

	RPDB_Mutex*	c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	return RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( RPDB_Mutex_settingsController( c_mutex ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_Mutex_parentEnvironment(	VALUE	rb_mutex )	{

	RPDB_Mutex*		c_mutex;
	C_RPDB_MUTEX( rb_mutex, c_mutex );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Mutex_parentEnvironment( c_mutex ) );

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
