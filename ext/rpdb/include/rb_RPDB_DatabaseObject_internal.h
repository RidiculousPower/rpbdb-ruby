#ifndef RB_RPDB_DATABASE_OBJECT_INTERNAL
	#define RB_RPDB_DATABASE_OBJECT_INTERNAL

	VALUE rb_RPDB_DatabaseObject_internal_cursorForCallingContext( VALUE rb_self );
VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_wrapper( VALUE rb_args );
VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame_exception_return_cursor( VALUE rb_args );
VALUE rb_RPDB_DatabaseObject_internal_each_backtrace_frame(	VALUE	rb_this_backtrace_frame_hash, 
															VALUE	rb_args );
	void rb_RPDB_DatabaseObject_internal_beginCursorContext(	VALUE	rb_self,
															 VALUE	rb_cursor );
	void rb_RPDB_DatabaseObject_internal_endCursorContext(	VALUE	rb_self,
														   VALUE	rb_cursor );
	VALUE rb_RPDB_DatabaseObject_internal_cursorContextStorageHash( VALUE rb_self );
VALUE rb_RPDB_DatabaseObject_internal_cursorObjectContextStorageHash( VALUE	rb_cursor_context_storage_hash,
																	  VALUE	rb_object_context );
	
	void rb_RPDB_DatabaseObject_internal_storeEnvironment(	VALUE	rb_self,
														   VALUE	rb_environment	);
	VALUE rb_RPDB_DatabaseObject_internal_getEnvironment(	VALUE	rb_self );
	void rb_RPDB_DatabaseObject_internal_storeDatabase(	VALUE	rb_self,
														VALUE	rb_database,
														VALUE	rb_index_method	);
	VALUE rb_RPDB_DatabaseObject_internal_getDatabase( VALUE	rb_self,
													   VALUE	rb_index_method );
	VALUE rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceArray(	VALUE	rb_self,
																		   char*	rb_class_instance_array_name,
																		   VALUE	rb_index_method	);
	VALUE rb_RPDB_DatabaseObject_internal_getClassInstanceArray(	VALUE	rb_self,
																	char*	c_class_instance_hash_name );
	VALUE rb_RPDB_DatabaseObject_internal_storeObjectInClassInstanceHash(	VALUE	rb_self,
																		  char*	rb_class_instance_hash_name,
																		  VALUE	rb_index_method,
																		  VALUE	rb_object  );
	VALUE rb_RPDB_DatabaseObject_internal_getObjectFromClassInstanceHash(	VALUE	rb_self,
																		  char*	rb_class_instance_hash_name,
																		  VALUE	rb_index_method );
VALUE rb_RPDB_DatabaseObject_mergedInitializeArguments(	int		argc,
														VALUE*	args,
														VALUE	rb_self );
void rb_RPDB_DatabaseObject_internal_packRubyObjectForDatabaseStorage(	VALUE	rb_key,
																	   DBT*	c_key_dbt	);
	VALUE rb_RPDB_DatabaseObject_internal_unpackRubyObjectFromDatabaseStorage( VALUE		rb_message_packed_string );
	RPDB_Record* rb_RPDB_DatabaseObject_internal_compactRetrievalObject( VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_internal_extractRetrievalKey( RPDB_Record* c_retrieval_record );
	VALUE rb_RPDB_DatabaseObject_internal_extractRetrievalData( RPDB_Record* c_retrieval_record );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameters(	int	argc,
																					VALUE*	args,
																					VALUE	rb_klass_self );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataFromParameterDescription(	VALUE	rb_self,
																											VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveEachOfMultipleFromParameterDataArray(	VALUE	rb_self,
																										VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataHash(	VALUE	rb_self,
																									   VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataPrimaryKey(	VALUE	rb_self,
																											 VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataMethodValueKeyHash(	VALUE	rb_self,
																													 VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataSecondaryKey(	VALUE	rb_self,
																											   VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedDataUniqueKey(	VALUE	rb_self,
																											VALUE	rb_unique_key_parameter );
	VALUE rb_RPDB_DatabaseObject_internal_createTemporaryRetrievalObjectFromParameterDescription(	VALUE	rb_self,
																								  VALUE	rb_key_method_symbol_or_string,
																								  VALUE	rb_key_value );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveCursorForParameterDescription(	VALUE	rb_self,
																								   VALUE	rb_key_method_symbol,
																								   VALUE	rb_key_value );
	VALUE rb_RPDB_DatabaseObject_internal_retrieveSelfAsPrimaryPackedData( VALUE	rb_self );
	VALUE rb_RPDB_DatabaseObject_internal_verifyObjectAsEnvironment( VALUE rb_object );
	VALUE rb_RPDB_DatabaseObject_internal_verifyObjectAsDatabase( VALUE rb_object );
	void rb_RPDB_DatabaseObject_internal_requireObjectVerifyAsEnvironment( VALUE rb_object );
	void rb_RPDB_DatabaseObject_internal_requireObjectVerifyAsDatabase( VALUE rb_object );
	VALUE rb_RPDB_DatabaseObject_internal_verifyObjectHasMethods(	VALUE	rb_object,
																 VALUE	rb_method_symbol_array );
	VALUE rb_RPDB_DatabaseObject_internal_addSecondaryKeyMethods(	VALUE	rb_self,
																  char*	rb_secondary_key_class_instance_variable,
																  int		argc,
																  VALUE*	args	);
	VALUE rb_RPDB_DatabaseObject_internal_createAndAssociateSecondaryDatabase(	VALUE	rb_self,
																				VALUE	rb_index_method_symbol );
	RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_DatabaseObject_internal_secondaryKeyCreationCallbackMethod(	RPDB_Database*			c_secondary_database, 
																												RPDB_Record*			c_record, 
																												RPDB_SecondaryKeys*	c_secondary_keys );
	VALUE rb_RPDB_DatabaseObject_internal_identifiesWithCurrentlyOpenOrDefaultEnvironment(	VALUE	rb_klass_self,
																					VALUE	rb_identifiers );
VALUE rb_RPDB_DatabaseObject_internal_identifiesWithCurrentlyOpenEnvironment(	VALUE	rb_klass_self,
																			  VALUE	rb_environments_hash );
VALUE rb_RPDB_DatabaseObject_internal_identifiersAllowDefaultEnvironment(	VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_internal_initWithDefaultEnvironment(	VALUE	rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_activateClass(	VALUE	rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_addToAppropriateWaitlist(	VALUE	rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_configureWithEnvironment(	VALUE	rb_klass_self,
																VALUE	rb_environment );
VALUE rb_RPDB_DatabaseObject_internal_ensureInitialized( VALUE	rb_self );
VALUE rb_RPDB_DatabaseObject_internal_setHasConfigured(	VALUE	rb_klass_self,
														VALUE	rb_true_or_false );
VALUE rb_RPDB_DatabaseObject_internal_setHasInitialized(	VALUE	rb_klass_self,
														 VALUE	rb_true_or_false  );
VALUE rb_RPDB_DatabaseObject_internal_markForDefaultEnvironment( VALUE rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_markForIdentification( VALUE rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_markForInitialization( VALUE rb_klass_self );
VALUE rb_RPDB_DatabaseObject_internal_identifiers( VALUE rb_self );
VALUE rb_RPDB_DatabaseObject_internal_callInitRPDB( VALUE rb_self );
	
VALUE rb_RPDB_DatabaseObject_internal_uniqueJoinDeclarationHash( VALUE rb_self );
void rb_RPDB_DatabaseObject_internal_addChainedMember(	VALUE	rb_hash_self,
														VALUE	rb_array_of_items );

#endif