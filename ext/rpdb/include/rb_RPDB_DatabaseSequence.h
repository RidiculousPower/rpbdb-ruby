#ifndef RB_RPDB_DATABASE_SEQUENCE
	#define RB_RPDB_DATABASE_SEQUENCE
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseSequence();

VALUE rb_RPDB_DatabaseSequence_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE rb_RPDB_DatabaseSequence_initialize(	int				argc __attribute__ ((unused)),
																			VALUE*		args __attribute__ ((unused)),
																			VALUE			rb_self );
	VALUE rb_RPDB_DatabaseSequence_settingsController(	VALUE	rb_database_sequence );
	VALUE rb_RPDB_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
	VALUE rb_RPDB_DatabaseSequence_openSequence(	VALUE	rb_database_sequence,
	 												VALUE	rb_stored_at_key	);
	VALUE rb_RPDB_DatabaseSequence_closeSequence( VALUE	rb_database_sequence );
	VALUE rb_RPDB_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence );
	VALUE rb_RPDB_DatabaseSequence_step( VALUE	rb_database_sequence );
	VALUE rb_RPDB_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
	 										VALUE	rb_step_value	);
	VALUE rb_RPDB_DatabaseSequence_stepBackward(	VALUE	rb_database_sequence 	);
	VALUE rb_RPDB_DatabaseSequence_stepBackwardBy(	VALUE	rb_database_sequence,
																									VALUE	rb_step_value	);
VALUE rb_RPDB_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
VALUE rb_RPDB_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence );
VALUE rb_RPDB_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence );
VALUE rb_RPDB_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence );

#endif
