#ifndef RB_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_CACHE_PRIORITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorCachePrioritySettingsController();

VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_new(	int			argc,
																																	VALUE*	args,
																																	VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																	VALUE*		args __attribute__ ((unused)),
																																	VALUE			rb_self );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentEnvironment(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabase(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_parentDatabaseCursorCacheSettingsController(	VALUE	rb_database_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_priority( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_low( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostLow( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_default( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostDefault( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_high( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_veryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_setVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtLeastVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );
	VALUE rb_RPDB_DatabaseCursorCachePrioritySettingsController_isAtMostVeryHigh( VALUE	rb_cursor_cache_priority_settings_controller );

#endif
