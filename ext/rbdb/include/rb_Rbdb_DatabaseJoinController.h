#ifndef RB_RBDB_DATABASE_JOIN_CONTROLLER
	#define RB_RBDB_DATABASE_JOIN_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseJoinController();
VALUE rb_Rbdb_DatabaseJoinController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseJoinController_initialize(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller );
	VALUE rb_Rbdb_DatabaseJoinController_settingsController(	VALUE	rb_join_controller );
VALUE rb_Rbdb_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller );
	
	VALUE rb_Rbdb_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller );
	VALUE rb_Rbdb_DatabaseJoinController_join(	int			argc,
																							VALUE*	args,
																							VALUE		rb_join_controller );
	VALUE rb_Rbdb_DatabaseJoinController_joinListOfCursors(	int			argc,
																												VALUE*	args,
																												VALUE		rb_join_controller );
	VALUE rb_Rbdb_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller );


#endif