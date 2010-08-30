#ifndef RB_RPDB_DATABASE_VERIFICATION_CONTROLLER
	#define RB_RPDB_DATABASE_VERIFICATION_CONTROLLER
	
	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DatabaseVerificationController();

VALUE rb_RPDB_DatabaseVerificationController_new(	VALUE	klass,
												  VALUE	rb_parent_database );
VALUE rb_RPDB_DatabaseVerificationController_init(	VALUE	rb_database_verification_controller,
	VALUE	rb_parent_database );
	VALUE rb_RPDB_DatabaseVerificationController_settingsController(	VALUE	rb_database_verification_controller );
	VALUE rb_RPDB_DatabaseVerificationController_parentEnvironment(	VALUE	rb_database_verification_controller );
	VALUE rb_RPDB_DatabaseVerificationController_verifyDatabase( VALUE	rb_database_verification_controller );
VALUE rb_RPDB_DatabaseVerificationController_parentDatabase(	VALUE	rb_database_verification_controller );

#endif