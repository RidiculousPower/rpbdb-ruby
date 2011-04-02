#ifndef RB_RPBDB_MUTEX_SETTINGS_CONTROLLER
	#define RB_RPBDB_MUTEX_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_MutexSettingsController();

VALUE rb_RPbdb_MutexSettingsController_new(	int			argc,
																						VALUE*	args,
																						VALUE		rb_klass_self );
VALUE rb_RPbdb_MutexSettingsController_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self );
VALUE rb_RPbdb_MutexSettingsController_parentEnvironment(	VALUE	rb_mutex_settings_controller );
VALUE rb_RPbdb_MutexSettingsController_parentSettingsController(	VALUE	rb_mutex_settings_controller );
	VALUE rb_RPbdb_MutexSettingsController_spinTimesBeforeBlockingForTestAndSpinMutexes( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_setSpinTimesBeforeBlockingForTestAndSpinMutexes(	VALUE	rb_mutex_settings_controller, 
																								VALUE	rb_spin_times_before_blocking_for_test_and_spin_mutexes );
	VALUE rb_RPbdb_MutexSettingsController_maxAllowableMutexes( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_setMaxAllowableMutexes(	VALUE	rb_mutex_settings_controller, 
																		VALUE	rb_max_allowable_mutexes );
	VALUE rb_RPbdb_MutexSettingsController_incrementForAddingMutexes( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_setIncrementForAddingMutexes(	VALUE	rb_mutex_settings_controller, 
																				VALUE	rb_increment_for_adding_mutexes );
	VALUE rb_RPbdb_MutexSettingsController_mutexAlignment( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_setMutexAlignment(	VALUE	rb_mutex_settings_controller, 
																	VALUE	rb_increment_for_adding_mutexes );
	VALUE rb_RPbdb_MutexSettingsController_associatedWithSingleProcess( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOn( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_turnAssociatedWithSingleProcessOff( VALUE	rb_mutex_settings_controller );
	VALUE rb_RPbdb_MutexSettingsController_selfBlocking( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_turnSelfBlockingOn( VALUE	rb_mutex_settings_controller );
		VALUE rb_RPbdb_MutexSettingsController_turnSelfBlockingOff( VALUE	rb_mutex_settings_controller );

#endif
