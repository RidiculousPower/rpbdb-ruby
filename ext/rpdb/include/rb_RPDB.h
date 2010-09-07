#ifndef RB_RPDB
	#define RB_RPDB

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

	void Init_RPDB();
	VALUE rb_RPDB_registerModuleClass(	VALUE	rb_module_self,
																			VALUE	rb_klass );

	VALUE rb_RPDB_extend(	VALUE	rb_klass_self,
							 VALUE	rb_module );
	VALUE rb_RPDB_included(	VALUE	rb_module_self,
								VALUE	rb_included_in_module_or_class );
	VALUE rb_RPDB_extended(	VALUE	rb_module_self,
								VALUE	rb_extended_module_or_class );
	VALUE rb_RPDB_includedFor(	int	argc,
								 VALUE*	args,
								 VALUE	rb_module_self )	;
	VALUE rb_RPDB_extends(	int	argc,
							 VALUE*	args,
							 VALUE	rb_module_self );

	VALUE rb_RPDB_version( VALUE rb_module_self );
	VALUE rb_RPDB_versionMajor( VALUE rb_module_self );
	VALUE rb_RPDB_versionMinor( VALUE rb_module_self );
	VALUE rb_RPDB_versionPatch( VALUE rb_module_self );
	VALUE rb_RPDB_versionData(	VALUE	rb_module_self );

	VALUE rb_RPDB_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) );
	VALUE rb_RPDB_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																							VALUE	rb_environment );
	
#endif