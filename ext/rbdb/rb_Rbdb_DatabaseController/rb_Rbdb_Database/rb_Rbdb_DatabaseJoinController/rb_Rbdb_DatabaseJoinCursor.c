/*
 *		Rbdb::JoinController::JoinCursor
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseJoinCursor.h"
#include "rb_Rbdb_DatabaseJoinController.h"
#include "rb_Rbdb_DatabaseJoinController_internal.h"
#include "rb_Rbdb_DatabaseController.h"

#include "rb_Rbdb_Database.h"
#include "rb_Rbdb_Database_internal.h"

#include "rb_Rbdb_DatabaseObject.h"
#include "rb_Rbdb_DatabaseObject_internal.h"

#include <rbdb/Rbdb_Environment.h>
#include <rbdb/Rbdb_Database.h>

#include <rbdb/Rbdb_Record.h>

#include <rbdb/Rbdb_DatabaseJoinController.h>
#include <rbdb/Rbdb_DatabaseJoinCursor.h>
#include <rbdb/Rbdb_DatabaseJoinSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_DatabaseJoinCursor;
extern	VALUE	rb_Rbdb_DatabaseJoinSettingsController;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_Key;
extern	VALUE	rb_Rbdb_DatabaseJoinController;
extern	VALUE	rb_Rbdb_Database;
extern  VALUE rb_Rbdb_DatabaseCursor;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseJoinContainer;

void Init_rb_Rbdb_DatabaseJoinCursor()	{
		
	rb_Rbdb_DatabaseJoinCursor		=	rb_define_class_under(	rb_Rbdb_DatabaseJoinContainer, 
																													"Cursor",				
																													rb_cObject );
	
	rb_define_singleton_method(	rb_Rbdb_DatabaseJoinCursor, 	"new",																	rb_Rbdb_DatabaseJoinCursor_new,															-1 	);
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"initialize",														rb_Rbdb_DatabaseJoinCursor_initialize,														-1 	);
	                                                                                          				
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"settings_controller",									rb_Rbdb_DatabaseJoinCursor_settingsController,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"is_set_to",														"settings_controller"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"parent_environment",										rb_Rbdb_DatabaseJoinCursor_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"environment",													"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"parent_database",											rb_Rbdb_DatabaseJoinCursor_parentDatabase,									0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"database",															"parent_database"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"parent_database_join_controller",			rb_Rbdb_DatabaseJoinCursor_parentDatabaseJoinController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"parent_join_controller",								"parent_database_join_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinCursor, 	"join_controller",											"parent_database_join_controller"	);
                    					
	rb_define_method(						rb_Rbdb_DatabaseJoinCursor, 	"each",																	rb_Rbdb_DatabaseJoinCursor_iterate,													-1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseJoinCursor_new(	int			argc,
																			VALUE*	args,
																			VALUE		rb_klass_self __attribute__ ((unused)) )	{
	
	VALUE	rb_parent_database                  =	Qnil;
	VALUE	rb_parent_database_join_controller	=	Qnil;
  VALUE rb_first_cursor                     = Qnil;
  VALUE rb_hash_descriptor_for_join         = Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(	R_Parameter(          R_MatchAncestorInstance(  rb_parent_database,                   rb_Rbdb_Database ),
                                            R_MatchAncestorInstance(  rb_parent_database_join_controller,   rb_Rbdb_DatabaseJoinController ) ),
                      R_Parameter(          R_MatchHash(              rb_hash_descriptor_for_join,
                                                                      R_HashKey( R_Symbol() ),
                                                                      NULL ),
                                            R_MatchAncestorInstance(  rb_first_cursor,                      rb_Rbdb_DatabaseCursor ) ) ),
			R_ListOrder( 1 ),
			":index => key, ...",
			"<database cursor>, ...",
			"[ <parent database > ], :index => key, ...",
			"[ <parent database > ], <database cursor>, ...",
			"[ <parent database > ], <database cursor>, :index => key, ...",
			"[ <parent database join controller> ], :index => key, ..."
			"[ <parent database join controller> ], <database cursor>, ..."
			"[ <parent database join controller> ], <database cursor>, :index => key, ..."
		)
	);

  if ( rb_parent_database != Qnil ) {
    rb_parent_database_join_controller  = rb_Rbdb_Database_joinController( rb_parent_database );
  }

  int     argc_without_parent = argc - 1;
  VALUE*  args_without_parent = args + 1;

  VALUE rb_cursors_for_join = rb_Rbdb_DatabaseJoinController_internal_getListOfCursors( argc_without_parent,
                                                                                        args_without_parent,
                                                                                        rb_parent_database_join_controller );
  if ( ! RARRAY_LEN( rb_cursors_for_join ) )  {
    //  no join cursor existed for parameters
    return Qnil;
  }
    
	Rbdb_DatabaseCursor**	c_cursor_list	=	calloc( RARRAY_LEN( rb_cursors_for_join ) + 1, sizeof( Rbdb_DatabaseCursor* ) );

	int	c_which_arg	=	0;
	for ( c_which_arg = 0 ; c_which_arg < argc ; c_which_arg++ )	{

		VALUE rb_this_cursor	=	RARRAY_PTR( rb_cursors_for_join )[ c_which_arg ];
		
		//	Get c pointer to Rbdb_DatabaseCursor
		C_RBDB_DATABASE_CURSOR( rb_this_cursor, c_cursor_list[ c_which_arg ] );
	}
	
	//	cap off list with a NULL pointer
	c_cursor_list[ c_which_arg ]	=	NULL;
		
	Rbdb_DatabaseJoinController*	c_join_controller;
	C_RBDB_DATABASE_JOIN_CONTROLLER( rb_parent_database_join_controller, c_join_controller );

	Rbdb_DatabaseJoinCursor*	c_join_cursor	=	Rbdb_DatabaseJoinController_join(	c_join_controller,
																																							c_cursor_list );
							
	VALUE  rb_join_cursor   = RUBY_RBDB_DATABASE_JOIN_CURSOR( c_join_cursor );

	//	store reference to parent
	rb_iv_set(	rb_join_cursor,
							RBDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER,
							rb_parent_database_join_controller );

	rb_obj_call_init(	rb_join_cursor,
										argc, 
										args );
	
	return rb_join_cursor;	
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseJoinCursor_initialize(	int				argc __attribute__ ((unused)),
                                              VALUE*		args __attribute__ ((unused)),
                                              VALUE			rb_self )	{

	return rb_self;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_DatabaseJoinCursor_settingsController(	VALUE	rb_join_cursor )	{

	VALUE	rb_local_database_join_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_join_settings_controller = rb_iv_get(	rb_join_cursor,
																																	RBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_DatabaseJoinCursor*		c_join_cursor;
		C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );
	
		Rbdb_DatabaseJoinSettingsController*	c_local_database_join_settings_controller	=	Rbdb_DatabaseJoinCursor_settingsController( c_join_cursor );

		rb_local_database_join_settings_controller	=	RUBY_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_local_database_join_settings_controller );

		rb_iv_set(	rb_join_cursor,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER,
								rb_local_database_join_settings_controller );
	}

	return rb_local_database_join_settings_controller;
}

/***************************************
*  environment  *
***************************************/
VALUE rb_Rbdb_DatabaseJoinCursor_parentEnvironment(	VALUE	rb_join_cursor )	{

	VALUE	rb_parent_join_controller					=	rb_Rbdb_DatabaseJoinCursor_parentDatabaseJoinController( rb_join_cursor );
	VALUE	rb_parent_database								=	rb_Rbdb_DatabaseJoinController_parentDatabase( rb_parent_join_controller );
	VALUE	rb_parent_database_controller			=	rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
	VALUE	rb_parent_environment							=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );

	return rb_parent_environment;
}

