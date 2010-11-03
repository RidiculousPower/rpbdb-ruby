/*
 *		RPDB::LockController::Lock
 *
 *		Reference - http://www.oracle.com/technology/documentation/berkeley-db/db/ref/lock/am_conv.html
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_Lock.h"
#include "rb_RPDB_LockController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Lock.h>

#include <rpdb/RPDB_LockSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_Lock;
extern	VALUE	rb_RPDB_LockController;
extern	VALUE	rb_RPDB_LockSettingsController;

void Init_RPDB_Lock()	{

	rb_RPDB_LockController	=	rb_define_class_under(	rb_RPDB_Environment, 
																										"Lock",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPDB_Lock, 	"new",																													rb_RPDB_Lock_new,																	-1 	);
	rb_define_method(						rb_RPDB_Lock, 	"initialize",																										rb_RPDB_Lock_init,																-1 	);
                                                                                          		
	rb_define_method(						rb_RPDB_Lock, 	"settings_controller",																					rb_RPDB_Lock_settingsController,									0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPDB_Lock, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPDB_Lock, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPDB_Lock, 	"parent_environment",																						rb_RPDB_Lock_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPDB_Lock, 	"lock",																													rb_RPDB_Lock_lock,																0 	);
	rb_define_method(						rb_RPDB_Lock, 	"unlock",																												rb_RPDB_Lock_unlock,															0 	);
	rb_define_method(						rb_RPDB_Lock, 	"is_read_lock?",																								rb_RPDB_Lock_isReadLock,													0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"read_lock?",																										"is_read_lock?"	);
	rb_define_method(						rb_RPDB_Lock, 	"is_write_lock?",																								rb_RPDB_Lock_isWriteLock,													0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"write_lock?",																									"is_write_lock?"	);
	rb_define_method(						rb_RPDB_Lock, 	"set_to_write_lock",																						rb_RPDB_Lock_setToWriteLock,											0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_to_write",																									"set_to_write_lock"	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_write",																										"set_to_write_lock"	);
	rb_define_method(						rb_RPDB_Lock, 	"is_intent_to_write_lock?",																			rb_RPDB_Lock_isIntentToWriteLock,									0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"intent_to_write_lock?",																				"is_intent_to_write_lock?"	);
	rb_define_method(						rb_RPDB_Lock, 	"set_to_intent_to_write_lock",																	rb_RPDB_Lock_setToIntentToWriteLock,							0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_intent_to_write",																					"set_to_intent_to_write_lock"	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_intent",																										"set_to_intent_to_write_lock"	);
	rb_define_method(						rb_RPDB_Lock, 	"is_intent_to_read_lock?",																			rb_RPDB_Lock_isIntentToReadLock,									0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"intent_to_read_lock?",																					"is_intent_to_read_lock?"	);
	rb_define_method(						rb_RPDB_Lock, 	"set_to_intent_to_read_lock",																		rb_RPDB_Lock_setToIntentToReadLock,								0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_intent_to_read",																						"set_to_intent_to_read_lock"	);
	rb_define_method(						rb_RPDB_Lock, 	"is_intent_to_read_and_write_lock?",														rb_RPDB_Lock_isIntentToReadAndWriteLock,					0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"intent_to_read_and_write_lock?",																"is_intent_to_read_and_write_lock?"	);
	rb_define_method(						rb_RPDB_Lock, 	"set_to_intent_to_read_and_write_lock",													rb_RPDB_Lock_setToIntentToReadAndWriteLock,				0 	);
	rb_define_alias(						rb_RPDB_Lock, 	"set_intent_to_read_and_write",																	"set_to_intent_to_read_and_write_lock"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/********
*  new  *
********/

