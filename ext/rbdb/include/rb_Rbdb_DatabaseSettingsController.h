#ifndef RB_RBDB_DATABASE_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseSettingsController();

VALUE rb_Rbdb_DatabaseSettingsController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseSettingsController_initialize(	int				argc __attribute__ ((unused)),
																								VALUE*		args __attribute__ ((unused)),
																								VALUE			rb_self );
VALUE rb_Rbdb_DatabaseSettingsController_parentEnvironment(	VALUE	rb_database_settings_controller );
VALUE rb_Rbdb_DatabaseSettingsController_parentDatabase(	VALUE	rb_database_settings_controller );
VALUE rb_Rbdb_DatabaseSettingsController_parentSettingsController(	VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_checksum( VALUE	rb_database_settings_controller );
		VALUE rb_Rbdb_DatabaseSettingsController_turnChecksumOn( VALUE	rb_database_settings_controller );
		VALUE rb_Rbdb_DatabaseSettingsController_turnChecksumOff( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_transactionDurability( VALUE	rb_database_settings_controller );
		VALUE rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOn( VALUE	rb_database_settings_controller );
		VALUE rb_Rbdb_DatabaseSettingsController_turnTransactionDurabilityOff( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_pagesize( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_setPagesize(	VALUE	rb_database_settings_controller, 
															VALUE	rb_pagesize );
	VALUE rb_Rbdb_DatabaseSettingsController_isBigEndian( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_setByteOrderToBigEndian( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_isLittleEndian( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_setByteOrderToLittleEndian( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_isByteswapped( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_maxSizePageIn( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_errorSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_fixedRecordSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_associationSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_joinSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_encryptionSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_verbositySettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_verificationSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_cacheSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_cursorSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_sequenceSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_typeSettingsController( VALUE	rb_database_settings_controller );
	VALUE		rb_Rbdb_DatabaseRecordSettingsController_readWriteSettingsController( VALUE	rb_database_settings_controller );
	VALUE rb_Rbdb_DatabaseSettingsController_recordSettingsController( VALUE	rb_database_settings_controller );

#endif
