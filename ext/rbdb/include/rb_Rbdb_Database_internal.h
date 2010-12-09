#ifndef RB_Rbdb_DATABASE_INTERNAL
	#define RB_Rbdb_DATABASE_INTERNAL

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

	VALUE rb_Rbdb_Database_internal_iterationCursor( VALUE rb_database );

	VALUE	rb_Rbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database_name,
	 																					VALUE	rb_callback_object,
																						VALUE	rb_callback_method );
																						
	Rbdb_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_secondaryKeyCreationCallbackMethod(	Rbdb_Database*			c_secondary_database, 
																										Rbdb_Record*			c_record, 
																										Rbdb_SecondaryKeys*	c_return_data );

	VALUE rb_Rbdb_Database_internal_removeCallbackInfoFromHash(	VALUE	rb_secondary_database );
	enum ruby_value_type rb_Rbdb_Database_internal_storageType( VALUE rb_database );
	Rbdb_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																													VALUE									rb_secondary_keys,
																																													Rbdb_SecondaryKeys*		c_secondary_keys );
	void rb_Rbdb_Database_internal_packRubyObjectOrValueForDatabaseStorage(	VALUE		rb_database,
																																					VALUE		rb_key_or_data,
																																					DBT*		c_key_dbt,
																																					BOOL		c_convert_string_encoding );
	void rb_Rbdb_Database_internal_packRubyValueForDatabaseStorage(	VALUE		rb_database,
																																	VALUE		rb_key_or_data,
																																	DBT*		c_key_or_data );

	VALUE rb_Rbdb_Database_internal_initRubyRuntimeStorage(	VALUE rb_ruby_runtime_storage_database );
	VALUE rb_Rbdb_Database_internal_storeRubyRuntimeInstanceForCInstance(	VALUE rb_database );
	VALUE rb_Rbdb_Database_internal_rubyRuntimeInstanceForCInstance(	void* c_rbdb_instance );
VALUE rb_Rbdb_Database_internal_createSecondaryIndex(	int			argc,
																											VALUE*	args,
																											VALUE		rb_primary_database_self,
																											BOOL		c_with_duplicates,
																											BOOL		c_with_sorted_duplicates );
static int rb_Rbdb_Database_internal_retrieveKeysForEachIndex(	VALUE	rb_index,
																																VALUE	rb_key_or_keys,
																																VALUE	rb_passed_args );
static int rb_Rbdb_Database_internal_writeDataForEachKey(	VALUE	rb_key,
																													VALUE	rb_data_or_datas,
																													VALUE	rb_passed_args );
static int rb_Rbdb_Database_internal_keyExistsForEachIndex(	VALUE	rb_index,
																														VALUE	rb_key_or_keys,
																														VALUE	rb_passed_args );

#endif
