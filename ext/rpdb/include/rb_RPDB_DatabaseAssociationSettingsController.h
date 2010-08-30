#ifndef RB_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseAssociationSettingsController();

VALUE rb_RPDB_DatabaseAssociationSettingsController_new(	VALUE	klass,
														 VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseAssociationSettingsController_init(	VALUE	rb_database_association_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseAssociationSettingsController_parentEnvironment(	VALUE	rb_database_association_settings_controller );
	VALUE rb_RPDB_DatabaseAssociationSettingsController_parentDatabase(	VALUE	rb_database_association_settings_controller );
	VALUE rb_RPDB_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( VALUE	rb_database_association_settings_controller );
		VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( VALUE	rb_database_association_settings_controller );
		VALUE rb_RPDB_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( VALUE	rb_database_association_settings_controller );
	VALUE rb_RPDB_DatabaseAssociationSettingsController_immutableSecondaryKey( VALUE	rb_database_association_settings_controller );
		VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( VALUE	rb_database_association_settings_controller );
		VALUE rb_RPDB_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( VALUE	rb_database_association_settings_controller );

#endif
