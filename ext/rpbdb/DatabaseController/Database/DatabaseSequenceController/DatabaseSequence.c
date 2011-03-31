/*
 *		RPbdb::DatabaseController::Database::SequenceController::Sequence
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "DatabaseSequence.h"
#include "DatabaseSequenceController.h"
#include "DatabaseController.h"
#include "Database.h"

#include "Database_internal.h"

#include "RPbdb.h"

#include <rpbdb/Environment.h>

#include <rpbdb/Database.h>
#include <rpbdb/DatabaseSequence.h>
#include <rpbdb/DatabaseSequenceController.h>

#include <rpbdb/Record.h>

#include <rpbdb/DatabaseSequenceSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRPbdb;
extern	VALUE	rb_RPbdb_Environment;
extern	VALUE	rb_RPbdb_Database;
extern	VALUE	rb_RPbdb_DatabaseController;
extern	VALUE	rb_RPbdb_Record;
extern	VALUE	rb_RPbdb_DatabaseSequenceController;
extern	VALUE	rb_RPbdb_DatabaseSequence;
extern	VALUE	rb_RPbdb_DatabaseJoinsSettingsController;
extern	VALUE	rb_RPbdb_DatabaseSequenceSettingsController;
/*
R_DeclareClass(	rb_cObject, rb_RPbdb_DatabaseSequence, rb_RPbdb_Database, "Sequence",

		R_DeclareSingletonMethod(	-1,	rb_RPbdb_DatabaseSequence_new,
																	"new" ),
		R_DeclareMethod(					-1,	rb_RPbdb_DatabaseSequence_initialize,
																	"initialize" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_settingsController,
																	"settings_controller",
																	"settings",
																	"set",
																	"set_to",
																	"is_set_to" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_parentEnvironment,
																	"parent_environment",
																	"environment"),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_parentDatabase,
																	"parent_database",
																	"database" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_parentDatabaseSequenceController,
																	"parent_sequence_controller",
																	"sequence_controller",
																	"parent_controller",
																	"controller" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_isOpen,
																	"is_open?" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_openSequence,
																	"open" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_closeSequence,
																	"close" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_deleteSequence,
																	"delete!" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_renameSequence,
																	"rename!" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_step,
																	"step",
																	"next" ),
		R_DeclareMethod(					0,	rb_RPbdb_DatabaseSequence_stepBy,
																	"step_by" )
)
*/
void Init_rb_RPbdb_DatabaseSequence()	{

	rb_RPbdb_DatabaseSequence		=	rb_define_class_under(	rb_RPbdb_Database, 
																												"Sequence",				
																												rb_cObject );
	
	
	rb_define_singleton_method(	rb_RPbdb_DatabaseSequence, 	"new",																	rb_RPbdb_DatabaseSequence_new,															-1 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"initialize",														rb_RPbdb_DatabaseSequence_initialize,														-1 	);

	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"settings_controller",									rb_RPbdb_DatabaseSequence_settingsController,							0 	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"parent_environment",										rb_RPbdb_DatabaseSequence_parentEnvironment,								0 	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"parent_database",											rb_RPbdb_DatabaseSequence_parentDatabase,									0 	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"database",															"parent_database"	);

	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"parent_sequence_controller",						rb_RPbdb_DatabaseSequence_parentDatabaseSequenceController,		0 	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"sequence_controller",									"parent_sequence_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"parent_controller",										"parent_sequence_controller"	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"controller",														"parent_sequence_controller"	);
	
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"is_open?",															rb_RPbdb_DatabaseSequence_isOpen,													0 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"open",																	rb_RPbdb_DatabaseSequence_openSequence,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"close",																rb_RPbdb_DatabaseSequence_closeSequence,										0 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"delete!",															rb_RPbdb_DatabaseSequence_deleteSequence,									0 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"rename!",															rb_RPbdb_DatabaseSequence_renameSequence,									1 	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"step",																	rb_RPbdb_DatabaseSequence_step,														0 	);
	rb_define_alias(						rb_RPbdb_DatabaseSequence, 	"next",																	"step"	);
	rb_define_method(						rb_RPbdb_DatabaseSequence, 	"step_by",															rb_RPbdb_DatabaseSequence_stepBy,													1 	);

}

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*  self.new  *
*************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPbdb_DatabaseSequence_new(	int			argc,
																		VALUE*	args,
																		VALUE		rb_klass_self __attribute__ ((unused)) )	{

	VALUE	rb_sequence_name													=	Qnil;
	VALUE	rb_parent_environment											=	Qnil;
	VALUE	rb_parent_environment_home_directory			=	Qnil;
	VALUE	rb_parent_database												=	Qnil;
	VALUE	rb_parent_database_controller							=	Qnil;
	VALUE	rb_parent_database_name										=	Qnil;
	VALUE	rb_parent_database_sequence_controller		=	Qnil;
	R_DefineAndParse( argc, args, rb_klass_self,
		R_DescribeParameterSet(
			R_ParameterSet(
				R_Parameter(	R_MatchStringSymbol(			rb_sequence_name ) ),
				R_Parameter(	R_MatchAncestorInstance(	rb_parent_database_controller,					rb_RPbdb_DatabaseController ),
											R_MatchAncestorInstance(	rb_parent_environment,									rb_RPbdb_Environment ),
											R_MatchString(						rb_parent_environment_home_directory ) ),
				R_Parameter(	R_MatchString(						rb_parent_database_name ) )
			),
			2,
			"<sequence name>, <parent database controller>, <parent database name>",
			"<sequence name>, <parent environment>, <parent database name>",
			"<sequence name>, <parent environment home directory>, <parent database name>"
		),
		R_DescribeParameterSet(
			R_ParameterSet(
				R_Parameter(	R_MatchStringSymbol(			rb_sequence_name ) ),
				R_Parameter(	R_MatchAncestorInstance(	rb_parent_database_sequence_controller,	rb_RPbdb_DatabaseSequenceController ),
											R_MatchAncestorInstance(	rb_parent_database,											rb_RPbdb_Database ),
											R_MatchString(						rb_parent_database_name ) )
			),
			1,
			"<sequence name>, <parent database>",
			"<sequence name>, <parent database name>"
		)
	)
	
	if (		rb_parent_environment == Qnil
			&&	rb_parent_environment_home_directory == Qnil
			&&	rb_parent_database == Qnil
			&&	rb_parent_database_controller == Qnil
			&&	rb_parent_database_sequence_controller == Qnil )	{
		rb_parent_environment	=	rb_RPbdb_currentWorkingEnvironment( rb_mRPbdb );
	}
	
	if (	rb_parent_environment_home_directory != Qnil )	{
		rb_parent_environment	=	rb_RPbdb_Environment_new(	1,
																											& rb_parent_environment_home_directory,
																											rb_RPbdb_Environment );
	}
	if (	rb_parent_environment != Qnil )	{
		rb_parent_database_controller	=	rb_RPbdb_Environment_databaseController( rb_parent_environment );
	}
	if (		rb_parent_database_controller != Qnil
			&&	rb_parent_database_name != Qnil )	{
		rb_parent_database	=	rb_RPbdb_DatabaseController_newDatabase(	rb_parent_database_controller,
																																	rb_parent_database_name );
		
	}
	if (		rb_parent_database != Qnil )	{
		rb_parent_database_sequence_controller	=	rb_RPbdb_Database_sequenceController(	0,
																																										NULL,
																																										rb_parent_database );
	}

	RPbdb_DatabaseSequenceController*	c_parent_database_sequence_controller;
	C_RPBDB_DATABASE_SEQUENCE_CONTROLLER( rb_parent_database_sequence_controller, c_parent_database_sequence_controller );
	
	if ( TYPE( rb_sequence_name ) == T_SYMBOL )	{
		rb_sequence_name = rb_obj_as_string( rb_sequence_name );
	}
	char*	c_storage_key	=	StringValuePtr( rb_sequence_name );
	RPbdb_DatabaseSequence*	c_database_sequence	=	RPbdb_DatabaseSequenceController_sequence(	c_parent_database_sequence_controller,
																																													c_storage_key );
	
	VALUE	rb_database_sequence	=	RUBY_RPBDB_DATABASE_SEQUENCE( c_database_sequence );

	//	store reference to parent
	rb_iv_set(	rb_database_sequence,
							RPBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER,
							rb_parent_database_sequence_controller );

	VALUE	argv[]	=	{ rb_parent_database_sequence_controller };
	rb_obj_call_init(	rb_database_sequence,
										1, 
										argv );
	
	return rb_database_sequence;		
}

