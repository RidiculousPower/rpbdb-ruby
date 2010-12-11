#ifndef RB_RBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_TYPE_QUEUE_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseTypeQueueSettingsController();

VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_new(	int			argc,
																												VALUE*	args,
																												VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentEnvironment(	VALUE	rb_database_type_queue_settings_controller );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabase(	VALUE	rb_database_type_queue_settings_controller );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentSettingsController(	VALUE	rb_database_type_queue_settings_controller );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_type_queue_settings_controller );
VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_parentDatabaseTypeSettingsController(	VALUE	rb_database_type_queue_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_returnKeyDataPairsInOrder( VALUE	rb_database_type_queue_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOn( VALUE	rb_database_type_queue_settings_controller );
		VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_turnReturnKeyDataPairsInOrderOff( VALUE	rb_database_type_queue_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_numberOfPagesForUnderlyingData( VALUE	rb_database_type_queue_settings_controller );
	VALUE rb_Rbdb_DatabaseTypeQueueSettingsController_setNumberOfPagesForUnderlyingData(	VALUE	rb_database_type_queue_settings_controller, 
																							VALUE	rb_number_of_pages_for_underlying_data );

#endif