VALUE rb_RPDB_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_lock_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_lock_controller, rb_RPDB_LockController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent lock controller> ]"
		)
	);
	
	
	RPDB_LockController*	c_parent_lock_controller;
	C_RPDB_LOCK_CONTROLLER( rb_parent_lock_controller, c_parent_lock_controller );
	
	VALUE	rb_lock		=	RUBY_RPDB_LOCK( RPDB_Lock_new( c_parent_lock_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_lock_controller;
	
	rb_obj_call_init(	rb_lock,
					 1, 
					 argv );
	
	return rb_lock;	
}

/*********
*  init  *
*********/

VALUE rb_RPDB_Lock_init(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self )	{


	return rb_self;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPDB_Lock_settingsController(	VALUE	rb_lock )	{

	RPDB_Lock*	c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return RUBY_RPDB_LOCK_SETTINGS_CONTROLLER( RPDB_Lock_settingsController( c_lock ) );
}

/****************
*  environment  *
****************/
VALUE rb_RPDB_Lock_parentEnvironment(	VALUE	rb_lock )	{

	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return RUBY_RPDB_ENVIRONMENT( RPDB_Lock_parentEnvironment( c_lock ) );

}

/*********
*  lock  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
VALUE rb_RPDB_Lock_lock(	VALUE	rb_lock, 
													VALUE	rb_record )	{

	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	RPDB_Record*		c_record;
	C_RPDB_RECORD( rb_record, c_record );

	RPDB_Lock_lock(	c_lock,
									c_record );
	
	return rb_lock;
}

/***********
*  unlock  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_put.html
VALUE rb_RPDB_Lock_unlock( VALUE	rb_lock )	{

	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	RPDB_Lock_unlock( c_lock );

	return rb_lock;
}

/*****************
*  is_read_lock  *
*****************/

VALUE rb_RPDB_Lock_isReadLock( VALUE	rb_lock )	{
	
	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return ( RPDB_Lock_isReadLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/*********************
	*  set_to_read_lock  *
	*********************/

	VALUE rb_RPDB_Lock_setToReadLock( VALUE	rb_lock )	{
	
		RPDB_Lock*			c_lock;
		C_RPDB_LOCK( rb_lock, c_lock );

		RPDB_Lock_setToReadLock( c_lock );

		return rb_lock;
	}

/******************
*  is_write_lock  *
******************/

VALUE rb_RPDB_Lock_isWriteLock( VALUE	rb_lock )	{
	
	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return ( RPDB_Lock_isWriteLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/**********************
	*  set_to_write_lock  *
	**********************/

	VALUE rb_RPDB_Lock_setToWriteLock( VALUE	rb_lock )	{
	
		RPDB_Lock*			c_lock;
		C_RPDB_LOCK( rb_lock, c_lock );
							
		RPDB_Lock_setToWriteLock( c_lock );

		return rb_lock;
	}

/****************************
*  is_intent_to_write_lock  *
****************************/

VALUE rb_RPDB_Lock_isIntentToWriteLock( VALUE	rb_lock )	{
	
	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return ( RPDB_Lock_isIntentToWriteLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/********************************
	*  set_to_intent_to_write_lock  *
	********************************/

	VALUE rb_RPDB_Lock_setToIntentToWriteLock( VALUE	rb_lock )	{
	
		RPDB_Lock*			c_lock;
		C_RPDB_LOCK( rb_lock, c_lock );
							
		RPDB_Lock_setToIntentToWriteLock( c_lock );

		return rb_lock;
	}

/***************************
*  is_intent_to_read_lock  *
***************************/

VALUE rb_RPDB_Lock_isIntentToReadLock( VALUE	rb_lock )	{
	
	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );
						
	return ( RPDB_Lock_isIntentToReadLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/*******************************
	*  set_to_intent_to_read_lock  *
	*******************************/

	VALUE rb_RPDB_Lock_setToIntentToReadLock( VALUE	rb_lock )	{
	
		RPDB_Lock*			c_lock;
		C_RPDB_LOCK( rb_lock, c_lock );
							
		RPDB_Lock_setToIntentToReadLock( c_lock );

		return rb_lock;
	}

/*************************************
*  is_intent_to_read_and_write_lock  *
*************************************/

VALUE rb_RPDB_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
	RPDB_Lock*			c_lock;
	C_RPDB_LOCK( rb_lock, c_lock );

	return ( RPDB_Lock_isIntentToReadAndWriteLock( c_lock )	?	Qtrue
																:	Qfalse );
}

	/*****************************************
	*  set_to_intent_to_read_and_write_lock  *
	*****************************************/

	VALUE rb_RPDB_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
		RPDB_Lock*			c_lock;
		C_RPDB_LOCK( rb_lock, c_lock );
							
		RPDB_Lock_setToIntentToReadAndWriteLock( c_lock );

		return rb_lock;
	}
