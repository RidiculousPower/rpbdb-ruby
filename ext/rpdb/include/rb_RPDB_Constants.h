#ifndef RB_RPDB_CONSTANTS
	#define RB_RPDB_CONSTANTS

	#define RPDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH										"@rpdb__extended_classes_hash"
	#define RPDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH								"@rpdb__included_for_classes_hash"

	//	Ruby items that exist in a one => many storage relation require runtime storages 
	//	so that garbage collection can function properly; otherwise the item stored in the hash will prevent
	//	collection from even taking place.
	#define	RPDB_RUBY_RUNTIME_STORAGE_ENVIRONMENT_HANDLE											"ruby_environments"
	#define	RPDB_RUBY_RUNTIME_STORAGE_DATABASE_HANDLE													"ruby_databases"
	#define	RPDB_RUBY_RUNTIME_STORAGE_DATABASE_CURSOR_HANDLE									"ruby_database_cursors"

	//	Module Variables

	#define RPDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS														"@rpdb__environments"
	#define RPDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY					"@rpdb__identification_wait_list"
	#define RPDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY			"@rpdb__current_working_environment_wait_list"
	#define RPDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY					"@rpdb__initialization_wait_list_array"
	#define RPDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK				"@current_working_environment_stack"
	#define RPDB_RUBY_MODULE_VARIABLE_ENVIRONMENT_COUNT												"@rpdb__environment_count"
	#define RPDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE								"@rpdb__database_runtime_storage"
	#define RPDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS										"@rpdb_secondary_key_callback_methods"

	//	Class Variables
	
	//	Environment
	#define RPDB_RUBY_CLASS_ENVIRONMENT_VARIABLE_CONFIGURED_CLASSES						"@rpdb__configured_classes_array"
	#define RPDB_RUBY_CLASS_ENVIRONMENT_VARIABLE_DATABASE_CONTROLLER					"@database_controller"
	#define RPDB_RUBY_CLASS_ENVIRONMENT_VARIABLE_TRANSACTION_CONTROLLER				"@transaction_controller"
	#define RPDB_RUBY_CLASS_ENVIRONMENT_VARIABLE_SETTINGS_CONTROLLER					"@settings_controller"

	//	Database Controller
	#define RPDB_RUBY_CLASS_DATABASE_CONTROLLER_VARIABLE_DATABASES_HASH				"@rpdb__databases_hash"

	//	Database
	#define RPDB_RUBY_CLASS_DATABASE_VARIABLE_DATABASE_CONTROLLER							"@database_controller"
	#define RPDB_RUBY_CLASS_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE										"@storage_type"

	//	Database Cursor
	#define RPDB_RUBY_CLASS_DATABASE_CURSOR_CONTROLLER												"@database_cursor_controller"
	#define RPDB_RUBY_CLASS_DATABASE_JOIN_CONTROLLER													"@database_join_controller"
	#define RPDB_RUBY_CLASS_SECONDARY_DATABASES																"@secondary_databases"

	#define RPDB_RUBY_CLASS_DATABASE_SEQUENCE_CONTROLLER											"@database_sequence_controller"

	#define RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_ENVIRONMENT										"@parent_environment"
	#define RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE											"@parent_database"
	#define RPDB_RUBY_CLASS_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER		"@parent_database_cursor_controller"

	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER				"@file_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER				"@error_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER					"@log_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_MEMORY_SETTINGS_CONTROLLER			"@memory_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER		"@database_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER		"@database_cursor_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER		"@directory_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER "@database_sequence_settings_controller"
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER "@database_join_settings_controller"
	
	#define RPDB_RUBY_CLASS_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA		"@serialize_data"

	#define RPDB_FUNCTION_INIT																								"init_rpdb"
	#define RPDB_FUNCTION_CONFIGURE																						"configure_rpdb"
	#define RPDB_FUNCTION_IDENTIFY_AS																					"identify_for_rpdb_as"

	#define	RPDB_RUBY_CONSTANT_DEFAULT																				"Default"

	#define RPDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED			"Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."
	#define RPDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND											"Requested Environment was missing."
	#define RPDB_RUBY_ERROR_MESSAGE_DATABASE_CONTROLLER_NOT_FOUND							"Requested Environment was missing."
	#define RPDB_RUBY_ERROR_ENVIRONMENT_WITH_NAME_ALREADY_EXISTS							"Environment with requested name already exists."

	#define RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY													"Cannot write to database without key."
	#define RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA													"Cannot write to database without data."
	#define RPDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY												"Cannot retrieve to database without key."
	#define RPDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA											"Cannot retrieve to database without data."

	#define RPDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK						"Secondary key creation callback method/proc has unexpected arity. Expected 1, 2, 3 or -1."

	/****************************
	*	Get Ruby from C Macros	*
	****************************/

	#define RUBY_RPDB_ENVIRONMENT( c_environment )																																RUBY_RPDB_OBJECT(	c_environment, rb_RPDB_Environment, NULL, NULL )
	#define RUBY_RPDB_ENVIRONMENT_WITH_FREE( c_environment )																											RUBY_RPDB_OBJECT(	c_environment, rb_RPDB_Environment, NULL, rb_RPDB_Environment_free )
	#define C_RPDB_ENVIRONMENT( rb_environment, c_environment )																										C_RPDB_STRUCT(		rb_environment, c_environment, RPDB_Environment )
                                                                                                    								
	#define RUBY_RPDB_DATABASE_CONTROLLER( c_database_controller )																								RUBY_RPDB_OBJECT(	c_database_controller, rb_RPDB_DatabaseController, NULL, NULL )
	#define C_RPDB_DATABASE_CONTROLLER( rb_database_controller, c_database_controller )														C_RPDB_STRUCT(		rb_database_controller, c_database_controller, RPDB_DatabaseController )
                                                                                                    								
	#define RUBY_RPDB_DATABASE( c_database )																									RUBY_RPDB_OBJECT(	c_database, rb_RPDB_Database, NULL, NULL )
	#define C_RPDB_DATABASE( rb_database, c_database )																				C_RPDB_STRUCT(		rb_database, c_database, RPDB_Database )

	#define RUBY_RPDB_DATABASE_OBJECT_DATABASE( c_database )																		RUBY_RPDB_OBJECT(	c_database, rb_RPDB_DatabaseObjectDatabase, NULL, NULL )
	#define C_RPDB_DATABASE_OBJECT_DATABASE( rb_database, c_database )																C_RPDB_STRUCT(		rb_database, c_database, RPDB_Database )

	#define RUBY_RPDB_DATABASE_CURSOR_CONTROLLER( c_cursor_controller )															RUBY_RPDB_OBJECT(	c_cursor_controller, rb_RPDB_DatabaseCursorController, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR_CONTROLLER( rb_cursor_controller, c_cursor_controller )											C_RPDB_STRUCT(		rb_cursor_controller, c_cursor_controller, RPDB_DatabaseCursorController )
                                                                            														
	#define RUBY_RPDB_DATABASE_CURSOR( c_cursor )																					RUBY_RPDB_OBJECT(	c_cursor, rb_RPDB_DatabaseCursor, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR( rb_cursor, c_cursor )																			C_RPDB_STRUCT(		rb_cursor, c_cursor, RPDB_DatabaseCursor )
                                                                            														
	#define RUBY_RPDB_DATABASE_OBJECT_CURSOR( c_cursor )																			RUBY_RPDB_OBJECT(	c_cursor, rb_RPDB_DatabaseObjectCursor, NULL, NULL )
	#define C_RPDB_DATABASE_OBJECT_CURSOR( rb_cursor, c_cursor )																	C_RPDB_STRUCT(		rb_cursor, c_cursor, RPDB_DatabaseCursor )
                                                                                                    								
	#define RUBY_RPDB_DATABASE_JOIN_CONTROLLER( c_join_controller )																RUBY_RPDB_OBJECT(	c_join_controller, rb_RPDB_DatabaseJoinController, NULL, NULL )
	#define C_RPDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller )												C_RPDB_STRUCT(		rb_join_controller, c_join_controller, RPDB_DatabaseJoinController )
                                                                            														
	#define RUBY_RPDB_DATABASE_JOIN_CURSOR( c_join_cursor )																		RUBY_RPDB_OBJECT(	c_join_cursor, rb_RPDB_DatabaseJoinCursor, NULL, NULL )
	#define C_RPDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor )															C_RPDB_STRUCT(		rb_join_cursor, c_join_cursor, RPDB_DatabaseJoinCursor )
                                                                                                                            		
	#define RUBY_RPDB_DATABASE_SEQUENCE_CONTROLLER( c_database_sequence_controller )												RUBY_RPDB_OBJECT(	c_database_sequence_controller, rb_RPDB_DatabaseSequenceController, NULL, NULL )
	#define C_RPDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller )					C_RPDB_STRUCT(		rb_database_sequence_controller, c_database_sequence_controller, RPDB_DatabaseSequenceController )
                                                                                                                            		
	#define RUBY_RPDB_DATABASE_SEQUENCE( c_database_sequence )																		RUBY_RPDB_OBJECT(	c_database_sequence, rb_RPDB_DatabaseSequence, NULL, NULL )
	#define C_RPDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence )													C_RPDB_STRUCT(		rb_database_sequence, c_database_sequence, RPDB_DatabaseSequence )

	#define RUBY_RPDB_ERROR_CONTROLLER( c_error_controller )																		RUBY_RPDB_OBJECT(	c_error_controller, rb_RPDB_ErrorController, NULL, NULL )
	#define C_RPDB_ERROR_CONTROLLER( rb_error_controller, c_error_controller )														C_RPDB_STRUCT(		rb_error_controller, c_error_controller, RPDB_ErrorController )

	#define RUBY_RPDB_ERROR( c_error )																								RUBY_RPDB_OBJECT(	c_error, rb_RPDB_Error, NULL, NULL )
	#define C_RPDB_ERROR( rb_error, c_error )																						C_RPDB_STRUCT(		rb_error, c_error, RPDB_Error )

	#define RUBY_RPDB_LOCK_CONTROLLER( c_lock_controller )																			RUBY_RPDB_OBJECT(	c_lock_controller, rb_RPDB_LockController, NULL, NULL )
	#define C_RPDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller )														C_RPDB_STRUCT(		rb_lock_controller, c_lock_controller, RPDB_LockController )

	#define RUBY_RPDB_LOCK( c_lock )																								RUBY_RPDB_OBJECT(	c_lock, rb_RPDB_Lock, NULL, NULL )
	#define C_RPDB_LOCK( rb_lock, c_lock )																							C_RPDB_STRUCT(		rb_lock, c_lock, RPDB_Lock )

	#define RUBY_RPDB_LOG_CONTROLLER( c_log_controller )																			RUBY_RPDB_OBJECT(	c_log_controller, rb_RPDB_LogController, NULL, NULL )
	#define C_RPDB_LOG_CONTROLLER( rb_log_controller, c_log_controller )															C_RPDB_STRUCT(		rb_log_controller, c_log_controller, RPDB_LogController )

	#define RUBY_RPDB_LOG( c_log )																									RUBY_RPDB_OBJECT(	c_log, rb_RPDB_Log, NULL, NULL )
	#define C_RPDB_LOG( rb_log, c_log )																							C_RPDB_STRUCT(		rb_log, c_log, RPDB_Log )

	#define RUBY_RPDB_LOG_CURSOR_CONTROLLER( c_log_cursor_controller )																RUBY_RPDB_OBJECT(	c_log_cursor_controller, rb_RPDB_LogCursorController, NULL, NULL )
	#define C_RPDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller )										C_RPDB_STRUCT(		rb_log_cursor_controller, c_log_cursor_controller, RPDB_LogCursorController )

	#define RUBY_RPDB_LOG_CURSOR( c_log_cursor )																					RUBY_RPDB_OBJECT(	c_log_cursor, rb_RPDB_LogCursor, NULL, NULL )
	#define C_RPDB_LOG_CURSOR( rb_log_cursor, c_log_cursor )																		C_RPDB_STRUCT(		rb_log_cursor, c_log_cursor, RPDB_LogCursor )

	#define RUBY_RPDB_LOG_SEQUENCE_NUMBER( c_log_sequence_number )																	RUBY_RPDB_OBJECT(	c_log_sequence_number, rb_RPDB_LogSequenceNumber, NULL, NULL )
	#define C_RPDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number )											C_RPDB_STRUCT(		rb_log_sequence_number, c_log_sequence_number, RPDB_LogSequenceNumber )

	#define RUBY_RPDB_MEMORY_POOL_CONTROLLER( c_memory_pool_controller )															RUBY_RPDB_OBJECT(	c_memory_pool_controller, rb_RPDB_MemoryPoolController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller )									C_RPDB_STRUCT(		rb_memory_pool_controller, c_memory_pool_controller, RPDB_MemoryPoolController )

	#define RUBY_RPDB_MEMORY_POOL_FILE_CONTROLLER( c_memory_pool_file_controller )													RUBY_RPDB_OBJECT(	c_memory_pool_file_controller, rb_RPDB_MemoryPoolFileController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller )					C_RPDB_STRUCT(		rb_memory_pool_file_controller, c_memory_pool_file_controller, RPDB_MemoryPoolFileController )

	#define RUBY_RPDB_MEMORY_POOL_FILE( c_memory_pool_file )																		RUBY_RPDB_OBJECT(	c_memory_pool_file, rb_RPDB_MemoryPoolFile, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file )														C_RPDB_STRUCT(		rb_memory_pool_file, c_memory_pool_file, RPDB_MemoryPoolFile )

	#define RUBY_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( c_memory_pool_file_page_controller )										RUBY_RPDB_OBJECT(	c_memory_pool_file_page_controller, rb_RPDB_MemoryPoolFilePageController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller )		C_RPDB_STRUCT(		rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller, RPDB_MemoryPoolFilePageController )

	#define RUBY_RPDB_MEMORY_POOL_FILE_PAGE( c_memory_pool_file_page )																RUBY_RPDB_OBJECT(	c_memory_pool_file_page, rb_RPDB_MemoryPoolFilePage, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page )										C_RPDB_STRUCT(		rb_memory_pool_file_page, c_memory_pool_file_page, RPDB_MemoryPoolFilePage )

	#define RUBY_RPDB_MUTEX_CONTROLLER( c_mutex_controller )																		RUBY_RPDB_OBJECT(	c_mutex_controller, rb_RPDB_MutexController, NULL, NULL )
	#define C_RPDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller )														C_RPDB_STRUCT(		rb_mutex_controller, c_mutex_controller, RPDB_MutexController )

	#define RUBY_RPDB_MUTEX( c_mutex )																								RUBY_RPDB_OBJECT(	c_mutex, rb_RPDB_Mutex, NULL, NULL )
	#define C_RPDB_MUTEX( rb_mutex, c_mutex )																						C_RPDB_STRUCT(		rb_mutex, c_mutex, RPDB_Mutex )

	#define RUBY_RPDB_RECORD( c_record )																							RUBY_RPDB_OBJECT(	c_record, rb_RPDB_Record, NULL, NULL )
	#define C_RPDB_RECORD( rb_record, c_record )																					C_RPDB_STRUCT(		rb_record, c_record, RPDB_Record )

	#define RUBY_RPDB_DATA( c_data )																								RUBY_RPDB_OBJECT(	c_data, rb_RPDB_Data, NULL, NULL )
	#define C_RPDB_DATA( rb_data, c_data )																							C_RPDB_STRUCT(		rb_data, c_data, RPDB_Data )

	#define RUBY_RPDB_KEY( c_key )																									RUBY_RPDB_OBJECT(	c_key, rb_RPDB_Key, NULL, NULL )
	#define C_RPDB_KEY( rb_key, c_key )																							C_RPDB_STRUCT(		rb_key, c_key, RPDB_Key )

	#define RUBY_RPDB_SECONDARY_KEYS( c_secondary_key )																			RUBY_RPDB_OBJECT(	c_secondary_key, rb_RPDB_SecondaryKeys, NULL, NULL )
	#define C_RPDB_SECONDARY_KEYS( rb_secondary_key, c_secondary_key )																C_RPDB_STRUCT(		rb_secondary_key, c_secondary_key, RPDB_SecondaryKeys )

	#define RUBY_RPDB_REPLICATION_CONTROLLER( c_replication_controller )															RUBY_RPDB_OBJECT(	c_replication_controller, rb_RPDB_ReplicationController, NULL, NULL )
	#define C_RPDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller )									C_RPDB_STRUCT(		rb_replication_controller, c_replication_controller, RPDB_ReplicationController )

	#define RUBY_RPDB_REMOTE_SITE( c_remote_site )																					RUBY_RPDB_OBJECT(	c_remote_site, rb_RPDB_RemoteSite, NULL, NULL )
	#define C_RPDB_REMOTE_SITE( rb_remote_site, c_remote_site )																	C_RPDB_STRUCT(		rb_remote_site, c_remote_site, RPDB_RemoteSite )

	#define RUBY_RPDB_TRANSACTION_CONTROLLER( c_transaction_controller )															RUBY_RPDB_OBJECT(	c_transaction_controller, rb_RPDB_TransactionController, NULL, NULL )
	#define C_RPDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller )									C_RPDB_STRUCT(		rb_transaction_controller, c_transaction_controller, RPDB_TransactionController )

	#define RUBY_RPDB_TRANSACTION( c_transaction )																					RUBY_RPDB_OBJECT(	c_transaction, rb_RPDB_Transaction, NULL, NULL )
	#define C_RPDB_TRANSACTION( rb_transaction, c_transaction )																	C_RPDB_STRUCT(		rb_transaction, c_transaction, RPDB_Transaction )

	#define RUBY_RPDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )												RUBY_RPDB_OBJECT(	c_database_settings_controller, rb_RPDB_DatabaseSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )					C_RPDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, RPDB_DatabaseSettingsController )

		/****************************
		*	Settings Controllers	*
		****************************/

	#define RUBY_RPDB_SETTINGS_CONTROLLER( c_settings_controller )																															  RUBY_RPDB_OBJECT(	c_settings_controller, rb_RPDB_SettingsController, NULL, NULL )
	#define C_RPDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller )																									  C_RPDB_STRUCT(		rb_settings_controller, c_settings_controller, RPDB_SettingsController )
                                                                                                                                                            								  
	#define RUBY_RPDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )																										  RUBY_RPDB_OBJECT(	c_database_settings_controller, rb_RPDB_DatabaseSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )																			  C_RPDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, RPDB_DatabaseSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RPDB_OBJECT(	c_database_association_settings_controller, rb_RPDB_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RPDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, RPDB_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RPDB_OBJECT(	c_database_association_settings_controller, rb_RPDB_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RPDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, RPDB_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( c_database_cache_settings_controller )																							  RUBY_RPDB_OBJECT(	c_database_cache_settings_controller, rb_RPDB_DatabaseCacheSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller )														  C_RPDB_STRUCT(		rb_database_cache_settings_controller, c_database_cache_settings_controller, RPDB_DatabaseCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cache_priority_settings_controller )																			  RUBY_RPDB_OBJECT(	c_database_cache_priority_settings_controller, rb_RPDB_DatabaseCachePrioritySettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller )							  C_RPDB_STRUCT(		rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller, RPDB_DatabaseCachePrioritySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller )																						  RUBY_RPDB_OBJECT(	c_database_compact_settings_controller, rb_RPDB_DatabaseCompactSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller )													  C_RPDB_STRUCT(		rb_database_compact_settings_controller, c_database_compact_settings_controller, RPDB_DatabaseCompactSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller )																							  RUBY_RPDB_OBJECT(	c_database_cursor_settings_controller, rb_RPDB_DatabaseCursorSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller )													  C_RPDB_STRUCT(		rb_database_cursor_settings_controller, c_database_cursor_settings_controller, RPDB_DatabaseCursorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( c_database_cursor_record_read_write_settings_controller )																	  RUBY_RPDB_OBJECT(	c_database_cursor_record_read_write_settings_controller, rb_RPDB_DatabaseCursorReadWriteSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller )					  C_RPDB_STRUCT(		rb_database_cursor_record_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller, RPDB_DatabaseCursorReadWriteSettingsController )
                                                                                                                                                                                    		  
	#define RUBY_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( c_database_cursor_cache_settings_controller )																				  RUBY_RPDB_OBJECT(	c_database_cursor_cache_settings_controller, rb_RPDB_DatabaseCursorCacheSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller )									  C_RPDB_STRUCT(		rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller, RPDB_DatabaseCursorCacheSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cursor_cache_priority_settings_controller )															  RUBY_RPDB_OBJECT(	c_database_cursor_cache_priority_settings_controller, rb_RPDB_DatabaseCursorCachePrioritySettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller )		  C_RPDB_STRUCT(		rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller, RPDB_DatabaseCursorCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( c_database_encryption_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_encryption_settings_controller, rb_RPDB_DatabaseEncryptionSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller )										  C_RPDB_STRUCT(		rb_database_encryption_settings_controller, c_database_encryption_settings_controller, RPDB_DatabaseEncryptionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller )																							  RUBY_RPDB_OBJECT(	c_database_error_settings_controller, rb_RPDB_DatabaseErrorSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller )														  C_RPDB_STRUCT(		rb_database_error_settings_controller, c_database_error_settings_controller, RPDB_DatabaseErrorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( c_database_record_fixed_length_settings_controller )																				  RUBY_RPDB_OBJECT(	c_database_record_fixed_length_settings_controller, rb_RPDB_DatabaseRecordFixedLengthSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller )									  C_RPDB_STRUCT(		rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller, RPDB_DatabaseRecordFixedLengthSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller )																								  RUBY_RPDB_OBJECT(	c_database_join_settings_controller, rb_RPDB_DatabaseJoinSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_database_join_settings_controller, c_database_join_settings_controller )															  C_RPDB_STRUCT(		rb_database_join_settings_controller, c_database_join_settings_controller, RPDB_DatabaseJoinSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( c_database_record_read_write_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_record_read_write_settings_controller, rb_RPDB_DatabaseRecordReadWriteSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller )										  C_RPDB_STRUCT(		rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller, RPDB_DatabaseRecordReadWriteSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_database_record_settings_controller )																							  RUBY_RPDB_OBJECT(	c_database_record_settings_controller, rb_RPDB_DatabaseRecordSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller )													  C_RPDB_STRUCT(		rb_database_record_settings_controller, c_database_record_settings_controller, RPDB_DatabaseRecordSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller )																						  RUBY_RPDB_OBJECT(	c_database_sequence_settings_controller, rb_RPDB_DatabaseSequenceSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller )												  C_RPDB_STRUCT(		rb_database_sequence_settings_controller, c_database_sequence_settings_controller, RPDB_DatabaseSequenceSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller )																								  RUBY_RPDB_OBJECT(	c_database_type_settings_controller, rb_RPDB_DatabaseTypeSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller )															  C_RPDB_STRUCT(		rb_database_type_settings_controller, c_database_type_settings_controller, RPDB_DatabaseTypeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( c_database_type_btree_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_type_btree_settings_controller, rb_RPDB_DatabaseTypeBtreeSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller )										  C_RPDB_STRUCT(		rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller, RPDB_DatabaseTypeBtreeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_type_hash_settings_controller, rb_RPDB_DatabaseTypeHashSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller )											  C_RPDB_STRUCT(		rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller, RPDB_DatabaseTypeHashSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( c_database_type_recno_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_type_recno_settings_controller, rb_RPDB_DatabaseTypeRecnoSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller )										  C_RPDB_STRUCT(		rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller, RPDB_DatabaseTypeRecnoSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( c_database_type_queue_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_type_queue_settings_controller, rb_RPDB_DatabaseTypeQueueSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller )										  C_RPDB_STRUCT(		rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller, RPDB_DatabaseTypeQueueSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller )																		  RUBY_RPDB_OBJECT(	c_database_record_variable_length_settings_controller, rb_RPDB_DatabaseRecordVariableLengthSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller )							  C_RPDB_STRUCT(		rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller, RPDB_DatabaseRecordVariableLengthSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller )																					  RUBY_RPDB_OBJECT(	c_database_verbosity_settings_controller, rb_RPDB_DatabaseVerbositySettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller )											  C_RPDB_STRUCT(		rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller, RPDB_DatabaseVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( c_database_verification_settings_controller )																				  RUBY_RPDB_OBJECT(	c_database_verification_settings_controller, rb_RPDB_DatabaseVerificationSettingsController, NULL, NULL )
	#define C_RPDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller )									  C_RPDB_STRUCT(		rb_database_verification_settings_controller, c_database_verification_settings_controller, RPDB_DatabaseVerificationSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DEBUG_SETTINGS_CONTROLLER( c_debug_settings_controller )																												  RUBY_RPDB_OBJECT(	c_debug_settings_controller, rb_RPDB_DebugSettingsController, NULL, NULL )
	#define C_RPDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller )																					  C_RPDB_STRUCT(		rb_debug_settings_controller, c_debug_settings_controller, RPDB_DebugSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( c_debug_verbosity_settings_controller )																							  RUBY_RPDB_OBJECT(	c_debug_verbosity_settings_controller, rb_RPDB_DebugVerbositySettingsController, NULL, NULL )
	#define C_RPDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller )													  C_RPDB_STRUCT(		rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller, RPDB_DebugVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_DIRECTORY_SETTINGS_CONTROLLER( c_directory_settings_controller )																										  RUBY_RPDB_OBJECT(	c_directory_settings_controller, rb_RPDB_DirectorySettingsController, NULL, NULL )
	#define C_RPDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller )																		  C_RPDB_STRUCT(		rb_directory_settings_controller, c_directory_settings_controller, RPDB_DirectorySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( c_environment_cache_settings_controller )																						  RUBY_RPDB_OBJECT(	c_environment_cache_settings_controller, rb_RPDB_EnvironmentCacheSettingsController, NULL, NULL )
	#define C_RPDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller )												  C_RPDB_STRUCT(		rb_environment_cache_settings_controller, c_environment_cache_settings_controller, RPDB_EnvironmentCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller )																												  RUBY_RPDB_OBJECT(	c_error_settings_controller, rb_RPDB_ErrorSettingsController, NULL, NULL )
	#define C_RPDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller )																					  C_RPDB_STRUCT(		rb_error_settings_controller, c_error_settings_controller, RPDB_ErrorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_FILE_SETTINGS_CONTROLLER( c_file_settings_controller )																												  RUBY_RPDB_OBJECT(	c_file_settings_controller, rb_RPDB_FileSettingsController, NULL, NULL )
	#define C_RPDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller )																						  C_RPDB_STRUCT(		rb_file_settings_controller, c_file_settings_controller, RPDB_FileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( c_file_verbosity_settings_controller )																							  RUBY_RPDB_OBJECT(	c_file_verbosity_settings_controller, rb_RPDB_FileVerbositySettingsController, NULL, NULL )
	#define C_RPDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller )														  C_RPDB_STRUCT(		rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller, RPDB_FileVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_LOCK_SETTINGS_CONTROLLER( c_lock_settings_controller )																												  RUBY_RPDB_OBJECT(	c_lock_settings_controller, rb_RPDB_LockSettingsController, NULL, NULL )
	#define C_RPDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller )																						  C_RPDB_STRUCT(		rb_lock_settings_controller, c_lock_settings_controller, RPDB_LockSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( c_lock_deadlock_detector_settings_controller )																			  RUBY_RPDB_OBJECT(	c_lock_deadlock_detector_settings_controller, rb_RPDB_LockDeadlockDetectorSettingsController, NULL, NULL )
	#define C_RPDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller )								  C_RPDB_STRUCT(		rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller, RPDB_LockDeadlockDetectorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( c_lock_deadlock_detector_verbosity_settings_controller )														  RUBY_RPDB_OBJECT(	c_lock_deadlock_detector_verbosity_settings_controller, rb_RPDB_LockDeadlockDetectorVerbositySettingsController, NULL, NULL )
	#define C_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller )	  C_RPDB_STRUCT(		rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller, RPDB_LockDeadlockDetectorVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_LOG_SETTINGS_CONTROLLER( c_log_settings_controller )																													  RUBY_RPDB_OBJECT(	c_log_settings_controller, rb_RPDB_LogSettingsController, NULL, NULL )
	#define C_RPDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller )																						  C_RPDB_STRUCT(		rb_log_settings_controller, c_log_settings_controller, RPDB_LogSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_memory_pool_settings_controller )																									  RUBY_RPDB_OBJECT(	c_memory_pool_settings_controller, rb_RPDB_MemoryPoolSettingsController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller )																  C_RPDB_STRUCT(		rb_memory_pool_settings_controller, c_memory_pool_settings_controller, RPDB_MemoryPoolSettingsController )
                                                                                                                                                                							  
	#define RUBY_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_memory_pool_file_settings_controller )																						  RUBY_RPDB_OBJECT(	c_memory_pool_file_settings_controller, rb_RPDB_MemoryPoolFileSettingsController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller )													  C_RPDB_STRUCT(		rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller, RPDB_MemoryPoolFileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_memory_pool_file_cache_priority_settings_controller )															  RUBY_RPDB_OBJECT(	c_memory_pool_file_cache_priority_settings_controller, rb_RPDB_MemoryPoolFileCachePrioritySettingsController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller )	  C_RPDB_STRUCT(		rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller, RPDB_MemoryPoolFileCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_memory_pool_file_page_settings_controller )																				  RUBY_RPDB_OBJECT(	c_memory_pool_file_page_settings_controller, rb_RPDB_MemoryPoolFilePageSettingsController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller )									  C_RPDB_STRUCT(		rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller, RPDB_MemoryPoolFilePageSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( c_memory_pool_record_read_write_settings_controller )																			  RUBY_RPDB_OBJECT(	c_memory_pool_record_read_write_settings_controller, rb_RPDB_MemoryPoolReadWriteSettingsController, NULL, NULL )
	#define C_RPDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller )								  C_RPDB_STRUCT(		rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller, RPDB_MemoryPoolReadWriteSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_MESSAGE_SETTINGS_CONTROLLER( c_message_settings_controller )																											  RUBY_RPDB_OBJECT(	c_message_settings_controller, rb_RPDB_MessageSettingsController, NULL, NULL )
	#define C_RPDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller )																			  C_RPDB_STRUCT(		rb_message_settings_controller, c_message_settings_controller, RPDB_MessageSettingsController )
                                                                                                                                                											  
	#define RUBY_RPDB_MUTEX_SETTINGS_CONTROLLER( c_mutex_settings_controller )																												  RUBY_RPDB_OBJECT(	c_mutex_settings_controller, rb_RPDB_MutexSettingsController, NULL, NULL )
	#define C_RPDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller )																					  C_RPDB_STRUCT(		rb_mutex_settings_controller, c_mutex_settings_controller, RPDB_MutexSettingsController )
                                                                                                                                                											  
	#define RUBY_RPDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller )																									  RUBY_RPDB_OBJECT(	c_replication_settings_controller, rb_RPDB_ReplicationSettingsController, NULL, NULL )
	#define C_RPDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller )																  C_RPDB_STRUCT(		rb_replication_settings_controller, c_replication_settings_controller, RPDB_ReplicationSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( c_replication_election_settings_controller )																				  RUBY_RPDB_OBJECT(	c_replication_election_settings_controller, rb_RPDB_ReplicationElectionSettingsController, NULL, NULL )
	#define C_RPDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller )										  C_RPDB_STRUCT(		rb_replication_election_settings_controller, c_replication_election_settings_controller, RPDB_ReplicationElectionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( c_replication_timeout_settings_controller )																					  RUBY_RPDB_OBJECT(	c_replication_timeout_settings_controller, rb_RPDB_ReplicationTimeoutSettingsController, NULL, NULL )
	#define C_RPDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller )										  C_RPDB_STRUCT(		rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller, RPDB_ReplicationTimeoutSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( c_replication_verbosity_settings_controller )																				  RUBY_RPDB_OBJECT(	c_replication_verbosity_settings_controller, rb_RPDB_ReplicationVerbositySettingsController, NULL, NULL )
	#define C_RPDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller )									  C_RPDB_STRUCT(		rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller, RPDB_ReplicationVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_THREAD_SETTINGS_CONTROLLER( c_thread_settings_controller )																											  RUBY_RPDB_OBJECT(	c_thread_settings_controller, rb_RPDB_ThreadSettingsController, NULL, NULL )
	#define C_RPDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller )																				  C_RPDB_STRUCT(		rb_thread_settings_controller, c_thread_settings_controller, RPDB_ThreadSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPDB_TRANSACTION_SETTINGS_CONTROLLER( c_transaction_settings_controller )																									  RUBY_RPDB_OBJECT(	c_transaction_settings_controller, rb_RPDB_TransactionSettingsController, NULL, NULL )
	#define C_RPDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller )																  C_RPDB_STRUCT(		rb_transaction_settings_controller, c_transaction_settings_controller, RPDB_TransactionSettingsController )

	/****************************
	*	Wrapping/Get Macros		*
	****************************/

	//	Extract C RPDB struct from Ruby T_DATA
	#define C_RPDB_STRUCT(	rb_object, c_struct, rpdb_type )	Data_Get_Struct(	rb_object,																					\
																																							rpdb_type,																					\
																																							c_struct )

	//	Wrap Ruby RBDB T_DATA from C RPDB struct
	#define RUBY_RPDB_OBJECT(	c_object, rb_rpdb_type, c_mark_function, c_free_function )	Data_Wrap_Struct(	rb_rpdb_type,						\
																																																					c_mark_function,				\
																																																					c_free_function,				\
																																																					c_object )


	/***********************
	*  Convenience Macros  *
	***********************/

	#define RUBY_CLASS( rb_class_constant_name )	rb_const_get(	rb_cObject,																													\
																															rb_intern( rb_class_constant_name ) )

	#define STRING2SYM( rb_string )				\
		ID2SYM( rb_to_id( rb_string ) );

	/**************
	*  Returning  *
	**************/

	#define SIMPLIFIED_RUBY_ARRAY( rb_return )																																\
		( rb_return == Qnil ?																																										\
				Qnil																																																			\
				: ( TYPE( rb_return ) == T_ARRAY ) ?																																	\
						( RARRAY_LEN( rb_return ) == 0 ?																																	\
							Qnil																																																		\
							: ( RARRAY_LEN( rb_return ) == 1 ?																																\
								rb_ary_entry( rb_return, 0 )																																		\
								: rb_return ) )																																								\
						: rb_return )

	#define RETURN_ENUMERATOR_IF_NO_BLOCK( obj, argc, argv ) \
		RETURN_ENUMERATOR( obj, argc, argv );

	/*-----------------------------------------------------------------*/
	
	#define RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record )																						\
		( ( RPDB_Record_rawKey( c_record ) != NULL ) ? rb_str_new(	(char*) RPDB_Record_rawKey( c_record ),						\
																										RPDB_Record_keySize( c_record ) )															\
																									: Qnil )

	#define RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record )																													\
		( ( RPDB_Record_rawData( c_record ) != NULL ) ? rb_str_new(	(char*) RPDB_Record_rawData( c_record ),					\
																										RPDB_Record_dataSize( c_record ) )														\
																									: Qnil )

	#define RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RPDB_RECORD( rb_key, rb_data, c_record )																\
		rb_key	= RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record );																											\
		rb_data	= RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );		

	#define RETURN_RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record )																										\
		VALUE	rb_return_value	=	RUBY_STRING_FOR_KEY_IN_RPDB_RECORD( c_record );																				\
		RPDB_Record_free( & c_record );																																								\
		return rb_return_value;

	#define RETURN_RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record )																									\
		VALUE	rb_return_value	=	RUBY_STRING_FOR_DATA_IN_RPDB_RECORD( c_record );																			\
		RPDB_Record_free( & c_record );																																								\
		return rb_return_value;

	
	/*********************
	*  Argument Parsing  *
	*********************/
		
	//	1: array
	//	1: index_or_key => key_or_data_or_array
	//	1: index_or_key => [ key_or_data, ... ]
	//	2: index_or_key, key_or_data_or_array
	//	2: index, key => data_or_array
	//	3: index, key, data_or_array
	#define PARSE_RUBY_ARGS_FOR_KEY_DATA_OR_KEY_DATA_HASH_OR_KEY_ARRAY_HASH_OR_ARRAY( argc, args, rb_self, function, returns_other_than_self, rb_key, rb_data )		\
		PARSE_RUBY_ARGS_FOR_ARRAY( argc, args, rb_self, function )																																									\
