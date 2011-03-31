#ifndef RB_RPBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseSequenceSettingsController();

VALUE rb_RPbdb_DatabaseSequenceSettingsController_new(	int			argc,
																											VALUE*	args,
																											VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseSequenceSettingsController_initialize(	int				argc __attribute__ ((unused)),
																												VALUE*		args __attribute__ ((unused)),
																												VALUE			rb_self );
VALUE rb_RPbdb_DatabaseSequenceSettingsController_parentEnvironment(	VALUE	rb_database_sequence_settings_controller );
VALUE rb_RPbdb_DatabaseSequenceSettingsController_parentDatabase(	VALUE	rb_database_sequence_settings_controller );
VALUE rb_RPbdb_DatabaseSequenceSettingsController_parentSettingsController(	VALUE	rb_database_sequence_settings_controller );
VALUE rb_RPbdb_DatabaseSequenceSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_increasing( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setAsIncreasing( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_decreasing( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setAsDecreasing( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_wrap( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setToWrap( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_rangeMinimum( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setRangeMinimum(	VALUE	rb_sequence_settings_controller, 
																		VALUE	rb_range_minimum );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_rangeMaximum( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setRangeMaximum(	VALUE	rb_sequence_settings_controller,
																		VALUE	rb_range_maximum );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_cacheSize( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setCacheSize(	VALUE	rb_sequence_settings_controller,
	 																VALUE	rb_number_of_cached_elements	);
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_initialValue( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setInitialValue(	VALUE	rb_sequence_settings_controller,
	 																	VALUE	rb_initial_value );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_defaultStepValue( VALUE	rb_sequence_settings_controller );
	VALUE rb_RPbdb_DatabaseSequenceSettingsController_setDefaultStepValue(	VALUE	rb_sequence_settings_controller,
	 																		VALUE	rb_default_step_value	);

#endif