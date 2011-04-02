#ifndef RB_RPBDB_DATABASE_SEQUENCE_CONTROLLER
	#define RB_RPBDB_DATABASE_SEQUENCE_CONTROLLER
	
	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseSequenceController();

VALUE rb_RPbdb_DatabaseSequenceController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseSequenceController_initialize(	int			argc,
																								VALUE*	args,
																								VALUE		rb_self );
	VALUE rb_RPbdb_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller );
	VALUE rb_RPbdb_DatabaseSequenceController_parentEnvironment(	VALUE database_sequence_controller );
VALUE rb_RPbdb_DatabaseSequenceController_sequence(	VALUE		rb_database_sequence_controller,
																										VALUE		rb_sequence_name );
VALUE rb_RPbdb_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller );
VALUE rb_RPbdb_DatabaseSequenceController_parentDatabaseController(	VALUE	rb_database_sequence_controller );
VALUE rb_RPbdb_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller );

#endif
