#ifndef RB_RPDB_INTERNAL
#define RB_RPDB_INTERNAL

VALUE rb_RPDB_internal_environmentsToIdentifiersHash();
VALUE rb_RPDB_internal_extendedClassesHash();
VALUE rb_RPDB_internal_includedForClassesHash();
VALUE rb_RPDB_internal_initializeWaitingClasses();
VALUE rb_RPDB_internal_classesWaitingForDefaultEnvironment();
VALUE rb_RPDB_internal_classesWaitingForIdentification();
VALUE rb_RPDB_internal_classesWaitingForInitialization();
VALUE rb_RPDB_internal_environmentsHash(	VALUE rb_module_self );
	
#endif