/*********
*  initialize  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_class.html
VALUE rb_RPbdb_DatabaseSequence_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  settingsController  *
***********************/

VALUE rb_RPbdb_DatabaseSequence_settingsController(	VALUE	rb_database_sequence )	{

	VALUE	rb_local_database_sequence_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_sequence_settings_controller = rb_iv_get(	rb_database_sequence,
																																			RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		RPbdb_DatabaseSequence*		c_database_sequence;
		C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );
	
		RPbdb_DatabaseSequenceSettingsController*	c_local_database_sequence_settings_controller	=	RPbdb_DatabaseSequence_settingsController( c_database_sequence );

		rb_local_database_sequence_settings_controller	=	RUBY_RPBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_local_database_sequence_settings_controller );

		rb_iv_set(	rb_database_sequence,
								RPBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER,
								rb_local_database_sequence_settings_controller );
	}

	return rb_local_database_sequence_settings_controller;
}

/****************
*  environment  *
****************/

VALUE rb_RPbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_controller		=	rb_RPbdb_DatabaseSequence_parentDatabaseController( rb_database_sequence );
	VALUE	rb_parent_environment						=	rb_RPbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/****************
*  parent_database_controller  *
****************/

VALUE rb_RPbdb_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database							=	rb_RPbdb_DatabaseSequence_parentDatabase( rb_database_sequence );
	VALUE	rb_parent_database_controller		= rb_RPbdb_Database_parentDatabaseController( rb_parent_database );
	return rb_parent_database_controller;
}

