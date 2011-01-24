/*
 *		Rbdb
 *
 *		On the C API		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/frame.html
 *
 *			Getting Started:			http://www.oracle.com/technology/documentation/berkeley-db/db/gsg/C/index.html
 *			Transaction Processing:		http://www.oracle.com/technology/documentation/berkeley-db/db/gsg_txn/C/index.html
 *			Replication:				http://www.oracle.com/technology/documentation/berkeley-db/db/gsg_db_rep/C/index.html
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_Environment.h"
#include "rb_Rbdb_Environment_internal.h"

#include "rb_Rbdb.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb_internal.h"

#include "rb_Rbdb_DatabaseObject.h"
#include "rb_Rbdb_DatabaseObject_internal.h"

#include "rb_Rbdb_SettingsController.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_DatabaseController.h>
#include <rbdb/Rbdb_ErrorController.h>
#include <rbdb/Rbdb_TransactionController.h>
#include <rbdb/Rbdb_RuntimeStorageController.h>

#include <rbdb/Rbdb_SettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_mRbdb;
	
VALUE	extern	rb_Rbdb_Environment;

VALUE	extern	rb_Rbdb_ErrorController;
VALUE	extern	rb_Rbdb_DatabaseController;
VALUE	extern	rb_Rbdb_TransactionController;
VALUE	extern	rb_Rbdb_RuntimeStorageController;
VALUE	extern	rb_Rbdb_SettingsController;

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_rb_Rbdb_Environment()	{

	rb_Rbdb_Environment		=	rb_define_class_under(	rb_mRbdb,	
																									"Environment", 
																									rb_cObject );
		
	rb_define_singleton_method(	rb_Rbdb_Environment, 	"new",															rb_Rbdb_Environment_new,													-1 );
	rb_define_singleton_method(	rb_Rbdb_Environment, 	"use",															rb_Rbdb_Environment_use,													-1 );
	rb_define_method(						rb_Rbdb_Environment, 	"initialize",												rb_Rbdb_Environment_initialize,													-1 );
	rb_define_method(						rb_Rbdb_Environment, 	"init_for_storage_in_memory",				rb_Rbdb_Environment_initForStorageInMemory,				0 );
	rb_define_method(						rb_Rbdb_Environment, 	"identify_for_rbdb_as",							rb_Rbdb_Environment_setIdentifiesAs,							-1 );
	rb_define_alias(						rb_Rbdb_Environment, 	"identify_for_rbdb_as=",						"identify_for_rbdb_as" );
	rb_define_alias(						rb_Rbdb_Environment, 	"set_identifies_for_rbdb_as",				"identify_for_rbdb_as" );
	rb_define_alias(						rb_Rbdb_Environment, 	"set_identifies_for_rbdb_as=",			"identify_for_rbdb_as" );
	rb_define_method(						rb_Rbdb_Environment, 	"identifies_for_rbdb_as?",					rb_Rbdb_Environment_identifiesAs,									-1 );
	rb_define_method(						rb_Rbdb_Environment, 	"identifiers",											rb_Rbdb_Environment_identifiers,									0 );
	rb_define_method(						rb_Rbdb_Environment, 	"home_directory",										rb_Rbdb_Environment_homeDirectory,								0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"directory",												"home_directory" );
	
	rb_define_method(						rb_Rbdb_Environment, 	"open",															rb_Rbdb_Environment_open,													0 );
	rb_define_method(						rb_Rbdb_Environment, 	"is_open?",													rb_Rbdb_Environment_isOpen,												0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"open?",														"is_open?" );
	rb_define_method(						rb_Rbdb_Environment, 	"close",														rb_Rbdb_Environment_close,												0 );
	rb_define_method(						rb_Rbdb_Environment, 	"erase!",														rb_Rbdb_Environment_erase,												0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"delete!",													"erase!"	);                            				

	rb_define_method(						rb_Rbdb_Environment, 	"name",															rb_Rbdb_Environment_name,													0 );
	rb_define_method(						rb_Rbdb_Environment, 	"handle",														rb_Rbdb_Environment_handle,												0 );

	rb_define_method(						rb_Rbdb_Environment, 	"database_controller",							rb_Rbdb_Environment_databaseController,						0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"database",													"database_controller" );
	rb_define_alias(						rb_Rbdb_Environment, 	"databases",												"database_controller" );

	rb_define_method(						rb_Rbdb_Environment, 	"transaction_controller",						rb_Rbdb_Environment_transactionController,				0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"transactions",											"transaction_controller" );
	rb_define_alias(						rb_Rbdb_Environment, 	"transaction",											"transaction_controller" );

	rb_define_method(						rb_Rbdb_Environment, 	"settings_controller",							rb_Rbdb_Environment_settingsController,						0 );
	rb_define_alias(						rb_Rbdb_Environment, 	"settings",													"settings_controller" );
	rb_define_alias(						rb_Rbdb_Environment, 	"set",															"settings_controller" );
	rb_define_alias(						rb_Rbdb_Environment, 	"set_to",														"settings_controller"	);
	rb_define_alias(						rb_Rbdb_Environment, 	"is_set_to",												"settings_controller"	);
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_Environment_new(	int			argc,
																VALUE*	args,
																VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_environment_home_directory		=	Qnil;

	/*------------------------------------------------------*/

	rb_scan_args(	argc,
								args,
								"01",
								& rb_environment_home_directory );

	/*------------------------------------------------------*/
	
	char*	c_environment_home_directory	=	NULL;
	if ( rb_environment_home_directory != Qnil )	{
		c_environment_home_directory	=	strdup( StringValuePtr( rb_environment_home_directory ) );
	}
	Rbdb_Environment*	c_environment			=	Rbdb_Environment_new(	c_environment_home_directory );
	
	VALUE	rb_environment	=	RUBY_RBDB_ENVIRONMENT_WITH_FREE( c_environment );

	VALUE	argv[]	=	{ rb_environment_home_directory };
	rb_obj_call_init(	rb_environment,
										1, 
										argv );
	
	return rb_environment;
}
	
