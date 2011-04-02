#ifndef RB_RPBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCursorCachePrioritySettingsController();

VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_priority( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_veryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_setVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_low( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_setLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtMostLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_default( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_setDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_high( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_setHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_veryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_setVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPbdb_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );

#endif
