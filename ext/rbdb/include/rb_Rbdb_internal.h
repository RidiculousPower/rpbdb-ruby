#ifndef RB_RBDB_INTERNAL
#define RB_RBDB_INTERNAL

void rb_Rbdb_internal_initRuntimeStorages( VALUE rb_module_self );
VALUE rb_Rbdb_internal_rubyRuntimeDatabase(	VALUE rb_module_self );
VALUE rb_Rbdb_internal_configureIfNecessary(	VALUE	rb_module_self,
																							VALUE	rb_klass );
VALUE rb_Rbdb_internal_environmentsToIdentifiersHash();
VALUE rb_Rbdb_internal_extendedClassesHash();
VALUE rb_Rbdb_internal_includedForClassesHash();
VALUE rb_Rbdb_internal_initializeWaitingClasses();
VALUE rb_Rbdb_internal_classesWaitingForDefaultEnvironment();
VALUE rb_Rbdb_internal_classesWaitingForIdentification();
VALUE rb_Rbdb_internal_classesWaitingForInitialization();
VALUE rb_Rbdb_internal_environmentsHash(	VALUE rb_module_self );
	
	VALUE rb_Rbdb_internal_deleteFromCurrentWorkingEnvironmentStack(	VALUE	rb_module_self,
																																		VALUE	rb_environment );
	VALUE rb_Rbdb_internal_currentWorkingEnvironmentStack(	VALUE	rb_module_self );


#endif