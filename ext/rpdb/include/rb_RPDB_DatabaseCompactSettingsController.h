#ifndef RB_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_COMPACT_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCompactSettingsController();

VALUE rb_RPDB_DatabaseCompactSettingsController_new(	VALUE	klass,
													 VALUE 	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseCompactSettingsController_init(	VALUE	rb_database_compact_settings_controller,
	VALUE 	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_parentEnvironment(	VALUE	rb_database_compact_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_parentDatabase(	VALUE	rb_database_compact_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_fillPercent( VALUE	rb_database_compact_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_setFillPercent(	VALUE	rb_database_compact_settings_controller, 
																		VALUE	rb_fill_percent );
	VALUE rb_RPDB_DatabaseCompactSettingsController_maxPagesToCompact( VALUE	rb_database_compact_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_setMaxPagesToCompact(	VALUE	rb_database_compact_settings_controller, 
																			VALUE	rb_max_pages_to_compact );
	VALUE rb_RPDB_DatabaseCompactSettingsController_timeout( VALUE	rb_database_compact_settings_controller );
	VALUE rb_RPDB_DatabaseCompactSettingsController_setTimeout(	VALUE	rb_database_compact_settings_controller, 
																	VALUE	rb_timeout );

#endif
