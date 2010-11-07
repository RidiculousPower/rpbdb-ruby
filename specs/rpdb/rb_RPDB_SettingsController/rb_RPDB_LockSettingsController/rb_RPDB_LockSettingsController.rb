require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock do

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

  # RPDB::Environment::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock.new.should_not == nil
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

  /********
  *  on?  *
  ********/

  /*********
  *  off?  *
  *********/

  	/************
  	*  turn_on  *
  	************/

  	/*************
  	*  turn_off  *
  	*************/

  /**********************
  *  prohibit_locking?  *
  **********************/

  	/*****************************
  	*  turn_prohibit_locking_on  *
  	*****************************/

  	/******************************
  	*  turn_prohibit_locking_off  *
  	******************************/

  /*********************************************
  *  timeout_returns_return_deny_not_deadlock  *
  *********************************************/

  	/*****************************************************
  	*  turn_timeout_returns_return_deny_not_deadlock_on  *
  	*****************************************************/

  	/******************************************************
  	*  turn_timeout_returns_return_deny_not_deadlock_off  *
  	******************************************************/

  /**********
  *  wait?  *
  **********/

  	/*****************
  	*  turn_wait_on  *
  	*****************/

  	/******************
  	*  turn_wait_off  *
  	******************/

  /***************************************
  *  lock_for_environment_not_database?  *
  ***************************************/

  	/**********************************************
  	*  turn_lock_for_environment_not_database_on  *
  	**********************************************/

  	/***********************************************
  	*  turn_lock_for_environment_not_database_off  *
  	***********************************************/

  /************
  *  timeout  *
  ************/

  	/****************
  	*  set_timeout  *
  	****************/

  /********************
  *  conflict_matrix  *
  ********************/

  	/************************
  	*  set_conflict_matrix  *
  	************************/

  /****************
  *  max_lockers  *
  ****************/

  	/********************
  	*  set_max_lockers  *
  	********************/

  /**************
  *  max_locks  *
  **************/

  	/******************
  	*  set_max_locks  *
  	******************/

  /****************
  *  max_objects  *
  ****************/

  	/********************
  	*  set_max_objects  *
  	********************/

  /*************************
  *  number_of_partitions  *
  *************************/

  	/*****************************
  	*  set_number_of_partitions  *
  	*****************************/

  /*********************************
  *  deadlock_detector_controller  *
  *********************************/

end

