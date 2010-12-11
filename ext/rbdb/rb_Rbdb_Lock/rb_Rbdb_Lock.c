/*
 *		Rbdb::LockController::Lock
 *
 *		Reference - http://www.oracle.com/technology/documentation/berkeley-db/db/ref/lock/am_conv.html
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Lock.h"
#include "rb_Rbdb_LockController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Lock.h>

#include <rbdb/Rbdb_LockSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Lock;
extern	VALUE	rb_Rbdb_LockController;
extern	VALUE	rb_Rbdb_LockSettingsController;

void Init_rb_Rbdb_Lock()	{

	rb_Rbdb_LockController	=	rb_define_class_under(	rb_Rbdb_Environment, 
																										"Lock",			
																										rb_cObject );

	rb_define_singleton_method(	rb_Rbdb_Lock, 	"new",																													rb_Rbdb_Lock_new,																	-1 	);
	rb_define_method(						rb_Rbdb_Lock, 	"initialize",																										rb_Rbdb_Lock_initialize,																-1 	);
                                                                                          		
	rb_define_method(						rb_Rbdb_Lock, 	"settings_controller",																					rb_Rbdb_Lock_settingsController,									0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"settings",																											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set",																													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_to",																												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Lock, 	"is_set_to",																										"settings_controller"	);
	rb_define_method(						rb_Rbdb_Lock, 	"parent_environment",																						rb_Rbdb_Lock_parentEnvironment,										0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"environment",																									"parent_environment"	);

	rb_define_method(						rb_Rbdb_Lock, 	"lock",																													rb_Rbdb_Lock_lock,																0 	);
	rb_define_method(						rb_Rbdb_Lock, 	"unlock",																												rb_Rbdb_Lock_unlock,															0 	);
	rb_define_method(						rb_Rbdb_Lock, 	"is_read_lock?",																								rb_Rbdb_Lock_isReadLock,													0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"read_lock?",																										"is_read_lock?"	);
	rb_define_method(						rb_Rbdb_Lock, 	"is_write_lock?",																								rb_Rbdb_Lock_isWriteLock,													0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"write_lock?",																									"is_write_lock?"	);
	rb_define_method(						rb_Rbdb_Lock, 	"set_to_write_lock",																						rb_Rbdb_Lock_setToWriteLock,											0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_to_write",																									"set_to_write_lock"	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_write",																										"set_to_write_lock"	);
	rb_define_method(						rb_Rbdb_Lock, 	"is_intent_to_write_lock?",																			rb_Rbdb_Lock_isIntentToWriteLock,									0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"intent_to_write_lock?",																				"is_intent_to_write_lock?"	);
	rb_define_method(						rb_Rbdb_Lock, 	"set_to_intent_to_write_lock",																	rb_Rbdb_Lock_setToIntentToWriteLock,							0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_intent_to_write",																					"set_to_intent_to_write_lock"	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_intent",																										"set_to_intent_to_write_lock"	);
	rb_define_method(						rb_Rbdb_Lock, 	"is_intent_to_read_lock?",																			rb_Rbdb_Lock_isIntentToReadLock,									0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"intent_to_read_lock?",																					"is_intent_to_read_lock?"	);
	rb_define_method(						rb_Rbdb_Lock, 	"set_to_intent_to_read_lock",																		rb_Rbdb_Lock_setToIntentToReadLock,								0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_intent_to_read",																						"set_to_intent_to_read_lock"	);
	rb_define_method(						rb_Rbdb_Lock, 	"is_intent_to_read_and_write_lock?",														rb_Rbdb_Lock_isIntentToReadAndWriteLock,					0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"intent_to_read_and_write_lock?",																"is_intent_to_read_and_write_lock?"	);
	rb_define_method(						rb_Rbdb_Lock, 	"set_to_intent_to_read_and_write_lock",													rb_Rbdb_Lock_setToIntentToReadAndWriteLock,				0 	);
	rb_define_alias(						rb_Rbdb_Lock, 	"set_intent_to_read_and_write",																	"set_to_intent_to_read_and_write_lock"	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Lock_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment						=	Qnil;
	VALUE	rb_parent_lock_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_Rbdb_Environment ),
																						R_MatchAncestorInstance( rb_parent_lock_controller, rb_Rbdb_LockController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent lock controller> ]"
		)
	);
	
	
	Rbdb_LockController*	c_parent_lock_controller;
	C_RBDB_LOCK_CONTROLLER( rb_parent_lock_controller, c_parent_lock_controller );
	
	VALUE	rb_lock		=	RUBY_RBDB_LOCK( Rbdb_Lock_new( c_parent_lock_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_lock,
							RBDB_RB_LOCK_VARIABLE_PARENT_LOCK_CONTROLLER,
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

VALUE rb_Rbdb_Lock_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self )	{


	return rb_self;
}

/************************
*  settings_controller  *
************************/
VALUE rb_Rbdb_Lock_settingsController(	VALUE	rb_lock )	{

	VALUE	rb_local_lock_settings_controller	=	Qnil;
	
	if ( ( rb_local_lock_settings_controller = rb_iv_get(	rb_lock,
																												RBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Lock*		c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );
	
		Rbdb_LockSettingsController*	c_local_lock_settings_controller	=	Rbdb_Lock_settingsController( c_lock );

		rb_local_lock_settings_controller	=	RUBY_RBDB_LOCK_SETTINGS_CONTROLLER( c_local_lock_settings_controller );

		rb_iv_set(	rb_lock,
								RBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER,
								rb_local_lock_settings_controller );
	}

	return rb_local_lock_settings_controller;
}

/****************
*  environment  *
****************/
VALUE rb_Rbdb_Lock_parentEnvironment(	VALUE	rb_lock )	{

	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	return RUBY_RBDB_ENVIRONMENT( Rbdb_Lock_parentEnvironment( c_lock ) );

}

/*********
*  lock  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_get.html
VALUE rb_Rbdb_Lock_lock(	VALUE	rb_lock, 
													VALUE	rb_record )	{

	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	Rbdb_Record*		c_record;
	C_RBDB_RECORD( rb_record, c_record );

	Rbdb_Lock_lock(	c_lock,
									c_record );
	
	return rb_lock;
}

/***********
*  unlock  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/lock_put.html
VALUE rb_Rbdb_Lock_unlock( VALUE	rb_lock )	{

	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	Rbdb_Lock_unlock( c_lock );

	return rb_lock;
}

/*****************
*  is_read_lock  *
*****************/

VALUE rb_Rbdb_Lock_isReadLock( VALUE	rb_lock )	{
	
	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	return ( Rbdb_Lock_isReadLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/*********************
	*  set_to_read_lock  *
	*********************/

	VALUE rb_Rbdb_Lock_setToReadLock( VALUE	rb_lock )	{
	
		Rbdb_Lock*			c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );

		Rbdb_Lock_setToReadLock( c_lock );

		return rb_lock;
	}

/******************
*  is_write_lock  *
******************/

VALUE rb_Rbdb_Lock_isWriteLock( VALUE	rb_lock )	{
	
	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	return ( Rbdb_Lock_isWriteLock( c_lock )	?	Qtrue
												:	Qfalse );
}

	/**********************
	*  set_to_write_lock  *
	**********************/

	VALUE rb_Rbdb_Lock_setToWriteLock( VALUE	rb_lock )	{
	
		Rbdb_Lock*			c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );
							
		Rbdb_Lock_setToWriteLock( c_lock );

		return rb_lock;
	}

/****************************
*  is_intent_to_write_lock  *
****************************/

VALUE rb_Rbdb_Lock_isIntentToWriteLock( VALUE	rb_lock )	{
	
	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	return ( Rbdb_Lock_isIntentToWriteLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/********************************
	*  set_to_intent_to_write_lock  *
	********************************/

	VALUE rb_Rbdb_Lock_setToIntentToWriteLock( VALUE	rb_lock )	{
	
		Rbdb_Lock*			c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );
							
		Rbdb_Lock_setToIntentToWriteLock( c_lock );

		return rb_lock;
	}

/***************************
*  is_intent_to_read_lock  *
***************************/

VALUE rb_Rbdb_Lock_isIntentToReadLock( VALUE	rb_lock )	{
	
	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );
						
	return ( Rbdb_Lock_isIntentToReadLock( c_lock )	?	Qtrue
														:	Qfalse );
}

	/*******************************
	*  set_to_intent_to_read_lock  *
	*******************************/

	VALUE rb_Rbdb_Lock_setToIntentToReadLock( VALUE	rb_lock )	{
	
		Rbdb_Lock*			c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );
							
		Rbdb_Lock_setToIntentToReadLock( c_lock );

		return rb_lock;
	}

/*************************************
*  is_intent_to_read_and_write_lock  *
*************************************/

VALUE rb_Rbdb_Lock_isIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
	Rbdb_Lock*			c_lock;
	C_RBDB_LOCK( rb_lock, c_lock );

	return ( Rbdb_Lock_isIntentToReadAndWriteLock( c_lock )	?	Qtrue
																:	Qfalse );
}

	/*****************************************
	*  set_to_intent_to_read_and_write_lock  *
	*****************************************/

	VALUE rb_Rbdb_Lock_setToIntentToReadAndWriteLock( VALUE	rb_lock )	{
	
		Rbdb_Lock*			c_lock;
		C_RBDB_LOCK( rb_lock, c_lock );
							
		Rbdb_Lock_setToIntentToReadAndWriteLock( c_lock );

		return rb_lock;
	}
