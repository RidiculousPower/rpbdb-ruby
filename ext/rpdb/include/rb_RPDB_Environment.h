#ifndef RB_RPDB_ENVIRONMENT
	#define RB_RPDB_ENVIRONMENT

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Environment();

	VALUE rb_RPDB_Environment_new(	int		argc,
									VALUE*	args,
									VALUE	rb_klass_self );
	void rb_RPDB_Environment_free(	RPDB_Environment* c_environment );
VALUE rb_RPDB_Environment_initialize(	int		argc,
							   VALUE*	args,
							   VALUE	rb_environment );
	VALUE rb_RPDB_Environment_initForStorageInMemory( VALUE	rb_environment );
VALUE rb_RPDB_Environment_identifiesAs(	int	argc,
											VALUE*	args,
											VALUE	rb_environment );
VALUE rb_RPDB_Environment_setIdentifiesAs(	int	argc,
											VALUE*	args,
												VALUE	rb_environment );
	VALUE rb_RPDB_Environment_identifiers( VALUE	rb_environment );
VALUE rb_RPDB_Environment_homeDirectory( VALUE	rb_environment );
	VALUE rb_RPDB_Environment_open( VALUE	rb_environment );
VALUE rb_RPDB_Environment_isOpen( VALUE	rb_environment );
	VALUE rb_RPDB_Environment_close( VALUE	rb_environment );
	VALUE rb_RPDB_Environment_erase( VALUE	rb_environment );

VALUE rb_RPDB_Environment_name( VALUE rb_environment );
VALUE rb_RPDB_Environment_handle( VALUE rb_environment );

	VALUE rb_RPDB_Environment_version( VALUE rb_environment );
		VALUE rb_RPDB_Environment_versionMajor( VALUE rb_environment );
		VALUE rb_RPDB_Environment_versionMinor( VALUE rb_environment );
		VALUE rb_RPDB_Environment_versionPatch( VALUE rb_environment );
		VALUE rb_RPDB_Environment_versionData(	VALUE	rb_environment );
	VALUE rb_RPDB_Environment_errorController( VALUE rb_environment );
	VALUE					rb_RPDB_Environment_databaseController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_lockController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_memoryPoolController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_mutexController( VALUE rb_environment );
	VALUE 	rb_RPDB_Environment_replicationController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_logController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_transactionController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_joinController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_runtimeStorageController( VALUE rb_environment );
	VALUE rb_RPDB_Environment_settingsController( VALUE rb_environment );
VALUE rb_RPDB_Environment_configuredClasses( VALUE rb_environment );
VALUE rb_RPDB_Environment_isSetToValue(	VALUE		rb_environment_self,
																				VALUE		rb_new_value );

#endif
