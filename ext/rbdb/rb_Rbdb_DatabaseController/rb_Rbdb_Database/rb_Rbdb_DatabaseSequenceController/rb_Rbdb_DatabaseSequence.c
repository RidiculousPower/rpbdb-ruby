/*
 *		Rbdb::DatabaseController::Database::SequenceController::Sequence
 *
 *
 */

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Headers
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

#include "rb_Rbdb_DatabaseSequence.h"
#include "rb_Rbdb_DatabaseSequenceController.h"
#include "rb_Rbdb_DatabaseController.h"
#include "rb_Rbdb_Database.h"

#include "rb_Rbdb_Database_internal.h"

#include "rb_Rbdb.h"

#include <rbdb/Rbdb_Environment.h>

#include <rbdb/Rbdb_Database.h>
#include <rbdb/Rbdb_DatabaseSequence.h>
#include <rbdb/Rbdb_DatabaseSequenceController.h>

#include <rbdb/Rbdb_Record.h>

#include <rbdb/Rbdb_DatabaseSequenceSettingsController.h>

#include <rargs.h>

/*******************************************************************************************************************************************************************************************
																		Ruby Definitions
*******************************************************************************************************************************************************************************************/

extern	VALUE	rb_mRbdb;
extern	VALUE	rb_Rbdb_Environment;
extern	VALUE	rb_Rbdb_Database;
extern	VALUE	rb_Rbdb_DatabaseController;
extern	VALUE	rb_Rbdb_Record;
extern	VALUE	rb_Rbdb_DatabaseSequenceController;
extern	VALUE	rb_Rbdb_DatabaseSequence;
extern	VALUE	rb_Rbdb_DatabaseJoinsSettingsController;
extern	VALUE	rb_Rbdb_DatabaseSequenceSettingsController;
/*
R_DeclareClass(	rb_cObject, rb_Rbdb_DatabaseSequence, rb_Rbdb_Database, "Sequence",

		R_DeclareSingletonMethod(	-1,	rb_Rbdb_DatabaseSequence_new,
																	"new" ),
		R_DeclareMethod(					-1,	rb_Rbdb_DatabaseSequence_initialize,
																	"initialize" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_settingsController,
																	"settings_controller",
																	"settings",
																	"set",
																	"set_to",
																	"is_set_to" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_parentEnvironment,
																	"parent_environment",
																	"environment"),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_parentDatabase,
																	"parent_database",
																	"database" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController,
																	"parent_sequence_controller",
																	"sequence_controller",
																	"parent_controller",
																	"controller" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_isOpen,
																	"is_open?" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_openSequence,
																	"open" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_closeSequence,
																	"close" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_deleteSequence,
																	"delete!" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_renameSequence,
																	"rename!" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_step,
																	"step",
																	"next" ),
		R_DeclareMethod(					0,	rb_Rbdb_DatabaseSequence_stepBy,
																	"step_by" )
)
*/
void Init_rb_Rbdb_DatabaseSequence()	{

	rb_Rbdb_DatabaseSequence		=	rb_define_class_under(	rb_Rbdb_Database, 
																												"Sequence",				
																												rb_cObject );
	
	
	rb_define_singleton_method(	rb_Rbdb_DatabaseSequence, 	"new",																	rb_Rbdb_DatabaseSequence_new,															-1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"initialize",														rb_Rbdb_DatabaseSequence_initialize,														-1 	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"settings_controller",									rb_Rbdb_DatabaseSequence_settingsController,							0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"settings",															"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"set",																	"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"set_to",																"settings_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"is_set_to",														"settings_controller"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_environment",										rb_Rbdb_DatabaseSequence_parentEnvironment,								0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"environment",													"parent_environment"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_database",											rb_Rbdb_DatabaseSequence_parentDatabase,									0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"database",															"parent_database"	);

	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"parent_sequence_controller",						rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController,		0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"sequence_controller",									"parent_sequence_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"parent_controller",										"parent_sequence_controller"	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"controller",														"parent_sequence_controller"	);
	
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"is_open?",															rb_Rbdb_DatabaseSequence_isOpen,													0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"open",																	rb_Rbdb_DatabaseSequence_openSequence,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"close",																rb_Rbdb_DatabaseSequence_closeSequence,										0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"delete!",															rb_Rbdb_DatabaseSequence_deleteSequence,									0 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"rename!",															rb_Rbdb_DatabaseSequence_renameSequence,									1 	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step",																	rb_Rbdb_DatabaseSequence_step,														0 	);
	rb_define_alias(						rb_Rbdb_DatabaseSequence, 	"next",																	"step"	);
	rb_define_method(						rb_Rbdb_DatabaseSequence, 	"step_by",															rb_Rbdb_DatabaseSequence_stepBy,													1 	);

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
VALUE rb_Rbdb_DatabaseSequence_new(	int			argc,
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
				R_Parameter(	R_MatchAncestorInstance(	rb_parent_database_controller,					rb_Rbdb_DatabaseController ),
											R_MatchAncestorInstance(	rb_parent_environment,									rb_Rbdb_Environment ),
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
				R_Parameter(	R_MatchAncestorInstance(	rb_parent_database_sequence_controller,	rb_Rbdb_DatabaseSequenceController ),
											R_MatchAncestorInstance(	rb_parent_database,											rb_Rbdb_Database ),
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
		rb_parent_environment	=	rb_Rbdb_currentWorkingEnvironment( rb_mRbdb );
	}
	
	if (	rb_parent_environment_home_directory != Qnil )	{
		rb_parent_environment	=	rb_Rbdb_Environment_new(	1,
																											& rb_parent_environment_home_directory,
																											rb_Rbdb_Environment );
	}
	if (	rb_parent_environment != Qnil )	{
		rb_parent_database_controller	=	rb_Rbdb_Environment_databaseController( rb_parent_environment );
	}
	if (		rb_parent_database_controller != Qnil
			&&	rb_parent_database_name != Qnil )	{
		rb_parent_database	=	rb_Rbdb_DatabaseController_newDatabase(	rb_parent_database_controller,
																																	rb_parent_database_name );
		
	}
	if (		rb_parent_database != Qnil )	{
		rb_parent_database_sequence_controller	=	rb_Rbdb_Database_sequenceController(	0,
																																										NULL,
																																										rb_parent_database );
	}

	Rbdb_DatabaseSequenceController*	c_parent_database_sequence_controller;
	C_RBDB_DATABASE_SEQUENCE_CONTROLLER( rb_parent_database_sequence_controller, c_parent_database_sequence_controller );
	
	if ( TYPE( rb_sequence_name ) == T_SYMBOL )	{
		rb_sequence_name = rb_obj_as_string( rb_sequence_name );
	}
	char*	c_storage_key	=	StringValuePtr( rb_sequence_name );
	Rbdb_DatabaseSequence*	c_database_sequence	=	Rbdb_DatabaseSequenceController_sequence(	c_parent_database_sequence_controller,
																																													c_storage_key );
	
	VALUE	rb_database_sequence	=	RUBY_RBDB_DATABASE_SEQUENCE( c_database_sequence );

	//	store reference to parent
	rb_iv_set(	rb_database_sequence,
							RBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER,
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
VALUE rb_Rbdb_DatabaseSequence_initialize(	int				argc __attribute__ ((unused)),
																						VALUE*		args __attribute__ ((unused)),
																						VALUE			rb_self )	{

	return rb_self;
}

/***********************
*  settingsController  *
***********************/

VALUE rb_Rbdb_DatabaseSequence_settingsController(	VALUE	rb_database_sequence )	{

	VALUE	rb_local_database_sequence_settings_controller	=	Qnil;
	
	if ( ( rb_local_database_sequence_settings_controller = rb_iv_get(	rb_database_sequence,
																																			RBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER ) ) == Qnil )	{
		
		Rbdb_DatabaseSequence*		c_database_sequence;
		C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );
	
		Rbdb_DatabaseSequenceSettingsController*	c_local_database_sequence_settings_controller	=	Rbdb_DatabaseSequence_settingsController( c_database_sequence );

		rb_local_database_sequence_settings_controller	=	RUBY_RBDB_DATABASE_SEQUENCE_SETTINGS_CONTROLLER( c_local_database_sequence_settings_controller );

		rb_iv_set(	rb_database_sequence,
								RBDB_RB_SETTINGS_VARIABLE_DATABASE_SEQUENCE_SETTINGS_CONTROLLER,
								rb_local_database_sequence_settings_controller );
	}

	return rb_local_database_sequence_settings_controller;
}

/****************
*  environment  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentEnvironment(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_controller		=	rb_Rbdb_DatabaseSequence_parentDatabaseController( rb_database_sequence );
	VALUE	rb_parent_environment						=	rb_Rbdb_DatabaseController_parentEnvironment( rb_parent_database_controller );
	
	return rb_parent_environment;
}

/****************
*  parent_database_controller  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabaseController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database							=	rb_Rbdb_DatabaseSequence_parentDatabase( rb_database_sequence );
	VALUE	rb_parent_database_controller		= rb_Rbdb_Database_parentDatabaseController( rb_parent_database );
	return rb_parent_database_controller;
}

/****************
*  parent_database  *
****************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabase(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController( rb_database_sequence );
	VALUE	rb_parent_database											=	rb_Rbdb_DatabaseSequenceController_parentDatabase( rb_parent_database_sequence_controller );
	return rb_parent_database;
}

/*******************************
*  parent_sequence_controller  *
*******************************/

VALUE rb_Rbdb_DatabaseSequence_parentDatabaseSequenceController(	VALUE	rb_database_sequence )	{

	VALUE	rb_parent_database_sequence_controller	=	rb_iv_get(	rb_database_sequence,
																															RBDB_RB_DATABASE_SEQUENCE_VARIABLE_PARENT_SEQUENCE_CONTROLLER );
	return rb_parent_database_sequence_controller;
}

/*******************************************************************************************************************************************************************************************
																		Opening, Closing, Deleting
*******************************************************************************************************************************************************************************************/

/*************
*  is_open?  *
*************/

VALUE rb_Rbdb_DatabaseSequence_isOpen(	VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	BOOL	c_is_open		=	Rbdb_DatabaseSequence_isOpen( c_database_sequence );
	VALUE	rb_is_open	=	( c_is_open ? Qtrue : Qfalse );

	return rb_is_open;
}

/*****************
*  openSequence  *
*****************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_open.html
VALUE rb_Rbdb_DatabaseSequence_openSequence(	VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_openSequence(	c_database_sequence );
	
	return rb_database_sequence;
}

/******************
*  closeSequence  *
******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_close.html
VALUE rb_Rbdb_DatabaseSequence_closeSequence( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_closeSequence( c_database_sequence );
	
	return rb_database_sequence;
}

/*******************
*  deleteSequence  *
*******************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_remove.html
VALUE rb_Rbdb_DatabaseSequence_deleteSequence( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	Rbdb_DatabaseSequence_deleteSequence( c_database_sequence );

	return rb_database_sequence;
}

/*******************
*  renameSequence  *
*******************/

VALUE rb_Rbdb_DatabaseSequence_renameSequence(	VALUE	rb_database_sequence,
																								VALUE	rb_new_name )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	if ( TYPE( rb_new_name ) != T_STRING )	{
		rb_new_name = rb_obj_as_string( rb_new_name );
	}
	
	char*	c_new_name	=	StringValuePtr( rb_new_name );
	
	Rbdb_DatabaseSequence_renameSequence( c_database_sequence,
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
VALUE rb_Rbdb_DatabaseSequence_step( VALUE	rb_database_sequence )	{

	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	int32_t	c_sequence_value	=	Rbdb_DatabaseSequence_step( c_database_sequence );
	VALUE		rb_sequence_value	=	INT2FIX( c_sequence_value );
	
	return rb_sequence_value;
}

/************
*  step_by  *
************/

//	http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/seq_get.html
VALUE rb_Rbdb_DatabaseSequence_stepBy(	VALUE	rb_database_sequence,
 																				VALUE	rb_step_value	)	{
	
	Rbdb_DatabaseSequence*		c_database_sequence;
	C_RBDB_DATABASE_SEQUENCE( rb_database_sequence, c_database_sequence );

	int32_t	c_step_value	=	FIX2INT( rb_step_value );
	int32_t	c_sequence_value	=	Rbdb_DatabaseSequence_stepBy( c_database_sequence,
																														c_step_value );
	VALUE		rb_sequence_value	=	INT2FIX( c_sequence_value );

	return rb_sequence_value;
}

