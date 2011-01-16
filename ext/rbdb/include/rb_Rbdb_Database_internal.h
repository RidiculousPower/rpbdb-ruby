#ifndef RB_RBDB_DATABASE_INTERNAL
	#define RB_RBDB_DATABASE_INTERNAL

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

	VALUE rb_Rbdb_Database_internal_iterationCursor( VALUE rb_database );

	VALUE	rb_Rbdb_Database_internal_setSecondaryKeyCreationCallbackMethodInfo(	VALUE	rb_primary_database_self,
																																									VALUE	rb_index,
																																									VALUE	rb_callback_object );
																						
	RBDB_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_secondaryKeyCreationCallbackMethod(	Rbdb_Database*			c_secondary_database, 
																										Rbdb_Record*			c_record, 
																										Rbdb_SecondaryKeys*	c_return_data );

	VALUE rb_Rbdb_Database_internal_removeCallbackInfoFromHash(	VALUE	rb_secondary_database );
	RBDB_SECONDARY_KEY_CREATION_RETURN rb_Rbdb_Database_internal_processSecondaryKeyReturn(	VALUE									rb_secondary_database,
																																													VALUE									rb_secondary_keys,
																																													Rbdb_SecondaryKeys*		c_secondary_keys );
	void rb_Rbdb_Database_internal_packRubyObjectOrValueForDatabaseStorage(	VALUE		rb_database,
																																					VALUE		rb_key_or_data,
																																					Rbdb_DBT*		c_key,
																																					BOOL		c_convert_string_encoding );
	void rb_Rbdb_Database_internal_packRubyValueForDatabaseStorage(	VALUE				rb_database,
																																	VALUE				rb_key_or_data,
																																	Rbdb_DBT*		c_key_or_data );
	void rb_Rbdb_Database_internal_packRubyValueForDatabaseStorageForBDBDBT(	VALUE		rb_database,
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
VALUE rb_Rbdb_Database_internal_uniqueIndexesHash( VALUE	rb_database );


Rbdb_Record* rb_Rbdb_Database_internal_recordForRubyKeyData(	VALUE	rb_database,
																															VALUE	rb_key,
																															VALUE	rb_data );
Rbdb_Record* rb_Rbdb_Database_internal_recordForRubyKey(	VALUE	rb_database,
																													VALUE	rb_key );
void rb_Rbdb_Database_internal_packDBTForRubyInstance(	VALUE				rb_database,
																												VALUE				rb_object,
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyFile(	VALUE				rb_database,
																								VALUE				rb_file,
																								Rbdb_DBT*		c_dbt,
																								BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubySymbol(	VALUE				rb_database,
																									VALUE				rb_symbol,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyRegexp(	VALUE				rb_database,
																									VALUE				rb_regexp,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyClassName(	VALUE				rb_database,
																										VALUE				rb_class,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyString(	VALUE				rb_database,
																									VALUE				rb_string,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyComplex(	VALUE				rb_database,
																									VALUE				rb_complex_number,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyRational(	VALUE				rb_database,
																										VALUE				rb_rational_number,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyInteger(	VALUE				rb_database,
																									VALUE				rb_integer,
																									Rbdb_DBT*		c_dbt,
																									BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyFloat(	VALUE				rb_database,
																								VALUE				rb_float,
																								Rbdb_DBT*		c_dbt,
																								BOOL				key_not_data );
void rb_Rbdb_Database_internal_DBTForRubyTrueFalse(	VALUE				rb_database,
																										VALUE				rb_object,
																										Rbdb_DBT*		c_dbt,
																										BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_unpackDBTForRubyInstance(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbFile(	VALUE				rb_database,
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbSymbol(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbRegexp(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbClassName(	VALUE				rb_database,
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbString(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbComplex(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbRational(	VALUE				rb_database,
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbInteger(	VALUE				rb_database,
																													Rbdb_DBT*		c_dbt,
																													BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbFloat(	VALUE				rb_database,
																												Rbdb_DBT*		c_dbt,
																												BOOL				key_not_data );
VALUE rb_Rbdb_Database_internal_RubyObjectForRbdbTrueFalse(	VALUE				rb_database,
																														Rbdb_DBT*		c_dbt,
																														BOOL				key_not_data );

Rbdb_DatabaseRecordStorageType rb_Rbdb_Database_internal_storageTypeForRubyInstance( VALUE rb_object );
Rbdb_DatabaseRecordStorageType rb_Rbdb_Database_internal_storageTypeForRubyClass( VALUE rb_object );

#endif
