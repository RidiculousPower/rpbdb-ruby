/*
 *		RPDB::DatabaseController::Database
 *
 *
 */

#include "rb_RPDB.h"
#include "rb_RPDB_Database.h"
#include "rb_RPDB_Database_internal.h"
#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_DatabaseCursorController.h"
#include "rb_RPDB_DatabaseCursor.h"

#include "rb_RPDB_DatabaseController.h"
#include "rb_RPDB_Environment.h"

#include "rb_RPDB_SettingsController.h"
#include "rb_RPDB_DatabaseSettingsController.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseCursor.h>
#include <rpdb/RPDB_Database_internal.h>
#include <rpdb/RPDB_DatabaseController.h>
#include <rpdb/RPDB_DatabaseCursorController.h>
#include <rpdb/RPDB_DatabaseJoinController.h>

#include <rpdb/RPDB_Record.h>
#include <rpdb/RPDB_Key.h>
#include <rpdb/RPDB_Data.h>
#include <rpdb/RPDB_SecondaryKeys.h>

#include <rpdb/RPDB_SettingsController.h>
#include <rpdb/RPDB_DatabaseSettingsController.h>

extern	VALUE	rb_mRPDB;
extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_DatabaseController;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseCursor;
extern	VALUE	rb_RPDB_DatabaseObjectCursor;
extern	VALUE	rb_RPDB_DatabaseCursorController;
extern	VALUE	rb_RPDB_DatabaseVerificationController;
extern	VALUE	rb_RPDB_DatabaseJoinController;
extern	VALUE	rb_RPDB_DatabaseSequenceController;

extern	VALUE	rb_RPDB_Key;
extern	VALUE	rb_RPDB_Data;
extern	VALUE	rb_RPDB_SecondaryKeys;
extern	VALUE	rb_RPDB_SettingsController;
extern	VALUE	rb_RPDB_DatabaseSettingsController;
	
#define RPDB_RUBY_ERROR_INVALID_DATABASE_DATA			"Provided data was invalid. Database requires object that can be automatically converted to string."

#define RPDB_GVAR_SECONDARY_KEY_CALLBACK_METHODS	"$rpdb_secondary_key_callback_methods"

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

