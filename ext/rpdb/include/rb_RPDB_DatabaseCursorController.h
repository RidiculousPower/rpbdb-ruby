#ifndef RB_RPDB_DATABASE_CURSOR_CONTROLLER
	#define RB_RPDB_DATABASE_CURSOR_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseCursorController();

VALUE rb_RPDB_DatabaseCursorController_new( 	VALUE	klass,
											VALUE	rb_parent_database );
VALUE rb_RPDB_DatabaseCursorController_init( 	VALUE	rb_database_cursor_controller,
												VALUE	rb_parent_database );
	VALUE rb_RPDB_DatabaseCursorController_settingsController(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPDB_DatabaseCursorController_parentEnvironment(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPDB_DatabaseCursorController_cursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPDB_DatabaseCursorController_objectCursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPDB_DatabaseCursorController_closeAllCursors( VALUE	rb_database_cursor_controller );

#endif
