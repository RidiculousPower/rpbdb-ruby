#ifndef RB_ARG_PARSER_TYPES
	#define RB_ARG_PARSER_TYPES

	#include <ruby.h>
	
	/* describes 1 possible argument format */
	typedef struct	rarg_descriptor_s								rarg_descriptor_t;
	typedef struct	rarg_parameter_s								rarg_parameter_t;
	typedef int																			rarg_type_t;
	typedef struct	rarg_allowed_type_s							rarg_allowed_type_t;
	typedef struct	rarg_prohibited_type_s					rarg_prohibited_type_t;
	typedef union		rarg_allowable_or_prohibited_u	rarg_allowable_or_prohibited_t;

	//	RARG_DESCRIPTOR( "description" )
	struct rarg_descriptor_s	{
		rarg_parameter_t*									parameters;
		rarg_descriptor_t*								next;
	};
	//	RARG_PARAMETER( "description" )
	struct rarg_parameter_s	{		
		rarg_allowed_type_t*							allowed_types;
		rarg_prohibited_type_t*						prohibited_types;
		rarg_parameter_t*									next;
	};
	//	RARG_ALLOW( T_TYPE )
	//	RARG_ALLOW_HASH_KEY
	//	RARG_ALLOW_HASH_DATA
	struct rarg_allowed_type_s	{
		rarg_type_t												type;
		VALUE*														parameter_value_receiver;		
		rarg_allowed_type_t*							allowed_hash_key_types;
		rarg_allowed_type_t*							allowed_hash_data_types;
		rarg_prohibited_type_t*						prohibited_hash_key_types;
		rarg_prohibited_type_t*						prohibited_hash_data_types;
		rarg_allowed_type_t*							next;
	};
	//	RARG_PROHIBIT( T_TYPE )
	struct rarg_prohibited_type_s	{
		rarg_type_t												type;
		rarg_prohibited_type_t*						prohibited_hash_key_types;
		rarg_prohibited_type_t*						prohibited_hash_data_types;
		VALUE															exception_type;
		char*															error_message;
		rarg_prohibited_type_t*						next;
	};

	union rarg_allowable_or_prohibited_u	{
		rarg_allowed_type_t**						allowed_type;
		rarg_prohibited_type_t**				prohibited_type;
	};

	#ifndef FALSE
		#define FALSE 0
	#endif
	#ifndef TRUE
		#define TRUE 1
	#endif
	#define RARG_CONTINUE -1

	#define T_ANY			-0x01
	#define T_NOT_NIL -0x02

#endif