#include "rb_Rargs_free.h"

/*********************
*  freeDescriptors  *
*********************/

void RARG_freeDescriptors( int argc, VALUE* args, rarg_descriptor_t* rarg_descriptor )	{	

	rarg_descriptor_t* rarg_descriptor_ptr;
	while ( rarg_descriptor != NULL )	{
		rarg_descriptor_ptr = rarg_descriptor;
		rarg_descriptor	= rarg_descriptor->next;
		free( rarg_descriptor_ptr );
	}
}

/********************
*  freeParameters  *
********************/

void RARG_freeParameters( int argc, VALUE* args, rarg_parameter_t* rarg_parameter )	{
	
	rarg_parameter_t* rarg_parameter_ptr	=	rarg_parameter;
	while ( rarg_parameter != NULL )	{
		rarg_parameter_ptr = rarg_parameter;
		rarg_parameter = rarg_parameter->next;
		free( rarg_parameter_ptr );
	}
}

/***********************************
*  freeAllowedAndProhibitedTypes  *
***********************************/

void RARG_freeAllowedAndProhibitedTypes( rarg_allowed_type_t* rarg_allowed_type, VALUE rb_arg )	{

	rarg_allowed_type_t* rarg_allowed_type_ptr;
	
	while ( rarg_allowed_type != NULL )	{
		rarg_allowed_type_ptr = rarg_allowed_type;
		rarg_allowed_type = rarg_allowed_type->next;
		free( rarg_allowed_type_ptr );
	}
}

/**************************
*  freeAllowedHashTypes  *
**************************/

void RARG_freeAllowedHashTypes( rarg_allowed_type_t* rarg_allowed_type, VALUE rb_hash_arg )	{
	RARG_freeAllowedHashKeyOrDataTypes( rarg_allowed_type->allowed_hash_key_types, rb_hash_arg );
	RARG_freeAllowedHashKeyOrDataTypes( rarg_allowed_type->allowed_hash_data_types, rb_hash_arg );
}

/***********************************
*  freeAllowedHashKeyOrDataTypes  *
***********************************/

void RARG_freeAllowedHashKeyOrDataTypes( rarg_allowed_type_t* rarg_allowed_hash_key_type, VALUE rb_hash_arg )	{

	rarg_allowed_type_t* rarg_allowed_hash_key_type_ptr;
	while ( rarg_allowed_hash_key_type != NULL )	{
		rarg_allowed_hash_key_type_ptr = rarg_allowed_hash_key_type;
		rarg_allowed_hash_key_type = rarg_allowed_hash_key_type->next;
		free( rarg_allowed_hash_key_type_ptr );
	}
}

/*************************
*  freeProhibitedTypes  *
*************************/

void RARG_freeProhibitedTypes( rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg )	{

	rarg_prohibited_type_t* rarg_prohibited_type_ptr;
	
	while ( rarg_prohibited_type != NULL )	{		
		rarg_prohibited_type_ptr = rarg_prohibited_type;
		rarg_prohibited_type = rarg_prohibited_type->next;
		free( rarg_prohibited_type_ptr );
	}

}

/*****************************
*  freeProhibitedHashTypes  *
*****************************/

void RARG_freeProhibitedHashTypes( rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_hash_arg )	{
	RARG_freeProhibitedHashKeyOrDataTypes( rarg_prohibited_type->prohibited_hash_key_types, rb_hash_arg );
	RARG_freeProhibitedHashKeyOrDataTypes( rarg_prohibited_type->prohibited_hash_data_types, rb_hash_arg );
}

/**************************************
*  freeProhibitedHashKeyOrDataTypes  *
**************************************/

void RARG_freeProhibitedHashKeyOrDataTypes( rarg_prohibited_type_t* rarg_prohibited_hash_key_or_data_type, VALUE rb_hash_arg )	{

	rarg_prohibited_type_t* rarg_prohibited_hash_key_or_data_type_ptr;

	while ( rarg_prohibited_hash_key_or_data_type != NULL )	{
		rarg_prohibited_hash_key_or_data_type_ptr	=	rarg_prohibited_hash_key_or_data_type;
		rarg_prohibited_hash_key_or_data_type = rarg_prohibited_hash_key_or_data_type->next;
		free( rarg_prohibited_hash_key_or_data_type_ptr );
	}
}
