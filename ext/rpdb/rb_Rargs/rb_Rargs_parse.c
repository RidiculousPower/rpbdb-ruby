#include "rb_Rargs_parse.h"
#include "rb_Rargs_describe.h"
#include "rb_Rargs_error.h"
#include "rb_Rargs_free.h"

/***********************************************************************************************************************
																					Parameter Sets
***********************************************************************************************************************/

/*************************************
*  RARG_parse_ParameterSetsForMatch  *
*************************************/

int RARG_parse_ParameterSetsForMatch(	int											argc, 
																			VALUE*									args, 
																			rarg_parameter_set_t*		parameter_sets )	{	

	//	we do this here to allow looping by macro (R_Parse)
	if (		argc <= 0 
			&&	! rb_block_given_p() )	{
		return FALSE;
	}

	//	Parse parameter_sets for match
	rarg_matched_parameter_set_t* matched_parameter_set	=	RARG_parse_ParameterSets(	argc, 
																																									args, 
																																									parameter_sets );

	//	Iterate matched parameter_set parameters
	if ( matched_parameter_set == NULL )	{
	
		RARG_error_NoMatchForParameters( parameter_sets );
		
	
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

/*****************************
*  RARG_parse_ParameterSets  *
*****************************/

rarg_matched_parameter_set_t* RARG_parse_ParameterSets(	int											argc, 
																												VALUE*									args, 
																												rarg_parameter_set_t*		parameter_set)	{	

	rarg_matched_parameter_set_t*	matched_parameter_set	=	NULL;

	while ( parameter_set != NULL )	{

		matched_parameter_set	=	calloc( 1, sizeof( rarg_matched_parameter_set_t ) );

		// if all parameters in a parameter_set match args
		if ( ( matched_parameter_set->last_arg	=	RARG_parse_Parameters(	argc, 
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

/**************************
*  RARG_parse_Parameters  *
**************************/

int RARG_parse_Parameters(	int															argc, 
														VALUE*													args, 
														rarg_parameter_t*								parameter, 
														rarg_matched_parameter_set_t*		matched_parameter_set )	{
	
	rarg_matched_parameter_t**	matched_parameter_ptr	=	& matched_parameter_set->parameters;

	//	we need to iterate parameters to check possible matches against args
	//	this is necessary rather than iterating args because the terminal arg is Qfalse,
	//	which can be a valid arg
	//	so we parse expected declared parameters and look for a match, not argc

	




		
	int which_parameter	=	0;
	if ( parameter != NULL )	{
	
		while ( parameter != NULL )	{

			VALUE	rb_arg	=	args[ which_parameter ];

			// loop index starts with 1 to match argc, which is 1-based
			which_parameter++;

			// if we have no args but a block parameter, we still need to test
			if (		which_parameter <= argc
					||	(		rb_block_given_p()
							&&	parameter->possible_match->type == RARG_BLOCK ) )	{
			
				// if parsing allowed types fails, break from parsing these parameters and go to next parameter_set
				if (	! RARG_parse_PossibleMatches(	parameter,
																						rb_arg,
																						matched_parameter_ptr )
						&&	! parameter->optional ) {
						
					which_parameter = FALSE;
					break;
				}
				
			}
			else {
				
				// move to the next parameter_set
				which_parameter = FALSE;
				break;

			}

			//	we matched if we got here
			parameter = parameter->next;
		}
	}

	//	if we got here we matched
	//	* we have the option of requiring exact match (in which case we test which_parameter == argc)
	//	* or of allowing repeats, in which case we return the index of the next unused arg
	//	we test for this after return, in parameter set
	return which_parameter;
}

/***********************************************************************************************************************
																					Possible Matches
***********************************************************************************************************************/

/*******************************
*  RARG_parse_PossibleMatches  *
*******************************/

BOOL RARG_parse_PossibleMatches(	rarg_parameter_t*							parameter, 
																	VALUE													rb_arg, 
																	rarg_matched_parameter_t**		matched_parameter )	{
	
	rarg_possible_match_t*	possible_match	=	parameter->possible_match;
	
	int matched	=	FALSE;
	// test each allowed type for this parameter slot to see if this arg matches parameter
	while ( possible_match != NULL )	{

		//	if our possible match is true, we matched this parameter (continue to next)
		//	if our possible match is false, we do not match this possible match 
		if (	( matched = RARG_parse_PossibleMatch(	possible_match,
																								rb_arg,
																								matched_parameter ) ) )	{
			break;
		}

		possible_match = possible_match->next;
	}
	// if we get here we didn't match
	return matched;
}

/*****************************
*  RARG_parse_PossibleMatch  *
*****************************/

BOOL RARG_parse_PossibleMatch(		rarg_possible_match_t*				possible_match, 
																	VALUE													rb_arg, 
																	rarg_matched_parameter_t**		matched_parameter_ptr )	{

	int	matched	=	FALSE;

	if ( *matched_parameter_ptr == NULL )	{
		*matched_parameter_ptr	=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
	}
	else if ( ( *matched_parameter_ptr )->receiver != NULL )	{
		( *matched_parameter_ptr )->next		=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
		matched_parameter_ptr								=	& ( *matched_parameter_ptr )->next;
	}

	//	parse allowed blocks
	if (			possible_match->type == RARG_BLOCK )	{
		
		matched	=	RARG_parse_PossibleBlockMatch(	possible_match,
																							matched_parameter_ptr );
	}
	//	parse allowed hashes
	else if ( possible_match->type == RARG_HASH )	{
	
		matched	=	RARG_parse_PossibleHashMatch(	possible_match,
																						rb_arg,
																						matched_parameter_ptr );

	}
	//	parse allowed types
	else if ( possible_match->type == RARG_TYPE )	{

		matched = RARG_parse_PossibleTypeMatch(	possible_match, 
																						rb_arg, 
																						matched_parameter_ptr );
	
	}
	//	parse allowed ancestors
	else if ( possible_match->type == RARG_ANCESTOR )	{

		matched	=	RARG_parse_PossibleAncestorMatches(	possible_match,
																									rb_arg,
																									matched_parameter_ptr );
		
	}
	//	parse allowed ancestors
	else if ( possible_match->type == RARG_METHOD )	{

		matched	=	RARG_parse_PossibleMethodMatches(	possible_match,
																								rb_arg,
																								matched_parameter_ptr );
		
	}
	
	if ( ! matched )	{
		free( *matched_parameter_ptr );
		matched_parameter_ptr = NULL;
	}

	return matched;
}

/***********************************************************************************************************************
																					Possible Match Details
***********************************************************************************************************************/

/**********************************
*  RARG_parse_PossibleBlockMatch  *
**********************************/

BOOL RARG_parse_PossibleBlockMatch(		rarg_possible_match_t*				possible_match, 
																			rarg_matched_parameter_t**		matched_parameter)	{

	rarg_possible_block_match_t*	possible_block_match	=	possible_match->possible->block;

	BOOL	matched	=	FALSE;
	
	if ( rb_block_given_p() )	{

		VALUE	rb_block_as_lambda	=	rb_block_lambda();

		VALUE	rb_arity	=	rb_funcall(	rb_block_as_lambda,
																	rb_intern( "arity" ),
																	0 );

		if (	(		possible_block_match->possible_arity == NULL
					||	( matched = RARG_parse_PossibleBlockArityMatch( possible_block_match->possible_arity,
																															rb_arity ) ) )
					&&	possible_match->receiver != NULL )	{

			if ( possible_block_match->lambda_instead_of_proc )	{
		
				( *matched_parameter )->match			=	rb_block_as_lambda;
				( *matched_parameter )->receiver	=	possible_match->receiver;
			}
			else {
				
				VALUE	rb_block_as_proc						=	rb_block_proc();
				( *matched_parameter )->match			=	rb_block_as_proc;
				( *matched_parameter )->receiver	=	possible_match->receiver;
			}
		}

	}
	else {
		matched = FALSE;
	}

	return matched;
}

/***************************************
*  RARG_parse_PossibleBlockArityMatch  *
***************************************/

BOOL RARG_parse_PossibleBlockArityMatch(	rarg_possible_block_match_arity_t*	possible_arity_match,
																					VALUE																rb_arity	)	{

	BOOL	matched	=	FALSE;
	
	int	c_arity	=	FIX2INT( rb_arity );
	
	while ( possible_arity_match )	{
		
		if ( possible_arity_match->arity == c_arity )	{
			matched = TRUE;
			break;
		}
		
		possible_arity_match	=	possible_arity_match->next;
	}
	
	return matched;
}

/*********************************
*  RARG_parse_PossibleHashMatch  *
*********************************/

BOOL RARG_parse_PossibleHashMatch(		rarg_possible_match_t*				possible_match, 
																			VALUE													rb_arg, 
																			rarg_matched_parameter_t**		matched_parameter_ptr)	{

	rarg_possible_hash_match_t*	possible_hash_match	=	possible_match->possible->hash;

	BOOL	matched	=	FALSE;

	if ( TYPE( rb_arg ) == T_HASH )	{
		
		//	once we match a hash we assume we have matched unless more settings tell us otherwise
		matched	=	TRUE;
				
		VALUE rb_array_key_data	=	rb_funcall( rb_arg,
																					rb_intern( "first" ),
																					0 );
		VALUE	rb_key	=	rb_ary_shift( rb_array_key_data );
		VALUE	rb_data	=	rb_ary_shift( rb_array_key_data );
		
		VALUE	rb_hash_arg	=	rb_arg;

		if ( possible_hash_match->possible_index_match )	{
			
			matched = RARG_parse_PossibleIndexMatch(	possible_match,
																								rb_hash_arg,
																								matched_parameter_ptr );
		}
		
		if (		matched
				&&	possible_hash_match->possible_key_match )	{
		
			matched = RARG_parse_PossibleHashKeyOrDataMatch(	possible_hash_match->possible_key_match,
																												rb_hash_arg, 
																												rb_key, 
																												matched_parameter_ptr );
		}
		
		if (		matched
				&&	possible_hash_match->possible_data_match )	{
		
			matched = RARG_parse_PossibleHashKeyOrDataMatch(	possible_hash_match->possible_data_match,
																												rb_hash_arg, 
																												rb_data, 
																												matched_parameter_ptr );
		}

	}
	
	if ( matched )	{

		if ( possible_match->receiver != NULL )	{

			if ( ( *matched_parameter_ptr )->receiver != NULL )	{
				matched_parameter_ptr		=	& ( *matched_parameter_ptr )->next;
				*matched_parameter_ptr	=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
			}
			
			( *matched_parameter_ptr )->receiver									=	possible_match->receiver;	
			( *matched_parameter_ptr )->match											=	rb_arg;			
		}
	}

	return matched;
}

	/**********************************
	*  RARG_parse_PossibleIndexMatch  *
	**********************************/

	BOOL RARG_parse_PossibleIndexMatch(	rarg_possible_match_t*			possible_match,
																			VALUE												rb_arg,
																			rarg_matched_parameter_t**	matched_parameter_ptr )	{

		rarg_possible_hash_index_match_t*	possible_index_match	=	possible_match->possible->hash->possible_index_match;
			
		BOOL	has_required_indexes	=	TRUE;
		
		//	a "possible index match" can be one or more indexes; if multiple are specified together, all are expected
		while ( possible_index_match != NULL ) {
			
			VALUE	rb_index_ref	=	Qnil;
			if (		possible_index_match->index_name
									//	symbol
					&&	(		( rb_index_ref	=	rb_hash_aref(	rb_arg,
																									ID2SYM( rb_intern( possible_index_match->index_name ) ) != Qnil ) )
									//	or string
							||	( rb_index_ref	=	rb_hash_aref(	rb_arg,
																									rb_str_new2( possible_index_match->index_name ) ) ) ) )	{
				
				//	if we get to this point we match
				if (		possible_index_match->receiver != NULL
						||	possible_index_match->assign_parent_hash_for_match )	{
					
					( *matched_parameter_ptr )->match			=	( possible_index_match->assign_parent_hash_for_match ? 
																											rb_arg 
																											: rb_index_ref );
					( *matched_parameter_ptr )->receiver	=	( possible_index_match->assign_parent_hash_for_match ? 
																											possible_match->receiver 
																											: possible_index_match->receiver );
				
				}
				
			}
			else if ( ! possible_index_match->optional )	{

				has_required_indexes	=	FALSE;
				break;
			}
			
			possible_index_match = possible_index_match->next;
		}
		
		return has_required_indexes;
	}

	/******************************************
	*  RARG_parse_PossibleHashKeyOrDataMatch  *
	******************************************/

	BOOL RARG_parse_PossibleHashKeyOrDataMatch(	rarg_possible_hash_key_data_match_t*		possible_hash_key_or_data, 
																							VALUE																		rb_hash_arg, 
																							VALUE																		rb_hash_key_or_data, 
																							rarg_matched_parameter_t**							matched_parameter )	{

		rarg_possible_match_t**	this_possible_key_or_data	=	& possible_hash_key_or_data->possible_match;

		//	if no key/data types are specified, any are allowed
		BOOL	matched	=	TRUE;
		if ( possible_hash_key_or_data )	{
			//	but once we start testing, we assume a match hasn't happened yet
			matched	=	FALSE;
			while ( *this_possible_key_or_data != NULL )	{
				
				if ( ( matched	=	RARG_parse_PossibleMatch( *this_possible_key_or_data,
																										rb_hash_key_or_data,
																										matched_parameter ) ) )	{
				
					//	if we matched our key or data and are supposed to assign our parent hash for the match then
					//	we will have set the match already to the key or data; we test if this has happened and 
					//	override the key or data with the parent hash
					
					if (		( *matched_parameter )->match
							&&	possible_hash_key_or_data->assign_parent_hash_for_match	)	{
						
						( *matched_parameter )->receiver	=	& rb_hash_arg;
					}
					
					//	and we matched so we're done with this key or data
					break;
				}
				
				this_possible_key_or_data = & ( *this_possible_key_or_data )->next;
			}

			// if we get here we didn't match
			return matched;
		}
		return TRUE;
	}

/*********************************
*  RARG_parse_PossibleTypeMatch  *
*********************************/

BOOL RARG_parse_PossibleTypeMatch(	rarg_possible_match_t*				possible_match, 
																		VALUE													rb_arg, 
																		rarg_matched_parameter_t**		matched_parameter_ptr )	{
	
	const int	rb_arg_type					=	TYPE( rb_arg );
	const int allowed_match_type	=	possible_match->possible->types->type;
	
	int	matched	=	FALSE;
	
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
	
	if ( ! matched ) switch ( rb_arg_type )	{

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
				rb_raise( rb_eArgError, "Hash should have already been processed. This should never happen." );
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
			if (		allowed_match_type & R_OBJECT )	{
				rb_raise( rb_eArgError, "Instance should have already been processed. This should never happen." );
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
	if ( matched )	{

		if ( possible_match->receiver != NULL )	{

			if ( ( *matched_parameter_ptr )->receiver != NULL )	{
				matched_parameter_ptr		=	& ( *matched_parameter_ptr )->next;
				*matched_parameter_ptr	=	calloc( 1, sizeof( rarg_matched_parameter_t ) );
			}
			
			( *matched_parameter_ptr )->receiver									=	possible_match->receiver;	
			( *matched_parameter_ptr )->match											=	rb_arg;			
		}
	}
	
	return matched;
}

/***************************************
*  RARG_parse_PossibleAncestorMatches  *
***************************************/

BOOL RARG_parse_PossibleAncestorMatches(	rarg_possible_match_t*				possible_match, 
																					VALUE													rb_arg, 
																					rarg_matched_parameter_t**		matched_parameter)	{
	
	BOOL	matched	=	TRUE;

	//	test ancestor(s)
	if ( possible_match->possible->ancestors != NULL )	{
		
		VALUE	rb_arg_class			=	rb_obj_class( rb_arg );
		VALUE	rb_arg_ancestors	=	rb_mod_ancestors( rb_arg_class );
		
		rarg_possible_ancestor_matches_t**	c_this_possible_ancestor	=	& possible_match->possible->ancestors;
		
		while ( *c_this_possible_ancestor != NULL )	{
			
			if ( rb_ary_includes( rb_arg_ancestors, ( *c_this_possible_ancestor )->ancestor ) == Qfalse )	{
				matched = FALSE;
				break;
			}
			
			c_this_possible_ancestor	=	& ( *c_this_possible_ancestor )->next;
		}
	}

	if (		matched
			&&	possible_match->receiver )	{
		
		( *matched_parameter )->match			=	rb_arg;
		( *matched_parameter )->receiver	=	possible_match->receiver;
	}
	
	return matched;
}

/*************************************
*  RARG_parse_PossibleMethodMatches  *
*************************************/

BOOL RARG_parse_PossibleMethodMatches(		rarg_possible_match_t*				possible_match, 
																					VALUE													rb_arg, 
																					rarg_matched_parameter_t**		matched_parameter)	{
	
	BOOL	matched	=	TRUE;

	//	test method(s)
	if ( possible_match->possible->methods )	{

		rarg_possible_method_matches_t**	c_this_possible_method	=	& possible_match->possible->methods;
		
		while ( *c_this_possible_method != NULL )	{
			
			if ( rb_respond_to( rb_arg, ( *c_this_possible_method )->method_id ) == Qfalse )	{
				matched = FALSE;
				break;
			}

			c_this_possible_method	=	& ( *c_this_possible_method )->next;
		}
	
	}
	
	if (		matched
			&&	possible_match->receiver )	{
		
		( *matched_parameter )->match			=	rb_arg;
		( *matched_parameter )->receiver	=	possible_match->receiver;
	}
	
	return matched;
}

