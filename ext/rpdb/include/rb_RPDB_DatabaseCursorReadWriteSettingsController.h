#ifndef RB_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_READ_WRITE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorReadWriteSettingsController();

VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_new(	int			argc,
																															VALUE*	args,
																															VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_init(	int				argc __attribute__ ((unused)),
																															VALUE*		args __attribute__ ((unused)),
																															VALUE			rb_self );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_cursor_record_read_write_settings_controller );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabase(	VALUE	rb_database_cursor_record_read_write_settings_controller );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller );
VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_parentDatabaseCursorSettingsController(	VALUE	rb_database_cursor_record_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_permitWrite( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOn( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnPermitWriteOff( VALUE	rb_database_cursor_record_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLease( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOn( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_ignoreLeaseOff( VALUE	rb_database_cursor_record_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_database_cursor_record_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleDataItems( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOn( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleDataItemsOff( VALUE	rb_database_cursor_record_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_returnMultipleKeyDataPairs( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOn( VALUE	rb_database_cursor_record_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseCursorReadWriteSettingsController_turnReturnMultipleKeyDataPairsOff( VALUE	rb_database_cursor_record_read_write_settings_controller );

#endif
