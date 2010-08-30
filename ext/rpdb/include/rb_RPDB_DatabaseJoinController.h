#ifndef RB_RPDB_DATABASE_JOIN_CONTROLLER
	#define RB_RPDB_DATABASE_JOIN_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseJoinController();
VALUE rb_RPDB_DatabaseJoinController_new(	VALUE	klass,
								  VALUE	rb_parent_environment );
VALUE rb_RPDB_DatabaseJoinController_init(	VALUE	rb_join_controller,
	VALUE	rb_parent_environment );
	VALUE rb_RPDB_DatabaseJoinController_settingsController(	VALUE	rb_join_controller );
VALUE rb_RPDB_DatabaseJoinController_parentDatabase(	VALUE	rb_join_controller );
	
	VALUE rb_RPDB_DatabaseJoinController_parentEnvironment(	VALUE	rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_join(	VALUE	rb_join_controller,
																	VALUE	rb_join_cursor_name,
																	VALUE	rb_cursor_list );
	VALUE rb_RPDB_DatabaseJoinController_cursorForName(	VALUE	rb_join_controller,
	 														VALUE	rb_join_cursor_name );
	VALUE rb_RPDB_DatabaseJoinController_closeCursorForName(	VALUE	rb_join_controller,
	 																VALUE	rb_join_cursor_name );
	VALUE rb_RPDB_DatabaseJoinController_allCursors( VALUE	rb_join_controller );
	VALUE rb_RPDB_DatabaseJoinController_closeAllCursors( VALUE	rb_join_controller );


#endif