#ifndef RB_Rbdb_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER
	#define RB_Rbdb_LOCK_DEADLOCK_DETECTOR_VERBOSITY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_LockDeadlockDetectorVerbositySettingsController();

VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_new(	int			argc,
																																		VALUE*	args,
																																		VALUE		rb_klass_self );
VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_initialize(	int				argc __attribute__ ((unused)),
																																		VALUE*		args __attribute__ ((unused)),
																																		VALUE			rb_self );
VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_parentEnvironment(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_parentSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_parentLockSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_parentLockDeadlockDetectorSettingsController(	VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_displayAdditionalInformationDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayAdditionalInformationDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
	VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_displayWaitTableDuringDeadlockDetection( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOn( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );
		VALUE rb_Rbdb_LockDeadlockDetectorVerbositySettingsController_turnDisplayWaitTableDuringDeadlockDetectionOff( VALUE	rb_lock_deadlock_detector_verbosity_settings_controller );

#endif
