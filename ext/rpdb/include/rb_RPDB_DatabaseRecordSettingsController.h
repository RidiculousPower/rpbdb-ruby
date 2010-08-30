#ifndef RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_RECORD_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseRecordSettingsController();

VALUE rb_RPDB_DatabaseRecordSettingsController_new(	VALUE	klass,
													VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseRecordSettingsController_init(	VALUE	rb_database_record_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_parentEnvironment(	VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_parentDatabase(	VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingMalloc( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingMallocOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_databaseAllocatesMemoryUsingRealloc( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseAllocatesMemoryUsingReallocOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_applicationAllocatesMemory( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnApplicationAllocatesMemoryOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_databaseFreesMemory( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnDatabaseFreesMemoryOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_partialAccess( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnPartialAccessOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_syncPriorToWriteReturn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOn( VALUE	rb_record_settings_controller );
		VALUE rb_RPDB_DatabaseRecordSettingsController_turnSyncPriorToWriteReturnOff( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_dataBufferSize( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_setDataBufferSize(	VALUE	rb_record_settings_controller, 
																		VALUE	rb_buffer_size );
	VALUE rb_RPDB_DatabaseRecordSettingsController_partialReadWriteSize( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteSize(	VALUE	rb_record_settings_controller, 
																				VALUE	rb_partial_read_write_size );
	VALUE rb_RPDB_DatabaseRecordSettingsController_partialReadWriteOffset( VALUE	rb_record_settings_controller );
	VALUE rb_RPDB_DatabaseRecordSettingsController_setPartialReadWriteOffset(	VALUE	rb_record_settings_controller, 
																				VALUE	rb_partial_read_write_offset );

#endif
