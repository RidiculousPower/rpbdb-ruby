#ifndef RB_RPBDB_CONSTANTS
	#define RB_RPBDB_CONSTANTS

	#define RPBDB_RUBY_MODULE_VARIABLE_EXTENDED_CLASSES_HASH															"@rpbdb__extended_classes_hash"
	#define RPBDB_RUBY_MODULE_VARIABLE_INCLUDED_FOR_CLASSES_HASH													"@rpbdb__included_for_classes_hash"

	//	Ruby items that exist in a one => many storage relation require runtime storages 
	//	so that garbage collection can function properly; otherwise the item stored in the hash will prevent
	//	collection from even taking place.
	#define	RPBDB_RUBY_RUNTIME_STORAGE_ENVIRONMENT_HANDLE																"ruby_environments"
	#define	RPBDB_RUBY_RUNTIME_STORAGE_DATABASE_HANDLE																		"ruby_databases"
	#define	RPBDB_RUBY_RUNTIME_STORAGE_DATABASE_CURSOR_HANDLE														"ruby_database_cursors"

	//	Module Variables

	#define RPBDB_RUBY_MODULE_VARIABLE_ENVIRONMENTS																			"@rpbdb__environments"
	#define RPBDB_RUBY_MODULE_VARIABLE_IDENTIFICATION_WAIT_LIST_ARRAY										"@rpbdb__identification_wait_list"
	#define RPBDB_RUBY_MODULE_VARIABLE_DEFAULT_ENVIRONMENT_WAIT_LIST_ARRAY								"@rpbdb__current_working_environment_wait_list"
	#define RPBDB_RUBY_MODULE_VARIABLE_INITIALIZATION_WAIT_LIST_ARRAY										"@rpbdb__initialization_wait_list_array"
	#define RPBDB_RUBY_MODULE_VARIABLE_CURRENT_WORKING_ENVIRONMENT_STACK									"@current_working_environment_stack"
	#define RPBDB_RUBY_MODULE_VARIABLE_ENVIRONMENT_COUNT																	"@rpbdb__environment_count"
	#define RPBDB_RUBY_MODULE_VARIABLE_DATABASE_RUNTIME_STORAGE													"@rpbdb__database_runtime_storage"
	#define RPBDB_RUBY_MODULE_SECONDARY_KEY_CALLBACK_METHODS															"@rpbdb_secondary_key_callback_methods"

	//	Class Variables
	
	//	Environment
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_CONFIGURED_CLASSES															"@rpbdb__configured_classes_array"
	
	//	Database Controller
	#define RPBDB_RB_DATABASE_CONTROLLER_VARIABLE_DATABASES_HASH													"@rpbdb__databases_hash"

	//	Database
	#define RPBDB_RB_DATABASE_SETTINGS_READ_WRITE_VARIABLE_STORAGE_TYPE									"@storage_type"
	
	
	
	
	
	
	
	//	Environment
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_DATABASE_CONTROLLER														"@database_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_LOCK_CONTROLLER																"@lock_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_LOG_CONTROLLER																	"@log_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_MEMORY_POOL_CONTROLLER													"@memory_pool_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_MUTEX_CONTROLLER																"@mutex_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_REPLICATION_CONTROLLER													"@replication_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_TRANSACTION_CONTROLLER													"@transaction_controller"
	#define RPBDB_RB_ENVIRONMENT_VARIABLE_SETTINGS_CONTROLLER														"@settings_controller"

	//	Database Controller

	#define RPBDB_RB_DATABASE_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT											"@parent_environment"

	//	Database
	#define RPBDB_RB_DATABASE_VARIABLE_CURSOR_CONTROLLER																	"@cursor_controller"
	#define RPBDB_RB_DATABASE_VARIABLE_JOIN_CONTROLLER																		"@join_controller"
	#define RPBDB_RB_DATABASE_VARIABLE_SEQUENCE_CONTROLLER																"@sequence_controller"
	#define RPBDB_RB_DATABASE_VARIABLE_UNIQUE_INDEXES																		"@unique_indexes"

	#define RPBDB_RB_DATABASE_VARIABLE_PARENT_DATABASE_CONTROLLER												"@parent_database_controller"

	#define RPBDB_RB_DATABASE_VARIABLE_SECONDARY_DATABASES																"@secondary_databases"

	//	Database Cursor Controller
	#define RPBDB_RB_CURSOR_CONTROLLER_VARIABLE_PARENT_DATABASE													"@parent_database"

	//	Database Cursor
	#define RPBDB_RB_CURSOR_VARIABLE_PARENT_CURSOR_CONTROLLER														"@parent_cursor_controller"

	//	Database Join Controller
	#define RPBDB_RB_JOIN_CONTROLLER_VARIABLE_PARENT_DATABASE														"@parent_database"
	
	//	Database Join Cursor
	#define RPBDB_RB_JOIN_CURSOR_VARIABLE_PARENT_JOIN_CONTROLLER													"@parent_join_controller"
	
	//	Database Sequence Controller
	#define RPBDB_RB_DATABASE_SEQUENCE_CONTROLLER_VARIABLE_PARENT_DATABASE												"@parent_database"

	//	Database Sequence
	#define RPBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER								"@parent_sequence_controller"
	
	//	Lock Controller
		#define RPBDB_RB_LOCK_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT												"@parent_environment"

	//	Lock
	#define RPBDB_RB_LOCK_VARIABLE_PARENT_LOCK_CONTROLLER																"@parent_lock_controller"
	
	//	Log Controller
	#define RPBDB_RB_LOG_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT													"@parent_environment"
	
	//	Log Cursor
	#define RPBDB_RB_LOG_CURSOR_VARIABLE_PARENT_LOG_CONTROLLER														"@parent_log_controller"
	
	//	Log
	#define RPBDB_RB_LOG_VARIABLE_PARENT_LOG_CURSOR																			"@parent_log_cursor"
	
	//	Log Sequence Number
	#define RPBDB_RB_LOG_SEQUENCE_NUMBER_VARIABLE_PARENT_LOG															"@parent_log"
	
	//	Memory Pool Controller
	#define RPBDB_RB_MEMORY_POOL_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Memory Pool File Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_CONTROLLER	"@parent_memory_pool_controller"
	
	//	Memory Pool File
	#define RPBDB_RB_MEMORY_POOL_FILE_VARIABLE_PARENT_MEMORY_POOL_FILE_CONTROLLER				"@parent_memory_pool_file_controller"
	
	//	Memory Pool File Page Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_PAGE_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE		"@parent_memory_pool_file"
	
	//	Memory Pool File Page
	#define RPBDB_RB_MEMORY_POOL_FILE_PAGE_VARIABLE_PARENT_MEMORY_POOL_FILE_PAGE_CONTROLLER					"@parent_memory_pool_file_page_controller"
	
	//	Mutex Controller
	#define RPBDB_RB_MUTEX_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT												"@parent_environment"
	
	//	Mutex
	#define RPBDB_RB_MUTEX_VARIABLE_PARENT_MUTEX_CONTROLLER															"@parent_mutex_controller"
	
	//	Record
	#define RPBDB_RB_RECORD_VARIABLE_PARENT_DATABASE																			"@parent_database"
	
	//	Key
	#define RPBDB_RB_KEY_VARIABLE_PARENT_RECORD																					"@parent_record"
	
	//	Data
	#define RPBDB_RB_DATA_VARIABLE_PARENT_RECORD																					"@parent_record"
	
	//	Secondary Keys
	#define RPBDB_RB_SECONDARY_KEYS_VARIABLE_PARENT_RECORD																"@parent_record"
	
	//	Replication Controller
	#define RPBDB_RB_REPLICATION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Remote Site
	#define RPBDB_RB_REMOTE_SITE_VARIABLE_PARENT_REPLICATION_CONTROLLER									"@parent_replication_controller"
	
	//	Transaction Controller
	#define RPBDB_RB_TRANSACTION_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Transaction
	#define RPBDB_RB_TRANSACTION_VARIABLE_PARENT_TRANSACTION_CONTROLLER									"@parent_transaction_controller"
	
	//	Settings Controller
	#define RPBDB_RB_SETTINGS_CONTROLLER_VARIABLE_PARENT_ENVIRONMENT									"@parent_environment"
	
	//	Database Settings Controller
	#define RPBDB_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	#define RPBDB_RB_DATABASE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE															"@parent_database"
	
	//	Database Association Settings Controller
	#define RPBDB_RB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Cache Settings Controller
	#define RPBDB_RB_DATABASE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Cache Priority Settings Controller
	#define RPBDB_RB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_cache_settings_controller"
	
	//	Database Cursor Settings Controller
	#define RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	#define RPBDB_RB_DATABASE_CURSOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR																"@parent_database_cursor"
	
	//	Database Cursor Read Write Settings Controller
	#define RPBDB_RB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER									"@parent_database_cursor_settings_controller"
	
	//	Database Cursor Cache Settings Controller
	#define RPBDB_RB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_SETTINGS_CONTROLLER									"@parent_database_cursor_settings_controller"
	
	//	Database Cursor Cache Priority Settings Controller
	#define RPBDB_RB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER									"@parent_database_cursor_cache_settings_controller"
	
	//	Database Compact Settings Controller
	#define RPBDB_RB_DATABASE_COMPACT_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Encryption Settings Controller
	#define RPBDB_RB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Error Settings Controller
	#define RPBDB_RB_DATABASE_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Join Settings Controller
	#define RPBDB_RB_DATABASE_JOIN_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Record Settings Controller
	#define RPBDB_RB_DATABASE_RECORD_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Record Fixed Length Settings Controller
	#define RPBDB_RB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Record Variable Length Settings Controller
	#define RPBDB_RB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Record Read Write Settings Controller
	#define RPBDB_RB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_RECORD_SETTINGS_CONTROLLER									"@parent_database_record_settings_controller"
	
	//	Database Sequence Settings Controller
	#define RPBDB_RB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Type Settings Controller
	#define RPBDB_RB_DATABASE_TYPE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Btree Type Settings Controller
	#define RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER											"@parent_database_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"
	
	//	Database Hash Type Settings Controller
	#define RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER												"@parent_database_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																						"@parent_database"

	//	Database Recno Type Settings Controller
	#define RPBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER												"@parent_database_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"

	//	Database Queue Type Settings Controller
	#define RPBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_TYPE_SETTINGS_CONTROLLER									"@parent_database_type_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER											"@parent_database_settings_controller"
	#define RPBDB_RB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE																					"@parent_database"

	//	Database Verbosity Settings Controller
	#define RPBDB_RB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Database Verification Settings Controller
	#define RPBDB_RB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_DATABASE_SETTINGS_CONTROLLER									"@parent_database_settings_controller"
	
	//	Debug Settings Controller
	#define RPBDB_RB_DEBUG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Debug Verbosity Settings Controller
	#define RPBDB_RB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_DEBUG_SETTINGS_CONTROLLER									"@parent_debug_settings_controller"
	
	//	Directory Settings Controller
	#define RPBDB_RB_DIRECTORY_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Environmental Cache Settings Controller
	#define RPBDB_RB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Error Settings Controller
	#define RPBDB_RB_ERROR_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	File Settings Controller
	#define RPBDB_RB_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	File Verbosity Settings Controller
	#define RPBDB_RB_FILE_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_FILE_SETTINGS_CONTROLLER									"@parent_file_settings_controller"
	
	//	Lock Settings Controller
	#define RPBDB_RB_LOCK_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Lock Deadlock Detector Settings Controller
	#define RPBDB_RB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_SETTINGS_CONTROLLER									"@parent_lock_settings_controller"
	
	//	Lock Deadlock Detector Verbosity Settings Controller
	#define RPBDB_RB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER									"@parent_lock_deadlock_detector_settings_controller"
	
	//	Log Settings Controller
	#define RPBDB_RB_LOG_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER																						"@parent_settings_controller"
	
	//	Memory Pool Settings Controller
	#define RPBDB_RB_MEMORY_POOL_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Memory Pool Read Write Settings Controller
	#define RPBDB_RB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER									"@parent_memory_pool_settings_controller"

	//	Memory Pool File Settings Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_SETTINGS_CONTROLLER									"@parent_memory_pool_settings_controller"

	//	Memory Pool File Page Settings Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_settings_controller"

	//	Memory Pool File Cache Settings Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_settings_controller"

	//	Memory Pool File Cache Priority Settings Controller
	#define RPBDB_RB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER									"@parent_memory_pool_file_cache_settings_controller"

	//	Message Settings Controller
	#define RPBDB_RB_MESSAGE_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Mutex Settings Controller
	#define RPBDB_RB_MUTEX_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Replication Settings Controller
	#define RPBDB_RB_REPLICATION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"

	//	Replication Election Settings Controller
	#define RPBDB_RB_REPLICATION_ELECTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Replication Timeout Settings Controller
	#define RPBDB_RB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Replication Verbosity Settings Controller
	#define RPBDB_RB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER_VARIABLE_PARENT_REPLICATION_SETTINGS_CONTROLLER									"@parent_replication_settings_controller"

	//	Thread Settings Controller
	#define RPBDB_RB_THREAD_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"
	
	//	Transaction Settings Controller
	#define RPBDB_RB_TRANSACTION_SETTINGS_CONTROLLER_VARIABLE_PARENT_SETTINGS_CONTROLLER									"@parent_settings_controller"






	
	#define RPBDB_RB_DATABASE_SEQUENCE_CONTROLLER																	"@database_sequence_controller"


	#define RPBDB_RB_ALL_VARIABLE_PARENT_ENVIRONMENT																"@parent_environment"
	#define RPBDB_RB_ALL_VARIABLE_PARENT_DATABASE																	"@parent_database"
	#define RPBDB_RB_ALL_VARIABLE_PARENT_DATABASE_CURSOR_CONTROLLER								"@parent_database_cursor_controller"

	#define RPBDB_RB_SETTINGS_VARIABLE_SETTINGS_CONTROLLER													"@settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_FILE_SETTINGS_CONTROLLER										"@file_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_FILE_VERBOSITY_SETTINGS_CONTROLLER					"@file_verbosity_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_ERROR_SETTINGS_CONTROLLER										"@error_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_LOG_SETTINGS_CONTROLLER											"@log_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_LOG_CURSOR_SETTINGS_CONTROLLER							"@log_cursor_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_LOCK_SETTINGS_CONTROLLER										"@lock_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER										"@lock_deadlock_detector_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER										"@lock_deadlock_detector_verbosity_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MUTEX_SETTINGS_CONTROLLER										"@mutex_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_SETTINGS_CONTROLLER							"@replication_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_ELECTION_SETTINGS_CONTROLLER							"@replication_election_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER							"@replication_timeout_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER							"@replication_verbosity_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_SETTINGS_CONTROLLER							"@memory_pool_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER							"@memory_pool_read_write_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_SETTINGS_CONTROLLER				"@memory_pool_file_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER		"@memory_pool_file_page_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER		"@memory_pool_file_cache_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER		"@memory_pool_file_cache_priority_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SETTINGS_CONTROLLER								"@database_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER		"@database_association_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_SETTINGS_CONTROLLER					"@database_cache_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER					"@database_cache_priority_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER					"@database_cursor_cache_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER					"@database_cursor_cache_priority_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_SETTINGS_CONTROLLER					"@database_cursor_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER					"@database_cursor_read_write_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_ERROR_SETTINGS_CONTROLLER					"@database_error_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_SETTINGS_CONTROLLER								"@database_record_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER								"@database_record_fixed_length_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER								"@database_record_variable_length_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER								"@database_record_read_write_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER								"@database_read_write_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_SETTINGS_CONTROLLER								"@database_type_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER								"@database_type_btree_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER								"@database_type_hash_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER								"@database_type_queue_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER								"@database_type_recno_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DIRECTORY_SETTINGS_CONTROLLER								"@directory_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER				"@database_sequence_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_JOIN_SETTINGS_CONTROLLER						"@database_join_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_RECORD_SETTINGS_CONTROLLER									"@database_record_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DEBUG_SETTINGS_CONTROLLER									"@database_debug_settings_controller"
	#define RPBDB_RB_SETTINGS_VARIABLE_DEBUG_VERBOSITY_SETTINGS_CONTROLLER									"@database_debug_verbosity_settings_controller"
	
	#define RPBDB_RB_SETTINGS_VARIABLE_DATABASE_READ_WRITE_SETTINGS_CONTROLLER_SERIALIZE_DATA		"@serialize_data"

	#define RPBDB_FUNCTION_INIT																										"init_rpbdb"
	#define RPBDB_FUNCTION_CONFIGURE																						"configure_rpbdb"
	#define RPBDB_FUNCTION_IDENTIFY_AS																					"identify_for_rpbdb_as"

	#define	RPBDB_RUBY_CONSTANT_DEFAULT																				"Default"

	#define RPBDB_RUBY_ERROR_MESSAGE_DUPLICATES_AND_KEY_OR_BLOCK_REQUIRED			"Duplicates must be enabled and key must be set or must be inside iterate block to iterate duplicates."
	#define RPBDB_RUBY_ERROR_MESSAGE_ENVIRONMENT_NOT_FOUND											"Requested Environment was missing."
	#define RPBDB_RUBY_ERROR_MESSAGE_DATABASE_CONTROLLER_NOT_FOUND							"Requested Environment was missing."
	#define RPBDB_RUBY_ERROR_ENVIRONMENT_WITH_NAME_ALREADY_EXISTS							"Environment with requested name already exists."

	#define RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY													"Cannot write to database without key."
	#define RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA													"Cannot write to database without data."
	#define RPBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY												"Cannot retrieve to database without key."
	#define RPBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA											"Cannot retrieve to database without data."

	#define RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_SECONDARY_KEY_CALLBACK						"Secondary key creation callback method/proc has unexpected arity. Expected 1, 2, 3 or -1."
	#define RPBDB_RUBY_ERROR_WRONG_ARITY_FOR_ITERATION                         "Iteration block has unexpected arity. Expected 1, 2, 3 or -1."

	/****************************
	*	Get Ruby from C Macros	*
	****************************/

	#define RUBY_RPBDB_ENVIRONMENT( c_environment )																																RUBY_RPBDB_OBJECT(	c_environment, rb_RPbdb_Environment, NULL, NULL )
	#define RUBY_RPBDB_ENVIRONMENT_WITH_FREE( c_environment )																											RUBY_RPBDB_OBJECT(	c_environment, rb_RPbdb_Environment, NULL, rb_RPbdb_Environment_free )
	#define C_RPBDB_ENVIRONMENT( rb_environment, c_environment )																										C_RPBDB_STRUCT(		rb_environment, c_environment, RPbdb_Environment )
                                                                                                    								
	#define RUBY_RPBDB_DATABASE_CONTROLLER( c_database_controller )																								RUBY_RPBDB_OBJECT(	c_database_controller, rb_RPbdb_DatabaseController, NULL, NULL )
	#define C_RPBDB_DATABASE_CONTROLLER( rb_database_controller, c_database_controller )														C_RPBDB_STRUCT(		rb_database_controller, c_database_controller, RPbdb_DatabaseController )
                                                                                                    								
	#define RUBY_RPBDB_DATABASE( c_database )																									RUBY_RPBDB_OBJECT(	c_database, rb_RPbdb_Database, NULL, NULL )
	#define C_RPBDB_DATABASE( rb_database, c_database )																				C_RPBDB_STRUCT(		rb_database, c_database, RPbdb_Database )

	#define RUBY_RPBDB_BTREE_DATABASE( c_btree_database )																									RUBY_RPBDB_OBJECT(	c_btree_database, rb_RPbdb_BtreeDatabase, NULL, NULL )
	#define RUBY_RPBDB_HASH_DATABASE( c_hash_database )																										RUBY_RPBDB_OBJECT(	c_hash_database, rb_RPbdb_HashDatabase, NULL, NULL )
	#define RUBY_RPBDB_QUEUE_DATABASE( c_queue_database )																									RUBY_RPBDB_OBJECT(	c_queue_database, rb_RPbdb_QueueDatabase, NULL, NULL )
	#define RUBY_RPBDB_RECNO_DATABASE( c_recno_database )																									RUBY_RPBDB_OBJECT(	c_recno_database, rb_RPbdb_RecnoDatabase, NULL, NULL )

	#define RUBY_RPBDB_DATABASE_OBJECT_DATABASE( c_database )																		RUBY_RPBDB_OBJECT(	c_database, rb_RPbdb_DatabaseObjectDatabase, NULL, NULL )
	#define C_RPBDB_DATABASE_OBJECT_DATABASE( rb_database, c_database )																C_RPBDB_STRUCT(		rb_database, c_database, RPbdb_Database )

	#define RUBY_RPBDB_DATABASE_CURSOR_CONTROLLER( c_cursor_controller )															RUBY_RPBDB_OBJECT(	c_cursor_controller, rb_RPbdb_DatabaseCursorController, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR_CONTROLLER( rb_cursor_controller, c_cursor_controller )											C_RPBDB_STRUCT(		rb_cursor_controller, c_cursor_controller, RPbdb_DatabaseCursorController )
                                                                            														
	#define RUBY_RPBDB_DATABASE_CURSOR( c_cursor )																					RUBY_RPBDB_OBJECT(	c_cursor, rb_RPbdb_DatabaseCursor, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR( rb_cursor, c_cursor )																			C_RPBDB_STRUCT(		rb_cursor, c_cursor, RPbdb_DatabaseCursor )
                                                                            														
	#define RUBY_RPBDB_DATABASE_OBJECT_CURSOR( c_cursor )																			RUBY_RPBDB_OBJECT(	c_cursor, rb_RPbdb_DatabaseObjectCursor, NULL, NULL )
	#define C_RPBDB_DATABASE_OBJECT_CURSOR( rb_cursor, c_cursor )																	C_RPBDB_STRUCT(		rb_cursor, c_cursor, RPbdb_DatabaseCursor )
                                                                                                    								
	#define RUBY_RPBDB_DATABASE_JOIN_CONTROLLER( c_join_controller )																RUBY_RPBDB_OBJECT(	c_join_controller, rb_RPbdb_DatabaseJoinController, NULL, NULL )
	#define C_RPBDB_DATABASE_JOIN_CONTROLLER( rb_join_controller, c_join_controller )												C_RPBDB_STRUCT(		rb_join_controller, c_join_controller, RPbdb_DatabaseJoinController )
                                                                            														
	#define RUBY_RPBDB_DATABASE_JOIN_CURSOR( c_join_cursor )																		RUBY_RPBDB_OBJECT(	c_join_cursor, rb_RPbdb_DatabaseJoinCursor, NULL, NULL )
	#define C_RPBDB_DATABASE_JOIN_CURSOR( rb_join_cursor, c_join_cursor )															C_RPBDB_STRUCT(		rb_join_cursor, c_join_cursor, RPbdb_DatabaseJoinCursor )
                                                                                                                            		
	#define RUBY_RPBDB_DATABASE_SEQUENCE_CONTROLLER( c_database_sequence_controller )												RUBY_RPBDB_OBJECT(	c_database_sequence_controller, rb_RPbdb_DatabaseSequenceController, NULL, NULL )
	#define C_RPBDB_DATABASE_SEQUENCE_CONTROLLER( rb_database_sequence_controller, c_database_sequence_controller )					C_RPBDB_STRUCT(		rb_database_sequence_controller, c_database_sequence_controller, RPbdb_DatabaseSequenceController )
                                                                                                                            		
	#define RUBY_RPBDB_DATABASE_SEQUENCE( c_database_sequence )																		RUBY_RPBDB_OBJECT(	c_database_sequence, rb_RPbdb_DatabaseSequence, NULL, NULL )
	#define C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence )													C_RPBDB_STRUCT(		rb_database_sequence, c_database_sequence, RPbdb_DatabaseSequence )

	#define RUBY_RPBDB_ERROR_CONTROLLER( c_error_controller )																		RUBY_RPBDB_OBJECT(	c_error_controller, rb_RPbdb_ErrorController, NULL, NULL )
	#define C_RPBDB_ERROR_CONTROLLER( rb_error_controller, c_error_controller )														C_RPBDB_STRUCT(		rb_error_controller, c_error_controller, RPbdb_ErrorController )

	#define RUBY_RPBDB_ERROR( c_error )																								RUBY_RPBDB_OBJECT(	c_error, rb_RPbdb_Error, NULL, NULL )
	#define C_RPBDB_ERROR( rb_error, c_error )																						C_RPBDB_STRUCT(		rb_error, c_error, RPbdb_Error )

	#define RUBY_RPBDB_LOCK_CONTROLLER( c_lock_controller )																			RUBY_RPBDB_OBJECT(	c_lock_controller, rb_RPbdb_LockController, NULL, NULL )
	#define C_RPBDB_LOCK_CONTROLLER( rb_lock_controller, c_lock_controller )														C_RPBDB_STRUCT(		rb_lock_controller, c_lock_controller, RPbdb_LockController )

	#define RUBY_RPBDB_LOCK( c_lock )																								RUBY_RPBDB_OBJECT(	c_lock, rb_RPbdb_Lock, NULL, NULL )
	#define C_RPBDB_LOCK( rb_lock, c_lock )																							C_RPBDB_STRUCT(		rb_lock, c_lock, RPbdb_Lock )

	#define RUBY_RPBDB_LOG_CONTROLLER( c_log_controller )																			RUBY_RPBDB_OBJECT(	c_log_controller, rb_RPbdb_LogController, NULL, NULL )
	#define C_RPBDB_LOG_CONTROLLER( rb_log_controller, c_log_controller )															C_RPBDB_STRUCT(		rb_log_controller, c_log_controller, RPbdb_LogController )

	#define RUBY_RPBDB_LOG( c_log )																									RUBY_RPBDB_OBJECT(	c_log, rb_RPbdb_Log, NULL, NULL )
	#define C_RPBDB_LOG( rb_log, c_log )																							C_RPBDB_STRUCT(		rb_log, c_log, RPbdb_Log )

	#define RUBY_RPBDB_LOG_CURSOR_CONTROLLER( c_log_cursor_controller )																RUBY_RPBDB_OBJECT(	c_log_cursor_controller, rb_RPbdb_LogCursorController, NULL, NULL )
	#define C_RPBDB_LOG_CURSOR_CONTROLLER( rb_log_cursor_controller, c_log_cursor_controller )										C_RPBDB_STRUCT(		rb_log_cursor_controller, c_log_cursor_controller, RPbdb_LogCursorController )

	#define RUBY_RPBDB_LOG_CURSOR( c_log_cursor )																					RUBY_RPBDB_OBJECT(	c_log_cursor, rb_RPbdb_LogCursor, NULL, NULL )
	#define C_RPBDB_LOG_CURSOR( rb_log_cursor, c_log_cursor )																		C_RPBDB_STRUCT(		rb_log_cursor, c_log_cursor, RPbdb_LogCursor )

	#define RUBY_RPBDB_LOG_SEQUENCE_NUMBER( c_log_sequence_number )																	RUBY_RPBDB_OBJECT(	c_log_sequence_number, rb_RPbdb_LogSequenceNumber, NULL, NULL )
	#define C_RPBDB_LOG_SEQUENCE_NUMBER( rb_log_sequence_number, c_log_sequence_number )											C_RPBDB_STRUCT(		rb_log_sequence_number, c_log_sequence_number, RPbdb_LogSequenceNumber )

	#define RUBY_RPBDB_MEMORY_POOL_CONTROLLER( c_memory_pool_controller )															RUBY_RPBDB_OBJECT(	c_memory_pool_controller, rb_RPbdb_MemoryPoolController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_CONTROLLER( rb_memory_pool_controller, c_memory_pool_controller )									C_RPBDB_STRUCT(		rb_memory_pool_controller, c_memory_pool_controller, RPbdb_MemoryPoolController )

	#define RUBY_RPBDB_MEMORY_POOL_FILE_CONTROLLER( c_memory_pool_file_controller )													RUBY_RPBDB_OBJECT(	c_memory_pool_file_controller, rb_RPbdb_MemoryPoolFileController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_CONTROLLER( rb_memory_pool_file_controller, c_memory_pool_file_controller )					C_RPBDB_STRUCT(		rb_memory_pool_file_controller, c_memory_pool_file_controller, RPbdb_MemoryPoolFileController )

	#define RUBY_RPBDB_MEMORY_POOL_FILE( c_memory_pool_file )																		RUBY_RPBDB_OBJECT(	c_memory_pool_file, rb_RPbdb_MemoryPoolFile, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE( rb_memory_pool_file, c_memory_pool_file )														C_RPBDB_STRUCT(		rb_memory_pool_file, c_memory_pool_file, RPbdb_MemoryPoolFile )

	#define RUBY_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( c_memory_pool_file_page_controller )										RUBY_RPBDB_OBJECT(	c_memory_pool_file_page_controller, rb_RPbdb_MemoryPoolFilePageController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_PAGE_CONTROLLER( rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller )		C_RPBDB_STRUCT(		rb_memory_pool_file_page_controller, c_memory_pool_file_page_controller, RPbdb_MemoryPoolFilePageController )

	#define RUBY_RPBDB_MEMORY_POOL_FILE_PAGE( c_memory_pool_file_page )																RUBY_RPBDB_OBJECT(	c_memory_pool_file_page, rb_RPbdb_MemoryPoolFilePage, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_PAGE( rb_memory_pool_file_page, c_memory_pool_file_page )										C_RPBDB_STRUCT(		rb_memory_pool_file_page, c_memory_pool_file_page, RPbdb_MemoryPoolFilePage )

	#define RUBY_RPBDB_MUTEX_CONTROLLER( c_mutex_controller )																		RUBY_RPBDB_OBJECT(	c_mutex_controller, rb_RPbdb_MutexController, NULL, NULL )
	#define C_RPBDB_MUTEX_CONTROLLER( rb_mutex_controller, c_mutex_controller )														C_RPBDB_STRUCT(		rb_mutex_controller, c_mutex_controller, RPbdb_MutexController )

	#define RUBY_RPBDB_MUTEX( c_mutex )																								RUBY_RPBDB_OBJECT(	c_mutex, rb_RPbdb_Mutex, NULL, NULL )
	#define C_RPBDB_MUTEX( rb_mutex, c_mutex )																						C_RPBDB_STRUCT(		rb_mutex, c_mutex, RPbdb_Mutex )

	#define RUBY_RPBDB_RECORD( c_record )																							RUBY_RPBDB_OBJECT(	c_record, rb_RPbdb_Record, NULL, NULL )
	#define C_RPBDB_RECORD( rb_record, c_record )																					C_RPBDB_STRUCT(		rb_record, c_record, RPbdb_Record )

	#define RUBY_RPBDB_DATA( c_data )																								RUBY_RPBDB_OBJECT(	c_data, rb_RPbdb_Data, NULL, NULL )
	#define C_RPBDB_DATA( rb_data, c_data )																							C_RPBDB_STRUCT(		rb_data, c_data, RPbdb_Data )

	#define RUBY_RPBDB_KEY( c_key )																									RUBY_RPBDB_OBJECT(	c_key, rb_RPbdb_Key, NULL, NULL )
	#define C_RPBDB_KEY( rb_key, c_key )																							C_RPBDB_STRUCT(		rb_key, c_key, RPbdb_Key )

	#define RUBY_RPBDB_SECONDARY_KEYS( c_secondary_key )																			RUBY_RPBDB_OBJECT(	c_secondary_key, rb_RPbdb_SecondaryKeys, NULL, NULL )
	#define C_RPBDB_SECONDARY_KEYS( rb_secondary_key, c_secondary_key )																C_RPBDB_STRUCT(		rb_secondary_key, c_secondary_key, RPbdb_SecondaryKeys )

	#define RUBY_RPBDB_REPLICATION_CONTROLLER( c_replication_controller )															RUBY_RPBDB_OBJECT(	c_replication_controller, rb_RPbdb_ReplicationController, NULL, NULL )
	#define C_RPBDB_REPLICATION_CONTROLLER( rb_replication_controller, c_replication_controller )									C_RPBDB_STRUCT(		rb_replication_controller, c_replication_controller, RPbdb_ReplicationController )

	#define RUBY_RPBDB_REMOTE_SITE( c_remote_site )																					RUBY_RPBDB_OBJECT(	c_remote_site, rb_RPbdb_RemoteSite, NULL, NULL )
	#define C_RPBDB_REMOTE_SITE( rb_remote_site, c_remote_site )																	C_RPBDB_STRUCT(		rb_remote_site, c_remote_site, RPbdb_RemoteSite )

	#define RUBY_RPBDB_TRANSACTION_CONTROLLER( c_transaction_controller )															RUBY_RPBDB_OBJECT(	c_transaction_controller, rb_RPbdb_TransactionController, NULL, NULL )
	#define C_RPBDB_TRANSACTION_CONTROLLER( rb_transaction_controller, c_transaction_controller )									C_RPBDB_STRUCT(		rb_transaction_controller, c_transaction_controller, RPbdb_TransactionController )

	#define RUBY_RPBDB_TRANSACTION( c_transaction )																					RUBY_RPBDB_OBJECT(	c_transaction, rb_RPbdb_Transaction, NULL, NULL )
	#define C_RPBDB_TRANSACTION( rb_transaction, c_transaction )																	C_RPBDB_STRUCT(		rb_transaction, c_transaction, RPbdb_Transaction )

	#define RUBY_RPBDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )												RUBY_RPBDB_OBJECT(	c_database_settings_controller, rb_RPbdb_DatabaseSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )					C_RPBDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, RPbdb_DatabaseSettingsController )

		/****************************
		*	Settings Controllers	*
		****************************/

	#define RUBY_RPBDB_SETTINGS_CONTROLLER( c_settings_controller )																															  RUBY_RPBDB_OBJECT(	c_settings_controller, rb_RPbdb_SettingsController, NULL, NULL )
	#define C_RPBDB_SETTINGS_CONTROLLER( rb_settings_controller, c_settings_controller )																									  C_RPBDB_STRUCT(		rb_settings_controller, c_settings_controller, RPbdb_SettingsController )
                                                                                                                                                            								  
	#define RUBY_RPBDB_DATABASE_SETTINGS_CONTROLLER( c_database_settings_controller )																										  RUBY_RPBDB_OBJECT(	c_database_settings_controller, rb_RPbdb_DatabaseSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_database_settings_controller, c_database_settings_controller )																			  C_RPBDB_STRUCT(		rb_database_settings_controller, c_database_settings_controller, RPbdb_DatabaseSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_database_association_settings_controller, rb_RPbdb_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RPBDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, RPbdb_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( c_database_association_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_database_association_settings_controller, rb_RPbdb_DatabaseAssociationSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER( rb_database_association_settings_controller, c_database_association_settings_controller )										  C_RPBDB_STRUCT(		rb_database_association_settings_controller, c_database_association_settings_controller, RPbdb_DatabaseAssociationSettingsController )
                                                                                                                                                            								  
	#define RUBY_RPBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( c_database_cache_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_database_cache_settings_controller, rb_RPbdb_DatabaseCacheSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CACHE_SETTINGS_CONTROLLER( rb_database_cache_settings_controller, c_database_cache_settings_controller )														  C_RPBDB_STRUCT(		rb_database_cache_settings_controller, c_database_cache_settings_controller, RPbdb_DatabaseCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cache_priority_settings_controller )																			  RUBY_RPBDB_OBJECT(	c_database_cache_priority_settings_controller, rb_RPbdb_DatabaseCachePrioritySettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller )							  C_RPBDB_STRUCT(		rb_database_cache_priority_settings_controller, c_database_cache_priority_settings_controller, RPbdb_DatabaseCachePrioritySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( c_database_compact_settings_controller )																						  RUBY_RPBDB_OBJECT(	c_database_compact_settings_controller, rb_RPbdb_DatabaseCompactSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER( rb_database_compact_settings_controller, c_database_compact_settings_controller )													  C_RPBDB_STRUCT(		rb_database_compact_settings_controller, c_database_compact_settings_controller, RPbdb_DatabaseCompactSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( c_database_cursor_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_database_cursor_settings_controller, rb_RPbdb_DatabaseCursorSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR_SETTINGS_CONTROLLER( rb_database_cursor_settings_controller, c_database_cursor_settings_controller )													  C_RPBDB_STRUCT(		rb_database_cursor_settings_controller, c_database_cursor_settings_controller, RPbdb_DatabaseCursorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( c_database_cursor_record_read_write_settings_controller )																	  RUBY_RPBDB_OBJECT(	c_database_cursor_record_read_write_settings_controller, rb_RPbdb_DatabaseCursorReadWriteSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER( rb_database_cursor_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller )					  C_RPBDB_STRUCT(		rb_database_cursor_read_write_settings_controller, c_database_cursor_record_read_write_settings_controller, RPbdb_DatabaseCursorReadWriteSettingsController )
                                                                                                                                                                                    		  
	#define RUBY_RPBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( c_database_cursor_cache_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_database_cursor_cache_settings_controller, rb_RPbdb_DatabaseCursorCacheSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR_CACHE_SETTINGS_CONTROLLER( rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller )									  C_RPBDB_STRUCT(		rb_database_cursor_cache_settings_controller, c_database_cursor_cache_settings_controller, RPbdb_DatabaseCursorCacheSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_database_cursor_cache_priority_settings_controller )															  RUBY_RPBDB_OBJECT(	c_database_cursor_cache_priority_settings_controller, rb_RPbdb_DatabaseCursorCachePrioritySettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller )		  C_RPBDB_STRUCT(		rb_database_cursor_cache_priority_settings_controller, c_database_cursor_cache_priority_settings_controller, RPbdb_DatabaseCursorCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( c_database_encryption_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_encryption_settings_controller, rb_RPbdb_DatabaseEncryptionSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_ENCRYPTION_SETTINGS_CONTROLLER( rb_database_encryption_settings_controller, c_database_encryption_settings_controller )										  C_RPBDB_STRUCT(		rb_database_encryption_settings_controller, c_database_encryption_settings_controller, RPbdb_DatabaseEncryptionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( c_database_error_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_database_error_settings_controller, rb_RPbdb_DatabaseErrorSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_ERROR_SETTINGS_CONTROLLER( rb_database_error_settings_controller, c_database_error_settings_controller )														  C_RPBDB_STRUCT(		rb_database_error_settings_controller, c_database_error_settings_controller, RPbdb_DatabaseErrorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( c_database_record_fixed_length_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_database_record_fixed_length_settings_controller, rb_RPbdb_DatabaseRecordFixedLengthSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_RECORD_FIXED_LENGTH_SETTINGS_CONTROLLER( rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller )									  C_RPBDB_STRUCT(		rb_database_record_fixed_length_settings_controller, c_database_record_fixed_length_settings_controller, RPbdb_DatabaseRecordFixedLengthSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( c_database_join_settings_controller )																								  RUBY_RPBDB_OBJECT(	c_database_join_settings_controller, rb_RPbdb_DatabaseJoinSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER( rb_database_join_settings_controller, c_database_join_settings_controller )															  C_RPBDB_STRUCT(		rb_database_join_settings_controller, c_database_join_settings_controller, RPbdb_DatabaseJoinSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER( c_database_record_read_write_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_record_read_write_settings_controller, rb_RPbdb_DatabaseRecordReadWriteSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_RECORD_READ_WRITE_SETTINGS_CONTROLLER( rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller )										  C_RPBDB_STRUCT(		rb_database_record_read_write_settings_controller, c_database_record_read_write_settings_controller, RPbdb_DatabaseRecordReadWriteSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( c_database_record_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_database_record_settings_controller, rb_RPbdb_DatabaseRecordSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_RECORD_SETTINGS_CONTROLLER( rb_database_record_settings_controller, c_database_record_settings_controller )													  C_RPBDB_STRUCT(		rb_database_record_settings_controller, c_database_record_settings_controller, RPbdb_DatabaseRecordSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_database_sequence_settings_controller )																						  RUBY_RPBDB_OBJECT(	c_database_sequence_settings_controller, rb_RPbdb_DatabaseSequenceSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( rb_database_sequence_settings_controller, c_database_sequence_settings_controller )												  C_RPBDB_STRUCT(		rb_database_sequence_settings_controller, c_database_sequence_settings_controller, RPbdb_DatabaseSequenceSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( c_database_type_settings_controller )																								  RUBY_RPBDB_OBJECT(	c_database_type_settings_controller, rb_RPbdb_DatabaseTypeSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER( rb_database_type_settings_controller, c_database_type_settings_controller )															  C_RPBDB_STRUCT(		rb_database_type_settings_controller, c_database_type_settings_controller, RPbdb_DatabaseTypeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( c_database_type_btree_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_type_btree_settings_controller, rb_RPbdb_DatabaseTypeBtreeSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER( rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller )										  C_RPBDB_STRUCT(		rb_database_type_btree_settings_controller, c_database_type_btree_settings_controller, RPbdb_DatabaseTypeBtreeSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( c_database_type_hash_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_type_hash_settings_controller, rb_RPbdb_DatabaseTypeHashSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_TYPE_HASH_SETTINGS_CONTROLLER( rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller )											  C_RPBDB_STRUCT(		rb_database_type_hash_settings_controller, c_database_type_hash_settings_controller, RPbdb_DatabaseTypeHashSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( c_database_type_recno_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_type_recno_settings_controller, rb_RPbdb_DatabaseTypeRecnoSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_TYPE_RECNO_SETTINGS_CONTROLLER( rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller )										  C_RPBDB_STRUCT(		rb_database_type_recno_settings_controller, c_database_type_recno_settings_controller, RPbdb_DatabaseTypeRecnoSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( c_database_type_queue_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_type_queue_settings_controller, rb_RPbdb_DatabaseTypeQueueSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER( rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller )										  C_RPBDB_STRUCT(		rb_database_type_queue_settings_controller, c_database_type_queue_settings_controller, RPbdb_DatabaseTypeQueueSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( c_database_record_variable_length_settings_controller )																		  RUBY_RPBDB_OBJECT(	c_database_record_variable_length_settings_controller, rb_RPbdb_DatabaseRecordVariableLengthSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_RECORD_VARIABLE_LENGTH_SETTINGS_CONTROLLER( rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller )							  C_RPBDB_STRUCT(		rb_database_record_variable_length_settings_controller, c_database_record_variable_length_settings_controller, RPbdb_DatabaseRecordVariableLengthSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( c_database_verbosity_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_database_verbosity_settings_controller, rb_RPbdb_DatabaseVerbositySettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_VERBOSITY_SETTINGS_CONTROLLER( rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller )											  C_RPBDB_STRUCT(		rb_database_verbosity_settings_controller, c_database_verbosity_settings_controller, RPbdb_DatabaseVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( c_database_verification_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_database_verification_settings_controller, rb_RPbdb_DatabaseVerificationSettingsController, NULL, NULL )
	#define C_RPBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER( rb_database_verification_settings_controller, c_database_verification_settings_controller )									  C_RPBDB_STRUCT(		rb_database_verification_settings_controller, c_database_verification_settings_controller, RPbdb_DatabaseVerificationSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DEBUG_SETTINGS_CONTROLLER( c_debug_settings_controller )																												  RUBY_RPBDB_OBJECT(	c_debug_settings_controller, rb_RPbdb_DebugSettingsController, NULL, NULL )
	#define C_RPBDB_DEBUG_SETTINGS_CONTROLLER( rb_debug_settings_controller, c_debug_settings_controller )																					  C_RPBDB_STRUCT(		rb_debug_settings_controller, c_debug_settings_controller, RPbdb_DebugSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( c_debug_verbosity_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_debug_verbosity_settings_controller, rb_RPbdb_DebugVerbositySettingsController, NULL, NULL )
	#define C_RPBDB_DEBUG_VERBOSITY_SETTINGS_CONTROLLER( rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller )													  C_RPBDB_STRUCT(		rb_debug_verbosity_settings_controller, c_debug_verbosity_settings_controller, RPbdb_DebugVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_DIRECTORY_SETTINGS_CONTROLLER( c_directory_settings_controller )																										  RUBY_RPBDB_OBJECT(	c_directory_settings_controller, rb_RPbdb_DirectorySettingsController, NULL, NULL )
	#define C_RPBDB_DIRECTORY_SETTINGS_CONTROLLER( rb_directory_settings_controller, c_directory_settings_controller )																		  C_RPBDB_STRUCT(		rb_directory_settings_controller, c_directory_settings_controller, RPbdb_DirectorySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( c_environment_cache_settings_controller )																						  RUBY_RPBDB_OBJECT(	c_environment_cache_settings_controller, rb_RPbdb_EnvironmentCacheSettingsController, NULL, NULL )
	#define C_RPBDB_ENVIRONMENT_CACHE_SETTINGS_CONTROLLER( rb_environment_cache_settings_controller, c_environment_cache_settings_controller )												  C_RPBDB_STRUCT(		rb_environment_cache_settings_controller, c_environment_cache_settings_controller, RPbdb_EnvironmentCacheSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_ERROR_SETTINGS_CONTROLLER( c_error_settings_controller )																												  RUBY_RPBDB_OBJECT(	c_error_settings_controller, rb_RPbdb_ErrorSettingsController, NULL, NULL )
	#define C_RPBDB_ERROR_SETTINGS_CONTROLLER( rb_error_settings_controller, c_error_settings_controller )																					  C_RPBDB_STRUCT(		rb_error_settings_controller, c_error_settings_controller, RPbdb_ErrorSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_FILE_SETTINGS_CONTROLLER( c_file_settings_controller )																												  RUBY_RPBDB_OBJECT(	c_file_settings_controller, rb_RPbdb_FileSettingsController, NULL, NULL )
	#define C_RPBDB_FILE_SETTINGS_CONTROLLER( rb_file_settings_controller, c_file_settings_controller )																						  C_RPBDB_STRUCT(		rb_file_settings_controller, c_file_settings_controller, RPbdb_FileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( c_file_verbosity_settings_controller )																							  RUBY_RPBDB_OBJECT(	c_file_verbosity_settings_controller, rb_RPbdb_FileVerbositySettingsController, NULL, NULL )
	#define C_RPBDB_FILE_VERBOSITY_SETTINGS_CONTROLLER( rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller )														  C_RPBDB_STRUCT(		rb_file_verbosity_settings_controller, c_file_verbosity_settings_controller, RPbdb_FileVerbositySettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_LOCK_SETTINGS_CONTROLLER( c_lock_settings_controller )																												  RUBY_RPBDB_OBJECT(	c_lock_settings_controller, rb_RPbdb_LockSettingsController, NULL, NULL )
	#define C_RPBDB_LOCK_SETTINGS_CONTROLLER( rb_lock_settings_controller, c_lock_settings_controller )																						  C_RPBDB_STRUCT(		rb_lock_settings_controller, c_lock_settings_controller, RPbdb_LockSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( c_lock_deadlock_detector_settings_controller )																			  RUBY_RPBDB_OBJECT(	c_lock_deadlock_detector_settings_controller, rb_RPbdb_LockDeadlockDetectorSettingsController, NULL, NULL )
	#define C_RPBDB_LOCK_DEADLOCK_DETECTOR_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller )								  C_RPBDB_STRUCT(		rb_lock_deadlock_detector_settings_controller, c_lock_deadlock_detector_settings_controller, RPbdb_LockDeadlockDetectorSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( c_lock_deadlock_detector_verbosity_settings_controller )														  RUBY_RPBDB_OBJECT(	c_lock_deadlock_detector_verbosity_settings_controller, rb_RPbdb_LockDeadlockDetectorVerbositySettingsController, NULL, NULL )
	#define C_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER( rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller )	  C_RPBDB_STRUCT(		rb_lock_deadlock_detector_verbosity_settings_controller, c_lock_deadlock_detector_verbosity_settings_controller, RPbdb_LockDeadlockDetectorVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_LOG_SETTINGS_CONTROLLER( c_log_settings_controller )																													  RUBY_RPBDB_OBJECT(	c_log_settings_controller, rb_RPbdb_LogSettingsController, NULL, NULL )
	#define C_RPBDB_LOG_SETTINGS_CONTROLLER( rb_log_settings_controller, c_log_settings_controller )																						  C_RPBDB_STRUCT(		rb_log_settings_controller, c_log_settings_controller, RPbdb_LogSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_MEMORY_POOL_SETTINGS_CONTROLLER( c_memory_pool_settings_controller )																									  RUBY_RPBDB_OBJECT(	c_memory_pool_settings_controller, rb_RPbdb_MemoryPoolSettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_SETTINGS_CONTROLLER( rb_memory_pool_settings_controller, c_memory_pool_settings_controller )																  C_RPBDB_STRUCT(		rb_memory_pool_settings_controller, c_memory_pool_settings_controller, RPbdb_MemoryPoolSettingsController )
                                                                                                                                                                							  
	#define RUBY_RPBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( c_memory_pool_file_settings_controller )																						  RUBY_RPBDB_OBJECT(	c_memory_pool_file_settings_controller, rb_RPbdb_MemoryPoolFileSettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_SETTINGS_CONTROLLER( rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller )													  C_RPBDB_STRUCT(		rb_memory_pool_file_settings_controller, c_memory_pool_file_settings_controller, RPbdb_MemoryPoolFileSettingsController )
                                                                                                                                                                        					  
	#define RUBY_RPBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( c_memory_pool_file_cache_settings_controller )															  RUBY_RPBDB_OBJECT(	c_memory_pool_file_cache_settings_controller, rb_RPbdb_MemoryPoolFileCacheSettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_CACHE_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_settings_controller, c_memory_pool_file_cache_settings_controller )	  C_RPBDB_STRUCT(		rb_memory_pool_file_cache_settings_controller, c_memory_pool_file_cache_settings_controller, RPbdb_MemoryPoolFileCacheSettingsController )

	#define RUBY_RPBDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( c_memory_pool_file_cache_priority_settings_controller )															  RUBY_RPBDB_OBJECT(	c_memory_pool_file_cache_priority_settings_controller, rb_RPbdb_MemoryPoolFileCachePrioritySettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_CACHE_PRIORITY_SETTINGS_CONTROLLER( rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller )	  C_RPBDB_STRUCT(		rb_memory_pool_file_cache_priority_settings_controller, c_memory_pool_file_cache_priority_settings_controller, RPbdb_MemoryPoolFileCachePrioritySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( c_memory_pool_file_page_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_memory_pool_file_page_settings_controller, rb_RPbdb_MemoryPoolFilePageSettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_FILE_PAGE_SETTINGS_CONTROLLER( rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller )									  C_RPBDB_STRUCT(		rb_memory_pool_file_page_settings_controller, c_memory_pool_file_page_settings_controller, RPbdb_MemoryPoolFilePageSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( c_memory_pool_record_read_write_settings_controller )																			  RUBY_RPBDB_OBJECT(	c_memory_pool_record_read_write_settings_controller, rb_RPbdb_MemoryPoolReadWriteSettingsController, NULL, NULL )
	#define C_RPBDB_MEMORY_POOL_READ_WRITE_SETTINGS_CONTROLLER( rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller )								  C_RPBDB_STRUCT(		rb_memory_pool_record_read_write_settings_controller, c_memory_pool_record_read_write_settings_controller, RPbdb_MemoryPoolReadWriteSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_MESSAGE_SETTINGS_CONTROLLER( c_message_settings_controller )																											  RUBY_RPBDB_OBJECT(	c_message_settings_controller, rb_RPbdb_MessageSettingsController, NULL, NULL )
	#define C_RPBDB_MESSAGE_SETTINGS_CONTROLLER( rb_message_settings_controller, c_message_settings_controller )																			  C_RPBDB_STRUCT(		rb_message_settings_controller, c_message_settings_controller, RPbdb_MessageSettingsController )
                                                                                                                                                											  
	#define RUBY_RPBDB_MUTEX_SETTINGS_CONTROLLER( c_mutex_settings_controller )																												  RUBY_RPBDB_OBJECT(	c_mutex_settings_controller, rb_RPbdb_MutexSettingsController, NULL, NULL )
	#define C_RPBDB_MUTEX_SETTINGS_CONTROLLER( rb_mutex_settings_controller, c_mutex_settings_controller )																					  C_RPBDB_STRUCT(		rb_mutex_settings_controller, c_mutex_settings_controller, RPbdb_MutexSettingsController )
                                                                                                                                                											  
	#define RUBY_RPBDB_REPLICATION_SETTINGS_CONTROLLER( c_replication_settings_controller )																									  RUBY_RPBDB_OBJECT(	c_replication_settings_controller, rb_RPbdb_ReplicationSettingsController, NULL, NULL )
	#define C_RPBDB_REPLICATION_SETTINGS_CONTROLLER( rb_replication_settings_controller, c_replication_settings_controller )																  C_RPBDB_STRUCT(		rb_replication_settings_controller, c_replication_settings_controller, RPbdb_ReplicationSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( c_replication_election_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_replication_election_settings_controller, rb_RPbdb_ReplicationElectionSettingsController, NULL, NULL )
	#define C_RPBDB_REPLICATION_ELECTION_SETTINGS_CONTROLLER( rb_replication_election_settings_controller, c_replication_election_settings_controller )										  C_RPBDB_STRUCT(		rb_replication_election_settings_controller, c_replication_election_settings_controller, RPbdb_ReplicationElectionSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( c_replication_timeout_settings_controller )																					  RUBY_RPBDB_OBJECT(	c_replication_timeout_settings_controller, rb_RPbdb_ReplicationTimeoutSettingsController, NULL, NULL )
	#define C_RPBDB_REPLICATION_TIMEOUT_SETTINGS_CONTROLLER( rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller )										  C_RPBDB_STRUCT(		rb_replication_timeout_settings_controller, c_replication_timeout_settings_controller, RPbdb_ReplicationTimeoutSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( c_replication_verbosity_settings_controller )																				  RUBY_RPBDB_OBJECT(	c_replication_verbosity_settings_controller, rb_RPbdb_ReplicationVerbositySettingsController, NULL, NULL )
	#define C_RPBDB_REPLICATION_VERBOSITY_SETTINGS_CONTROLLER( rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller )									  C_RPBDB_STRUCT(		rb_replication_verbosity_settings_controller, c_replication_verbosity_settings_controller, RPbdb_ReplicationVerbositySettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_THREAD_SETTINGS_CONTROLLER( c_thread_settings_controller )																											  RUBY_RPBDB_OBJECT(	c_thread_settings_controller, rb_RPbdb_ThreadSettingsController, NULL, NULL )
	#define C_RPBDB_THREAD_SETTINGS_CONTROLLER( rb_thread_settings_controller, c_thread_settings_controller )																				  C_RPBDB_STRUCT(		rb_thread_settings_controller, c_thread_settings_controller, RPbdb_ThreadSettingsController )
                                                                                                                                                                                              
	#define RUBY_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( c_transaction_settings_controller )																									  RUBY_RPBDB_OBJECT(	c_transaction_settings_controller, rb_RPbdb_TransactionSettingsController, NULL, NULL )
	#define C_RPBDB_TRANSACTION_SETTINGS_CONTROLLER( rb_transaction_settings_controller, c_transaction_settings_controller )																  C_RPBDB_STRUCT(		rb_transaction_settings_controller, c_transaction_settings_controller, RPbdb_TransactionSettingsController )

	/****************************
	*	Wrapping/Get Macros		*
	****************************/

	//	Extract C RPbdb struct from Ruby T_DATA
	#define C_RPBDB_STRUCT(	rb_object, c_struct, rpbdb_type )	Data_Get_Struct(	rb_object,																					\
																																							rpbdb_type,																					\
																																							c_struct )

	//	Wrap Ruby RPBDB T_DATA from C RPbdb struct
	#define RUBY_RPBDB_OBJECT(	c_object, rb_rpbdb_type, c_mark_function, c_free_function )	Data_Wrap_Struct(	rb_rpbdb_type,						\
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
	
	/*******************
	*  Error Checking  *
	*******************/

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																								\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_WRITE( rb_key, rb_data )															\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY_WRITE( rb_key )																											\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_WRITE_WITHOUT_DATA );															\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_RETRIEVE( rb_key )																							\
		if ( rb_key == Qnil )	{																																							\
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_KEY );																\
		}

	#define CHECK_RUBY_ARG_RESULTS_FOR_KEY_AND_DATA_RETRIEVE( rb_key, rb_data )														\
		CHECK_RUBY_ARG_RESULTS_FOR_KEY( rb_key );																														\
		else if ( rb_data == Qnil )	{																																				\
			rb_raise( rb_eArgError, RPBDB_RUBY_ERROR_CANNOT_RETRIEVE_WITHOUT_DATA );															\
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