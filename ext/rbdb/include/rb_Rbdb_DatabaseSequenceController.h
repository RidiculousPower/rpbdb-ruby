#ifndef RB_Rbdb_DATABASE_SEQUENCE_CONTROLLER
	#define RB_Rbdb_DATABASE_SEQUENCE_CONTROLLER
	
	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseSequenceController();

VALUE rb_Rbdb_DatabaseSequenceController_new(	int			argc,
																							VALUE*	args,
																							VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseSequenceController_initialize(	int			argc,
																								VALUE*	args,
																								VALUE		rb_self );
	VALUE rb_Rbdb_DatabaseSequenceController_settingsController(	VALUE	rb_database_sequence_controller );
	VALUE rb_Rbdb_DatabaseSequenceController_parentEnvironment(	VALUE database_sequence_controller );
	VALUE rb_Rbdb_DatabaseSequenceController_createSequence(	int			argc,
																														VALUE*	argv,
																														VALUE		rb_database_sequence_controller );
VALUE rb_Rbdb_DatabaseSequenceController_parentEnvironment(	VALUE	rb_database_sequence_controller );
VALUE rb_Rbdb_DatabaseSequenceController_parentDatabaseController(	VALUE	rb_database_sequence_controller );
VALUE rb_Rbdb_DatabaseSequenceController_parentDatabase(	VALUE	rb_database_sequence_controller );

#endif
