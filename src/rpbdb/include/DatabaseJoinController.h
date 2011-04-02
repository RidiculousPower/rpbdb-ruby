#ifndef RB_RPBDB_DATABASE_JOIN_CONTROLLER
	#define RB_RPBDB_DATABASE_JOIN_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseJoinController();
VALUE rb_RPbdb_DatabaseJoinController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseJoinController_initialize(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller );
	VALUE rb_RPbdb_DatabaseJoinController_settingsController(	VALUE	rb_join_controller );
VALUE rb_RPbdb_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller );
	
	VALUE rb_RPbdb_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller );
	VALUE rb_RPbdb_DatabaseJoinController_join(	int			argc,
																							VALUE*	args,
																							VALUE		rb_join_controller );
	VALUE rb_RPbdb_DatabaseJoinController_joinListOfCursors(	int			argc,
																												VALUE*	args,
																												VALUE		rb_join_controller );
	VALUE rb_RPbdb_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller );


#endif