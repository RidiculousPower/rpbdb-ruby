#ifndef RB_RBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseCursorReadWriteSettingsController();

VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_new(	int			argc,
																															VALUE*	args,
																															VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_initialize(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_cursor_read_write_settings_controller );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentDatabase(	VALUE	rb_database_cursor_read_write_settings_controller );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentDatabaseCursor(	VALUE	rb_database_cursor_read_write_settings_controller );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentSettingsController(	VALUE	rb_database_cursor_read_write_settings_controller );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_read_write_settings_controller );
VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_read_write_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_permitWrite( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( VALUE	rb_database_cursor_read_write_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_ignoreLease( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( VALUE	rb_database_cursor_read_write_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_cursor_read_write_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( VALUE	rb_database_cursor_read_write_settings_controller );
	VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( VALUE	rb_database_cursor_read_write_settings_controller );
		VALUE rb_Rbdb_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( VALUE	rb_database_cursor_read_write_settings_controller );

#endif
