require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity do

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

  # RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( RPDB::Environment::Settings::Lock.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( lock_settings_controller )
  it "can be created with a lock deadlock detector settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new( RPDB::Environment::Settings::Lock::DeadlockDetector.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock::DeadlockDetector::Verbosity.new.should_not == nil
  end

  /*************
  *  self.new  *
  *************/

  /***************
  *  initialize  *
  ***************/

  /***********************
  *  parent_environment  *
  ***********************/

  /*******************************
  *  parent_settings_controller  *
  *******************************/

  /************************************
  *  parent_lock_settings_controller  *
  ************************************/

  /******************************************************
  *  parent_lock_deadlock_detector_settings_controller  *
  ******************************************************/

  /**************************************************************
  *  display_additional_information_during_deadlock_detection?  *
  **************************************************************/

  	/*********************************************************************
  	*  turn_display_additional_information_during_deadlock_detection_on  *
  	*********************************************************************/

  	/**********************************************************************
  	*  turn_display_additional_information_during_deadlock_detection_off  *
  	**********************************************************************/

  /**************************************************
  *  display_wait_table_during_deadlock_detection?  *
  **************************************************/

  	/*********************************************************
  	*  turn_display_wait_table_during_deadlock_detection_on  *
  	*********************************************************/

  	/**********************************************************
  	*  turn_display_wait_table_during_deadlock_detection_off  *
  	**********************************************************/

end

