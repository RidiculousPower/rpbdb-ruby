#ifndef RB_RPDB_DATABASE_INTERNAL
	#define RB_RPDB_DATABASE_INTERNAL

	#include "rb_RPDB_BaseStandardIncludes.h"
	#include <rpdb/RPDB_Types.h>

	VALUE rb_RPDB_Database_internal_iterationCursor( VALUE rb_database );
	VALUE	rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database_name );

	VALUE	rb_RPDB_Database_internal_setSecondaryKeyCreationCallbackMethodInfoHash(	VALUE	rb_secondary_database_name,
	 																					VALUE	rb_callback_object,
																						VALUE	rb_callback_method );
																						
	RPDB_SECONDARY_KEY_CREATION_RETURN rb_RPDB_Database_internal_secondaryKeyCreationCallbackMethod(	RPDB_Database*			c_secondary_database, 
																										RPDB_Record*			c_record, 
																										RPDB_SecondaryKeys*	c_return_data );

void rb_RPDB_Database_internal_serializeRubyObject(	VALUE				rb_key_or_data,
														DBT*			c_key_or_data );

#endif
