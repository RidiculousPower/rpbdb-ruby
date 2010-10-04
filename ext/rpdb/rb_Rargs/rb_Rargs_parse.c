#include "rb_Rargs_parse.h"
#include "rb_Rargs_describe.h"
#include "rb_Rargs_free.h"

/***********************
*  parseParameterSets  *
***********************/

int RARG_parseParameterSetsForMatch(	int											argc, 
																			VALUE*									args, 
																			rarg_parameter_set_t*		parameter_sets )	{	

	//	we do this here to allow looping by macro (R_Parse)
	if ( argc <= 0 )	{
		return FALSE;
	}

	//	Parse parameter_sets for match
	rarg_matched_parameter_set_t* matched_parameter_set	=	RARG_parseParameterSets(	argc, 
																																									args, 
																																									parameter_sets );

	//	Iterate matched parameter_set parameters
	if ( matched_parameter_set == NULL )	{
	
		VALUE	rb_arg_formats_array			=	RARG_collectDescriptionsForParameterSets( parameter_sets );
		VALUE	rb_arg_formats_string			=	rb_funcall(	rb_arg_formats_array,
																									rb_intern( "join" ),
																									1,
																									rb_str_new( "\n\n *\t",
																															5 ) );
		char*	c_arg_formats_string	=	StringValuePtr( rb_arg_formats_string );
		char*	c_format_string				=	"Failed to match any acceptable parameter formats.\n\nParameter formats include:\n\n *\t%s\n\n";
		int		c_error_string_length	=	strlen( c_arg_formats_string ) + strlen( c_format_string );
		char*	c_error_string				=	calloc( c_error_string_length + 1, sizeof( char ) );		
		sprintf(	c_error_string, 
							c_format_string, 
							c_arg_formats_string );			
		VALUE	rb_exception	=	rb_exc_new2( rb_eArgError, c_error_string );
		free( c_error_string );
		rb_exc_raise( rb_exception );
	
	}
	//	assign matched parameter values to value receivers
	else	{
	
		rarg_matched_parameter_t* matched_parameter	=	matched_parameter_set->parameters;
		while ( matched_parameter != NULL )	{

			*matched_parameter->receiver	=	matched_parameter->match;
			matched_parameter							= matched_parameter->next;

		}
	}
	
	//	FIX - free parameter sets
	
	return matched_parameter_set->last_arg;
}

/***********************
*  parseParameterSets  *
***********************/

rarg_matched_parameter_set_t* RARG_parseParameterSets(	int											argc, 
																												VALUE*									args, 
																												rarg_parameter_set_t*		parameter_set)	{	

	rarg_matched_parameter_set_t*	matched_parameter_set	=	NULL;

	while ( parameter_set != NULL )	{

		matched_parameter_set	=	calloc( 1, sizeof( rarg_matched_parameter_set_t ) );

		// if all parameters in a parameter_set match args
		if ( ( matched_parameter_set->last_arg	=	RARG_parseParameters(	argc, 
																																		args, 
																																		parameter_set->parameters, 
																																		matched_parameter_set ) )

			//	if we require exact match and have args remaining we don't match
			&&	(		! parameter_set->require_exact
					||	matched_parameter_set->last_arg == argc ) )	{

			//	otherwise, success - matched parameter_set
			break;
		}

		matched_parameter_set = NULL;
		
		parameter_set	= parameter_set->next;
	}
	//	success = match
	//	failure = NULL
	return matched_parameter_set;
}

/********************
*  parseParameters  *
********************/

