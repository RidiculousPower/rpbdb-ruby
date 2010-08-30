/*
 *		RPDB::DatabaseController::Database::CursorController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_RemoteSite.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_ReplicationSettingsController.h>
#include <rpdb/RPDB_RemoteSite.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_RemoteSite;
extern	VALUE	rb_RPDB_ReplicationController;
extern	VALUE	rb_RPDB_ReplicationSettingsController;

void Init_RPDB_RemoteSite()	{

	rb_RPDB_RemoteSite		=	rb_define_class_under(	rb_RPDB_ReplicationController, 
																									"RemoteSite", 		
																									rb_cObject );

	rb_define_singleton_method(	rb_RPDB_RemoteSite, 	"new",											rb_RPDB_RemoteSite_new,													-1 	);
	rb_define_method(						rb_RPDB_RemoteSite, 	"initialize",								rb_RPDB_RemoteSite_init,												-1 	);

	rb_define_method(						rb_RPDB_RemoteSite, 	"settings_controller",			rb_RPDB_RemoteSite_settingsController,					0 	);
	rb_define_alias(						rb_RPDB_RemoteSite, 	"settings",									"settings_controller"	);
	rb_define_alias(						rb_RPDB_RemoteSite, 	"set",											"settings_controller"	);
	rb_define_alias(						rb_RPDB_RemoteSite, 	"set_to",										"settings_controller"	);
	rb_define_alias(						rb_RPDB_RemoteSite, 	"is_set_to",								"settings_controller"	);
	rb_define_method(						rb_RPDB_RemoteSite, 	"parent_environment",				rb_RPDB_RemoteSite_parentEnvironment,						0 	);
	rb_define_alias(						rb_RPDB_RemoteSite, 	"environment",							"parent_environment"	);

	//	FIX - this class hasn't been considered thoroughly yet

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_RemoteSite_new(	VALUE	klass __attribute__ ((unused )),
															VALUE	rb_parent_replication_controller )	{

	RPDB_ReplicationController*	c_parent_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_parent_replication_controller, c_parent_replication_controller );
	
	VALUE	rb_remote_site	=	RUBY_RPDB_REMOTE_SITE( RPDB_RemoteSite_new( c_parent_replication_controller ) );

	VALUE	argv[ 1 ];
	
	argv[ 0 ]	=	rb_parent_replication_controller;
	
	rb_obj_call_init(	rb_remote_site,
					 1, 
					 argv );
	
	return rb_remote_site;		
}

/************
*  new  *
************/

VALUE rb_RPDB_RemoteSite_init(	VALUE	rb_remote_site,
																VALUE	rb_parent_replication_controller __attribute__ ((unused )) )	{

	return rb_remote_site;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_RemoteSite_settingsController(	VALUE	rb_remote_site )	{

	RPDB_RemoteSite*			c_remote_site;
	C_RPDB_REMOTE_SITE( rb_remote_site, c_remote_site );

	return RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( RPDB_RemoteSite_settingsController( c_remote_site ) );

}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_RemoteSite_parentEnvironment(	VALUE	rb_remote_site )	{

	RPDB_RemoteSite*		c_remote_site;
	C_RPDB_REMOTE_SITE( rb_remote_site, c_remote_site );

	return RUBY_RPDB_ENVIRONMENT( RPDB_RemoteSite_parentEnvironment( c_remote_site ) );

}


