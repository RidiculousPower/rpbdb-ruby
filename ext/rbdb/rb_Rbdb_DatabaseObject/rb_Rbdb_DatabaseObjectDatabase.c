/*
 *		Rbdb::DatabaseController::ObjectDatabase
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseObjectCursor.h"
#include "rb_Rbdb_DatabaseObjectDatabase.h"
#include "rb_Rbdb_DatabaseObjectDatabase_internal.h"

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseCursor.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_DatabaseObjectCursor;
extern	VALUE	rb_Rbdb_DatabaseObjectDatabase;

void Init_Rbdb_DatabaseObjectDatabase()	{
	
	rb_Rbdb_DatabaseObjectDatabase		=	rb_define_class_under(	rb_Rbdb_DatabaseController, 
																															"ObjectDatabase",
																															rb_Rbdb_Database );

	rb_define_method(		rb_Rbdb_DatabaseObjectDatabase, 	"cursor",										rb_Rbdb_DatabaseObjectDatabase_cursor,						0 	);
		
}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
													Module Definition (Ruby Init)
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/***********
*  cursor  *
***********/

VALUE rb_Rbdb_DatabaseObjectDatabase_cursor( VALUE	rb_database )	{

	Rbdb_Database*	c_database	=	NULL;
	C_Rbdb_DATABASE_OBJECT_DATABASE( rb_database, c_database );
	
	Rbdb_DatabaseCursor*	c_cursor	=	Rbdb_Database_cursor( c_database );
	
	VALUE	rb_cursor	=	RUBY_RBDB_DATABASE_OBJECT_CURSOR( c_cursor );
	
	return rb_cursor;
}	

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
															Internal Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

