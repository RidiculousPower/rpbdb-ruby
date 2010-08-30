#ifndef RB_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseTypeBtreeSettingsController();

VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_new(	VALUE	klass,
													   VALUE	rb_parent_database_type_settings_controller );
VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_init(	VALUE	rb_database_type_btree_settings_controller,
	VALUE	rb_parent_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_parentEnvironment(	VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_parentDatabase(	VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_reverseSplitting( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_RPDB_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	VALUE	rb_database_type_btree_settings_controller,
																				VALUE	rb_minimum_keys_per_page );

#endif
