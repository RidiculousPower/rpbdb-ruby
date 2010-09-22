#ifndef RB_RARGS
	#define RB_RARGS

#include "rb_Rargs_types.h"
#include "rb_Rargs_parser.h"
#include "rb_Rargs_free.h"

/**************
*  Interface  *
**************/

			/*===========*/
#define RARG_Define																																																								\
			/*===========*/																																																							\
	RARG_DEFINE_BASE_DESCRIPTOR																																																			\
	/* init descriptor instance */																																																		\
	RARG_DEFINE_POINTERS																																																							\
	RARG_START																																																												\
		/* note start bracket; closing bracket expected from RARG_PARSE */

			/*==========*/
#define RARG_Parse( argc, args )																																																		\
			/*==========*/																																																								\
		/* note closing bracket; opening bracket expected from RARG_DEFINE */																													\

	/* for each descriptor in linked list */																																													\
//	RARG_PARSE_EACH_DESCRIPTOR( argc, args )																																												\
	/* free allocated configuration structs */																																												\
//	RARG_FREE_ALLOCATED_CONFIGURATION

/*------------------------------------------------------------------------------*/

			/*===============*/
#define RARG_Descriptor(...)																																																	\
			/*===============*/																																																						\
	/* init descriptor root or move descriptor pointer forward */																																			\
	RARG_CREATE_AND_INIT_OR_ADVANCE( RARG_VAR_DESCRIPTOR, RARG_PTR_DESCRIPTOR, rarg_descriptor_t )																		\
	RARG_SET_TO_FIRST_PARAMETER

			/*==============*/
#define RARG_Parameter(...)																																																	\
			/*==============*/																																																			\
	/* init the root parameter or move the parameter pointer forward */																																\
	RARG_INIT_OR_ADVANCE( RARG_PTR_PARAMETER, rarg_parameter_t )																																			\
	/* set the allowable pointer to the parameter allowable types */																																	\
	RARG_SET_TO_FIRST_ALLOWABLE_TYPE																																																\
	RARG_SET_TO_FIRST_PROHIBITED_TYPE
	
			/*=============*/
#define RARG_HashKey(...)																																																					\
			/*=============*/

			/*==============*/
#define RARG_HashData(...)																																																					\
			/*==============*/


/*------------------------------------------------------------------------------*/

			/*==========*/
#define RARG_Allow( allowed_type, ... )																																															\
			/*==========*/																																																								\
	RARG_INIT_OR_ADVANCE( RARG_PTR_ALLOWABLE_TYPE, rarg_allowed_type_t )																														\
	RARG_ALLOWABLE_TYPE_REF->type	=	allowed_type;																																											\
	if (		allowed_type == T_ANY																																																			\
			||	allowed_type == T_HASH )	{																																																\
		RARG_SET_TO_FIRST_ALLOWABLE_HASH_KEY_TYPE																																										\
		RARG_SET_TO_FIRST_ALLOWABLE_HASH_DATA_TYPE																																										\
	}

			/*=============*/
#define RARG_Prohibit( prohibited_type, ... )																																												\
			/*=============*/																																																							\
	RARG_INIT_OR_ADVANCE( RARG_PTR_PROHIBITED_TYPE, rarg_prohibited_type_t )																											\
	RARG_PROHIBITED_TYPE_REF->type	=	prohibited_type;																																								\
	if (		prohibited_type == T_ANY																																																	\
			||	prohibited_type == T_HASH )	{																																															\
		RARG_SET_TO_FIRST_PROHIBITED_HASH_KEY_TYPE																																									\
		RARG_SET_TO_FIRST_PROHIBITED_HASH_DATA_TYPE																																									\
	}

			/*===================*/
#define RARG_AllowHashKey( allowed_type, ... )																																										\
			/*===================*/																																																				\
	RARG_INIT_OR_ADVANCE( RARG_PTR_ALLOWABLE_HASH_KEY_TYPE, rarg_allowed_type_t )																			\
	RARG_ALLOWABLE_HASH_KEY_TYPE_REF->type	=	allowed_type;

			/*====================*/
