#ifndef RB_RPBDB_ENVIRONMENT
	#define RB_RPBDB_ENVIRONMENT

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_Environment();

	VALUE rb_RPbdb_Environment_new(	int		argc,
									VALUE*	args,
									VALUE	rb_klass_self );
	void rb_RPbdb_Environment_free(	RPbdb_Environment* c_environment );
VALUE rb_RPbdb_Environment_initialize(	int		argc,
							   VALUE*	args,
							   VALUE	rb_environment );
VALUE rb_RPbdb_Environment_use(	int			argc,
																VALUE*	args,
																VALUE		rb_klass_self );
	VALUE rb_RPbdb_Environment_initForStorageInMemory( VALUE	rb_environment );
VALUE rb_RPbdb_Environment_identifiesAs(	int	argc,
											VALUE*	args,
											VALUE	rb_environment );
VALUE rb_RPbdb_Environment_setIdentifiesAs(	int	argc,
											VALUE*	args,
												VALUE	rb_environment );
	VALUE rb_RPbdb_Environment_identifiers( VALUE	rb_environment );
VALUE rb_RPbdb_Environment_homeDirectory( VALUE	rb_environment );
	VALUE rb_RPbdb_Environment_open( VALUE	rb_environment );
VALUE rb_RPbdb_Environment_isOpen( VALUE	rb_environment );
	VALUE rb_RPbdb_Environment_close( VALUE	rb_environment );
	VALUE rb_RPbdb_Environment_erase( VALUE	rb_environment );

VALUE rb_RPbdb_Environment_name( VALUE rb_environment );
VALUE rb_RPbdb_Environment_handle( VALUE rb_environment );

	VALUE rb_RPbdb_Environment_version( VALUE rb_environment );
		VALUE rb_RPbdb_Environment_versionMajor( VALUE rb_environment );
		VALUE rb_RPbdb_Environment_versionMinor( VALUE rb_environment );
		VALUE rb_RPbdb_Environment_versionPatch( VALUE rb_environment );
		VALUE rb_RPbdb_Environment_versionData(	VALUE	rb_environment );
	VALUE rb_RPbdb_Environment_errorController( VALUE rb_environment );
	VALUE					rb_RPbdb_Environment_databaseController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_lockController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_memoryPoolController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_mutexController( VALUE rb_environment );
	VALUE 	rb_RPbdb_Environment_replicationController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_logController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_transactionController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_joinController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_runtimeStorageController( VALUE rb_environment );
	VALUE rb_RPbdb_Environment_settingsController( VALUE rb_environment );
VALUE rb_RPbdb_Environment_configuredClasses( VALUE rb_environment );
VALUE rb_RPbdb_Environment_isSetToValue(	VALUE		rb_environment_self,
																				VALUE		rb_new_value );

#endif
