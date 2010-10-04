#include "rb_Rargs_free.h"

/*********************
*  freeParameterSets  *
*********************/

void RARG_freeParameterSets( rarg_parameter_set_t* rarg_parameter_set )	{	

	rarg_parameter_set_t* rarg_parameter_set_ptr;
	while ( rarg_parameter_set != NULL )	{
		rarg_parameter_set_ptr = rarg_parameter_set;
		rarg_parameter_set	= rarg_parameter_set->next;
		free( rarg_parameter_set_ptr );
	}
}

/********************
*  freeParameters  *
********************/

void RARG_freeParameters( rarg_parameter_t* rarg_parameter )	{
	
	rarg_parameter_t* rarg_parameter_ptr	=	rarg_parameter;
	while ( rarg_parameter != NULL )	{
		rarg_parameter_ptr = rarg_parameter;
		rarg_parameter = rarg_parameter->next;
		free( rarg_parameter_ptr );
	}
}

/************************
*  freePossibleMatches  *
************************/

void RARG_freePossibleMatches( rarg_possible_match_t* rarg_possible_match )	{

	rarg_possible_match_t* rarg_possible_match_ptr;
	
	while ( rarg_possible_match != NULL )	{
		rarg_possible_match_ptr = rarg_possible_match;
		rarg_possible_match = rarg_possible_match->next;
		free( rarg_possible_match_ptr );
	}
}

/****************************
*  freePossibleHashMatches  *
****************************/

void RARG_freePossibleHashMatches( rarg_possible_match_t* rarg_possible_match )	{
	RARG_freePossibleHashKeyOrDataMatches( rarg_possible_match->possible_hash_key_match );
	RARG_freePossibleHashKeyOrDataMatches( rarg_possible_match->possible_hash_data_match );
}

/*************************************
*  freePossibleHashKeyOrDataMatches  *
*************************************/

void RARG_freePossibleHashKeyOrDataMatches( rarg_possible_match_t* rarg_allowed_hash_key_type )	{

	rarg_possible_match_t* rarg_allowed_hash_key_type_ptr;
	while ( rarg_allowed_hash_key_type != NULL )	{
		rarg_allowed_hash_key_type_ptr = rarg_allowed_hash_key_type;
		rarg_allowed_hash_key_type = rarg_allowed_hash_key_type->next;
		free( rarg_allowed_hash_key_type_ptr );
	}
}

/**************************
*  freeMatchedParameterSet  *
**************************/

void RARG_freeMatchedParameterSet( rarg_matched_parameter_set_t* rarg_matched_parameter_set )	{

	rarg_matched_parameter_t* rarg_matched_parameter			=	rarg_matched_parameter_set->parameters;
	rarg_matched_parameter_t* rarg_next_matched_parameter	=	NULL;
	while ( rarg_matched_parameter != NULL )	{
		rarg_next_matched_parameter = rarg_matched_parameter->next;
		free( rarg_matched_parameter );
		rarg_matched_parameter = rarg_next_matched_parameter;
	}
	free( rarg_matched_parameter_set );
}
