#ifndef RB_RPBDB_INTERNAL
#define RB_RPBDB_INTERNAL

void rb_RPbdb_internal_initRuntimeStorages( VALUE rb_module_self );
VALUE rb_RPbdb_internal_rubyRuntimeDatabase(	VALUE rb_module_self );
VALUE rb_RPbdb_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass );
VALUE rb_RPbdb_internal_environmentsToIdentifiersHash();
VALUE rb_RPbdb_internal_extendedClassesHash();
VALUE rb_RPbdb_internal_includedForClassesHash();
VALUE rb_RPbdb_internal_initializeWaitingClasses();
VALUE rb_RPbdb_internal_classesWaitingForDefaultEnvironment();
VALUE rb_RPbdb_internal_classesWaitingForIdentification();
VALUE rb_RPbdb_internal_classesWaitingForInitialization();
VALUE rb_RPbdb_internal_environmentsHash(	VALUE rb_module_self );
	
	VALUE rb_RPbdb_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																		VALUE	rb_environment );
	VALUE rb_RPbdb_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self );


#endif