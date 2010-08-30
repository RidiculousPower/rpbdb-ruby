#ifndef RB_RPDB_DATABASE_SEQUENCE_CONTROLLER
	#define RB_RPDB_DATABASE_SEQUENCE_CONTROLLER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseSequenceController();

VALUE rb_RPDB_DatabaseSequenceController_new(	VALUE	klass,
											  VALUE	rb_parent_database );
VALUE rb_RPDB_DatabaseSequenceController_init(	VALUE	rb_database_sequence_controller,
	VALUE	rb_parent_database );
	VALUE rb_RPDB_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller );
	VALUE rb_RPDB_DatabaseSequenceController_parentEnvironment(	VALUE database_sequence_controller );
	VALUE rb_RPDB_DatabaseSequenceController_createSequence(	int			argc,
																														VALUE*	argv,
																														VALUE		rb_database_sequence_controller );
VALUE rb_RPDB_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller );

#endif