void Init_RPDB_Database()	{

	rb_RPDB_Database		=	rb_define_class_under(	rb_RPDB_DatabaseController, 
																								"Database",
																								rb_cObject );

	rb_define_singleton_method(	rb_RPDB_Database, 	"new",																					rb_RPDB_Database_new,																				-1 	);
	rb_define_method(						rb_RPDB_Database, 	"initialize",																		rb_RPDB_Database_init,																			-1 	);

	rb_define_method(						rb_RPDB_Database, 	"settings_controller",													rb_RPDB_Database_settingsController,												0 	);
	rb_define_alias(						rb_RPDB_Database, 	"settings",																			"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"set",																					"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"set_to",																				"settings_controller"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"is_set_to",																		"settings_controller"	);                            				
	rb_define_method(						rb_RPDB_Database, 	"parent_environment",														rb_RPDB_Database_parentEnvironment,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"parent_environment",														"parent_environment"	);                            				
	rb_define_alias(						rb_RPDB_Database, 	"environment",																	"parent_environment"	);                            				

	rb_define_method(						rb_RPDB_Database, 	"filename",																			rb_RPDB_Database_filename,																	0 	);
	rb_define_method(						rb_RPDB_Database, 	"name",																					rb_RPDB_Database_name,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"rename",																				rb_RPDB_Database_rename,																		1 	);
	rb_define_method(						rb_RPDB_Database, 	"handle",																				rb_RPDB_Database_handle,																		0 	);

	rb_define_method(						rb_RPDB_Database, 	"open",																					rb_RPDB_Database_open,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"is_open?",																			rb_RPDB_Database_isOpen,																		0 	);
	rb_define_alias(						rb_RPDB_Database, 	"open?",																				"is_open?"	);                                        				
	rb_define_method(						rb_RPDB_Database, 	"close",																				rb_RPDB_Database_close,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"empty",																				rb_RPDB_Database_empty,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"erase",																				rb_RPDB_Database_erase,																			0 	);
	rb_define_method(						rb_RPDB_Database, 	"sync",																					rb_RPDB_Database_sync,																			0 	);
                    					                                                                                                                        				
	rb_define_method(						rb_RPDB_Database, 	"key_exists?",																	rb_RPDB_Database_keyExists,																	1 	);
	rb_define_alias(						rb_RPDB_Database, 	"exists?",																			"key_exists?" );                                    				
	rb_define_method(						rb_RPDB_Database, 	"write",																				rb_RPDB_Database_write,																			2 	);
	rb_define_method(						rb_RPDB_Database, 	"retrieve",																			rb_RPDB_Database_retrieve,																	-1 	);
	rb_define_method(						rb_RPDB_Database, 	"delete",																				rb_RPDB_Database_delete,																		-1 	);
                    					                                                                                                                        				
	rb_define_method(						rb_RPDB_Database, 	"associate_secondary_database",									rb_RPDB_Database_associateSecondaryDatabase,								1 	);
	rb_define_alias(						rb_RPDB_Database, 	"associate_secondary",													"associate_secondary_database"	);                  				
	rb_define_method(						rb_RPDB_Database, 	"is_secondary_database?",												rb_RPDB_Database_isSecondary,																0 	);
	rb_define_alias(						rb_RPDB_Database, 	"is_secondary?",																"is_secondary_database?"	);
	rb_define_method(						rb_RPDB_Database, 	"secondary_key_creation_callback_method",				rb_RPDB_Database_secondaryKeyCreationCallbackMethod,				0 	);
	rb_define_method(						rb_RPDB_Database, 	"secondary_key_creation_callback_method=",			rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod,			-1 	);
	rb_define_alias(						rb_RPDB_Database, 	"secondary_key_creation_callback_method=",			"secondary_key_creation_callback_method="	);
	rb_define_alias(						rb_RPDB_Database, 	"set_secondary_key_creation_callback_method",		"secondary_key_creation_callback_method="	);
	rb_define_method(						rb_RPDB_Database, 	"create_secondary_index",												rb_RPDB_Database_createSecondaryIndex,											-1 	);
                    					
	rb_define_method(						rb_RPDB_Database, 	"cursor_controller",														rb_RPDB_Database_cursorController,													0 	);
	rb_define_alias(						rb_RPDB_Database, 	"cursors",																			"cursor_controller"	);
	rb_define_method(						rb_RPDB_Database, 	"cursor",																				rb_RPDB_Database_cursor,																		0 	);
	rb_define_method(						rb_RPDB_Database, 	"object_cursor",																rb_RPDB_Database_objectCursor,															0 	);

}

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_RPDB_Database_new(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self __attribute__((unused)) )	{

	VALUE	rb_database_name							=	Qnil;
	VALUE	rb_parent_database_controller	=	Qnil;
	VALUE	rb_parent_environment					=	Qnil;
	
	/*------------------------------------------------------*/

	VALUE	rb_parent_environment_or_name_string_or_symbol_or_database_controller	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_database_name,
								& rb_parent_environment_or_name_string_or_symbol_or_database_controller );
	
	//	if we have an environment or database controller, figure out which
	if ( rb_parent_environment_or_name_string_or_symbol_or_database_controller != Qnil ) {
		
		VALUE	rb_arg_klass			=	rb_class_of( rb_parent_environment_or_name_string_or_symbol_or_database_controller );
		VALUE	rb_arg_ancestors	=	rb_mod_ancestors( rb_arg_klass );
		if ( rb_ary_includes(	rb_arg_ancestors,
													rb_RPDB_DatabaseController ) == Qtrue )	{

			rb_parent_database_controller	=	rb_parent_environment_or_name_string_or_symbol_or_database_controller;
		}
		else if ( rb_ary_includes(	rb_arg_ancestors,
																rb_RPDB_Environment ) == Qtrue )	{
			
			rb_parent_environment					=	rb_parent_environment_or_name_string_or_symbol_or_database_controller;
		}
	}
	//	if we have only a name, try to get a default environment
	else {
		
		rb_parent_environment					=	rb_RPDB_defaultEnvironment( rb_mRPDB );
	}
	
	//	Raise exceptions if we can't find a parent database controller
	if (		rb_parent_database_controller == Qnil )	{
		
		if ( rb_parent_environment == Qnil )	{
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND );
		}
		else {
			rb_parent_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		}
		
		if ( rb_parent_database_controller == Qnil )	{
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_MESSAGE_DATABASE_CONTROLLER_NOT_FOUND );
		}
	}

	/*------------------------------------------------------*/

	RPDB_DatabaseController*	c_parent_database_controller;
	char*	c_database_name		=	NULL;
	if ( rb_database_name != Qnil )	{
		rb_database_name	=	rb_obj_as_string( rb_database_name );
		c_database_name	=	StringValuePtr( rb_database_name );
	}
	C_RPDB_DATABASE_CONTROLLER( rb_parent_database_controller, c_parent_database_controller );
	
	RPDB_Database*	c_database	=	RPDB_DatabaseController_newDatabase(	c_parent_database_controller,
																																			c_database_name );
	
	VALUE	rb_database	=	RUBY_RPDB_DATABASE( c_database );

	//	store reference to parent database controller
	rb_iv_set(	rb_database,
							RPDB_RUBY_CLASS_DATABASE_VARIABLE_DATABASE_CONTROLLER,
							rb_parent_database_controller );

	return rb_database;	
}

/*********
*  init  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_class.html
VALUE rb_RPDB_Database_init(	int			argc __attribute__((unused)),
															VALUE*	args __attribute__((unused)),
															VALUE		rb_database_self )	{
		
	return rb_database_self;
}

/***********************
*  settingsController  *
***********************/
VALUE rb_RPDB_Database_settingsController( VALUE	rb_database )	{

	VALUE	rb_local_database_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_settings_controller = rb_iv_get(	rb_database,
																														RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_Database*		c_database;
		C_RPDB_DATABASE( rb_database, c_database );
	
		RPDB_DatabaseSettingsController*	c_local_database_settings_controller	=	RPDB_Database_settingsController( c_database );

		rb_local_database_settings_controller	=	RUBY_RPDB_DATABASE_SETTINGS_CONTROLLER( c_local_database_settings_controller );
	}

	return rb_local_database_settings_controller;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_Database_parentEnvironment(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_RPDB_Database_parentDatabaseController( rb_database );
	VALUE	rb_parent_environment					=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/*******************************
*  parent_database_controller  *
*******************************/

VALUE rb_RPDB_Database_parentDatabaseController(	VALUE	rb_database )	{

	VALUE	rb_parent_database_controller	=	rb_iv_get(	rb_database,
																										RPDB_RUBY_CLASS_DATABASE_VARIABLE_DATABASE_CONTROLLER );

	return rb_parent_database_controller;
}

/*******************************************************************************************************************************************************************************************
																		Actions
*******************************************************************************************************************************************************************************************/

/*************
*  filename  *
*************/

VALUE rb_RPDB_Database_filename( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return rb_str_new2( RPDB_Database_filename( c_database ) );	
}

/*********
*  name  *
*********/

VALUE rb_RPDB_Database_name( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return rb_str_new2( RPDB_Database_name( c_database ) );	
}

/***********
*  rename  *
***********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_rename.html
VALUE rb_RPDB_Database_rename(	VALUE	rb_database,
																VALUE	rb_name	)	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	rb_name	=	rb_obj_as_string( rb_name );

	char*	c_name	=	StringValuePtr( rb_name );

	RPDB_Database_rename(	c_database,
												c_name );
						
	return rb_database;
}

/***********
*  handle  *
***********/

VALUE rb_RPDB_Database_handle( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return ID2SYM( rb_intern( RPDB_Database_name( c_database ) ) );	
}

/************
*  open  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_open.html
VALUE rb_RPDB_Database_open( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_open( c_database );

	return rb_database;
}

/*************
*  is_open?  *
*************/

VALUE rb_RPDB_Database_isOpen( VALUE	rb_database )	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );
	
	if ( RPDB_Database_isOpen( c_database ) )	{
		return Qtrue;
	}
	
	return Qfalse;
}