int RARG_parseParameters(	int															argc, 
													VALUE*													args, 
													rarg_parameter_t*								parameter, 
													rarg_matched_parameter_set_t*		matched_parameter_set )	{
	
	rarg_matched_parameter_t**	matched_parameter_ptr	=	& matched_parameter_set->parameters;
	
	int which_parameter	=	0;                                                                                                          
	if ( parameter != NULL )	{

		while ( parameter != NULL )	{
			
			*matched_parameter_ptr	=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
			
			VALUE	rb_arg	=	args[ which_parameter ];
			
			// loop index starts with 1 to match argc, which is 1-based																															
			which_parameter++;

			// if we run out of args and have more parameters, continue to next parameter_set                                           
			if ( which_parameter > argc )	{                                                                                                 
				// move to the next parameter_set	                                                                  
				return FALSE;
			}			                                                                                                                      

			// if parsing allowed types fails, break from parsing these parameters and go to next parameter_set
			if ( ! RARG_parsePossibleMatches(	parameter, 
																				rb_arg, 
																				matched_parameter_ptr ) ) {
				return FALSE;
			}
			
			//	we matched if we got here

			//	only advance matched parameter if we had a receiver
			if ( ( *matched_parameter_ptr )->receiver != NULL )	{
				matched_parameter_ptr	=	& ( *matched_parameter_ptr )->next;
			}
			
			parameter = parameter->next;
		}
	}
	
	//	if we got here we matched
	//	* we have the option of requiring exact match (in which case we test which_parameter == argc)
	//	* or of allowing repeats, in which case we return the index of the next unused arg
	//	we test for this after return, in parameter set
	return which_parameter;
}

/*************************
*  parsePossibleMatches  *
*************************/

BOOL RARG_parsePossibleMatches(	rarg_parameter_t*							parameter, 
																VALUE													rb_arg, 
																rarg_matched_parameter_t**		matched_parameter )	{
	
	rarg_possible_match_t*	possible_match	=	parameter->possible_match;
	
	// test each allowed type for this parameter slot to see if this arg matches parameter
	while ( possible_match != NULL )	{

		int	switch_result = RARG_parseAllowedTypes(	parameter, 
																								possible_match, 
																								rb_arg, 
																								matched_parameter, 
																								FALSE );
		if (		switch_result != RARG_CONTINUE 
				//	if it's optional we don't care what the result was; act as if it was ok
				&&	! possible_match->optional )	{
			return switch_result;
		}
		possible_match = possible_match->next;
	}
	// if we get here we didn't match
	return FALSE;
}

/*****************************
*  parsePossibleHashMatches  *
*****************************/

BOOL RARG_parsePossibleHashMatches(	rarg_parameter_t*							parameter, 
																		rarg_possible_match_t*				possible_match, 
																		VALUE													rb_hash_arg,
																		VALUE													rb_key,
																		VALUE													rb_data,
																		rarg_matched_parameter_t**		matched_parameter )	{

	if (		! RARG_parseIndexes(	possible_match,
																rb_hash_arg,
																matched_parameter )
			&&	(		! RARG_parsePossibleHashKeyOrDataMatches(	parameter, 
																												possible_match->possible_hash_key_match,
																												rb_hash_arg, 
																												rb_key, 
																												matched_parameter ) 
					||	! RARG_parsePossibleHashKeyOrDataMatches(	parameter, 
																												possible_match->possible_hash_data_match,	
																												rb_hash_arg, 
																												rb_data, 
																												matched_parameter ) ) )	{
		return FALSE;
	}
	
	// types matched
	return TRUE;
}

/**************************************
*  parsePossibleHashKeyOrDataMatches  *
**************************************/

BOOL RARG_parsePossibleHashKeyOrDataMatches(	rarg_parameter_t*							parameter, 
																							rarg_possible_match_t*				possible_hash_key_or_data, 
																							VALUE													rb_hash_arg, 
																							VALUE													rb_hash_key_or_data, 
																							rarg_matched_parameter_t**		matched_parameter )	{

	if ( possible_hash_key_or_data )	{
		while ( possible_hash_key_or_data != NULL )	{
			
			BOOL	switch_result = RARG_parseAllowedTypes(	parameter, 
																										possible_hash_key_or_data, 
																										rb_hash_key_or_data, 
																										matched_parameter, 
																										rb_hash_arg );
			if ( switch_result != RARG_CONTINUE )	{
				return switch_result;
			}
			possible_hash_key_or_data = possible_hash_key_or_data->next;
		}

		// if we get here we didn't match
		return FALSE;
	}
	//	if no key/data types are specified, any are allowed
	return TRUE;
}

