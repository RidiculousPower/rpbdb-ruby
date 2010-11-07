require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Type::Btree do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller

  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment::Settings::Database::Type::Btree.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Type::Btree.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Type::Btree.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Type::Btree.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Type::Btree.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Type::Btree.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Type::Btree.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Type::Btree.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Type::Btree.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Type::Btree.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Type::Btree.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Type::Btree.new.should_not == nil
  end

  /*
   *		RPDB::SettingsController::DatabaseSettingsController::DatabaseTypeSettingsController::DatabaseTypeBtreeSettingsController
   *
   *
   */

  /*******************************************************************************************************************************************************************************************
  ********************************************************************************************************************************************************************************************
  																		Headers
  ********************************************************************************************************************************************************************************************
  *******************************************************************************************************************************************************************************************/

  #include "rb_RPDB_DatabaseTypeBtreeSettingsController.h"
  #include "rb_RPDB_DatabaseTypeSettingsController.h"
  #include "rb_RPDB_DatabaseSettingsController.h"
  #include "rb_RPDB_DatabaseRecordSettingsController.h"
  #include "rb_RPDB_DatabaseController.h"
  #include "rb_RPDB_SettingsController.h"
  #include "rb_RPDB_Database.h"

  #include "rb_RPDB.h"


  #include <rpdb/RPDB_Environment.h>
  #include <rpdb/RPDB_Database.h>

  #include <rpdb/RPDB_DatabaseTypeBtreeSettingsController.h>
  #include <rpdb/RPDB_DatabaseTypeSettingsController.h>
  #include <rpdb/RPDB_DatabaseSettingsController.h>
  #include <rpdb/RPDB_SettingsController.h>

  #include <rargs.h>

  /*******************************************************************************************************************************************************************************************
  																		Ruby Definitions
  *******************************************************************************************************************************************************************************************/

  extern	VALUE	rb_mRPDB;
  extern	VALUE	rb_RPDB_Environment;
  extern	VALUE	rb_RPDB_Database;
  extern	VALUE	rb_RPDB_DatabaseController;
  extern	VALUE	rb_RPDB_DatabaseSettingsController;
  extern	VALUE	rb_RPDB_DatabaseTypeSettingsController;
  extern	VALUE	rb_RPDB_DatabaseTypeBtreeSettingsController;
  extern	VALUE	rb_RPDB_Record;
  extern	VALUE	rb_RPDB_DatabaseRecordSettingsController;
  extern	VALUE	rb_RPDB_SettingsController;

  void Init_RPDB_DatabaseTypeBtreeSettingsController()	{

  	rb_RPDB_DatabaseTypeBtreeSettingsController		=	rb_define_class_under(	rb_RPDB_DatabaseTypeSettingsController, 
  																																					"Btree",	
  																																					rb_cObject );

  	rb_define_singleton_method(	rb_RPDB_DatabaseTypeBtreeSettingsController, 	"new",																	rb_RPDB_DatabaseTypeBtreeSettingsController_new,															-1 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"initialize",														rb_RPDB_DatabaseTypeBtreeSettingsController_initialize,															-1 	);

  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"parent_environment",										rb_RPDB_DatabaseTypeBtreeSettingsController_parentEnvironment,								0 	);
  	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"environment",													"parent_environment"	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"parent_database",											rb_RPDB_DatabaseTypeBtreeSettingsController_parentDatabase,										0 	);
  	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"database",															"parent_database"	);

  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"record_number_retrieval?",							rb_RPDB_DatabaseTypeBtreeSettingsController_recordNumberRetrieval,						0 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_on",			rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOn,			0 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_record_number_retrieval_off",			rb_RPDB_DatabaseTypeBtreeSettingsController_turnRecordNumberRetrievalOff,			0 	);

  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"reverse_splitting?",										rb_RPDB_DatabaseTypeBtreeSettingsController_reverseSplitting,									0 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_on",						rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOn,						0 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"turn_reverse_splitting_off",						rb_RPDB_DatabaseTypeBtreeSettingsController_turnReverseSplittingOff,					0 	);

  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page",								rb_RPDB_DatabaseTypeBtreeSettingsController_minimumKeysPerPage,								0 	);
  	rb_define_method(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"minimum_keys_per_page=",								rb_RPDB_DatabaseTypeBtreeSettingsController_setMinimumKeysPerPage,						1 	);
  	rb_define_alias(						rb_RPDB_DatabaseTypeBtreeSettingsController, 	"set_minimum_keys_per_page",						"minimum_keys_per_page="	);
  }

  /*******************************************************************************************************************************************************************************************
  ********************************************************************************************************************************************************************************************
  																		Public Methods
  ********************************************************************************************************************************************************************************************
  *******************************************************************************************************************************************************************************************/

  /*************
  *  self.new  *
  *************/

  /***************
  *  initialize  *
  ***************/

  /***********************
  *  parent_environment  *
  ***********************/

  /********************
  *  parent_database  *
  ********************/

  /*******************************
  *  parent_settings_controller  *
  *******************************/

  /****************************************
  *  parent_database_settings_controller  *
  ****************************************/

  /*********************************************
  *  parent_database_type_settings_controller  *
  *********************************************/

  /****************************
  *  record_number_retrieval  *
  ****************************/

  	/************************************
  	*  turn_record_number_retrieval_on  *
  	************************************/

  	/*************************************
  	*  turn_record_number_retrieval_off  *
  	*************************************/

  /**********************
  *  reverse_splitting  *
  **********************/

  	/******************************
  	*  turn_reverse_splitting_on  *
  	******************************/

  	/*******************************
  	*  turn_reverse_splitting_off  *
  	*******************************/

  /**************************
  *  minimum_keys_per_page  *
  **************************/

  /******************************
  *  set_minimum_keys_per_page  *
  ******************************/

  /******************************
  *  set_prefix_compare_method  *
  ******************************/

  /**************************
  *  prefix_compare_method  *
  **************************/

  /***********************
  *  set_compare_method  *
  ***********************/

  /*******************
  *  compare_method  *
  *******************/

  /*********************************
  *  set_duplicate_compare_method  *
  *********************************/

  /*****************************
  *  duplicate_compare_method  *
  *****************************/

end

