#ifndef RB_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_TYPE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseTypeSettingsController();

VALUE rb_RPDB_DatabaseTypeSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseTypeSettingsController_init(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPDB_DatabaseTypeSettingsController_parentEnvironment(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabase(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPDB_DatabaseTypeSettingsController_parentSettingsController(	VALUE	rb_database_type_settings_controller );
VALUE rb_RPDB_DatabaseTypeSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_databaseType( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_isBTree( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToBTree( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_isHash( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToHash( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_isRecno( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToRecno( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_isQueue( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_setTypeToQueue( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_btreeController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_hashController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_queueController( VALUE	rb_database_type_settings_controller );
	VALUE rb_RPDB_DatabaseTypeSettingsController_recnoController( VALUE	rb_database_type_settings_controller ) ;

#endif
