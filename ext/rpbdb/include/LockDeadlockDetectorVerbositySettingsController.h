#ifndef RB_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPBDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_LockDeadlockDetectorVerbositySettingsController();

VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_new(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_klass_self );
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self );
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );

#endif