#define RARG_AllowHashData( allowed_type, ... )																																										\
			/*====================*/																																																			\
	RARG_INIT_OR_ADVANCE( RARG_PTR_ALLOWABLE_HASH_DATA_TYPE, rarg_allowed_type_t )																			\
	RARG_ALLOWABLE_HASH_DATA_TYPE_REF->type	=	allowed_type;

			/*======================*/
#define RARG_ProhibitHashKey( prohibited_type, ... )																																							\
			/*======================*/																																																		\
	RARG_INIT_OR_ADVANCE( RARG_PTR_PROHIBITED_HASH_KEY_TYPE, rarg_prohibited_type_t )																	\
	RARG_PROHIBITED_HASH_TYPE_REF->type	=	prohibited_type;

			/*=======================*/
#define RARG_ProhibitHashData( prohibited_type, ... )																																							\
			/*=======================*/																																																		\
	RARG_INIT_OR_ADVANCE( RARG_PTR_PROHIBITED_HASH_DATA_TYPE, rarg_prohibited_type_t )																	\
	RARG_PROHIBITED_HASH_TYPE_REF->type	=	prohibited_type;

/*------------------------------------------------------------------------------*/

			/*====================*/
#define RARG_AssignTo( ruby_var )																																														\
			/*====================*/																																																			\
	RARG_ALLOWABLE_TYPE_REF->parameter_value_receiver	=	& ruby_var;

			/*=============================*/
#define RARG_AssignHashKeyTo( ruby_var )																																										\
			/*=============================*/																																															\
	RARG_ALLOWABLE_HASH_KEY_TYPE_REF->parameter_value_receiver	=	& ruby_var;

			/*==============================*/
#define RARG_AssignHashDataTo( ruby_var )																																									\
			/*==============================*/																																														\
	RARG_ALLOWABLE_HASH_DATA_TYPE_REF->parameter_value_receiver	=	& ruby_var;

/**************************************************************************************************/


/**************
*  Variables  *
**************/

			/*====================*/
#define RARG_VAR_DESCRIPTOR																																																				\
			/*====================*/																																																			\
	rarg_descriptor

/*************
*  Pointers  *
*************/

			/*====================*/
#define RARG_PTR_DESCRIPTOR																																																				\
			/*====================*/																																																			\
	rarg_next_descriptor

			/*===================*/
#define RARG_PTR_PARAMETER																																																					\
			/*===================*/																																																				\
	rarg_next_parameter

			/*===========================*/
#define RARG_PTR_ALLOWABLE_TYPE																																																	\
			/*===========================*/																																																\
	rarg_next_allowable_element

			/*================================*/
#define RARG_PTR_ALLOWABLE_HASH_KEY_TYPE																																														\
			/*================================*/																																													\
	rarg_next_allowable_hash_key_element

			/*================================*/
#define RARG_PTR_ALLOWABLE_HASH_DATA_TYPE																																														\
			/*================================*/																																													\
	rarg_next_allowable_hash_data_element

			/*============================*/
#define RARG_PTR_PROHIBITED_TYPE																																																\
			/*============================*/																																															\
	rarg_next_prohibited_element

			/*=================================*/
#define RARG_PTR_PROHIBITED_HASH_KEY_TYPE																																														\
			/*=================================*/																																													\
	rarg_next_prohibited_hash_key_element

			/*=================================*/
#define RARG_PTR_PROHIBITED_HASH_DATA_TYPE																																														\
			/*=================================*/																																													\
	rarg_next_prohibited_hash_data_element

/***********************
*  Deferenced Handles  *
***********************/

			/*===================*/
#define RARG_DESCRIPTOR_REF																																																						\
			/*===================*/																																																					\
	( *RARG_PTR_DESCRIPTOR )

			/*==================*/
#define RARG_PARAMETER_REF																																																							\
			/*==================*/																																																						\
	( *RARG_PTR_PARAMETER )

			/*==========================*/
#define RARG_ALLOWABLE_TYPE_REF																																																			\
			/*==========================*/																																																		\
	( *RARG_PTR_ALLOWABLE_TYPE )

			/*===============================*/
#define RARG_ALLOWABLE_HASH_KEY_TYPE_REF																																																\
			/*===============================*/																																															\
	( *RARG_PTR_ALLOWABLE_HASH_KEY_TYPE )

			/*===============================*/
