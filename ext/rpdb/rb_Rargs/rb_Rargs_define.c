#include "rb_Rargs_define.h"

/************************
*  defineParameterSets  *
************************/

rarg_parameter_set_t* RARG_defineParameterSets( rarg_parameter_set_t* parameter_set, ... )	{	

	rarg_parameter_set_t*		root_parameter_set	=	parameter_set;
	rarg_parameter_set_t**	this_parameter_set	=	& root_parameter_set;

	//	for each possible type, create FIFO chain in root_possible_match
	va_list	var_args;
	va_start( var_args, parameter_set );
	
		while ( parameter_set != NULL )	{
			
			//	make sure parameter sets are chained together at the end; it is possible we get chains of parameter sets
			if ( parameter_set != *this_parameter_set )	{
				while ( *this_parameter_set != NULL )	{
					this_parameter_set							=	& ( *this_parameter_set )->next;
				}
				*this_parameter_set = parameter_set;
				this_parameter_set	=	& ( *this_parameter_set )->next;
			}
			
			parameter_set = va_arg( var_args, rarg_parameter_set_t* );
		}
	
	va_end( var_args );
	
	return root_parameter_set;
}

/********************************
*  defineParameterSetDescriber  *
********************************/

rarg_parameter_set_t* RARG_defineParameterSet_requireExactMatch(	rarg_parameter_set_t*		parameter_set, ... )	{	

	rarg_parameter_set_t*		root_parameter_set	=	parameter_set;
	rarg_parameter_set_t**	this_parameter_set	=	& parameter_set;
	
	va_list	var_args;
	va_start( var_args, parameter_set );

		while ( parameter_set != NULL )	{
			parameter_set->require_exact	=	TRUE;
			if ( parameter_set != *this_parameter_set )	{
				while ( ( *this_parameter_set )->next != NULL )	{
					this_parameter_set	=	& ( *this_parameter_set )->next;			
				}
				( *this_parameter_set )->next	=	parameter_set;
				this_parameter_set	=	& ( *this_parameter_set )->next;
			}
			parameter_set = va_arg( var_args, rarg_parameter_set_t* );
		}
	
	va_end( var_args );	
	
	return root_parameter_set;
}

/********************************
*  defineParameterSetDescriber  *
********************************/

rarg_parameter_set_t* RARG_defineParameterSetDescriber(	rarg_parameter_set_t*		parameter_set,
																												int											order_ranking,
																												char*										description, ... )	{	

	rarg_describer_t**		this_describer	=	& parameter_set->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *this_describer == NULL )	{
				*this_describer = calloc( 1, sizeof( rarg_describer_t ) );
			}
			else if ( *( *this_describer )->description != '\0' )	{
				( *this_describer )->next		= calloc( 1, sizeof( rarg_describer_t ) );
				this_describer													=	& ( *this_describer )->next;
			}
			( *this_describer )->description		= description;
			( *this_describer )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return parameter_set;
}

/*****************************
*  defineParameterDescriber  *
*****************************/

rarg_parameter_t* RARG_defineParameterDescriber(	rarg_parameter_t*		parameter,
																									int									order_ranking,
																									char*								description, ... )	{	

	rarg_describer_t**		this_describer	=	& parameter->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *( *this_describer )->description != '\0' )	{
				( *this_describer )->next		= calloc( 1, sizeof( rarg_describer_t ) );
				this_describer													=	& ( *this_describer )->next;
			}
			( *this_describer )->description		= description;
			( *this_describer )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return parameter;
}

/*********************************
*  definePossibleMatchDescriber  *
*********************************/

rarg_possible_match_t* RARG_definePossibleMatchDescriber(	rarg_possible_match_t*	possible_match,
																													int											order_ranking,
																													char*										description, ... )	{	

	rarg_describer_t**		this_describer	=	& possible_match->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *( *this_describer )->description != '\0' )	{
				( *this_describer )->next		= calloc( 1, sizeof( rarg_describer_t ) );
				this_describer													=	& ( *this_describer )->next;
			}
			( *this_describer )->description		= description;
			( *this_describer )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return possible_match;
}

/***********************
*  defineParameterSet  *
***********************/

