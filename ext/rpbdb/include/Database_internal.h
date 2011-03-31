#ifndef RB_RPBDB_DATABASE_INTERNAL
	#define RB_RPBDB_DATABASE_INTERNAL

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

	VALUE rb_RPbdb_Database_internal_iterationCursor( VALUE rb_database );

	VALUE	rb_RPbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	VALUE	rb_primary_database_self,
																																									VALUE	rb_index,
																																									VALUE	rb_callback_object );
																						
	RPBDB_SECONDARY_KEY_CREATION_RETURN rb_RPbdb_Database_internal_secondaryKeyCreationCallbackMethod(	RPbdb_Database*			c_secondary_database, 
																										RPbdb_Record*			c_record, 
																										RPbdb_SecondaryKeys*	c_return_data );

	VALUE rb_RPbdb_Database_internal_removeCallbackInfoFromHash(	VALUE	rb_secondary_database );
	RPBDB_SECONDARY_KEY_CREATION_RETURN rb_RPbdb_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																													VALUE									rb_secondary_keys,
																																													RPbdb_SecondaryKeys*		c_secondary_keys );
	void rb_RPbdb_Database_internal_packRubyObjectOrValueForDatabaseStorage(	VALUE		rb_database,
																																					VALUE		rb_key_or_data,
																																					RPbdb_DBT*		c_key,
																																					BOOL		c_convert_string_encoding );
	void rb_RPbdb_Database_internal_packRubyValueForDatabaseStorage(	VALUE				rb_database,
																																	VALUE				rb_key_or_data,
																																	RPbdb_DBT*		c_key_or_data );
	void rb_RPbdb_Database_internal_packRubyValueForDatabaseStorageForBDBDBT(	VALUE		rb_database,
																																						VALUE		rb_key_or_data,
																																						DBT*		c_key_or_data );


	VALUE rb_RPbdb_Database_internal_initRubyRuntimeStorage(	VALUE rb_ruby_runtime_storage_database );
	VALUE rb_RPbdb_Database_internal_storeRubyRuntimeInstanceForCInstance(	VALUE rb_database );
	VALUE rb_RPbdb_Database_internal_rubyRuntimeInstanceForCInstance(	void* c_rpbdb_instance );
VALUE rb_RPbdb_Database_internal_createSecondaryIndex(	int			argc,
																											VALUE*	args,
																											VALUE		rb_primary_database_self,
																											BOOL		c_with_duplicates,
																											BOOL		c_with_sorted_duplicates );
VALUE rb_RPbdb_Database_internal_uniqueIndexesHash( VALUE	rb_database );

VALUE rb_RPbdb_Database_internal_removeSecondaryDatabaseFromHash( VALUE rb_database );

RPbdb_Record* rb_RPbdb_Database_internal_recordForRubyKeyData(	VALUE	rb_database,
																															VALUE	rb_key,
																															VALUE	rb_data );
RPbdb_Record* rb_RPbdb_Database_internal_recordForRubyKey(	VALUE	rb_database,
																													VALUE	rb_key );
void rb_RPbdb_Database_internal_packDBTForRubyInstance(	VALUE				rb_database,
																												VALUE				rb_object,
																												RPbdb_DBT*		c_dbt,
																												BOOL				key_not_data );
VALUE rb_RPbdb_Database_internal_unpackDBTForRubyInstance(	VALUE				rb_database,
																													RPbdb_DBT*		c_dbt,
																													BOOL				key_not_data );

CerializeType rb_RPbdb_Database_internal_storageTypeForRubyInstance( VALUE rb_object );
CerializeType rb_RPbdb_Database_internal_storageTypeForRubyClass( VALUE rb_object );

#endif