/***************************************
*  database  *
***************************************/
VALUE rb_Rbdb_DatabaseJoinCursor_parentDatabaseController(	VALUE	rb_join_cursor )	{
	
	VALUE	rb_parent_database								=	rb_Rbdb_DatabaseJoinCursor_parentDatabase( rb_join_cursor );
	VALUE	rb_parent_database_controller			=	rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
		
	return rb_parent_database_controller;
}

/***************************************
*  parent_database  *
***************************************/
VALUE rb_Rbdb_DatabaseJoinCursor_parentDatabase(	VALUE	rb_join_cursor )	{
	
	VALUE	rb_parent_join_controller					=	rb_Rbdb_DatabaseJoinCursor_parentDatabaseJoinController( rb_join_cursor );
	VALUE	rb_parent_database								=	rb_Rbdb_DatabaseJoinController_parentDatabase( rb_parent_join_controller );
		
	return rb_parent_database;
}

/***************************************
*  parent_database_join_controller  *
*  parent_join_controller  *
***************************************/
VALUE rb_Rbdb_DatabaseJoinCursor_parentDatabaseJoinController(	VALUE	rb_join_cursor )	{
	
	VALUE		rb_database_join_controller	=	rb_iv_get(	rb_join_cursor,
																										RBDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER );

	return rb_database_join_controller;
}
	