rarg_parameter_set_t* RARG_defineParameterSet( rarg_parameter_t* parameter, ... )	{	

	rarg_parameter_set_t*	parameter_set			=	calloc( 1, sizeof( rarg_parameter_set_t ) );
	rarg_parameter_t**		this_parameter		=	& parameter_set->parameters;
	
	va_list	var_args;
	va_start( var_args, parameter );
	
		while ( parameter != NULL )	{

			//	make sure parameter are chained together at the end; it is possible we get chains of parameter
			while ( *this_parameter != NULL )	{
				this_parameter	=	& ( *this_parameter )->next;
			}
			*this_parameter = parameter;

			parameter = va_arg( var_args, rarg_parameter_t* );
		}
	
	va_end( var_args );
	
	return parameter_set;
}


/********************
*  defineParameter  *
********************/

rarg_parameter_t* RARG_defineParameter( rarg_possible_match_t* possible_match, ... )	{

	rarg_parameter_t*				parameter							=	calloc( 1, sizeof( rarg_parameter_t ) );
	rarg_possible_match_t**	this_possible_match		=	& parameter->possible_match;

	//	for each possible match, create FIFO chain in parameter
	va_list	var_args;
	va_start( var_args, possible_match );
	
		while ( possible_match != NULL )	{
			
			//	make sure possible matches are chained together at the end; it is possible we get chains of possible matches
			while ( *this_possible_match != NULL )	{
				this_possible_match = & ( *this_possible_match )->next;
			}
			*this_possible_match	=	possible_match;
			
			possible_match = va_arg( var_args, rarg_possible_match_t* );
		}
	
	va_end( var_args );
	
	return parameter;
}

/****************************************
*  RARG_defineNewPossibleMatchWithType  *
****************************************/

