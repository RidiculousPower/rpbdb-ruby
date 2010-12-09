#ifndef RB_Rbdb_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_TYPE_BTREE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseTypeBtreeSettingsController();

VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_parentEnvironment(	VALUE	rb_database_type_btree_settings_controller );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_parentDatabase(	VALUE	rb_database_type_btree_settings_controller );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_parentSettingsController(	VALUE	rb_database_type_btree_settings_controller );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_btree_settings_controller );
VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_recordNumberRetrieval( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_reverseSplitting( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn( VALUE	rb_database_type_btree_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_minimumKeysPerPage( VALUE	rb_database_type_btree_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage(	VALUE	rb_database_type_btree_settings_controller,
																				VALUE	rb_minimum_keys_per_page );

#endif
