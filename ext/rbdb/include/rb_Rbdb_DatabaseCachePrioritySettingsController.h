#ifndef RB_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseCachePrioritySettingsController();

VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_priority( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_veryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_low( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_default( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( VALUE database_cache_priority_settings_controller );
	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_high( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( VALUE database_cache_priority_settings_controller );
	VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_veryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_setVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_Rbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( VALUE database_cache_priority_settings_controller );

#endif
