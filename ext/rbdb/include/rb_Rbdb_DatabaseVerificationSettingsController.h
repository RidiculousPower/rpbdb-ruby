#ifndef RB_Rbdb_DATABASE_VERIFICATION_SETTINGS_CONTROLLER
	#define RB_Rbdb_DATABASE_VERIFICATION_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DatabaseVerificationSettingsController();

VALUE rb_Rbdb_DatabaseVerificationSettingsController_new(	int			argc,
																													VALUE*	args,
																													VALUE		rb_klass_self );
VALUE rb_Rbdb_DatabaseVerificationSettingsController_initialize(	int				argc __attribute__ ((unused)),
																														VALUE*		args __attribute__ ((unused)),
																														VALUE			rb_self );
VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentEnvironment(	VALUE	rb_database_verification_settings_controller );
VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentDatabase(	VALUE	rb_database_verification_settings_controller );
VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentSettingsController(	VALUE	rb_database_verification_settings_controller );
VALUE rb_Rbdb_DatabaseVerificationSettingsController_parentDatabaseSettingsController(	VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_file(	VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_setFile(	VALUE	rb_database_verification_settings_controller, 
																	VALUE	rb_data_output_file );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_aggressiveKeyDataPairDump( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnAggressiveKeyDataPairDumpOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_printableCharacters( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnPrintableCharactersOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_skipOrderCheck( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOn( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnSkipOrderCheckOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_onlyOrderCheck( VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOn(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnOnlyOrderCheckOff( VALUE	rb_database_verification_settings_controller );
	VALUE rb_Rbdb_DatabaseVerificationSettingsController_forceOrderCheck(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOn(	VALUE	rb_database_verification_settings_controller );
		VALUE rb_Rbdb_DatabaseVerificationSettingsController_turnForceOrderCheckOff(	VALUE	rb_database_verification_settings_controller );

#endif
