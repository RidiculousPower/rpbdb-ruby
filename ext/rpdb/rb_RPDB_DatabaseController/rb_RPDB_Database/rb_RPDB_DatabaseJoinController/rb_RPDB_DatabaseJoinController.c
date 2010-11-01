/*
 *		RPDB::JoinController
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_RPDB_DatabaseJoinController.h"
#include "rb_RPDB_DatabaseJoinController_internal.h"

#include "rb_RPDB_Database.h"

#include <rpdb/RPDB_Environment.h>

#include <rpdb/RPDB_Database.h>
#include <rpdb/RPDB_DatabaseJoinController.h>
#include <rpdb/RPDB_DatabaseJoinCursor.h>

#include <rpdb/RPDB_DatabaseJoinSettingsController.h>
#include <rpdb/RPDB_DatabaseCursor.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

VALUE	extern	rb_RPDB_Environment;
VALUE	extern	rb_RPDB_DatabaseJoinController;
VALUE	extern	rb_RPDB_DatabaseJoinCursor;
VALUE	extern	rb_RPDB_DatabaseJoinSettingsController;
VALUE	extern	rb_RPDB_DatabaseCursor;
VALUE	extern	rb_RPDB_Database;

void Init_RPDB_DatabaseJoinController()	{

	rb_RPDB_DatabaseJoinController		=	rb_define_class_under(	rb_RPDB_Database,				
																															"JoinController",				
																															rb_cObject );
	
	rb_define_singleton_method(	rb_RPDB_DatabaseJoinController, 	"new",													rb_RPDB_DatabaseJoinController_new,											-1 	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"initialize",										rb_RPDB_DatabaseJoinController_init,										-1 	);
		
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"settings_controller",					rb_RPDB_DatabaseJoinController_settingsController,			0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"settings",											"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"set",													"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"set_to",												"settings_controller"	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"is_set_to",										"settings_controller"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"parent_environment",						rb_RPDB_DatabaseJoinController_parentEnvironment,				0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"environment",									"parent_environment"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"parent_database",							rb_RPDB_DatabaseJoinController_parentDatabase,					0 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"database",											"parent_database"	);
	                  					
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"join",													rb_RPDB_DatabaseJoinController_join,										-1 	);
	rb_define_alias(						rb_RPDB_DatabaseJoinController, 	"cursor",												"join"	);
	rb_define_method(						rb_RPDB_DatabaseJoinController, 	"close_all_cursors",						rb_RPDB_DatabaseJoinController_closeAllCursors,					-1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinController_new(	int			argc,
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
		VALUE	rb_database_controller	=	rb_RPDB_Environment_databaseController( rb_parent_environment );
		rb_parent_database	=	rb_RPDB_Database_new( 1,
																								& rb_database_controller,
																								rb_RPDB_Database );
	}

	/*------------------------------------------------------*/
	
	RPDB_Database*		c_parent_database;
	C_RPDB_DATABASE( rb_parent_database, c_parent_database );
	VALUE	rb_join_controller	=	RUBY_RPDB_DATABASE_JOIN_CONTROLLER( RPDB_DatabaseJoinController_new( c_parent_database ) );

	rb_iv_set(	rb_join_controller,
							RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE,
							rb_parent_database );

	rb_obj_call_init(	rb_join_controller,
										1, 
										& rb_parent_database );
	
	return rb_join_controller;		
}

/************
*  new  *
************/

VALUE rb_RPDB_DatabaseJoinController_init(	int			argc __attribute__ ((unused)),
																						VALUE*	args __attribute__ ((unused)),
																						VALUE		rb_join_controller )	{

	return rb_join_controller;
}

/***************************
*  settingsController  *
***************************/
VALUE rb_RPDB_DatabaseJoinController_settingsController(	VALUE	rb_database_join_controller )	{

	VALUE	rb_database_join_settings_controller	=	Qnil;
	
	if ( ( rb_database_join_settings_controller = rb_iv_get(	rb_database_join_controller,
																														RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPDB_DatabaseJoinController*		c_database_join_controller;
		C_RPDB_DATABASE_JOIN_CONTROLLER( rb_database_join_controller, c_database_join_controller );
	
		RPDB_DatabaseJoinSettingsController*	c_database_join_settings_controller	=	RPDB_DatabaseJoinController_settingsController( c_database_join_controller );

		rb_database_join_settings_controller	=	RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller );

		rb_iv_set(	rb_database_join_controller,
								RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER,
								rb_database_join_settings_controller );
	}

	return rb_database_join_settings_controller;
}

/***********************
*  parent_environment  *
***********************/

VALUE rb_RPDB_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller )	{

	VALUE	rb_parent_database	=	rb_RPDB_DatabaseJoinController_parentDatabase( rb_join_controller );
	
	VALUE	rb_parent_environment	=	rb_RPDB_Database_parentEnvironment( rb_parent_database );
	
	return rb_parent_environment;
}

