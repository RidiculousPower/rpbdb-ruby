#ifndef RB_RPDB_DATABASE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseSettingsController();

VALUE rb_RPDB_DatabaseSettingsController_new(	VALUE	klass,
											  VALUE	rb_parent_settings_controller );
VALUE rb_RPDB_DatabaseSettingsController_init(	VALUE	rb_database_settings_controller,
	VALUE	rb_parent_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_parentEnvironment(	VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_parentDatabase(	VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_checksum( VALUE	rb_database_settings_controller );
		VALUE rb_RPDB_DatabaseSettingsController_turnChecksumOn( VALUE	rb_database_settings_controller );
		VALUE rb_RPDB_DatabaseSettingsController_turnChecksumOff( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_transactionDurability( VALUE	rb_database_settings_controller );
		VALUE rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOn( VALUE	rb_database_settings_controller );
		VALUE rb_RPDB_DatabaseSettingsController_turnTransactionDurabilityOff( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_pagesize( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_setPageSize(	VALUE	rb_database_settings_controller, 
															VALUE	rb_pagesize );
	VALUE rb_RPDB_DatabaseSettingsController_isBigEndian( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_setByteOrderToBigEndian( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_isLittleEndian( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_setByteOrderToLittleEndian( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_isByteswapped( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_maxSizePageIn( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_errorSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_fixedRecordSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_associationSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_encryptionSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_verbositySettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_verificationSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_cursorSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_sequenceSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_typeSettingsController( VALUE	rb_database_settings_controller );
	VALUE		rb_RPDB_DatabaseSettingsController_readWriteSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_RPDB_DatabaseSettingsController_recordSettingsController( VALUE	rb_database_settings_controller );

#endif
