#ifndef RB_Rbdb_DIRECTORY_SETTINGS_CONTROLLER
	#define RB_Rbdb_DIRECTORY_SETTINGS_CONTROLLER

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_Rbdb_DirectorySettingsController();

VALUE rb_Rbdb_DirectorySettingsController_new(	int				argc,
																								VALUE*		args,
																								VALUE			rb_klass_self );
VALUE rb_Rbdb_DirectorySettingsController_initialize(	int				argc,
																								VALUE*		args,
																								VALUE			rb_self );
VALUE rb_Rbdb_DirectorySettingsController_parentEnvironment(	VALUE	rb_directory_settings_controller );
VALUE rb_Rbdb_DirectorySettingsController_parentSettingsController(	VALUE	rb_directory_settings_controller );
	VALUE rb_Rbdb_DirectorySettingsController_homeDirectory( VALUE	rb_directory_settings_controller );
	VALUE rb_Rbdb_DirectorySettingsController_dataDirectories( VALUE	rb_directory_settings_controller );
	VALUE rb_Rbdb_DirectorySettingsController_addDataDirectory(	VALUE	rb_directory_settings_controller, 
																	VALUE	rb_directory  );

#endif