#define RARG_ALLOWABLE_HASH_DATA_TYPE_REF																																																\
			/*===============================*/																																															\
	( *RARG_PTR_ALLOWABLE_HASH_DATA_TYPE )

			/*=============================*/
#define RARG_PROHIBITED_TYPE_REF																																																	\
			/*=============================*/																																																\
	( *RARG_PTR_PROHIBITED_TYPE )

			/*==================================*/
#define RARG_PROHIBITED_HASH_KEY_TYPE_REF																																															\
			/*==================================*/																																														\
	( *RARG_PTR_PROHIBITED_HASH_KEY_TYPE )

			/*==================================*/
#define RARG_PROHIBITED_HASH_DATA_TYPE_REF																																															\
			/*==================================*/																																														\
	( *RARG_PTR_PROHIBITED_HASH_DATA_TYPE )

/***********************
*  Pointer Definition  *
***********************/

			/*=====================*/
#define RARG_DEFINE_POINTERS																																																				\
			/*=====================*/																																																			\
	/* init pointers that track insert points */																																											\
	rarg_descriptor_t**											RARG_PTR_DESCRIPTOR																= NULL;																	\
	rarg_parameter_t**											RARG_PTR_PARAMETER																= NULL;																	\
	rarg_allowed_type_t**										RARG_PTR_ALLOWABLE_TYPE												=	NULL;																	\
	rarg_allowed_type_t**										RARG_PTR_ALLOWABLE_HASH_KEY_TYPE								= NULL;																	\
	rarg_allowed_type_t**										RARG_PTR_ALLOWABLE_HASH_DATA_TYPE							= NULL;																	\
	rarg_prohibited_type_t**								RARG_PTR_PROHIBITED_TYPE												=	NULL;																	\
	rarg_prohibited_type_t**								RARG_PTR_PROHIBITED_HASH_KEY_TYPE							= NULL;																	\
	rarg_prohibited_type_t**								RARG_PTR_PROHIBITED_HASH_DATA_TYPE							= NULL;

/*****************************
*  Iteration Initialization  *
*****************************/

			/*============================*/
#define RARG_SET_TO_FIRST_DESCRIPTOR																																																\
			/*============================*/																																															\
	RARG_PTR_DESCRIPTOR												=	& RARG_VAR_DESCRIPTOR;

			/*===========================*/
#define RARG_SET_TO_FIRST_PARAMETER																																																\
			/*===========================*/																																															\
	RARG_PTR_PARAMETER												=	& RARG_DESCRIPTOR_REF->parameters;

			/*===================================*/
#define RARG_SET_TO_FIRST_ALLOWABLE_TYPE																																												\
			/*===================================*/																																											\
	RARG_PTR_ALLOWABLE_TYPE								=	& RARG_PARAMETER_REF->allowed_types;

			/*======================================*/
#define RARG_SET_TO_FIRST_PROHIBITED_TYPE																																											\
			/*======================================*/																																										\
	RARG_PTR_PROHIBITED_TYPE								=	& RARG_PARAMETER_REF->prohibited_types;
	
			/*============================================*/
#define RARG_SET_TO_FIRST_ALLOWABLE_HASH_KEY_TYPE																																								\
			/*============================================*/																																							\
	RARG_PTR_ALLOWABLE_HASH_KEY_TYPE				=	& RARG_ALLOWABLE_TYPE_REF->allowed_hash_key_types;

			/*=============================================*/
#define RARG_SET_TO_FIRST_ALLOWABLE_HASH_DATA_TYPE																																							\
			/*=============================================*/																																						\
	RARG_PTR_ALLOWABLE_HASH_DATA_TYPE			=	& RARG_ALLOWABLE_TYPE_REF->allowed_hash_data_types;

			/*===============================================*/
#define RARG_SET_TO_FIRST_PROHIBITED_HASH_KEY_TYPE																																						\
			/*===============================================*/																																					\
	RARG_PTR_PROHIBITED_HASH_KEY_TYPE			=	& RARG_PROHIBITED_TYPE_REF->prohibited_hash_key_types;

			/*================================================*/
#define RARG_SET_TO_FIRST_PROHIBITED_HASH_DATA_TYPE																																						\
			/*================================================*/																																					\
	RARG_PTR_PROHIBITED_HASH_DATA_TYPE			=	& RARG_PROHIBITED_TYPE_REF->prohibited_hash_data_types;
	