/********************
*  parent_database  *
********************/
VALUE rb_RPDB_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller )	{
	
	VALUE	rb_parent_database	=		rb_iv_get(	rb_join_controller,
																						RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE );
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
VALUE rb_RPDB_DatabaseJoinController_join(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller )	{

	if ( argc == 0 )	{
		rb_scan_args(	argc,
									args,
									"10" );
	}

	VALUE	rb_cursors										=	rb_ary_new();
	VALUE	rb_descriptor_hashes					=	rb_ary_new();
	VALUE	rb_join_arrays								=	rb_ary_new();
	
	VALUE	rb_join_cursors_return_array	=	rb_ary_new();
	
	VALUE	rb_primary_database						=	rb_RPDB_DatabaseJoinController_parentDatabase( rb_join_controller );

	//	sort each arg
	int	c_which_arg	=	0;
	for ( c_which_arg = 0 ; c_which_arg < argc ; c_which_arg++ )	{
		VALUE	rb_this_arg	=	args[ c_which_arg ];
		switch ( TYPE( args ) )	{
			case T_ARRAY:
				rb_ary_push(	rb_join_arrays,
											rb_this_arg );
				break;
			case T_HASH:
				rb_ary_push(	rb_descriptor_hashes,
											rb_this_arg );
				break;
			case T_DATA:
			case T_OBJECT:
			{
				VALUE	rb_klass	=	rb_obj_class( rb_this_arg );
				VALUE	rb_ancestors	=	rb_mod_ancestors( rb_klass );
				if ( rb_ary_includes(	rb_ancestors,
															rb_RPDB_DatabaseCursor ) == Qtrue )	{
					rb_ary_push(	rb_cursors,
												rb_this_arg );
				}
			}
				break;
			default:
				rb_raise( rb_eArgError, "Unknown argument type for join. Expected hash, array, or cursor." );
				break;
		}
	}
	
	//	if we have multiple hashes and any cursors, throw error
	if (		RARRAY_LEN( rb_descriptor_hashes ) > 1
			&&	RARRAY_LEN( rb_cursors ) )	{
		
		rb_raise( rb_eArgError, "Multiple hash descriptors given alongside cursors. Use arrays to describe appropriate grouping (unable to determine automatically)." );
	}

	//	if we have any arrays, process recursively and concat results to rb_join_cursors_return_array
	if ( RARRAY_LEN( rb_join_arrays ) )	{
		int	c_which_join_array	=	0;
		for ( c_which_join_array = 0 ; c_which_join_array < RARRAY_LEN( rb_join_arrays ) ; c_which_join_array++ )	{
			VALUE		rb_this_join_array	=	RARRAY_PTR( rb_join_arrays )[ c_which_join_array ];
			//	call recursively
			VALUE	rb_join_cursor_or_array	=	rb_RPDB_DatabaseJoinController_join(	RARRAY_LEN( rb_this_join_array ),
																																						RARRAY_PTR( rb_this_join_array ),
																																						rb_join_controller );
			//	we don't know what's in the array, so we can get 1 or more cursors back
			if ( TYPE( rb_join_cursor_or_array ) == T_ARRAY )	{
				rb_ary_concat(	rb_join_cursors_return_array,
												rb_join_cursor_or_array );			
			}
			else {
				rb_ary_push(	rb_join_cursors_return_array,
											rb_join_cursor_or_array );
			}
		}
	}
	//	otherwise, if we have cursors and a hash we have to get each cursor for the hash before we can combine all cursors
	else if (		RARRAY_LEN( rb_cursors )
					&&	RARRAY_LEN( rb_descriptor_hashes ) )	{

		VALUE	rb_descriptor_hash	=	rb_ary_entry( rb_descriptor_hashes, 0 );
		VALUE	rb_cursors_array		=	rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	rb_primary_database,
																																															rb_descriptor_hash );
		//	concat cursors with any others we might have
		rb_ary_concat(	rb_cursors,
										rb_cursors_array );
	}
	
	//	now, if we have cursors, combine all cursors
	if ( RARRAY_LEN( rb_cursors ) )	{
		
		VALUE	rb_join_cursor	=	rb_RPDB_DatabaseJoinController_joinListOfCursors(	RARRAY_LEN( rb_cursors ),
																																							RARRAY_PTR( rb_cursors ),
																																							rb_join_controller );
		rb_ary_push(	rb_join_cursors_return_array,
									rb_join_cursor );
	}
	//	otherwise, if we still have hashes, get a join cursor for each hash descriptor
	else if ( RARRAY_LEN( rb_descriptor_hashes ) ) {

		int	c_which_hash	=	0;
		for ( c_which_hash = 0 ; c_which_hash < RARRAY_LEN( rb_descriptor_hashes ) ; c_which_hash++ )	{
			VALUE	rb_this_hash_descriptor	=	RARRAY_PTR( rb_descriptor_hashes )[ c_which_hash ];
			VALUE	rb_join_cursor					=	rb_DatabaseJoinController_internal_joinCursorForHashDescriptor(	rb_join_controller,
																																																			rb_primary_database,
																																																			rb_this_hash_descriptor );
			//	concat cursors with any others we might have
			rb_ary_push(	rb_join_cursors_return_array,
										rb_join_cursor );			
		}
	}

	return SIMPLIFIED_RUBY_ARRAY( rb_join_cursors_return_array );
}




