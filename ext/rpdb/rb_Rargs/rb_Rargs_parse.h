#ifndef RB_RARGS_PARSE
	#define RB_RARGS_PARSE

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"

int RARG_parse_ParameterSetsForMatch(	int											argc, 
																			VALUE*									args, 
																			rarg_parameter_set_t*		parameter_sets );	
rarg_matched_parameter_set_t* RARG_parse_ParameterSets(	int											argc, 
																												VALUE*									args, 
																												rarg_parameter_set_t*		parameter_set);	
int RARG_parse_Parameters(	int															argc, 
														VALUE*													args, 
														rarg_parameter_t*								parameter, 
														rarg_matched_parameter_set_t*		matched_parameter_set );
BOOL RARG_parse_PossibleMatches(	rarg_parameter_t*							parameter, 
																	VALUE													rb_arg, 
																	rarg_matched_parameter_t**		matched_parameter );
BOOL RARG_parse_PossibleMatch(		rarg_possible_match_t*				possible_match, 
																	VALUE													rb_arg, 
																	rarg_matched_parameter_t**		matched_parameter);
BOOL RARG_parse_PossibleBlockMatch(		rarg_possible_match_t*				possible_match, 
																			rarg_matched_parameter_t**		matched_parameter);
BOOL RARG_parse_PossibleBlockArityMatch(	rarg_possible_block_match_arity_t*	possible_arity_match,
																					VALUE																rb_arity	);
BOOL RARG_parse_PossibleHashMatch(		rarg_possible_match_t*				possible_match, 
																			VALUE													rb_arg, 
																			rarg_matched_parameter_t**		matched_parameter);
	BOOL RARG_parse_PossibleIndexMatch(	rarg_possible_match_t*			possible_match,
																			VALUE												rb_arg,
																			rarg_matched_parameter_t**	matched_parameter_ptr );
	BOOL RARG_parse_PossibleHashKeyOrDataMatch(	rarg_possible_hash_key_data_match_t*		possible_hash_key_or_data, 
																							VALUE																		rb_hash_arg, 
																							VALUE																		rb_hash_key_or_data, 
																							rarg_matched_parameter_t**							matched_parameter );
BOOL RARG_parse_PossibleTypeMatch(	rarg_possible_match_t*				possible_match, 
																		VALUE													rb_arg, 
																		rarg_matched_parameter_t**		matched_parameter_ptr );
BOOL RARG_parse_PossibleAncestorMatches(	rarg_possible_match_t*				possible_match, 
																					VALUE													rb_arg, 
																					rarg_matched_parameter_t**		matched_parameter);
BOOL RARG_parse_PossibleMethodMatches(		rarg_possible_match_t*				possible_match, 
																					VALUE													rb_arg, 
																					rarg_matched_parameter_t**		matched_parameter);

#endif