/**************
*  Iteration  *
**************/

			/*=====================*/
#define RARG_NEXT_DESCRIPTOR																																																				\
			/*=====================*/																																																			\
	RARG_PTR_DESCRIPTOR									= & RARG_DESCRIPTOR_REF->next;

			/*====================*/
#define RARG_NEXT_PARAMETER																																																				\
			/*====================*/																																																			\
	RARG_PTR_PARAMETER									= & RARG_PARAMETER_REF->next;

			/*=========================*/
#define RARG_NEXT_ALLOWABLE_TYPE																																																		\
			/*=========================*/																																																	\
	RARG_PTR_ALLOWABLE_TYPE					= & RARG_ALLOWABLE_TYPE_REF->next;

			/*============================*/
#define RARG_NEXT_PROHIBITED_TYPE																																																\
			/*============================*/																																															\
	RARG_PTR_PROHIBITED_TYPE					= & RARG_PROHIBITED_TYPE_REF->next;

			/*==================================*/
#define RARG_NEXT_ALLOWABLE_HASH_KEY_TYPE																																													\
			/*==================================*/																																												\
	RARG_PTR_ALLOWABLE_HASH_KEY_TYPE	= & RARG_ALLOWABLE_HASH_KEY_TYPE_REF->next;

			/*===================================*/
#define RARG_NEXT_ALLOWABLE_HASH_DATA_TYPE																																													\
			/*===================================*/																																												\
	RARG_PTR_ALLOWABLE_HASH_DATA_TYPE	= & RARG_ALLOWABLE_HASH_DATA_TYPE_REF->next;

			/*=====================================*/
#define RARG_NEXT_PROHIBITED_HASH_KEY_TYPE																																												\
			/*=====================================*/																																											\
	RARG_PTR_PROHIBITED_HASH_KEY_TYPE	= & RARG_PROHIBITED_HASH_KEY_TYPE_REF->next;

			/*======================================*/
#define RARG_NEXT_PROHIBITED_HASH_DATA_TYPE																																											\
			/*======================================*/																																										\
	RARG_PTR_PROHIBITED_HASH_DATA_TYPE	= & RARG_PROHIBITED_HASH_DATA_TYPE_REF->next;

/*------------------------------------------------------------------------------*/

			/*============================*/
#define RARG_DEFINE_BASE_DESCRIPTOR																																																\
			/*============================*/																																															\
	rarg_descriptor_t*		RARG_VAR_DESCRIPTOR	=	NULL;

			/*===========*/
#define RARG_START																																																									\
			/*===========*/																																																								\
	RARG_SET_TO_FIRST_DESCRIPTOR

			/*=============*/
#define RARG_RESTART																																																								\
			/*=============*/																																																							\
	RARG_START

/*------------------------------------------------------------------------------*/

			/*===============================*/
#define RARG_CREATE_AND_INIT_OR_ADVANCE( ptr, ptr_to_ptr, type )																																		\
			/*===============================*/																																														\
	/* if pointer is still NULL we haven't initialized the first slot */																															\
	if ( ptr == NULL )	{																																																							\
		ptr = calloc( 1, sizeof( type ) );																																															\
		ptr_to_ptr	=	& ptr;																																																						\
	}																																																																	\
	/* otherwise init the next slot and move the pointer forward */																																		\
	else {																																																														\
		( *ptr_to_ptr )->next = calloc( 1, sizeof( type ) );																																						\
		ptr_to_ptr	=	& ( *ptr_to_ptr )->next;																																													\
	}

			/*====================*/
#define RARG_INIT_OR_ADVANCE( ptr_to_ptr, type )																																										\
			/*====================*/																																																			\
	/* if pointer is still NULL we haven't initialized the first slot */																															\
	if ( *ptr_to_ptr == NULL )	{																																																			\
		*ptr_to_ptr = calloc( 1, sizeof( type ) );																																											\
	}																																																																	\
	/* otherwise init the next slot and move the pointer forward */																																		\
	else {																																																														\
		( *ptr_to_ptr )->next = calloc( 1, sizeof( type ) );																																						\
		ptr_to_ptr	=	& ( *ptr_to_ptr )->next;																																													\
	}
	
#endif