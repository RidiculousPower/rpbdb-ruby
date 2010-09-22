#ifndef RB_RARGS_FREE
	#define RB_RARGS_FREE

	#include <ruby.h>
	#include "rb_Rargs_types.h"

	void RARG_freeDescriptors( int argc, VALUE* args, rarg_descriptor_t* rarg_descriptor );	
	void RARG_freeParameters( int argc, VALUE* args, rarg_parameter_t* rarg_parameter );
	void RARG_freeAllowedAndProhibitedTypes( rarg_allowed_type_t* rarg_allowed_type, VALUE rb_arg );
	void RARG_freeAllowedHashTypes( rarg_allowed_type_t* rarg_allowed_type, VALUE rb_hash_arg );
	void RARG_freeAllowedHashKeyOrDataTypes( rarg_allowed_type_t* rarg_allowed_hash_key_type, VALUE rb_hash_arg );
	void RARG_freeProhibitedTypes( rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg );
	void RARG_freeProhibitedHashTypes( rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_hash_arg );
	void RARG_freeProhibitedHashKeyOrDataTypes( rarg_prohibited_type_t* rarg_prohibited_hash_key_or_data_type, VALUE rb_hash_arg );
	
#endif