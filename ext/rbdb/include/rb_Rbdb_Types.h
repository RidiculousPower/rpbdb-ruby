#ifndef RB_RBDB_TYPES
	#define RB_RBDB_TYPES

	typedef struct rb_Rbdb_RbdbDataFromHash rb_Rbdb_RbdbDataFromHash;

	/******************
	*  foreach types  *
	******************/
		
	struct rb_Rbdb_RbdbDataFromHash	{
		
		VALUE					rb_database;
		Rbdb_Record**	c_record;
		Rbdb_DBT**		c_dbt_pointers;
		int						count;
		uint32_t			total_size;
		
	}	c_passed_info;
		
#endif