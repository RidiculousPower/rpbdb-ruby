#ifndef RB_RBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_COMPACT_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseCompactSettingsController();

VALUE rb_Rbdb_DatabaseCompactSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCompactSettingsController_initialize(	int				argc __attribute__ ((unused)),
																											VALUE*		args __attribute__ ((unused)),
																											VALUE			rb_self );
VALUE rb_Rbdb_DatabaseCompactSettingsController_parentEnvironment(	VALUE	rb_database_compact_settings_controller );
VALUE rb_Rbdb_DatabaseCompactSettingsController_parentDatabase(	VALUE	rb_database_compact_settings_controller );
VALUE rb_Rbdb_DatabaseCompactSettingsController_parentSettingsController(	VALUE	rb_database_compact_settings_controller );
VALUE rb_Rbdb_DatabaseCompactSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_compact_settings_controller );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_fillPercent( VALUE	rb_database_compact_settings_controller );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_setFillPercent(	VALUE	rb_database_compact_settings_controller, 
																		VALUE	rb_fill_percent );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_maxPagesToCompact( VALUE	rb_database_compact_settings_controller );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_setMaxPagesToCompact(	VALUE	rb_database_compact_settings_controller, 
																			VALUE	rb_max_pages_to_compact );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_timeout( VALUE	rb_database_compact_settings_controller );
	VALUE rb_Rbdb_DatabaseCompactSettingsController_setTimeout(	VALUE	rb_database_compact_settings_controller, 
																	VALUE	rb_timeout );

#endif
