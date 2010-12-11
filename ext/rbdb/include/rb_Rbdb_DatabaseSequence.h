#ifndef RB_RBDB_DATABASE_SEQUENCE
	#define RB_RBDB_DATABASE_SEQUENCE
	
	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_DatabaseSequence();

VALUE rb_Rbdb_DatabaseSequence_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseSequence_initialize(	int				argc,
																						VALUE*		args,
																						VALUE			rb_self );
	VALUE rb_Rbdb_DatabaseSequence_settingsController(	VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_isOpen(	VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_openSequence(	VALUE	rb_database_sequence	);
	VALUE rb_Rbdb_DatabaseSequence_closeSequence( VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_renameSequence(	VALUE	rb_database_sequence,
																									VALUE	rb_new_name );
	VALUE rb_Rbdb_DatabaseSequence_step( VALUE	rb_database_sequence );
	VALUE rb_Rbdb_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
	 										VALUE	rb_step_value	);
VALUE rb_Rbdb_DatabaseSequence_currentValue( VALUE	rb_database_sequence );
VALUE rb_Rbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence );
VALUE rb_Rbdb_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence );
VALUE rb_Rbdb_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence );
VALUE rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence );

#endif
