#ifndef RB_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCachePrioritySettingsController();

VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_parentDatabaseCacheSettingsController(	VALUE	rb_database_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_priority( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_veryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_low( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_default( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostDefault( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_high( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostHigh( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_veryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_setVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPbdb_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( VALUE database_cache_priority_settings_controller );

#endif
