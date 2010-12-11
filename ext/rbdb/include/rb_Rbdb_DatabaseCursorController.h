#ifndef RB_RBDB_DATABASE_CURSOR_CONTROLLER
	#define RB_RBDB_DATABASE_CURSOR_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseCursorController();

	VALUE rb_Rbdb_DatabaseCursorController_new( int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
	VALUE rb_Rbdb_DatabaseCursorController_initialize( 	int			argc,
																								VALUE*	args,
																								VALUE		rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_settingsController(	VALUE	rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_parentEnvironment(	VALUE	rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_parentDatabase(	VALUE	rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_cursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_objectCursor(	VALUE	rb_database_cursor_controller );
	VALUE rb_Rbdb_DatabaseCursorController_closeAllCursors( VALUE	rb_database_cursor_controller );

#endif
