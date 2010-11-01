#ifndef RB_RPDB_DATABASE_JOIN_CONTROLLER
	#define RB_RPDB_DATABASE_JOIN_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseJoinController();
VALUE rb_RPDB_DatabaseJoinController_new(	int			argc,
																					VALUE*	args,
																					VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseJoinController_init(	int			argc,
																						VALUE*	args,
																						VALUE		rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_settingsController(	VALUE	rb_join_controller );
VALUE rb_RPDB_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller );
	
	VALUE rb_RPDB_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_join(	int			argc,
																							VALUE*	args,
																							VALUE		rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_joinListOfCursors(	int			argc,
																												VALUE*	args,
																												VALUE		rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller );


#endif