/*************
*  close  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_close.html
VALUE rb_RPDB_Database_close( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_close( c_database );

	return rb_database;
}

/**********
*  empty  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_truncate.html
VALUE rb_RPDB_Database_empty( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_empty( c_database );

	return rb_database;
}

/**********
*  erase  *
**********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_remove.html
VALUE rb_RPDB_Database_erase( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_erase( c_database );

	return rb_database;
}

/*********
*  copy  *
*********/

//	Duplicate in Same Environment (requires resetIDs)
	/*
VALUE rb_RPDB_Database_copy( VALUE	rb_database )	{
	RPDB_Database_copy();

	//	Copy database file or logical db
	//	reset IDs
	//	return new name
}
*/

/********************************
*  copy_to_foreign_environment  *
********************************/

//	Copy to Foreign Environment (requires log.resetLSN)	
	/*
VALUE rb_RPDB_Database_copyToForeignEnvironment( VALUE	rb_database )	{
	RPDB_Database_copyToForeignEnvironment();

	//	copy database file or logical db
	//	reset LSN
	//	add to new environment
	//	return new name
}
*/

/*********
*  sync  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_sync.html
VALUE rb_RPDB_Database_sync( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Database_sync( c_database );

	return rb_database;	
}

/**************
*  associate  *
**************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_associate.html
//
//	Note that it is not safe to associate as a secondary database a name that is in use by another thread of control or has open cursors.
//
//	The callback parameter is a callback function that creates the set of secondary keys corresponding to a given primary key and data pair.
//
//	Callback can return:
//	- DB_DBT_APPMALLOC
//	- DB_DBT_MULTIPLE
//	- DB_DONOTINDEX
//
//	Secondary indices can be created manually by the application; there is no disadvantage, other than complexity, to doing so. 
//	However, when the secondary key can be mechanically derived from the primary key and datum that it points to, as is frequently the case, 
//	Berkeley DB can automatically and transparently manage secondary indices.
//
//	After a DB->associate call is made, the secondary indices become alternate interfaces to the primary database. 
//	All updates to the primary will be automatically reflected in each secondary index that has been associated with it.
//
//	It is generally unsafe, but not forbidden by Berkeley DB, to modify a database that has secondary indices without having those indices open and associated.
//	Similarly, it is generally unsafe, but not forbidden, to modify a secondary index directly. 
//	
//	If a secondary index becomes outdated for any reason, it should be discarded using the DB->remove method and a new one created using the DB->associate method. 
//	If a secondary index is no VALUEer needed, all of its names should be closed using the DB->close method, and then the database should be removed 
//	using a new database name and the DB->remove method.
//
//	Closing a primary database name automatically dis-associates all secondary database names associated with it.
VALUE rb_RPDB_Database_associateSecondaryDatabase(	VALUE		rb_primary_database, 
													VALUE		rb_secondary_database )	{

	RPDB_Database*		c_primary_database;
	C_RPDB_DATABASE( rb_primary_database, c_primary_database );

	RPDB_Database*		c_secondary_database;
	C_RPDB_DATABASE( rb_secondary_database, c_secondary_database );

	RPDB_Database_associateSecondaryDatabase(	c_primary_database,
	 																					c_secondary_database	);

	//	Returns primary database so associations can be chained
	return rb_primary_database;
}

/*****************
*  is_secondary  *
*****************/

VALUE rb_RPDB_Database_isSecondary(	VALUE	rb_database )	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return ( RPDB_Database_isSecondary( c_database )	?	Qtrue 
																										:	Qfalse );
}

/***********************************************
*  set_secondary_key_creation_callback_method  *
***********************************************/

VALUE rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod(	int	argc, 
																VALUE*	args,
																VALUE	rb_secondary_database	)	{

	RPDB_Database*		c_secondary_database;
	C_RPDB_DATABASE( rb_secondary_database, c_secondary_database );

	//	We need to save the callback object and method
	//	We expect this signature:
	//		VALUE			rb_secondary_database, 
	//  	const VALUE		rb_key, 
	//  	const VALUE		rb_data, 
	//  	VALUE			rb_return_data
	
	//	When an insert is made we need our RPDB callback to call the Ruby RPDB callback
	//	our Ruby RPDB callback calls the ruby method that has been specified and returns it to RPDB
	RPDB_Database_setSecondaryKeyCreationCallbackMethod(	c_secondary_database,
																												& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );

	//	Now we need to make sure that we have our appropriate info when we reach our internal callback
	
	//	2 args: callback object, callback method in object
	if ( argc == 2 )	{

		rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																																													rb_intern( "name" ),
																																													0 ),
																																							args[ 0 ],
																																							args[ 1 ] );
	}
	//	1 arg: callback method in self (database)
	else if ( argc == 1 )	{
		
		rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																																													rb_intern( "name" ),
																																													0 ),
																																							rb_secondary_database,
																																							args[ 1 ] );		
	}
	
	//	Returns the database
	return rb_secondary_database;
}

/***************************************
*  secondaryKeyCreationCallbackMethod  *
***************************************/

