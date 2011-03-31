/*
 *		RPbdb::LockController::Lock
 *
 *		Reference - http://www.oracle.com/technology/documentation/berkeley-db/db/ref/lock/am_conv.html
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "Lock.h"
#include "LockController.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Lock.h>

#include <rpbdb/LockSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Lock;
extern	VALUE	rb_RPbdb_LockController;
extern	VALUE	rb_RPbdb_LockSettingsController;

void Init_rb_RPbdb_Lock()	{

	rb_RPbdb_LockController	=	rb_define_class_under(	rb_RPbdb_Environment, 
																										"Lock",			
																										rb_cObject );

	rb_define_singleton_method(	rb_RPbdb_Lock, 	"new",																													rb_RPbdb_Lock_new,																	-1 	);
	rb_define_method(						rb_RPbdb_Lock, 	"initialize",																										rb_RPbdb_Lock_initialize,																-1 	);
                                                                                          		
	rb_define_method(						rb_RPbdb_Lock, 	"settings_controller",																					rb_RPbdb_Lock_settingsController,									0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_RPbdb_Lock, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_RPbdb_Lock, 	"parent_environment",																						rb_RPbdb_Lock_parentEnvironment,										0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_RPbdb_Lock, 	"lock",																													rb_RPbdb_Lock_lock,																0 	);
	rb_define_method(						rb_RPbdb_Lock, 	"unlock",																												rb_RPbdb_Lock_unlock,															0 	);
	rb_define_method(						rb_RPbdb_Lock, 	"is_read_lock?",																								rb_RPbdb_Lock_isReadLock,													0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"read_lock?",																										"is_read_lock?"	);
	rb_define_method(						rb_RPbdb_Lock, 	"is_write_lock?",																								rb_RPbdb_Lock_isWriteLock,													0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"write_lock?",																									"is_write_lock?"	);
	rb_define_method(						rb_RPbdb_Lock, 	"set_to_write_lock",																						rb_RPbdb_Lock_setToWriteLock,											0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_to_write",																									"set_to_write_lock"	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_write",																										"set_to_write_lock"	);
	rb_define_method(						rb_RPbdb_Lock, 	"is_intent_to_write_lock?",																			rb_RPbdb_Lock_isIntentToWriteLock,									0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"intent_to_write_lock?",																				"is_intent_to_write_lock?"	);
	rb_define_method(						rb_RPbdb_Lock, 	"set_to_intent_to_write_lock",																	rb_RPbdb_Lock_setToIntentToWriteLock,							0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_intent_to_write",																					"set_to_intent_to_write_lock"	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_intent",																										"set_to_intent_to_write_lock"	);
	rb_define_method(						rb_RPbdb_Lock, 	"is_intent_to_read_lock?",																			rb_RPbdb_Lock_isIntentToReadLock,									0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"intent_to_read_lock?",																					"is_intent_to_read_lock?"	);
	rb_define_method(						rb_RPbdb_Lock, 	"set_to_intent_to_read_lock",																		rb_RPbdb_Lock_setToIntentToReadLock,								0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_intent_to_read",																						"set_to_intent_to_read_lock"	);
	rb_define_method(						rb_RPbdb_Lock, 	"is_intent_to_read_and_write_lock?",														rb_RPbdb_Lock_isIntentToReadAndWriteLock,					0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"intent_to_read_and_write_lock?",																"is_intent_to_read_and_write_lock?"	);
	rb_define_method(						rb_RPbdb_Lock, 	"set_to_intent_to_read_and_write_lock",													rb_RPbdb_Lock_setToIntentToReadAndWriteLock,				0 	);
	rb_define_alias(						rb_RPbdb_Lock, 	"set_intent_to_read_and_write",																	"set_to_intent_to_read_and_write_lock"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_RPbdb_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_lock_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_lock_controller, rb_RPbdb_LockController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent lock controller> ]"
		)
	);
	
	
	RPbdb_LockController*	c_parent_lock_controller;
	C_RPBDB_LOCK_CONTROLLER( rb_parent_lock_controller, c_parent_lock_controller );
	
	VALUE	rb_lock		=	RUBY_RPBDB_LOCK( RPbdb_Lock_new( c_parent_lock_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_lock,
							RPBDB_RB_LOCK_VARIABLE_PARENT_LOCK_CONTROLLER,
							rb_parent_lock_controller );


	VALUE	argv[]	=	{ rb_parent_lock_controller };	
	rb_obj_call_init(	rb_lock,
										 1, 
										 argv );
	
	return rb_lock;	
}

/*********
*  initialize  *
*********/

