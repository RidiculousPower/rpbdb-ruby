#ifndef RB_Rbdb_DATABASE_CONTROLLER
	#define RB_Rbdb_DATABASE_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseController();

	VALUE rb_Rbdb_DatabaseController_new(	int		argc,
																				 VALUE*	args,
																				 VALUE	rb_klass_self );
	VALUE rb_Rbdb_DatabaseController_initialize(	int		argc,
										  VALUE*	args,
										  VALUE	rb_parent_environment );

	VALUE rb_Rbdb_DatabaseController_settingsController(	VALUE rb_database_controller );
	VALUE rb_Rbdb_DatabaseController_parentEnvironment(	VALUE rb_database_controller );
	VALUE rb_Rbdb_DatabaseController_database(	VALUE		rb_database_controller,
																											VALUE		rb_database_name );
	VALUE rb_Rbdb_DatabaseController_newDatabase(	VALUE		rb_database_controller,
																								VALUE		rb_database_name );
	VALUE rb_Rbdb_DatabaseController_closeAllDatabases( VALUE rb_database_controller );

#endif