/*********************
*  join_cursor_list  *
*  join_cursors      *
*********************/

//	The curslist parameter contains a NULL terminated array of cursors. Each database_cursor must have been initialized to refer to the key 
//	on which the underlying database should be joined. Typically, this initialization is done by a DBcursor->get call with the 
//	DB_SET flag specified. Once the cursors have been passed as part of a curslist, they should not be accessed or modified until 
//	the newly created join database_cursor has been closed, or else inconsistent results may be returned.
//
//	the best join performance normally results from sorting the cursors from the one that refers to the least number of data items 
//	to the one that refers to the most. By default, DB->join does this sort on behalf of its caller.
//
//	For the returned join database_cursor to be used in a transaction-protected manner, the cursors listed in curslist must have been created within the context of the same transaction.
//
//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_join.html
//	Assumes that all cursors in list have the same primary database (the first will be used)
//
//	Join cursors have the same name as the Database database_cursor that was used to initalize them
VALUE rb_RPDB_DatabaseJoinController_joinListOfCursors(	int			argc,
																												VALUE*	args,
																												VALUE		rb_join_controller )	{
	
	if ( argc == 0 )	{
		rb_scan_args(	argc,
									args,
									"10" );
	}
		
	VALUE	rb_cursor_list	=	rb_ary_new();
	
	//	we accept cursors or arrays of cursors; collect them all into a single list
	int	c_which_arg	=	0;
	for ( c_which_arg = 0 ; c_which_arg < argc ; c_which_arg++ )	{
		VALUE	rb_this_arg	=	args[ c_which_arg ];
		rb_ary_push(	rb_cursor_list,
									rb_this_arg );
	}

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );
	
	VALUE	rb_this_cursor		=	Qnil;
	RPDB_DatabaseCursor**	c_cursor_list	=	calloc( RARRAY_LEN( rb_cursor_list ) + 1, sizeof( RPDB_DatabaseCursor* ) );
	int		which_cursor_index	=	0;
	for( which_cursor_index = 0 ; which_cursor_index < RARRAY_LEN( rb_cursor_list ) ; which_cursor_index++ )	{

		rb_this_cursor	=	RARRAY_PTR( rb_cursor_list )[ which_cursor_index ];
		
		//	Get c pointer to RPDB_DatabaseCursor
		C_RPDB_DATABASE_CURSOR( rb_this_cursor, c_cursor_list[ which_cursor_index ] );
	}
	
	//	cap off list with a NULL pointer
	c_cursor_list[ which_cursor_index++ ]	=	NULL;
		
	RPDB_DatabaseJoinCursor*	c_join_cursor	=	RPDB_DatabaseJoinController_join(	c_join_controller,
																																							c_cursor_list );
							
	return RUBY_RPDB_DATABASE_JOIN_CURSOR( c_join_cursor );
	
}

/*************************
*  closeAllCursors  *
*************************/

VALUE rb_RPDB_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller )	{

	RPDB_DatabaseJoinController*	c_join_controller;
	C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller );

	RPDB_DatabaseJoinController_closeAllCursors( c_join_controller );

	return rb_join_controller;
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

static int rb_RPDB_DatabaseCursorController_internal_cursorsForEachHashDescriptor(	VALUE	rb_key_method_symbol,
																																										VALUE	rb_key_value,
																																										VALUE	rb_passed_args );

/******************************************
*  joinCursorForHashDescriptor  *
******************************************/

