#ifndef RB_RPbdb
	#define RB_RPbdb

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

	void Init_RPbdb();
	VALUE rb_RPbdb_registerModuleClass(	VALUE	rb_module_self,
																			VALUE	rb_klass );

	VALUE rb_RPbdb_extend(	VALUE	rb_klass_self,
							 VALUE	rb_module );
	VALUE rb_RPbdb_included(	VALUE	rb_module_self,
								VALUE	rb_included_in_module_or_class );
	VALUE rb_RPbdb_extended(	VALUE	rb_module_self,
								VALUE	rb_extended_module_or_class );
	VALUE rb_RPbdb_includedFor(	int	argc,
								 VALUE*	args,
								 VALUE	rb_module_self )	;
	VALUE rb_RPbdb_extends(	int	argc,
							 VALUE*	args,
							 VALUE	rb_module_self );

	VALUE rb_RPbdb_version( VALUE rb_module_self );
	VALUE rb_RPbdb_versionMajor( VALUE rb_module_self );
	VALUE rb_RPbdb_versionMinor( VALUE rb_module_self );
	VALUE rb_RPbdb_versionPatch( VALUE rb_module_self );
	VALUE rb_RPbdb_versionData(	VALUE	rb_module_self );

	VALUE rb_RPbdb_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) );
	VALUE rb_RPbdb_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																							VALUE	rb_environment );
	
#endif