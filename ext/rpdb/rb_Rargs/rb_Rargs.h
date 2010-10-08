#ifndef RB_RARGS
	#define RB_RARGS

	#include "rb_Rargs_types.h"
	#include "rb_Rargs_define.h"
	#include "rb_Rargs_parse.h"
	#include "rb_Rargs_free.h"
	#include "rb_Rargs_error.h"

	extern	rarg_possible_type_match_t*	rarg_tmp;

	/*
	
		R_ParameterSet							can take:	R_Parameter
		
		R_Parameter									can take: 
		
			for matching									R_Type and subtypes:
																			R_Any, R_NotNil, R_String, R_Symbol, R_StringSymbol, R_Hash, R_Array
			
			for assigning									R_MatchType and subtypes:
																			R_MatchAny, R_MatchNotNil, R_MatchString, R_MatchSymbol, R_MatchStringSymbol, 
																			R_MatchHash, R_MatchArray
			
			for assigning hash on					R_Match...ForHash:
			key/data match									R_MatchAnyForHash, R_MatchNotNilForHash, R_MatchStringForHash, R_MatchSymbolForHash, 
																			R_MatchStringSymbolForHash, R_MatchHashForHash, R_MatchArrayForHash												
		
		R_Type												can take: type
			
			R_Any												and
			R_NotNil										and
			R_String										and
			R_Symbol										and
			R_StringSymbol							and
			R_Array											and
			R_Hash											and
			R_Key												and
			R_Data											and
			R_Index											can take: ()
			
			
		R_MatchType	and
		R_MatchPossibleTypeForHash		can take: type, receiver
		
			R_MatchAny									and
			R_MatchNotNil								and
			R_MatchString								and
			R_MatchSymbol								and
			R_MatchStringSymbol					and
			R_MatchArray								and
			R_MatchHash									and
			R_MatchKey									and
			R_MatchData									and			
			R_MatchIndex								and
					
			R_MatchAnyForHash						and
			R_MatchNotNilForHash				and
			R_MatchStringForHash				and
			R_MatchSymbolForHash				and
			R_MatchStringSymbolForHash	and
			R_MatchArrayForHash					and
			R_MatchHashForHash					and
			R_MatchIndexForHash					can take: receiver			<= works in place of Type with implicit Type = R_STRING_OR_SYMBOL
	
	*/

	/*
	
		RARGS Example:
		
			//	Define result parameters
			VALUE	rb_index														=	Qnil;
			VALUE	rb_key															=	Qnil;
			VALUE	rb_hash_parameter_set_index_key				=	Qnil;
			VALUE	rb_hash_parameter_set_index_keys_array	=	Qnil;
			VALUE	rb_args_array												= Qnil;

			R_Define(

				/------------------------------------------------/

				//	{ :index  => [ <key> ] }
				//	{ "index" => [ <key> ] }
				//	{ :index  => <key> }
				//	{ "index" => <key> }
				R_ParameterSet(		R_Parameter(	R_Hash(	R_Key(	R_Type(	R_SYMBOL | R_STRING ) ),
																							R_Data(	R_MatchArrayForHash(	rb_hash_parameter_set_index_keys_array ) ),
																											R_MatchAnyForHash(		rb_hash_parameter_set_index_key ) ) ) ) ),


				/------------------------------------------------/

				//	:index, <key>
				//	"index", <key>
				R_ParameterSet(		R_Parameter(	R_MatchType(		R_SYMBOL | R_STRING,		
																											rb_index ) ),
												R_Parameter(	R_MatchAny(			rb_key ) ) ),

				/------------------------------------------------/

				//	[ <arg> ]
				R_ParameterSet(		R_Parameter(	R_MatchArray(		rb_args_array ) ) ),

				/------------------------------------------------/

				//	<key>
				R_ParameterSet(		R_Parameter(	R_MatchAny(			rb_key ) ) )

				/------------------------------------------------/
				
			)	

			//	Now use result parameters accordingly
			if (		rb_index != Qnil
					&&	rb_key != Qnil )	{
					
			}
			else if (	rb_key != Qnil )	{
			
			}
			else if ( rb_hash_parameter_set_index_key != Qnil )	{
			
			}
			else if ( rb_hash_parameter_set_index_keys_array != Qnil )	{
			
			}
			else if ( rb_args_array != Qnil )	{
			
			}

	*/

	/*

		RARGS Layout:

		parameter_sets have parameters
		parameters have possible matches
		possible matches can have:
			* allowed and prohibited:
					+ type
					+ class
					+ responds to method
					+ hash
							- key-value presence
							- key/data allow/prohibit constraints
									= type
									= class
									= responds to method
					+ array
							- first member constraints
									= type
									= class
									= responds to method
			* receiver for match assignment
					+ hash
							- receiver for key
							- receiver for data match assignment

	*/	
				
	/*

		Thanks for _tar (#ruby on irc.freenode.net) for interface/implementation ideas:
		* multiple type specification
		* bitwise math for types
		* recursive macro design
	
	*/

	#define R_DefineAndParse( argc, args, parameter_set, ... )				R_Define( parameter_set,##__VA_ARGS__ );		\
																																		R_Parse( argc, args );

	#define R_Define( parameter_set, ... )														int		c_args_parsed			=	0;																																																	\
																																		VALUE*	rarg_args = NULL;			/* rarg_args is used for continual arg processing in recursion */																\
																																		int		c_suppress_unused_expression_warnings	=	0;																																							\
																																		rarg_parameter_set_t*		parameter_sets	=	RARG_define_ParameterSets( parameter_set,##__VA_ARGS__, NULL );

	#define R_Parse( argc, args )																			( c_suppress_unused_expression_warnings = ( ( ( rarg_args = args ) != NULL ) ?																																																		\
																																			( ( c_args_parsed += RARG_parse_ParameterSetsForMatch( argc - c_args_parsed, args + c_args_parsed, parameter_sets ) ) > argc ?		\
																																					( ( c_args_parsed = argc ) ?																																																				\
																																								FALSE																																																											\
																																								: FALSE )																																																										\
																																					: ( ( c_args_parsed == argc ) ?																																																		\
																																								c_args_parsed++																																																						\
																																								: TRUE ) )																																																									\
																																			: NEVER ) )



	/***********************
	*  RARG Public Macros  *
	***********************/
