/*
 *		Rbdb::JoinController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseJoinController.h"
#include "rb_Rbdb_DatabaseJoinController_internal.h"

#include "rb_Rbdb_DatabaseJoinCursor.h"

#include "rb_Rbdb_Database.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseJoinController.h>
#include <rbdb/Rbdb_DatabaseJoinCursor.h>

#include <rbdb/Rbdb_DatabaseJoinSettingsController.h>
#include <rbdb/Rbdb_DatabaseCursor.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_DatabaseJoinController;
extern	VALUE	rb_Rbdb_DatabaseJoinCursor;
extern	VALUE	rb_Rbdb_DatabaseJoinSettingsController;
extern	VALUE	rb_Rbdb_DatabaseCursor;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseJoinContainer;

void Init_rb_Rbdb_DatabaseJoinController()	{

	rb_Rbdb_DatabaseJoinContainer	=	rb_define_module_under(	rb_Rbdb_Database, "Join" );

	rb_Rbdb_DatabaseJoinController		=	rb_define_class_under(	rb_Rbdb_DatabaseJoinContainer,				
																															"Controller",		
																															rb_cObject );
	
	rb_define_singleton_method(	rb_Rbdb_DatabaseJoinController, 	"new",													rb_Rbdb_DatabaseJoinController_new,											-1 	);
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"initialize",										rb_Rbdb_DatabaseJoinController_initialize,										-1 	);
		
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"settings_controller",					rb_Rbdb_DatabaseJoinController_settingsController,			0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"settings",											"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"set",													"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"set_to",												"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"is_set_to",										"settings_controller"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"parent_environment",						rb_Rbdb_DatabaseJoinController_parentEnvironment,				0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"environment",									"parent_environment"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"parent_database",							rb_Rbdb_DatabaseJoinController_parentDatabase,					0 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"database",											"parent_database"	);
	                  					
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"join",													rb_Rbdb_DatabaseJoinController_join,										-1 	);
	rb_define_alias(						rb_Rbdb_DatabaseJoinController, 	"cursor",												"join"	);
	rb_define_method(						rb_Rbdb_DatabaseJoinController, 	"close_all_cursors",						rb_Rbdb_DatabaseJoinController_closeAllCursors,					-1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseJoinController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_database_join_controller_class __attribute__((unused)) )	{

	VALUE	rb_parent_database	=	Qnil;

	/*------------------------------------------------------*/

	VALUE	rb_parent_database_or_environment				=	Qnil;
	VALUE	rb_parent_database_name_in_environment	=	Qnil;
	rb_scan_args(	argc,
								args,
								"11",
								& rb_parent_database_or_environment,
								& rb_parent_database_name_in_environment );

	if ( rb_parent_database_name_in_environment == Qnil )	{
		rb_parent_database = rb_parent_database_or_environment;
	}
	else {
		VALUE	rb_parent_environment		=	rb_parent_database_or_environment;
		VALUE	rb_database_controller	=	rb_Rbdb_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_Rbdb_Database_new( 1,
																								& rb_database_controller,
																								rb_Rbdb_Database );
	}

	/*------------------------------------------------------*/
	
	Rbdb_Database*		c_parent_database;
	C_RBDB_DATABASE( rb_parent_database, c_parent_database );
	VALUE	rb_join_controller	=	RUBY_RBDB_DATABASE_JOIN_CONTROLLER( Rbdb_DatabaseJoinController_new( c_parent_database ) );

	//	store reference to parent
	rb_iv_set(	rb_join_controller,
							RBDB_RB_ALL_VARIABLE_PARENT_DATABASE,
							rb_parent_database );

	rb_obj_call_init(	rb_join_controller,
										1, 
										& rb_parent_database );
	
	return rb_join_controller;		
}

/*************
*  self.new  *
*************/

