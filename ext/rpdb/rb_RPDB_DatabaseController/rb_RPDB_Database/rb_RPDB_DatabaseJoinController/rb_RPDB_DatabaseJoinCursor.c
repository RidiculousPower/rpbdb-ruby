/*
 *		RPDB::JoinController::JoinCursor
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseJoinCursor.h"

#include "rb_RPDB_Database.h"

#include "rb_RPDB_DatabaseObject.h"
#include "rb_RPDB_DatabaseObject_internal.h"

#include <rpdb/RPDB_Environment.h>
#include <rpdb/RPDB_Database.h>

#include <rpdb/RPDB_Record.h>

#include <rpdb/RPDB_DatabaseJoinCursor.h>
#include <rpdb/RPDB_DatabaseJoinSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_RPDB_Environment;
extern	VALUE	rb_RPDB_DatabaseJoinCursor;
extern	VALUE	rb_RPDB_DatabaseJoinSettingsController;
extern	VALUE	rb_RPDB_Record;
extern	VALUE	rb_RPDB_Key;
extern	VALUE	rb_RPDB_DatabaseJoinController;
extern	VALUE	rb_RPDB_Database;
extern	VALUE	rb_RPDB_DatabaseController;

void Init_RPDB_DatabaseJoinCursor()	{
	
	rb_RPDB_DatabaseJoinCursor		=	rb_define_class_under(	rb_RPDB_DatabaseJoinController, 
																													"Cursor",				
																													rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseJoinCursor, 	"new",																	rb_RPDB_DatabaseJoinCursor_new,															-1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"initialize",														rb_RPDB_DatabaseJoinCursor_init,														-1 	);
	                                                                                          				
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"settings_controller",									rb_RPDB_DatabaseJoinCursor_settingsController,							0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"is_set_to",														"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"parent_environment",										rb_RPDB_DatabaseJoinCursor_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"parent_database",											rb_RPDB_DatabaseJoinCursor_parentDatabase,									0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"database",															"parent_database"	);
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"parent_database_join_controller",			rb_RPDB_DatabaseJoinCursor_parentDatabaseJoinController,		0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"parent_join_controller",								"parent_database_join_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinCursor, 	"join_controller",											"parent_database_join_controller"	);
                    					
	rb_define_method(						rb_RPDB_DatabaseJoinCursor, 	"each",																	rb_RPDB_DatabaseJoinCursor_iterate,													-1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinCursor_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database						=	Qnil;
	VALUE	rb_parent_database_join_controller	=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_OptionalParameter(	R_MatchAncestorInstance( rb_parent_database, rb_RPDB_Database ),
																						R_MatchAncestorInstance( rb_parent_database_join_controller, rb_RPDB_DatabaseJoinController ) ) ),
			R_ListOrder( 1 ),
			"[ <parent database > ]",
			"[ <parent database join controller> ]"
		)
	);
	
	RPDB_DatabaseJoinController*	c_parent_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_parent_database_join_controller, c_parent_join_controller );
	
	VALUE	rb_join_cursor	=	RUBY_RPDB_DATABASE_JOIN_CURSOR( RPDB_DatabaseJoinCursor_new( c_parent_join_controller ) );

	//	store reference to parent
	rb_iv_set(	rb_join_cursor,
							RPDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER,
							rb_parent_database_join_controller );

	VALUE	argv[]	=	{ rb_parent_database_join_controller };
	rb_obj_call_init(	rb_join_cursor,
										1, 
										argv );
	
	return rb_join_cursor;	
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinCursor_init(	int				argc __attribute__ ((unused)),
																				VALUE*		args __attribute__ ((unused)),
																				VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseJoinCursor_settingsController(	VALUE	rb_join_cursor )	{

	RPDB_DatabaseJoinCursor*	c_join_cursor;
	C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	return RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( RPDB_DatabaseJoinCursor_settingsController( c_join_cursor ) );
}

/***************************************
*  environment  *
***************************************/
VALUE rb_RPDB_DatabaseJoinCursor_parentEnvironment(	VALUE	rb_join_cursor )	{

	VALUE	rb_parent_join_controller					=	rb_RPDB_DatabaseJoinCursor_parentJoinController( rb_join_cursor );
	VALUE	rb_parent_database								=	rb_RPDB_DatabaseJoinController_parentDatabase( rb_parent_join_controller );
	VALUE	rb_parent_database_controller			=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
	VALUE	rb_parent_environment							=	rb_RPDB_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/***************************************
*  database  *
***************************************/
VALUE rb_RPDB_DatabaseJoinCursor_parentDatabaseController(	VALUE	rb_join_cursor )	{
	
	VALUE	rb_parent_database								=	rb_RPDB_DatabaseJoinCursor_parentDatabase( rb_join_cursor );
	VALUE	rb_parent_database_controller			=	rb_RPDB_Database_parentDatabaseController( rb_parent_database );
		
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_RPDB_DatabaseJoinCursor_parentDatabase(	VALUE	rb_join_cursor )	{
	
	VALUE	rb_parent_join_controller					=	rb_RPDB_DatabaseJoinCursor_parentDatabaseJoinController( rb_join_cursor );
	VALUE	rb_parent_database								=	rb_RPDB_DatabaseJoinController_parentDatabase( rb_parent_join_controller );
		
	return rb_parent_database;
}

/***************************************
*  parent_database_join_controller  *
*  parent_join_controller  *
***************************************/
VALUE rb_RPDB_DatabaseJoinCursor_parentDatabaseJoinController(	VALUE	rb_join_cursor )	{
	
	VALUE		rb_database_join_controller	=	rb_iv_get(	rb_join_cursor,
																										RPDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER );

	return rb_database_join_controller;
}
	
/******************
*  close  *
******************/

VALUE rb_RPDB_DatabaseJoinCursor_close( VALUE	rb_join_cursor )	{
	
	RPDB_DatabaseJoinCursor*	c_join_cursor;
	C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	RPDB_DatabaseJoinCursor_close( c_join_cursor );

	return rb_join_cursor;
}

/******************
*  retrieve  *
******************/

VALUE rb_RPDB_DatabaseJoinCursor_retrieveKey(	VALUE	rb_join_cursor,
												VALUE	rb_key	)	{

	RPDB_DatabaseJoinCursor*	c_join_cursor;
	C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	RPDB_Key*			c_key;
	C_RPDB_KEY( rb_key, c_key );

	return RUBY_RPDB_RECORD( RPDB_DatabaseJoinCursor_retrieveKey(	c_join_cursor,
																	c_key ) );
}

/******************************
*  iterate  *
******************************/

VALUE rb_RPDB_DatabaseJoinCursor_iterate(	int	argc,
											VALUE*	args,
											VALUE	rb_join_cursor )	{

	VALUE	rb_record_data	=	Qnil;
	
	//	if we have an arg it is our enumerator-passed already_iterated flags
	if ( argc )	{
		rb_record_data = args[ 0 ];
	}

	RPDB_DatabaseJoinCursor*	c_join_cursor;
	C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	RPDB_Record*	c_record	=	NULL;

	while (		rb_record_data != Qnil
		   ||	(	( c_record = RPDB_DatabaseJoinCursor_iterate( c_join_cursor ) ) != NULL ) 
				&&	( rb_record_data = rb_RPDB_DatabaseObject_internal_extractRetrievalData( c_record ) ) )	{
		
		//	If we don't have a block, we return an enumerator
		RETURN_ENUMERATOR_IF_NO_BLOCK(	rb_join_cursor,
							1,
							& rb_record_data );
		
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );	
		
		//	reset record_data so we don't create an infinite loop
		rb_record_data = Qnil;
	}	
	
	return rb_join_cursor;
}

/******************************
*  retrieveRecordNumber  *
******************************/
/*

//	Do not use the data value found in all of the cursors as a lookup key for the primary database, 
//	but simply return it in the key parameter instead. The data parameter is left unchanged.
//	For DB_JOIN_ITEM to be specified, the underlying database_cursor must have been returned from the DB->join method.
//	DB_JOIN_ITEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_RPDB_DatabaseJoinCursor_retrievePrimaryKeysForJoinData( VALUE	rb_join_cursor )	{

	RPDB_DatabaseJoinCursor*	c_join_cursor;
	C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	RPDB_DatabaseJoinCursor_retrievePrimaryKeysForJoinData( c_join_cursor );
}

*/