/*
	#define R_Type( type )																						RI_CreateAndAssignType( type )
	#define R_MatchType( type, receiver )															RI_AssignReceiverForPossibleMatch( RI_CreateAndAssignType( type ), receiver )
	*/








		/*--------------------*
		*  RARG Descriptions  *
		*--------------------*/

	#define R_ListOrder( list_order_number )													list_order_number
	#define R_DescribeParameterSet(		parameter_set,									\
																		order_ranking_number,						\
																		description, ... )							RARG_define_ParameterSet_description(	parameter_set				,																	\
																																																					order_ranking_number,																	\
																																																					description,##__VA_ARGS__, NULL )

	#define R_DescribeParameter(			parameter,											\
																		order_ranking_number,						\
																		description, ... )							RARG_define_Parameter_description(	parameter,																							\
																																																				order_ranking_number,																		\
																																																				description,##__VA_ARGS__, NULL )	
																																																						
	#define R_DescribePossibleMatch(	possible_match,									\
																		order_ranking_number,						\
																		description, ... )							RARG_define_PossibleMatch_description(	possible_match,																			\
																																																						order_ranking_number,																\
																																																						description,##__VA_ARGS__, NULL )





	#define R_ExactMatch( parameter_set, ... )												RARG_define_ParameterSet_requireExactMatch( parameter_set,##__VA_ARGS__, NULL )
	#define R_Optional( possible_match, ... )													RARG_define_PossibleMatch_setOptional( possible_match,##__VA_ARGS__, NULL )

	
	#define R_ParameterSet( parameter, ... )													RARG_define_ParameterSet( parameter,##__VA_ARGS__, NULL )
	#define R_Parameter( possible_match, ... )												RARG_define_Parameter( possible_match,##__VA_ARGS__, NULL )

	#define R_Type( type, ... )																				RARG_define_PossibleTypeMatch( type,##__VA_ARGS__, R_TERMINAL )
	#define R_MatchType( type, receiver )															R_MatchPossibleType( R_Type( type ), receiver )
	#define R_MatchPossibleType( possible_match, receiver )						RARG_define_PossibleMatch_assignMatchToValue( possible_match, & receiver )
	#define R_MatchPossibleTypeForHash( possible_match, receiver )		RARG_define_PossibleMatch_assignHashForKeyDataMatchToValue( possible_match, & receiver )

	#define R_Any()																										R_Type( R_ANY )
	#define R_NotNil()                                      					R_Type( R_NOT_NIL )
	#define R_String()                                      					R_Type( R_STRING )
	#define R_Symbol()                                      					R_Type( R_SYMBOL )
	#define R_StringSymbol()                                					R_Type( R_STRING_SYMBOL )
	#define R_Array()                                       					R_Type( R_ARRAY )
	
	#define R_Hash( hash_key, hash_data )															RARG_define_PossibleHashMatch( hash_key, hash_data )
	#define R_Key( possible_match, ... )															RARG_define_PossibleHashMatch_KeyOrDataMatch( possible_match,##__VA_ARGS__, NULL )
	#define R_Data( possible_match, ... )															RARG_define_PossibleHashMatch_KeyOrDataMatch( possible_match,##__VA_ARGS__, NULL )
	#define R_Index( index_string, ... )															RARG_define_PossibleHashMatch_index( index_string,##__VA_ARGS__, NULL )
	#define R_Ancestor( class_name, ... )															RARG_define_PossibleAncestorMatch( class_name,##__VA_ARGS__, NULL )
	#define R_AncestorInstance( class_or_module_instance, ... )				RARG_define_PossibleAncestorInstanceMatch( class_or_module_instance,##__VA_ARGS__, R_TERMINAL )
	#define R_Class( class_or_module_name, ... )											R_Ancestor( class_or_module_name,##__VA_ARGS__ )
	#define R_ClassInstance( class_or_module_instance, ... )					R_AncestorInstance( class_or_module_instance,##__VA_ARGS__ )
	#define R_Proc()																									R_AncestorInstance( rb_cProc )
	#define R_Lambda()																								R_Proc()
	#define R_ProcWithArity( arity, ... )															RI_Arity( R_Proc(),##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_LambdaWithArity( arity, ... )														RI_Arity( R_Lambda(),##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_BlockProc()																							RARG_define_Block_procMatch()
	#define R_BlockLambda()																						RARG_define_Block_lambdaMatch()
	#define R_BlockProcWithArity( arity, ... )												RI_Arity( R_BlockProc(),##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_BlockLambdaWithArity( arity, ... )											RI_Arity( R_BlockLambda(),##__VA_ARGS__, R_TERMINATE_ARITY )

	#define R_MatchAny( receiver )																		R_MatchPossibleType( R_Any(), receiver )
	#define R_MatchNotNil( receiver )																	R_MatchPossibleType( R_NotNil(), receiver )
	#define R_MatchString( receiver )																	R_MatchPossibleType( R_String(), receiver )
	#define R_MatchSymbol( receiver )																	R_MatchPossibleType( R_Symbol(), receiver )
	#define R_MatchStringSymbol( receiver )														R_MatchPossibleType( R_StringSymbol(), receiver )
	#define R_MatchArray( receiver )																	R_MatchPossibleType( R_Array(), receiver )
	#define R_MatchHash( key, data, receiver )												R_MatchPossibleType( R_Hash( key, data ), receiver )
	#define R_MatchKey( possible_match, receiver )										R_MatchPossibleType( possible_match, receiver )
	#define R_MatchData( possible_match, receiver )										R_MatchPossibleType( possible_match, receiver )
	#define R_MatchIndex( index_string, receiver )										R_MatchPossibleType( R_Index( index_string ), receiver )
	#define R_MatchProc( receiver )																		R_MatchPossibleType( R_Proc(), receiver )
	#define R_MatchLambda( receiver )																	R_MatchProc( receiver )
	#define R_MatchProcWithArity( receiver, arity, ... )							RI_Arity( R_MatchProc( receiver ),##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_MatchLambdaWithArity( receiver, arity, ... )						RI_Arity( R_MatchLambda( receiver ),##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_MatchBlockProc( receiver )															R_MatchPossibleType( R_BlockProc(), receiver )
	#define R_MatchBlockLambda( receiver )														R_MatchPossibleType( R_BlockLambda(), receiver )
	#define R_MatchBlockProcWithArity( receiver, arity, ... )					RI_Arity( R_MatchBlockProc( receiver ), arity,##__VA_ARGS__, R_TERMINATE_ARITY )
	#define R_MatchBlockLambdaWithArity( receiver, arity, ... )				RI_Arity( R_MatchBlockLambda( receiver ), arity,##__VA_ARGS__, R_TERMINATE_ARITY )

	#define R_MatchAnyForHash( receiver )                   					R_MatchPossibleTypeForHash( R_Any(), receiver )     
	#define R_MatchNotNilForHash( receiver )                					R_MatchPossibleTypeForHash( R_NotNil(), receiver )
	#define R_MatchStringForHash( receiver )                					R_MatchPossibleTypeForHash( R_String(), receiver )
	#define R_MatchSymbolForHash( receiver )                					R_MatchPossibleTypeForHash( R_Symbol(), receiver )
	#define R_MatchStringSymbolForHash( receiver )          					R_MatchPossibleTypeForHash( R_StringSymbol(), receiver )
	#define R_MatchArrayForHash( receiver )														R_MatchPossibleTypeForHash( R_Array(), receiver )
	#define R_MatchHashForHash( key, data, receiver )        					R_MatchPossibleTypeForHash( R_Hash( key, data ), receiver )
	#define R_MatchIndexForHash( receiver )                 					R_MatchPossibleTypeForHash( R_StringSymbol(), receiver )
	#define R_MatchProcForHash( receiver )														R_MatchPossibleTypeForHash( R_Proc(), receiver )




	#define R_Arg(		receiver )																																																							\
		( ( c_args_parsed <= argc ) ? ( c_args_parsed++ ? ( ( receiver = rarg_args[ c_args_parsed - 1 ] ) != Qnil ) : FALSE ) : FALSE )

	#define R_Args1(	receiver_one )																																																					\
		R_Arg( receiver_one )
	#define R_Args2(	receiver_one,																																																						\
										receiver_two )																																																					\
		R_Args( receiver_one, receiver_two )
	#define R_Args(		receiver_one,																																																						\
										receiver_two )																																																					\
		( R_Arg( receiver_one ) ? R_Arg( receiver_two ) : FALSE )
		
	#define R_Args3(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three )																																																				\
		( R_Args( receiver_one, receiver_two ) ? R_Arg( receiver_three ) : FALSE )

	#define R_Args4(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four )																																																					\
		( R_Args( receiver_one, receiver_two ) ? R_Args( receiver_three, receiver_four ) : FALSE )

	#define R_Args5(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four,																																																					\
										receiver_five )																																																					\
		( R_Args3( receiver_one, receiver_two, receiver_three ) ? R_Args( receiver_four, receiver_five ) : FALSE )

	#define R_Args6(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four,																																																					\
										receiver_five,																																																					\
										receiver_six )																																																					\
		( R_Args3( receiver_one, receiver_two, receiver_three ) ? R_Args3( receiver_four, receiver_five, receiver_six ) : FALSE )

	#define R_Args7(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four,																																																					\
										receiver_five,																																																					\
										receiver_six,																																																						\
										receiver_seven )																																																				\
		( R_Args4(	receiver_one,																																																								\
								receiver_two,																																																								\
								receiver_three,																																																							\
								receiver_four ) ? R_Args3( receiver_five, receiver_six, receiver_seven ) : FALSE )

	#define R_Args8(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four,																																																					\
										receiver_five,																																																					\
										receiver_six,																																																						\
										receiver_seven,																																																					\
										receiver_eight )																																																				\
		( R_Args4(	receiver_one,																																																								\
								receiver_two,																																																								\
								receiver_three,																																																							\
								receiver_four ) ? R_Args3( receiver_five, receiver_six, receiver_seven, receiver_eight ) : FALSE )
		
	#define R_Args9(	receiver_one,																																																						\
										receiver_two,																																																						\
										receiver_three,																																																					\
										receiver_four,																																																					\
										receiver_five,																																																					\
										receiver_six,																																																						\
										receiver_seven,																																																					\
										receiver_eight,																																																					\
										receiver_nine )																																																					\
		( R_Args5(	receiver_one,																																																								\
								receiver_two,																																																								\
								receiver_three,																																																							\
								receiver_four,																																																							\
								receiver_five ) ? R_Args3( receiver_six, receiver_seven, receiver_eight, receiver_nine ) : FALSE )

	#define R_IterateHashDescriptor( rb_self, rb_hash, rb_return, c_function, ... )																														\
		if ( rb_return == Qnil )	{																																																							\
			rb_return	=	rb_hash_new();																																																						\
		}																																																																				\
		RI_ConstructPassedArgsArray( rb_self, rb_return,##__VA_ARGS__ );																																				\
		do {																																																																		\
			rb_hash_foreach(	rb_hash,	c_function, rb_args_to_pass );																																						\
			/* remaining args are hashes */																																																				\
		} while ( R_Arg( rb_hash ) );																																																						\
		if ( TYPE( rb_return ) == T_HASH )	{																																																		\
			VALUE	rb_partial_return_hash	=	rb_ary_entry( rb_args_to_pass, 1 );																																		\
			rb_funcall(	rb_return,																																																								\
									rb_intern( "merge" ),																																																			\
									1,																																																												\
									rb_partial_return_hash );																																																	\
		}
		
	#define R_IterateArrayDescriptor( rb_self, rb_array, rb_return, c_function, ... )																													\
		if ( rb_return == Qnil )	{																																																							\
			rb_return	=	rb_ary_new();																																																							\
		}																																																																				\
		do {																																																																		\
			VALUE	rb_this_return	=	c_function(	RARRAY_LEN( rb_array ),																																						\
																					RARRAY_PTR( rb_array ),																																						\
																					rb_self );																																												\
			if ( TYPE( rb_return ) == T_ARRAY )	{																																																	\
				rb_ary_push( rb_return, rb_this_return );																																														\
			}																																																																			\
			/* remaining args are arrays */																																																				\
		} while ( R_Arg( rb_array ) );
		
#endif
