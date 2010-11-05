#ifndef RB_RPDB_DATABASE_SEQUENCE_CONTROLLER
	#define RB_RPDB_DATABASE_SEQUENCE_CONTROLLER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseSequenceController();

VALUE rb_RPDB_DatabaseSequenceController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseSequenceController_init(	int			argc,
																								VALUE*	args,
																								VALUE		rb_self );
	VALUE rb_RPDB_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller );
	VALUE rb_RPDB_DatabaseSequenceController_parentEnvironment(	VALUE database_sequence_controller );
	VALUE rb_RPDB_DatabaseSequenceController_createSequence(	int			argc,
																														VALUE*	argv,
																														VALUE		rb_database_sequence_controller );
VALUE rb_RPDB_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller );
VALUE rb_RPDB_DatabaseSequenceController_parentDatabaseController(	VALUE	rb_database_sequence_controller );
VALUE rb_RPDB_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller );

#endif
