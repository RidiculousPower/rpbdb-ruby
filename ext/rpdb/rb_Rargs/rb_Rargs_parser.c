#include "rb_Rargs_parser.h"

/*********************
*  parseDescriptors  *
*********************/

rarg_descriptor_t* RARG_parseDescriptors( int argc, VALUE* args, rarg_descriptor_t* rarg_descriptor )	{	

	while ( rarg_descriptor != NULL )	{

		// if all parameters in a descriptor exactly match args, descriptor is returned to parse args
		if ( RARG_parseParameters( argc, args, rarg_descriptor->parameters ) )	{
			//	success - matched descriptor
			break;
		}
		
		rarg_descriptor	= rarg_descriptor->next;
	}
	//	success = match
	//	failure = NULL
	return rarg_descriptor;
}

/********************
*  parseParameters  *
********************/

int RARG_parseParameters( int argc, VALUE* args, rarg_parameter_t* rarg_parameter )	{

	int rarg_which_parameter	=	0;                                                                                                          
	if ( rarg_parameter != NULL )	{

		while ( rarg_parameter != NULL )	{
			
			VALUE	rb_arg	=	args[ rarg_which_parameter ];
			
			// loop index starts with 1 to match argc, which is 1-based																															
			rarg_which_parameter++;

			// if we run out of args and have more parameters, continue to next descriptor                                           
			if ( rarg_which_parameter > argc )	{                                                                                                 
				// move to the next descriptor	                                                                  
				return FALSE;
			}			                                                                                                                      

			// if parsing allowed types fails, break from parsing these parameters and go to next descriptor
			if ( ! RARG_parseAllowedAndProhibitedTypes( rarg_parameter, rb_arg ) ) {
				return FALSE;
			}
			
			rarg_parameter = rarg_parameter->next;
		}
	}
	
	// if we got here and have the same number of parameters and args we matched
	if ( rarg_which_parameter == argc )	{
		return TRUE;
	}
	
	// if we get here we didn't match
	return FALSE;
}

/***********************************
*  parseAllowedAndProhibitedTypes  *
***********************************/

int RARG_parseAllowedAndProhibitedTypes( rarg_parameter_t* rarg_parameter, VALUE rb_arg )	{
	
	rarg_allowed_type_t*	rarg_allowed_type	=	rarg_parameter->allowed_types;
	
	// test each allowed type for this parameter slot to see if this arg matches parameter
	while ( rarg_allowed_type != NULL )	{
		
		int	switch_result = RARG_switchAllowedTypes( rarg_parameter, rarg_allowed_type, rb_arg );
		if ( switch_result != RARG_CONTINUE )	{
			return switch_result;
		}
		rarg_allowed_type = rarg_allowed_type->next;
	}
	// if we get here we didn't match
	return FALSE;
}

/**************************
*  parseAllowedHashTypes  *
**************************/

int RARG_parseAllowedHashTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_type, VALUE rb_hash_arg )	{

	if (		! RARG_parseAllowedHashKeyOrDataTypes( rarg_parameter, rarg_allowed_type->allowed_hash_key_types, rb_hash_arg )
			||	! RARG_parseAllowedHashKeyOrDataTypes( rarg_parameter, rarg_allowed_type->allowed_hash_data_types, rb_hash_arg ) )	{

		//	key or data did not match
		return FALSE;
	}
	
	// types matched
	return TRUE;
}

/***********************************
*  parseAllowedHashKeyOrDataTypes  *
***********************************/

int RARG_parseAllowedHashKeyOrDataTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_hash_key_type, VALUE rb_hash_arg )	{

	if ( rarg_allowed_hash_key_type )	{
		while ( rarg_allowed_hash_key_type != NULL )	{
			
			int	switch_result = RARG_switchAllowedTypes( rarg_parameter, rarg_allowed_hash_key_type, rb_hash_arg );
			if ( switch_result != RARG_CONTINUE )	{
				return switch_result;
			}
			rarg_allowed_hash_key_type = rarg_allowed_hash_key_type->next;
		}

		// if we get here we didn't match
		return FALSE;
	}
	//	if no key/data types are specified, any are allowed
	return TRUE;
}

/*************************
*  parseProhibitedTypes  *
*************************/

