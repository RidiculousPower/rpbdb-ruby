#ifndef RB_RPDB_DIRECTORY_SETTINGS_CONTROLLER
	#define RB_RPDB_DIRECTORY_SETTINGS_CONTROLLER

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_DirectorySettingsController();

VALUE rb_RPDB_DirectorySettingsController_new(	int				argc,
																								VALUE*		args,
																								VALUE			rb_klass_self );
VALUE rb_RPDB_DirectorySettingsController_init(	int				argc,
																								VALUE*		args,
																								VALUE			rb_self );
	VALUE rb_RPDB_DirectorySettingsController_parentEnvironment(	VALUE	rb_directory_settings_controller );
	VALUE rb_RPDB_DirectorySettingsController_homeDirectory( VALUE	rb_directory_settings_controller );
	VALUE rb_RPDB_DirectorySettingsController_dataDirectories( VALUE	rb_directory_settings_controller );
	VALUE rb_RPDB_DirectorySettingsController_addDataDirectory(	VALUE	rb_directory_settings_controller, 
																	VALUE	rb_directory  );

#endif
