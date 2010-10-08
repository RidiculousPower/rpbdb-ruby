#ifndef RB_RARGS_DEFINE
	#define RB_RARGS_DEFINE

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"

	rarg_parameter_set_t* RARG_define_ParameterSets( rarg_parameter_set_t* parameter_set, ... );	
	rarg_parameter_set_t* RARG_define_ParameterSet( rarg_parameter_t* parameter, ... );	
	rarg_parameter_t* RARG_define_Parameter( rarg_possible_match_t* possible_match, ... );
	rarg_possible_match_t* RARG_define_PossibleTypeMatch( rarg_type_t type, ... );
	rarg_possible_match_t* RARG_define_PossibleAncestorMatch( char* c_class_name, ... );
	rarg_possible_match_t* RARG_define_PossibleAncestorInstanceMatch( VALUE rb_class_instance, ... );
	rarg_possible_match_t* RARG_define_PossibleMethodMatch( char* c_method, ... );
	rarg_possible_match_t* RARG_define_PossibleHashMatch(	rarg_possible_hash_key_data_match_t*	possible_key_match, 
																												rarg_possible_hash_key_data_match_t*	possible_data_match );
		rarg_possible_hash_key_data_match_t* RARG_define_PossibleHashMatch_KeyOrDataMatch( rarg_possible_match_t* possible_match, ... );
		rarg_possible_hash_index_match_t* RARG_define_PossibleHashMatch_indexesMatch(	char*	c_index, ... );
	rarg_possible_match_t* RARG_define_Block_procMatch();
	rarg_possible_match_t* RARG_define_Block_lambdaMatch();
		rarg_parameter_set_t* RARG_define_ParameterSet_requireExactMatch(	rarg_parameter_set_t*		parameter_set, ... );	
		rarg_parameter_t* RARG_define_PossibleMatch_setOptional( rarg_parameter_t*	parameter, ... );
		rarg_possible_match_t* RARG_define_PossibleBlockMatch_arity( rarg_possible_match_t*	possible_match, int arity, ... );
		rarg_possible_match_t* RARG_define_PossibleMatch_assignMatchToValue(	rarg_possible_match_t*	possible_match, 
																																					VALUE*									receiver );
		rarg_possible_hash_key_data_match_t* RARG_define_PossibleMatch_assignHashForKeyDataMatchToValue(	rarg_possible_hash_key_data_match_t*	possible_hash_key_or_data_match, 
																																																			VALUE*																receiver );
	rarg_parameter_set_t* RARG_define_ParameterSet_description(	rarg_parameter_set_t*		parameter_set,
																															int											order_ranking,
																															char*										description, ... );	
	rarg_parameter_t* RARG_define_Parameter_description(	rarg_parameter_t*		parameter,
																												int									order_ranking,
																												char*								description, ... );	
	rarg_possible_match_t* RARG_define_PossibleMatch_description(	rarg_possible_match_t*	possible_match,
																																int											order_ranking,
																																char*										description, ... );	


	/*************************
	*  RARG Internal Macros  *
	*************************/

	#ifndef NEVER
		#define NEVER																															FALSE
	#endif

	#define RI_AllocPossibleMatch()																							calloc( 1, sizeof( rarg_possible_match_t ) )
	#define RI_AllocPossibleMatchDetails()																			calloc( 1, sizeof( rarg_possible_match_frame_t ) )
	#define RI_AllocPossibleBlockMatch()																				calloc( 1, sizeof( rarg_possible_block_match_t ) )
	#define RI_AllocPossibleHashMatch()																					calloc( 1, sizeof( rarg_possible_hash_match_t ) )
	#define RI_AllocPossibleTypeMatch()																					calloc( 1, sizeof( rarg_possible_type_match_t ) )
	#define RI_AllocPossibleAncestorMatch()																			calloc( 1, sizeof( rarg_possible_ancestor_matches_t ) )
	#define RI_AllocPossibleMethodMatch()																				calloc( 1, sizeof( rarg_possible_method_matches_t ) )

	#define RI_AllocAndAssignPossibleMatch( var )																( var )	= RI_AllocPossibleMatch()
	#define RI_AllocAndAssignPossibleMatchDetails( var )												( var )->possible							= RI_AllocPossibleMatchDetails()
	#define RI_AllocAndAssignPossibleBlockMatch( var )													( var )->possible->block			= RI_AllocPossibleBlockMatch()
	#define RI_AllocAndAssignPossibleHashMatch( var )														( var )->possible->hash				= RI_AllocPossibleHashMatch()
	#define RI_AllocAndAssignPossibleAncestorsMatch( var )											( var )->possible->ancestors	= RI_AllocPossibleAncestorMatch()
	#define RI_AllocAndAssignPossibleMethodsMatch( var )												( var )->possible->methods		= RI_AllocPossibleMethodMatch()
	#define RI_AllocAndAssignPossibleTypeMatch( var )														( var )->possible->types			= RI_AllocPossibleTypeMatch()

	#define RI_AssignPossibleMatchType( var, rarg_type )												( var )->type = rarg_type;
	
	//----------------------------------------------------------------------------------------------------------//

	#define RI_CreatePossibleMatch( possible_match_ptr_var )											RI_AllocAndAssignPossibleMatch( possible_match_ptr_var );															\
																																								RI_AllocAndAssignPossibleMatchDetails( possible_match_ptr_var );

	#define RI_CreatePossibleBlockMatch( possible_block_match_ptr_var )						RI_AllocAndAssignPossibleBlockMatch( possible_block_match_ptr_var );
	#define RI_CreatePossibleHashMatch( possible_hash_match_ptr_var )							RI_AllocAndAssignPossibleHashMatch( possible_hash_match_ptr_var );
	#define RI_CreatePossibleTypeMatch( possible_type_match_ptr_var )							RI_AllocAndAssignPossibleTypeMatch( possible_type_match_ptr_var );
	#define RI_CreatePossibleAncestorsMatch( possible_ancestors_match_ptr_var )		RI_AllocAndAssignPossibleAncestorsMatch( possible_ancestors_match_ptr_var );
	#define RI_CreatePossibleMethodsMatch( possible_methods_match_ptr_var )				RI_AllocAndAssignPossibleMethodsMatch( possible_methods_match_ptr_var );

	#define RI_CreatePossibleBlockMatchForPossibleMatch( possible_match )					RI_AssignPossibleMatchType( possible_match, RARG_BLOCK );						\
																																								RI_AllocAndAssignPossibleBlockMatch( possible_match );
	#define RI_CreatePossibleHashMatchForPossibleMatch( possible_match )					RI_AssignPossibleMatchType( possible_match, RARG_HASH );						\
																																								RI_AllocAndAssignPossibleHashMatch( possible_match );
	#define RI_CreatePossibleTypeMatchForPossibleMatch( possible_match )					RI_AssignPossibleMatchType( possible_match, RARG_TYPE );						\
																																								RI_AllocAndAssignPossibleTypeMatch( possible_match );
	#define RI_CreatePossibleAncestorsMatchForPossibleMatch( possible_match )			RI_AssignPossibleMatchType( possible_match, RARG_ANCESTOR );				\
																																								RI_AllocAndAssignPossibleAncestorsMatch( possible_match );
	#define RI_CreatePossibleMethodsMatchForPossibleMatch( possible_match )				RI_AssignPossibleMatchType( possible_match, RARG_METHOD );				\
																																								RI_AllocAndAssignPossibleMethodsMatch( possible_match );

	#define RI_CreatePossibleMatchWithBlock( possible_match_ptr_var )							RI_CreatePossibleMatch( possible_match_ptr_var );										\
																																								RI_CreatePossibleBlockMatchForPossibleMatch( possible_match_ptr_var );
	#define RI_CreatePossibleMatchWithHash( possible_match_ptr_var )							RI_CreatePossibleMatch( possible_match_ptr_var );										\
																																								RI_CreatePossibleHashMatchForPossibleMatch( possible_match_ptr_var );
	#define RI_CreatePossibleMatchWithType( possible_match_ptr_var )							RI_CreatePossibleMatch( possible_match_ptr_var );										\
																																								RI_CreatePossibleTypeMatchForPossibleMatch( possible_match_ptr_var );
	#define RI_CreatePossibleMatchWithAncestors( possible_match_ptr_var )					RI_CreatePossibleMatch( possible_match_ptr_var );										\
																																								RI_CreatePossibleAncestorsMatchForPossibleMatch( possible_match_ptr_var );
	#define RI_CreatePossibleMatchWithMethods( possible_match_ptr_var )						RI_CreatePossibleMatch( possible_match_ptr_var );										\
																																								RI_CreatePossibleMethodsMatchForPossibleMatch( possible_match_ptr_var );

	#define RI_Arity( arity, ... )																								RARG_define_PossibleBlockMatch_arity( arity,##__VA_ARGS__, NULL )
	#define R_TERMINATE_ARITY -4

	//----------------------------------------------------------------------------------------------------------//

	#define RI_ConstructPassedArgsArray( c_passed_arg, ... )																																									\
		VALUE		c_rb_passed_args[]	=	{ c_passed_arg,##__VA_ARGS__, Qnil };																																			\
		VALUE*	c_which_rb_passed_arg	=	c_rb_passed_args;																																												\
		VALUE		rb_args_to_pass	=	rb_ary_new();																																																	\
		while ( *c_which_rb_passed_arg != Qnil )	{																																															\
			rb_ary_push(	rb_args_to_pass,																																																				\
										*c_which_rb_passed_arg );																																																\
			c_which_rb_passed_arg++;																																																							\
		}																																																																				\





































/*


	
	#define RI_FrameDetails( possible_match )													possible_match->possible
	#define RI_FrameType( possible_match )																possible_match->type
	
	#define RI_PossibleType( possible_match )													( RI_FrameDetails( possible_match )->type )
	#define RI_PossibleClass( possible_match )												( RI_FrameDetails( possible_match )->possible_instance_match )
	#define RI_PossibleHash( possible_match )													( RI_FrameDetails( possible_match )hash )
	#define RI_PossibleBlock( possible_match )												( RI_FrameDetails( possible_match )block )

	//------------------------------------------------------------------------------//

	#define RI_tmp																										rarg_tmp
	#define RI_tmp_Type																								rarg_possible_type_match_t*

	//	action_c never happens, so ternary cascades
	#define RI_Cascade( action_a, action_b )													( action_a ? action_b : NEVER )
	#define RI_ReturnArgFromMacro( rarg )															( rarg )

	#define RI_AssignFrameType( rarg, type )										( RI_FrameType( rarg ) = type )
	#define RI_SetFrameType( rarg, type )												RI_Cascade(	RI_AssignFrameType( rarg, type ),																	\
																																								RI_ReturnArgFromMacro( rarg ) ),
																																								
	#define RI_SetFrameAsPossibleTypeMatch( rarg )										RI_SetFrameType( rarg, RARG_TYPE )
	#define RI_SetFrameAsPossibleClassMatch( rarg )										RI_SetFrameType( rarg, RARG_INSTANCE )
	#define RI_SetFrameAsPossibleHashMatch( rarg )										RI_SetFrameType( rarg, RARG_HASH )
	#define RI_SetFrameAsPossibleBlockMatch( rarg )										RI_SetFrameType( rarg, RARG_BLOCK )
	#define RI_SetFrameAsPossibleMethodMatch( rarg )									RI_SetFrameType( rarg, RARG_METHOD )

	//------------------------------------------------------------------------------//

	#define RI_AllocPossibleMatch( var )															( var = calloc( 1, sizeof( rarg_possible_match_t ) ) )
	#define RI_AllocPossibleMatchFrame( var )													( RI_FrameDetails( var ) = calloc( 1, sizeof( rarg_possible_match_frame_t ) ) )
	#define RI_CreatePossibleMatch( var )															RI_Cascade(	RI_AllocPossibleMatch( var ),																						\
																																								RI_Cascade(	RI_AllocPossibleMatchFrame( var ),													\
																																														RI_ReturnArgFromMacro( var ) ) )

	#define RI_AllocPossibleTypeMatch( var )													RI_SetFrameAsPossibleTypeMatch(	RI_CreatePossibleMatch( var ) )
	#define RI_AllocPossibleClassMatch( var )													RI_SetFrameAsPossibleClassMatch(	RI_CreatePossibleMatch( var ) )
	#define RI_AllocPossibleHashMatch( var )													RI_SetFrameAsPossibleHashMatch(	RI_CreatePossibleMatch( var ) )
	#define RI_AllocPossibleBlockMatch( var )													RI_SetFrameAsPossibleBlockMatch(	RI_CreatePossibleMatch( var ) )
	#define RI_AllocPossibleMethodMatch( var )												RI_SetFrameAsPossibleMethodMatch(	RI_CreatePossibleMatch( var ) )

	//------------------------------------------------------------------------------//

	#define RI_CreatePossibleTypeMatch()															RI_AllocPossibleTypeMatch( RI_tmp )
	#define RI_CreatePossibleClassMatch()															RI_AllocPossibleClassMatch( RI_tmp )
	#define RI_CreatePossibleHashMatch()															RI_AllocPossibleHashMatch( RI_tmp )
	#define RI_CreatePossibleBlockMatch()															RI_AllocPossibleBlockMatch( RI_tmp )
	#define RI_CreatePossibleMethodMatch()														RI_AllocPossibleMethodMatch( RI_tmp )

	//------------------------------------------------------------------------------//

	#define RI_AssignTypeToPossibleMatch( possible_match,							\
																				assign_type )								( RI_FrameDetails( possible_match )->type = assign_type )
	#define RI_CreateAndAssignType( assign_type )											RI_Cascade(	RI_CreateType(),																														\
																																								RI_Cascade(	RI_AssignTypeToPossibleMatch( RI_tmp, assign_type ),						\
																																														RI_ReturnArgFromMacro( RI_tmp ) ) )

	#define RI_SetReceiver( possible_match, match_receiver )					( possible_match->receiver = & match_receiver )
	#define RI_AssignReceiverForPossibleMatch(	possible_match,				\
																							receiver )						RI_Cascade(	RI_SetReceiver( possible_match, receiver ),																	\
																																								RI_ReturnArgFromMacro( possible_match ) )
*/
	
#endif