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

#include <rargs.h>

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

VALUE rb_RPDB_RemoteSite_new(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_parent_environment										=	Qnil;
	VALUE	rb_parent_replication_controller				=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_environment, rb_RPDB_Environment ),
																						R_MatchAncestorInstance( rb_parent_replication_controller, rb_RPDB_ReplicationController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent environment> ]",
			"[ <parent replication controller> ]"
		)
	);

	RPDB_ReplicationController*	c_parent_replication_controller;
	C_RPDB_REPLICATION_CONTROLLER( rb_parent_replication_controller, c_parent_replication_controller );
	
	RPDB_RemoteSite*	c_remote_site	=	RPDB_ReplicationController_addRemoteSite( c_parent_replication_controller );
	
	VALUE	rb_remote_site	=	RUBY_RPDB_REMOTE_SITE( c_remote_site );

	//	store reference to parent
	rb_iv_set(	rb_remote_site,
							RPDB_RB_REMOTE_SITE_VARIABLE_PARENT_REPLICATION_CONTROLLER,
							rb_parent_replication_controller );

	VALUE	argv[]	=	{ rb_parent_replication_controller };
	rb_obj_call_initialize(	rb_remote_site,
										1, 
										argv );
	
	return rb_remote_site;		
}

/************
*  new  *
************/

VALUE rb_RPDB_RemoteSite_initialize(	int				argc __attribute__ ((unused)),
																VALUE*		args __attribute__ ((unused)),
																VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_RemoteSite_settingsController(	VALUE	rb_remote_site )	{

	VALUE	rb_local_replication_settings_controller	=	Qnil;
	
	if ( ( rb_local_replication_settings_controller = rb_iv_get(	rb_remote_site,
																																RPDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_RemoteSite*		c_remote_site;
		C_RPDB_REMOTE_SITE( rb_remote_site, c_remote_site );
	
		RPDB_ReplicationSettingsController*	c_local_replication_settings_controller	=	RPDB_RemoteSite_settingsController( c_remote_site );

		rb_local_replication_settings_controller	=	RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( c_local_replication_settings_controller );

		rb_iv_set(	rb_remote_site,
								RPDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER,
								rb_local_replication_settings_controller );
	}

	return rb_local_replication_settings_controller;
}

/***************************************
*  parent_environment  *
***************************************/
VALUE rb_RPDB_RemoteSite_parentEnvironment(	VALUE	rb_remote_site )	{

	VALUE	rb_parent_replication_controller	=	rb_RPDB_RemoteSite_parentReplicationController( rb_remote_site );
	VALUE	rb_parent_environment							=	rb_RPDB_RemoteSite_parentEnvironment( rb_parent_replication_controller );
	
	return rb_parent_environment;
}

/***************************************
*  parent_replication_controller  *
***************************************/
VALUE rb_RPDB_RemoteSite_parentReplicationController(	VALUE	rb_remote_site )	{

	VALUE	rb_replication_controller	=	rb_iv_get(	rb_remote_site,
																								RPDB_RB_REMOTE_SITE_VARIABLE_PARENT_REPLICATION_CONTROLLER );

	return rb_replication_controller;
}


