#ifndef RB_RPDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCachePrioritySettingsController();

VALUE rb_RPDB_DatabaseCachePrioritySettingsController_new(	int			argc,
																														VALUE*	args,
																														VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseCachePrioritySettingsController_init(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_parentEnvironment(	VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_parentDatabase(	VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_priority( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_veryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_setVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtLeastVeryLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtMostVeryLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_low( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_setLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtLeastLow( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtMostLow( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_default( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_setDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtLeastDefault( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtMostDefault( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_high( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_setHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtLeastHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtMostHigh( VALUE database_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCachePrioritySettingsController_veryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_setVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtLeastVeryHigh( VALUE database_cache_priority_settings_controller );
		VALUE rb_RPDB_DatabaseCachePrioritySettingsController_isAtMostVeryHigh( VALUE database_cache_priority_settings_controller );

#endif
