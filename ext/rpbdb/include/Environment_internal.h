#ifndef RB_RPBDB_ENVIRONMENT_INTERNAL
	#define RB_RPBDB_ENVIRONMENT_INTERNAL

	VALUE rb_RPbdb_Environment_internal_configureWaitingClassesForEnvironment( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_internal_markClassConfigured(	VALUE	rb_enviroment,
																VALUE	rb_klass );
		VALUE rb_RPbdb_Environment_internal_unmarkClassesConfigured( VALUE rb_enviroment );

	
#endif