#ifndef RB_RPDB_DATABASE_OBJECT
	#define RB_RPDB_DATABASE_OBJECT

	//	This is a module - rb_self refers to the object currently implementing the module

	#include <rpdb/RPDB_Database.h>
	#include <rpdb/RPDB_Record.h>

	void Init_RPDB_Module();
	VALUE rb_RPDB_DatabaseObject_initRPDB( VALUE	rb_klass_self );
VALUE rb_RPDB_DatabaseObject_hasConfigured( VALUE rb_self );
VALUE rb_RPDB_DatabaseObject_hasInitialized( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_configureRPDB( VALUE	rb_klass_self );
VALUE rb_RPDB_DatabaseObject_include(	VALUE	rb_klass_self,
									  VALUE	rb_module );
VALUE rb_RPDB_DatabaseObject_identifyAs(	VALUE	rb_klass_self );
	VALUE rb_RPDB_DatabaseObject_pathsafeClassname( VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_setEnvironment(	VALUE	rb_self,
												 VALUE	rb_environment_or_name );
	VALUE rb_RPDB_DatabaseObject_environment(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_database(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_databases( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_databaseWithIndex(	VALUE	rb_self,
												   VALUE	rb_index_method );
VALUE rb_RPDB_DatabaseObject_setDatabase(	VALUE	rb_self,
										  VALUE	rb_database_or_name );
VALUE rb_RPDB_DatabaseObject_setStoreAsClass(	VALUE	rb_self,
											  VALUE	rb_store_as_class	);
	VALUE rb_RPDB_DatabaseObject_primaryKeyMethod(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_setPrimaryKeyMethod(	VALUE	rb_self,
													  VALUE	rb_primary_key_method	);
	VALUE rb_RPDB_DatabaseObject_primaryKeyValue(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_secondaryKeyMethods(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_addSecondaryKeyMethod(	int	argc,
														VALUE*	args,
														VALUE	rb_self	);
	VALUE rb_RPDB_DatabaseObject_addUniqueSecondaryKeyMethod(	int	argc,
															  VALUE*	args,
															  VALUE	rb_self	);
	VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKeyMethods(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_nonUniqueSecondaryKeyMethods(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_uniqueKeyMethod(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_uniqueKeyMethods(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_keyMethods(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_primaryKey( VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_uniqueKey( VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_uniqueKeys(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_isUniqueKeyMethod(	VALUE	rb_self,
														VALUE	rb_key_method_symbol );
	VALUE rb_RPDB_DatabaseObject_secondaryKeys(	VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKey(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_uniqueSecondaryKeys(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_nonUniqueSecondaryKeys(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_keys(	VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_requireEnvironment( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_requireDefaultEnvironment( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_requireDatabaseWithIndex(	VALUE	rb_self,
															VALUE	rb_index);
	VALUE rb_RPDB_DatabaseObject_requireUniqueKeyMethod( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_requireUniqueKey( VALUE rb_self );
	VALUE rb_RPDB_DatabaseObject_write(	int	argc,
											VALUE*	args,
											VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_exists(	int	argc,
									 VALUE*	args,
									 VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_setStoredInitializeArguments(	int	argc,
																VALUE*	args,
																VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_storedInitializeArguments(	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_addStoredInitializeArguments(	int	argc,
																VALUE*	args,
																VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_retrieve(	int	argc,
											VALUE*	args,
											VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_retrieveWithInitializeArgs(	int	argc,
																VALUE*	args,
																VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_retrieveWithKeyAndInitializeArgs(	int	argc,
																	VALUE*	args,
																	VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_delete(	int	argc,
											VALUE*	args,
											VALUE	rb_self );
	
VALUE rb_RPDB_DatabaseObject_cursor( int	argc,
									 VALUE*	args,
									 VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_cursors( VALUE rb_self );
VALUE rb_RPDB_DatabaseObject_iterate( int	argc,
									  VALUE*	args,
									  VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_iterateInSegments( VALUE	rb_self,
									   VALUE	rb_items_per_segment );
VALUE rb_RPDB_DatabaseObject_iterateAll( int	argc,
										 VALUE*	args,
										 VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_iterateAllInSegments(	VALUE	rb_self,
										  VALUE	rb_items_per_segment );
VALUE rb_RPDB_DatabaseObject_iterateDuplicates( int	argc,
												VALUE*	args,
												VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_iterateDuplicatesInSegments(	VALUE	rb_self,
												 VALUE	rb_items_per_segment );
VALUE rb_RPDB_DatabaseObject_iterateKeys( int	argc,
										  VALUE*	args,
										  VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_iterateKeysInSegments( VALUE	rb_self,
										   VALUE	rb_items_per_segment );

VALUE rb_RPDB_DatabaseObject_declareUniqueJoin(	int		argc,
											   VALUE*	args,
											   VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_isUniqueJoin(	int		argc,
										  VALUE*	args,
										  VALUE	rb_self );	
	
#endif
