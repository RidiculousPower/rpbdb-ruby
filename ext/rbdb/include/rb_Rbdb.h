#ifndef RB_Rbdb
	#define RB_Rbdb

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

	void Init_Rbdb();
	VALUE rb_Rbdb_registerModuleClass(	VALUE	rb_module_self,
																			VALUE	rb_klass );

	VALUE rb_Rbdb_extend(	VALUE	rb_klass_self,
							 VALUE	rb_module );
	VALUE rb_Rbdb_included(	VALUE	rb_module_self,
								VALUE	rb_included_in_module_or_class );
	VALUE rb_Rbdb_extended(	VALUE	rb_module_self,
								VALUE	rb_extended_module_or_class );
	VALUE rb_Rbdb_includedFor(	int	argc,
								 VALUE*	args,
								 VALUE	rb_module_self )	;
	VALUE rb_Rbdb_extends(	int	argc,
							 VALUE*	args,
							 VALUE	rb_module_self );

	VALUE rb_Rbdb_version( VALUE rb_module_self );
	VALUE rb_Rbdb_versionMajor( VALUE rb_module_self );
	VALUE rb_Rbdb_versionMinor( VALUE rb_module_self );
	VALUE rb_Rbdb_versionPatch( VALUE rb_module_self );
	VALUE rb_Rbdb_versionData(	VALUE	rb_module_self );

	VALUE rb_Rbdb_currentWorkingEnvironment( VALUE rb_module_self __attribute__ ((unused )) );
	VALUE rb_Rbdb_setCurrentWorkingEnvironment(	VALUE	rb_module_self,
																							VALUE	rb_environment );
	
#endif