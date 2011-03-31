#ifndef RB_RPBDB_DATABASE_CURSOR_CONTROLLER
	#define RB_RPBDB_DATABASE_CURSOR_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseCursorController();

	VALUE rb_RPbdb_DatabaseCursorController_new( int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
	VALUE rb_RPbdb_DatabaseCursorController_initialize( 	int			argc,
																								VALUE*	args,
																								VALUE		rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_settingsController(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_parentEnvironment(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_parentDatabase(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_cursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_objectCursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_RPbdb_DatabaseCursorController_closeAllCursors( VALUE	rb_database_cursor_controller );

#endif
