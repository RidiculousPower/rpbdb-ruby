#ifndef RB_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER
	#define RB_RBDB_DATABASE_JOIN_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseJoinSettingsController();

VALUE rb_Rbdb_DatabaseJoinSettingsController_new(	int			argc,
																									VALUE*	args,
																									VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseJoinSettingsController_initialize(	int				argc __attribute__ ((unused)),
																										VALUE*		args __attribute__ ((unused)),
																										VALUE			rb_self );
VALUE rb_Rbdb_DatabaseJoinSettingsController_parentEnvironment(	VALUE	rb_join_settings_controller );
VALUE rb_Rbdb_DatabaseJoinSettingsController_parentDatabase(	VALUE	rb_join_settings_controller );
VALUE rb_Rbdb_DatabaseJoinSettingsController_parentSettingsController(	VALUE	rb_join_settings_controller );
VALUE rb_Rbdb_DatabaseJoinSettingsController_parentDatabaseSettingsController(	VALUE	rb_join_settings_controller );
	VALUE rb_Rbdb_DatabaseJoinController_degreeOneIsolation( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnDegreeOneIsolationOn( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnDegreeOneIsolationOff( VALUE	rb_join_settings_controller );
	VALUE rb_Rbdb_DatabaseJoinController_writeLocksInsteadOfReadLocks( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOn( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnWriteLocksInsteadOfReadLocksOff( VALUE	rb_join_settings_controller );
	VALUE rb_Rbdb_DatabaseJoinController_noSortBeforeJoin( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnNoSortBeforeJoinOn( VALUE	rb_join_settings_controller );
		VALUE rb_Rbdb_DatabaseJoinController_turnNoSortBeforeJoinOff( VALUE	rb_join_settings_controller );

#endif