/*********
*  free  *
*********/

void rb_Rbdb_Environment_free(	Rbdb_Environment* c_environment )	{
	
	Rbdb_Environment_free( & c_environment );
}

/*********
*  initialize  *
*********/

VALUE rb_Rbdb_Environment_initialize(	int			argc __attribute__ ((unused)),
																VALUE*	args __attribute__ ((unused)),
																VALUE		rb_environment )	{

	return rb_environment;
}

/********
*  use  *
********/

VALUE rb_Rbdb_Environment_use(	int			argc,
																VALUE*	args,
																VALUE		rb_klass_self )	{

	VALUE	rb_environment	=	rb_Rbdb_Environment_new(	argc,
																										args,
																										rb_klass_self );
	
	rb_environment = rb_Rbdb_Environment_open( rb_environment );
	
	return rb_environment;
}

/****************************
*  init_for_memory_storage  *
****************************/

VALUE rb_Rbdb_Environment_initForStorageInMemory( VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );
					
	Rbdb_Environment_initForStorageInMemory( c_environment );

	return rb_environment;
}

/****************************
*  identifies_for_rbdb_as?  *
****************************/

//	answers if environment identifies with identifiers given as parameters
//	returns false if not, or the identifier if true
VALUE rb_Rbdb_Environment_identifiesAs(	int			argc,
																				VALUE*	args,
																				VALUE		rb_environment )	{

	//	get the identifies_as array for this environment, stored in Rbdb
	VALUE	rb_environment_identifiers_array	=	rb_Rbdb_Environment_identifiers( rb_environment );
	
	//	iterate; if one matches, return it (first one wins)
	int	which_identifier	=	0;
	for ( which_identifier = 0 ; which_identifier < argc ; which_identifier++ )	{
	
		if ( rb_ary_includes(	rb_environment_identifiers_array,
													args[ which_identifier ] ) == Qtrue )	{

			return args[ which_identifier ];
			break;
		}
	}
	return Qfalse;
}

/**********************
*  set_identifies_as  *
**********************/

