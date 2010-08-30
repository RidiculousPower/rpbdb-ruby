
/*
 *		RPDB::SettingsController::ThreadSettingsController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_ThreadSettingsController.h"
#include "rb_RPDB_SettingsController.h"

#include "rb_RPDB_Environment.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ThreadSettingsController.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;	
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_ThreadSettingsController;
	
void Init_RPDB_ThreadSettingsController()	{

	rb_define_singleton_method(	rb_RPDB_ThreadSettingsController, 	"new",																rb_RPDB_ThreadSettingsController_init,										1 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"initialize",													rb_RPDB_ThreadSettingsController_init,										1 	);

	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"parent_environment",									rb_RPDB_ThreadSettingsController_parentEnvironment,				0 	);
	rb_define_alias(			rb_RPDB_ThreadSettingsController, 				"environment",												"parent_environment"	);

	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_on,													0 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_off,													0 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_turnOn,											0 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_turnOff,											0 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_threadCount,									0 	);
	rb_define_method(			rb_RPDB_ThreadSettingsController, 				"shm_key",														rb_RPDB_ThreadSettingsController_setThreadCount,							0 	);

}
	
/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_ThreadSettingsController_new(	VALUE	klass __attribute__ ((unused )),
																						VALUE	rb_parent_settings_controller )	{
	
	RPDB_SettingsController*	c_parent_settings_controller;
	C_RPDB_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );
	
	VALUE	rb_thread_settings_controller	= RUBY_RPDB_THREAD_SETTINGS_CONTROLLER( RPDB_ThreadSettingsController_new( c_parent_settings_controller ) );
	
	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_settings_controller;
	
	rb_obj_call_init(	rb_thread_settings_controller,
					 1, 
					 argv );
	
	return rb_thread_settings_controller;		
}

/************
*  init  *
************/

VALUE rb_RPDB_ThreadSettingsController_init(	VALUE	rb_thread_settings_controller,
																							VALUE	rb_parent_settings_controller __attribute__ ((unused )) )	{

	return rb_thread_settings_controller;
}

/***************************************
*  environment  *
***************************************/

VALUE rb_RPDB_ThreadSettingsController_parentEnvironment(	VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return RUBY_RPDB_ENVIRONMENT( RPDB_ThreadSettingsController_parentEnvironment( c_thread_settings_controller ) );
}

/**********
*  on  *
**********/

//	DB_THREAD		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_ThreadSettingsController_on( VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return ( RPDB_ThreadSettingsController_on( c_thread_settings_controller )	?	Qtrue
																				:	Qfalse );
}

/************
*  off  *
************/

VALUE rb_RPDB_ThreadSettingsController_off( VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return ( RPDB_ThreadSettingsController_off( c_thread_settings_controller )	?	Qtrue
																				:	Qfalse );
}

/****************
*  turnOn  *
****************/

VALUE rb_RPDB_ThreadSettingsController_turnOn( VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	RPDB_ThreadSettingsController_turnOn( c_thread_settings_controller );

	return rb_thread_settings_controller;
}

/****************
*  turnOff  *
****************/

VALUE rb_RPDB_ThreadSettingsController_turnOff( VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	RPDB_ThreadSettingsController_turnOff( c_thread_settings_controller );

	return rb_thread_settings_controller;
}

/*********************
*  threadCount  *
*********************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_count.html
VALUE rb_RPDB_ThreadSettingsController_threadCount( VALUE	rb_thread_settings_controller )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	return FIX2INT( RPDB_ThreadSettingsController_threadCount( c_thread_settings_controller ) );
}

/**********************
*  setThreadCount  *
**********************/

VALUE rb_RPDB_ThreadSettingsController_setThreadCount(	VALUE	rb_thread_settings_controller, 
														VALUE	rb_thread_count )	{

	RPDB_ThreadSettingsController*	c_thread_settings_controller;
	C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller );

	RPDB_ThreadSettingsController_setThreadCount(	c_thread_settings_controller,
													FIX2INT( rb_thread_count ) );

	return rb_thread_settings_controller;
}

/************************************************
*  setUniqueThreadIdentifierCallbackMethod  *
************************************************/
/*
VALUE rb_RPDB_ThreadSettingsController_setUniqueThreadIdentifierCallbackMethod(	VALUE	rb_thread_settings_controller,
 																				void (*unique_thread_identifier_callback_method)(	VALUE				environment,
																																	pid_t*				process_id,
																																	db_threadid_t*		thread_id	) )	{

}
*/
/********************************************
*  uniqueThreadIdentifierCallbackMethod  *
********************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_id.html
void (*unique_thread_identifier_callback_method)(	VALUE				environment,
													pid_t*				process_id,
													db_threadid_t*		thread_id	) RPDB_ThreadSettingsController_uniqueThreadIdentifierCallbackMethod( VALUE	rb_thread_settings_controller )	{

}
*/
/********************************************************************
*  setFormatThreadAndProcessIdentifierForDisplayCallbackMethod  *
********************************************************************/
/*
VALUE rb_RPDB_ThreadSettingsController_setFormatThreadAndProcessIdentifierForDisplayCallbackMethod(	VALUE	rb_thread_settings_controller,
 																									void (*format_thread_and_process_identifier_for_display_callback_method)(	VALUE				environment,
																																												pid_t				process_id,
																																												db_threadid_t		thread_id,
																																												VALUE				string_buffer ) )	{

}
*/
/****************************************************************
*  formatThreadAndProcessIdentifierForDisplayCallbackMethod  *
****************************************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_thread_id_string.html
void (*format_thread_and_process_identifier_for_display_callback_method)(	VALUE				environment,
																			pid_t				process_id,
																			db_threadid_t		thread_id,
																			VALUE				string_buffer ) RPDB_ThreadSettingsController_formatThreadAndProcessIDForDisplayCallbackMethod(	VALUE	rb_thread_settings_controller	)	{


}
*/
/************************************
*  setIsThreadAliveCallbackMethod  *
************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_isalive.html
VALUE rb_RPDB_ThreadSettingsController_setIsThreadAliveCallbackgBDB_ThreadSettingsController* 									thread_settings_controller,
 																	VALUE(*RPDB_IsThreadAliveCallbackMethod)(	VALUE				environment,
																													pid_t				process_id,
																													db_threadid_t		thread_id,
																													VALUE			associated_with_single_process ) )	{
																														
}
*/
/************************************
*  isThreadAliveCallbackMethod  *
************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_set_isalive.html
VALUE(*RPDB_IsThreadAliveCallbackMethod)(	VALUE				environment,
												pid_t				process_id,
												db_threadid_t		thread_id,
												VALUE			associated_with_single_process ) RPDB_ThreadSettingsController_isThreadAliveCallbackMethod( VALUE	rb_thread_settings_controller )	{

}
*/