/******************
*  close  *
******************/

VALUE rb_Rbdb_DatabaseJoinCursor_close( VALUE	rb_join_cursor )	{
	
	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_DatabaseJoinCursor_close( c_join_cursor );

	return rb_join_cursor;
}

/******************
*  retrieve  *
******************/

VALUE rb_Rbdb_DatabaseJoinCursor_retrieveKey(	VALUE	rb_join_cursor,
                                              VALUE	rb_key	)	{

	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_Key*			c_key;
	C_RBDB_KEY( rb_key, c_key );

	return RUBY_RBDB_RECORD( Rbdb_DatabaseJoinCursor_retrieveKey(	c_join_cursor,
                                                                c_key ) );
}

/******************************
*  iterate  *
******************************/

VALUE rb_Rbdb_DatabaseJoinCursor_iterate(	int	argc,
																					VALUE*	args,
																					VALUE	rb_join_cursor )	{

	VALUE	rb_record_data	=	Qnil;
	
	//	if we have an arg it is our enumerator-passed already_iterated flags
	if ( argc )	{
		rb_record_data = args[ 0 ];
	}

	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_Record*	c_record	=	NULL;

  VALUE rb_database = rb_Rbdb_DatabaseJoinCursor_parentDatabase( rb_join_cursor );

	while (		rb_record_data != Qnil
				||	(		( c_record = Rbdb_DatabaseJoinCursor_iterate( c_join_cursor ) ) != NULL ) 
						&&	( ( ( rb_record_data = rb_Rbdb_Database_internal_unpackDBTForRubyInstance(  rb_database,
                                                                                            c_record->data,
                                                                                            FALSE ) ) != Qnil ) ) )	{
		
		//	If we don't have a block, we return an enumerator
		R_ReturnEnumeratorIfNoBlock(	1,
																	& rb_record_data,
																	rb_join_cursor);
		
		//	Otherwise we iterate the block
		rb_yield( rb_record_data );	
		
		//	reset record_data so we don't create an infinite loop
		rb_record_data = Qnil;
	}
	
	if ( c_record )	{
		Rbdb_Record_free( & c_record );
	}
	
	return rb_join_cursor;
}

/**********
*  first  *
**********/

VALUE rb_Rbdb_DatabaseJoinCursor_first(	VALUE	rb_join_cursor )	{

	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_Record*	c_record				=	Rbdb_DatabaseJoinCursor_iterate( c_join_cursor );

  VALUE rb_data	=	Qnil;
  if ( c_record->result )	{

    VALUE rb_database = rb_Rbdb_DatabaseJoinCursor_parentDatabase( rb_join_cursor );

    rb_data = rb_Rbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->data,
                                                                  FALSE );
  }

	if ( c_record )	{
		Rbdb_Record_free( & c_record );
	}
	
	return rb_data;
}

/**************
*  first_key  *
**************/

VALUE rb_Rbdb_DatabaseJoinCursor_firstKey(	VALUE	rb_join_cursor )	{

	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_Record*	c_record				=	Rbdb_DatabaseJoinCursor_iterate( c_join_cursor );

  VALUE rb_key	=	Qnil;
  if ( c_record->result )	{

    VALUE rb_database = rb_Rbdb_DatabaseJoinCursor_parentDatabase( rb_join_cursor );

    rb_key	=	rb_Rbdb_Database_internal_unpackDBTForRubyInstance( rb_database,
                                                                  c_record->key,
                                                                  TRUE );
  }
	
	if ( c_record )	{
		Rbdb_Record_free( & c_record );
	}
	
	return rb_key;
}

/******************************
*  retrieveRecordNumber  *
******************************/
/*

//	Do not use the data value found in all of the cursors as a lookup key for the primary database, 
//	but simply return it in the key parameter instead. The data parameter is left unchanged.
//	For DB_JOIN_ITEM to be specified, the underlying database_cursor must have been returned from the DB->join method.
//	DB_JOIN_ITEM			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/dbc_get.html
VALUE rb_Rbdb_DatabaseJoinCursor_retrievePrimaryKeysForJoinData( VALUE	rb_join_cursor )	{

	Rbdb_DatabaseJoinCursor*	c_join_cursor;
	C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor );

	Rbdb_DatabaseJoinCursor_retrievePrimaryKeysForJoinData( c_join_cursor );
}

*/