/****************
*  parent_database  *
****************/

VALUE rb_RPbdb_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_RPbdb_DatabaseSequence_parentDatabaseSequenceController( rb_database_sequence );
	VALUE	rb_parent_database											=	rb_RPbdb_DatabaseSequenceController_parentDatabase( rb_parent_database_sequence_controller );
	return rb_parent_database;
}

/*******************************
*  parent_sequence_controller  *
*******************************/

VALUE rb_RPbdb_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_iv_get(	rb_database_sequence,
																															RPBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER );
	return rb_parent_database_sequence_controller;
}

/*******************************************************************************************************************************************************************************************
																		Opening, Closing, Deleting
*******************************************************************************************************************************************************************************************/

/*************
*  is_open?  *
*************/

VALUE rb_RPbdb_DatabaseSequence_isOpen(	VALUE	rb_database_sequence )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	BOOL	c_is_open		=	RPbdb_DatabaseSequence_isOpen( c_database_sequence );
	VALUE	rb_is_open	=	( c_is_open ? Qtrue : Qfalse );

	return rb_is_open;
}

/*****************
*  openSequence  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_open.html
VALUE rb_RPbdb_DatabaseSequence_openSequence(	VALUE	rb_database_sequence )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPbdb_DatabaseSequence_openSequence(	c_database_sequence );
	
	return rb_database_sequence;
}

/******************
*  closeSequence  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_close.html
VALUE rb_RPbdb_DatabaseSequence_closeSequence( VALUE	rb_database_sequence )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPbdb_DatabaseSequence_closeSequence( c_database_sequence );
	
	return rb_database_sequence;
}

/*******************
*  deleteSequence  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_remove.html
VALUE rb_RPbdb_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	RPbdb_DatabaseSequence_deleteSequence( c_database_sequence );

	return rb_database_sequence;
}

/*******************
*  renameSequence  *
*******************/

VALUE rb_RPbdb_DatabaseSequence_renameSequence(	VALUE	rb_database_sequence,
																								VALUE	rb_new_name )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	if ( TYPE( rb_new_name ) != T_STRING )	{
		rb_new_name = rb_obj_as_string( rb_new_name );
	}
	
	char*	c_new_name	=	StringValuePtr( rb_new_name );
	
	RPbdb_DatabaseSequence_renameSequence( c_database_sequence,
																				c_new_name );

	return rb_database_sequence;
}

/*******************************************************************************************************************************************************************************************
																		Stepping
*******************************************************************************************************************************************************************************************/

/*********
*  step  *
*********/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPbdb_DatabaseSequence_step( VALUE	rb_database_sequence )	{

	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	int32_t	c_sequence_value	=	RPbdb_DatabaseSequence_step( c_database_sequence );
	VALUE		rb_sequence_value	=	INT2FIX( c_sequence_value );
	
	return rb_sequence_value;
}

/************
*  step_by  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_RPbdb_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
 																				VALUE	rb_step_value	)	{
	
	RPbdb_DatabaseSequence*		c_database_sequence;
	C_RPBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	int32_t	c_step_value	=	FIX2INT( rb_step_value );
	int32_t	c_sequence_value	=	RPbdb_DatabaseSequence_stepBy( c_database_sequence,
																														c_step_value );
	VALUE		rb_sequence_value	=	INT2FIX( c_sequence_value );

	return rb_sequence_value;
}

