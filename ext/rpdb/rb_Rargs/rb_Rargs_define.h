#ifndef RB_RARGS_DEFINE
	#define RB_RARGS_DEFINE

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"

rarg_parameter_set_t* RARG_defineParameterSets( rarg_parameter_set_t* parameter_set, ... );
rarg_parameter_set_t* RARG_defineParameterSet_requireExactMatch(	rarg_parameter_set_t*		parameter_set, ... );
rarg_parameter_set_t* RARG_defineParameterSetDescriber(	rarg_parameter_set_t*		parameter_set,
																												int											order_ranking,
																												char*										description, ... );
rarg_parameter_t* RARG_defineParameterDescriber(	rarg_parameter_t*		parameter,
																									int									order_ranking,
																									char*								description, ... );
rarg_possible_match_t* RARG_definePossibleMatchDescriber(	rarg_possible_match_t*	possible_match,
																													int											order_ranking,
																													char*										description, ... );
rarg_parameter_set_t* RARG_defineParameterSet( rarg_parameter_t* parameter, ... );	
rarg_parameter_t* RARG_defineParameter( rarg_possible_match_t* possible_match, ... );
rarg_possible_match_t* RARG_defineNewPossibleMatchWithType( rarg_type_t type, ... );
	rarg_possible_match_t* RARG_defineNewPossibleMatchHash(	rarg_possible_match_t*	possible_key_match, 
																													rarg_possible_match_t*	possible_data_match );
	rarg_possible_match_t* RARG_definePossibleMatchForHash_index( char* c_index, ... );
	rarg_possible_match_t* RARG_definePossibleMatchForHash_class( char* c_class_name, ... );
	rarg_possible_match_t* RARG_definePossibleMatchForHash_classInstance( VALUE class_instance, ... );
	rarg_possible_match_t* RARG_definePossibleMatch_setOptional( rarg_possible_match_t*	possible_match, ... );
	rarg_possible_match_t* RARG_definePossibleMatch_assignMatchToValue(	rarg_possible_match_t*	rarg_possible_match_ptr, 
																																			VALUE*									value_receiver );
	rarg_possible_match_t* RARG_definePossibleMatch_assignHashForKeyDataMatchToValue(	rarg_possible_match_t*	possible_match, 
																																										VALUE*									receiver );
	rarg_possible_match_t* RARG_definePossibleMatchForHash_keyOrData( rarg_possible_match_t*	rarg_possible_match, ... );
	
#endif