/**********************
*  parseAllowedTypes  *
**********************/

BOOL RARG_parseAllowedTypes(	rarg_parameter_t*							parameter, 
															rarg_possible_match_t*				possible_match, 
															VALUE													rb_arg, 
															rarg_matched_parameter_t**		matched_parameter_ptr, 
															VALUE													rb_hash_whose_key_or_data_is_rb_arg )	{
	
	const int	rb_arg_type					=	TYPE( rb_arg );
	const int allowed_match_type	=	possible_match->type;
	
	/* if the condition doesn't match we return a continue message */
	int	matched	=	RARG_CONTINUE;
	
	//	check for allowed types
	if ( allowed_match_type == R_ANY )	{
		matched	=	TRUE;
	}
	else if (	allowed_match_type == R_NOT_NIL )	{

		if ( rb_arg != Qnil )	{
			matched	=	TRUE;
		}
		matched = FALSE;
	}
	
	//	0 is FALSE, -1 is RARG_CONTINUE
	if ( matched <= 0 ) switch ( rb_arg_type )	{

		case T_NIL:
			if ( allowed_match_type & R_NIL )	{
				matched	=	TRUE;
			}
			break;
			
		case T_CLASS:
			if ( allowed_match_type & R_CLASS )	{
				matched	=	TRUE;
			}
			break;

		case T_MODULE:
			if ( allowed_match_type & R_MODULE )	{
				matched	=	TRUE;
			}
			break;

		case T_FLOAT:
			if ( allowed_match_type & R_FLOAT )	{
				matched	=	TRUE;
			}
			break;

		case T_STRING:
			if ( allowed_match_type & R_STRING )	{
				matched	=	TRUE;	
			}
			break;

		case T_SYMBOL:
			if ( allowed_match_type & R_SYMBOL )	{
				matched	=	TRUE;
			}			
			break;


		case T_REGEXP:
			if ( allowed_match_type & R_REGEXP )	{
				matched	=	TRUE;	
			}
			break;

		case T_ARRAY:
			if ( allowed_match_type & R_ARRAY )	{
				matched	=	TRUE;
			}
			break;

		case T_HASH:
			if ( allowed_match_type & R_HASH )	{

				VALUE rb_array_key_data	=	rb_funcall( rb_arg,
																							rb_intern( "first" ),
																							0 );
				VALUE	rb_key	=	rb_ary_shift( rb_array_key_data );
				VALUE	rb_data	=	rb_ary_shift( rb_array_key_data );

				// if our hash types match we match parameter, otherwise we don't
				matched = RARG_parsePossibleHashMatches(	parameter,
																									possible_match, 
																									rb_arg,
																									rb_key,
																									rb_data, 
																									matched_parameter_ptr );
			
			}
			break;

		case T_BIGNUM:
			if ( allowed_match_type & R_BIGNUM )	{
				matched	=	TRUE;
			}
			break;

		case T_FILE:
			if ( allowed_match_type & R_FILE )	{
				matched	=	TRUE;	
			}
			break;

		case T_FIXNUM:
			if ( allowed_match_type & R_FIXNUM )	{
				matched	=	TRUE;
			}
			break;

		case T_TRUE:
			if ( allowed_match_type & R_TRUE )	{
				matched	=	TRUE;	
			}
			break;

		case T_FALSE:
			if ( allowed_match_type & R_FALSE )	{
				matched	=	TRUE;	
			}
			break;

		case T_STRUCT:
			if ( allowed_match_type & R_STRUCT )	{
				matched	=	TRUE;
			}
		case T_DATA:
			if ( allowed_match_type & R_DATA )	{
				matched	=	TRUE;
			}
		case T_OBJECT:
			if (		allowed_match_type & R_OBJECT
					&&	RARG_parseAllowedClasses(	possible_match,
																				rb_arg ) )	{
				matched	=	TRUE;
			}
			break;
			

		case T_MATCH:
			if ( allowed_match_type & R_MATCH )	{
				matched	=	TRUE;	
			}
			break;

		case T_RATIONAL:
			if ( allowed_match_type & R_RATIONAL )	{
				matched	=	TRUE;
			}
			break;

		case T_COMPLEX:
			if ( allowed_match_type & R_COMPLEX )	{
				matched	=	TRUE;
			}
			break;
	}
	
	//	if we matched we want to store reference to match data so we don't have to reparse the matched parameter_set
	if (		matched == TRUE
			//	if we already have matched via key/data don't overwrite
			&&	! ( *matched_parameter_ptr )->match )	{
		
		//	standard condition: 
		//	* match assigns to receiver 
		//	hash conditions:
		//	* hash match assigns hash to receiver
		//	* hash match assigns key to receiver
		//	* hash match assigns data to receiver
		//	if we only have rb_arg, we assign rb_arg to receiver
		//	if we have rb_arg and rb_hash
		

		//	if we have only rb_arg and not rb_hash_whose_key_or_data_is_rb_arg
		//	we are assigning a standard arg to receiver (includes hash)
		if (		! rb_hash_whose_key_or_data_is_rb_arg
				&&	possible_match->receiver != NULL )	{

			( *matched_parameter_ptr )->receiver									=	possible_match->receiver;	
			( *matched_parameter_ptr )->match											=	rb_arg;			
		}
		//	if we have rb_arg and rb_hash_whose_key_or_data_is_rb_arg we are assigning either a hash key or data or a hash for key/data match
		else if ( possible_match->receiver != NULL )	{

			( *matched_parameter_ptr )->receiver									=	possible_match->receiver;			
			
			if ( possible_match->assign_parent_hash_for_key_or_data_self )	{
				
				( *matched_parameter_ptr )->match										=	rb_hash_whose_key_or_data_is_rb_arg;			
			}
			else {
				
				( *matched_parameter_ptr )->match										=	rb_arg;			
			}
		}
	}
	
	return matched;
}