VALUE rb_RPDB_Database_secondaryKeyCreationCallbackMethod(	VALUE	rb_secondary_database )	{

	//	get the hash of callback info (callback object, callback method in object)
	return rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																																														rb_intern( "name" ),
																																														0 ) );
}

/***************************
*  create_secondary_index  *
***************************/

VALUE rb_RPDB_Database_createSecondaryIndex(	int	argc, 
												VALUE*	args,
												VALUE	rb_self	)	{

	//	We need to save the callback object and method
	//	We expect this signature:
	//		VALUE			rb_secondary_database, 
	//  	const VALUE		rb_key, 
	//  	const VALUE		rb_data, 
	//  	VALUE			rb_return_secondary_key

	//	1 arg:
	//		* callback method in primary database
	//	2 args: 
	//		* secondary database, callback method in secondary database
	//		* index name, callback method in primary database
	//	3 args: 
	//		* secondary database, index name, callback method in secondary database
	//		* index name, callback object, callback method in callback object
	//	4 args:
	//		* secondary database, index name, callback object, callback method in callback object

	RPDB_Database*		c_primary_database;
	C_RPDB_DATABASE( rb_self, c_primary_database );
	
	RPDB_Database*		c_secondary_database	=	NULL;
	VALUE				rb_secondary_database	=	Qnil;
	
	switch ( argc ) {

		case 1:
			{
			//	1 arg:
			//		* callback method in secondary database (implied by name of method)

			VALUE	rb_secondary_database_callback_method	=	args[ 0 ];

			VALUE	rb_index_name	=	rb_secondary_database_callback_method;

			if ( TYPE( rb_index_name ) == T_SYMBOL )	{
				
				rb_index_name	=	rb_obj_as_string( rb_index_name );
			}
			
			c_secondary_database	=	RPDB_Database_internal_createDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																													StringValuePtr( rb_index_name ),
																													FALSE );
			
			VALUE	rb_primary_database	= RUBY_RPDB_DATABASE( c_secondary_database );
				
			if ( TYPE( rb_secondary_database_callback_method ) == T_STRING )	{
				
				rb_secondary_database_callback_method	=	rb_to_id( rb_secondary_database_callback_method );
			}
				
			rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																									rb_intern( "name" ),
																									0 ),
																						rb_primary_database,
																						rb_secondary_database_callback_method );
			
			RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
																StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			break;
		case 2:
			
			//	2 args: 
			//		* secondary database, callback method in secondary database
			if (	TYPE( args[ 0 ] ) == T_DATA )	{
				
				rb_secondary_database					=	args[ 0 ];
				VALUE	rb_secondary_database_callback_method	=	args[ 1 ];
				VALUE	rb_index_name							=	rb_secondary_database_callback_method;
				
				if ( TYPE( rb_index_name ) == T_SYMBOL )	{
					
					rb_index_name	=	rb_obj_as_string( rb_index_name );
				}
								
				if ( TYPE( rb_secondary_database_callback_method ) == T_STRING )	{
					
					rb_secondary_database_callback_method	=	rb_to_id( rb_secondary_database_callback_method );
				}

				RUBY_RPDB_DATABASE( c_secondary_database );
				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																										rb_intern( "name" ),
																										0 ),
																							rb_secondary_database,
																							rb_secondary_database_callback_method );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
																StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
				
			}
			//	2 args: 
			//		* callback object, callback method in object
			else if (	TYPE( args[ 0 ] ) == T_OBJECT
					 ||	TYPE( args[ 0 ] ) == T_CLASS ) {

				VALUE	rb_callback_object						=	args[ 0 ];
				VALUE	rb_callback_method_in_callback_object	=	args[ 1 ];
				VALUE	rb_index_name							=	rb_callback_method_in_callback_object;
				
				if ( TYPE( rb_index_name ) == T_SYMBOL )	{
					
					rb_index_name	=	rb_obj_as_string(	rb_index_name );
				}
				
				if ( TYPE( rb_callback_method_in_callback_object ) == T_STRING )	{
					
					rb_callback_method_in_callback_object	=	rb_to_id( rb_callback_method_in_callback_object );
				}
				
				c_secondary_database	=	RPDB_Database_internal_createDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																																StringValuePtr( rb_index_name ),
																																FALSE );
																														
				rb_secondary_database	=	RUBY_RPDB_DATABASE( c_secondary_database );
				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																									   rb_intern( "name" ),
																									   0 ),
																							rb_callback_object,
																							rb_callback_method_in_callback_object );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
															   c_secondary_database,
															   StringValuePtr( rb_index_name ),
															   & rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
				
			}

			//		* index name, callback method in primary database
			else	{
			
				VALUE	rb_index_name							=	args[ 0 ];
				VALUE	rb_secondary_database_callback_method	=	args[ 1 ];
					
				if ( TYPE( rb_secondary_database_callback_method ) == T_STRING )	{
					
					rb_secondary_database_callback_method	=	rb_to_id( rb_secondary_database_callback_method );
				}
				
				if ( TYPE( rb_index_name ) == T_SYMBOL )	{
					
					rb_index_name	=	rb_obj_as_string(	rb_index_name );
				}
				
				c_secondary_database	=	RPDB_Database_internal_createDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																																StringValuePtr( rb_index_name ),
																																FALSE );
				
				VALUE	rb_primary_database	=	RUBY_RPDB_DATABASE( c_secondary_database );
				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																										rb_intern( "name" ),
																										0 ),
																							rb_primary_database,
																							rb_secondary_database_callback_method );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
																StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			
			break;
		case 3:
			
			//	3 args: 
			//		* secondary database, index name, callback method in secondary database
			if ( TYPE( args[ 0 ] ) == T_DATA  )	{
			
				rb_secondary_database					=	args[ 0 ];
				VALUE	rb_index_name							=	args[ 1 ];
				VALUE	rb_secondary_database_callback_method	=	args[ 2 ];
				
				if ( TYPE( rb_secondary_database_callback_method ) == T_STRING )	{
					
					rb_secondary_database_callback_method	=	rb_to_id( rb_secondary_database_callback_method );
				}
				
				if ( TYPE( rb_index_name ) == T_SYMBOL )	{
					
					rb_index_name	=	rb_obj_as_string(	rb_index_name );
				}
				
				RUBY_RPDB_DATABASE( c_secondary_database );
				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																										rb_intern( "name" ),
																										0 ),
																							rb_secondary_database,
																							rb_secondary_database_callback_method );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
																StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			//		* index name, callback object, callback method in callback object
			else {
				
				VALUE	rb_index_name							=	args[ 0 ];
				VALUE	rb_callback_object						=	args[ 1 ];
				VALUE	rb_callback_method_in_callback_object	=	args[ 2 ];
				
				if ( TYPE( rb_callback_method_in_callback_object ) == T_STRING )	{
					
					rb_callback_method_in_callback_object	=	rb_to_id( rb_callback_method_in_callback_object );
				}
				
				if ( TYPE( rb_index_name ) == T_SYMBOL )	{
					
					rb_index_name	=	rb_obj_as_string(	rb_index_name );
				}

				c_secondary_database	=	RPDB_Database_internal_createDatabaseInstanceForSecondaryIndexOnPrimaryDatabase(	c_primary_database,
																														StringValuePtr( rb_index_name ),
																														FALSE );
				
				RUBY_RPDB_DATABASE( c_secondary_database );
				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																										rb_intern( "name" ),
																										0 ),
																							rb_callback_object,
																							rb_callback_method_in_callback_object );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
												StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}

			
			break;
		case 4:
			{
			//	4 args:
			//		* secondary database, index name, callback object, callback method in callback object
			
			rb_secondary_database					=	args[ 0 ];
			VALUE	rb_index_name							=	args[ 1 ];
			VALUE	rb_callback_object						=	args[ 2 ];
			VALUE	rb_callback_method_in_callback_object	=	args[ 3 ];
			
			if ( TYPE( rb_callback_method_in_callback_object ) == T_STRING )	{
				
				rb_callback_method_in_callback_object	=	rb_to_id( rb_callback_method_in_callback_object );
			}
				
			if ( TYPE( rb_index_name ) == T_SYMBOL )	{
				
				rb_index_name	=	rb_obj_as_string(	rb_index_name );
			}
			
			RUBY_RPDB_DATABASE( c_secondary_database );
				
			VALUE	rb_secondary_db_name	=	rb_funcall(	rb_secondary_database,
																								rb_intern( "name" ),
																								0 );
			rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_secondary_db_name,
																																								rb_callback_object,
																																								rb_callback_method_in_callback_object );
			
			RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																											c_secondary_database,
																											StringValuePtr( rb_index_name ),
																											& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			break;
	}

	//	Returns the database
	return rb_self;	
}

