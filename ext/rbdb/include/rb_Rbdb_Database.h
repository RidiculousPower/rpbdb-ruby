#ifndef RB_RBDB_DATABASE
	#define RB_RBDB_DATABASE

	#include "rb_Rbdb_BaseStandardIncludes.h"
	#include <rbdb/Rbdb_Types.h>

void Init_rb_Rbdb_Database();

VALUE rb_Rbdb_Database_new(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self );
VALUE rb_Rbdb_Database_initialize(	int			argc,
															VALUE*	args,
															VALUE		rb_klass_self );
VALUE rb_Rbdb_Database_use(	int			argc,
														VALUE*	args,
														VALUE		rb_klass_self );
	VALUE rb_Rbdb_Database_settingsController( VALUE	rb_database );
	VALUE rb_Rbdb_Database_parentEnvironment(	VALUE	rb_database );
	VALUE rb_Rbdb_Database_parentDatabaseController(	VALUE	rb_database );
	
	VALUE rb_Rbdb_Database_filename( VALUE	rb_database );
	VALUE rb_Rbdb_Database_name( VALUE	rb_database );
	VALUE rb_Rbdb_Database_handle( VALUE	rb_database );
	VALUE rb_Rbdb_Database_isOpen( VALUE	rb_database );
	VALUE rb_Rbdb_Database_open( VALUE	rb_database );
	VALUE rb_Rbdb_Database_close( VALUE	rb_database );
	VALUE rb_Rbdb_Database_rename(	VALUE	rb_database,
									VALUE	new_name );
	VALUE rb_Rbdb_Database_empty( VALUE	rb_database );
	VALUE rb_Rbdb_Database_erase( VALUE	rb_database );
	VALUE rb_Rbdb_Database_sync( VALUE	rb_database );
	VALUE rb_Rbdb_Database_isSecondary(	VALUE	rb_database );
	VALUE rb_Rbdb_Database_primaryDatabase(	VALUE	rb_secondary_database );
	VALUE rb_Rbdb_Database_secondaryIndexName(	VALUE	rb_secondary_database );
	VALUE rb_Rbdb_Database_setSecondaryKeyCreationCallbackMethod(	int	argc, 
																	VALUE*	args,
																	VALUE	rb_database	);
	VALUE rb_Rbdb_Database_secondaryKeyCreationCallbackMethod(	int			argc,
																															VALUE*	args,
																															VALUE		rb_primary_or_secondary_database );
VALUE rb_Rbdb_Database_createSecondaryIndex(	int			argc, 
																							VALUE*	args,
																							VALUE		rb_primary_database_self	);
VALUE rb_Rbdb_Database_createSecondaryIndexWithUnsortedDuplicates(	int			argc, 
																														VALUE*	args,
																														VALUE		rb_primary_database_self	);
VALUE rb_Rbdb_Database_createSecondaryIndexWithSortedDuplicates(	int			argc, 
																																	VALUE*	args,
																																	VALUE		rb_primary_database_self	);
VALUE rb_Rbdb_Database_databaseWithIndex(	VALUE	rb_primary_database,
																					VALUE	rb_index_name );
VALUE rb_Rbdb_Database_secondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																									VALUE	rb_index_name );
VALUE rb_Rbdb_Database_requireSecondaryDatabaseWithIndex(	VALUE	rb_primary_database,
																													VALUE	rb_index_name );
VALUE rb_Rbdb_Database_secondaryDatabaseHash( VALUE rb_primary_database );
VALUE rb_Rbdb_Database_uniqueForIndex(	int			argc,
																				VALUE*	args,
																				VALUE		rb_database );
VALUE rb_Rbdb_Database_setUniqueForIndex(	int			argc,
																					VALUE*	args,
																					VALUE		rb_database	);


	VALUE rb_Rbdb_Database_cursor( VALUE	rb_database );
	VALUE rb_Rbdb_Database_objectCursor( VALUE	rb_database );
	VALUE rb_Rbdb_Database_cursorController( VALUE	rb_database );
	VALUE rb_Rbdb_Database_joinController( VALUE	rb_database );
	VALUE rb_Rbdb_Database_verificationController( VALUE	rb_database );
VALUE rb_Rbdb_Database_sequenceController( int			argc,
																						VALUE*	args,
																						VALUE		rb_database );
VALUE rb_Rbdb_Database_write(	int			argc, 
															VALUE*	args, 
															VALUE		rb_database );
	VALUE rb_Rbdb_Database_keyExists(	int			argc,
																		VALUE*	args,
																		VALUE		rb_database );
VALUE rb_Rbdb_Database_keysExist(	int			argc,
																	VALUE*	args,
																	VALUE		rb_database );
	VALUE rb_Rbdb_Database_retrieve(	int	argc, 
										VALUE*	args,
										VALUE	rb_database );
VALUE rb_Rbdb_Database_retrievePrimaryKey(	int			argc, 
																						VALUE*	args,
																						VALUE		rb_database );
VALUE rb_Rbdb_Database_retrieveExactHashPair(	int			argc, 
																			VALUE*	args,
																			VALUE		rb_database );
	VALUE rb_Rbdb_Database_delete(	int	argc, 
									VALUE*	args,
									VALUE	rb_database );
VALUE rb_Rbdb_Database_verify( VALUE	rb_database );

VALUE rb_Rbdb_Database_iterate( VALUE	rb_database );
VALUE rb_Rbdb_Database_iterateKeys( VALUE	rb_database );
VALUE rb_Rbdb_Database_iterateDuplicates( VALUE	rb_database );

#endif
