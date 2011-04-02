#ifndef RB_RPBDB_TYPES
	#define RB_RPBDB_TYPES

	typedef struct rb_RPbdb_RPbdbDataFromHash rb_RPbdb_RPbdbDataFromHash;

	/******************
	*  foreach types  *
	******************/
		
	struct rb_RPbdb_RPbdbDataFromHash	{
		
		VALUE					rb_database;
		RPbdb_Record**	c_record;
		RPbdb_DBT**		c_dbt_pointers;
		int						count;
		uint32_t			total_size;
		
	}	c_passed_info;
		
#endif