rarg_possible_match_t* RARG_defineNewPossibleMatchWithType( rarg_type_t type, ... )	{

	rarg_possible_match_t*	possible_match = calloc( 1, sizeof( rarg_possible_match_t ) );
	
	//	| together types
	va_list	var_args;
	va_start( var_args, type );

		while ( type )	{
		
			if ( possible_match->type )	{
				possible_match->type	|=	type;
			}
			else {
				possible_match->type	=		type;
			}

			type = va_arg( var_args, rarg_type_t );
		}
	
	va_end( var_args );

	return possible_match;
}

	/*****************************
	*  definePossibleMatch_hash  *
	*****************************/

	rarg_possible_match_t* RARG_defineNewPossibleMatchHash(	rarg_possible_match_t*	possible_key_match, 
																													rarg_possible_match_t*	possible_data_match )	{

		rarg_possible_match_t*	possible_hash_match = RARG_defineNewPossibleMatchWithType( R_HASH, R_TERMINAL );

		possible_hash_match->possible_hash_key_match		=	possible_key_match;
		possible_hash_match->possible_hash_data_match		=	possible_data_match;

		return possible_hash_match;
	}

	/***************************************************
	*  definePossibleMatch_possibleHashKeyOrDataMatch  *
	***************************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_keyOrData( rarg_possible_match_t* possible_match, ... )	{

		rarg_possible_match_t*	root_possible_match	=	possible_match;
		rarg_possible_match_t**	this_possible_match	=	& root_possible_match->next;

		//	for each possible type, create FIFO chain in root_possible_match
		va_list	var_args;
		va_start( var_args, possible_match );
		
			while ( possible_match != NULL )	{
				
				//	make sure possible matches are chained together at the end; it is possible we get chains of possible matches
				if ( possible_match != *this_possible_match )	{
					while ( *this_possible_match != NULL )	{
						this_possible_match		=	& ( *this_possible_match )->next;
					}
					*this_possible_match	= possible_match;
					this_possible_match		=	& ( *this_possible_match )->next;
				}
				
				possible_match = va_arg( var_args, rarg_possible_match_t* );
			}
		
		va_end( var_args );
		
		return root_possible_match;
	}
	
	/*************************************
	*  definePossibleMatchForHash_index  *
	*************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_index(	char*	c_index, ... )	{
		
		rarg_possible_match_t*	possible_hash_indexes			=	RARG_defineNewPossibleMatchWithType( R_STRING_SYMBOL );
		rarg_possible_match_t**	this_index_match					=	& possible_hash_indexes;

		va_list	var_args;
		va_start( var_args, c_index );

			while( c_index != NULL )	{
				
				//	use instance function to define
				if ( ( *this_index_match )->index_name != NULL )	{
					this_index_match	=	& ( *this_index_match )->next;
					*this_index_match	=	RARG_defineNewPossibleMatchWithType( R_STRING_SYMBOL );
				}
				( *this_index_match )->index_name	=	c_index;
				
				c_index = va_arg( var_args, char* );
			}
			
		va_end( var_args );
		
		return possible_hash_indexes;
	}

	/*************************************
	*  definePossibleMatchForHash_class  *
	*************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_class(	char*	c_class_name, ... )	{

		rarg_possible_match_t*	possible_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE );
		rarg_possible_match_t**	this_class_match			=	& possible_class_match;

		va_list	var_args;
		va_start( var_args, c_class_name );

			while( c_class_name != NULL )	{
				
				//	get class instance
				VALUE	rb_class_instance	=	rb_const_get(	rb_cBasicObject, rb_intern( c_class_name ) );
				
				( *this_class_match )->ruby_class	=	rb_class_instance;
				
				if ( ( *this_class_match )->ruby_class != 0 )	{
					this_class_match	=	& ( *this_class_match )->next;
					*this_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE ); 
				}
				( *this_class_match )->ruby_class = rb_class_instance;

				c_class_name = va_arg( var_args, char* );
			}
			
		va_end( var_args );
		
		return possible_class_match;
	}
	
	/*********************************************
	*  definePossibleMatchForHash_classInstance  *
	*********************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_classInstance(	VALUE rb_class_instance, ... )	{

		rarg_possible_match_t*	possible_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE );
		rarg_possible_match_t**	this_class_match			=	& possible_class_match;

		va_list	var_args;
		va_start( var_args, rb_class_instance );

			while ( rb_class_instance != Qnil )	{
				
				if ( ( *this_class_match )->ruby_class != 0 )	{
					this_class_match	=	& ( *this_class_match )->next;
					*this_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE ); 
				}
				( *this_class_match )->ruby_class	=	rb_class_instance;
				
				rb_class_instance = va_arg( var_args, VALUE );
			}
			
		va_end( var_args );
		
		return possible_class_match;
	}

	/*****************************************
	*  definePossibleMatchForHash_blockProc  *
	*****************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_blockProc(	VALUE*	receiver )	{

		rarg_possible_match_t*	possible_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE );

		possible_class_match->expect_block_proc	=	TRUE;

	}

	/*******************************************
	*  definePossibleMatchForHash_blockLambda  *
	*******************************************/

	rarg_possible_match_t* RARG_definePossibleMatchForHash_blockProc(	VALUE*	receiver )	{

		rarg_possible_match_t*	possible_class_match	=	RARG_defineNewPossibleMatchWithType( R_INSTANCE );

		possible_class_match->expect_block_lambda	=	TRUE;

	}
	
	/************************************
	*  definePossibleMatch_setRequired  *
	************************************/

	rarg_possible_match_t* RARG_definePossibleMatch_setOptional( rarg_possible_match_t*	possible_match, ... )	{

		va_list	var_args;
		va_start( var_args, possible_match );

			while ( possible_match != NULL )	{
				possible_match->optional	=	TRUE;
				possible_match = va_arg( var_args, rarg_possible_match_t* );
			}
			
		va_end( var_args );
		
		return possible_match;
	}
	
	/*******************************************
	*  definePossibleMatch_assignMatchToValue  *
	*******************************************/

	rarg_possible_match_t* RARG_definePossibleMatch_assignMatchToValue(	rarg_possible_match_t*	possible_match, 
																																			VALUE*									receiver )	{

		possible_match->receiver	=	receiver;

		return possible_match;
	}

	/*********************************************************
	*  definePossibleMatch_assignHashForKeyDataMatchToValue  *
	*********************************************************/

	rarg_possible_match_t* RARG_definePossibleMatch_assignHashForKeyDataMatchToValue(	rarg_possible_match_t*	possible_match, 
																																										VALUE*									receiver )	{

		possible_match->assign_parent_hash_for_key_or_data_self	=	TRUE;
		possible_match->receiver	=	receiver;

		return possible_match;
	}