int RARG_parseProhibitedTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg )	{

	while ( rarg_prohibited_type != NULL )	{
		
		int	switch_result = RARG_switchProhibitedTypes( rarg_parameter, rarg_prohibited_type, rb_arg );
		if ( switch_result != RARG_CONTINUE )	{
			return switch_result;
		}
		rarg_prohibited_type = rarg_prohibited_type->next;
	}

	// if we got here we were not prohibited
	return FALSE;
}

/*****************************
*  parseProhibitedHashTypes  *
*****************************/

int RARG_parseProhibitedHashTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_hash_arg )	{

	if (		RARG_parseProhibitedHashKeyOrDataTypes( rarg_parameter, rarg_prohibited_type->prohibited_hash_key_types, rb_hash_arg )
			||	RARG_parseProhibitedHashKeyOrDataTypes( rarg_parameter, rarg_prohibited_type->prohibited_hash_data_types, rb_hash_arg ) )	{

		//	key or data did not match
		return TRUE;
	}
	
	// types matched
	return FALSE;
}

/**************************************
*  parseProhibitedHashKeyOrDataTypes  *
**************************************/

int RARG_parseProhibitedHashKeyOrDataTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_hash_key_or_data_type, VALUE rb_hash_arg )	{

	while ( rarg_prohibited_hash_key_or_data_type != NULL )	{
		
		int	switch_result = RARG_switchProhibitedTypes( rarg_parameter, rarg_prohibited_hash_key_or_data_type, rb_hash_arg );
		if ( switch_result != RARG_CONTINUE )	{
			return switch_result;
		}
		rarg_prohibited_hash_key_or_data_type = rarg_prohibited_hash_key_or_data_type->next;
	}

	// if we get here we didn't match
	return FALSE;
}

/***********************
*  switchAllowedTypes  *
***********************/

int RARG_switchAllowedTypes( rarg_parameter_t* rarg_parameter, rarg_allowed_type_t* rarg_allowed_type, VALUE rb_arg )	{
	
	int	rb_arg_type	=	TYPE( rb_arg );
	switch( rarg_allowed_type->type )	{			

		case T_NOT_NIL:
			// make sure RARGS_THIS_ARG_TYPE is not Qnil
			if ( rb_arg == Qnil )	{
				// type cannot be nil so descriptor cannot match
				return FALSE;
			}
			// check for prohibited exceptions to T_NOT_NIL via T_ANY case (so don't break)
		case T_ANY:
			// check for prohibited exceptions to T_ANY (or to T_NOT_NIL) by looping prohibited types for this parameter
			if ( RARG_parseProhibitedTypes( rarg_parameter, rarg_parameter->prohibited_types, rb_arg ) )	{
				return FALSE;
			}
			
			// if we have a hash, check key/data constraints to see if it matches this parameter
			if ( TYPE( rb_arg ) == T_HASH )	{
				// if our hash types match we match parameter, otherwise we don't
				return RARG_parseAllowedHashTypes( rarg_parameter, rarg_allowed_type, rb_arg );
			}
			// if we don't have a hash, we match
			return TRUE;
			break;
		
		default:
			if ( rb_arg_type == rarg_allowed_type->type )	{
				// this parameter matches acceptable type
				return TRUE;
				break;
			}
	}
	/* if the condition doesn't match we return a continue message */
	return RARG_CONTINUE;
}

/***********************
*  switchAllowedTypes  *
***********************/

int RARG_switchProhibitedTypes( rarg_parameter_t* rarg_parameter, rarg_prohibited_type_t* rarg_prohibited_type, VALUE rb_arg )	{
	
	int	rb_arg_type	=	TYPE( rb_arg );
	switch( rarg_prohibited_type->type )	{			
	
		default:
			if ( rb_arg_type == rarg_prohibited_type->type )	{
				// if we have a hash, check key/data constraints to see if it matches this parameter
				if ( rb_arg_type == T_HASH )	{
					// if our hash types match prohibited, we prohibit, otherwise we're fine
					return RARG_parseProhibitedHashTypes( rarg_parameter, rarg_prohibited_type, rb_arg );
				}
				// this parameter matches prohibited type
				return TRUE;
			}
			break;
	}
	/* if the condition doesn't match we return a continue message */
	return RARG_CONTINUE;
}
