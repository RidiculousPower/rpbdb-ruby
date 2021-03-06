#ifndef RB_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_JOIN_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseJoinSettingsController();

VALUE rb_RPbdb_DatabaseJoinSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseJoinSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_RPbdb_DatabaseJoinSettingsController_parentEnvironment(	VALUE	rb_join_settings_controller );
VALUE rb_RPbdb_DatabaseJoinSettingsController_parentDatabase(	VALUE	rb_join_settings_controller );
VALUE rb_RPbdb_DatabaseJoinSettingsController_parentSettingsController(	VALUE	rb_join_settings_controller );
VALUE rb_RPbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController(	VALUE	rb_join_settings_controller );
	VALUE rb_RPbdb_DatabaseJoinController_degreeOneIsolation( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOn( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnDegreeOneIsolationOff( VALUE	rb_join_settings_controller );
	VALUE rb_RPbdb_DatabaseJoinController_writeLocksInsteadOfReadLocks( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_join_settings_controller );
	VALUE rb_RPbdb_DatabaseJoinController_noSortBeforeJoin( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOn( VALUE	rb_join_settings_controller );
		VALUE rb_RPbdb_DatabaseJoinController_turnNoSortBeforeJoinOff( VALUE	rb_join_settings_controller );

#endif