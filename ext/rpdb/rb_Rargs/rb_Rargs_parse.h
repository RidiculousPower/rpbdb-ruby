#ifndef RB_RARGS_PARSE
	#define RB_RARGS_PARSE

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"

int RARG_parseParameterSetsForMatch(	int										argc, 
																			VALUE*								args, 
																			rarg_parameter_set_t*		parameter_sets );
rarg_matched_parameter_set_t* RARG_parseParameterSets(	int										argc, 
																									VALUE*								args, 
																									rarg_parameter_set_t*		parameter_set );	
int RARG_parseParameters(	int														argc, 
													VALUE*												args, 
													rarg_parameter_t*							parameter, 
													rarg_matched_parameter_set_t*		matched_parameter_set );
BOOL RARG_parsePossibleMatches(	rarg_parameter_t*							parameter, 
																VALUE													rb_arg, 
																rarg_matched_parameter_t**		matched_parameter );
BOOL RARG_parsePossibleHashMatches(	rarg_parameter_t*							parameter, 
																		rarg_possible_match_t*				possible_match, 
																		VALUE													rb_hash_arg,
																		VALUE													rb_key,
																		VALUE													rb_data,
																		rarg_matched_parameter_t**		matched_parameter );
BOOL RARG_parsePossibleHashKeyOrDataMatches(	rarg_parameter_t*							parameter, 
																							rarg_possible_match_t*				possible_hash_key_or_data, 
																							VALUE													rb_hash_arg, 
																							VALUE													rb_hash_key_or_data, 
																							rarg_matched_parameter_t**		matched_parameter );
BOOL RARG_parseAllowedTypes(	rarg_parameter_t*							parameter, 
															rarg_possible_match_t*				possible_match, 
															VALUE													rb_arg, 
															rarg_matched_parameter_t**		matched_parameter, 
															VALUE													rb_hash_for_key_data_check );

BOOL RARG_parseAllowedClasses(	rarg_possible_match_t*	possible_class_match,
																VALUE										rb_arg );

BOOL RARG_parseIndexes(	rarg_possible_match_t*			possible_index_match,
												VALUE												rb_arg,
												rarg_matched_parameter_t**	matched_parameter_ptr );
	
#endif