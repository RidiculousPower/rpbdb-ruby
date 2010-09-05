#ifndef RB_RPDB_INTERNAL
#define RB_RPDB_INTERNAL

void rb_RPDB_internal_initRuntimeStorages( VALUE rb_module_self );
VALUE rb_RPDB_internal_rubyRuntimeDatabase(	VALUE rb_module_self );
VALUE rb_RPDB_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass );
VALUE rb_RPDB_internal_environmentsToIdentifiersHash();
VALUE rb_RPDB_internal_extendedClassesHash();
VALUE rb_RPDB_internal_includedForClassesHash();
VALUE rb_RPDB_internal_initializeWaitingClasses();
VALUE rb_RPDB_internal_classesWaitingForDefaultEnvironment();
VALUE rb_RPDB_internal_classesWaitingForIdentification();
VALUE rb_RPDB_internal_classesWaitingForInitialization();
VALUE rb_RPDB_internal_environmentsHash(	VALUE rb_module_self );
	
	VALUE rb_RPDB_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																		VALUE	rb_environment );
	VALUE rb_RPDB_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self );


#endif