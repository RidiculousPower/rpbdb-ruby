#ifndef RB_RBDB_CONSTANTS
	#define RB_RBDB_CONSTANTS

	#define RBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH															"@rbdb__extended_classes_hash"
	#define RBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH													"@rbdb__included_for_classes_hash"

	//	Ruby items that exist in a one => many storage relation require runtime storages 
	//	so that garbage collection can function properly; otherwise the item stored in the hash will prevent
	//	collection from even taking place.
	#define	RBDB_RUBY_RUNTIME_STORAGE_ENVIRONMENT_HANDLE																"ruby_environments"
	#define	RBDB_RUBY_RUNTIME_STORAGE_DATABASE_HANDLE																		"ruby_databases"
	#define	RBDB_RUBY_RUNTIME_STORAGE_DATABASE_CURSOR_HANDLE														"ruby_database_cursors"

	//	Module Variables

	#define RBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS																			"@rbdb__environments"
	#define RBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY										"@rbdb__identification_wait_list"
	#define RBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY								"@rbdb__current_working_environment_wait_list"
	#define RBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY										"@rbdb__initialization_wait_list_array"
	#define RBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK									"@current_working_environment_stack"
	#define RBDB_RUBY_MODULE_VARIABLE_ENVIRONMENT_COUNT																	"@rbdb__environment_count"
	#define RBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE													"@rbdb__database_runtime_storage"
	#define RBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS															"@rbdb_secondary_key_callback_methods"

	//	Class Variables
	
	//	Environment
	#define RBDB_RB_ENVIRONMENT_VARIABLE_CONFIGURED_CLASSES															"@rbdb__configured_classes_array"
	
	//	Database Controller
	#define RBDB_RB_DATABASE_CONTROLLER_VARIABLE_DATABASES_HASH													"@rbdb__databases_hash"

	//	Database
	#define RBDB_RB_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE									"@storage_type"
	
	
	
	
	
	
	
	//	Environment
	#define RBDB_RB_ENVIRONMENT_VARIABLE_DATABASE_CONTROLLER														"@database_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_LOCK_CONTROLLER																"@lock_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_LOG_CONTROLLER																	"@log_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_MEMORY_POOL_CONTROLLER													"@memory_pool_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_MUTEX_CONTROLLER																"@mutex_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_REPLICATION_CONTROLLER													"@replication_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_TRANSACTION_CONTROLLER													"@transaction_controller"
	#define RBDB_RB_ENVIRONMENT_VARIABLE_SETTINGS_CONTROLLER														"@settings_controller"

	//	Database Controller

	#define RBDB_RB_DATABASE_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT											"@parent_environment"

	//	Database
	#define RBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER																	"@cursor_controller"
	#define RBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER																		"@join_controller"
	#define RBDB_RB_DATABASE_VARIABLE_SEQUENCE_CONTROLLER																"@sequence_controller"
	#define RBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES																		"@unique_indexes"

	#define RBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER												"@parent_database_controller"

	#define RBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES																"@secondary_databases"

	//	Database Cursor Controller
	#define RBDB_RB_CURSOR_CONTROLLER_VARIABLE_PARENT_DATABASE													"@parent_database"

	//	Database Cursor
	#define RBDB_RB_CURSOR_VARIABLE_PARENT_CURSOR_CONTROLLER														"@parent_cursor_controller"

	//	Database Join Controller
	#define RBDB_RB_JOIN_CONTROLLER_VARIABLE_PARENT_DATABASE														"@parent_database"
	
	//	Database Join Cursor
	#define RBDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER													"@parent_join_controller"
	
	//	Database Sequence Controller
	#define RBDB_RB_DATABASE_SEQUENCE_CONTROLLER_VARIABLE_PARENT_DATABASE												"@parent_database"

	//	Database Sequence
	#define RBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER								"@parent_sequence_controller"
	
	//	Lock Controller
		#define RBDB_RB_LOCK_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT												"@parent_environment"

	//	Lock
	#define RBDB_RB_LOCK_VARIABLE_PARENT_LOCK_CONTROLLER																"@parent_lock_controller"
	
	//	Log Controller
	#define RBDB_RB_LOG_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT													"@parent_environment"
	
	//	Log Cursor
	#define RBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER														"@parent_log_controller"
	
	//	Log
	#define RBDB_RB_LOG_VARIABLE_PARENT_LOG_CURSOR																			"@parent_log_cursor"
	
	//	Log Sequence Number
	#define RBDB_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG															"@parent_log"
	
	//	Memory Pool Controller
	#define RBDB_RB_MEMORY_POOL_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Memory Pool File Controller
	#define RBDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER	"@parent_memory_pool_controller"
	
	//	Memory Pool File
	#define RBDB_RB_MEMORY_POOL_FILE_VARIABLE_PARENT_MEMORY_POOL_FILE_CONTROLLER				"@parent_memory_pool_file_controller"
	
	//	Memory Pool File Page Controller
	#define RBDB_RB_MEMORY_POOL_FILE_PAGE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE		"@parent_memory_pool_file"
	
	//	Memory Pool File Page
	#define RBDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER					"@parent_memory_pool_file_page_controller"
	
	//	Mutex Controller
	#define RBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT												"@parent_environment"
	
	//	Mutex
	#define RBDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER															"@parent_mutex_controller"
	
	//	Record
	#define RBDB_RB_RECORD_VARIABLE_PARENT_DATABASE																			"@parent_database"
	
	//	Key
	#define RBDB_RB_KEY_VARIABLE_PARENT_RECORD																					"@parent_record"
	
	//	Data
	#define RBDB_RB_DATA_VARIABLE_PARENT_RECORD																					"@parent_record"
	
	//	Secondary Keys
	#define RBDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD																"@parent_record"
	
	//	Replication Controller
	#define RBDB_RB_REPLICATION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Remote Site
	#define RBDB_RB_REMOTE_SITE_VARIABLE_PARENT_REPLICATION_CONTROLLER									"@parent_replication_controller"
	
	//	Transaction Controller
	#define RBDB_RB_TRANSACTION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Transaction
	#define RBDB_RB_TRANSACTION_VARIABLE_PARENT_TRANSACTION_CONTROLLER									"@parent_transaction_controller"
	
	//	Settings Controller
	#define RBDB_RB_SETTINGS_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Database Settings Controller
	#define RBDB_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	#define RBDB_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE															"@parent_database"
	
	//	Database Association Settings Controller
	#define RBDB_RB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Cache Settings Controller
	#define RBDB_RB_DATABASE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Cache Priority Settings Controller
	#define RBDB_RB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_cache_settings_controller"
	
	//	Database Cursor Settings Controller
	#define RBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	#define RBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR																"@parent_database_cursor"
	
	//	Database Cursor Read Write Settings Controller
	#define RBDB_RB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER									"@parent_database_cursor_settings_controller"
	
	//	Database Cursor Cache Settings Controller
	#define RBDB_RB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER									"@parent_database_cursor_settings_controller"
	
	//	Database Cursor Cache Priority Settings Controller
	#define RBDB_RB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER									"@parent_database_cursor_cache_settings_controller"
	
	//	Database Compact Settings Controller
	#define RBDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Encryption Settings Controller
	#define RBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Error Settings Controller
	#define RBDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Join Settings Controller
	#define RBDB_RB_DATABASE_JOIN_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Record Settings Controller
	#define RBDB_RB_DATABASE_RECORD_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Record Fixed Length Settings Controller
	#define RBDB_RB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Record Variable Length Settings Controller
	#define RBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Record Read Write Settings Controller
	#define RBDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Sequence Settings Controller
	#define RBDB_RB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Type Settings Controller
	#define RBDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Btree Type Settings Controller
	#define RBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER											"@parent_database_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"
	
	//	Database Hash Type Settings Controller
	#define RBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER												"@parent_database_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																						"@parent_database"

	//	Database Recno Type Settings Controller
	#define RBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER												"@parent_database_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"

	//	Database Queue Type Settings Controller
	#define RBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER											"@parent_database_settings_controller"
	#define RBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"

	//	Database Verbosity Settings Controller
	#define RBDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Verification Settings Controller
	#define RBDB_RB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Debug Settings Controller
	#define RBDB_RB_DEBUG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Debug Verbosity Settings Controller
	#define RBDB_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER									"@parent_debug_settings_controller"
	
	//	Directory Settings Controller
	#define RBDB_RB_DIRECTORY_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Environmental Cache Settings Controller
	#define RBDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Error Settings Controller
	#define RBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	File Settings Controller
	#define RBDB_RB_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	File Verbosity Settings Controller
	#define RBDB_RB_FILE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_FILE_SETTINGS_CONTROLLER									"@parent_file_settings_controller"
	
	//	Lock Settings Controller
	#define RBDB_RB_LOCK_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Lock Deadlock Detector Settings Controller
	#define RBDB_RB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_SETTINGS_CONTROLLER									"@parent_lock_settings_controller"
	
	//	Lock Deadlock Detector Verbosity Settings Controller
	#define RBDB_RB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER									"@parent_lock_deadlock_detector_settings_controller"
	
	//	Log Settings Controller
	#define RBDB_RB_LOG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER																						"@parent_settings_controller"
	
	//	Memory Pool Settings Controller
	#define RBDB_RB_MEMORY_POOL_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Memory Pool Read Write Settings Controller
	#define RBDB_RB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER									"@parent_memory_pool_settings_controller"

	//	Memory Pool File Settings Controller
	#define RBDB_RB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER									"@parent_memory_pool_settings_controller"

	//	Memory Pool File Page Settings Controller
	#define RBDB_RB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_settings_controller"

	//	Memory Pool File Cache Settings Controller
	#define RBDB_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_settings_controller"

	//	Memory Pool File Cache Priority Settings Controller
	#define RBDB_RB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_cache_settings_controller"

	//	Message Settings Controller
	#define RBDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Mutex Settings Controller
	#define RBDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Replication Settings Controller
	#define RBDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Replication Election Settings Controller
	#define RBDB_RB_REPLICATION_ELECTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Replication Timeout Settings Controller
	#define RBDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Replication Verbosity Settings Controller
	#define RBDB_RB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Thread Settings Controller
	#define RBDB_RB_THREAD_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Transaction Settings Controller
	#define RBDB_RB_TRANSACTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"






	
	#define RBDB_RB_DATABASE_SEQUENCE_CONTROLLER																	"@database_sequence_controller"


	#define RBDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT																"@parent_environment"
	#define RBDB_RB_ALL_VARIABLE_PARENT_DATABASE																	"@parent_database"
	#define RBDB_RB_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER								"@parent_database_cursor_controller"

	#define RBDB_RB_SETTINGS_VARIABLE_SETTINGS_CONTROLLER													"@settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER										"@file_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_FILE_VERBOSITY_SETTINGS_CONTROLLER					"@file_verbosity_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER										"@error_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER											"@log_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_LOG_CURSOR_SETTINGS_CONTROLLER							"@log_cursor_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER										"@lock_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER										"@lock_deadlock_detector_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER										"@lock_deadlock_detector_verbosity_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER										"@mutex_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER							"@replication_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_REPLICATION_ELECTION_SETTINGS_CONTROLLER							"@replication_election_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER							"@replication_timeout_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER							"@replication_verbosity_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER							"@memory_pool_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER							"@memory_pool_read_write_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER				"@memory_pool_file_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER		"@memory_pool_file_page_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER		"@memory_pool_file_cache_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER		"@memory_pool_file_cache_priority_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER								"@database_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER		"@database_association_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER					"@database_cache_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER					"@database_cache_priority_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER					"@database_cursor_cache_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER					"@database_cursor_cache_priority_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER					"@database_cursor_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER					"@database_cursor_read_write_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_ERROR_SETTINGS_CONTROLLER					"@database_error_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_SETTINGS_CONTROLLER								"@database_record_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER								"@database_record_fixed_length_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER								"@database_record_variable_length_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER								"@database_record_read_write_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER								"@database_read_write_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_SETTINGS_CONTROLLER								"@database_type_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER								"@database_type_btree_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER								"@database_type_hash_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER								"@database_type_queue_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER								"@database_type_recno_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER								"@directory_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER				"@database_sequence_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER						"@database_join_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER									"@database_record_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DEBUG_SETTINGS_CONTROLLER									"@database_debug_settings_controller"
	#define RBDB_RB_SETTINGS_VARIABLE_DEBUG_VERBOSITY_SETTINGS_CONTROLLER									"@database_debug_verbosity_settings_controller"
	
	#define RBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA		"@serialize_data"

	#define RBDB_FUNCTION_INIT																										"init_rbdb"
	#define RBDB_FUNCTION_CONFIGURE																						"configure_rbdb"
	#define RBDB_FUNCTION_IDENTIFY_AS																					"identify_for_rbdb_as"

	#define	RBDB_RUBY_CONSTANT_DEFAULT																				"Default"

	#define RBDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED			"Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."
	#define RBDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND											"Requested Environment was missing."
	#define RBDB_RUBY_ERROR_MESSAGE_DATABASE_CONTROLLER_NOT_FOUND							"Requested Environment was missing."
	#define RBDB_RUBY_ERROR_ENVIRONMENT_WITH_NAME_ALREADY_EXISTS							"Environment with requested name already exists."

	#define RBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY													"Cannot write to database without key."
	#define RBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA													"Cannot write to database without data."
	#define RBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY												"Cannot retrieve to database without key."
	#define RBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA											"Cannot retrieve to database without data."

	#define RBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK						"Secondary key creation callback method/proc has unexpected arity. Expected 1, 2, 3 or -1."

	/****************************
	*	Get Ruby from C Macros	*
	****************************/

	#define RUBY_RBDB_ENVIRONMENT( c_environment )																																RUBY_RBDB_OBJECT(	c_environment, rb_Rbdb_Environment, NULL, NULL )
	#define RUBY_RBDB_ENVIRONMENT_WITH_FREE( c_environment )																											RUBY_RBDB_OBJECT(	c_environment, rb_Rbdb_Environment, NULL, rb_Rbdb_Environment_free )
	#define C_RBDB_ENVIRONMENT( rb_environment, c_environment )																										C_RBDB_STRUCT(		rb_environment, c_environment, Rbdb_Environment )
                                                                                                    								
	#define RUBY_RBDB_DATABASE_CONTROLLER( c_database_controller )																								RUBY_RBDB_OBJECT(	c_database_controller, rb_Rbdb_DatabaseController, NULL, NULL )
	#define C_RBDB_DATABASE_CONTROLLER( rb_database_controller, c_database_controller )														C_RBDB_STRUCT(		rb_database_controller, c_database_controller, Rbdb_DatabaseController )
                                                                                                    								
	#define RUBY_RBDB_DATABASE( c_database )																									RUBY_RBDB_OBJECT(	c_database, rb_Rbdb_Database, NULL, NULL )
	#define C_RBDB_DATABASE( rb_database, c_database )																				C_RBDB_STRUCT(		rb_database, c_database, Rbdb_Database )

	#define RUBY_RBDB_BTREE_DATABASE( c_btree_database )																									RUBY_RBDB_OBJECT(	c_btree_database, rb_Rbdb_BtreeDatabase, NULL, NULL )
	#define RUBY_RBDB_HASH_DATABASE( c_hash_database )																										RUBY_RBDB_OBJECT(	c_hash_database, rb_Rbdb_HashDatabase, NULL, NULL )
	#define RUBY_RBDB_QUEUE_DATABASE( c_queue_database )																									RUBY_RBDB_OBJECT(	c_queue_database, rb_Rbdb_QueueDatabase, NULL, NULL )
	#define RUBY_RBDB_RECNO_DATABASE( c_recno_database )																									RUBY_RBDB_OBJECT(	c_recno_database, rb_Rbdb_RecnoDatabase, NULL, NULL )

	#define RUBY_RBDB_DATABASE_OBJECT_DATABASE( c_database )																		RUBY_RBDB_OBJECT(	c_database, rb_Rbdb_DatabaseObjectDatabase, NULL, NULL )
	#define C_RBDB_DATABASE_OBJECT_DATABASE( rb_database, c_database )																C_RBDB_STRUCT(		rb_database, c_database, Rbdb_Database )

	#define RUBY_RBDB_DATABASE_CURSOR_CONTROLLER( c_cursor_controller )															RUBY_RBDB_OBJECT(	c_cursor_controller, rb_Rbdb_DatabaseCursorController, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR_CONTROLLER( rb_cursor_controller, c_cursor_controller )											C_RBDB_STRUCT(		rb_cursor_controller, c_cursor_controller, Rbdb_DatabaseCursorController )
                                                                            														
	#define RUBY_RBDB_DATABASE_CURSOR( c_cursor )																					RUBY_RBDB_OBJECT(	c_cursor, rb_Rbdb_DatabaseCursor, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR( rb_cursor, c_cursor )																			C_RBDB_STRUCT(		rb_cursor, c_cursor, Rbdb_DatabaseCursor )
                                                                            														
	#define RUBY_RBDB_DATABASE_OBJECT_CURSOR( c_cursor )																			RUBY_RBDB_OBJECT(	c_cursor, rb_Rbdb_DatabaseObjectCursor, NULL, NULL )
	#define C_RBDB_DATABASE_OBJECT_CURSOR( rb_cursor, c_cursor )																	C_RBDB_STRUCT(		rb_cursor, c_cursor, Rbdb_DatabaseCursor )
                                                                                                    								
	#define RUBY_RBDB_DATABASE_JOIN_CONTROLLER( c_join_controller )																RUBY_RBDB_OBJECT(	c_join_controller, rb_Rbdb_DatabaseJoinController, NULL, NULL )
	#define C_RBDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller )												C_RBDB_STRUCT(		rb_join_controller, c_join_controller, Rbdb_DatabaseJoinController )
                                                                            														
	#define RUBY_RBDB_DATABASE_JOIN_CURSOR( c_join_cursor )																		RUBY_RBDB_OBJECT(	c_join_cursor, rb_Rbdb_DatabaseJoinCursor, NULL, NULL )
	#define C_RBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor )															C_RBDB_STRUCT(		rb_join_cursor, c_join_cursor, Rbdb_DatabaseJoinCursor )
                                                                                                                            		
	#define RUBY_RBDB_DATABASE_SEQUENCE_CONTROLLER( c_database_sequence_controller )												RUBY_RBDB_OBJECT(	c_database_sequence_controller, rb_Rbdb_DatabaseSequenceController, NULL, NULL )
	#define C_RBDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller )					C_RBDB_STRUCT(		rb_database_sequence_controller, c_database_sequence_controller, Rbdb_DatabaseSequenceController )
                                                                                                                            		
	#define RUBY_RBDB_DATABASE_SEQUENCE( c_database_sequence )																		RUBY_RBDB_OBJECT(	c_database_sequence, rb_Rbdb_DatabaseSequence, NULL, NULL )
	#define C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence )													C_RBDB_STRUCT(		rb_database_sequence, c_database_sequence, Rbdb_DatabaseSequence )

	#define RUBY_RBDB_ERROR_CONTROLLER( c_error_controller )																		RUBY_RBDB_OBJECT(	c_error_controller, rb_Rbdb_ErrorController, NULL, NULL )
	#define C_RBDB_ERROR_CONTROLLER( rb_error_controller, c_error_controller )														C_RBDB_STRUCT(		rb_error_controller, c_error_controller, Rbdb_ErrorController )

	#define RUBY_RBDB_ERROR( c_error )																								RUBY_RBDB_OBJECT(	c_error, rb_Rbdb_Error, NULL, NULL )
	#define C_RBDB_ERROR( rb_error, c_error )																						C_RBDB_STRUCT(		rb_error, c_error, Rbdb_Error )

	#define RUBY_RBDB_LOCK_CONTROLLER( c_lock_controller )																			RUBY_RBDB_OBJECT(	c_lock_controller, rb_Rbdb_LockController, NULL, NULL )
	#define C_RBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller )														C_RBDB_STRUCT(		rb_lock_controller, c_lock_controller, Rbdb_LockController )

	#define RUBY_RBDB_LOCK( c_lock )																								RUBY_RBDB_OBJECT(	c_lock, rb_Rbdb_Lock, NULL, NULL )
	#define C_RBDB_LOCK( rb_lock, c_lock )																							C_RBDB_STRUCT(		rb_lock, c_lock, Rbdb_Lock )

	#define RUBY_RBDB_LOG_CONTROLLER( c_log_controller )																			RUBY_RBDB_OBJECT(	c_log_controller, rb_Rbdb_LogController, NULL, NULL )
	#define C_RBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller )															C_RBDB_STRUCT(		rb_log_controller, c_log_controller, Rbdb_LogController )

	#define RUBY_RBDB_LOG( c_log )																									RUBY_RBDB_OBJECT(	c_log, rb_Rbdb_Log, NULL, NULL )
	#define C_RBDB_LOG( rb_log, c_log )																							C_RBDB_STRUCT(		rb_log, c_log, Rbdb_Log )

	#define RUBY_RBDB_LOG_CURSOR_CONTROLLER( c_log_cursor_controller )																RUBY_RBDB_OBJECT(	c_log_cursor_controller, rb_Rbdb_LogCursorController, NULL, NULL )
	#define C_RBDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller )										C_RBDB_STRUCT(		rb_log_cursor_controller, c_log_cursor_controller, Rbdb_LogCursorController )

	#define RUBY_RBDB_LOG_CURSOR( c_log_cursor )																					RUBY_RBDB_OBJECT(	c_log_cursor, rb_Rbdb_LogCursor, NULL, NULL )
	#define C_RBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor )																		C_RBDB_STRUCT(		rb_log_cursor, c_log_cursor, Rbdb_LogCursor )

	#define RUBY_RBDB_LOG_SEQUENCE_NUMBER( c_log_sequence_number )																	RUBY_RBDB_OBJECT(	c_log_sequence_number, rb_Rbdb_LogSequenceNumber, NULL, NULL )
	#define C_RBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number )											C_RBDB_STRUCT(		rb_log_sequence_number, c_log_sequence_number, Rbdb_LogSequenceNumber )

	#define RUBY_RBDB_MEMORY_POOL_CONTROLLER( c_memory_pool_controller )															RUBY_RBDB_OBJECT(	c_memory_pool_controller, rb_Rbdb_MemoryPoolController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller )									C_RBDB_STRUCT(		rb_memory_pool_controller, c_memory_pool_controller, Rbdb_MemoryPoolController )

	#define RUBY_RBDB_MEMORY_POOL_FILE_CONTROLLER( c_memory_pool_file_controller )													RUBY_RBDB_OBJECT(	c_memory_pool_file_controller, rb_Rbdb_MemoryPoolFileController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller )					C_RBDB_STRUCT(		rb_memory_pool_file_controller, c_memory_pool_file_controller, Rbdb_MemoryPoolFileController )

	#define RUBY_RBDB_MEMORY_POOL_FILE( c_memory_pool_file )																		RUBY_RBDB_OBJECT(	c_memory_pool_file, rb_Rbdb_MemoryPoolFile, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file )														C_RBDB_STRUCT(		rb_memory_pool_file, c_memory_pool_file, Rbdb_MemoryPoolFile )

	#define RUBY_RBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( c_memory_pool_file_page_controller )										RUBY_RBDB_OBJECT(	c_memory_pool_file_page_controller, rb_Rbdb_MemoryPoolFilePageController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller )		C_RBDB_STRUCT(		rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller, Rbdb_MemoryPoolFilePageController )

	#define RUBY_RBDB_MEMORY_POOL_FILE_PAGE( c_memory_pool_file_page )																RUBY_RBDB_OBJECT(	c_memory_pool_file_page, rb_Rbdb_MemoryPoolFilePage, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page )										C_RBDB_STRUCT(		rb_memory_pool_file_page, c_memory_pool_file_page, Rbdb_MemoryPoolFilePage )

	#define RUBY_RBDB_MUTEX_CONTROLLER( c_mutex_controller )																		RUBY_RBDB_OBJECT(	c_mutex_controller, rb_Rbdb_MutexController, NULL, NULL )
	#define C_RBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller )														C_RBDB_STRUCT(		rb_mutex_controller, c_mutex_controller, Rbdb_MutexController )

	#define RUBY_RBDB_MUTEX( c_mutex )																								RUBY_RBDB_OBJECT(	c_mutex, rb_Rbdb_Mutex, NULL, NULL )
	#define C_RBDB_MUTEX( rb_mutex, c_mutex )																						C_RBDB_STRUCT(		rb_mutex, c_mutex, Rbdb_Mutex )

	#define RUBY_RBDB_RECORD( c_record )																							RUBY_RBDB_OBJECT(	c_record, rb_Rbdb_Record, NULL, NULL )
	#define C_RBDB_RECORD( rb_record, c_record )																					C_RBDB_STRUCT(		rb_record, c_record, Rbdb_Record )

	#define RUBY_RBDB_DATA( c_data )																								RUBY_RBDB_OBJECT(	c_data, rb_Rbdb_Data, NULL, NULL )
	#define C_RBDB_DATA( rb_data, c_data )																							C_RBDB_STRUCT(		rb_data, c_data, Rbdb_Data )

	#define RUBY_RBDB_KEY( c_key )																									RUBY_RBDB_OBJECT(	c_key, rb_Rbdb_Key, NULL, NULL )
	#define C_RBDB_KEY( rb_key, c_key )																							C_RBDB_STRUCT(		rb_key, c_key, Rbdb_Key )

	#define RUBY_RBDB_SECONDARY_KEYS( c_secondary_key )																			RUBY_RBDB_OBJECT(	c_secondary_key, rb_Rbdb_SecondaryKeys, NULL, NULL )
	#define C_RBDB_SECONDARY_KEYS( rb_secondary_key, c_secondary_key )																C_RBDB_STRUCT(		rb_secondary_key, c_secondary_key, Rbdb_SecondaryKeys )

	#define RUBY_RBDB_REPLICATION_CONTROLLER( c_replication_controller )															RUBY_RBDB_OBJECT(	c_replication_controller, rb_Rbdb_ReplicationController, NULL, NULL )
	#define C_RBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller )									C_RBDB_STRUCT(		rb_replication_controller, c_replication_controller, Rbdb_ReplicationController )

	#define RUBY_RBDB_REMOTE_SITE( c_remote_site )																					RUBY_RBDB_OBJECT(	c_remote_site, rb_Rbdb_RemoteSite, NULL, NULL )
	#define C_RBDB_REMOTE_SITE( rb_remote_site, c_remote_site )																	C_RBDB_STRUCT(		rb_remote_site, c_remote_site, Rbdb_RemoteSite )

	#define RUBY_RBDB_TRANSACTION_CONTROLLER( c_transaction_controller )															RUBY_RBDB_OBJECT(	c_transaction_controller, rb_Rbdb_TransactionController, NULL, NULL )
	#define C_RBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller )									C_RBDB_STRUCT(		rb_transaction_controller, c_transaction_controller, Rbdb_TransactionController )

	#define RUBY_RBDB_TRANSACTION( c_transaction )																					RUBY_RBDB_OBJECT(	c_transaction, rb_Rbdb_Transaction, NULL, NULL )
	#define C_RBDB_TRANSACTION( rb_transaction, c_transaction )																	C_RBDB_STRUCT(		rb_transaction, c_transaction, Rbdb_Transaction )

	#define RUBY_RBDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )												RUBY_RBDB_OBJECT(	c_database_settings_controller, rb_Rbdb_DatabaseSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )					C_RBDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, Rbdb_DatabaseSettingsController )

		/****************************
		*	Settings Controllers	*
		****************************/

	#define RUBY_RBDB_SETTINGS_CONTROLLER( c_settings_controller )																															  RUBY_RBDB_OBJECT(	c_settings_controller, rb_Rbdb_SettingsController, NULL, NULL )
	#define C_RBDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller )																									  C_RBDB_STRUCT(		rb_settings_controller, c_settings_controller, Rbdb_SettingsController )
                                                                                                                                                            								  
	#define RUBY_RBDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )																										  RUBY_RBDB_OBJECT(	c_database_settings_controller, rb_Rbdb_DatabaseSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )																			  C_RBDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, Rbdb_DatabaseSettingsController )
                                                                                                                                                            								  
	#define RUBY_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RBDB_OBJECT(	c_database_association_settings_controller, rb_Rbdb_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RBDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, Rbdb_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RBDB_OBJECT(	c_database_association_settings_controller, rb_Rbdb_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RBDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, Rbdb_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( c_database_cache_settings_controller )																							  RUBY_RBDB_OBJECT(	c_database_cache_settings_controller, rb_Rbdb_DatabaseCacheSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller )														  C_RBDB_STRUCT(		rb_database_cache_settings_controller, c_database_cache_settings_controller, Rbdb_DatabaseCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cache_priority_settings_controller )																			  RUBY_RBDB_OBJECT(	c_database_cache_priority_settings_controller, rb_Rbdb_DatabaseCachePrioritySettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller )							  C_RBDB_STRUCT(		rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller, Rbdb_DatabaseCachePrioritySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller )																						  RUBY_RBDB_OBJECT(	c_database_compact_settings_controller, rb_Rbdb_DatabaseCompactSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller )													  C_RBDB_STRUCT(		rb_database_compact_settings_controller, c_database_compact_settings_controller, Rbdb_DatabaseCompactSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller )																							  RUBY_RBDB_OBJECT(	c_database_cursor_settings_controller, rb_Rbdb_DatabaseCursorSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller )													  C_RBDB_STRUCT(		rb_database_cursor_settings_controller, c_database_cursor_settings_controller, Rbdb_DatabaseCursorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( c_database_cursor_record_read_write_settings_controller )																	  RUBY_RBDB_OBJECT(	c_database_cursor_record_read_write_settings_controller, rb_Rbdb_DatabaseCursorReadWriteSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller )					  C_RBDB_STRUCT(		rb_database_cursor_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller, Rbdb_DatabaseCursorReadWriteSettingsController )
                                                                                                                                                                                    		  
	#define RUBY_RBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( c_database_cursor_cache_settings_controller )																				  RUBY_RBDB_OBJECT(	c_database_cursor_cache_settings_controller, rb_Rbdb_DatabaseCursorCacheSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller )									  C_RBDB_STRUCT(		rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller, Rbdb_DatabaseCursorCacheSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cursor_cache_priority_settings_controller )															  RUBY_RBDB_OBJECT(	c_database_cursor_cache_priority_settings_controller, rb_Rbdb_DatabaseCursorCachePrioritySettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller )		  C_RBDB_STRUCT(		rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller, Rbdb_DatabaseCursorCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( c_database_encryption_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_encryption_settings_controller, rb_Rbdb_DatabaseEncryptionSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller )										  C_RBDB_STRUCT(		rb_database_encryption_settings_controller, c_database_encryption_settings_controller, Rbdb_DatabaseEncryptionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller )																							  RUBY_RBDB_OBJECT(	c_database_error_settings_controller, rb_Rbdb_DatabaseErrorSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller )														  C_RBDB_STRUCT(		rb_database_error_settings_controller, c_database_error_settings_controller, Rbdb_DatabaseErrorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( c_database_record_fixed_length_settings_controller )																				  RUBY_RBDB_OBJECT(	c_database_record_fixed_length_settings_controller, rb_Rbdb_DatabaseRecordFixedLengthSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller )									  C_RBDB_STRUCT(		rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller, Rbdb_DatabaseRecordFixedLengthSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller )																								  RUBY_RBDB_OBJECT(	c_database_join_settings_controller, rb_Rbdb_DatabaseJoinSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_database_join_settings_controller, c_database_join_settings_controller )															  C_RBDB_STRUCT(		rb_database_join_settings_controller, c_database_join_settings_controller, Rbdb_DatabaseJoinSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( c_database_record_read_write_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_record_read_write_settings_controller, rb_Rbdb_DatabaseRecordReadWriteSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller )										  C_RBDB_STRUCT(		rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller, Rbdb_DatabaseRecordReadWriteSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_database_record_settings_controller )																							  RUBY_RBDB_OBJECT(	c_database_record_settings_controller, rb_Rbdb_DatabaseRecordSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller )													  C_RBDB_STRUCT(		rb_database_record_settings_controller, c_database_record_settings_controller, Rbdb_DatabaseRecordSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller )																						  RUBY_RBDB_OBJECT(	c_database_sequence_settings_controller, rb_Rbdb_DatabaseSequenceSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller )												  C_RBDB_STRUCT(		rb_database_sequence_settings_controller, c_database_sequence_settings_controller, Rbdb_DatabaseSequenceSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller )																								  RUBY_RBDB_OBJECT(	c_database_type_settings_controller, rb_Rbdb_DatabaseTypeSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller )															  C_RBDB_STRUCT(		rb_database_type_settings_controller, c_database_type_settings_controller, Rbdb_DatabaseTypeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( c_database_type_btree_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_type_btree_settings_controller, rb_Rbdb_DatabaseTypeBtreeSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller )										  C_RBDB_STRUCT(		rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller, Rbdb_DatabaseTypeBtreeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_type_hash_settings_controller, rb_Rbdb_DatabaseTypeHashSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller )											  C_RBDB_STRUCT(		rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller, Rbdb_DatabaseTypeHashSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( c_database_type_recno_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_type_recno_settings_controller, rb_Rbdb_DatabaseTypeRecnoSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller )										  C_RBDB_STRUCT(		rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller, Rbdb_DatabaseTypeRecnoSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( c_database_type_queue_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_type_queue_settings_controller, rb_Rbdb_DatabaseTypeQueueSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller )										  C_RBDB_STRUCT(		rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller, Rbdb_DatabaseTypeQueueSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller )																		  RUBY_RBDB_OBJECT(	c_database_record_variable_length_settings_controller, rb_Rbdb_DatabaseRecordVariableLengthSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller )							  C_RBDB_STRUCT(		rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller, Rbdb_DatabaseRecordVariableLengthSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller )																					  RUBY_RBDB_OBJECT(	c_database_verbosity_settings_controller, rb_Rbdb_DatabaseVerbositySettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller )											  C_RBDB_STRUCT(		rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller, Rbdb_DatabaseVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( c_database_verification_settings_controller )																				  RUBY_RBDB_OBJECT(	c_database_verification_settings_controller, rb_Rbdb_DatabaseVerificationSettingsController, NULL, NULL )
	#define C_RBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller )									  C_RBDB_STRUCT(		rb_database_verification_settings_controller, c_database_verification_settings_controller, Rbdb_DatabaseVerificationSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DEBUG_SETTINGS_CONTROLLER( c_debug_settings_controller )																												  RUBY_RBDB_OBJECT(	c_debug_settings_controller, rb_Rbdb_DebugSettingsController, NULL, NULL )
	#define C_RBDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller )																					  C_RBDB_STRUCT(		rb_debug_settings_controller, c_debug_settings_controller, Rbdb_DebugSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( c_debug_verbosity_settings_controller )																							  RUBY_RBDB_OBJECT(	c_debug_verbosity_settings_controller, rb_Rbdb_DebugVerbositySettingsController, NULL, NULL )
	#define C_RBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller )													  C_RBDB_STRUCT(		rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller, Rbdb_DebugVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_DIRECTORY_SETTINGS_CONTROLLER( c_directory_settings_controller )																										  RUBY_RBDB_OBJECT(	c_directory_settings_controller, rb_Rbdb_DirectorySettingsController, NULL, NULL )
	#define C_RBDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller )																		  C_RBDB_STRUCT(		rb_directory_settings_controller, c_directory_settings_controller, Rbdb_DirectorySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( c_environment_cache_settings_controller )																						  RUBY_RBDB_OBJECT(	c_environment_cache_settings_controller, rb_Rbdb_EnvironmentCacheSettingsController, NULL, NULL )
	#define C_RBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller )												  C_RBDB_STRUCT(		rb_environment_cache_settings_controller, c_environment_cache_settings_controller, Rbdb_EnvironmentCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller )																												  RUBY_RBDB_OBJECT(	c_error_settings_controller, rb_Rbdb_ErrorSettingsController, NULL, NULL )
	#define C_RBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller )																					  C_RBDB_STRUCT(		rb_error_settings_controller, c_error_settings_controller, Rbdb_ErrorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_FILE_SETTINGS_CONTROLLER( c_file_settings_controller )																												  RUBY_RBDB_OBJECT(	c_file_settings_controller, rb_Rbdb_FileSettingsController, NULL, NULL )
	#define C_RBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller )																						  C_RBDB_STRUCT(		rb_file_settings_controller, c_file_settings_controller, Rbdb_FileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( c_file_verbosity_settings_controller )																							  RUBY_RBDB_OBJECT(	c_file_verbosity_settings_controller, rb_Rbdb_FileVerbositySettingsController, NULL, NULL )
	#define C_RBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller )														  C_RBDB_STRUCT(		rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller, Rbdb_FileVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_LOCK_SETTINGS_CONTROLLER( c_lock_settings_controller )																												  RUBY_RBDB_OBJECT(	c_lock_settings_controller, rb_Rbdb_LockSettingsController, NULL, NULL )
	#define C_RBDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller )																						  C_RBDB_STRUCT(		rb_lock_settings_controller, c_lock_settings_controller, Rbdb_LockSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( c_lock_deadlock_detector_settings_controller )																			  RUBY_RBDB_OBJECT(	c_lock_deadlock_detector_settings_controller, rb_Rbdb_LockDeadlockDetectorSettingsController, NULL, NULL )
	#define C_RBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller )								  C_RBDB_STRUCT(		rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller, Rbdb_LockDeadlockDetectorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( c_lock_deadlock_detector_verbosity_settings_controller )														  RUBY_RBDB_OBJECT(	c_lock_deadlock_detector_verbosity_settings_controller, rb_Rbdb_LockDeadlockDetectorVerbositySettingsController, NULL, NULL )
	#define C_RBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller )	  C_RBDB_STRUCT(		rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller, Rbdb_LockDeadlockDetectorVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_LOG_SETTINGS_CONTROLLER( c_log_settings_controller )																													  RUBY_RBDB_OBJECT(	c_log_settings_controller, rb_Rbdb_LogSettingsController, NULL, NULL )
	#define C_RBDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller )																						  C_RBDB_STRUCT(		rb_log_settings_controller, c_log_settings_controller, Rbdb_LogSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_memory_pool_settings_controller )																									  RUBY_RBDB_OBJECT(	c_memory_pool_settings_controller, rb_Rbdb_MemoryPoolSettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller )																  C_RBDB_STRUCT(		rb_memory_pool_settings_controller, c_memory_pool_settings_controller, Rbdb_MemoryPoolSettingsController )
                                                                                                                                                                							  
	#define RUBY_RBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_memory_pool_file_settings_controller )																						  RUBY_RBDB_OBJECT(	c_memory_pool_file_settings_controller, rb_Rbdb_MemoryPoolFileSettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller )													  C_RBDB_STRUCT(		rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller, Rbdb_MemoryPoolFileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( c_memory_pool_file_cache_settings_controller )															  RUBY_RBDB_OBJECT(	c_memory_pool_file_cache_settings_controller, rb_Rbdb_MemoryPoolFileCacheSettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_settings_controller, c_memory_pool_file_cache_settings_controller )	  C_RBDB_STRUCT(		rb_memory_pool_file_cache_settings_controller, c_memory_pool_file_cache_settings_controller, Rbdb_MemoryPoolFileCacheSettingsController )

	#define RUBY_RBDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_memory_pool_file_cache_priority_settings_controller )															  RUBY_RBDB_OBJECT(	c_memory_pool_file_cache_priority_settings_controller, rb_Rbdb_MemoryPoolFileCachePrioritySettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller )	  C_RBDB_STRUCT(		rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller, Rbdb_MemoryPoolFileCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_memory_pool_file_page_settings_controller )																				  RUBY_RBDB_OBJECT(	c_memory_pool_file_page_settings_controller, rb_Rbdb_MemoryPoolFilePageSettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller )									  C_RBDB_STRUCT(		rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller, Rbdb_MemoryPoolFilePageSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( c_memory_pool_record_read_write_settings_controller )																			  RUBY_RBDB_OBJECT(	c_memory_pool_record_read_write_settings_controller, rb_Rbdb_MemoryPoolReadWriteSettingsController, NULL, NULL )
	#define C_RBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller )								  C_RBDB_STRUCT(		rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller, Rbdb_MemoryPoolReadWriteSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_MESSAGE_SETTINGS_CONTROLLER( c_message_settings_controller )																											  RUBY_RBDB_OBJECT(	c_message_settings_controller, rb_Rbdb_MessageSettingsController, NULL, NULL )
	#define C_RBDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller )																			  C_RBDB_STRUCT(		rb_message_settings_controller, c_message_settings_controller, Rbdb_MessageSettingsController )
                                                                                                                                                											  
	#define RUBY_RBDB_MUTEX_SETTINGS_CONTROLLER( c_mutex_settings_controller )																												  RUBY_RBDB_OBJECT(	c_mutex_settings_controller, rb_Rbdb_MutexSettingsController, NULL, NULL )
	#define C_RBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller )																					  C_RBDB_STRUCT(		rb_mutex_settings_controller, c_mutex_settings_controller, Rbdb_MutexSettingsController )
                                                                                                                                                											  
	#define RUBY_RBDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller )																									  RUBY_RBDB_OBJECT(	c_replication_settings_controller, rb_Rbdb_ReplicationSettingsController, NULL, NULL )
	#define C_RBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller )																  C_RBDB_STRUCT(		rb_replication_settings_controller, c_replication_settings_controller, Rbdb_ReplicationSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( c_replication_election_settings_controller )																				  RUBY_RBDB_OBJECT(	c_replication_election_settings_controller, rb_Rbdb_ReplicationElectionSettingsController, NULL, NULL )
	#define C_RBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller )										  C_RBDB_STRUCT(		rb_replication_election_settings_controller, c_replication_election_settings_controller, Rbdb_ReplicationElectionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( c_replication_timeout_settings_controller )																					  RUBY_RBDB_OBJECT(	c_replication_timeout_settings_controller, rb_Rbdb_ReplicationTimeoutSettingsController, NULL, NULL )
	#define C_RBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller )										  C_RBDB_STRUCT(		rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller, Rbdb_ReplicationTimeoutSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( c_replication_verbosity_settings_controller )																				  RUBY_RBDB_OBJECT(	c_replication_verbosity_settings_controller, rb_Rbdb_ReplicationVerbositySettingsController, NULL, NULL )
	#define C_RBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller )									  C_RBDB_STRUCT(		rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller, Rbdb_ReplicationVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_THREAD_SETTINGS_CONTROLLER( c_thread_settings_controller )																											  RUBY_RBDB_OBJECT(	c_thread_settings_controller, rb_Rbdb_ThreadSettingsController, NULL, NULL )
	#define C_RBDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller )																				  C_RBDB_STRUCT(		rb_thread_settings_controller, c_thread_settings_controller, Rbdb_ThreadSettingsController )
                                                                                                                                                                                              
	#define RUBY_RBDB_TRANSACTION_SETTINGS_CONTROLLER( c_transaction_settings_controller )																									  RUBY_RBDB_OBJECT(	c_transaction_settings_controller, rb_Rbdb_TransactionSettingsController, NULL, NULL )
	#define C_RBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller )																  C_RBDB_STRUCT(		rb_transaction_settings_controller, c_transaction_settings_controller, Rbdb_TransactionSettingsController )

	/****************************
	*	Wrapping/Get Macros		*
	****************************/

	//	Extract C Rbdb struct from Ruby T_DATA
	#define C_RBDB_STRUCT(	rb_object, c_struct, rbdb_type )	Data_Get_Struct(	rb_object,																					\
																																							rbdb_type,																					\
																																							c_struct )

	//	Wrap Ruby RBDB T_DATA from C Rbdb struct
	#define RUBY_RBDB_OBJECT(	c_object, rb_rbdb_type, c_mark_function, c_free_function )	Data_Wrap_Struct(	rb_rbdb_type,						\
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

	#define RUBY_STRING_FOR_KEY_IN_RBDB_RECORD( c_record )																						\
		( ( Rbdb_Record_rawKey( c_record ) != NULL ) ? rb_str_new(	(char*) Rbdb_Record_rawKey( c_record ),						\
																										Rbdb_Record_keySize( c_record ) )															\
																									: Qnil )

	#define RUBY_STRING_FOR_PRIMARY_KEY_IN_RBDB_RECORD( c_record )																						\
		( ( Rbdb_Record_rawPrimaryKey( c_record ) != NULL ) ? rb_str_new(	(char*) Rbdb_Record_rawPrimaryKey( c_record ),						\
																													Rbdb_Record_primaryKeySize( c_record ) )															\
																												: Qnil )

	#define RUBY_STRING_FOR_DATA_IN_RBDB_RECORD( c_record )																													\
		( ( Rbdb_Record_rawData( c_record ) != NULL ) ? rb_str_new(	(char*) Rbdb_Record_rawData( c_record ),					\
																										Rbdb_Record_dataSize( c_record ) )														\
																									: Qnil )

	#define RUBY_STRING_FOR_RBDB_DATA( c_data )																													\
		( ( Rbdb_Data_rawData( c_data ) != NULL ) ? rb_str_new(	(char*) Rbdb_Data_rawData( c_data ),					\
																										Rbdb_Data_size( c_data ) )														\
																									: Qnil )

	#define RUBY_STRINGS_FOR_KEY_AND_DATA_IN_RBDB_RECORD( rb_key, rb_data, c_record )																\
		rb_key	= RUBY_STRING_FOR_KEY_IN_RBDB_RECORD( c_record );																											\
		rb_data	= RUBY_STRING_FOR_DATA_IN_RBDB_RECORD( c_record );		

	#define RETURN_RUBY_STRING_FOR_KEY_IN_RBDB_RECORD( c_record )																										\
		VALUE	rb_return_value	=	RUBY_STRING_FOR_KEY_IN_RBDB_RECORD( c_record );																				\
		Rbdb_Record_free( & c_record );																																								\
		return rb_return_value;

	#define RETURN_RUBY_STRING_FOR_DATA_IN_RBDB_RECORD( c_record )																									\
		VALUE	rb_return_value	=	RUBY_STRING_FOR_DATA_IN_RBDB_RECORD( c_record );																			\
		Rbdb_Record_free( & c_record );																																								\
		return rb_return_value;

	
	/*******************
	*  Error Checking  *
	*******************/

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																								\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_WRITE( rb_key, rb_data )															\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																											\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );															\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_RETRIEVE( rb_key )																							\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_RETRIEVE( rb_key, rb_data )														\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY( rb_key );																														\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA );															\
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
		
#endif