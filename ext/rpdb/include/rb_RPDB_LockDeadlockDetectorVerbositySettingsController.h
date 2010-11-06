#ifndef RB_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_RPDB_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_LockDeadlockDetectorVerbositySettingsController();

VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_new(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_klass_self );
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self );
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_RPDB_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );

#endif
