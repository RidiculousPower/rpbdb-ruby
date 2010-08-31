#ifndef RB_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER
	#define RB_RPDB_DATABASE_READ_WRITE_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseReadWriteSettingsController();

VALUE rb_RPDB_DatabaseReadWriteSettingsController_new(	VALUE	klass,
													   VALUE	rb_parent_database_settings_controller );
VALUE rb_RPDB_DatabaseReadWriteSettingsController_init(	VALUE	rb_database_read_write_settings_controller,
	VALUE	rb_parent_database_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_parentEnvironment(	VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_parentDatabase(	VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_filename( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_setFilename(	VALUE	rb_database_read_write_settings_controller,
																	VALUE	rb_filename	);
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitSyncOnClose( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitSyncOnCloseOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_ignoreLease( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnIgnoreLeaseOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_returnMultiple( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnMultipleOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitDuplicateData( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitDuplicateDataOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitOverwrite( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitOverwriteOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_prohibitPageCompaction( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnProhibitPageCompactionOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_returnPagesToFilesystem( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnReturnPagesToFilesystemOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_partialAccess( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnPartialAccessOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_truncateFileOnOpen( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnTruncateFileOnOpenOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_writeLocksInsteadOfReadLocks( VALUE database_write_retrieve_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOn( VALUE database_write_retrieve_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnWriteLocksInsteadOfReadLocksOff( VALUE database_write_retrieve_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_duplicates( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnDuplicatesOff( VALUE	rb_database_read_write_settings_controller );
	VALUE rb_RPDB_DatabaseReadWriteSettingsController_sortedDuplicates( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOn( VALUE	rb_database_read_write_settings_controller );
		VALUE rb_RPDB_DatabaseReadWriteSettingsController_turnSortedDuplicatesOff( VALUE	rb_database_read_write_settings_controller );
	
#endif
