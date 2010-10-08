#include "rb_Rargs_define.h"
#include "rb_Rargs_error.h"

/***********************************************************************************************************************
																					Parameter Sets
***********************************************************************************************************************/

/************************
*  defineParameterSets  *
************************/

rarg_parameter_set_t* RARG_define_ParameterSets( rarg_parameter_set_t* parameter_set, ... )	{	

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

/***********************
*  defineParameterSet  *
***********************/

rarg_parameter_set_t* RARG_define_ParameterSet( rarg_parameter_t* parameter, ... )	{	

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

rarg_parameter_t* RARG_define_Parameter( rarg_possible_match_t* possible_match, ... )	{

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

/***********************************************************************************************************************
																					Possible Match Types
***********************************************************************************************************************/

/**********************************
*  RARG_define_PossibleTypeMatch  *
**********************************/

rarg_possible_match_t* RARG_define_PossibleTypeMatch( rarg_type_t type, ... )	{
	
	rarg_possible_match_t* possible_type_match;
	RI_CreatePossibleMatchWithType( possible_type_match );
	
	//	| together types
	va_list	var_args;
	va_start( var_args, type );

		while ( type )	{
		
			if ( possible_type_match->possible->types->type )	{
				possible_type_match->possible->types->type	|=	type;
			}
			else {
				possible_type_match->possible->types->type	=		type;
			}

			type = va_arg( var_args, rarg_type_t );
		}
	
	va_end( var_args );

	return possible_type_match;
}

/**************************************
*  RARG_define_PossibleAncestorMatch  *
**************************************/

rarg_possible_match_t* RARG_define_PossibleAncestorMatch( char* c_class_name, ... )	{

	rarg_possible_match_t*							possible_ancestors_match		= NULL;	
	RI_CreatePossibleMatch( possible_ancestors_match );
	RI_AssignPossibleMatchType( possible_ancestors_match, RARG_ANCESTOR );
	rarg_possible_ancestor_matches_t**	this_possible_ancestor_match			=	& possible_ancestors_match->possible->ancestors;

	va_list	var_args;
	va_start( var_args, c_class_name );

		while( c_class_name != NULL )	{
			
			if ( *this_possible_ancestor_match )	{
				this_possible_ancestor_match	=	& ( *this_possible_ancestor_match )->next;
			}
			*this_possible_ancestor_match	=	RI_AllocPossibleAncestorMatch();
			
			VALUE	rb_class_instance	=	rb_const_get(	rb_cBasicObject, rb_intern( c_class_name ) );

			( *this_possible_ancestor_match )->ancestor = rb_class_instance;

			c_class_name = va_arg( var_args, char* );
		}
		
	va_end( var_args );
	
	return possible_ancestors_match;
}

/**************************************
*  RARG_define_PossibleAncestorMatch  *
**************************************/

rarg_possible_match_t* RARG_define_PossibleAncestorInstanceMatch( VALUE rb_class_instance, ... )	{

	rarg_possible_match_t*							possible_ancestors_match		= NULL;	
	RI_CreatePossibleMatch( possible_ancestors_match );
	RI_AssignPossibleMatchType( possible_ancestors_match, RARG_ANCESTOR );
	rarg_possible_ancestor_matches_t**	this_possible_ancestor_match			=	& possible_ancestors_match->possible->ancestors;

	va_list	var_args;
	va_start( var_args, rb_class_instance );

		while( rb_class_instance != R_TERMINAL )	{
			
			if ( *this_possible_ancestor_match != NULL )	{
				this_possible_ancestor_match	=	& ( *this_possible_ancestor_match )->next;
			}
			*this_possible_ancestor_match	=	RI_AllocPossibleAncestorMatch();
			
			( *this_possible_ancestor_match )->ancestor = rb_class_instance;

			rb_class_instance = va_arg( var_args, VALUE );
		}
		
	va_end( var_args );
	
	return possible_ancestors_match;
}

/************************************
*  RARG_define_PossibleMethodMatch  *
************************************/

rarg_possible_match_t* RARG_define_PossibleMethodMatch( char* c_method, ... )	{

	rarg_possible_match_t*						possible_method_match		= NULL;	
	rarg_possible_method_matches_t**	this_method_match				=	& possible_method_match->possible->methods;

	va_list	var_args;
	va_start( var_args, c_method );

		while( c_method != NULL )	{
			
			if ( *this_method_match )	{
				this_method_match		=	& ( *this_method_match )->next;
				*this_method_match	=	RI_AllocPossibleMethodMatch();				
			}
			( *this_method_match )->method_id = rb_intern( c_method );

			c_method = va_arg( var_args, char* );
		}
		
	va_end( var_args );

	return possible_method_match;
}

/**********************************
*  RARG_define_PossibleHashMatch  *
**********************************/

rarg_possible_match_t* RARG_define_PossibleHashMatch(	rarg_possible_hash_key_data_match_t*	possible_key_match, 
																											rarg_possible_hash_key_data_match_t*	possible_data_match )	{

	rarg_possible_match_t*					possible_hash_match		= NULL;	
	RI_CreatePossibleMatchWithHash( possible_hash_match );

	possible_hash_match->possible->hash->possible_key_match			=	possible_key_match;
	possible_hash_match->possible->hash->possible_data_match		=	possible_data_match;

	return possible_hash_match;
}

	/*************************************************
	*  RARG_define_PossibleHashMatch_KeyOrDataMatch  *
	*************************************************/

	rarg_possible_hash_key_data_match_t* RARG_define_PossibleHashMatch_KeyOrDataMatch( rarg_possible_match_t* possible_match, ... )	{

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
		
		rarg_possible_hash_key_data_match_t*	possible_hash_key_or_data_match	=	calloc( 1, sizeof( rarg_possible_hash_key_data_match_t ) );
		
		possible_hash_key_or_data_match->possible_match	=	root_possible_match;
		
		return possible_hash_key_or_data_match;
	}

	/***********************************************
	*  RARG_define_PossibleHashMatch_indexesMatch  *
	***********************************************/

	rarg_possible_hash_index_match_t* RARG_define_PossibleHashMatch_indexesMatch(	char*	c_index, ... )	{
		
		rarg_possible_hash_index_match_t*		possible_hash_indexes		=	NULL;
		rarg_possible_hash_index_match_t**	this_index_match				=	& possible_hash_indexes;

		va_list	var_args;
		va_start( var_args, c_index );

			while( c_index != NULL )	{
				
				//	use instance function to define
				if ( ( *this_index_match )->index_name != NULL )	{
					this_index_match	=	& ( *this_index_match )->next;
				}
				*this_index_match	=	calloc( 1, sizeof( rarg_possible_hash_index_match_t ) );
				( *this_index_match )->index_name	=	c_index;
				
				c_index = va_arg( var_args, char* );
			}
			
		va_end( var_args );
		
		return possible_hash_indexes;
	}
	
/********************************
*  RARG_define_Block_procMatch  *
********************************/

rarg_possible_match_t* RARG_define_Block_procMatch()	{

	rarg_possible_match_t*						possible_block_proc_match		= NULL;	
	RI_CreatePossibleMatchWithBlock(	possible_block_proc_match );

	return possible_block_proc_match;
}

/**********************************
*  RARG_define_Block_lambdaMatch  *
**********************************/

rarg_possible_match_t* RARG_define_Block_lambdaMatch()	{

	rarg_possible_match_t*	possible_lambda_match	=	RARG_define_Block_procMatch();
	
	possible_lambda_match->possible->block->lambda_instead_of_proc	=	TRUE;
	
	return possible_lambda_match;
}

/***********************************************************************************************************************
																					Possible Match Options
***********************************************************************************************************************/

	/***********************************************
	*  RARG_define_ParameterSet_requireExactMatch  *
	***********************************************/

	rarg_parameter_set_t* RARG_define_ParameterSet_requireExactMatch(	rarg_parameter_set_t*		parameter_set, ... )	{	

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

		
	/******************************************
	*  RARG_define_PossibleMatch_setOptional  *
	******************************************/

	rarg_parameter_t* RARG_define_PossibleMatch_setOptional( rarg_parameter_t*	parameter, ... )	{

		va_list	var_args;
		va_start( var_args, parameter );

			while ( parameter != NULL )	{
				parameter->optional	=	TRUE;
				parameter = va_arg( var_args, rarg_parameter_t* );
			}
			
		va_end( var_args );
		
		return parameter;
	}

	/*****************************************
	*  RARG_define_PossibleBlockMatch_arity  *
	*****************************************/

	rarg_possible_match_t* RARG_define_PossibleBlockMatch_arity( rarg_possible_match_t*	possible_match, int arity, ... )	{

		rarg_possible_block_match_arity_t**	possible_block_arity_match_ptr	=	& possible_match->possible->block->possible_arity;

		va_list	var_args;
		va_start( var_args, arity );
			
			while ( arity != R_TERMINATE_ARITY )	{
				if ( *possible_block_arity_match_ptr != NULL )	{
					//	move to end of any defined arities
					while ( *( possible_block_arity_match_ptr = & ( *possible_block_arity_match_ptr )->next ) != NULL );
				}
				*possible_block_arity_match_ptr = calloc( 1, sizeof( rarg_possible_block_match_arity_t ) );

				( *possible_block_arity_match_ptr )->arity	=	arity;
				arity = va_arg( var_args, int );
			}
			
		va_end( var_args );
		
		return possible_match;
	}


/***********************************************************************************************************************
																							Assignment
***********************************************************************************************************************/
	
	/*******************************************
	*  definePossibleMatch_assignMatchToValue  *
	*******************************************/

	rarg_possible_match_t* RARG_define_PossibleMatch_assignMatchToValue(	rarg_possible_match_t*	possible_match, 
																																				VALUE*									receiver )	{

		possible_match->receiver	=	receiver;

		return possible_match;
	}

	/*********************************************************
	*  definePossibleMatch_assignHashForKeyDataMatchToValue  *
	*********************************************************/

	rarg_possible_hash_key_data_match_t* RARG_define_PossibleMatch_assignHashForKeyDataMatchToValue(	rarg_possible_hash_key_data_match_t*	possible_hash_key_or_data_match, 
																																																		VALUE*																receiver )	{

		possible_hash_key_or_data_match->assign_parent_hash_for_match		=	TRUE;
		possible_hash_key_or_data_match->possible_match->receiver				=	receiver;

		return possible_hash_key_or_data_match;
	}

/***********************************************************************************************************************
																							Descriptions
***********************************************************************************************************************/

/*****************************************
*  RARG_define_ParameterSet_description  *
*****************************************/

rarg_parameter_set_t* RARG_define_ParameterSet_description(	rarg_parameter_set_t*		parameter_set,
																														int											order_ranking,
																														char*										description, ... )	{	

	rarg_description_t**		this_description	=	& parameter_set->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *this_description == NULL )	{
				*this_description = calloc( 1, sizeof( rarg_description_t ) );
			}
			else if ( *( *this_description )->description != '\0' )	{
				( *this_description )->next		= calloc( 1, sizeof( rarg_description_t ) );
				this_description							=	& ( *this_description )->next;
			}
			( *this_description )->description		= description;
			( *this_description )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return parameter_set;
}

/**************************************
*  RARG_define_Parameter_description  *
**************************************/

rarg_parameter_t* RARG_define_Parameter_description(	rarg_parameter_t*		parameter,
																											int									order_ranking,
																											char*								description, ... )	{	

	rarg_description_t**		this_description	=	& parameter->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *( *this_description )->description != '\0' )	{
				( *this_description )->next		= calloc( 1, sizeof( rarg_description_t ) );
				this_description													=	& ( *this_description )->next;
			}
			( *this_description )->description		= description;
			( *this_description )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return parameter;
}

/******************************************
*  RARG_define_PossibleMatch_description  *
******************************************/

rarg_possible_match_t* RARG_define_PossibleMatch_description(	rarg_possible_match_t*	possible_match,
																															int											order_ranking,
																															char*										description, ... )	{	

	rarg_description_t**		this_description	=	& possible_match->description;
	
	va_list	var_args;
	va_start( var_args, description );

		while ( description != NULL )	{
			
			if ( *( *this_description )->description != '\0' )	{
				( *this_description )->next		= calloc( 1, sizeof( rarg_description_t ) );
				this_description													=	& ( *this_description )->next;
			}
			( *this_description )->description		= description;
			( *this_description )->order_ranking	= order_ranking;

			description = va_arg( var_args, char* );
		}
	
	va_end( var_args );	
		
	return possible_match;
}