//	sets identifiers for class
//	resets identifiers if called multiple times
VALUE rb_Rbdb_Environment_setIdentifiesAs(	int	argc,
																						VALUE*	args,
																						VALUE	rb_environment )	{

	VALUE	rb_environment_identifiers_array	=	rb_Rbdb_Environment_identifiers( rb_environment );
	
	if ( rb_environment_identifiers_array != Qnil )	{

		//	empty the array
		while( RARRAY_LEN( rb_environment_identifiers_array ) > 0 ) rb_ary_shift( rb_environment_identifiers_array );
		
		//	add new identifiers
		int	which_identifier	=	0;
		for ( which_identifier = 0 ; which_identifier < argc ; which_identifier++ )	{
			rb_ary_push(	rb_environment_identifiers_array,
										args[ which_identifier ] );
		}
	}
	
	return rb_environment;
}
	
/****************
*  identifiers  *
****************/

//	get identifiers for environment
VALUE rb_Rbdb_Environment_identifiers( VALUE	rb_environment )	{

	//	get the environment identifiers hash from the Rbdb module
	VALUE	rb_environment_to_identifiers_hash	=	rb_Rbdb_internal_environmentsToIdentifiersHash( rb_environment );
		
	//	get the environment identifier array from the hash - always initialized already b/c of storing environment at :new
	VALUE	rb_environment_identifier_array		=	rb_hash_aref(	rb_environment_to_identifiers_hash,
																													rb_environment );

	if ( rb_environment_identifier_array == Qnil )	{
		rb_environment_identifier_array	=	rb_ary_new();
		rb_hash_aset(	rb_environment_to_identifiers_hash,
									rb_environment,
									rb_environment_identifier_array );
	}

	//	return identifiers
	return rb_environment_identifier_array;
}	

/*******************************************************************************************************************************************************************************************
																		State
*******************************************************************************************************************************************************************************************/

/*********
*  open  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_open.html
//	This should be implied by the attempt to use a database
VALUE rb_Rbdb_Environment_open( VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment	=	NULL;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );
	
	BOOL	c_should_close_environment	=	TRUE;
	
	if ( Rbdb_Environment_isOpen( c_environment ) )	{
		
		c_should_close_environment	=	FALSE;
		
	}	else {
		
		Rbdb_Environment_open( c_environment );

		rb_Rbdb_Environment_internal_configureWaitingClassesForEnvironment( rb_environment );
	}

	rb_Rbdb_setCurrentWorkingEnvironment( rb_mRbdb,
																				rb_environment );

	if ( rb_block_given_p() )	{
		VALUE	rb_return	=	rb_yield( rb_environment );
		if ( c_should_close_environment )	{
			rb_Rbdb_Environment_close( rb_environment );
		}
		return rb_return;
	}
	
	return rb_environment;
}

/*************
*  is_open?  *
*************/

VALUE rb_Rbdb_Environment_isOpen( VALUE	rb_environment )	{
	
	Rbdb_Environment*	c_environment	=	NULL;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );
	
	return ( c_environment->is_open == TRUE ? Qtrue : Qfalse );
}	


/*******************
*  home_directory  *
*******************/

VALUE rb_Rbdb_Environment_homeDirectory( VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment	=	NULL;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );
	
	char*	c_environment_home_directory	=	Rbdb_Environment_homeDirectory( c_environment );
	VALUE	rb_environment_home_directory	=	rb_str_new2( c_environment_home_directory );
	
	return rb_environment_home_directory;
}	
	
/**********
*  close  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_close.html
VALUE rb_Rbdb_Environment_close( VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );

	//	mark configured classes as waiting for next environment
	rb_Rbdb_Environment_internal_unmarkClassesConfigured(	rb_environment );
		
	//	remove our environment from hash in module
	
	VALUE	rb_environment_to_identifiers_hash	=	rb_Rbdb_internal_environmentsToIdentifiersHash( rb_environment );

	rb_funcall(	rb_environment_to_identifiers_hash,
							rb_intern( "delete" ),
							1,
							rb_environment );
	
	Rbdb_Environment_close( c_environment );

	return rb_environment;
}

/**********
*  erase  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_remove.html
VALUE rb_Rbdb_Environment_erase( VALUE	rb_environment )	{

	Rbdb_Environment*	c_environment;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );

	Rbdb_Environment_erase( c_environment );
	
	return rb_environment;
}

/***********
*  handle  *
***********/