VALUE rb_RPbdb_Lock_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self )	{


	return rb_self;
}

/************************
*  settings_controller  *
************************/
VALUE rb_RPbdb_Lock_settingsController(	VALUE	rb_lock )	{

	VALUE	rb_local_lock_settings_controller	=	Qnil;
	
	if ( ( rb_local_lock_settings_controller = rb_iv_get(	rb_lock,
																												RPBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_Lock*		c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );
	
		RPbdb_LockSettingsController*	c_local_lock_settings_controller	=	RPbdb_Lock_settingsController( c_lock );

		rb_local_lock_settings_controller	=	RUBY_RPBDB_LOCK_SETTINGS_CONTROLLER( c_local_lock_settings_controller );

		rb_iv_set(	rb_lock,
								RPBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER,
								rb_local_lock_settings_controller );
	}

	return rb_local_lock_settings_controller;
}

/****************
*  environment  *
****************/
VALUE rb_RPbdb_Lock_parentEnvironment(	VALUE	rb_lock )	{

	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	return RUBY_RPBDB_ENVIRONMENT( RPbdb_Lock_parentEnvironment( c_lock ) );

}

/*********
*  lock  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
VALUE rb_RPbdb_Lock_lock(	VALUE	rb_lock, 
													VALUE	rb_record )	{

	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	RPbdb_Record*		c_record;
	C_RPBDB_RECORD( rb_record, c_record );

	RPbdb_Lock_lock(	c_lock,
									c_record );
	
	return rb_lock;
}

/***********
*  unlock  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_put.html
VALUE rb_RPbdb_Lock_unlock( VALUE	rb_lock )	{

	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	RPbdb_Lock_unlock( c_lock );

	return rb_lock;
}

/*****************
*  is_read_lock  *
*****************/

VALUE rb_RPbdb_Lock_isReadLock( VALUE	rb_lock )	{
	
	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	return ( RPbdb_Lock_isReadLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/*********************
	*  set_to_read_lock  *
	*********************/

	VALUE rb_RPbdb_Lock_setToReadLock( VALUE	rb_lock )	{
	
		RPbdb_Lock*			c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );

		RPbdb_Lock_setToReadLock( c_lock );

		return rb_lock;
	}

/******************
*  is_write_lock  *
******************/

VALUE rb_RPbdb_Lock_isWriteLock( VALUE	rb_lock )	{
	
	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	return ( RPbdb_Lock_isWriteLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/**********************
	*  set_to_write_lock  *
	**********************/

	VALUE rb_RPbdb_Lock_setToWriteLock( VALUE	rb_lock )	{
	
		RPbdb_Lock*			c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );
							
		RPbdb_Lock_setToWriteLock( c_lock );

		return rb_lock;
	}

/****************************
*  is_intent_to_write_lock  *
****************************/

VALUE rb_RPbdb_Lock_isIntentToWriteLock( VALUE	rb_lock )	{
	
	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	return ( RPbdb_Lock_isIntentToWriteLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/********************************
	*  set_to_intent_to_write_lock  *
	********************************/

	VALUE rb_RPbdb_Lock_setToIntentToWriteLock( VALUE	rb_lock )	{
	
		RPbdb_Lock*			c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );
							
		RPbdb_Lock_setToIntentToWriteLock( c_lock );

		return rb_lock;
	}

/***************************
*  is_intent_to_read_lock  *
***************************/

VALUE rb_RPbdb_Lock_isIntentToReadLock( VALUE	rb_lock )	{
	
	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );
						
	return ( RPbdb_Lock_isIntentToReadLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/*******************************
	*  set_to_intent_to_read_lock  *
	*******************************/

	VALUE rb_RPbdb_Lock_setToIntentToReadLock( VALUE	rb_lock )	{
	
		RPbdb_Lock*			c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );
							
		RPbdb_Lock_setToIntentToReadLock( c_lock );

		return rb_lock;
	}

/*************************************
*  is_intent_to_read_and_write_lock  *
*************************************/

VALUE rb_RPbdb_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
	RPbdb_Lock*			c_lock;
	C_RPBDB_LOCK( rb_lock, c_lock );

	return ( RPbdb_Lock_isIntentToReadAndWriteLock( c_lock )	?	Qtrue
																:	Qfalse );
}

	/*****************************************
	*  set_to_intent_to_read_and_write_lock  *
	*****************************************/

	VALUE rb_RPbdb_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
		RPbdb_Lock*			c_lock;
		C_RPBDB_LOCK( rb_lock, c_lock );
							
		RPbdb_Lock_setToIntentToReadAndWriteLock( c_lock );

		return rb_lock;
	}
