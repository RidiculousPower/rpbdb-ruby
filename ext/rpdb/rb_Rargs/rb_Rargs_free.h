#ifndef RB_RARGS_FREE
	#define RB_RARGS_FREE

	#include <ruby.h>
	#include "rb_Rargs_types.h"

void RARG_freeParameterSets( rarg_parameter_set_t* rarg_parameter_set );	
void RARG_freeParameters( rarg_parameter_t* rarg_parameter );
void RARG_freePossibleMatches( rarg_possible_match_t* rarg_possible_match );
void RARG_freePossibleHashMatches( rarg_possible_match_t* rarg_possible_match );
void RARG_freePossibleHashKeyOrDataMatches( rarg_possible_match_t* rarg_allowed_hash_key_type );
void RARG_freeMatchedParameterSet( rarg_matched_parameter_set_t* rarg_matched_parameter_set );
	
#endif