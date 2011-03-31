#ifndef RB_RPBDB_DATABASE_SEQUENCE
	#define RB_RPBDB_DATABASE_SEQUENCE
	
	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseSequence();

VALUE rb_RPbdb_DatabaseSequence_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseSequence_initialize(	int				argc,
																						VALUE*		args,
																						VALUE			rb_self );
	VALUE rb_RPbdb_DatabaseSequence_settingsController(	VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_isOpen(	VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_openSequence(	VALUE	rb_database_sequence	);
	VALUE rb_RPbdb_DatabaseSequence_closeSequence( VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_renameSequence(	VALUE	rb_database_sequence,
																									VALUE	rb_new_name );
	VALUE rb_RPbdb_DatabaseSequence_step( VALUE	rb_database_sequence );
	VALUE rb_RPbdb_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
	 										VALUE	rb_step_value	);
VALUE rb_RPbdb_DatabaseSequence_currentValue( VALUE	rb_database_sequence );
VALUE rb_RPbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
VALUE rb_RPbdb_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence );
VALUE rb_RPbdb_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence );
VALUE rb_RPbdb_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence );

#endif
