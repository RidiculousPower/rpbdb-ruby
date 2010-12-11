#ifndef RB_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_ASSOCIATION_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseAssociationSettingsController();

VALUE rb_Rbdb_DatabaseAssociationSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseAssociationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																													VALUE*		args __attribute__ ((unused)),
																													VALUE			rb_self );
VALUE rb_Rbdb_DatabaseAssociationSettingsController_parentEnvironment(	VALUE	rb_database_association_settings_controller );
VALUE rb_Rbdb_DatabaseAssociationSettingsController_parentDatabase(	VALUE	rb_database_association_settings_controller );
VALUE rb_Rbdb_DatabaseAssociationSettingsController_parentSettingsController(	VALUE	rb_database_association_settings_controller );
VALUE rb_Rbdb_DatabaseAssociationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_association_settings_controller );
	VALUE rb_Rbdb_DatabaseAssociationSettingsController_secondaryAssociationCreatesIndex( VALUE	rb_database_association_settings_controller );
		VALUE rb_Rbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOn( VALUE	rb_database_association_settings_controller );
		VALUE rb_Rbdb_DatabaseAssociationSettingsController_turnSecondaryAssociationCreatesIndexOff( VALUE	rb_database_association_settings_controller );
	VALUE rb_Rbdb_DatabaseAssociationSettingsController_immutableSecondaryKey( VALUE	rb_database_association_settings_controller );
		VALUE rb_Rbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOn( VALUE	rb_database_association_settings_controller );
		VALUE rb_Rbdb_DatabaseAssociationSettingsController_turnImmutableSecondaryKeyOff( VALUE	rb_database_association_settings_controller );

#endif
