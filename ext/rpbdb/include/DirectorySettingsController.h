#ifndef RB_RPBDB_DIRECTORY_SETTINGS_CONTROLLER
	#define RB_RPBDB_DIRECTORY_SETTINGS_CONTROLLER

	#include "BaseStandardIncludes.h"
	#include <rpbdb/Types.h>

void Init_rb_RPbdb_DirectorySettingsController();

VALUE rb_RPbdb_DirectorySettingsController_new(	int				argc,
																								VALUE*		args,
																								VALUE			rb_klass_self );
VALUE rb_RPbdb_DirectorySettingsController_initialize(	int				argc,
																								VALUE*		args,
																								VALUE			rb_self );
VALUE rb_RPbdb_DirectorySettingsController_parentEnvironment(	VALUE	rb_directory_settings_controller );
VALUE rb_RPbdb_DirectorySettingsController_parentSettingsController(	VALUE	rb_directory_settings_controller );
	VALUE rb_RPbdb_DirectorySettingsController_homeDirectory( VALUE	rb_directory_settings_controller );
	VALUE rb_RPbdb_DirectorySettingsController_dataDirectories( VALUE	rb_directory_settings_controller );
	VALUE rb_RPbdb_DirectorySettingsController_addDataDirectory(	VALUE	rb_directory_settings_controller, 
																	VALUE	rb_directory  );

#endif