VALUE rb_Rbdb_DatabaseJoinController_initialize(	int			argc __attribute__ ((unused)),
																						VALUE*	args __attribute__ ((unused)),
																						VALUE		rb_join_controller )	{

	return rb_join_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_Rbdb_DatabaseJoinController_settingsController(	VALUE	rb_database_join_controller )	{

	VALUE	rb_database_join_settings_controller	=	Qnil;
	
	if ( ( rb_database_join_settings_controller = rb_iv_get(	rb_database_join_controller,
																														RBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_DatabaseJoinController*		c_database_join_controller;
		C_RBDB_DATABASE_JOIN_CONTROLLER( rb_database_join_controller, c_database_join_controller );
	
		Rbdb_DatabaseJoinSettingsController*	c_database_join_settings_controller	=	Rbdb_DatabaseJoinController_settingsController( c_database_join_controller );

		rb_database_join_settings_controller	=	RUBY_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller );

		rb_iv_set(	rb_database_join_controller,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER,
								rb_database_join_settings_controller );
	}

	return rb_database_join_settings_controller;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_Rbdb_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller )	{

	VALUE	rb_parent_database	=	rb_Rbdb_DatabaseJoinController_parentDatabase( rb_join_controller );
	
	VALUE	rb_parent_environment	=	rb_Rbdb_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_Rbdb_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller )	{
	
	VALUE	rb_parent_database	=		rb_iv_get(	rb_join_controller,
																						RBDB_RB_ALL_VARIABLE_PARENT_DATABASE );
	return rb_parent_database;
}

/****************
*  join         *
*  join_cursor  *
*  cursor       *
****************/

//	args:
//		:index => value, ...
//		positioned cursor, ...
//	if there are multiple hashes, multiple join cursors will be returned
//	if there is one hash and one or more cursors, they will be joined
//	if there is more than one hash with one or more cursors, an error will be thrown
//	arrays will be treated as groups, so ( [ hash, cursor ], hash ) is a valid set 
//		of arguments, which will return 2 join cursors
VALUE rb_Rbdb_DatabaseJoinController_join(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller )	{

  int     c_passed_argc               = argc + 1;
  VALUE   c_passed_args[ argc + 1 ];

  c_passed_args[ 0 ]  = rb_join_controller;

  int     c_which_arg  =  0;
  for ( c_which_arg = 0 ; c_which_arg < argc ; c_which_arg++ )  {
    c_passed_args[ c_which_arg + 1 ] = args[ c_which_arg ];
  }

  VALUE	rb_join_cursor	=	rb_Rbdb_DatabaseJoinCursor_new(	c_passed_argc,
                                                          c_passed_args,
                                                          rb_join_controller );

	return rb_join_cursor;
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_Rbdb_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller )	{

	Rbdb_DatabaseJoinController*	c_join_controller;
	C_RBDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );

	Rbdb_DatabaseJoinController_closeAllCursors( c_join_controller );

	return rb_join_controller;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

static int rb_Rbdb_DatabaseCursorController_internal_cursorsForEachHashDescriptor(	VALUE	rb_key_method_symbol,
																																										VALUE	rb_key_value,
																																										VALUE	rb_passed_args );

/******************************************
*  cursorsForHashDescriptor  *
******************************************/

VALUE rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	VALUE	rb_database_join_controller,
																																		VALUE	rb_hash_descriptor )	{

  VALUE rb_primary_database = rb_Rbdb_DatabaseJoinController_parentDatabase( rb_database_join_controller );

	//	args to pass to foreach
	VALUE	rb_passed_args	=	rb_ary_new();
	rb_ary_push(	rb_passed_args,
								rb_primary_database );

	//	foreach item (once): 
	rb_hash_foreach(	rb_hash_descriptor, 
										& rb_Rbdb_DatabaseCursorController_internal_cursorsForEachHashDescriptor,
										rb_passed_args );
	
	//	our cursor array is our passed args array minus the first index (rb_primary_database)
	VALUE	rb_cursor_array	=	rb_passed_args;
	//	chop off rb_primary_database and we have our cursor array
	rb_ary_shift( rb_cursor_array );

	//	If the last element in our array is false, one of the cursors failed to retrieve (record didn't exist)
	if ( RARRAY_PTR( rb_cursor_array )[ RARRAY_LEN( rb_cursor_array ) - 1 ] == Qfalse )	{
    //  first, free any cursors we created
    int c_which_cursor = 0;
    for ( c_which_cursor = 0 ; c_which_cursor < RARRAY_LEN( rb_cursor_array ) - 1 ; c_which_cursor++ )  {
      
      VALUE rb_this_database_cursor = RARRAY_PTR( rb_cursor_array )[ c_which_cursor ];
      
      Rbdb_DatabaseCursor*	c_this_database_cursor;
      C_RBDB_DATABASE_CURSOR( rb_this_database_cursor, c_this_database_cursor );
      Rbdb_DatabaseCursor_free( & c_this_database_cursor );
      
    }
		//	then we return Qnil because this join wasn't possible
		//	we had a hash + cursors, so we have no other args for this iteration
		//	if this iteration is one of multiple, this nil will get inserted into the return array of the calling iteration
		return Qnil;
	}
	
	return rb_cursor_array;
}	

/****************************************************
*  cursorsForEachHashDescriptor  *
***************************************************/

//	rb_passed_args should end up with 1 element (rb_self) + 1 element (idx-idx string) + # of elements in hash
static int rb_Rbdb_DatabaseCursorController_internal_cursorsForEachHashDescriptor(	VALUE	rb_key_method_symbol,
																																										VALUE	rb_key_value,
																																										VALUE	rb_passed_args )	{
	
	VALUE	rb_primary_database	=	rb_ary_entry( rb_passed_args, 0 );

	//	make sure we have symbols rather than strings for our key
	if ( TYPE( rb_key_method_symbol ) == T_STRING )	{
		rb_key_method_symbol	=	STRING2SYM( rb_key_method_symbol );
	}
	
	VALUE	rb_cursor				=	rb_Rbdb_DatabaseJoinController_internal_cursorForIndexAtKeyValue(	rb_primary_database,
																																														rb_key_method_symbol,
																																														rb_key_value );
	
	//	If we get no record for setting our cursor we push false and fail
	if ( rb_cursor == Qnil )	{    
		rb_ary_push(	rb_passed_args,
									Qfalse );
		return ST_STOP;
	}

	
	//	push cursor for return - we always do this (if we have a cursor) so that cleanup can occur afterward if join was not possible
	rb_ary_push(	rb_passed_args,
								rb_cursor );

  //  we call through ruby so subclass support is implicit
  //  this is important, for instance, if we want :current to automatically unserialize
	VALUE	rb_current_record		=	rb_funcall( rb_cursor,
																					rb_intern( "current" ),
																					0 );

	//	If we get no record for setting our cursor we push false and fail
	if ( rb_current_record == Qnil )	{
		rb_ary_push(	rb_passed_args,
									Qfalse );
		return ST_STOP;
	}

	return ST_CONTINUE;
}

/******************************************
*  cursorForIndexAtKeyValue  *
******************************************/

VALUE rb_Rbdb_DatabaseJoinController_internal_cursorForIndexAtKeyValue(	VALUE	rb_primary_database,
																																				VALUE	rb_index_name,
																																				VALUE	rb_key_value  )	{
		
	VALUE	rb_secondary_database	=	rb_Rbdb_Database_requireSecondaryDatabaseWithIndex(	rb_primary_database,
																																										rb_index_name );
	
	Rbdb_Database*		c_primary_database;
	C_RBDB_DATABASE( rb_primary_database, c_primary_database );
	Rbdb_Database*		c_secondary_database;
	C_RBDB_DATABASE( rb_secondary_database, c_secondary_database );

  //  we call through ruby so subclass support is implicit
  //  this is important, for instance, if we want :current to automatically unserialize
	VALUE	rb_database_cursor	=	rb_funcall(	rb_secondary_database,
																					rb_intern( "cursor" ),
																					0 );

	//	FIX - we probably want to add a method (perhaps a block) that gets called here that can be overridden for settings, etc.
	
	//	set cursor to requested first record
	//	again, we call via rb_funcall so that the class determines whether or not to use Rbdb_DatabaseCursor or Rbdb_DatabaseObjectCursor
	VALUE	rb_current	=	rb_funcall(	rb_database_cursor,
																	rb_intern( "retrieve" ),
																	1,
																	rb_key_value );

	//	if we get a nil result it means we have no such key in the db
  //  since we may have opened cursors already we need to let our caller know that it should free them
	if ( rb_current == Qnil )   {		
		Rbdb_DatabaseCursor*	c_database_cursor;
		C_RBDB_DATABASE_CURSOR( rb_database_cursor, c_database_cursor );
		Rbdb_DatabaseCursor_free( & c_database_cursor );
		rb_database_cursor	=	Qnil;
	}
	
	return rb_database_cursor;
}

/*********************
*  getListOfCursors  *
*********************/

VALUE rb_Rbdb_DatabaseJoinController_internal_getListOfCursors( int      argc,
                                                                VALUE*   args,
                                                                VALUE    rb_join_controller __attribute__ ((unused)) ) {

  VALUE rb_first_cursor       = Qnil;
  VALUE rb_descriptor_hash    = Qnil;
	R_DefineAndParse( argc, args, rb_join_controller,
		R_DescribeParameterSet(
			R_ParameterSet(	R_Parameter(          R_MatchAncestorInstance(  rb_first_cursor,                    rb_Rbdb_DatabaseCursor ),
                                            R_MatchHash(              rb_descriptor_hash,
                                                                      R_HashKey( R_Any() ),
                                                                      R_HashData( R_Any() ) ) ) ),
			R_ListOrder( 1 ),
			":index => key, ...",
			"<database cursor>, ...",
			"<database cursor>, ..., :index => key, ..."
		)
	);

  VALUE rb_cursors_for_join   = rb_ary_new();

  if ( rb_first_cursor != Qnil )  {
    rb_ary_push(  rb_cursors_for_join,
                  rb_first_cursor );
  }
  
  //  if we don't have a hash yet then we have cursors (we may still have a hash)
  if ( rb_descriptor_hash == Qnil ) {

    VALUE rb_next_cursor_or_hash  = Qnil;
    while ( R_Arg( rb_next_cursor_or_hash ) ) {

      if ( TYPE( rb_next_cursor_or_hash ) == T_HASH ) {
        rb_descriptor_hash  = rb_next_cursor_or_hash;
        break;
      }
      else  {
        rb_ary_push(  rb_cursors_for_join,
                      rb_next_cursor_or_hash );
      }

    }
    
  }

  if ( rb_descriptor_hash != Qnil ) {
    VALUE rb_cursors_from_hash_descriptor = rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	rb_join_controller,
                                                                                                          rb_descriptor_hash );
    if ( rb_cursors_from_hash_descriptor != Qnil )  {
    
      //  if we have hash descriptor, get corresponding cursors
      rb_cursors_for_join = rb_ary_concat(  rb_cursors_for_join,
                                            rb_cursors_from_hash_descriptor );
    }
  }  

  return rb_cursors_for_join;
}