VALUE rb_Rbdb_Environment_handle( VALUE rb_environment )	{
	
	Rbdb_Environment*	c_environment;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );

	char*	c_name	=	Rbdb_Environment_name( c_environment );
	VALUE	rb_handle	=	Qnil;
	if ( c_name )	{
		rb_handle	=	ID2SYM( rb_intern( c_name ) );
	}

	return rb_handle;
}

/*********
*  name  *
*********/

VALUE rb_Rbdb_Environment_name( VALUE rb_environment )	{

	Rbdb_Environment*	c_environment;
	C_RBDB_ENVIRONMENT( rb_environment, c_environment );

	char*	c_name	=	Rbdb_Environment_name( c_environment );
	VALUE	rb_name	=	Qnil;
	if ( c_name )	{
		rb_name	=	rb_str_new2( c_name );
	}

	return rb_name;
}

/***********************
*  configured_classes  *
***********************/

VALUE rb_Rbdb_Environment_configuredClasses( VALUE rb_environment )	{
	
	VALUE	rb_configured_classes_array	=	rb_iv_get(	rb_environment,
														RBDB_RB_ENVIRONMENT_VARIABLE_CONFIGURED_CLASSES );
	
	if ( rb_configured_classes_array == Qnil )	{
		rb_configured_classes_array = rb_ary_new();
		rb_iv_set(	rb_environment,
					RBDB_RB_ENVIRONMENT_VARIABLE_CONFIGURED_CLASSES,
					rb_configured_classes_array );
	}
	return rb_configured_classes_array;
}
	
/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/************************
*  database_controller  *
************************/

VALUE rb_Rbdb_Environment_databaseController( VALUE rb_environment )	{

	VALUE	rb_database_controller	=	Qnil;
	if ( ( rb_database_controller = rb_iv_get(	rb_environment,
																							RBDB_RB_ENVIRONMENT_VARIABLE_DATABASE_CONTROLLER ) ) == Qnil )	{
		
		rb_database_controller	=	rb_Rbdb_DatabaseController_new(	1,
																															& rb_environment,
																															rb_Rbdb_DatabaseController );
		
		rb_iv_set(	rb_environment,
								RBDB_RB_ENVIRONMENT_VARIABLE_DATABASE_CONTROLLER,
								rb_database_controller );
	}
	
	return rb_database_controller;
}

/***************************
*  transaction_controller  *
***************************/