//		else PARSE_RUBY_ARGS_FOR_INDEXORKEY_KEYORDATA_OR_INDEXORKEY_KEYORDATA_HASH_OR_KEY_ARRAY_HASH( argc, args, rb_self, rb_return_array, function )

	//	check if first arg is an array; if it is, process each arg as array or throw error
	#define PARSE_RUBY_ARGS_FOR_ARRAY( argc, args, rb_self, function )											\
		if (		argc																																													\
				&&	TYPE( args[ 0 ] ) == T_ARRAY )	{																															\
			VALUE	rb_return_array	=	rb_ary_new();																																	\
			ITERATE_ARGS_ARRAY_FOR_ARRAYS_AND_CALL_ON_EACH_MEMBER( argc, args, rb_self, rb_return_array, function )				\
		}
	
	//	if we have only keys (1..2):
	//	1: [ any arg ]
	//	1: key_or_array
	//	1: index => key_or_array
	//	1: index => [ key_or_array, ... ]
	//	2: index, key_or_array
	//	2: index, [ key_or_array, ... ]
//	#define PARSE_RUBY_ARGS_FOR_INDEX_KEY( argc, args, rb_self, function, returns_other_than_self )										


	#define ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS_FOR_KEY( rb_index, rb_self, rb_key_array, function, returns_other_than_self )					\
		/*	we need to recursively pass the common prefix from our hash with the array	*/																		\
		VALUE	rb_args_prefix	=	rb_ary_new();																																									\
		ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS( rb_args_prefix, rb_self, rb_key_array, function, returns_other_than_self )

	#define ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS_FOR_INDEX_KEY( rb_index, rb_self, rb_key_array, function, returns_other_than_self )					\
		/*	we need to recursively pass the common prefix from our hash with the array	*/																		\
		VALUE	rb_args_prefix	=	rb_ary_new();																																									\
		rb_ary_push(	rb_args_prefix,																																													\
									rb_index );																																															\
		ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS( rb_args_prefix, rb_self, rb_key_array, function, returns_other_than_self )

	#define ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS_FOR_KEY_DATA( rb_key, rb_self, rb_key_array, function, returns_other_than_self )					\
		/*	we need to recursively pass the common prefix from our hash with the array	*/																		\
		VALUE	rb_args_prefix	=	rb_ary_new();																																									\
		rb_ary_push(	rb_args_prefix,																																													\
									rb_key );																																															\
		ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS( rb_args_prefix, rb_self, rb_key_array, function, returns_other_than_self )

	#define ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS_FOR_INDEX_KEY_DATA( rb_index, rb_key, rb_self, rb_key_array, function, returns_other_than_self )					\
		/*	we need to recursively pass the common prefix from our hash with the array	*/																		\
		VALUE	rb_args_prefix	=	rb_ary_new();																																									\
		rb_ary_push(	rb_args_prefix,																																													\
									rb_index );																																															\
		rb_ary_push(	rb_args_prefix,																																													\
									rb_key );																																																\
		ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS( rb_args_prefix, rb_self, rb_key_array, function, returns_other_than_self )
		



	#define ITERATE_AND_CALL_SELF_ON_ARRAY_MEMBERS_AND_RETURN_RESULTS( rb_args_prefix, rb_self, rb_key_array, function, returns_other_than_self )							\
		VALUE	rb_recursive_return_array	=	rb_ary_new();																																									\
		/*	iterate each member of the array and collate return values	*/																															\
		ITERATE_RUBY_ARRAY_AND_CALL_ON_EACH_MEMBER( rb_self, rb_key_array, rb_recursive_return_array, function )				\
		/*	return collated values if appropriate or otherwise self	*/																																	\
		RETURN_SELF_OR_VALUES( returns_other_than_self, rb_recursive_return_array, rb_self )
		

	

	//	if we have keys and data (1..3):
	//	1: [ any arg ]
	//	1: key => data_or_array
	//	1: key => [ data_or_array, ... ]
	//	2: key, data_or_array
	//	2: index, key => data_or_array
	//	3: index, key, data_or_array
	//	3: index, key, [ data_or_array, ... ]
	#define PARSE_RUBY_ARGS_FOR_INDEX_KEY_DATA( argc, args, rb_self, function )																			\
		int	c_remaining_args	=	argc;																																									\
		rb_scan_args(	argc,																																														\
									args,																																														\
									"12",																																														\
									& rb_key_or_index_or_key_data_hash_or_key_data_array_hash,																			\
									& rb_key_or_data_or_data_array_or_key_data_hash_or_key_data_array_hash,													\
									& rb_data_or_data_array );																																			\
	



	//	1: index_or_key => key_or_data_or_array
	//	1: index_or_key => [ key_or_data_or_array, ... ]
	//	2: index_or_key, key_or_data_or_array
	//	2: index, key => data_or_array
	//	3: index, key, data_or_array
	//	3: index, key, [ data_or_array, ... ]
	#define PARSE_RUBY_ARGS_FOR_INDEXORKEY_KEYORDATA_OR_INDEXORKEY_KEYORDATA_HASH_OR_KEY_ARRAY_HASH( argc, args, rb_self, rb_return_array, function )

	
	//	parses args for rb_key, rb_data, or an array
	//	if an array, each member is processed for key and data
	//		if returns_other_than_self, returns the return values from each call for each array member
	//		otherwise returns self
	#define PARSE_RUBY_ARGS_FOR_KEY_DATA_HASH_OR_ARRAY( argc, args, rb_self, function, returns_other_than_self, rb_key, rb_data )		\
		VALUE	rb_key_or_key_data_hash	=	Qnil;																																					\
		rb_scan_args(	argc,																																														\
									args,																																														\
									"11",																																														\
									& rb_key_or_key_data_hash,																																			\
									& rb_data );																																										\
		PARSE_RUBY_KEY_OR_KEY_DATA_HASH( rb_key_or_key_data_hash, rb_self, function, returns_other_than_self, rb_key, rb_data );			\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_WRITE( rb_key, rb_data );

	#define PARSE_RUBY_ARGS_FOR_KEY_AND_OR_INDEX_OR_HASH_OR_ARRAY( argc, args, rb_self, function, returns_other_than_self, rb_index, rb_key )		\
		VALUE	rb_key_or_index_or_index_key_hash	=	Qnil;																																					\
		VALUE	rb_key_or_index_key_hash	=	Qnil;																																											\
		rb_scan_args(	argc,																																														\
									args,																																														\
									"11",																																														\
									& rb_key_or_index_or_index_key_hash,																													\
									& rb_key_or_index_key_hash );																																										\
		if ( TYPE( rb_key_or_index_or_index_key_hash ) == T_HASH )	{																																	\
			PARSE_RUBY_KEY_OR_KEY_DATA_HASH( rb_key_or_index_or_index_key_hash, rb_self, function, returns_other_than_self, rb_index, rb_key );	\
		}																																																																					\
		else if ( TYPE( rb_key_or_index_key_hash ) == T_HASH )	{																																									\
			PARSE_RUBY_KEY_OR_KEY_DATA_HASH( rb_key_or_index_key_hash, rb_self, function, returns_other_than_self, rb_index, rb_key );							\
		}																																																																					\
		else if ( rb_key_or_index_key_hash != Qnil ) 	{																																														\
			rb_index	=	rb_key_or_index_or_index_key_hash;																																												\
			rb_key		=	rb_key_or_index_key_hash;																																																		\
		}																																																																					\
		else	{																																																																		\
			rb_index	=	Qnil;																																																												\
			rb_key		=	rb_key_or_index_or_index_key_hash;																																																		\
		}																																																																					\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY_RETRIEVE( rb_key );

	/*-----------------------------------------------------------------*/

	#define PARSE_RUBY_KEY_OR_KEY_DATA_HASH( rb_key_or_key_data_hash, rb_self, function, returns_other_than_self, rb_hash_key, rb_hash_data )							\
		if ( TYPE( rb_key_or_key_data_hash ) == T_HASH )	{																																				\
			VALUE	rb_key_data_array	=	Qnil;																																													\
			rb_key_data_array	=	rb_funcall( rb_key_or_key_data_hash,																																\
																			rb_intern( "first" ),																																		\
																			0 );																																										\
			rb_hash_key				=	rb_ary_shift( rb_key_data_array );																																	\
			rb_hash_data			=	rb_ary_shift( rb_key_data_array );																																	\
		}																																																													\
		else if ( TYPE( rb_key_or_key_data_hash ) == T_ARRAY )	{																																	\
			VALUE	rb_return_array	=	rb_ary_new();																																												\
			ITERATE_RUBY_ARRAY_AND_CALL_ON_EACH_MEMBER( rb_self, rb_key_or_key_data_hash, rb_return_array, function )													\
			RETURN_SELF_OR_VALUES( returns_other_than_self, rb_return_array, rb_self );																						\
		}																																																													\
		else {																																																										\
			rb_hash_key				=	rb_key_or_key_data_hash;																																						\
		}

	#define RETURN_SELF_OR_VALUES( returns_other_than_self, rb_return_values, rb_self )																					\
			if ( returns_other_than_self )	{																																												\
				return rb_return_values;																																															\
			}																																																												\
			else	{																																																									\
				return rb_self;																																																				\
			}

	/*******************
	*  Error Checking  *
	*******************/

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																								\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_WRITE( rb_key, rb_data )															\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																											\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );															\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_RETRIEVE( rb_key )																							\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_RETRIEVE( rb_key, rb_data )														\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY( rb_key );																														\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RPDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA );															\
		}

	/**************
	*  Iteration  *
	**************/

	#define ITERATE_RUBY_ARRAY_AND_CALL_ON_EACH_MEMBER( rb_self, rb_array, rb_return_array, function )						\
		int	c_which_array_member	=	0;																														\
		for (	c_which_array_member = 0 ;																													\
					c_which_array_member < RARRAY_LEN( rb_array ) ;																			\
					c_which_array_member++ )	{																													\
			VALUE rb_member = RARRAY_PTR( rb_array )[ c_which_array_member ];												\
			CALL_ON_MEMBER( rb_self, rb_member, rb_return_array, function );																														\
		}

	#define ITERATE_ARGS_ARRAY_AND_CALL_ON_EACH_MEMBER( argc, args, rb_self, rb_return_array, function )						\
		int	c_which_array_member	=	0;																														\
		for (	c_which_array_member = 0 ;																													\
					c_which_array_member < argc ;																												\
					c_which_array_member++ )	{																													\
			VALUE rb_member = args[ c_which_array_member ];																					\
			CALL_ON_MEMBER( rb_self, rb_member, rb_return_array, function );																														\
		}

	#define ITERATE_ARGS_ARRAY_FOR_ARRAYS_AND_CALL_ON_EACH_MEMBER( argc, args, rb_self, rb_return_array, function )						\
		int	c_which_array_member	=	0;																														\
		for (	c_which_array_member = 0 ;																													\
					c_which_array_member < argc ;																												\
					c_which_array_member++ )	{																													\
			VALUE rb_member = args[ c_which_array_member ];																					\
			Check_Type( rb_member, T_ARRAY );																												\
			CALL_ON_MEMBER( rb_self, rb_member, rb_return_array, function )																														\
		}
	
	#define CALL_ON_MEMBER( rb_self, rb_member, rb_return_array, function )											\
				VALUE	rb_result	=	function(	1,																														\
																		& rb_member,																									\
																		rb_self );																								\
				rb_ary_push(	rb_return_array,																												\
											rb_result );
	
	
	/*************
	*  Yielding  *
	*************/

	#define YIELD_BLOCK_FOR_KEY_DATA_INDEX( rb_record_key, rb_record_data, c_index )	\
		switch ( rb_proc_arity( rb_block_lambda() ) )	{																	\
			case 1:																																				\
				rb_yield( rb_record_data );																									\
				break;																																			\
			case 2:																																				\
				rb_yield_values(	2,																												\
													rb_record_key,																						\
													rb_record_data );																					\
				break;																																			\
			case 3:																																				\
				rb_yield_values(	3,																												\
													rb_record_key,																						\
													rb_record_data,																						\
													INT2FIX( c_index ) );																			\
				break;																																			\
		}

	#define YIELD_BLOCK_FOR_DATA_INDEX( rb_record_key, rb_record_data, c_index )			\
		switch ( rb_proc_arity( rb_block_lambda() ) )	{																	\
			case 1:																																				\
				rb_yield( rb_record_data );																									\
				break;																																			\
			case 2:																																				\
				rb_yield_values(	2,																												\
													rb_record_data,																						\
													INT2FIX( c_index ) );																			\
				break;																																			\
		}

	#define PREPARE_RECORD_FROM_KEY_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, rb_index, rb_key )						\
		PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_database, c_database, rb_index );												\
		c_record	=	RPDB_Record_new( c_database );																													\
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_which_database,							\
																																				rb_key,													\
																																				c_record->key->wrapped_bdb_dbt,	\
																																				TRUE );
	
	#define PREPARE_RECORD_FROM_KEY_DATA_FOR_WRITE_RETRIEVE_DELETE( rb_database, c_database, c_record, rb_index, rb_key, rb_data )		\
		PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_database, c_database, rb_index );																										\
		c_record	=	RPDB_Record_new( c_database );																													\
		PACK_KEY_DATA_FOR_STORAGE( rb_database, rb_key, rb_data, c_record );

	#define PACK_KEY_DATA_FOR_STORAGE( rb_database, rb_key, rb_data, c_record )					\
		PACK_KEY_FOR_STORAGE( rb_database, rb_key, c_record );										\
		PACK_DATA_FOR_STORAGE( rb_database, rb_data, c_record );

	#define PACK_KEY_FOR_STORAGE( rb_database, rb_key, c_record )																					\
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_database,										\
																																				rb_key,													\
																																				c_record->key->wrapped_bdb_dbt,	\
																																				TRUE );

	#define PACK_DATA_FOR_STORAGE( rb_which_database, rb_data, c_record )																		\
		rb_RPDB_Database_internal_packRubyObjectOrValueForDatabaseStorage(	rb_which_database,								\
																																				rb_data,													\
																																				c_record->data->wrapped_bdb_dbt,	\
																																				TRUE );
		
	#define PRIMARY_OR_SECONDARY_DATABASE_FOR_INDEX( rb_primary_database, c_database, rb_index )					\
		VALUE	rb_which_database	=	Qnil;																																			\
		if ( rb_index != Qnil )	{																																						\
			rb_which_database	=	rb_RPDB_Database_secondaryDatabaseWithIndex(	rb_primary_database,						\
																																				rb_index );											\
		}																																																		\
		else {																																															\
			rb_which_database	=	rb_primary_database;																													\
		}																																																		\
		C_RPDB_DATABASE( rb_which_database, c_database );


#endif