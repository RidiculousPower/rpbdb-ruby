#ifndef RB_RBDB_DATA
	#define RB_RBDB_DATA
	
	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_Data();

VALUE rb_Rbdb_Data_new(	int			argc,
												VALUE*	args,
												VALUE		rb_klass_self );
VALUE rb_Rbdb_Data_initialize(	int				argc __attribute__ ((unused)),
													VALUE*		args __attribute__ ((unused)),
													VALUE			rb_self );
	VALUE rb_Rbdb_Data_settingsController(	VALUE	rb_data );
VALUE rb_Rbdb_Data_parentEnvironment(	VALUE	rb_data );
VALUE rb_Rbdb_Data_parentDatabaseController(	VALUE	rb_data );
VALUE rb_Rbdb_Data_parentDatabase(	VALUE	rb_data );
VALUE rb_Rbdb_Data_parentRecord(	VALUE	rb_data );

#endif