VALUE rb_Rbdb_Environment_transactionController( VALUE rb_environment )	{
	
	VALUE	rb_transaction_controller	=	Qnil;
	if ( ( rb_transaction_controller = rb_iv_get(	rb_environment,
																								RBDB_RB_ENVIRONMENT_VARIABLE_TRANSACTION_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_Environment*	c_environment;
		C_RBDB_ENVIRONMENT( rb_environment, c_environment );
		
		Rbdb_TransactionController*	c_transaction_controller	=	Rbdb_Environment_transactionController( c_environment );

		rb_transaction_controller	=	RUBY_RBDB_TRANSACTION_CONTROLLER( c_transaction_controller );

		rb_iv_set(	rb_environment,
								RBDB_RB_ENVIRONMENT_VARIABLE_TRANSACTION_CONTROLLER,
								rb_transaction_controller );
	}
	
	return rb_transaction_controller;	
}

/************************
*  settings_controller  *
************************/

VALUE rb_Rbdb_Environment_settingsController( VALUE rb_environment )	{

	VALUE	rb_settings_controller	=	Qnil;
	if ( ( rb_settings_controller = rb_iv_get(	rb_environment,
																							RBDB_RB_ENVIRONMENT_VARIABLE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		rb_settings_controller	=	rb_Rbdb_SettingsController_new(	1,
																															& rb_environment,
																															rb_Rbdb_SettingsController );

		rb_iv_set(	rb_environment,
								RBDB_RB_ENVIRONMENT_VARIABLE_SETTINGS_CONTROLLER,
								rb_settings_controller );
	}
	
	return rb_settings_controller;

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/******************************************
*  configureWaitingClassesForEnvironment  *
******************************************/

VALUE rb_Rbdb_Environment_internal_configureWaitingClassesForEnvironment( VALUE rb_environment )	{
	
	//	iterate default environment wait list
	//	if anything is on this wait list then this environment opening now will be the default
	//	so we can initialize any classes on the default environment wait list with this environment
	VALUE	rb_current_working_environment_wait_list	=	rb_Rbdb_internal_classesWaitingForDefaultEnvironment();
	
	int	which_klass;
	for ( which_klass = 0 ; which_klass < RARRAY_LEN( rb_current_working_environment_wait_list ) ; which_klass++ )	{
		
		VALUE	rb_klass_self	=	RARRAY_PTR( rb_current_working_environment_wait_list )[ which_klass ];
		
		//	configure
		rb_Rbdb_DatabaseObject_internal_configureWithEnvironment(	rb_klass_self,
																	rb_environment );
	}
	
	//	iterate identifier wait list to see if environment provides identifiers on wait list
	VALUE	rb_klass_wait_list				=	rb_Rbdb_internal_classesWaitingForIdentification();
	VALUE	rb_klass_identifiers			=	Qnil;
	VALUE	rb_identifier_intersection		=	Qnil;

	for ( which_klass = 0 ; which_klass < RARRAY_LEN( rb_klass_wait_list ) ; which_klass++ )	{
		
		VALUE	rb_this_klass_from_waitlist	=	RARRAY_PTR( rb_klass_wait_list )[ which_klass ];
		
		//	get identifiers for class
		rb_klass_identifiers		=	rb_Rbdb_DatabaseObject_internal_identifiers( rb_this_klass_from_waitlist );
		
		//	iterate identifiers provided by this environment
		VALUE	rb_environment_identifiers	=	rb_Rbdb_Environment_identifiers( rb_environment );
		
		//	if we don't have any environment identifiers we can break - we won't match anything (or would have at default environment)
		if ( RARRAY_LEN( rb_environment_identifiers ) == 0 )	{
			break;
		}
		
		
		//	if one matches one in class, use this environment for class
		rb_identifier_intersection	=	rb_funcall(	rb_environment_identifiers,
													rb_intern( "&" ),
													1,
													rb_klass_identifiers );
		if ( RARRAY_LEN( rb_identifier_intersection ) > 0 )	{
			
			//	now we know that we have a match 
			//	we don't care which identifier matched, only that one did - set this environment for class
			rb_Rbdb_DatabaseObject_internal_configureWithEnvironment(	rb_this_klass_from_waitlist,
																																rb_environment );
		}
	}
	
	//	call init on all classes that were just configured
	rb_Rbdb_internal_initializeWaitingClasses();
	
	return rb_environment;
}

/************************
*  markClassConfigured  *
************************/

//	mark class as configured when it is associated with environment so that we can unload it when environment closes
VALUE rb_Rbdb_Environment_internal_markClassConfigured(	VALUE	rb_enviroment,
															VALUE	rb_klass )	{
	
	VALUE	rb_configured_classes_array	=	rb_Rbdb_Environment_configuredClasses( rb_enviroment );

	rb_ary_push(	rb_configured_classes_array,
					rb_klass );
	
	return rb_enviroment;
}

/****************************
*  unmarkClassesConfigured  *
****************************/

//	mark classes that were configured for environment as waiting for new environment
VALUE rb_Rbdb_Environment_internal_unmarkClassesConfigured( VALUE rb_enviroment )	{

	VALUE	rb_configured_classes_array	=	rb_Rbdb_Environment_configuredClasses( rb_enviroment );
	
	//	if we have configured classes we have to mark them as waiting again
	if ( RARRAY_LEN( rb_configured_classes_array ) > 0 )	{
		
		VALUE	rb_this_class;
		while ( ( rb_this_class = rb_ary_shift( rb_configured_classes_array ) ) != Qnil )	{
			
			//	check if class is good for default environment
			//	if it is, put it on default environment wait list
			//	it will configure with the next environment that opens
			if ( rb_Rbdb_DatabaseObject_internal_identifiersAllowDefaultEnvironment( rb_this_class ) )	{				
				rb_Rbdb_DatabaseObject_internal_markForDefaultEnvironment( rb_this_class );
			}		
			//	otherwise put class on identifier wait list
			else {
				rb_Rbdb_DatabaseObject_internal_markForIdentification( rb_this_class );
			}

		}
	}
	
	return rb_enviroment;
}
