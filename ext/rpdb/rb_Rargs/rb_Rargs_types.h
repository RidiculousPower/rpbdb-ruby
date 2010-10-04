#ifndef RB_ARG_PARSER_TYPES
	#define RB_ARG_PARSER_TYPES

	#include <ruby.h>
	
	/*------------------------------------------------------------------------------*/
	
	#ifndef FALSE
		#define FALSE 0
	#endif
	#ifndef TRUE
		#define TRUE 1
	#endif
	#ifndef BOOL
		typedef int BOOL;
	#endif
	#define RARG_CONTINUE -1

	/*------------------------------------------------------------------------------*/
	
	enum rarg_types_e	{
	
    R_TERMINAL							= 0,
		
    R_MODULE								= 0x1,
    R_CLASS									= 0x2,
    R_NIL										= 0x4,
    R_OBJECT								= 0x8,
    R_DATA									= 0x10,
    R_STRUCT								= 0x20,

    R_ARRAY									= 0x40,
    R_HASH									= 0x80,

    R_FIXNUM								= 0x100,
    R_BIGNUM								= 0x200,
    R_FLOAT									= 0x400,
    R_COMPLEX								= 0x800,
    R_RATIONAL							= 0x1000,

    R_REGEXP								= 0x2000,
    R_FILE									= 0x4000,
    R_MATCH									= 0x8000,

    R_STRING								= 0x10000,
    R_SYMBOL								= 0x20000,

    R_TRUE									= 0x40000,
    R_FALSE									= 0x80000,
		
		R_META									=	R_MODULE | R_CLASS,
		R_INSTANCE							=	R_STRUCT | R_OBJECT | R_DATA,
		R_STRING_SYMBOL					=	R_STRING | R_SYMBOL,
		R_TEXT									=	R_STRING_SYMBOL | R_REGEXP | R_MATCH,
		R_NUMBER								=	R_FIXNUM | R_BIGNUM	| R_FLOAT | R_COMPLEX | R_RATIONAL,
		R_TRUE_FALSE						=	R_TRUE | R_FALSE,
		R_BUCKET								=	R_ARRAY | R_HASH,
		R_ANY										=	R_NIL
															| R_FILE
															| R_META
															| R_INSTANCE
															| R_TEXT
															| R_NUMBER
															| R_TRUE_FALSE
															| R_BUCKET,
		R_NOT_NIL								=	R_ANY - R_NIL,
		R_NOT_TRUE_FALSE				=	R_ANY - R_TRUE_FALSE,
		R_NOT_TRUE_FALSE_NIL		=	R_NOT_TRUE_FALSE - R_NIL
		
	};

	/*------------------------------------------------------------------------------*/

	/************
	*  typedef  *
	************/

	typedef enum		rarg_types_e											rarg_type_t;

	typedef struct	rarg_describer_s									rarg_describer_t;

	typedef struct	rarg_parameter_set_s							rarg_parameter_set_t;
	typedef struct	rarg_parameter_s									rarg_parameter_t;
	typedef struct	rarg_possible_match_s							rarg_possible_match_t;
	
	typedef struct	rarg_matched_parameter_set_s			rarg_matched_parameter_set_t;
	typedef struct	rarg_matched_parameter_s					rarg_matched_parameter_t;

	/*------------------------------------------------------------------------------*/

	/***********************
	*  Definition Structs  *
	***********************/

	//	describers allow in-line definition of argument format to be printed in error
	//	message if no condition matches
	//	describers can grow in two directions:	multiple descriptions, multiple describers
	//																					(each of which can have multiple descriptions)
	struct rarg_parameter_set_s	{

		rarg_describer_t*										description;
		rarg_parameter_t*										parameters;
		BOOL																require_exact;

		rarg_parameter_set_t*								next;

	};
	
	struct rarg_parameter_s	{

		rarg_describer_t*										description;
		rarg_possible_match_t*							possible_match;

		rarg_parameter_t*										next;

	};

	struct rarg_possible_match_s	{		

		rarg_describer_t*										description;
		rarg_possible_match_frame_t					frame;
		VALUE*															receiver;
		BOOL																optional;

		rarg_possible_match_subtype_t*			details

		rarg_possible_match_t*							next;

	};

	union rarg_possible_match_u	{
	
		rarg_possible_hash_match_t*					possible_hash_match;
		rarg_possible_block_match_t*				possible_block_match;

	};


	/*------------------------------------------------------------------------------*/
	
		/****************************
		*  Definition Type Structs  *
		****************************/
	
		struct rarg_possible_match_type_s	{

			rarg_type_t													type;
		
		};

		struct rarg_possible_match_class_s	{
		
			VALUE																ruby_class;

		};

		struct rarg_possible_hash_match_s	{	
			
			char*																index_name;
			rarg_possible_hash_index_match_t*		possible_hash_indexes;
			rarg_possible_match_t*							possible_hash_key_match;
			rarg_possible_match_t*							possible_hash_data_match;
			BOOL																assign_parent_hash_for_key_or_data_self;

			rarg_possible_hash_match_t*					next;

		};
		
		struct rarg_possible_block_match_s	{
		
		};
		
	/*------------------------------------------------------------------------------*/

			/************************************
			*  Definition Type Support Structs  *
			************************************/

			struct rarg_possible_hash_index_match_s	{
			
			};

	/*------------------------------------------------------------------------------*/

	/***************************
	*  Definition Frame Types  *
	***************************/

	enum rarg_possible_match_frame_e	{
	
		RARG_TYPE						=	1,
		RARG_CLASS					=	2,
		RARG_HASH						= 3,
		RARG_BLOCK					= 4,
		RARG_METHOD					= 5
		
	};

	/***********************
	*  Description Struct  *
	***********************/

	struct rarg_describer_s	{

		int																	order_ranking;
		char*																description;

		rarg_describer_t*										next;

	};
	
	/*------------------------------------------------------------------------------*/

	/*********************************
	*  Matched Parameter Set Struct  *
	*********************************/
	
	struct rarg_matched_parameter_set_s	{

		rarg_matched_parameter_t*					parameters;
		int																last_arg;

	};

	/*****************************
	*  Matched Parameter Struct  *
	*****************************/
	
	struct rarg_matched_parameter_s	{

		VALUE															match;
		VALUE*														receiver;
		rarg_matched_parameter_t*					next;

	};

#endif