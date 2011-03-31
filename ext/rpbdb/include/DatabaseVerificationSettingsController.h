#ifndef RB_RPBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER
	#define RB_RPBDB_DATABASE_VERIFICATION_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DatabaseVerificationSettingsController();

VALUE rb_RPbdb_DatabaseVerificationSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_RPbdb_DatabaseVerificationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_RPbdb_DatabaseVerificationSettingsController_parentEnvironment(	VALUE	rb_database_verification_settings_controller );
VALUE rb_RPbdb_DatabaseVerificationSettingsController_parentDatabase(	VALUE	rb_database_verification_settings_controller );
VALUE rb_RPbdb_DatabaseVerificationSettingsController_parentSettingsController(	VALUE	rb_database_verification_settings_controller );
VALUE rb_RPbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_file(	VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_setFile(	VALUE	rb_database_verification_settings_controller, 
																	VALUE	rb_data_output_file );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_printableCharacters( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_skipOrderCheck( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_onlyOrderCheck( VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_RPbdb_DatabaseVerificationSettingsController_forceOrderCheck(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOn(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_RPbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOff(	VALUE	rb_database_verification_settings_controller );

#endif
