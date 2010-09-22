#ifndef RB_RARGS_PARSER
	#define RB_RARGS_PARSER

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"
		
	rarg_descriptor_t* RARG_parseDescriptors( int argc, VALUE* args, rarg_descriptor_t* rarg_descriptor );	
	int RARG_parseParameters( int argc, VALUE* args, rarg_parameter_t* rarg_parameter );
	int RARG_parseAllowedAndProhibitedTypes( rarg_parameter_t* rarg_parameter, VALUE rb_arg );
	int RARG_parseAllowedHashTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_type, VALUE rb_hash_arg );
	int RARG_parseAllowedHashKeyOrDataTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_hash_key_type, VALUE rb_hash_arg );
	int RARG_parseProhibitedTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg );
	int RARG_parseProhibitedHashTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_hash_arg );
	int RARG_parseProhibitedHashKeyOrDataTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_hash_key_or_data_type, VALUE rb_hash_arg );
	int RARG_switchAllowedTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_type, VALUE rb_arg );
	int RARG_switchProhibitedTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg );
	
#endif