/*****************************************
*  create_secondary_index_with_database  *
*****************************************/

VALUE rb_RPDB_Database_createSecondaryIndexWithDatabase(	int	argc, 
																													VALUE*	args,
																													VALUE	rb_self	)	{
	
	//	Args
	//	2 args:
	//		* Secondary Database, Callback in database
	//	3 args:
	//		* Secondary Database, Index Name, callback in database
	//		* Secondary Database, callback object, callback in object
	//	4 args:
	//		* Secondary Database, Index Name, callback object, callback in object

	RPDB_Database*		c_primary_database;
	C_RPDB_DATABASE( rb_self, c_primary_database );

	VALUE	rb_secondary_database		=	args[ 0 ];
	
	RPDB_Database*		c_secondary_database;
	C_RPDB_DATABASE( rb_secondary_database, c_secondary_database );
	
	switch ( argc ) {
		case 2:
			{
			//	2 args:
			//		* Secondary Database, Callback in database

			VALUE	rb_callback_in_database		=	args[ 1 ];
			VALUE	rb_index_name				=	rb_callback_in_database;

			rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																									rb_intern( "name" ),
																									0 ),
																						rb_secondary_database,
																						rb_callback_in_database );
				
			RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																c_secondary_database,
																StringValuePtr( rb_index_name ),
																& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
				
			}
			break;
		case 3:

			//	3 args:
			//		* Secondary Database, callback object, callback in object
			if ( TYPE( args[ 1 ] ) == T_OBJECT )	{

				VALUE	rb_callback_object					=	args[ 1 ];
				VALUE	rb_index_name						=	rb_callback_object;
				VALUE	rb_callback_method_in_callback_object		=	args[ 2 ];
			
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																									   rb_intern( "name" ),
																									   0 ),
																						 rb_callback_object,
																						 rb_callback_method_in_callback_object );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																	c_secondary_database,
																	StringValuePtr( rb_index_name ),
																	& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			//		* Secondary Database, Index Name, callback in database
			else	{
			
				VALUE	rb_index_name				=	args[ 1 ];
				VALUE	rb_callback_in_database		=	args[ 2 ];

				
				rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																									   rb_intern( "name" ),
																									   0 ),
																						 rb_secondary_database,
																						 rb_callback_in_database );
				
				RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
																	c_secondary_database,
																	StringValuePtr( rb_index_name ),
																	& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}
			
			break;
		case 4:

			//	4 args:
			//		* Secondary Database, Index Name, callback object, callback in object
			{
			VALUE	rb_index_name						=	args[ 1 ];
			VALUE	rb_callback_object					=	args[ 2 ];
			VALUE	rb_callback_method_in_callback_object		=	args[ 3 ];
			
				
			rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																								   rb_intern( "name" ),
																								   0 ),
																					 rb_callback_object,
																					 rb_callback_method_in_callback_object );
				
			RPDB_Database_createSecondaryIndexWithDatabase(	c_primary_database,
															c_secondary_database,
															StringValuePtr( rb_index_name ),
															& rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod );
			}	
			break;
	}
	
	return rb_self;
}	