VALUE rb_DatabaseJoinController_internal_joinCursorForHashDescriptor( VALUE	rb_join_controller,
																																			VALUE	rb_primary_database,
																																			VALUE	rb_hash_descriptor )	{
	
	VALUE	rb_cursors_array	=	rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	rb_primary_database,
																																													rb_hash_descriptor );
	
	VALUE	rb_join_cursor	=	rb_RPDB_DatabaseJoinController_joinListOfCursors(	RARRAY_LEN( rb_cursors_array ),
																																						RARRAY_PTR( rb_cursors_array ),
																																						rb_join_controller );
	return rb_join_cursor;
}

/******************************************
*  cursorsForHashDescriptor  *
******************************************/

VALUE rb_DatabaseJoinController_internal_cursorsForHashDescriptor(	VALUE	rb_primary_database,
																																		VALUE	rb_hash_descriptor )	{

	//	args to pass to foreach
	VALUE	rb_passed_args	=	rb_ary_new();
	rb_ary_push(	rb_passed_args,
								rb_primary_database );

	//	foreach item (once): 
	rb_hash_foreach(	rb_hash_descriptor, 
										& rb_RPDB_DatabaseCursorController_internal_cursorsForEachHashDescriptor,
										rb_passed_args );
	
	//	our cursor array is our passed args array minus the first index (rb_primary_database)
	VALUE	rb_cursor_array	=	rb_passed_args;
	//	chop off rb_primary_database and we have our cursor array
	rb_ary_shift( rb_cursor_array );

	//	If the last element in our array is false, one of the cursors failed to retrieve (record didn't exist)
	if ( RARRAY_PTR( rb_cursor_array )[ RARRAY_LEN( rb_cursor_array ) ] == Qfalse )	{
		//	we return Qnil because this join wasn't possible
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
static int rb_RPDB_DatabaseCursorController_internal_cursorsForEachHashDescriptor(	VALUE	rb_key_method_symbol,
																																										VALUE	rb_key_value,
																																										VALUE	rb_passed_args )	{
	
	VALUE	rb_primary_database	=	rb_ary_entry( rb_passed_args, 0 );

	//	make sure we have symbols rather than strings for our key
	if ( TYPE( rb_key_method_symbol ) == T_STRING )	{
		rb_key_method_symbol	=	STRING2SYM( rb_key_method_symbol );
	}
	
	VALUE	rb_cursor				=	rb_RPDB_DatabaseJoinController_internal_cursorForIndexAtKeyValue(	rb_primary_database,
																																										rb_key_method_symbol,
																																										rb_key_value );
	
	//	If we get no record for setting our cursor we push false and fail
	if ( rb_cursor == Qnil )	{
		rb_ary_push(	rb_passed_args,
									Qfalse );
		return ST_STOP;
	}

	//	we use ruby internals to handle subclasses (such as object cursors)
	VALUE	rb_current_record		=	rb_funcall( rb_cursor,
																					rb_intern( "current" ),
																					0 );

	//	If we get no record for setting our cursor we push false and fail
	if ( rb_current_record == Qnil )	{
		
		rb_ary_push(	rb_passed_args,
									Qfalse );
		return ST_STOP;
	}

	//	push cursor for return
	rb_ary_push(	rb_passed_args,
								rb_cursor );
	
	return ST_CONTINUE;
}

/******************************************
*  cursorForParameterDescription  *
******************************************/

VALUE rb_RPDB_DatabaseJoinController_internal_cursorForIndexAtKeyValue(	VALUE	rb_primary_database,
																																				VALUE	rb_index_name,
																																				VALUE	rb_key_value  )	{
		
	VALUE	rb_secondary_database	=	rb_RPDB_Database_requireSecondaryDatabaseWithIndex(	rb_primary_database,
																																										rb_index_name );
	
	//	we call via rb_funcall so that the class determines whether or not to use RPDB_DatabaseCursor or RPDB_DatabaseObjectCursor
	VALUE	rb_cursor	=	rb_funcall(	rb_secondary_database,
																rb_intern( "cursor" ),
																0 );

	//	FIX - we probably want to add a method (perhaps a block) that gets called here that can be overridden for settings, etc.
	
	//	set cursor to requested first record
	//	again, we call via rb_funcall so that the class determines whether or not to use RPDB_DatabaseCursor or RPDB_DatabaseObjectCursor
	VALUE	rb_current	=	rb_funcall(	rb_cursor,
																	rb_intern( "retrieve" ),
																	1,
																	rb_key_value );

	if ( rb_current == Qnil )   {
		rb_cursor	=	Qnil;
	}
	
	return rb_cursor;
}

