#ifndef RB_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_TYPE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseTypeSettingsController();

VALUE rb_RPbdb_DatabaseTypeSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseTypeSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPbdb_DatabaseTypeSettingsController_parentEnvironment(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPbdb_DatabaseTypeSettingsController_parentDatabase(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPbdb_DatabaseTypeSettingsController_parentSettingsController(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPbdb_DatabaseTypeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_databaseType( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_isBTree( VALUE		rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_setTypeToBTree( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_isHash(	VALUE		rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_setTypeToHash( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_isRecno(	VALUE		rb_database_type_settings_controller);
	VALUE rb_RPbdb_DatabaseTypeSettingsController_setTypeToRecno( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_isQueue( VALUE		rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_setTypeToQueue( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_btreeController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_hashController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_queueController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPbdb_DatabaseTypeSettingsController_recnoController( VALUE	rb_database_type_settings_controller ) ;

#endif