/************
*  compact  *
************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_compact.html
VALUE rb_RPDB_Database_compact(	VALUE	rb_database, 
									VALUE	start_record, 
									VALUE	stop_record )	{
	RPDB_Database_compact();


}

VALUE rb_RPDB_Database_compactAllRecords( VALUE	rb_database )	{
	RPDB_Database_compactAllRecords();


}
*/
/****************
*  upgrade  *
****************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_upgrade.html
VALUE rb_RPDB_Database_upgrade( VALUE	rb_database )	{
	RPDB_Database_upgrade();

}
*/
/************************
*  resetDatabaseIDs  *
************************/
/*
//	For copying database and using duplicate in same environment 
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_fileid_reset.html
VALUE rb_RPDB_Database_resetDatabaseIDs( VALUE	rb_database )	{
	RPDB_Database_resetDatabaseIDs();

}
*/
/****************************************
*  prepareDatabaseForFileTransfer  *
****************************************/
/*
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_lsn_reset.html
VALUE rb_RPDB_Database_prepareDatabaseForFileTransfer( VALUE	rb_database )	{
	RPDB_Database_prepareDatabaseForFileTransfer();
	
}
*/

/***********
*  cursor  *
***********/

VALUE rb_RPDB_Database_cursor( VALUE	rb_database )	{
	return rb_RPDB_DatabaseCursorController_cursor( rb_RPDB_Database_cursorController( rb_database ) );
}	

/*************
*  cursor  *
************/

VALUE rb_RPDB_Database_objectCursor( VALUE	rb_database )	{
	return rb_RPDB_DatabaseCursorController_objectCursor( rb_RPDB_Database_cursorController( rb_database ) );
}	

/*******************************************************************************************************************************************************************************************
																		Controllers
*******************************************************************************************************************************************************************************************/

/*************************
*  cursorController  *
*************************/

VALUE rb_RPDB_Database_cursorController( VALUE	rb_database )	{

	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	return RUBY_RPDB_DATABASE_CURSOR_CONTROLLER( RPDB_Database_cursorController( c_database ) );
}

/*************************
*  joinController  *
*************************/

VALUE rb_RPDB_Database_joinController( VALUE	rb_database )	{
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );
	
	return RUBY_RPDB_DATABASE_JOIN_CONTROLLER( RPDB_Database_joinController( c_database ) );
}

/*******************************************************************************************************************************************************************************************
																		Write Actions
*******************************************************************************************************************************************************************************************/

/**********************
*  write  *
**********************/

//	It is an error to attempt a partial put using the DB->put function in a database that supports duplicate records.
//	Partial puts in databases supporting duplicate records must be done using a DBcursor->put function.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
VALUE rb_RPDB_Database_write(	VALUE	rb_database, 
								VALUE	rb_key, 
								VALUE	rb_data )	{

	//	1 arg: 
	//	*	RPDB_Record
	//	2 args:	
	//	*	RPDB_Key / RPDB_Data
	//	*	Raw Key / Raw Data
	
	RPDB_Database*		c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

	rb_RPDB_Database_internal_serializeRubyObject(	rb_key,
													c_record->key->wrapped_bdb_dbt );

	rb_RPDB_Database_internal_serializeRubyObject(	rb_data,
													c_record->data->wrapped_bdb_dbt );
	
	RPDB_Database_write(	c_database,
							c_record	);
	
	//	Returns data
	return rb_database;
}	

/**********************
*  append  *
**********************/
/*
//	DB_APPEND			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_put.html
//	Queue or Recno only
VALUE rb_RPDB_Database_append(	VALUE	rb_database,
	 											VALUE	append_record	)	{
	RPDB_Database_appendRecord();

}

*/

/*******************************************************************************************************************************************************************************************
																		Key Retrieval
*******************************************************************************************************************************************************************************************/

/*******************
*  keyExists  *
*******************/

//	returns if the specified key appears in the database
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_exists.html	
VALUE rb_RPDB_Database_keyExists(	VALUE	rb_database,
									VALUE	rb_key )	{

	RPDB_Database*						c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Key*							c_key;
	C_RPDB_KEY( rb_key, c_key );

	return ( RPDB_Database_keyExists(	c_database,
										c_key )	?	Qtrue
												:	Qfalse );
}

/*******************************************************************************************************************************************************************************************
																		Data Retrieval
*******************************************************************************************************************************************************************************************/

/*****************************
*  retrieveRecord  *
*****************************/

//	Retrieval of duplicates requires the use of database_cursor operations.
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_Database_retrieve(	int	argc, 
									VALUE*	args,
									VALUE	rb_database )	{

	//	we are always retrieving a string— even if it is a byte string

	//	1 arg: (key match)
	//	*	RPDB_Record
	//	*	Key
	//	*	Raw Key
	//	2 args: (exact pair match)
	//	*	Key / Data
	//	*	Raw Key / Raw Data

	RPDB_Database*						c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

	//	1 arg: retrieve key - key is args[ 0 ] in either case
	rb_RPDB_Database_internal_serializeRubyObject(	args[ 0 ],
													c_record->key->wrapped_bdb_dbt );
	
	if ( argc == 1 )	{
		c_record	=	RPDB_Database_retrieveRecord(	c_database,
														c_record );
	}
	
	//	2 args: retrieve specific key/data pair (to specify from duplicates)
	else if ( argc == 2 )	{
		
		rb_RPDB_Database_internal_serializeRubyObject(	args[ 1 ],
														c_record->data->wrapped_bdb_dbt );

		c_record	=	RPDB_Database_retrieveRecord(	c_database,
														c_record );
	}


	VALUE	return_value	=	rb_str_new(	(char*) RPDB_Record_rawData( c_record ),
											RPDB_Record_dataSize( c_record ) );
	
	RPDB_Record_free( & c_record );
	
	return return_value;
}

