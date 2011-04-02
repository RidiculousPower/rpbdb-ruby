#ifndef RB_RPBDB_DATABASE_CONTROLLER
	#define RB_RPBDB_DATABASE_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseController();

	VALUE rb_RPbdb_DatabaseController_new(	int		argc,
																				 VALUE*	args,
																				 VALUE	rb_klass_self );
	VALUE rb_RPbdb_DatabaseController_initialize(	int		argc,
										  VALUE*	args,
										  VALUE	rb_parent_environment );

	VALUE rb_RPbdb_DatabaseController_settingsController(	VALUE rb_database_controller );
	VALUE rb_RPbdb_DatabaseController_parentEnvironment(	VALUE rb_database_controller );
	VALUE rb_RPbdb_DatabaseController_database(	VALUE		rb_database_controller,
																											VALUE		rb_database_name );
	VALUE rb_RPbdb_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																								VALUE		rb_database_name );
	VALUE rb_RPbdb_DatabaseController_closeAllDatabases( VALUE rb_database_controller );

#endif
