#ifndef RB_RPDB_DATABASE_CONTROLLER
	#define RB_RPDB_DATABASE_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseController();

	VALUE rb_RPDB_DatabaseController_new(	int		argc,
																				 VALUE*	args,
																				 VALUE	rb_klass_self );
	VALUE rb_RPDB_DatabaseController_init(	int		argc,
										  VALUE*	args,
										  VALUE	rb_parent_environment );

	VALUE rb_RPDB_DatabaseController_settingsController(	VALUE rb_database_controller );
	VALUE rb_RPDB_DatabaseController_parentEnvironment(	VALUE rb_database_controller );
	VALUE rb_RPDB_DatabaseController_database(	VALUE		rb_database_controller,
																											VALUE		rb_database_name );
	VALUE rb_RPDB_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																								VALUE		rb_database_name );
	VALUE rb_RPDB_DatabaseController_closeAllDatabases( VALUE rb_database_controller );

#endif