/************************************
*  retrievePartialKey  *
************************************/
/*
//	DB_SET_RANGE			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Must be Btree and it must have been created with the DB_RECNUM flag.
//	Permits partial key matches and range searches by returning the smallest item matching or including the key
VALUE rb_RPDB_Database_retrievePartialKey(	VALUE	rb_database,
 																			VALUE						partial_key )	{
	RPDB_Database_retrievePartialKey();
	
}
*/
/************************************
*  retrievePartialData  *
************************************/
/*
//	DB_GET_BOTH_RANGE		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
//	Permits partial data matches and range searches by returning the smallest item matching or including the data
VALUE rb_RPDB_Database_retrievePartialData(	VALUE	rb_database,
 																				VALUE						data )	{
	RPDB_Database_retrievePartialData();

}
*/

/**********************************************
*  retrieveMultipleObjectCursorForKey  *
**********************************************/
/*
VALUE rb_RPDB_Database_retrieveMultipleObjectCursor(	VALUE	rb_database,
 																							VALUE					data_object )	{
	RPDB_Database_retrieveMultipleObjectCursorForKey();
	
}
*/
/**************************************************
*  retrieveMultipleObjectCursorForPartialKey  *
**************************************************/
/*
VALUE rb_RPDB_Database_retrieveMultipleObjectCursorForPartialKey(	VALUE	rb_database,
 																									VALUE					data_object )	{
	RPDB_Database_retrieveMultipleObjectCursorForPartialKey();
	
}
*/
/*******************************************************************************************************************************************************************************************
																		Btree Specific
*******************************************************************************************************************************************************************************************/

/*****************************
*  relativePositionOfKey  *
*****************************/
/*

//	returns an estimate of the proportion of keys that are less than, equal to, and greater than the specified key
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_key_range.html
//	Requires Btree
RPDB_KeyRange* RPDB_Database_relativePositionOfKey(	VALUE	rb_database,
 																		VALUE	rb_key )	{


}
*/
/*******************************************************************************************************************************************************************************************
																		Queue Specific
*******************************************************************************************************************************************************************************************/

/******************
*  shiftQueue  *
******************/
	/*
//	Only relevant for Queue databases
//	DB_CONSUME				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_Database_shiftQueue( VALUE	rb_database )	{
	RPDB_Database_shiftQueue();
	
}
*/
/**************************
*  shiftQueueOrWait  *
**************************/
/*
//	Only relevant for Queue databases
//	DB_CONSUME_WAIT			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_get.html
VALUE rb_RPDB_Database_shiftQueueOrWait( VALUE	rb_database )	{
	RPDB_Database_shiftQueueOrWait();

}

*/

/*******************************************************************************************************************************************************************************************
																		Data Deletion
*******************************************************************************************************************************************************************************************/

/***************************
*  deleteDataForKey  *
***************************/

VALUE rb_RPDB_Database_delete(	int	argc, 
								VALUE*	args,
								VALUE	rb_database )	{

	//	1 arg: (key match)
	//	*	RPDB_Record
	//	*	Key
	//	*	Raw Key
	//	2 args: (exact pair match)
	//	*	Key / Data
	//	*	Raw Key / Raw Data

	RPDB_Database*						c_database;
	C_RPDB_DATABASE( rb_database, c_database );

	RPDB_Record*	c_record	=	RPDB_Record_new( c_database );

	//	1 arg: retrieve key - key is args[ 0 ] in either case
	rb_RPDB_Database_internal_serializeRubyObject(	args[ 0 ],
													c_record->key->wrapped_bdb_dbt );

	if ( argc == 1 )	{

		RPDB_Database_deleteRecord(	c_database,
		 									c_record	);
	}
	
	//	2 args: retrieve specific key/data pair (to specify from duplicates)
	else if ( argc == 2 )	{
		
		rb_RPDB_Database_internal_serializeRubyObject(	args[ 1 ],
														c_record->data->wrapped_bdb_dbt );
/*
	FIX	-	add function to support exact key/pair match for delete

		RPDB_Database_deleteDataForRawKeyDataPair(	c_database,
													c_key,
													c_key_size,
													c_data,
													c_data_size );
													*/
	}
	
	return rb_database;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

VALUE	rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database_name )	{

	if ( TYPE( rb_secondary_database_name ) == T_STRING )	{
		rb_secondary_database_name = ID2SYM( rb_to_id( rb_secondary_database_name ) );
	}
	
	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_gv_get( RPDB_GVAR_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		
		rb_callbacks_hash	=	rb_hash_new();
	}

	//	return the array of callback info (callback object, callback method in object)
	return rb_hash_aref(	rb_callbacks_hash,
							rb_secondary_database_name );
}

VALUE	rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database_name,
 																					VALUE	rb_callback_object,
																					VALUE	rb_callback_method )	{

	if ( TYPE( rb_secondary_database_name ) == T_STRING )	{
		rb_secondary_database_name = ID2SYM( rb_to_id( rb_secondary_database_name ) );
	}

	//	Get global variable 'callbacks', which stores secondary key creation callback methods
	VALUE	rb_callbacks_hash	=	rb_gv_get( RPDB_GVAR_SECONDARY_KEY_CALLBACK_METHODS );
	
	//	Make sure it's a hash - if it's not, instantiate it as a new hash
	if ( TYPE( rb_callbacks_hash ) != T_HASH )	{
		rb_callbacks_hash	=	rb_hash_new();
	}
	
	//	Create a new hash for our object and method
	VALUE	rb_new_callback_info	=	rb_hash_new();
	
	//	:object
	rb_hash_aset(	rb_new_callback_info,
					ID2SYM( rb_intern( "object" ) ),
					rb_callback_object );		
	//	:method
	rb_hash_aset(	rb_new_callback_info,
					ID2SYM( rb_intern( "method" ) ),
					rb_callback_method );

	//	Put the callback info array in the hash by database
	rb_hash_aset(	rb_callbacks_hash,
					rb_secondary_database_name,
					rb_new_callback_info );
	
	return Qnil;
}

