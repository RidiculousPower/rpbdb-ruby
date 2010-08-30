#ifndef RB_RPDB_DATABASE
	#define RB_RPDB_DATABASE

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

void Init_RPDB_Database();

VALUE rb_RPDB_Database_new(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self );
VALUE rb_RPDB_Database_init(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
	VALUE rb_RPDB_Database_settingsController( VALUE	rb_database );
	VALUE rb_RPDB_Database_parentEnvironment(	VALUE	rb_database );
	VALUE rb_RPDB_Database_parentDatabaseController(	VALUE	rb_database );
	
	VALUE rb_RPDB_Database_filename( VALUE	rb_database );
	VALUE rb_RPDB_Database_name( VALUE	rb_database );
	VALUE rb_RPDB_Database_handle( VALUE	rb_database );
	VALUE rb_RPDB_Database_isOpen( VALUE	rb_database );
	VALUE rb_RPDB_Database_open( VALUE	rb_database );
	VALUE rb_RPDB_Database_close( VALUE	rb_database );
	VALUE rb_RPDB_Database_rename(	VALUE	rb_database,
									VALUE	new_name );
	VALUE rb_RPDB_Database_empty( VALUE	rb_database );
	VALUE rb_RPDB_Database_erase( VALUE	rb_database );
	VALUE rb_RPDB_Database_sync( VALUE	rb_database );
	VALUE rb_RPDB_Database_associateSecondaryDatabase(	VALUE		rb_primary_database, 
														VALUE		rb_secondary_database );
	VALUE rb_RPDB_Database_isSecondary(	VALUE	rb_database );
	VALUE rb_RPDB_Database_setSecondaryKeyCreationCallbackMethod(	int	argc, 
																	VALUE*	args,
																	VALUE	rb_database	);
	VALUE rb_RPDB_Database_secondaryKeyCreationCallbackMethod(	VALUE	rb_secondary_database );
	VALUE rb_RPDB_Database_createSecondaryIndex(	int	argc, 
													VALUE*	args,
													VALUE	rb_self	);
VALUE rb_RPDB_Database_createSecondaryIndexWithDatabase(	int	argc, 
														 VALUE*	args,
														 VALUE	rb_self	);
	VALUE rb_RPDB_Database_cursor( VALUE	rb_database );
	VALUE rb_RPDB_Database_objectCursor( VALUE	rb_database );
	VALUE rb_RPDB_Database_cursorController( VALUE	rb_database );
	VALUE rb_RPDB_Database_joinController( VALUE	rb_database );
	VALUE rb_RPDB_Database_verificationController( VALUE	rb_database );
	VALUE rb_RPDB_Database_databaseSequenceController( VALUE	rb_database );
	VALUE rb_RPDB_Database_write(	VALUE	rb_database, 
									VALUE	rb_key, 
									VALUE	rb_data );
	VALUE rb_RPDB_Database_keyExists(	VALUE	rb_database,
															VALUE	rb_key );
	VALUE rb_RPDB_Database_retrieve(	int	argc, 
										VALUE*	args,
										VALUE	rb_database );
	VALUE rb_RPDB_Database_delete(	int	argc, 
									VALUE*	args,
									VALUE	rb_database );
VALUE rb_RPDB_Database_iterateInSegments(	VALUE	rb_database,
										  VALUE	rb_items_per_segment	);
VALUE rb_RPDB_Database_iterate(	int	argc,
								VALUE*	args,
								VALUE	rb_database	);
VALUE rb_RPDB_Database_iterateAllInSegments(	VALUE	rb_database,
											 VALUE	rb_items_per_segment	);
VALUE rb_RPDB_Database_iterateAll(	int	argc,
								   VALUE*	args,
								   VALUE	rb_database	);
VALUE rb_RPDB_Database_iterateDuplicatesInSegments(	VALUE	rb_database,
													VALUE	rb_items_per_segment );
VALUE rb_RPDB_Database_iterateDuplicates(	int	argc,
											VALUE*	args,
											VALUE	rb_database );
VALUE rb_RPDB_Database_iterateKeysInSegments(	VALUE rb_database,
											  VALUE rb_items_per_segment );
VALUE rb_RPDB_Database_iterateKeys(	int	argc,
									VALUE*	args,
									VALUE	rb_database );
	
#endif