/************************
*  parseAllowedClasses  *
************************/

BOOL RARG_parseAllowedClasses(	rarg_possible_match_t*	possible_class_match,
																VALUE										rb_arg )	{
	
	VALUE	rb_ancestors	=	rb_mod_ancestors( rb_arg );
	
	while ( possible_class_match != NULL ) {
		
		if ( rb_funcall(	rb_ancestors,
											rb_intern( "include?" ),
											1,
											possible_class_match->ruby_class ) != Qfalse )	{
			return TRUE;
		}
		
		possible_class_match = possible_class_match->next;
	}
	
	return FALSE;
}

/*****************
*  parseIndexes  *
*****************/

BOOL RARG_parseIndexes(	rarg_possible_match_t*			possible_index_match,
												VALUE												rb_arg,
												rarg_matched_parameter_t**	matched_parameter_ptr )	{
		
	BOOL	has_required_indexes	=	TRUE;
		
	while ( possible_index_match != NULL ) {
		
		VALUE	rb_index_ref	=	Qnil;
		if (		possible_index_match->index_name
				&&	(		( rb_index_ref	=	rb_hash_aref(	rb_arg,
																							ID2SYM( rb_intern( possible_index_match->index_name ) ) != Qnil ) )
						||	( rb_index_ref	=	rb_hash_aref(	rb_arg,
																							rb_str_new2( possible_index_match->index_name ) ) ) ) )	{
			
			//	if we get to this point we match
			if ( possible_index_match->receiver != NULL )	{
				if ( ( *matched_parameter_ptr )->receiver != NULL )	{
					( *matched_parameter_ptr )->next		=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
					matched_parameter_ptr								=	& ( *matched_parameter_ptr )->next;
				}
				( *matched_parameter_ptr )->match			=	rb_index_ref;
				( *matched_parameter_ptr )->receiver	=	possible_index_match->receiver;
			}
			
		}
		else if ( possible_index_match->optional == FALSE )	{
			has_required_indexes	=	FALSE;
			break;
		}
		
		possible_index_match = possible_index_match->next;
	}
	
	return has_required_indexes;
}

//	FIX - add min/max argument counting

//	FIX - make sure these work:
//	* class compatibility test
//	* index test - required and optional and receivers