//	This is the actual C method that gets called when a callback is set
RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod(	RPDB_Database*			c_secondary_database, 
																									RPDB_Record*			c_record, 
																									RPDB_SecondaryKeys*	c_secondary_keys )	{
	
	VALUE					rb_secondary_database;
	VALUE					rb_key;
	VALUE					rb_data;
	VALUE					rb_secondary_keys;
	
	//	Wrap up our C structures to pass to the Ruby function
	rb_secondary_database	=	RUBY_RPDB_DATABASE( c_secondary_database );
	rb_key					=	RUBY_RPDB_KEY( c_record->key );
	rb_data					=	RUBY_RPDB_DATA( c_record->data );
	rb_secondary_keys		=	RUBY_RPDB_SECONDARY_KEYS( c_secondary_keys );
	
	VALUE					rb_callback_info_hash	=	rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethodInfoHash(	rb_funcall(	rb_secondary_database,
																																			rb_intern( "name" ),
																																			0 ) );
	
	VALUE					rb_callback_object		=	rb_hash_aref(	rb_callback_info_hash,
																		ID2SYM( rb_intern( "object" ) ) );
	VALUE					rb_callback_method		=	rb_hash_aref(	rb_callback_info_hash,
																		ID2SYM( rb_intern( "method" ) ) );
	
	//	Call our ruby callback and translate returns from ruby callback to return to C function	
	//	Ruby callback expects:	secondary database, key, data
	//			  and returns:	secondary key, secondary key array, RPDB::DoNotIndex, or RPDB::ApplicationAllocatedMemory
	return FIX2INT(	rb_funcall(	rb_callback_object,
								SYM2ID( rb_callback_method ),
								4,
								rb_secondary_database,
								rb_key,
								rb_data,
								rb_secondary_keys ) );
}

void rb_RPDB_Database_internal_serializeRubyObject(	VALUE				rb_key_or_data,
														DBT*				c_key_or_data )	{
	
	long*		long_key;
	double*		double_key;
	int*		int_key;
	BOOL*		bool_key;
	
	//	FIX
	//	Maybe we want to make this function call .to_s if available or otherwise fail?
	
	//	FIX
	//	how about two modes 
	//	- C compatible (values are stored as C values; values without native correspondent must do their own translation)
	//	- Ruby (all values are marshaled and stored as Marshaled string; no translation is ever necessary)
	
	//	We need the key to be in string form
	switch ( TYPE( rb_key_or_data ) )	{
			
		case T_OBJECT:
		case T_MODULE:
		case T_HASH:
		case T_ARRAY:
        case T_STRUCT:
        case T_FILE:
        case T_DATA:
			
			//	If we marshalled data we wouldn't know how to get it back out
			//	Technically we could marshal consistently for the key, but we would never know
			//	what type of data was being stored for the key, so we wouldn't know with any 
			//	consistency how we could unmarshall it. 
			//	So for consistency's sake, neither key nor data are permitted to be objects (and thus require marshalling)
			
			//	Throw an error
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_INVALID_DATABASE_DATA );
			break;
			
		case T_STRING:
			//	simple string
			c_key_or_data->data		=	strdup( StringValuePtr(	rb_key_or_data ) );
			c_key_or_data->size		=	( RSTRING_LEN( rb_key_or_data ) + 1 ) * sizeof( char );
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
        case T_SYMBOL:
		case T_REGEXP:
		case T_CLASS:
			//	to_s will make sure it renders as a string
			rb_key_or_data			=	rb_obj_as_string(	rb_key_or_data );
			c_key_or_data->data		=	strdup( StringValuePtr(	rb_key_or_data ) );
			c_key_or_data->size		=	( RSTRING_LEN( rb_key_or_data ) + 1 ) * sizeof( char );
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
        case T_BIGNUM:
			//	to long
			long_key				=	calloc( 1, sizeof( long ) );
			*long_key				=	NUM2LONG( rb_key_or_data );
			c_key_or_data->data		=	long_key;
			c_key_or_data->size		=	sizeof( long );			
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FIXNUM:
			//	to int
			int_key					=	calloc( 1, sizeof( int ) );
			*int_key				=	FIX2INT( rb_key_or_data );
			c_key_or_data->data		=	int_key;
			c_key_or_data->size		=	sizeof( int );			
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FLOAT:
			//	to float
			double_key				=	calloc( 1, sizeof( double ) );
			*double_key				=	NUM2DBL( rb_key_or_data );
			c_key_or_data->data		=	double_key;
			c_key_or_data->size		=	sizeof( float );			
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_TRUE:
			bool_key				=	calloc( 1, sizeof( BOOL ) );
			*bool_key				=	TRUE;
			c_key_or_data->data		=	bool_key;
			c_key_or_data->size		=	sizeof( BOOL );			
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
			
		case T_FALSE:
			bool_key				=	calloc( 1, sizeof( BOOL ) );
			*bool_key				=	FALSE;
			c_key_or_data->data		=	bool_key;
			c_key_or_data->size		=	sizeof( BOOL );			
			c_key_or_data->flags	|=	DB_DBT_APPMALLOC;
			break;
	}
}

