require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock::DeadlockDetector do

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

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings::Lock.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new.should_not == nil
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

  /****************
  *  is_default?  *
  ****************/

  	/*******************
  	*  set_to_default  *
  	*******************/

  /********************
  *  reject_expired?  *
  ********************/

  	/**************************
  	*  set_to_reject_expired  *
  	**************************/

  /***********************************
  *  reject_locker_with_most_locks?  *
  ***********************************/

  	/*****************************************
  	*  set_to_reject_locker_with_most_locks  *
  	*****************************************/

  /*****************************************
  *  reject_locker_with_most_write_locks?  *
  *****************************************/

  	/***********************************************
  	*  set_to_reject_locker_with_most_write_locks  *
  	***********************************************/

  /*************************************
  *  reject_locker_with_fewest_locks?  *
  *************************************/

  	/*******************************************
  	*  set_to_reject_locker_with_fewest_locks  *
  	*******************************************/

  /*******************************************
  *  reject_locker_with_fewest_write_locks?  *
  *******************************************/

  	/*************************************************
  	*  set_to_reject_locker_with_fewest_write_locks  *
  	*************************************************/

  /************************************
  *  reject_locker_with_oldest_lock?  *
  ************************************/

  	/******************************************
  	*  set_to_reject_locker_with_oldest_lock  *
  	******************************************/

  /**************************************
  *  reject_locker_with_youngest_lock?  *
  **************************************/

  	/********************************************
  	*  set_to_reject_locker_with_youngest_lock  *
  	********************************************/

  /*******************
  *  reject_random?  *
  *******************/

  	/*************************
  	*  set_to_reject_random  *
  	*************************/

  /**********************************
  *  verbosity_settings_controller  *
  **********************************/

end

